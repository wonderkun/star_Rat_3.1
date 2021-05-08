// XTPFlowGraphPaintManager.h: interface for the CXTPFlowGraphPaintManager class.
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
#if !defined(__XTPFLOWGRAPHPAINTMANAGER_H__)
#	define __XTPFLOWGRAPHPAINTMANAGER_H__
//}}AFX_CODEJOCK_PRIVATE

#	if _MSC_VER > 1000
#		pragma once
#	endif // _MSC_VER > 1000

#	include "Common/Base/Diagnostic/XTPDisableNoisyWarnings.h"

class CXTPFlowGraphControl;
class CXTPFlowGraphDrawContext;
class CXTPFlowGraphNode;
class CXTPFlowGraphConnectionPoint;
class CXTPFlowGraphConnection;
class CXTPFlowGraphNodeGroup;
class CXTPFlowGraphElement;

namespace Gdiplus
{
class Font;
}

// ------------------------------------------------------------------
// Summary:
//     Node connector styles.
// Remarks:
//     The xtpFlowGraphConnectorType specifies the style of the lines
//     that "connect" the connections of a node.
// See Also:
//     CXTPFlowGraphPaintManager::m_nConnectorType
// ------------------------------------------------------------------
enum XTPFlowGraphConnectorType
{
	xtpFlowGraphConnectorStraight			 = 0, // 00000000
	xtpFlowGraphConnectorStraightArrow		 = 1, // 00000001
	xtpFlowGraphConnectorStraightDoubleArrow = 3, // 00000011
	xtpFlowGraphConnectorCurved				 = 4, // 00000100
	xtpFlowGraphConnectorCurvedArrow		 = 5, // 00000101
	xtpFlowGraphConnectorCurvedDoubleArrow   = 7, // 00000111
	xtpFlowGraphConnectorElbow				 = 8, // 00001000
	xtpFlowGraphConnectorElbowArrow			 = 9, // 00001001
	xtpFlowGraphConnectorElbowDoubleArrow	= 11 // 00001011
};

#	define IsStraightConnection(type) ((type >> 2) == 0)
#	define IsCurvedConnection(type) ((type & 4))
#	define IsElbowConnection(type) ((type & 8))

#	define HasStartingArrow(type) ((type & 2))
#	define HasEndingArrow(type) ((type & 1))

// -------------------------------------------------------------
//
// Summary:
//     Handles most of the drawing activities of the Flow Graph.
// -------------------------------------------------------------
class _XTP_EXT_CLASS CXTPFlowGraphPaintManager : public CXTPCmdTarget
{
public:
	// --------------------------------------------------
	// Summary:
	//     Constructs a CXTPFlowGraphPaintManager object.
	// --------------------------------------------------
	CXTPFlowGraphPaintManager();
	// --------------------------------------------------------------------
	// Summary:
	//     Destroys a CXTPFlowGraphPaintManager object, handles cleanup and
	//     deallocation.
	// --------------------------------------------------------------------
	virtual ~CXTPFlowGraphPaintManager();

protected:
	BOOL CalculateConnectionPointsPositions(CXTPFlowGraphConnection* pConnection, CPoint& p1,
											CPoint& p2);

public:
	// ----------------------------------------------------
	// Summary:
	//     Draws the background for the flow graph control.
	// Parameters:
	//     pDC :       Pointer to a valid device context.
	//     pControl :  Pointer to the flow graph control.
	// ----------------------------------------------------
	virtual void DrawControlBackground(CXTPFlowGraphDrawContext* pDC,
									   CXTPFlowGraphControl* pControl, BOOL bPrintToFile = FALSE,
									   const CRect& drawRect = CRect(0, 0, 0, 0));

	// -------------------------------------------------------------------
	// Summary:
	//     This method is called to refresh the visual metrics of the flow
	//     graph.
	// -------------------------------------------------------------------
	virtual void RefreshMetrics();

	// ----------------------------------------------------------------------
	// Summary:
	//     Recalculates the layout of the connection.
	// Remarks:
	//     Call this functions to correctly reposition the connection within
	//     the node. This will also update any colors, etc that have changed.
	// ----------------------------------------------------------------------
	virtual void RecalcConnectionLayout(CXTPFlowGraphDrawContext* pDC,
										CXTPFlowGraphConnection* pConnection);

	// ----------------------------------------------------------------------
	// Summary:
	//     This method is called to draw a single connection in the flow
	//     graph control.
	// Parameters:
	//     pDC :          Pointer to a valid device context.
	//     pConnection :  Points to a CXTPFlowGraphConnection object to draw.
	// ----------------------------------------------------------------------
	virtual void DrawConnection(CXTPFlowGraphDrawContext* pDC,
								CXTPFlowGraphConnection* pConnection);

	// ------------------------------------------------------------------
	// Summary:
	//     Gets the bounding rectangle for the specified node.
	// Parameters:
	//     pNode :  Reference to the node to get it's bounding rectangle.
	// Returns:
	//     The bounding rectangle for the specified node.
	// ------------------------------------------------------------------
	virtual CRect GetNodeBoundingRectangle(CXTPFlowGraphNode* pNode);

	// --------------------------------------------------------------------
	// Summary:
	//     This method is called to draw a transparent rectangle on the
	//     graph control.
	// Parameters:
	//     pDC :         Pointer to a valid device context.
	//     rect :        Rectangle boundaries
	//     clrColor :    Base color
	// --------------------------------------------------------------------
	void DrawTransparentRectangle(CXTPFlowGraphDrawContext* pDC, CRect rect, COLORREF clrColor);

