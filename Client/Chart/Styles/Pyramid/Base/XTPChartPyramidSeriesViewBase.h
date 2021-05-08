// XTPChartPyramidSeriesViewBase.h
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
#if !defined(__XTPCHARTPYRAMIDSERIESVIEWBASE_H__)
#	define __XTPCHARTPYRAMIDSERIESVIEWBASE_H__
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
class CXTPChartDiagramDomain;

//===========================================================================
// Summary:
//     This class abstracts the view of a pyramid series.
//===========================================================================
class _XTP_EXT_CLASS CXTPChartPyramidSeriesViewBase : public CXTPChartSeriesView
{
	DECLARE_DYNAMIC(CXTPChartPyramidSeriesViewBase);

public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPChartPyramidSeriesViewBase object.
	// Parameters:
	//     pSeries       - Pointer to pyramid series object.
	//     pDiagramView  - Pointer to the pyramid diagram view.
	// Remarks:
	//-----------------------------------------------------------------------
	CXTPChartPyramidSeriesViewBase(CXTPChartSeries* pSeries, CXTPChartDiagramView* pDiagramView);

	//-------------------------------------------------------------------------
	// Summary:
	//     Destroys a CXTPChartPyramidSeriesViewBase object, handle cleanup.
	//-------------------------------------------------------------------------
	virtual ~CXTPChartPyramidSeriesViewBase();

public:
	//-------------------------------------------------------------------------
	// Summary:
	//     Call this function to calculate the pyramid series point layout.
	// Parameters:
	//     pDC      - Pointer to the chart device context.
	//     rcBounds - The rectangular boundary.
	//-------------------------------------------------------------------------
	virtual void CalculatePointLayout(CXTPChartDeviceContext* pDC, CRect rcBounds) = 0;

	//-------------------------------------------------------------------------
	// Summary:
	//     Call this function to calculate the pyramid series label layout.
	// Parameters:
	//     pDC      - Pointer to the chart device context.
	//-------------------------------------------------------------------------
	void CalculateLabelLayout(CXTPChartDeviceContext* pDC);

	//-------------------------------------------------------------------------
	// Summary:
	//     Call this function to create the pyramid diagram domain object associated
	//     with this object.
	// Parameters:
	//     pDC      - Pointer to the chart device context.
	//     rcBounds - The rectangular boundary of the diagram.
	// Returns:
	//     A pointer to the chart diagram domain object.
	//-------------------------------------------------------------------------
	virtual CXTPChartDiagramDomain* CreateDiagramDomain(CXTPChartDeviceContext* pDC,
														CRect rcBounds);

	//-------------------------------------------------------------------------
	// Summary:
	//     Call this function to get the inner bounds of the diagram.
	// Returns:
	//     A chart rect object denoting the rectangular boundary.
	//-------------------------------------------------------------------------
	virtual CXTPChartRectF GetInnerBounds() const;

	//-------------------------------------------------------------------------
	// Summary:
	//     Use this function to get the pyramid diagram domain object associated with
	//     this object.
	// Returns:
	//     A pointer to the chart diagram domain object.
	//-------------------------------------------------------------------------
	CXTPChartDiagramDomain* GetDomain() const;

	//-----------------------------------------------------------------------
	// Summary:
	//      Obtains maximum allowed label width.
	// Returns:
	//      Maximum allowed label width.
	//-----------------------------------------------------------------------
	int GetMaxLabelWidth() const;

protected:
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
															CXTPChartElementView* pParentView) = 0;

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
	virtual CXTPChartDeviceCommand* CreateDeviceCommand(CXTPChartDeviceContext* pDC) = 0;

	//-------------------------------------------------------------------------
	// Summary:
	//     These functions create a label view drawing command object.
	// Parameters:
	//     pDC       - Pointer to a CXTPChartDeviceContext object.
	//     rcBounds  - The rectangular boundary of the legend.
	// Returns:
	//     Returns a new label view drawing command object.
	//-------------------------------------------------------------------------
	virtual CXTPChartDeviceCommand* CreateLegendDeviceCommand(CXTPChartDeviceContext* pDC,
															  CRect rcBounds) = 0;

public:
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
															  CRect rcBounds, CXTPChartColor color1,
															  CXTPChartColor color2,
															  CXTPChartColor clrBorder) = 0;

	//{{AFX_CODEJOCK_PRIVATE
	void CalculateValues();
	//{{AFX_CODEJOCK_PRIVATE

protected:
	CXTPChartDiagramDomain* m_pDomain; // Pointer to the diagram domain.
	int m_nMaxLabelWidth;
};

AFX_INLINE CXTPChartDiagramDomain* CXTPChartPyramidSeriesViewBase::GetDomain() const
{
	return m_pDomain;
}

AFX_INLINE int CXTPChartPyramidSeriesViewBase::GetMaxLabelWidth() const
{
	return m_nMaxLabelWidth;
}

#	include "Common/Base/Diagnostic/XTPEnableNoisyWarnings.h"
#endif //#if !defined(__XTPCHARTPYRAMIDSERIESVIEWBASE_H__)
