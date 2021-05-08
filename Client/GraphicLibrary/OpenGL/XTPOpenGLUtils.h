// XTPOpenGLUtils.h
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
#if !defined(__XTPOPENGLUTILS_H__)
#define __XTPOPENGLUTILS_H__
//}}AFX_CODEJOCK_PRIVATE

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Common/Base/Diagnostic/XTPDisableNoisyWarnings.h"

template<class T>
class CXTPMatrix;

//-----------------------------------------------------------------------
// Summary:
//      Provides a set of common OpenGL utilities.
//-----------------------------------------------------------------------
class _XTP_EXT_CLASS CXTPOpenGLUtils
{
public:
	//{{AFX_CODEJOCK_PRIVATE
#ifdef _DEBUG
	// Debugging
	static void DebugAxes(double dSize);
	static void DebugBox(const CXTPPoint3d& ptMin, const CXTPPoint3d& ptMax, BOOL bSolid = FALSE);
#endif /*_DEBUG*/
	//}}AFX_CODEJOCK_PRIVATE

	//-----------------------------------------------------------------------
	// Summary:
	//      Sets vertex from point coordinates.
	// Parameters:
	//      ptVertext - Vertex coordinates.
	//-----------------------------------------------------------------------
	static void Vertex(const CXTPPoint3d& ptVertext);

	//-----------------------------------------------------------------------
	// Summary:
	//      Sets vertex and its normal from point coordinates.
	// Parameters:
	//      ptVertext - Vertex coordinates.
	//      vNormal - Normal coordinates.
	//-----------------------------------------------------------------------
	static void Vertex(const CXTPPoint3d& ptVertext, const CXTPPoint3d& vNormal);

	//-----------------------------------------------------------------------
	// Summary:
	//      Rotates active matrix using Euler angles.
	// Parameters:
	//      dYaw - Yaw angle value in degrees.
	//      dPitch - Pitch angle value in degrees.
	//      dRoll - Roll angle value in degrees.
	//-----------------------------------------------------------------------
	static void Rotate(double dYaw, double dPitch, double dRoll);

	//-----------------------------------------------------------------------
	// Summary:
	//      Projects coordinates from 3D space to 2D space coordinate of the current viewport.
	// Parameters:
	//      pt3d - 3D space point coordinate.
	//      pt2d - Result 2D space point coordinate of the current viewport.
	//      pdWinZ - If not NULL and the function succeedes the value defines
	//               Z-plane coordinate of the specified 3D point, i.e. the position
	//               between the near plane (0) and the far plane (1).
	// Returns:
	//      TRUE if the coordinates are successfully mapped.
	// See also:
	//      Unproject
	//-----------------------------------------------------------------------
	static BOOL Project(const CXTPPoint3d& pt3d, CPoint& pt2d, double* pdWinZ = NULL);

	//-----------------------------------------------------------------------
	// Summary:
	//      Unprojects coordinates from 2D space coordinates of the current viewport 
	//      to 3D space coordinates between the near and the far planes.
	// Parameters:
	//      pt2d - 2D space coordinates of the current viewport.
	//      pt3d - Result 3D space coordinates.
	//      dWinZ - Z-plane coordinate value, i.e. a value between the near plane (0)
	//              or the far plane (1).
	// Returns:
	//      TRUE if coordinates are mapped successfully.
	// See also:
	//      Project
	//-----------------------------------------------------------------------
	static BOOL Unproject(const CPoint& pt2d, CXTPPoint3d& pt3d, double dWinZ = 0.);

	//-----------------------------------------------------------------------
	// Summary:
	//      Mutpliplies a vector by the matrix provided.
	// Parameters:
	//      v - The vector to multiply by the matrix.
	//      matrix - The matrix by which the vector is multiplied.
	//-----------------------------------------------------------------------
	static void MultiplyByMatrix(CXTPPoint3d& v, const CXTPMatrix<double>& matrix);

	//-----------------------------------------------------------------------
	// Summary:
	//      Mutpliplies a vector by the OpenGL matrix specified by its ID.
	// Parameters:
	//      v - The vector to multiply by the matrix.
	//      name - OpenGL matrix name by which the vector is multiplied.
	//-----------------------------------------------------------------------
	static void MultiplyByMatrix(CXTPPoint3d& v, GLenum name);

	//-----------------------------------------------------------------------
	// Summary:
	//      Computes a normal for a triangle specified.
	// Parameters:
	//      vA - 1st triangle point
	//      vB - 2nd triangle point
	//      vC - 3rd triangle point
	//      ccw - Determines which side of the triangle the normal vector will
	//            be directed from. By default triangle points are assumed to
	//            be in close-wise order which determines the front face of 
	//            the triangle for which the normal is computed. In order
	//            to reverse normal vector this value has to be false which means
	//            counter clock wise vertex unwinding.
	// Returns:
	//      Computed normal vector.
	//-----------------------------------------------------------------------
	static CXTPPoint3d ComputeTriangleNormal(
		const CXTPPoint3d& vA,
		const CXTPPoint3d& vB,
		const CXTPPoint3d& vC,
		bool ccw = false);
};


#include "Common/Base/Diagnostic/XTPEnableNoisyWarnings.h"
#endif // #if !defined(__XTPOPENGLUTILS_H__)
