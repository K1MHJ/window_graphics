
// MFCApplication2View.cpp : implementation of the CMFCApplication2View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCApplication2.h"
#endif

#include "MFCApplication2Doc.h"
#include "MFCApplication2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication2View

IMPLEMENT_DYNCREATE(CMFCApplication2View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication2View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_MESSAGE(UM_UPDATE, &CMFCApplication2View::MyUpdate)
	ON_WM_DESTROY()
END_MESSAGE_MAP()

// CMFCApplication2View construction/destruction

CMFCApplication2View::CMFCApplication2View() noexcept
{
	// TODO: add construction code here

}

CMFCApplication2View::~CMFCApplication2View()
{
}

BOOL CMFCApplication2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCApplication2View drawing

void CMFCApplication2View::OnDraw(CDC* pDC)
{
	CMFCApplication2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	CRect cClip; // 更新領域
	int nResult; // 更新領域の取得状況
	nResult = pDC->GetClipBox(&cClip);
	if (nResult == ERROR || nResult == NULLREGION) 
	{ 
		return; 
	}
	pDC->BitBlt(cClip.left, cClip.top,
		cClip.Width(), cClip.Height(),
		&dcMem, cClip.left, cClip.top, SRCCOPY);
}


// CMFCApplication2View printing

BOOL CMFCApplication2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCApplication2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCApplication2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMFCApplication2View diagnostics

#ifdef _DEBUG
void CMFCApplication2View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication2Doc* CMFCApplication2View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication2Doc)));
	return (CMFCApplication2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication2View message handlers
LRESULT CMFCApplication2View::MyUpdate(UINT wParam, LONG lParam)
{
	//TRACE("MyUpdate\n");
	CBrush brush;
	CBrush* oldbrush;
	brush.CreateSolidBrush(RGB(255, 255, 255));
	oldbrush = dcMem.SelectObject(&brush);
	for (auto & i: GetDocument()->m_points) {
		dcMem.Rectangle(i.x, i.y, i.x, i.y);
	}
	dcMem.SelectObject(oldbrush);
	Invalidate();
	return 0;
}


void CMFCApplication2View::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: Add your specialized code here and/or call the base class
	CDC* pDC;//通常のデバイスコンテキストを格納するポインタ
	CBrush cBrush;//ブラシ
	CBrush* pOldBrush;//ブラシのストック変数
	CRect rc;
	GetClientRect(&rc);

	pBitmap = new CBitmap();
	pDC = GetDC();
	dcMem.CreateCompatibleDC(pDC);
	pBitmap->CreateCompatibleBitmap(pDC, rc.Width(), rc.Height());
	pOldBitmap = dcMem.SelectObject(pBitmap);
	cBrush.CreateSolidBrush(RGB(255, 255, 255));
	pOldBrush = dcMem.SelectObject(&cBrush);
	dcMem.PatBlt(0, 0, rc.Width(), rc.Height(), PATCOPY);
	dcMem.SelectObject(pOldBrush);
	ReleaseDC(pDC);
}


void CMFCApplication2View::OnDestroy()
{
	CView::OnDestroy();

	// TODO: Add your message handler code here
	dcMem.SelectObject(pOldBitmap);
	pBitmap->DeleteObject();
	dcMem.DeleteDC();
}
