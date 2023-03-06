#include <stdio.h>
#include <dos.h>

void mi_pausa(){

   union REGS inregs, outregs;
	 inregs.h.ah = 8;
	 int86(0x21, &inregs, &outregs);
}

int leer_letra(){

    union REGS inregs, outregs;
    int caracter;

    inregs.h.ah = 1;
    int86(0x21, &inregs, &outregs);

    caracter = outregs.h.al;
    return caracter;

}

void mostrar_letra(char c){
	 union REGS inregs, outregs;

	 inregs.h.ah = 2;
	 inregs.h.dl = c;
	 int86(0x21, &inregs, &outregs);
}

int main(){

    int tmp;

    printf("\nPulsa una tecla: ");

    tmp = leer_letra();

    printf("\nHas pulsado:  ");

    mostrar_letra((char)tmp);

    printf("\nPulsa para terminar.");

    mi_pausa();

    return 0;
}