
// D2DGraphicsView.cpp : implementation of the CD2DGraphicsView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "D2DGraphics.h"
#endif

#include "D2DGraphicsDoc.h"
#include "D2DGraphicsView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



// CD2DGraphicsView

IMPLEMENT_DYNCREATE(CD2DGraphicsView, CView)

BEGIN_MESSAGE_MAP(CD2DGraphicsView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_REGISTERED_MESSAGE(AFX_WM_DRAW2D, &CD2DGraphicsView::OnDraw2D)
END_MESSAGE_MAP()

// CD2DGraphicsView construction/destruction

CD2DGraphicsView::CD2DGraphicsView() noexcept
{
	// TODO: add construction code here

	// Enable Direct2D
	this->EnableD2DSupport();
}

CD2DGraphicsView::~CD2DGraphicsView()
{
}

BOOL CD2DGraphicsView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CD2DGraphicsView drawing

void CD2DGraphicsView::OnDraw(CDC* /*pDC*/)
{
	CD2DGraphicsDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}

void CD2DGraphicsView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CD2DGraphicsView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CD2DGraphicsView diagnostics

#ifdef _DEBUG
void CD2DGraphicsView::AssertValid() const
{
	CView::AssertValid();
}

void CD2DGraphicsView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CD2DGraphicsDoc* CD2DGraphicsView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CD2DGraphicsDoc)));
	return (CD2DGraphicsDoc*)m_pDocument;
}
#endif //_DEBUG


// CD2DGraphicsView message handlers


afx_msg LRESULT CD2DGraphicsView::OnDraw2D(WPARAM wParam, LPARAM lParam)
{
	this->m_RenderEngine.Initialize(this);

	return TRUE;
}
