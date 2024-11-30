
// MFCApplication1View.h : interface of the CMFCApplication1View class
//

#pragma once
#include <thread>


class CMFCApplication1View : public CView
{
protected: // create from serialization only
	CMFCApplication1View() noexcept;
	DECLARE_DYNCREATE(CMFCApplication1View)

// Attributes
public:
	CMFCApplication1Doc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CMFCApplication1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
public:
	CDC dcMem; // メモリデバイスコンテキスト
	CBitmap* pOldBitmap; // ストックビットマップ
	CBitmap* pBitmap; // ビットマップ
protected:
	std::thread th1;
// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
	afx_msg void OnDestroy();
};

#ifndef _DEBUG  // debug version in MFCApplication1View.cpp
inline CMFCApplication1Doc* CMFCApplication1View::GetDocument() const
   { return reinterpret_cast<CMFCApplication1Doc*>(m_pDocument); }
#endif

