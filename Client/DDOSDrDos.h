#if !defined(AFX_DDOSDRDOS_H__36F525ED_6BB3_43C1_9647_00E0BFE5031F__INCLUDED_)
#define AFX_DDOSDRDOS_H__36F525ED_6BB3_43C1_9647_00E0BFE5031F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DDOSDrDos.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDDOSDrDos form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CDDOSDrDos : public CFormView
{
protected:
	CDDOSDrDos();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CDDOSDrDos)

// Form Data
public:
	//{{AFX_DATA(CDDOSDrDos)
	enum { IDD = IDD_DDOS_DRDOS };
	CSpinButtonCtrl	m_spin_drdos_time;
	CSpinButtonCtrl	m_spin_drdos_host;
	BOOL	m_check_drdos_auto;
	BOOL	m_check_drdos_online;
	CString	m_drdos_addr;
	CString	m_drdos_dns;
	int		m_drdos_hostnum;
	int		m_drdos_time;
	//}}AFX_DATA

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDDOSDrDos)
	public:
		virtual void OnInitialUpdate();
	protected:
		virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
		//}}AFX_VIRTUAL
		
		// Implementation
	protected:
		virtual ~CDDOSDrDos();
#ifdef _DEBUG
		virtual void AssertValid() const;
		virtual void Dump(CDumpContext& dc) const;
#endif
		
		// Generated message map functions
		//{{AFX_MSG(CDDOSDrDos)
		afx_msg void OnDrdosStart();
		afx_msg void OnDrdosStop();
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

#endif // !defined(AFX_DDOSDRDOS_H__36F525ED_6BB3_43C1_9647_00E0BFE5031F__INCLUDED_)
