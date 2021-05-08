// XTPTabColorSetOffice2013.h
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
#if !defined(__XTPTABCOLORSETOFFICE2013_H__)
#	define __XTPTABCOLORSETOFFICE2013_H__
//}}AFX_CODEJOCK_PRIVATE

#	if _MSC_VER > 1000
#		pragma once
#	endif // _MSC_VER > 1000

#	include "Common/Base/Diagnostic/XTPDisableNoisyWarnings.h"

class _XTP_EXT_CLASS CXTPTabColorSetOffice2013 : public CXTPTabColorSetVisualStudio2012
{
public:
	CXTPTabColorSetOffice2013();

	//-------------------------------------------------------------------------
	// Summary:
	//     This member is called to refresh the visual metrics of the tabs.
	// Remarks:
	//     All of the color members are refreshed when this is called.
	//     This member can be override this member to change the colors of
	//     the color members.
	//-------------------------------------------------------------------------
	virtual void RefreshMetrics();

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this member to change the color of text in the tab.
	// Parameters:
	//     pDC   - Pointer to a valid device context.
	//     pItem - Change text color of this tab.
	//-----------------------------------------------------------------------
	virtual void SetTextColor(CDC* pDC, CXTPTabManagerItem* pItem);

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this member to get the color of a tab.
	// Parameters:
	//     pItem - Get color of this Tab.
	// Returns:
	//     COLORREF of pItem.
	// Remarks:
	//     This is used in many of the CXTPTabPaintManagerColorSet "fill" functions.
	// See Also: CXTPTabManager::GetItemColor, XTPTabColorStyle, SetColor, GetColorSet, SetColorSet
	//-----------------------------------------------------------------------
	virtual COLORREF GetItemColor(CXTPTabManagerItem* pItem);

	//-----------------------------------------------------------------------
	// Summary:
	//     This member is called to fill a tab button.
	// Parameters:
	//     pDC    - Pointer to a valid device context.
	//     rcItem - Bounding rectangle of the tab button to fill.
	//     pItem  - Tab button to draw.
	// Returns:
	//     COLORREF returned from CXTPTabManager::GetItemColor(pItem).
	// Remarks:
	//     This member is used to fill all tab buttons except when the XTPTabAppearanceStyle is
	//     xtpTabAppearanceStateButtons.  xtpTabAppearanceStateButtons require
	//     the FillStateButton member.
	// See Also: FillStateButton
	//-----------------------------------------------------------------------
	virtual COLORREF FillPropertyButton(CDC* pDC, CRect rcItem, CXTPTabManagerItem* pItem);

	//-----------------------------------------------------------------------
	// Summary:
	//     This member is called to fill the tab navigation buttons.
	// Parameters:
	//     pDC     - Pointer to a valid device context.
	//     pButton - Tab navigation button to fill.
	//     rc      - Bounding rectangle of the tab navigation button.
	// Remarks:
	//     This member must be overridden and takes care of filling the
	//     tab navigation buttons that are in the header of the TabClient.
	//     The XTPTabColorStyle CXTPTabPaintManagerColorSet classes override this to perform
	//     actions such as painting the highlighting, pressed, and normal
	//     versions of the tab navigation buttons.
	//
	// See Also: CXTPTabManager::GetNavigateButton, CXTPTabManagerNavigateButton
	//-----------------------------------------------------------------------
	virtual void FillNavigateButton(CDC* pDC, CXTPTabManagerNavigateButton* pButton, CRect& rc);

protected:
	void FillNavigateButtonEx(CDC* pDC, CXTPTabManagerNavigateButton* pButton, CRect& rc,
							  CXTPPaintManagerColor clrBack = RGB(255, 0, 0),
							  CXTPPaintManagerColor clrText = RGB(0, 0, 255));

public:
	CXTPPaintManagerColor m_clrButtonSeparator;
	CXTPPaintManagerColor m_clrNonActiveButtonSeparator;
};

#	include "Common/Base/Diagnostic/XTPEnableNoisyWarnings.h"
#endif // !defined(__XTPTABCOLORSETOFFICE2013_H__)
