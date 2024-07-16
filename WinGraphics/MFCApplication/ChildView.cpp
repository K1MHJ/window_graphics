
// ChildView.cpp : implementation of the CChildView class
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication.h"
#include "ChildView.h"

#include <ddraw.h>

#pragma comment(lib, "ddraw.lib")
#pragma comment(lib, "dxguid.lib")

bool init;
LPDIRECTDRAW7        g_pDD = NULL;
LPDIRECTDRAWSURFACE7 g_pDDSPrimary = NULL;
LPDIRECTDRAWSURFACE7 g_pDDSBack = NULL;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
HRESULT InitDirectDraw(HWND hWnd)
{
    if (FAILED(DirectDrawCreateEx(NULL, (void**)&g_pDD, IID_IDirectDraw7, NULL)))
    {
        return E_FAIL;
    }

    if (FAILED(g_pDD->SetCooperativeLevel(hWnd, DDSCL_NORMAL)))
    {
        return E_FAIL;
    }

    DDSURFACEDESC2 ddsd;
    ZeroMemory(&ddsd, sizeof(ddsd));
    ddsd.dwSize = sizeof(ddsd);
    ddsd.dwFlags = DDSD_CAPS;
    ddsd.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE;

    if (FAILED(g_pDD->CreateSurface(&ddsd, &g_pDDSPrimary, NULL)))
    {
        return E_FAIL;
    }

    ddsd.dwFlags = DDSD_CAPS | DDSD_WIDTH | DDSD_HEIGHT;
    ddsd.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN;
    ddsd.dwWidth = 640;
    ddsd.dwHeight = 480;

    if (FAILED(g_pDD->CreateSurface(&ddsd, &g_pDDSBack, NULL)))
    {
        return E_FAIL;
    }

    return S_OK;
}
void CleanupDirectDraw()
{
    if (g_pDDSBack) g_pDDSBack->Release();
    if (g_pDDSPrimary) g_pDDSPrimary->Release();
    if (g_pDD) g_pDD->Release();
}

void Render()
{
    if (!g_pDDSBack) return;

    DDBLTFX ddbltfx;
    ZeroMemory(&ddbltfx, sizeof(ddbltfx));
    ddbltfx.dwSize = sizeof(ddbltfx);
    ddbltfx.dwFillColor = RGB(255, 255, 0); // Yellow color

    g_pDDSBack->Blt(NULL, NULL, NULL, DDBLT_COLORFILL | DDBLT_WAIT, &ddbltfx);

    RECT rcRect;
    GetClientRect(GetForegroundWindow(), &rcRect);
    POINT pt = { 0, 0 };
    ClientToScreen(GetForegroundWindow(), &pt);
    OffsetRect(&rcRect, pt.x, pt.y);

    g_pDDSPrimary->Blt(&rcRect, g_pDDSBack, NULL, DDBLT_WAIT, NULL);
}



// CChildView

CChildView::CChildView()
{
    init = false;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_CREATE()
    ON_WM_DESTROY()
END_MESSAGE_MAP()



// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
    if (!init) {
        InitDirectDraw(this->GetSafeHwnd());
        init = true;
    }
    Render();
    ValidateRect(NULL);

	// Do not call CWnd::OnPaint() for painting messages
}



int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
    
    
	return 0;
}


void CChildView::OnDestroy()
{
    CWnd::OnDestroy();

    // TODO: Add your message handler code here
    CleanupDirectDraw();
}
