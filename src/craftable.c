// Libraries //
#include "resource.h"
#include "craftable.h"

// Forward Declarations //
uint16_t adr_c_cost [][12] = {
    [CART]       = { [WOOD] = 30                                      },
    [LODGE]      = { [WOOD] = 200,    [FUR] = 10,      [MEAT] = 5     },
    [TRADE_POST] = { [WOOD] = 400,    [FUR] = 100                     },
    [TANNERY]    = { [WOOD] = 500,    [FUR] = 50                      },
    [SMOKEHOUSE] = { [WOOD] = 600,    [MEAT] = 50                     },
    [WORKSHOP]   = { [WOOD] = 800,    [LEATHER] = 100, [SCALES] = 10  },
    [STEELWORKS] = { [WOOD] = 1500,   [IRON] = 100,    [COAL] = 100   },
    [ARSENAL]    = { [WOOD] = 3000,   [STEEL] = 100,   [SULPHUR] = 50 },
    [TORCH]      = { [WOOD] = 1,      [CLOTH] = 1                     },
    [WATERSKIN]  = { [LEATHER] = 50                                   },
    [CASK]       = { [LEATHER] = 100, [IRON] = 20                     },
    [WATER_TANK] = { [IRON] = 100,    [STEEL] = 50                    },
    [RUCKSACK]   = { [LEATHER] = 200                                  },
    [WAGON]      = { [WOOD] = 500,    [IRON] = 100                    },
    [CONVOY]     = { [WOOD] = 1000,   [IRON] = 200,    [STEEL] = 100  },
    [L_ARMOR]    = { [LEATHER] = 200, [SCALES] = 20                   },
    [I_ARMOR]    = { [LEATHER] = 200, [IRON] = 100                    },
    [S_ARMOR]    = { [LEATHER] = 200, [STEEL] = 100                   },
    [BONE_SPEAR] = { [WOOD] = 100,    [TEETH] = 5                     },
    [I_SWORD]    = { [WOOD] = 200,    [LEATHER] = 50,  [IRON] = 20    },
    [S_SWORD]    = { [WOOD] = 500,    [LEATHER] = 100, [STEEL] = 20   },
    [RIFLE]      = { [WOOD] = 200,    [STEEL] = 50,    [SULPHUR] = 50 }
};

struct adr_c craftables [] = {
    [TRAP] = {
        .name = "trap", .max = 10,
        .avail_ln  = 3,
        .avail_msg = "The builder says she can make     "
                     "traps to catch any creatures that "
                     "might still be alive out there.",
        .build_ln  = 1,
        .build_msg = "More traps to kill more creatures.",
        .max_ln    = 1,
        .max_msg   = "More traps won't help now."
    },

    [CART] = {
        .name = "cart", .max = 1,
        .avail_ln  = 2,
        .avail_msg = "The builder says she can make a   "
                     "cart for carrying wood.",
        .build_ln  = 2,
        .build_msg = "The rickety cart will carry more  "
                     "wood from the forest."
    },

    [HUT] = {
        .name = "hut", .max = 20,
        .avail_ln  = 3,
        .avail_msg = "The builder says there are more   "
                     "wanderers and that they'll work   "
                     "too.",
        .build_ln  = 3,
        .build_msg = "The builder puts up a hut out in   "
                     "the forest, and says word will     "
                     "get around.",
        .max_ln    = 1,
        .max_msg   = "There's no more room for huts."
    },

    [LODGE] = {
        .name = "lodge", .max = 1,
        .avail_ln  = 2,
        .avail_msg = "Villagers could help hunt, given   "
                     "the means.",
        .build_ln  = 2,
        .build_msg = "The hunting lodge stands out in    "
                     "the forest, a ways out of town."
    },

    [TRADE_POST] = {
        .name = "trading post", .max = 1,
        .avail_ln  = 2,
        .avail_msg = "A trading post would make commerce "
                     "easier",
        .build_ln  = 3,
        .build_msg = "Now that the nomads have a place   "
                     "to shop, they might stick around   "
                     "for while."
    },

    [TANNERY] = {
        .name = "tannery", .max = 1,
        .avail_ln  = 3,
        .avail_msg = "The builder says leather could be  "
                     "useful and that the villagers      "
                     "could make it.",
        .build_ln  = 2,
        .build_msg = "The tannery is finished quickly on "
                     "the edge of the village."
    },

