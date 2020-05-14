#include "pch.h"
#include "CClientSocket.h"
#include "sw300-naviDlg.h"

CClientSocket::CClientSocket()
{
}

CClientSocket::~CClientSocket()
{
}

void CClientSocket::setListenSocket(CAsyncSocket* pSocket)
{
	m_pListenSocket = pSocket;
}

void CClientSocket::onClose(int nErrorCode)
{
	CSocket::OnClose(nErrorCode);

	CListenSocket* pServerSocket = (CListenSocket*)m_pListenSocket;
	pServerSocket->closeClientSocket(this);

}

void CClientSocket::onReceive(int nErrorCode)
{
	CString strTmp = _T(""), strIPAddress = _T("");
	UINT uPortNumber = 0;
	TCHAR strBuffer[1024];
	::ZeroMemory(strBuffer, sizeof(strBuffer));	// :: 붙이고 안붙이고 차이?

	GetPeerName(strIPAddress, uPortNumber);

	// 전달된 데이터(문자열)가 있을 경우
	if (Receive(strBuffer, sizeof(strBuffer)) > 0)
	{
		Csw300naviDlg* pMain = (Csw300naviDlg*)AfxGetMainWnd();
		strTmp.Format(_T("[%s:%d]: %s"), strIPAddress, uPortNumber, strBuffer);

		// 메시지 리스트(메시지창?)에 입력받은 메시지 띄우기
		pMain->m_List.AddString(strTmp);
		pMain->m_List.SetCurSel(pMain->m_List.GetCount() - 1);

		CListenSocket* pServerSocket = (CListenSocket*)m_pListenSocket;
		// 다른 클라이언트들에게 메시지 전달
		pServerSocket->sendAllMessage(strBuffer);
	}

	CSocket::OnReceive(nErrorCode);
}
