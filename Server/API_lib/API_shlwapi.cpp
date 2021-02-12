#include <windows.h>
#include "API_shlwapi.h"
#include "GetProcAddressEx.h"



DWORD API_SHDeleteKeyA(HKEY hkey, LPCSTR pszSubKey)
{
	DWORD ret = 0;
	typedef DWORD (WINAPI *lpAddFun)(HKEY,LPCSTR);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"shlwapi.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"SHDeleteKeyA"); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(hkey,pszSubKey);//调用函数
	}
	return ret;
}

void API_PathStripPathW(LPWSTR pszPath)
{
	typedef void (WINAPI *lpAddFun)(LPWSTR);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"shlwapi.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"PathStripPathW"); //函数名字
	if (addFun != NULL)
	{
		addFun(pszPath);//调用函数
	}
	return;
}

void API_PathStripPathA(LPSTR pszPath)
{
	typedef void (WINAPI *lpAddFun)(LPSTR);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"shlwapi.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"PathStripPathA"); //函数名字
	if (addFun != NULL)
	{
		addFun(pszPath);//调用函数
	}
	return;
}