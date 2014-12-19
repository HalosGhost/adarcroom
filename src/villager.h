#ifndef ADR_VILLAGER_H
#define ADR_VILLAGER_H

// Libraries //
#include "craftable.h"

// Forward Declarations //
enum adr_v_type {
    GATHERER, HUNTER, TRAPPER, TANNER, CHARCUTIER, I_MINER, C_MINER, S_MINER,
    BLACKSMITH, MUNITIONIST
};

extern signed short adr_v_income [][16];

extern signed short
adr_work (enum adr_v_type, unsigned short, unsigned []);

#endif // ADR_VILLAGER_H
// vim: set ts=4 sw=4 et:
