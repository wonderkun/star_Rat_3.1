// XTPDockingPaneThemeVisualStudio2005Beta2.h
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
#if !defined(__XTPDOCKINGPANETHEMEVISUALSTUDIO2005BETA2_H__)
#	define __XTPDOCKINGPANETHEMEVISUALSTUDIO2005BETA2_H__
//}}AFX_CODEJOCK_PRIVATE

#	if _MSC_VER > 1000
#		pragma once
#	endif // _MSC_VER > 1000

#	include "Common/Base/Diagnostic/XTPDisableNoisyWarnings.h"

//===========================================================================
// Summary:
//     CXTPDockingPaneVisualStudio2005Beta2Theme is CXTPDockingPaneVisualStudio2005Beta1Theme
//     derived class, represents Visual Studio 2005 beta 2 theme for docking panes.
// Remarks:
//     Call CXTPDockingPaneManager::SetTheme(xtpPaneThemeVisualStudio2005Beta1); to set this theme.
//===========================================================================
class _XTP_EXT_CLASS CXTPDockingPaneVisualStudio2005Beta2Theme
	: public CXTPDockingPaneVisualStudio2005Beta1Theme
{
public:
	//-------------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPDockingPaneVisualStudio2005Beta2Theme object.
	//-------------------------------------------------------------------------
	CXTPDockingPaneVisualStudio2005Beta2Theme();

	//-------------------------------------------------------------------------
	// Summary:
	//     This method is called to refresh the visual metrics of the pane.
	//-------------------------------------------------------------------------
	void RefreshMetrics();

	//-----------------------------------------------------------------------
	// Summary:
	//     Draws the background of the pane caption.
	// Parameters:
	//     pDC        - Reference to the device context in which to draw.
	//     pPane     - Container of the caption needs to draw the background.
	//     rcCaption - Caption bounding rectangle
	//     strTitle  - Caption text.
	//     bActive   - TRUE if caption is active.
	//     bVertical - TRUE to draw caption vertically
	//-----------------------------------------------------------------------
	virtual COLORREF FillCaptionPart(CDC* pDC, CXTPDockingPaneBase* pPane, CRect rcCaption,
									 BOOL bActive, BOOL bVertical);

protected:
	COLORREF m_clrCaptionBorder; // Color used to draw the border of the pane caption.
};

#	include "Common/Base/Diagnostic/XTPEnableNoisyWarnings.h"
#endif // !defined(__XTPDOCKINGPANETHEMEVISUALSTUDIO2005BETA2_H__)
