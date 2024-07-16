
// MFCD2DView.h : interface of the CMFCD2DView class
//

#pragma once


class CMFCD2DView : public CView
{
protected: // create from serialization only
	CMFCD2DView() noexcept;
	DECLARE_DYNCREATE(CMFCD2DView)

// Attributes
public:
	CMFCD2DDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CMFCD2DView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
	afx_msg LRESULT OnDraw2D(WPARAM wParam, LPARAM lParam);
};

#ifndef _DEBUG  // debug version in MFCD2DView.cpp
inline CMFCD2DDoc* CMFCD2DView::GetDocument() const
   { return reinterpret_cast<CMFCD2DDoc*>(m_pDocument); }
#endif

