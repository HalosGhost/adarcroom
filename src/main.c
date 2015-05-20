
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

void
update_main_win (WINDOW *, WINDOW * [], enum WIN_TYPE, struct adr_state *);

void
update_inventory (WINDOW *, struct adr_state *);

// Main Function //
signed
main (void) { // Eventually offer argument parsing?

    struct adr_state state = {
        .fire = ROARING,
        .temp = FREEZING,
        .rs = { [WOOD] = 15, [COMPASS] = 1 },
        .cs = { [HUT]  = 2 },
        .ds = { [STARSHIP] = true },
        .bldr = CAPABLE
    };

    enum WIN_TYPE cur_loc = ROOM;

    WINDOW * wins [SHIP + 1];
    WINDOW * btns [LASER_RIFLE + 1];

    initscr(); noecho(); cbreak(); curs_set(0); keypad(stdscr, true);
    refresh();

    signed cc = COLS / 2 - 2, cr = LINES / 2;

    if ( COLS < 149 ) { // Handle SIGWINCH instead of erroring out
        printw("The classic interface requires at least 149 columns");
        getch(); endwin(); exit(1);
    }

    wins[LOG] = newwin(LINES - 1, 35, 1, cc - 71);
    scrollok(wins[LOG], TRUE);
    wins[TRVL] = newwin(1, 69, 1, cc - 34);
    for ( enum WIN_TYPE i = ROOM; i <= SHIP; i ++ ) {
        wins[i] = newwin(LINES - 2, 69, 2, cc - 34);
        box(wins[i], 0, 0);
    }

    wins[INV] = newwin(LINES - 1, 38, 1, cc + 37);
    box(wins[INV], 0, 0);

    WLOG(1, FIRE_DESC[state.fire]);
    WLOG(1, TEMP_DESC[state.temp]);
    WLOG(craftables[RIFLE].build_ln, craftables[RIFLE].build_msg);

    mvwprintw(wins[ROOM], 1, 1, "cc = %d, cr = %d", cc, cr);

    mousemask(BUTTON1_CLICKED, NULL);
    MEVENT e;

    for ( signed c = 0; c != 'q'; c = wgetch(stdscr) ) {
        switch ( c ) {
            case KEY_MOUSE:
                if ( getmouse(&e) == OK ) {
                    if ( wenclose(wins[ROOM], e.y, e.x) ) {
                        mvwprintw(wins[ROOM], 2, 1, "Wewt, mouse!");
                        wrefresh(wins[ROOM]);
                    } else if ( wenclose(wins[TRVL], e.y, e.x) ) {
                        signed x = e.x - (cc - 34);
                        cur_loc = x < 16                                  ? ROOM :
                                  state.bldr >= AWAKE && x > 16 && x < 36 ? OTSD :
                                  state.rs[COMPASS]   && x > 36 && x < 51 ? PATH :
                                  state.ds[STARSHIP]  && x > 51           ? SHIP : cur_loc;
                        update_travel_bar(wins[TRVL], cur_loc, &state);
                        wrefresh(wins[cur_loc]);
                    }
                } break;

            default:
                update_inventory(wins[INV], &state);
                update_travel_bar(wins[TRVL], cur_loc, &state);

                for ( enum WIN_TYPE i = 0; i <= INV; i ++ ) {
                    wrefresh(wins[i]);
                } wrefresh(wins[cur_loc]); break;
        }
    }

    for ( enum WIN_TYPE i = 0; i <= SHIP; i ++ ) {
        delwin(wins[i]);
    } endwin(); return 0;
}

void
update_travel_bar (WINDOW * w, enum WIN_TYPE l, struct adr_state * s) {

    if ( l == ROOM ) { wattron(w, A_REVERSE); }
    mvwprintw(w, 0, 1, "A %s Room", s->fire > FLICKERING ? "Firelit" : "Dark");
    wattroff(w, A_REVERSE);

    if ( s->bldr >= AWAKE ) {
        char * noise = //s->v_pop >= 128 ? "Roaring" :
                       s->v_pop >=  64 ? "Raucous" :
                       s->v_pop >=  32 ? "Busy"    :
                       s->v_pop >=  16 ? "Sleepy"  :
                       s->v_pop >=   1 ? "Quiet"   : "Silent";

        char * title = //s->cs[HUT] >= 32 ? "Town"    :
                       s->cs[HUT] >=  2 ? "Village" :
                       s->cs[HUT] ==  1 ? "Hut"     : "Forest";

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

    if ( s->ds[STARSHIP] ) {
        wprintw(w, " | ");
        if ( l == SHIP ) { wattron(w, A_REVERSE); }
        wprintw(w, "An Old Starship");
        wattroff(w, A_REVERSE);
    } wrefresh(w);
}

void
update_main_win (WINDOW * w, WINDOW * bs [], enum WIN_TYPE l,
                 struct adr_state * s) {

    // create/update the buttons available for the current location
    switch ( l ) {
        case ROOM:
            for ( enum adr_c_type i = TRAP; i <= LASER_RIFLE; i ++ ) {
                if ( s->cs[i] > 0 || s->cs_seen[i] ) {
                    // bs[i] = derwin(…
                }
            } break;
    }
}

void
update_inventory (WINDOW * w, struct adr_state * s) {

    uint8_t lns = 1;
    mvwprintw(w, 1, 2, "Stores:");
    for ( enum adr_r_type i = FUR; i <= ALIEN_ALLOY; i ++ ) {
        if ( s->rs[i] > 0 || s->rs_seen[i] ) {
            s->rs_seen[i] = true;
            mvwprintw(w, ++ lns, 2, "%u %s", s->rs[i], adr_r_name[i]);
        }
    }

    if ( s->bldr < CAPABLE ) { return; } // Crafting is unavailable

    lns += 2; mvwprintw(w, lns, 2, "Village:");
    for ( enum adr_c_type i = TRAP; i <= LASER_RIFLE; i ++ ) {
        if ( s->cs[i] > 0 || s->cs_seen[i] ) {
            s->cs_seen[i] = true;
            mvwprintw(w, ++ lns, 2, "%u %s%c", s->cs[i], craftables[i].name,
                                               s->cs[i] > 1 ? 's' : '\0'); // naïve pluralization
        }
    } wrefresh(w);
}

// vim: set ts=4 sw=4 et:
