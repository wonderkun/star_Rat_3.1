// XTPReportGroupRow.h: interface for the CXTPReportGroupItem class.
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
#if !defined(__XTPREPORTGROUPROW_H__)
#	define __XTPREPORTGROUPROW_H__
//}}AFX_CODEJOCK_PRIVATE

#	if _MSC_VER > 1000
#		pragma once
#	endif // _MSC_VER > 1000

#	include "Common/Base/Diagnostic/XTPDisableNoisyWarnings.h"

class CXTPMarkupContext;
class CXTPMarkupUIElement;

//===========================================================================
// Summary:
//     This class represents a 'group row' of the report control view -
//     that means a row which has no associated Record item, but
//     has a special text caption instead.
// Remarks:
//     CXTPReportGroupRow has a slightly different reaction on mouse events and another
//     draw logic.
//
//     All other behavior of the group row is similar to its parent.
//
// See Also: CXTPReportRow overview, CXTPReportControl overview
//===========================================================================
class _XTP_EXT_CLASS CXTPReportGroupRow : public CXTPReportRow
{
	DECLARE_DYNAMIC(CXTPReportGroupRow);

public:
	//-----------------------------------------------------------------------
	// Summary:
	//     A constructor of the CXTPReportGroupRow object.
	//-----------------------------------------------------------------------
	CXTPReportGroupRow();

	//-----------------------------------------------------------------------
	// Summary:
	//     A default object destructor.
	//-----------------------------------------------------------------------
	virtual ~CXTPReportGroupRow();

	//-----------------------------------------------------------------------
	// Summary:
	//     Returns the group text caption.
	// Remarks:
	//     Call this member function to retrieve a text caption of this
	//     group row item.
	// Returns:
	//     Group text caption.
	// See Also: CXTPReportGroupRow::CXTPReportGroupRow
	//-----------------------------------------------------------------------
	virtual CString GetCaption() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Returns an optional native group caption value.
	// Remarks:
	//     Call this member function to retrieve an optional native group
	//     caption value of this group row item.
	// Returns:
	//     Group text caption.
	// See Also: CXTPReportGroupRow::CXTPReportGroupRow
	//-----------------------------------------------------------------------
	virtual COleVariant GetCaptionValue() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Returns tool tip text displayed for this group row.
	// Remarks:
	//     Call this member function to retrieve the tool tip text displayed the
	//     this group row.
	// Returns:
	//     Tool tip Text for this row.
	//-----------------------------------------------------------------------
	virtual CString GetTooltip() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this member to specify the text that is displayed as the group
	//     caption when the column that the ReportRecordItem is in has been grouped.
	// Parameters:
	//     lpszCaption - Caption to be set
	//     vtValue - Optional group caption value.
	// Remarks:
	//     When a column that the ReportRecordItem belong to has been grouped,
	//     the caption of the column is displayed as
	//     the group caption.  If you specify a caption with CXTPReportGroupRow::SetCaption
	//     for the ReportRecordItem, the m_strGroupText text
	//     will be displayed instead of the caption of the column.
	//     You can use CXTPReportGroupRow::SetCaption to "sub group" your ReportRecordItems when
	//     the column they belong to has been grouped.  The ReportRecordItems
	//     will be "sub grouped" by the value in m_strGroupText when the
	//     column they belong to is grouped.
	//-----------------------------------------------------------------------
	void SetCaption(LPCTSTR lpszCaption);
	void SetCaption(LPCTSTR lpszCaption,
					COleVariant vtValue); // <combine CXTPReportGroupRow::SetCaption@LPCTSTR>

	//-----------------------------------------------------------------------
	// Summary:
	//     Gets group row Formula
	// Returns:
	//     String object, containing current Formula
	//-----------------------------------------------------------------------
	virtual CString GetFormula() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Sets group row Formula.
	// Parameters:
	//     sFormula - New Formula.
	virtual void SetFormula(LPCTSTR sFormula);

	//-----------------------------------------------------------------------
	// Summary:
	//     Gets group row caption format string.
	// Returns:
	//     String object, containing current format string
	//-----------------------------------------------------------------------
	virtual CString GetFormatString() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Sets group row caption format string.
	// Parameters:
	//     strFormat - New format string.
	//-----------------------------------------------------------------------
	virtual void SetFormatString(LPCTSTR strFormat);

	//-----------------------------------------------------------------------
	// Summary:
	//     Draws the row using the specified device context.
	// Parameters:
	//     pDC     - A pointer to the device context in which the drawing occurs.
	//     rcRow   - Position of the row in client window coordinates.
	//     rcClip  - Position of the row in client window coordinates.
	//     nLeftOffset - Start drawing left offset in pixels (Horizontal scroll position).
	// See Also: CXTPReportRow::Draw
	//-----------------------------------------------------------------------
	virtual void Draw(CDC* pDC, CRect rcRow, CRect rcClip, int nLeftOffset,
					  CXTPReportRecordMergeItems& mergeItems, int nColumnFrom, int nColumnTo);

	//-----------------------------------------------------------------------
	// Summary:
	//     Process mouse single clicks.
	// Parameters:
	//     ptClicked - Point coordinates where the message was fired from.
	// See Also: CXTPReportRow::OnClick
	//-----------------------------------------------------------------------
	void OnClick(CPoint ptClicked);

	//-----------------------------------------------------------------------
	// Summary:
	//     Process mouse double clicks.
	// Parameters:
	//     ptClicked - Point coordinates where the message was fired from.
	// Remarks:
	//     Group row adds a collapse/expand functionality if double-
	//     clicked on a row.
	// See Also: CXTPReportRow::OnDblClick
	//-----------------------------------------------------------------------
	void OnDblClick(CPoint ptClicked);

	//-----------------------------------------------------------------------
	// Summary:
	//     Determines if this is a group row or not.
	// Returns:
	//     TRUE because this is a group row.
	// See Also: CXTPReportRow::IsGroupRow
	//-----------------------------------------------------------------------
	BOOL IsGroupRow() const;

	//{{AFX_CODEJOCK_PRIVATE
	BOOL CalculateByChilds(CXTPReportRow* pPassedRow, int col_start, int col_end,
						   double& dPassedValue);
	//}}AFX_CODEJOCK_PRIVATE
	CXTPMarkupUIElement* m_pMarkupUIElement; // Store Markup Object

	//-----------------------------------------------------------------------
	// Summary:
	//      Call this method to reset Markup element
	// See Also:
	//      CXTPReportControl::EnableMarkup
	//-----------------------------------------------------------------------
	virtual void ResetMarkupUIElement();

	//-----------------------------------------------------------------------
	// Summary:
	//     Sets a pointer to the parent report control.
	// Remarks:
	//     Call this member function to set a pointer to the
	//     CXTPReportControl which this item belongs to.
	// See Also: CXTPReportControl overview
	//-----------------------------------------------------------------------
	virtual void SetControl(CXTPReportControl* pControl);

	//-----------------------------------------------------------------------
	// Summary:
	//     Sets information that defines the format of a currency string.
	// Remarks:
	//     Call this member function to set a pointer to the
	//     LPCURRENCYFMT.
	//-----------------------------------------------------------------------
	void SetCurrencyFormat(LPCURRENCYFMT fmt);

protected:
	//-----------------------------------------------------------------------
	// Summary:
	//     The framework calls this member function to determine whether a
	//     point is in the bounding rectangle of the specified tool.
	// Parameters:
	//     point - Specifies the x- and y-coordinate of the cursor. These
	//             coordinates are always relative to the upper-left corner of the window
	//     pTI   - A pointer to a TOOLINFO structure.
	// Returns:
	//     If the tooltip control was found, the window control ID. If
	//     the tooltip control was not found, -1.
	//-----------------------------------------------------------------------
	virtual INT_PTR OnToolHitTest(CPoint point, TOOLINFO* pTI);

	//-----------------------------------------------------------------------
	// Summary:
	//     Gets formatted string with m_lpCurrencyFmt.
	// Parameters:
	//     value - value which will be formatted.
	// Returns:
	//     String object, containing string.
	//-----------------------------------------------------------------------
	CString GetCurrencyString(double value);

protected:
	CString m_strGroupText;		   // Group text label
	CString m_strGroupLabel;	   // Group text label - used as formula prefix
	CString m_strFormula;		   // The formula.
	CString m_strFormat;		   // The format string.
	COleVariant m_vtCaptionValue;  // Native caption value.
	LPCURRENCYFMT m_lpCurrencyFmt; // Contains information that defines the format of a currency
								   // string

	friend class CXTPReportPaintManager;

#	ifdef _XTP_ACTIVEX
	//{{AFX_CODEJOCK_PRIVATE
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()

	DECLARE_OLETYPELIB_EX(CXTPReportGroupRow);
	BSTR OleGetCaption();
	void OleSetCaption(LPCTSTR pcszCaption);

	BSTR OleGetFormat();
	void OleSetFormat(LPCTSTR pcszFormat);

	BSTR OleGetFormula();
	void OleSetFormula(LPCTSTR pcszFormula);

//}}AFX_CODEJOCK_PRIVATE
#	endif
};

AFX_INLINE BOOL CXTPReportGroupRow::IsGroupRow() const
{
	return TRUE;
}

AFX_INLINE CString CXTPReportGroupRow::GetTooltip() const
{
	return GetCaption();
}

AFX_INLINE CString CXTPReportGroupRow::GetFormula() const
{
	return m_strFormula;
}

AFX_INLINE void CXTPReportGroupRow::SetFormula(LPCTSTR sFormula)
{
	m_strFormula = sFormula;
}

AFX_INLINE CString CXTPReportGroupRow::GetFormatString() const
{
	return m_strFormat;
}

AFX_INLINE void CXTPReportGroupRow::SetFormatString(LPCTSTR strFormat)
{
	m_strFormat = strFormat;
}

AFX_INLINE void CXTPReportGroupRow::SetControl(CXTPReportControl* pControl)
{
	CXTPReportRow::SetControl(pControl);
	ResetMarkupUIElement();
}

AFX_INLINE void CXTPReportGroupRow::SetCurrencyFormat(LPCURRENCYFMT fmt)
{
	m_lpCurrencyFmt = fmt;
}

#	include "Common/Base/Diagnostic/XTPEnableNoisyWarnings.h"
#endif //#if !defined(__XTPREPORTGROUPROW_H__)
