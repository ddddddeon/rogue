#include <ncurses.h>
#include <unistd.h>

#include "position.h"
#include "map.h"

int main(int argc, char *argv[]) {
    int c;
    coordinates coords = {
        .x = 0,
        .y = 0,
        .max_x = 0,
        .max_y = 0,
        .next_x = 0,
        .next_y = 0,
        .prev_x = 0,
        .prev_y = 0,
        .saved_char = "."
    };

    init_position(&coords);
    draw_dungeon(coords);
    
    while(1) {
        draw_position(&coords);
        c = getch();
        move_position(c, &coords);
    }

    endwin();
}
