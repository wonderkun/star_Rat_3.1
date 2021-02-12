#include <windows.h>
#include "API_avicap32.h"
#include "GetProcAddressEx.h"



BOOL API_capGetDriverDescriptionA (UINT wDriverIndex,
        LPSTR lpszName, int cbName,
        LPSTR lpszVer, int cbVer)
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(UINT,LPSTR,int,LPSTR,int);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"avicap32.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"capGetDriverDescriptionA"); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(wDriverIndex,lpszName,cbName,lpszVer,cbVer);//调用函数
	}
	return ret;
}

HWND API_capCreateCaptureWindowA (
        LPCSTR lpszWindowName,
        DWORD dwStyle,
        int x, int y, int nWidth, int nHeight,
        HWND hwndParent, int nID)
{
	HWND ret = NULL;
	typedef HWND (WINAPI *lpAddFun)(LPCSTR,DWORD,int,int,int,int,HWND,int);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"avicap32.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"capCreateCaptureWindowA"); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(lpszWindowName,dwStyle,x,y,nWidth,nHeight,hwndParent,nID);//调用函数
	}
	return ret;
}