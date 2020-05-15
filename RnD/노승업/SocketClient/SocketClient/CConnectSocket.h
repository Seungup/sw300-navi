#pragma once
//#include "SocketClientDlg.h"

// CConnectSocket 명령 대상

class CConnectSocket : public CSocket
{
public:
	CConnectSocket();
	virtual ~CConnectSocket();

public:
	// 프로그램 종료 시 소켓을 끔
	void OnClose(int nErrorCode);
	// 받은 메시지를 메시지창에 출력
	void OnReceive(int nErrorCode);
};


