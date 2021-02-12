// Client.h : main header file for the Client application
//

#if !defined(AFX_Client_H__C0496689_B41C_45DE_9F46_75A916C86D38__INCLUDED_)
#define AFX_Client_H__C0496689_B41C_45DE_9F46_75A916C86D38__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols
/////////////////////////////////////////////////////////////////////////////
// CClientApp:
// See Client.cpp for the implementation of this class
//
#include "IniFile.h"
class CClientApp : public CWinApp
{
public:
	CIniFile	m_IniFile;
	// ClientContext地址为主键
	bool m_bIsQQwryExist;
	bool m_bIsDisablePopTips;
	CView*		m_pConnectView; // 主连接视图
	CClientApp();
	HMODULE m_Hmodule;
	DWORD GetRand();
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClientApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CClientApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_Client_H__C0496689_B41C_45DE_9F46_75A916C86D38__INCLUDED_)
