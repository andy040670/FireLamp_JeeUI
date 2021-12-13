color 4A
setlocal
set workdir=%~dp0
PATH=%PATH%;%workdir%;%USERPROFILE%\.platformio\penv\Scripts;
echo off
cls

:m1
Echo  #****************************************#
Echo  #        Commands [91m[env:esp8266dev][92m       #
Echo  #----------------------------------------#
Echo  # Switch to MASTER branch           - ([97mm[92m)#
Echo  # Switch to DEV branch              - ([97md[92m)#
Echo  #----------------------------------------#
echo  # Reset changes in local repo!           #
Echo  # Update from Git repo              - ([97mu[92m)#
Echo  #----------------------------------------#
Echo  #       Build and upload firmware        #
Echo  # Update libs and PIO Core          - ([97m0[92m)#
Echo  # Update FS data from framework     - ([97m1[92m)#
Echo  #-------- [91mBuild and Uload by HTTP[92m -------#
Echo  # Build Esp8266@80dev               - ([97m2[92m)#
Echo  # Build File System (FS)            - ([97m3[92m)#
Echo  # Uload by http firmware.bin        - ([97m4[92m)#
Echo  # Uload by http littlefs.bin        - ([97m5[92m)#
Echo  #-------- [91mBuild and Uload by USB[92m -------=#
Echo  # Build and upload Esp8266@80dev    - ([97m6[92m)#
Echo  # Build and upload File System (FS) - ([97m7[92m)#
Echo  # Port monitor                      - ([97mp[92m)#
Echo  # Erase Flash                       - ([97m8[92m)#
Echo  #----------------------------------------#
Echo  # Clean up temp files .pio          - ([97m9[92m)#
Echo  #----------------------------------------#
Echo  # CMD window                        -([97m10[92m)#
Echo  #----------------------------------------#
Echo  # Clean Platformio installation     - [91m([97mr[91m)[92m#
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

if "%choice%"=="2" ("%USERPROFILE%\.platformio\penv\Scripts\pio.exe" run --environment esp8266dev)
if "%choice%"=="3" ("%USERPROFILE%\.platformio\penv\Scripts\pio.exe" run --target buildfs --environment esp8266dev)
if "%choice%"=="4" (curl -v http://192.168.1.70/update -F "name=@.pio\build\esp8266dev\firmware.bin")
if "%choice%"=="5" (curl -v http://192.168.1.70/update -F "name=@.pio\build\esp8266dev\littlefs.bin")
if "%choice%"=="6" ("%USERPROFILE%\.platformio\penv\Scripts\pio.exe" run --target upload --environment esp8266dev)
if "%choice%"=="7" ("%USERPROFILE%\.platformio\penv\Scripts\pio.exe" run --target uploadfs --environment esp8266dev)
if "%choice%"=="p" (start %workdir%\SerialMonitor.cmd)
if "%choice%"=="8" ("%USERPROFILE%\.platformio\penv\Scripts\pio.exe" run --target erase --environment esp8266dev)
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