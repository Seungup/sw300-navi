#pragma once
#include "CClientSocket.h"

// CListenSocket 명령 대상

// 클라이언트 접속을 기다리고, 메시지를 입력받는 클래스 (비동기)
class CListenSocket : public CAsyncSocket
{
public:
	CListenSocket();
	virtual ~CListenSocket();

	// 클라이언트를 관리하는 리스트
	CPtrList m_ptrClientSocketList;
	// 서버-클라이언트의 연결을 담당
	void OnAccept(int nErrorCode);
	// 클라이언트의 연결을 종료
	void CloseClientSocket(CSocket* pClient);
	// 클라이언트의 메시지를 다른 클라이언트에게 전송
	void SendAllMessage(TCHAR* pszMessage);


};


