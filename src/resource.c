// Libraries //
#include "resource.h"

// Forward Declarations //
const unsigned short adr_r_cost [][3] = {
    [SCALES]       = { [FUR] = 150                                 },
    [TEETH]        = { [FUR] = 300                                 },
    [COAL]         = { [FUR] = 200,                  [TEETH] = 50  },
    [STEEL]        = { [FUR] = 300,  [SCALES] = 50,  [TEETH] = 50  },
    [COMPASS]      = { [FUR] = 400,  [SCALES] = 750, [TEETH] = 300 },
    [ALIEN_ALLOY]  = { [FUR] = 1500, [SCALES] = 750, [TEETH] = 300 },
    [IRON]         = { [FUR] = 150,  [SCALES] = 50                 },
    [BULLETS]      = {               [SCALES] = 10                 },
    [ENERGY_CELLS] = {               [SCALES] = 10,  [TEETH] = 10  },
    [MEDECINE]     = {               [SCALES] = 50,  [TEETH] = 30  },
    [GRENADES]     = {               [SCALES] = 100, [TEETH] = 50  },
    [BAYONET]      = {               [SCALES] = 500, [TEETH] = 250 },
    [BOLAS]        = {                               [TEETH] = 10  }
};

const char * adr_r_name [] = {
    [FUR]   = "fur",   [TEETH]   = "teeth",   [BAYONET]      = "bayonet",
    [WOOD]  = "wood",  [CLOTH]   = "cloth",   [MEDECINE]     = "medecine",
    [MEAT]  = "meat",  [STEEL]   = "steel",   [GRENADES]     = "grenades",
    [BAIT]  = "bait",  [SCALES]  = "scales",  [CURED_MEAT]   = "cured meat",
    [IRON]  = "iron",  [COMPASS] = "compass", [ENERGY_CELLS] = "energy cells",
    [COAL]  = "coal",  [LEATHER] = "leather", [ALIEN_ALLOY]  = "alien alloy",
    [BOLAS] = "bolas", [SULPHUR] = "sulphur",
    [CHARM] = "charm", [BULLETS] = "bullets"
};

void
adr_trade (enum adr_r_type t, unsigned r []) {

    if ( adr_r_cost[t][FUR] > r[FUR] ) {
        return; // Not enough fur
    } else if ( adr_r_cost[t][SCALES] > r[SCALES] ) {
        return; // Not enough scales
    } else if ( adr_r_cost[t][TEETH] > r[TEETH] ) {
        return; // Not enough teeth
    }

    r[FUR]    -= adr_r_cost[t][FUR];
    r[SCALES] -= adr_r_cost[t][SCALES];
    r[TEETH]  -= adr_r_cost[t][TEETH];
    r[t]      += 1;
}
// vim: set ts=4 sw=4 et:
