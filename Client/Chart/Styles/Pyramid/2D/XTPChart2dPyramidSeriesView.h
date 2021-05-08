// XTPChart2dPyramidSeriesView.h
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
#if !defined(__XTPCHART2DPYRAMIDSERIESVIEW_H__)
#	define __XTPCHART2DPYRAMIDSERIESVIEW_H__
//}}AFX_CODEJOCK_PRIVATE

#	if _MSC_VER >= 1000
#		pragma once
#	endif // _MSC_VER >= 1000

#	include "Common/Base/Diagnostic/XTPDisableNoisyWarnings.h"

class CXTPChartDeviceCommand;
class CXTPChartSeriesPointView;
class CXTPChartElementView;
class CXTPChartSeriesPoint;
class CXTPChartDeviceContext;
class CXTPChartSeries;
class CXTPChartDiagramView;

//===========================================================================
// Summary:
//     This class abstracts the view of a pyramid series.This class is a kind of
//     CXTPChartSeriesView.
// Remarks:
//     A pyramid chart (or a circle graph) is a circular chart divided into sectors,
//     illustrating percents. In a pyramid chart, the arc length of each sector (and
//     consequently its central angle and area), is proportional to the quantity
//     it represents. Together, the sectors create a full disk.
//===========================================================================
class _XTP_EXT_CLASS CXTPChartPyramidSeriesView : public CXTPChartPyramidSeriesViewBase
{
	DECLARE_DYNAMIC(CXTPChartPyramidSeriesView);

public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPChartPyramidSeriesView object.
	// Parameters:
	//     pSeries       - Pointer to pyramid series object.
	//     pDiagramView  - Pointer to the pyramid diagram view.
	// Remarks:
	//-----------------------------------------------------------------------
	CXTPChartPyramidSeriesView(CXTPChartSeries* pSeries, CXTPChartDiagramView* pDiagramView);

	//-------------------------------------------------------------------------
	// Summary:
	//     Call this function to calculate the pyramid series point layout.
	// Parameters:
	//     pDC      - Pointer to the chart device context.
	//     rcBounds - The rectangular boundary.
	//-------------------------------------------------------------------------
	virtual void CalculatePointLayout(CXTPChartDeviceContext* pDC, CRect rcBounds);

protected:
	//-------------------------------------------------------------------------
	// Summary:
	//     Call this function to get the inner bounds of the diagram.
	// Returns:
	//     A chart rect object denoting the rectangular boundary.
	//-------------------------------------------------------------------------
	virtual CXTPChartRectF GetInnerBounds() const;

	//-------------------------------------------------------------------------
	// Summary:
	//     Use this function to create the pyramid series point view object.
	// Parameters:
	//     pDC    - Pointer to chart device context.
	//     pPoint - Pointer to chart series point.
	//     pParentView - Parent element view pointer.
	// Returns:
	//     A pointer to the chart series point view.
	//-------------------------------------------------------------------------
	virtual CXTPChartSeriesPointView* CreateSeriesPointView(CXTPChartDeviceContext* pDC,
															CXTPChartSeriesPoint* pPoint,
															CXTPChartElementView* pParentView);

	//-------------------------------------------------------------------------
	// Summary:
	//     This function creates a CXTPChartDeviceCommand object, this object
	//     represents the rendering of the pyramid series.
	// Parameters:
	//     pDC      - Pointer to a CXTPChartDeviceContext object.
	// Returns:
	//     Returns CXTPChartDeviceCommand object, this object handles
	//     the rendering of an element in the chart. Here it handles
	//     the drawing of the pyramid series.
	//-------------------------------------------------------------------------
	virtual CXTPChartDeviceCommand* CreateDeviceCommand(CXTPChartDeviceContext* pDC);

	//-------------------------------------------------------------------------
	// Summary:
	//     These functions create a label view drawing command object.
	// Parameters:
	//     pDC       - Pointer to a CXTPChartDeviceContext object.
	//     rcBounds  - The rectangular boundary of the legend.
	//     color1    - 1-st gradient fill color.
	//     color2    - 2-nd gradient fill color.
	//     clrBorder - Border color.
	// Returns:
	//     Returns a new label view drawing command object.
	//-------------------------------------------------------------------------
	virtual CXTPChartDeviceCommand* CreateLegendDeviceCommand(CXTPChartDeviceContext* pDC,
															  CRect rcBounds);

public:
	virtual CXTPChartDeviceCommand* CreateLegendDeviceCommand(
		CXTPChartDeviceContext* pDC, CRect rcBounds, CXTPChartColor color1, CXTPChartColor color2,
		CXTPChartColor
			clrBorder); // <combine
						// CXTPChartPyramidSeriesViewBase::CreateLegendDeviceCommand@CXTPChartDeviceContext*@CRect>

private:
	CXTPChartRectF m_rcInnerBounds;
};

#	include "Common/Base/Diagnostic/XTPEnableNoisyWarnings.h"
#endif //#if !defined(__XTPCHART2DPYRAMIDSERIESVIEW_H__)
