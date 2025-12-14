#include "pch.h"
#include "VideoClient.h"

#include <algorithm>
#include <memory>
#include <vector>
#include <process.h>

CVideoClient::CVideoClient() {}
CVideoClient::~CVideoClient() { Stop(); }

BOOL CVideoClient::Start(HWND hNotify, LPCWSTR url, BOOL useCamera2)
{
    if (m_running) return TRUE;

    m_hNotify = hNotify;
    m_url = url;
    m_bUseCamera2 = useCamera2;
    m_running = TRUE;

    m_hThread = (HANDLE)_beginthreadex(nullptr, 0, &CVideoClient::ThreadProc, this, 0, nullptr);
    if (!m_hThread) {
        m_running = FALSE;
        return FALSE;
    }
    return TRUE;
}

void CVideoClient::Stop()
{
    if (!m_running) return;

    m_running = FALSE;

    if (m_hThread) {
        WaitForSingleObject(m_hThread, 2000);
        CloseHandle(m_hThread);
        m_hThread = nullptr;
    }
}

UINT __stdcall CVideoClient::ThreadProc(LPVOID pParam)
{
    CVideoClient* self = reinterpret_cast<CVideoClient*>(pParam);
    if (self) self->ThreadLoop();
    return 0;
}

BOOL CVideoClient::OpenWinHttp(HINTERNET& hSession, HINTERNET& hConnect, HINTERNET& hRequest)
{
    hSession = WinHttpOpen(L"VideoClient/1.0",
        WINHTTP_ACCESS_TYPE_NO_PROXY,
        WINHTTP_NO_PROXY_NAME,
        WINHTTP_NO_PROXY_BYPASS,
        0);
    if (!hSession) return FALSE;

    //  타임아웃 단축 (4초 → 1초)
    WinHttpSetTimeouts(hSession, 1000, 1000, 1000, 1000);

    URL_COMPONENTS uc{};
    uc.dwStructSize = sizeof(uc);
    WCHAR host[256] = { 0 };
    WCHAR path[1024] = { 0 };
    uc.lpszHostName = host;  uc.dwHostNameLength = _countof(host);
    uc.lpszUrlPath = path;  uc.dwUrlPathLength = _countof(path);

    if (!WinHttpCrackUrl(m_url, 0, 0, &uc)) return FALSE;

    hConnect = WinHttpConnect(hSession, host, uc.nPort, 0);
    if (!hConnect) return FALSE;

    DWORD flags = (uc.nScheme == INTERNET_SCHEME_HTTPS) ? WINHTTP_FLAG_SECURE : 0;

    hRequest = WinHttpOpenRequest(hConnect,
        L"GET",
        path,
        nullptr,
        WINHTTP_NO_REFERER,
        WINHTTP_DEFAULT_ACCEPT_TYPES,
        flags);
    if (!hRequest) return FALSE;

    WinHttpAddRequestHeaders(hRequest,
        L"Accept: multipart/x-mixed-replace\r\n", -1L, WINHTTP_ADDREQ_FLAG_ADD);

    if (!WinHttpSendRequest(hRequest,
        WINHTTP_NO_ADDITIONAL_HEADERS, 0,
        WINHTTP_NO_REQUEST_DATA, 0, 0, 0)) return FALSE;

    if (!WinHttpReceiveResponse(hRequest, nullptr)) return FALSE;

    return TRUE;
}

void CVideoClient::CloseWinHttp(HINTERNET& hSession, HINTERNET& hConnect, HINTERNET& hRequest)
{
    if (hRequest) WinHttpCloseHandle(hRequest), hRequest = nullptr;
    if (hConnect) WinHttpCloseHandle(hConnect), hConnect = nullptr;
    if (hSession) WinHttpCloseHandle(hSession), hSession = nullptr;
}

