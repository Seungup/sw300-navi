// Chatting.cpp: 구현 파일
//

#include "pch.h"
#include "sw300-navi.h"
#include "Chatting.h"
#include "afxdialogex.h"


// Chatting 대화 상자

IMPLEMENT_DYNAMIC(Chatting, CDialogEx)

Chatting::Chatting(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Chat_DIALOG, pParent)
{

}

Chatting::~Chatting()
{
}

void Chatting::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SEND, m_btnsend);
}


BEGIN_MESSAGE_MAP(Chatting, CDialogEx)
END_MESSAGE_MAP()


// Chatting 메시지 처리기
