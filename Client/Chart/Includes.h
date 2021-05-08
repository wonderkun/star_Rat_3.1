// Includes.h : header file
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
#if !defined(__XTPCHART_INCLUDES_H__)
#	define __XTPCHART_INCLUDES_H__

#	if _MSC_VER >= 1000
#		pragma once
#	endif // _MSC_VER >= 1000

#	include "GraphicLibrary/GdiPlus/XTPGdiPlus.h"

#	include "Common/XTPSystemHelpers.h"

#	include "Chart/Types/XTPChartTypes.h"
#	include "Common/Base/Types/XTPPoint3.h"
#	include "Types/XTPChartPie.h"

#	include "Chart/XTPChartDefines.h"
#	include "Chart/XTPChartElement.h"
#	include "Chart/XTPChartLegendItem.h"
#	include "Chart/XTPChartElementView.h"
#	include "Chart/XTPChartLegend.h"
#	include "Chart/XTPChartTitle.h"
#	include "Chart/XTPChartSeriesPointView.h"
#	include "Chart/XTPChartSeriesView.h"
#	include "Chart/XTPChartSeriesStyle.h"
#	include "Chart/XTPChartSeriesPoint.h"
#	include "Chart/XTPChartSeriesLabel.h"
#	include "Chart/XTPChartSeries.h"
#	include "Chart/XTPChartPanel.h"
#	include "Chart/XTPChartDiagram.h"
#	include "Chart/XTPChartDiagramView.h"
#	include "Chart/XTPChartControl.h"
#	include "Chart/XTPChartContent.h"
#	include "Chart/XTPChartContentView.h"
#	include "Chart/XTPChartErrorBar.h"
#	include "Chart/XTPChartTrendline.h"

#	include "Diagram/Axis/XTPChartAxis.h"
#	include "Diagram/Axis/XTPChartAxisLabel.h"
#	include "Diagram/Axis/XTPChartAxisRange.h"
#	include "Diagram/Axis/XTPChartAxisGridLines.h"
#	include "Diagram/Axis/XTPChartAxisTitle.h"
#	include "Diagram/Axis/XTPChartAxisConstantLines.h"
#	include "Diagram/Axis/XTPChartAxisCustomLabels.h"
#	include "Diagram/Axis/XTPChartAxisStrips.h"
#	include "Diagram/Axis/XTPChartAxisTickMarks.h"
#	include "Diagram/Axis/XTPChartAxisView.h"
#	include "Diagram/Axis/XTPChartScaleTypeMap.h"

#	include "Diagram/Diagram2D/XTPChartDiagram2DPane.h"
#	include "Diagram/Diagram2D/XTPChartDiagram2D.h"
#	include "Diagram/Diagram2D/XTPChartDiagram2DView.h"
#	include "Diagram/Diagram2D/XTPChartDiagram2DSeriesView.h"
#	include "Diagram/Diagram2D/XTPChartDiagram2DSeriesStyle.h"
#	include "Diagram/Diagram2D/XTPChartDiagram2DSeriesLabel.h"

#	include "Diagram/RadarDiagram/XTPChartRadarDiagram.h"
#	include "Diagram/RadarDiagram/XTPChartRadarDiagramSeriesStyle.h"
#	include "Diagram/RadarDiagram/XTPChartRadarDiagramSeriesView.h"

#	include "Styles/Point/XTPChartPointSeriesStyle.h"
#	include "Styles/Point/XTPChartPointSeriesView.h"
#	include "Styles/Point/XTPChartPointSeriesLabel.h"
#	include "Styles/Point/XTPChartBubbleSeriesStyle.h"
#	include "Styles/Point/XTPChartBubbleSeriesLabel.h"
#	include "Styles/Point/XTPChartMarker.h"

#	include "Styles/Pie/XTPChartPieSeriesStyle.h"
#	include "Styles/Pie/XTPChartPieDiagram.h"
#	include "Styles/Pie/XTPChartPieSeriesLabel.h"
#	include "Styles/Pie/3D/XTPChart3dPieSeriesStyle.h"

#	include "Styles/Funnel/XTPChartFunnelSeriesStyle.h"
#	include "Styles/Funnel/XTPChartFunnelSeriesView.h"
#	include "Styles/Funnel/XTPChartFunnelSeriesLabel.h"
#	include "Styles/Funnel/XTPChartFunnelDiagram.h"

