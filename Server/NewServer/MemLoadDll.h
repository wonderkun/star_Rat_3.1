
#pragma warning( disable : 4311 4312 )

#include <Windows.h>
#include <winnt.h>
#include <Windows.h>
#include <TCHAR.H>
typedef void *HMEMORYMODULE;

#ifdef __cplusplus
extern "C" {
#endif

HMEMORYMODULE MemoryLoadLibrary(const void *);

FARPROC MemoryGetProcAddress(HMEMORYMODULE, const char *);

void MemoryFreeLibrary(HMEMORYMODULE);

#ifdef __cplusplus
}
#endif

typedef struct {
	PIMAGE_NT_HEADERS headers;
	unsigned char *codeBase;
	HMODULE *modules;
	int numModules;
	int initialized;
} MEMORYMODULE, *PMEMORYMODULE;

typedef BOOL (WINAPI *DllEntryProc)(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved);

#define GET_HEADER_DICTIONARY(module, idx)	&(module)->headers->OptionalHeader.DataDirectory[idx]

///-------------------------------------------MyFunctions
__declspec(naked) char __fastcall upcaseA(char c)
{
	__asm
	{
		mov al, cl
			cmp al, 'a'
			jl m1
			cmp al, 'z'
			jg m1
			and al, 0xdf
m1:
		retn
	}
}

int __fastcall strcmpiA(const char *s1, const char *s2)
{
	unsigned long k = 0;
	unsigned char c1, c2;
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
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;

	do
	{
		c1 = upcaseA(s1[k]);
		c2 = upcaseA(s2[k]);
		if (c1 > c2)
		{
			return 1;
		}
		else if (c1 < c2)
		{
			return -1;
		};
		
		k++;
	} while ((c1 | c2) != 0);
	return 0;
}

void myfree(void *p)
{
	typedef BOOL
		(WINAPI
		*HeapFreeT)(
		__inout HANDLE hHeap,
		__in    DWORD dwFlags,
		__deref LPVOID lpMem
		);
	char AOiHr[] = {'H','e','a','p','F','r','e','e','\0'};
	char dcCRF[] = {'K','E','R','N','E','L','3','2','.','d','l','l','\0'};
	HeapFreeT pHeapFree=(HeapFreeT)GetProcAddress(LoadLibrary(dcCRF),AOiHr);
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
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;

	typedef HANDLE
		(WINAPI
		*GetProcessHeapT)(
		VOID
		);
	char GWcOq[] = {'G','e','t','P','r','o','c','e','s','s','H','e','a','p','\0'};
	GetProcessHeapT pGetProcessHeap=(GetProcessHeapT)GetProcAddress(LoadLibrary(dcCRF),GWcOq);
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
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;

    pHeapFree(pGetProcessHeap(), 0, p);
}


////------------------------------------

