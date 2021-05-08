// XTPChart2dPyramidSeriesPointView.h
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
#if !defined(__XTPCHART2DPYRAMIDSERIESPOINTVIEW_H__)
#	define __XTPCHART2DPYRAMIDSERIESPOINTVIEW_H__
//}}AFX_CODEJOCK_PRIVATE

#	if _MSC_VER >= 1000
#		pragma once
#	endif // _MSC_VER >= 1000

#	include "Common/Base/Diagnostic/XTPDisableNoisyWarnings.h"

class CXTPChartSeriesPoint;
class CXTPChartElementView;
class CXTPChartDeviceCommand;
class CXTPChartDeviceContext;

//===========================================================================
// Summary:
//     This class abstracts the view of a pyramid series point.This class is a kind of
//     CXTPChartSeriesPointView.
// Remarks:
//     A pyramid chart (or a circle graph) is a circular chart divided into sectors,
//     illustrating percents. In a pyramid chart, the arc length of each sector (and
//     consequently its central angle and area), is proportional to the quantity
//     it represents. Together, the sectors create a full disk.
//===========================================================================
class _XTP_EXT_CLASS CXTPChartPyramidSeriesPointView : public CXTPChartPyramidSeriesPointViewBase
{
	DECLARE_DYNAMIC(CXTPChartPyramidSeriesPointView);

public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPChartPyramidSeriesPointView object.
	// Parameters:
	//     pPoint        - Pointer to chart series point.
	//     bAddToParent  - If TRUE the view will be be added to parent's child view list.
	// Remarks:
	//-----------------------------------------------------------------------
	CXTPChartPyramidSeriesPointView(CXTPChartSeriesPoint* pPoint,
									CXTPChartElementView* pParentView);
	CXTPChartPyramidSeriesPointView(
		CXTPChartSeriesPoint* pPoint, CXTPChartElementView* pParentView,
		BOOL bAddToParent); // <combine
							// CXTPChartPyramidSeriesPointView::CXTPChartPyramidSeriesPointView@CXTPChartSeriesPoint*@CXTPChartElementView*>

public:
	//-------------------------------------------------------------------------
	// Summary:
	//     Use this function to calculate the layout of the pyramid series point.
	// Parameters:
	//     dAngle - The swipe angle of the sector(pyramid).
	//-------------------------------------------------------------------------
	void CalculateLayout(int nIndex, int nCount, double dFrom, double dTo);

protected:
	//-------------------------------------------------------------------------
	// Summary:
	//     This function creates a CXTPChartDeviceCommand object, this object
	//     represents the rendering of the pyramid series point.
	// Parameters:
	//     pDC      - Pointer to a CXTPChartDeviceContext object.
	// Returns:
	//     Returns CXTPChartDeviceCommand object, this object handles
	//     the rendering of an element in the chart. Here it handles
	//     the drawing of the pyramid series point.
	//-------------------------------------------------------------------------
	virtual CXTPChartDeviceCommand* CreateDeviceCommand(CXTPChartDeviceContext* pDC);

public:
	CXTPChartRectF m_rc;

	double m_dFrom;
	double m_dTo;
};

#	include "Common/Base/Diagnostic/XTPEnableNoisyWarnings.h"
#endif //#if !defined(__XTPCHART2DPYRAMIDSERIESPOINTVIEW_H__)
