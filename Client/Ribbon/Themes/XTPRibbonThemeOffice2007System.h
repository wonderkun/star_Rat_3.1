// XTPRibbonThemeOffice2007System.h: interface for the CXTPRibbonThemeOffice2007System class.
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
#if !defined(__XTPRIBBONTHEMEOFFICE2007SYSTEM_H__)
#	define __XTPRIBBONTHEMEOFFICE2007SYSTEM_H__
//}}AFX_CODEJOCK_PRIVATE

#	if _MSC_VER > 1000
#		pragma once
#	endif // _MSC_VER > 1000

#	include "Common/Base/Diagnostic/XTPDisableNoisyWarnings.h"

//===========================================================================
// Summary:
//     CXTPRibbonThemeOffice2007System is a CXTPRibbonMarkupTheme derived class
//     used to represent a Office 2007 ribbon theme.
//===========================================================================
class _XTP_EXT_CLASS CXTPRibbonThemeOffice2007System : public CXTPRibbonMarkupTheme
{
public:
	// --------------------------------------------------------
	// Summary:
	//     Constructs a CXTPRibbonThemeOffice2007System object
	// Parameters:
	//     pPaintManager :  \Returns a CXTPPaintManager object.
	// --------------------------------------------------------
	CXTPRibbonThemeOffice2007System(CXTPPaintManager* pPaintManager);

	virtual ~CXTPRibbonThemeOffice2007System();

public:
	//-------------------------------------------------------------------------
	// Summary:
	//      This method is called to refresh the visual metrics of manager.
	// Remarks:
	//      Refreshes all of the colors in the Ribbon Bar.  Many of the colors
	//      used are set with the GROUP_COLOR structure.
	// See Also:
	//     GROUP_COLOR
	//-------------------------------------------------------------------------
	virtual void RefreshMetrics();

	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called to draw Ribbon quick access controls
	//-----------------------------------------------------------------------
	virtual void DrawRibbonQuickAccessControls(CDC* pDC, CXTPRibbonBar* pRibbonBar);

public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Calculates ribbon caption height
	//-----------------------------------------------------------------------
	virtual int GetRibbonCaptionHeight(const CXTPRibbonBar* pRibbonBar) const;

	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called to draw quick access customize button
	// Parameters:
	//     pDC - Pointer to a valid device context
	//     pControl - Pointer to Quick Access customize button
	// See Also: DrawRibbonQuickAccessMoreButton
	//-----------------------------------------------------------------------
	virtual void DrawRibbonQuickAccessButton(CDC* pDC, CXTPControlPopup* pControl);

protected:
	BOOL LoadResource();
};

#	include "Common/Base/Diagnostic/XTPEnableNoisyWarnings.h"
#endif // !defined(__XTPRIBBONTHEMEOFFICE2007SYSTEM_H__)
