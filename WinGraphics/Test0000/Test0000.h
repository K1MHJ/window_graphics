
// Test0000.h : main header file for the Test0000 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CTest0000App:
// See Test0000.cpp for the implementation of this class
//

class CTest0000App : public CWinApp
{
public:
	CTest0000App() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CTest0000App theApp;
