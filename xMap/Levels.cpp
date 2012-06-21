#include "xMap.h"

LVA Vectors[] = {
    //act 1
    { MAP_A1_ROGUE_ENCAMPMENT, VECTOR_NEXT, MAP_A1_BLOOD_MOOR, TARGET_LEVEL },

    { MAP_A1_BLOOD_MOOR, VECTOR_NEXT, MAP_A1_COLD_PLAINS, TARGET_LEVEL },
    { MAP_A1_BLOOD_MOOR, VECTOR_PREV, MAP_A1_ROGUE_ENCAMPMENT, TARGET_LEVEL },
    { MAP_A1_BLOOD_MOOR, VECTOR_QUEST, MAP_A1_DEN_OF_EVIL, TARGET_LEVEL },

    { MAP_A1_COLD_PLAINS, VECTOR_NEXT, MAP_A1_STONY_FIELD, TARGET_LEVEL },
    { MAP_A1_COLD_PLAINS, VECTOR_PREV, MAP_A1_BLOOD_MOOR, TARGET_LEVEL },//
    { MAP_A1_COLD_PLAINS, VECTOR_QUEST, MAP_A1_BURIAL_GROUNDS, TARGET_LEVEL },

    { MAP_A1_BURIAL_GROUNDS, VECTOR_PREV, MAP_A1_COLD_PLAINS, TARGET_LEVEL },
    { MAP_A1_BURIAL_GROUNDS, VECTOR_QUEST, 267, UNIT_MONSTER },

    { MAP_A1_STONY_FIELD, VECTOR_NEXT, MAP_A1_UNDERGROUND_PASSAGE_LEVEL_1, TARGET_LEVEL },
    { MAP_A1_STONY_FIELD, VECTOR_PREV, MAP_A1_COLD_PLAINS, TARGET_LEVEL },//
    { MAP_A1_STONY_FIELD, VECTOR_QUEST, 17, UNIT_OBJECT },

    { MAP_A1_UNDERGROUND_PASSAGE_LEVEL_1, VECTOR_NEXT, MAP_A1_DARK_WOOD, TARGET_LEVEL },
    { MAP_A1_UNDERGROUND_PASSAGE_LEVEL_1, VECTOR_PREV, MAP_A1_STONY_FIELD, TARGET_LEVEL },
    { MAP_A1_UNDERGROUND_PASSAGE_LEVEL_1, VECTOR_QUEST, MAP_A1_UNDERGROUND_PASSAGE_LEVEL_2, TARGET_LEVEL },

    { MAP_A1_UNDERGROUND_PASSAGE_LEVEL_2, VECTOR_PREV, MAP_A1_UNDERGROUND_PASSAGE_LEVEL_1, TARGET_LEVEL },

    { MAP_A1_DARK_WOOD, VECTOR_NEXT, MAP_A1_BLACK_MARSH, TARGET_LEVEL },
    { MAP_A1_DARK_WOOD, VECTOR_PREV, MAP_A1_UNDERGROUND_PASSAGE_LEVEL_1, TARGET_LEVEL },
    { MAP_A1_DARK_WOOD, VECTOR_QUEST, 30, UNIT_OBJECT },

    { MAP_A1_BLACK_MARSH, VECTOR_NEXT, MAP_A1_TAMOE_HIGHLAND, TARGET_LEVEL },
    { MAP_A1_BLACK_MARSH, VECTOR_PREV, MAP_A1_DARK_WOOD, TARGET_LEVEL },
    { MAP_A1_BLACK_MARSH, VECTOR_QUEST, MAP_A1_FORGOTTEN_TOWER, TARGET_LEVEL },

    { MAP_A1_FORGOTTEN_TOWER, VECTOR_NEXT, MAP_A1_TOWER_CELLAR_LEVEL_1, TARGET_LEVEL },
    { MAP_A1_FORGOTTEN_TOWER, VECTOR_PREV, MAP_A1_BLACK_MARSH, TARGET_LEVEL },

    { MAP_A1_TOWER_CELLAR_LEVEL_1, VECTOR_NEXT, MAP_A1_TOWER_CELLAR_LEVEL_2, TARGET_LEVEL },
    { MAP_A1_TOWER_CELLAR_LEVEL_1, VECTOR_PREV, MAP_A1_FORGOTTEN_TOWER, TARGET_LEVEL },

    { MAP_A1_TOWER_CELLAR_LEVEL_2, VECTOR_NEXT, MAP_A1_TOWER_CELLAR_LEVEL_3, TARGET_LEVEL },
    { MAP_A1_TOWER_CELLAR_LEVEL_2, VECTOR_PREV, MAP_A1_TOWER_CELLAR_LEVEL_1, TARGET_LEVEL },

    { MAP_A1_TOWER_CELLAR_LEVEL_3, VECTOR_NEXT, MAP_A1_TOWER_CELLAR_LEVEL_4, TARGET_LEVEL },
    { MAP_A1_TOWER_CELLAR_LEVEL_3, VECTOR_PREV, MAP_A1_TOWER_CELLAR_LEVEL_2, TARGET_LEVEL },

    { MAP_A1_TOWER_CELLAR_LEVEL_4, VECTOR_NEXT, MAP_A1_TOWER_CELLAR_LEVEL_5, TARGET_LEVEL },
    { MAP_A1_TOWER_CELLAR_LEVEL_4, VECTOR_PREV, MAP_A1_TOWER_CELLAR_LEVEL_3, TARGET_LEVEL },

    { MAP_A1_TOWER_CELLAR_LEVEL_5, VECTOR_PREV, MAP_A1_TOWER_CELLAR_LEVEL_4, TARGET_LEVEL },

    { MAP_A1_TAMOE_HIGHLAND, VECTOR_NEXT, MAP_A1_MONASTERY_GATE, TARGET_LEVEL },
    { MAP_A1_TAMOE_HIGHLAND, VECTOR_PREV, MAP_A1_BLACK_MARSH, TARGET_LEVEL },
    { MAP_A1_TAMOE_HIGHLAND, VECTOR_QUEST, MAP_A1_PIT_LEVEL_1, TARGET_LEVEL },

    { MAP_A1_PIT_LEVEL_1, VECTOR_NEXT, MAP_A1_PIT_LEVEL_2, TARGET_LEVEL },
    { MAP_A1_PIT_LEVEL_1, VECTOR_PREV, MAP_A1_TAMOE_HIGHLAND, TARGET_LEVEL },

    { MAP_A1_PIT_LEVEL_2, VECTOR_PREV, MAP_A1_PIT_LEVEL_1, TARGET_LEVEL },

    { MAP_A1_MONASTERY_GATE, VECTOR_NEXT, MAP_A1_OUTER_CLOISTER, TARGET_LEVEL },
    { MAP_A1_MONASTERY_GATE, VECTOR_PREV, MAP_A1_TAMOE_HIGHLAND, TARGET_LEVEL },

    { MAP_A1_OUTER_CLOISTER, VECTOR_NEXT, MAP_A1_BARRACKS, TARGET_LEVEL },
    { MAP_A1_OUTER_CLOISTER, VECTOR_PREV, MAP_A1_MONASTERY_GATE, TARGET_LEVEL },

    { MAP_A1_BARRACKS, VECTOR_NEXT, MAP_A1_JAIL_LEVEL_1, TARGET_LEVEL },
    { MAP_A1_BARRACKS, VECTOR_PREV, MAP_A1_OUTER_CLOISTER, TARGET_LEVEL },
    { MAP_A1_BARRACKS, VECTOR_QUEST, 108, UNIT_OBJECT },

    { MAP_A1_JAIL_LEVEL_1, VECTOR_NEXT, MAP_A1_JAIL_LEVEL_2, TARGET_LEVEL },
    { MAP_A1_JAIL_LEVEL_1, VECTOR_PREV, MAP_A1_BARRACKS, TARGET_LEVEL },

    { MAP_A1_JAIL_LEVEL_2, VECTOR_NEXT, MAP_A1_JAIL_LEVEL_3, TARGET_LEVEL },
    { MAP_A1_JAIL_LEVEL_2, VECTOR_PREV, MAP_A1_JAIL_LEVEL_1, TARGET_LEVEL },
    
    { MAP_A1_JAIL_LEVEL_3, VECTOR_NEXT, MAP_A1_INNER_CLOISTER, TARGET_LEVEL },
    { MAP_A1_JAIL_LEVEL_3, VECTOR_PREV, MAP_A1_JAIL_LEVEL_2, TARGET_LEVEL },

    { MAP_A1_INNER_CLOISTER, VECTOR_NEXT, MAP_A1_INNER_CLOISTER_2, TARGET_LEVEL },
    { MAP_A1_INNER_CLOISTER, VECTOR_PREV, MAP_A1_JAIL_LEVEL_3, TARGET_LEVEL },

    { MAP_A1_INNER_CLOISTER_2, VECTOR_NEXT, MAP_A1_CATACOMBS_LEVEL_1, TARGET_LEVEL },
    { MAP_A1_INNER_CLOISTER_2, VECTOR_PREV, MAP_A1_INNER_CLOISTER, TARGET_LEVEL },

    { MAP_A1_CATACOMBS_LEVEL_1, VECTOR_NEXT, MAP_A1_CATACOMBS_LEVEL_2, TARGET_LEVEL },
    { MAP_A1_CATACOMBS_LEVEL_1, VECTOR_PREV, MAP_A1_INNER_CLOISTER_2, TARGET_LEVEL },

    { MAP_A1_CATACOMBS_LEVEL_2, VECTOR_NEXT, MAP_A1_CATACOMBS_LEVEL_3, TARGET_LEVEL },
    { MAP_A1_CATACOMBS_LEVEL_2, VECTOR_PREV, MAP_A1_CATACOMBS_LEVEL_1, TARGET_LEVEL },

    { MAP_A1_CATACOMBS_LEVEL_3, VECTOR_NEXT, MAP_A1_CATACOMBS_LEVEL_4, TARGET_LEVEL },
    { MAP_A1_CATACOMBS_LEVEL_3, VECTOR_PREV, MAP_A1_CATACOMBS_LEVEL_2, TARGET_LEVEL },

    { MAP_A1_CATACOMBS_LEVEL_4, VECTOR_PREV, MAP_A1_CATACOMBS_LEVEL_3, TARGET_LEVEL },
    { MAP_A1_CATACOMBS_LEVEL_4, VECTOR_QUEST, 156, UNIT_MONSTER },
    //2 act
    { MAP_A2_LUT_GHOLEIN, VECTOR_NEXT, MAP_A2_ROCKY_WASTE, TARGET_LEVEL },
    { MAP_A2_LUT_GHOLEIN, VECTOR_QUEST, MAP_A2_HAREM_LEVEL_1, TARGET_LEVEL },

    { MAP_A2_ROCKY_WASTE, VECTOR_NEXT, MAP_A2_DRY_HILLS, TARGET_LEVEL },
    { MAP_A2_ROCKY_WASTE, VECTOR_PREV, MAP_A2_LUT_GHOLEIN, TARGET_LEVEL },
    { MAP_A2_ROCKY_WASTE, VECTOR_QUEST, MAP_A2_STONY_TOMB_LEVEL_1, TARGET_LEVEL },

    { MAP_A2_DRY_HILLS, VECTOR_NEXT, MAP_A2_FAR_OASIS, TARGET_LEVEL },
    { MAP_A2_DRY_HILLS, VECTOR_PREV, MAP_A2_ROCKY_WASTE, TARGET_LEVEL },
    { MAP_A2_DRY_HILLS, VECTOR_QUEST, MAP_A2_HALLS_OF_THE_DEAD_LEVEL_1, TARGET_LEVEL },

    { MAP_A2_FAR_OASIS, VECTOR_PREV, MAP_A2_DRY_HILLS, TARGET_LEVEL },
    { MAP_A2_FAR_OASIS, VECTOR_NEXT, MAP_A2_LOST_CITY, TARGET_LEVEL },
    { MAP_A2_FAR_OASIS, VECTOR_QUEST, 47, UNIT_TILE },

    { MAP_A2_LOST_CITY, VECTOR_PREV, MAP_A2_FAR_OASIS, TARGET_LEVEL },
    { MAP_A2_LOST_CITY, VECTOR_NEXT, MAP_A2_VALLEY_OF_SNAKES, TARGET_LEVEL },
    { MAP_A2_LOST_CITY, VECTOR_QUEST, MAP_A2_ANCIENT_TUNNELS, TARGET_LEVEL },

    { MAP_A2_ANCIENT_TUNNELS, VECTOR_PREV, MAP_A2_LOST_CITY, TARGET_LEVEL },

    { MAP_A2_VALLEY_OF_SNAKES, VECTOR_PREV, MAP_A2_LOST_CITY, TARGET_LEVEL },
    { MAP_A2_VALLEY_OF_SNAKES, VECTOR_NEXT, MAP_A2_CLAW_VIPER_TEMPLE_LEVEL_1, TARGET_LEVEL },

    { MAP_A2_CLAW_VIPER_TEMPLE_LEVEL_1, VECTOR_PREV, MAP_A2_VALLEY_OF_SNAKES, TARGET_LEVEL },
    { MAP_A2_CLAW_VIPER_TEMPLE_LEVEL_1, VECTOR_NEXT, MAP_A2_CLAW_VIPER_TEMPLE_LEVEL_2, TARGET_LEVEL },

    { MAP_A2_CLAW_VIPER_TEMPLE_LEVEL_2, VECTOR_NEXT, 149, UNIT_OBJECT },
    { MAP_A2_CLAW_VIPER_TEMPLE_LEVEL_2, VECTOR_PREV, MAP_A2_CLAW_VIPER_TEMPLE_LEVEL_1, TARGET_LEVEL },

    { MAP_A2_HAREM_LEVEL_1, VECTOR_PREV, MAP_A2_LUT_GHOLEIN, TARGET_LEVEL },
    { MAP_A2_HAREM_LEVEL_1, VECTOR_NEXT, MAP_A2_HAREM_LEVEL_2, TARGET_LEVEL },

    { MAP_A2_HAREM_LEVEL_2, VECTOR_PREV, MAP_A2_HAREM_LEVEL_1, TARGET_LEVEL },
    { MAP_A2_HAREM_LEVEL_2, VECTOR_NEXT, MAP_A2_PALACE_CELLAR_LEVEL_1, TARGET_LEVEL },

    { MAP_A2_PALACE_CELLAR_LEVEL_1, VECTOR_PREV, MAP_A2_HAREM_LEVEL_2, TARGET_LEVEL },
    { MAP_A2_PALACE_CELLAR_LEVEL_1, VECTOR_NEXT, MAP_A2_PALACE_CELLAR_LEVEL_2, TARGET_LEVEL },

    { MAP_A2_PALACE_CELLAR_LEVEL_2, VECTOR_PREV, MAP_A2_PALACE_CELLAR_LEVEL_1, TARGET_LEVEL },
    { MAP_A2_PALACE_CELLAR_LEVEL_2, VECTOR_NEXT, MAP_A2_PALACE_CELLAR_LEVEL_3, TARGET_LEVEL },

    { MAP_A2_PALACE_CELLAR_LEVEL_3, VECTOR_PREV, MAP_A2_PALACE_CELLAR_LEVEL_2, TARGET_LEVEL },
    { MAP_A2_PALACE_CELLAR_LEVEL_3, VECTOR_NEXT, 298, UNIT_OBJECT },

    { MAP_A2_ARCANE_SANCTUARY, VECTOR_PREV, 298, UNIT_OBJECT },
    { MAP_A2_ARCANE_SANCTUARY, VECTOR_NEXT, 357, UNIT_OBJECT },

    { MAP_A2_SEWERS_LEVEL_1, VECTOR_PREV, MAP_A2_LUT_GHOLEIN, TARGET_LEVEL },
    { MAP_A2_SEWERS_LEVEL_1, VECTOR_NEXT, MAP_A2_SEWERS_LEVEL_2, TARGET_LEVEL },

    { MAP_A2_SEWERS_LEVEL_2, VECTOR_PREV, MAP_A2_SEWERS_LEVEL_1, TARGET_LEVEL },
    { MAP_A2_SEWERS_LEVEL_2, VECTOR_NEXT, MAP_A2_SEWERS_LEVEL_3, TARGET_LEVEL },

    { MAP_A2_SEWERS_LEVEL_3, VECTOR_PREV, MAP_A2_SEWERS_LEVEL_2, TARGET_LEVEL },
    { MAP_A2_SEWERS_LEVEL_3, VECTOR_QUEST, 355, UNIT_OBJECT },

    { MAP_A2_HALLS_OF_THE_DEAD_LEVEL_1, VECTOR_PREV, MAP_A2_DRY_HILLS, TARGET_LEVEL },
    { MAP_A2_HALLS_OF_THE_DEAD_LEVEL_1, VECTOR_NEXT, MAP_A2_HALLS_OF_THE_DEAD_LEVEL_2, TARGET_LEVEL },

    { MAP_A2_HALLS_OF_THE_DEAD_LEVEL_2, VECTOR_PREV, MAP_A2_HALLS_OF_THE_DEAD_LEVEL_1, TARGET_LEVEL },
    { MAP_A2_HALLS_OF_THE_DEAD_LEVEL_2, VECTOR_NEXT, MAP_A2_HALLS_OF_THE_DEAD_LEVEL_3, TARGET_LEVEL },

    { MAP_A2_HALLS_OF_THE_DEAD_LEVEL_3, VECTOR_PREV, MAP_A2_HALLS_OF_THE_DEAD_LEVEL_2, TARGET_LEVEL },
    { MAP_A2_HALLS_OF_THE_DEAD_LEVEL_3, VECTOR_QUEST, 354, UNIT_OBJECT },

    { MAP_A2_MAGGOT_LAIR_LEVEL_1, VECTOR_PREV, MAP_A2_FAR_OASIS, TARGET_LEVEL },
    { MAP_A2_MAGGOT_LAIR_LEVEL_1, VECTOR_NEXT, MAP_A2_MAGGOT_LAIR_LEVEL_2, TARGET_LEVEL },

    { MAP_A2_MAGGOT_LAIR_LEVEL_2, VECTOR_PREV, MAP_A2_MAGGOT_LAIR_LEVEL_1, TARGET_LEVEL },
    { MAP_A2_MAGGOT_LAIR_LEVEL_2, VECTOR_NEXT, MAP_A2_MAGGOT_LAIR_LEVEL_3, TARGET_LEVEL },

    { MAP_A2_MAGGOT_LAIR_LEVEL_3, VECTOR_PREV, MAP_A2_MAGGOT_LAIR_LEVEL_2, TARGET_LEVEL },
    { MAP_A2_MAGGOT_LAIR_LEVEL_3, VECTOR_NEXT, 356, UNIT_OBJECT },

    { MAP_A2_STONY_TOMB_LEVEL_1, VECTOR_PREV, MAP_A2_ROCKY_WASTE, TARGET_LEVEL },
    { MAP_A2_STONY_TOMB_LEVEL_1, VECTOR_NEXT, MAP_A2_STONY_TOMB_LEVEL_2, TARGET_LEVEL },

    { MAP_A2_STONY_TOMB_LEVEL_2, VECTOR_PREV, MAP_A2_STONY_TOMB_LEVEL_1, TARGET_LEVEL },

    { MAP_A2_TAL_RASHAS_TOMB_1, VECTOR_PREV, MAP_A2_CANYON_OF_THE_MAGI, TARGET_LEVEL },
    { MAP_A2_TAL_RASHAS_TOMB_1, VECTOR_QUEST, 152, UNIT_OBJECT },

    { MAP_A2_TAL_RASHAS_TOMB_2, VECTOR_PREV, MAP_A2_CANYON_OF_THE_MAGI, TARGET_LEVEL },
    { MAP_A2_TAL_RASHAS_TOMB_2, VECTOR_QUEST, 152, UNIT_OBJECT },

    { MAP_A2_TAL_RASHAS_TOMB_3, VECTOR_PREV, MAP_A2_CANYON_OF_THE_MAGI, TARGET_LEVEL },
    { MAP_A2_TAL_RASHAS_TOMB_3, VECTOR_QUEST, 152, UNIT_OBJECT },

    { MAP_A2_TAL_RASHAS_TOMB_4, VECTOR_PREV, MAP_A2_CANYON_OF_THE_MAGI, TARGET_LEVEL },
    { MAP_A2_TAL_RASHAS_TOMB_4, VECTOR_QUEST, 152, UNIT_OBJECT },

    { MAP_A2_TAL_RASHAS_TOMB_5, VECTOR_PREV, MAP_A2_CANYON_OF_THE_MAGI, TARGET_LEVEL },
    { MAP_A2_TAL_RASHAS_TOMB_5, VECTOR_QUEST, 152, UNIT_OBJECT },

    { MAP_A2_TAL_RASHAS_TOMB_6, VECTOR_PREV, MAP_A2_CANYON_OF_THE_MAGI, TARGET_LEVEL },
    { MAP_A2_TAL_RASHAS_TOMB_6, VECTOR_QUEST, 152, UNIT_OBJECT },

    { MAP_A2_TAL_RASHAS_TOMB_7, VECTOR_PREV, MAP_A2_CANYON_OF_THE_MAGI, TARGET_LEVEL },
    { MAP_A2_TAL_RASHAS_TOMB_7, VECTOR_QUEST, 152, UNIT_OBJECT },

    //act 3
    { MAP_A3_KURAST_DOCKS, VECTOR_NEXT, MAP_A3_SPIDER_FOREST, TARGET_LEVEL },

    { MAP_A3_SPIDER_FOREST, VECTOR_PREV, MAP_A3_KURAST_DOCKS, TARGET_LEVEL },
    { MAP_A3_SPIDER_FOREST, VECTOR_NEXT, MAP_A3_GREAT_MARSH, TARGET_LEVEL },
    { MAP_A3_SPIDER_FOREST, VECTOR_NEXT, MAP_A3_FLAYER_JUNGLE, TARGET_LEVEL },
    { MAP_A3_SPIDER_FOREST, VECTOR_QUEST, MAP_A3_SPIDER_CAVERN, TARGET_LEVEL },

    { MAP_A3_ARCHNID_LAIR, VECTOR_PREV, MAP_A3_SPIDER_FOREST, TARGET_LEVEL },

    { MAP_A3_SPIDER_CAVERN, VECTOR_PREV, MAP_A3_SPIDER_FOREST, TARGET_LEVEL },

    { MAP_A3_GREAT_MARSH, VECTOR_PREV, MAP_A3_SPIDER_FOREST, TARGET_LEVEL },
    { MAP_A3_GREAT_MARSH, VECTOR_NEXT, MAP_A3_FLAYER_JUNGLE, TARGET_LEVEL },

    { MAP_A3_FLAYER_JUNGLE, VECTOR_NEXT, MAP_A3_LOWER_KURAST, TARGET_LEVEL },
    { MAP_A3_FLAYER_JUNGLE, VECTOR_PREV, MAP_A3_SPIDER_FOREST, TARGET_LEVEL },
    //{ MAP_A3_FLAYER_JUNGLE, VECTOR_QUEST, 252, UNIT_OBJECT },
    { MAP_A3_FLAYER_JUNGLE, VECTOR_QUEST, MAP_A3_FLAYER_DUNGEON_LEVEL_1, TARGET_LEVEL },

    { MAP_A3_LOWER_KURAST, VECTOR_PREV, MAP_A3_FLAYER_JUNGLE, TARGET_LEVEL },
    { MAP_A3_LOWER_KURAST, VECTOR_NEXT, MAP_A3_KURAST_BAZAAR, TARGET_LEVEL },

    { MAP_A3_KURAST_BAZAAR, VECTOR_PREV, MAP_A3_LOWER_KURAST, TARGET_LEVEL },
    { MAP_A3_KURAST_BAZAAR, VECTOR_NEXT, MAP_A3_UPPER_KURAST, TARGET_LEVEL },
    { MAP_A3_KURAST_BAZAAR, VECTOR_QUEST, 195, UNIT_OBJECT },

    { MAP_A3_UPPER_KURAST, VECTOR_PREV, MAP_A3_KURAST_BAZAAR, TARGET_LEVEL },
    { MAP_A3_UPPER_KURAST, VECTOR_NEXT, MAP_A3_KURAST_CAUSEWAY, TARGET_LEVEL },
    { MAP_A3_UPPER_KURAST, VECTOR_QUEST, MAP_A3_SEWERS_LEVEL_1, TARGET_LEVEL },

    { MAP_A3_SEWERS_LEVEL_1, VECTOR_PREV, MAP_A3_UPPER_KURAST, TARGET_LEVEL },
    { MAP_A3_SEWERS_LEVEL_1, VECTOR_NEXT, MAP_A3_SEWERS_LEVEL_2, TARGET_LEVEL },

    { MAP_A3_SEWERS_LEVEL_2, VECTOR_PREV, MAP_A3_SEWERS_LEVEL_1, TARGET_LEVEL },
    { MAP_A3_SEWERS_LEVEL_2, VECTOR_QUEST, 405, UNIT_OBJECT },

    { MAP_A3_KURAST_CAUSEWAY, VECTOR_PREV, MAP_A3_UPPER_KURAST, TARGET_LEVEL },
    { MAP_A3_KURAST_CAUSEWAY, VECTOR_NEXT, MAP_A3_TRAVINCAL, TARGET_LEVEL },

    { MAP_A3_TRAVINCAL, VECTOR_PREV, MAP_A3_KURAST_CAUSEWAY, TARGET_LEVEL },
    { MAP_A3_TRAVINCAL, VECTOR_NEXT, 386, UNIT_OBJECT },

    { MAP_A3_DURANCE_OF_HATE_LEVEL_1, VECTOR_PREV, MAP_A3_TRAVINCAL, TARGET_LEVEL },
    { MAP_A3_DURANCE_OF_HATE_LEVEL_1, VECTOR_NEXT, MAP_A3_DURANCE_OF_HATE_LEVEL_2, TARGET_LEVEL },

    { MAP_A3_DURANCE_OF_HATE_LEVEL_2, VECTOR_PREV, MAP_A3_DURANCE_OF_HATE_LEVEL_1, TARGET_LEVEL },
    { MAP_A3_DURANCE_OF_HATE_LEVEL_2, VECTOR_NEXT, MAP_A3_DURANCE_OF_HATE_LEVEL_3, TARGET_LEVEL },

    { MAP_A3_DURANCE_OF_HATE_LEVEL_3, VECTOR_PREV, MAP_A3_DURANCE_OF_HATE_LEVEL_2, TARGET_LEVEL },
    { MAP_A3_DURANCE_OF_HATE_LEVEL_3, VECTOR_NEXT, 242, UNIT_MONSTER },

    { MAP_A3_SWAMPY_PIT_LEVEL_1, VECTOR_PREV, MAP_A3_FLAYER_JUNGLE, TARGET_LEVEL },
    { MAP_A3_SWAMPY_PIT_LEVEL_1, VECTOR_NEXT, MAP_A3_SWAMPY_PIT_LEVEL_2, TARGET_LEVEL },

    { MAP_A3_SWAMPY_PIT_LEVEL_2, VECTOR_PREV, MAP_A3_SWAMPY_PIT_LEVEL_1, TARGET_LEVEL },
    { MAP_A3_SWAMPY_PIT_LEVEL_2, VECTOR_NEXT, MAP_A3_SWAMPY_PIT_LEVEL_3, TARGET_LEVEL },

    { MAP_A3_SWAMPY_PIT_LEVEL_3, VECTOR_PREV, MAP_A3_SWAMPY_PIT_LEVEL_2, TARGET_LEVEL },
    { MAP_A3_SWAMPY_PIT_LEVEL_3, VECTOR_QUEST, 397, UNIT_OBJECT },

    { MAP_A3_FLAYER_DUNGEON_LEVEL_1, VECTOR_PREV, MAP_A3_FLAYER_JUNGLE, TARGET_LEVEL },
    { MAP_A3_FLAYER_DUNGEON_LEVEL_1, VECTOR_NEXT, MAP_A3_FLAYER_DUNGEON_LEVEL_2, TARGET_LEVEL },
    
    { MAP_A3_FLAYER_DUNGEON_LEVEL_2, VECTOR_PREV, MAP_A3_FLAYER_DUNGEON_LEVEL_1, TARGET_LEVEL },
    { MAP_A3_FLAYER_DUNGEON_LEVEL_2, VECTOR_NEXT, MAP_A3_FLAYER_DUNGEON_LEVEL_3, TARGET_LEVEL },
    
    { MAP_A3_FLAYER_DUNGEON_LEVEL_3, VECTOR_PREV, MAP_A3_FLAYER_DUNGEON_LEVEL_2, TARGET_LEVEL },
    { MAP_A3_FLAYER_DUNGEON_LEVEL_3, VECTOR_QUEST, 406, UNIT_OBJECT },
    
    { MAP_A3_RUINED_TEMPLE, VECTOR_PREV, MAP_A3_KURAST_BAZAAR, TARGET_LEVEL },
    { MAP_A3_RUINED_TEMPLE, VECTOR_QUEST, 193, UNIT_OBJECT },

    //act 4
    { MAP_A4_THE_PANDEMONIUM_FORTRESS, VECTOR_NEXT, MAP_A4_OUTER_STEPPES, TARGET_LEVEL },

    { MAP_A4_OUTER_STEPPES, VECTOR_PREV, MAP_A4_THE_PANDEMONIUM_FORTRESS, TARGET_LEVEL },
    { MAP_A4_OUTER_STEPPES, VECTOR_NEXT, MAP_A4_PLAINS_OF_DESPAIR, TARGET_LEVEL },

    { MAP_A4_PLAINS_OF_DESPAIR, VECTOR_PREV, MAP_A4_OUTER_STEPPES, TARGET_LEVEL },
    { MAP_A4_PLAINS_OF_DESPAIR, VECTOR_NEXT, MAP_A4_CITY_OF_THE_DAMNED, TARGET_LEVEL },
    { MAP_A4_PLAINS_OF_DESPAIR, VECTOR_QUEST, 256, UNIT_NPC },

    { MAP_A4_CITY_OF_THE_DAMNED, VECTOR_PREV, MAP_A4_PLAINS_OF_DESPAIR, TARGET_LEVEL },
    { MAP_A4_CITY_OF_THE_DAMNED, VECTOR_NEXT, MAP_A4_RIVER_OF_FLAME, TARGET_LEVEL },

    { MAP_A4_RIVER_OF_FLAME, VECTOR_PREV, MAP_A4_CITY_OF_THE_DAMNED, TARGET_LEVEL },
    { MAP_A4_RIVER_OF_FLAME, VECTOR_NEXT, MAP_A4_THE_CHAOS_SANCTUARY, TARGET_LEVEL },
    { MAP_A4_RIVER_OF_FLAME, VECTOR_QUEST, 775, UNIT_NPC },

    { MAP_A4_THE_CHAOS_SANCTUARY, VECTOR_QUEST, 255, UNIT_OBJECT },
    { MAP_A4_THE_CHAOS_SANCTUARY, VECTOR_PREV, MAP_A4_RIVER_OF_FLAME, TARGET_LEVEL },

    //act 5
    { MAP_A5_HARROGATH, VECTOR_NEXT, MAP_A5_THE_BLOODY_FOOTHILLS, TARGET_LEVEL },

    { MAP_A5_THE_BLOODY_FOOTHILLS, VECTOR_PREV, MAP_A5_HARROGATH, TARGET_LEVEL },
    { MAP_A5_THE_BLOODY_FOOTHILLS, VECTOR_NEXT, MAP_A5_FRIGID_HIGHLANDS, TARGET_LEVEL },
    { MAP_A5_THE_BLOODY_FOOTHILLS, VECTOR_QUEST, 824, UNIT_TILE },

    { MAP_A5_FRIGID_HIGHLANDS, VECTOR_PREV, MAP_A5_THE_BLOODY_FOOTHILLS, TARGET_LEVEL },
    { MAP_A5_FRIGID_HIGHLANDS, VECTOR_NEXT, MAP_A5_ARREAT_PLATEAU, TARGET_LEVEL },

    { MAP_A5_ARREAT_PLATEAU, VECTOR_PREV, MAP_A5_FRIGID_HIGHLANDS, TARGET_LEVEL },
    { MAP_A5_ARREAT_PLATEAU, VECTOR_NEXT, MAP_A5_CRYSTALLINE_PASSAGE, TARGET_LEVEL },

    { MAP_A5_CRYSTALLINE_PASSAGE, VECTOR_PREV, MAP_A5_ARREAT_PLATEAU, TARGET_LEVEL },
    { MAP_A5_CRYSTALLINE_PASSAGE, VECTOR_NEXT, MAP_A5_GLACIAL_TRAIL, TARGET_LEVEL },
    { MAP_A5_CRYSTALLINE_PASSAGE, VECTOR_QUEST, MAP_A5_FROZEN_RIVER, TARGET_LEVEL },

    { MAP_A5_FROZEN_RIVER, VECTOR_PREV, MAP_A5_CRYSTALLINE_PASSAGE, TARGET_LEVEL },
    { MAP_A5_FROZEN_RIVER, VECTOR_QUEST, 793, UNIT_NPC },

    { MAP_A5_GLACIAL_TRAIL, VECTOR_PREV, MAP_A5_CRYSTALLINE_PASSAGE, TARGET_LEVEL },
    { MAP_A5_GLACIAL_TRAIL, VECTOR_NEXT, MAP_A5_FROZEN_TUNDRA, TARGET_LEVEL },

    { MAP_A5_FROZEN_TUNDRA, VECTOR_PREV, MAP_A5_GLACIAL_TRAIL, TARGET_LEVEL },
    { MAP_A5_FROZEN_TUNDRA, VECTOR_NEXT, MAP_A5_THE_ANCIENTS_WAY, TARGET_LEVEL },

    { MAP_A5_THE_ANCIENTS_WAY, VECTOR_PREV, MAP_A5_FROZEN_TUNDRA, TARGET_LEVEL },
    { MAP_A5_THE_ANCIENTS_WAY, VECTOR_NEXT, MAP_A5_ARREAT_SUMMIT, TARGET_LEVEL },

    { MAP_A5_ARREAT_SUMMIT, VECTOR_PREV, MAP_A5_THE_ANCIENTS_WAY, TARGET_LEVEL },
    { MAP_A5_ARREAT_SUMMIT, VECTOR_NEXT, MAP_A5_WORLDSTONE_KEEP_LEVEL_1, TARGET_LEVEL },

    { MAP_A5_WORLDSTONE_KEEP_LEVEL_1, VECTOR_PREV, MAP_A5_ARREAT_SUMMIT, TARGET_LEVEL },
    { MAP_A5_WORLDSTONE_KEEP_LEVEL_1, VECTOR_NEXT, MAP_A5_WORLDSTONE_KEEP_LEVEL_2, TARGET_LEVEL },

    { MAP_A5_WORLDSTONE_KEEP_LEVEL_2, VECTOR_PREV, MAP_A5_WORLDSTONE_KEEP_LEVEL_1, TARGET_LEVEL },
    { MAP_A5_WORLDSTONE_KEEP_LEVEL_2, VECTOR_NEXT, MAP_A5_WORLDSTONE_KEEP_LEVEL_3, TARGET_LEVEL },

    { MAP_A5_WORLDSTONE_KEEP_LEVEL_3, VECTOR_PREV, MAP_A5_WORLDSTONE_KEEP_LEVEL_2, TARGET_LEVEL },
    { MAP_A5_WORLDSTONE_KEEP_LEVEL_3, VECTOR_NEXT, MAP_A5_THRONE_OF_DESTRUCTION, TARGET_LEVEL },

    { MAP_A5_THRONE_OF_DESTRUCTION, VECTOR_PREV, MAP_A5_WORLDSTONE_KEEP_LEVEL_3, TARGET_LEVEL },
    { MAP_A5_THRONE_OF_DESTRUCTION, VECTOR_NEXT, 543, UNIT_NPC },

    { MAP_A5_NIHLATHAKS_TEMPLE, VECTOR_PREV, MAP_A5_THRONE_OF_DESTRUCTION, TARGET_LEVEL },
    { MAP_A5_NIHLATHAKS_TEMPLE, VECTOR_NEXT, MAP_A5_HALLS_OF_ANGUISH, TARGET_LEVEL },

    { MAP_A5_HALLS_OF_ANGUISH, VECTOR_PREV, MAP_A5_NIHLATHAKS_TEMPLE, TARGET_LEVEL },
    { MAP_A5_HALLS_OF_ANGUISH, VECTOR_NEXT, MAP_A5_HALLS_OF_PAIN, TARGET_LEVEL },

    { MAP_A5_HALLS_OF_PAIN, VECTOR_PREV, MAP_A5_HALLS_OF_ANGUISH, TARGET_LEVEL },
    { MAP_A5_HALLS_OF_PAIN, VECTOR_NEXT, MAP_A5_HALLS_OF_VAUGHT, TARGET_LEVEL },

    { MAP_A5_HALLS_OF_VAUGHT, VECTOR_PREV, MAP_A5_HALLS_OF_PAIN, TARGET_LEVEL },
    { MAP_A5_HALLS_OF_VAUGHT, VECTOR_QUEST, 462, UNIT_OBJECT },

    { MAP_A5_FORGOTTEN_SANDS, VECTOR_PREV, 60, UNIT_OBJECT },
    { MAP_A5_FORGOTTEN_SANDS, VECTOR_QUEST, 708, UNIT_MONSTER },

    { MAP_A5_FURNACE_OF_PAIN, VECTOR_PREV, 60, UNIT_OBJECT },
    { MAP_A5_FURNACE_OF_PAIN, VECTOR_QUEST, 706, UNIT_MONSTER },


    { MAP_A5_MATRONS_DEN, VECTOR_PREV, 60, UNIT_OBJECT },
    { MAP_A5_MATRONS_DEN, VECTOR_QUEST, 707, UNIT_MONSTER },
};

