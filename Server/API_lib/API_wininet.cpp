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
	typedef HINTERNET (WINAPI *lpAddFun)(LPCSTR,DWORD,LPCSTR OPTIONAL,LPCSTR OPTIONAL,DWORD);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"wininet.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"InternetOpenA"); //��������
	if (addFun != NULL)
	{
		ret = addFun(lpszAgent,dwAccessType,lpszProxy,lpszProxyBypass,dwFlags);//���ú���
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
	typedef HINTERNET (WINAPI *lpAddFun)(LPCWSTR,DWORD,LPCWSTR OPTIONAL,LPCWSTR OPTIONAL,DWORD);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"wininet.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"InternetOpenW"); //��������
	if (addFun != NULL)
	{
		ret = addFun(lpszAgent,dwAccessType,lpszProxy,lpszProxyBypass,dwFlags);//���ú���
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
	typedef HINTERNET (WINAPI *lpAddFun)(HINTERNET,LPCSTR,LPCSTR OPTIONAL,DWORD,DWORD,DWORD_PTR);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"wininet.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"InternetOpenUrlA"); //��������
	if (addFun != NULL)
	{
		ret = addFun(hInternet,lpszUrl,lpszHeaders,dwHeadersLength,dwFlags,dwContext);//���ú���
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
	typedef HINTERNET (WINAPI *lpAddFun)(HINTERNET,LPCWSTR,LPCWSTR OPTIONAL,DWORD,DWORD,DWORD_PTR);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"wininet.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"InternetOpenUrlW"); //��������
	if (addFun != NULL)
	{
		ret = addFun(hInternet,lpszUrl,lpszHeaders,dwHeadersLength,dwFlags,dwContext);//���ú���
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
	typedef BOOL (WINAPI *lpAddFun)(HINTERNET,LPVOID,DWORD,LPDWORD);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"wininet.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"InternetReadFile"); //��������
	if (addFun != NULL)
	{
		ret = addFun(hFile,lpBuffer,dwNumberOfBytesToRead,lpdwNumberOfBytesRead);//���ú���
	}
	return ret;
}

BOOL API_InternetCloseHandle(
    IN HINTERNET hInternet
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(HINTERNET);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"wininet.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"InternetCloseHandle"); //��������
	if (addFun != NULL)
	{
		ret = addFun(hInternet);//���ú���
	}
	return ret;
}

BOOL API_InternetGetConnectedState(
    OUT LPDWORD  lpdwFlags,
    IN DWORD    dwReserved)
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(LPDWORD,DWORD);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"wininet.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"InternetGetConnectedState"); //��������
	if (addFun != NULL)
	{
		ret = addFun(lpdwFlags,dwReserved);//���ú���
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
	typedef BOOL (WINAPI *lpAddFun)(HINTERNET OPTIONAL,DWORD,LPVOID,DWORD);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"wininet.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"InternetSetOptionA"); //��������
	if (addFun != NULL)
	{
		ret = addFun(hInternet,dwOption,lpBuffer,dwBufferLength);//���ú���
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
	typedef BOOL (WINAPI *lpAddFun)(HINTERNET OPTIONAL,DWORD,LPVOID,DWORD);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"wininet.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"InternetSetOptionW"); //��������
	if (addFun != NULL)
	{
		ret = addFun(hInternet,dwOption,lpBuffer,dwBufferLength);//���ú���
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
	typedef BOOL (WINAPI *lpAddFun)(HINTERNET,DWORD,LPVOID OPTIONAL,LPDWORD,LPDWORD OPTIONAL);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"wininet.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"HttpQueryInfoA"); //��������
	if (addFun != NULL)
	{
		ret = addFun(hRequest,dwInfoLevel,lpBuffer,lpdwBufferLength,lpdwIndex);//���ú���
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
	typedef BOOL (WINAPI *lpAddFun)(HINTERNET,DWORD,LPVOID OPTIONAL,LPDWORD,LPDWORD OPTIONAL);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"wininet.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"HttpQueryInfoW"); //��������
	if (addFun != NULL)
	{
		ret = addFun(hRequest,dwInfoLevel,lpBuffer,lpdwBufferLength,lpdwIndex);//���ú���
	}
	return ret;
}