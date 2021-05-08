// XTPChart2dPyramidDiagram.h
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
#if !defined(__XTPCHART2DPYRAMIDDIAGRAM_H__)
#	define __XTPCHART2DPYRAMIDDIAGRAM_H__
//}}AFX_CODEJOCK_PRIVATE

#	if _MSC_VER >= 1000
#		pragma once
#	endif // _MSC_VER >= 1000

#	include "Common/Base/Diagnostic/XTPDisableNoisyWarnings.h"

class CXTPChartDeviceContext;
class CXTPChartElementView;
class CXTPChartDiagramView;

//===========================================================================
// Summary:
//     This class abstracts the pyramid diagram. This class is a kind of
//     CXTPChartDiagram.
//===========================================================================
class _XTP_EXT_CLASS CXTPChartPyramidDiagram : public CXTPChart2dPyramidDiagramBase
{
	DECLARE_SERIAL(CXTPChartPyramidDiagram);

public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPChartPyramidDiagram object.
	// Remarks:
	//-----------------------------------------------------------------------
	CXTPChartPyramidDiagram();

public:
	//-------------------------------------------------------------------------
	// Summary:
	//     Call this function to create the view of the pyramid diagram.
	// Parameters:
	//     pDC           - A pointer to chart device context.
	//     pParent       - A pointer to the parent view.
	// Returns:
	//     A pointer to CXTPChartDiagramView object which points to a newly created
	//     CXTPChartPyramidDiagramViewBase object.
	//-------------------------------------------------------------------------
	virtual CXTPChartDiagramView* CreateView(CXTPChartDeviceContext* pDC,
											 CXTPChartElementView* pParent);

#	ifdef _XTP_ACTIVEX
public:
	//{{AFX_CODEJOCK_PRIVATE
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
	DECLARE_OLETYPELIB_EX(CXTPChartPyramidDiagram);
	DECLARE_OLECREATE_EX(CXTPChartPyramidDiagram)
	//}}AFX_CODEJOCK_PRIVATE
#	endif
};

#	include "Common/Base/Diagnostic/XTPEnableNoisyWarnings.h"
#endif //#if !defined(__XTPCHART2DPYRAMIDDIAGRAM_H__)
