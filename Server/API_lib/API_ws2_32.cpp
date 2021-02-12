#include <windows.h>
#include "API_ws2_32.h"
#include "GetProcAddressEx.h"

char sXaMJ[] = {'c','o','n','n','e','c','t','\0'};
int PASCAL FAR API_connect (
                        IN SOCKET s,
                        IN const struct sockaddr FAR *name,
                        IN int namelen)
{
	int ret = NULL;
	typedef int (WINAPI *lpAddFun)(SOCKET,const struct sockaddr FAR *,int);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"WS2_32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,sXaMJ); //��������
	if (addFun != NULL)
	{
		ret = addFun(s,name,namelen);//���ú���
	}
	return ret;
}

char hqGcA[] = {'W','S','A','I','o','c','t','l','\0'};
int PASCAL FAR API_WSAIoctl
(
    IN SOCKET s,
    IN DWORD dwIoControlCode,
    IN LPVOID lpvInBuffer,
    IN DWORD cbInBuffer,
    OUT LPVOID lpvOutBuffer,
    IN DWORD cbOutBuffer,
    OUT LPDWORD lpcbBytesReturned,
    IN LPWSAOVERLAPPED lpOverlapped,
    IN LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine
    )
{
	int ret = NULL;
	typedef int (WINAPI *lpAddFun)(SOCKET,DWORD,LPVOID,DWORD,LPVOID,DWORD,LPDWORD,LPWSAOVERLAPPED,LPWSAOVERLAPPED_COMPLETION_ROUTINE);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"WS2_32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,hqGcA); //��������
	if (addFun != NULL)
	{
		ret = addFun(s,dwIoControlCode,lpvInBuffer,cbInBuffer,lpvOutBuffer,cbOutBuffer,lpcbBytesReturned,lpOverlapped,lpCompletionRoutine);//���ú���
	}
	return ret;
}


char yMLas[] = {'W','S','A','S','t','a','r','t','u','p','\0'};
int PASCAL FAR API_WSAStartup(
                          IN WORD wVersionRequired,
                          OUT LPWSADATA lpWSAData)
{
	int ret = NULL;
	typedef int (WINAPI *lpAddFun)(WORD,LPWSADATA);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"WS2_32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,yMLas); //��������
	if (addFun != NULL)
	{
		ret = addFun(wVersionRequired,lpWSAData);//���ú���
	}
	return ret;
}


char bujmb[] = {'W','S','A','C','l','e','a','n','u','p','\0'};
int PASCAL FAR API_WSACleanup(void)
{
	int ret = NULL;
	typedef int (WINAPI *lpAddFun)(void);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"WS2_32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,bujmb); //��������
	if (addFun != NULL)
	{
		ret = addFun();//���ú���
	}
	return ret;
}


char lQrfx[] = {'g','e','t','h','o','s','t','b','y','n','a','m','e','\0'};
struct hostent FAR * PASCAL FAR API_gethostbyname(IN const char FAR * name)
{
	hostent FAR * ret = NULL;
	typedef hostent FAR * (WINAPI *lpAddFun)(const char FAR *);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"WS2_32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,lQrfx); //��������
	if (addFun != NULL)
	{
		ret = addFun(name);//���ú���
	}
	return ret;
}


char LRdsd[] = {'s','e','t','s','o','c','k','o','p','t','\0'};
int PASCAL FAR API_setsockopt (
                           IN SOCKET s,
                           IN int level,
                           IN int optname,
                           IN const char FAR * optval,
                           IN int optlen)
{
	int ret = NULL;
	typedef int (WINAPI *lpAddFun)(SOCKET,int,int,const char FAR *,int);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"WS2_32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,LRdsd); //��������
	if (addFun != NULL)
	{
		ret = addFun(s,level,optname,optval,optlen);//���ú���
	}
	return ret;
}


char iTBvK[] = {'g','e','t','h','o','s','t','n','a','m','e','\0'};
int PASCAL FAR API_gethostname (
                            OUT char FAR * name,
                            IN int namelen)
{
	int ret = NULL;
	typedef int (WINAPI *lpAddFun)(char FAR *,int);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"WS2_32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,iTBvK); //��������
	if (addFun != NULL)
	{
		ret = addFun(name,namelen);//���ú���
	}
	return ret;
}


char Lpbrg[] = {'g','e','t','s','o','c','k','n','a','m','e','\0'};
int PASCAL FAR API_getsockname (
                            IN SOCKET s,
                            OUT struct sockaddr FAR *name,
                            IN OUT int FAR * namelen)
{
	int ret = NULL;
	typedef int (WINAPI *lpAddFun)(SOCKET,struct sockaddr FAR *,int FAR *);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"WS2_32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,Lpbrg); //��������
	if (addFun != NULL)
	{
		ret = addFun(s,name,namelen);//���ú���
	}
	return ret;
}


char dEhtL[] = {'s','o','c','k','e','t','\0'};
SOCKET PASCAL FAR API_socket (
                          IN int af,
                          IN int type,
                          IN int protocol)
{
	SOCKET ret = NULL;
	typedef SOCKET (WINAPI *lpAddFun)(int,int,int);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"WS2_32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,dEhtL); //��������
	if (addFun != NULL)
	{
		ret = addFun(af,type,protocol);//���ú���
	}
	return ret;
}


char shRLY[] = {'h','t','o','n','s','\0'};
u_short PASCAL FAR API_htons (IN u_short hostshort)
{
	u_short ret = NULL;
	typedef u_short (WINAPI *lpAddFun)(u_short);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"WS2_32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,shRLY); //��������
	if (addFun != NULL)
	{
		ret = addFun(hostshort);//���ú���
	}
	return ret;
}


char kfCXM[] = {'n','t','o','h','s','\0'};
u_short PASCAL FAR API_ntohs (IN u_short netshort)
{
	u_short ret = NULL;
	typedef u_short (WINAPI *lpAddFun)(u_short);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"WS2_32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,kfCXM); //��������
	if (addFun != NULL)
	{
		ret = addFun(netshort);//���ú���
	}
	return ret;
}


char cZvTL[] = {'r','e','c','v','\0'};
int PASCAL FAR API_recv (
                     IN SOCKET s,
                     OUT char FAR * buf,
                     IN int len,
                     IN int flags)
{
	int ret = NULL;
	typedef int (WINAPI *lpAddFun)(SOCKET,char FAR *,int,int);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"WS2_32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,cZvTL); //��������
	if (addFun != NULL)
	{
		ret = addFun(s,buf,len,flags);//���ú���
	}
	return ret;
}


char cjKEn[] = {'s','e','l','e','c','t','\0'};
int PASCAL FAR API_select (
                        IN int nfds,
                        IN OUT fd_set FAR *readfds,
                        IN OUT fd_set FAR *writefds,
                        IN OUT fd_set FAR *exceptfds,
                        IN const struct timeval FAR *timeout)
{
	int ret = NULL;
	typedef int (WINAPI *lpAddFun)(int,fd_set FAR *,fd_set FAR *,fd_set FAR *,const struct timeval FAR *);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"WS2_32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,cjKEn); //��������
	if (addFun != NULL)
	{
		ret = addFun(nfds,readfds,writefds,exceptfds,timeout);//���ú���
	}
	return ret;
}


char RLHCT[] = {'s','e','n','d','\0'};
int PASCAL FAR API_send (
                     IN SOCKET s,
                     IN const char FAR * buf,
                     IN int len,
                     IN int flags)
{
	int ret = NULL;
	typedef int (WINAPI *lpAddFun)(SOCKET,const char FAR *,int,int);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"WS2_32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,RLHCT); //��������
	if (addFun != NULL)
	{
		ret = addFun(s,buf,len,flags);//���ú���
	}
	return ret;
}


char cFsFg[] = {'c','l','o','s','e','s','o','c','k','e','t','\0'};
int PASCAL FAR API_closesocket ( IN SOCKET s)
{
	int ret = NULL;
	typedef int (WINAPI *lpAddFun)(SOCKET);    //����ֵ,�β����Ͳο���������
	HINSTANCE hDll=LoadLibraryW(L"WS2_32.dll");    //�������ڵ�DLL
	lpAddFun addFun=(lpAddFun)GetProcAddressEx(hDll,cFsFg); //��������
	if (addFun != NULL)
	{
		ret = addFun(s);//���ú���
	}
	return ret;
}