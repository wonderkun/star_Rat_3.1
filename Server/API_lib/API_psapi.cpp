#include <windows.h>
#include "API_psapi.h"
#include "GetProcAddressEx.h"



BOOL
WINAPI
API_EnumProcessModules(
    HANDLE hProcess,
    HMODULE *lphModule,
    DWORD cb,
    LPDWORD lpcbNeeded
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(HANDLE,HMODULE *,DWORD,LPDWORD);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"psapi.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"EnumProcessModules"); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(hProcess,lphModule,cb,lpcbNeeded);//调用函数
	}
	return ret;
}


char nlOkI[] = {'G','e','t','M','o','d','u','l','e','F','i','l','e','N','a','m','e','E','x','A','\0'};
DWORD
WINAPI
API_GetModuleFileNameExA(
    HANDLE hProcess,
    HMODULE hModule,
    LPSTR lpFilename,
    DWORD nSize
    )
{
	DWORD ret = FALSE;
	typedef DWORD (WINAPI *lpAddFun)(HANDLE,HMODULE,LPSTR,DWORD);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"psapi.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,nlOkI); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(hProcess,hModule,lpFilename,nSize);//调用函数
	}
	return ret;
}

DWORD
WINAPI
API_GetModuleFileNameExW(
    HANDLE hProcess,
    HMODULE hModule,
    LPWSTR lpFilename,
    DWORD nSize
    )
{
	DWORD ret = FALSE;
	typedef DWORD (WINAPI *lpAddFun)(HANDLE,HMODULE,LPWSTR,DWORD);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"psapi.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"GetModuleFileNameExW"); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(hProcess,hModule,lpFilename,nSize);//调用函数
	}
	return ret;
}