#ifndef ADR_MAIN_H
#define ADR_MAIN_H

// Libraries //
#include <stdbool.h>
#include "craftable.h"
#include "resource.h"
#include "villager.h"
#include "location.h"

// Forward Declarations //
struct adr_state {
    enum FIRE_STATE fire;
    enum ROOM_TEMP temp;
    enum BUILDER_STATE bldr;
    unsigned rs [ALIEN_ALLOY + 1];
    unsigned short cs [RIFLE + 1];
    unsigned char vs [MUNITIONIST + 1];
    unsigned char v_pop;
};

#endif // ADR_MAIN_H
// vim: set ts=4 sw=4 et:
