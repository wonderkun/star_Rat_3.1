// XTPListCtrlView.h interface for the CXTPListView and CXTPListCtrlView class.
//
// (c)1998-2020 Codejock Software, All Rights Reserved.
//
// THIS SOURCE FILE IS THE PROPERTY OF CODEJOCK SOFTWARE AND IS NOT TO BE
// RE-DISTRIBUTED BY ANY MEANS WHATSOEVER WITHOUT THE EXPRESSED WRITTEN
// CONSENT OF CODEJOCK SOFTWARE.
//
// THIS SOURCE CODE CAN ONLY BE USED UNDER THE TERMS AND CONDITIONS OUTLINED
// IN THE XTREME TOOLKIT PRO LICENSE AGREEMENT. CODEJOCK SOFTWARE GRANTS TO
// YOU (ONE SOFTWARE DEVELOPER) THE LIMITED RIGHT TO USE THIS SOFTWARE ON A
// SINGLE COMPUTER.
//
// CONTACT INFORMATION:
// support@codejock.com
// http://www.codejock.com
//
/////////////////////////////////////////////////////////////////////////////

//{{AFX_CODEJOCK_PRIVATE
#if !defined(__XTPLISTVIEW_H__)
#	define __XTPLISTVIEW_H__
//}}AFX_CODEJOCK_PRIVATE

#	if _MSC_VER >= 1000
#		pragma once
#	endif // _MSC_VER >= 1000

#	include "Common/Base/Diagnostic/XTPDisableNoisyWarnings.h"

DECLARE_LIST_BASE(CXTPListViewBase, CListView, CXTPListBase)
DECLARE_LIST_BASE(CXTPListCtrlBase, CListCtrl, CXTPListBase)

//===========================================================================
// Summary:
//     CXTPListView is a multiple inheritance class derived from CListView and
//     CXTPListBase. This class implements flat header and generic sorting
//     routines.
// See Also: CXTPListBase
//===========================================================================
class _XTP_EXT_CLASS CXTPListView : public CXTPListViewBase
{
	DECLARE_DYNCREATE(CXTPListView)

public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPListView object
	//-----------------------------------------------------------------------
	CXTPListView();

	//-----------------------------------------------------------------------
	// Summary:
	//     Destroys a CXTPListView object, handles cleanup and deallocation
	//-----------------------------------------------------------------------
	virtual ~CXTPListView();

protected:
	DECLARE_MESSAGE_MAP()
};

//---------------------------------------------------------------------------
// Summary:
//     CXTPListCtrl is a multiple inheritance class derived from CListCtrl and
//     CXTPListBase. This class implements flat header and generic sorting
//     routines. See CXTPListBase for additional functionality.
// See Also: CXTPListBase
//---------------------------------------------------------------------------
class _XTP_EXT_CLASS CXTPListCtrl : public CXTPListCtrlBase
{
	DECLARE_DYNAMIC(CXTPListCtrl)

public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPListCtrl object
	//-----------------------------------------------------------------------
	CXTPListCtrl();

	//-----------------------------------------------------------------------
	// Summary:
	//     Destroys a CXTPListCtrl object, handles cleanup and deallocation
	//-----------------------------------------------------------------------
	virtual ~CXTPListCtrl();

protected:
	DECLARE_MESSAGE_MAP()
};

//=======================================================================
// Summary:
//	An adaptor for any CListCtrl derived control that overrides standard scroll bars with custom
// scroll
// bars.
// Parameters:
//	ListBase - base CListCtrl derived class name.
// See also:
//	CXTPScrollable
//=======================================================================
template<class ListBase>
class CXTPScrollableListCtrlT : public CXTPScrollable<ListBase>
{
public:
	//-----------------------------------------------------------------------
	// Summary:
	//	Initializes scrollable control instance.
	//-----------------------------------------------------------------------
	CXTPScrollableListCtrlT();

protected:
	//{{AFX_CODEJOCK_PRIVATE
	virtual BOOL HasVScroll(DWORD dwStyle, DWORD dwExStyle) const;
	virtual BOOL HasHScroll(DWORD dwStyle, DWORD dwExStyle) const;
	virtual BOOL OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	//}}AFX_CODEJOCK_PRIVATE
};

//-----------------------------------------------------------------------
// Summary:
//	Type alias for CXTPListCtrl derived scrollable control.
//-----------------------------------------------------------------------
typedef CXTPScrollableListCtrlT<CXTPListCtrl> CXTPScrollableListCtrl;

template<class ListBase>
AFX_INLINE CXTPScrollableListCtrlT<ListBase>::CXTPScrollableListCtrlT()
{
	ASSERT(GetRuntimeClass()->IsDerivedFrom(RUNTIME_CLASS(CListCtrl)));
}

template<class ListBase>
AFX_INLINE BOOL CXTPScrollableListCtrlT<ListBase>::HasVScroll(DWORD dwStyle, DWORD dwExStyle) const
{
	UNREFERENCED_PARAMETER(dwExStyle);
	return 0 == (dwStyle & LVS_NOSCROLL);
}

template<class ListBase>
AFX_INLINE BOOL CXTPScrollableListCtrlT<ListBase>::HasHScroll(DWORD dwStyle, DWORD dwExStyle) const
{
	UNREFERENCED_PARAMETER(dwExStyle);
	return 0 == (dwStyle & LVS_NOSCROLL);
}

//{{AFX_CODEJOCK_PRIVATE
_XTP_EXT_CLASS BOOL AFXAPI XTPOnScrollableListCtrlWndMsg(UINT message, WPARAM wParam, LPARAM lParam,
														 LRESULT* pResult, CWnd* pEmbeddedControl);
//}}AFX_CODEJOCK_PRIVATE

template<class ListBase>
AFX_INLINE BOOL CXTPScrollableListCtrlT<ListBase>::OnWndMsg(UINT message, WPARAM wParam,
															LPARAM lParam, LRESULT* pResult)
{
	if (XTPOnScrollableListCtrlWndMsg(message, wParam, lParam, pResult, GetEmbeddedControl()))
		return TRUE;

	return CXTPScrollable<ListBase>::OnWndMsg(message, wParam, lParam, pResult);
}

#	include "Common/Base/Diagnostic/XTPEnableNoisyWarnings.h"
#endif // #if !defined(__XTPLISTVIEW_H__)
