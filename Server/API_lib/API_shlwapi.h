#pragma once

DWORD API_SHDeleteKeyA(HKEY hkey, LPCSTR pszSubKey);

void API_PathStripPathW(LPWSTR pszPath);

void API_PathStripPathA(LPSTR pszPath);