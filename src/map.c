#include <ncurses.h>

#include "map.h"

void draw_rectangle(int height, int width, int start_y, int start_x) {
    int x;
    int y;

    for (y = start_y; y <= start_y + height; y++) {
        mvprintw(y, start_x, "#");
        mvprintw(y, start_x + width, "#");
    }

    for (x = start_x; x <= start_x + width; x++) {
        mvprintw(start_y, x, "#");
        mvprintw(start_y + height, x, "#");
    }
 
}


void draw_dungeon(coordinates coords) {
    draw_rectangle(10, 20, (coords.max_y / 2) - 5, (coords.max_x / 2) - 10);
}
