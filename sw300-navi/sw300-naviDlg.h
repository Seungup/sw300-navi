
// sw300-naviDlg.h: 헤더 파일
//

#pragma once
#include "Friend.h"
using namespace std;


// Csw300naviDlg 대화 상자
class Csw300naviDlg : public CDialogEx
{
// 생성입니다.
public:
	Csw300naviDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.
	~Csw300naviDlg();
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SW300NAVI_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.

protected:
	vector<Friend*> friendList;
public:
	void addFriend(string name, string IP);
	Friend* searchFriend(string name);
	void deleteFreind(string name);
	void addChatDialog();

// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};
