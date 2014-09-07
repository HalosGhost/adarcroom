#ifndef __ADR_LOCATION_H__
#define __ADR_LOCATION_H__

// Libraries //
#include <ncurses.h>
#include <stdlib.h>
#include "resource.h"

// Forward Declarations //
enum LOCATION {
    ROOM, OUTSIDE, PATH, WORLD, STARSHIP, SPACE
};

enum FIRE_STATE {
    DEAD, SMOLDERING, FLICKERING, BURNING, ROARING
};

enum ROOM_TEMP {
    FREEZING, COLD, MILD, WARM, HOT
};

const char * TRAP_DROPS [] = {
    [FUR]    = "scraps of fur",
    [MEAT]   = "bits of meat",
    [SCALES] = "strange scales",
    [TEETH]  = "scattered teeth",
    [CLOTH]  = "tattered cloth",
    [CHARM]  = "a crudely made charm"
};

enum FIRE_STATE
adr_stoke_fire (unsigned int r [], enum FIRE_STATE f) {

    if ( r[WOOD] < 5 || f == ROARING ) {
        return f;
    }

    r[WOOD] -= 5;
    return f + 1;
}

void
gather_wood (unsigned int r [], unsigned short c []) {

    r[WOOD] += (c[CART] > 0 ? 50 : 10);
}

void
check_traps (unsigned int r [], unsigned short c []) {

    short drops = c[TRAP] + (r[BAIT] < c[TRAP] ? r[BAIT] : c[TRAP]);

    for ( int i = 0; i < drops; i ++ ) {
        //int r_val = rand();
        // do some fancy random stuff to choose what's dropped
        // log what's dropped
    }
}

int
adr_survey () {

	return 0;
}

#endif // __ADR_LOCATION_H__
// vim: set ts=4 sw=4 et:
