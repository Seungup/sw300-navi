// CClientSocket.cpp: 구현 파일
//

#include "pch.h"
#include "SocketServer.h"
#include "CClientSocket.h"
#include "SocketServerDlg.h"


// CClientSocket
int index = 0;	// 추가
CString alias[100][2];	// 추가

CClientSocket::CClientSocket()
{
}

CClientSocket::~CClientSocket()
{
}

// CClientSocket 멤버 함수

void CClientSocket::SetListenSocket(CAsyncSocket* pSocket)
{
	m_pListenSocket = pSocket;	//?????
}

void CClientSocket::OnClose(int nErrorCode)
{
	CSocket::OnClose(nErrorCode);

	CListenSocket* pServerSocket = (CListenSocket*)m_pListenSocket;
	pServerSocket->CloseClientSocket(this);
}

void CClientSocket::OnReceive(int nErrorCode)	// 소켓에 데이터가 들어왔을 때
{
	int i, check = 0;	// 추가
	CString strTmp = _T(""), strIPAddress = _T("");
	UINT uPortNumber = 0;
	TCHAR strBuffer[1024];
	::ZeroMemory(strBuffer, sizeof(strBuffer));	// :: 붙이고 안붙이고 차이?

	GetPeerName(strIPAddress, uPortNumber);	// ip주소와 포트번호 받기

	/*
	닉네임 받기 없는 버전
	// 전달된 데이터(문자열)가 있을 경우
	if (Receive(strBuffer, sizeof(strBuffer)) > 0)
	{
		CSocketServerDlg* pMain = (CSocketServerDlg*)AfxGetMainWnd();
		strTmp.Format(_T("[%s:%d]: %s"), strIPAddress, uPortNumber, strBuffer);
		
		// 메시지 리스트(메시지창?)에 입력받은 메시지 띄우기
		pMain->m_List.AddString(strTmp);
		pMain->m_List.SetCurSel(pMain->m_List.GetCount() - 1);

		CListenSocket* pServerSocket = (CListenSocket*)m_pListenSocket;
		// 다른 클라이언트들에게 메시지 전달
		pServerSocket->SendAllMessage(strBuffer);
	}
	*/

	// 닉네임 설정 가능 버전
	if (Receive(strBuffer, sizeof(strBuffer)) > 0)
	{
		CSocketServerDlg* pMain = (CSocketServerDlg*)AfxGetMainWnd();

		CString portStr;
		portStr.Format(L"%d", uPortNumber);

		for (i = index - 1; i >= 0; i--)
		{
			if (portStr == alias[i][0])
			{
				// 사용자가 지정한 이름과 매칭
				strTmp.Format(_T("[%s]: %s"), alias[i][1], strBuffer);
				break;
			}
		}

		if (i == -1)
		{
			strTmp.Format(_T("[%s:%d]: %s"), strIPAddress, uPortNumber, strBuffer);
		}

		// 이름 설정하는 신호였다면
		if (strTmp.Find(L"alias:") != -1)
		{
			alias[index][0] = portStr;	// 이름 저장
			CString temp = strBuffer;
			temp.Delete(0, 6);
			alias[index][1] = temp;
			index++;
			check = 1;
		}

		// 이름 설정하는 신호가 아니라면 (메시지 전송)
		if (check == 0)
		{
			int cnt = pMain->m_List.GetCount();
			pMain->m_List.InsertString(cnt, strTmp);
			
			CListenSocket* pServerSocket = (CListenSocket*)m_pListenSocket;

			TCHAR* tChr = (TCHAR*)(LPCTSTR)strTmp;
			pServerSocket->SendAllMessage(tChr);
			// CListenSocket의 SendAllMessage 함수 call
		}
		else
		{
			check = 0;
		}

	}

	CSocket::OnReceive(nErrorCode);
}



