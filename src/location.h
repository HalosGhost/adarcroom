#ifndef ADR_LOCATION_H
#define ADR_LOCATION_H

// Forward Declarations //
enum FIRE_STATE {
    DEAD, SMOLDERING, FLICKERING, BURNING, ROARING
};

enum ROOM_TEMP {
    FREEZING, COLD, MILD, WARM, HOT
};

extern const char * TRAP_DROPS [];
extern const char * FIRE_DESC [];
extern const char * TEMP_DESC [];

extern enum FIRE_STATE
adr_stoke_fire (unsigned [], enum FIRE_STATE);

extern void
adr_gather_wood (unsigned [], unsigned short []);

extern void
adr_check_traps (unsigned [], unsigned short []);

#endif // ADR_LOCATION_H
// vim: set ts=4 sw=4 et:
