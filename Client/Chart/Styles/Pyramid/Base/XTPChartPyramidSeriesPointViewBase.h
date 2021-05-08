// XTPChartPyramidSeriesPointViewBase.h
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
#if !defined(__XTPCHARTPYRAMIDSERIESPOINTVIEWBASE_H__)
#	define __XTPCHARTPYRAMIDSERIESPOINTVIEWBASE_H__
//}}AFX_CODEJOCK_PRIVATE

#	if _MSC_VER >= 1000
#		pragma once
#	endif // _MSC_VER >= 1000

#	include "Common/Base/Diagnostic/XTPDisableNoisyWarnings.h"

class CXTPChartSeriesPoint;
class CXTPChartElementView;
class CXTPChartDeviceCommand;
class CXTPChartDeviceContext;
class CXTPChartPyramidSeriesViewBase;
class CXTPChartPyramidSeriesView;
class CXTPChart3dPyramidSeriesPointView;

//===========================================================================
// Summary:
//     This class abstracts the view of a pyramid series point.
//===========================================================================
class _XTP_EXT_CLASS CXTPChartPyramidSeriesPointViewBase : public CXTPChartSeriesPointView
{
	DECLARE_DYNAMIC(CXTPChartPyramidSeriesPointViewBase);

public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPChartPyramidSeriesPointViewBase object.
	// Parameters:
	//     pPoint        - Pointer to chart series point.
	//     pParentView   - Parent element view pointer.
	//     bAddToParent  - If TRUE the view will be be added to parent's child view list.
	//-----------------------------------------------------------------------
	CXTPChartPyramidSeriesPointViewBase(CXTPChartSeriesPoint* pPoint,
										CXTPChartElementView* pParentView);
	CXTPChartPyramidSeriesPointViewBase(
		CXTPChartSeriesPoint* pPoint, CXTPChartElementView* pParentView,
		BOOL bAddToParent); // <combine
							// CXTPChartPyramidSeriesPointViewBase::CXTPChartPyramidSeriesPointViewBase@CXTPChartSeriesPoint*@CXTPChartElementView*>

	//-------------------------------------------------------------------------
	// Summary:
	//     Destroys a CXTPChartPyramidSeriesPointViewBase object, handle cleanup.
	//-------------------------------------------------------------------------
	virtual ~CXTPChartPyramidSeriesPointViewBase();

	//-------------------------------------------------------------------------
	// Summary:
	//     Use this function to calculate the layout of the pyramid series point.
	// Parameter:
	//     nIndex - Point index.
	//     nCount - Total number of points.
	//     dFrom - The percentage factor value in the range 0..1 of the inital pyramid point value.
	//     dTo - The percentage factor value in the range 0..1 of the final pyramid point value.
	//-------------------------------------------------------------------------
	virtual void CalculateLayout(int nIndex, int nCount, double dFrom, double dTo) = 0;

	//-------------------------------------------------------------------------
	// Summary:
	//     Use this function to obtain the color value of the pyramid border.
	// Returns:
	//     Border color value.
	//-------------------------------------------------------------------------
	CXTPChartColor GetBorderActualColor() const;

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
	// Remarks:
	// See Also:
	//-------------------------------------------------------------------------
	virtual CXTPChartDeviceCommand* CreateDeviceCommand(CXTPChartDeviceContext* pDC) = 0;

	//-------------------------------------------------------------------------
	// Summary:
	//     This function creates a label view drawing command object.
	// Parameters:
	//     pDC      - Pointer to a CXTPChartDeviceContext object.
	//     rcBounds - The rectangular boundary of the legend.
	// Returns:
	//     Returns a new label view drawing command object.
	//-------------------------------------------------------------------------
	virtual CXTPChartDeviceCommand* CreateLegendDeviceCommand(CXTPChartDeviceContext* pDC,
															  CRect rcBounds);

protected:
	double m_dValue; // The value of the point.

	friend class CXTPChartPyramidSeriesViewBase;
	friend class CXTPChartPyramidSeriesView;
	friend class CXTPChart3dPyramidSeriesView;
	friend class CXTPChart3dPyramidSeriesPointView;
};

#	include "Common/Base/Diagnostic/XTPEnableNoisyWarnings.h"
#endif //#if !defined(__XTPCHARTPYRAMIDSERIESPOINTVIEWBASE_H__)
