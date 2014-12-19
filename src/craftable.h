#ifndef ADR_CRAFTABLE_H
#define ADR_CRAFTABLE_H

// Libraries //
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

extern unsigned short adr_c_cost [][12];

struct adr_c {
    char * name;
    char * avail_msg;
    char * build_msg;
    char * max_msg;
    unsigned int max;
};

extern struct adr_c craftables [];

extern short
adr_craft (enum adr_c_type, unsigned short [], unsigned int []);

#endif // ADR_CRAFTABLE_H
// vim: set ts=4 sw=4 et:
