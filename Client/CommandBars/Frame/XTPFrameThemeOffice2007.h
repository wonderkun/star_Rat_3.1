// XTPFrameThemeOffice2007.h : interface for the CXTPRibbonOffice2007FrameTheme class.
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
#if !defined(__XTPRIBBONOFFICE2007FRAMETHEME_H__)
#	define __XTPRIBBONOFFICE2007FRAMETHEME_H__
//}}AFX_CODEJOCK_PRIVATE

#	if _MSC_VER >= 1000
#		pragma once
#	endif // _MSC_VER >= 1000

#	include "Common/Base/Diagnostic/XTPDisableNoisyWarnings.h"

class CXTPPaintManager;
class CXTPCommandBarsFrameHook;
class CXTPRibbonBar;

//---------------------------------------------------------------------------

class _XTP_EXT_CLASS CXTPRibbonOffice2007FrameTheme : public CXTPFramePaintManager
{
	// Construction / Destruction
public:
	CXTPRibbonOffice2007FrameTheme(CXTPPaintManager* pPaintManager);

	virtual ~CXTPRibbonOffice2007FrameTheme();

	// Frame border
public:
	virtual CRect CalcFrameBorder(const CXTPCommandBarsFrameHook* pFrameHook) const;

	virtual HRGN CalcFrameRegion(CXTPCommandBarsFrameHook* pFrameHook, CSize sz) const;

	// Frame caption
public:
	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called to draw frame if Ribbon was found
	// Parameters:
	//      pDC - Pointer to device context
	//      pFrameHook - CXTPCommandBarsFrameHook hook object
	//-----------------------------------------------------------------------
	virtual void DrawFrame(CDC* pDC, CXTPCommandBarsFrameHook* pFrameHook);

	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called to draw caption button
	// Parameters:
	//      pDC - Pointer to device context
	//      rc - Bounding rectangle of the button
	//      nId - Identifier of the button
	//      bSelected - TURE if button is highlighted
	//      bPressed -  TURE if button is pressed
	//      bActive - TURE if frame is active
	//-----------------------------------------------------------------------
	virtual void DrawFrameCaptionButton(CDC* pDC, CRect rc, int nId, BOOL bSelected, BOOL bPressed,
										BOOL bActive);
	//-----------------------------------------------------------------------
	// <combine
	// CXTPRibbonOffice2007FrameTheme::DrawFrameCaptionButton@CDC*@CRect@int@BOOL@BOOL@BOOL>
	//-----------------------------------------------------------------------
	virtual void DrawFrameCaptionButton(CDC* pDC, CRect rc, int nId, BOOL bSelected, BOOL bPressed,
										BOOL bActive, CXTPRibbonBar* pRibbonBar);

	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called to draw frame caption text
	// Parameters:
	//     pDC - Pointer to device context
	//     rcCaptionText - Bounding rectangle of window text
	//     pSite - Frame to draw
	//     bActive - TRUE if frame is active
	//-----------------------------------------------------------------------
	virtual void DrawCaptionText(CDC* pDC, CRect rcCaptionText, CWnd* pSite, BOOL bActive);
	//-----------------------------------------------------------------------
	// <combine CXTPRibbonOffice2007FrameTheme::DrawCaptionText@CDC*@CRect@CWnd*@BOOL>
	//-----------------------------------------------------------------------
	virtual void DrawCaptionText(CDC* pDC, CRect rcCaptionText, CWnd* pSite, BOOL bActive,
								 CXTPRibbonBar* pRibbonBar);

	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called to refresh the visual metrics of the manager.
	//-----------------------------------------------------------------------
	virtual void RefreshMetrics();

protected:
	COLORREF m_clrFrameBorderActive0;   // Border color
	COLORREF m_clrFrameBorderActive1;   // Border color
	COLORREF m_clrFrameBorderActive2;   // Border color
	COLORREF m_clrFrameBorderActive3;   // Border color
	COLORREF m_clrFrameBorderInactive0; // Border color
	COLORREF m_clrFrameBorderInactive1; // Border color
	COLORREF m_clrFrameBorderInactive2; // Border color
	COLORREF m_clrFrameBorderInactive3; // Border color
};

#	include "Common/Base/Diagnostic/XTPEnableNoisyWarnings.h"
#endif // !defined(__XTPRIBBONOFFICE2007FRAMETHEME_H__)
