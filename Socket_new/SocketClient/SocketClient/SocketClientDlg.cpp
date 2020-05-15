
// SocketClientDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "SocketClient.h"
#include "SocketClientDlg.h"
#include "afxdialogex.h"
#include "CAlias.h"

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


// CSocketClientDlg 대화 상자



CSocketClientDlg::CSocketClientDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SOCKETCLIENT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSocketClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_List);
	DDX_Control(pDX, IDC_LIST2, m_List2);
}

BEGIN_MESSAGE_MAP(CSocketClientDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CSocketClientDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CSocketClientDlg::OnBnClickedButton2)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CSocketClientDlg 메시지 처리기

BOOL CSocketClientDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

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
	CButton* button1 = (CButton*)GetDlgItem(IDOK);
	CButton* button2 = (CButton*)GetDlgItem(IDCANCEL);
	button1->DestroyWindow();
	button2->DestroyWindow();

	SetTimer(1, 100, NULL);

	// 서버 접속
	// TEST 내 컴퓨터에 접속 ip 127.0.0.1


	m_Socket.Create();
	if (m_Socket.Connect(connetIP, 21000) == FALSE)
	{
		AfxMessageBox(_T("ERROR : Failed to connect Server"));
		PostQuitMessage(0);
		return FALSE;
	}

	CAlias dialog1 = new CAlias();
	dialog1.DoModal();

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CSocketClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSocketClientDlg::OnPaint()
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
HCURSOR CSocketClientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSocketClientDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	checknew = 0;
	CString str;

	UpdateData(TRUE);
	GetDlgItemText(IDC_INPUT, str);
	m_Socket.Send((LPVOID)(LPCTSTR)str, str.GetLength() * 2);
	str.Format(_T(""));
	SetDlgItemText(IDC_INPUT, str);
	UpdateData(FALSE);
	/*CString nickName;
	GetDlgItemText(IDC_EDIT1, nickName);

	CEdit* test = (CEdit*)GetDlgItem(IDC_INPUT);
	test->GetWindowTextW(str);
	m_Socket.Send((LPVOID)(LPCTSTR)str, str.GetLength() * 2);
	test->SetWindowTextW(_T(""));*/
}


void CSocketClientDlg::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CAlias dialog1 = new CAlias();
	dialog1.DoModal();
}

//void CSocketClientDlg::OnTimer(UINT_PTR nIDEvent)
//{
//	if (checknew == 1)
//	{
//		// 추가한 개수를 얻어옴
//		int line = m_List.GetCount();
//		// 얻어온 개수로 스크롤
//		m_List.SetTopIndex(line - 1);
//		checknew = 0;
//	}
//
//	CDialogEx::OnTimer(nIDEvent);
//}

BOOL CSocketClientDlg::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == WM_KEYDOWN)
	{
		if (pMsg->wParam == VK_RETURN)
		{
			OnBnClickedButton1();
			return true;
		}
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}


void CSocketClientDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (checknew == 1)
	{
		// 추가한 개수를 얻어옴
		int line = m_List.GetCount();
		int line2 = m_List2.GetCount();
		// 얻어온 개수로 스크롤
		m_List.SetTopIndex(line - 1);
		m_List2.SetTopIndex(line2 - 1);
		checknew = 0;
	}
	CDialogEx::OnTimer(nIDEvent);
}
