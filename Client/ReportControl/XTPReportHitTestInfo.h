// XTPReportHitTestInfo.h: interface for the CXTPReportHitTestInfo class.
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
#if !defined(__XTPREPORTHITTESTINFO_H__)
#	define __XTPREPORTHITTESTINFO_H__
//}}AFX_CODEJOCK_PRIVATE

#	if _MSC_VER > 1000
#		pragma once
#	endif // _MSC_VER > 1000

#	include "Common/Base/Diagnostic/XTPDisableNoisyWarnings.h"

// Forward declarations
class CXTPReportColumn;
class CXTPReportRow;
class CXTPReportRecordItem;
class CXTPTrackBlock;

enum XTPReportHitTestInfoCode
{
	xtpReportHitTestUnknown	= 0,
	xtpReportHitTestHeader	 = 1,
	xtpReportHitTestGroupBox   = 2,
	xtpReportHitTestBodyRows   = 3,
	xtpReportHitTestBlock	  = 4,
	xtpReportHitTestHeaderRows = 5,
	xtpReportHitTestFooterRows = 6
};

class _XTP_EXT_CLASS CXTPReportHitTestInfo : public CXTPCmdTarget
{
	DECLARE_DYNCREATE(CXTPReportHitTestInfo)

public:
	CXTPReportHitTestInfo();
	virtual ~CXTPReportHitTestInfo();

	// Attributes
public:
	XTPReportHitTestInfoCode m_htCode;
	CXTPReportColumn* m_pColumn;
	CXTPReportRow* m_pRow;
	CXTPReportRecordItem* m_pItem;
	CXTPTrackBlock* m_pBlock;
	int m_iTrackPosition;

#	ifdef _XTP_ACTIVEX
	//{{AFX_CODEJOCK_PRIVATE
public:
	LPDISPATCH OleGetColumn();
	LPDISPATCH OleGetRow();
	LPDISPATCH OleGetItem();
	LPDISPATCH OleGetBlock();
	long OleGetTrackPosition();
	long OleGetHt();

protected:
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
	DECLARE_OLETYPELIB_EX(CXTPReportHitTestInfo);
	//}}AFX_CODEJOCK_PRIVATE
#	endif
};

#	include "Common/Base/Diagnostic/XTPEnableNoisyWarnings.h"
#endif // !defined(__XTPREPORTHITTESTINFO_H__)