static void CopySections(const unsigned char *data, PIMAGE_NT_HEADERS old_headers, PMEMORYMODULE module)
{
	typedef LPVOID
		(WINAPI
		*VirtualAllocT)(
		__in_opt LPVOID lpAddress,
		__in     SIZE_T dwSize,
		__in     DWORD flAllocationType,
		__in     DWORD flProtect
		);
	char uitgn[] = {'K','E','R','N','E','L','3','2','.','d','l','l','\0'};
	char qyasB[] = {'V','i','r','t','u','a','l','A','l','l','o','c','\0'};
	VirtualAllocT pVirtualAlloc=(VirtualAllocT)GetProcAddress(LoadLibrary(uitgn),qyasB);
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
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;

	int i, size;
	unsigned char *codeBase = module->codeBase;
	unsigned char *dest;
	PIMAGE_SECTION_HEADER section = IMAGE_FIRST_SECTION(module->headers);
	for (i=0; i<module->headers->FileHeader.NumberOfSections; i++, section++)
	{
		if (section->SizeOfRawData == 0)
		{
			// section doesn't contain data in the dll itself, but may define
			// uninitialized data
			size = old_headers->OptionalHeader.SectionAlignment;
			if (size > 0)
			{
				dest = (unsigned char *)pVirtualAlloc(codeBase + section->VirtualAddress,
					size,
					MEM_COMMIT,
					PAGE_READWRITE);
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
				_asm nop;
				_asm nop;
				_asm nop;
				_asm nop;
				_asm nop;
				_asm nop;
				_asm nop;
				_asm nop;

				section->Misc.PhysicalAddress = (DWORD)dest;
				memset(dest, 0, size);
			}
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
			_asm nop;
			_asm nop;
			_asm nop;
			_asm nop;
			_asm nop;
			_asm nop;
			_asm nop;
			_asm nop;

			// section is empty
			continue;
		}
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
		_asm nop;
		_asm nop;
		_asm nop;
		_asm nop;
		_asm nop;
		_asm nop;
		_asm nop;
		_asm nop;

		// commit memory block and copy data from dll
		dest = (unsigned char *)pVirtualAlloc(codeBase + section->VirtualAddress,
							section->SizeOfRawData,
							MEM_COMMIT,
							PAGE_READWRITE);
		memcpy(dest, data + section->PointerToRawData, section->SizeOfRawData);
		section->Misc.PhysicalAddress = (DWORD)dest;
	}
}
void *myrealloc(void *p, size_t size)
{
	typedef LPVOID
		(WINAPI
		*HeapReAllocT)(
		__inout HANDLE hHeap,
		__in    DWORD dwFlags,
		__deref LPVOID lpMem,
		__in    SIZE_T dwBytes
		);
	char lygUR[] = {'K','E','R','N','E','L','3','2','.','d','l','l','\0'};
	char gfKIk[] = {'H','e','a','p','R','e','A','l','l','o','c','\0'};
	HeapReAllocT pHeapReAlloc=(HeapReAllocT)GetProcAddress(LoadLibrary(lygUR),gfKIk);
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
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;

	typedef LPVOID
		(WINAPI
		*HeapAllocT)(
		__in HANDLE hHeap,
		__in DWORD dwFlags,
		__in SIZE_T dwBytes
		);
	char nGOQF[] = {'H','e','a','p','A','l','l','o','c','\0'};
	HeapAllocT pHeapAlloc=(HeapAllocT)GetProcAddress(LoadLibrary(lygUR),nGOQF);
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
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;

	typedef HANDLE
		(WINAPI
		*GetProcessHeapT)(
		VOID
		);
	char GWcOq[] = {'G','e','t','P','r','o','c','e','s','s','H','e','a','p','\0'};
	GetProcessHeapT pGetProcessHeap=(GetProcessHeapT)GetProcAddress(LoadLibrary(lygUR),GWcOq);
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
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;

    if (p)
        return pHeapReAlloc(pGetProcessHeap(), 0, p, size);
    else
        return pHeapAlloc(pGetProcessHeap(), 0, size);
}
// Protection flags for memory pages (Executable, Readable, Writeable)
static int ProtectionFlags[2][2][2] = 
{
	{
		// not executable
		{PAGE_NOACCESS, PAGE_WRITECOPY},
		{PAGE_READONLY, PAGE_READWRITE},
	}, {
		// executable
		{PAGE_EXECUTE, PAGE_EXECUTE_WRITECOPY},
		{PAGE_EXECUTE_READ, PAGE_EXECUTE_READWRITE},
	},
};

static void FinalizeSections(PMEMORYMODULE module)
{
	typedef BOOL
		(WINAPI
		*VirtualFreeT)(
		__in LPVOID lpAddress,
		__in SIZE_T dwSize,
		__in DWORD dwFreeType
		);
	char GdcJG[] = {'K','E','R','N','E','L','3','2','.','d','l','l','\0'};
	char BdPGX[] = {'V','i','r','t','u','a','l','F','r','e','e','\0'};
	VirtualFreeT pVirtualFree=(VirtualFreeT)GetProcAddress(LoadLibrary(GdcJG),BdPGX);
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
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;

	typedef BOOL
		(WINAPI
		*VirtualProtectT)(
		__in  LPVOID lpAddress,
		__in  SIZE_T dwSize,
		__in  DWORD flNewProtect,
		__out PDWORD lpflOldProtect
		);	
	char nOVLO[] = {'V','i','r','t','u','a','l','P','r','o','t','e','c','t','\0'};
	VirtualProtectT pVirtualProtect=(VirtualProtectT)GetProcAddress(LoadLibrary(GdcJG),nOVLO);

	int i;
	PIMAGE_SECTION_HEADER section = IMAGE_FIRST_SECTION(module->headers);
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
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;

	// loop through all sections and change access flags
	for (i=0; i<module->headers->FileHeader.NumberOfSections; i++, section++)
	{
		DWORD protect, oldProtect, size;
		int executable = (section->Characteristics & IMAGE_SCN_MEM_EXECUTE) != 0;
		int readable =   (section->Characteristics & IMAGE_SCN_MEM_READ) != 0;
		int writeable =  (section->Characteristics & IMAGE_SCN_MEM_WRITE) != 0;
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
		_asm nop;
		_asm nop;
		_asm nop;
		_asm nop;
		_asm nop;
		_asm nop;
		_asm nop;
		_asm nop;

		if (section->Characteristics & IMAGE_SCN_MEM_DISCARDABLE)
		{
			// section is not needed any more and can safely be freed
			pVirtualFree((LPVOID)section->Misc.PhysicalAddress, section->SizeOfRawData, MEM_DECOMMIT);
			continue;
		}
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
		_asm nop;
		_asm nop;
		_asm nop;
		_asm nop;
		_asm nop;
		_asm nop;
		_asm nop;
		_asm nop;

		// determine protection flags based on characteristics
		protect = ProtectionFlags[executable][readable][writeable];
		if (section->Characteristics & IMAGE_SCN_MEM_NOT_CACHED)
			protect |= PAGE_NOCACHE;
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
		_asm nop;
		_asm nop;
		_asm nop;
		_asm nop;
		_asm nop;
		_asm nop;
		_asm nop;
		_asm nop;

		// determine size of region
		size = section->SizeOfRawData;
		if (size == 0)
		{
			if (section->Characteristics & IMAGE_SCN_CNT_INITIALIZED_DATA)
				size = module->headers->OptionalHeader.SizeOfInitializedData;
			else if (section->Characteristics & IMAGE_SCN_CNT_UNINITIALIZED_DATA)
				size = module->headers->OptionalHeader.SizeOfUninitializedData;
		}
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
		_asm nop;
		_asm nop;
		_asm nop;
		_asm nop;
		_asm nop;
		_asm nop;
		_asm nop;
		_asm nop;

		if (size > 0)
		{
			// change memory access flags
			if (pVirtualProtect((LPVOID)section->Misc.PhysicalAddress, section->SizeOfRawData, protect, &oldProtect) == 0)
			{
				//OutputLastError("Error protecting memory page");
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
				_asm nop;
				_asm nop;
				_asm nop;
				_asm nop;
				_asm nop;
				_asm nop;
				_asm nop;
				_asm nop;
			}	
		}
	}
}

static void PerformBaseRelocation(PMEMORYMODULE module, DWORD delta)
{
	DWORD i;
	unsigned char *codeBase = module->codeBase;
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
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;

	PIMAGE_DATA_DIRECTORY directory = GET_HEADER_DICTIONARY(module, IMAGE_DIRECTORY_ENTRY_BASERELOC);
	if (directory->Size > 0)
	{
		PIMAGE_BASE_RELOCATION relocation = (PIMAGE_BASE_RELOCATION)(codeBase + directory->VirtualAddress);
		for (; relocation->VirtualAddress > 0; )
		{
			unsigned char *dest = (unsigned char *)(codeBase + relocation->VirtualAddress);
			unsigned short *relInfo = (unsigned short *)((unsigned char *)relocation + IMAGE_SIZEOF_BASE_RELOCATION);
			for (i=0; i<((relocation->SizeOfBlock-IMAGE_SIZEOF_BASE_RELOCATION) / 2); i++, relInfo++)
			{
				DWORD *patchAddrHL;
				int type, offset;
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
				_asm nop;
				_asm nop;
				_asm nop;
				_asm nop;
				_asm nop;
				_asm nop;
				_asm nop;
				_asm nop;

				// the upper 4 bits define the type of relocation
				type = *relInfo >> 12;
				// the lower 12 bits define the offset
				offset = *relInfo & 0xfff;
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
				_asm nop;
				_asm nop;
				_asm nop;
				_asm nop;
				_asm nop;
				_asm nop;
				_asm nop;
				_asm nop;

				switch (type)
				{
				case IMAGE_REL_BASED_ABSOLUTE:
					// skip relocation
					break;

				case IMAGE_REL_BASED_HIGHLOW:
					// change complete 32 bit address
					patchAddrHL = (DWORD *)(dest + offset);
					*patchAddrHL += delta;
					break;

				default:
					//printf("Unknown relocation: %d\n", type);
					break;
				}
			}
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
			_asm nop;
			_asm nop;
			_asm nop;
			_asm nop;
			_asm nop;
			_asm nop;
			_asm nop;
			_asm nop;

			// advance to next relocation block
			relocation = (PIMAGE_BASE_RELOCATION)(((DWORD)relocation) + relocation->SizeOfBlock);
		}
	}
}

static int BuildImportTable(PMEMORYMODULE module)
{
	typedef BOOL
		(WINAPI
		*IsBadReadPtrT)(
		__in_opt CONST VOID *lp,
		__in     UINT_PTR ucb
		);
	char scfXK[] = {'I','s','B','a','d','R','e','a','d','P','t','r','\0'};
	char eYhRS[] = {'K','E','R','N','E','L','3','2','.','d','l','l','\0'};
	IsBadReadPtrT pIsBadReadPtr=(IsBadReadPtrT)GetProcAddress(LoadLibrary(eYhRS),scfXK);
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
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;

	int result=1;
	unsigned char *codeBase = module->codeBase;
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
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;

	PIMAGE_DATA_DIRECTORY directory = GET_HEADER_DICTIONARY(module, IMAGE_DIRECTORY_ENTRY_IMPORT);
	if (directory->Size > 0)
	{
		PIMAGE_IMPORT_DESCRIPTOR importDesc = (PIMAGE_IMPORT_DESCRIPTOR)(codeBase + directory->VirtualAddress);
		for (; !pIsBadReadPtr(importDesc, sizeof(IMAGE_IMPORT_DESCRIPTOR)) && importDesc->Name; importDesc++)
		{
			DWORD *thunkRef, *funcRef;
			HMODULE handle = LoadLibraryA((LPCSTR)(codeBase + importDesc->Name));
			if (handle == INVALID_HANDLE_VALUE)
			{
//				OutputDebugString(_T("Can't load library"));
				result = 0;
				break;
			}
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
			_asm nop;
			_asm nop;
			_asm nop;
			_asm nop;
			_asm nop;
			_asm nop;
			_asm nop;
			_asm nop;

			module->modules = (HMODULE *)myrealloc(module->modules, (module->numModules+1)*(sizeof(HMODULE)));
			if (module->modules == NULL)
			{
				result = 0;
				break;
			}
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
			_asm nop;
			_asm nop;
			_asm nop;
			_asm nop;
			_asm nop;
			_asm nop;
			_asm nop;
			_asm nop;

			module->modules[module->numModules++] = handle;
			if (importDesc->OriginalFirstThunk)
			{
				thunkRef = (DWORD *)(codeBase + importDesc->OriginalFirstThunk);
				funcRef = (DWORD *)(codeBase + importDesc->FirstThunk);
			} else {
				// no hint table
				thunkRef = (DWORD *)(codeBase + importDesc->FirstThunk);
				funcRef = (DWORD *)(codeBase + importDesc->FirstThunk);
			}
			for (; *thunkRef; thunkRef++, funcRef++)
			{
				if IMAGE_SNAP_BY_ORDINAL(*thunkRef)
					*funcRef = (DWORD)GetProcAddress(handle, (LPCSTR)IMAGE_ORDINAL(*thunkRef));
				else {
					PIMAGE_IMPORT_BY_NAME thunkData = (PIMAGE_IMPORT_BY_NAME)(codeBase + *thunkRef);
					*funcRef = (DWORD)GetProcAddress(handle, (LPCSTR)&thunkData->Name);
				}
				if (*funcRef == 0)
				{
					result = 0;
					break;
				}
			}
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
			_asm nop;
			_asm nop;
			_asm nop;
			_asm nop;
			_asm nop;
			_asm nop;
			_asm nop;
			_asm nop;

			if (!result)
				break;
		}
	}
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
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;

	return result;
}

HMEMORYMODULE MemoryLoadLibrary(const void *data)
{
	typedef LPVOID
		(WINAPI
		*HeapAllocT)(
		__in HANDLE hHeap,
		__in DWORD dwFlags,
		__in SIZE_T dwBytes
		);
	char lygUR[] = {'K','E','R','N','E','L','3','2','.','d','l','l','\0'};
	char nGOQF[] = {'H','e','a','p','A','l','l','o','c','\0'};
	HeapAllocT pHeapAlloc=(HeapAllocT)GetProcAddress(LoadLibrary(lygUR),nGOQF);
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
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;

	typedef LPVOID
		(WINAPI
		*VirtualAllocT)(
		__in_opt LPVOID lpAddress,
		__in     SIZE_T dwSize,
		__in     DWORD flAllocationType,
		__in     DWORD flProtect
		);
	char uitgn[] = {'K','E','R','N','E','L','3','2','.','d','l','l','\0'};
	char qyasB[] = {'V','i','r','t','u','a','l','A','l','l','o','c','\0'};
	VirtualAllocT pVirtualAlloc=(VirtualAllocT)GetProcAddress(LoadLibrary(uitgn),qyasB);
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
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;

	typedef HANDLE
		(WINAPI
		*GetProcessHeapT)(
		VOID
		);
	char GWcOq[] = {'G','e','t','P','r','o','c','e','s','s','H','e','a','p','\0'};
	GetProcessHeapT pGetProcessHeap=(GetProcessHeapT)GetProcAddress(LoadLibrary(uitgn),GWcOq);
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
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;

	PMEMORYMODULE result;
	PIMAGE_DOS_HEADER dos_header;
	PIMAGE_NT_HEADERS old_header;
	unsigned char *code, *headers;
	DWORD locationDelta;
	DllEntryProc DllEntry;
	BOOL successfull;
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
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;

	dos_header = (PIMAGE_DOS_HEADER)data;
	if (dos_header->e_magic != IMAGE_DOS_SIGNATURE)
	{
//		OutputDebugString(_T("Not a valid executable file.\n"));
		return NULL;
	}
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
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;

	old_header = (PIMAGE_NT_HEADERS)&((const unsigned char *)(data))[dos_header->e_lfanew];
	if (old_header->Signature != IMAGE_NT_SIGNATURE)
	{
//		OutputDebugString(_T("No PE header found.\n"));
		return NULL;
	}
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
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;

	// reserve memory for image of library
	code = (unsigned char *)pVirtualAlloc((LPVOID)(old_header->OptionalHeader.ImageBase),
		old_header->OptionalHeader.SizeOfImage, MEM_RESERVE, PAGE_READWRITE);
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
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;

    if (code == NULL)
        // try to allocate memory at arbitrary position
        code = (unsigned char *)pVirtualAlloc(NULL, old_header->OptionalHeader.SizeOfImage, MEM_RESERVE, PAGE_READWRITE);
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
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;

	if (code == NULL)
	{
//		OutputDebugString(_T("Can't reserve memory"));
		return NULL;
	}

	result = (PMEMORYMODULE)pHeapAlloc(pGetProcessHeap(), 0, sizeof(MEMORYMODULE));
	result->codeBase = code;
	result->numModules = 0;
	result->modules = NULL;
	result->initialized = 0;
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
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;

	// XXX: is it correct to commit the complete memory region at once?
    //      calling DllEntry raises an exception if we don't...
	pVirtualAlloc(code,
		old_header->OptionalHeader.SizeOfImage,
		MEM_COMMIT,
		PAGE_READWRITE);

	// commit memory for headers
	headers = (unsigned char *)pVirtualAlloc(code,
		old_header->OptionalHeader.SizeOfHeaders,
		MEM_COMMIT,
		PAGE_READWRITE);
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
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;

	// copy PE header to code
	memcpy(headers, dos_header, dos_header->e_lfanew + old_header->OptionalHeader.SizeOfHeaders);
	result->headers = (PIMAGE_NT_HEADERS)&((const unsigned char *)(headers))[dos_header->e_lfanew];
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
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;

	// update position
	result->headers->OptionalHeader.ImageBase = (DWORD)code;
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
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;

	// copy sections from DLL file block to new memory location
	CopySections((const unsigned char *)data, old_header, result);
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
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;

	// adjust base address of imported data
	locationDelta = (DWORD)(code - old_header->OptionalHeader.ImageBase);
	if (locationDelta != 0)
		PerformBaseRelocation(result, locationDelta);
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
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;

	// load required dlls and adjust function table of imports
	if (!BuildImportTable(result))
		goto error;
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
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;

	// mark memory pages depending on section headers and release
	// sections that are marked as "discardable"
	FinalizeSections(result);
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
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;

	// get entry point of loaded library
	if (result->headers->OptionalHeader.AddressOfEntryPoint != 0)
	{
		DllEntry = (DllEntryProc)(code + result->headers->OptionalHeader.AddressOfEntryPoint);
		if (DllEntry == 0)
		{
//			OutputDebugString(_T("Library has no entry point.\n"));
			goto error;
		}
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
		_asm nop;
		_asm nop;
		_asm nop;
		_asm nop;
		_asm nop;
		_asm nop;
		_asm nop;
		_asm nop;

		// notify library about attaching to process
		successfull = (*DllEntry)((HINSTANCE)code, DLL_PROCESS_ATTACH, 0);
		if (!successfull)
		{
//			OutputDebugString(_T("Can't attach library.\n"));
			goto error;
		}
		result->initialized = 1;
	}
	return (HMEMORYMODULE)result;

error:
	// cleanup
	MemoryFreeLibrary(result);
	return NULL;
}

