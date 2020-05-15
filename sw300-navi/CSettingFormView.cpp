// CSettingFormView.cpp: 구현 파일
//

#include "pch.h"
#include "sw300-navi.h"
#include "CSettingFormView.h"
#include "afxdialogex.h"


// CSettingFormView 대화 상자

IMPLEMENT_DYNAMIC(CSettingFormView, CDialogEx)

CSettingFormView::CSettingFormView(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Setting_DIALOG, pParent)
{

}

CSettingFormView::~CSettingFormView()
{
}

void CSettingFormView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSettingFormView, CDialogEx)
END_MESSAGE_MAP()


// CSettingFormView 메시지 처리기
