// XTPChartPyramidSeriesLabelBase.h
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
#if !defined(__XTPCHARTPYRAMIDSERIESLABELBASE_H__)
#	define __XTPCHARTPYRAMIDSERIESLABELBASE_H__
//}}AFX_CODEJOCK_PRIVATE

#	if _MSC_VER >= 1000
#		pragma once
#	endif // _MSC_VER >= 1000

#	include "Common/Base/Diagnostic/XTPDisableNoisyWarnings.h"

class CXTPChartPyramidSeriesStyleBase;
class CXTPPropExchange;
class CXTPChartDeviceContext;
class CXTPChartSeriesPointView;
class CXTPChartElementView;

//===========================================================================
// Summary:
//     This enumeration tell the various positions available for the pyramid label.
// Remarks:
//===========================================================================
enum XTPChartPyramidLabelPosition
{
	xtpChartPyramidLabelLeft,  // Place label on the left side of a pyramid point
	xtpChartPyramidLabelRight, // Place label on the right side of a pyramid point
	xtpChartPyramidLabelCenter // Place label in the center of a pyramid point
};

//===========================================================================
// Summary:
//     This class abstracts the pyramid series label.
//===========================================================================
class _XTP_EXT_CLASS CXTPChartPyramidSeriesLabelBase : public CXTPChartSeriesLabel
{
	DECLARE_DYNAMIC(CXTPChartPyramidSeriesLabelBase);

public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPChartPyramidSeriesLabelBase object.
	// Remarks:
	//-----------------------------------------------------------------------
	CXTPChartPyramidSeriesLabelBase();

	//-------------------------------------------------------------------------
	// Summary:
	//     Destroys a CXTPChartPyramidSeriesLabelBase object, handles cleanup
	//-------------------------------------------------------------------------
	virtual ~CXTPChartPyramidSeriesLabelBase();

public:
	//-------------------------------------------------------------------------
	// Summary:
	//     Call this function to get the label position.
	// Returns:
	//     A pyramid label position object describing the position of pyramid label.
	//-------------------------------------------------------------------------
	XTPChartPyramidLabelPosition GetPosition() const;

	//-------------------------------------------------------------------------
	// Summary:
	//     Call this function to set the label position.
	// Parameters:
	//     nPosition - A pyramid label position object describing the position of
	//                 pyramid label.
	//-------------------------------------------------------------------------
	void SetPosition(XTPChartPyramidLabelPosition nPosition);

	//-------------------------------------------------------------------------
	// Summary:
	//     Call this function to get the basic style of the pyramid series.
	// Returns:
	//     A pointer to CXTPChartPyramidSeriesStyleBase object.
	//-------------------------------------------------------------------------
	CXTPChartPyramidSeriesStyleBase* GetStyle() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this member function to Store/Load the properties of content
	//      using the specified data object.
	// Parameters:
	//     pPX - Source or destination CXTPPropExchange data object reference.
	// Remarks:
	//     This member function is used to store or load property data to or
	//     from a storage.
	//-----------------------------------------------------------------------
	void DoPropExchange(CXTPPropExchange* pPX);

	//-------------------------------------------------------------------------
	// Summary:
	//     Call this function to check whether the label is inside the pyramid.
	// Returns:
	//     Returns TRUE if the label is inside the pyramid and FALSE if not.
	//-------------------------------------------------------------------------
	BOOL IsInside() const;

protected:
	//-------------------------------------------------------------------------
	// Summary:
	//     This function creates the view of the pyramid series.
	// Parameters:
	//     pDC - The chart device context object pointer.
	//     pPointView - The series point view.
	//     pParentView - Parent element view.
	// Returns:
	//     Returns an pointer to CXTPChartSeriesLabelView which is a kind of
	//     CXTPChartElementView object newly created.
	// Remarks:
	// See Also:
	//-------------------------------------------------------------------------
	virtual CXTPChartElementView* CreateView(CXTPChartDeviceContext* pDC,
											 CXTPChartSeriesPointView* pPointView,
											 CXTPChartElementView* pParentView) = 0;

protected:
	XTPChartPyramidLabelPosition m_nPosition; // The pyramid label position.

#	ifdef _XTP_ACTIVEX
public:
	//{{AFX_CODEJOCK_PRIVATE
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
	DECLARE_OLETYPELIB_EX(CXTPChartPyramidSeriesLabelBase);
	//}}AFX_CODEJOCK_PRIVATE
#	endif
};

AFX_INLINE XTPChartPyramidLabelPosition CXTPChartPyramidSeriesLabelBase::GetPosition() const
{
	return m_nPosition;
}

AFX_INLINE void CXTPChartPyramidSeriesLabelBase::SetPosition(XTPChartPyramidLabelPosition nPosition)
{
	m_nPosition = nPosition;
	OnChartChanged();
}

//===========================================================================
// Summary:
//      This class abstracts the view of a pyramid series label.
//===========================================================================
class CXTPChartPyramidSeriesLabelViewBase : public CXTPChartSeriesLabelView
{
	DECLARE_DYNAMIC(CXTPChartPyramidSeriesLabelViewBase);

protected:
	//-----------------------------------------------------------------------
	// Summary:
	//      Constructs CXTPChartPyramidSeriesLabelViewBase object.
	// Parameters:
	//      pLabel - Associated label model pointer.
	//      pPointView - Point view object pointer associated with the label.
	//      pParentView - Parent view pointer.
	//-----------------------------------------------------------------------
	CXTPChartPyramidSeriesLabelViewBase(CXTPChartSeriesLabel* pLabel,
										CXTPChartSeriesPointView* pPointView,
										CXTPChartElementView* pParentView);

public:
	//-----------------------------------------------------------------------
	// Summary:
	//      Obtains label position.
	// Returns:
	//      Label position.
	//-----------------------------------------------------------------------
	XTPChartPyramidLabelPosition GetPosition() const;

	//-----------------------------------------------------------------------
	// Summary:
	//      Creates view drawing device command for the device context specified.
	// Parameters:
	//      pDC - Device context pointer for which the drawing command is to be created.
	// Returns:
	//      A new instance of view drawing device command or NULL if no command
	//      is provided.
	//-----------------------------------------------------------------------
	virtual CXTPChartDeviceCommand* CreateDeviceCommand(CXTPChartDeviceContext* pDC) = 0;
};

#	include "Common/Base/Diagnostic/XTPEnableNoisyWarnings.h"
#endif //#if !defined(__XTPCHARTPYRAMIDSERIESLABELBASE_H__)
