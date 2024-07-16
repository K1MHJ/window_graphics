
// MFCD2DView.cpp : implementation of the CMFCD2DView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCD2D.h"
#endif

#include "MFCD2DDoc.h"
#include "MFCD2DView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCD2DView

IMPLEMENT_DYNCREATE(CMFCD2DView, CView)

BEGIN_MESSAGE_MAP(CMFCD2DView, CView)
	ON_REGISTERED_MESSAGE(AFX_WM_DRAW2D, &CMFCD2DView::OnDraw2D)
END_MESSAGE_MAP()

// CMFCD2DView construction/destruction

CMFCD2DView::CMFCD2DView() noexcept
{
	// TODO: add construction code here
	// Enable Direct2D
	this->EnableD2DSupport();

}

CMFCD2DView::~CMFCD2DView()
{
}

BOOL CMFCD2DView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCD2DView drawing

void CMFCD2DView::OnDraw(CDC* /*pDC*/)
{
	CMFCD2DDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMFCD2DView diagnostics

#ifdef _DEBUG
void CMFCD2DView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCD2DView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCD2DDoc* CMFCD2DView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCD2DDoc)));
	return (CMFCD2DDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCD2DView message handlers


afx_msg LRESULT CMFCD2DView::OnDraw2D(WPARAM wParam, LPARAM lParam)
{
	CHwndRenderTarget* pRenderTarget = (CHwndRenderTarget*)lParam;
	pRenderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
	pRenderTarget->Clear(D2D1::ColorF(D2D1::ColorF::White));
	CD2DSizeF size = pRenderTarget->GetSize();
	CD2DRectF rect(100.0f, 100.0f,
		size.width - 100.0f, size.height - 100.0f);
	pRenderTarget->DrawRectangle(rect, 
		&CD2DSolidColorBrush(pRenderTarget, D2D1::ColorF(D2D1::ColorF::Black)));

	return 0;
}