	// --------------------------------------------------------------------
	// Summary:
	//     This method is called to draw a single node group in the flow
	//     graph control.
	// Parameters:
	//     pDC :         Pointer to a valid device context.
	//     pNodeGroup :  Points to a CXTPFlowGraphNodeGroup object to draw.
	// --------------------------------------------------------------------
	virtual void DrawNodeGroup(CXTPFlowGraphDrawContext* pDC, CXTPFlowGraphNodeGroup* pNodeGroup);

	// --------------------------------------------------------------------
	// Summary:
	//     Determines if the specified point is within the connection area.
	// Parameters:
	//     pPoint :  CXTPFlowGraphConnectionPoint to test.
	//     point :   Point in flow graph to test.
	// Returns:
	//     True if the point is located within the connection area, False
	//     \otherwise.
	// --------------------------------------------------------------------
	virtual BOOL HitTestConnectionArea(const CXTPFlowGraphConnectionPoint* pPoint, CPoint point);

	// ------------------------------------------------------------------------
	// Summary:
	//     Gets the bounding rectangle for the caption of the specified node.
	// Parameters:
	//     pNode :  Reference to the element to retrieve the bounding rectangle
	//              for the caption.
	// Returns:
	//     The bounding rectangle for the caption of the specified node.
	// ------------------------------------------------------------------------
	virtual CRect GetCaptionRect(CXTPFlowGraphElement* pNode);

	// --------------------------------------------------------------------
	// Summary:
	//     Cleans up allocated resources used by the paintmanager that have
	//     been allocated during draw routines.
	// --------------------------------------------------------------------
	virtual void Cleanup();

	// ------------------------------------------------------------------
	// Summary:
	//     Creates and returns a darker color of the specified color.
	// Parameters:
	//     clrBackground :  Color to make darker.
	// Remarks:
	//     This will take the specified color and make it darker. For
	//     \example, it will take blue and make "dark blue". This is also
	//     used internally to make the node and group frame colors.
	// Returns:
	//     \Returns a darker color of the specified color.
	// ------------------------------------------------------------------
	static COLORREF AFX_CDECL GetDarkColor(COLORREF clrBackground);

public:
	COLORREF m_clrBackground; // Specifies the background "canvas" color for the flow graph.
	COLORREF m_clrSelection;  // Specifies the color used for selected nodes connection points
							  // rectangles.
	COLORREF m_clrSelectionInactive; // Specifies the color used for selected nodes rectangle
									 // (inactive)
	COLORREF m_clrTextColor;		 // Specifies the color used for text.
	COLORREF m_clrTextColorSelected; // Specifies the color used for text when node is selected

	COLORREF m_clrGridColor; // Specifies the color used for grid lines.

	COLORREF m_clrNodeBackground; // Gets\sets the background color used for Nodes.

	LOGFONT m_lfText;	// Gets\sets the font used for connection captions.
	LOGFONT m_lfCaption; // Gets\sets the font used for Node captions.

	int m_nNodeFrameSize;   // Gets\sets the size of the border-frame of a node.
	int m_nPointTextMargin; // Specifies the margin to place between a connection's caption text and
							// the connection's connection point (if a connection point is present).
	COLORREF m_clrConnection; // Specifies the color of the connection lines that connect two
							  // connection points.
	int m_nEllipseSize;		  // Specifies the size of Connection Points.
	BOOL m_bShowGrid;		  // Specifies whether to show the grid for the flow graph.

	BOOL m_bShowNodeGroupsAlways;		// Specifies whether to always show node groups, even if a
										// non-grouped node is selected (or no nodes are selected).
	BOOL m_bAlwaysDrawConnectionPoints; // Specifies whether to draw connection points always or
										// draw only on active nodes
	BOOL m_bRecalcConnectionLayoutWhenNeeded; // recalculates end points of a connection when it's
											  // selected state changes

	BOOL m_bChangeNodeColorWhenSelected; // true by default. Otherwise selected node's caption text
										 // color is changed (to white by default,
										 // m_clrTextColorSelected)

	XTPFlowGraphConnectorType m_nConnectorType; // Node connector style.

	double m_dMinZoomLevelBackground; // Specifies the minimum zoom level to stop drawing the
									  // background of the flow graph.  Default is 20%.  Can be used
									  // to optimize drawing when a lot of objects are on screen.
	double m_dMinZoomLevelConnectionPoints; // Specifies the minimum zoom level to stop drawing
											// connection points in the flow graph.  Default is 30%.
											// Can be used to optimize drawing when a lot of objects
											// are on screen.
	double m_dMinZoomLevelConnections;		// Specifies the minimum zoom level to stop drawing
									   // connections in the flow graph.  Default is 5%.  Can be
									   // used to optimize drawing when a lot of objects are on
									   // screen.
	double m_dMinZoomLevelGDIQuality; // Specifies the minimum zoom level to stop using GDI quality
									  // when drawing elements in the flow graph.  Default is 40%.
									  // Can be used to optimize drawing when a lot of objects are
									  // on screen.

protected:
#	ifdef _XTP_ACTIVEX
	//{{AFX_CODEJOCK_PRIVATE

	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()

	DECLARE_OLETYPELIB_EX(CXTPFlowGraphPaintManager)

	afx_msg void OleSetFont(LPFONTDISP pFontDisp);
	afx_msg LPFONTDISP OleGetFont();
	afx_msg void OleSetCaptionFont(LPFONTDISP pFontDisp);
	afx_msg LPFONTDISP OleGetCaptionFont();

//}}AFX_CODEJOCK_PRIVATE
#	endif
};

#	include "Common/Base/Diagnostic/XTPEnableNoisyWarnings.h"
#endif //#if !defined(__XTPFLOWGRAPHPAINTMANAGER_H__)
