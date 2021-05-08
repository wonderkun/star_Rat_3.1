// XTPTreeCtrlView.h interface for the CXTPTreeView class.
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
#if !defined(__XTPTREEVIEW_H__)
#	define __XTPTREEVIEW_H__
//}}AFX_CODEJOCK_PRIVATE

#	if _MSC_VER > 1000
#		pragma once
#	endif // _MSC_VER > 1000

#	include "Common/Base/Diagnostic/XTPDisableNoisyWarnings.h"

DECLARE_TREE_BASE(CXTPTreeViewBase, CTreeView, CXTPTreeBase)
DECLARE_TREE_BASE(CXTPTreeCtrlBase, CTreeCtrl, CXTPTreeBase)

//===========================================================================
// Summary:
//     CXTPTreeView is a CTreeView derived class. It extends the CTreeView
//     class to add additional functionality, including tree traversal, searching,
//     color, and settings.
//===========================================================================
class _XTP_EXT_CLASS CXTPTreeView : public CXTPTreeViewBase
{
	DECLARE_DYNCREATE(CXTPTreeView)

protected:
	//-----------------------------------------------------------------------
	// Summary:
	//     Protected constructor used by dynamic creation. Constructs a CXTPTreeView
	//     object
	//-----------------------------------------------------------------------
	CXTPTreeView();

	//-----------------------------------------------------------------------
	// Summary:
	//     Destroys a CXTPTreeView object, handles cleanup and deallocation
	//-----------------------------------------------------------------------
	virtual ~CXTPTreeView();

	DECLARE_MESSAGE_MAP()
};

//===========================================================================
// Summary:
//     CXTPTreeCtrl is a CTreeCtrl derived class. It extends the CTreeCtrl
//     class to add additional functionality, including tree traversal, searching,
//     color, and settings.
//===========================================================================
class _XTP_EXT_CLASS CXTPTreeCtrl : public CXTPTreeCtrlBase
{
	DECLARE_DYNAMIC(CXTPTreeCtrl)

public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPTreeCtrl object
	//-----------------------------------------------------------------------
	CXTPTreeCtrl();

	//-----------------------------------------------------------------------
	// Summary:
	//     Destroys a CXTPTreeCtrl object, handles cleanup and deallocation
	//-----------------------------------------------------------------------
	virtual ~CXTPTreeCtrl();

protected:
	DECLARE_MESSAGE_MAP()
};

//=======================================================================
// Summary:
//	An adaptor for any CTreeCtrl derived control that overrides standard scroll bars with custom
// scroll
// bars.
// Parameters:
//	TreeBase - base CTreeCtrl derived class name.
// See also:
//	CXTPScrollable
//=======================================================================
template<class TreeBase>
class CXTPScrollableTreeCtrlT : public CXTPScrollable<TreeBase>
{
public:
	//-----------------------------------------------------------------------
	// Summary:
	//	Initializes scrollable control instance.
	//-----------------------------------------------------------------------
	CXTPScrollableTreeCtrlT();

protected:
	//{{AFX_CODEJOCK_PRIVATE
	virtual BOOL HasVScroll(DWORD dwStyle, DWORD dwExStyle) const;
	virtual BOOL HasHScroll(DWORD dwStyle, DWORD dwExStyle) const;
	virtual void DisableScrollbars();
	virtual void DisableScrollbars(CWnd& wnd);
	//}}AFX_CODEJOCK_PRIVATE
};

//-----------------------------------------------------------------------
// Summary:
//	Type alias for CXTPTreeCtrl derived scrollable control.
//-----------------------------------------------------------------------
typedef CXTPScrollableTreeCtrlT<CXTPTreeCtrl> CXTPScrollableTreeCtrl;

template<class TreeBase>
AFX_INLINE CXTPScrollableTreeCtrlT<TreeBase>::CXTPScrollableTreeCtrlT()
{
	ASSERT(GetRuntimeClass()->IsDerivedFrom(RUNTIME_CLASS(CTreeCtrl)));
}

template<class TreeBase>
AFX_INLINE BOOL CXTPScrollableTreeCtrlT<TreeBase>::HasVScroll(DWORD dwStyle, DWORD dwExStyle) const
{
	UNREFERENCED_PARAMETER(dwExStyle);
	return 0 == (dwStyle & TVS_NOSCROLL);
}

template<class TreeBase>
AFX_INLINE BOOL CXTPScrollableTreeCtrlT<TreeBase>::HasHScroll(DWORD dwStyle, DWORD dwExStyle) const
{
	UNREFERENCED_PARAMETER(dwExStyle);

	const DWORD nTVS_NOHSCROLL = 0x8000;
	return 0 == (dwStyle & (TVS_NOSCROLL | nTVS_NOHSCROLL));
}

template<class TreeBase>
AFX_INLINE void CXTPScrollableTreeCtrlT<TreeBase>::DisableScrollbars()
{
	ModifyStyle(WS_VSCROLL | WS_HSCROLL, 0);
	ModifyStyleEx(WS_EX_LEFTSCROLLBAR, 0);
}

template<class TreeBase>
AFX_INLINE void CXTPScrollableTreeCtrlT<TreeBase>::DisableScrollbars(CWnd& wnd)
{
	UNREFERENCED_PARAMETER(wnd);
	// Do nothing as SysTreeView32 behaves improperly if scroll bars gets disabled repeatedly.
}

#	include "Common/Base/Diagnostic/XTPEnableNoisyWarnings.h"
#endif // !defined(__XTPTREEVIEW_H__)
