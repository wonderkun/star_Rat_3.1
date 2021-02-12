#pragma once

BOOL
WINAPI
API_EnumProcessModules(
    HANDLE hProcess,
    HMODULE *lphModule,
    DWORD cb,
    LPDWORD lpcbNeeded
    );

DWORD
WINAPI
API_GetModuleFileNameExA(
    HANDLE hProcess,
    HMODULE hModule,
    LPSTR lpFilename,
    DWORD nSize
    );

DWORD
WINAPI
API_GetModuleFileNameExW(
    HANDLE hProcess,
    HMODULE hModule,
    LPWSTR lpFilename,
    DWORD nSize
    );