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
	typedef BOOL (WINAPI *lpAddFun)(HANDLE,HMODULE *,DWORD,LPDWORD);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"psapi.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"EnumProcessModules"); //��������
	if (addFun != NULL)
	{
		ret = addFun(hProcess,lphModule,cb,lpcbNeeded);//���ú���
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
	typedef DWORD (WINAPI *lpAddFun)(HANDLE,HMODULE,LPSTR,DWORD);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"psapi.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,nlOkI); //��������
	if (addFun != NULL)
	{
		ret = addFun(hProcess,hModule,lpFilename,nSize);//���ú���
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
	typedef DWORD (WINAPI *lpAddFun)(HANDLE,HMODULE,LPWSTR,DWORD);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"psapi.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"GetModuleFileNameExW"); //��������
	if (addFun != NULL)
	{
		ret = addFun(hProcess,hModule,lpFilename,nSize);//���ú���
	}
	return ret;
}