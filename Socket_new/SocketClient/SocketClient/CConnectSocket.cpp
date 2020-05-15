// CConnectSocket.cpp: 구현 파일
//

#include "pch.h"
#include "SocketClient.h"
#include "CConnectSocket.h"
#include "SocketClientDlg.h"

// CConnectSocket

CConnectSocket::CConnectSocket()
{
	
}

CConnectSocket::~CConnectSocket()
{
}

// CConnectSocket 멤버 함수

void CConnectSocket::OnClose(int nErrorCode)
{
	ShutDown();
	Close();

	CSocket::OnClose(nErrorCode);

	AfxMessageBox(_T("error : Disconnected from server!"));
	::PostQuitMessage(0);
}

// 소켓에 데이터가 들어왔을 때
void CConnectSocket::OnReceive(int nErrorCode)
{
	TCHAR szBuffer[1024];
	::ZeroMemory(szBuffer, sizeof(szBuffer));

	/*
	별명 설정 기능 추가 전
	if (Receive(szBuffer, sizeof(szBuffer))
	{
		CSocketClientDlg* pMain = (CSocketClientDlg*)AfxGetMainWnd();
		// 리스트에 문자열을 추가한다
		pMain->m_List.AddString(szBuffer);
		pMain->m_List.SetCurSel(pMain->m_List.GetCount() - 1);
	}
	*/

	// 닉네임 설정 가능 기능 추가
	if (Receive(szBuffer, sizeof(szBuffer)) > 0)
	{
		// 메시지를 받고
		CSocketClientDlg* pMain = (CSocketClientDlg*)AfxGetMainWnd();
		int cnt = pMain->m_List.GetCount();
		int cnt2 = pMain->m_List2.GetCount();
		//int cnt2 = pMain->m_List2.GetCount();
		CString originText = szBuffer;

		CString RecName = pMain->name;
		RecName = L"[" + RecName + L"]:";

		if (originText.Find(RecName) != -1)
		{
			// 메시지 발신자가 자신이면 메시지 버퍼만 가져오기
			CString SendMsg = originText;
			SendMsg.Delete(0, pMain->name.GetLength() + 3);
			SendMsg += " : 나";
			pMain->m_List2.InsertString(cnt2, SendMsg);
			pMain->m_List.InsertString(cnt, L"\r\n");
		}
		else
		{
			//originText = L"  " + originText;	// 아니면 앞에 공백 처리
			CString RcivMsg = originText;
			int MsgStartPos = RcivMsg.Find(']');
			RcivMsg.Delete(0, MsgStartPos + 1);

			CString FromWho = originText;
			FromWho.Delete(MsgStartPos, FromWho.GetLength());
			FromWho.Delete(0, 1);
			FromWho += "님 ";

			pMain->m_List.InsertString(cnt, (LPCTSTR)(FromWho + RcivMsg));
			pMain->m_List2.InsertString(cnt2, L"\r\n");
		}
		//pMain->m_List.InsertString(cnt, originText);

		pMain->checknew = 1;


	}
	CSocket::OnReceive(nErrorCode);
}



