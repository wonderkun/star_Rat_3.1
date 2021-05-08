// XTPCalendarThemePrevNextEventButton.h : header file
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
#if !defined(__XTPCALENDARTHEMEPREVNEXTEVENTBUTTON_H__)
#	define __XTPCALENDARTHEMEPREVNEXTEVENTBUTTON_H__
//}}AFX_CODEJOCK_PRIVATE

#	if _MSC_VER > 1000
#		pragma once
#	endif // _MSC_VER > 1000

#	include "Common/Base/Diagnostic/XTPDisableNoisyWarnings.h"

class CTOPrevNextEventButtons;

DECLARE_THEMEPART(CTOPrevNextEventButton, CXTPCalendarThemePart)

CXTPCalendarThemeIntValue m_nBitmapID;
CXTPCalendarThemeRectValue m_rcBitmapBorder;

CXTPCalendarTheme::CThemeFontColorSetValue m_fcsetText;
CXTPPaintManagerColor m_clrDisabledText;
CXTPCalendarThemeStringValue m_strText;

virtual void RefreshMetrics(BOOL bRefreshChildren = TRUE);

virtual void DoPropExchange(CXTPPropExchange*){};
virtual void Serialize(CArchive&){};

virtual void AdjustLayout(CXTPCalendarView* pObject, CDC* pDC, const CRect& rcRect);
virtual void Draw(CXTPCalendarView* pObject, CDC* pDC);
using TBase::Draw;

virtual int HitTest(const CPoint* pPoint = NULL)
	const; // return 0, xtpCalendarHitTestPrevEventButton or xtpCalendarHitTestNextEventButton

virtual void OnMouseMove(CCmdTarget* pObject, UINT nFlags, CPoint point);
virtual BOOL OnLButtonDown(CCmdTarget* pObject, UINT nFlags, CPoint point,
						   CTOPrevNextEventButtons* pButtons);
using TBase::OnLButtonDown;

virtual CRect GetRect();

CTOPrevNextEventButton();
virtual ~CTOPrevNextEventButton();

protected:
CSize GetSize(const CRect* prcRect = NULL);
BOOL m_bPrev;
CRect m_rcRect;

public:
BOOL m_bHot;
BOOL m_bDisabled;
BOOL m_bVisible;
}
;

#	include "Common/Base/Diagnostic/XTPEnableNoisyWarnings.h"
//{{AFX_CODEJOCK_PRIVATE
#endif // __XTPCALENDARTHEMEPREVNEXTEVENTBUTTON_H__
//}}AFX_CODEJOCK_PRIVATE
