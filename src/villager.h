#ifndef ADR_VILLAGER_H
#define ADR_VILLAGER_H

// Libraries //
#include <stdint.h>
#include "craftable.h"

// Forward Declarations //
enum adr_v_type {
    GATHERER, HUNTER, TRAPPER, TANNER, CHARCUTIER, I_MINER, C_MINER, S_MINER,
    BLACKSMITH, MUNITIONIST
};

extern int16_t adr_v_income [][16];

extern int16_t
adr_work (enum adr_v_type, uint16_t, uint32_t []);

#endif // ADR_VILLAGER_H
// vim: set ts=4 sw=4 et:
