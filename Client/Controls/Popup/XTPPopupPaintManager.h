// XTPPopupPaintManager.h: interface for the CXTPPopupPaintManager class.
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
#if !defined(_XTPPOPUPPAINTMANAGER_H__)
#	define _XTPPOPUPPAINTMANAGER_H__
//}}AFX_CODEJOCK_PRIVATE

#	if _MSC_VER > 1000
#		pragma once
#	endif // _MSC_VER > 1000

#	include "Common/Base/Diagnostic/XTPDisableNoisyWarnings.h"

class CXTPPopupItem;
class CXTPPopupItemText;
class CXTPPopupItemIcon;
class CXTPPopupControl;

//===========================================================================
// Summary:
//     CXTPPopupPaintManager is a class used to perform specialized
//     drawing tasks.
//===========================================================================
class _XTP_EXT_CLASS CXTPPopupPaintManager
{
public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPPopupPaintManager object.
	//-----------------------------------------------------------------------
	CXTPPopupPaintManager();

	//-----------------------------------------------------------------------
	// Summary:
	//     Destroys a CXTPPopupPaintManager object.
	//-----------------------------------------------------------------------
	virtual ~CXTPPopupPaintManager();

public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Call this member function will draw the background of popup window.
	// Parameters:
	//     pDC - Points to the device context.
	//     rcClient - Size of area to fill.
	//     pControl - Popup control to draw
	//-----------------------------------------------------------------------
	virtual void DrawBackground(CDC* pDC, CXTPPopupControl* pControl, CRect rcClient);

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this member function will draw the controlled item object
	//     of popup window.
	// Parameters:
	//     pDC - Points to the device context.
	//     pItem - point to CXTPPopupItem object.
	//-----------------------------------------------------------------------
	void DrawItem(CDC* pDC, CXTPPopupItem* pItem);

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this method to draw the rectangle of a button.
	// Parameters:
	//     pDC   - Points to the device context.
	//     pItem - Pointer to a CXTPPopupItem.
	//-----------------------------------------------------------------------
	virtual void DrawButton(CDC* pDC, CXTPPopupItem* pItem);

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this method to draw the icon of a button.
	// Parameters:
	//     pDC   - Points to the device context.
	//     pItem - Pointer to a CXTPPopupItem.
	//-----------------------------------------------------------------------
	virtual void DrawItemIcon(CDC* pDC, CXTPPopupItem* pItem);

	//-----------------------------------------------------------------------
	// Summary:
	//     Sets font for text used in Popup control.
	// Parameters:
	//     hFont - Font handle to use.
	//-----------------------------------------------------------------------
	void SetFont(HFONT hFont);

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this member function to refresh draw metrics.
	//-----------------------------------------------------------------------
	virtual void RefreshMetrics();

public:
	CXTPPaintManagerColorGradient m_clrBackground; // gradient background color
	CXTPPaintManagerColorGradient m_clrFrame;	  // 3d frame color

	CXTPFont m_xtpFontText; // default font of text
	XTP_SUBSTITUTE_GDI_MEMBER_WITH_CACHED(CFont, m_fntText, m_xtpFontText, GetTextFontHandle);

	COLORREF m_clrText; // default color of text

	int m_iButtonBorderInflate;

	COLORREF m_clrButtonSelected;							 // color of selected button
	COLORREF m_clrButtonPressed;							 // color of pressed button
	CXTPPaintManagerColorGradient m_clrButtonSelectedBorder; // 3d border color of selected button
	CXTPPaintManagerColorGradient m_clrButtonPressedBorder;  // 3d border color of pressed button
};

#	include "Common/Base/Diagnostic/XTPEnableNoisyWarnings.h"
#endif // !defined(_XTPPOPUPPAINTMANAGER_H__)
