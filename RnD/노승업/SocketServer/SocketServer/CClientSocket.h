#pragma once
#include "CListenSocket.h"

// CClientSocket 명령 대상

// 클라이언트의 메시지를 수신하는 클래스(동기)
class CClientSocket : public CSocket
{
public:
	CClientSocket();
	virtual ~CClientSocket();

	void SetListenSocket(CAsyncSocket* pSocket);
	void OnClose(int nErrorCode);
	void OnReceive(int nErrorCode);

	CAsyncSocket* m_pListenSocket;
};


