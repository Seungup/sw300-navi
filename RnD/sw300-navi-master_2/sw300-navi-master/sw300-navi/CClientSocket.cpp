#include "pch.h"
#include "CClientSocket.h"
#include "sw300-naviDlg.h"

CClientSocket::CClientSocket()
{
}

CClientSocket::~CClientSocket()
{
}

void CClientSocket::SetListenSocket(CAsyncSocket* pSocket)
{
	m_pListenSocket = pSocket;
}

void CClientSocket::OnClose(int nErrorCode)
{
	CSocket::OnClose(nErrorCode);

	CListenSocket* pServerSocket = (CListenSocket*)m_pListenSocket;
	pServerSocket->CloseClientSocket(this);

}

void CClientSocket::OnReceive(int nErrorCode)
{
	CString strTmp = _T(""), strIPAddress = _T("");
	UINT uPortNumber = 0;
	TCHAR strBuffer[1024];
	::ZeroMemory(strBuffer, sizeof(strBuffer));	// :: ���̰� �Ⱥ��̰� ����?

	GetPeerName(strIPAddress, uPortNumber);

	// ���޵� ������(���ڿ�)�� ���� ���
	if (Receive(strBuffer, sizeof(strBuffer)) > 0)
	{
		Csw300naviDlg* pMain = (Csw300naviDlg*)AfxGetMainWnd();
		strTmp.Format(_T("[%s:%d]: %s"), strIPAddress, uPortNumber, strBuffer);

		// �޽��� ����Ʈ(�޽���â?)�� �Է¹��� �޽��� ����
		pMain->m_List.AddString(strTmp);
		pMain->m_List.SetCurSel(pMain->m_List.GetCount() - 1);

		CListenSocket* pServerSocket = (CListenSocket*)m_pListenSocket;
		// �ٸ� Ŭ���̾�Ʈ�鿡�� �޽��� ����
		pServerSocket->SendAllMessage(strBuffer);
	}

	CSocket::OnReceive(nErrorCode);
}
