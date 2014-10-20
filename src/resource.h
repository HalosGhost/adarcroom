#ifndef __ADR_RESOURCE_H__
#define __ADR_RESOURCE_H__

// Forward Declarations //
enum adr_r_type {
    FUR, SCALES, TEETH, WOOD, MEAT, BAIT, CLOTH, LEATHER, IRON, COAL, STEEL,
    SULPHUR, MEDECINE, COMPASS, CURED_MEAT, BULLETS, ENERGY_CELLS, BOLAS, 
    CHARM, GRENADES, BAYONET, ALIEN_ALLOY
};

extern const unsigned short adr_r_cost [][3];

extern void
adr_trade (enum adr_r_type t, unsigned int r []);

#endif // __ADR_RESOURCE_H__
// vim: set ts=4 sw=4 et:
