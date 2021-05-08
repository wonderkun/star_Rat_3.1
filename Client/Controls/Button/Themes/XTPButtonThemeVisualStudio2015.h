// XTPButtonThemeVisualStudio2015.h
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
#if !defined(__XTPBUTTONTHEMEVISUALSTUDIO2015_H__)
#	define __XTPBUTTONTHEMEVISUALSTUDIO2015_H__
//}}AFX_CODEJOCK_PRIVATE

#	if _MSC_VER >= 1000
#		pragma once
#	endif // _MSC_VER >= 1000

#	include "Common/Base/Diagnostic/XTPDisableNoisyWarnings.h"

//===========================================================================
// Summary:
//     CXTPButtonThemeVisualStudio2015 is a class used to perform Visual Studio 2015
//     theme drawing tasks.
//===========================================================================
class _XTP_EXT_CLASS CXTPButtonThemeVisualStudio2015 : public CXTPButtonThemeOffice2013
{
public:
	//-----------------------------------------------------------------------
	// Summary: Constructs a CXTPButtonThemeVisualStudio2015 object
	//-----------------------------------------------------------------------
	CXTPButtonThemeVisualStudio2015();

	//-----------------------------------------------------------------------
	// Summary:
	//     This member function is called by the theme manager to refresh
	//     the visual styles used by each components theme.
	// Parameters:
	//     pButton - Points to a CXTPButton object.
	//-----------------------------------------------------------------------
	virtual void RefreshMetrics(CXTPButton* pButton);
};

#	include "Common/Base/Diagnostic/XTPEnableNoisyWarnings.h"
#endif //#if !defined(__XTPBUTTONTHEMEVISUALSTUDIO2015_H__)
