# Microsoft Developer Studio Project File - Name="Video" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=Video - Win32 Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Video.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Video.mak" CFG="Video - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Video - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe
# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "Video_EXPORTS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /GX /I "../../common" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "Video_EXPORTS" /FR /Yu"stdafx.h" /FD /c
# SUBTRACT CPP /O<none>
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# ADD LINK32 STRMBASE.lib libxvidcore.lib capture.lib kernel32.lib user32.lib gdi32.lib MSVCRT.lib /nologo /dll /machine:I386 /out:"../../bin/Plugins/BWebCam.dll"
# Begin Target

# Name "Video - Win32 Release"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\Dllcomment\Buffer.cpp
# End Source File
# Begin Source File

SOURCE=.\CaptureVideo.cpp
# End Source File
# Begin Source File

SOURCE=..\Dllcomment\ClientSocket.cpp
# End Source File
# Begin Source File

SOURCE=..\Dllcomment\Manager.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=..\Dllcomment\until.cpp
# End Source File
# Begin Source File

SOURCE=.\Video.cpp
# End Source File
# Begin Source File

SOURCE=.\VideoManager.cpp
# End Source File
# Begin Source File

SOURCE=.\XvidEnc.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\Dllcomment\Audio.h
# End Source File
# Begin Source File

SOURCE=..\Dllcomment\Buffer.h
# End Source File
# Begin Source File

SOURCE=.\CaptureVideo.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\VideoCap.h
# End Source File
# Begin Source File

SOURCE=.\VideoCodec.h
# End Source File
# Begin Source File

SOURCE=.\VideoManager.h
# End Source File
# Begin Source File

SOURCE=.\xvid.h
# End Source File
# Begin Source File

SOURCE=.\XvidEnc.h
# End Source File
# Begin Source File

SOURCE=..\Dllcomment\zconf.h
# End Source File
# Begin Source File

SOURCE=..\Dllcomment\zlib.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
