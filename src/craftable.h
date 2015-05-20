#ifndef ADR_CRAFTABLE_H
#define ADR_CRAFTABLE_H

// Libraries //
#include <stdint.h>
#include "resource.h"

// Forward Declarations //
enum adr_c_type {
    /* Resource Gathering */
    TRAP, CART,
    HUT, LODGE, TRADE_POST, TANNERY, SMOKEHOUSE, WORKSHOP, STEELWORKS, ARSENAL,

    /* Expedition Items */
    TORCH,
    WATERSKIN, CASK, WATER_TANK,
    RUCKSACK, WAGON, CONVOY,
    L_ARMOR, I_ARMOR, S_ARMOR,
    BONE_SPEAR, I_SWORD, S_SWORD, RIFLE, LASER_RIFLE
};

enum BUILDER_STATE {
    NONE, PRESENT, AWAKE, CAPABLE, ADV
};

extern uint16_t adr_c_cost [][12];

struct adr_c {
    char * name;
    char * avail_msg;
    char * build_msg;
    char * max_msg;
    uint32_t max;
    uint32_t avail_ln: 11;
    uint32_t build_ln: 11;
    uint32_t max_ln:   10;
};

extern struct adr_c craftables [];

extern int16_t
adr_craft (enum adr_c_type, uint16_t [], uint32_t []);

#endif // ADR_CRAFTABLE_H
// vim: set ts=4 sw=4 et:
