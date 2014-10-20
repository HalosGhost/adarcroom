#ifndef __ADR_CRAFTABLE_H__
#define __ADR_CRAFTABLE_H__

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
    unsigned int max;
    char * avail_msg;
    char * build_msg;
    char * max_msg;
};

extern struct adr_c craftables [];

extern short
adr_craft (enum adr_c_type t, unsigned short c [], unsigned int r []);

#endif // __ADR_CRAFTABLE_H__
// vim: set ts=4 sw=4 et:
