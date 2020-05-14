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

void CListenSocket::onAccept(int nErrorCode)
{
	CClientSocket* pClient = new CClientSocket;
	CString str;

	// 클라이언트 접속 요청이 오면 서버-클라이언트를 연결시켜준다
	if (Accept(*pClient))
	{
		pClient->setListenSocket(this);
		// 리스트에 클라이언트 소켓 저장
		m_ptrClientSocketList.AddTail(pClient);

		//CSocektServerDlg의 핸들을 가져옴
		Csw300naviDlg* pMain = (Csw300naviDlg*)AfxGetMainWnd();
		// 클라이언트 번호(POSITION(주소) 값)
		str.Format(_T("Client (%d)"), (int)m_ptrClientSocketList.Find(pClient));
		// 클라이언트가 접속할 때마다 리스트에 클라이언트 이름 추가
		pMain->clientList->AddString(str);
	}
	else
	{
		delete pClient;
		AfxMessageBox(_T("ERROR : Failed can't accept new Client!"));
	}

	CAsyncSocket::OnAccept(nErrorCode);
}

void CListenSocket::closeClientSocket(CSocket* pClient)
{
	POSITION pos;
	pos = m_ptrClientSocketList.Find(pClient);

	if (pos != NULL)
	{
		if (pClient != NULL)
		{
			// 클라이언트 연결 중지 후 종료
			pClient->ShutDown();
			pClient->Close();
		}

		Csw300naviDlg* pMain = (Csw300naviDlg*)AfxGetMainWnd();
		CString str1, str2;
		UINT indx = 0, posNum;
		pMain->clientList->SetCurSel(0);

		// 접속 종료되는 클라이언트 찾기
		while (indx < pMain->clientList->GetCount())
		{
			posNum = (int)m_ptrClientSocketList.Find(pClient);
			pMain->clientList->GetText(indx, str1);
			str2.Format(_T("%d"), posNum);

			// 소켓리스트, 클라이언트리스트를 비교해서 같은 클라이언트 번호(POSITION 값) 있으면 리스트에서 삭제
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

void CListenSocket::sendAllMessage(TCHAR* pszMessage)
{
	POSITION pos;
	pos = m_ptrClientSocketList.GetHeadPosition();
	CClientSocket* pClient = NULL;

	while (pos != NULL)
	{
		pClient = (CClientSocket*)m_ptrClientSocketList.GetNext(pos);
		if (pClient != NULL)
		{
			// Send 함수의 두번째 인자는 메모리의 크기인데 유니코드를 사용하고 있으므로 *2를 한 크기가 된다
			// 이 함수는 전송한 데이터의 길이를 반환한다.
			int checkLenOfData = pClient->Send(pszMessage, lstrlen(pszMessage) * 2);
			if (checkLenOfData != lstrlen(pszMessage) * 2)
			{
				AfxMessageBox(_T("일부 데이터가 정상적으로 전송되지 못했습니다!"));
			}
		}
	}
}
