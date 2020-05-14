#pragma once
#include <afxsock.h>
#include "CListenSocket.h"

class CClientSocket :
	public CSocket
{
public:
	CClientSocket();
	virtual ~CClientSocket();

	void setListenSocket(CAsyncSocket* pSocket);
	void onClose(int nErrorCode);
	void onReceive(int nErrorCode);

	CAsyncSocket* m_pListenSocket;
};

