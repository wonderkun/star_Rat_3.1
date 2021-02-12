#if !defined(AFX_DDOSWEB_H__AE589291_D2F4_463A_AFBF_6AAEDE130971__INCLUDED_)
#define AFX_DDOSWEB_H__AE589291_D2F4_463A_AFBF_6AAEDE130971__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DDOSWeb.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDDOSWeb form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CDDOSWeb : public CFormView
{
protected:
	CDDOSWeb();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CDDOSWeb)

// Form Data
public:
	//{{AFX_DATA(CDDOSWeb)
	enum { IDD = IDD_DDOS_WEB };
	CSpinButtonCtrl	m_spin_web_time;
	CSpinButtonCtrl	m_spin_web_thread;
	CSpinButtonCtrl	m_spin_web_host;
	CComboBox	m_combo_web_modle;
	BOOL	m_check_web_auto;
	BOOL	m_check_web_online;
	int		m_web_cc1;
	int		m_web_cc2;
	CString	m_web_dns;
	int		m_web_hostnum;
	int		m_web_port;
	int		m_web_thread;
	int		m_web_time;
	//}}AFX_DATA

// Attributes
public:

// Operations
public:
	
	// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDDOSWeb)
public:
	virtual void OnInitialUpdate();
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL
	
	// Implementation
protected:
	virtual ~CDDOSWeb();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	
	// Generated message map functions
	//{{AFX_MSG(CDDOSWeb)
	afx_msg void OnWebStart();
	afx_msg void OnWebStop();
	afx_msg void OnSelchangeComboWebmodle();
	afx_msg void OnSlectAll2();
	afx_msg void OnSlectNow2();
	afx_msg void OnUnslectAll2();
	afx_msg void OnUnslectNow2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DDOSWEB_H__AE589291_D2F4_463A_AFBF_6AAEDE130971__INCLUDED_)
