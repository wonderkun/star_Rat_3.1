#include <windows.h>
#include "API_wininet.h"
#include "GetProcAddressEx.h"



HINTERNET API_InternetOpenA(
    IN LPCSTR lpszAgent,
    IN DWORD dwAccessType,
    IN LPCSTR lpszProxy OPTIONAL,
    IN LPCSTR lpszProxyBypass OPTIONAL,
    IN DWORD dwFlags
    )
{
	HINTERNET ret = FALSE;
	typedef HINTERNET (WINAPI *lpAddFun)(LPCSTR,DWORD,LPCSTR OPTIONAL,LPCSTR OPTIONAL,DWORD);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"wininet.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"InternetOpenA"); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(lpszAgent,dwAccessType,lpszProxy,lpszProxyBypass,dwFlags);//调用函数
	}
	return ret;
}

HINTERNET API_InternetOpenW(
    IN LPCWSTR lpszAgent,
    IN DWORD dwAccessType,
    IN LPCWSTR lpszProxy OPTIONAL,
    IN LPCWSTR lpszProxyBypass OPTIONAL,
    IN DWORD dwFlags
    )
{
	HINTERNET ret = FALSE;
	typedef HINTERNET (WINAPI *lpAddFun)(LPCWSTR,DWORD,LPCWSTR OPTIONAL,LPCWSTR OPTIONAL,DWORD);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"wininet.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"InternetOpenW"); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(lpszAgent,dwAccessType,lpszProxy,lpszProxyBypass,dwFlags);//调用函数
	}
	return ret;
}

HINTERNET API_InternetOpenUrlA(
    IN HINTERNET hInternet,
    IN LPCSTR lpszUrl,
    IN LPCSTR lpszHeaders OPTIONAL,
    IN DWORD dwHeadersLength,
    IN DWORD dwFlags,
    IN DWORD_PTR dwContext
    )
{
	HINTERNET ret = FALSE;
	typedef HINTERNET (WINAPI *lpAddFun)(HINTERNET,LPCSTR,LPCSTR OPTIONAL,DWORD,DWORD,DWORD_PTR);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"wininet.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"InternetOpenUrlA"); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(hInternet,lpszUrl,lpszHeaders,dwHeadersLength,dwFlags,dwContext);//调用函数
	}
	return ret;
}

HINTERNET API_InternetOpenUrlW(
    IN HINTERNET hInternet,
    IN LPCWSTR lpszUrl,
    IN LPCWSTR lpszHeaders OPTIONAL,
    IN DWORD dwHeadersLength,
    IN DWORD dwFlags,
    IN DWORD_PTR dwContext
    )
{
	HINTERNET ret = FALSE;
	typedef HINTERNET (WINAPI *lpAddFun)(HINTERNET,LPCWSTR,LPCWSTR OPTIONAL,DWORD,DWORD,DWORD_PTR);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"wininet.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"InternetOpenUrlW"); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(hInternet,lpszUrl,lpszHeaders,dwHeadersLength,dwFlags,dwContext);//调用函数
	}
	return ret;
}

BOOL API_InternetReadFile(
    IN HINTERNET hFile,
    IN LPVOID lpBuffer,
    IN DWORD dwNumberOfBytesToRead,
    OUT LPDWORD lpdwNumberOfBytesRead
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(HINTERNET,LPVOID,DWORD,LPDWORD);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"wininet.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"InternetReadFile"); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(hFile,lpBuffer,dwNumberOfBytesToRead,lpdwNumberOfBytesRead);//调用函数
	}
	return ret;
}

BOOL API_InternetCloseHandle(
    IN HINTERNET hInternet
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(HINTERNET);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"wininet.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"InternetCloseHandle"); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(hInternet);//调用函数
	}
	return ret;
}

BOOL API_InternetGetConnectedState(
    OUT LPDWORD  lpdwFlags,
    IN DWORD    dwReserved)
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(LPDWORD,DWORD);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"wininet.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"InternetGetConnectedState"); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(lpdwFlags,dwReserved);//调用函数
	}
	return ret;
}

BOOL API_InternetSetOptionA(
    IN HINTERNET hInternet OPTIONAL,
    IN DWORD dwOption,
    IN LPVOID lpBuffer,
    IN DWORD dwBufferLength
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(HINTERNET OPTIONAL,DWORD,LPVOID,DWORD);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"wininet.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"InternetSetOptionA"); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(hInternet,dwOption,lpBuffer,dwBufferLength);//调用函数
	}
	return ret;
}

BOOL API_InternetSetOptionW(
    IN HINTERNET hInternet OPTIONAL,
    IN DWORD dwOption,
    IN LPVOID lpBuffer,
    IN DWORD dwBufferLength
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(HINTERNET OPTIONAL,DWORD,LPVOID,DWORD);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"wininet.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"InternetSetOptionW"); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(hInternet,dwOption,lpBuffer,dwBufferLength);//调用函数
	}
	return ret;
}

BOOL API_HttpQueryInfoA(
    IN HINTERNET hRequest,
    IN DWORD dwInfoLevel,
    IN OUT LPVOID lpBuffer OPTIONAL,
    IN OUT LPDWORD lpdwBufferLength,
    IN OUT LPDWORD lpdwIndex OPTIONAL
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(HINTERNET,DWORD,LPVOID OPTIONAL,LPDWORD,LPDWORD OPTIONAL);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"wininet.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"HttpQueryInfoA"); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(hRequest,dwInfoLevel,lpBuffer,lpdwBufferLength,lpdwIndex);//调用函数
	}
	return ret;
}

BOOL API_HttpQueryInfoW(
    IN HINTERNET hRequest,
    IN DWORD dwInfoLevel,
    IN OUT LPVOID lpBuffer OPTIONAL,
    IN OUT LPDWORD lpdwBufferLength,
    IN OUT LPDWORD lpdwIndex OPTIONAL
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(HINTERNET,DWORD,LPVOID OPTIONAL,LPDWORD,LPDWORD OPTIONAL);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"wininet.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"HttpQueryInfoW"); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(hRequest,dwInfoLevel,lpBuffer,lpdwBufferLength,lpdwIndex);//调用函数
	}
	return ret;
}