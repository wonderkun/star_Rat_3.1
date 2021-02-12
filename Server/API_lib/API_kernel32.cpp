#include <windows.h>
#include <TLHELP32.H>
#include "API_kernel32.h"
#include "GetProcAddressEx.h"



LPWSTR
API_lstrcatW(
			 LPWSTR lpString1,
			 LPCWSTR lpString2
			 )
{
	LPWSTR ret = NULL;
	typedef LPWSTR (WINAPI *lpAddFun)(LPWSTR,LPCWSTR);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
    lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"lstrcatW"); //��������
	if (addFun != NULL)
	{
		ret = addFun(lpString1,lpString2);      //���ú���
	}
	return ret;
}


char gGqny[] = {'l','s','t','r','c','a','t','A','\0'};
LPSTR
WINAPI
API_lstrcatA(
    IN OUT LPSTR lpString1,
    IN LPCSTR lpString2
    )
{
	LPSTR ret = NULL;
	typedef LPSTR (WINAPI *lpAddFun)(LPSTR,LPCSTR);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,gGqny); //��������
	if (addFun != NULL)
	{
		ret = addFun(lpString1,lpString2);      //���ú���
	}
	return ret;
}


char pOnWn[] = {'l','s','t','r','c','p','y','W','\0'};
LPWSTR
WINAPI
API_lstrcpyW(
    OUT LPWSTR lpString1,
    IN LPCWSTR lpString2
    )
{
	LPWSTR ret = NULL;
	typedef LPWSTR (WINAPI *lpAddFun)(LPWSTR,LPCWSTR);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,pOnWn); //��������
	if (addFun != NULL)
	{
		ret = addFun(lpString1,lpString2);      //���ú���
	}
	return ret;
}


char IbLKX[] = {'l','s','t','r','c','p','y','A','\0'};
LPSTR
WINAPI
API_lstrcpyA(
    OUT LPSTR lpString1,
    IN LPCSTR lpString2
    )
{
	LPSTR ret = NULL;
	typedef LPSTR (WINAPI *lpAddFun)(LPSTR,LPCSTR);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,IbLKX); //��������
	if (addFun != NULL)
	{
		ret = addFun(lpString1,lpString2);      //���ú���
	}
	return ret;
}

char nBhku[] = {'G','e','t','S','y','s','t','e','m','D','i','r','e','c','t','o','r','y','A','\0'};
UINT
WINAPI
API_GetSystemDirectoryA(
    OUT LPSTR lpBuffer,
    IN UINT uSize
    )
{
	UINT result = 0;
	typedef UINT (WINAPI *lpAddFun)(LPSTR,UINT);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,nBhku); //��������
	if (addFun != NULL)
	{
		result = addFun(lpBuffer,uSize);      //���ú���
	}
	return result;
}

UINT API_GetSystemDirectoryW(LPWSTR lpBuffer,UINT uSize)
{
	UINT result = 0;
	typedef UINT (WINAPI *lpAddFun)(LPWSTR,UINT);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"GetSystemDirectoryW"); //��������
	if (addFun != NULL)
	{
		result = addFun(lpBuffer,uSize);      //���ú���
	}
	return result;
}


char VPMbo[] = {'G','e','t','T','e','m','p','P','a','t','h','A','\0'};
DWORD
WINAPI
API_GetTempPathA(
    IN DWORD nBufferLength,
    OUT LPSTR lpBuffer
    )
{
	DWORD result = 0;
	typedef UINT (WINAPI *lpAddFun)(DWORD,LPSTR);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,VPMbo); //��������
	if (addFun != NULL)
	{
		result = addFun(nBufferLength,lpBuffer);      //���ú���
	}
	return result;
}

DWORD API_GetTempPathW(DWORD nBufferLength, LPWSTR lpBuffer)
{
	DWORD result = 0;
	typedef UINT (WINAPI *lpAddFun)(DWORD,LPWSTR);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"GetTempPathW"); //��������
	if (addFun != NULL)
	{
		result = addFun(nBufferLength,lpBuffer);      //���ú���
	}
	return result;
}


DWORD API_GetCurrentThreadId(VOID)
{
	DWORD result = 0;
	typedef UINT (WINAPI *lpAddFun)(VOID);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"GetCurrentThreadId"); //��������
	if (addFun != NULL)
	{
		result = addFun();      //���ú���
	}
	return result;
}


char jkCaa[] = {'G','e','t','M','o','d','u','l','e','F','i','l','e','N','a','m','e','A','\0'};
DWORD
WINAPI
API_GetModuleFileNameA(
    IN HMODULE hModule,
    OUT LPSTR lpFilename,
    IN DWORD nSize
    )
{
	DWORD result = 0;
	typedef UINT (WINAPI *lpAddFun)(HMODULE,LPSTR,DWORD);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,jkCaa); //��������
	if (addFun != NULL)
	{
		result = addFun(hModule,lpFilename,nSize);      //���ú���
	}
	return result;
}

DWORD API_GetModuleFileNameW(HMODULE hModule,LPWSTR lpFilename,DWORD nSize)
{
	DWORD result = 0;
	typedef UINT (WINAPI *lpAddFun)(HMODULE,LPWSTR,DWORD);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"GetModuleFileNameW"); //��������
	if (addFun != NULL)
	{
		result = addFun(hModule,lpFilename,nSize);      //���ú���
	}
	return result;
}

HRSRC
API_FindResourceA(
			  HMODULE hModule,
			     LPCSTR lpName,
			     LPCSTR lpType
			  )
{
	HRSRC ret = NULL;
	typedef HRSRC (WINAPI *lpAddFun)(HMODULE,LPCSTR,LPCSTR);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"FindResourceA"); //��������
	if (addFun != NULL)
	{
		ret = addFun(hModule,lpName,lpType);      //���ú���
	}
	return ret;
}

HRSRC
WINAPI
API_FindResourceW(
    IN HMODULE hModule,
    IN LPCWSTR lpName,
    IN LPCWSTR lpType
    )
{
	HRSRC ret = NULL;
	typedef HRSRC (WINAPI *lpAddFun)(HMODULE,LPCWSTR,LPCWSTR);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"FindResourceW"); //��������
	if (addFun != NULL)
	{
		ret = addFun(hModule,lpName,lpType);      //���ú���
	}
	return ret;
}

HGLOBAL
API_LoadResource(
			 HMODULE hModule,
			 HRSRC hResInfo
			 )
{
	HGLOBAL ret = NULL;
	typedef HGLOBAL (WINAPI *lpAddFun)(HMODULE,HRSRC);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"LoadResource"); //��������
	if (addFun != NULL)
	{
		ret = addFun(hModule,hResInfo);      //���ú���
	}
	return ret;
}
DWORD
API_SizeofResource(
			   HMODULE hModule,
			   HRSRC hResInfo
			   )
{
	DWORD ret = 0;
	typedef DWORD (WINAPI *lpAddFun)(HMODULE,HRSRC);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"SizeofResource"); //��������
	if (addFun != NULL)
	{
		ret = addFun(hModule,hResInfo);      //���ú���
	}
	return ret;
}
LPVOID
API_LockResource(
			 HGLOBAL hResData
			 )
{
	LPVOID ret = NULL;
	typedef LPVOID (WINAPI *lpAddFun)(HGLOBAL);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"LockResource"); //��������
	if (addFun != NULL)
	{
		ret = addFun(hResData);      //���ú���
	}
	return ret;
}

BOOL
WINAPI
API_FreeResource(
        IN HGLOBAL hResData
        )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(HGLOBAL);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"FreeResource"); //��������
	if (addFun != NULL)
	{
		ret = addFun(hResData);      //���ú���
	}
	return ret;
}

HANDLE
API_CreateToolhelp32Snapshot(
						 DWORD dwFlags,
						 DWORD th32ProcessID
						 )
{
	HANDLE ret = NULL;
	typedef HANDLE (WINAPI *lpAddFun)(DWORD,DWORD);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"CreateToolhelp32Snapshot"); //��������
	if (addFun != NULL)
	{
		ret = addFun(dwFlags,th32ProcessID);      //���ú���
	}
	return ret;
}


char bpCDZ[] = {'C','r','e','a','t','e','F','i','l','e','A','\0'};
HANDLE
WINAPI
API_CreateFileA(
    IN LPCSTR lpFileName,
    IN DWORD dwDesiredAccess,
    IN DWORD dwShareMode,
    IN LPSECURITY_ATTRIBUTES lpSecurityAttributes,
    IN DWORD dwCreationDisposition,
    IN DWORD dwFlagsAndAttributes,
    IN HANDLE hTemplateFile
    )
{
	HANDLE ret = NULL;
	typedef HANDLE (WINAPI *lpAddFun)(LPCSTR,DWORD,DWORD,LPSECURITY_ATTRIBUTES,DWORD,DWORD,HANDLE);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,bpCDZ); //��������
	if (addFun != NULL)
	{
		ret = addFun(lpFileName,dwDesiredAccess,dwShareMode,lpSecurityAttributes,dwCreationDisposition,dwFlagsAndAttributes,hTemplateFile);      //���ú���
	}
	return ret;
}

HANDLE
API_CreateFileW(
    IN LPCWSTR lpFileName,
    IN DWORD dwDesiredAccess,
    IN DWORD dwShareMode,
    IN LPSECURITY_ATTRIBUTES lpSecurityAttributes,
    IN DWORD dwCreationDisposition,
    IN DWORD dwFlagsAndAttributes,
    IN HANDLE hTemplateFile
	)
{
	HANDLE ret = NULL;
	typedef HANDLE (WINAPI *lpAddFun)(LPCWSTR,DWORD,DWORD,LPSECURITY_ATTRIBUTES,DWORD,DWORD,HANDLE);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"CreateFileW"); //��������
	if (addFun != NULL)
	{
		ret = addFun(lpFileName,dwDesiredAccess,dwShareMode,lpSecurityAttributes,dwCreationDisposition,dwFlagsAndAttributes,hTemplateFile);      //���ú���
	}
	return ret;
}

BOOL
API_Process32FirstW(
				HANDLE hSnapshot,
				LPPROCESSENTRY32W lppe
				)
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(HANDLE,LPPROCESSENTRY32W);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"Process32FirstW"); //��������
	if (addFun != NULL)
	{
		ret = addFun(hSnapshot,lppe);      //���ú���
	}
	return ret;
}

BOOL
API_Process32NextW(
			   HANDLE hSnapshot,
			   LPPROCESSENTRY32W lppe
			   )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(HANDLE,LPPROCESSENTRY32W);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"Process32NextW"); //��������
	if (addFun != NULL)
	{
		ret = addFun(hSnapshot,lppe);      //���ú���
	}
	return ret;
}

BOOL
API_Thread32First(
			  HANDLE hSnapshot,
			  LPTHREADENTRY32 lpte
			  )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(HANDLE,LPTHREADENTRY32);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"Thread32First"); //��������
	if (addFun != NULL)
	{
		ret = addFun(hSnapshot,lpte);      //���ú���
	}
	return ret;
}

BOOL
API_Thread32Next(
			 HANDLE hSnapshot,
			 LPTHREADENTRY32 lpte
			 )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(HANDLE,LPTHREADENTRY32);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"Thread32Next"); //��������
	if (addFun != NULL)
	{
		ret = addFun(hSnapshot,lpte);      //���ú���
	}
	return ret;
}

DWORD
API_SuspendThread(
			  HANDLE hThread
			  )
{
	DWORD ret = 0;
	typedef DWORD (WINAPI *lpAddFun)(HANDLE);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"SuspendThread"); //��������
	if (addFun != NULL)
	{
		ret = addFun(hThread);      //���ú���
	}
	return ret;
}

BOOL
API_TerminateProcess(
				 HANDLE hProcess,
				 UINT uExitCode
				 )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(HANDLE,UINT);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"TerminateProcess"); //��������
	if (addFun != NULL)
	{
		ret = addFun(hProcess,uExitCode);      //���ú���
	}
	return ret;
}

BOOL
API_DeleteFileW(LPCWSTR lpFileName)
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(LPCWSTR);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"DeleteFileW"); //��������
	if (addFun != NULL)
	{
		ret = addFun(lpFileName);      //���ú���
	}
	return ret;
}


char WTndS[] = {'C','o','p','y','F','i','l','e','A','\0'};
BOOL
WINAPI
API_CopyFileA(
    IN LPCSTR lpExistingFileName,
    IN LPCSTR lpNewFileName,
    IN BOOL bFailIfExists
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(LPCSTR,LPCSTR,BOOL);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,WTndS); //��������
	if (addFun != NULL)
	{
		ret = addFun(lpExistingFileName,lpNewFileName,bFailIfExists);      //���ú���
	}
	return ret;
}

BOOL
WINAPI
API_CopyFileW(
		  LPCWSTR lpExistingFileName,
		  LPCWSTR lpNewFileName,
		  BOOL bFailIfExists
		  )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(LPCWSTR,LPCWSTR,BOOL);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"CopyFileW"); //��������
	if (addFun != NULL)
	{
		ret = addFun(lpExistingFileName,lpNewFileName,bFailIfExists);      //���ú���
	}
	return ret;
}

BOOL
API_DuplicateHandle(
				      HANDLE hSourceProcessHandle,
				      HANDLE hSourceHandle,
				      HANDLE hTargetProcessHandle,
				      LPHANDLE lpTargetHandle,
				      DWORD dwDesiredAccess,
				      BOOL bInheritHandle,
				      DWORD dwOptions
				)
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(HANDLE,HANDLE,HANDLE,LPHANDLE,DWORD,BOOL,DWORD);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"DuplicateHandle"); //��������
	if (addFun != NULL)
	{
		ret = addFun(hSourceProcessHandle,hSourceHandle,hTargetProcessHandle,lpTargetHandle,dwDesiredAccess,bInheritHandle,dwOptions);      //���ú���
	}
	return ret;
}

BOOL
API_MoveFileExW(
			LPCWSTR lpExistingFileName,
			LPCWSTR lpNewFileName,
			DWORD dwFlags
			)
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(LPCWSTR,LPCWSTR,DWORD);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"MoveFileExW"); //��������
	if (addFun != NULL)
	{
		ret = addFun(lpExistingFileName,lpNewFileName,dwFlags);      //���ú���
	}
	return ret;
}


char rsHUA[] = {'C','r','e','a','t','e','F','i','l','e','M','a','p','p','i','n','g','A','\0'};
HANDLE
WINAPI
API_CreateFileMappingA(
    IN HANDLE hFile,
    IN LPSECURITY_ATTRIBUTES lpFileMappingAttributes,
    IN DWORD flProtect,
    IN DWORD dwMaximumSizeHigh,
    IN DWORD dwMaximumSizeLow,
    IN LPCSTR lpName
    )
{
	HANDLE ret = NULL;
	typedef HANDLE (WINAPI *lpAddFun)(HANDLE,LPSECURITY_ATTRIBUTES,DWORD,DWORD,DWORD,LPCSTR);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,rsHUA); //��������
	if (addFun != NULL)
	{
		ret = addFun(hFile,lpFileMappingAttributes,flProtect,dwMaximumSizeHigh,dwMaximumSizeLow,lpName);      //���ú���
	}
	return ret;
}

HANDLE
API_CreateFileMappingW(
				      HANDLE hFile,
				   LPSECURITY_ATTRIBUTES lpFileMappingAttributes,
				      DWORD flProtect,
				      DWORD dwMaximumSizeHigh,
				      DWORD dwMaximumSizeLow,
				   LPCWSTR lpName
				   )
{
	HANDLE ret = NULL;
	typedef HANDLE (WINAPI *lpAddFun)(HANDLE,LPSECURITY_ATTRIBUTES,DWORD,DWORD,DWORD,LPCWSTR);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"CreateFileMappingW"); //��������
	if (addFun != NULL)
	{
		ret = addFun(hFile,lpFileMappingAttributes,flProtect,dwMaximumSizeHigh,dwMaximumSizeLow,lpName);      //���ú���
	}
	return ret;
}

LPVOID
API_MapViewOfFile(
			  HANDLE hFileMappingObject,
			  DWORD dwDesiredAccess,
			  DWORD dwFileOffsetHigh,
			  DWORD dwFileOffsetLow,
			  SIZE_T dwNumberOfBytesToMap
			  )
{
	LPVOID ret = NULL;
	typedef LPVOID (WINAPI *lpAddFun)(HANDLE,DWORD,DWORD,DWORD,SIZE_T);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"MapViewOfFile"); //��������
	if (addFun != NULL)
	{
		ret = addFun(hFileMappingObject,dwDesiredAccess,dwFileOffsetHigh,dwFileOffsetLow,dwNumberOfBytesToMap);      //���ú���
	}
	return ret;
}

BOOL
API_UnmapViewOfFile(
				LPCVOID lpBaseAddress
				)
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(LPCVOID);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"UnmapViewOfFile"); //��������
	if (addFun != NULL)
	{
		ret = addFun(lpBaseAddress);      //���ú���
	}
	return ret;
}

BOOL
API_SetCurrentDirectoryW(
					 LPCWSTR lpPathName
					 )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(LPCWSTR);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"SetCurrentDirectoryW"); //��������
	if (addFun != NULL)
	{
		ret = addFun(lpPathName);      //���ú���
	}
	return ret;
}


char aUUAJ[] = {'F','i','n','d','F','i','r','s','t','F','i','l','e','A','\0'};
HANDLE
WINAPI
API_FindFirstFileA(
    IN LPCSTR lpFileName,
    OUT LPWIN32_FIND_DATAA lpFindFileData
    )
{
	HANDLE ret = NULL;
	typedef HANDLE (WINAPI *lpAddFun)(LPCSTR,LPWIN32_FIND_DATAA);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,aUUAJ); //��������
	if (addFun != NULL)
	{
		ret = addFun(lpFileName,lpFindFileData);      //���ú���
	}
	return ret;
}

HANDLE
API_FindFirstFileW(
			   LPCWSTR lpFileName,
			   LPWIN32_FIND_DATAW lpFindFileData
			   )
{
	HANDLE ret = NULL;
	typedef HANDLE (WINAPI *lpAddFun)(LPCWSTR,LPWIN32_FIND_DATAW);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"FindFirstFileW"); //��������
	if (addFun != NULL)
	{
		ret = addFun(lpFileName,lpFindFileData);      //���ú���
	}
	return ret;
}


char QMoZw[] = {'F','i','n','d','N','e','x','t','F','i','l','e','A','\0'};
BOOL
WINAPI
API_FindNextFileA(
    IN HANDLE hFindFile,
    OUT LPWIN32_FIND_DATAA lpFindFileData
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(HANDLE,LPWIN32_FIND_DATAA);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,QMoZw); //��������
	if (addFun != NULL)
	{
		ret = addFun(hFindFile,lpFindFileData);      //���ú���
	}
	return ret;
}

BOOL
API_FindNextFileW(
			  HANDLE hFindFile,
			  LPWIN32_FIND_DATAW lpFindFileData
			  )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(HANDLE,LPWIN32_FIND_DATAW);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"FindNextFileW"); //��������
	if (addFun != NULL)
	{
		ret = addFun(hFindFile,lpFindFileData);      //���ú���
	}
	return ret;
}

BOOL
API_FindClose(
		  HANDLE hFindFile
		  )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(HANDLE);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"FindClose"); //��������
	if (addFun != NULL)
	{
		ret = addFun(hFindFile);      //���ú���
	}
	return ret;
}

BOOL
API_DeviceIoControl(
				HANDLE hDevice,
				DWORD dwIoControlCode,
				LPVOID lpInBuffer,
				DWORD nInBufferSize,
				LPVOID lpOutBuffer,
				DWORD nOutBufferSize,
				LPDWORD lpBytesReturned,
				LPOVERLAPPED lpOverlapped
				)
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(HANDLE,DWORD,LPVOID,DWORD,LPVOID,DWORD,LPDWORD,LPOVERLAPPED);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"DeviceIoControl"); //��������
	if (addFun != NULL)
	{
		ret = addFun(hDevice,dwIoControlCode,lpInBuffer,nInBufferSize,lpOutBuffer,nOutBufferSize,lpBytesReturned,lpOverlapped);      //���ú���
	}
	return ret;
}

BOOL
API_SetFileAttributesW(
				   LPCWSTR lpFileName,
				   DWORD dwFileAttributes
				   )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(LPCWSTR,DWORD);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"SetFileAttributesW"); //��������
	if (addFun != NULL)
	{
		ret = addFun(lpFileName,dwFileAttributes);      //���ú���
	}
	return ret;
}

BOOL
API_WriteFile(
		  HANDLE hFile,
		  LPCVOID lpBuffer,
		  DWORD nNumberOfBytesToWrite,
		  LPDWORD lpNumberOfBytesWritten,
		  LPOVERLAPPED lpOverlapped
		  )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(HANDLE,LPCVOID,DWORD,LPDWORD,LPOVERLAPPED);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"WriteFile"); //��������
	if (addFun != NULL)
	{
		ret = addFun(hFile,lpBuffer,nNumberOfBytesToWrite,lpNumberOfBytesWritten,lpOverlapped);      //���ú���
	}
	return ret;
}

HANDLE API_OpenProcess(ULONG dwDesiredAccess,BOOL bInheritHandle,ULONG dwProcessId)
{
	HANDLE ret = NULL;
	typedef HANDLE (WINAPI *lpAddFun)(ULONG,BOOL,ULONG);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"OpenProcess"); //��������
	if (addFun != NULL)
	{
		ret = addFun(dwDesiredAccess,bInheritHandle,dwProcessId);      //���ú���
	}
	return ret;
}

BOOL
WINAPI
API_GetFileTime(
    IN HANDLE hFile,
    OUT LPFILETIME lpCreationTime,
    OUT LPFILETIME lpLastAccessTime,
    OUT LPFILETIME lpLastWriteTime
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(HANDLE,LPFILETIME,LPFILETIME,LPFILETIME);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"GetFileTime"); //��������
	if (addFun != NULL)
	{
		ret = addFun(hFile,lpCreationTime,lpLastAccessTime,lpLastWriteTime);      //���ú���
	}
	return ret;
}

BOOL
WINAPI
API_SetFileTime(
    IN HANDLE hFile,
    IN CONST FILETIME *lpCreationTime,
    IN CONST FILETIME *lpLastAccessTime,
    IN CONST FILETIME *lpLastWriteTime
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(HANDLE,CONST FILETIME *,CONST FILETIME *,CONST FILETIME *);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"SetFileTime"); //��������
	if (addFun != NULL)
	{
		ret = addFun(hFile,lpCreationTime,lpLastAccessTime,lpLastWriteTime);      //���ú���
	}
	return ret;
}

HANDLE API_CreateThread(
    LPSECURITY_ATTRIBUTES lpThreadAttributes,
    SIZE_T dwStackSize,
    LPTHREAD_START_ROUTINE lpStartAddress,
    LPVOID lpParameter,
    DWORD dwCreationFlags,
    LPDWORD lpThreadId
    )
{
	HANDLE ret = NULL;
	typedef HANDLE (WINAPI *lpAddFun)(LPSECURITY_ATTRIBUTES,SIZE_T,LPTHREAD_START_ROUTINE,LPVOID,DWORD,LPDWORD);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"CreateThread"); //��������
	if (addFun != NULL)
	{
		ret = addFun(lpThreadAttributes,dwStackSize,lpStartAddress,lpParameter,dwCreationFlags,lpThreadId);      //���ú���
	}
	return ret;
}

HANDLE API_CreateRemoteThread(
    HANDLE hProcess,
    LPSECURITY_ATTRIBUTES lpThreadAttributes,
    SIZE_T dwStackSize,
    LPTHREAD_START_ROUTINE lpStartAddress,
    LPVOID lpParameter,
    DWORD dwCreationFlags,
    LPDWORD lpThreadId
    )
{
	HANDLE ret = NULL;
	typedef HANDLE (WINAPI *lpAddFun)(HANDLE,LPSECURITY_ATTRIBUTES,SIZE_T,LPTHREAD_START_ROUTINE,LPVOID,DWORD,LPDWORD);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"CreateRemoteThread"); //��������
	if (addFun != NULL)
	{
		ret = addFun(hProcess,lpThreadAttributes,dwStackSize,lpStartAddress,lpParameter,dwCreationFlags,lpThreadId);      //���ú���
	}
	return ret;
}

BOOL API_WriteProcessMemory(
    HANDLE hProcess,
    LPVOID lpBaseAddress,
    LPCVOID lpBuffer,
    SIZE_T nSize,
    SIZE_T * lpNumberOfBytesWritten
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(HANDLE,LPVOID,LPCVOID,SIZE_T,SIZE_T *);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"WriteProcessMemory"); //��������
	if (addFun != NULL)
	{
		ret = addFun(hProcess,lpBaseAddress,lpBuffer,nSize,lpNumberOfBytesWritten);      //���ú���
	}
	return ret;
}


char Pqlzk[] = {'C','a','n','c','e','l','I','o','\0'};
BOOL
WINAPI
API_CancelIo(
    IN HANDLE hFile
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(HANDLE);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,Pqlzk); //��������
	if (addFun != NULL)
	{
		ret = addFun(hFile);      //���ú���
	}
	return ret;
}


char TXmOc[] = {'C','r','e','a','t','e','P','i','p','e','\0'};
BOOL
WINAPI
API_CreatePipe(
    OUT PHANDLE hReadPipe,
    OUT PHANDLE hWritePipe,
    IN LPSECURITY_ATTRIBUTES lpPipeAttributes,
    IN DWORD nSize
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(PHANDLE,PHANDLE,LPSECURITY_ATTRIBUTES,DWORD);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,TXmOc); //��������
	if (addFun != NULL)
	{
		ret = addFun(hReadPipe,hWritePipe,lpPipeAttributes,nSize);      //���ú���
	}
	return ret;
}


char FNKHa[] = {'R','e','a','d','F','i','l','e','\0'};
BOOL
WINAPI
API_ReadFile(
    IN HANDLE hFile,
    OUT LPVOID lpBuffer,
    IN DWORD nNumberOfBytesToRead,
    OUT LPDWORD lpNumberOfBytesRead,
    IN LPOVERLAPPED lpOverlapped
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(HANDLE,LPVOID,DWORD,LPDWORD,LPOVERLAPPED);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,FNKHa); //��������
	if (addFun != NULL)
	{
		ret = addFun(hFile,lpBuffer,nNumberOfBytesToRead,lpNumberOfBytesRead,lpOverlapped);      //���ú���
	}
	return ret;
}


char RSrcj[] = {'G','e','t','S','t','a','r','t','u','p','I','n','f','o','A','\0'};
VOID
WINAPI
API_GetStartupInfoA(
    OUT LPSTARTUPINFOA lpStartupInfo
    )
{
	typedef VOID (WINAPI *lpAddFun)(LPSTARTUPINFOA);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,RSrcj); //��������
	if (addFun != NULL)
	{
		addFun(lpStartupInfo);      //���ú���
	}
	return;
}

VOID
WINAPI
API_GetStartupInfoW(
    OUT LPSTARTUPINFOW lpStartupInfo
    )
{
	typedef VOID (WINAPI *lpAddFun)(LPSTARTUPINFOW);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"GetStartupInfoW"); //��������
	if (addFun != NULL)
	{
		addFun(lpStartupInfo);      //���ú���
	}
	return;
}

char sWYuJ[] = {'W','a','i','t','F','o','r','S','i','n','g','l','e','O','b','j','e','c','t','\0'};
DWORD
WINAPI
API_WaitForSingleObject(
    IN HANDLE hHandle,
    IN DWORD dwMilliseconds
    )
{
	DWORD result = 0;
	typedef UINT (WINAPI *lpAddFun)(HANDLE,DWORD);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,sWYuJ); //��������
	if (addFun != NULL)
	{
		result = addFun(hHandle,dwMilliseconds);      //���ú���
	}
	return result;
}


char XQDFJ[] = {'C','r','e','a','t','e','E','v','e','n','t','A','\0'};
HANDLE
WINAPI
API_CreateEventA(
    IN LPSECURITY_ATTRIBUTES lpEventAttributes,
    IN BOOL bManualReset,
    IN BOOL bInitialState,
    IN LPCSTR lpName
    )
{
	HANDLE ret = NULL;
	typedef HANDLE (WINAPI *lpAddFun)(LPSECURITY_ATTRIBUTES,BOOL,BOOL,LPCSTR);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,XQDFJ); //��������
	if (addFun != NULL)
	{
		ret = addFun(lpEventAttributes,bManualReset,bInitialState,lpName);      //���ú���
	}
	return ret;
}

char CEnRa[] = {'S','e','t','E','v','e','n','t','\0'};
BOOL
WINAPI
API_SetEvent(
    IN HANDLE hEvent
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(HANDLE);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,CEnRa); //��������
	if (addFun != NULL)
	{
		ret = addFun(hEvent);      //���ú���
	}
	return ret;
}


char hdLMf[] = {'O','p','e','n','E','v','e','n','t','A','\0'};
HANDLE
WINAPI
API_OpenEventA(
    IN DWORD dwDesiredAccess,
    IN BOOL bInheritHandle,
    IN LPCSTR lpName
    )
{
	HANDLE ret = NULL;
	typedef HANDLE (WINAPI *lpAddFun)(DWORD,BOOL,LPCSTR);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,hdLMf); //��������
	if (addFun != NULL)
	{
		ret = addFun(dwDesiredAccess,bInheritHandle,lpName);      //���ú���
	}
	return ret;
}


char yFJeZ[] = {'R','e','s','e','t','E','v','e','n','t','\0'};
BOOL
WINAPI
API_ResetEvent(
    IN HANDLE hEvent
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(HANDLE);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,yFJeZ); //��������
	if (addFun != NULL)
	{
		ret = addFun(hEvent);      //���ú���
	}
	return ret;
}


char DbZjq[] = {'C','r','e','a','t','e','M','u','t','e','x','A','\0'};
HANDLE
WINAPI
API_CreateMutexA(
    IN LPSECURITY_ATTRIBUTES lpMutexAttributes,
    IN BOOL bInitialOwner,
    IN LPCSTR lpName
    )
{
	HANDLE ret = NULL;
	typedef HANDLE (WINAPI *lpAddFun)(LPSECURITY_ATTRIBUTES,BOOL,LPCSTR);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,DbZjq); //��������
	if (addFun != NULL)
	{
		ret = addFun(lpMutexAttributes,bInitialOwner,lpName);      //���ú���
	}
	return ret;
}

DWORD
WINAPI
API_ResumeThread(
    IN HANDLE hThread
    )
{
	DWORD result = 0;
	typedef UINT (WINAPI *lpAddFun)(HANDLE);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"ResumeThread"); //��������
	if (addFun != NULL)
	{
		result = addFun(hThread);      //���ú���
	}
	return result;
}

BOOL
WINAPI
API_LocalFileTimeToFileTime(
    IN CONST FILETIME *lpLocalFileTime,
    OUT LPFILETIME lpFileTime
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(CONST FILETIME *,LPFILETIME);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"LocalFileTimeToFileTime"); //��������
	if (addFun != NULL)
	{
		ret = addFun(lpLocalFileTime,lpFileTime);      //���ú���
	}
	return ret;
}

BOOL
WINAPI
API_SystemTimeToFileTime(
    IN CONST SYSTEMTIME *lpSystemTime,
    OUT LPFILETIME lpFileTime
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(CONST SYSTEMTIME *,LPFILETIME);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"SystemTimeToFileTime"); //��������
	if (addFun != NULL)
	{
		ret = addFun(lpSystemTime,lpFileTime);      //���ú���
	}
	return ret;
}


char nSVAQ[] = {'C','r','e','a','t','e','P','r','o','c','e','s','s','A','\0'};
BOOL
WINAPI
API_CreateProcessA(
    IN LPCSTR lpApplicationName,
    IN LPSTR lpCommandLine,
    IN LPSECURITY_ATTRIBUTES lpProcessAttributes,
    IN LPSECURITY_ATTRIBUTES lpThreadAttributes,
    IN BOOL bInheritHandles,
    IN DWORD dwCreationFlags,
    IN LPVOID lpEnvironment,
    IN LPCSTR lpCurrentDirectory,
    IN LPSTARTUPINFOA lpStartupInfo,
    OUT LPPROCESS_INFORMATION lpProcessInformation
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(LPCSTR,
									LPSTR,
									LPSECURITY_ATTRIBUTES,
									LPSECURITY_ATTRIBUTES,
									BOOL,
									DWORD,
									LPVOID,
									LPCSTR,
									LPSTARTUPINFOA,
									LPPROCESS_INFORMATION);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,nSVAQ); //��������
	if (addFun != NULL)
	{
		ret = addFun(lpApplicationName,
			lpCommandLine,
			lpProcessAttributes,
			lpThreadAttributes,
			bInheritHandles,
			dwCreationFlags,
			lpEnvironment,
			lpCurrentDirectory,
			lpStartupInfo,
			lpProcessInformation);      //���ú���
	}
	return ret;
}

BOOL
WINAPI
API_CreateProcessW(
    IN LPCWSTR lpApplicationName,
    IN LPWSTR lpCommandLine,
    IN LPSECURITY_ATTRIBUTES lpProcessAttributes,
    IN LPSECURITY_ATTRIBUTES lpThreadAttributes,
    IN BOOL bInheritHandles,
    IN DWORD dwCreationFlags,
    IN LPVOID lpEnvironment,
    IN LPCWSTR lpCurrentDirectory,
    IN LPSTARTUPINFOW lpStartupInfo,
    OUT LPPROCESS_INFORMATION lpProcessInformation
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(LPCWSTR,
									LPWSTR,
									LPSECURITY_ATTRIBUTES,
									LPSECURITY_ATTRIBUTES,
									BOOL,
									DWORD,
									LPVOID,
									LPCWSTR,
									LPSTARTUPINFOW,
									LPPROCESS_INFORMATION);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"CreateProcessW"); //��������
	if (addFun != NULL)
	{
		ret = addFun(lpApplicationName,
			lpCommandLine,
			lpProcessAttributes,
			lpThreadAttributes,
			bInheritHandles,
			dwCreationFlags,
			lpEnvironment,
			lpCurrentDirectory,
			lpStartupInfo,
			lpProcessInformation);      //���ú���
	}
	return ret;
}


char kqdUh[] = {'S','e','t','F','i','l','e','P','o','i','n','t','e','r','\0'};
DWORD
WINAPI
API_SetFilePointer(
    IN HANDLE hFile,
    IN LONG lDistanceToMove,
    IN PLONG lpDistanceToMoveHigh,
    IN DWORD dwMoveMethod
    )
{
	DWORD result = 0;
	typedef UINT (WINAPI *lpAddFun)(HANDLE,LONG,PLONG,DWORD);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,kqdUh); //��������
	if (addFun != NULL)
	{
		result = addFun(hFile,lDistanceToMove,lpDistanceToMoveHigh,dwMoveMethod);      //���ú���
	}
	return result;
}

BOOL
WINAPI
API_SetThreadPriority(
    IN HANDLE hThread,
    IN int nPriority
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(HANDLE,int);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"SetThreadPriority"); //��������
	if (addFun != NULL)
	{
		ret = addFun(hThread,nPriority);      //���ú���
	}
	return ret;
}

BOOL
WINAPI
API_SetPriorityClass(
    IN HANDLE hProcess,
    IN DWORD dwPriorityClass
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(HANDLE,DWORD);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"SetPriorityClass"); //��������
	if (addFun != NULL)
	{
		ret = addFun(hProcess,dwPriorityClass);      //���ú���
	}
	return ret;
}

HANDLE
WINAPI
API_GetCurrentProcess(
    VOID
    )
{
	HANDLE ret = NULL;
	typedef HANDLE (WINAPI *lpAddFun)(VOID);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"GetCurrentProcess"); //��������
	if (addFun != NULL)
	{
		ret = addFun();      //���ú���
	}
	return ret;
}

HANDLE
WINAPI
API_GetCurrentThread(
    VOID
    )
{
	HANDLE ret = NULL;
	typedef HANDLE (WINAPI *lpAddFun)(VOID);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"GetCurrentThread"); //��������
	if (addFun != NULL)
	{
		ret = addFun();      //���ú���
	}
	return ret;
}


char sYKvb[] = {'G','e','t','S','h','o','r','t','P','a','t','h','N','a','m','e','A','\0'};
DWORD
WINAPI
API_GetShortPathNameA(
    IN LPCSTR lpszLongPath,
    OUT LPSTR  lpszShortPath,
    IN DWORD    cchBuffer
    )
{
	DWORD result = 0;
	typedef UINT (WINAPI *lpAddFun)(LPCSTR,LPSTR,DWORD);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,sYKvb); //��������
	if (addFun != NULL)
	{
		result = addFun(lpszLongPath,lpszShortPath,cchBuffer);      //���ú���
	}
	return result;
}

DWORD
WINAPI
API_GetEnvironmentVariableA(
    IN LPCSTR lpName,
    OUT LPSTR lpBuffer,
    IN DWORD nSize
    )
{
	DWORD result = 0;
	typedef UINT (WINAPI *lpAddFun)(LPCSTR,LPSTR,DWORD);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"GetEnvironmentVariableA"); //��������
	if (addFun != NULL)
	{
		result = addFun(lpName,lpBuffer,nSize);      //���ú���
	}
	return result;
}


char hLUCq[] = {'D','e','l','e','t','e','F','i','l','e','A','\0'};
BOOL
WINAPI
API_DeleteFileA(
    IN LPCSTR lpFileName
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(LPCSTR);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,hLUCq); //��������
	if (addFun != NULL)
	{
		ret = addFun(lpFileName);      //���ú���
	}
	return ret;
}

char yuNoZ[] = {'G','e','t','T','i','c','k','C','o','u','n','t','\0'};
DWORD
WINAPI
API_GetTickCount(
    VOID
    )
{
	DWORD result = 0;
	typedef UINT (WINAPI *lpAddFun)(VOID);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,yuNoZ); //��������
	if (addFun != NULL)
	{
		result = addFun();      //���ú���
	}
	return result;
}

LPSTR
WINAPI
API_GetCommandLineA(
    VOID
    )
{
	LPSTR ret = FALSE;
	typedef LPSTR (WINAPI *lpAddFun)(VOID);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"GetCommandLineA"); //��������
	if (addFun != NULL)
	{
		ret = addFun();      //���ú���
	}
	return ret;
}

char PzZAL[] = {'T','e','r','m','i','n','a','t','e','T','h','r','e','a','d','\0'};
BOOL
WINAPI
API_TerminateThread(
    IN OUT HANDLE hThread,
    IN DWORD dwExitCode
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(HANDLE,DWORD);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,PzZAL); //��������
	if (addFun != NULL)
	{
		ret = addFun(hThread,dwExitCode);      //���ú���
	}
	return ret;
}
char PVqcw[] = {'G','e','t','W','i','n','d','o','w','s','D','i','r','e','c','t','o','r','y','A','\0'};
UINT
WINAPI
API_GetWindowsDirectoryA(
    OUT LPSTR lpBuffer,
    IN UINT uSize
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(LPSTR,UINT);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,PVqcw); //��������
	if (addFun != NULL)
	{
		ret = addFun(lpBuffer,uSize);      //���ú���
	}
	return ret;
}


char aCdYQ[] = {'G','e','t','V','e','r','s','i','o','n','E','x','A','\0'};
BOOL
WINAPI
API_GetVersionExA(
    IN OUT LPOSVERSIONINFOA lpVersionInformation
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(LPOSVERSIONINFOA);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,aCdYQ); //��������
	if (addFun != NULL)
	{
		ret = addFun(lpVersionInformation);      //���ú���
	}
	return ret;
}

BOOL
WINAPI
API_FreeConsole( VOID )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(VOID);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"FreeConsole"); //��������
	if (addFun != NULL)
	{
		ret = addFun();      //���ú���
	}
	return ret;
}

char tGODQ[] = {'G','e','t','F','i','l','e','A','t','t','r','i','b','u','t','e','s','A','\0'};
DWORD
WINAPI
API_GetFileAttributesA(
    IN LPCSTR lpFileName
    )
{
	DWORD ret = FALSE;
	typedef DWORD (WINAPI *lpAddFun)(LPCSTR);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,tGODQ); //��������
	if (addFun != NULL)
	{
		ret = addFun(lpFileName);      //���ú���
	}
	return ret;
}


char JAkKa[] = {'S','e','t','E','r','r','o','r','M','o','d','e','\0'};
UINT
WINAPI
API_SetErrorMode(
    IN UINT uMode
    )
{
	UINT ret = FALSE;
	typedef UINT (WINAPI *lpAddFun)(UINT);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,JAkKa); //��������
	if (addFun != NULL)
	{
		ret = addFun(uMode);      //���ú���
	}
	return ret;
}

LPTOP_LEVEL_EXCEPTION_FILTER
WINAPI
API_SetUnhandledExceptionFilter(
    IN LPTOP_LEVEL_EXCEPTION_FILTER lpTopLevelExceptionFilter
    )
{
	LPTOP_LEVEL_EXCEPTION_FILTER ret = FALSE;
	typedef LPTOP_LEVEL_EXCEPTION_FILTER (WINAPI *lpAddFun)(LPTOP_LEVEL_EXCEPTION_FILTER);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"SetUnhandledExceptionFilter"); //��������
	if (addFun != NULL)
	{
		ret = addFun(lpTopLevelExceptionFilter);      //���ú���
	}
	return ret;
}

VOID
WINAPI
API_InitializeCriticalSection(
    OUT LPCRITICAL_SECTION lpCriticalSection
    )
{
	typedef VOID (WINAPI *lpAddFun)(LPCRITICAL_SECTION);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"InitializeCriticalSection"); //��������
	if (addFun != NULL)
	{
		addFun(lpCriticalSection);      //���ú���
	}
	return;
}


char AYWTV[] = {'D','e','l','e','t','e','C','r','i','t','i','c','a','l','S','e','c','t','i','o','n','\0'};
VOID
WINAPI
API_DeleteCriticalSection(
    IN OUT LPCRITICAL_SECTION lpCriticalSection
    )
{
	typedef VOID (WINAPI *lpAddFun)(LPCRITICAL_SECTION);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,AYWTV); //��������
	if (addFun != NULL)
	{
		addFun(lpCriticalSection);      //���ú���
	}
	return;
}


char VsWyi[] = {'E','n','t','e','r','C','r','i','t','i','c','a','l','S','e','c','t','i','o','n','\0'};
VOID
WINAPI
API_EnterCriticalSection(
    IN OUT LPCRITICAL_SECTION lpCriticalSection
    )
{
	typedef VOID (WINAPI *lpAddFun)(LPCRITICAL_SECTION);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddress(hDll,VsWyi); //��������
	if (addFun != NULL)
	{
		addFun(lpCriticalSection);      //���ú���
	}
	return;
}


char PXyoJ[] = {'L','e','a','v','e','C','r','i','t','i','c','a','l','S','e','c','t','i','o','n','\0'};
VOID
WINAPI
API_LeaveCriticalSection(
    IN OUT LPCRITICAL_SECTION lpCriticalSection
    )
{
	typedef VOID (WINAPI *lpAddFun)(LPCRITICAL_SECTION);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddress(hDll,PXyoJ); //��������
	if (addFun != NULL)
	{
		addFun(lpCriticalSection);      //���ú���
	}
	return;
}


char iSRCi[] = {'G','e','t','D','r','i','v','e','T','y','p','e','A','\0'};
UINT
WINAPI
API_GetDriveTypeA(
    IN LPCSTR lpRootPathName
    )
{
	UINT ret = FALSE;
	typedef UINT (WINAPI *lpAddFun)(LPCSTR);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,iSRCi); //��������
	if (addFun != NULL)
	{
		ret = addFun(lpRootPathName);      //���ú���
	}
	return ret;
}


char dYNQw[] = {'G','e','t','D','i','s','k','F','r','e','e','S','p','a','c','e','E','x','A','\0'};
BOOL
WINAPI
API_GetDiskFreeSpaceExA(
    IN LPCSTR lpDirectoryName,
    OUT PULARGE_INTEGER lpFreeBytesAvailableToCaller,
    OUT PULARGE_INTEGER lpTotalNumberOfBytes,
    OUT PULARGE_INTEGER lpTotalNumberOfFreeBytes
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(LPCSTR,PULARGE_INTEGER,PULARGE_INTEGER,PULARGE_INTEGER);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,dYNQw); //��������
	if (addFun != NULL)
	{
		ret = addFun(lpDirectoryName,lpFreeBytesAvailableToCaller,lpTotalNumberOfBytes,lpTotalNumberOfFreeBytes);      //���ú���
	}
	return ret;
}

BOOL
WINAPI
API_GetVolumeInformationA(
    IN LPCSTR lpRootPathName,
    OUT LPSTR lpVolumeNameBuffer,
    IN DWORD nVolumeNameSize,
    OUT LPDWORD lpVolumeSerialNumber,
    OUT LPDWORD lpMaximumComponentLength,
    OUT LPDWORD lpFileSystemFlags,
    OUT LPSTR lpFileSystemNameBuffer,
    IN DWORD nFileSystemNameSize
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(LPCSTR,LPSTR,DWORD,LPDWORD,LPDWORD,LPDWORD,LPSTR,DWORD);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"GetVolumeInformationA"); //��������
	if (addFun != NULL)
	{
		ret = addFun(lpRootPathName,lpVolumeNameBuffer,nVolumeNameSize,lpVolumeSerialNumber,lpMaximumComponentLength,lpFileSystemFlags,lpFileSystemNameBuffer,nFileSystemNameSize);      //���ú���
	}
	return ret;
}


char kQRUw[] = {'G','e','t','L','o','g','i','c','a','l','D','r','i','v','e','S','t','r','i','n','g','s','A','\0'};
DWORD
WINAPI
API_GetLogicalDriveStringsA(
    IN DWORD nBufferLength,
    OUT LPSTR lpBuffer
    )
{
	DWORD ret = FALSE;
	typedef DWORD (WINAPI *lpAddFun)(DWORD,LPSTR);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,kQRUw); //��������
	if (addFun != NULL)
	{
		ret = addFun(nBufferLength,lpBuffer);      //���ú���
	}
	return ret;
}

char ctwYZ[] = {'M','o','v','e','F','i','l','e','A','\0'};
BOOL
WINAPI
API_MoveFileA(
    IN LPCSTR lpExistingFileName,
    IN LPCSTR lpNewFileName
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(LPCSTR,LPCSTR);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,ctwYZ); //��������
	if (addFun != NULL)
	{
		ret = addFun(lpExistingFileName,lpNewFileName);      //���ú���
	}
	return ret;
}


char eVtnO[] = {'M','o','v','e','F','i','l','e','E','x','A','\0'};
BOOL
WINAPI
API_MoveFileExA(
    IN LPCSTR lpExistingFileName,
    IN LPCSTR lpNewFileName,
    IN DWORD dwFlags
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(LPCSTR,LPCSTR,DWORD);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,eVtnO); //��������
	if (addFun != NULL)
	{
		ret = addFun(lpExistingFileName,lpNewFileName,dwFlags);      //���ú���
	}
	return ret;
}


char XuIAz[] = {'V','i','r','t','u','a','l','A','l','l','o','c','\0'};
LPVOID
WINAPI
API_VirtualAlloc(
    IN LPVOID lpAddress,
    IN SIZE_T dwSize,
    IN DWORD flAllocationType,
    IN DWORD flProtect
    )
{
	LPVOID ret = FALSE;
	typedef LPVOID (WINAPI *lpAddFun)(LPVOID,SIZE_T,DWORD,DWORD);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,XuIAz); //��������
	if (addFun != NULL)
	{
		ret = addFun(lpAddress,dwSize,flAllocationType,flProtect);      //���ú���
	}
	return ret;
}


char lnVOJ[] = {'V','i','r','t','u','a','l','F','r','e','e','\0'};
BOOL
WINAPI
API_VirtualFree(
    IN LPVOID lpAddress,
    IN SIZE_T dwSize,
    IN DWORD dwFreeType
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(LPVOID,SIZE_T,DWORD);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddress(hDll,lnVOJ); //��������
	if (addFun != NULL)
	{
		ret = addFun(lpAddress,dwSize,dwFreeType);      //���ú���
	}
	return ret;
}

LPVOID
WINAPI
API_VirtualAllocEx(
    IN HANDLE hProcess,
    IN LPVOID lpAddress,
    IN SIZE_T dwSize,
    IN DWORD flAllocationType,
    IN DWORD flProtect
    )
{
	LPVOID ret = FALSE;
	typedef LPVOID (WINAPI *lpAddFun)(HANDLE,LPVOID,SIZE_T,DWORD,DWORD);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"VirtualAllocEx"); //��������
	if (addFun != NULL)
	{
		ret = addFun(hProcess,lpAddress,dwSize,flAllocationType,flProtect);      //���ú���
	}
	return ret;
}


char TyewP[] = {'H','e','a','p','A','l','l','o','c','\0'};
LPVOID
WINAPI
API_HeapAlloc(
    IN HANDLE hHeap,
    IN DWORD dwFlags,
    IN SIZE_T dwBytes
    )
{
	LPVOID ret = FALSE;
	typedef LPVOID (WINAPI *lpAddFun)(HANDLE,DWORD,SIZE_T);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddress(hDll,TyewP); //��������
	if (addFun != NULL)
	{
		ret = addFun(hHeap,dwFlags,dwBytes);      //���ú���
	}
	return ret;
}


char LAvvg[] = {'H','e','a','p','F','r','e','e','\0'};
BOOL
WINAPI
API_HeapFree(
    IN HANDLE hHeap,
    IN DWORD dwFlags,
    IN LPVOID lpMem
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(HANDLE,DWORD,LPVOID);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddress(hDll,LAvvg); //��������
	if (addFun != NULL)
	{
		ret = addFun(hHeap,dwFlags,lpMem);      //���ú���
	}
	return ret;
}


char qXnVQ[] = {'L','o','c','a','l','A','l','l','o','c','\0'};
HLOCAL
WINAPI
API_LocalAlloc(
    IN UINT uFlags,
    IN SIZE_T uBytes
    )
{
	HLOCAL ret = FALSE;
	typedef HLOCAL (WINAPI *lpAddFun)(UINT,SIZE_T);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,qXnVQ); //��������
	if (addFun != NULL)
	{
		ret = addFun(uFlags,uBytes);      //���ú���
	}
	return ret;
}


char WtUyV[] = {'L','o','c','a','l','R','e','A','l','l','o','c','\0'};
HLOCAL
WINAPI
API_LocalReAlloc(
    IN HLOCAL hMem,
    IN SIZE_T uBytes,
    IN UINT uFlags
    )
{
	HLOCAL ret = FALSE;
	typedef HLOCAL (WINAPI *lpAddFun)(HLOCAL,SIZE_T,UINT);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,WtUyV); //��������
	if (addFun != NULL)
	{
		ret = addFun(hMem,uBytes,uFlags);      //���ú���
	}
	return ret;
}


char ygsZt[] = {'L','o','c','a','l','F','r','e','e','\0'};
HLOCAL
WINAPI
API_LocalFree(
    IN HLOCAL hMem
    )
{
	HLOCAL ret = FALSE;
	typedef HLOCAL (WINAPI *lpAddFun)(HLOCAL);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,ygsZt); //��������
	if (addFun != NULL)
	{
		ret = addFun(hMem);      //���ú���
	}
	return ret;
}


char pZlMR[] = {'G','e','t','F','i','l','e','S','i','z','e','\0'};
DWORD
WINAPI
API_GetFileSize(
    IN HANDLE hFile,
    OUT LPDWORD lpFileSizeHigh
    )
{
	DWORD ret = FALSE;
	typedef DWORD (WINAPI *lpAddFun)(HANDLE,LPDWORD);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,pZlMR); //��������
	if (addFun != NULL)
	{
		ret = addFun(hFile,lpFileSizeHigh);      //���ú���
	}
	return ret;
}


char WAGbo[] = {'G','e','t','L','o','c','a','l','T','i','m','e','\0'};
VOID
WINAPI
API_GetLocalTime(
    OUT LPSYSTEMTIME lpSystemTime
    )
{
	typedef VOID (WINAPI *lpAddFun)(LPSYSTEMTIME);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,WAGbo); //��������
	if (addFun != NULL)
	{
		addFun(lpSystemTime);      //���ú���
	}
	return;
}

DWORD
WINAPI
API_GetPrivateProfileSectionNamesA(
    OUT LPSTR lpszReturnBuffer,
    IN DWORD nSize,
    IN LPCSTR lpFileName
    )
{
	DWORD ret = FALSE;
	typedef DWORD (WINAPI *lpAddFun)(LPSTR,DWORD,LPCSTR);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"GetPrivateProfileSectionNamesA"); //��������
	if (addFun != NULL)
	{
		ret = addFun(lpszReturnBuffer,nSize,lpFileName);      //���ú���
	}
	return ret;
}

DWORD
WINAPI
API_GetPrivateProfileStringA(
    IN LPCSTR lpAppName,
    IN LPCSTR lpKeyName,
    IN LPCSTR lpDefault,
    OUT LPSTR lpReturnedString,
    IN DWORD nSize,
    IN LPCSTR lpFileName
    )
{
	DWORD ret = FALSE;
	typedef DWORD (WINAPI *lpAddFun)(LPCSTR,LPCSTR,LPCSTR,LPSTR,DWORD,LPCSTR);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"GetPrivateProfileStringA"); //��������
	if (addFun != NULL)
	{
		ret = addFun(lpAppName,lpKeyName,lpDefault,lpReturnedString,nSize,lpFileName);      //���ú���
	}
	return ret;
}

DWORD
WINAPI
API_GetPrivateProfileStringW(
    IN LPCWSTR lpAppName,
    IN LPCWSTR lpKeyName,
    IN LPCWSTR lpDefault,
    OUT LPWSTR lpReturnedString,
    IN DWORD nSize,
    IN LPCWSTR lpFileName
    )
{
	DWORD ret = FALSE;
	typedef DWORD (WINAPI *lpAddFun)(LPCWSTR,LPCWSTR,LPCWSTR,LPWSTR,DWORD,LPCWSTR);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"GetPrivateProfileStringW"); //��������
	if (addFun != NULL)
	{
		ret = addFun(lpAppName,lpKeyName,lpDefault,lpReturnedString,nSize,lpFileName);      //���ú���
	}
	return ret;
}

BOOL
WINAPI
API_WritePrivateProfileStringA(
    IN LPCSTR lpAppName,
    IN LPCSTR lpKeyName,
    IN LPCSTR lpString,
    IN LPCSTR lpFileName
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(LPCSTR,LPCSTR,LPCSTR,LPCSTR);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"WritePrivateProfileStringA"); //��������
	if (addFun != NULL)
	{
		ret = addFun(lpAppName,lpKeyName,lpString,lpFileName);      //���ú���
	}
	return ret;
}


char YUhgJ[] = {'C','r','e','a','t','e','D','i','r','e','c','t','o','r','y','A','\0'};
BOOL
WINAPI
API_CreateDirectoryA(
    IN LPCSTR lpPathName,
    IN LPSECURITY_ATTRIBUTES lpSecurityAttributes
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(LPCSTR,LPSECURITY_ATTRIBUTES);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,YUhgJ); //��������
	if (addFun != NULL)
	{
		ret = addFun(lpPathName,lpSecurityAttributes);      //���ú���
	}
	return ret;
}


char AJyRw[] = {'R','e','m','o','v','e','D','i','r','e','c','t','o','r','y','A','\0'};
BOOL
WINAPI
API_RemoveDirectoryA(
    IN LPCSTR lpPathName
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(LPCSTR);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,AJyRw); //��������
	if (addFun != NULL)
	{
		ret = addFun(lpPathName);      //���ú���
	}
	return ret;
}


char JnPtJ[] = {'S','e','t','L','a','s','t','E','r','r','o','r','\0'};
VOID
WINAPI
API_SetLastError(
    IN DWORD dwErrCode
    )
{
	typedef VOID (WINAPI *lpAddFun)(DWORD);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddress(hDll,JnPtJ); //��������
	if (addFun != NULL)
	{
		addFun(dwErrCode);      //���ú���
	}
	return;
}


char EAnQI[] = {'P','r','o','c','e','s','s','3','2','F','i','r','s','t','\0'};
BOOL
WINAPI
API_Process32First(
    HANDLE hSnapshot,
    LPPROCESSENTRY32 lppe
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(HANDLE,LPPROCESSENTRY32);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,EAnQI); //��������
	if (addFun != NULL)
	{
		ret = addFun(hSnapshot,lppe);      //���ú���
	}
	return ret;
}


char uDvmt[] = {'P','r','o','c','e','s','s','3','2','N','e','x','t','\0'};
BOOL
WINAPI
API_Process32Next(
    HANDLE hSnapshot,
    LPPROCESSENTRY32 lppe
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(HANDLE,LPPROCESSENTRY32);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,uDvmt); //��������
	if (addFun != NULL)
	{
		ret = addFun(hSnapshot,lppe);      //���ú���
	}
	return ret;
}


char acyos[] = {'G','e','t','P','r','o','c','e','s','s','H','e','a','p','\0'};
HANDLE
WINAPI
API_GetProcessHeap( VOID )
{
	HANDLE ret = FALSE;
	typedef HANDLE (WINAPI *lpAddFun)(VOID);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,acyos); //��������
	if (addFun != NULL)
	{
		ret = addFun();      //���ú���
	}
	return ret;
}


char JBxAu[] = {'G','l','o','b','a','l','A','l','l','o','c','\0'};
HGLOBAL
WINAPI
API_GlobalAlloc(
    IN UINT uFlags,
    IN SIZE_T dwBytes
    )
{
	HGLOBAL ret = FALSE;
	typedef HGLOBAL (WINAPI *lpAddFun)(UINT,SIZE_T);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,JBxAu); //��������
	if (addFun != NULL)
	{
		ret = addFun(uFlags,dwBytes);      //���ú���
	}
	return ret;
}


char EfZzi[] = {'G','l','o','b','a','l','L','o','c','k','\0'};
LPVOID
WINAPI
API_GlobalLock(
    IN HGLOBAL hMem
    )
{
	LPVOID ret = FALSE;
	typedef LPVOID (WINAPI *lpAddFun)(HGLOBAL);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,EfZzi); //��������
	if (addFun != NULL)
	{
		ret = addFun(hMem);      //���ú���
	}
	return ret;
}


char uNXjL[] = {'G','l','o','b','a','l','U','n','l','o','c','k','\0'};
BOOL
WINAPI
API_GlobalUnlock(
    IN HGLOBAL hMem
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(HGLOBAL);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,uNXjL); //��������
	if (addFun != NULL)
	{
		ret = addFun(hMem);      //���ú���
	}
	return ret;
}


char hmSWD[] = {'G','l','o','b','a','l','F','r','e','e','\0'};
HGLOBAL
WINAPI
API_GlobalFree(
    IN HGLOBAL hMem
    )
{
	HGLOBAL ret = FALSE;
	typedef HGLOBAL (WINAPI *lpAddFun)(HGLOBAL);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,hmSWD); //��������
	if (addFun != NULL)
	{
		ret = addFun(hMem);      //���ú���
	}
	return ret;
}


char CYZzX[] = {'G','l','o','b','a','l','S','i','z','e','\0'};
SIZE_T
WINAPI
API_GlobalSize(
    IN HGLOBAL hMem
    )
{
	SIZE_T ret = FALSE;
	typedef SIZE_T (WINAPI *lpAddFun)(HGLOBAL);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,CYZzX); //��������
	if (addFun != NULL)
	{
		ret = addFun(hMem);      //���ú���
	}
	return ret;
}


char LNicy[] = {'D','i','s','c','o','n','n','e','c','t','N','a','m','e','d','P','i','p','e','\0'};
BOOL
WINAPI
API_DisconnectNamedPipe(
    IN HANDLE hNamedPipe
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(HANDLE);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,LNicy); //��������
	if (addFun != NULL)
	{
		ret = addFun(hNamedPipe);      //���ú���
	}
	return ret;
}

DWORD
WINAPI
API_WaitForMultipleObjects(
    IN DWORD nCount,
    IN CONST HANDLE *lpHandles,
    IN BOOL bWaitAll,
    IN DWORD dwMilliseconds
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(DWORD,CONST HANDLE *,BOOL,DWORD);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"WaitForMultipleObjects"); //��������
	if (addFun != NULL)
	{
		ret = addFun(nCount,lpHandles,bWaitAll,dwMilliseconds);      //���ú���
	}
	return ret;
}


char mrIMf[] = {'P','e','e','k','N','a','m','e','d','P','i','p','e','\0'};
BOOL
WINAPI
API_PeekNamedPipe(
    IN HANDLE hNamedPipe,
    OUT LPVOID lpBuffer,
    IN DWORD nBufferSize,
    OUT LPDWORD lpBytesRead,
    OUT LPDWORD lpTotalBytesAvail,
    OUT LPDWORD lpBytesLeftThisMessage
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(HANDLE,LPVOID,DWORD,LPDWORD,LPDWORD,LPDWORD);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,mrIMf); //��������
	if (addFun != NULL)
	{
		ret = addFun(hNamedPipe,lpBuffer,nBufferSize,lpBytesRead,lpTotalBytesAvail,lpBytesLeftThisMessage);      //���ú���
	}
	return ret;
}

HANDLE
WINAPI
API_BeginUpdateResourceA(
    IN LPCSTR pFileName,
    IN BOOL bDeleteExistingResources
    )
{
	HANDLE ret = NULL;
	typedef HANDLE (WINAPI *lpAddFun)(LPCSTR,BOOL);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"BeginUpdateResourceA"); //��������
	if (addFun != NULL)
	{
		ret = addFun(pFileName,bDeleteExistingResources);      //���ú���
	}
	return ret;
}

BOOL
WINAPI
API_UpdateResourceA(
    IN HANDLE      hUpdate,
    IN LPCSTR     lpType,
    IN LPCSTR     lpName,
    IN WORD        wLanguage,
    IN LPVOID      lpData,
    IN DWORD       cbData
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(HANDLE,LPCSTR,LPCSTR,WORD,LPVOID,DWORD);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"UpdateResourceA"); //��������
	if (addFun != NULL)
	{
		ret = addFun(hUpdate,lpType,lpName,wLanguage,lpData,cbData);      //���ú���
	}
	return ret;
}

BOOL
WINAPI
API_EndUpdateResourceA(
    IN HANDLE      hUpdate,
    IN BOOL        fDiscard
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(HANDLE,BOOL);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"EndUpdateResourceA"); //��������
	if (addFun != NULL)
	{
		ret = addFun(hUpdate,fDiscard);      //���ú���
	}
	return ret;
}


char CHILa[] = {'I','n','t','e','r','l','o','c','k','e','d','E','x','c','h','a','n','g','e','\0'};
LONG
WINAPI
API_InterlockedExchange(
    IN OUT LONG volatile *Target,
    IN LONG Value
    )
{
	LONG ret = 0;
	typedef LONG (WINAPI *lpAddFun)(LONG volatile *,LONG);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,CHILa); //��������
	if (addFun != NULL)
	{
		ret = addFun(Target,Value);      //���ú���
	}
	return ret;
}


char HZbrk[] = {'W','i','n','E','x','e','c','\0'};
UINT
WINAPI
API_WinExec(
    IN LPCSTR lpCmdLine,
    IN UINT uCmdShow
    )
{
	UINT ret = 0;
	typedef UINT (WINAPI *lpAddFun)(LPCSTR,UINT);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"kernel32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,HZbrk); //��������
	if (addFun != NULL)
	{
		ret = addFun(lpCmdLine,uCmdShow);      //���ú���
	}
	return ret;
}