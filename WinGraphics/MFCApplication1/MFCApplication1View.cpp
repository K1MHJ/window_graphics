
// MFCApplication1View.cpp : implementation of the CMFCApplication1View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCApplication1.h"
#endif

#include "MFCApplication1Doc.h"
#include "MFCApplication1View.h"

//#ifdef _DEBUG
//#define new DEBUG_NEW
//#endif


// CMFCApplication1View

IMPLEMENT_DYNCREATE(CMFCApplication1View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication1View, CView)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_SIZE()
	ON_WM_MOUSEWHEEL()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_MOUSELEAVE()
END_MESSAGE_MAP()

// CMFCApplication1View construction/destruction

CMFCApplication1View::CMFCApplication1View() noexcept
{
	// TODO: add construction code here

}

CMFCApplication1View::~CMFCApplication1View()
{
}

BOOL CMFCApplication1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCApplication1View drawing

void CMFCApplication1View::OnDraw(CDC* pDC)
{
	CMFCApplication1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	CRect rc;
	GetClientRect(rc);
	Gdiplus::Graphics g(pDC->GetSafeHdc());

	Gdiplus::Rect newRect(0, 0, 
		m_bitmap.get()->GetWidth(), m_bitmap.get()->GetHeight());

	Gdiplus::Rect toZoom(0, 0, rc.Width(), rc.Height());

	g.DrawImage(m_bitmap.get(),
		toZoom,
		m_viewrc.left, m_viewrc.top,
		m_viewrc.Width(), m_viewrc.Height(),
		Gdiplus::UnitPixel);
}


// CMFCApplication1View diagnostics

#ifdef _DEBUG
void CMFCApplication1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication1Doc* CMFCApplication1View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication1Doc)));
	return (CMFCApplication1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication1View message handlers


BOOL CMFCApplication1View::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	// TODO: Add your specialized code here and/or call the base class

	return CView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}


int CMFCApplication1View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	m_viewrc.left = 0;
	m_viewrc.top = 0;
	m_viewrc.right = 0;
	m_viewrc.bottom = 0;
	m_bitmap = BitmapPtr(new Bitmap(1000, 1000));
	Graphics* g = Graphics::FromImage(m_bitmap.get());
	SolidBrush brush(Color(255, 150, 150, 150));
	
	int cellSize = 100;
	int i, j,row;
	row = 0;
	i = 0;
	for (;row < m_bitmap.get()->GetHeight();++i) {
		j = (i % 2 == 0) ? 0 : cellSize;
		for (;j<m_bitmap.get()->GetWidth();j+=2*cellSize) {
			g->FillRectangle(&brush, j, row, cellSize, cellSize);
		}
		row += cellSize;
	}
	return 0;
}


void CMFCApplication1View::OnDestroy()
{
	CView::OnDestroy();

	// TODO: Add your message handler code here
	m_bitmap.reset();
}


void CMFCApplication1View::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	if (m_viewrc.Width() == 0) {
		m_viewrc.right = m_viewrc.left + cx;
	}
	if (m_viewrc.Height() == 0) {
		m_viewrc.bottom = m_viewrc.top + cy;
	}

	double cr = (double)cx / cy;
	double r = (double)m_viewrc.Width() / m_viewrc.Height();
	if (cr > r) {
		double new_width = cr * m_viewrc.Height();
		double new_left = m_viewrc.CenterPoint().x - new_width / 2;
		double new_right = m_viewrc.CenterPoint().x + new_width / 2;
		m_viewrc.left = new_left;
		m_viewrc.right = new_right;
	}
	else {
		double new_height = m_viewrc.Width() / cr;
		double new_top = m_viewrc.CenterPoint().y - new_height / 2;
		double new_bottom = m_viewrc.CenterPoint().y + new_height / 2;
		m_viewrc.top = new_top;
		m_viewrc.bottom = new_bottom;
	}
}


BOOL CMFCApplication1View::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	// TODO: Add your message handler code here and/or call default
	CRect _rc;
	double scale = 0.001;
	m_viewrc.CopyRect(&_rc);
	m_viewrc.left -= scale * _rc.Width() * (zDelta > 0)?1:-1;
	m_viewrc.right+= scale * _rc.Width() * (zDelta > 0)?1:-1;
	m_viewrc.top -= scale * _rc.Height() * (zDelta > 0)?1:-1;
	m_viewrc.bottom += scale * _rc.Height() * (zDelta > 0)?1:-1;
	InvalidateRect(NULL, FALSE);
	return CView::OnMouseWheel(nFlags, zDelta, pt);
}


void CMFCApplication1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CView::OnLButtonDown(nFlags, point);
}


void CMFCApplication1View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CView::OnLButtonUp(nFlags, point);
}


void CMFCApplication1View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CView::OnMouseMove(nFlags, point);
}


void CMFCApplication1View::OnMouseLeave()
{
	// TODO: Add your message handler code here and/or call default

	CView::OnMouseLeave();
}
