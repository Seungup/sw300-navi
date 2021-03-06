﻿#pragma once


// CAlias 대화 상자

class CAlias : public CDialogEx
{
	DECLARE_DYNAMIC(CAlias)

public:
	CAlias(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CAlias();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedButton3();
	CString medit1;
	CEdit mEditButton;
	CButton IPConfigButton;
	afx_msg void OnStnClickedStaticText();
};
