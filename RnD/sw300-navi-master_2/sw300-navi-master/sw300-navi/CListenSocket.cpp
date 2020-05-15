#include "pch.h"
#include "CListenSocket.h"
#include "CClientSocket.h"
#include "sw300-naviDlg.h"

CListenSocket::CListenSocket()
{
}

CListenSocket::~CListenSocket()
{
}

void CListenSocket::OnAccept(int nErrorCode)
{
	CClientSocket* pClient = new CClientSocket;
	CString str;

	// Ŭ���̾�Ʈ ���� ��û�� ���� ����-Ŭ���̾�Ʈ�� ��������ش�
	if (Accept(*pClient))
	{
		pClient->SetListenSocket(this);
		// ����Ʈ�� Ŭ���̾�Ʈ ���� ����
		m_ptrClientSocketList.AddTail(pClient);

		//CSocektServerDlg�� �ڵ��� ������
		Csw300naviDlg* pMain = (Csw300naviDlg*)AfxGetMainWnd();
		// Ŭ���̾�Ʈ ��ȣ(POSITION(�ּ�) ��)
		str.Format(_T("Client (%d)"), (int)m_ptrClientSocketList.Find(pClient));
		// Ŭ���̾�Ʈ�� ������ ������ ����Ʈ�� Ŭ���̾�Ʈ �̸� �߰�
		pMain->clientList->AddString(str);
	}
	else
	{
		delete pClient;
		AfxMessageBox(_T("ERROR : Failed can't accept new Client!"));
	}

	CAsyncSocket::OnAccept(nErrorCode);
}

void CListenSocket::CloseClientSocket(CSocket* pClient)
{
	POSITION pos;
	pos = m_ptrClientSocketList.Find(pClient);

	if (pos != NULL)
	{
		if (pClient != NULL)
		{
			// Ŭ���̾�Ʈ ���� ���� �� ����
			pClient->ShutDown();
			pClient->Close();
		}

		Csw300naviDlg* pMain = (Csw300naviDlg*)AfxGetMainWnd();
		CString str1, str2;
		UINT indx = 0, posNum;
		pMain->clientList->SetCurSel(0);

		// ���� ����Ǵ� Ŭ���̾�Ʈ ã��
		while (indx < pMain->clientList->GetCount())
		{
			posNum = (int)m_ptrClientSocketList.Find(pClient);
			pMain->clientList->GetText(indx, str1);
			str2.Format(_T("%d"), posNum);

			// ���ϸ���Ʈ, Ŭ���̾�Ʈ����Ʈ�� ���ؼ� ���� Ŭ���̾�Ʈ ��ȣ(POSITION ��) ������ ����Ʈ���� ����
			if (str1.Find(str2) != -1)
			{
				AfxMessageBox(str1 + str2);
				pMain->clientList->DeleteString(indx);
				break;
			}
			indx++;
		}

		m_ptrClientSocketList.RemoveAt(pos);
		delete pClient;
	}
}

void CListenSocket::SendAllMessage(TCHAR* pszMessage)
{
	POSITION pos;
	pos = m_ptrClientSocketList.GetHeadPosition();
	CClientSocket* pClient = NULL;

	while (pos != NULL)
	{
		pClient = (CClientSocket*)m_ptrClientSocketList.GetNext(pos);
		if (pClient != NULL)
		{
			// Send �Լ��� �ι�° ���ڴ� �޸��� ũ���ε� �����ڵ带 ����ϰ� �����Ƿ� *2�� �� ũ�Ⱑ �ȴ�
			// �� �Լ��� ������ �������� ���̸� ��ȯ�Ѵ�.
			int checkLenOfData = pClient->Send(pszMessage, lstrlen(pszMessage) * 2);
			if (checkLenOfData != lstrlen(pszMessage) * 2)
			{
				AfxMessageBox(_T("�Ϻ� �����Ͱ� ���������� ���۵��� ���߽��ϴ�!"));
			}
		}
	}
}
