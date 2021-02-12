#pragma once

BOOL API_capGetDriverDescriptionA (UINT wDriverIndex,
        LPSTR lpszName, int cbName,
        LPSTR lpszVer, int cbVer);

HWND API_capCreateCaptureWindowA (
        LPCSTR lpszWindowName,
        DWORD dwStyle,
        int x, int y, int nWidth, int nHeight,
        HWND hwndParent, int nID);