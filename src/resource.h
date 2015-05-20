#ifndef ADR_RESOURCE_H
#define ADR_RESOURCE_H

#include <stdint.h>

// Forward Declarations //
enum adr_r_type {
    FUR, SCALES, TEETH, WOOD, MEAT, BAIT, CLOTH, LEATHER, IRON, COAL, STEEL,
    SULPHUR, MEDECINE, COMPASS, CURED_MEAT, BULLETS, ENERGY_CELLS, BOLAS,
    CHARM, GRENADES, BAYONET, ALIEN_ALLOY
};

extern const uint16_t adr_r_cost [][3];

extern const char * adr_r_name [];

extern void
adr_trade (enum adr_r_type, uint32_t []);

#endif // ADR_RESOURCE_H
// vim: set ts=4 sw=4 et:
