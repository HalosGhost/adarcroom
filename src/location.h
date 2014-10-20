#ifndef __ADR_LOCATION_H__
#define __ADR_LOCATION_H__

// Forward Declarations //
enum LOCATION {
    ROOM, OUTSIDE, PATH, WORLD, STARSHIP, SPACE
};

enum FIRE_STATE {
    DEAD, SMOLDERING, FLICKERING, BURNING, ROARING
};

enum ROOM_TEMP {
    FREEZING, COLD, MILD, WARM, HOT
};

extern const char * TRAP_DROPS [];

extern enum FIRE_STATE
adr_stoke_fire (unsigned int r [], enum FIRE_STATE f);

extern void
gather_wood (unsigned int r [], unsigned short c []);

extern void
check_traps (unsigned int r [], unsigned short c []);

#endif // __ADR_LOCATION_H__
// vim: set ts=4 sw=4 et:
