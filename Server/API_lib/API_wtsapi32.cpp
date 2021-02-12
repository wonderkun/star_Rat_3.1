#include <windows.h>
#include "API_wtsapi32.h"
#include "GetProcAddressEx.h"




char EgaCa[] = {'W','T','S','Q','u','e','r','y','S','e','s','s','i','o','n','I','n','f','o','r','m','a','t','i','o','n','A','\0'};
BOOL
WINAPI
API_WTSQuerySessionInformationA(
    IN HANDLE hServer,
    IN DWORD SessionId,
    IN WTS_INFO_CLASS WTSInfoClass,
    OUT LPSTR * ppBuffer,
    OUT DWORD * pBytesReturned
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(HANDLE,DWORD,WTS_INFO_CLASS,LPSTR *,DWORD *);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"wtsapi32.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,EgaCa); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(hServer,SessionId,WTSInfoClass,ppBuffer,pBytesReturned);//调用函数
	}
	return ret;
}


char YDDPi[] = {'W','T','S','F','r','e','e','M','e','m','o','r','y','\0'};
VOID
WINAPI
API_WTSFreeMemory(
    IN PVOID pMemory
    )
{
	typedef VOID (WINAPI *lpAddFun)(PVOID);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"wtsapi32.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,YDDPi); //函数名字
	if (addFun != NULL)
	{
		addFun(pMemory);//调用函数
	}
	return;
}

BOOL
WINAPI
API_WTSQueryUserToken(
    ULONG SessionId, 
    PHANDLE phToken
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(ULONG,PHANDLE);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"wtsapi32.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"WTSQueryUserToken"); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(SessionId,phToken);//调用函数
	}
	return ret;
}