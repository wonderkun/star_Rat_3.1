// XTPChart3dPyramidSeriesLabel.h
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
#if !defined(__XTPCHART3DPYRAMIDSERIESLABEL_H__)
#	define __XTPCHART3DPYRAMIDSERIESLABEL_H__
//}}AFX_CODEJOCK_PRIVATE

#	if _MSC_VER >= 1000
#		pragma once
#	endif // _MSC_VER >= 1000

#	include "Common/Base/Diagnostic/XTPDisableNoisyWarnings.h"

class CXTPChartSeriesView;
class CXTPChartPyramidSeriesPointViewBase;
class CXTPChartPyramidSeriesStyleBase;
class CXTPChart3dPyramidSeriesPointView;
class CXTPChart3dPyramidSeriesStyle;

//===========================================================================
// Summary:
//     CXTPChartPyramidSeriesLabelBase is a kind of CXTPChart3dPyramidSeriesLabel, this class
//     abstracts the label of a pyramid series.
//===========================================================================
class _XTP_EXT_CLASS CXTPChart3dPyramidSeriesLabel : public CXTPChartPyramidSeriesLabelBase
{
	DECLARE_SERIAL(CXTPChart3dPyramidSeriesLabel);

public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPChart3dPyramidSeriesLabel object.
	//-----------------------------------------------------------------------
	CXTPChart3dPyramidSeriesLabel();

protected:
	//-------------------------------------------------------------------------
	// Summary:
	//     This function creates the view of the pyramid series.
	// Parameters:
	//     pDC - The chart device context object pointer.
	//     pPointView - The series point view.
	//     pParentView - Parent element view pointer.
	// Returns:
	//     Returns an pointer to CXTPChartSeriesLabelView which is a kind of
	//     CXTPChartElementView object newly created.
	//-------------------------------------------------------------------------
	virtual CXTPChartElementView* CreateView(CXTPChartDeviceContext* pDC,
											 CXTPChartSeriesPointView* pPointView,
											 CXTPChartElementView* pParentView);
};

//===========================================================================
// Summary:
//      Represents series label view object.
//===========================================================================
class _XTP_EXT_CLASS CXTPChart3dPyramidSeriesLabelView : public CXTPChartPyramidSeriesLabelViewBase
{
	DECLARE_DYNAMIC(CXTPChart3dPyramidSeriesLabelView);

public:
	//-----------------------------------------------------------------------
	// Summary:
	//      Constructs view object.
	// Parameters:
	//      pLabel - Label model object pointer.
	//      pPointView - Related point view object pointer.
	//      pParentView - Parent view object pointer.
	//-----------------------------------------------------------------------
	CXTPChart3dPyramidSeriesLabelView(CXTPChartSeriesLabel* pLabel,
									  CXTPChartSeriesPointView* pPointView,
									  CXTPChartElementView* pParentView);

	//-----------------------------------------------------------------------
	// Summary:
	//      Handles view object destruction.
	//-----------------------------------------------------------------------
	~CXTPChart3dPyramidSeriesLabelView();

	//-----------------------------------------------------------------------
	// Summary:
	//      Creates label transposition device command object.
	// Parameters:
	//      pDC - Target device context.
	// Returns:
	//      New label transposition device command object.
	//-----------------------------------------------------------------------
	virtual CXTPChartDeviceCommand* CreateTranspositionDeviceCommand(CXTPChartDeviceContext* pDC);

	//-----------------------------------------------------------------------
	// Summary:
	//      Creates label drawing device command object.
	// Parameters:
	//      pDC - Target device context.
	// Returns:
	//      New label drawing device command object.
	//-----------------------------------------------------------------------
	virtual CXTPChartDeviceCommand* CreateDeviceCommand(CXTPChartDeviceContext* pDC);

	//-----------------------------------------------------------------------
	// Summary:
	//      Creates label connector drawing device command object.
	// Parameters:
	//      pDC - Target device context.
	// Returns:
	//      New label connector drawing device command object.
	//-----------------------------------------------------------------------
	virtual CXTPChartDeviceCommand* CreateConnectorDeviceCommand(CXTPChartDeviceContext* pDC);

