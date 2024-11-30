
// Test0000View.cpp : implementation of the CTest0000View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Test0000.h"
#endif

#include "Test0000Doc.h"
#include "Test0000View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTest0000View

IMPLEMENT_DYNCREATE(CTest0000View, CView)

BEGIN_MESSAGE_MAP(CTest0000View, CView)
END_MESSAGE_MAP()

// CTest0000View construction/destruction

CTest0000View::CTest0000View() noexcept
{
	// TODO: add construction code here

}

CTest0000View::~CTest0000View()
{
}

BOOL CTest0000View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CTest0000View drawing

void CTest0000View::OnDraw(CDC* /*pDC*/)
{
	CTest0000Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CTest0000View diagnostics

#ifdef _DEBUG
void CTest0000View::AssertValid() const
{
	CView::AssertValid();
}

void CTest0000View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTest0000Doc* CTest0000View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTest0000Doc)));
	return (CTest0000Doc*)m_pDocument;
}
#endif //_DEBUG


// CTest0000View message handlers
