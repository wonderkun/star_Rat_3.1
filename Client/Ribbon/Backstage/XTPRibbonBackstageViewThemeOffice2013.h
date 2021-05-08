// XTPRibbonBackstageViewThemeOffice2013.h: interface for the CXTPRibbonBackstageViewThemeOffice2013
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
#if !defined(__XTPRIBBONBACKSTAGEVIEWTHEMEOFFICE2013_H__)
#	define __XTPRIBBONBACKSTAGEVIEWTHEMEOFFICE2013_H__
//}}AFX_CODEJOCK_PRIVATE

#	if _MSC_VER > 1000
#		pragma once
#	endif // _MSC_VER > 1000

#	include "Common/Base/Diagnostic/XTPDisableNoisyWarnings.h"

class CXTPRibbonBackstageView;

class _XTP_EXT_CLASS CXTPRibbonBackstageViewThemeOffice2013 : public CXTPRibbonBackstagePaintManager
{
public:
	CXTPRibbonBackstageViewThemeOffice2013();

	virtual ~CXTPRibbonBackstageViewThemeOffice2013();

public:
	virtual void DrawBackground(CDC* pDC, CXTPRibbonBackstageView* pView);
	virtual void DrawControl(CDC* pDC, CXTPRibbonBackstageView* pView, CXTPControl* pControl);

protected:
	COLORREF m_clrButtonBackNormal;
	COLORREF m_clrButtonBackSelected;
	COLORREF m_clrButtonBackHighlighted;
	COLORREF m_clrButtonTextNormal;
	COLORREF m_clrButtonTextDisabled;
	COLORREF m_clrButtonTextSelected;
	COLORREF m_clrButtonTextHighlighted;
};

#	include "Common/Base/Diagnostic/XTPEnableNoisyWarnings.h"
#endif // !defined(__XTPRIBBONBACKSTAGEVIEWTHEMEOFFICE2013_H__)
