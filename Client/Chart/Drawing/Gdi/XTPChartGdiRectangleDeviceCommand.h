// XTPCharGditRectangleDeviceCommand.h
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
#if !defined(__XTPCHARTGDIRECTANGLEDEVICECOMMAND_H__)
#	define __XTPCHARTGDIRECTANGLEDEVICECOMMAND_H__

#	if _MSC_VER >= 1000
#		pragma once
#	endif // _MSC_VER >= 1000

#	include "Common/Base/Diagnostic/XTPDisableNoisyWarnings.h"

namespace Gdiplus
{
class GpPath;
}

//===========================================================================
// Summary:
//     This class represents a bounded rectangle device command,which is a kind of
//     CXTPChartDeviceCommand. It specifically handles the rendering of bounded rectangular
//     shapes in a chart.
// Remarks:
//===========================================================================
class _XTP_EXT_CLASS CXTPChartGdiBoundedRectangleDeviceCommand
	: public CXTPChartRectangleDeviceCommand
{
public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPChartGdiBoundedRectangleDeviceCommand object.
	// Parameters:
	//     rect      - The rectangular area to be rendered by the device command.
	//     color     - The color of the rectangle border.
	//     thickness - The thickness of the rectangular border.
	// Remarks:
	//-----------------------------------------------------------------------
	CXTPChartGdiBoundedRectangleDeviceCommand(const CXTPChartRectF& rect,
											  const CXTPChartColor& color, int thickness);

protected:
	//-----------------------------------------------------------------------
	// Summary:
	//     This is a virtual function override of base class CXTPChartDeviceContext,
	//     act polymorphically to do the actual drawing of the chart element, to which
	//     this device command is associated with.
	// Parameters:
	//     pDC      - The device context of the chart.
	// Remarks:
	//-----------------------------------------------------------------------
	void ExecuteOverride(CXTPChartDeviceContext* pDC);

	//-----------------------------------------------------------------------
	// Summary:
	//     This override do some works if any, before drawing of the chart element
	// Parameters:
	//     pDC - A pointer to the chart native device context.
	// Remarks:
	//-----------------------------------------------------------------------
	virtual void BeforeExecute(CXTPChartDeviceContext* pDC);

	//-----------------------------------------------------------------------
	// Summary:
	//     This override do some works if any, after drawing of the chart element
	// Parameters:
	//     pDC - A pointer to the chart native device context.
	// Remarks:
	//-----------------------------------------------------------------------
	virtual void AfterExecute(CXTPChartDeviceContext* pDC);

protected:
	CXTPChartColor m_color;		// The color of the rectangle border.
	int m_thickness;			// The thickness of the rectangle border.
	int m_OldSmoothingMode;		// Default SmoothingMode
	int m_OldPixelOffsetMode;   // Default PixelOffsetMode
	int m_OldInterpolationMode; // Default InterpolationMode
};

class _XTP_EXT_CLASS CXTPChartGdiInnerBorderDeviceCommand
	: public CXTPChartGdiBoundedRectangleDeviceCommand
{
public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPChartGdiInnerBorderDeviceCommand object.
	// Parameters:
	//     rect      - The rectangular area to be rendered by the device command.
	//     color     - The color of the rectangle border.
	//     thickness - The thickness of the rectangular border.
	// Remarks:
	//-----------------------------------------------------------------------
	CXTPChartGdiInnerBorderDeviceCommand(const CXTPChartRectF& rect, const CXTPChartColor& color,
										 int thickness);
};

//===========================================================================
// Summary:
//     This class represents a solid rectangle device command,which is a kind of
//     CXTPChartDeviceCommand. It specifically handles the rendering of solid rectangular shapes in
//     a chart like label.
// Remarks:
//===========================================================================
class _XTP_EXT_CLASS CXTPChartGdiSolidRectangleDeviceCommand
	: public CXTPChartRectangleDeviceCommand
{
public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPChartGdiSolidRectangleDeviceCommand object.
	// Parameters:
	//     rect      - The rectangular area to be rendered by the device command.
	//     color     - The color of the rectangle.
	// Remarks:
	//-----------------------------------------------------------------------
	CXTPChartGdiSolidRectangleDeviceCommand(const CXTPChartRectF& rect,
											const CXTPChartColor& color);

protected:
	//-----------------------------------------------------------------------
	// Summary:
	//     This is a virtual function override of base class CXTPChartDeviceContext,
	//     act polymorphically to do the actual drawing of the chart element, to which
	//     this device command is associated with.
	// Parameters:
	//     pDC      - The device context of the chart.
	// Remarks:
	//-----------------------------------------------------------------------
	void ExecuteOverride(CXTPChartDeviceContext* pDC);

protected:
	CXTPChartColor m_color; // The color of the rectangle.
};

