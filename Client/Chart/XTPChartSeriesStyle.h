// XTPChartSeriesStyle.h
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
#if !defined(__XTPCHARTSERIESSTYLE_H__)
#	define __XTPCHARTSERIESSTYLE_H__
//}}AFX_CODEJOCK_PRIVATE

#	if _MSC_VER >= 1000
#		pragma once
#	endif // _MSC_VER >= 1000

#	include "Common/Base/Diagnostic/XTPDisableNoisyWarnings.h"

class CXTPChartDiagram;
class CXTPChartSeriesLabel;
class CXTPChartSeriesView;
class CXTPChartSeries;
class CXTPChartDiagramView;
class CXTPChartAxis;
class CXTPChartSeriesStyleAppearance;
class CXTPChartErrorBar;
class CXTPChartDeviceCommand;

//===========================================================================
// Summary:
//     CXTPChartSeriesStyle is CXTPChartElement derived class, represents base class for all Styles
//     for the Chart.
// Remarks:
//===========================================================================
class _XTP_EXT_CLASS CXTPChartSeriesStyle : public CXTPChartElement
{
	DECLARE_DYNAMIC(CXTPChartSeriesStyle);

public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPChartSeriesStyle object.
	// Remarks:
	//-----------------------------------------------------------------------
	CXTPChartSeriesStyle();

	//-------------------------------------------------------------------------
	// Summary:
	//     Destroys a CXTPChartSeriesStyle object, handle cleanup.
	//-------------------------------------------------------------------------
	virtual ~CXTPChartSeriesStyle();

public:
	//-------------------------------------------------------------------------
	// Summary:
	//     Call this method to get properties for series label.
	// Returns:
	//     Pointer to CXTPChartSeriesLabel that contains properties for label
	//-------------------------------------------------------------------------
	CXTPChartSeriesLabel* GetLabel() const;

	CXTPChartSeriesLabel* SetLabel(CXTPChartSeriesLabel* pLabel);

	//-------------------------------------------------------------------------
	// Summary:
	//     Call this method to get properties for error bar.
	// Returns:
	//     Pointer to CXTPChartErrorBar that contains properties for error bar
	//-------------------------------------------------------------------------
	CXTPChartErrorBar* GetErrorBar() const;

	CXTPChartErrorBar* SetErrorBar(CXTPChartErrorBar* pErrorBar);

	//-------------------------------------------------------------------------
	// Summary:
	//     This method is called to allow style create diagram object
	// Returns:
	//     New diagram object that will contain series.
	//-------------------------------------------------------------------------
	virtual CXTPChartDiagram* CreateDiagram();

	//-------------------------------------------------------------------------
	// Summary:
	//     This method is called to ask style if series can be inserted in existing diagram
	// Parameters:
	//     pDiagram - Diagram to check
	// Returns:
	//     TRUE if Series can be inserted to Diagram
	//-------------------------------------------------------------------------
	virtual BOOL IsStyleDiagram(CXTPChartDiagram* pDiagram) const;

	//-------------------------------------------------------------------------
	// Summary:
	//     Call this method to get color assigned to this series
	// Returns:
	//     Color that was assigned to this style of CXTPChartColor::Empty if appearance color should
	//     be used
	//-------------------------------------------------------------------------
	CXTPChartColor GetColor() const;

	//-------------------------------------------------------------------------
	// Summary:
	//     Call this method to set color of the series
	// Parameters:
	//     clr - New Color to be set. It can be CXTPChartColor::Empty to use default appearance
	//     color.
	//-------------------------------------------------------------------------
	void SetColor(CXTPChartColor clr);

	//-------------------------------------------------------------------------
	// Summary:
	//     Call this method to set individual color for each point of series
	// Parameters:
	//     bColorEach - TRUE if individual color should be used for each point of series
	//-------------------------------------------------------------------------
	void SetColorEach(BOOL bColorEach);

	//-------------------------------------------------------------------------
	// Summary:
	//     This method is called to determine if individual color should be used for each point of
	//     series
	//-------------------------------------------------------------------------
	BOOL IsColorEach() const;

	//-----------------------------------------------------------------------
	// Summary:
	//      Provides default implementation for axis side margins correction.
	// Parameters:
	//      pAxis - Axis pointer.
	//      nMinValue - Minimal acceptable value.
	//      nMaxValue - Maximal acceptable value.
	//      nCorrection - Result new correction value.
	//-----------------------------------------------------------------------
	virtual void CorrectAxisSideMargins(CXTPChartAxis* pAxis, double nMinValue, double nMaxValue,
										double& nCorrection);

	//-----------------------------------------------------------------------
	// Summary:
	//      Obtains associated style appearance pointer.
	// Returns:
	//      Style appearance pointer
	//-----------------------------------------------------------------------
	virtual CXTPChartSeriesStyleAppearance* GetStyleAppearance() const;

	//-----------------------------------------------------------------------
	// Summary:
	//      Applies the style to the command provided in case the command
	//      needs style specific details for correct drawing.
	// Parameters:
	//      pCommand - Command pointer for which the style is to be applied.
	//-----------------------------------------------------------------------
	void ApplyTo(CXTPChartDeviceCommand* pCommand);

	//-----------------------------------------------------------------------
	// Summary:
	//      Obtains the index of a point element for which an internal value
	//      can be otained.
	// Returns:
	//      The index of a point element for which an internal value
	//      can be otained
	//-----------------------------------------------------------------------
	virtual int GetSeriesPointValueIndex() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Reads or writes this object from or to an archive.
	// Parameters:
	//     pPX - A CXTPPropExchange object to serialize to or from.
	//----------------------------------------------------------------------
	virtual void DoPropExchange(CXTPPropExchange* pPX);

	//-----------------------------------------------------------------------
	// Summary:
	//     This virtual method is called to create new  view associated with current style.
	// Parameters:
	//     pSeries - Series associated with style
	//     pDiagramView - Parent diagram view
	// Returns:
	//     Pointer to new CXTPChartSeriesView object.
	//----------------------------------------------------------------------
	virtual CXTPChartSeriesView* CreateView(CXTPChartSeries* pSeries,
											CXTPChartDiagramView* pDiagramView) = 0;

protected:
#	ifdef _XTP_ACTIVEX
public:
	//{{AFX_CODEJOCK_PRIVATE

	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
	DECLARE_OLETYPELIB_EX(CXTPChartSeriesStyle);

	afx_msg void OleChartChanged();
	afx_msg LPDISPATCH OleGetLabel();
	afx_msg LPDISPATCH OleGetErrorBar();
	afx_msg BOOL OleGetColorEach();
	afx_msg void OleSetColorEach(BOOL bColorEach);
	afx_msg OLE_COLOR OleGetColor();
	afx_msg void OleSetColor(OLE_COLOR clr);

//}}AFX_CODEJOCK_PRIVATE
#	endif

protected:
	friend class CXTPChartSeries;

	CXTPChartSeriesLabel* m_pLabel; // Label object
	CXTPChartErrorBar* m_pErrorBar; // Error bar object

	CXTPChartColor m_clrColor; // Custom color of series

	BOOL m_bColorEach; // TRUE to color each point.
};

AFX_INLINE CXTPChartDiagram* CXTPChartSeriesStyle::CreateDiagram()
{
	return NULL;
}

AFX_INLINE CXTPChartSeriesLabel* CXTPChartSeriesStyle::GetLabel() const
{
	return m_pLabel;
}

AFX_INLINE CXTPChartErrorBar* CXTPChartSeriesStyle::GetErrorBar() const
{
	return m_pErrorBar;
}

AFX_INLINE CXTPChartColor CXTPChartSeriesStyle::GetColor() const
{
	return m_clrColor;
}

AFX_INLINE void CXTPChartSeriesStyle::SetColor(CXTPChartColor clr)
{
	m_clrColor = clr;
	OnChartChanged();
}

AFX_INLINE BOOL CXTPChartSeriesStyle::IsColorEach() const
{
	return m_bColorEach;
}

AFX_INLINE void CXTPChartSeriesStyle::SetColorEach(BOOL bColorEach)
{
	m_bColorEach = bColorEach;
	OnChartChanged();
}

AFX_INLINE int CXTPChartSeriesStyle::GetSeriesPointValueIndex() const
{
	return 0;
}

#	include "Common/Base/Diagnostic/XTPEnableNoisyWarnings.h"
#endif //#if !defined(__XTPCHARTSERIESSTYLE_H__)
