// XTPChartSeriesPoint.h
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
#if !defined(__XTPCHARTSERIESPOINT_H__)
#	define __XTPCHARTSERIESPOINT_H__
//}}AFX_CODEJOCK_PRIVATE

#	if _MSC_VER >= 1000
#		pragma once
#	endif // _MSC_VER >= 1000

#	include "Common/Base/Diagnostic/XTPDisableNoisyWarnings.h"

class CXTPChartSeries;
class CXTPChartSeriesView;
class CXTPChartSeriesPointCollection;

//===========================================================================
// Summary:
//     CXTPChartSeriesPoint is a kind of CXTPChartElement, this class
//     represents the a chart series point.
// Remarks:
//===========================================================================
class _XTP_EXT_CLASS CXTPChartSeriesPoint : public CXTPChartElement
{
	DECLARE_DYNAMIC(CXTPChartSeriesPoint);

public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Default constructor, makes a CXTPChartSeriesPoint object.
	// Remarks:
	//-----------------------------------------------------------------------
	CXTPChartSeriesPoint();

	//-----------------------------------------------------------------------
	// Summary:
	//     Overloaded constructor makes a CXTPChartSeriesPoint object.
	// Parameters:
	//     strArgument - CXTPChartString denoting the argument.
	//     dValue -A double value for the point.
	// Remarks:
	//-----------------------------------------------------------------------
	CXTPChartSeriesPoint(const CXTPChartString& strArgument, double dValue);

	//-----------------------------------------------------------------------
	// Summary:
	//     Constructor makes a CXTPChartSeriesPoint object from the parameters.
	// Parameters:
	//     dArgument - A double value denoting the argument.
	//     dValue - A double value for the point.
	// Remarks:
	//-----------------------------------------------------------------------
	CXTPChartSeriesPoint(double dArgument, double dValue);

	//-----------------------------------------------------------------------
	// Summary:
	//     Constructor overload which makes a CXTPChartSeriesPoint object from
	//     an argument and pair of values.
	// Parameters:
	//     dArgument - Double value denoting the argument.
	//     dValue1 - First value for the point.
	//     dValue2 - Second value for the point.
	// Remarks:
	//-----------------------------------------------------------------------
	CXTPChartSeriesPoint(double dArgument, double dValue1, double dValue2);

	//-----------------------------------------------------------------------
	// Summary:
	//     Constructor overload which makes a CXTPChartSeriesPoint object from
	//     an argument and pair of values.
	// Parameters:
	//     strArgumentt - CXTPChartString denoting the argument.
	//     dValue1 - First value for the point.
	//     dValue2 - Second value for the point.
	// Remarks:
	//-----------------------------------------------------------------------
	CXTPChartSeriesPoint(const CXTPChartString& strArgument, double dValue1, double dValue2);

	//-----------------------------------------------------------------------
	// Summary:
	//     Constructor overload which makes a CXTPChartSeriesPoint object from
	//     an argument and four values.
	// Parameters:
	//     strArgument - String value denoting the argument.
	//     dValue1 - Double value for the point.
	//     dValue2 - Second value for the point.
	//     dValue3 - Third value for the point.
	//     dValue4 - Fourth value for the point.
	// Remarks:
	//-----------------------------------------------------------------------
	CXTPChartSeriesPoint(const CXTPChartString& strArgument, double dValue1, double dValue2,
						 double dValue3, double dValue4);
	CXTPChartSeriesPoint(double dArgument, double dValue1, double dValue2, double dValue3,
						 double dValue4);

	//-------------------------------------------------------------------------
	// Summary:
	//     Destroys a CXTPChartSeriesPoint object, handles cleanup
	//-------------------------------------------------------------------------
	virtual ~CXTPChartSeriesPoint();

public:
	//-------------------------------------------------------------------------
	// Summary:
	//     This function returns the value at a particular index.
	// Parameters:
	//     nIndex - Zero based index in which points are kept internally.
	// Returns:
	//     A double value at the, nIndex position.
	// Remarks:
	// See Also:
	//-------------------------------------------------------------------------
	double GetValue(int nIndex) const;
	void SetValue(int nIndex, double dValue);

	CXTPChartColor GetColor() const;
	void SetColor(const CXTPChartColor& clr);

	//-------------------------------------------------------------------------
	// Summary:
	//     This function returns the string argument of a point.
	// Returns:
	//     A CXTPChartString value argument of the point.
	// Remarks:
	// See Also:
	//-------------------------------------------------------------------------
	CXTPChartString GetArgument() const;

