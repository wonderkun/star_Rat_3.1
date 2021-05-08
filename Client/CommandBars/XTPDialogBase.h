// XTPDialogBase.h : interface for the CXTPDialogBase and CXTPMDIFrameWnd classes.
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
#if !defined(__XTPDIALOGBASE_H__)
#	define __XTPDIALOGBASE_H__
//}}AFX_CODEJOCK_PRIVATE

#	if _MSC_VER >= 1000
#		pragma once
#	endif // _MSC_VER >= 1000

#	include "Common/Base/Diagnostic/XTPDisableNoisyWarnings.h"

//{{AFX_CODEJOCK_PRIVATE

template<class TBase>
class CXTPDialogBaseParentWrapper : public TBase
{
public:
	CXTPDialogBaseParentWrapper()
	{
	}

	CXTPDialogBaseParentWrapper(UINT nIDTemplate, CWnd* pParentWnd)
		: TBase(nIDTemplate, pParentWnd)
	{
	}

	//<combine CXTPDialogBase::CXTPDialogBase>
	CXTPDialogBaseParentWrapper(LPCTSTR lpszTemplateName, CWnd* pParentWnd)
		: TBase(lpszTemplateName, pParentWnd)
	{
	}

#	if (_MSC_VER > 1200)
	CXTPDialogBaseParentWrapper(UINT nIDTemplate, UINT nHtmlResID, CWnd* pParentWnd)
		: TBase(nIDTemplate, pParentWnd)
	{
		ASSERT(!"This constructor is added for interface compatibility only and must never be "
				"called for a non-DHTML dialog");

		UNREFERENCED_PARAMETER(nHtmlResID);
	}

	CXTPDialogBaseParentWrapper(LPCTSTR lpszTemplateName, LPCTSTR szHtmlResID, CWnd* pParentWnd)
		: TBase(lpszTemplateName, pParentWnd)
	{
		ASSERT(!"This constructor is added for interface compatibility only and must never be "
				"called for a non-DHTML dialog");

		UNREFERENCED_PARAMETER(szHtmlResID);
	}
#	endif // (_MSC_VER > 1200)
};

#	if (_MSC_VER > 1200)
template<>
class CXTPDialogBaseParentWrapper<CDHtmlDialog> : public CDHtmlDialog
{
public:
	CXTPDialogBaseParentWrapper()
	{
	}

	CXTPDialogBaseParentWrapper(UINT nIDTemplate, CWnd* pParentWnd)
		: CDHtmlDialog(nIDTemplate, 0, pParentWnd)
	{
		ASSERT(!"This constructor is added for interface compatibility only and must never be "
				"called for a DHTML dialog");
	}

	//<combine CXTPDialogBase::CXTPDialogBase>
	CXTPDialogBaseParentWrapper(LPCTSTR lpszTemplateName, CWnd* pParentWnd)
		: CDHtmlDialog(lpszTemplateName, 0, pParentWnd)
	{
		ASSERT(!"This constructor is added for interface compatibility only and must never be "
				"called for a DHTML dialog");
	}

	CXTPDialogBaseParentWrapper(UINT nIDTemplate, UINT nHtmlResID, CWnd* pParentWnd)
		: CDHtmlDialog(nIDTemplate, nHtmlResID, pParentWnd)
	{
	}

	CXTPDialogBaseParentWrapper(LPCTSTR lpszTemplateName, LPCTSTR szHtmlResID, CWnd* pParentWnd)
		: CDHtmlDialog(lpszTemplateName, szHtmlResID, pParentWnd)
	{
	}
};

#		ifdef _XTP_INCLUDE_CONTROLS

template<>
class CXTPDialogBaseParentWrapper<CXTPResizeDHtmlDialog> : public CXTPResizeDHtmlDialog
{
public:
	CXTPDialogBaseParentWrapper()
	{
	}

	CXTPDialogBaseParentWrapper(UINT nIDTemplate, CWnd* pParentWnd)
		: CXTPResizeDHtmlDialog(nIDTemplate, 0, pParentWnd)
	{
		ASSERT(!"This constructor is added for interface compatibility only and must never be "
				"called for a DHTML dialog");
	}

	CXTPDialogBaseParentWrapper(LPCTSTR lpszTemplateName, CWnd* pParentWnd)
		: CXTPResizeDHtmlDialog(lpszTemplateName, 0, pParentWnd)
	{
		ASSERT(!"This constructor is added for interface compatibility only and must never be "
				"called for a DHTML dialog");
	}

	CXTPDialogBaseParentWrapper(UINT nIDTemplate, UINT nHtmlResID, CWnd* pParentWnd)
		: CXTPResizeDHtmlDialog(nIDTemplate, nHtmlResID, pParentWnd)
	{
	}

	CXTPDialogBaseParentWrapper(LPCTSTR lpszTemplateName, LPCTSTR szHtmlResID, CWnd* pParentWnd)
		: CXTPResizeDHtmlDialog(lpszTemplateName, szHtmlResID, pParentWnd)
	{
	}
};

#		endif // _XTP_INCLUDE_CONTROLS

#	endif // (_MSC_VER > 1200)

//}}AFX_CODEJOCK_PRIVATE

//===========================================================================
// Summary:
//     CXTPDialogBase is a TBase derived class. It represents the parent
//     class for a  CXTPDialog class .
//===========================================================================
template<class TBase>
class CXTPDialogBase : public CXTPDialogBaseParentWrapper<TBase>
{
public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPDialog object
	// Parameters:
	//     nIDTemplate - Contains the ID number of a dialog-template resource
	//     lpszTemplateName - Contains a null-terminated string that is
	//                        the name of a dialog-template resource
	//     pParentWnd  - Points to the parent of the DialogBase control
	//     nHtmlResID - HTML page resource ID for DHTML dialogs.
	//     szHtmlResID - HTML page resource ID for DHTML dialogs.
	//-----------------------------------------------------------------------
	CXTPDialogBase()
	{
		m_pCommandBars = 0;
	}

	//<combine CXTPDialogBase::CXTPDialogBase>
	CXTPDialogBase(UINT nIDTemplate, CWnd* pParentWnd = NULL)
		: CXTPDialogBaseParentWrapper<TBase>(nIDTemplate, pParentWnd)
	{
		m_pCommandBars = 0;
	}

	//<combine CXTPDialogBase::CXTPDialogBase>
	CXTPDialogBase(LPCTSTR lpszTemplateName, CWnd* pParentWnd = NULL)
		: CXTPDialogBaseParentWrapper<TBase>(lpszTemplateName, pParentWnd)
	{
		m_pCommandBars = 0;
	}

#	if (_MSC_VER > 1200)
	//<combine CXTPDialogBase::CXTPDialogBase>
	CXTPDialogBase(UINT nIDTemplate, UINT nHtmlResID, CWnd* pParentWnd = NULL)
		: CXTPDialogBaseParentWrapper<TBase>(nIDTemplate, nHtmlResID, pParentWnd)
	{
		m_pCommandBars = 0;
	}

	//<combine CXTPDialogBase::CXTPDialogBase>
	CXTPDialogBase(LPCTSTR lpszTemplateName, LPCTSTR szHtmlResID, CWnd* pParentWnd = NULL)
		: CXTPDialogBaseParentWrapper<TBase>(lpszTemplateName, szHtmlResID, pParentWnd)
	{
		m_pCommandBars = 0;
	}
#	endif

	//-----------------------------------------------------------------------
	// Summary:
	//     Destroys a CXTPDialogBase object, handles cleanup and deallocation
	//-----------------------------------------------------------------------
	~CXTPDialogBase()
	{
		CMDTARGET_RELEASE(m_pCommandBars);
	}

	//-----------------------------------------------------------------------
	// Summary:
	//     Creates command bars.
	// Parameters:
	//     pCommandBarsClass - Custom runtime class of CommandBars. It can be used if you want to
	//     override
	//                         some methods of CXTPCommandBars class.
	// Returns:
	//     Nonzero if successful; otherwise 0.
	//-----------------------------------------------------------------------
	virtual BOOL InitCommandBars(CRuntimeClass* pCommandBarsClass = RUNTIME_CLASS(CXTPCommandBars))
	{
		CMDTARGET_RELEASE(m_pCommandBars);

		ASSERT(NULL != pCommandBarsClass);
		ASSERT(pCommandBarsClass->IsDerivedFrom(RUNTIME_CLASS(CXTPCommandBars)));

		m_pCommandBars = (CXTPCommandBars*)pCommandBarsClass->CreateObject();
		ASSERT(m_pCommandBars);

		m_pCommandBars->SetSite(this);
		m_pCommandBars->EnableDocking();

		return TRUE;
	}

	//-----------------------------------------------------------------------
	// Summary:
	//     This member function will re-dock a toolbar specified by 'pBarToDock'
	//     to the right of a newly docked toolbar specified by 'pBarOnLeft'.
	// Parameters:
	//     pBarToDock - A CXTPToolBar pointer to the toolbar to be docked.
	//     pBarOnLeft - A CXTPToolBar pointer to the already docked toolbar.
	//-----------------------------------------------------------------------
	void DockRightOf(CXTPToolBar* pBarToDock, CXTPToolBar* pBarOnLeft)
	{
		ASSERT(NULL != pBarOnLeft);

		RepositionBars(AFX_IDW_CONTROLBAR_FIRST, AFX_IDW_CONTROLBAR_LAST, AFX_IDW_PANE_FIRST);

		CXTPWindowRect rcBar(pBarOnLeft);

		if (IsVerticalPosition(pBarOnLeft->GetPosition()))
			rcBar.OffsetRect(0, rcBar.Height());
		else
			rcBar.OffsetRect(rcBar.Width(), 0);

		GetCommandBars()->DockCommandBar(pBarToDock, rcBar, pBarOnLeft->GetDockBar());
	}

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this function to save the state information to the registry
	//     or .INI file.
	// Parameters:
	//     lpszProfileName - Points to a null-terminated string that specifies
	//                       the name of a section in the initialization file
	//                       or a key in the Windows registry where state
	//                       information is stored.
	//-----------------------------------------------------------------------
	virtual void SaveCommandBars(LPCTSTR lpszProfileName)
	{
		if (m_pCommandBars)
		{
			m_pCommandBars->SaveOptions(lpszProfileName);
			m_pCommandBars->SaveBarState(lpszProfileName);
			m_pCommandBars->GetShortcutManager()->SaveShortcuts(lpszProfileName);
		}
	}

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this function to retrieve state information from the registry
	//     or .INI file.
	// Parameters:
	//     lpszProfileName - Points to a null-terminated string that specifies
	//                       the name of a section in the initialization file
	//                       or a key in the Windows registry where state
	//                       information is stored.
	//     bSilent         - TRUE to disable user notifications when command bars are restore to
	//     their original state.
	//-----------------------------------------------------------------------
	virtual void LoadCommandBars(LPCTSTR lpszProfileName, BOOL bSilent = FALSE)
	{
		if (m_pCommandBars)
		{
			m_pCommandBars->LoadOptions(lpszProfileName);
			m_pCommandBars->LoadBarState(lpszProfileName, bSilent);
			m_pCommandBars->GetShortcutManager()->LoadShortcuts(lpszProfileName);
		}
	}

	//----------------------------------------------------------------------
	// Summary:
	//     Call this member to retrieve a pointer to the CommandBars object.
	// Returns:
	//     Retrieves Command Bars object.
	//----------------------------------------------------------------------
	CXTPCommandBars* GetCommandBars() const
	{
		return m_pCommandBars;
	}

	//{{AFX_CODEJOCK_PRIVATE
protected:
	virtual BOOL PreTranslateMessage(MSG* pMsg)
	{
		ASSERT(NULL != pMsg);

		if ((pMsg->message >= WM_KEYFIRST && pMsg->message <= WM_KEYLAST)
			&& (pMsg->wParam != VK_RETURN && pMsg->wParam != VK_TAB && pMsg->wParam != VK_ESCAPE))
		{
			CWnd* pWnd = CWnd::GetFocus();
			if (pWnd && pWnd->IsKindOf(RUNTIME_CLASS(CXTPCommandBarEditCtrl)))
				return FALSE;
		}

		if (m_pCommandBars && m_pCommandBars->PreTranslateFrameMessage(pMsg))
			return TRUE;

		if (TBase::PreTranslateMessage(pMsg))
			return TRUE;

		return FALSE;
	}

	virtual BOOL OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult)
	{
		if (m_pCommandBars && m_pCommandBars->OnFrameWndMsg(message, wParam, lParam, pResult))
			return TRUE;

		return TBase::OnWndMsg(message, wParam, lParam, pResult);
	}

	//}}AFX_CODEJOCK_PRIVATE

private:
	CXTPCommandBars* m_pCommandBars;
};

//===========================================================================
// Summary:
//     CXTPDialog is a CXTPDialogBase derived class. Use this class in your dialog base application.
//===========================================================================
class CXTPDialog : public CXTPDialogBase<CDialog>
{
public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPDialog object
	// Parameters:
	//     nIDTemplate - Contains the ID number of a dialog-template resource
	//     lpszTemplateName - Contains a null-terminated string that is
	//                        the name of a dialog-template resource
	//     pParentWnd  - Points to the parent of the Dialog control
	//-----------------------------------------------------------------------
	CXTPDialog()
	{
	}
	CXTPDialog(UINT nIDTemplate, CWnd* pParentWnd = NULL)
		: CXTPDialogBase<CDialog>(nIDTemplate, pParentWnd)
	{
	} //<combine CXTPDialog::CXTPDialog>
	CXTPDialog(LPCTSTR lpszTemplateName, CWnd* pParentWnd = NULL)
		: CXTPDialogBase<CDialog>(lpszTemplateName, pParentWnd)
	{
	} //<combine CXTPDialog::CXTPDialog>

	//-----------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPDialog object
	//-----------------------------------------------------------------------

	//{{AFX_CODEJOCK_PRIVATE

	// deprecated
	void SetMenuBar(CXTPMenuBar* /*pMenuBar*/)
	{
		XTP_ERROR_MSG("WARNING: CXTPDialog::SetMenuBar(...) has been deprecated, use\n"
					  "CXTPCommandBars::SetMenu(...) instead, for example:\n\n"
					  "VERIFY(InitCommandBars());\n\n"
					  "CXTPCommandBars* pCommandBars = GetCommandBars();\n"
					  "pCommandBars->SetMenu(_T(\"Menu Bar\"), IDR_MENU);");
	}

	//}}AFX_CODEJOCK_PRIVATE
};

#	if (_MSC_VER > 1200)
//===========================================================================
// Summary:
//     CXTPDHtmlDialog is a CXTPDialogBase derived class. Use this class in your html dialog base
//     application.
//===========================================================================
class CXTPDHtmlDialog : public CXTPDialogBase<CDHtmlDialog>
{
public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPDHtmlDialog object
	// Parameters:
	//     nHtmlResID - Contains the ID number of a dialog-template resource
	//     szHtmlResID - Contains a null-terminated string that is
	//                        the name of a dialog-template resource
	//     pParentWnd  - Points to the parent of the Dialog control
	//-----------------------------------------------------------------------
	CXTPDHtmlDialog()
	{
	}
	CXTPDHtmlDialog(UINT nIDTemplate, UINT nHtmlResID = 0, CWnd* pParentWnd = NULL)
		: CXTPDialogBase<CDHtmlDialog>(nIDTemplate, nHtmlResID, pParentWnd)
	{
	} //<combine CXTPDHtmlDialog::CXTPDHtmlDialog>
	CXTPDHtmlDialog(LPCTSTR lpszTemplateName, LPCTSTR szHtmlResID, CWnd* pParentWnd = NULL)
		: CXTPDialogBase<CDHtmlDialog>(lpszTemplateName, szHtmlResID, pParentWnd)
	{
	} //<combine CXTPDHtmlDialog::CXTPDHtmlDialog>

	//-----------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPDHtmlDialog object
	//-----------------------------------------------------------------------

	//{{AFX_CODEJOCK_PRIVATE

	// deprecated
	void SetMenuBar(CXTPMenuBar* /*pMenuBar*/)
	{
		XTP_ERROR_MSG("WARNING: CXTPDHtmlDialog::SetMenuBar(...) has been deprecated, use\n"
					  "CXTPCommandBars::SetMenu(...) instead, for example:\n\n"
					  "VERIFY(InitCommandBars());\n\n"
					  "CXTPCommandBars* pCommandBars = GetCommandBars();\n"
					  "pCommandBars->SetMenu(_T(\"Menu Bar\"), IDR_MENU);");
	}

	//}}AFX_CODEJOCK_PRIVATE
};
#	endif

#	include "Common/Base/Diagnostic/XTPEnableNoisyWarnings.h"
#endif // #if !defined(__XTPDIALOGBASE_H__)
