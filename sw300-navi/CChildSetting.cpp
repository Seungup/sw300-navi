// CChildSetting.cpp: 구현 파일
//

#include "pch.h"
#include "sw300-navi.h"
#include "CChildSetting.h"
#include "afxdialogex.h"


// CChildSetting 대화 상자

IMPLEMENT_DYNAMIC(CChildSetting, CDialogEx)

CChildSetting::CChildSetting(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Setting_DIALOG, pParent)
{

}

CChildSetting::~CChildSetting()
{
}

void CChildSetting::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CChildSetting, CDialogEx)
END_MESSAGE_MAP()


// CChildSetting 메시지 처리기
