// XTPDockingPaneDefines.h : public defines, structures and enumerations.
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
#if !defined(__XTPDOCKINGPANEDEFINES_H__)
#	define __XTPDOCKINGPANEDEFINES_H__
//}}AFX_CODEJOCK_PRIVATE

#	if _MSC_VER >= 1000
#		pragma once
#	endif // _MSC_VER >= 1000

#	include "Common/Base/Diagnostic/XTPDisableNoisyWarnings.h"

class CXTPDockingPane;
class CXTPDockingPaneBase;
class CXTPDockingPaneBase;

//-----------------------------------------------------------------------
// Summary:
//     Docking direction enumeration
// Example:
// <code>
// CXTPDockingPane* pwndPane1 = GetDockingPaneManager()->CreatePane(
//     IDR_PANE1, CRect(0, 0, 200, 120), xtpPaneDockTop);
// </code>
// See Also:
//     CXTPDockingPaneManager::CreatePane, CXTPDockingPaneManager
//
// <KEYWORDS xtpPaneDockLeft, xtpPaneDockRight, xtpPaneDockTop, xtpPaneDockBottom>
//-----------------------------------------------------------------------
enum XTPDockingPaneDirection
{
	xtpPaneDockUndefined = -1, // Docking pane direction is unspecified.
	xtpPaneDockLeft,		   // To dock the pane to the left of the pane or frame.
	xtpPaneDockRight,		   // To dock the pane to the right of the pane or frame.
	xtpPaneDockTop,			   // To dock the pane to the top of the pane or frame.
	xtpPaneDockBottom,		   // To dock the pane to the bottom of the pane or frame.
	xtpPaneDockMiniWnd		   // Docking pane is floating mini frame window.
};

//-----------------------------------------------------------------------
// Summary:
//     Docking pane type
// Example:
// <code>
// if (pPane->GetType() == xtpPaneTypeDockingPane)
// {
//     // This is CXTPDockingPane object
// }
// </code>
// See Also: CXTPDockingPaneBase::GetType, CXTPDockingPaneBase
//
// <KEYWORDS xtpPaneTypeDockingPane, xtpPaneTypeTabbedContainer, xtpPaneTypeSplitterContainer,
// xtpPaneTypeMiniWnd, xtpPaneTypeClient, xtpPaneTypeAutoHidePanel>
//-----------------------------------------------------------------------
enum XTPDockingPaneType
{
	xtpPaneTypeDockingPane,		  // Object is the docking pane.
	xtpPaneTypeTabbedContainer,   // Object is the tabbed container.
	xtpPaneTypeSplitterContainer, // Object is the splitter container.
	xtpPaneTypeMiniWnd,			  // Object is the mini window container.
	xtpPaneTypeClient,			  // Object is the pane contained client area.
	xtpPaneTypeAutoHidePanel,	 // Object is the auto hide panel.
	xtpPaneTypeSidePanel		  // Object is the side panel.
};

