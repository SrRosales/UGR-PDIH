@echo off

REM  compila el archivo que se le pasa como parámetro (sin extensión)

c:\BC\BIN\BCC -Ic:\BC\INCLUDE -Lc:\BC\LIB	%1.C


REM    bc /m  archivo.c

