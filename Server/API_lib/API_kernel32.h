#pragma once

#include <TLHELP32.H>



LPWSTR API_lstrcatW(LPWSTR lpString1,LPCWSTR lpString2);

LPSTR
WINAPI
API_lstrcatA(
    IN OUT LPSTR lpString1,
    IN LPCSTR lpString2
    );

LPWSTR
WINAPI
API_lstrcpyW(
    OUT LPWSTR lpString1,
    IN LPCWSTR lpString2
    );

LPSTR
WINAPI
API_lstrcpyA(
    OUT LPSTR lpString1,
    IN LPCSTR lpString2
    );

UINT
WINAPI
API_GetSystemDirectoryA(
    OUT LPSTR lpBuffer,
    IN UINT uSize
    );

UINT API_GetSystemDirectoryW(LPWSTR lpBuffer,UINT uSize);

DWORD
WINAPI
API_GetTempPathA(
    IN DWORD nBufferLength,
    OUT LPSTR lpBuffer
    );

DWORD API_GetTempPathW(DWORD nBufferLength, LPWSTR lpBuffer);

DWORD API_GetCurrentThreadId(VOID);

DWORD
WINAPI
API_GetModuleFileNameA(
    IN HMODULE hModule,
    OUT LPSTR lpFilename,
    IN DWORD nSize
    );

DWORD API_GetModuleFileNameW(HMODULE hModule,LPWSTR lpFilename,DWORD nSize);

HRSRC API_FindResourceA(HMODULE hModule,LPCSTR lpName,LPCSTR lpType);

HRSRC
WINAPI
API_FindResourceW(
    IN HMODULE hModule,
    IN LPCWSTR lpName,
    IN LPCWSTR lpType
    );

HGLOBAL API_LoadResource(HMODULE hModule,HRSRC hResInfo);

DWORD API_SizeofResource(HMODULE hModule,HRSRC hResInfo);

LPVOID API_LockResource(HGLOBAL hResData);

BOOL
WINAPI
API_FreeResource(
        IN HGLOBAL hResData
        );

HANDLE API_CreateToolhelp32Snapshot(DWORD dwFlags,DWORD th32ProcessID);

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
    );

HANDLE
API_CreateFileW(
    IN LPCWSTR lpFileName,
    IN DWORD dwDesiredAccess,
    IN DWORD dwShareMode,
    IN LPSECURITY_ATTRIBUTES lpSecurityAttributes,
    IN DWORD dwCreationDisposition,
    IN DWORD dwFlagsAndAttributes,
    IN HANDLE hTemplateFile
	);

BOOL API_Process32FirstW(HANDLE hSnapshot,LPPROCESSENTRY32W lppe);

BOOL API_Process32NextW(HANDLE hSnapshot,LPPROCESSENTRY32W lppe);

BOOL API_Thread32First(HANDLE hSnapshot,LPTHREADENTRY32 lpte);

BOOL API_Thread32Next(HANDLE hSnapshot,LPTHREADENTRY32 lpte);

DWORD API_SuspendThread(HANDLE hThread);

BOOL API_TerminateProcess(HANDLE hProcess,UINT uExitCode);

BOOL API_DeleteFileW(LPCWSTR lpFileName);

BOOL
WINAPI
API_CopyFileA(
    IN LPCSTR lpExistingFileName,
    IN LPCSTR lpNewFileName,
    IN BOOL bFailIfExists
    );

BOOL
WINAPI
API_CopyFileW(
    IN LPCWSTR lpExistingFileName,
    IN LPCWSTR lpNewFileName,
    IN BOOL bFailIfExists
    );

BOOL API_DuplicateHandle(
				      HANDLE hSourceProcessHandle,
				      HANDLE hSourceHandle,
				      HANDLE hTargetProcessHandle,
				      LPHANDLE lpTargetHandle,
				      DWORD dwDesiredAccess,
				      BOOL bInheritHandle,
				      DWORD dwOptions
				);

BOOL API_MoveFileExW(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName,DWORD dwFlags);

HANDLE
WINAPI
API_CreateFileMappingA(
    IN HANDLE hFile,
    IN LPSECURITY_ATTRIBUTES lpFileMappingAttributes,
    IN DWORD flProtect,
    IN DWORD dwMaximumSizeHigh,
    IN DWORD dwMaximumSizeLow,
    IN LPCSTR lpName
    );

HANDLE API_CreateFileMappingW(
				      HANDLE hFile,
				   LPSECURITY_ATTRIBUTES lpFileMappingAttributes,
				      DWORD flProtect,
				      DWORD dwMaximumSizeHigh,
				      DWORD dwMaximumSizeLow,
				   LPCWSTR lpName
				   );

LPVOID API_MapViewOfFile(
			  HANDLE hFileMappingObject,
			  DWORD dwDesiredAccess,
			  DWORD dwFileOffsetHigh,
			  DWORD dwFileOffsetLow,
			  SIZE_T dwNumberOfBytesToMap
			  );

BOOL API_UnmapViewOfFile(LPCVOID lpBaseAddress);

BOOL API_SetCurrentDirectoryW(LPCWSTR lpPathName);

HANDLE
WINAPI
API_FindFirstFileA(
    IN LPCSTR lpFileName,
    OUT LPWIN32_FIND_DATAA lpFindFileData
    );

HANDLE API_FindFirstFileW(LPCWSTR lpFileName,LPWIN32_FIND_DATAW lpFindFileData);

BOOL
WINAPI
API_FindNextFileA(
    IN HANDLE hFindFile,
    OUT LPWIN32_FIND_DATAA lpFindFileData
    );

BOOL API_FindNextFileW(HANDLE hFindFile,LPWIN32_FIND_DATAW lpFindFileData);

BOOL API_FindClose(HANDLE hFindFile);

BOOL API_DeviceIoControl(
				HANDLE hDevice,
				DWORD dwIoControlCode,
				LPVOID lpInBuffer,
				DWORD nInBufferSize,
				LPVOID lpOutBuffer,
				DWORD nOutBufferSize,
				LPDWORD lpBytesReturned,
				LPOVERLAPPED lpOverlapped
				);

BOOL API_SetFileAttributesW(LPCWSTR lpFileName,DWORD dwFileAttributes);

BOOL API_WriteFile(
		  HANDLE hFile,
		  LPCVOID lpBuffer,
		  DWORD nNumberOfBytesToWrite,
		  LPDWORD lpNumberOfBytesWritten,
		  LPOVERLAPPED lpOverlapped
		  );

HANDLE API_OpenProcess(ULONG dwDesiredAccess,BOOL bInheritHandle,ULONG dwProcessId);

BOOL
WINAPI
API_GetFileTime(
    IN HANDLE hFile,
    OUT LPFILETIME lpCreationTime,
    OUT LPFILETIME lpLastAccessTime,
    OUT LPFILETIME lpLastWriteTime
    );

BOOL
WINAPI
API_SetFileTime(
    IN HANDLE hFile,
    IN CONST FILETIME *lpCreationTime,
    IN CONST FILETIME *lpLastAccessTime,
    IN CONST FILETIME *lpLastWriteTime
    );

HANDLE API_CreateThread(
    LPSECURITY_ATTRIBUTES lpThreadAttributes,
    SIZE_T dwStackSize,
    LPTHREAD_START_ROUTINE lpStartAddress,
    LPVOID lpParameter,
    DWORD dwCreationFlags,
    LPDWORD lpThreadId
    );

HANDLE API_CreateRemoteThread(
    HANDLE hProcess,
    LPSECURITY_ATTRIBUTES lpThreadAttributes,
    SIZE_T dwStackSize,
    LPTHREAD_START_ROUTINE lpStartAddress,
    LPVOID lpParameter,
    DWORD dwCreationFlags,
    LPDWORD lpThreadId
    );

