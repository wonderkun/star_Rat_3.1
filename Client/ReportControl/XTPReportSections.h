// XTPReportSections.h: interface for the CXTPReportSections class.
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
#if !defined(__XTPREPORTSECTIONS_H__)
#	define __XTPREPORTSECTIONS_H__
//}}AFX_CODEJOCK_PRIVATE

#	if _MSC_VER > 1000
#		pragma once
#	endif // _MSC_VER > 1000

#	include "Common/Base/Diagnostic/XTPDisableNoisyWarnings.h"

class CXTPReportControl;
class CXTPReportSection;
class CXTPMarkupContext;

enum XTPReportSection
{
	xtpReportSectionHeader = 0, // Index of header section
	xtpReportSectionBody   = 1, // Index of body section
	xtpReportSectionFooter = 2, // Index of footer section
	xtpReportSectionCount  = 3  // Number of default sections
};

//-----------------------------------------------------------------------
// Summary:
//     Collection of sections.
//-----------------------------------------------------------------------
class _XTP_EXT_CLASS CXTPReportSections : public CXTPCmdTarget
{
public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Constructs the collection and default sections.
	//-----------------------------------------------------------------------
	CXTPReportSections(CXTPReportControl* pControl);

	//-----------------------------------------------------------------------
	// Summary:
	//     Destructs the collection and sections.
	//-----------------------------------------------------------------------
	~CXTPReportSections();

public:
	int Add(CXTPReportSection* pSection)
	{
		return (int)m_arrSections.Add(pSection);
	}

	CXTPReportSection* GetAt(int nIndex) const
	{
		CXTPReportSection* pSection = NULL;

		if (GetSize() > nIndex) // Valid index
		{
			pSection = m_arrSections.GetAt(nIndex);
		}

		return pSection;
	}

	int GetSize() const
	{
		return int(m_arrSections.GetSize());
	}

	void RemoveAll()
	{
		m_arrSections.RemoveAll();
	}

public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Ensures that a report control row is at least partially visible.
	// Parameters:
	//     pRow - A pointer to the row that is to be visible.
	// Remarks:
	//     Ensures that a report row item is at least partially visible.
	//     The list view control is scrolled if necessary.
	// See Also: MoveDown, MoveUp, MovePageDown, MovePageUp, MoveFirst, MoveLast
	//-----------------------------------------------------------------------
	virtual BOOL EnsureVisible(CDC* pDC, CXTPReportRow* pRow);

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves a pointer to the row that currently has focus
	// Returns:
	//     Returns pointer to the focused row, or NULL otherwise.
	//-----------------------------------------------------------------------
	CXTPReportRow* GetFocusedRow() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Returns the current rectangle for the sections.
	// Returns:
	//     Current rectangle for the sections.
	//-----------------------------------------------------------------------
	CRect GetRect() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Determines which section, if any, is at a specified position.
	// Parameters:
	//     pt - A point to test.
	// Returns:
	//     The section at the position specified by pt, otherwise NULL
	//-----------------------------------------------------------------------
	CXTPReportSection* HitTest(CPoint pt) const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Draws the sections to the device context.
	//-----------------------------------------------------------------------
	virtual void Draw(CDC* pDC);

	//-----------------------------------------------------------------------
	// Summary:
	//     Adjusts section areas depending on current control size.
	//-----------------------------------------------------------------------
	virtual void AdjustLayout(CDC* pDC, CRect rcSections);

	//-----------------------------------------------------------------------
	// Summary:
	//      Sets the markup context.
	//-----------------------------------------------------------------------
	void SetMarkupContext(CXTPMarkupContext* pMarkupContext);

	//-----------------------------------------------------------------------
	// Summary:
	//      Re-sorts the rows of all sections.
	//-----------------------------------------------------------------------
	virtual void ReSortRows();

	//-----------------------------------------------------------------------
	// Summary:
	//     Recalculates indexes of all rows.
	// Parameters:
	//     bAdjustLayout - If TRUE, layout is adjusted.
	//     bReverseOrder - If TRUE, row indices are updated in reverse order,
	//                     starting from the last row.
	//-----------------------------------------------------------------------
	virtual void RefreshIndexes(BOOL bAdjustLayout);

	virtual void ResetContent();

protected:
	CXTPReportSection* FindSection(CXTPReportRow* pRow) const;

protected:
	CArray<CXTPReportSection*, CXTPReportSection*> m_arrSections;

	CRect m_rcSections;			   // Sections rectangle
	CXTPReportControl* m_pControl; // Parent control.

private:
#	ifdef _XTP_ACTIVEX
	DECLARE_OLETYPELIB_EX(CXTPReportSections);
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()

	int OleGetCount() const
	{
		return GetSize();
	}

	LPDISPATCH OleGetSection(int nIndex) const;
#	endif // _XTP_ACTIVEX
};

#	include "Common/Base/Diagnostic/XTPEnableNoisyWarnings.h"
#endif //#if !defined(__XTPREPORTSECTIONS_H__)
