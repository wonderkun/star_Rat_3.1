// XTPChartPyramidSeriesStyleBase.h
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
#if !defined(__XTPCHARTPYRAMIDSERIESSTYLEBASE_H__)
#	define __XTPCHARTPYRAMIDSERIESSTYLEBASE_H__
//}}AFX_CODEJOCK_PRIVATE

#	if _MSC_VER >= 1000
#		pragma once
#	endif // _MSC_VER >= 1000

#	include "Common/Base/Diagnostic/XTPDisableNoisyWarnings.h"

class CXTPChartSeriesView;
class CXTPChartBorder;
class CXTPChartFillStyle;
class CXTPChartDiagram;
class CXTPChartDiagramView;
class CXTPChartSeries;

//===========================================================================
// Summary:
//     This class abstracts the basic style of a pyramid series.
//===========================================================================
class _XTP_EXT_CLASS CXTPChartPyramidSeriesStyleBase : public CXTPChartSeriesStyle
{
	DECLARE_DYNAMIC(CXTPChartPyramidSeriesStyleBase);

public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPChartPyramidSeriesStyleBase object.
	// Remarks:
	//-----------------------------------------------------------------------
	CXTPChartPyramidSeriesStyleBase();

	//-------------------------------------------------------------------------
	// Summary:
	//     Destroys a CXTPChartPyramidSeriesStyleBase object, handle cleanup.
	//-------------------------------------------------------------------------
	virtual ~CXTPChartPyramidSeriesStyleBase();

	//-------------------------------------------------------------------------
	// Summary:
	//     Gets/sets the distance bettween stacked pyramid point (a gap).
	// Parameters:
	//     nPointDistance - Distance value in pixels.
	// Returns:
	//     Current distance value in pixels.
	//-------------------------------------------------------------------------
	int GetPointDistance() const;
	void SetPointDistance(int nPointDistance); // <combine GetPointDistance>

	//-------------------------------------------------------------------------
	// Summary:
	//     Gets/sets the the ratio value that determines whether a pyramid
	//     looks more stretched towards its cone or it has a wider base.
	//     If the ratio value is less than 1 then the pyramid's base is wider than
	//     its height.
	//     If the ratio value is greater than 1 then the pyramid's base width is
	//     less than pyramid's height, making tall and acute.
	// Parameters:
	//     dRatio - A new ratio value.
	// Returns:
	//     Current ratio value.
	//-------------------------------------------------------------------------
	double GetHeightToWidthRatio() const;
	void SetHeightToWidthRatio(double dRatio); // <combine GetHeightToWidthRatio>

	//-------------------------------------------------------------------------
	// Summary:
	//     Call this function to get the background fill style.
	// Returns:
	//     Returns the pointer to CXTPChartFillStyle object, which abstracts
	//     various fill styles.
	//-------------------------------------------------------------------------
	CXTPChartFillStyle* GetFillStyle() const;

	//-----------------------------------------------------------------------
	// Summary:
	//      Obtains border object pointer.
	// Returns:
	//      Associated border object pointer.
	//-----------------------------------------------------------------------
	CXTPChartBorder* GetBorder() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this member function to Store/Load an event using the
	//     specified data object.
	// Parameters:
	//     pPX - Source or destination CXTPPropExchange data object reference.
	// Remarks:
	//     This member function is used to store or load event data to or
	//     from a storage.
	//-----------------------------------------------------------------------
	void DoPropExchange(CXTPPropExchange* pPX);

protected:
	//-------------------------------------------------------------------------
	// Summary:
	//     Call this function to create the pyramid diagram object.
	// Returns:
	//     A pointer to CXTPChartDiagram object which points to a newly created
	//     CXTPChart2dPyramidDiagramBase/CXTPChart3dPyramidDiagramBase object.
	//-------------------------------------------------------------------------
	virtual CXTPChartDiagram* CreateDiagram() = 0;

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
											CXTPChartDiagramView* pDiagramView) = 0;

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
	virtual BOOL IsStyleDiagram(CXTPChartDiagram* pDiagram) const = 0;

#	ifdef _XTP_ACTIVEX
public:
	//{{AFX_CODEJOCK_PRIVATE
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
//}}AFX_CODEJOCK_PRIVATE
#	endif

protected:
	double m_dHeightToWidthRatio;
	int m_nPointDistance;
	CXTPChartBorder* m_pBorder;
	CXTPChartFillStyle* m_pFillStyle;
};

AFX_INLINE int CXTPChartPyramidSeriesStyleBase::GetPointDistance() const
{
	return m_nPointDistance;
}

AFX_INLINE void CXTPChartPyramidSeriesStyleBase::SetPointDistance(int nPointDistance)
{
	m_nPointDistance = nPointDistance;
	OnChartChanged();
}

AFX_INLINE CXTPChartFillStyle* CXTPChartPyramidSeriesStyleBase::GetFillStyle() const
{
	return m_pFillStyle;
}

AFX_INLINE CXTPChartBorder* CXTPChartPyramidSeriesStyleBase::GetBorder() const
{
	return m_pBorder;
}

AFX_INLINE void CXTPChartPyramidSeriesStyleBase::SetHeightToWidthRatio(double dRatio)
{
	m_dHeightToWidthRatio = dRatio;
	OnChartChanged();
}

AFX_INLINE double CXTPChartPyramidSeriesStyleBase::GetHeightToWidthRatio() const
{
	return m_dHeightToWidthRatio;
}

#	include "Common/Base/Diagnostic/XTPEnableNoisyWarnings.h"
#endif //#if !defined(__XTPCHARTPYRAMIDSERIESSTYLEBASE_H__)