//-----------------------------------------------------------------------
// Summary:
//     Visual theme enumeration
// Example:
//     <code>m_paneManager.SetTheme(xtpPaneThemeVisualStudio2005Beta1);</code>
// See Also: CXTPDockingPaneManager, CXTPDockingPaneManager::SetTheme
//
// <KEYWORDS xtpPaneThemeDefault, xtpPaneThemeVisualStudio2003, xtpPaneThemeGrippered,
// xtpPaneThemeOffice2002Visio, xtpPaneThemeCustom, xtpPaneThemeOffice2003, xtpPaneThemeWinNative,
// xtpPaneThemeVisualStudio2005Beta1>
//-----------------------------------------------------------------------
enum XTPDockingPanePaintTheme
{
	xtpPaneThemeDefault,							 // Default theme
	xtpPaneThemeVisualStudio2003,					 // Visual Studio 2003 theme
	xtpPaneThemeOffice2003,							 // Office 2003 theme
	xtpPaneThemeWinNative,							 // Windows Native theme
	xtpPaneThemeGrippered,							 // Gripper theme
	xtpPaneThemeOffice2002Visio,					 // Office 2002 Visio theme
	xtpPaneThemeVisualStudio2005Beta1,				 // Visual Studio 2005 Beta 1 theme
	xtpPaneThemeOffice2003Outlook,					 // Office 2003 Outlook theme
	xtpPaneThemeWinExplorer,						 // Windows Explorer theme
	xtpPaneThemeVisualStudio2005,					 // Visual Studio 2005 theme
	xtpPaneThemeResource,							 // Office 2007/2010 theme
	xtpPaneThemeOffice2007Word,						 // Office 2007 Word theme
	xtpPaneThemeOffice2007Outlook,					 // Office 2007 Outlook theme
	xtpPaneThemeVisualStudio6,						 // Visual Studio 6 theme
	xtpPaneThemeVisualStudio2005Beta2,				 // Visual Studio 2005 Beta 2 theme
	xtpPaneThemeVisualStudio2008,					 // Visual Studio 2008 theme
	xtpPaneThemeVisualStudio2010,					 // Visual Studio 2010 Beta 1 theme
	xtpPaneThemeOffice2003Visio,					 // Office 2003 Visio theme
	xtpPaneThemeOffice2007Visio,					 // Office 2007 Visio theme
	xtpPaneThemeOffice2013,							 // Office 2013 pane theme
	xtpPaneThemeOffice2016 = xtpPaneThemeOffice2013, // Office 2016 pane theme
	xtpPaneThemeVisualStudio2012,					 // Visual Studio 2012 theme
	xtpPaneThemeVisualStudio2015,					 // Visual Studio 2015 theme
	xtpPaneThemeCustom,								 // Custom User Defined Theme.
};

//{{AFX_CODEJOCK_PRIVATE
#	define xtpPaneThemeOffice                                                                     \
		xtpPaneThemeVisualStudio2003 // obsolete names, for backward compatibility only.
#	define xtpPaneThemeNativeWinXP xtpPaneThemeWinNative
#	define xtpPaneThemeExplorer xtpPaneThemeWinExplorer
#	define xtpPaneThemeVisio xtpPaneThemeOffice2002Visio
#	define xtpPaneThemeWhidbey xtpPaneThemeVisualStudio2005Beta1
#	define xtpPaneThemeShortcutBar2003 xtpPaneThemeOffice2003Outlook
#	define xtpPaneThemeWord2007 xtpPaneThemeOffice2007Word
#	define xtpPaneThemeOutlook2007 xtpPaneThemeOffice2007Outlook
#	define xtpPaneThemeOffice2007 xtpPaneThemeResource
//}}AFX_CODEJOCK_PRIVATE

//-----------------------------------------------------------------------
// Summary:
//     Docking Panes sticker style  enumeration
// Example:
//     <code>m_paneManager.SetStickerStyle(xtpPaneStickerStyleVisualStudio2005);</code>
//
// <KEYWORDS xtpPaneStickerStyleVisualStudio2005Beta, xtpPaneStickerStyleVisualStudio2005>
//-----------------------------------------------------------------------
enum XTPDockingContextStickerStyle
{
	xtpPaneStickerStyleVisualStudio2005Beta,  // Visual Studio 2005 Beta stickers
	xtpPaneStickerStyleVisualStudio2005,	  // Visual Studio 2005 stickers
	xtpPaneStickerStyleVisualStudio2008,	  // Visual Studio 2008 stickers
	xtpPaneStickerStyleVisualStudio2010,	  // Visual Studio 2010 stickers
	xtpPaneStickerStyleVisualStudio2012Light, // Visual Studio 2012 light stickers
	xtpPaneStickerStyleVisualStudio2012Dark,  // Visual Studio 2012 dark stickers
	xtpPaneStickerStyleVisualStudio2015Light, // Visual Studio 2015 light stickers
	xtpPaneStickerStyleVisualStudio2015Blue,  // Visual Studio 2015 blue stickers
	xtpPaneStickerStyleVisualStudio2015Dark,  // Visual Studio 2015 dark stickers
};

