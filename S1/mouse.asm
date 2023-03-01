
pila segment stack 'stack'
        dw 100h dup (?)
pila ends

datos segment 'data'
datos ends

codigo segment 'code'
	assume cs:codigo, ds:datos, ss:pila
	main PROC
		mov ax,datos
		mov ds,ax
		; modo de video GRAFICO
                mov al, 13h
                mov ah,0
                int 10h

                mov ax,0001
                int 33h

                ;mostrar el caracter '1'
                mov dl,'1'
                mov ah,2
                int 21h

                do_izq:
                        mov ax,5
                        mov bx,0  ; 0=izq ; 1=der
                        int 33h

                        cmp bx,0
                        je do_izq

                ; mostrar el caracter '2'
                mov dl,'2'
                mov ah,2
                int 21h

                do_der:
                        mov ax,5
                        mov bx,1  ; 0=izq ; 1=der
                        int 33h

                        cmp bx,0
                        je do_der

                ; mostrar el caracter '3'
                mov dl,'3'
                mov ah,2
                int 21h

                ; hacer una pausa
                mov ah,0
                int 16h
		
                ; modo de video TEXTO
                mov al, 3h
                mov ah,0
                int 10h

		; terminar y salir
                mov ax,4C00h
		int 21h
	main ENDP

codigo ends

END main
