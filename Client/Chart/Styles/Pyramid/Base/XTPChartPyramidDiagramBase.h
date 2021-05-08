// XTPChartPyramidDiagramBase.h
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
#if !defined(__XTPCHARTPYRAMIDDIAGRAMBASE_H__)
#	define __XTPCHARTPYRAMIDDIAGRAMBASE_H__
//}}AFX_CODEJOCK_PRIVATE

#	if _MSC_VER >= 1000
#		pragma once
#	endif // _MSC_VER >= 1000

#	include "Common/Base/Diagnostic/XTPDisableNoisyWarnings.h"

class CXTPChartDeviceContext;
class CXTPChartElementView;
class CXTPChartDiagramView;

//{{AFX_CODEJOCK_PRIVATE

class _XTP_EXT_CLASS CXTPChartPyramidDiagramBaseImpl
{
protected:
	void CalculateSeriesLayout(CXTPChartDeviceContext* pDC, CXTPChartDiagramView* pView);
};

//}}AFX_CODEJOCK_PRIVATE

//===========================================================================
// Summary:
//     This class abstracts the pyramid diagram.
//===========================================================================
template<class BaseDiagram>
class CXTPChartPyramidDiagramBase
	: public BaseDiagram
	, private CXTPChartPyramidDiagramBaseImpl
{
protected:
	//-----------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPChartPyramidDiagramBase object.
	// Remarks:
	//-----------------------------------------------------------------------
	CXTPChartPyramidDiagramBase();

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
											 CXTPChartElementView* pParent) = 0;

	//-------------------------------------------------------------------------
	// Summary:
	//     Call this function to calculate the pyramid series layout.
	// Parameters:
	//     pDC           - A pointer to chart device context.
	//     pView         - A pointer to the diagram view.
	//-------------------------------------------------------------------------
	virtual void CalculateSeriesLayout(CXTPChartDeviceContext* pDC, CXTPChartDiagramView* pView);
};

template<class BaseDiagram>
AFX_INLINE CXTPChartPyramidDiagramBase<BaseDiagram>::CXTPChartPyramidDiagramBase()
{
}

template<class BaseDiagram>
AFX_INLINE void CXTPChartPyramidDiagramBase<BaseDiagram>::CalculateSeriesLayout(
	CXTPChartDeviceContext* pDC, CXTPChartDiagramView* pView)
{
	CXTPChartPyramidDiagramBaseImpl::CalculateSeriesLayout(pDC, pView);
}

typedef CXTPChartPyramidDiagramBase<CXTPChart2dDiagram> CXTPChart2dPyramidDiagramBase;
typedef CXTPChartPyramidDiagramBase<CXTPChart3dDiagram> CXTPChart3dPyramidDiagramBase;

#	include "Common/Base/Diagnostic/XTPEnableNoisyWarnings.h"
#endif //#if !defined(__XTPCHARTPYRAMIDDIAGRAMBASE_H__)
