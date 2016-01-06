@REM This script allows a 3rd party IDE to use CyHexTool to perform
@REM any post processing that is necessary to convert the raw flash
@REM image into a complete hex file to use in programming the PSoC.
@REM USAGE: post_link.bat
@REM    arg1: Persistant path back to the directory containing the app project.
@REM    arg2: Path (relative to arg1) of the directory where the hex files go.
@REM    arg3: Name of the project.
@REM NOTE: This script is auto generated. Do not modify.

"C:\Program Files\Cypress\PSoC Creator\2.2\PSoC Creator\bin\cyvalidateide.exe" -dev CY8C5667LTI-LP009 -ide "%~1\%~3" -flsAddr 0x0 -flsSize 0x20000 -sramAddr 0x1FFFC000 -sramSize 0x8000
@IF %errorlevel% NEQ 0 EXIT /b %errorlevel% 
move "%~1\%~2\%~n3.hex" "%~1\%~2\%~n3.ihx"
@IF %errorlevel% NEQ 0 EXIT /b %errorlevel% 
"C:\Program Files\Cypress\PSoC Creator\2.2\PSoC Creator\bin\cyhextool" -o "%~1\%~2\%~n3.hex" -f "%~1\%~2\%~n3.ihx" -prot "%~dp0protect.hex" -id 2E109069 -a EEPROM=90200000:800,PROGRAM=00000000:20000,CONFIG=80000000:4000,PROTECT=90400000:80 -meta 0001 -cunv 00004007 -wonv BC90ACAF -ecc "%~dp0config.hex" 
@IF %errorlevel% NEQ 0 EXIT /b %errorlevel% 
CD /D "C:\Keil\UV4"
@IF %errorlevel% NEQ 0 EXIT /b %errorlevel% 
IF NOT EXIST "\\psf\Home\Desktop\PSOC5LP dev\non-boot-bit-shift-CY8C5667\PioneerKit_P5LP_USB_Audio\PioneerKit_P5LP_USB_Audio.cydsn\PioneerKit_P5LP_USB_Audio.svd" rem "\\psf\Home\Desktop\PSOC5LP dev\non-boot-bit-shift-CY8C5667\PioneerKit_P5LP_USB_Audio\PioneerKit_P5LP_USB_Audio.cydsn\PioneerKit_P5LP_USB_Audio.sfr"
@IF %errorlevel% NEQ 0 EXIT /b %errorlevel% 
