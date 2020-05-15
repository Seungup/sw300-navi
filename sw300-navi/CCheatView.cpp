// CCheatView.cpp: 구현 파일
//

#include "pch.h"
#include "sw300-navi.h"
#include "CCheatView.h"


// CCheatView

IMPLEMENT_DYNCREATE(CCheatView, CFormView)

CCheatView::CCheatView()
	: CFormView(IDD_Chat_DIALOG)
{

}

CCheatView::~CCheatView()
{
}

void CCheatView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCheatView, CFormView)
END_MESSAGE_MAP()


// CCheatView 진단

#ifdef _DEBUG
void CCheatView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CCheatView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CCheatView 메시지 처리기
