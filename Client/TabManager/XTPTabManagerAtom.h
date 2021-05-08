// XTPTabManagerAtom.h
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
#if !defined(__XTPTABMANAGERATOM_H__)
#	define __XTPTABMANAGERATOM_H__
//}}AFX_CODEJOCK_PRIVATE

#	if _MSC_VER > 1000
#		pragma once
#	endif // _MSC_VER > 1000

#	include "Common/Base/Diagnostic/XTPDisableNoisyWarnings.h"

//===========================================================================
// Summary:
//     CXTPTabManagerAtom is a class that has only one purpose, which
//     is to catch the event when a property of the PaintManager has changed.
//     When a property of the PaintManager has changed, the OnPropertyChanged
//     event if called. When the OnPropertyChanged is caught, Reposition
//     is called to recalculate self layout.
// Remarks:
//     This is the base class for CXTPTabManager.  When a property of the
//     CXTPTabPaintManager has changed, then OnPropertyChanged is called
//     to recalculate the layout.  The paint manager can be accessed
//     with the CXTPTabManager::GetPaintManager member.
// See Also: CXTPTabManager::GetPaintManager
//===========================================================================
class _XTP_EXT_CLASS CXTPTabManagerAtom
{
public:
	//-------------------------------------------------------------------------
	// Summary:
	//     This member is called when a property of the PaintManager has
	//     changed.
	// See Also: CXTPTabManager::GetPaintManager
	//-------------------------------------------------------------------------
	virtual void OnPropertyChanged()
	{
		Reposition();
	}

	//-------------------------------------------------------------------------
	// Summary:
	//     This member recalculates the layout of the tab manager and
	//     then repositions itself.  This member must be overridden in
	//     derived classes.
	//-------------------------------------------------------------------------
	virtual void Reposition() = 0;

protected:
	//-------------------------------------------------------------------------
	// Summary:
	//     Destroys a CXTPTabManagerAtom object, handles cleanup and deallocation.
	//-------------------------------------------------------------------------
	virtual ~CXTPTabManagerAtom()
	{
	}
};

#	include "Common/Base/Diagnostic/XTPEnableNoisyWarnings.h"
#endif // !defined(__XTPTABMANAGERATOM_H__)
