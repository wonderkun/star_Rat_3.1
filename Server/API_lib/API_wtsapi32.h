#pragma once

#include <wtsapi32.h>

BOOL
WINAPI
API_WTSQuerySessionInformationA(
    IN HANDLE hServer,
    IN DWORD SessionId,
    IN WTS_INFO_CLASS WTSInfoClass,
    OUT LPSTR * ppBuffer,
    OUT DWORD * pBytesReturned
    );

VOID
WINAPI
API_WTSFreeMemory(
    IN PVOID pMemory
    );

BOOL
WINAPI
API_WTSQueryUserToken(
    ULONG SessionId, 
    PHANDLE phToken
    );