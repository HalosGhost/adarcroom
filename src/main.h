#ifndef __ADR_MAIN_H__
#define __ADR_MAIN_H__

// Libraries //
#include "craftable.h"
#include "resource.h"
#include "villager.h"
#include "location.h"

// Forward Declarations //
struct adr_state {
    enum LOCATION adr_loc;
    enum FIRE_STATE adr_fire;
    enum ROOM_TEMP adr_temp;
    unsigned int adr_rs [ALIEN_ALLOY + 1];
    unsigned short adr_cs [RIFLE + 1];
    unsigned short adr_vs [MUNITIONIST + 1];
};

#endif // __ADR_MAIN_H__
// vim: set ts=4 sw=4 et:
