
// Libraries //
#include <ncurses.h>
#include <getopt.h>
#include <stdio.h>
#include "main.h"

#define WLOG(x, y) wscrl(wins[LOG], -(x)); mvwprintw(wins[LOG], 0, 1, (y));

// Main Function //
signed
main (void) { // Eventually offer argument parsing?

    struct adr_state state = {
        .fire = ROARING,
        .temp = FREEZING,
        .rs = { [WOOD] = 15 },
    };

    enum WIN_TYPE {
        LOG, TRVL, INV, ROOM, OTSD, PATH, WRLD, SHIP
    } cur_loc = ROOM;

    WINDOW * wins [SHIP + 1];

    initscr(); noecho(); cbreak(); curs_set(0);
    refresh();

    signed cc = COLS / 2, cr = LINES / 2;

    if ( COLS < 149 ) {
        printw("The classic interface requires a console at least 149 columns wide");
        getch(); endwin(); exit(1);
    }

    wins[LOG] = newwin(LINES - 1, 35, 1, cc - 71);
    scrollok(wins[LOG], TRUE);
    wins[TRVL] = newwin(1, 69, 1, cc - 34);
    wins[ROOM] = newwin(LINES - 2, 69, 2, cc - 34);
    mvwprintw(wins[ROOM], 1, 1, "cc = %d, cr = %d", cc, cr);
    wins[INV] = newwin(LINES - 1, 38, 1, cc + 37);
    box(wins[ROOM], 0, 0);
    box(wins[INV], 0, 0);

    WLOG(1, FIRE_DESC[state.fire]);
    WLOG(1, TEMP_DESC[state.temp]);
    WLOG(craftables[RIFLE].build_ln, craftables[RIFLE].build_msg);
    mvwprintw(wins[TRVL], 0, 1, "A %s Room", state.fire > FLICKERING ? "Firelit" : "Dark");
    wprintw(wins[TRVL], " | A Raucous Village");
    wprintw(wins[TRVL], " | A Dusty Path");
    wprintw(wins[TRVL], " | An Old Starship");

    // Refresh Windows
    for ( enum WIN_TYPE i = 0; i <= INV; i ++ ) {
        wrefresh(wins[i]);
    } wrefresh(wins[cur_loc]); // only refresh currently selected main window

    for ( ; getch() != 'q'; );
    for ( enum WIN_TYPE i = 0; i <= SHIP; i ++ ) {
        delwin(wins[i]);
    }

    endwin();
    return 0;
}

// vim: set ts=4 sw=4 et:
