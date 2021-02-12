#include <windows.h>
#include "API_avicap32.h"
#include "GetProcAddressEx.h"



BOOL API_capGetDriverDescriptionA (UINT wDriverIndex,
        LPSTR lpszName, int cbName,
        LPSTR lpszVer, int cbVer)
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(UINT,LPSTR,int,LPSTR,int);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"avicap32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"capGetDriverDescriptionA"); //��������
	if (addFun != NULL)
	{
		ret = addFun(wDriverIndex,lpszName,cbName,lpszVer,cbVer);//���ú���
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
	typedef HWND (WINAPI *lpAddFun)(LPCSTR,DWORD,int,int,int,int,HWND,int);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"avicap32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"capCreateCaptureWindowA"); //��������
	if (addFun != NULL)
	{
		ret = addFun(lpszWindowName,dwStyle,x,y,nWidth,nHeight,hwndParent,nID);//���ú���
	}
	return ret;
}