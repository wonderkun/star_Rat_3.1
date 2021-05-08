// XTPRibbonBackstageSeparatorThemeOffice2013.h: interface for the
// CXTPRibbonBackstageSeparatorThemeOffice2013 class.
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
#if !defined(__XTPRIBBONBACKSTAGESEPARATORTHEMEOFFICE2013_H__)
#	define __XTPRIBBONBACKSTAGESEPARATORTHEMEOFFICE2013_H__
//}}AFX_CODEJOCK_PRIVATE

#	if _MSC_VER > 1000
#		pragma once
#	endif // _MSC_VER > 1000

#	include "Common/Base/Diagnostic/XTPDisableNoisyWarnings.h"

class CXTPRibbonBackstageSeparator;

class _XTP_EXT_CLASS CXTPRibbonBackstageSeparatorThemeOffice2013
	: public CXTPRibbonBackstageSeparatorPaintManager
{
public:
	CXTPRibbonBackstageSeparatorThemeOffice2013();

	virtual void DrawSeparator(CDC* pDC, CXTPRibbonBackstageSeparator* pSeparator);
};

#	include "Common/Base/Diagnostic/XTPEnableNoisyWarnings.h"
#endif // !defined(__XTPRIBBONBACKSTAGESEPARATORTHEMEOFFICE2013_H__)
