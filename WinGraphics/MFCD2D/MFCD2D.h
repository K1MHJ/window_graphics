
// MFCD2D.h : main header file for the MFCD2D application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMFCD2DApp:
// See MFCD2D.cpp for the implementation of this class
//

class CMFCD2DApp : public CWinApp
{
public:
	CMFCD2DApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCD2DApp theApp;
