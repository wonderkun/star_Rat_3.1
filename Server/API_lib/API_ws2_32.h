#pragma once

#include <winsock.h>



int PASCAL FAR API_connect (
                        IN SOCKET s,
                        IN const struct sockaddr FAR *name,
                        IN int namelen);

//
typedef struct _OVERLAPPED *    LPWSAOVERLAPPED;

typedef void
(CALLBACK * LPWSAOVERLAPPED_COMPLETION_ROUTINE)(
    IN DWORD dwError,
    IN DWORD cbTransferred,
    IN LPWSAOVERLAPPED lpOverlapped,
    IN DWORD dwFlags
    );
//

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
    );

int PASCAL FAR API_WSAStartup(
                          IN WORD wVersionRequired,
                          OUT LPWSADATA lpWSAData);

int PASCAL FAR API_WSACleanup(void);

struct hostent FAR * PASCAL FAR API_gethostbyname(IN const char FAR * name);

int PASCAL FAR API_setsockopt (
                           IN SOCKET s,
                           IN int level,
                           IN int optname,
                           IN const char FAR * optval,
                           IN int optlen);

int PASCAL FAR API_gethostname (
                            OUT char FAR * name,
                            IN int namelen);

int PASCAL FAR API_getsockname (
                            IN SOCKET s,
                            OUT struct sockaddr FAR *name,
                            IN OUT int FAR * namelen);

SOCKET PASCAL FAR API_socket (
                          IN int af,
                          IN int type,
                          IN int protocol);

u_short PASCAL FAR API_htons (IN u_short hostshort);

u_short PASCAL FAR API_ntohs (IN u_short netshort);

int PASCAL FAR API_recv (
                     IN SOCKET s,
                     OUT char FAR * buf,
                     IN int len,
                     IN int flags);

int PASCAL FAR API_select (
                        IN int nfds,
                        IN OUT fd_set FAR *readfds,
                        IN OUT fd_set FAR *writefds,
                        IN OUT fd_set FAR *exceptfds,
                        IN const struct timeval FAR *timeout);

int PASCAL FAR API_send (
                     IN SOCKET s,
                     IN const char FAR * buf,
                     IN int len,
                     IN int flags);

int PASCAL FAR API_closesocket ( IN SOCKET s);