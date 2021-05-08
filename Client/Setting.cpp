// Settings.cpp : implementation file
//

#include "pcl.h"
#include "Client.h"
#include "Setting.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CMainFrame	*g_pFrame;
extern CIOCPServer	*m_iocpServer;
/////////////////////////////////////////////////////////////////////////////
// CSetting dialog


CSetting::CSetting(CWnd* pParent /*=NULL*/)
	: CDialog(CSetting::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSetting)
	m_max_connections = ((CClientApp *)AfxGetApp())->m_IniFile.GetInt("Settings", "MaxConnection", 8000);
	m_connect_auto =((CClientApp *)AfxGetApp())->m_IniFile.GetInt("Settings", "MaxConnectionAuto", 0);
	m_bIsDisablePopTips =  ((CClientApp *)AfxGetApp())->m_IniFile.GetInt("Settings", "PopTips", false);
	m_listen_port = ((CClientApp *)AfxGetApp())->m_IniFile.GetInt("Settings", "ListenPort", 8080);
	//}}AFX_DATA_INIT
}

void CSetting::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSetting)
	DDX_Control(pDX, IDC_SHOWTIPS, m_showtips);
	DDX_Control(pDX, IDC_LISTEN_PORT, m_listen_port_XTP);
	DDX_Control(pDX, IDC_DISABLE_POPTIPS, m_disable_poptips_XTP);
	DDX_Control(pDX, IDC_CONNECT_MAX, m_connect_max_XTP);
	DDX_Control(pDX, IDC_CONNECT_AUTO, m_connect_auto_XTP);
	DDX_Text(pDX, IDC_CONNECT_MAX, m_max_connections);
	DDV_MinMaxUInt(pDX, m_max_connections, 1, 10000);
	DDX_Check(pDX, IDC_CONNECT_AUTO, m_connect_auto);
	DDX_Check(pDX, IDC_DISABLE_POPTIPS, m_bIsDisablePopTips);
	DDX_Text(pDX, IDC_LISTEN_PORT, m_listen_port);
	DDV_MinMaxUInt(pDX, m_listen_port, 1, 65535);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSetting, CDialog)
	//{{AFX_MSG_MAP(CSetting)
	ON_BN_CLICKED(IDC_APPLY, OnApply)
	ON_BN_CLICKED(IDC_DISABLE_POPTIPS, OnDisablePoptips)
	ON_BN_CLICKED(IDC_CONNECT_AUTO, OnConnectAuto)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetting message handlers

void CSetting::OnApply() 
{
	// TODO: Add your control notification handler code here
	int prev_port = m_listen_port;
	int prev_max_connections = m_max_connections;
	
	UpdateData(TRUE);
	
	if (prev_max_connections != m_max_connections)
	{
		if (m_connect_auto)
			InterlockedExchange((LPLONG)&m_iocpServer->m_nMaxConnections, 8000);
		else
			InterlockedExchange((LPLONG)&m_iocpServer->m_nMaxConnections, m_max_connections);
	}
	
	if (prev_port != m_listen_port)
		g_pFrame->Activate(m_listen_port, m_iocpServer->m_nMaxConnections);

	((CClientApp *)AfxGetApp())->m_IniFile.SetInt("Settings", "ListenPort", m_listen_port);
	((CClientApp *)AfxGetApp())->m_IniFile.SetInt("Settings", "MaxConnection", m_max_connections);
	((CClientApp *)AfxGetApp())->m_IniFile.SetInt("Settings", "MaxConnectionAuto", m_connect_auto);
	SetDlgItemText(IDC_SHOWTIPS, "�ѱ�������");
// 	Sleep(500);
// 	SetDlgItemText(IDC_SHOWTIPS, "");
}

void CSetting::OnDisablePoptips() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	((CClientApp *)AfxGetApp())->m_IniFile.SetInt("Settings", "PopTips", m_bIsDisablePopTips);
	((CClientApp *)AfxGetApp())->m_bIsDisablePopTips = m_bIsDisablePopTips;
	if ( ((CButton *)GetDlgItem(IDC_DISABLE_POPTIPS))->GetCheck() == TRUE )
	{
		SetDlgItemText(IDC_SHOWTIPS, "�ѹر�����������ʾ");
// 		Sleep(500);
// 		SetDlgItemText(IDC_SHOWTIPS, "");
	}
	else
	{
		SetDlgItemText(IDC_SHOWTIPS, "�ѿ�������������ʾ");
// 		Sleep(500);
// 		SetDlgItemText(IDC_SHOWTIPS, "");
	}
}

void CSetting::OnConnectAuto() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	GetDlgItem(IDC_CONNECT_MAX)->EnableWindow(!m_connect_auto);
	m_connect_auto = ((CClientApp *)AfxGetApp())->m_IniFile.SetInt("Settings", "MaxConnectionAuto", m_connect_auto);
	if ( ((CButton *)GetDlgItem(IDC_CONNECT_AUTO))->GetCheck() == TRUE )
	{
		SetDlgItemText(IDC_SHOWTIPS, "������������");
// 		Sleep(500);
// 		SetDlgItemText(IDC_SHOWTIPS, "");
	}
	else
	{
		SetDlgItemText(IDC_SHOWTIPS, "�����������������Զ���");
// 		Sleep(500);
// 		SetDlgItemText(IDC_SHOWTIPS, "");
	}
}

BOOL CSetting::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
//	((CClientApp *)AfxGetApp())->m_IniFile.SetInt("Settings", "MaxConnectionAuto", m_connect_auto);
	if (m_connect_auto==TRUE)
		GetDlgItem(IDC_CONNECT_MAX)->EnableWindow(FALSE);
	else
		GetDlgItem(IDC_CONNECT_MAX)->EnableWindow(TRUE);

// 	((CClientApp *)AfxGetApp())->m_IniFile.GetInt("Settings", "Alarm", m_useautio);
	
	m_listen_port_XTP.SetTheme(xtpControlThemeOfficeXP);
	m_connect_max_XTP.SetTheme(xtpControlThemeOfficeXP);
	m_disable_poptips_XTP.SetTheme(xtpControlThemeOffice2003);
	m_connect_auto_XTP.SetTheme(xtpControlThemeOffice2003);
	
	m_listen_port_XTP.SetFlatStyle(TRUE);
	m_connect_max_XTP.SetFlatStyle(TRUE);
	m_disable_poptips_XTP.SetFlatStyle(TRUE);
	m_connect_auto_XTP.SetFlatStyle(TRUE);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
