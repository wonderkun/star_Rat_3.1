// ClientView.h : interface of the CClientView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ClientVIEW_H__14553897_2664_48B4_A82B_6D6F8F789ED3__INCLUDED_)
#define AFX_ClientVIEW_H__14553897_2664_48B4_A82B_6D6F8F789ED3__INCLUDED_

#include "ClientDoc.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CClientView : public CView
{
protected: // create from serialization only
	CClientView();
	DECLARE_DYNCREATE(CClientView)

// Attributes
public:
	CClientDoc* GetDocument();
	CXTPTabControl m_wndTabControl;
	BOOL UpDateNumber();
	void UpdateDocTitle();
	BOOL AddGroup( LPCTSTR lpszTitle );
	BOOL AddView(CRuntimeClass* pViewClass, LPCTSTR lpszTitle);
// Operations
public:
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClientView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CClientView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
 
// Generated message map functions
protected:
	//{{AFX_MSG(CClientView)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnAddGroup();
	afx_msg void OnDelGroup();
	//}}AFX_MSG
	afx_msg LRESULT OnAddFindGroup(WPARAM, LPARAM);
	afx_msg void OnSelectedChanged(NMHDR* pNMHDR, LRESULT* pResult);
	DECLARE_MESSAGE_MAP()
private:

};

#ifndef _DEBUG  // debug version in ClientView.cpp
inline CClientDoc* CClientView::GetDocument()
   { return (CClientDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ClientVIEW_H__14553897_2664_48B4_A82B_6D6F8F789ED3__INCLUDED_)
