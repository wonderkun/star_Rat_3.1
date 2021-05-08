// XTPTaskPanelVisualStudio2005Theme.h : implementation of the CXTPTaskPanelVisualStudio2005Theme
// class.
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
#if !defined(__XTPTASKPANELVISUALSTUDIO2005THEME_H__)
#	define __XTPTASKPANELVISUALSTUDIO2005THEME_H__
//}}AFX_CODEJOCK_PRIVATE

#	if _MSC_VER > 1000
#		pragma once
#	endif // _MSC_VER > 1000

#	include "Common/Base/Diagnostic/XTPDisableNoisyWarnings.h"

//===========================================================================
// Summary:
//     The CXTPTaskPanelVisualStudio2005Theme class is used to enable a Visual Studio 2005 style
//     theme.
// See Also:
//     CXTPTaskPanel::SetTheme
//===========================================================================
class _XTP_EXT_CLASS CXTPTaskPanelVisualStudio2005Theme : public CXTPTaskPanelToolboxTheme
{
public:
	//-------------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPTaskPanelVisualStudio2005Theme object.
	//-------------------------------------------------------------------------
	CXTPTaskPanelVisualStudio2005Theme();

	//-----------------------------------------------------------------------
	// Summary:
	//     This member is called to draw the background of the group caption.
	// Parameters:
	//     pDC    - Pointer to a valid device context.
	//     pGroup - Fill group caption of this group.
	//     rc     - Bounding rectangle of the group caption.
	// Returns:
	//     Bounding rectangle of text within group caption.
	// Remarks:
	//     This member will draw the Visual Studio color gradient in the group
	//     caption rectangle.
	//-----------------------------------------------------------------------
	CRect DrawGroupCaptionBackground(CDC* pDC, CXTPTaskPanelGroup* pGroup, CRect rc);

	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called to draw the face of the group.
	// Parameters:
	//     pDC    - Pointer to a valid device context
	//     pGroup - Points to a CXTPTaskPanelGroup object.
	//     rc     - Rectangle of group to be draw.
	//-----------------------------------------------------------------------
	void DrawGroupClientFace(CDC* pDC, CXTPTaskPanelGroup* pGroup, CRect rc);

	//-----------------------------------------------------------------------
	// Summary:
	//     Fills group rectangle
	// Parameters:
	//     pDC - Pointer to a valid device context
	//     pGroup - Points to a CXTPTaskPanelGroup object
	//     rc - Rectangle of group to be draw.
	// See Also: DrawGroupClientFace
	//-----------------------------------------------------------------------
	void FillGroupClientFace(CDC* pDC, CXTPTaskPanelGroup* pGroup, CRect rc);

	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called to fill background of task panel control.
	// Parameters:
	//     pDC - Pointer to a valid device context
	//     pTaskPanel - Points to a CXTPTaskPanel object
	//-----------------------------------------------------------------------
	void FillTaskPanel(CDC* pDC, CXTPTaskPanel* pTaskPanel);

	//-------------------------------------------------------------------------
	// Summary:
	//     This method is called to refresh the visual metrics of task panel.
	//-------------------------------------------------------------------------
	void RefreshMetrics();

protected:
	virtual CRect DrawExpandButton(CDC* pDC, CXTPTaskPanelGroup* pGroup, CRect rc);
};

//{{AFX_CODEJOCK_PRIVATE
typedef CXTPTaskPanelVisualStudio2005Theme CXTPTaskPanelToolboxWhidbeyTheme;
//}}AFX_CODEJOCK_PRIVATE

#	include "Common/Base/Diagnostic/XTPEnableNoisyWarnings.h"
#endif // __XTPTASKPANELVISUALSTUDIO2005THEME_H__
