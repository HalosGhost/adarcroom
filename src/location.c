// Libraries //
#include <stdlib.h>
#include "resource.h"
#include "craftable.h"
#include "location.h"

// Forward Declarations //
const char * TRAP_DROPS [] = {
    [FUR]    = "scraps of fur",
    [MEAT]   = "bits of meat",
    [SCALES] = "strange scales",
    [TEETH]  = "scattered teeth",
    [CLOTH]  = "tattered cloth",
    [CHARM]  = "a crudely made charm"
};

#define _FIREP "The fire is "

const char * FIRE_DESC [] = {
    [DEAD]       = _FIREP "dead.",
    [SMOLDERING] = _FIREP "smoldering.",
    [FLICKERING] = _FIREP "flickering.",
    [BURNING]    = _FIREP "burning.",
    [ROARING]    = _FIREP "roaring."
};

#define _TEMPP "The room is "

const char * TEMP_DESC [] = {
    [FREEZING] = _TEMPP "freezing.",
    [COLD]     = _TEMPP "cold.",
    [MILD]     = _TEMPP "mild.",
    [WARM]     = _TEMPP "warm.",
    [HOT]      = _TEMPP "hot."
};

enum FIRE_STATE
adr_stoke_fire (unsigned r [], enum FIRE_STATE f) {

    if ( r[WOOD] < 5 || f == ROARING ) {
        return f;
    }

    r[WOOD] -= 5;
    return f + 1;
}

void
gather_wood (unsigned r [], unsigned short c []) {

    r[WOOD] += (c[CART] > 0 ? 50 : 10);
}

void
check_traps (unsigned r [], unsigned short c []) {

    unsigned short drops = c[TRAP] + (r[BAIT] < c[TRAP] ?
                                      (unsigned short )r[BAIT] :
                                      c[TRAP]);

    for ( unsigned short i = 0; i < drops; i ++ ) {
        //int r_val = rand();
        // do some fancy random stuff to choose what's dropped
        // log what's dropped
    }
}
// vim: set ts=4 sw=4 et:
