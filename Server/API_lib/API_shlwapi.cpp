#include <windows.h>
#include "API_shlwapi.h"
#include "GetProcAddressEx.h"



DWORD API_SHDeleteKeyA(HKEY hkey, LPCSTR pszSubKey)
{
	DWORD ret = 0;
	typedef DWORD (WINAPI *lpAddFun)(HKEY,LPCSTR);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"shlwapi.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"SHDeleteKeyA"); //��������
	if (addFun != NULL)
	{
		ret = addFun(hkey,pszSubKey);//���ú���
	}
	return ret;
}

void API_PathStripPathW(LPWSTR pszPath)
{
	typedef void (WINAPI *lpAddFun)(LPWSTR);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"shlwapi.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"PathStripPathW"); //��������
	if (addFun != NULL)
	{
		addFun(pszPath);//���ú���
	}
	return;
}

void API_PathStripPathA(LPSTR pszPath)
{
	typedef void (WINAPI *lpAddFun)(LPSTR);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"shlwapi.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"PathStripPathA"); //��������
	if (addFun != NULL)
	{
		addFun(pszPath);//���ú���
	}
	return;
}