#pragma once
#include <afxsock.h>
class CListenSocket :
	public CAsyncSocket
{
public:
	CListenSocket();
	virtual ~CListenSocket();

public:
	// Ŭ���̾�Ʈ�� �����ϴ� ����Ʈ
	CPtrList m_ptrClientSocketList;
	// ����-Ŭ���̾�Ʈ�� ������ ���
	void OnAccept(int nErrorCode);
	// Ŭ���̾�Ʈ�� ������ ����
	void CloseClientSocket(CSocket* pClient);
	// Ŭ���̾�Ʈ�� �޽����� �ٸ� Ŭ���̾�Ʈ���� ����
	void SendAllMessage(TCHAR* pszMessage);
};

