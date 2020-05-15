#pragma once


// CCheatingFormView 대화 상자

class CCheatingFormView : public CDialogEx
{
	DECLARE_DYNAMIC(CCheatingFormView)

public:
	CCheatingFormView(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CCheatingFormView();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Chat_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
