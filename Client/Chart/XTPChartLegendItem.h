// XTPChartLegendItem.h
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
#if !defined(__XTPCHARTLEGENDITEM_H__)
#	define __XTPCHARTLEGENDITEM_H__
//}}AFX_CODEJOCK_PRIVATE

#	if _MSC_VER >= 1000
#		pragma once
#	endif // _MSC_VER >= 1000

#	include "Common/Base/Diagnostic/XTPDisableNoisyWarnings.h"

//===========================================================================
// Summary:
//     CXTPChartLegendItemView is an abstract base class, this class also act as
//     a multiple inheritance base class.It represents a chart legend item.
// Remarks:
//===========================================================================
class _XTP_EXT_CLASS CXTPChartLegendItemView
{
public:
	//-------------------------------------------------------------------------
	// Summary:
	//     This function returns the legend name, it is a pure virtual
	//     function so it should be implemented in the derived classes.
	// Returns:
	//     Returns the legend name represented by the CXTPChartString class.
	// Remarks:
	// See Also:
	//-------------------------------------------------------------------------
	virtual CXTPChartString GetLegendName() const = 0;

	//-------------------------------------------------------------------------
	// Summary:
	//     This function creates a CXTPChartDeviceCommand object, this object
	//     represents the rendering of a legend item in the chart.
	// Returns:
	//     Returns CXTPChartDeviceCommand object, this object handles
	//     the rendering of an element in the chart. Here it handles
	//     the drawing of the legend item.
	// Remarks:
	// See Also:
	//-------------------------------------------------------------------------
	virtual CXTPChartDeviceCommand* CreateLegendDeviceCommand(CXTPChartDeviceContext* pDC,
															  CRect rcBounds) = 0;
};

class _XTP_EXT_CLASS CXTPChartLegendItem : public CXTPChartElement
{
private:
	enum
	{
		UseDefaultLineThickness = -1,
	};

public:
	CXTPChartLegendItem();

	void SetLineThickness(int nLineThickness);

	int GetActualLineThickness() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this function to set dash line style.
	// Parameters:
	//     nDashStyle - An enumerated value specifying the line style of choice.
	// Remarks:
	//-----------------------------------------------------------------------
	void SetDashStyle(XTPChartDashStyle nDashStyle);

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this function to get the dash line style.
	// Returns:
	//     An enumerated value specifying the line style.
	// Remarks:
	//-----------------------------------------------------------------------
	XTPChartDashStyle GetDashStyle() const;

protected:
	int m_nLineThickness;
	XTPChartDashStyle m_nDashStyle; // The dash style.

#	ifdef _XTP_ACTIVEX
public:
	//{{AFX_CODEJOCK_PRIVATE
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
	DECLARE_OLETYPELIB_EX(CXTPChartLegendItem);
//}}AFX_CODEJOCK_PRIVATE
#	endif

	friend class CXTPChartSeries;
};

#	include "Common/Base/Diagnostic/XTPEnableNoisyWarnings.h"
#endif //#if !defined(__XTPCHARTLEGENDITEM_H__)
