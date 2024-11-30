
// MFCApplication1.h : main header file for the MFCApplication1 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMFCApplication1App:
// See MFCApplication1.cpp for the implementation of this class
//

class CMFCApplication1App : public CWinApp
{
public:
	CMFCApplication1App() noexcept;
	ULONG_PTR gdiplusToken;

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
	virtual int ExitInstance();
};

extern CMFCApplication1App theApp;
