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

void pixel(int x, int y, BYTE c){

    union REGS inregs, outregs;
    
    inregs.x.cx = x;
    inregs.x.dx = y;
    inregs.h.al = c;
    inregs.h.ah = 0x0C;

    int86(0x10, &inregs, &outregs);

}

void dibujo(){
    int i;

    setvideomode(4);

    // Techo
    // Derecha

    for(i = 10; i <= 40; i++){
        pixel(40+i,i,2);
    }

    // Izquierda

    for(i = 10; i <= 40; i++){
        pixel(60-i,i,2);
    }

    // Parte de abajo

    for(i = 10; i <= 70; i++){
        pixel(i+10,40,2);
    }

    // Base

    // Lateral izquierdo

    for(i = 10; i <= 50; i++){
        pixel(20,i+30,2);
    }    

    // Lateral derecho

       for(i = 10; i <= 50; i++){
        pixel(80,i+30,2);
    }  

    // Parte de abajo

    for(i = 10; i <= 70; i++){
        pixel(i+10,80,2);
    } 

    // Puerta

    // Lateral Izquierdo

    for(i = 0; i <= 15; i++){
        pixel(45,i+65,3);
    } 

    // Lateral Derecho

    for(i = 0; i <= 15; i++){
        pixel(55,i+65,3);
    } 

    // Parte de Arriba

    for(i = 0; i <= 10; i++){
        pixel(i+45,65,3);
    } 

    // Ventanal

    // Parte de Arriba
    
    for(i = 10; i <= 60; i++){
        pixel(i+15,45,1);
    } 

    // Parte de abajo

    for(i = 10; i <= 60; i++){
        pixel(i+15,55,1);
    } 

    // Lateral Izquierdo

    for(i = 0; i <= 10; i++){
        pixel(25,i+45,1);
    }

    // Lateral Derecho

    for(i = 0; i <= 10; i++){
        pixel(75,i+45,1);
    }

    // Divisiones

    for(i = 0; i <= 10; i++){
        pixel(35,i+45,1);
    }

    for(i = 0; i <= 10; i++){
        pixel(45,i+45,1);
    }

    for(i = 0; i <= 10; i++){
        pixel(55,i+45,1);
    }

    for(i = 0; i <= 10; i++){
        pixel(65,i+45,1);
    }
}

int main(){

    clrscr();

    pausa();

    dibujo();

    pausa();

    setvideomode(3);

    return 0;

}