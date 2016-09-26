#include <ncurses.h>
#include <unistd.h>

#include "movement.h"

int main(int argc, char *argv[]) {
    int c;

    coordinates coords = {
        .x = 0,
        .y = 0,
        .max_x = 0,
        .max_y = 0,
        .next_x = 0,
        .next_y = 0
    };


    init_position(&coords);

    while(1) {
        clear();
        movement_refresh(&coords);
        c = getch();
        move_one(c, &coords);
    }

    endwin();
}
