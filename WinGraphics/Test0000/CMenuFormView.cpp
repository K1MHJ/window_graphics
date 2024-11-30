// CMenuFormView.cpp : implementation file
//

#include "pch.h"
#include "Test0000.h"
#include "CMenuFormView.h"


// CMenuFormView

IMPLEMENT_DYNCREATE(CMenuFormView, CFormView)

CMenuFormView::CMenuFormView()
	: CFormView(IDD_FORMVIEW)
{

}

CMenuFormView::~CMenuFormView()
{
}

void CMenuFormView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMenuFormView, CFormView)
END_MESSAGE_MAP()


// CMenuFormView diagnostics

#ifdef _DEBUG
void CMenuFormView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CMenuFormView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CMenuFormView message handlers
