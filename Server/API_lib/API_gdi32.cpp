#include <windows.h>
#include "API_gdi32.h"
#include "GetProcAddressEx.h"


HBITMAP API_CreateDIBSection(
  HDC hdc,                 // handle to DC
  CONST BITMAPINFO *pbmi,  // bitmap data
  UINT iUsage,             // data type indicator
  VOID **ppvBits,          // bit values
  HANDLE hSection,         // handle to file mapping object
  DWORD dwOffset           // offset to bitmap bit values
  )
{
	HBITMAP ret = FALSE;
	typedef HBITMAP (WINAPI *lpAddFun)(HDC,CONST BITMAPINFO *,UINT,VOID **,HANDLE,DWORD);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"gdi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"CreateDIBSection"); //��������
	if (addFun != NULL)
	{
		ret = addFun(hdc,pbmi,iUsage,ppvBits,hSection,dwOffset);//���ú���
	}
	return ret;
}

HGDIOBJ API_SelectObject(
  HDC hdc,          // handle to DC
  HGDIOBJ hgdiobj   // handle to object
)
{
	HGDIOBJ ret = FALSE;
	typedef HGDIOBJ (WINAPI *lpAddFun)(HDC,HGDIOBJ);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"gdi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"SelectObject"); //��������
	if (addFun != NULL)
	{
		ret = addFun(hdc,hgdiobj);//���ú���
	}
	return ret;
}

BOOL API_BitBlt(
  HDC hdcDest, // handle to destination DC
  int nXDest,  // x-coord of destination upper-left corner
  int nYDest,  // y-coord of destination upper-left corner
  int nWidth,  // width of destination rectangle
  int nHeight, // height of destination rectangle
  HDC hdcSrc,  // handle to source DC
  int nXSrc,   // x-coordinate of source upper-left corner
  int nYSrc,   // y-coordinate of source upper-left corner
  DWORD dwRop  // raster operation code
)
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(HDC,int,int,int,int,HDC,int,int,DWORD);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"gdi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"BitBlt"); //��������
	if (addFun != NULL)
	{
		ret = addFun(hdcDest,nXDest,nYDest,nWidth,nHeight,hdcSrc,nXSrc,nYSrc,dwRop);//���ú���
	}
	return ret;
}

HBITMAP API_CreateCompatibleBitmap(
  HDC hdc,        // handle to DC
  int nWidth,     // width of bitmap, in pixels
  int nHeight     // height of bitmap, in pixels
)
{
	HBITMAP ret = FALSE;
	typedef HBITMAP (WINAPI *lpAddFun)(HDC,int,int);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"gdi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"CreateCompatibleBitmap"); //��������
	if (addFun != NULL)
	{
		ret = addFun(hdc,nWidth,nHeight);//���ú���
	}
	return ret;
}

int API_GetDIBits(
  HDC hdc,           // handle to DC
  HBITMAP hbmp,      // handle to bitmap
  UINT uStartScan,   // first scan line to set
  UINT cScanLines,   // number of scan lines to copy
  LPVOID lpvBits,    // array for bitmap bits
  LPBITMAPINFO lpbi, // bitmap data buffer
  UINT uUsage        // RGB or palette index
)
{
	int ret = FALSE;
	typedef int (WINAPI *lpAddFun)(HDC,HBITMAP,UINT,UINT,LPVOID,LPBITMAPINFO,UINT);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"gdi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"GetDIBits"); //��������
	if (addFun != NULL)
	{
		ret = addFun(hdc,hbmp,uStartScan,cScanLines,lpvBits,lpbi,uUsage);//���ú���
	}
	return ret;
}

BOOL API_DeleteDC(
  HDC hdc   // handle to DC
)
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(HDC);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"gdi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"DeleteDC"); //��������
	if (addFun != NULL)
	{
		ret = addFun(hdc);//���ú���
	}
	return ret;
}

BOOL API_DeleteObject(
  HGDIOBJ hObject   // handle to graphic object
)
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(HGDIOBJ);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"gdi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"DeleteObject"); //��������
	if (addFun != NULL)
	{
		ret = addFun(hObject);//���ú���
	}
	return ret;
}

HDC API_CreateCompatibleDC(
  HDC hdc   // handle to DC
)
{
	HDC ret = FALSE;
	typedef HDC (WINAPI *lpAddFun)(HDC);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"gdi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"CreateCompatibleDC"); //��������
	if (addFun != NULL)
	{
		ret = addFun(hdc);//���ú���
	}
	return ret;
}