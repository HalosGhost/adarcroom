
// Libraries //
#include <ncurses.h>
#include <getopt.h>
#include <stdio.h>
#include "main.h"

#define WLOG(x, y) wscrl(wins[LOG], -(x)); mvwprintw(wins[LOG], 0, 1, (y));

// Main Function //
int
main (int argc, char * argv []) {

    struct adr_state state = {
        .fire = ROARING,
        .temp = FREEZING,
        .rs = { [WOOD] = 15 },
    };

    enum WIN_TYPE {
        LOG, TRVL, INV, ROOM, OTSD, PATH, WRLD, SHIP
    };

    char fire_msg [23];
    char temp_msg [22];
    snprintf(fire_msg, 23, "The fire is %s.", FIRE_DESC[state.fire]);
    snprintf(temp_msg, 22, "The room is %s.", TEMP_DESC[state.temp]);

    WINDOW * wins [SHIP + 1];
    initscr(); noecho(); cbreak(); curs_set(0);
    refresh();
    wins[LOG] = newwin(LINES - 1, 35, 1, 1);
    scrollok(wins[LOG], TRUE);
    wins[TRVL] = newwin(1, 69, 1, 38);
    wins[ROOM] = newwin(LINES - 2, 69, 2, 38);
    wins[INV] = newwin(LINES - 1, 38, 1, 109);
    box(wins[ROOM], 0, 0);
    box(wins[INV], 0, 0);

    WLOG(1, fire_msg);
    WLOG(1, temp_msg);
    WLOG(3, craftables[RIFLE].build_msg);
    //mvwprintw(wins[LOG], 1, 1, "The fire is %s.\n", FIRE_DESC[adr_fire]);
    //wprintw(wins[LOG], "The room is %s.", TEMP_DESC[adr_temp]);
    mvwprintw(wins[TRVL], 0, 1, "A %s Room", state.fire > FLICKERING ? "Firelit" : "Dark");
    wprintw(wins[TRVL], " | A Raucous Village");
    wprintw(wins[TRVL], " | A Dusty Path");
    wprintw(wins[TRVL], " | An Old Starship");
    wrefresh(wins[LOG]);
    wrefresh(wins[TRVL]);
    wrefresh(wins[ROOM]);
    wrefresh(wins[INV]);

    for ( ; getch() != 'q'; );
    for ( int i = 0; i <= SHIP; i ++ ) {
        delwin(wins[i]);
    }

    endwin();
    return 0;
}

// vim: set ts=4 sw=4 et:
