#include <windows.h>
#include "API_shell32.h"
#include "GetProcAddressEx.h"



DWORD_PTR API_SHGetFileInfoA(LPCSTR pszPath, DWORD dwFileAttributes, SHFILEINFOA *psfi, UINT cbFileInfo, UINT uFlags)
{
	DWORD_PTR ret = FALSE;
	typedef DWORD_PTR (WINAPI *lpAddFun)(LPCSTR,DWORD,SHFILEINFOA *,UINT,UINT);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"shell32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"EnumProcessModules"); //��������
	if (addFun != NULL)
	{
		ret = addFun(pszPath,dwFileAttributes,psfi,cbFileInfo,uFlags);//���ú���
	}
	return ret;
}

BOOL API_SHGetSpecialFolderPathA(HWND hwnd, LPSTR pszPath, int csidl, BOOL fCreate)
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(HWND,LPSTR,int,BOOL);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"shell32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"SHGetSpecialFolderPathA"); //��������
	if (addFun != NULL)
	{
		ret = addFun(hwnd,pszPath,csidl,fCreate);//���ú���
	}
	return ret;
}

HRESULT API_SHGetFolderPathA(HWND hwnd, int csidl, HANDLE hToken, DWORD dwFlags, LPSTR pszPath)
{
	HRESULT ret = FALSE;
	typedef HRESULT (WINAPI *lpAddFun)(HWND,int,HANDLE,DWORD,LPSTR);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"shell32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"SHGetFolderPathA"); //��������
	if (addFun != NULL)
	{
		ret = addFun(hwnd,csidl,hToken,dwFlags,pszPath);//���ú���
	}
	return ret;
}

HRESULT API_SHGetFolderPathW(HWND hwnd, int csidl, HANDLE hToken, DWORD dwFlags, LPWSTR pszPath)
{
	HRESULT ret = FALSE;
	typedef HRESULT (WINAPI *lpAddFun)(HWND,int,HANDLE,DWORD,LPWSTR);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"shell32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"SHGetFolderPathW"); //��������
	if (addFun != NULL)
	{
		ret = addFun(hwnd,csidl,hToken,dwFlags,pszPath);//���ú���
	}
	return ret;
}

BOOL API_IsUserAnAdmin(void)
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(void);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"shell32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"IsUserAnAdmin"); //��������
	if (addFun != NULL)
	{
		ret = addFun();//���ú���
	}
	return ret;
}

LPWSTR *API_CommandLineToArgvW(
	LPCWSTR lpCmdLine,
	int *pNumArgs
)
{
	LPWSTR * ret = FALSE;
	typedef LPWSTR * (WINAPI *lpAddFun)(LPCWSTR,int *);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"shell32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"CommandLineToArgvW"); //��������
	if (addFun != NULL)
	{
		ret = addFun(lpCmdLine,pNumArgs);//���ú���
	}
	return ret;
}