#ifndef __ADR_MAIN_H__
#define __ADR_MAIN_H__

// Libraries //
#include "craftable.h"
#include "resource.h"
#include "villager.h"
#include "location.h"

// Forward Declarations //
struct adr_state {
    enum LOCATION loc;
    enum FIRE_STATE fire;
    enum ROOM_TEMP temp;
    unsigned int rs [ALIEN_ALLOY + 1];
    unsigned short cs [RIFLE + 1];
    unsigned short vs [MUNITIONIST + 1];
};

#endif // __ADR_MAIN_H__
// vim: set ts=4 sw=4 et:
