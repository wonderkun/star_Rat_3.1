#if !defined(AFX_DDOSFLOOD_H__35FA8DF5_A3AC_4387_8859_3BD17A1DDE1C__INCLUDED_)
#define AFX_DDOSFLOOD_H__35FA8DF5_A3AC_4387_8859_3BD17A1DDE1C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DDOSFlood.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDDOSFlood form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CDDOSFlood : public CFormView
{
protected:
	CDDOSFlood();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CDDOSFlood)
// 	WORD ForMatFlowAddr(LPSTR szAddr,WORD iPort);
// Form Data
public:
	//{{AFX_DATA(CDDOSFlood)
	enum { IDD = IDD_DDOS_FLOOD };
	CSpinButtonCtrl	m_spin_flood_time;
	CSpinButtonCtrl	m_spin_flood_thread;
	CSpinButtonCtrl	m_spin_flood_host;
	CComboBox	m_combo_flood_modle;
	BOOL	m_check_flood_auto;
	BOOL	m_check_flood_online;
	CString	m_flood_dns;
	int		m_flood_hostnum;
	int		m_flood_port;
	int		m_flood_thread;
	int		m_flood_time;
	//}}AFX_DATA

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDDOSFlood)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CDDOSFlood();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CDDOSFlood)
	afx_msg void OnFloodStart();
	afx_msg void OnFloodStop();
	afx_msg void OnSlectAll();
	afx_msg void OnSlectNow();
	afx_msg void OnUnslectAll();
	afx_msg void OnUnslectNow();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DDOSFLOOD_H__35FA8DF5_A3AC_4387_8859_3BD17A1DDE1C__INCLUDED_)
