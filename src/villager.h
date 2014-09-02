#ifndef __ADR_VILLAGER_H__
#define __ADR_VILLAGER_H__

// Libraries //
#include "craftable.h"

// Forward Declarations //
enum adr_v_type {
    GATHERER, HUNTER, TRAPPER, TANNER, CHARCUTIER, I_MINER, C_MINER, S_MINER,
    BLACKSMITH, MUNITIONIST
};

short adr_v_income [][16] = {
    [GATHERER]     = { [WOOD] = 1                                          },
    [HUNTER]       = { [FUR]  = 1,        [MEAT] = 1                       },
    [TRAPPER]      = { [MEAT] = -1,       [BAIT] = 1                       },
    [TANNER]       = { [FUR]  = -5,       [LEATHER] = 1                    },
    [CHARCUTIER]   = { [MEAT] = -1,       [WOOD] = -1,    [CURED_MEAT] = 1 },
    [I_MINER]      = { [CURED_MEAT] = -1, [IRON] = 1                       },
    [C_MINER]      = { [CURED_MEAT] = -1, [COAL] = 1                       },
    [S_MINER]      = { [CURED_MEAT] = -1, [SULPHUR] = 1                    },
    [BLACKSMITH]   = { [IRON] = -1,       [COAL] = -1,    [STEEL] = 1      },
    [MUNITIONIST]  = { [STEEL] = -1,      [SULPHUR] = -1, [BULLETS] = 1    }
};

short
adr_work (enum adr_v_type t, unsigned short n, unsigned int r []) {

    for ( int i = 0; i < 15; i ++ ) {
        signed short ci = adr_v_income[t][i];
        unsigned short aci = (ci > 0 ? (unsigned short )ci : 
                                       (unsigned short )(ci * -1));

        if ( ci < 0 && r[i] < aci ) {
            return 1; // Not enough resources
        }
    } for ( int i = 0; i < 11; i ++ ) {
        r[i] += n * adr_v_income[t][i];
    } return 0;
}

#endif // __ADR_VILLAGER_H__
// vim: set ts=4 sw=4 et:
