#pragma once
#include <afxsock.h>
class CListenSocket :
	public CAsyncSocket
{
public:
	CListenSocket();
	virtual ~CListenSocket();

public:
	// 클라이언트를 관리하는 리스트
	CPtrList m_ptrClientSocketList;
	// 서버-클라이언트의 연결을 담당
	void onAccept(int nErrorCode);
	// 클라이언트의 연결을 종료
	void closeClientSocket(CSocket* pClient);
	// 클라이언트의 메시지를 다른 클라이언트에게 전송
	void sendAllMessage(TCHAR* pszMessage);
};

