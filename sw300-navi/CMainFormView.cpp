// CMainFormView.cpp: 구현 파일
//

#include "pch.h"
#include "sw300-navi.h"
#include "CMainFormView.h"
#include "afxdialogex.h"


// CMainFormView 대화 상자

IMPLEMENT_DYNAMIC(CMainFormView, CDialogEx)

CMainFormView::CMainFormView(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SW300NAVI_DIALOG, pParent)
{

}

CMainFormView::~CMainFormView()
{
}

void CMainFormView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMainFormView, CDialogEx)
END_MESSAGE_MAP()


// CMainFormView 메시지 처리기