    [SMOKEHOUSE] = {
        .name = "smokehouse", .max = 1,
        .avail_ln  = 3,
        .avail_msg = "The builder says she can fix       "
                     "something up to help keep the meat "
                     "from spoiling.",
        .build_ln  = 2,
        .build_msg = "The builder finishes the           "
                     "smokehouse and looks hungry."
    },

    [WORKSHOP] = {
        .name = "workshop", .max = 1,
        .avail_ln  = 2,
        .avail_msg = "The builder says she could make    "
                     "finer things if she had the tools.",
        .build_ln  = 2,
        .build_msg = "The builder is excited to get to   "
                     "work now that the workshop's done."
    },

    [STEELWORKS] = {
        .name = "steelworks", .max = 1,
        .avail_ln  = 2,
        .avail_msg = "The builder says the villagers     "
                     "could make steel, given the means.",
        .build_ln  = 2,
        .build_msg = "A haze falls over the village as   "
                     "the steelworks fires up."
    },

    [ARSENAL] = {
        .name = "arsenal", .max = 1,
        .avail_ln  = 3,
        .avail_msg = "The builder says it might be       "
                     "useful to have a steady supply of  "
                     "bullets.",
        .build_ln  = 2,
        .build_msg = "The proud new arsenal stands ready "
                     "to bring forth weapons of war."
    },

    [TORCH] = {
        .name = "torch", .max = 0,
        .build_ln  = 1,
        .build_msg = "A torch to keep the dark away."
    },

    [WATERSKIN] = {
        .name = "waterskin", .max = 1,
        .build_ln  = 2,
        .build_msg = "This waterskin'll hold a bit of    "
                     "water at least."
    },

    [CASK] = {
        .name = "cask", .max = 1,
        .build_ln  = 2,
        .build_msg = "the cask holds enough water for    "
                     "longer expeditions"
    },

    [WATER_TANK] = {
        .name = "water tank", .max = 1,
        .build_ln  = 1,
        .build_msg = "Never go thirsty again."
    },

    [RUCKSACK] = {
        .name = "rucksack", .max = 1,
        .build_ln  = 2,
        .build_msg = "Carrying more means longer         "
                     "expeditions."
    },

    [WAGON] = {
        .name = "wagon", .max = 1,
        .build_ln  = 2,
        .build_msg = "The wagon can carry a lot of       "
                     "supplies."
    },

    [CONVOY] = {
        .name = "convoy", .max = 1,
        .build_ln  = 2,
        .build_msg = "The convoy can haul mostly         "
                     "everything."
    },

    [L_ARMOR] = {
        .name = "leather armor", .max = 1,
        .build_ln  = 2,
        .build_msg = "Leather's not strong; better than  "
                     "rags though."
    },

    [I_ARMOR] = {
        .name = "iron armor", .max = 1,
        .build_ln  = 1,
        .build_msg = "Protect yourself a little better."
    },

    [S_ARMOR] = {
        .name = "steel armor", .max = 1,
        .build_ln  = 1,
        .build_msg = "The best armor you can make."
    },

    [BONE_SPEAR] = {
        .name = "bone spear", .max = 0,
        .build_ln  = 2,
        .build_msg = "Not an elegant weapon, but good    "
                     "for stabbing."
    },

    [I_SWORD] = {
        .name = "iron sword", .max = 0,
        .build_ln  = 2,
        .build_msg = "A sharp sword; good for            "
                     "protection."
    },

    [S_SWORD] = {
        .name = "steel sword", .max = 0,
        .build_ln  = 2,
        .build_msg = "The steel is strong and the blade, "
                     "true."
    },

    [RIFLE] = {
        .name = "rifle", .max = 0,
        .build_ln  = 2,
        .build_msg = "Black powder and bullets, like old "
                     "times."
    }
};

int16_t
adr_craft (enum adr_c_type t, uint16_t c [], uint32_t r []) {

    if ( craftables[t].max != 0 && c[t] == craftables[t].max ) {
        return 1; // Maximum amount owned
    }

    if ( t == TRAP || t == HUT ) {
        uint32_t price = (t == TRAP ? 10 + 10 * c[t] : 100 + 50 * c[t]);

        if ( r[WOOD] < price ) {
            return 2; // Not enough resources
        }

        r[WOOD] -= price;
        c[t] += 1;
        return 0;
    }

    for ( int32_t i = 0; i < 12; i ++ ) {
        if ( r[i] < adr_c_cost[t][i] ) {
            return 2; // Not enough resources
        }
    } for ( int32_t i = 0; i < 12; i ++ ) {
        r[i] -= adr_c_cost[t][i];
    } c[t] += 1;

    return 0;
}
// vim: set ts=4 sw=4 et:
