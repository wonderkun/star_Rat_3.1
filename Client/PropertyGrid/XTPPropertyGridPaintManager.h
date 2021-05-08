// XTPPropertyGridPaintManager.h interface for the CXTPPropertyGridPaintManager class.
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
#if !defined(_XTPPROPERTYGRIDPAINTMANAGER_H__)
#	define _XTPPROPERTYGRIDPAINTMANAGER_H__
//}}AFX_CODEJOCK_PRIVATE

#	if _MSC_VER > 1000
#		pragma once
#	endif // _MSC_VER > 1000

#	include "Common/Base/Diagnostic/XTPDisableNoisyWarnings.h"

class CXTPPropertyGrid;
class CXTPPropertyGridInplaceButton;
class CXTPPropertyGridItem;
class CXTPPropertyGridItemConstraint;
class CXTPPropertyGridItemBool;
class CXTPWinThemeWrapper;

class CXTPButton;
class CXTPComboBox;

class CXTPPropertyGridPaintManager;

//===========================================================================
// Summary:
//     Standalone class used by CXTPPropertyGridPaintManager as holder of item metrics
//===========================================================================
class _XTP_EXT_CLASS CXTPPropertyGridItemMetrics : public CXTPCmdTarget
{
public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPPropertyGridItemMetrics object.
	// Parameters:
	//     pPaintManager - Parent CXTPPropertyGridPaintManager object
	//-----------------------------------------------------------------------
	CXTPPropertyGridItemMetrics(CXTPPropertyGridPaintManager* pPaintManager);

	//-----------------------------------------------------------------------
	// Summary:
	//     Resets all color values to its defaults.
	//-----------------------------------------------------------------------
	virtual void SetDefaultValues();

public:
	CXTPFont m_xtpFontNormal;	// Normal font.
	CXTPFont m_xtpFontBold;		 // Bold font.
	CXTPFont m_xtpFontUnderline; // Underline Font.

	XTP_SUBSTITUTE_GDI_MEMBER_WITH_CACHED(CFont, m_fontNormal, m_xtpFontNormal,
										  GetNormalFontHandle);
	XTP_SUBSTITUTE_GDI_MEMBER_WITH_CACHED(CFont, m_fontBold, m_xtpFontBold, GetBoldFontHandle);
	XTP_SUBSTITUTE_GDI_MEMBER_WITH_CACHED(CFont, m_fontUnderline, m_xtpFontUnderline,
										  GetUnderlineFontHandle);

	int m_nImage; // Image index.

	CXTPPaintManagerColor m_clrHelpBack;	 // Color of the description background.
	CXTPPaintManagerColor m_clrHelpFore;	 // Color of the description text.
	CXTPPaintManagerColor m_clrLine;		 // Line color.
	CXTPPaintManagerColor m_clrFore;		 // Color of the item's text.
	CXTPPaintManagerColor m_clrCategoryFore; // Color of the category text.
	CXTPPaintManagerColor m_clrBack;		 // Background color.
	CXTPPaintManagerColor m_clrReadOnlyFore; // Color of read-only text.
	CXTPPaintManagerColor m_clrVerbFace;	 // Text color of verbs.

	UINT m_uDrawTextFormat; // Text formatting style for the property item.
	int m_nMaxLength; // Maximum number of characters that can be entered into an editable item
					  // (Edit limit).

protected:
	CXTPPropertyGridPaintManager* m_pPaintManager; // Pointer to the paint manager used to draw the
												   // property grid.

#	ifdef _XTP_ACTIVEX
	//{{AFX_CODEJOCK_PRIVATE

public:
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()

	DECLARE_OLETYPELIB_EX(CXTPPropertyGridItemMetrics)

	afx_msg COLORREF OleGetForeColor();
	afx_msg void OleSetForeColor(COLORREF clr);
	afx_msg COLORREF OleGetBackColor();
	afx_msg void OleSetBackColor(COLORREF clr);
	afx_msg void OleSetFont(LPFONTDISP pFontDisp);
	afx_msg LPFONTDISP OleGetFont();

//}}AFX_CODEJOCK_PRIVATE
#	endif
};

//-----------------------------------------------------------------------
// Summary:
//     Window identifiers.
// See Also: CXTPPropertyGridPaintManager::DrawPropertyGridBorder
//-----------------------------------------------------------------------
enum XTPPropertyGridWindow
{
	xtpGridVerbWindow, // Verb window
	xtpGridGridWindow, // Grid window
	xtpGridHelpWindow  // Help window
};

//===========================================================================
// Summary:
//     Standalone class used by CXTPPropertyGrid as the paint manager.
//===========================================================================
class _XTP_EXT_CLASS CXTPPropertyGridPaintManager : public CXTPCmdTarget
{
public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPPropertyGridPaintManager object.
	// Parameters:
	//     pGrid - Points to a CXTPPropertyGrid object
	//-----------------------------------------------------------------------
	CXTPPropertyGridPaintManager(CXTPPropertyGrid* pGrid);

	//-----------------------------------------------------------------------
	// Summary:
	//     Destroys a CXTPPropertyGridPaintManager object, handles cleanup
	//     and deallocation.
	//-----------------------------------------------------------------------
	virtual ~CXTPPropertyGridPaintManager();

public:
	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called to get item text color
	// Parameters:
	//     pItem - Item which text color need to get
	//     bValuePart - TRUE if value part color needed
	// Returns:
	//     COLORREF of item text.
	//-----------------------------------------------------------------------
	virtual COLORREF GetItemTextColor(CXTPPropertyGridItem* pItem, BOOL bValuePart);

	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called to get item back color
	// Parameters:
	//     pItem - Item which back color need to get
	//     bValuePart - TRUE if value part color needed
	// Returns:
	//     COLORREF of item back.
	//-----------------------------------------------------------------------
	virtual COLORREF GetItemBackColor(CXTPPropertyGridItem* pItem, BOOL bValuePart);

	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called to get item font
	// Parameters:
	//     pItem - Item which font color need to get
	//     bValuePart - TRUE if value part font needed
	// Returns:
	//     Pointer to CFont object containing font of the item
	//-----------------------------------------------------------------------
	virtual CFont* GetItemFont(CXTPPropertyGridItem* pItem, BOOL bValuePart);

public:
	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called to draw property grid background.
	// Parameters:
	//     pDC - Pointer to a valid device context
	//-----------------------------------------------------------------------
	virtual void FillPropertyGrid(CDC* pDC);

	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called to draw view background.
	// Parameters:
	//     pDC - Pointer to a valid device context
	//-----------------------------------------------------------------------
	virtual void FillPropertyGridView(CDC* pDC);

	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called to draw grid borders
	// Parameters:
	//      pDC      - Pointer to a valid device context
	//      rcBorder - Size of the border to draw.
	//      nWindow  - Specifies for which window the border is to be drawn,
	//                 1 = Grid, 2 = Help, 3 = Verb.
	// See Also: FillPropertyGridView
	//-----------------------------------------------------------------------
	virtual void DrawPropertyGridBorder(CDC* pDC, RECT& rcBorder, XTPPropertyGridWindow nWindow);

	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called to adjust the bounding rectangle for the grid.
	// Parameters:
	//      rc - Bounding rectangle
	//-----------------------------------------------------------------------
	virtual void OnNcCalcSize(RECT& rc);

	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called to draw single item of the grid.
	// Parameters:
	//     lpDrawItemStruct - A long pointer to a DRAWITEMSTRUCT structure
	//     that contains information about the type of drawing required.
	//-----------------------------------------------------------------------
	virtual void DrawItem(PDRAWITEMSTRUCT lpDrawItemStruct);

	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called to draw specified constraint in in-place list.
	// Parameters:
	//     pDC       - Pointer to a valid device context
	//     rc        - Bounding rectangle of the constraint
	//     bSelected - TRUE if constraint is currently selected.
	//     pConstraint - Constraint to draw.
	//-----------------------------------------------------------------------
	virtual void DrawInplaceListItem(CDC* pDC, CXTPPropertyGridItemConstraint* pConstraint,
									 CRect rc, BOOL bSelected);

	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called to get rectangle of value part of the item.
	// Parameters:
	//     pItem - Property Grid item
	//     rcValue - Rectangle of the value part
	//-----------------------------------------------------------------------
	virtual void AdjustItemValueRect(CXTPPropertyGridItem* pItem, CRect& rcValue);

	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called to get rectangle of caption part of the item.
	// Parameters:
	//     pItem - Property Grid item
	//     rcCaption - Rectangle of the caption part
	//-----------------------------------------------------------------------
	virtual void AdjustItemCaptionRect(CXTPPropertyGridItem* pItem, CRect& rcCaption);

	//-----------------------------------------------------------------------
	// Summary:
	//     Override this method and fill in the MEASUREITEMSTRUCT structure
	//     to inform Windows of the list-box dimensions.
	// Parameters:
	//     lpMeasureItemStruct - Specifies a long pointer to a MEASUREITEMSTRUCT
	//     structure.
	//-----------------------------------------------------------------------
	virtual void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);

	void FillInplaceButtonThemed(CDC* pDC, CXTPPropertyGridInplaceButton* pButton);

	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called to draw in-place button of the grid.
	// Parameters:
	//     pDC - Pointer to a valid device context
	//     pButton - Points to a CXTPPropertyGridInplaceButton object
	//-----------------------------------------------------------------------
	virtual void FillInplaceButton(CDC* pDC, CXTPPropertyGridInplaceButton* pButton);

	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called to refresh the visual metrics of manager.
	//-----------------------------------------------------------------------
	virtual void RefreshMetrics();

	//-----------------------------------------------------------------------
	// Summary:
	//     Returns scroll bar theme identifier.
	//-----------------------------------------------------------------------
	virtual XTPScrollBarTheme GetScrollBarTheme() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this member to determine if a verb is at a specific point.
	// Parameters:
	//     pDC     - Reference to a valid device context
	//     rcVerbs - Bounding rectangle of all verbs.
	//     pt      - Point to test.
	// Returns:
	//     Index of verb within collection if the point was on a verb,
	//     otherwise -1.
	//-----------------------------------------------------------------------
	int HitTestVerbs(CDC* pDC, CRect rcVerbs, CPoint pt);

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves default item metrics
	// Returns:
	//     Call this method to get default item metrics
	//-----------------------------------------------------------------------
	CXTPPropertyGridItemMetrics* GetItemMetrics() const;

	//-----------------------------------------------------------------------
	// Summary: This member function is called by the property-grid to determine
	//          the size of the splitter bar.
	// Input:   rc       - Size of the property grid client area.
	//          bIsHelp  - TRUE if retrieving the height of the help splitter
	//                     bar, otherwise the height of the verbs splitter bar
	//                     is retrieved.
	// Returns: If bIsHelp is TRUE returns the size of the splitter
	//          bar used the help window, otherwise if bIsHelp is FALSE
	//          returns the size of the verbs splitter bar.
	//-----------------------------------------------------------------------
	CRect GetSplitterRect(CRect rc, BOOL bIsHelp);

	//-----------------------------------------------------------------------
	// Summary:  Call this method to get height of horizontal grid line
	//           between PropertyGridItems.
	// Returns:
	//           Height in pixels of the horizontal grid line
	//           between PropertyGridItems.
	//-----------------------------------------------------------------------
	virtual int GetItemsBorderHeight() const;

	//-----------------------------------------------------------------------
	// Summary:  Call this method to set height of horizontal grid line
	//           between PropertyGridItems.
	// Parameters:
	//   nHeight  - Height in pixels of the horizontal grid line
	//           between PropertyGridItems.
	//-----------------------------------------------------------------------
	virtual void SetItemsBorderHeight(int nHeight);

public:
	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called to draw expand buttons of the grid.
	// Parameters:
	//     dc - Reference to a valid device context
	//     pItem - Points to a CXTPPropertyGridItem object
	//     rcCaption - Caption button rectangle.
	//-----------------------------------------------------------------------
	virtual void DrawExpandButton(CDC& dc, CXTPPropertyGridItem* pItem, CRect rcCaption);

	//-----------------------------------------------------------------------
	// Summary:
	//     This member is called to draw the bounding rectangle for a
	//     category caption.
	// Parameters:
	//     pDC - Reference to a valid device context
	//     pItem  - Item to drawn the caption on.
	//     rc  - Bounding rectangle of Category's caption.
	//-----------------------------------------------------------------------
	virtual void DrawCategoryCaptionBackground(CDC* pDC, CXTPPropertyGridItem* pItem, CRect rc);

	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called to draw value part of the property grid item
	// Parameters:
	//     pDC     - Pointer to a valid device context
	//     pItem   - Property Grid item to draw
	//     rcValue - Bounding rectangle of the value part
	//-----------------------------------------------------------------------
	virtual void DrawItemValue(CDC* pDC, CXTPPropertyGridItem* pItem, CRect rcValue);

	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called to draw caption part of the property grid item
	// Parameters:
	//     pDC     - Pointer to a valid device context
	//     pItem   - Property Grid item to draw
	//     rcCaption - Bounding rectangle of the caption part
	//-----------------------------------------------------------------------
	virtual void DrawItemCaption(CDC* pDC, CXTPPropertyGridItem* pItem, CRect rcCaption);

	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called to draw inplace buttons if the item
	// Parameters:
	//     pDC     - Pointer to a valid device context
	//     lpDrawItemStruct - Specifies a long pointer to a DRAWITEMSTRUCT
	//                        data structure that contains information about
	//                        the item to be drawn and the type of drawing required.
	//     pItem   - Property Grid item to draw
	//     rcValue - Value bounding rectangle
	//-----------------------------------------------------------------------
	virtual void DrawInplaceButtons(CDC* pDC, PDRAWITEMSTRUCT lpDrawItemStruct,
									CXTPPropertyGridItem* pItem, CRect rcValue);

	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called to draw checkbox of CXTPPropertyGridItemOption item with CheckBox
	//     style.
	// Parameters:
	//     pDC - Pointer to device context to draw.
	//     pButton - Pointer to Bool item.
	//-----------------------------------------------------------------------
	virtual void DrawCheckBox(CDC* pDC, CXTPPropertyGridItemBool* pButton);

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this member function to draw a check mark.
	// Parameters:
	//     pDC - Pointer to device context to draw.
	//     rc - Specifies the rectangle in logical units.
	//     bEnabled - TRUE if enabled, FALSE if disabled.
	//     bChecked - TRUE if checked, FALSE if not checked.
	//-----------------------------------------------------------------------
	virtual void DrawCheckMark(CDC* pDC, CRect rc, BOOL bEnabled, BOOL bChecked);

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this member function to draw a radio button for a CXTPPropertyGridItemOption item
	//     with RadioButton (default) style.
	// Parameters:
	//     pDC - Pointer to device context to draw.
	//     rc - Specifies the rectangle in logical units.
	//     bEnabled - TRUE if enabled, FALSE if disabled.
	//     bChecked - TRUE if checked, FALSE if not checked.
	//-----------------------------------------------------------------------
	virtual void DrawRadioMark(CDC* pDC, CRect rc, BOOL bEnabled, BOOL bChecked);

	virtual void DrawSplitter(CDC* pDC, BOOL bIsHelp);

	//{{AFX_CODEJOCK_PRIVATE
	void DrawInplaceButtons(CDC* pDC, CXTPPropertyGridItem* pItem, CRect rcValue); // Obsolete
	//}}AFX_CODEJOCK_PRIVATE

#	ifdef _XTP_INCLUDE_CONTROLS
	void DrawCheckMarkThemed(CDC* pDC, CRect rc, BOOL bEnabled, BOOL bChecked);
	void DrawRadioMarkThemed(CDC* pDC, CRect rc, BOOL bEnabled, BOOL bChecked);
	void SetControlsTheme(int eTheme); // XTPControlTheme
#	endif

public:
	XTPPropertyGridInplaceButtonsStyle m_buttonsStyle; // TRUE to use WinXP themes.

	CXTPWinThemeWrapper* m_themeTree;   // Themes for Tree controls.
	CXTPWinThemeWrapper* m_themeButton; // Themes for button controls
	CXTPWinThemeWrapper* m_themeCombo;  // Themes for combo button.
	BOOL m_bTransparent;				// TRUE to draw background with parent color

#	ifdef _XTP_INCLUDE_CONTROLS
	CXTPButton* m_pButton;
	CXTPButton* m_pButtonCheck;
	CXTPComboBox* m_pCombo;
	BOOL m_bUseThemedControls;
#	else
private:
	CXTPExcludedMemberPadding<CXTPButton*> m_pButton;
	CXTPExcludedMemberPadding<CXTPButton*> m_pButtonCheck;
	CXTPExcludedMemberPadding<CXTPComboBox*> m_pCombo;
	CXTPExcludedMemberPadding<BOOL> m_bUseThemedControls;

public:
#	endif

public:
	CXTPPaintManagerColor m_clrFace;			  // Face color.
	CXTPPaintManagerColor m_clrShadow;			  // Shadow color.
	CXTPPaintManagerColor m_clrHighlight;		  // Highlight color.
	CXTPPaintManagerColor m_clrHighlightText;	 // Highlight text color.
	CXTPPaintManagerColor m_clrNonHighlightBack;  // Non highlight background color.
	CXTPPaintManagerColor m_clrNonHighlightText;  // Non highlight text color.
	CXTPPaintManagerColor m_clrCategorySeparator; // Face color.
	CXTPPaintManagerColor m_clrSplitter;		  // Splitter border color.

protected:
	int m_nItemsBorderHeight;  // Height in pixels of the horizontal border between
							   // PropertyGridItems.
	int m_nSplitterHeight;	 // Height in pixels of the splitter bar.
	int m_nHelpHeight;		   // Height of the description area (help panel).
	int m_nVerbsHeight;		   // Height of the verbs panel.
	BOOL m_bThinSplitter;	  // TRUE to draw a single line for splitter.
	CXTPPropertyGrid* m_pGrid; // Parent grid class.

	CXTPPropertyGridItemMetrics* m_pMetrics; // Default metrics of the item

	friend class CXTPPropertyGrid;

#	ifdef _XTP_ACTIVEX
	//{{AFX_CODEJOCK_PRIVATE

	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()

	DECLARE_OLETYPELIB_EX(CXTPPropertyGridPaintManager)
	DECLARE_PROPERTY(HelpBackColor, COLORREF);
	DECLARE_PROPERTY(HelpForeColor, COLORREF);
	DECLARE_PROPERTY(ViewBackColor, COLORREF);
	DECLARE_PROPERTY(ViewForeColor, COLORREF);
	DECLARE_PROPERTY(LineColor, COLORREF);
	DECLARE_PROPERTY(ViewCategoryForeColor, COLORREF);
	DECLARE_PROPERTY(ViewReadOnlyForeColor, COLORREF);

	DECLARE_PROPERTY(BackgroundColor, COLORREF);
	DECLARE_PROPERTY(ShadowColor, COLORREF);
	DECLARE_PROPERTY(HighlightBackColor, COLORREF);
	DECLARE_PROPERTY(HighlightForeColor, COLORREF);
	DECLARE_PROPERTY(HyperlinkColor, COLORREF);

//}}AFX_CODEJOCK_PRIVATE
#	endif
};

//===========================================================================
// Summary:
//     CXTPPropertyGridOffice2003Theme is a CXTPPropertyGridPaintManager derived
//     class.  This represents an Office 2003 style theme.
//===========================================================================
class _XTP_EXT_CLASS CXTPPropertyGridOffice2003Theme : public CXTPPropertyGridPaintManager
{
public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPPropertyGridOffice2003Theme object.
	// Parameters:
	//     pGrid - Points to a CXTPPropertyGrid object
	//-----------------------------------------------------------------------
	CXTPPropertyGridOffice2003Theme(CXTPPropertyGrid* pGrid);

	//-------------------------------------------------------------------------
	// Summary:
	//     This method is called to refresh the visual metrics of the
	//     property grid.
	//-------------------------------------------------------------------------
	virtual void RefreshMetrics();

	//-----------------------------------------------------------------------
	// Summary:
	//     Returns scroll bar theme identifier.
	//-----------------------------------------------------------------------
	virtual XTPScrollBarTheme GetScrollBarTheme() const;

protected:
	BOOL m_bLunaTheme; // TRUE to use luna colors, FALSE otherwise
};

//===========================================================================
// Summary:
//     CXTPPropertyGridOffice2007Theme is a CXTPPropertyGridOffice2003Theme derived
//     class.  This represents an Office 2007 style theme.
//===========================================================================
class _XTP_EXT_CLASS CXTPPropertyGridOffice2007Theme : public CXTPPropertyGridOffice2003Theme
{
public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPPropertyGridOffice2003Theme object.
	// Parameters:
	//     pGrid - Points to a CXTPPropertyGrid object
	//-----------------------------------------------------------------------
	CXTPPropertyGridOffice2007Theme(CXTPPropertyGrid* pGrid);

	//-------------------------------------------------------------------------
	// Summary:
	//     This method is called to refresh the visual metrics of the
	//     property grid.
	//-------------------------------------------------------------------------
	virtual void RefreshMetrics();

protected:
	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called to draw in-place button of the grid.
	// Parameters:
	//     pDC - Pointer to a valid device context
	//     pButton - Points to a CXTPPropertyGridInplaceButton object
	//-----------------------------------------------------------------------
	virtual void FillInplaceButton(CDC* pDC, CXTPPropertyGridInplaceButton* pButton);

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this member function to draw a check mark.
	// Parameters:
	//     pDC - Pointer to device context to draw.
	//     rc - Specifies the rectangle in logical units.
	//     bEnabled - TRUE if enabled, FALSE if disabled.
	//     bChecked - TRUE if checked, FALSE if not checked.
	//-----------------------------------------------------------------------
	virtual void DrawCheckMark(CDC* pDC, CRect rc, BOOL bEnabled, BOOL bChecked);

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this member function to draw a radio button for a CXTPPropertyGridItemOption item
	//     with RadioButton (default) style.
	// Parameters:
	//     pDC - Pointer to device context to draw.
	//     rc - Specifies the rectangle in logical units.
	//     bEnabled - TRUE if enabled, FALSE if disabled.
	//     bChecked - TRUE if checked, FALSE if not checked.
	//-----------------------------------------------------------------------
	virtual void DrawRadioMark(CDC* pDC, CRect rc, BOOL bEnabled, BOOL bChecked);

	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called to draw expand buttons of the grid.
	// Parameters:
	//     dc        - Reference to a valid device context
	//     pItem     - Points to a CXTPPropertyGridItem object
	//     rcCaption - Caption button rectangle.
	//-----------------------------------------------------------------------
	void DrawExpandButton(CDC& dc, CXTPPropertyGridItem* pItem, CRect rcCaption);

	//-----------------------------------------------------------------------
	// Summary:
	//     Returns scroll bar theme identifier.
	//-----------------------------------------------------------------------
	virtual XTPScrollBarTheme GetScrollBarTheme() const;
};

//===========================================================================
// Summary:
//     CXTPPropertyGridNativeXPTheme is a CXTPPropertyGridPaintManager derived
//     class.  This represents a Native Windows XP style theme.
//===========================================================================
class _XTP_EXT_CLASS CXTPPropertyGridNativeXPTheme : public CXTPPropertyGridPaintManager
{
public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPPropertyGridNativeXPTheme object.
	// Parameters:
	//     pGrid - Points to a CXTPPropertyGrid object
	//-----------------------------------------------------------------------
	CXTPPropertyGridNativeXPTheme(CXTPPropertyGrid* pGrid);

	//-------------------------------------------------------------------------
	// Summary:
	//     This method is called to refresh the visual metrics of the
	//     property grid.
	//-------------------------------------------------------------------------
	virtual void RefreshMetrics();

	//-----------------------------------------------------------------------
	// Summary:
	//     Returns scroll bar theme identifier.
	//-----------------------------------------------------------------------
	virtual XTPScrollBarTheme GetScrollBarTheme() const;
};

//===========================================================================
// Summary:
//     CXTPPropertyGridOfficeXPTheme is a CXTPPropertyGridPaintManager derived
//     class.  This represents a Office XP style theme.
//===========================================================================
class _XTP_EXT_CLASS CXTPPropertyGridOfficeXPTheme : public CXTPPropertyGridPaintManager
{
public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPPropertyGridOfficeXPTheme object.
	// Parameters:
	//     pGrid - Points to a CXTPPropertyGrid object
	//-----------------------------------------------------------------------
	CXTPPropertyGridOfficeXPTheme(CXTPPropertyGrid* pGrid);

	//-------------------------------------------------------------------------
	// Summary:
	//     This method is called to refresh the visual metrics of the
	//     property grid.
	//-------------------------------------------------------------------------
	void RefreshMetrics();

	//-----------------------------------------------------------------------
	// Summary:
	//     Returns scroll bar theme identifier.
	//-----------------------------------------------------------------------
	virtual XTPScrollBarTheme GetScrollBarTheme() const;
};

//===========================================================================
// Summary:
//     CXTPPropertyGridCoolTheme is a CXTPPropertyGridPaintManager derived
//     class.  This represents a Cool style theme.
//===========================================================================
class _XTP_EXT_CLASS CXTPPropertyGridCoolTheme : public CXTPPropertyGridPaintManager
{
public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPPropertyGridCoolTheme object.
	// Parameters:
	//     pGrid - Points to a CXTPPropertyGrid object
	//-----------------------------------------------------------------------
	CXTPPropertyGridCoolTheme(CXTPPropertyGrid* pGrid);

	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called to draw single item of the grid.
	// Parameters:
	//     lpDrawItemStruct - A long pointer to a DRAWITEMSTRUCT structure
	//     that contains information about the type of drawing required.
	//-----------------------------------------------------------------------
	virtual void DrawItem(PDRAWITEMSTRUCT lpDrawItemStruct);

	//-------------------------------------------------------------------------
	// Summary:
	//     This method is called to refresh the visual metrics of the
	//     property grid.
	//-------------------------------------------------------------------------
	void RefreshMetrics();

	//-----------------------------------------------------------------------
	// Summary:
	//     Returns scroll bar theme identifier.
	//-----------------------------------------------------------------------
	virtual XTPScrollBarTheme GetScrollBarTheme() const;
};

//===========================================================================
// Summary:
//     CXTPPropertyGridSimpleTheme is a CXTPPropertyGridPaintManager derived
//     class.  This represents a Simple style theme.
//===========================================================================
class _XTP_EXT_CLASS CXTPPropertyGridSimpleTheme : public CXTPPropertyGridPaintManager
{
public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPPropertyGridSimpleTheme object.
	// Parameters:
	//     pGrid - Points to a CXTPPropertyGrid object
	//-----------------------------------------------------------------------
	CXTPPropertyGridSimpleTheme(CXTPPropertyGrid* pGrid);

	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called to draw single item of the grid.
	// Parameters:
	//     lpDrawItemStruct - A long pointer to a DRAWITEMSTRUCT structure
	//     that contains information about the type of drawing required.
	//-----------------------------------------------------------------------
	virtual void DrawItem(PDRAWITEMSTRUCT lpDrawItemStruct);

	//-------------------------------------------------------------------------
	// Summary:
	//     This method is called to refresh the visual metrics of the
	//     property grid.
	//-------------------------------------------------------------------------
	void RefreshMetrics();

	//-----------------------------------------------------------------------
	// Summary:
	//     Returns scroll bar theme identifier.
	//-----------------------------------------------------------------------
	virtual XTPScrollBarTheme GetScrollBarTheme() const;
};

//===========================================================================
// Summary:
//     CXTPPropertyGridDelphiTheme is a CXTPPropertyGridPaintManager derived
//     class.  This represents a Delphi style theme.
//===========================================================================
class _XTP_EXT_CLASS CXTPPropertyGridDelphiTheme : public CXTPPropertyGridPaintManager
{
public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPPropertyGridDelphiTheme object.
	// Parameters:
	//     pGrid - Points to a CXTPPropertyGrid object
	//-----------------------------------------------------------------------
	CXTPPropertyGridDelphiTheme(CXTPPropertyGrid* pGrid);

	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called to draw single item of the grid.
	// Parameters:
	//     lpDrawItemStruct - A long pointer to a DRAWITEMSTRUCT structure
	//     that contains information about the type of drawing required.
	//-----------------------------------------------------------------------
	virtual void DrawItem(PDRAWITEMSTRUCT lpDrawItemStruct);

	//-------------------------------------------------------------------------
	// Summary:
	//     This method is called to refresh the visual metrics of the
	//     property grid.
	//-------------------------------------------------------------------------
	virtual void RefreshMetrics();

	//-----------------------------------------------------------------------
	// Summary:
	//     Returns scroll bar theme identifier.
	//-----------------------------------------------------------------------
	virtual XTPScrollBarTheme GetScrollBarTheme() const;
};

//===========================================================================
// Summary:
//     CXTPPropertyGridVisualStudio2005Theme is a CXTPPropertyGridPaintManager derived
//     class.  This represents a Visual Studio 2005 style theme.
//===========================================================================
class _XTP_EXT_CLASS CXTPPropertyGridVisualStudio2005Theme : public CXTPPropertyGridPaintManager
{
public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPPropertyGridVisualStudio2005Theme object.
	// Parameters:
	//     pGrid - Points to a CXTPPropertyGrid object
	//-----------------------------------------------------------------------
	CXTPPropertyGridVisualStudio2005Theme(CXTPPropertyGrid* pGrid);

protected:
	//-----------------------------------------------------------------------
	// Summary:
	//     This member is called to draw the bounding rectangle for a
	//     category caption.
	// Parameters:
	//     pDC - Reference to a valid device context
	//     pItem  - Item to drawn the caption on.
	//     rc  - Bounding rectangle of Category's caption.
	//-----------------------------------------------------------------------
	void DrawCategoryCaptionBackground(CDC* pDC, CXTPPropertyGridItem* pItem, CRect rc);

	//-------------------------------------------------------------------------
	// Summary:
	//     This method is called to refresh the visual metrics of the
	//     property grid.
	//-------------------------------------------------------------------------
	void RefreshMetrics();

	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called to draw expand buttons of the grid.
	// Parameters:
	//     dc        - Reference to a valid device context
	//     pItem     - Points to a CXTPPropertyGridItem object
	//     rcCaption - Caption button rectangle.
	//-----------------------------------------------------------------------
	void DrawExpandButton(CDC& dc, CXTPPropertyGridItem* pItem, CRect rcCaption);

	//-----------------------------------------------------------------------
	// Summary:
	//     Returns scroll bar theme identifier.
	//-----------------------------------------------------------------------
	virtual XTPScrollBarTheme GetScrollBarTheme() const;
};

//===========================================================================
// Summary:
//     CXTPPropertyGridVisualStudio2010Theme is a CXTPPropertyGridPaintManager derived
//     class.  This represents a Visual Studio 2010 style theme.
//===========================================================================
class _XTP_EXT_CLASS CXTPPropertyGridVisualStudio2010Theme : public CXTPPropertyGridPaintManager
{
public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPPropertyGridVisualStudio2010Theme object.
	// Parameters:
	//     pGrid - Points to a CXTPPropertyGrid object
	//-----------------------------------------------------------------------
	CXTPPropertyGridVisualStudio2010Theme(CXTPPropertyGrid* pGrid);
	~CXTPPropertyGridVisualStudio2010Theme();

public:
	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called to draw expand buttons of the grid.
	// Parameters:
	//     dc - Reference to a valid device context
	//     pItem - Points to a CXTPPropertyGridItem object
	//     rcCaption - Caption button rectangle.
	//-----------------------------------------------------------------------
	virtual void DrawExpandButton(CDC& dc, CXTPPropertyGridItem* pItem, CRect rcCaption);

	//-------------------------------------------------------------------------
	// Summary:
	//     This method is called to refresh the visual metrics of the
	//     property grid.
	//-------------------------------------------------------------------------
	virtual void RefreshMetrics();

	//-----------------------------------------------------------------------
	// Summary:
	//     Returns scroll bar theme identifier.
	//-----------------------------------------------------------------------
	virtual XTPScrollBarTheme GetScrollBarTheme() const;
};

//===========================================================================
// Summary:
//     CXTPPropertyGridVisualStudio2012Theme is a CXTPPropertyGridVisualStudio2010Theme derived
//     class.  This represents a Office XP style theme.
//===========================================================================
class _XTP_EXT_CLASS CXTPPropertyGridVisualStudio2012Theme : public CXTPPropertyGridPaintManager
{
public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPPropertyGridVisualStudio2012Theme object.
	// Parameters:
	//     pGrid - Points to a CXTPPropertyGrid object
	//-----------------------------------------------------------------------
	CXTPPropertyGridVisualStudio2012Theme(CXTPPropertyGrid* pGrid, BOOL bLight);

	//-------------------------------------------------------------------------
	// Summary:
	//     This method is called to refresh the visual metrics of the
	//     property grid.
	//-------------------------------------------------------------------------
	virtual void RefreshMetrics();

	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called to draw expand buttons of the grid.
	// Parameters:
	//     dc - Reference to a valid device context
	//     pItem - Points to a CXTPPropertyGridItem object
	//     rcCaption - Caption button rectangle.
	//-----------------------------------------------------------------------
	virtual void DrawExpandButton(CDC& dc, CXTPPropertyGridItem* pItem, CRect rcCaption);

	//-----------------------------------------------------------------------
	// Summary:
	//     Returns scroll bar theme identifier.
	//-----------------------------------------------------------------------
	virtual XTPScrollBarTheme GetScrollBarTheme() const;

protected:
	BOOL m_bLight;
};

//===========================================================================
// Summary:
//     CXTPPropertyGridOffice2013Theme is a CXTPPropertyGridPaintManager derived
//     class.  This represents a Office XP style theme.
//===========================================================================
class _XTP_EXT_CLASS CXTPPropertyGridOffice2013Theme : public CXTPPropertyGridPaintManager
{
public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPPropertyGridOffice2013Theme object.
	// Parameters:
	//     pGrid - Points to a CXTPPropertyGrid object
	//-----------------------------------------------------------------------
	CXTPPropertyGridOffice2013Theme(CXTPPropertyGrid* pGrid);

	//-------------------------------------------------------------------------
	// Summary:
	//     This method is called to refresh the visual metrics of the
	//     property grid.
	//-------------------------------------------------------------------------
	virtual void RefreshMetrics();

	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called to draw expand buttons of the grid.
	// Parameters:
	//     dc - Reference to a valid device context
	//     pItem - Points to a CXTPPropertyGridItem object
	//     rcCaption - Caption button rectangle.
	//-----------------------------------------------------------------------
	virtual void DrawExpandButton(CDC& dc, CXTPPropertyGridItem* pItem, CRect rcCaption);

	//-----------------------------------------------------------------------
	// Summary:
	//     Returns scroll bar theme identifier.
	//-----------------------------------------------------------------------
	virtual XTPScrollBarTheme GetScrollBarTheme() const;

	CXTPPaintManagerColor m_clrGlyphExpand;   // Expand glyph color.
	CXTPPaintManagerColor m_clrGlyphBorder;   // Expand glyph border color.
	CXTPPaintManagerColor m_clrGlyphContract; // Contract glyph color.
};

//===========================================================================
// Summary:
//     CXTPPropertyGridVisualStudio2015Theme is a CXTPPropertyGridVisualStudio2010Theme derived
//     class.  This represents a Office XP style theme.
//===========================================================================
class _XTP_EXT_CLASS CXTPPropertyGridVisualStudio2015Theme
	: public CXTPPropertyGridVisualStudio2010Theme
{
public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPPropertyGridVisualStudio2015Theme object.
	// Parameters:
	//     pGrid - Points to a CXTPPropertyGrid object
	//-----------------------------------------------------------------------
	CXTPPropertyGridVisualStudio2015Theme(CXTPPropertyGrid* pGrid);

	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called to draw expand buttons of the grid.
	// Parameters:
	//     dc - Reference to a valid device context
	//     pItem - Points to a CXTPPropertyGridItem object
	//     rcCaption - Caption button rectangle.
	//-----------------------------------------------------------------------
	virtual void DrawExpandButton(CDC& dc, CXTPPropertyGridItem* pItem, CRect rcCaption);

	//-------------------------------------------------------------------------
	// Summary:
	//     This method is called to refresh the visual metrics of the
	//     property grid.
	//-------------------------------------------------------------------------
	virtual void RefreshMetrics();

	//-----------------------------------------------------------------------
	// Summary:
	//     Returns scroll bar theme identifier.
	//-----------------------------------------------------------------------
	virtual XTPScrollBarTheme GetScrollBarTheme() const;
};

AFX_INLINE CXTPPropertyGridItemMetrics* CXTPPropertyGridPaintManager::GetItemMetrics() const
{
	return m_pMetrics;
}

AFX_INLINE void CXTPPropertyGridPaintManager::DrawInplaceButtons(CDC* pDC,
																 CXTPPropertyGridItem* pItem,
																 CRect rcValue)
{
	DrawInplaceButtons(pDC, NULL, pItem, rcValue);
}

AFX_INLINE int CXTPPropertyGridPaintManager::GetItemsBorderHeight() const
{
	return m_nItemsBorderHeight;
}

AFX_INLINE void CXTPPropertyGridPaintManager::SetItemsBorderHeight(int nHeight)
{
	m_nItemsBorderHeight = nHeight;
}

#	include "Common/Base/Diagnostic/XTPEnableNoisyWarnings.h"
#endif // !defined(_XTPPROPERTYGRIDPAINTMANAGER_H__)
