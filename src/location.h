#ifndef ADR_LOCATION_H
#define ADR_LOCATION_H

#include <stdint.h>

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
adr_stoke_fire (uint32_t [], enum FIRE_STATE);

extern void
adr_gather_wood (uint32_t [], uint16_t []);

extern void
adr_check_traps (uint32_t [], uint16_t []);

#endif // ADR_LOCATION_H
// vim: set ts=4 sw=4 et:
