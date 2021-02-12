#include <windows.h>
#include "API_advapi32.h"
#include "GetProcAddressEx.h"



SC_HANDLE API_OpenSCManagerW(
							 LPCWSTR                lpMachineName,
							 LPCWSTR                lpDatabaseName,
							 DWORD                   dwDesiredAccess
							 )
{
	SC_HANDLE ret = NULL;
	typedef SC_HANDLE (WINAPI *lpAddFun)(LPCWSTR,LPCWSTR,DWORD);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"OpenSCManagerW"); //��������
	if (addFun != NULL)
	{
		ret = addFun(lpMachineName,lpDatabaseName,dwDesiredAccess);      //���ú���
	}
	return ret;
}

SC_HANDLE API_OpenServiceW(SC_HANDLE hSCManager,LPCWSTR lpServiceName,DWORD dwDesiredAccess)
{
	/*
	SC_HANDLE
	WINAPI
	OpenServiceW(
	__in            SC_HANDLE               hSCManager,
	__in            LPCWSTR                lpServiceName,
	__in            DWORD                   dwDesiredAccess
	);
	*/
	SC_HANDLE ret = NULL;
	typedef SC_HANDLE (WINAPI *lpAddFun)(SC_HANDLE,LPCWSTR,DWORD);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"OpenServiceW"); //��������
	if (addFun != NULL)
	{
		ret = addFun(hSCManager,lpServiceName,dwDesiredAccess);      //���ú���
	}
	return ret;
}

BOOL API_ChangeServiceConfigW(
								SC_HANDLE hService,
								ULONG dwServiceType,
								ULONG dwStartType,
								ULONG dwErrorControl,
								LPCTSTR lpBinaryPathName,
								LPCTSTR lpLoadOrderGroup,
								LPDWORD lpdwTagId,
								LPCTSTR lpDependencies,
								LPCTSTR lpServiceStartName,
								LPCTSTR lpPassword,
								LPCTSTR lpDisplayName
							  )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(SC_HANDLE,ULONG,ULONG,ULONG,LPCTSTR,LPCTSTR,LPDWORD,LPCTSTR,LPCTSTR,LPCTSTR,LPCTSTR);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"ChangeServiceConfigW"); //��������
	if (addFun != NULL)
	{
		ret = addFun(hService,dwServiceType,dwStartType,dwErrorControl,lpBinaryPathName,lpLoadOrderGroup,lpdwTagId,lpDependencies,lpServiceStartName,lpPassword,lpDisplayName);//���ú���
	}
	return ret;
}

char kpzmt[] = {'O','p','e','n','P','r','o','c','e','s','s','T','o','k','e','n','\0'};
BOOL API_OpenProcessToken(HANDLE ProcessHandle,ULONG DesiredAccess,PHANDLE TokenHandle)
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(HANDLE,ULONG,PHANDLE);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,kpzmt); //��������
	if (addFun != NULL)
	{
		ret = addFun(ProcessHandle,DesiredAccess,TokenHandle);      //���ú���
	}
	return ret;
}

BOOL API_LookupPrivilegeValueW(LPCTSTR lpSystemName,LPCTSTR lpName,PLUID lpLuid)
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(LPCTSTR,LPCTSTR,PLUID);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"LookupPrivilegeValueW"); //��������
	if (addFun != NULL)
	{
		ret = addFun(lpSystemName,lpName,lpLuid);      //���ú���
	}
	return ret;
}

BOOL API_LookupPrivilegeValueA(LPCSTR lpSystemName,LPCSTR lpName,PLUID lpLuid)
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(LPCSTR,LPCSTR,PLUID);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"LookupPrivilegeValueA"); //��������
	if (addFun != NULL)
	{
		ret = addFun(lpSystemName,lpName,lpLuid);      //���ú���
	}
	return ret;
}

BOOL API_AdjustTokenPrivileges(
							   HANDLE TokenHandle,
							   BOOL DisableAllPrivileges,
							   PTOKEN_PRIVILEGES NewState,
							   ULONG BufferLength,
							   PTOKEN_PRIVILEGES PreviousState,
							   PDWORD ReturnLength)
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(HANDLE,BOOL,PTOKEN_PRIVILEGES,ULONG,PTOKEN_PRIVILEGES,PDWORD);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"AdjustTokenPrivileges"); //��������
	if (addFun != NULL)
	{
		ret = addFun(TokenHandle,DisableAllPrivileges,NewState,BufferLength,PreviousState,ReturnLength);      //���ú���
	}
	return ret;
}

NTSTATUS __stdcall API_LsaRetrievePrivateData
(
    IN LSA_HANDLE PolicyHandle,
    IN PLSA_UNICODE_STRING KeyName,
    OUT PLSA_UNICODE_STRING * PrivateData
    )
{
	NTSTATUS ret = NULL;
	typedef NTSTATUS (WINAPI *lpAddFun)(LSA_HANDLE,PLSA_UNICODE_STRING,PLSA_UNICODE_STRING);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"LsaRetrievePrivateData"); //��������
	if (addFun != NULL)
	{
		ret = addFun(PolicyHandle,KeyName,* PrivateData);//���ú���
	}
	return ret;
}

NTSTATUS __stdcall API_LsaOpenPolicy
(
    IN PLSA_UNICODE_STRING SystemName OPTIONAL,
    IN PLSA_OBJECT_ATTRIBUTES ObjectAttributes,
    IN ACCESS_MASK DesiredAccess,
    IN OUT PLSA_HANDLE PolicyHandle
    )
{
	NTSTATUS ret = NULL;
	typedef NTSTATUS (WINAPI *lpAddFun)(PLSA_UNICODE_STRING,PLSA_OBJECT_ATTRIBUTES,ACCESS_MASK,PLSA_HANDLE);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"LsaOpenPolicy"); //��������
	if (addFun != NULL)
	{
		ret = addFun(SystemName,ObjectAttributes,DesiredAccess,PolicyHandle);//���ú���
	}
	return ret;
}

NTSTATUS __stdcall API_LsaClose
(
    IN LSA_HANDLE ObjectHandle
    )
{
	NTSTATUS ret = NULL;
	typedef NTSTATUS (WINAPI *lpAddFun)(LSA_HANDLE);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"LsaClose"); //��������
	if (addFun != NULL)
	{
		ret = addFun(ObjectHandle);//���ú���
	}
	return ret;
}

NTSTATUS __stdcall API_LsaFreeMemory
(
    IN PVOID Buffer
    )
{
	NTSTATUS ret = NULL;
	typedef NTSTATUS (WINAPI *lpAddFun)(PVOID);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"LsaFreeMemory"); //��������
	if (addFun != NULL)
	{
		ret = addFun(Buffer);//���ú���
	}
	return ret;
}


char AqACR[] = {'R','e','g','C','l','o','s','e','K','e','y','\0'};
LONG
APIENTRY
API_RegCloseKey (
    IN HKEY hKey
    )
{
	LONG ret = NULL;
	typedef LONG (WINAPI *lpAddFun)(HKEY);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,AqACR); //��������
	if (addFun != NULL)
	{
		ret = addFun(hKey);//���ú���
	}
	return ret;
}


char KPpji[] = {'R','e','g','O','p','e','n','K','e','y','A','\0'};
LONG
APIENTRY
API_RegOpenKeyA (
    IN HKEY hKey,
    IN LPCSTR lpSubKey,
    OUT PHKEY phkResult
    )
{
	LONG ret = NULL;
	typedef LONG (WINAPI *lpAddFun)(HKEY,LPCSTR,PHKEY);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,KPpji); //��������
	if (addFun != NULL)
	{
		ret = addFun(hKey,lpSubKey,phkResult);//���ú���
	}
	return ret;
}


char MYcFW[] = {'S','e','t','S','e','r','v','i','c','e','S','t','a','t','u','s','\0'};
BOOL
WINAPI
API_SetServiceStatus(
    SERVICE_STATUS_HANDLE   hServiceStatus,
    LPSERVICE_STATUS        lpServiceStatus
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(SERVICE_STATUS_HANDLE,LPSERVICE_STATUS);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,MYcFW); //��������
	if (addFun != NULL)
	{
		ret = addFun(hServiceStatus,lpServiceStatus);      //���ú���
	}
	return ret;
}

BOOL
WINAPI
API_StartServiceCtrlDispatcherA(
    CONST SERVICE_TABLE_ENTRYA *lpServiceStartTable
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(CONST SERVICE_TABLE_ENTRYA *);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"StartServiceCtrlDispatcherA"); //��������
	if (addFun != NULL)
	{
		ret = addFun(lpServiceStartTable);      //���ú���
	}
	return ret;
}


char prNAJ[] = {'R','e','g','i','s','t','e','r','S','e','r','v','i','c','e','C','t','r','l','H','a','n','d','l','e','r','A','\0'};
SERVICE_STATUS_HANDLE
WINAPI
API_RegisterServiceCtrlHandlerA(
    LPCSTR             lpServiceName,
    LPHANDLER_FUNCTION   lpHandlerProc
    )
{
	SERVICE_STATUS_HANDLE ret = FALSE;
	typedef SERVICE_STATUS_HANDLE (WINAPI *lpAddFun)(LPCSTR,LPHANDLER_FUNCTION);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,prNAJ); //��������
	if (addFun != NULL)
	{
		ret = addFun(lpServiceName,lpHandlerProc);      //���ú���
	}
	return ret;
}

SERVICE_STATUS_HANDLE
WINAPI
API_RegisterServiceCtrlHandlerW(
    LPCWSTR             lpServiceName,
    LPHANDLER_FUNCTION   lpHandlerProc
    )
{
	SERVICE_STATUS_HANDLE ret = FALSE;
	typedef SERVICE_STATUS_HANDLE (WINAPI *lpAddFun)(LPCWSTR,LPHANDLER_FUNCTION);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"RegisterServiceCtrlHandlerW"); //��������
	if (addFun != NULL)
	{
		ret = addFun(lpServiceName,lpHandlerProc);      //���ú���
	}
	return ret;
}

BOOL
WINAPI
API_GetTokenInformation (
    IN HANDLE TokenHandle,
    IN TOKEN_INFORMATION_CLASS TokenInformationClass,
    OUT LPVOID TokenInformation,
    IN DWORD TokenInformationLength,
    OUT PDWORD ReturnLength
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(HANDLE,TOKEN_INFORMATION_CLASS,LPVOID,DWORD,PDWORD);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"GetTokenInformation"); //��������
	if (addFun != NULL)
	{
		ret = addFun(TokenHandle,TokenInformationClass,TokenInformation,TokenInformationLength,ReturnLength);      //���ú���
	}
	return ret;
}

BOOL
WINAPI
API_LookupAccountSidA(
    IN LPCSTR lpSystemName,
    IN PSID Sid,
    OUT LPSTR Name,
    IN OUT LPDWORD cbName,
    OUT LPSTR ReferencedDomainName,
    IN OUT LPDWORD cbReferencedDomainName,
    OUT PSID_NAME_USE peUse
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(LPCSTR,PSID,LPSTR,LPDWORD,LPSTR,LPDWORD,PSID_NAME_USE);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"LookupAccountSidA"); //��������
	if (addFun != NULL)
	{
		ret = addFun(lpSystemName,Sid,Name,cbName,ReferencedDomainName,cbReferencedDomainName,peUse);      //���ú���
	}
	return ret;
}

BOOL
WINAPI
API_IsValidSid (
    IN PSID pSid
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(PSID);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"IsValidSid"); //��������
	if (addFun != NULL)
	{
		ret = addFun(pSid);      //���ú���
	}
	return ret;
}

BOOL
WINAPI
API_LookupAccountNameA(
    IN LPCSTR lpSystemName,
    IN LPCSTR lpAccountName,
    OUT PSID Sid,
    IN OUT LPDWORD cbSid,
    OUT LPSTR ReferencedDomainName,
    IN OUT LPDWORD cbReferencedDomainName,
    OUT PSID_NAME_USE peUse
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(LPCSTR,LPCSTR,PSID,LPDWORD,LPSTR,LPDWORD,PSID_NAME_USE);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"LookupAccountNameA"); //��������
	if (addFun != NULL)
	{
		ret = addFun(lpSystemName,lpAccountName,Sid,cbSid,ReferencedDomainName,cbReferencedDomainName,peUse);      //���ú���
	}
	return ret;
}


char AwrKP[] = {'R','e','g','C','r','e','a','t','e','K','e','y','A','\0'};
LONG
APIENTRY
API_RegCreateKeyA (
    IN HKEY hKey,
    IN LPCSTR lpSubKey,
    OUT PHKEY phkResult
    )
{
	LONG ret = FALSE;
	typedef LONG (WINAPI *lpAddFun)(HKEY,LPCSTR,PHKEY);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,AwrKP); //��������
	if (addFun != NULL)
	{
		ret = addFun(hKey,lpSubKey,phkResult);      //���ú���
	}
	return ret;
}

LONG
APIENTRY
API_RegCreateKeyW (
    IN HKEY hKey,
    IN LPCWSTR lpSubKey,
    OUT PHKEY phkResult
    )
{
	LONG ret = FALSE;
	typedef LONG (WINAPI *lpAddFun)(HKEY,LPCWSTR,PHKEY);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"RegCreateKeyW"); //��������
	if (addFun != NULL)
	{
		ret = addFun(hKey,lpSubKey,phkResult);      //���ú���
	}
	return ret;
}


char EwSmd[] = {'R','e','g','C','r','e','a','t','e','K','e','y','E','x','A','\0'};
LONG
APIENTRY
API_RegCreateKeyExA (
    IN HKEY hKey,
    IN LPCSTR lpSubKey,
    IN DWORD Reserved,
    IN LPSTR lpClass,
    IN DWORD dwOptions,
    IN REGSAM samDesired,
    IN LPSECURITY_ATTRIBUTES lpSecurityAttributes,
    OUT PHKEY phkResult,
    OUT LPDWORD lpdwDisposition
    )
{
	LONG ret = FALSE;
	typedef LONG (WINAPI *lpAddFun)(HKEY,LPCSTR,DWORD,LPSTR,DWORD,REGSAM,LPSECURITY_ATTRIBUTES,PHKEY,LPDWORD);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,EwSmd); //��������
	if (addFun != NULL)
	{
		ret = addFun(hKey,lpSubKey,Reserved,lpClass,dwOptions,samDesired,lpSecurityAttributes,phkResult,lpdwDisposition);      //���ú���
	}
	return ret;
}


char pZzIL[] = {'I','n','i','t','i','a','l','i','z','e','S','e','c','u','r','i','t','y','D','e','s','c','r','i','p','t','o','r','\0'};
BOOL
WINAPI
API_InitializeSecurityDescriptor (
    OUT PSECURITY_DESCRIPTOR pSecurityDescriptor,
    IN DWORD dwRevision
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(PSECURITY_DESCRIPTOR,DWORD);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,pZzIL); //��������
	if (addFun != NULL)
	{
		ret = addFun(pSecurityDescriptor,dwRevision);      //���ú���
	}
	return ret;
}


char ikqCU[] = {'A','l','l','o','c','a','t','e','A','n','d','I','n','i','t','i','a','l','i','z','e','S','i','d','\0'};
BOOL
WINAPI
API_AllocateAndInitializeSid (
    IN PSID_IDENTIFIER_AUTHORITY pIdentifierAuthority,
    IN BYTE nSubAuthorityCount,
    IN DWORD nSubAuthority0,
    IN DWORD nSubAuthority1,
    IN DWORD nSubAuthority2,
    IN DWORD nSubAuthority3,
    IN DWORD nSubAuthority4,
    IN DWORD nSubAuthority5,
    IN DWORD nSubAuthority6,
    IN DWORD nSubAuthority7,
    OUT PSID *pSid
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(PSID_IDENTIFIER_AUTHORITY,BYTE,DWORD,DWORD,DWORD,DWORD,DWORD,DWORD,DWORD,DWORD,PSID *);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,ikqCU); //��������
	if (addFun != NULL)
	{
		ret = addFun(pIdentifierAuthority,nSubAuthorityCount,nSubAuthority0,nSubAuthority1,nSubAuthority2,nSubAuthority3,nSubAuthority4,nSubAuthority5,nSubAuthority6,nSubAuthority7,pSid);      //���ú���
	}
	return ret;
}


char TaSsD[] = {'O','p','e','n','S','e','r','v','i','c','e','A','\0'};
SC_HANDLE
WINAPI
API_OpenServiceA(
    SC_HANDLE   hSCManager,
    LPCSTR    lpServiceName,
    DWORD       dwDesiredAccess
    )
{
	SC_HANDLE ret = FALSE;
	typedef SC_HANDLE (WINAPI *lpAddFun)(SC_HANDLE,LPCSTR,DWORD);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,TaSsD); //��������
	if (addFun != NULL)
	{
		ret = addFun(hSCManager,lpServiceName,dwDesiredAccess);      //���ú���
	}
	return ret;
}


char YqOEu[] = {'S','t','a','r','t','S','e','r','v','i','c','e','A','\0'};
BOOL
WINAPI
API_StartServiceA(
    SC_HANDLE            hService,
    DWORD                dwNumServiceArgs,
    LPCSTR             *lpServiceArgVectors
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(SC_HANDLE,DWORD,LPCSTR             *);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,YqOEu); //��������
	if (addFun != NULL)
	{
		ret = addFun(hService,dwNumServiceArgs,lpServiceArgVectors);      //���ú���
	}
	return ret;
}

BOOL
WINAPI
API_StartServiceW(
    SC_HANDLE            hService,
    DWORD                dwNumServiceArgs,
    LPCWSTR             *lpServiceArgVectors
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(SC_HANDLE,DWORD,LPCWSTR             *);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"StartServiceW"); //��������
	if (addFun != NULL)
	{
		ret = addFun(hService,dwNumServiceArgs,lpServiceArgVectors);      //���ú���
	}
	return ret;
}


char SlVzj[] = {'O','p','e','n','S','C','M','a','n','a','g','e','r','A','\0'};
SC_HANDLE
WINAPI
API_OpenSCManagerA(
    LPCSTR lpMachineName,
    LPCSTR lpDatabaseName,
    DWORD   dwDesiredAccess
    )
{
	SC_HANDLE ret = FALSE;
	typedef SC_HANDLE (WINAPI *lpAddFun)(LPCSTR,LPCSTR,DWORD);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,SlVzj); //��������
	if (addFun != NULL)
	{
		ret = addFun(lpMachineName,lpDatabaseName,dwDesiredAccess);      //���ú���
	}
	return ret;
}


char PLqiL[] = {'C','r','e','a','t','e','S','e','r','v','i','c','e','A','\0'};
SC_HANDLE
WINAPI
API_CreateServiceA(
    SC_HANDLE    hSCManager,
    LPCSTR     lpServiceName,
    LPCSTR     lpDisplayName,
    DWORD        dwDesiredAccess,
    DWORD        dwServiceType,
    DWORD        dwStartType,
    DWORD        dwErrorControl,
    LPCSTR     lpBinaryPathName,
    LPCSTR     lpLoadOrderGroup,
    LPDWORD      lpdwTagId,
    LPCSTR     lpDependencies,
    LPCSTR     lpServiceStartName,
    LPCSTR     lpPassword
    )
{
	SC_HANDLE ret = FALSE;
	typedef SC_HANDLE (WINAPI *lpAddFun)(SC_HANDLE,LPCSTR,LPCSTR,DWORD,DWORD,DWORD,DWORD,LPCSTR,LPCSTR,LPDWORD,LPCSTR,LPCSTR,LPCSTR);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,PLqiL); //��������
	if (addFun != NULL)
	{
		ret = addFun(hSCManager,lpServiceName,lpDisplayName,dwDesiredAccess,dwServiceType,dwStartType,dwErrorControl,lpBinaryPathName,lpLoadOrderGroup,lpdwTagId,lpDependencies,lpServiceStartName,lpPassword);      //���ú���
	}
	return ret;
}

SC_HANDLE
WINAPI
API_CreateServiceW(
    SC_HANDLE    hSCManager,
    LPCWSTR     lpServiceName,
    LPCWSTR     lpDisplayName,
    DWORD        dwDesiredAccess,
    DWORD        dwServiceType,
    DWORD        dwStartType,
    DWORD        dwErrorControl,
    LPCWSTR     lpBinaryPathName,
    LPCWSTR     lpLoadOrderGroup,
    LPDWORD      lpdwTagId,
    LPCWSTR     lpDependencies,
    LPCWSTR     lpServiceStartName,
    LPCWSTR     lpPassword
    )
{
	SC_HANDLE ret = FALSE;
	typedef SC_HANDLE (WINAPI *lpAddFun)(SC_HANDLE,LPCWSTR,LPCWSTR,DWORD,DWORD,DWORD,DWORD,LPCWSTR,LPCWSTR,LPDWORD,LPCWSTR,LPCWSTR,LPCWSTR);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"CreateServiceW"); //��������
	if (addFun != NULL)
	{
		ret = addFun(hSCManager,lpServiceName,lpDisplayName,dwDesiredAccess,dwServiceType,dwStartType,dwErrorControl,lpBinaryPathName,lpLoadOrderGroup,lpdwTagId,lpDependencies,lpServiceStartName,lpPassword);      //���ú���
	}
	return ret;
}


char rtzID[] = {'C','l','o','s','e','S','e','r','v','i','c','e','H','a','n','d','l','e','\0'};
BOOL
WINAPI
API_CloseServiceHandle(
    SC_HANDLE   hSCObject
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(SC_HANDLE);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,rtzID); //��������
	if (addFun != NULL)
	{
		ret = addFun(hSCObject);      //���ú���
	}
	return ret;
}

BOOL
WINAPI
API_SetFileSecurityA (
    IN LPCSTR lpFileName,
    IN SECURITY_INFORMATION SecurityInformation,
    IN PSECURITY_DESCRIPTOR pSecurityDescriptor
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(LPCSTR,SECURITY_INFORMATION,PSECURITY_DESCRIPTOR);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"SetFileSecurityA"); //��������
	if (addFun != NULL)
	{
		ret = addFun(lpFileName,SecurityInformation,pSecurityDescriptor);      //���ú���
	}
	return ret;
}

BOOL
WINAPI
API_GetSecurityDescriptorDacl (
    IN PSECURITY_DESCRIPTOR pSecurityDescriptor,
    OUT LPBOOL lpbDaclPresent,
    OUT PACL *pDacl,
    OUT LPBOOL lpbDaclDefaulted
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(PSECURITY_DESCRIPTOR,LPBOOL,PACL *,LPBOOL);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"GetSecurityDescriptorDacl"); //��������
	if (addFun != NULL)
	{
		ret = addFun(pSecurityDescriptor,lpbDaclPresent,pDacl,lpbDaclDefaulted);      //���ú���
	}
	return ret;
}

BOOL
WINAPI
API_GetSecurityDescriptorControl (
    IN PSECURITY_DESCRIPTOR pSecurityDescriptor,
    OUT PSECURITY_DESCRIPTOR_CONTROL pControl,
    OUT LPDWORD lpdwRevision
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(PSECURITY_DESCRIPTOR,PSECURITY_DESCRIPTOR_CONTROL,LPDWORD);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"GetSecurityDescriptorControl"); //��������
	if (addFun != NULL)
	{
		ret = addFun(pSecurityDescriptor,pControl,lpdwRevision);      //���ú���
	}
	return ret;
}


char BDjsA[] = {'A','d','d','A','c','c','e','s','s','A','l','l','o','w','e','d','A','c','e','\0'};
BOOL
WINAPI
API_AddAccessAllowedAce (
    IN OUT PACL pAcl,
    IN DWORD dwAceRevision,
    IN DWORD AccessMask,
    IN PSID pSid
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(PACL,DWORD,DWORD,PSID);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,BDjsA); //��������
	if (addFun != NULL)
	{
		ret = addFun(pAcl,dwAceRevision,AccessMask,pSid);      //���ú���
	}
	return ret;
}


char NnMiY[] = {'S','e','t','S','e','c','u','r','i','t','y','D','e','s','c','r','i','p','t','o','r','D','a','c','l','\0'};
BOOL
WINAPI
API_SetSecurityDescriptorDacl (
    IN OUT PSECURITY_DESCRIPTOR pSecurityDescriptor,
    IN BOOL bDaclPresent,
    IN PACL pDacl,
    IN BOOL bDaclDefaulted
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(PSECURITY_DESCRIPTOR,BOOL,PACL,BOOL);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,NnMiY); //��������
	if (addFun != NULL)
	{
		ret = addFun(pSecurityDescriptor,bDaclPresent,pDacl,bDaclDefaulted);      //���ú���
	}
	return ret;
}

BOOL
WINAPI
API_EqualSid (
    IN PSID pSid1,
    IN PSID pSid2
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(PSID,PSID);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"EqualSid"); //��������
	if (addFun != NULL)
	{
		ret = addFun(pSid1,pSid2);      //���ú���
	}
	return ret;
}

BOOL
WINAPI
API_GetAce (
    IN PACL pAcl,
    IN DWORD dwAceIndex,
    OUT LPVOID *pAce
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(PACL,DWORD,LPVOID *);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"GetAce"); //��������
	if (addFun != NULL)
	{
		ret = addFun(pAcl,dwAceIndex,pAce);      //���ú���
	}
	return ret;
}

BOOL
WINAPI
API_AddAce (
    IN OUT PACL pAcl,
    IN DWORD dwAceRevision,
    IN DWORD dwStartingAceIndex,
    IN LPVOID pAceList,
    IN DWORD nAceListLength
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(PACL,DWORD,DWORD,LPVOID,DWORD);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"AddAce"); //��������
	if (addFun != NULL)
	{
		ret = addFun(pAcl,dwAceRevision,dwStartingAceIndex,pAceList,nAceListLength);      //���ú���
	}
	return ret;
}

char oYerh[] = {'I','n','i','t','i','a','l','i','z','e','A','c','l','\0'};
BOOL
WINAPI
API_InitializeAcl (
    OUT PACL pAcl,
    IN DWORD nAclLength,
    IN DWORD dwAclRevision
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(PACL,DWORD,DWORD);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,oYerh); //��������
	if (addFun != NULL)
	{
		ret = addFun(pAcl,nAclLength,dwAclRevision);      //���ú���
	}
	return ret;
}


char pFhFQ[] = {'G','e','t','L','e','n','g','t','h','S','i','d','\0'};
DWORD
WINAPI
API_GetLengthSid (
    IN PSID pSid
    )
{
	DWORD ret = FALSE;
	typedef DWORD (WINAPI *lpAddFun)(PSID);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,pFhFQ); //��������
	if (addFun != NULL)
	{
		ret = addFun(pSid);      //���ú���
	}
	return ret;
}

BOOL
WINAPI
API_GetAclInformation (
    IN PACL pAcl,
    OUT LPVOID pAclInformation,
    IN DWORD nAclInformationLength,
    IN ACL_INFORMATION_CLASS dwAclInformationClass
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(PACL,LPVOID,DWORD,ACL_INFORMATION_CLASS);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"GetAclInformation"); //��������
	if (addFun != NULL)
	{
		ret = addFun(pAcl,pAclInformation,nAclInformationLength,dwAclInformationClass);      //���ú���
	}
	return ret;
}

BOOL
WINAPI
API_GetFileSecurityA (
    IN LPCSTR lpFileName,
    IN SECURITY_INFORMATION RequestedInformation,
    OUT PSECURITY_DESCRIPTOR pSecurityDescriptor,
    IN DWORD nLength,
    OUT LPDWORD lpnLengthNeeded
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(LPCSTR,SECURITY_INFORMATION,PSECURITY_DESCRIPTOR,DWORD,LPDWORD);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"GetFileSecurityA"); //��������
	if (addFun != NULL)
	{
		ret = addFun(lpFileName,RequestedInformation,pSecurityDescriptor,nLength,lpnLengthNeeded);      //���ú���
	}
	return ret;
}

