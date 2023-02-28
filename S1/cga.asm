TEXTO   EQU 3
GRAFICO EQU 4
BLANCO  EQU 3
ROSA    EQU 2
VERDE   EQU 1

;MACRO pausa_tecla
;espera la pulsacion de una tecla
pausa_tecla MACRO
        push ax
        mov ah,0   ;funcion para leer una tecla
        int 16h    ;interrupcion BIOS para teclado
        pop ax
ENDM

;MACRO modo_video
;cambia el modo de video (texto-3 o grafico-4)
modo_video MACRO modo
        push ax
        mov al,modo
        mov ah,0
        int 10h
        pop ax
ENDM

;MACRO pixel
;pone un pixel en la coordenada X,Y de color C
pixel MACRO X,Y,C
        push ax
        push cx
		push dx
		mov ax,Y
		mov cx,X
		mov dx,ax
        mov al,C
        mov ah,0Ch
        int 10h
        pop dx
        pop cx
		pop ax
ENDM

pila segment stack 'stack'
	dw 100h dup (?)
pila ends

datos segment 'data'
		msg_pulsa_tecla db 'pulsa para continuar...',7,'$'
datos ends


codigo segment 'code'
	assume cs:codigo, ds:datos, ss:pila
	main PROC
		mov ax,datos
		mov ds,ax

		mov dx,OFFSET msg_pulsa_tecla
		mov ah,9
		int 21h
		pausa_tecla

		modo_video GRAFICO

		;pintar unos puntos por pantalla
		pixel 20,10,VERDE    	;puntos verdes
		pixel 110,90,VERDE

		;pintar una linea horizontal
		mov cx,300
		bucle1:
			pixel cx,40,VERDE
			dec cx
			jnz bucle1


		pixel 10,100,ROSA	;puntos rosa
		pixel 100,10,ROSA

		;pintar una linea vertical
		mov cx,190
		bucle2:
			pixel 100,cx,ROSA
			dec cx
			jnz bucle2


		pixel 70,50,BLANCO    ;puntos blancos
		pixel 50,70,BLANCO

		;pintar una linea diagonal
		mov cx,200
		bucle3:
			pixel cx,cx,BLANCO
			dec cx
			jnz bucle3


		pausa_tecla
		modo_video TEXTO

		mov ax,4C00h
		int 21h
	main ENDP
codigo ends

END main
