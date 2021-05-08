// XTPTrackThemeOffice2003Luna.h: interface for the CXTPTrackPaintManager class.
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
#if !defined(__XTPTRACKTHEMEOffice2003Luna_H__)
#	define __XTPTRACKTHEMEOffice2003Luna_H__
//}}AFX_CODEJOCK_PRIVATE

#	if _MSC_VER > 1000
#		pragma once
#	endif // _MSC_VER > 1000

#	include "Common/Base/Diagnostic/XTPDisableNoisyWarnings.h"

//===========================================================================
// Summary:
//     CXTPTrackThemeOffice2003Luna is a CXTPTrackPaintManager derived
//     class.  This represents an Office 2003 style theme.
//===========================================================================
class _XTP_EXT_CLASS CXTPTrackThemeOffice2003Luna : public CXTPTrackPaintManager
{
public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Default paint manager constructor, handles properties initialization.
	//-----------------------------------------------------------------------
	CXTPTrackThemeOffice2003Luna();

	//-------------------------------------------------------------------------
	// Summary:
	//     This method is called to refresh the visual metrics of the
	//     report control.
	//-------------------------------------------------------------------------
	virtual void RefreshMetrics();

	//-----------------------------------------------------------------------
	// Summary:
	//     Fills column footer control area by its background.
	// Parameters:
	//     pDC      -  Pointer to the used Device Context.
	//     rcFooter -  Footer area rectangle coordinates.
	//-----------------------------------------------------------------------
	virtual void FillFooter(CDC* pDC, CRect rcFooter);

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this method to determine if hot tracking is enabled for current column style.
	// Returns:
	//     TRUE if enabled; FALSE otherwise
	// Remarks:
	//     Hot Tracking can be used only for xtpReportColumnOffice2003 and xtpReportColumnExplorer
	//     styles.
	// See Also:
	//     m_columnStyle, m_bHotTracking
	//-----------------------------------------------------------------------
	virtual BOOL IsColumHotTrackingEnabled() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called to draw background of the column using current column style
	// Parameters:
	//     pDC - Point to used Device Context
	//     pColumn - Column needs to draw
	//     rcColumn - Bounding rectangle of the column
	//     bColumnPressed - TRUE if column is pressed by user.
	//     bDraggingFromHeader - TRUE if column is begin dragged from header area.
	//     pHeader - Pointer to a header the column belongs to.
	//-----------------------------------------------------------------------
	virtual void DrawColumnBackground(CDC* pDC, CXTPReportColumn* pColumn, CRect rcColumn,
									  BOOL& bColumnPressed, BOOL& bDraggingFromHeader,
									  CXTPReportHeader* pHeader = NULL);

	//-----------------------------------------------------------------------
	// Summary:
	//     Draws column footer divider.
	// Parameters:
	//     pDC           - Pointer to the used Device Context.
	//     pColumn       - Column header area rectangle coordinates.
	//     rcColumn      - Column area rectangle coordinates.
	//-----------------------------------------------------------------------
	virtual void DrawColumnFooterDivider(CDC* pDC, CXTPReportColumn* pColumn, CRect rcColumn);

	//-----------------------------------------------------------------------
	// Summary:
	//     Draws the divider between report sections (e.g. dividing header record rows and body
	//     rows).
	// Parameters:
	//     pDC   - Pointer to the used Device Context.
	//     rc - Rectangle coordinates.
	//     dividerPosition - position of section divider.
	//     dividerStyle - style of section divider.
	//     dividerColor - color of section divider.
	//-----------------------------------------------------------------------
	void DrawSectionDivider(CDC* pDC, const CRect& rc,
							XTPReportSectionDividerPosition dividerPosition,
							XTPReportSectionDividerStyle dividerStyle,
							CXTPPaintManagerColor dividerColor);
};

#	include "Common/Base/Diagnostic/XTPEnableNoisyWarnings.h"
#endif //#if !defined(__XTPTRACKTHEMEOffice2003Luna_H__)
