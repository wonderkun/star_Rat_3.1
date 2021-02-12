del ShellCode.h
del Zesr68f4.dllbak
copy Zesr68f4.dll Zesr68f4.dllbak
upx.exe Zesr68f4.dll -9
rename Zesr68f4.dll 1.dll
ShllCodeDec.exe
del 1.dll
rename 2.dll Zesr68f4.dll