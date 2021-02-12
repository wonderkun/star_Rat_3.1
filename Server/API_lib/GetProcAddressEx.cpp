#include <windows.h>
#include "GetProcAddressEx.h"

DWORD __stdcall searchexport(DWORD modbase,DWORD szexportname);



FARPROC GetProcAddressEx(HMODULE hModule, LPCSTR pProcName)
{
	//return searchexport( (DWORD) hModule,(DWORD) pProcName );
	return GetProcAddress(hModule,pProcName);
}

__declspec(naked)
DWORD __stdcall searchexport(DWORD modbase,DWORD szexportname)
//copy from very early testing 'searchaddr' in 'PEinfect',self-reloc,case sensitive
{
	__asm{
		push ebp
		mov ebp,esp
		push ebx
		push esi
		push edi
		///
		mov al,0
		mov ecx,256
		mov edi,szexportname
		cld
		repnz scasb
		mov edx,256
		sub edx,ecx//edx:strlen
		///
		mov ebx,modbase//ebx: hold the modbase.
		mov esi,[ebx+60]//PEheaderRVA
		add esi,ebx	
		add esi,78h//datadirectory,no.1 is exporttable
		mov eax,[esi]//exptable RVA
		add eax,ebx
		mov esi,eax//exptable
		mov ecx,[esi+24]//ecx:num_of_names
		mov eax,[esi+32]
		add eax,ebx//eax:namestable

looper:	cmp ecx,0
		jz error
		dec ecx
		mov esi,[eax+4*ecx]
		add esi,ebx
		inc ecx
		push ecx
		mov ecx,edx
		mov edi,szexportname
		cld
		repz cmpsb
		pop ecx
		jz found
		dec ecx
		jmp looper
found:	dec ecx
		mov esi,[ebx+60]//PEheaderRVA
		add esi,ebx	
		add esi,78h//datadirectory,no.1 is exporttable
		mov esi,[esi]//exptable RVA
		add esi,ebx//exptable:esi
		mov esi,[esi+36]
		add esi,ebx//序号table
		mov ax,[esi+2*ecx]//x获得了
		mov esi,[ebx+60]//PEheaderRVA
		add esi,ebx	
		add esi,78h//datadirectory,no.1 is exporttable
		mov esi,[esi]//exptable RVA
		add esi,ebx//exptable:esi
		mov esi,[esi+28]
		add esi,ebx//地址table
		xor edi,edi
		movzx edi,ax
		mov eax,[esi+edi*4]
		add eax,ebx
		jmp end
error:
		xor eax,eax
		jmp end
end:
		pop edi
		pop esi
		pop ebx
		pop ebp
		ret 8
	}
}