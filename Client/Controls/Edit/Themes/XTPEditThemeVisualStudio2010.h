// XTPEditThemeVisualStudio2010.h
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
#if !defined(__XTPEDITTHEMEVISUALSTUDIO2010_H__)
#	define __XTPEDITTHEMEVISUALSTUDIO2010_H__
//}}AFX_CODEJOCK_PRIVATE

#	if _MSC_VER > 1000
#		pragma once
#	endif // _MSC_VER > 1000

#	include "Common/Base/Diagnostic/XTPDisableNoisyWarnings.h"

//===========================================================================
// Summary: CXTPEditThemeVisualStudio2010 is a class used to perform theme
//          drawing tasks.
//===========================================================================
class _XTP_EXT_CLASS CXTPEditThemeVisualStudio2010 : public CXTPEditThemeOfficeXP
{
public:
	//-----------------------------------------------------------------------
	// Summary: Constructs a CXTPEditThemeVisualStudio2010 object
	//-----------------------------------------------------------------------
	CXTPEditThemeVisualStudio2010();

	//-----------------------------------------------------------------------
	// Summary: Destructor, handles cleanup and deallocation.
	//-----------------------------------------------------------------------
	virtual ~CXTPEditThemeVisualStudio2010();

	//-----------------------------------------------------------------------
	// Summary: This member function is called by the theme manager to refresh
	//          the visual styles used by each components theme.
	// Input:   pEdit - Points to a CXTPEdit object.
	//-----------------------------------------------------------------------
	virtual void RefreshMetrics(CXTPEdit* pEdit);
};

#	include "Common/Base/Diagnostic/XTPEnableNoisyWarnings.h"
#endif // __XTPEDITTHEMEVISUALSTUDIO2010_H__
