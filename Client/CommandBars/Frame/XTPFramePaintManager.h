// XTPFrameShadow.h: interface for the CXTPFramePaintManager class.
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
#if !defined(__XTPFRAMEPAINTMANAGER_H__)
#	define __XTPFRAMEPAINTMANAGER_H__
//}}AFX_CODEJOCK_PRIVATE

#	if _MSC_VER > 1000
#		pragma once
#	endif // _MSC_VER > 1000

#	include "Common/Base/Diagnostic/XTPDisableNoisyWarnings.h"

class CXTPCommandBarsFrameHook;
class CXTPFrameShadow;
class CXTPRibbonBar;

//===========================================================================
// Summary: Paint manager for the Office 2007 style window frame.
//===========================================================================
class _XTP_EXT_CLASS CXTPFramePaintManager
{
public:
	//-----------------------------------------------------------------------
	// Summary: Constructs a CXTPFramePaintManager object.
	// Input:   pPaintManager - Reference to a CXTPPaintManager object.
	//-----------------------------------------------------------------------
	CXTPFramePaintManager(CXTPPaintManager* pPaintManager);

	//-----------------------------------------------------------------------
	// Summary:
	//     Destroys a CXTPFramePaintManager object, handles cleanup and
	//     deallocation
	//-----------------------------------------------------------------------
	virtual ~CXTPFramePaintManager();

public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Sets the frame icon.
	//-----------------------------------------------------------------------
	void SetIcon(HICON hIcon, CSize szIcon);

public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Calculates the frame caption rect
	//-----------------------------------------------------------------------
	virtual CRect CalcFrameCaption(const CXTPCommandBarsFrameHook* pFrameHook) const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Calculates the frame border sizes
	//-----------------------------------------------------------------------
	virtual CRect CalcFrameBorder(const CXTPCommandBarsFrameHook* pFrameHook) const;

public:
	virtual void RecalcLayout(CXTPCommandBarsFrameHook* pFrameHook);

	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called to create window region
	// Parameters:
	//      pFrameHook - CXTPCommandBarsFrameHook hook object
	//      sz - Window size
	// Returns: Region of window to be set
	//-----------------------------------------------------------------------
	virtual HRGN CalcFrameRegion(CXTPCommandBarsFrameHook* pFrameHook, CSize sz) const = 0;

	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called to draw frame if Ribbon was found
	// Parameters:
	//      pDC - Pointer to device context
	//      pFrameHook - CXTPCommandBarsFrameHook hook object
	//-----------------------------------------------------------------------
	virtual void DrawFrame(CDC* pDC, CXTPCommandBarsFrameHook* pFrameHook) = 0;

	virtual void DrawFrameIcon(CDC* pDC, CXTPCommandBarsFrameHook* pFrameHook, CRect& rcCaption);

	virtual void DrawFrameCaptionButtons(CDC* pDC, CXTPCommandBarsFrameHook* pFrameHook,
										 CRect& rcCaptionText);

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
	//      pRibbonBar - Ribbon pointer
	//-----------------------------------------------------------------------
	virtual void DrawFrameCaptionButton(CDC* pDC, CRect rc, int nId, BOOL bSelected, BOOL bPressed,
										BOOL bActive) = 0;
	//-----------------------------------------------------------------------
	// <combine CXTPFramePaintManager::DrawFrameCaptionButton@CDC*@CRect@int@BOOL@BOOL@BOOL>
	//-----------------------------------------------------------------------
	virtual void DrawFrameCaptionButton(CDC* pDC, CRect rc, int nId, BOOL bSelected, BOOL bPressed,
										BOOL bActive, CXTPRibbonBar* pRibbonBar) = 0;

	virtual CSize GetCaptionButtonSize(UINT nId) const;
	virtual CSize GetCaptionButtonSize(UINT nId, HWND hwnd) const;

	virtual CRect GetCaptionButtonMargin() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves height of caption.
	// Returns:
	//     Frame Caption's height.
	//-----------------------------------------------------------------------
	virtual int GetFrameCaptionHeight() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called to refresh the visual metrics of the manager.
	//-----------------------------------------------------------------------
	virtual void RefreshMetrics();

	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called to get CXTPResourceImages pointer.
	// Returns:
	//     Pointer to image collection of the class.
	//-----------------------------------------------------------------------
	CXTPResourceImages* GetImages() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called to draw frame caption text
	// Parameters:
	//     pDC - Pointer to device context
	//     rcCaptionText - Bounding rectangle of window text
	//     pSite - Frame to draw
	//     bActive - TRUE if frame is active
	//     pRibbonBar - Ribbon bar pointer
	//-----------------------------------------------------------------------
	virtual void DrawCaptionText(CDC* pDC, CRect rcCaptionText, CWnd* pSite, BOOL bActive);
	//-----------------------------------------------------------------------
	// <combine CXTPFramePaintManager::DrawCaptionText@CDC*@CRect@CWnd*@BOOL>
	//-----------------------------------------------------------------------
	virtual void DrawCaptionText(CDC* pDC, CRect rcCaptionText, CWnd* pSite, BOOL bActive,
								 CXTPRibbonBar* pRibbonBar);

	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called to draw frame caption bar.
	// Parameters:
	//     pDC - Pointer to device context
	//     rcCaptionBar - Caption bar rectangle
	//     pSite - Frame to draw
	//     bActive - TRUE if frame is active
	//-----------------------------------------------------------------------
	virtual void DrawCaptionBar(CDC* pDC, CRect rcCaptionBar, CWnd* pSite, BOOL bActive);

