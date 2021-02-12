#if !defined(AFX_BUILD_H__E851B65B_6C2E_4C5F_9DD1_1D2696CFE2EF__INCLUDED_)
#define AFX_BUILD_H__E851B65B_6C2E_4C5F_9DD1_1D2696CFE2EF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Build.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBuild dialog

class CBuild : public CDialog
{
// Construction
public:
	CBuild(CWnd* pParent = NULL);   // standard constructor
// Dialog Data
	//{{AFX_DATA(CBuild)
	enum { IDD = IDD_BUILD };
	CXTPEdit	m_qqnum;
	CXTPEdit	m_version;
	CXTPComboBox	m_insatll_way;
	CXTPEdit	m_biaozhi;
	CXTPComboBox	m_group_name;
	CXTPEdit	m_ServiceDescription;
	CXTPEdit	m_ServiceDisplayName;
	CXTPEdit	m_ServiceName;
	CXTPEdit	m_port1;
	CXTPEdit	m_host1;
	BOOL	m_green;
	BOOL	m_qq;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBuild)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CBuild)
	virtual BOOL OnInitDialog();
	afx_msg void OnBuild();
	afx_msg void OnSelchangeInstallWay();
	afx_msg void OnGreen();
	afx_msg void OnRandom();
	afx_msg void OnQq();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	bool m_bFirstShow;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BUILD_H__E851B65B_6C2E_4C5F_9DD1_1D2696CFE2EF__INCLUDED_)