String D2GetMapName(BYTE iMapID)
{
    switch (iMapID)
    {    
        ///////////////////////////////////////////////////
        // Act 1 Maps
        ///////////////////////////////////////////////////
    case MAP_A1_ROGUE_ENCAMPMENT:
        return "Rogue Encampment";
    case MAP_A1_BLOOD_MOOR:
        return "Blood Moor";
    case MAP_A1_COLD_PLAINS:
        return "Cold Plains";
    case MAP_A1_STONY_FIELD:
        return "Stony Field";
    case MAP_A1_DARK_WOOD:
        return "Dark Wood";
    case MAP_A1_BLACK_MARSH:
        return "Black Marsh";
    case MAP_A1_DEN_OF_EVIL:
        return "Den of Evil";
    case MAP_A1_CAVE_LEVEL_1:
        return "Cave Level 1";
    case MAP_A1_UNDERGROUND_PASSAGE_LEVEL_1:
        return "Underground Passage Level 1";
    case MAP_A1_HOLE_LEVEL_1:
        return "Hole Level 1";
    case MAP_A1_PIT_LEVEL_1:
        return "Pit Level 1";
    case MAP_A1_CAVE_LEVEL_2:
        return "Cave Level 2";
    case MAP_A1_UNDERGROUND_PASSAGE_LEVEL_2:
        return "Underground Passage Level 2";
    case MAP_A1_HOLE_LEVEL_2:
        return "Hole Level 2";
    case MAP_A1_PIT_LEVEL_2:
        return "Pit Level 2";
    case MAP_A1_BURIAL_GROUNDS:
        return "Burial Grounds";
    case MAP_A1_CRYPT:
        return "Crypt";
    case MAP_A1_MAUSOLEUM:
        return "Mausoleum";
    case MAP_A1_FORGOTTEN_TOWER:
        return "Forgotten Tower";
    case MAP_A1_TOWER_CELLAR_LEVEL_1:
        return "Tower Cellar Level 1";
    case MAP_A1_TOWER_CELLAR_LEVEL_2:
        return "Tower Cellar Level 2";
    case MAP_A1_TOWER_CELLAR_LEVEL_3:
        return "Tower Cellar Level 3";
    case MAP_A1_TOWER_CELLAR_LEVEL_4:
        return "Tower Cellar Level 4";
    case MAP_A1_TOWER_CELLAR_LEVEL_5:
        return "Tower Cellar Level 5";
    case MAP_A1_TAMOE_HIGHLAND:
        return "Tamoe Highland";
    case MAP_A1_MONASTERY_GATE:
        return "Monastery Gate";
    case MAP_A1_OUTER_CLOISTER:
        return "Outer Cloister";
    case MAP_A1_BARRACKS:
        return "Barracks";
    case MAP_A1_JAIL_LEVEL_1:
        return "Jail Level 1";
    case MAP_A1_JAIL_LEVEL_2:
        return "Jail Level 2";
    case MAP_A1_JAIL_LEVEL_3:
        return "Jail Level 3";
    case MAP_A1_INNER_CLOISTER:
    case MAP_A1_INNER_CLOISTER_2:
        return "Inner Cloister";
    case MAP_A1_CATACOMBS_LEVEL_1:
        return "Catacombs Level 1";
    case MAP_A1_CATACOMBS_LEVEL_2:
        return "Catacombs Level 2";
    case MAP_A1_CATACOMBS_LEVEL_3:
        return "Catacombs Level 3";
    case MAP_A1_CATACOMBS_LEVEL_4:
        return "Catacombs Level 4";
    case MAP_A1_TRISTRAM:
        return "Tristram";
    case MAP_A1_THE_SECRET_COW_LEVEL:
        return "The Secret Cow Level";
        ///////////////////////////////////////////////////
        // Act 2 Maps
        ///////////////////////////////////////////////////
    case MAP_A2_LUT_GHOLEIN:
        return "Lut Gholein";
    case MAP_A2_ROCKY_WASTE:
        return "Rocky Waste";
    case MAP_A2_DRY_HILLS:
        return "Dry Hills";
    case MAP_A2_FAR_OASIS:
        return "Far Oasis";
    case MAP_A2_LOST_CITY:
        return "Lost City";
    case MAP_A2_VALLEY_OF_SNAKES:
        return "Valley of Snakes";
    case MAP_A2_CANYON_OF_THE_MAGI:
        return "Cayon of the Magi";
    case MAP_A2_SEWERS_LEVEL_1:
        return "Sewers Level 1";
    case MAP_A2_SEWERS_LEVEL_2:
        return "Sewers Level 2";
    case MAP_A2_SEWERS_LEVEL_3:
        return "Sewers Level 3";
    case MAP_A2_HAREM_LEVEL_1:
        return "Harem Level 1";
    case MAP_A2_HAREM_LEVEL_2:
        return "Harem Level 2";
    case MAP_A2_PALACE_CELLAR_LEVEL_1:
        return "Palace Cellar Level 1";
    case MAP_A2_PALACE_CELLAR_LEVEL_2:
        return "Palace Cellar Level 2";
    case MAP_A2_PALACE_CELLAR_LEVEL_3:
        return "Palace Cellar Level 3";
    case MAP_A2_STONY_TOMB_LEVEL_1:
        return "Stony Tomb Level 1";
    case MAP_A2_HALLS_OF_THE_DEAD_LEVEL_1:
        return "Halls of the Dead Level 1";
    case MAP_A2_HALLS_OF_THE_DEAD_LEVEL_2:
        return "Halls of the Dead Level 2";
    case MAP_A2_CLAW_VIPER_TEMPLE_LEVEL_1:
        return "Claw Viper Temple Level 1";
    case MAP_A2_STONY_TOMB_LEVEL_2:
        return "Stony Tomb Level 2";
    case MAP_A2_HALLS_OF_THE_DEAD_LEVEL_3:
        return "Halls of the Dead Level 3";
    case MAP_A2_CLAW_VIPER_TEMPLE_LEVEL_2:
        return "Claw Viper Temple Level 2";
    case MAP_A2_MAGGOT_LAIR_LEVEL_1:
        return "Maggot Lair Level 1";
    case MAP_A2_MAGGOT_LAIR_LEVEL_2:
        return "Maggot Lair Level 2";
    case MAP_A2_MAGGOT_LAIR_LEVEL_3:
        return "Maggot Lair Level 3";
    case MAP_A2_ANCIENT_TUNNELS:
        return "Ancient Tunnels";
    case MAP_A2_TAL_RASHAS_TOMB_1:
    case MAP_A2_TAL_RASHAS_TOMB_2:
    case MAP_A2_TAL_RASHAS_TOMB_3:
    case MAP_A2_TAL_RASHAS_TOMB_4:
    case MAP_A2_TAL_RASHAS_TOMB_5:
    case MAP_A2_TAL_RASHAS_TOMB_6:
    case MAP_A2_TAL_RASHAS_TOMB_7:
        return "Tal Rasha's Tomb";
    case MAP_A2_TAL_RASHAS_CHAMBER:
        return "Tal Rasha's Chamber";
    case MAP_A2_ARCANE_SANCTUARY:
        return "Arcane Sanctuary";
        ///////////////////////////////////////////////////
        // Act 3 Maps
        ///////////////////////////////////////////////////
    case MAP_A3_KURAST_DOCKS:
        return "Kurast Docks";
    case MAP_A3_SPIDER_FOREST:
        return "Spider Forest";
    case MAP_A3_GREAT_MARSH:
        return "Great Marsh";
    case MAP_A3_FLAYER_JUNGLE:
        return "Flayer Jungle";
    case MAP_A3_LOWER_KURAST:
        return "Lower Kurast";
    case MAP_A3_KURAST_BAZAAR:
        return "Kurast Bazaar";
    case MAP_A3_UPPER_KURAST:
        return "Upper Kurast";
    case MAP_A3_KURAST_CAUSEWAY:
        return "Kurast Causeway";
    case MAP_A3_TRAVINCAL:
        return "Travinval";
    case MAP_A3_ARCHNID_LAIR:
        return "Archnid Lair";
    case MAP_A3_SPIDER_CAVERN:
        return "Spider Cavern";
    case MAP_A3_SWAMPY_PIT_LEVEL_1:
        return "Swampy Pit Level 1";
    case MAP_A3_SWAMPY_PIT_LEVEL_2:
        return "Swampy Pit Level 2";
    case MAP_A3_FLAYER_DUNGEON_LEVEL_1:
        return "Flayer Dungeon Level 1";
    case MAP_A3_FLAYER_DUNGEON_LEVEL_2:
        return "Flayer Dungeon Level 2";
    case MAP_A3_SWAMPY_PIT_LEVEL_3:
        return "Swampy Pit Level 3";
    case MAP_A3_FLAYER_DUNGEON_LEVEL_3:
        return "Flayer Dungeon Level 3";
    case MAP_A3_SEWERS_LEVEL_1:
        return "Sewers Level 1";
    case MAP_A3_SEWERS_LEVEL_2:
        return "Sewers Level 2";
    case MAP_A3_RUINED_TEMPLE:
        return "Ruined Temple";
    case MAP_A3_DISUSED_FANE:
        return "Disused Fane";
    case MAP_A3_FORGOTTEN_RELIQUARY:
        return "Forgotten Reliquary";
    case MAP_A3_FORGOTTEN_TEMPLE:
        return "Forgotten Temple";
    case MAP_A3_RUINED_FANE:
        return "Ruined Fane";
    case MAP_A3_DISUSED_RELIQUARY:
        return "Disused Reliquary";
    case MAP_A3_DURANCE_OF_HATE_LEVEL_1:
        return "Durance of Hate Level 1";
    case MAP_A3_DURANCE_OF_HATE_LEVEL_2:
        return "Durance of Hate Level 2";
    case MAP_A3_DURANCE_OF_HATE_LEVEL_3:
        return "Durance of Hate Level 3";
        ///////////////////////////////////////////////////
        // Act 4 Maps
        ///////////////////////////////////////////////////
    case MAP_A4_THE_PANDEMONIUM_FORTRESS:
        return "The Pandemonium Fortress";
    case MAP_A4_OUTER_STEPPES:
        return "Outer Steppes";
    case MAP_A4_PLAINS_OF_DESPAIR:
        return "Plains of Despair";
    case MAP_A4_CITY_OF_THE_DAMNED:
        return "City of the Damned";
    case MAP_A4_RIVER_OF_FLAME:
        return "River of Flame";
    case MAP_A4_THE_CHAOS_SANCTUARY:
        return "The Chaos Sanctuary";
        ///////////////////////////////////////////////////
        // Act 5 Maps
        ///////////////////////////////////////////////////
    case MAP_A5_HARROGATH:
        return "Harrogath";
    case MAP_A5_THE_BLOODY_FOOTHILLS:
        return "The Bloody Foothills";
    case MAP_A5_FRIGID_HIGHLANDS:
        return "Frigid Highlands";
    case MAP_A5_ARREAT_PLATEAU:
        return "Arreat Plateau";
    case MAP_A5_CRYSTALLINE_PASSAGE:
        return "Crystalline Passage";
    case MAP_A5_FROZEN_RIVER:
        return "Frozen River";
    case MAP_A5_GLACIAL_TRAIL:
        return "Glacial Trail";
    case MAP_A5_DRIFTER_CAVERN:
        return "Drifter Cavern";
    case MAP_A5_FROZEN_TUNDRA:
        return "Frozen Tundra";
    case MAP_A5_THE_ANCIENTS_WAY:
        return "The Ancients' Way";
    case MAP_A5_ICY_CELLAR:
        return "Icy Cellar";
    case MAP_A5_ARREAT_SUMMIT:
        return "Arreat Summit";
    case MAP_A5_HALLS_OF_PAIN:
        return "Halls of Pain";
    case MAP_A5_ABADDON:
        return "Abaddon";
    case MAP_A5_PIT_OF_ACHERON:
        return "Pit of Acheron";
    case MAP_A5_INFERNAL_PIT:
        return "Infernal Pit";
    case MAP_A5_NIHLATHAKS_TEMPLE:
        return "Nihlathak's Temple";
    case MAP_A5_HALLS_OF_ANGUISH:
        return "Halls of Anguish";
    case MAP_A5_HALLS_OF_VAUGHT:
        return "Halls of Vaught";
    case MAP_A5_WORLDSTONE_KEEP_LEVEL_1:
        return "Worldstone Keep Level 1";
    case MAP_A5_WORLDSTONE_KEEP_LEVEL_2:
        return "Worldstone Keep Level 2";
    case MAP_A5_WORLDSTONE_KEEP_LEVEL_3:
        return "Worldstone Keep Level 3";
    case MAP_A5_THRONE_OF_DESTRUCTION:
        return "Throne of Destruction";
    case MAP_A5_WORLDSTONE_KEEP:
        return "The Worldstone Chamber";
    case MAP_A5_MATRONS_DEN:
        return "Matron's Den";
    case MAP_A5_FORGOTTEN_SANDS:
        return "Forgotten Sands";
    case MAP_A5_FURNACE_OF_PAIN:
        return "Furnace of Pain";
    case MAP_A5_TRISTRAM:
        return "Uber Tristram";
    default:
        return 0;
    }

    return "Unknown";
}

INT nWaypoints[] = { 119, 157, 156, 402, 323, 288, 237, 324, 238, 496, 511, 494, 398, 429 };
BOOL GetVectorArrows()
{
    UnitAny* pPlayer = D2CLIENT_GetPlayerUnit();
    if (GetUnitLevel(pPlayer)->dwLevelNo != nLastLevel)
    {
        if (v_CurrentVectors[GetUnitLevel(pPlayer)->dwLevelNo].GetSize() != 0)
            return TRUE;

        LPLEVELEXIT pLevels[0x40] = {NULL};

        if (!cMap->CreateCollisionMap())
            return FALSE;
        cMap->GetLevelExits(pLevels, 0x40);

        for (INT i = 0; i < ArraySize(nWaypoints); ++i)
        {
            Room2* pRoom;
            PresetUnit* pUnit = FindPresetUnit(nWaypoints[i], UNIT_OBJECT, &pRoom);
            if(!pUnit)
                continue;

            LPVECTOR pVect = new VECTOR;
            pVect->nType = VECTOR_WAYPOINT;
            /*pVect->ptPos.x = ((pRoom->dwPosX * 5) + pUnit->dwPosX) * 32;
            pVect->ptPos.y = ((pRoom->dwPosY * 5) + pUnit->dwPosY) * 32;*/
            pVect->ptPos.x = pRoom->dwPosX * 5 + pUnit->dwPosX;
            pVect->ptPos.y = pRoom->dwPosY * 5 + pUnit->dwPosY;
            pVect->dwTarget = nWaypoints[i];
            pVect->dwTargetType = UNIT_OBJECT;

            v_CurrentVectors[GetUnitLevel(pPlayer)->dwLevelNo].Add(pVect);
            break;
        }

        for (INT j = 0; j < ArraySize(Vectors); ++j)
        {
            if (Vectors[j].dwCurrentLevel != GetUnitLevel(D2CLIENT_GetPlayerUnit())->dwLevelNo)
                continue;

            if (Vectors[j].dwTargetType == TARGET_LEVEL)
            {
                for (INT i = 0; i < 0x40; i++)
                {
                    if (!pLevels[i])
                        break;

                    if (Vectors[j].dwTarget != pLevels[i]->dwTargetLevel)
                        continue;

                    for (INT k = 0; k < v_CurrentVectors[GetUnitLevel(pPlayer)->dwLevelNo].GetSize(); ++k)
                    {
                        if(v_CurrentVectors[GetUnitLevel(pPlayer)->dwLevelNo][k]->nType == Vectors[j].dwVectorType)
                            goto ContinueIt;
                    }

                    LPVECTOR pVect = new VECTOR;
                    pVect->ptPos.x = pLevels[i]->ptPos.x;
                    pVect->ptPos.y = pLevels[i]->ptPos.y;
                    pVect->nType = Vectors[j].dwVectorType;
                    pVect->dwTarget = Vectors[j].dwTarget;
                    pVect->dwTargetType = Vectors[j].dwTargetType;

                    v_CurrentVectors[GetUnitLevel(pPlayer)->dwLevelNo].Add(pVect);
                }
            }
            else
            {
                Room2* pRoom;
                PresetUnit* pUnit = FindPresetUnit(Vectors[j].dwTarget, Vectors[j].dwTargetType, &pRoom);

            //                    continue;
                if (!pUnit)
                    continue;                

                for (INT k = 0; k < v_CurrentVectors[GetUnitLevel(pPlayer)->dwLevelNo].GetSize(); ++k)
                {
                    if (v_CurrentVectors[GetUnitLevel(pPlayer)->dwLevelNo][k]->nType == Vectors[j].dwVectorType)
                        goto ContinueIt;
                }
                
                LPVECTOR pVect = new VECTOR;
                pVect->ptPos.x = pRoom->dwPosX * 5 + pUnit->dwPosX;
                pVect->ptPos.y = pRoom->dwPosY * 5 + pUnit->dwPosY;
                pVect->nType = Vectors[j].dwVectorType;
                pVect->dwTarget = 0;

                //continue;

                v_CurrentVectors[GetUnitLevel(pPlayer)->dwLevelNo].Add(pVect);
                break;
            }

ContinueIt:
            continue;
        }

        nLastLevel = GetUnitLevel(D2CLIENT_GetPlayerUnit())->dwLevelNo;
    }

    return TRUE;
}