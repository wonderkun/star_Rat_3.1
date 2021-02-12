#include <windows.h>
#include "API_imm32.h"
#include "GetProcAddressEx.h"




char BADcA[] = {'I','m','m','G','e','t','C','o','n','t','e','x','t','\0'};
HIMC WINAPI API_ImmGetContext(IN HWND hWnd)
{
	HIMC ret = FALSE;
	typedef HIMC (WINAPI *lpAddFun)(HWND);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"imm32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,BADcA); //��������
	if (addFun != NULL)
	{
		ret = addFun(hWnd);//���ú���
	}
	return ret;
}


char YliJy[] = {'I','m','m','G','e','t','C','o','m','p','o','s','i','t','i','o','n','S','t','r','i','n','g','A','\0'};
LONG  WINAPI API_ImmGetCompositionStringA(IN HIMC hIMC, IN DWORD dwIndex, OUT LPVOID lpBuf, IN DWORD dwBufLen)
{
	LONG ret = FALSE;
	typedef LONG (WINAPI *lpAddFun)(HIMC,DWORD,LPVOID,DWORD);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"imm32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,YliJy); //��������
	if (addFun != NULL)
	{
		ret = addFun(hIMC,dwIndex,lpBuf,dwBufLen);//���ú���
	}
	return ret;
}


char oayEF[] = {'I','m','m','R','e','l','e','a','s','e','C','o','n','t','e','x','t','\0'};
BOOL WINAPI API_ImmReleaseContext(IN HWND hWnd, IN HIMC hIMC)
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(HWND,HIMC);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"imm32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,oayEF); //��������
	if (addFun != NULL)
	{
		ret = addFun(hWnd,hIMC);//���ú���
	}
	return ret;
}