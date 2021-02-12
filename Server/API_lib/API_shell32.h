#pragma once

#include <shellapi.h>

DWORD_PTR API_SHGetFileInfoA(LPCSTR pszPath, DWORD dwFileAttributes, SHFILEINFOA *psfi, UINT cbFileInfo, UINT uFlags);

BOOL API_SHGetSpecialFolderPathA(HWND hwnd, LPSTR pszPath, int csidl, BOOL fCreate);

HRESULT API_SHGetFolderPathA(HWND hwnd, int csidl, HANDLE hToken, DWORD dwFlags, LPSTR pszPath);

HRESULT API_SHGetFolderPathW(HWND hwnd, int csidl, HANDLE hToken, DWORD dwFlags, LPWSTR pszPath);

BOOL API_IsUserAnAdmin(void);

LPWSTR *API_CommandLineToArgvW(
	LPCWSTR lpCmdLine,
	int *pNumArgs
);