	//-------------------------------------------------------------------------
	// Summary:
	//     This function returns the double value of the argument of a point.
	// Returns:
	//     A double value argument of the point.
	// Remarks:
	// See Also:
	//-------------------------------------------------------------------------
	double GetArgumentValue() const;

	void SetArgumentValue(double dArgument);

	//-------------------------------------------------------------------------
	// Summary:
	//     This function returns the double value of the string argument of a point.
	// Returns:
	//     A double value corresponding to the string argument of the point.
	// Remarks:
	// See Also:
	//-------------------------------------------------------------------------
	double GetInternalArgumentValue() const;

	void SetInternalArgumentValue(double dInternalArgument);

	//-------------------------------------------------------------------------
	// Summary:
	//     This function returns the palette index used.
	// Returns:
	//     An int value corresponding to the chosen palette index.
	// Remarks:
	// See Also:
	//-------------------------------------------------------------------------
	int GetPaletteIndex() const;

	//-------------------------------------------------------------------------
	// Summary:
	//     This function returns the previous point in the series.
	// Returns:
	//     A CXTPChartSeriesPoint pointer corresponding to the previous point  .
	// Remarks:
	// See Also:
	//-------------------------------------------------------------------------
	CXTPChartSeriesPoint* GetPreviousPoint() const;

	//-------------------------------------------------------------------------
	// Summary:
	//     This function returns the next point in the series.
	// Returns:
	//     A CXTPChartSeriesPoint pointer corresponding to the next point.
	// Remarks:
	// See Also:
	//-------------------------------------------------------------------------
	CXTPChartSeriesPoint* GetNextPoint() const;

	void SetLegentText(LPCTSTR lpszLegendText);

	CXTPChartString GetLegendText() const;

	int GetValueLength() const;

	void SetValueLength(int nLength);

	CXTPChartSeries* GetSeries() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this member to set the tooltip of the action.
	// Parameters:
	//     lpszTooltip - Tooltip to be set.
	// See Also: SetCaption, SetDescription, SetPrompt
	//-----------------------------------------------------------------------
	void SetTooltipText(LPCTSTR lpszTooltip);

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this member to get the action's tooltip.
	// Returns:
	//     Tooltip of the control.
	//-----------------------------------------------------------------------
	CXTPChartString GetTooltipText() const;

	void SetLabelText(LPCTSTR lpszLegendText);
	CXTPChartString GetLabelText() const;

public:
	virtual void DoPropExchange(CXTPPropExchange* pPX);

protected:
	//-------------------------------------------------------------------------
	// Summary:
	//     This function handles so internal, argument type conversions.
	// Remarks:
	// See Also:
	//-------------------------------------------------------------------------
	void CommonConstruct();

protected:
	CXTPChartString m_strArgument; // String argument.
	double m_dArgument;			   // Double value of argument.
	double m_dValues[4];		   // The array of values.
	int m_nLength;				   // The size of the array, m_dValues.
	double m_dInternalArgument;	// The double value of the string argument.
	int m_nPaletteIndex;		   // The chosen palette index.
	int m_nIndex;				   // Number of elements present in the array m_dValues.

	CXTPChartString m_strLegentText; // Text to show in legend

	CXTPChartString m_strTooltipText;

	CXTPChartString m_strLabelText;

	CXTPChartColor m_clrPoint;

public:
	BOOL m_bSpecial;

#	ifdef _XTP_ACTIVEX
public:
	//{{AFX_CODEJOCK_PRIVATE
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
	DECLARE_OLETYPELIB_EX(CXTPChartSeriesPoint);

	afx_msg LPDISPATCH OleGetPreviousPoint();
	afx_msg LPDISPATCH OleGetNextPoint();
	afx_msg void OleSetArgumentValue(double dNewValue);
	afx_msg void OleSetArgumentString(LPCTSTR lpszText);
	afx_msg BSTR OleGetArgumentString();
	afx_msg void OleSetSpecial(BOOL bSpecial);
	afx_msg BOOL OleGetSpecial();
	afx_msg BSTR OleGetLegendText();
	afx_msg void OleSetLegendText(LPCTSTR lpszText);
	afx_msg BSTR OleGetLabelText();
	afx_msg void OleSetLabelText(LPCTSTR lpszText);
	afx_msg OLE_COLOR OleGetColor();
	afx_msg void OleSetColor(OLE_COLOR clr);
//}}AFX_CODEJOCK_PRIVATE
#	endif

protected:
	friend class CXTPChartSeriesPointCollection;
	friend class CXTPChartContent;
	friend class CXTPChartSeriesVirtualPointCollection;
	friend class CXTPChartSeriesTrendlinePointCollection;
};

//===========================================================================
// Summary:
//     CXTPChartSeriesPointCollection class represents a collection of chart
//      series points.
// Remarks:
//
//===========================================================================
class _XTP_EXT_CLASS CXTPChartSeriesPointCollection : public CXTPChartElementCollection
{
	DECLARE_DYNAMIC(CXTPChartSeriesPointCollection)
public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Constructs CXTPChartSeriesPointCollection object.
	// Remarks:
	//-----------------------------------------------------------------------
	CXTPChartSeriesPointCollection();

	//-------------------------------------------------------------------------
	// Summary:
	//     Destroys a CXTPChartSeriesPointCollection object, handles cleanup
	//-------------------------------------------------------------------------
	virtual ~CXTPChartSeriesPointCollection();

public:
	//-------------------------------------------------------------------------
	// Summary:
	//     This function add a point represented by the class CXTPChartSeriesPoint
	//     to the internal array of points.
	// Parameters:
	//     pPoint - The pointer to a CXTPChartSeriesPoint object.
	// Returns:
	//     The pointer to CXTPChartSeriesPoint object, which is added to the object array.
	// Remarks:
	// See Also:
	//-------------------------------------------------------------------------
	CXTPChartSeriesPoint* Add(CXTPChartSeriesPoint* pPoint);

	//-------------------------------------------------------------------------
	// Summary:
	//     Call this function to get the pointer to the CXTPChartSeriesPoint object
	//     at a particular index.
	// Parameters:
	//     nIndex - The zero based index.
	// Returns:
	//     The pointer to CXTPChartSeriesPoint object, which stays at the index nIndex.
	// Remarks:
	// See Also:
	//-------------------------------------------------------------------------
	virtual CXTPChartSeriesPoint* GetAt(int nIndex) const;

	//-------------------------------------------------------------------------
	// Summary:
	//     Call this method to add batch of points.
	// Parameters:
	//     nCount - Number of points to add
	// Remarks:
	//     Its optimized way to add big number of points - Memory will be allocated once for all of
	//     them.
	// See Also:
	//-------------------------------------------------------------------------
	void AddPoints(int nCount);

	//-------------------------------------------------------------------------
	// Summary:
	//     Call this method to get the arithmetic mean of the point collection.
	// Parameters:
	//     nValue - Index of the value
	// Returns:
	//     The arithmetic mean of the series collection.
	//-------------------------------------------------------------------------
	virtual double GetArithmeticMean(int nValue) const;

	//-------------------------------------------------------------------------
	// Summary:
	//     Call this method to get the variance of the point collection.
	// Parameters:
	//     nValue - Index of the value
	// Returns:
	//     The variance of the series collection.
	//-------------------------------------------------------------------------
	virtual double GetVariance(int nValue) const;

	//-------------------------------------------------------------------------
	// Summary:
	//     Call this method to get the standard deviation of the point collection.
	// Parameters:
	//     nValue - Index of the value
	// Returns:
	//     The standard deviation of the series collection.
	//-------------------------------------------------------------------------
	virtual double GetStandardDeviation(int nValue) const;

	//-------------------------------------------------------------------------
	// Summary:
	//     Call this method to get the moving average of the point collection.
	// Parameters:
	//     nValue - Index of the value
	//     nFrom  - Index of the point
	//     nTo    - Index of the point
	// Returns:
	//     The moving average of the series collection.
	//-------------------------------------------------------------------------
	virtual double GetMovingAverage(int nValue, int nFrom, int nTo) const;

	//-------------------------------------------------------------------------
	// Summary:
	//     Call this method to get the minimum of the point collection.
	//-------------------------------------------------------------------------
	virtual double GetMinimum(int nValue) const;

	//-------------------------------------------------------------------------
	// Summary:
	//     Call this method to get the maximum of the point collection.
	//-------------------------------------------------------------------------
	virtual double GetMaximum(int nValue) const;

	virtual void GetSlopeQualitative(int nValue, double& dSlope, double& dIntercept) const;
	virtual void GetSlopeNumerical(int nValue, double& dSlope, double& dIntercept) const;

public:
	virtual void DoPropExchange(CXTPPropExchange* pPX);

protected:
#	ifdef _XTP_ACTIVEX
public:
	//{{AFX_CODEJOCK_PRIVATE
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()

	DECLARE_OLETYPELIB_EX(CXTPChartSeriesPointCollection);

