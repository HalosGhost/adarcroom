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

#define ADR_FIREP "The fire is "

const char * FIRE_DESC [] = {
    [DEAD]       = ADR_FIREP "dead.",
    [SMOLDERING] = ADR_FIREP "smoldering.",
    [FLICKERING] = ADR_FIREP "flickering.",
    [BURNING]    = ADR_FIREP "burning.",
    [ROARING]    = ADR_FIREP "roaring."
};

#define ADR_TEMPP "The room is "

const char * TEMP_DESC [] = {
    [FREEZING] = ADR_TEMPP "freezing.",
    [COLD]     = ADR_TEMPP "cold.",
    [MILD]     = ADR_TEMPP "mild.",
    [WARM]     = ADR_TEMPP "warm.",
    [HOT]      = ADR_TEMPP "hot."
};

enum FIRE_STATE
adr_stoke_fire (uint32_t r [], enum FIRE_STATE f) {

    if ( r[WOOD] < 5 || f == ROARING ) {
        return f;
    }

    r[WOOD] -= 5;
    return f + 1;
}

void
adr_gather_wood (uint32_t r [], uint16_t c []) {

    r[WOOD] += (c[CART] > 0 ? 50 : 10);
}

void
adr_check_traps (uint32_t r [], uint16_t c []) {

    uint16_t drops = c[TRAP] + (r[BAIT] < c[TRAP] ?
                               (uint16_t )r[BAIT] :
                               c[TRAP]);

    for ( uint16_t i = 0; i < drops; i ++ ) {
        //int r_val = rand();
        // do some fancy random stuff to choose what's dropped
        // log what's dropped
    }
}
// vim: set ts=4 sw=4 et:
