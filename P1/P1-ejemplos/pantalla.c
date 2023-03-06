#include <stdio.h>
#include <dos.h>


void mi_pausa(){
   union REGS inregs, outregs;
	 inregs.h.ah = 8;
	 int86(0x21, &inregs, &outregs);
}

void mi_modo_video(unsigned char modo){
	union REGS inregs, outregs; 
	inregs.h.ah = 0x00; 
	inregs.h.al = modo; 
	int86(0x10,&inregs,&outregs); 
	return;
}

int main(){

	mi_modo_video(1);  // modo 1 -> 40x25 (letras grandes)

	printf("\nEn C. Pulsa una tecla...  ");

   	mi_pausa();

	mi_modo_video(3);  // modo 3 -> 80x25 (letras pequeñas)

	return 0;
}
