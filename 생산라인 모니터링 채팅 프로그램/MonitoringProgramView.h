#pragma once
#include "CChatListBox.h"
#include "ChatClient.h"
#include "VideoClient.h"
#include <gdiplus.h>
#include "ConveyorControl.h"

#pragma comment(lib, "gdiplus.lib")
#pragma comment(lib, "winhttp.lib")  //  WinHTTP 라이브러리 추가

class CMonitoringProgramDoc;

class CMonitoringProgramView : public CFormView
{

protected:
    CMonitoringProgramView() noexcept;
    DECLARE_DYNCREATE(CMonitoringProgramView)
public: // 컨베이어 벨트 제어 버튼 핸들러 함수
    afx_msg void OnBnClickedConveyorStart();
    afx_msg void OnBnClickedConveyorStop();
public:
#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_MONITORINGPROGRAM_FORM };
#endif

    CMonitoringProgramDoc* GetDocument() const;

protected:
    virtual void DoDataExchange(CDataExchange* pDX);
    virtual void OnInitialUpdate();

public:
    virtual ~CMonitoringProgramView();

#ifdef _DEBUG
    virtual void AssertValid() const;
    virtual void Dump(CDumpContext& dc) const;
#endif

protected:
    DECLARE_MESSAGE_MAP()

    // --- UI ---
    CChatListBox m_myListBox;
    CFont        m_Font;

    // --- 채팅 통신 ---
    ChatClient   m_chatClient;

    // --- 재연결 타이머 ---
    UINT_PTR m_nTimerID = 0;

    //  온습도 타이머 추가
    UINT_PTR m_nEnvTimerID = 0;

    // --- 로그인 정보 ---
    CString m_empNo;
    CString m_password;

    // --- 유틸 ---
    void AddStringToListBoxWithWrap(CListBox* pListBox, const CString& text);

    //  온습도 업데이트 함수 추가
    void UpdateEnvironmentData();

public:
    // --- 메시지/핸들러 ---
    afx_msg void OnBnClickedChatButton();
    virtual BOOL PreTranslateMessage(MSG* pMsg);
    afx_msg LRESULT OnChatMessage(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnConnectionStatus(WPARAM wParam, LPARAM lParam);
    afx_msg void OnTimer(UINT_PTR nIDEvent);
    afx_msg void OnDestroy();

private:
    // --- 카메라 ---
    CVideoClient m_video;
    CVideoClient m_video2;
    HBITMAP      m_hbmVideo = nullptr;
    HBITMAP      m_hbmVideo2 = nullptr;

    ULONG_PTR    m_gdiplusToken = 0;
    bool         m_gdiInited = false;

    // --- 중복 로그인 ---
    BOOL m_bDuplicateLogin = FALSE;

protected:
    // --- 카메라 핸들러 ---
    afx_msg LRESULT OnVideoFrame(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnVideoStatus(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnVideoFrame2(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnVideoStatus2(WPARAM wParam, LPARAM lParam);

    void StartVideo();
    void StopVideo();
    HBITMAP CreateScaledHBitmap(Gdiplus::Bitmap* bmp, int dstW, int dstH);

public:
    afx_msg void OnBnClickedEnvButton();

    // --- 메인 화면 OnOff 버튼 ---
private:
    BOOL m_bEnvVisible = TRUE;
    BOOL m_bVideoVisible = TRUE;
	BOOL m_bConveyorVisible = FALSE;

public:
    afx_msg void OnBnClickedVideoButton();
    afx_msg void OnBnClickedConveyorButton();
};

#ifndef _DEBUG
inline CMonitoringProgramDoc* CMonitoringProgramView::GetDocument() const
{
    return reinterpret_cast<CMonitoringProgramDoc*>(m_pDocument);
}
#endif