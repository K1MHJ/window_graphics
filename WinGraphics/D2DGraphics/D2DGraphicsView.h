
// D2DGraphicsView.h : interface of the CD2DGraphicsView class
//

#pragma once

#include "RenderEngine.h"

class CD2DGraphicsView : public CView
{
protected: // create from serialization only
	CD2DGraphicsView() noexcept;
	DECLARE_DYNCREATE(CD2DGraphicsView)

// Attributes
public:
	CD2DGraphicsDoc* GetDocument() const;
	
	CRenderEngine m_RenderEngine;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CD2DGraphicsView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
	afx_msg LRESULT OnDraw2D(WPARAM wParam, LPARAM lParam);
};

#ifndef _DEBUG  // debug version in D2DGraphicsView.cpp
inline CD2DGraphicsDoc* CD2DGraphicsView::GetDocument() const
   { return reinterpret_cast<CD2DGraphicsDoc*>(m_pDocument); }
#endif

