// XTPOpenGLListPool.h
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
#if !defined(__XTPOPENGLLISTPOOL_H__)
#define __XTPOPENGLLISTPOOL_H__
//}}AFX_CODEJOCK_PRIVATE

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Common/Base/Diagnostic/XTPDisableNoisyWarnings.h"

//-----------------------------------------------------------------------
// Summary:
//      Provides a convenient API around OpenGL list for reliable
//      list management.
//-----------------------------------------------------------------------
class _XTP_EXT_CLASS CXTPOpenGLListPool : public CXTPSingleton<CXTPOpenGLListPool>
{
	friend class CXTPSingleton<CXTPOpenGLListPool>;

	CXTPOpenGLListPool();
	~CXTPOpenGLListPool();

public:

	//-----------------------------------------------------------------------
	// Summary:
	//      Allocates an OpenGL list. Once allocated the list must be committed
	//      using CommitList method after being populated.
	// Parameters:
	//      mode - List compilation flags, can be either GL_COMPILE
	//             or GL_COMPILE_AND_EXECUTE.
	// Returns:
	//      If succeedes the returned value is OpenGL list identifier,
	//      otherwise the returned value is 0.
	// See also:
	//      CommitList, ReclaimList
	//-----------------------------------------------------------------------
	GLuint AllocateList(GLenum mode);

	//-----------------------------------------------------------------------
	// Summary:
	//      Commits a list that has been allocated during a previous call to
	//      AllocateList.
	// See also:
	//      AllocateList
	//-----------------------------------------------------------------------
	void CommitList();

	//-----------------------------------------------------------------------
	// Summary:
	//      Reclaims a previously allocated and committed OpenGL list and
	//      releases all associated resources.
	// Parameters:
	//      id - List it to reclaim.
	// See also:
	//      AllocateList, CommitList
	//-----------------------------------------------------------------------
	void ReclaimList(GLuint id);

private:
	GLuint m_nMax;
	CList<GLuint, const GLuint&> m_allocated;
	CList<GLuint, const GLuint&> m_reclaimed;
	BOOL m_bCommitExpected;
};

//-----------------------------------------------------------------------
// Summary:
//      Provides access to the global instance of OpenGL list pool object.
// Returns:
//      A pointer to the global instance of OpenGL list pool object.
//-----------------------------------------------------------------------
_XTP_EXT_CLASS CXTPOpenGLListPool* AFX_CDECL XTPOpenGLListPool();


#include "Common/Base/Diagnostic/XTPEnableNoisyWarnings.h"
#endif // #if !defined(__XTPOPENGLLISTPOOL_H__)