void CVideoClient::ThreadLoop()
{
    HINTERNET hSession = nullptr, hConnect = nullptr, hRequest = nullptr;

    UINT MSG_FRAME = m_bUseCamera2 ? WM_USER_VIDEO_FRAME2 : WM_USER_VIDEO_FRAME;
    UINT MSG_STATUS = m_bUseCamera2 ? WM_USER_VIDEO_STATUS2 : WM_USER_VIDEO_STATUS;

RECONNECT:
    if (!m_running) return;

    if (!OpenWinHttp(hSession, hConnect, hRequest)) {
        if (m_hNotify) ::PostMessage(m_hNotify, MSG_STATUS, 0, 0);
        Sleep(2000);  //  재연결 대기 증가 (1초 → 2초)
        goto RECONNECT;
    }
    else {
        if (m_hNotify) ::PostMessage(m_hNotify, MSG_STATUS, 1, 0);
    }

    std::vector<BYTE> buf;
    buf.reserve(256 * 1024);

    static const BYTE SOI[] = { 0xFF, 0xD8 };
    static const BYTE EOI[] = { 0xFF, 0xD9 };

    URL_COMPONENTS uc{}; uc.dwStructSize = sizeof(uc);
    WCHAR host[256] = { 0 }; WCHAR path[1024] = { 0 };
    uc.lpszHostName = host;  uc.dwHostNameLength = _countof(host);
    uc.lpszUrlPath = path;  uc.dwUrlPathLength = _countof(path);
    WinHttpCrackUrl(m_url, 0, 0, &uc);
    CString snapPath = path;
    if (snapPath.Find(L"/latest_jpeg") < 0)
        snapPath.Replace(L"/video_feed", L"/latest_jpeg");

    auto fetchSnapshotOnce = [&](std::vector<BYTE>& out)->bool {
        out.clear();
        HINTERNET sReq = WinHttpOpenRequest(hConnect, L"GET", snapPath, nullptr,
            WINHTTP_NO_REFERER, WINHTTP_DEFAULT_ACCEPT_TYPES,
            (uc.nScheme == INTERNET_SCHEME_HTTPS) ? WINHTTP_FLAG_SECURE : 0);
        if (!sReq) return false;

        //  스냅샷 타임아웃 설정
        DWORD timeout = 500;
        WinHttpSetOption(sReq, WINHTTP_OPTION_RECEIVE_TIMEOUT, &timeout, sizeof(timeout));

        BOOL ok = WinHttpSendRequest(sReq, WINHTTP_NO_ADDITIONAL_HEADERS, 0,
            WINHTTP_NO_REQUEST_DATA, 0, 0, 0)
            && WinHttpReceiveResponse(sReq, nullptr);
        if (!ok) { WinHttpCloseHandle(sReq); return false; }

        DWORD rd = 0; BYTE tmp[16 * 1024];
        while (WinHttpReadData(sReq, tmp, sizeof(tmp), &rd) && rd > 0) {
            out.insert(out.end(), tmp, tmp + rd);
            rd = 0;
        }
        WinHttpCloseHandle(sReq);
        return !out.empty();
        };

    DWORD lastFrameTick = GetTickCount();
    DWORD noDataStartTick = GetTickCount();  //  데이터 없을 때 타임아웃
    DWORD lastPostTick = GetTickCount();     //  프레임 전송 제한
    int consecutiveEmptyReads = 0;           //  연속 빈 읽기 카운트

    while (m_running)
    {
        BYTE tmp[16 * 1024];
        DWORD rd = 0;

        //  핵심 1: 5초간 데이터 없으면 재연결
        if (GetTickCount() - noDataStartTick > 5000) {
            break;
        }

        if (!WinHttpReadData(hRequest, tmp, sizeof(tmp), &rd)) {
            break;
        }

        if (rd == 0) {
            consecutiveEmptyReads++;

            //  핵심 2: 빈 읽기 시 점진적 Sleep (CPU 폭발 방지!)
            if (consecutiveEmptyReads < 10) {
                Sleep(10);   // 처음엔 10ms
            }
            else if (consecutiveEmptyReads < 50) {
                Sleep(50);   // 그 다음 50ms
            }
            else {
                Sleep(100);  // 계속 없으면 100ms
            }

            continue;
        }

        // 데이터 받았으면 초기화
        consecutiveEmptyReads = 0;
        noDataStartTick = GetTickCount();
        buf.insert(buf.end(), tmp, tmp + rd);

        bool produced = false;
        int framesInBuffer = 0;  //  버퍼 내 프레임 수

        for (;;)
        {
            auto itSOI = std::search(buf.begin(), buf.end(), std::begin(SOI), std::end(SOI));
            if (itSOI == buf.end()) {
                if (buf.size() > 4 * 1024 * 1024) {
                    buf.erase(buf.begin(), buf.end() - 512 * 1024);
                }
                break;
            }

            auto itEOI = std::search(itSOI + 2, buf.end(), std::begin(EOI), std::end(EOI));
            if (itEOI == buf.end()) {
                break;
            }

            const size_t idxSOI = static_cast<size_t>(itSOI - buf.begin());
            const size_t idxEOI = static_cast<size_t>(itEOI - buf.begin()) + 2;
            const size_t len = idxEOI - idxSOI;

            framesInBuffer++;

            //  핵심 3: 프레임 전송 제한 (10fps)
            DWORD now = GetTickCount();
            if (now - lastPostTick < 100) {  // 100ms = 10fps
                buf.erase(buf.begin(), buf.begin() + idxEOI);
                continue;  // 이 프레임 건너뜀
            }

            //  핵심 4: 버퍼에 프레임 많이 쌓였으면 건너뛰기 (최신 프레임만)
            if (framesInBuffer > 1) {
                buf.erase(buf.begin(), buf.begin() + idxEOI);
                continue;
            }

            lastPostTick = now;

            auto frame = new std::vector<BYTE>(len);
            memcpy(frame->data(), &buf[idxSOI], len);

            if (m_hNotify) {
                ::PostMessage(m_hNotify, MSG_FRAME, reinterpret_cast<WPARAM>(frame), 0);
            }
            else {
                delete frame;
            }

            buf.erase(buf.begin(), buf.begin() + idxEOI);
            produced = true;
            lastFrameTick = GetTickCount();
        }

        // 스냅샷 fallback
        if (!produced && (GetTickCount() - lastFrameTick) > 1500) {
            std::vector<BYTE> snap;
            if (fetchSnapshotOnce(snap)) {
                auto frame = new std::vector<BYTE>(snap.begin(), snap.end());
                if (m_hNotify) ::PostMessage(m_hNotify, MSG_FRAME, reinterpret_cast<WPARAM>(frame), 0);
                else delete frame;
                lastFrameTick = GetTickCount();
            }
            Sleep(200);
        }

        // 핵심 5: CPU 사용률 제어
        if (!produced) {
            Sleep(10);  // 프레임 없으면 10ms 대기
        }
    }

    CloseWinHttp(hSession, hConnect, hRequest);

    if (m_running)
        goto RECONNECT;
}