// lib_d2d.h : main header file for the lib_d2d DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// Clibd2dApp
// See lib_d2d.cpp for the implementation of this class
//

class Clibd2dApp : public CWinApp
{
public:
	Clibd2dApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
