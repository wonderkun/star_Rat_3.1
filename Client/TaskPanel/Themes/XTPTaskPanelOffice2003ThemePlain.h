// XTPTaskPanelOffice2003ThemePlain.h : implementation of the CXTPTaskPanelOffice2003ThemePlain
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
#ifndef XTPTaskPanelOffice2003ThemePlain_h__
#define XTPTaskPanelOffice2003ThemePlain_h__
//}}AFX_CODEJOCK_PRIVATE

#if _MSC_VER > 1000
#	pragma once
#endif // _MSC_VER > 1000

#include "Common/Base/Diagnostic/XTPDisableNoisyWarnings.h"

//===========================================================================
// Summary:
//     The CXTPTaskPanelOffice2003ThemePlain class is used to enable a classic Office 2003 style
//     theme.
// See Also:
//     CXTPTaskPanel::SetTheme
//===========================================================================
class _XTP_EXT_CLASS CXTPTaskPanelOffice2003ThemePlain : public CXTPTaskPanelOfficeXPThemePlain
{
public:
	//-------------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPTaskPanelOffice2003ThemePlain object.
	//-------------------------------------------------------------------------
	CXTPTaskPanelOffice2003ThemePlain();

	//-------------------------------------------------------------------------
	// Summary:
	//     This method is called to refresh the visual metrics of task panel.
	//-------------------------------------------------------------------------
	void RefreshMetrics();
};

#include "Common/Base/Diagnostic/XTPEnableNoisyWarnings.h"
#endif // XTPTaskPanelOffice2003ThemePlain_h__
