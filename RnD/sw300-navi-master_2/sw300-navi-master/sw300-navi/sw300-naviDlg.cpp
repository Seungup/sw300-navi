
// sw300-naviDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "sw300-navi.h"
#include "sw300-naviDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Csw300naviDlg 대화 상자



Csw300naviDlg::Csw300naviDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SW300NAVI_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

Csw300naviDlg::~Csw300naviDlg()
{
	for (auto lastFriend : friendList)
	{
		delete lastFriend;
	}

}

void Csw300naviDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

void Csw300naviDlg::addFriend(string name, string IP)
{
	
	friendList.push_back(new Friend(name, IP));

}

Friend* Csw300naviDlg::searchFriend(string name)
{
	for (auto tempFriend : friendList)
	{
		if (tempFriend->getName().compare(name) == 0)
			return tempFriend;
	}
	return nullptr;
}

void Csw300naviDlg::deleteFreind(string name)
{

}

void Csw300naviDlg::addChatDialog()
{
}

BEGIN_MESSAGE_MAP(Csw300naviDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_LBN_SELCHANGE(IDC_LIST1, &Csw300naviDlg::OnLbnSelchangeList1)
	//ON_BN_CLICKED(IDC_BUTT, &Csw300naviDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_CreateRoom, &Csw300naviDlg::OnBnClickedCreateroom)
END_MESSAGE_MAP()


// Csw300naviDlg 메시지 처리기

BOOL Csw300naviDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	//clientList = (CListBox*)GetDlgItem(IDC_CLIENT_LIST);

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	if (m_ListenSocket.Create(21000, SOCK_STREAM))	// (포트, 데이터전송타입 TCP)
	{
		if (!m_ListenSocket.Listen())
		{
			AfxMessageBox(_T("ERROR : Listen() return False"));
		}
	}

	else
	{
		AfxMessageBox(_T("ERROR : Failed to create server socket!"));	//
	}


	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void Csw300naviDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void Csw300naviDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR Csw300naviDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Csw300naviDlg::OnLbnSelchangeList1()
{


}


void Csw300naviDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Csw300naviDlg::OnBnClickedCreateroom()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	// add server logic
	if (m_ListenSocket.Create(21000, SOCK_STREAM))	// (포트, 데이터전송타입 TCP)
	{
		if (!m_ListenSocket.Listen())
		{
			AfxMessageBox(_T("ERROR : Listen() return False"));
		}
	}

}

void Csw300naviDlg::OnDestroy()
{
	CDialog::OnDestroy();

	POSITION pos;

	pos = m_ListenSocket.m_ptrClientSocketList.GetHeadPosition();
	CClientSocket* pClient = NULL;

	// 생성되어있는 클라이언트 소켓이 없을 때까지 체크하여 소켓닫기
	while (pos != NULL)
	{
		pClient = (CClientSocket*)m_ListenSocket.m_ptrClientSocketList.GetNext(pos);
		if (pClient != NULL)
		{
			pClient->ShutDown();
			pClient->Close();

			delete pClient;
		}
	}
	m_ListenSocket.ShutDown();
	m_ListenSocket.Close();

}
