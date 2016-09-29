#include <ncurses.h>
#include <unistd.h>

#include "position.h"

void init_position(coordinates *coords) {
    initscr();
    cbreak();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    getmaxyx(stdscr, coords->max_y, coords->max_x);

    coords->y = coords->max_y / 2;
    coords->x = coords->max_x / 2;
    coords->next_x = coords->x;
    coords->next_y = coords->y;
    coords->prev_x = coords->x;
    coords->prev_y = coords->y;
}

void draw_position(coordinates *coords) {
    //    mvdelch(coords->prev_y, coords->prev_x);
    mvprintw(coords->prev_y, coords->prev_x, coords->saved_char);

    mvprintw(coords->y, coords->x, "@");

#ifdef DEBUG
    mvprintw(0, 0, "x: %d", coords->x);
    mvprintw(1, 0, "y: %d", coords->y);
#endif

    refresh();
    usleep(DELAY);
}

void move_position(int c, coordinates *coords) {
    if (c == KEY_RIGHT) { 
        coords->next_x = coords->x + 1;
    } else if (c == KEY_DOWN) { 
        coords->next_y = coords->y + 1;
    } else if (c == KEY_LEFT) {
        coords->next_x = coords->x - 1;
    } else if (c == KEY_UP) {
        coords->next_y = coords->y - 1;
    }

    if (mvinch(coords->next_y, coords->next_x) == '#') {
        coords->next_x = coords->x;
        coords->next_y = coords->y;
    } else {
        
        if (!(coords->next_x >= coords->max_x ||
              coords->next_x < 0)) {
            
            
            coords->prev_x = coords->x;
            coords->x = coords->next_x;
        }
    
        if (!(coords->next_y >= coords->max_y ||
              coords->next_y < 0)) {

            coords->prev_y = coords->y;
            coords->y = coords->next_y;
        }
    }
}
