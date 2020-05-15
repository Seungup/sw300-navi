// CChlildSetting.cpp: 구현 파일
//

#include "pch.h"
#include "sw300-navi.h"
#include "CChlildSetting.h"
#include "afxdialogex.h"


// CChlildSetting 대화 상자

IMPLEMENT_DYNAMIC(CChlildSetting, CDialogEx)

CChlildSetting::CChlildSetting(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Chat_DIALOG, pParent)
{

}

CChlildSetting::~CChlildSetting()
{
}

void CChlildSetting::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CChlildSetting, CDialogEx)
END_MESSAGE_MAP()


// CChlildSetting 메시지 처리기
