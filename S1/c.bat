@echo off

REM  Espera el nombre de un fichero con codigo ensamblador
REM  Solo necesita el nombre, sin extension

if "%1"=="" goto :error_parametros
if NOT EXIST "%1.asm" goto :error_parametros

REM  si existe el fichero, lo compilamos, enlazamos y depuramos:
c:\BC\BIN\TASM /zi  %1.asm
c:\BC\BIN\TLINK /v  %1.obj

goto :fin

:error_parametros
        echo ERROR: Necesito el nombre de un fichero con codigo ensamblador.
        echo AVISO: Solo necesito el nombre del fichero, sin extension.

:fin