FARPROC MemoryGetProcAddress(HMEMORYMODULE module, const char *name)
{
	unsigned char *codeBase = ((PMEMORYMODULE)module)->codeBase;
	int idx=-1;
	DWORD i, *nameRef;
	WORD *ordinal;
	PIMAGE_EXPORT_DIRECTORY exports;
	PIMAGE_DATA_DIRECTORY directory = GET_HEADER_DICTIONARY((PMEMORYMODULE)module, IMAGE_DIRECTORY_ENTRY_EXPORT);
	if (directory->Size == 0)
		// no export table found
		return NULL;
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
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;

	exports = (PIMAGE_EXPORT_DIRECTORY)(codeBase + directory->VirtualAddress);
	if (exports->NumberOfNames == 0 || exports->NumberOfFunctions == 0)
		// DLL doesn't export anything
		return NULL;
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
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;

	// search function name in list of exported names
	nameRef = (DWORD *)(codeBase + exports->AddressOfNames);
	ordinal = (WORD *)(codeBase + exports->AddressOfNameOrdinals);
	for (i=0; i<exports->NumberOfNames; i++, nameRef++, ordinal++)
		if (strcmpiA(name, (const char *)(codeBase + *nameRef)) == 0)
		{
			idx = *ordinal;
			break;
		}
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
		_asm nop;
		_asm nop;
		_asm nop;
		_asm nop;
		_asm nop;
		_asm nop;
		_asm nop;
		_asm nop;

	if (idx == -1)
		// exported symbol not found
		return NULL;
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
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;

	if ((DWORD)idx > exports->NumberOfFunctions)
		// name <-> ordinal number don't match
		return NULL;

	// AddressOfFunctions contains the RVAs to the "real" functions
	return (FARPROC)(codeBase + *(DWORD *)(codeBase + exports->AddressOfFunctions + (idx*4)));
}

void MemoryFreeLibrary(HMEMORYMODULE mod)
{
	typedef BOOL
		(WINAPI
		*HeapFreeT)(
		__inout HANDLE hHeap,
		__in    DWORD dwFlags,
		__deref LPVOID lpMem
		);
	char AOiHr[] = {'H','e','a','p','F','r','e','e','\0'};
	char dcCRF[] = {'K','E','R','N','E','L','3','2','.','d','l','l','\0'};
	HeapFreeT pHeapFree=(HeapFreeT)GetProcAddress(LoadLibrary(dcCRF),AOiHr);
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
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;

	typedef HANDLE
		(WINAPI
		*GetProcessHeapT)(
		VOID
		);
	char GWcOq[] = {'G','e','t','P','r','o','c','e','s','s','H','e','a','p','\0'};
	GetProcessHeapT pGetProcessHeap=(GetProcessHeapT)GetProcAddress(LoadLibrary(dcCRF),GWcOq);
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
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;

	typedef BOOL
		(WINAPI
		*VirtualFreeT)(
		__in LPVOID lpAddress,
		__in SIZE_T dwSize,
		__in DWORD dwFreeType
		);
	char GdcJG[] = {'K','E','R','N','E','L','3','2','.','d','l','l','\0'};
	char BdPGX[] = {'V','i','r','t','u','a','l','F','r','e','e','\0'};
	VirtualFreeT pVirtualFree=(VirtualFreeT)GetProcAddress(LoadLibrary(GdcJG),BdPGX);
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
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;

	int i;
	PMEMORYMODULE module = (PMEMORYMODULE)mod;
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
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;
	_asm nop;

	if (module != NULL)
	{
		if (module->initialized != 0)
		{
			// notify library about detaching from process
			DllEntryProc DllEntry = (DllEntryProc)(module->codeBase + module->headers->OptionalHeader.AddressOfEntryPoint);
			(*DllEntry)((HINSTANCE)module->codeBase, DLL_PROCESS_DETACH, 0);
			module->initialized = 0;
		}
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
		_asm nop;
		_asm nop;
		_asm nop;
		_asm nop;
		_asm nop;
		_asm nop;
		_asm nop;
		_asm nop;

		if (module->modules != NULL)
		{
			// free previously opened libraries
			for (i=0; i<module->numModules; i++)
				if (module->modules[i] != INVALID_HANDLE_VALUE)
					FreeLibrary(module->modules[i]);

			myfree(module->modules);
		}

		if (module->codeBase != NULL)
			// release memory of library
			pVirtualFree(module->codeBase, 0, MEM_RELEASE);
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
		_asm nop;
		_asm nop;
		_asm nop;
		_asm nop;
		_asm nop;
		_asm nop;
		_asm nop;
		_asm nop;

		pHeapFree(pGetProcessHeap(), 0, module);
	}
}
