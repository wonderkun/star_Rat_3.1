// XTPControlButton.h : interface for the CXTPControlButton class.
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
#if !defined(__XTPCONTROLBUTTON_H__)
#	define __XTPCONTROLBUTTON_H__
//}}AFX_CODEJOCK_PRIVATE

#	if _MSC_VER >= 1000
#		pragma once
#	endif // _MSC_VER >= 1000

#	include "Common/Base/Diagnostic/XTPDisableNoisyWarnings.h"

//===========================================================================
// Summary:
//     CXTPControlButton is a CXTPControl derived class.
//     It represents a button control.
//===========================================================================
class _XTP_EXT_CLASS CXTPControlButton : public CXTPControl
{
public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPControlButton object
	//-----------------------------------------------------------------------
	CXTPControlButton();

	//-----------------------------------------------------------------------
	// Summary:
	//     Destroys a CXTPControlButton object, handles cleanup and deallocation
	//-----------------------------------------------------------------------
	virtual ~CXTPControlButton();

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this member to set the style of the button containing vector icon.
	// Parameters:
	//     buttonStyle - The style to be set. Can be any of the values listed in the Remarks
	//     section.
	// Remarks:
	//     buttonStyle parameter can be one of the following:
	//         * <b>xtpButtonAutomatic</b> Indicates the default style.
	//         * <b>xtpButtonCaption</b> Indicates caption drawing only.
	//         * <b>xtpButtonIcon</b> Indicates icon drawing only.
	//         * <b>xtpButtonIconAndCaption</b> Indicates icon and caption drawing.
	//-----------------------------------------------------------------------
	void SetStyleEx(XTPButtonStyle buttonStyle);

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this member to get the button's style containing vector icon.
	// Returns:
	//     The style of the button.
	//-----------------------------------------------------------------------
	XTPButtonStyle GetStyleEx() const;

public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Reads or writes this object from or to an archive.
	// Parameters:
	//     pPX - A CXTPPropExchange object to serialize to or from.
	//----------------------------------------------------------------------
	void DoPropExchange(CXTPPropExchange* pPX);

protected:
	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called when the user clicks the control.
	// Parameters:
	//     bKeyboard - TRUE if the control is selected using the keyboard.
	//     pt        - Mouse cursor position.
	//-----------------------------------------------------------------------
	virtual void OnClick(BOOL bKeyboard = FALSE, CPoint pt = CPoint(0, 0));

	//-----------------------------------------------------------------------
	// Summary:
	//     This member is called when the user releases the left mouse button.
	// Parameters:
	//     point - Specifies the x- and y coordinate of the cursor.
	//-----------------------------------------------------------------------
	virtual void OnLButtonUp(CPoint point);

	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called to copy the control.
	// Parameters:
	//     pControl - Points to a source CXTPControl object
	//     bRecursive - TRUE to copy recursively.
	//-----------------------------------------------------------------------
	virtual void Copy(CXTPControl* pControl, BOOL bRecursive = FALSE);

	XTPButtonStyle m_buttonStyleEx; // User defined style of button containing vector icon.

private:
#	ifdef _XTP_ACTIVEX
	//{{AFX_CODEJOCK_PRIVATE

	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()

	DECLARE_OLETYPELIB_EX(CXTPControlButton)

	afx_msg XTPButtonStyle OleGetStyleEx();
	afx_msg void OleSetStyleEx(XTPButtonStyle nStyle);

	enum
	{
		dispidStyle = 50L,
	};

//}}AFX_CODEJOCK_PRIVATE
#	endif

	DECLARE_XTP_CONTROL(CXTPControlButton)
};

//////////////////////////////////////////////////////////////////////////

#	include "Common/Base/Diagnostic/XTPEnableNoisyWarnings.h"
#endif // #if !defined(__XTPCONTROLBUTTON_H__)
