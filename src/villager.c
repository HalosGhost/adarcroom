// Libraries //
#include "craftable.h"
#include "villager.h"

// Forward Declarations //
int16_t adr_v_income [][16] = {
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

int16_t
adr_work (enum adr_v_type t, uint16_t n, uint32_t r []) {

    for ( int32_t i = 0; i < 15; i ++ ) {
        int16_t ci = adr_v_income[t][i];
        uint16_t aci = ci > 0 ? (uint16_t )ci : (uint16_t )(ci * -1);

        if ( ci < 0 && r[i] < aci ) {
            return 1; // Not enough resources
        }
    } for ( int32_t i = 0; i < 11; i ++ ) {
        int16_t ci = adr_v_income[t][i];
        uint16_t aci = ci > 0 ? (uint16_t )ci : (uint16_t )(-ci);
		r[i] = ci > 0 ? r[i] + n * aci : r[i] - n * aci;
    } return 0;
}
// vim: set ts=4 sw=4 et:
