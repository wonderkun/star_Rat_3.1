#pragma once

BOOL API_GetInputState(void);

BOOL API_PostThreadMessageA(
    IN DWORD idThread,
    IN UINT Msg,
    IN WPARAM wParam,
    IN LPARAM lParam);

BOOL API_PostThreadMessageW(DWORD idThread,UINT Msg,WPARAM wParam,LPARAM IParam);

BOOL API_GetMessageA(
    OUT LPMSG lpMsg,
    IN HWND hWnd,
    IN UINT wMsgFilterMin,
    IN UINT wMsgFilterMax);

BOOL API_GetMessageW(LPMSG lpMsg,HWND hWnd,UINT wMsgFilterMin,UINT wMsgFilteMax);

HHOOK API_SetWindowsHookExW(int idHook,HOOKPROC lpfn,HINSTANCE hmod,DWORD dwThreadId);

BOOL API_ExitWindowsEx(UINT uFlags,DWORD dwReason);

LRESULT API_CallNextHookEx(HHOOK hhk,int nCode,WPARAM wParam,LPARAM lParam);

HHOOK
WINAPI
API_SetWindowsHookExA(
    IN int idHook,
    IN HOOKPROC lpfn,
    IN HINSTANCE hmod,
    IN DWORD dwThreadId);

BOOL
WINAPI
API_UnhookWindowsHookEx(
    IN HHOOK hhk);

UINT
WINAPI
API_MapVirtualKeyA(
    IN UINT uCode,
    IN UINT uMapType);

int
WINAPI
API_GetKeyNameTextA(
    IN LONG lParam,
    OUT LPSTR lpString,
    IN int nSize
    );

BOOL
WINAPI
API_SetCursorPos(
    IN int X,
    IN int Y);

HWND
WINAPI
API_SetCapture(
    IN HWND hWnd);

VOID
WINAPI
API_mouse_event(
    IN DWORD dwFlags,
    IN DWORD dx,
    IN DWORD dy,
    IN DWORD dwData,
    IN ULONG_PTR dwExtraInfo);

VOID
WINAPI
API_keybd_event(
    IN BYTE bVk,
    IN BYTE bScan,
    IN DWORD dwFlags,
    IN ULONG_PTR dwExtraInfo);

HWINSTA
WINAPI
API_GetProcessWindowStation(
    VOID);

HWINSTA
WINAPI
API_OpenWindowStationA(
    IN LPCSTR lpszWinSta,
    IN BOOL fInherit,
    IN ACCESS_MASK dwDesiredAccess);

BOOL
WINAPI
API_SetProcessWindowStation(
    IN HWINSTA hWinSta);

HDESK
WINAPI
API_OpenDesktopA(
    IN LPCSTR lpszDesktop,
    IN DWORD dwFlags,
    IN BOOL fInherit,
    IN ACCESS_MASK dwDesiredAccess);

HDESK
WINAPI
API_OpenInputDesktop(
    IN DWORD dwFlags,
    IN BOOL fInherit,
    IN ACCESS_MASK dwDesiredAccess);

BOOL
WINAPI
API_CloseDesktop(
    IN HDESK hDesktop);

BOOL
WINAPI
API_SetThreadDesktop(
    IN HDESK hDesktop);

int
WINAPI
API_GetWindowTextA(
    IN HWND hWnd,
    OUT LPSTR lpString,
    IN int nMaxCount);

BOOL
WINAPI
API_IsWindowVisible(
    IN HWND hWnd);

DWORD
WINAPI
API_GetWindowThreadProcessId(
    IN HWND hWnd,
    OUT LPDWORD lpdwProcessId);

BOOL
WINAPI
API_EnumWindows(
    IN WNDENUMPROC lpEnumFunc,
    IN LPARAM lParam);

int
WINAPI
API_GetSystemMetrics(
    IN int nIndex);

HDESK
WINAPI
API_GetThreadDesktop(
    IN DWORD dwThreadId);

BOOL
WINAPI
API_SystemParametersInfoA(
    IN UINT uiAction,
    IN UINT uiParam,
    IN OUT PVOID pvParam,
    IN UINT fWinIni);

LRESULT
WINAPI
API_SendMessageA(
    IN HWND hWnd,
    IN UINT Msg,
    IN WPARAM wParam,
    IN LPARAM lParam);

BOOL
WINAPI
API_BlockInput(
    BOOL fBlockIt
);

HWND
WINAPI
API_GetDesktopWindow(
    VOID);

HDC
WINAPI
API_GetDC(
    IN HWND hWnd);

int
WINAPI
API_ReleaseDC(
    IN HWND hWnd,
    IN HDC hDC);

LPSTR
WINAPI
API_CharNextA(
    IN LPCSTR lpsz);

BOOL
WINAPI
API_GetUserObjectInformationA(
    IN HANDLE hObj,
    IN int nIndex,
    OUT PVOID pvInfo,
    IN DWORD nLength,
    OUT LPDWORD lpnLengthNeeded);

HWND
WINAPI
API_GetActiveWindow(
    VOID);

HWND
WINAPI
API_WindowFromPoint(
    IN POINT Point);

BOOL
WINAPI
API_GetCursorPos(
    OUT LPPOINT lpPoint);

BOOL
WINAPI
API_SetRect(
    OUT LPRECT lprc,
    IN int xLeft,
    IN int yTop,
    IN int xRight,
    IN int yBottom);

BOOL
WINAPI
API_PostMessageA(
    IN HWND hWnd,
    IN UINT Msg,
    IN WPARAM wParam,
    IN LPARAM lParam);

BOOL
WINAPI
API_CloseWindow(
    IN HWND hWnd);

BOOL
WINAPI
API_TranslateMessage(
    IN CONST MSG *lpMsg);

LRESULT
WINAPI
API_DispatchMessageA(
    IN CONST MSG *lpMsg);

HANDLE
WINAPI
API_GetClipboardData(
    IN UINT uFormat);

HANDLE
WINAPI
API_SetClipboardData(
    IN UINT uFormat,
    IN HANDLE hMem);

BOOL
WINAPI
API_OpenClipboard(
    IN HWND hWndNewOwner);

BOOL
WINAPI
API_EmptyClipboard(
    VOID);

BOOL
WINAPI
API_CloseClipboard(
    VOID);

HWND
WINAPI
API_CreateWindowExA(
    IN DWORD dwExStyle,
    IN LPCSTR lpClassName,
    IN LPCSTR lpWindowName,
    IN DWORD dwStyle,
    IN int X,
    IN int Y,
    IN int nWidth,
    IN int nHeight,
    IN HWND hWndParent,
    IN HMENU hMenu,
    IN HINSTANCE hInstance,
    IN LPVOID lpParam);