//===========================================================================
// Summary:
//     This class represents a gradient rectangle device command,which is a kind of
//     CXTPChartDeviceCommand. It specifically handles the rendering of gradient rectangular shapes
//     in a chart.
// Remarks:
//===========================================================================
class _XTP_EXT_CLASS CXTPChartGdiGradientRectangleDeviceCommand
	: public CXTPChartRectangleDeviceCommand
{
public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPChartGdiGradientRectangleDeviceCommand object.
	// Parameters:
	//     rect      - The rectangular area to be rendered by the device command.
	//     color     - The start color of the gradient.
	//     color2    - The end color of the gradient.
	//     nMode     - The linear gradient mode, it can be horizontal, vertical,
	//                 forward diagonal or backward diagonal.
	// Remarks:
	//-----------------------------------------------------------------------
	CXTPChartGdiGradientRectangleDeviceCommand(const CXTPChartRectF& rect,
											   const CXTPChartColor& color,
											   const CXTPChartColor& color2,
											   XTPChartLinearGradientMode nMode);

protected:
	//-----------------------------------------------------------------------
	// Summary:
	//     This is a virtual function override of base class CXTPChartDeviceContext,
	//     act polymorphically to do the actual drawing of the chart element, to which
	//     this device command is associated with.
	// Parameters:
	//     pDC      - The device context of the chart.
	// Remarks:
	//-----------------------------------------------------------------------
	void ExecuteOverride(CXTPChartDeviceContext* pDC);

protected:
	CXTPChartColor m_color;				// The start color of the gradient.
	CXTPChartColor m_color2;			// The end color of the gradient.
	XTPChartLinearGradientMode m_nMode; // The gradient mode.
};

//===========================================================================
// Summary:
//     This class represents a hatch rectangle device command,which is a kind of
//     CXTPChartDeviceCommand. It specifically handles the rendering of hatch
//     rectangular shapes in a chart.
// Remarks:
//===========================================================================
class _XTP_EXT_CLASS CXTPChartGdiHatchRectangleDeviceCommand
	: public CXTPChartRectangleDeviceCommand
{
public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPChartGdiHatchRectangleDeviceCommand object.
	// Parameters:
	//     rect      - The rectangular area to be rendered by the device command.
	//     color     - The first color of the pattern.
	//     color2    - The second color of the pattern.
	//     nStyle    - chart hatch style.
	// Remarks:
	//-----------------------------------------------------------------------
	CXTPChartGdiHatchRectangleDeviceCommand(const CXTPChartRectF& rect, const CXTPChartColor& color,
											const CXTPChartColor& color2,
											XTPChartHatchStyle nStyle);

protected:
	//-----------------------------------------------------------------------
	// Summary:
	//     This is a virtual function override of base class CXTPChartDeviceContext,
	//     act polymorphically to do the actual drawing of the chart element, to which
	//     this device command is associated with.
	// Parameters:
	//     pDC      - The device context of the chart.
	// Remarks:
	//-----------------------------------------------------------------------
	void ExecuteOverride(CXTPChartDeviceContext* pDC);

protected:
	CXTPChartColor m_color;		 // The first color.
	CXTPChartColor m_color2;	 // The second color.
	XTPChartHatchStyle m_nStyle; // The hatch style selected.
};

#	include "Common/Base/Diagnostic/XTPEnableNoisyWarnings.h"
#endif //#if !defined(__XTPCHARTGDIRECTANGLEDEVICECOMMAND_H__)
//}}AFX_CODEJOCK_PRIVATE
