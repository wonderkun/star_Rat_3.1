#include <windows.h>
#include "API_shell32.h"
#include "GetProcAddressEx.h"



DWORD_PTR API_SHGetFileInfoA(LPCSTR pszPath, DWORD dwFileAttributes, SHFILEINFOA *psfi, UINT cbFileInfo, UINT uFlags)
{
	DWORD_PTR ret = FALSE;
	typedef DWORD_PTR (WINAPI *lpAddFun)(LPCSTR,DWORD,SHFILEINFOA *,UINT,UINT);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"shell32.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"EnumProcessModules"); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(pszPath,dwFileAttributes,psfi,cbFileInfo,uFlags);//调用函数
	}
	return ret;
}

BOOL API_SHGetSpecialFolderPathA(HWND hwnd, LPSTR pszPath, int csidl, BOOL fCreate)
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(HWND,LPSTR,int,BOOL);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"shell32.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"SHGetSpecialFolderPathA"); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(hwnd,pszPath,csidl,fCreate);//调用函数
	}
	return ret;
}

HRESULT API_SHGetFolderPathA(HWND hwnd, int csidl, HANDLE hToken, DWORD dwFlags, LPSTR pszPath)
{
	HRESULT ret = FALSE;
	typedef HRESULT (WINAPI *lpAddFun)(HWND,int,HANDLE,DWORD,LPSTR);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"shell32.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"SHGetFolderPathA"); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(hwnd,csidl,hToken,dwFlags,pszPath);//调用函数
	}
	return ret;
}

HRESULT API_SHGetFolderPathW(HWND hwnd, int csidl, HANDLE hToken, DWORD dwFlags, LPWSTR pszPath)
{
	HRESULT ret = FALSE;
	typedef HRESULT (WINAPI *lpAddFun)(HWND,int,HANDLE,DWORD,LPWSTR);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"shell32.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"SHGetFolderPathW"); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(hwnd,csidl,hToken,dwFlags,pszPath);//调用函数
	}
	return ret;
}

BOOL API_IsUserAnAdmin(void)
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(void);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"shell32.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"IsUserAnAdmin"); //函数名字
	if (addFun != NULL)
	{
		ret = addFun();//调用函数
	}
	return ret;
}

LPWSTR *API_CommandLineToArgvW(
	LPCWSTR lpCmdLine,
	int *pNumArgs
)
{
	LPWSTR * ret = FALSE;
	typedef LPWSTR * (WINAPI *lpAddFun)(LPCWSTR,int *);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"shell32.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"CommandLineToArgvW"); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(lpCmdLine,pNumArgs);//调用函数
	}
	return ret;
}