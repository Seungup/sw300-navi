// CCheatingFormView.cpp: 구현 파일
//

#include "pch.h"
#include "sw300-navi.h"
#include "CCheatingFormView.h"
#include "afxdialogex.h"


// CCheatingFormView 대화 상자

IMPLEMENT_DYNAMIC(CCheatingFormView, CDialogEx)

CCheatingFormView::CCheatingFormView(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Chat_DIALOG, pParent)
{

}

CCheatingFormView::~CCheatingFormView()
{
}

void CCheatingFormView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CCheatingFormView, CDialogEx)
END_MESSAGE_MAP()


// CCheatingFormView 메시지 처리기
