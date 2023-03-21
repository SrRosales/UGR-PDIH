// 
// gcc Ejer1.c -o Ejer1 -lncurses
// 

#include <stdlib.h>
#include <ncurses.h>

int main(){

    int filas, columnas;

    initscr();

    if(has_colors() == FALSE){

        endwin();
        printf("El terminal no tiene soporte de color\n");
        exit(1);

    }

    start_color();

    init_pair(1,COLOR_YELLOW, COLOR_GREEN);
    init_pair(2, COLOR_BLACK, COLOR_WHITE);
    init_pair(3, COLOR_WHITE, COLOR_BLUE);
    clear();

    refresh();
    getmaxyx(stdscr, filas, columnas);

    WINDOW *window = newwin(filas,columnas,0,0);
    wbkgd(window, COLOR_PAIR(3));
    box(window, '|', '-');

    mvwprintw(window, 10, 10, "una cadena");
    wrefresh(window);

    getch();
    endwin();

    return 0;
}