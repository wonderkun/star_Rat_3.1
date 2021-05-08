// XTPChart3dPyramidSeriesLabelsViewDeviceCommand.h
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
#if !defined(__XTPCHART3DPYRAMIDSERIESLABELSVIEWDEVICECOMMAND_H__)
#	define __XTPCHART3DPYRAMIDSERIESLABELSVIEWDEVICECOMMAND_H__
//}}AFX_CODEJOCK_PRIVATE

#	if _MSC_VER >= 1000
#		pragma once
#	endif // _MSC_VER >= 1000

#	include "Common/Base/Diagnostic/XTPDisableNoisyWarnings.h"

class CXTPChart3dPyramidSeriesLabelsView;
class CXTPChart3dPyramidSeriesLabelView;
class CXTPChart3dPyramidSeriesPointView;
class CXTPChart3dPyramidSeriesLabelDeviceCommand;
class CXTPChart3dDeviceContext;
class CXTPChart3dPyramidSeriesLabel;

//-----------------------------------------------------------------------
// Summary:
//      Implements 3D chart pyramid series label device command.
//-----------------------------------------------------------------------
class _XTP_EXT_CLASS CXTPChart3dPyramidSeriesLabelDeviceCommand : public CXTPChart3dDeviceCommand
{
	DECLARE_DYNAMIC(CXTPChart3dPyramidSeriesLabelDeviceCommand);

public:
	//-----------------------------------------------------------------------
	// Summary:
	//      Constructs CXTPChart3dPyramidSeriesLabelDeviceCommand object.
	// Parameters:
	//      pSeriesLabelView - Associated series label view pointer.
	//-----------------------------------------------------------------------
	CXTPChart3dPyramidSeriesLabelDeviceCommand(CXTPChart3dPyramidSeriesLabelView* pSeriesLabelView);

public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Override this function to write the drawing code for specific objects.
	// Parameters:
	//     pDC - A pointer to the chart device context.
	//-----------------------------------------------------------------------
	virtual void ExecuteOverride(CXTPChartDeviceContext* pDC);

	//-----------------------------------------------------------------------
	// Summary:
	//      Obtains label view object pointer.
	// Returns:
	//      Label view object pointer
	//-----------------------------------------------------------------------
	CXTPChart3dPyramidSeriesLabelView* GetSeriesLabelView() const;

	//-----------------------------------------------------------------------
	// Summary:
	//      Checks whether command object is in a failed state.
	// Returns:
	//      TRUE if command object is in a failed state.
	// See also:
	//      SetFailed
	//-----------------------------------------------------------------------
	BOOL IsFailed() const;

	//-----------------------------------------------------------------------
	// Summary:
	//      Sets command object to a failed state.
	//-----------------------------------------------------------------------
	void SetFailed();

	//-----------------------------------------------------------------------
	// Summary:
	//      Obtains label rectangle.
	// Returns:
	//      Label rectangle.
	// See also:
	//      SetLabelRect
	//-----------------------------------------------------------------------
	CRect GetLabelRect() const;

	//-----------------------------------------------------------------------
	// Summary:
	//      Sets label rectangle.
	// Parameters:
	//      rcLabel - Label rectangle.
	// See also:
	//      GetLabelRect
	//-----------------------------------------------------------------------
	void SetLabelRect(CRect rcLabel);

	//-----------------------------------------------------------------------
	// Summary:
	//      Computes connector vector.
	// Parameters:
	//      pDC - Target device context pointer.
	// Returns:
	//      TRUE if the vector is successfully computed.
	//-----------------------------------------------------------------------
	BOOL ComputeConnectorVector(CXTPChart3dDeviceContext* pDC);

	//-----------------------------------------------------------------------
	// Summary:
	//      Computes label.
	// Parameters:
	//      pDC - Target device context pointer.
	//-----------------------------------------------------------------------
	void ComputeLabel(CXTPChart3dDeviceContext* pDC);

	//-----------------------------------------------------------------------
	// Summary:
	//      Determines connector length value.
	// Returns:
	//      Connector length value.
	// See also:
	//      SetConnectorLength
	//-----------------------------------------------------------------------
	double GetConnectorLength() const;

	//-----------------------------------------------------------------------
	// Summary:
	//      Sets connector length value.
	// Parameters:
	//      dLength - New connector length value.
	// See also:
	//      GetConnectorLength
	//-----------------------------------------------------------------------
	void SetConnectorLength(double dLength);

	//-----------------------------------------------------------------------
	// Summary:
	//      Determines connector endpoint vertical offset value.
	// Returns:
	//      Connector endpoint vertical offset value.
	// See also:
	//      SetConnectorEndpointVerticalOffset
	//-----------------------------------------------------------------------
	double GetConnectorEndpointVerticalOffset() const;

	//-----------------------------------------------------------------------
	// Summary:
	//      Sets connector endpoint vertical offset value.
	// Parameters:
	//      yOffset - New connector endpoint vertical offset value.
	// See also:
	//      GetConnectorEndpointVerticalOffset
	//-----------------------------------------------------------------------
	void SetConnectorEndpointVerticalOffset(double yOffset);

private:
	BOOL ComputeConnectorStartPoint(CXTPChart3dDeviceContext* pDC, CXTPPoint3d& ptStart,
									CPoint& ptProjected) const;
	CXTPPoint3d ComputeConnectorEndPoint() const;
	CXTPPoint3d ComputeConnectorVectorEndPoint(const CXTPPoint3d& point) const;
	void ComputeLabel_Outside(const CSize& szLabel, const CPoint& ptAnchorOrigin,
							  const CPoint& ptAnchor);
	void ComputeLabel_Center(const CSize& szLabel, const CPoint& ptAnchor);

private:
	CXTPChart3dPyramidSeriesLabelView* m_pSeriesLabelView;
	CXTPChart3dPyramidSeriesPointView* m_pPointView;
	CRect m_rcLabel;
	BOOL m_bFailed;
	double m_dConnectorLength;
	double m_dConnectorEndpointVerticalOffset;
};

AFX_INLINE BOOL CXTPChart3dPyramidSeriesLabelDeviceCommand::IsFailed() const
{
	return m_bFailed;
}

AFX_INLINE void CXTPChart3dPyramidSeriesLabelDeviceCommand::SetFailed()
{
	m_bFailed = TRUE;
}

AFX_INLINE CXTPChart3dPyramidSeriesLabelView*
	CXTPChart3dPyramidSeriesLabelDeviceCommand::GetSeriesLabelView() const
{
	return m_pSeriesLabelView;
}

AFX_INLINE CRect CXTPChart3dPyramidSeriesLabelDeviceCommand::GetLabelRect() const
{
	return m_rcLabel;
}

AFX_INLINE void CXTPChart3dPyramidSeriesLabelDeviceCommand::SetLabelRect(CRect rcLabel)
{
	m_rcLabel = rcLabel;
}

AFX_INLINE double CXTPChart3dPyramidSeriesLabelDeviceCommand::GetConnectorLength() const
{
	return m_dConnectorLength;
}

AFX_INLINE void CXTPChart3dPyramidSeriesLabelDeviceCommand::SetConnectorLength(double dLength)
{
	m_dConnectorLength = dLength;
}

AFX_INLINE double
	CXTPChart3dPyramidSeriesLabelDeviceCommand::GetConnectorEndpointVerticalOffset() const
{
	return m_dConnectorEndpointVerticalOffset;
}

AFX_INLINE void
	CXTPChart3dPyramidSeriesLabelDeviceCommand::SetConnectorEndpointVerticalOffset(double yOffset)
{
	m_dConnectorEndpointVerticalOffset = yOffset;
}

//-----------------------------------------------------------------------
// Summary:
//      Represents device command for all pyramid series labels view.
//-----------------------------------------------------------------------
class _XTP_EXT_CLASS CXTPChart3dPyramidSeriesLabelsViewDeviceCommand
	: public CXTPChart3dDeviceCommand
	, private CXTPChartDeviceCommandEvents
{
public:
	//-----------------------------------------------------------------------
	// Summary:
	//      Constructs command object instance.
	// Parameters:
	//      pSeriesLabelsView - View pointer.
	//-----------------------------------------------------------------------
	CXTPChart3dPyramidSeriesLabelsViewDeviceCommand(
		CXTPChart3dPyramidSeriesLabelsView* pSeriesLabelsView);

public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Override this function to write the drawing code for specific objects.
	// Parameters:
	//     pDC - A pointer to the chart device context.
	//-----------------------------------------------------------------------
	virtual void ExecuteOverride(CXTPChartDeviceContext* pDC);

private:
	CXTPChart3dPyramidSeriesLabel* GetLabel() const;
	void ComputeLabelConnectorVectors(CXTPChart3dDeviceContext* pDC);
	void ComputeLabels(CXTPChart3dDeviceContext* pDC);
	BOOL ResolveLabelOverlaps(CXTPChart3dDeviceContext* pDC);
	BOOL ResolveLabelOverlaps_ChangeConnectorLength(CXTPChart3dDeviceContext* pDC);

	CXTPChart3dPyramidSeriesLabelDeviceCommand*
		FindLabelDeviceCommand(CXTPChartDeviceCommand* pCommand) const;

private:
	virtual void OnAfterExecute(CXTPChartDeviceCommand* pCommand, CXTPChartDeviceContext* pDC);

	struct CommandCallbackData
	{
		enum State
		{
			None,
			ComputeVector
		};

		CommandCallbackData(State state = None);
		void SwitchTo(State state);
		State GetState() const;

		BOOL bSuccess;
		CXTPChart3dDeviceContext* pDC;
		CXTPChart3dPyramidSeriesLabelDeviceCommand* pLabelCommand;

	private:
		State state;
	};

	CommandCallbackData m_CommandCallbackData;

protected:
	CXTPChart3dPyramidSeriesLabelsView* m_pSeriesLabelsView; // View pointer
};

AFX_INLINE void
	CXTPChart3dPyramidSeriesLabelsViewDeviceCommand::CommandCallbackData::SwitchTo(State newState)
{
	*this = CommandCallbackData(newState);
}

AFX_INLINE CXTPChart3dPyramidSeriesLabelsViewDeviceCommand::CommandCallbackData::State
	CXTPChart3dPyramidSeriesLabelsViewDeviceCommand::CommandCallbackData::GetState() const
{
	return state;
}

AFX_INLINE CXTPChart3dPyramidSeriesLabelsViewDeviceCommand::CommandCallbackData::CommandCallbackData(
	State state)
	: bSuccess(FALSE)
	, pDC(NULL)
	, pLabelCommand(NULL)
	, state(state)
{
}

#	include "Common/Base/Diagnostic/XTPEnableNoisyWarnings.h"
#endif //#if !defined(__XTPCHART3DPYRAMIDSERIESLABELSVIEWDEVICECOMMAND_H__)
