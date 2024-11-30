
// MainFrm.cpp : implementation of the CMainFrame class
//

#include "pch.h"
#include "framework.h"
#include "Test0000.h"

#include "MainFrm.h"
#include "Test0000View.h"
#include "CMenuFormView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

extern CTest0000View* g_pView;

// CSplitterX
BEGIN_MESSAGE_MAP(CSplitterX, CSplitterWnd)
	ON_WM_NCHITTEST()
END_MESSAGE_MAP()

CSplitterX::CSplitterX(){}
CSplitterX::~CSplitterX(){}

LRESULT CSplitterX::OnNcHitTest(CPoint point)
{
	return HTNOWHERE;
}

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame construction/destruction

CMainFrame::CMainFrame() noexcept
{
	// TODO: add member initialization code here
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: Delete these three lines if you don't want the toolbar to be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);


	return 0;
}

BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT /*lpcs*/,
	CCreateContext* pContext)
{
	CRect rect;
	GetClientRect(&rect);

	if (!m_wndSplitter.CreateStatic(this, 1, 2))
		return FALSE;
	int nSizeX = rect.right - rect.left;
	int nMenuSize = nSizeX / 6;
	if (!m_wndSplitter.CreateView(0, 0, RUNTIME_CLASS(CTest0000View), CSize(nSizeX - nMenuSize, 0), pContext))
		return FALSE;
	if (!m_wndSplitter.CreateView(0, 1, RUNTIME_CLASS(CMenuFormView), CSize(nMenuSize, 0), pContext))
		return FALSE;
	return TRUE;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame message handlers

