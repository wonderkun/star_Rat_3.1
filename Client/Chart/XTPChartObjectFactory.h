// XTPChartObjectFactory.h
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
#if !defined(__XTPCHARTOBJECTFACTORY_H__)
#	define __XTPCHARTOBJECTFACTORY_H__
//}}AFX_CODEJOCK_PRIVATE

#	if _MSC_VER >= 1000
#		pragma once
#	endif // _MSC_VER >= 1000

#	include "Common/Base/Diagnostic/XTPDisableNoisyWarnings.h"

class CXTPChartDrawingObjectFactory;

/////////////////////////////////////////////////////////////////////////
// CXTPChartObjectFactory

class _XTP_EXT_CLASS CXTPChartObjectFactory : public CXTPSingleton<CXTPChartObjectFactory>
{
	friend class CXTPSingleton<CXTPChartObjectFactory>;

	CXTPChartObjectFactory();

public:
	CXTPChartDrawingObjectFactory* Get2dDrawingObjectFactory();
	CXTPChartDrawingObjectFactory* Get3dDrawingObjectFactory();
};

_XTP_EXT_CLASS CXTPChartObjectFactory* AFX_CDECL XTPChartObjectFactory();

#	include "Common/Base/Diagnostic/XTPEnableNoisyWarnings.h"
#endif //#if !defined(__XTPCHARTOBJECTFACTORY_H__)