	//-----------------------------------------------------------------------
	// Summary:
	//      Obtains a previously set connector start point.
	// Returns:
	//      Connector start point or NULL if not set.
	// See also:
	//      SetConnectorStartPoint
	//-----------------------------------------------------------------------
	const CXTPPoint3d* GetConnectorStartPoint() const;

	//-----------------------------------------------------------------------
	// Summary:
	//      Sets connector start point.
	// Parameters:
	//      pointer - New value of the connector start point.
	// See also:
	//      GetConnectorStartPoint
	//-----------------------------------------------------------------------
	void SetConnectorStartPoint(const CXTPPoint3d& point);

	//-----------------------------------------------------------------------
	// Summary:
	//      Obtains a previously set connector bend point.
	// Returns:
	//      Connector bend point or NULL if not set.
	// See also:
	//      SetConnectorBendPoint
	//-----------------------------------------------------------------------
	const CXTPPoint3d* GetConnectorBendPoint() const;

	//-----------------------------------------------------------------------
	// Summary:
	//      Sets connector bend point.
	// Parameters:
	//      pointer - New value of the connector bend point.
	// See also:
	//      GetConnectorBendPoint
	//-----------------------------------------------------------------------
	void SetConnectorBendPoint(const CXTPPoint3d& point);

	//-----------------------------------------------------------------------
	// Summary:
	//      Obtains a previously set connector end point.
	// Returns:
	//      Connector end point or NULL if not set.
	// See also:
	//      SetConnectorEndPoint
	//-----------------------------------------------------------------------
	const CXTPPoint3d* GetConnectorEndPoint() const;

	//-----------------------------------------------------------------------
	// Summary:
	//      Sets connector end point.
	// Parameters:
	//      pointer - New value of the connector end point.
	// See also:
	//      GetConnectorEndPoint
	//-----------------------------------------------------------------------
	void SetConnectorEndPoint(const CXTPPoint3d& point);

	//-----------------------------------------------------------------------
	// Summary:
	//      Obtains a previously set label anchor point.
	// Returns:
	//      Label anchor point or NULL if not set.
	// See also:
	//      SetLabelAnchorPoint
	//-----------------------------------------------------------------------
	const CPoint* GetLabelAnchorPoint() const;

	//-----------------------------------------------------------------------
	// Summary:
	//      Sets label anchor point.
	// Parameters:
	//      ptAnchor - New value of the label anchor point.
	// See also:
	//      GetLabelAnchorPoint
	//-----------------------------------------------------------------------
	void SetLabelAnchorPoint(CPoint ptAnchor);

	//-----------------------------------------------------------------------
	// Summary:
	//      Obtains a previously set label anchor origin point.
	// Returns:
	//      Label anchor origin point or NULL if not set.
	// See also:
	//      SetLabelAnchorOrigin
	//-----------------------------------------------------------------------
	const CPoint* GetLabelAnchorOrigin() const;

	//-----------------------------------------------------------------------
	// Summary:
	//      Sets label anchor origin point.
	// Parameters:
	//      ptAnchorOrigin - New value of the label anchor origin point.
	// See also:
	//      GetLabelAnchorOrigin
	//-----------------------------------------------------------------------
	void SetLabelAnchorOrigin(CPoint ptAnchorOrigin);

	//-----------------------------------------------------------------------
	// Summary:
	//      Makes label left directed.
	// See also:
	//      IsLeftDirected
	//-----------------------------------------------------------------------
	void SetLeftDirected();

	//-----------------------------------------------------------------------
	// Summary:
	//      Determies if the label is left directed.
	// Returns:
	//      TRUE if left directed.
	// See also:
	//      SetLeftDirected
	//-----------------------------------------------------------------------
	BOOL IsLeftDirected() const;

	//-----------------------------------------------------------------------
	// Summary:
	//      Makes label right directed.
	// See also:
	//      IsRightDirected
	//-----------------------------------------------------------------------
	void SetRightDirected();

	//-----------------------------------------------------------------------
	// Summary:
	//      Determies if the label is right directed.
	// Returns:
	//      TRUE if right directed.
	// See also:
	//      SetRightDirected
	//-----------------------------------------------------------------------
	BOOL IsRightDirected() const;

	//-----------------------------------------------------------------------
	// Summary:
	//      Determines if connector is visible.
	// Returns:
	//      TRUE if connector is visible.
	// See also:
	//      SetConnectorVisible
	//-----------------------------------------------------------------------
	BOOL IsConnectorVisible() const;

	//-----------------------------------------------------------------------
	// Summary:
	//      Sets connectoir visibility.
	// Parameters:
	//      bVisible - TRUE for making connector visible.
	// See also:
	//      SetConnectorVisible
	//-----------------------------------------------------------------------
	void SetConnectorVisible(BOOL bVisible = TRUE);

protected:
	CXTPPoint3d* m_ptStart;							   // Connector start point or NULL if not set.
	CXTPPoint3d* m_ptBend;							   // Connector bend point or NULL if not set.
	CXTPPoint3d* m_ptEnd;							   // Connector end point or NULL if not set.
	CPoint m_ptLabelAnchor;							   // Label anchor point.
	CPoint m_ptLabelAnchorOrigin;					   // Label anchor point origin.
	CXTPChart3dPyramidSeriesPointView* m_p3dPointView; // Point view.
	BOOL m_bLeftDirected;							   // TRUE if label is to be left directed.
	BOOL m_bConnectorVisible;						   // TRUE if connector is visible.

	friend class CXTPChart3dPyramidSeriesLabelsView;
};

AFX_INLINE const CXTPPoint3d* CXTPChart3dPyramidSeriesLabelView::GetConnectorStartPoint() const
{
	return m_ptStart;
}

AFX_INLINE const CXTPPoint3d* CXTPChart3dPyramidSeriesLabelView::GetConnectorBendPoint() const
{
	return m_ptBend;
}

AFX_INLINE const CXTPPoint3d* CXTPChart3dPyramidSeriesLabelView::GetConnectorEndPoint() const
{
	return m_ptEnd;
}

AFX_INLINE void CXTPChart3dPyramidSeriesLabelView::SetLabelAnchorPoint(CPoint ptAnchor)
{
	m_ptLabelAnchor = ptAnchor;
}

AFX_INLINE void CXTPChart3dPyramidSeriesLabelView::SetLabelAnchorOrigin(CPoint ptAnchorOrigin)
{
	m_ptLabelAnchorOrigin = ptAnchorOrigin;
}

AFX_INLINE void CXTPChart3dPyramidSeriesLabelView::SetLeftDirected()
{
	m_bLeftDirected = TRUE;
}

AFX_INLINE BOOL CXTPChart3dPyramidSeriesLabelView::IsLeftDirected() const
{
	return m_bLeftDirected;
}

AFX_INLINE void CXTPChart3dPyramidSeriesLabelView::SetRightDirected()
{
	m_bLeftDirected = FALSE;
}

AFX_INLINE BOOL CXTPChart3dPyramidSeriesLabelView::IsRightDirected() const
{
	return !m_bLeftDirected;
}

AFX_INLINE BOOL CXTPChart3dPyramidSeriesLabelView::IsConnectorVisible() const
{
	return m_bConnectorVisible;
}

AFX_INLINE void CXTPChart3dPyramidSeriesLabelView::SetConnectorVisible(BOOL bVisible /*= TRUE*/)
{
	m_bConnectorVisible = bVisible;
}

//===========================================================================
// Summary:
//      Represents a view object for all pyramid series labels.
//===========================================================================
class _XTP_EXT_CLASS CXTPChart3dPyramidSeriesLabelsView : public CXTPChartElementView
{
	DECLARE_DYNAMIC(CXTPChart3dPyramidSeriesLabelsView);

public:
	//-----------------------------------------------------------------------
	// Summary:
	//      Constructs view object.
	// Parameters:
	//      pParentView - Parent view pointer.
	//-----------------------------------------------------------------------
	CXTPChart3dPyramidSeriesLabelsView(CXTPChartElementView* pParentView);

public:
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

	//-----------------------------------------------------------------------
	// Summary:
	//      Resolves label overlapping in implementation specific way.
	//-----------------------------------------------------------------------
	void ResolveOverlapping();

private:
	CXTPChart3dPyramidSeriesStyle* GetStyle() const;
};

#	include "Common/Base/Diagnostic/XTPEnableNoisyWarnings.h"
#endif //#if !defined(__XTPCHART3DPYRAMIDSERIESLABEL_H__)
