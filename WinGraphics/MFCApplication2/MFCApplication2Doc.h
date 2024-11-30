// MFCApplication2Doc.h : interface of the CMFCApplication2Doc class
//
#pragma once
#include <deque>
#include <thread>

//typedef struct{
//	int X;
//	int Y;
//}POINT;

class CMFCApplication2Doc : public CDocument
{
protected: // create from serialization only
	CMFCApplication2Doc() noexcept;
	DECLARE_DYNCREATE(CMFCApplication2Doc)

// Attributes
public:
	std::deque<POINT> m_points;
	std::thread th1;

// Operations
public:
	static void ThreadNewFunc(CMFCApplication2Doc* doc);

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CMFCApplication2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
