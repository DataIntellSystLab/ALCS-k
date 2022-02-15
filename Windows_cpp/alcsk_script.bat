echo %time%
ext1.exe 12 caenor.fasta sorangium.fasta T11T21
IF %ERRORLEVEL% EQU 0 sort outT1.txt /o sortstrT1.txt
IF %ERRORLEVEL% EQU 0 sort outT2.txt /o sortstrT2.txt
IF %ERRORLEVEL% EQU 0 ext2.exe
IF %ERRORLEVEL% EQU 0 sort strcomT1.txt /o sortstrcomT1.txt
IF %ERRORLEVEL% EQU 0 sort strcomT2.txt /o sortstrcomT2.txt
IF %ERRORLEVEL% EQU 0 ext3.exe
IF %ERRORLEVEL% EQU 0 sort strextT1.txt /+17 /o sortstrextT1.txt
IF %ERRORLEVEL% EQU 0 sort strextT2.txt /+17 /o sortstrextT2.txt
IF %ERRORLEVEL% EQU 0 ext4.exe
IF %ERRORLEVEL% EQU 0 sort strextT1T2.txt /rec 40000 /o sortstrextT1T2.txt
IF %ERRORLEVEL% EQU 0 ext5.exe
echo %time%
