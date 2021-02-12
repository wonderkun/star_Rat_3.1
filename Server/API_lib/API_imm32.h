#pragma once

HIMC WINAPI API_ImmGetContext(IN HWND hWnd);

LONG WINAPI API_ImmGetCompositionStringA(IN HIMC hIMC, IN DWORD dwIndex, OUT LPVOID lpBuf, IN DWORD dwBufLen);

BOOL WINAPI API_ImmReleaseContext(IN HWND, IN HIMC);