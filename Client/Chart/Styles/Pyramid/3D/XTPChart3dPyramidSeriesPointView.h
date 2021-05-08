// XTPChart3dPyramidSeriesPointView.h
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
#if !defined(__XTPCHART3DPYPAMIDSERIESPOINTVIEW_H__)
#	define __XTPCHART3DPYRAMIDSERIESPOINTVIEW_H__
//}}AFX_CODEJOCK_PRIVATE

#	if _MSC_VER >= 1000
#		pragma once
#	endif // _MSC_VER >= 1000

#	include "Common/Base/Diagnostic/XTPDisableNoisyWarnings.h"

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
class _XTP_EXT_CLASS CXTPChart3dPyramidSeriesPointView
	: public CXTPChartPyramidSeriesPointViewBase
	, private CXTPChart3dPyramidDeviceCommandEvents
{
	DECLARE_DYNAMIC(CXTPChart3dPyramidSeriesPointView);

public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPChart3dPyramidSeriesPointView object.
	// Parameters:
	//     pPoint        - Pointer to chart series point.
	//     pParentView   - Parent element view pointer.
	//-----------------------------------------------------------------------
	CXTPChart3dPyramidSeriesPointView(CXTPChartSeriesPoint* pPoint,
									  CXTPChartElementView* pParentView);

	//-----------------------------------------------------------------------
	// Summary:
	//      Handles view destruction.
	//-----------------------------------------------------------------------
	virtual ~CXTPChart3dPyramidSeriesPointView();

public:
	//-------------------------------------------------------------------------
	// Summary:
	//     Use this function to calculate the layout of the pyramid series point.
	// Parameter:
	//     nIndex - Point index.
	//     nCount - Total number of points.
	//     dFrom - The percentage factor value in the range 0..1 of the inital pyramid point value.
	//     dTo - The percentage factor value in the range 0..1 of the final pyramid point value.
	//-------------------------------------------------------------------------
	virtual void CalculateLayout(int nIndex, int nCount, double dFrom, double dTo);

	//-----------------------------------------------------------------------
	// Summary:
	//      Obtains shape center connector point.
	// Returns:
	//      Shape center connector point.
	// See also:
	//      GetOuterCenterConnectorPoint
	//-----------------------------------------------------------------------
	const CXTPPoint3d& GetCenterShapeConnectorPoint() const;

	//-----------------------------------------------------------------------
	// Summary:
	//      Obtains outer shape center connector point.
	// Returns:
	//      Outer shape center connector point.
	// See also:
	//      GetCenterShapeConnectorPoint
	//-----------------------------------------------------------------------
	const CXTPPoint3d& GetOuterCenterConnectorPoint() const;

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
	//-----------------------------------------------------------------------
	// Summary:
	//      Notifies about updated boundaries of the command result.
	// Parameters:
	//      pCommand - Sender command pointer.
	//      rcBounds - Updated bounray rectangle.
	//-----------------------------------------------------------------------
	virtual void OnUpdateBounds(CXTPChartDeviceCommand* pCommand, CRect rcBounds);

	//-----------------------------------------------------------------------
	// Summary:
	//      Gets called when pyramid connector points are computed.
	// Parameters:
	//      pCommand - The sender command.
	//      ptShapeCenter - The coordinates of the physical shape center.
	//      ptOuterCenter - The coordinates of the most outer horizontal shape center point.
	//-----------------------------------------------------------------------
	virtual void OnSetConnectorPoints(CXTPChartDeviceCommand* pCommand, CXTPPoint3d ptShapeCenter,
									  CXTPPoint3d ptOuterCenter);

private:
	CXTPChartPyramidSeriesPointViewBase* m_p2dSeriesPointView; // Used for drawing 2D legend items
	CXTPPoint3d m_ptShapeCenter;
	CXTPPoint3d m_ptOuterCenter;
	CXTPSubscriptionList<CXTPChartDeviceCommand, CXTPChartDeviceCommandEvents>*
		m_pCommandSubscriptionList;

	double m_dWidth;
	double m_dHeight;
	double m_dFrom;
	double m_dTo;
};

AFX_INLINE const CXTPPoint3d& CXTPChart3dPyramidSeriesPointView::GetCenterShapeConnectorPoint() const
{
	return m_ptShapeCenter;
}

AFX_INLINE const CXTPPoint3d& CXTPChart3dPyramidSeriesPointView::GetOuterCenterConnectorPoint() const
{
	return m_ptOuterCenter;
}

#	include "Common/Base/Diagnostic/XTPEnableNoisyWarnings.h"
#endif //#if !defined(__XTPCHART3DPYRAMIDSERIESPOINTVIEW_H__)
