
// Calcex.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CCalcexApp:
// See Calcex.cpp for the implementation of this class
//

class CCalcexApp : public CWinApp
{
public:
	CCalcexApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
//	CString show;
};

extern CCalcexApp theApp;