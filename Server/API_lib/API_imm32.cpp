#include <windows.h>
#include "API_imm32.h"
#include "GetProcAddressEx.h"




char BADcA[] = {'I','m','m','G','e','t','C','o','n','t','e','x','t','\0'};
HIMC WINAPI API_ImmGetContext(IN HWND hWnd)
{
	HIMC ret = FALSE;
	typedef HIMC (WINAPI *lpAddFun)(HWND);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"imm32.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,BADcA); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(hWnd);//调用函数
	}
	return ret;
}


char YliJy[] = {'I','m','m','G','e','t','C','o','m','p','o','s','i','t','i','o','n','S','t','r','i','n','g','A','\0'};
LONG  WINAPI API_ImmGetCompositionStringA(IN HIMC hIMC, IN DWORD dwIndex, OUT LPVOID lpBuf, IN DWORD dwBufLen)
{
	LONG ret = FALSE;
	typedef LONG (WINAPI *lpAddFun)(HIMC,DWORD,LPVOID,DWORD);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"imm32.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,YliJy); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(hIMC,dwIndex,lpBuf,dwBufLen);//调用函数
	}
	return ret;
}


char oayEF[] = {'I','m','m','R','e','l','e','a','s','e','C','o','n','t','e','x','t','\0'};
BOOL WINAPI API_ImmReleaseContext(IN HWND hWnd, IN HIMC hIMC)
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(HWND,HIMC);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"imm32.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,oayEF); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(hWnd,hIMC);//调用函数
	}
	return ret;
}