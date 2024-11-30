
// Test0000View.h : interface of the CTest0000View class
//

#pragma once
#include "Test0000Doc.h"

class CTest0000View : public CView
{
protected: // create from serialization only
	CTest0000View() noexcept;
	DECLARE_DYNCREATE(CTest0000View)

// Attributes
public:
	CTest0000Doc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CTest0000View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Test0000View.cpp
inline CTest0000Doc* CTest0000View::GetDocument() const
   { return reinterpret_cast<CTest0000Doc*>(m_pDocument); }
#endif

