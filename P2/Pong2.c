// 
// gcc Pong2.c -o Pong2 -lncurses
// 

#include <stdlib.h>
#include <ncurses.h>
#include <stdlib.h>

#define DELAY 55000

int main(int argc, char *argv[]){

 int filas, columnas;

    initscr();

    if (has_colors() == FALSE) {
    	endwin();
    	printf("Your terminal does not support color\n");
    	exit(1);
	}

    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    clear();

    refresh();
    getmaxyx(stdscr, filas, columnas);

    // JUEGO

    // Rango de espacio de la pelota
    int max_y = filas, max_x = columnas;    

    // Posicion inicial de la pelota
    int next_x = max_x/2;
    int next_y = max_y/2;
    int x = max_x/2, y = max_y/2;
    
    // Dirección de la pelota
    int directionx = 1, directiony = 1;

    // Jugador 1 Posición
    int J1_xc = 0, J1_yc = max_y/2;
    
    // Jugador 2 Posición
    int J2_xc = max_x - 1, J2_yc = max_y/2;

    //Puntuación de los jugadores
    int J1_Puntos = 0;
    int J2_Puntos = 0;

    initscr();
    noecho();
    cbreak();
    curs_set(FALSE);
    nodelay(stdscr, TRUE);
    
    while(1) {

        clear();

        // Pintamos el marcador con los puntos de ambos jugadores
        mvprintw(0, max_x/2 - 16, "%d :J1_Puntos | J2_Puntos: %d", J1_Puntos, J2_Puntos);

        // Pintamos opciones de salir y pausar
        mvprintw(max_y - 1, max_x/2 , "Q --> SALIR");
        mvprintw(max_y - 1, max_x/2 - 17, "P --> PAUSAR");

        // Pintamos la linea divisoria
        for(int i = 1; i < 37; i++){
            mvprintw(i, max_x/2 - 3, "|");
        }

        // Pintamos la pelota
        mvprintw(y, x, "o");

        // Pintamos al J1
        mvprintw(J1_yc, J1_xc, "|");

        // Pintamos al J2
        mvprintw(J2_yc, J2_xc, "|");

        // Lectura de pulsaciones
        switch(getch()){
            case 'w': J1_yc--; break;   // Si es W el J1 se mueve hacia arriba
            case 's': J1_yc++; break;   // Si es S el J1 se mueve hacia abajo
            case 'i': J2_yc--; break;   // Si es I el J2 se mueve hacia arriba
            case 'k': J2_yc++; break;   // Si es K el J2 se mueve hacia abajo
            case 'q': endwin(); exit(1); break; // Si es Q se sale del juego
            case 'p': getchar(); break; // Si es P se pausa el juego
        }

        usleep(DELAY);

        refresh();

        // Direccion de la pelota
        next_x = x + directionx;
        next_y = y + directiony;

        // Calculo del movimiento de la pelota en el eje X
        if (next_x == J2_xc && (next_y <= J2_yc && next_y >= J2_yc)) {
            directionx*= -1;
        } 
        else if(next_x == J1_xc && (next_y <= J1_yc && next_y >= J1_yc)) {
            directionx*= -1;
        }else{
            x += directionx;
        }

        // Calculo del movimiento de la pelota en el eje Y
        if (next_y >= max_y || next_y < 0) {
            directiony*= -1;
        } 
        else {
            y+= directiony;
        }

        // Calcular los puntos
        if(next_x > J2_xc){

            // Establecemos la posicion de la pelota a la inicial
            next_x = max_x/2;
            next_y = max_y/2;
            x = max_x/2, 
            y = max_y/2;

            // J1 suma 1 punto
            J1_Puntos++;

        }else if(next_x < J1_xc){

            // Establecemos la posicion de la pelota a la inicial
            next_x = max_x/2;
            next_y = max_y/2;
            x = max_x/2, 
            y = max_y/2;

            // J2 suma 1 punto
            J2_Puntos++;

        }
    }
}
