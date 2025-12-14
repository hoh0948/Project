#include "pch.h"
#include "framework.h"
#ifndef SHARED_HANDLERS
#include "MonitoringProgram.h"
#endif

#include "MonitoringProgramDoc.h"
#include "MonitoringProgramView.h"
#include "resource.h"

#include <gdiplus.h>
#include <vector>
#include <memory>
#include <string>

using namespace Gdiplus;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CMonitoringProgramView, CFormView)

BEGIN_MESSAGE_MAP(CMonitoringProgramView, CFormView)
    ON_BN_CLICKED(IDC_CHAT_BUTTON, &CMonitoringProgramView::OnBnClickedChatButton)
    ON_MESSAGE(WM_USER_CHAT_MESSAGE, &CMonitoringProgramView::OnChatMessage)
    ON_MESSAGE(WM_USER_CONNECTION_STATUS, &CMonitoringProgramView::OnConnectionStatus)
    ON_MESSAGE(WM_USER_VIDEO_FRAME, &CMonitoringProgramView::OnVideoFrame)
    ON_MESSAGE(WM_USER_VIDEO_STATUS, &CMonitoringProgramView::OnVideoStatus)
    ON_MESSAGE(WM_USER_VIDEO_FRAME2, &CMonitoringProgramView::OnVideoFrame2)
    ON_MESSAGE(WM_USER_VIDEO_STATUS2, &CMonitoringProgramView::OnVideoStatus2)
    ON_WM_TIMER()
    ON_WM_DESTROY()
    ON_BN_CLICKED(IDC_ENV_BUTTON, &CMonitoringProgramView::OnBnClickedEnvButton)
    ON_BN_CLICKED(IDC_VIDEO_BUTTON, &CMonitoringProgramView::OnBnClickedVideoButton)
    ON_BN_CLICKED(IDC_CONVEYOR_START_BUTTON, &CMonitoringProgramView::OnBnClickedConveyorStart)
    ON_BN_CLICKED(IDC_CONVEYOR_STOP_BUTTON, &CMonitoringProgramView::OnBnClickedConveyorStop)

    ON_BN_CLICKED(IDC_CONVEYOR_BUTTON, &CMonitoringProgramView::OnBnClickedConveyorButton)
END_MESSAGE_MAP()

 
CMonitoringProgramView::CMonitoringProgramView() noexcept
    : CFormView(IDD_MONITORINGPROGRAM_FORM)
{
    m_nTimerID = 0;
    m_hbmVideo = nullptr;
    m_hbmVideo2 = nullptr;
    m_gdiplusToken = 0;
    m_gdiInited = false;    
    m_bDuplicateLogin = FALSE;
    m_bEnvVisible = TRUE;
    m_bVideoVisible = TRUE;
}

CMonitoringProgramView::~CMonitoringProgramView()
{
}

void CMonitoringProgramView::DoDataExchange(CDataExchange* pDX)
{
    CFormView::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_CHAT_LIST, m_myListBox);
}
    
void CMonitoringProgramView::OnInitialUpdate()
{
    CFormView::OnInitialUpdate();
    GetParentFrame()->RecalcLayout();
    ResizeParentToFit();

    m_Font.CreatePointFont(100, _T("맑은 고딕"));
    GetDlgItem(IDC_CHAT_LIST)->SetFont(&m_Font);

    auto* pApp = (CMonitoringProgramApp*)AfxGetApp();
    if (pApp) {
        m_empNo = pApp->m_empNo;
        m_password = pApp->m_password;

        CString manager_name = L"<관리자(";
        manager_name.Append(m_empNo);
        manager_name.Append(L")>");
        GetDlgItem(IDC_MANAGER_STATIC)->SetWindowTextW(manager_name);
    }
    
    if (!m_chatClient.Connect(GetSafeHwnd(), IP, 5000, m_empNo, m_password)) {
        m_myListBox.AddString(_T("**서버 연결 실패. 5초 후 재시도..."));
        if (m_nTimerID == 0) m_nTimerID = SetTimer(1, 5000, NULL);
    }

    auto FixPictureCtrl = [&](int id) {
        if (CStatic* pPic = (CStatic*)GetDlgItem(id)) {
            if (::IsWindow(pPic->m_hWnd)) {
                pPic->ModifyStyle(SS_TYPEMASK, SS_BITMAP | SS_CENTERIMAGE);
                pPic->ModifyStyle(0, WS_BORDER);
                pPic->SetWindowPos(nullptr, 0, 0, 0, 0,
                    SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_FRAMECHANGED);
                pPic->ShowWindow(SW_SHOW);
            }
        }
        };
    // Flask 서버 주소/포트 설정 (ANSI 변환 필요)
    USES_CONVERSION;
    Conveyor_SetServerA(CT2A(IP), 8000);
    FixPictureCtrl(IDC_VIDEO1);
    FixPictureCtrl(IDC_VIDEO2);

    if (!m_gdiInited) {
        GdiplusStartupInput si;
        if (GdiplusStartup(&m_gdiplusToken, &si, nullptr) == Ok) {
            m_gdiInited = true;
        }
    }

    StartVideo();

    //  온습도 타이머 시작 (5초마다)
    m_nEnvTimerID = SetTimer(2, 5000, NULL);

    //  초기 온습도 데이터 로드
    UpdateEnvironmentData();

    GetDlgItem(IDC_CONVEYOR_START_BUTTON)->ShowWindow(SW_HIDE);
    GetDlgItem(IDC_CONVEYOR_STOP_BUTTON)->ShowWindow(SW_HIDE);
}

void CMonitoringProgramView::OnDestroy()
{
    StopVideo();

    // 채팅 재연결 타이머 정리
    if (m_nTimerID != 0) {
        KillTimer(m_nTimerID);
        m_nTimerID = 0;
    }

    //  온습도 타이머 정리
    if (m_nEnvTimerID != 0) {
        KillTimer(m_nEnvTimerID);
        m_nEnvTimerID = 0;
    }

    CFormView::OnDestroy();
}

void CMonitoringProgramView::OnBnClickedChatButton()
{
    CEdit* pChatEdit = (CEdit*)GetDlgItem(IDC_CHAT_EDIT);
    CString buffer;
    pChatEdit->GetWindowText(buffer);
    buffer.Trim();

    if (buffer.IsEmpty()) return;

    if (!m_chatClient.IsConnected()) {
        AfxMessageBox(L"서버에 연결되어 있지 않습니다.");
        return;
    }

    // 메세지 200자 이내로 제한
    if (buffer.GetLength() > 200)
    {
        AfxMessageBox(_T("메세지는 200자 이내로 입력해주세요."));
        return;
    }

    if (m_chatClient.SendMessage(buffer)) {
        CString selfLine;
        selfLine.Format(L"나 (%s) > %s", m_empNo.GetString(), buffer.GetString());
        AddStringToListBoxWithWrap(&m_myListBox, selfLine);
    }
    else {
        AddStringToListBoxWithWrap(&m_myListBox, L"** 메시지 전송 실패 **");
    }

    pChatEdit->SetWindowText(L"");
    pChatEdit->SetFocus();

   
}

LRESULT CMonitoringProgramView::OnChatMessage(WPARAM wParam, LPARAM)
{
    CString* pReceivedMsg = (CString*)wParam;
    if (pReceivedMsg) {
        if (pReceivedMsg->Find(L"DUPLICATE_LOGIN") >= 0) {
            m_bDuplicateLogin = TRUE;
            AfxMessageBox(L"⚠️ 다른 곳에서 로그인되어 연결이 종료되었습니다.\n"
                L"중복 로그인으로 인한 연결 해제입니다.",
                MB_ICONWARNING | MB_OK);
            AddStringToListBoxWithWrap(&m_myListBox, L"🚨 [경고] 중복 로그인으로 인한 연결 종료");
        }
        else {
            AddStringToListBoxWithWrap(&m_myListBox, *pReceivedMsg);
        }
        delete pReceivedMsg;
    }
    return 0;
}

LRESULT CMonitoringProgramView::OnConnectionStatus(WPARAM wParam, LPARAM)
{
    BOOL bConnected = (BOOL)wParam;
    if (bConnected) {
        AddStringToListBoxWithWrap(&m_myListBox, _T("**서버에 성공적으로 연결되었습니다.**"));
        m_bDuplicateLogin = FALSE;
        if (m_nTimerID != 0) {
            KillTimer(m_nTimerID);
            m_nTimerID = 0;
        }
    }
    else {
        if (m_bDuplicateLogin) {
            AddStringToListBoxWithWrap(&m_myListBox, _T("**중복 로그인으로 연결 해제됨**"));
        }
        else {
            AddStringToListBoxWithWrap(&m_myListBox, _T("**서버와 연결이 끊겼습니다. 5초 후 재시도...**"));
            if (m_nTimerID == 0) m_nTimerID = SetTimer(1, 5000, NULL);
        }
    }
    return 0;
}

void CMonitoringProgramView::OnTimer(UINT_PTR nIDEvent)
{
    if (nIDEvent == 1) {
        // 채팅 재연결 로직
        if (m_bDuplicateLogin) {
            KillTimer(m_nTimerID);
            m_nTimerID = 0;
            return;
        }
        if (!m_chatClient.IsConnected()) {
            m_chatClient.Connect(GetSafeHwnd(), IP, 5000, m_empNo, m_password);
        }
        else {
            KillTimer(m_nTimerID);
            m_nTimerID = 0;
        }
    }
    else if (nIDEvent == 2) {
        //  온습도 업데이트 (5초마다)
        UpdateEnvironmentData();
    }

    CFormView::OnTimer(nIDEvent);
}

BOOL CMonitoringProgramView::PreTranslateMessage(MSG* pMsg)
{
    if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN)
    {
        if (GetFocus() == GetDlgItem(IDC_CHAT_EDIT)) {
            OnBnClickedChatButton();
            return TRUE;
        }
    }
    return CFormView::PreTranslateMessage(pMsg);
}

void CMonitoringProgramView::AddStringToListBoxWithWrap(CListBox* pListBox, const CString& text)
{
    CRect rect;
    pListBox->GetClientRect(&rect); // 리스트박스 폭
    int maxWidth = rect.Width() - 4; // 약간 여유

    CDC* pDC = pListBox->GetDC();
    CFont* pOldFont = pDC->SelectObject(&m_Font); // 현재 사용하는 폰트 설정

    CString line;
    int curWidth = 0;

    for (int i = 0; i < text.GetLength(); i++)
    {
        CString ch = text.Mid(i, 1);
        CSize sz = pDC->GetTextExtent(ch);

        if (curWidth + sz.cx > maxWidth)
        {
            pListBox->AddString(line);  // 줄 추가
            line = ch;
            curWidth = sz.cx;
        }
        else
        {
            line += ch;
            curWidth += sz.cx;
        }
    }

    if (!line.IsEmpty())
        pListBox->AddString(line);

    pDC->SelectObject(pOldFont);
    pListBox->ReleaseDC(pDC);

    // 최대 100줄 유지
    const int count = pListBox->GetCount();
    if (count > 100) {
        pListBox->DeleteString(0);
    }

    // 자동 스크롤
    if (count > 0) {
        pListBox->SetTopIndex(count - 1);
    }
}

void CMonitoringProgramView::StartVideo()
{
    if (!m_gdiInited) {
        GdiplusStartupInput si;
        if (GdiplusStartup(&m_gdiplusToken, &si, nullptr) == Ok) {
            m_gdiInited = true;
            AddStringToListBoxWithWrap(&m_myListBox, L"[VIDEO] GDI+ 초기화 완료");
        }
        else {
            AddStringToListBoxWithWrap(&m_myListBox, L"[VIDEO] ❌ GDI+ 초기화 실패");
            return;
        }
    }

    if (!m_video.IsRunning()) {
        CString url1 = L"http://";
        url1.Append(IP);
        url1.Append(L":8000/video_feed_1");
        if (m_video.Start(this->GetSafeHwnd(), url1, FALSE)) {
            AddStringToListBoxWithWrap(&m_myListBox, L"[VIDEO1] 카메라 1 스트림 시작");
        }
        else {
            AddStringToListBoxWithWrap(&m_myListBox, L"[VIDEO1] ❌ 카메라 1 시작 실패");
        }
    }

    if (!m_video2.IsRunning()) {
        CString url2 = L"http://";
        url2.Append(IP);
        url2.Append(L":8000/video_feed_2");
        
        if (m_video2.Start(this->GetSafeHwnd(), url2, TRUE)) {
            AddStringToListBoxWithWrap(&m_myListBox, L"[VIDEO2] 카메라 2 스트림 시작");
        }
        else {
            AddStringToListBoxWithWrap(&m_myListBox, L"[VIDEO2] ❌ 카메라 2 시작 실패");
        }
    }
}

void CMonitoringProgramView::StopVideo()
{
    m_video.Stop();
    if (m_hbmVideo) {
        CStatic* pPic = (CStatic*)GetDlgItem(IDC_VIDEO1);
        if (pPic && ::IsWindow(pPic->m_hWnd)) {
            HBITMAP hOld = (HBITMAP)pPic->SendMessage(STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)nullptr);
            if (hOld) ::DeleteObject(hOld);
        }
        ::DeleteObject(m_hbmVideo);
        m_hbmVideo = nullptr;
    }

    m_video2.Stop();
    if (m_hbmVideo2) {
        CStatic* pPic2 = (CStatic*)GetDlgItem(IDC_VIDEO2);
        if (pPic2 && ::IsWindow(pPic2->m_hWnd)) {
            HBITMAP hOld = (HBITMAP)pPic2->SendMessage(STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)nullptr);
            if (hOld) ::DeleteObject(hOld);
        }
        ::DeleteObject(m_hbmVideo2);
        m_hbmVideo2 = nullptr;
    }

    if (m_gdiInited) {
        GdiplusShutdown(m_gdiplusToken);
        m_gdiInited = false;
        m_gdiplusToken = 0;
    }
}

LRESULT CMonitoringProgramView::OnVideoStatus(WPARAM wParam, LPARAM)
{
    if (wParam) AddStringToListBoxWithWrap(&m_myListBox, L"[VIDEO1] 연결됨");
    else        AddStringToListBoxWithWrap(&m_myListBox, L"[VIDEO1] 연결 끊김");
    return 0;
}

LRESULT CMonitoringProgramView::OnVideoFrame(WPARAM wParam, LPARAM)
{
    std::unique_ptr<std::vector<BYTE>> frame((std::vector<BYTE>*)wParam);
    if (!frame || frame->empty()) return 0;

    CStatic* pPic = (CStatic*)GetDlgItem(IDC_VIDEO1);
    if (!pPic || !::IsWindow(pPic->m_hWnd)) return 0;

    HGLOBAL hMem = ::GlobalAlloc(GMEM_MOVEABLE, frame->size());
    if (!hMem) return 0;
    void* p = ::GlobalLock(hMem);
    if (!p) { ::GlobalFree(hMem); return 0; }
    memcpy(p, frame->data(), frame->size());
    ::GlobalUnlock(hMem);

    IStream* pStream = nullptr;
    if (CreateStreamOnHGlobal(hMem, TRUE, &pStream) != S_OK) {
        ::GlobalFree(hMem);
        return 0;
    }

    std::unique_ptr<Bitmap> bmp(Bitmap::FromStream(pStream));
    pStream->Release();
    if (!bmp || bmp->GetLastStatus() != Ok) return 0;

    CRect rc; pPic->GetClientRect(&rc);
    HBITMAP hScaled = CreateScaledHBitmap(bmp.get(), rc.Width(), rc.Height());
    if (!hScaled) return 0;

    HBITMAP hOld = (HBITMAP)pPic->SendMessage(STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hScaled);
    if (hOld) ::DeleteObject(hOld);
    if (m_hbmVideo) ::DeleteObject(m_hbmVideo);
    m_hbmVideo = hScaled;

    return 0;
}

LRESULT CMonitoringProgramView::OnVideoStatus2(WPARAM wParam, LPARAM)
{
    if (wParam) AddStringToListBoxWithWrap(&m_myListBox, L"[VIDEO2] 연결됨");
    else        AddStringToListBoxWithWrap(&m_myListBox, L"[VIDEO2] 연결 끊김");
    return 0;
}

LRESULT CMonitoringProgramView::OnVideoFrame2(WPARAM wParam, LPARAM)
{
    std::unique_ptr<std::vector<BYTE>> frame((std::vector<BYTE>*)wParam);
    if (!frame || frame->empty()) return 0;

    CStatic* pPic = (CStatic*)GetDlgItem(IDC_VIDEO2);
    if (!pPic || !::IsWindow(pPic->m_hWnd)) return 0;

    HGLOBAL hMem = ::GlobalAlloc(GMEM_MOVEABLE, frame->size());
    if (!hMem) return 0;
    void* p = ::GlobalLock(hMem);
    if (!p) { ::GlobalFree(hMem); return 0; }
    memcpy(p, frame->data(), frame->size());
    ::GlobalUnlock(hMem);

    IStream* pStream = nullptr;
    if (CreateStreamOnHGlobal(hMem, TRUE, &pStream) != S_OK) {
        ::GlobalFree(hMem);
        return 0;
    }

    std::unique_ptr<Bitmap> bmp(Bitmap::FromStream(pStream));
    pStream->Release();
    if (!bmp || bmp->GetLastStatus() != Ok) return 0;

    CRect rc; pPic->GetClientRect(&rc);
    HBITMAP hScaled = CreateScaledHBitmap(bmp.get(), rc.Width(), rc.Height());
    if (!hScaled) return 0;

    HBITMAP hOld = (HBITMAP)pPic->SendMessage(STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hScaled);
    if (hOld) ::DeleteObject(hOld);
    if (m_hbmVideo2) ::DeleteObject(m_hbmVideo2);
    m_hbmVideo2 = hScaled;

    return 0;
}


