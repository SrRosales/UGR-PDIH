#include <stdio.h>
#include <dos.h>

#define BYTE unsigned char

unsigned char cfondo = 0;
unsigned char ctexto = 1;

// Función de pausa

void pausa(){

   union REGS inregs, outregs;

   inregs.h.ah = 0x00;

   int86(0x16, &inregs, &outregs);

}

// Funcion que coloca el cursor en una posición determinada.

void gotoxy(int fil, int col){
	union REGS inregs, outregs;

	inregs.h.ah = 2;
	inregs.h.dh = fil;
	inregs.h.dl = col;
	inregs.h.bh = 0;
	int86(0x10, &inregs, &outregs);
}

// Funcion que fija el aspecto del cursor, debe admitir tres valores: INVISIBLE, NORMAL y GRUESO.

void setcursosrtype(int tipo_cursor){
    
    union REGS inregs, outregs;

    inregs.h.ah = 1;
    switch(tipo_cursor){
        case 0: // invisible
            inregs.h.ch = 010;
            inregs.h.cl = 000;
            break;
        case 1: // por fedecto
            inregs.h.ch = 010;
            inregs.h.cl = 010;
            break;
        case 2: // grueso
            inregs.h.ch = 000;
            inregs.h.cl = 010;
            break;
    }

    int86(0x10, &inregs, &outregs);

}

// Función que fija el modo de video deseado.

void setvideomode(BYTE modo){

    union REGS inregs, outregs;

    inregs.h.al = modo;
    inregs.h.ah = 0x00;
    int86(0x10, &inregs, &outregs);

}

// Función que obtiene el modo de video actual.

int getvideomode(){

    union REGS inregs, outregs;
    int modo;

    inregs.h.ah = 15;
    int86(0x10, &inregs, &outregs);

    modo = outregs.h.al;

    return modo;

}

// Función que modifica el color de primer plano con que se mostrarán los caracteres.

void textcolor(unsigned char _ctexto){

	ctexto = _ctexto;

}

// Función que modifica el color de fondo con que se mostrarán los caracteres.

void textbackground(unsigned char _cfondo){

	cfondo = _cfondo;

}

// Función que borra toda la pantalla.

void clrscr(){

    union REGS inregs, outregs;

    inregs.h.ah = 0x06;
    inregs.h.al = 0;
    inregs.h.dh = 0x25;
    inregs.h.dl = 0x80;
    inregs.h.bh = 0x00;
    inregs.x.cx = 0x00;
    int86(0x10, &inregs, &outregs);

}

// Función que escribe un carácter en pantalla con el color indicado actualmente.

void cputchar(char letra){

    union REGS inregs, outregs;

    inregs.h.ah = 0x09;
    inregs.h.al = letra;
    inregs.h.bl = cfondo << 4 | ctexto;
    inregs.h.bh = 0x00;
    inregs.x.cx = 1;
    int86(0x10, &inregs, &outregs);
    return;
	
}

// Función que obtiene un carácter de teclado y lo muestra en pantalla.

int getche(){

    union REGS inregs, outregs;
    int caracter;

    inregs.h.ah = 1;
    int86(0x21, &inregs, &outregs);

    caracter = outregs.h.al;
    return caracter;

}

void PintarCuadrado(int s_x, int s_y, int i_x, int i_y, unsigned char _color, unsigned char _fondo){

    char caracter = ' ';
    int i = 0;

    // Establecemos los colores
    textcolor(_color);
    textbackground(_fondo);

    // Nos movemos por el eje x y pintamos el lateral izquierdo
    for(i = s_x; i <= i_x; i++){
        gotoxy(i,s_y);
        cputchar(caracter);
    }

    // Nos movemos por el eje x y pintamos el lateral derecho
    for(i = s_x; i <= i_x; i++){
        gotoxy(i,i_y);
        cputchar(caracter);
    }

    // Nos movemos por el eje y y pintamos la parte de arriba
    for(i = s_y; i <= i_y; i++){
        gotoxy(s_y,i);
        cputchar(caracter);
    }
    
    // Nos movemos por el eje y y pintamos la parte de abajo
    for(i = s_y; i <= i_y; i++){
        gotoxy(i_y,i);
        cputchar(caracter);
    }

}

int main(){

    int sx, sy, ix, iy;

    clrscr();

    sx = 1;
    sy = 1;

    ix = 10;
    iy = 10;

    PintarCuadrado(sx, sy, ix, iy, 3, 3);

    pausa();

    setvideomode(3);

    return 0;

}