// XTPChart2dPyramidSeriesLabel.h
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
#if !defined(__XTPCHART2DPYRAMIDSERIESLABEL_H__)
#	define __XTPCHART2DPYRAMIDSERIESLABEL_H__
//}}AFX_CODEJOCK_PRIVATE

#	if _MSC_VER >= 1000
#		pragma once
#	endif // _MSC_VER >= 1000

#	include "Common/Base/Diagnostic/XTPDisableNoisyWarnings.h"

class CXTPChartElementView;
class CXTPChartDeviceContext;
class CXTPChartSeriesPointView;
class CXTPChartElementView;

//===========================================================================
// Summary:
//     CXTPChartPyramidSeriesLabel is a kind of CXTPChartSeriesLabel, this class
//     abstracts the label of a pyramid series.
// Remarks:
//
//===========================================================================
class _XTP_EXT_CLASS CXTPChartPyramidSeriesLabel : public CXTPChartPyramidSeriesLabelBase
{
	DECLARE_SERIAL(CXTPChartPyramidSeriesLabel);

protected:
	//-------------------------------------------------------------------------
	// Summary:
	//     This function creates the view of the pyramid series.
	// Parameters:
	//     pDC - The chart device context object pointer.
	//     pPointView - The series point view.
	// Returns:
	//     Returns an pointer to CXTPChartSeriesLabelView which is a kind of
	//     CXTPChartElementView object newly created.
	// Remarks:
	// See Also:
	//-------------------------------------------------------------------------
	virtual CXTPChartElementView* CreateView(CXTPChartDeviceContext* pDC,
											 CXTPChartSeriesPointView* pPointView,
											 CXTPChartElementView* pParentView);

#	ifdef _XTP_ACTIVEX
public:
	//{{AFX_CODEJOCK_PRIVATE
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
	DECLARE_OLETYPELIB_EX(CXTPChartPyramidSeriesLabel);
	//}}AFX_CODEJOCK_PRIVATE
#	endif
};

//-----------------------------------------------------------------------
// Summary:
//      Defines 2D series label view.
//-----------------------------------------------------------------------
class _XTP_EXT_CLASS CXTPChartPyramidSeriesLabelView : public CXTPChartPyramidSeriesLabelViewBase
{
	DECLARE_DYNAMIC(CXTPChartPyramidSeriesLabelView);

public:
	//-----------------------------------------------------------------------
	// Summary:
	//      Constructs CXTPChartPyramidSeriesLabelView object.
	// Parameters:
	//      pLabel - Associated label model pointer.
	//      pPointView - Point view object pointer associated with the label.
	//      pParentView - Parent view pointer.
	//-----------------------------------------------------------------------
	CXTPChartPyramidSeriesLabelView(CXTPChartSeriesLabel* pLabel,
									CXTPChartSeriesPointView* pPointView,
									CXTPChartElementView* pParentView);

	//-----------------------------------------------------------------------
	// Summary:
	//      Creates view drawing device command for the device context specified.
	// Parameters:
	//      pDC - Device context pointer for which the drawing command is to be created.
	// Returns:
	//      A new instance of view drawing device command or NULL if no command
	//      is provided.
	//-----------------------------------------------------------------------
	virtual CXTPChartDeviceCommand* CreateDeviceCommand(CXTPChartDeviceContext* pDC);
};

#	include "Common/Base/Diagnostic/XTPEnableNoisyWarnings.h"
#endif //#if !defined(__XTPCHART2DPYRAMIDSERIESLABEL_H__)