	//-----------------------------------------------------------------------
	// Summary:
	//     Loads a bitmap image from the specified path.
	// Parameters:
	//     lpszFileName - The name of the file that contains the bitmaps
	//                    to load.
	// Remarks:
	//     The images are the bitmaps that represent all the visual components
	//     of the Ribbon Bar.  For example tab buttons, group buttons, menu buttons,
	//     toolbar buttons, option button, toolbar dropdown, etc.
	//     The images are loaded using LoadImage and are stored in the m_pImages
	//     image collection.
	//     Images for the Office 2007 theme can be found in the \Source\Ribbon\Res
	//     folder.
	// Returns: New CXTPResourceImage containing the loaded bitmap.
	// See Also: SetImageHandle, m_pImages
	//-----------------------------------------------------------------------
	CXTPResourceImage* LoadImage(LPCTSTR lpszFileName);

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves frame small icon.
	// Parameters:
	//     pFrame - Window to retrieve icon.
	// Returns:
	//     Frame small icon.
	// See Also: GetFrameLargeIcon
	//-----------------------------------------------------------------------
	HICON GetFrameSmallIcon(CWnd* pFrame);

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves frame large icon.
	// Parameters:
	//     pFrame - Window to retrieve icon.
	// Returns:
	//     Frame large icon.
	// See Also: GetFrameLargeIcon
	//-----------------------------------------------------------------------
	HICON GetFrameLargeIcon(CWnd* pFrame);

	//-----------------------------------------------------------------------
	// Summary:
	//     Creates frame shadow if supported by theme. Default implementation returns NULL.
	// Parameters:
	//     pFrame - Window object pointer
	// Returns:
	//     Returns either a valid frame shadow pointer created by
	//     XTPFrameShadowManager()->EnableShadow or NULL if frame has no shadow.
	// See Also: XTPFrameShadowManager
	//-----------------------------------------------------------------------
	virtual CXTPFrameShadow* CreateShadow(CWnd* pFrame);

	//-----------------------------------------------------------------------
	// Summary:
	//     An implementation can override this method in order to change frame appearance
	//     when a window gets activated or deactivated.
	// Parameters:
	//     bActive - TRUE is a window is activated, otherwise FALSE
	//     pFrame - Window object pointer
	//     pShadow - Shadow object pointer
	// See Also: CreateShadow, XTPFrameShadowManager
	//-----------------------------------------------------------------------
	virtual void OnShadowedFrameActiveStateChanged(BOOL bActive, CWnd* pFrame,
												   CXTPFrameShadow* pShadow);

public:
	BOOL m_bFrameStatusBar; // TRUE if status bar used to draw.
	BOOL m_bRoundedCornersAlways;

	CXTPPaintManagerFont m_fntFrameCaption; // Font used to draw text in the frame caption

public:
	int m_nFrameCaptionHeight; // Frame caption

	CXTPPaintManager* m_pPaintManager; // Parent Paint Manager.

	BOOL m_bFlatFrame;			  // TRUE to use a flat frame, FALSE otherwise.
	BOOL m_bCaptionCenterAligned; // If TRUE, caption title will be center aligned.

protected:
	HICON m_hIcon;		  // Icon handle
	CSize m_szIcon;		  // Icon size
	CRect m_rcIconMargin; // Icon margin
	CRect m_rcCaptionButtonMargin;
	CSize m_szCaptionButtonSize;
	CSize m_szMDIClildWindowCaptionButtonSize;

	CXTPPaintManagerColor m_clrFrameCaptionActive;				  // Caption color (active)
	CXTPPaintManagerColor m_clrFrameCaptionInactive;			  // Caption color (inactive)
	CXTPPaintManagerColor m_clrFrameCaptionTextActive;			  // Caption text color
	CXTPPaintManagerColor m_clrFrameCaptionTextInactive;		  // Caption text color
	CXTPPaintManagerColor m_clrFrameCaptionTextActiveTitle;		  // Caption text color
	CXTPPaintManagerColor m_clrFrameCaptionTextActiveBSMode;	  // Caption text color
	CXTPPaintManagerColor m_clrFrameCaptionTextInactiveBSMode;	// Caption text color
	CXTPPaintManagerColor m_clrFrameCaptionTextActiveTitleBSMode; // Caption text color
};

AFX_INLINE int CXTPFramePaintManager::GetFrameCaptionHeight() const
{
	return m_nFrameCaptionHeight;
}
AFX_INLINE CRect CXTPFramePaintManager::GetCaptionButtonMargin() const
{
	return m_rcCaptionButtonMargin;
}
AFX_INLINE CSize CXTPFramePaintManager::GetCaptionButtonSize(UINT /*nId*/) const
{
	return m_szCaptionButtonSize;
}

#	include "Common/Base/Diagnostic/XTPEnableNoisyWarnings.h"
#endif // !defined(__XTPFRAMEPAINTMANAGER_H__)