HBITMAP CMonitoringProgramView::CreateScaledHBitmap(Gdiplus::Bitmap* bmp, int dstW, int dstH)
{
    if (!bmp || dstW <= 0 || dstH <= 0) return nullptr;

    Bitmap scaled(dstW, dstH, PixelFormat24bppRGB);
    Graphics g(&scaled);

    g.SetInterpolationMode(InterpolationModeHighQualityBicubic);
    g.SetSmoothingMode(SmoothingModeHighQuality);

    g.DrawImage(bmp, Rect(0, 0, dstW, dstH));

    HBITMAP hOut = nullptr;
    scaled.GetHBITMAP(Color(0, 0, 0), &hOut);
    return hOut;
}

void CMonitoringProgramView::OnBnClickedEnvButton() // 온도 습도
{
    m_bEnvVisible = !m_bEnvVisible;
    int nEnvShow = m_bEnvVisible ? SW_SHOW : SW_HIDE;

    GetDlgItem(IDC_ENV_GROUP_STATIC)->ShowWindow(nEnvShow);
    GetDlgItem(IDC_ENV_LABEL_STATIC)->ShowWindow(nEnvShow);
    GetDlgItem(IDC_HUMI_VALUE_STATIC)->ShowWindow(nEnvShow);
    GetDlgItem(IDC_TEMP_VALUE_STATIC)->ShowWindow(nEnvShow);
}

void CMonitoringProgramView::OnBnClickedVideoButton() // 카메라
{
    m_bVideoVisible = !m_bVideoVisible;
    int nVideoShow = m_bVideoVisible ? SW_SHOW : SW_HIDE;

    GetDlgItem(IDC_CAMERA1_STATIC)->ShowWindow(nVideoShow);
    GetDlgItem(IDC_CAMERA2_STATIC)->ShowWindow(nVideoShow);
    GetDlgItem(IDC_VIDEO1)->ShowWindow(nVideoShow);
    GetDlgItem(IDC_VIDEO2)->ShowWindow(nVideoShow);
    GetDlgItem(IDC_MAIN_VIDEO_STATIC)->ShowWindow(nVideoShow);
}

void CMonitoringProgramView::OnBnClickedConveyorButton()
{
	m_bConveyorVisible = !m_bConveyorVisible;
    int nConveyorShow = m_bConveyorVisible ? SW_SHOW : SW_HIDE;

    GetDlgItem(IDC_CONVEYOR_START_BUTTON)->ShowWindow(nConveyorShow);
    GetDlgItem(IDC_CONVEYOR_STOP_BUTTON)->ShowWindow(nConveyorShow);
}

void CMonitoringProgramView::UpdateEnvironmentData()
{
    //  HTTP 요청으로 온습도 가져오기
    HINTERNET hSession = nullptr;
    HINTERNET hConnect = nullptr;
    HINTERNET hRequest = nullptr;

    try {
        hSession = WinHttpOpen(L"MFC/1.0",
            WINHTTP_ACCESS_TYPE_NO_PROXY,
            WINHTTP_NO_PROXY_NAME,
            WINHTTP_NO_PROXY_BYPASS, 0);

        if (!hSession) return;

        // 타임아웃 설정 (1초)
        DWORD timeout = 1000;
        WinHttpSetTimeouts(hSession, timeout, timeout, timeout, timeout);

        hConnect = WinHttpConnect(hSession, IP, 8000, 0);
        if (!hConnect) {
            WinHttpCloseHandle(hSession);
            return;
        }

        hRequest = WinHttpOpenRequest(hConnect,
            L"GET",
            L"/api/environment",
            nullptr,
            WINHTTP_NO_REFERER,
            WINHTTP_DEFAULT_ACCEPT_TYPES,
            0);

        if (!hRequest) {
            WinHttpCloseHandle(hConnect);
            WinHttpCloseHandle(hSession);
            return;
        }

        if (!WinHttpSendRequest(hRequest,
            WINHTTP_NO_ADDITIONAL_HEADERS, 0,
            WINHTTP_NO_REQUEST_DATA, 0, 0, 0)) {
            WinHttpCloseHandle(hRequest);
            WinHttpCloseHandle(hConnect);
            WinHttpCloseHandle(hSession);
            return;
        }

        if (!WinHttpReceiveResponse(hRequest, nullptr)) {
            WinHttpCloseHandle(hRequest);
            WinHttpCloseHandle(hConnect);
            WinHttpCloseHandle(hSession);
            return;
        }

        // 응답 읽기
        std::string response;
        DWORD dwSize = 0;
        DWORD dwRead = 0;

        do {
            dwSize = 0;
            if (!WinHttpQueryDataAvailable(hRequest, &dwSize))
                break;

            if (dwSize == 0)
                break;

            std::vector<char> buffer(dwSize + 1, 0);

            if (WinHttpReadData(hRequest, buffer.data(), dwSize, &dwRead)) {
                response.append(buffer.data(), dwRead);
            }

        } while (dwSize > 0);

        //  간단한 JSON 파싱
        if (!response.empty()) {
            // "temperature": 값 추출
            size_t tempPos = response.find("\"temperature\":");
            size_t humiPos = response.find("\"humidity\":");

            if (tempPos != std::string::npos && humiPos != std::string::npos) {
                // temperature 추출
                tempPos += 14;  // "temperature": 길이
                size_t tempEnd = response.find_first_of(",}", tempPos);
                std::string tempStr = response.substr(tempPos, tempEnd - tempPos);

                // 공백 제거
                tempStr.erase(0, tempStr.find_first_not_of(" \t\n\r"));
                tempStr.erase(tempStr.find_last_not_of(" \t\n\r") + 1);

                // humidity 추출
                humiPos += 11;  // "humidity": 길이
                size_t humiEnd = response.find_first_of(",}", humiPos);
                std::string humiStr = response.substr(humiPos, humiEnd - humiPos);

                // 공백 제거
                humiStr.erase(0, humiStr.find_first_not_of(" \t\n\r"));
                humiStr.erase(humiStr.find_last_not_of(" \t\n\r") + 1);

                //  Static 컨트롤에 표시
                try {
                    double temp = std::stod(tempStr);
                    double humi = std::stod(humiStr);

                    CString tempText;
                    tempText.Format(L"%.1f", temp);
                    GetDlgItem(IDC_TEMP_VALUE_STATIC)->SetWindowText(tempText);

                    CString humiText;
                    humiText.Format(L"%.1f", humi);
                    GetDlgItem(IDC_HUMI_VALUE_STATIC)->SetWindowText(humiText);
                }
                catch (...) {
                    // 파싱 오류 무시
                }
            }
        }

        WinHttpCloseHandle(hRequest);
        WinHttpCloseHandle(hConnect);
        WinHttpCloseHandle(hSession);
    }
    catch (...) {
        // 오류 발생 시 정리
        if (hRequest) WinHttpCloseHandle(hRequest);
        if (hConnect) WinHttpCloseHandle(hConnect);
        if (hSession) WinHttpCloseHandle(hSession);
    }
}

void CMonitoringProgramView::OnBnClickedConveyorStart()
{
    if (!Conveyor_Start()) {
        AfxMessageBox(L"컨베이어 시작 실패");
        return;
    }
    // 성공 시 필요하면 로그/토스트
}

void CMonitoringProgramView::OnBnClickedConveyorStop()
{
    if (!Conveyor_Stop()) {
        AfxMessageBox(L"컨베이어 정지 실패");
        return;
    }
}


#ifdef _DEBUG
void CMonitoringProgramView::AssertValid() const
{
    CFormView::AssertValid();
}

void CMonitoringProgramView::Dump(CDumpContext& dc) const
{
    CFormView::Dump(dc);
}

CMonitoringProgramDoc* CMonitoringProgramView::GetDocument() const
{
    ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMonitoringProgramDoc)));
    return (CMonitoringProgramDoc*)m_pDocument;
}
#endif