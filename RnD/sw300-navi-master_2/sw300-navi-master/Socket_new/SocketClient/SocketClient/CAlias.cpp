// CAlias.cpp: 구현 파일
//

#include "pch.h"
#include "SocketClient.h"
#include "CAlias.h"
#include "afxdialogex.h"
#include "SocketClientDlg.h"


// CAlias 대화 상자

IMPLEMENT_DYNAMIC(CAlias, CDialogEx)

CAlias::CAlias(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, medit1(_T("127.0.0.1"))
{

}

CAlias::~CAlias()
{
}

void CAlias::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, medit1);
	DDX_Control(pDX, IDC_EDIT2, mEditButton);
}


BEGIN_MESSAGE_MAP(CAlias, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CAlias::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT2, &CAlias::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON3, &CAlias::OnBnClickedButton3)
END_MESSAGE_MAP()


// CAlias 메시지 처리기

// 별명 설정 클릭
void CAlias::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	CString alias = L"alias:";


	GetDlgItemText(IDC_EDIT1, str);	// EDIT 컨트롤에 있는 닉네임 값 가져오기

	((CSocketClientDlg*)GetParent())->name = str;

	str = alias + str;

	// alias : 이름    -> 서버로 전송
	// 이 형식의 메시지는 이름 설정용으로 이름 저장됨
	((CSocketClientDlg*)GetParent())->m_Socket.Send((LPVOID)(LPCTSTR)str, str.GetLength() * 2);

	::SendMessage(this->m_hWnd, WM_CLOSE, NULL, NULL);
}

BOOL CAlias::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == WM_KEYDOWN)
	{
		if (pMsg->wParam == VK_RETURN)
		{
			// Enter 키 지원용
			OnBnClickedButton1();
			return true;
		}
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}


void CAlias::OnEnChangeEdit2()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CAlias::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str= L"127.0.0.1";
	GetDlgItemText(IDC_EDIT2, str);
	
	//IP 저장
	((CSocketClientDlg*)GetParent())->connetIP = str;
	
	((CSocketClientDlg*)GetParent())->m_Socket.Create();
	if( ((CSocketClientDlg*)GetParent())->m_Socket.Connect(str, 21000) == FALSE)
	{
		AfxMessageBox(_T("ERROR : Failed to connect Server"));
		PostQuitMessage(0);
		//return FALSE;
	}

}
