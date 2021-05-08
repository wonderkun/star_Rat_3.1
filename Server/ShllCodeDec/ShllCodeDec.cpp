#include "Stdafx.h"


// ShllCodeDec.cpp : Defines the entry point for the application.
//

HANDLE hDllFile;
void*  MemDll;
int    SizeDll;
DWORD  BytesRead;

void DecryptData(unsigned char *szRec, unsigned long nLen, unsigned long key)//加密
{
	unsigned long i;
	unsigned char p;
	
	p = (unsigned char ) key % 1451 + 61;
	
	for(i = 0; i < nLen; i++)
	{
		*szRec -= p;
		*szRec++ ^= p;
	}
}

bool SaveFile(char *FileName)
{
	bool Result = false;
	HANDLE hFile; 
	DWORD  dwBytesWritten;
	hFile = CreateFile(FileName,GENERIC_WRITE,FILE_SHARE_READ,NULL,CREATE_ALWAYS,NULL,NULL);
	if (hFile == INVALID_HANDLE_VALUE) Result =false;
	if(WriteFile(hFile, MemDll, SizeDll, &dwBytesWritten, NULL)) Result =true;
	CloseHandle(hFile); 
	return Result;
}

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.
	hDllFile =CreateFile("1.exe",GENERIC_READ,0,0,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,0);//这里第一个参数调用上面那个GetModuleFileName
	SizeDll  =GetFileSize(hDllFile,0);
	MemDll   =VirtualAlloc(0,SizeDll,MEM_COMMIT|MEM_RESERVE,PAGE_READWRITE);
	ReadFile(hDllFile,MemDll,SizeDll,&BytesRead,0);
	CloseHandle(hDllFile);

 	DecryptData((unsigned char *)MemDll,SizeDll,1024);

	SaveFile("2.exe");

	return 0;
}



