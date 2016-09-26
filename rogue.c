#include <ncurses.h>
#include <unistd.h>

#define DELAY 20000

int main(int argc, char *argv[]) {
    int x = 0;
    int y = 0;
    int max_y = 0;
    int max_x = 0;
    int next_x = 0;
    int next_y = 0;
    int direction = 0;
    int c;

    initscr();
    cbreak();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    getmaxyx(stdscr, max_y, max_x);

    y = max_y / 2;
    x = max_x / 2;
    next_x = x;
    next_y = y;

    while(1) {
        clear();
        mvprintw(y, x, "@");
        refresh();

        usleep(DELAY);
        
        c = getch();

        if (c == KEY_RIGHT) { 
            next_x = x + 1;
        } else if (c == KEY_DOWN) { 
            next_y = y + 1;
        } else if (c == KEY_LEFT) {
            next_x = x - 1;
        } else if (c == KEY_UP) {
            next_y = y - 1;
        }

        mvprintw(max_y - 2, max_x - 2, "next_x: %d", next_x);
        mvprintw(max_y - 1, max_x - 1, "next_y: %d", next_y);
       
        if (next_x >= max_x || next_x < 0 ||
            next_y >= max_y || next_y < 0) {
            beep();
        } else {
            x = next_x;
            y = next_y;
        }
        /*        
        next_x = 0;
        next_y = 0;
        */
    }

    endwin();
}