	afx_msg long OleGetItemCount();
	afx_msg LPDISPATCH OleGetItem(long nIndex);
	DECLARE_ENUM_VARIANT(CXTPChartSeriesPointCollection)
	afx_msg LPDISPATCH OleAdd(const VARIANT& varArgument, const VARIANT& varValue);
	afx_msg LPDISPATCH OleAdd4(const VARIANT& varArgument, double varValue1, double varValue2,
							   double varValue3, double varValue4);
	afx_msg LPDISPATCH OleAdd2(const VARIANT& varArgument, double varValue1, double varValue2);

//}}AFX_CODEJOCK_PRIVATE
#	endif
	friend class CXTPChartSeries;
};

//////////////////////////////////////////////////////////////////////////
// CXTPChartSeriesVirtualPointCollection

class _XTP_EXT_CLASS CXTPChartSeriesVirtualPointCollection : public CXTPChartSeriesPointCollection
{
	DECLARE_DYNAMIC(CXTPChartSeriesVirtualPointCollection);
	typedef double(CALLBACK* GETPOINTVALUEPTR)(CXTPChartSeries* pSeries, double x);

public:
	CXTPChartSeriesVirtualPointCollection(double dMinRange, double dMaxRange, double dStep,
										  GETPOINTVALUEPTR pCallbackPtr);
	virtual ~CXTPChartSeriesVirtualPointCollection();

public:
	virtual CXTPChartSeriesPoint* GetAt(int nIndex) const;

	virtual int GetCount() const;

protected:
	double m_dMinRange;
	double m_dMaxRange;
	double m_dStep;
	int m_nCount;
	CXTPChartSeriesPoint* m_pVirtualPoint;
	GETPOINTVALUEPTR m_pCallbackPtr;
};

AFX_INLINE CXTPChartSeriesPoint* CXTPChartSeriesPointCollection::GetAt(int nIndex) const
{
	return nIndex >= 0 && nIndex < m_arrElements.GetSize()
			   ? (CXTPChartSeriesPoint*)m_arrElements.GetAt(nIndex)
			   : NULL;
}

AFX_INLINE CXTPChartString CXTPChartSeriesPoint::GetArgument() const
{
	return m_strArgument;
}

AFX_INLINE double CXTPChartSeriesPoint::GetArgumentValue() const
{
	return m_dArgument;
}

AFX_INLINE double CXTPChartSeriesPoint::GetInternalArgumentValue() const
{
	return m_dInternalArgument;
}

AFX_INLINE void CXTPChartSeriesPoint::SetInternalArgumentValue(double dInternalArgument)
{
	m_dInternalArgument = dInternalArgument;
}

AFX_INLINE int CXTPChartSeriesPoint::GetPaletteIndex() const
{
	return m_nPaletteIndex;
}
AFX_INLINE void CXTPChartSeriesPoint::SetLegentText(LPCTSTR lpszLegendText)
{
	m_strLegentText = lpszLegendText;
	OnChartChanged();
}
AFX_INLINE CXTPChartString CXTPChartSeriesPoint::GetLegendText() const
{
	return m_strLegentText;
}

AFX_INLINE int CXTPChartSeriesPoint::GetValueLength() const
{
	return m_nLength;
}

AFX_INLINE void CXTPChartSeriesPoint::SetValueLength(int nLength)
{
	m_nLength = nLength;
}

AFX_INLINE CXTPChartColor CXTPChartSeriesPoint::GetColor() const
{
	return m_clrPoint;
}
AFX_INLINE void CXTPChartSeriesPoint::SetColor(const CXTPChartColor& clr)
{
	m_clrPoint = clr;
	OnChartChanged();
}
AFX_INLINE CXTPChartString CXTPChartSeriesPoint::GetTooltipText() const
{
	return m_strTooltipText;
}
AFX_INLINE void CXTPChartSeriesPoint::SetTooltipText(LPCTSTR lpszTooltip)
{
	m_strTooltipText = lpszTooltip;
}
AFX_INLINE CXTPChartString CXTPChartSeriesPoint::GetLabelText() const
{
	return m_strLabelText;
}
AFX_INLINE void CXTPChartSeriesPoint::SetLabelText(LPCTSTR lpszLabelText)
{
	m_strLabelText = lpszLabelText;
	OnChartChanged();
}
AFX_INLINE void CXTPChartSeriesPoint::SetArgumentValue(double dArgument)
{
	m_dArgument = dArgument;
	OnChartChanged();
}

#	include "Common/Base/Diagnostic/XTPEnableNoisyWarnings.h"
#endif //#if !defined(__XTPCHARTSERIESPOINT_H__)
