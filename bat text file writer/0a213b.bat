@ECHO OFF
SETLOCAL ENABLEDELAYEDEXPANSION
@echo off
title exec 0a213b.exe

if exist 07d91c214e.key goto pass
exit

:pass
echo passcode:
set /p senha1=
if %senha1%==1234 goto cont
cls
echo wrong password
pause
exit

:cont
cls
echo [main menu]
echo.
echo 1.write new
echo 2.list
echo.
echo x.close
set /p errorlevel1=
if %errorlevel1%==1 goto save
if %errorlevel1%==2 goto list
if %errorlevel1%==x goto close
goto cont

:close
cls
echo closing..
echo del 07d91c214e.key
ren saves "Control Panel.{21EC2020-3AEA-1069-A2DD-08002B30309D}"
attrib +h +s "Control Panel.{21EC2020-3AEA-1069-A2DD-08002B30309D}"
pause
exit

:save
echo name the file:
set /p flname=
echo set the contents:
set /p contents=
echo.
attrib -h -s "Control Panel.{21EC2020-3AEA-1069-A2DD-08002B30309D}"
ren "Control Panel.{21EC2020-3AEA-1069-A2DD-08002B30309D}" saves
pause
echo %contents%>saves/%flname%.dat
ren saves "Control Panel.{21EC2020-3AEA-1069-A2DD-08002B30309D}"
attrib +h +s "Control Panel.{21EC2020-3AEA-1069-A2DD-08002B30309D}"
echo sucess!
pause
goto cont

:list
echo listing
echo.
attrib -h -s "Control Panel.{21EC2020-3AEA-1069-A2DD-08002B30309D}"
ren "Control Panel.{21EC2020-3AEA-1069-A2DD-08002B30309D}" saves
cd saves/
dir
ren saves "Control Panel.{21EC2020-3AEA-1069-A2DD-08002B30309D}"
attrib +h +s "Control Panel.{21EC2020-3AEA-1069-A2DD-08002B30309D}"
echo.
echo type the name of the file you want to open (without `.dat`)
echo type `b` to go back
echo type `x` to exit
set /p errorlevel2=
if %errorlevel2%==b goto cont
if %errorlevel2%==x goto exit
attrib -h -s "Control Panel.{21EC2020-3AEA-1069-A2DD-08002B30309D}"
ren "Control Panel.{21EC2020-3AEA-1069-A2DD-08002B30309D}" saves
cd saves/
echo.
type %errorlevel2%.dat
echo.
ren saves "Control Panel.{21EC2020-3AEA-1069-A2DD-08002B30309D}"
attrib +h +s "Control Panel.{21EC2020-3AEA-1069-A2DD-08002B30309D}"
echo type `b` to clean and go back
pause
cls
goto list