BOOL
WINAPI
API_GetUserNameA (
    OUT LPSTR lpBuffer,
    IN OUT LPDWORD nSize
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(LPSTR,LPDWORD);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"GetUserNameA"); //��������
	if (addFun != NULL)
	{
		ret = addFun(lpBuffer,nSize);      //���ú���
	}
	return ret;
}


char TKHSo[] = {'R','e','g','D','e','l','e','t','e','V','a','l','u','e','A','\0'};
LONG
APIENTRY
API_RegDeleteValueA (
    IN HKEY hKey,
    IN LPCSTR lpValueName
    )
{
	LONG ret = FALSE;
	typedef LONG (WINAPI *lpAddFun)(HKEY,LPCSTR);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,TKHSo); //��������
	if (addFun != NULL)
	{
		ret = addFun(hKey,lpValueName);      //���ú���
	}
	return ret;
}

LONG
APIENTRY
API_RegSetValueA (
    IN HKEY hKey,
    IN LPCSTR lpSubKey,
    IN DWORD dwType,
    IN LPCSTR lpData,
    IN DWORD cbData
    )
{
	LONG ret = FALSE;
	typedef LONG (WINAPI *lpAddFun)(HKEY,LPCSTR,DWORD,LPCSTR,DWORD);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"RegSetValueA"); //��������
	if (addFun != NULL)
	{
		ret = addFun(hKey,lpSubKey,dwType,lpData,cbData);      //���ú���
	}
	return ret;
}

char ETMgW[] = {'R','e','g','S','e','t','V','a','l','u','e','E','x','A','\0'};
LONG
APIENTRY
API_RegSetValueExA (
    IN HKEY hKey,
    IN LPCSTR lpValueName,
    IN DWORD Reserved,
    IN DWORD dwType,
    IN CONST BYTE* lpData,
    IN DWORD cbData
    )
{
	LONG ret = FALSE;
	typedef LONG (WINAPI *lpAddFun)(HKEY,LPCSTR,DWORD,DWORD,CONST BYTE* ,DWORD);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,ETMgW); //��������
	if (addFun != NULL)
	{
		ret = addFun(hKey,lpValueName,Reserved,dwType,lpData,cbData);      //���ú���
	}
	return ret;
}

LONG
APIENTRY
API_RegSetValueExW (
    IN HKEY hKey,
    IN LPCWSTR lpValueName,
    IN DWORD Reserved,
    IN DWORD dwType,
    IN CONST BYTE* lpData,
    IN DWORD cbData
    )
{
	LONG ret = FALSE;
	typedef LONG (WINAPI *lpAddFun)(HKEY,LPCWSTR,DWORD,DWORD,CONST BYTE* ,DWORD);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"RegSetValueExW"); //��������
	if (addFun != NULL)
	{
		ret = addFun(hKey,lpValueName,Reserved,dwType,lpData,cbData);      //���ú���
	}
	return ret;
}


char XqRVR[] = {'R','e','g','D','e','l','e','t','e','K','e','y','A','\0'};
LONG
APIENTRY
API_RegDeleteKeyA (
    IN HKEY hKey,
    IN LPCSTR lpSubKey
    )
{
	LONG ret = FALSE;
	typedef LONG (WINAPI *lpAddFun)(HKEY,LPCSTR);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,XqRVR); //��������
	if (addFun != NULL)
	{
		ret = addFun(hKey,lpSubKey);      //���ú���
	}
	return ret;
}

LONG
APIENTRY
API_RegDeleteKeyW (
    IN HKEY hKey,
    IN LPCWSTR lpSubKey
    )
{
	LONG ret = FALSE;
	typedef LONG (WINAPI *lpAddFun)(HKEY,LPCWSTR);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"RegDeleteKeyW"); //��������
	if (addFun != NULL)
	{
		ret = addFun(hKey,lpSubKey);      //���ú���
	}
	return ret;
}


char jOTfy[] = {'R','e','g','O','p','e','n','K','e','y','E','x','A','\0'};
LONG
APIENTRY
API_RegOpenKeyExA (
    IN HKEY hKey,
    IN LPCSTR lpSubKey,
    IN DWORD ulOptions,
    IN REGSAM samDesired,
    OUT PHKEY phkResult
    )
{
	LONG ret = FALSE;
	typedef LONG (WINAPI *lpAddFun)(HKEY,LPCSTR,DWORD,REGSAM,PHKEY);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,jOTfy); //��������
	if (addFun != NULL)
	{
		ret = addFun(hKey,lpSubKey,ulOptions,samDesired,phkResult);      //���ú���
	}
	return ret;
}

LONG
APIENTRY
API_RegOpenKeyExW (
    IN HKEY hKey,
    IN LPCWSTR lpSubKey,
    IN DWORD ulOptions,
    IN REGSAM samDesired,
    OUT PHKEY phkResult
    )
{
	LONG ret = FALSE;
	typedef LONG (WINAPI *lpAddFun)(HKEY,LPCWSTR,DWORD,REGSAM,PHKEY);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"RegOpenKeyExW"); //��������
	if (addFun != NULL)
	{
		ret = addFun(hKey,lpSubKey,ulOptions,samDesired,phkResult);      //���ú���
	}
	return ret;
}


char rbVIJ[] = {'R','e','g','Q','u','e','r','y','V','a','l','u','e','E','x','A','\0'};
LONG
APIENTRY
API_RegQueryValueExA (
    IN HKEY hKey,
    IN LPCSTR lpValueName,
    IN LPDWORD lpReserved,
    OUT LPDWORD lpType,
    IN OUT LPBYTE lpData,
    IN OUT LPDWORD lpcbData
    )
{
	LONG ret = FALSE;
	typedef LONG (WINAPI *lpAddFun)(HKEY,LPCSTR,LPDWORD,LPDWORD,LPBYTE,LPDWORD);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,rbVIJ); //��������
	if (addFun != NULL)
	{
		ret = addFun(hKey,lpValueName,lpReserved,lpType,lpData,lpcbData);      //���ú���
	}
	return ret;
}

LONG
APIENTRY
API_RegQueryValueExW (
    IN HKEY hKey,
    IN LPCWSTR lpValueName,
    IN LPDWORD lpReserved,
    OUT LPDWORD lpType,
    IN OUT LPBYTE lpData,
    IN OUT LPDWORD lpcbData
    )
{
	LONG ret = FALSE;
	typedef LONG (WINAPI *lpAddFun)(HKEY,LPCWSTR,LPDWORD,LPDWORD,LPBYTE,LPDWORD);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"RegQueryValueExW"); //��������
	if (addFun != NULL)
	{
		ret = addFun(hKey,lpValueName,lpReserved,lpType,lpData,lpcbData);      //���ú���
	}
	return ret;
}


char Qraeq[] = {'R','e','g','S','a','v','e','K','e','y','A','\0'};
LONG
APIENTRY
API_RegSaveKeyA (
    IN HKEY hKey,
    IN LPCSTR lpFile,
    IN LPSECURITY_ATTRIBUTES lpSecurityAttributes
    )
{
	LONG ret = FALSE;
	typedef LONG (WINAPI *lpAddFun)(HKEY,LPCSTR,LPSECURITY_ATTRIBUTES);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,Qraeq); //��������
	if (addFun != NULL)
	{
		ret = addFun(hKey,lpFile,lpSecurityAttributes);      //���ú���
	}
	return ret;
}


char ShCZZ[] = {'R','e','g','R','e','s','t','o','r','e','K','e','y','A','\0'};
LONG
APIENTRY
API_RegRestoreKeyA (
    IN HKEY hKey,
    IN LPCSTR lpFile,
    IN DWORD   dwFlags
    )
{
	LONG ret = FALSE;
	typedef LONG (WINAPI *lpAddFun)(HKEY,LPCSTR,DWORD);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,ShCZZ); //��������
	if (addFun != NULL)
	{
		ret = addFun(hKey,lpFile,dwFlags);      //���ú���
	}
	return ret;
}


char lkabz[] = {'R','e','g','Q','u','e','r','y','V','a','l','u','e','A','\0'};
LONG
APIENTRY
API_RegQueryValueA (
    IN HKEY hKey,
    IN LPCSTR lpSubKey,
    OUT LPSTR lpValue,
    IN OUT PLONG   lpcbValue
    )
{
	LONG ret = FALSE;
	typedef LONG (WINAPI *lpAddFun)(HKEY,LPCSTR,LPSTR,PLONG);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,lkabz); //��������
	if (addFun != NULL)
	{
		ret = addFun(hKey,lpSubKey,lpValue,lpcbValue);      //���ú���
	}
	return ret;
}


char AIqYX[] = {'D','e','l','e','t','e','S','e','r','v','i','c','e','\0'};
BOOL
WINAPI
API_DeleteService(
    SC_HANDLE   hService
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(SC_HANDLE);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,AIqYX); //��������
	if (addFun != NULL)
	{
		ret = addFun(hService);      //���ú���
	}
	return ret;
}


char sscte[] = {'R','e','g','E','n','u','m','K','e','y','E','x','A','\0'};
LONG
APIENTRY
API_RegEnumKeyExA (
    IN HKEY hKey,
    IN DWORD dwIndex,
    OUT LPSTR lpName,
    IN OUT LPDWORD lpcbName,
    IN LPDWORD lpReserved,
    IN OUT LPSTR lpClass,
    IN OUT LPDWORD lpcbClass,
    OUT PFILETIME lpftLastWriteTime
    )
{
	LONG ret = FALSE;
	typedef LONG (WINAPI *lpAddFun)(HKEY,DWORD,LPSTR,LPDWORD,LPDWORD,LPSTR,LPDWORD,PFILETIME);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,sscte); //��������
	if (addFun != NULL)
	{
		ret = addFun(hKey,dwIndex,lpName,lpcbName,lpReserved,lpClass,lpcbClass,lpftLastWriteTime);      //���ú���
	}
	return ret;
}


char iIcoy[] = {'R','e','g','E','n','u','m','V','a','l','u','e','A','\0'};
LONG
APIENTRY
API_RegEnumValueA (
    IN HKEY hKey,
    IN DWORD dwIndex,
    OUT LPSTR lpValueName,
    IN OUT LPDWORD lpcbValueName,
    IN LPDWORD lpReserved,
    OUT LPDWORD lpType,
    OUT LPBYTE lpData,
    IN OUT LPDWORD lpcbData
    )
{
	LONG ret = FALSE;
	typedef LONG (WINAPI *lpAddFun)(HKEY,DWORD,LPSTR,LPDWORD,LPDWORD,LPDWORD,LPBYTE,LPDWORD);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,iIcoy); //��������
	if (addFun != NULL)
	{
		ret = addFun(hKey,dwIndex,lpValueName,lpcbValueName,lpReserved,lpType,lpData,lpcbData);      //���ú���
	}
	return ret;
}


char tsNQI[] = {'C','o','n','t','r','o','l','S','e','r','v','i','c','e','\0'};
BOOL
WINAPI
API_ControlService(
    SC_HANDLE           hService,
    DWORD               dwControl,
    LPSERVICE_STATUS    lpServiceStatus
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(SC_HANDLE,DWORD,LPSERVICE_STATUS);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,tsNQI); //��������
	if (addFun != NULL)
	{
		ret = addFun(hService,dwControl,lpServiceStatus);      //���ú���
	}
	return ret;
}


char uSfqs[] = {'Q','u','e','r','y','S','e','r','v','i','c','e','S','t','a','t','u','s','\0'};
BOOL
WINAPI
API_QueryServiceStatus(
    SC_HANDLE           hService,
    LPSERVICE_STATUS    lpServiceStatus
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(SC_HANDLE,LPSERVICE_STATUS);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,uSfqs); //��������
	if (addFun != NULL)
	{
		ret = addFun(hService,lpServiceStatus);      //���ú���
	}
	return ret;
}


char FvJgs[] = {'F','r','e','e','S','i','d','\0'};
PVOID
WINAPI
API_FreeSid(
    IN PSID pSid
    )
{
	PVOID ret = FALSE;
	typedef PVOID (WINAPI *lpAddFun)(PSID);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,FvJgs); //��������
	if (addFun != NULL)
	{
		ret = addFun(pSid);      //���ú���
	}
	return ret;
}


char oDUoz[] = {'O','p','e','n','E','v','e','n','t','L','o','g','A','\0'};
HANDLE
WINAPI
API_OpenEventLogA (
    IN LPCSTR lpUNCServerName,
    IN LPCSTR lpSourceName
    )
{
	HANDLE ret = FALSE;
	typedef HANDLE (WINAPI *lpAddFun)(LPCSTR,LPCSTR);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,oDUoz); //��������
	if (addFun != NULL)
	{
		ret = addFun(lpUNCServerName,lpSourceName);      //���ú���
	}
	return ret;
}


char uLHXQ[] = {'C','l','e','a','r','E','v','e','n','t','L','o','g','A','\0'};
BOOL
WINAPI
API_ClearEventLogA (
    IN HANDLE hEventLog,
    IN LPCSTR lpBackupFileName
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(HANDLE,LPCSTR);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,uLHXQ); //��������
	if (addFun != NULL)
	{
		ret = addFun(hEventLog,lpBackupFileName);      //���ú���
	}
	return ret;
}


char rskSl[] = {'C','l','o','s','e','E','v','e','n','t','L','o','g','\0'};
BOOL
WINAPI
API_CloseEventLog (
    IN OUT HANDLE hEventLog
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(HANDLE);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,rskSl); //��������
	if (addFun != NULL)
	{
		ret = addFun(hEventLog);      //���ú���
	}
	return ret;
}

//BOOL
//WINAPI
//API_CreateWellKnownSid(
//    IN WELL_KNOWN_SID_TYPE WellKnownSidType,
//    IN PSID DomainSid  OPTIONAL,
//    OUT PSID pSid,
//    IN OUT DWORD *cbSid
//    )
//{
//	BOOL ret = FALSE;
//	typedef BOOL (WINAPI *lpAddFun)(WELL_KNOWN_SID_TYPE,PSID,PSID,DWORD *);    //����ֵ,�β����Ͳο���������
//	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
//	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"CreateWellKnownSid"); //��������
//	if (addFun != NULL)
//	{
//		ret = addFun(WellKnownSidType,DomainSid,pSid,cbSid);      //���ú���
//	}
//	return ret;
//}

BOOL
WINAPI
API_CheckTokenMembership(
    IN HANDLE TokenHandle OPTIONAL,
    IN PSID SidToCheck,
    OUT PBOOL IsMember
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(HANDLE,PSID,PBOOL);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"CheckTokenMembership"); //��������
	if (addFun != NULL)
	{
		ret = addFun(TokenHandle,SidToCheck,IsMember);      //���ú���
	}
	return ret;
}

BOOL
WINAPI
API_SetTokenInformation (
    IN HANDLE TokenHandle,
    IN TOKEN_INFORMATION_CLASS TokenInformationClass,
    IN LPVOID TokenInformation,
    IN DWORD TokenInformationLength
    )
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(HANDLE,TOKEN_INFORMATION_CLASS,LPVOID,DWORD);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"SetTokenInformation"); //��������
	if (addFun != NULL)
	{
		ret = addFun(TokenHandle,TokenInformationClass,TokenInformation,TokenInformationLength);      //���ú���
	}
	return ret;
}

BOOL
WINAPI
API_DuplicateTokenEx(
    IN HANDLE hExistingToken,
    IN DWORD dwDesiredAccess,
    IN LPSECURITY_ATTRIBUTES lpTokenAttributes,
    IN SECURITY_IMPERSONATION_LEVEL ImpersonationLevel,
    IN TOKEN_TYPE TokenType,
    OUT PHANDLE phNewToken)
{
	BOOL ret = FALSE;
	typedef BOOL (WINAPI *lpAddFun)(HANDLE,DWORD,LPSECURITY_ATTRIBUTES,SECURITY_IMPERSONATION_LEVEL,TOKEN_TYPE,PHANDLE);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"DuplicateTokenEx"); //��������
	if (addFun != NULL)
	{
		ret = addFun(hExistingToken,dwDesiredAccess,lpTokenAttributes,ImpersonationLevel,TokenType,phNewToken);      //���ú���
	}
	return ret;
}

BOOL
WINAPI
API_CreateProcessAsUserA (
    IN HANDLE hToken,
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
	typedef BOOL (WINAPI *lpAddFun)(HANDLE,LPCSTR,LPSTR,LPSECURITY_ATTRIBUTES,LPSECURITY_ATTRIBUTES,BOOL,DWORD,LPVOID,LPCSTR,LPSTARTUPINFOA,LPPROCESS_INFORMATION);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"advapi32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,"CreateProcessAsUserA"); //��������
	if (addFun != NULL)
	{
		ret = addFun(hToken,lpApplicationName,lpCommandLine,lpProcessAttributes,lpThreadAttributes,bInheritHandles,dwCreationFlags,lpEnvironment,lpCurrentDirectory,lpStartupInfo,lpProcessInformation);      //���ú���
	}
	return ret;
}