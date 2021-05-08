// XTPChartOpenGLPyramidDeviceCommand.h
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
#if !defined(__XTPCHARTOPENGLPYRAMIDDEVICECOMMAND_H__)
#	define __XTPCHARTOPENGLPYRAMIDDEVICECOMMAND_H__

#	if _MSC_VER >= 1000
#		pragma once
#	endif // _MSC_VER >= 1000

#	include "Common/Base/Diagnostic/XTPDisableNoisyWarnings.h"

class CXTPChart3dPyramidSeriesStyle;
class CXTPChartDeviceContext;
class CXTPChartSeriesStyle;
class CXTPChartOpenGLDeviceContext;

//===========================================================================
// Summary:
//     This class represents a chart pyramid device command, which is a kind of
//     CXTPChartDeviceCommand. It specifically handles the rendering of a pyramid
//     in a chart using OpenGL.
// Remarks:
//===========================================================================
class _XTP_EXT_CLASS CXTPChartOpenGLPyramidDeviceCommand : public CXTPChart3dDeviceCommand
{
public:
	//-------------------------------------------------------------------------
	// Summary:
	//     These functions create a label view drawing command object.
	// Parameters:
	//     center - Pyramid point physical center in 3d space.
	//     dWidth - Total pyramid width.
	//     dHeight - Total pyramid height.
	//     dFrom - The percentage factor value in the range 0..1 of the inital pyramid point value.
	//     dTo - The percentage factor value in the range 0..1 of the final pyramid point value.
	//     color - Pyramid point color value.
	//     bSmoothEdges - TRUE to make edges between point faces smooth and reflect light towards
	//                    the outer radius, FALSE to make point faces reflect light in one
	//                    direction.
	//-------------------------------------------------------------------------
	CXTPChartOpenGLPyramidDeviceCommand(const CXTPPoint3d& center, double dWidth, double dHeight,
										double dFrom, double dTo, const CXTPChartColor& color,
										BOOL bSmoothEdges);

	//-------------------------------------------------------------------------
	// Summary:
	//     Handles command object destruction.
	//-------------------------------------------------------------------------
	~CXTPChartOpenGLPyramidDeviceCommand();

protected:
	//-----------------------------------------------------------------------
	// Summary:
	//      Performs recursive hit testing of the element at the specified point.
	// Parameters:
	//      point - Point at which an element to be found.
	//      pParent - Parent element pointer.
	// Returns:
	//      A pointer to the element found at the specified point or NULL
	//      if no element is found.
	//-----------------------------------------------------------------------
	virtual CXTPChartElement* HitTest(CPoint point, CXTPChartElement* pParent) const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Override this function to write the drawing code for specific objects.
	// Parameters:
	//     pDC - A pointer to the chart device context.
	//-----------------------------------------------------------------------
	virtual void ExecuteOverride(CXTPChartDeviceContext* pDC);

	//-----------------------------------------------------------------------
	// Summary:
	//      Applies series style to the current element.
	// Parameters:
	//      pStyle - Series style to apply.
	//-----------------------------------------------------------------------
	virtual void ApplySeriesStyle(CXTPChartSeriesStyle* pStyle);

	//-----------------------------------------------------------------------
	// Summary:
	//      Derived implementation must override this method for implementing
	//      implementation specific preparation behavior.
	// Parameters:
	//      pDC - Device context pointer for which the command is to be prepared.
	// See also:
	//      Prepare
	//-----------------------------------------------------------------------
	virtual void PrepareOverride(CXTPChartDeviceContext* pDC);

private:
	void DrawTriangle(const CXTPPoint3d& a, const CXTPPoint3d& va, const CXTPPoint3d& b,
					  const CXTPPoint3d& vb, const CXTPPoint3d& c, const CXTPPoint3d& vc);
	void DrawPyramidSlice();

	void ComputeConnectorPoints(CXTPChartOpenGLDeviceContext* pGLDC);

private:
	BOOL m_bPrepared;
	CXTPChart3dBox m_3dBox;
	CXTPPoint3d m_ptCenterConnectorPoint;
	CXTPPoint3d m_ptOuterConnectorPoint;
	CXTPChartColor m_color;
	CXTPChart3dPyramidSeriesStyle* m_pStyle;
	GLuint m_listId;
	double m_dWidth;
	double m_dHeight;
	double m_dFrom;
	double m_dTo;
	CXTPPoint3d m_ptCenter;
	BOOL m_bSmoothEdges;
	CArray<CXTPPoint3d, const CXTPPoint3d&> m_arMidFacePoints;
};

#	include "Common/Base/Diagnostic/XTPEnableNoisyWarnings.h"
#endif //#if !defined(__XTPCHARTOPENGLPYRAMIDDEVICECOMMAND_H__)
//}}AFX_CODEJOCK_PRIVATE