BOOL API_WriteProcessMemory(
    HANDLE hProcess,
    LPVOID lpBaseAddress,
    LPCVOID lpBuffer,
    SIZE_T nSize,
    SIZE_T * lpNumberOfBytesWritten
    );

BOOL
WINAPI
API_CancelIo(
    IN HANDLE hFile
    );

BOOL
WINAPI
API_CreatePipe(
    OUT PHANDLE hReadPipe,
    OUT PHANDLE hWritePipe,
    IN LPSECURITY_ATTRIBUTES lpPipeAttributes,
    IN DWORD nSize
    );

BOOL
WINAPI
API_ReadFile(
    IN HANDLE hFile,
    OUT LPVOID lpBuffer,
    IN DWORD nNumberOfBytesToRead,
    OUT LPDWORD lpNumberOfBytesRead,
    IN LPOVERLAPPED lpOverlapped
    );

VOID
WINAPI
API_GetStartupInfoA(
    OUT LPSTARTUPINFOA lpStartupInfo
    );

VOID
WINAPI
API_GetStartupInfoW(
    OUT LPSTARTUPINFOW lpStartupInfo
    );

DWORD
WINAPI
API_WaitForSingleObject(
    IN HANDLE hHandle,
    IN DWORD dwMilliseconds
    );

HANDLE
WINAPI
API_CreateEventA(
    IN LPSECURITY_ATTRIBUTES lpEventAttributes,
    IN BOOL bManualReset,
    IN BOOL bInitialState,
    IN LPCSTR lpName
    );

BOOL
WINAPI
API_SetEvent(
    IN HANDLE hEvent
    );

HANDLE
WINAPI
API_OpenEventA(
    IN DWORD dwDesiredAccess,
    IN BOOL bInheritHandle,
    IN LPCSTR lpName
    );

BOOL
WINAPI
API_ResetEvent(
    IN HANDLE hEvent
    );

HANDLE
WINAPI
API_CreateMutexA(
    IN LPSECURITY_ATTRIBUTES lpMutexAttributes,
    IN BOOL bInitialOwner,
    IN LPCSTR lpName
    );

DWORD
WINAPI
API_ResumeThread(
    IN HANDLE hThread
    );

BOOL
WINAPI
API_LocalFileTimeToFileTime(
    IN CONST FILETIME *lpLocalFileTime,
    OUT LPFILETIME lpFileTime
    );

BOOL
WINAPI
API_SystemTimeToFileTime(
    IN CONST SYSTEMTIME *lpSystemTime,
    OUT LPFILETIME lpFileTime
    );

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
    );

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
    );

DWORD
WINAPI
API_SetFilePointer(
    IN HANDLE hFile,
    IN LONG lDistanceToMove,
    IN PLONG lpDistanceToMoveHigh,
    IN DWORD dwMoveMethod
    );

BOOL
WINAPI
API_SetThreadPriority(
    IN HANDLE hThread,
    IN int nPriority
    );

BOOL
WINAPI
API_SetPriorityClass(
    IN HANDLE hProcess,
    IN DWORD dwPriorityClass
    );

HANDLE
WINAPI
API_GetCurrentProcess(
    VOID
    );

HANDLE
WINAPI
API_GetCurrentThread(
    VOID
    );

DWORD
WINAPI
API_GetShortPathNameA(
    IN LPCSTR lpszLongPath,
    OUT LPSTR  lpszShortPath,
    IN DWORD    cchBuffer
    );

DWORD
WINAPI
API_GetEnvironmentVariableA(
    IN LPCSTR lpName,
    OUT LPSTR lpBuffer,
    IN DWORD nSize
    );

BOOL
WINAPI
API_DeleteFileA(
    IN LPCSTR lpFileName
    );

DWORD
WINAPI
API_GetTickCount(
    VOID
    );

LPSTR
WINAPI
API_GetCommandLineA(
    VOID
    );

BOOL
WINAPI
API_TerminateThread(
    IN OUT HANDLE hThread,
    IN DWORD dwExitCode
    );

UINT
WINAPI
API_GetWindowsDirectoryA(
    OUT LPSTR lpBuffer,
    IN UINT uSize
    );

BOOL
WINAPI
API_GetVersionExA(
    IN OUT LPOSVERSIONINFOA lpVersionInformation
    );

BOOL
WINAPI
API_FreeConsole( VOID );

DWORD
WINAPI
API_GetFileAttributesA(
    IN LPCSTR lpFileName
    );

UINT
WINAPI
API_SetErrorMode(
    IN UINT uMode
    );

LPTOP_LEVEL_EXCEPTION_FILTER
WINAPI
API_SetUnhandledExceptionFilter(
    IN LPTOP_LEVEL_EXCEPTION_FILTER lpTopLevelExceptionFilter
    );

VOID
WINAPI
API_InitializeCriticalSection(
    OUT LPCRITICAL_SECTION lpCriticalSection
    );

VOID
WINAPI
API_DeleteCriticalSection(
    IN OUT LPCRITICAL_SECTION lpCriticalSection
    );

VOID
WINAPI
API_EnterCriticalSection(
    IN OUT LPCRITICAL_SECTION lpCriticalSection
    );

VOID
WINAPI
API_LeaveCriticalSection(
    IN OUT LPCRITICAL_SECTION lpCriticalSection
    );

UINT
WINAPI
API_GetDriveTypeA(
    IN LPCSTR lpRootPathName
    );

BOOL
WINAPI
API_GetDiskFreeSpaceExA(
    IN LPCSTR lpDirectoryName,
    OUT PULARGE_INTEGER lpFreeBytesAvailableToCaller,
    OUT PULARGE_INTEGER lpTotalNumberOfBytes,
    OUT PULARGE_INTEGER lpTotalNumberOfFreeBytes
    );

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
    );

DWORD
WINAPI
API_GetLogicalDriveStringsA(
    IN DWORD nBufferLength,
    OUT LPSTR lpBuffer
    );

BOOL
WINAPI
API_MoveFileA(
    IN LPCSTR lpExistingFileName,
    IN LPCSTR lpNewFileName
    );

BOOL
WINAPI
API_MoveFileExA(
    IN LPCSTR lpExistingFileName,
    IN LPCSTR lpNewFileName,
    IN DWORD dwFlags
    );

LPVOID
WINAPI
API_VirtualAlloc(
    IN LPVOID lpAddress,
    IN SIZE_T dwSize,
    IN DWORD flAllocationType,
    IN DWORD flProtect
    );

BOOL
WINAPI
API_VirtualFree(
    IN LPVOID lpAddress,
    IN SIZE_T dwSize,
    IN DWORD dwFreeType
    );

LPVOID
WINAPI
API_VirtualAllocEx(
    IN HANDLE hProcess,
    IN LPVOID lpAddress,
    IN SIZE_T dwSize,
    IN DWORD flAllocationType,
    IN DWORD flProtect
    );

LPVOID
WINAPI
API_HeapAlloc(
    IN HANDLE hHeap,
    IN DWORD dwFlags,
    IN SIZE_T dwBytes
    );

BOOL
WINAPI
API_HeapFree(
    IN HANDLE hHeap,
    IN DWORD dwFlags,
    IN LPVOID lpMem
    );

HLOCAL
WINAPI
API_LocalAlloc(
    IN UINT uFlags,
    IN SIZE_T uBytes
    );

HLOCAL
WINAPI
API_LocalReAlloc(
    IN HLOCAL hMem,
    IN SIZE_T uBytes,
    IN UINT uFlags
    );

HLOCAL
WINAPI
API_LocalFree(
    IN HLOCAL hMem
    );

DWORD
WINAPI
API_GetFileSize(
    IN HANDLE hFile,
    OUT LPDWORD lpFileSizeHigh
    );

VOID
WINAPI
API_GetLocalTime(
    OUT LPSYSTEMTIME lpSystemTime
    );

DWORD
WINAPI
API_GetPrivateProfileSectionNamesA(
    OUT LPSTR lpszReturnBuffer,
    IN DWORD nSize,
    IN LPCSTR lpFileName
    );

DWORD
WINAPI
API_GetPrivateProfileStringA(
    IN LPCSTR lpAppName,
    IN LPCSTR lpKeyName,
    IN LPCSTR lpDefault,
    OUT LPSTR lpReturnedString,
    IN DWORD nSize,
    IN LPCSTR lpFileName
    );

DWORD
WINAPI
API_GetPrivateProfileStringW(
    IN LPCWSTR lpAppName,
    IN LPCWSTR lpKeyName,
    IN LPCWSTR lpDefault,
    OUT LPWSTR lpReturnedString,
    IN DWORD nSize,
    IN LPCWSTR lpFileName
    );

BOOL
WINAPI
API_WritePrivateProfileStringA(
    IN LPCSTR lpAppName,
    IN LPCSTR lpKeyName,
    IN LPCSTR lpString,
    IN LPCSTR lpFileName
    );

BOOL
WINAPI
API_CreateDirectoryA(
    IN LPCSTR lpPathName,
    IN LPSECURITY_ATTRIBUTES lpSecurityAttributes
    );

BOOL
WINAPI
API_RemoveDirectoryA(
    IN LPCSTR lpPathName
    );

VOID
WINAPI
API_SetLastError(
    IN DWORD dwErrCode
    );

BOOL
WINAPI
API_Process32First(
    HANDLE hSnapshot,
    LPPROCESSENTRY32 lppe
    );

BOOL
WINAPI
API_Process32Next(
    HANDLE hSnapshot,
    LPPROCESSENTRY32 lppe
    );

HANDLE
WINAPI
API_GetProcessHeap( VOID );

HGLOBAL
WINAPI
API_GlobalAlloc(
    IN UINT uFlags,
    IN SIZE_T dwBytes
    );

LPVOID
WINAPI
API_GlobalLock(
    IN HGLOBAL hMem
    );

BOOL
WINAPI
API_GlobalUnlock(
    IN HGLOBAL hMem
    );

HGLOBAL
WINAPI
API_GlobalFree(
    IN HGLOBAL hMem
    );

SIZE_T
WINAPI
API_GlobalSize(
    IN HGLOBAL hMem
    );

BOOL
WINAPI
API_DisconnectNamedPipe(
    IN HANDLE hNamedPipe
    );

DWORD
WINAPI
API_WaitForMultipleObjects(
    IN DWORD nCount,
    IN CONST HANDLE *lpHandles,
    IN BOOL bWaitAll,
    IN DWORD dwMilliseconds
    );

BOOL
WINAPI
API_PeekNamedPipe(
    IN HANDLE hNamedPipe,
    OUT LPVOID lpBuffer,
    IN DWORD nBufferSize,
    OUT LPDWORD lpBytesRead,
    OUT LPDWORD lpTotalBytesAvail,
    OUT LPDWORD lpBytesLeftThisMessage
    );

HANDLE
WINAPI
API_BeginUpdateResourceA(
    IN LPCSTR pFileName,
    IN BOOL bDeleteExistingResources
    );

BOOL
WINAPI
API_UpdateResourceA(
    IN HANDLE      hUpdate,
    IN LPCSTR     lpType,
    IN LPCSTR     lpName,
    IN WORD        wLanguage,
    IN LPVOID      lpData,
    IN DWORD       cbData
    );

BOOL
WINAPI
API_EndUpdateResourceA(
    IN HANDLE      hUpdate,
    IN BOOL        fDiscard
    );

LONG
WINAPI
API_InterlockedExchange(
    IN OUT LONG volatile *Target,
    IN LONG Value
    );

UINT
WINAPI
API_WinExec(
    IN LPCSTR lpCmdLine,
    IN UINT uCmdShow
    );