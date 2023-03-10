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

int main(){

    /* 

----1.GOTOXY----------------------------

    int tmp;
    int fil, col;

	fil = 10;
	col = 17;

    gotoxy(fil,col);

    tmp = getche();

    textcolor(2);

    textbackground(6);

    cputchar((char) tmp);
    

----2.SETCURSORTYPE----------------------------

    int tmp;

    printf("\nPulsa una tecla.");
    printf("\n Pulse 0 --> Cursor invisible.");
    printf("\n Pulse 1 --> Cursor normal.");
    printf("\n Pulse 2 --> Cursor grueso.\n");

    tmp = getche();

    if(tmp == '0'){
        setcursosrtype(0);
        printf("\nCursor establecido a invisible");
    }
    else if(tmp == '1'){
        setcursosrtype(1);
        printf("\nCursor establecido a normal");
    }
    else if(tmp == '2'){
        setcursosrtype(2);
        printf("\nCursor establecido a grueso");
    }
    else{
        printf("\nValor incorrecto, pulse 0, 1 0 2");
    }

----3.SETVIDEMODE----------------------------

    int tmp;

    printf("\nPulsa una tecla.");
    printf("\nPula 3 --> Modo Texto.");
    printf("\nPula 4 --> Modo Gráfico.\n");

    tmp = getche();

    if(tmp == '3'){
        setvideomode(3);
    }
    else if(tmp == '4'){
        setvideomode(4);
    }
    else{
        printf("\nValor incorrecto, pulse 3 o 4");
    }
    
----4.GETVIDEOMODE----------------------------

    int modo;

    modo = getvideomode();

    printf("\n Estas en el modo: ");
    printf("%d",modo);
    

----5.TEXTCOLOR----------------------------
    char letra;

    textcolor(4);

    letra = getche();

    cputchar(letra);
    
----6.TEXTBACKGROUND----------------------------

    char letra;

    textcolor(4);

    textbackground(15);

    letra = getche();

    cputchar(letra);

----7.CLRSCR----------------------------

    clrscr();

----8.CPUTCHAR----------------------------

    char letra;

    textcolor(4);

    textbackground(15);

    letra = getche();

    cputchar(letra);
    
----9.GETCHE----------------------------

    int tmp;

    printf("\nPulsa una tecla.");

    tmp = getche();

    printf("\nHas pulsado: ");
    cputchar((char) tmp);

    */

    return 0;

}