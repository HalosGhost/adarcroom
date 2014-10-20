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

const char * FIRE_DESC [] = {
    [DEAD]       = "dead",
    [SMOLDERING] = "smoldering",
    [FLICKERING] = "flickering",
    [BURNING]    = "burning",
    [ROARING]    = "roaring"
};

const char * TEMP_DESC [] = {
    [FREEZING] = "freezing",
    [COLD]     = "cold",
    [MILD]     = "mild",
    [WARM]     = "warm",
    [HOT]      = "hot"
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

    unsigned short drops = c[TRAP] + (r[BAIT] < c[TRAP] ? 
                                      (unsigned short )r[BAIT] : 
                                      c[TRAP]);

    for ( int i = 0; i < drops; i ++ ) {
        //int r_val = rand();
        // do some fancy random stuff to choose what's dropped
        // log what's dropped
    }
}
// vim: set ts=4 sw=4 et:
