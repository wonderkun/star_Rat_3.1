#pragma once

#include <winbase.h>
#include <windows.h>
#include <ntsecapi.h>
#include <winreg.h>
#include <winsvc.h>

typedef LONG NTSTATUS;

SC_HANDLE API_OpenSCManagerW(LPCWSTR lpMachineName,LPCWSTR lpDatabaseName,DWORD dwDesiredAccess);

SC_HANDLE API_OpenServiceW(SC_HANDLE hSCManager,LPCWSTR lpServiceName,DWORD dwDesiredAccess);

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
							  );

BOOL API_OpenProcessToken(HANDLE ProcessHandle,ULONG DesiredAccess,PHANDLE TokenHandle);

BOOL API_LookupPrivilegeValueW(LPCTSTR lpSystemName,LPCTSTR lpName,PLUID lpLuid);

BOOL API_LookupPrivilegeValueA(LPCSTR lpSystemName,LPCSTR lpName,PLUID lpLuid);

BOOL API_AdjustTokenPrivileges(
							   HANDLE TokenHandle,
							   BOOL DisableAllPrivileges,
							   PTOKEN_PRIVILEGES NewState,
							   ULONG BufferLength,
							   PTOKEN_PRIVILEGES PreviousState,
							   PDWORD ReturnLength);

NTSTATUS __stdcall API_LsaRetrievePrivateData(
    IN LSA_HANDLE PolicyHandle,
    IN PLSA_UNICODE_STRING KeyName,
    OUT PLSA_UNICODE_STRING * PrivateData
    );

NTSTATUS __stdcall API_LsaOpenPolicy
(
    IN PLSA_UNICODE_STRING SystemName OPTIONAL,
    IN PLSA_OBJECT_ATTRIBUTES ObjectAttributes,
    IN ACCESS_MASK DesiredAccess,
    IN OUT PLSA_HANDLE PolicyHandle
    );

NTSTATUS __stdcall API_LsaClose
(
    IN LSA_HANDLE ObjectHandle
    );

NTSTATUS __stdcall API_LsaFreeMemory
(
    IN PVOID Buffer
    );

LONG
APIENTRY
API_RegCloseKey (
    IN HKEY hKey
    );

LONG
APIENTRY
API_RegOpenKeyA (
    IN HKEY hKey,
    IN LPCSTR lpSubKey,
    OUT PHKEY phkResult
    );

BOOL
WINAPI
API_SetServiceStatus(
    SERVICE_STATUS_HANDLE   hServiceStatus,
    LPSERVICE_STATUS        lpServiceStatus
    );

BOOL
WINAPI
API_StartServiceCtrlDispatcherA(
    CONST SERVICE_TABLE_ENTRYA *lpServiceStartTable
    );

SERVICE_STATUS_HANDLE
WINAPI
API_RegisterServiceCtrlHandlerA(
    LPCSTR             lpServiceName,
    LPHANDLER_FUNCTION   lpHandlerProc
    );

SERVICE_STATUS_HANDLE
WINAPI
API_RegisterServiceCtrlHandlerW(
    LPCWSTR             lpServiceName,
    LPHANDLER_FUNCTION   lpHandlerProc
    );

BOOL
WINAPI
API_GetTokenInformation (
    IN HANDLE TokenHandle,
    IN TOKEN_INFORMATION_CLASS TokenInformationClass,
    OUT LPVOID TokenInformation,
    IN DWORD TokenInformationLength,
    OUT PDWORD ReturnLength
    );

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
    );

BOOL
WINAPI
API_IsValidSid (
    IN PSID pSid
    );

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
    );

LONG
APIENTRY
API_RegCreateKeyA (
    IN HKEY hKey,
    IN LPCSTR lpSubKey,
    OUT PHKEY phkResult
    );

LONG
APIENTRY
API_RegCreateKeyW (
    IN HKEY hKey,
    IN LPCWSTR lpSubKey,
    OUT PHKEY phkResult
    );

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
    );

BOOL
WINAPI
API_InitializeSecurityDescriptor (
    OUT PSECURITY_DESCRIPTOR pSecurityDescriptor,
    IN DWORD dwRevision
    );

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
    );

SC_HANDLE
WINAPI
API_OpenServiceA(
    SC_HANDLE   hSCManager,
    LPCSTR    lpServiceName,
    DWORD       dwDesiredAccess
    );

BOOL
WINAPI
API_StartServiceA(
    SC_HANDLE            hService,
    DWORD                dwNumServiceArgs,
    LPCSTR             *lpServiceArgVectors
    );

BOOL
WINAPI
API_StartServiceW(
    SC_HANDLE            hService,
    DWORD                dwNumServiceArgs,
    LPCWSTR             *lpServiceArgVectors
    );

SC_HANDLE
WINAPI
API_OpenSCManagerA(
    LPCSTR lpMachineName,
    LPCSTR lpDatabaseName,
    DWORD   dwDesiredAccess
    );

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
    );

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
    );

BOOL
WINAPI
API_CloseServiceHandle(
    SC_HANDLE   hSCObject
    );

BOOL
WINAPI
API_SetFileSecurityA (
    IN LPCSTR lpFileName,
    IN SECURITY_INFORMATION SecurityInformation,
    IN PSECURITY_DESCRIPTOR pSecurityDescriptor
    );

BOOL
WINAPI
API_GetSecurityDescriptorDacl (
    IN PSECURITY_DESCRIPTOR pSecurityDescriptor,
    OUT LPBOOL lpbDaclPresent,
    OUT PACL *pDacl,
    OUT LPBOOL lpbDaclDefaulted
    );

BOOL
WINAPI
API_GetSecurityDescriptorControl (
    IN PSECURITY_DESCRIPTOR pSecurityDescriptor,
    OUT PSECURITY_DESCRIPTOR_CONTROL pControl,
    OUT LPDWORD lpdwRevision
    );

BOOL
WINAPI
API_AddAccessAllowedAce (
    IN OUT PACL pAcl,
    IN DWORD dwAceRevision,
    IN DWORD AccessMask,
    IN PSID pSid
    );

BOOL
WINAPI
API_SetSecurityDescriptorDacl (
    IN OUT PSECURITY_DESCRIPTOR pSecurityDescriptor,
    IN BOOL bDaclPresent,
    IN PACL pDacl,
    IN BOOL bDaclDefaulted
    );

BOOL
WINAPI
API_EqualSid (
    IN PSID pSid1,
    IN PSID pSid2
    );

BOOL
WINAPI
API_GetAce (
    IN PACL pAcl,
    IN DWORD dwAceIndex,
    OUT LPVOID *pAce
    );

BOOL
WINAPI
API_AddAce (
    IN OUT PACL pAcl,
    IN DWORD dwAceRevision,
    IN DWORD dwStartingAceIndex,
    IN LPVOID pAceList,
    IN DWORD nAceListLength
    );

BOOL
WINAPI
API_InitializeAcl (
    OUT PACL pAcl,
    IN DWORD nAclLength,
    IN DWORD dwAclRevision
    );

DWORD
WINAPI
API_GetLengthSid (
    IN PSID pSid
    );

BOOL
WINAPI
API_GetAclInformation (
    IN PACL pAcl,
    OUT LPVOID pAclInformation,
    IN DWORD nAclInformationLength,
    IN ACL_INFORMATION_CLASS dwAclInformationClass
    );

BOOL
WINAPI
API_GetFileSecurityA (
    IN LPCSTR lpFileName,
    IN SECURITY_INFORMATION RequestedInformation,
    OUT PSECURITY_DESCRIPTOR pSecurityDescriptor,
    IN DWORD nLength,
    OUT LPDWORD lpnLengthNeeded
    );

BOOL
WINAPI
API_GetUserNameA (
    OUT LPSTR lpBuffer,
    IN OUT LPDWORD nSize
    );

LONG
APIENTRY
API_RegDeleteValueA (
    IN HKEY hKey,
    IN LPCSTR lpValueName
    );

LONG
APIENTRY
API_RegSetValueA (
    IN HKEY hKey,
    IN LPCSTR lpSubKey,
    IN DWORD dwType,
    IN LPCSTR lpData,
    IN DWORD cbData
    );

LONG
APIENTRY
API_RegSetValueExA (
    IN HKEY hKey,
    IN LPCSTR lpValueName,
    IN DWORD Reserved,
    IN DWORD dwType,
    IN CONST BYTE* lpData,
    IN DWORD cbData
    );

LONG
APIENTRY
API_RegSetValueExW (
    IN HKEY hKey,
    IN LPCWSTR lpValueName,
    IN DWORD Reserved,
    IN DWORD dwType,
    IN CONST BYTE* lpData,
    IN DWORD cbData
    );

LONG
APIENTRY
API_RegDeleteKeyA (
    IN HKEY hKey,
    IN LPCSTR lpSubKey
    );

LONG
APIENTRY
API_RegDeleteKeyW (
    IN HKEY hKey,
    IN LPCWSTR lpSubKey
    );

LONG
APIENTRY
API_RegOpenKeyExA (
    IN HKEY hKey,
    IN LPCSTR lpSubKey,
    IN DWORD ulOptions,
    IN REGSAM samDesired,
    OUT PHKEY phkResult
    );

LONG
APIENTRY
API_RegOpenKeyExW (
    IN HKEY hKey,
    IN LPCWSTR lpSubKey,
    IN DWORD ulOptions,
    IN REGSAM samDesired,
    OUT PHKEY phkResult
    );

LONG
APIENTRY
API_RegQueryValueExA (
    IN HKEY hKey,
    IN LPCSTR lpValueName,
    IN LPDWORD lpReserved,
    OUT LPDWORD lpType,
    IN OUT LPBYTE lpData,
    IN OUT LPDWORD lpcbData
    );

LONG
APIENTRY
API_RegQueryValueExW (
    IN HKEY hKey,
    IN LPCWSTR lpValueName,
    IN LPDWORD lpReserved,
    OUT LPDWORD lpType,
    IN OUT LPBYTE lpData,
    IN OUT LPDWORD lpcbData
    );

LONG
APIENTRY
API_RegSaveKeyA (
    IN HKEY hKey,
    IN LPCSTR lpFile,
    IN LPSECURITY_ATTRIBUTES lpSecurityAttributes
    );

LONG
APIENTRY
API_RegRestoreKeyA (
    IN HKEY hKey,
    IN LPCSTR lpFile,
    IN DWORD   dwFlags
    );

LONG
APIENTRY
API_RegQueryValueA (
    IN HKEY hKey,
    IN LPCSTR lpSubKey,
    OUT LPSTR lpValue,
    IN OUT PLONG   lpcbValue
    );

BOOL
WINAPI
API_DeleteService(
    SC_HANDLE   hService
    );

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
    );

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
    );

BOOL
WINAPI
API_ControlService(
    SC_HANDLE           hService,
    DWORD               dwControl,
    LPSERVICE_STATUS    lpServiceStatus
    );

BOOL
WINAPI
API_QueryServiceStatus(
    SC_HANDLE           hService,
    LPSERVICE_STATUS    lpServiceStatus
    );

PVOID
WINAPI
API_FreeSid(
    IN PSID pSid
    );

HANDLE
WINAPI
API_OpenEventLogA (
    IN LPCSTR lpUNCServerName,
    IN LPCSTR lpSourceName
    );

BOOL
WINAPI
API_ClearEventLogA (
    IN HANDLE hEventLog,
    IN LPCSTR lpBackupFileName
    );

BOOL
WINAPI
API_CloseEventLog (
    IN OUT HANDLE hEventLog
    );

//BOOL
//WINAPI
//API_CreateWellKnownSid(
//    IN WELL_KNOWN_SID_TYPE WellKnownSidType,
//    IN PSID DomainSid  OPTIONAL,
//    OUT PSID pSid,
//    IN OUT DWORD *cbSid
//    );

BOOL
WINAPI
API_CheckTokenMembership(
    IN HANDLE TokenHandle OPTIONAL,
    IN PSID SidToCheck,
    OUT PBOOL IsMember
    );

BOOL
WINAPI
API_SetTokenInformation (
    IN HANDLE TokenHandle,
    IN TOKEN_INFORMATION_CLASS TokenInformationClass,
    IN LPVOID TokenInformation,
    IN DWORD TokenInformationLength
    );

BOOL
WINAPI
API_DuplicateTokenEx(
    IN HANDLE hExistingToken,
    IN DWORD dwDesiredAccess,
    IN LPSECURITY_ATTRIBUTES lpTokenAttributes,
    IN SECURITY_IMPERSONATION_LEVEL ImpersonationLevel,
    IN TOKEN_TYPE TokenType,
    OUT PHANDLE phNewToken);

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
    );