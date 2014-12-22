
// Libraries //
#include <ncurses.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

#define WLOG(x, y) wscrl(wins[LOG], -(x)); mvwprintw(wins[LOG], 0, 1, (y));

enum WIN_TYPE {
    LOG, TRVL, INV, ROOM, OTSD, PATH, WRLD, SHIP
};

void
update_travel_bar (WINDOW *, enum WIN_TYPE, struct adr_state *);

// Main Function //
signed
main (void) { // Eventually offer argument parsing?

    struct adr_state state = {
        .fire = ROARING,
        .temp = FREEZING,
        .rs = { [WOOD] = 15, [COMPASS] = 1 },
        .bldr = AWAKE
    };

    enum WIN_TYPE cur_loc = ROOM;

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

    update_travel_bar(wins[TRVL], cur_loc, &state);

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

void
update_travel_bar (WINDOW * w, enum WIN_TYPE l, struct adr_state * s) {

    if ( l == ROOM ) { wattron(w, A_REVERSE); }
    mvwprintw(w, 0, 1, "A %s Room", s->fire > FLICKERING ? "Firelit" : "Dark");
    wattroff(w, A_REVERSE);

    if ( s->bldr >= AWAKE ) {
        char * noise = s->v_pop >= 64 ? "Raucous" :
                       s->v_pop >= 32 ? "Large"   :
                       s->v_pop >= 16 ? "Modest"  :
                       s->v_pop >=  1 ? "Tiny"    : "Silent";

        char * title = s->cs[HUT] >  1 ? "Village" :
                       s->cs[HUT] == 1 ? "Hut"     : "Forest";

        wprintw(w, " | ");
        if ( l == OTSD ) { wattron(w, A_REVERSE); }
        wprintw(w, "A %s %s", noise, title);
        wattroff(w, A_REVERSE);
    }

    if ( s->rs[COMPASS] ) {
        wprintw(w, " | ");
        if ( l == PATH ) { wattron(w, A_REVERSE); }
        wprintw(w, "A Dusty Path");
        wattroff(w, A_REVERSE);
    }

    if ( /* Found the starship */ 0 ) {
        wprintw(w, " | ");
        if ( l == SHIP ) { wattron(w, A_REVERSE); }
        wprintw(w, "An Old Starship");
        wattroff(w, A_REVERSE);
    }
}

// vim: set ts=4 sw=4 et:
