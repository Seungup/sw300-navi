
// SocketServerDlg.h: 헤더 파일
//

#pragma once
#include "CListenSocket.h"
#include "afxwin.h"
//#include "CClientSocket.h"

// CSocketServerDlg 대화 상자
class CSocketServerDlg : public CDialogEx
{
// 생성입니다.
public:
	CSocketServerDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

	// 소켓 생성 객체
	CListenSocket m_ListenSocket;

	//현재 접속한 클라이언트를 보여주는 CListBox 객체
	CListBox* clientList;

	// 프로그램 종료 시 소켓 닫기
	void OnDestroy();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SOCKETSERVER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListBox m_List;	// 메시지 리스트 변수
};
