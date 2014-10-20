#ifndef __ADR_VILLAGER_H__
#define __ADR_VILLAGER_H__

// Libraries //
#include "craftable.h"

// Forward Declarations //
enum adr_v_type {
    GATHERER, HUNTER, TRAPPER, TANNER, CHARCUTIER, I_MINER, C_MINER, S_MINER,
    BLACKSMITH, MUNITIONIST
};

extern short adr_v_income [][16];

extern short
adr_work (enum adr_v_type t, unsigned short n, unsigned int r []);

#endif // __ADR_VILLAGER_H__
// vim: set ts=4 sw=4 et:
