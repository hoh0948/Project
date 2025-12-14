#pragma once
#include <afxwin.h>
#include <winhttp.h>
#include <vector>

#pragma comment(lib, "winhttp.lib")

// ===== 카메라 1 메시지 (기존) =====
#ifndef WM_USER_VIDEO_FRAME
#define WM_USER_VIDEO_FRAME   (WM_APP + 1201)
#endif
#ifndef WM_USER_VIDEO_STATUS
#define WM_USER_VIDEO_STATUS  (WM_APP + 1202)
#endif

// ===== 카메라 2 메시지 (신규) =====
#ifndef WM_USER_VIDEO_FRAME2
#define WM_USER_VIDEO_FRAME2  (WM_APP + 1203)
#endif
#ifndef WM_USER_VIDEO_STATUS2
#define WM_USER_VIDEO_STATUS2 (WM_APP + 1204)
#endif

class CVideoClient
{
public:
    CVideoClient();
    ~CVideoClient();

    // useCamera2 파라미터 추가
    BOOL Start(HWND hNotify, LPCWSTR url, BOOL useCamera2 = FALSE);
    void Stop();
    BOOL IsRunning() const { return m_running; }

private:
    static UINT __stdcall ThreadProc(LPVOID pParam);
    void ThreadLoop();

    BOOL OpenWinHttp(HINTERNET& hSession, HINTERNET& hConnect, HINTERNET& hRequest);
    void CloseWinHttp(HINTERNET& hSession, HINTERNET& hConnect, HINTERNET& hRequest);

private:
    HANDLE        m_hThread = nullptr;
    volatile BOOL m_running = FALSE;
    HWND          m_hNotify = nullptr;
    CString       m_url;
    BOOL          m_bUseCamera2 = FALSE;  // 카메라 2 플래그
};