#	include "Styles/Radar/XTPChartRadarPointSeriesStyle.h"
#	include "Styles/Radar/XTPChartRadarPointSeriesLabel.h"
#	include "Styles/Radar/XTPChartRadarPointSeriesView.h"
#	include "Styles/Radar/XTPChartRadarLineSeriesStyle.h"
#	include "Styles/Radar/XTPChartRadarLineSeriesView.h"
#	include "Styles/Radar/XTPChartRadarAreaSeriesStyle.h"
#	include "Styles/Radar/XTPChartRadarAreaSeriesView.h"
#	include "Styles/Radar/XTPChartRadarSplineSeriesStyle.h"
#	include "Styles/Radar/XTPChartRadarSplineAreaSeriesStyle.h"

#	include "Styles/Pyramid/XTPChartPyramidSeriesStyle.h"
#	include "Styles/Pyramid/XTPChartPyramidSeriesView.h"
#	include "Styles/Pyramid/XTPChartPyramidSeriesPointView.h"
#	include "Styles/Pyramid/XTPChartPyramidSeriesLabel.h"
#	include "Styles/Pyramid/XTPChartPyramidDiagram.h"
#	include "Styles/Pyramid/XTPChartPyramidDiagramView.h"
#	include "Styles/Pyramid/3D/XTPChart3dPyramidSeriesStyle.h"

#	include "Styles/Line/XTPChartLineSeriesStyle.h"
#	include "Styles/Line/XTPChartScatterLineSeriesStyle.h"
#	include "Styles/Line/XTPChartFastLineSeriesStyle.h"
#	include "Styles/Line/XTPChartStepLineSeriesStyle.h"
#	include "Styles/Line/XTPChartSplineSeriesStyle.h"

#	include "Styles/Area/XTPChartAreaSeriesStyle.h"
#	include "Styles/Area/XTPChartAreaSeriesView.h"
#	include "Styles/Area/XTPChartStackedAreaSeriesStyle.h"
#	include "Styles/Area/XTPChartSplineAreaSeriesStyle.h"
#	include "Styles/Area/XTPChartStackedSplineAreaSeriesStyle.h"
#	include "Styles/Area/XTPChartRangeSplineAreaSeriesStyle.h"
#	include "Styles/Area/XTPChartStepAreaSeriesStyle.h"

#	include "Styles/Bar/XTPChartBarSeriesStyle.h"
#	include "Styles/Bar/XTPChartBarSeriesView.h"
#	include "Styles/Bar/XTPChartStackedBarSeriesStyle.h"
#	include "Styles/Bar/XTPChartBarSeriesLabel.h"

#	include "Styles/Range/XTPChartRangeBarSeriesStyle.h"
#	include "Styles/Range/XTPChartRangeBarSeriesView.h"
#	include "Styles/Range/XTPChartRangeBarSeriesLabel.h"
#	include "Styles/Range/XTPChartGanttSeriesStyle.h"

#	include "Styles/Financial/XTPChartHighLowSeriesStyle.h"
#	include "Styles/Financial/XTPChartCandleStickSeriesStyle.h"

#	include "Drawing/XTPChartDeviceContext.h"
#	include "Drawing/XTPChartDeviceCommand.h"
#	include "Drawing/XTPChartLineDeviceCommand.h"
#	include "Drawing/XTPChartPieDeviceCommand.h"
#	include "Drawing/XTPChartRectangleDeviceCommand.h"
#	include "Drawing/XTPChartTextDeviceCommand.h"
#	include "Drawing/XTPChartTransformationDeviceCommand.h"

#	include "Appearance/XTPChartAppearance.h"
#	include "Appearance/XTPChartLineStyle.h"
#	include "Appearance/XTPChartBorder.h"
#	include "Appearance/XTPChartPalette.h"
#	include "Appearance/XTPChartFillStyle.h"

#	include "Common/Math/XTPMathUtils.h"
#	include "Utils/XTPChartTextPainter.h"
#	include "Utils/XTPChartNumberFormat.h"

#endif //#if !defined(__XTPCHART_INCLUDES_H__)

//}}AFX_CODEJOCK_PRIVATE
