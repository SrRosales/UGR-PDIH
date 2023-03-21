// 
// gcc Ejer2.c -o Ejer2 -lncurses
// 

#include <ncurses.h>
#include <unistd.h>

#define DELAY 30000

int main(int argc, char *argv[]){

    int x = 0, y = 0;
    int max_y = 50, max_x = 50;
    int next_x = 0;
    int direction = 1;

    initscr();
    noecho();
    curs_set(FALSE);

    while(1){

        clear();
        mvprintw(y, x, "o");
        refresh();

        usleep(DELAY);

        next_x = x + direction;

        if(next_x >= max_x || next_x < 0){

            direction *= -1;

        }else{

            x += direction;
        }
    }

    endwin();
}