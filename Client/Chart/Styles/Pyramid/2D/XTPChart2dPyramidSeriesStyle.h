// XTPChart2dPyramidSeriesStyle.h
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
#if !defined(__XTPCHART2DPYRAMIDSERIESSTYLE_H__)
#	define __XTPCHART2DPYRAMIDSERIESSTYLE_H__
//}}AFX_CODEJOCK_PRIVATE

#	if _MSC_VER >= 1000
#		pragma once
#	endif // _MSC_VER >= 1000

#	include "Common/Base/Diagnostic/XTPDisableNoisyWarnings.h"

class CXTPChartSeriesView;
class CXTPChartBorder;
class CXTPChartFillStyle;

//===========================================================================
// Summary:
//     This class abstracts the basic style of a pyramid serie.This class is a kind of
//     CXTPChartSeriesStyle.
// Remarks:
//     A pyramid chart (or a circle graph) is a circular chart divided into sectors,
//     illustrating percents. In a pyramid chart, the arc length of each sector (and
//     consequently its central angle and area), is proportional to the quantity
//     it represents. Together, the sectors create a full disk.
//===========================================================================
class _XTP_EXT_CLASS CXTPChartPyramidSeriesStyle : public CXTPChartPyramidSeriesStyleBase
{
	DECLARE_SERIAL(CXTPChartPyramidSeriesStyle);

public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPChartPyramidSeriesStyle object.
	//-----------------------------------------------------------------------
	CXTPChartPyramidSeriesStyle();

protected:
	//-------------------------------------------------------------------------
	// Summary:
	//     Call this function to create the pyramid diagram object.
	// Returns:
	//     A pointer to CXTPChartDiagram object which points to a newly created
	//     CXTPChart2dPyramidDiagramBase object.
	//-------------------------------------------------------------------------
	virtual CXTPChartDiagram* CreateDiagram();

	//-------------------------------------------------------------------------
	// Summary:
	//     Call this function to create the view of the pyramid series.
	// Parameters:
	//     pSeries       - A pointer to chart series object.
	//     pDiagramView  - A pointer to the diagram view object.
	// Returns:
	//     A pointer to CXTPChartSeriesView object which points to a newly created
	//     CXTPChartPyramidSeriesViewBase object.
	//-------------------------------------------------------------------------
	virtual CXTPChartSeriesView* CreateView(CXTPChartSeries* pSeries,
											CXTPChartDiagramView* pDiagramView);

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this function to check whether chart diagram object passed
	//     is a kind of CXTPChart2dPyramidDiagramBase/CXTPChart3dPyramidDiagramBase.
	// Parameters:
	//     pDiagram - A pointer to a chart diagram, whose type is to be identified.
	// Returns:
	//     TRUE if the chart diagram is a pyramid diagram and FALSE if not.
	// Remarks:
	//-----------------------------------------------------------------------
	virtual BOOL IsStyleDiagram(CXTPChartDiagram* pDiagram) const;

#	ifdef _XTP_ACTIVEX
public:
	//{{AFX_CODEJOCK_PRIVATE
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
	DECLARE_OLETYPELIB_EX(CXTPChartPyramidSeriesStyle);
	DECLARE_OLECREATE_EX(CXTPChartPyramidSeriesStyle)
//}}AFX_CODEJOCK_PRIVATE
#	endif
};

#	include "Common/Base/Diagnostic/XTPEnableNoisyWarnings.h"
#endif //#if !defined(__XTPCHART2DPYRAMIDSERIESSTYLE_H__)
