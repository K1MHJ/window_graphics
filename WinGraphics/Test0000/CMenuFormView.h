#pragma once



// CMenuFormView form view

class CMenuFormView : public CFormView
{
	DECLARE_DYNCREATE(CMenuFormView)

protected:
	CMenuFormView();           // protected constructor used by dynamic creation
	virtual ~CMenuFormView();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD =  };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};


