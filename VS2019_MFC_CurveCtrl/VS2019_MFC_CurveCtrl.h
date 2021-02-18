
// VS2019_MFC_CurveCtrl.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CVS2019MFCCurveCtrlApp:
// See VS2019_MFC_CurveCtrl.cpp for the implementation of this class
//

class CVS2019MFCCurveCtrlApp : public CWinApp
{
public:
	CVS2019MFCCurveCtrlApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CVS2019MFCCurveCtrlApp theApp;
