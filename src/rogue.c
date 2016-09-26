#include <ncurses.h>
#include <unistd.h>

#include "movement.h"

int main(int argc, char *argv[]) {
    coordinates coords = {
        .x = 0,
        .y = 0,
        .max_x = 0,
        .max_y = 0,
        .next_x = 0,
        .next_y = 0
    };

    int c;

    initscr();
    cbreak();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    getmaxyx(stdscr, coords.max_y, coords.max_x);

    coords.y = coords.max_y / 2;
    coords.x = coords.max_x / 2;
    coords.next_x = coords.x;
    coords.next_y = coords.y;

    while(1) {
        clear();
        init_position(&coords);
        c = getch();
        move_one(c, &coords);
    }

    endwin();
}
