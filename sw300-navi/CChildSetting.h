#pragma once


// CChildSetting 대화 상자

class CChildSetting : public CDialogEx
{
	DECLARE_DYNAMIC(CChildSetting)

public:
	CChildSetting(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CChildSetting();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Setting_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
