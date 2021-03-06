#ifndef POSITION_H
#define POSITION_H

#include <ncurses.h>
#include <unistd.h>

#define DELAY 30000

typedef struct {
    int x;
    int y;
    int max_y;
    int max_x;
    int next_x;
    int next_y;
    int prev_x;
    int prev_y;
    char* saved_char;
} coordinates;

void init_position(coordinates *coords);
void draw_position(coordinates *coords);
void move_position(int c, coordinates *coords);

#endif /* POSITION_H */
