#include <ncurses.h>
#include <unistd.h>

#include "movement.h"

void init_position(coordinates *coords) {
    mvprintw(coords->y, coords->x, "@");
    mvprintw(0, 0, "next_x: %d", coords->next_x);
    mvprintw(1, 0, "next_y: %d", coords->next_y);

    refresh();
    
    usleep(DELAY);
}

void move_one(int c, coordinates *coords) {
    
    if (c == KEY_RIGHT) { 
        coords->next_x = coords->x + 1;
    } else if (c == KEY_DOWN) { 
        coords->next_y = coords->y + 1;
    } else if (c == KEY_LEFT) {
        coords->next_x = coords->x - 1;
    } else if (c == KEY_UP) {
        coords->next_y = coords->y - 1;
    }
        
    if (coords->next_x >= coords->max_x || coords->next_x < 0 ||
        coords->next_y >= coords->max_y || coords->next_y < 0) {
        beep();
    } else {
        coords->x = coords->next_x;
        coords->y = coords->next_y;
    }
}
