#pragma once
#include <afxsock.h>
#include "CListenSocket.h"

class CClientSocket :
	public CSocket
{
public:
	CClientSocket();
	virtual ~CClientSocket();

	void SetListenSocket(CAsyncSocket* pSocket);
	void OnClose(int nErrorCode);
	void OnReceive(int nErrorCode);

	CAsyncSocket* m_pListenSocket;
};