//{{AFX_CODEJOCK_PRIVATE
#	define xtpPaneStickerStyleWhidbey                                                             \
		xtpPaneStickerStyleVisualStudio2005Beta // obsolete name, for backward compatibility only.
//}}AFX_CODEJOCK_PRIVATE

//-----------------------------------------------------------------------
// Summary:
//     Docking Pane Options enumeration
// Example:
// <code>
// // Remove Hide button for all panes
// m_paneManager.SetDefaultPaneOptions(xtpPaneNoHideable);
// // Remove close button for pPane
// pPane->SetOptions(xtpPaneNoCloseable);
// </code>
// See Also: CXTPDockingPaneManager::SetDefaultPaneOptions, CXTPDockingPane::SetOptions
//
// <KEYWORDS xtpPaneNoCloseable, xtpPaneNoHideable, xtpPaneNoFloatable, xtpPaneNoCaption>
//-----------------------------------------------------------------------
enum XTPDockingPaneOptions
{
	xtpPaneNoCloseable				   = 1,  // Pane can't be closed.
	xtpPaneNoHideable				   = 2,  // Pane can't be hidden.
	xtpPaneNoFloatable				   = 4,  // Pane can't be floated.
	xtpPaneNoCaption				   = 8,  // Pane has no caption.
	xtpPaneHasMenuButton			   = 16, // Pane has menu button.
	xtpPaneNoDockable				   = 32, // Pane can't be docked.
	xtpPaneNoFloatableByTabDoubleClick = 64, // Pane can't be floated by a double-click on the tab
											 // button.
	xtpPaneNoFloatableByCaptionDoubleClick = 128, // Pane can't be floated by a double-click on the
												  // pane caption.
	xtpPaneNoHoverShow = 1024
};

//-----------------------------------------------------------------------
// Summary:
//     Docking Pane Caption direction enumeration
// Example:
// <code>
// m_paneManager.SetCaptionDirection(xtpPaneCaptionAutoBySize);
// </code>
// See Also: CXTPDockingPaneManager::SetCaptionDirection
//
// <KEYWORDS xtpPaneCaptionHorizontal, xtpPaneCaptionVertical, xtpPaneCaptionAutoByPosition,
// xtpPaneCaptionAutoBySize>
//-----------------------------------------------------------------------
enum XTPDockingPaneCaptionDirection
{
	xtpPaneCaptionHorizontal,	 // Show caption on top
	xtpPaneCaptionVertical,		  // Show caption on left
	xtpPaneCaptionAutoByPosition, // Automatically
	xtpPaneCaptionAutoBySize	  // Automatically
};

//-----------------------------------------------------------------------
// Summary:
//     Actions a docking pane is currently performing.
// Example:
// <code>
// BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
//     ON_MESSAGE(XTPWM_DOCKINGPANE_NOTIFY, OnDockingPaneNotify)
// END_MESSAGE_MAP()
//
// LRESULT CMainFrame::OnDockingPaneNotify(WPARAM wParam, LPARAM lParam)
// {
//     if (wParam == XTP_DPN_ACTION)
//     {
//         XTP_DOCKINGPANE_ACTION* pAction = (XTP_DOCKINGPANE_ACTION*)lParam;
//         TRACE("Action %i\n", pAction->action);
//         return TRUE;
//     }
//     return FALSE;
// }
// </code>
// See Also: XTP_DOCKINGPANE_ACTION, XTP_DPN_ACTION
//
// <KEYWORDS xtpPaneActionFloating, xtpPaneActionFloated, xtpPaneActionClosing, xtpPaneActionClosed,
// xtpPaneActionDocking, xtpPaneActionDocked, xtpPaneActionAttaching, xtpPaneActionAttached,
// xtpPaneActionPinning, xtpPaneActionPinned, xtpPaneActionCollapsing, xtpPaneActionCollapsed,
// xtpPaneActionExpanding, xtpPaneActionExpanded>
//-----------------------------------------------------------------------
enum XTPDockingPaneAction
{
	xtpPaneActionFloating,  // Docking pane is currently floating.  This occurs when the user clicks
							// on the title bar of a docking pane and drags the pane to another
							// location.  When this occurs, the pane is said to be "floating."
	xtpPaneActionFloated,   // Docking pane has been docked, and is currently floating.
	xtpPaneActionClosing,   // Docking pane is currently closing.  This occurs when the close button
							// of the pane is clicked.
	xtpPaneActionClosed,	// Docking pane has been closed.  This occurs when the docking pane has
							// finished closing.
	xtpPaneActionDocking,   // Docking pane is in the process of docking.
	xtpPaneActionDocked,	// Docking pane has been docked.  This occurs when the docking pane has
							// finished docking.
	xtpPaneActionAttaching, // Docking pane is in the process of attaching to another pane.
	xtpPaneActionAttached, // Docking pane has been attached.  This occurs when the docking pane has
						   // finished attaching to another pane.
	xtpPaneActionPinning, // Docking pane is currently pinning (hiding).  This occurs when the "pin"
						  // button is clicked.
	xtpPaneActionPinned,  // Docking pane has been pinned.  This occurs when the docking pane has
						  // finished pinning.
	xtpPaneActionCollapsing, // Docking pane is currently collapsing (hiding).  This occurs when a
							 // pane is going back to its AutoHide position.  If a pane is hidden
							 // and the mouse is positioned over the tab to display the pane, the
							 // pane is expanding, when the mouse is moved off of the pane it begins
							 // to collapse.
	xtpPaneActionCollapsed,  // Docking Pane has been collapsed.   This occurs when the docking pane
							 // has finished collapsing.
	xtpPaneActionExpanding,  // Docking pane is currently expanding.  This occurs when a pane is
							 // being displayed from its AutoHide position.  If a pane is hidden and
	// the mouse is positioned over the tab to display the pane, the pane is
	// then expanding, when the mouse is moved off of the pane it begins to
	// collapse.
	xtpPaneActionExpanded,	// Docking pane is expanded, this is when the pane is fully shown from
							  // the auto-hide position.
	xtpPaneActionActivated,   // Docking pane become active
	xtpPaneActionDeactivated, // Docking pane deactivated
	xtpPaneActionDetaching,   // Docking pane removing from tabbed container
	xtpPaneActionDragging,	// Docking pane has been dragged
	xtpPaneActionUnpinning, // Docking pane is currently docked.  This occurs when the "pin" button
							// is clicked.
	xtpPaneActionUnpinned, // Docking pane has been unpinned.  This occurs when the docking pane has
						   // finished pinning.
	xtpPaneActionSplitterResizing, // Docking pane splitter resizing
	xtpPaneActionSplitterResized   // Docking pane splitter resized
};

//-------------------------------------------------------------------------
// Summary:
//     Enable options of the pane
//-------------------------------------------------------------------------
enum XTPDockingPaneEnableOptions
{
	xtpPaneDisabled		 = 0, // Pane is disabled
	xtpPaneEnableClient  = 1, // Client is enabled
	xtpPaneEnableActions = 2, // All actions are enabled
	xtpPaneEnabled		 = 3, // Pane is enabled
	xtpPaneEnabledAuto   = 4 + 3
};

//-----------------------------------------------------------------------
// Summary:
//     Keyboard options indicates which key can be used to navigate panes
// Example:
// <code>
// m_paneManager.EnableKeyboardNavigate(xtpPaneKeyboardUseAll);
// </code>
// See Also: CXTPDockingPaneManager::EnableKeyboardNavigate
//-----------------------------------------------------------------------
enum XTPDockingPaneKeyboardNavigate
{
	xtpPaneKeyboardUnused	  = 0, // Don't use keyboard
	xtpPaneKeyboardUseAltMinus = 1, // To use Alt+'-' to show context menu
	xtpPaneKeyboardUseAltF6	= 2, // To use Alt+F6 to select next pane
	xtpPaneKeyboardUseAltF7	= 4, // To use Alt+F7 to show window select dialog
	xtpPaneKeyboardUseCtrlTab  = 8, // To use Ctrl+Tab to show window select dialog
	xtpPaneKeyboardUseAll	  = 15 // To use all keys
};

//-----------------------------------------------------------------------
// Summary:
//     XTP_DOCKINGPANE_CLICK structure contains information about pane
//     was used in XTP_DPN_PANEMENUCLICK message
// See Also:
//     XTP_DPN_PANEMENUCLICK
//-----------------------------------------------------------------------
struct XTP_DOCKINGPANE_CLICK
{
	CXTPDockingPane* pPane;			 // Docking Pane pointer
	CXTPDockingPaneBase* pContainer; // Docking Pane container
	CPoint pt;						 // Mouse pointer
	CRect rcExclude;				 // Exclude rectangle
};

//-----------------------------------------------------------------------
// Summary:
//     XTP_DOCKINGPANE_ACTION structure contains information about action
//     performed by user with docking panes.
// Example:
// <code>
// LRESULT CMainFrame::OnDockingPaneNotify(WPARAM wParam, LPARAM lParam)
// {
//     if (wParam == XTP_DPN_ACTION)
//     {
//         XTP_DOCKINGPANE_ACTION* pAction = (XTP_DOCKINGPANE_ACTION*)lParam;
//         TRACE("Action %i\n", pAction->action);
//         return TRUE;
//     }
//     return FALSE;
// }
// </code>
// See Also: XTP_DPN_ACTION, XTPDockingPaneAction
//-----------------------------------------------------------------------
struct XTP_DOCKINGPANE_ACTION
{
	//{{AFX_CODEJOCK_PRIVATE
	XTP_DOCKINGPANE_ACTION(XTPDockingPaneAction _action)
	{
		pPane		   = NULL;
		pDockContainer = NULL;
		action		   = _action;
		bCancel		   = FALSE;
		dockDirection  = xtpPaneDockUndefined;
	}
	//}}AFX_CODEJOCK_PRIVATE

	XTPDockingPaneAction action;		   // Current action the pane is performing.
	BOOL bCancel;						   // If TRUE, the current action will be ignored/canceled
	CXTPDockingPane* pPane;				   // Pane performing the action.
	CXTPDockingPaneBase* pDockContainer;   // Container of xtpPaneActionDocking action.
	XTPDockingPaneDirection dockDirection; // The direction that the pane is trying to dock, if any.
};

//-----------------------------------------------------------------------
// Summary:
//     Internal structure used by Layout manager
// See Also: CXTPDockingPaneLayout
//-----------------------------------------------------------------------
struct XTP_DOCKINGPANE_INFO
{
	//{{AFX_CODEJOCK_PRIVATE
	XTP_DOCKINGPANE_INFO(CXTPDockingPane* p = NULL)
	{
		pPane		= p;
		pLastHolder = pDockingHolder = pFloatingHolder = 0;
	}

	operator CXTPDockingPane*()
	{
		return pPane;
	}
	CXTPDockingPane* operator->()
	{
		return pPane;
	}
	//}}AFX_CODEJOCK_PRIVATE

	CXTPDockingPane* pPane;				  // Docking Pane
	CXTPDockingPaneBase* pFloatingHolder; // Last floating holder of the pane
	CXTPDockingPaneBase* pDockingHolder;  // Last docking holder of the pane
	CXTPDockingPaneBase* pLastHolder;	 // Last holder (must be pFloatingHolder or pDockingHolder)
};

//-----------------------------------------------------------------------
// Summary:
//     This list is used by the CXTPDockingPaneTabbedContainer class for
//     maintaining a CXTPDockingPane collection.
// See Also:
//     CXTPDockingPaneTabbedContainer::GetPanes
//-----------------------------------------------------------------------
typedef CList<CXTPDockingPane*, CXTPDockingPane*> CXTPDockingPaneList;

//-----------------------------------------------------------------------
// Summary:
//     This list is used for maintaining a CXTPDockingPaneBase collection.
// See Also:
//     CXTPDockingPaneBase::FindPane, CXTPDockingPaneAutoHidePanel::GetPanes
//-----------------------------------------------------------------------
typedef CList<CXTPDockingPaneBase*, CXTPDockingPaneBase*> CXTPDockingPaneBaseList;

//-----------------------------------------------------------------------
// Summary:
//     This list is used by the CXTPDockingPaneLayout class for
//     maintaining a XTP_DOCKINGPANE_INFO collection.
// See Also:
//     CXTPDockingPaneLayout::GetPaneList, CXTPDockingPaneManager::GetPaneList
//-----------------------------------------------------------------------
typedef CList<XTP_DOCKINGPANE_INFO, XTP_DOCKINGPANE_INFO&> CXTPDockingPaneInfoList;

//-----------------------------------------------------------------------
// Summary:
//     This map is used for mapping CXTPDockingPaneBase objects.
// Example:
// <code>
// CXTPDockingPaneBase* CXTPDockingPaneBase::Clone(
//     CXTPDockingPaneLayout* pLayout,
//     CXTPPaneToPaneMap* pMap,
//     DWORD /*dwIgnoredOptions*/)
// {
//     ASSERT(pMap);
//     CXTPDockingPaneBase* pClone = new CXTPDockingPaneBase(m_type, pLayout);
//     pMap->SetAt(this, pClone);
//     return pClone;
// }
// </code>
// See Also:
//     CXTPDockingPaneBase::Clone, CXTPDockingPane::Clone
//-----------------------------------------------------------------------
typedef CMap<CXTPDockingPaneBase*, CXTPDockingPaneBase*, CXTPDockingPaneBase*, CXTPDockingPaneBase*>
	CXTPPaneToPaneMap;

//-----------------------------------------------------------------------
// Summary:
//     This map is used for mapping index to CXTPDockingPaneBase objects.
//-------------------------------------------------------------------------
typedef CMap<int, int, CXTPDockingPaneBase*, CXTPDockingPaneBase*> CXTPPaneIndexToPaneMap;

//===========================================================================
// Summary:
//     Base for all docking pane messages
//===========================================================================
const UINT WM_XTP_DOCKINGPANE_BASE = (WM_USER + 9900);

//===========================================================================
// Summary:
//     The XTPWM_DOCKINGPANE_NOTIFY message is sent to the Docking Pane Manager
//     owner window whenever an action occurs within the DockingPanes.
// Remarks:
//     The XTPWM_DOCKINGPANE_NOTIFY notification message is sent to inform the
//     owner window that an action occurs within the DockingPanes.
//     The owner window of the color picker receives this notification
//     through the WM_COMMAND message.
//
// <code>XTPWM_DOCKINGPANE_NOTIFY
// CXTPDockingPane* pPane = (CXTPDockingPane*)lParam; // pointer to an CXTPDockingPane object
// </code>
//
//     wParam can be one of the following:
//     * <b>XTP_DPN_SHOWWINDOW</b>
//         The docking pane is just a virtual container for a user window. The best
//         place to associate them is after the pane becomes visible because, initially,
//         it can be created, closed, hidden, or as a non-active tab. You can create your
//         user window in this handler.
//         Process this message to attach an existing window to the Docking Pane container using the
//         Attach member function.
//     * <b>XTP_DPN_RCLICK</b>
//         User presses the right mouse button on the docking pane container.
//     * <b>XTP_DPN_CLOSEPANE</b>
//         User close the Pane. You can return <b>XTP_ACTION_NOCLOSE</b> while processing the
//         <b>XTP_DPN_CLOSEPANE</b> notification to disable closing docking pane windows.
//     * <b>XTP_DPN_ACTION</b>
//         Extended action occur (see XTPDockingPaneAction)
//     * <b>XTP_DPN_CONTEXTMENU</b>
//         User pressed menu button or right click to show context menu
//
// Parameters:
//     pPane - The value of lParam points to a CXTPDockingPane object that becomes visible.(for
//     XTP_DPN_SHOWWINDOW)
//             This pointer should <b>never</b> be NULL.
//
// Example:
//     Here is an example of how an application would process the XTPWM_DOCKINGPANE_NOTIFY
//     message.
// <code>
// BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
//     ON_MESSAGE(XTPWM_DOCKINGPANE_NOTIFY, OnDockingPaneNotify)
// END_MESSAGE_MAP()
//
// LRESULT CMainFrame::OnDockingPaneNotify(WPARAM wParam, LPARAM lParam)
// {
//     switch ((int)wParam)
//     {
//     case XTP_DPN_SHOWWINDOW:
//         {
//             CXTPDockingPane* pPane = (CXTPDockingPane*)lParam;
//
//             // check if the Pane hasn't been attached yet.
//             if (!pPane->IsValid())
//             {
//                 // check if the user window hasn't been created.
//                 if (!m_wndPane.m_hWnd)
//                 {
//                     // create it.
//                     m_wndPane.CreateEx(WS_EX_STATICEDGE, _T("EDIT"), _T(""),
//                         WS_CHILD | ES_AUTOVSCROLL | ES_MULTILINE,
//                         CRect(0, 0, 200, 120), this, 0);
//                 }
//                 // attach it to the Pane.
//                 pPane->Attach(&m_wndPane);
//             }
//             return TRUE;
//         }
//     case XTP_DPN_CLOSEPANE:
//         {
//             // Disable the user from closing docking panes.
//             return XTP_ACTION_NOCLOSE;
//         }
//     }
//
//     return FALSE;
// }
// </code>
// Returns:
//     If the application is to process this message, the return value should be
//     TRUE, otherwise the return value is FALSE.
//
//===========================================================================
#	define XTPWM_DOCKINGPANE_NOTIFY (WM_XTP_DOCKINGPANE_BASE + 1)

const int XTP_DPN_SHOWWINDOW  = 1;  //<ALIAS XTPWM_DOCKINGPANE_NOTIFY>
const int XTP_DPN_RCLICK	  = 2;  //<ALIAS XTPWM_DOCKINGPANE_NOTIFY>
const int XTP_DPN_CLOSEPANE   = 3;  //<ALIAS XTPWM_DOCKINGPANE_NOTIFY>
const int XTP_DPN_ACTION	  = 4;  //<ALIAS XTPWM_DOCKINGPANE_NOTIFY>
const int XTP_DPN_CONTEXTMENU = 5;  //<ALIAS XTPWM_DOCKINGPANE_NOTIFY>
const int XTP_ACTION_NOCLOSE  = -1; //<ALIAS XTPWM_DOCKINGPANE_NOTIFY>

//{{AFX_CODEJOCK_PRIVATE
// Obsolete
#	define XTP_DPN_PANEMENUCLICK XTP_DPN_CONTEXTMENU
//}}AFX_CODEJOCK_PRIVATE

#	include "Common/Base/Diagnostic/XTPEnableNoisyWarnings.h"
#endif // #if !defined(__XTPDOCKINGPANEDEFINES_H__)
