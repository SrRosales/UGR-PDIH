#include <dos.h>

#define BYTE unsigned char

BYTE MODOTEXTO = 3;
BYTE MODOGRAFICO = 4;

// hace una pausa
void pausa(){
   union REGS inregs, outregs;
   inregs.h.ah = 0x00;
   int86(0x16, &inregs, &outregs);
}

// establece el modo de vídeo: 3-texto, 4-gráfico
void modovideo(BYTE modo){
   union REGS inregs, outregs;
   inregs.h.al = modo;
   inregs.h.ah = 0x00;
   int86(0x10, &inregs, &outregs);
}

// pone un pixel en la coordenada X,Y de color C
void pixel(int x, int y, BYTE C){
   union REGS inregs, outregs;
   inregs.x.cx = x;
   inregs.x.dx = y;
   inregs.h.al = C;
   inregs.h.ah = 0x0C;
   int86(0x10, &inregs, &outregs);
}

/*#################################################################################*/
int main(){
   int i;
   
   modovideo(MODOGRAFICO); //gráfico

   pixel(10,40,0);
   pixel(10,50,1);
   pixel(15,60,2);
   pixel(20,70,3);

   for(i=0; i<100; i++){
      pixel(i,i, i%4 );
   }

   pausa();
   modovideo(MODOTEXTO); //texto

	return 0;
}
