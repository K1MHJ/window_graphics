
// D2DGraphics.h : main header file for the D2DGraphics application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CD2DGraphicsApp:
// See D2DGraphics.cpp for the implementation of this class
//

class CD2DGraphicsApp : public CWinAppEx
{
public:
	CD2DGraphicsApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CD2DGraphicsApp theApp;
