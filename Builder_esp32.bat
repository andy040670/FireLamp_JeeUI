color 70
setlocal
set workdir=%~dp0
PATH=%PATH%;%workdir%;%USERPROFILE%\.platformio\penv\Scripts
echo off
cls

:m1
Echo  #****************************************#
Echo  #          Commands [91m[env:esp32][30m          #
Echo  #----------------------------------------#
Echo  # Switch to MASTER branch           - (m)#
Echo  # Switch to DEV branch              - (d)#
Echo  #----------------------------------------#
echo  # Reset changes in local repo!           #
Echo  # Update from Git repo              - (u)#
Echo  #----------------------------------------#
Echo  #       Build and upload firmware        #
Echo  # Update libs and PIO Core          - (0)#
Echo  # Update FS data from framework     - (1)#
Echo  #-------- [91mBuild and Uload by HTTP[30m -------#
Echo  # Build Esp32                       - (2)#
Echo  # Build File System (FS)            - (3)#
Echo  # Uload by http firmware.bin        - (4)#
Echo  # Uload by http littlefs.bin        - (5)#
Echo  #-------- [91mBuild and Uload by USB[30m -------=#
Echo  # Build and upload Esp32            - (6)#
Echo  # Build and upload File System (FS) - (7)#
Echo  # Port monitor                      - (p)#
Echo  # Erase Flash                       - (8)#
Echo  #----------------------------------------#
Echo  # Clean up temp files .pio          - (9)#
Echo  #----------------------------------------#
Echo  # CMD window                        -(10)#
Echo  #----------------------------------------#
Echo  # Clean Platformio installation     - (r)#
Echo  #****************************************#
Echo.
Set /p choice="Your choice: "

if not defined choice (
	echo.
	Echo Wrong command!
	goto m1
)

if "%choice%"=="m" (
	call update-DEV-from-Git.cmd 1
	"%USERPROFILE%\.platformio\penv\Scripts\pio.exe" lib update
)
if "%choice%"=="d" (
	call update-DEV-from-Git.cmd 2
	"%USERPROFILE%\.platformio\penv\Scripts\pio.exe" lib update
)

if "%choice%"=="u" call update-DEV-from-Git.cmd 3

if "%choice%"=="0" (
    "%USERPROFILE%\.platformio\penv\Scripts\pio.exe" update
	"%USERPROFILE%\.platformio\penv\Scripts\pio.exe" upgrade
	"%USERPROFILE%\.platformio\penv\Scripts\pio.exe" lib update
)

if "%choice%"=="1" (
	cd %workdir%\resources\
	start respack.cmd
	cd %workdir%
)

if "%choice%"=="2" ("%USERPROFILE%\.platformio\penv\Scripts\pio.exe" run --environment esp32)
if "%choice%"=="3" ("%USERPROFILE%\.platformio\penv\Scripts\pio.exe" run --target buildfs --environment esp32)
if "%choice%"=="4" (curl -v http://192.168.1.107/update -F "name=@.pio\build\esp32\firmware.bin")
if "%choice%"=="5" (curl -v http://192.168.1.107/update -F "name=@.pio\build\esp32\spiffs.bin")
if "%choice%"=="6" ("%USERPROFILE%\.platformio\penv\Scripts\pio.exe" run --target upload --environment esp32)
if "%choice%"=="7" ("%USERPROFILE%\.platformio\penv\Scripts\pio.exe" run --target uploadfs --environment esp32)
if "%choice%"=="p" (start %workdir%\SerialMonitor.cmd)
if "%choice%"=="8" ("%USERPROFILE%\.platformio\penv\Scripts\pio.exe" run --target erase --environment esp32)
if "%choice%"=="9" (
	pio system prune -f
	rmdir /S /Q %workdir%\.pio
)

if "%choice%"=="10" (start cmd)
if "%choice%"=="r" (rmdir /S "%USERPROFILE%\.platformio")
Echo.
Echo.
Echo.
pause
del %workdir%\resources\.wget-hsts
cls
goto m1


exit