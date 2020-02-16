#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "dialog_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"

#include "game/level_update.h"

#include "levels/scripts.h"

#include "actors/common1.h"
// #include "actors/group13.h"
#include "actors/group15.h"

#include "make_const_nonconst.h"
#include "levels/bitdw/header.h"

static const LevelScript script_func_local_1[] = {
    OBJECT(/*model*/ MODEL_BITDW_SQUARE_PLATFORM,   /*pos*/ -1966, -3154,  3586, /*angle*/ 0, 0, 0,  /*behParam*/ 0x00000000, /*beh*/ bhvSquarishPathMoving),
    OBJECT(/*model*/ MODEL_BITDW_SQUARE_PLATFORM,   /*pos*/ -1352, -3154,  4200, /*angle*/ 0, 0, 0,  /*behParam*/ 0x00020000, /*beh*/ bhvSquarishPathMoving),
    OBJECT(/*model*/ MODEL_BITDW_SQUARE_PLATFORM,   /*pos*/ -2963,  1017, -2464, /*angle*/ 0, 0, 0,  /*behParam*/ 0x00000000, /*beh*/ bhvSquarishPathMoving),
    OBJECT(/*model*/ MODEL_BITDW_SQUARE_PLATFORM,   /*pos*/ -2349,  1017, -1849, /*angle*/ 0, 0, 0,  /*behParam*/ 0x00020000, /*beh*/ bhvSquarishPathMoving),
    OBJECT(/*model*/ MODEL_BITDW_SQUARE_PLATFORM,   /*pos*/ -2349,  1017, -1235, /*angle*/ 0, 0, 0,  /*behParam*/ 0x00000000, /*beh*/ bhvSquarishPathMoving),
    OBJECT(/*model*/ MODEL_BITDW_SQUARE_PLATFORM,   /*pos*/ -1735,  1017,  -621, /*angle*/ 0, 0, 0,  /*behParam*/ 0x00020000, /*beh*/ bhvSquarishPathMoving),
    OBJECT(/*model*/ MODEL_BITDW_SEESAW_PLATFORM,   /*pos*/  1491,  1273,   512, /*angle*/ 0, 90, 0, /*behParam*/ 0x00000000, /*beh*/ bhvSeesawPlatform),
    OBJECT(/*model*/ MODEL_BITDW_SEESAW_PLATFORM,   /*pos*/  -147,   894,   512, /*angle*/ 0, 90, 0, /*behParam*/ 0x00000000, /*beh*/ bhvSeesawPlatform),
    OBJECT(/*model*/ MODEL_BITDW_SLIDING_PLATFORM,  /*pos*/ -5728,   819, -2151, /*angle*/ 0, 0, 0,  /*behParam*/ 0x03CE0000, /*beh*/ bhvSlidingPlatform2),
    OBJECT(/*model*/ MODEL_BITDW_FERRIS_WHEEL_AXLE, /*pos*/  -204, -1924,  3381, /*angle*/ 0, 0, 0,  /*behParam*/ 0x00010000, /*beh*/ bhvFerrisWheelAxle),
    OBJECT(/*model*/ MODEL_BITDW_STAIRCASE,         /*pos*/  5279,  1740,    -6, /*angle*/ 0, 0, 0,  /*behParam*/ 0x00010000, /*beh*/ bhvAnimatesOnFloorSwitchPress),
    OBJECT(/*model*/ MODEL_PURPLE_SWITCH,           /*pos*/  3922,  1740,    -7, /*angle*/ 0, 0, 0,  /*behParam*/ 0x00000000, /*beh*/ bhvFloorSwitchAnimatesObject),
    RETURN(),
};

static const LevelScript script_func_local_2[] = {
    OBJECT(/*model*/ MODEL_NONE, /*pos*/ -3092, -2795, 2842, /*angle*/ 0, 0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvFlamethrower),
    OBJECT(/*model*/ MODEL_NONE, /*pos*/  2463, -2386, 2844, /*angle*/ 0, 0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvFlamethrower),
    RETURN(),
};

static const LevelScript script_func_local_3[] = {
    // OBJECT(/*model*/ MODEL_NONE, /*pos*/  294, 1305, 582,  /*angle*/ 0, 0, 0,  /*behParam*/ 0x00000000, /*beh*/ bhvBowserCourseRedCoinStar),
    // OBJECT(/*model*/ MODEL_STAR, /*pos*/  294, 1305, -3000, /*angle*/ 0, 0, 0,  /*behParam*/ 0x00000000, /*beh*/ bhvStarNoExit),
    // OBJECT(/*model*/ MODEL_STAR, /*pos*/  294, 1305, -4000, /*angle*/ 0, 0, 0,  /*behParam*/ 0x00000000, /*beh*/ bhvStarNoExit),
    OBJECT(/*model*/ MODEL_NONE, /*pos*/ 1135, 1079, -5824,  /*angle*/ 0, 0, 0, /*behParam*/ 0x03000000, /*beh*/ bhvJetStreamRingSpawner),
    OBJECT(/*model*/ MODEL_NONE, /*pos*/ 1954, 4553, -3963,  /*angle*/ 0, 0, 0, /*behParam*/ 0x03000000, /*beh*/ bhvJetStreamRingSpawner),
    OBJECT(/*model*/ MODEL_NONE, /*pos*/ 1954, 4553, -2779,  /*angle*/ 0, 0, 0, /*behParam*/ 0x03000000, /*beh*/ bhvJetStreamRingSpawner),
    OBJECT(/*model*/ MODEL_NONE, /*pos*/ 496,  4750, -1643,  /*angle*/ 0, 0, 0, /*behParam*/ 0x03000000, /*beh*/ bhvJetStreamRingSpawner),
    // OBJECT(/*model*/ MODEL_NONE, /*pos*/-3266, 5346, -2007,  /*angle*/ 0, 0, 0, /*behParam*/ 0x03000000, /*beh*/ bhvJetStreamRingSpawner),
    OBJECT(/*model*/ MODEL_NONE, /*pos*/-3266, 5182, -2943,  /*angle*/ 0, 0, 0, /*behParam*/ 0x03000000, /*beh*/ bhvJetStreamRingSpawner),
    OBJECT(/*model*/ MODEL_NONE, /*pos*/-3266, 6150, -3165,  /*angle*/ 0, 0, 0, /*behParam*/ 0x03000000, /*beh*/ bhvJetStreamRingSpawner),
    OBJECT(/*model*/ MODEL_NONE, /*pos*/-2289, 6231, -3807,  /*angle*/ 0, 0, 0, /*behParam*/ 0x03000000, /*beh*/ bhvJetStreamRingSpawner),
    RETURN(),
};

const LevelScript level_bitdw_entry[] = {
    INIT_LEVEL(),
    LOAD_MIO0(        /*seg*/ 0x07, _bitdw_segment_7SegmentRomStart, _bitdw_segment_7SegmentRomEnd),
    LOAD_MIO0(        /*seg*/ 0x0B, _effect_mio0SegmentRomStart, _effect_mio0SegmentRomEnd),
    LOAD_MIO0(        /*seg*/ 0x0A, _bidw_skybox_mio0SegmentRomStart, _bidw_skybox_mio0SegmentRomEnd),
    LOAD_MIO0_TEXTURE(/*seg*/ 0x09, _sky_mio0SegmentRomStart, _sky_mio0SegmentRomEnd),
    // LOAD_MIO0(        /*seg*/ 0x05, _group13_mio0SegmentRomStart, _group13_mio0SegmentRomEnd),
    // LOAD_RAW(         /*seg*/ 0x0C, _group13_geoSegmentRomStart,  _group13_geoSegmentRomEnd),
    LOAD_MIO0(        /*seg*/ 0x06, _group15_mio0SegmentRomStart, _group15_mio0SegmentRomEnd),
    LOAD_RAW(         /*seg*/ 0x0D, _group15_geoSegmentRomStart,  _group15_geoSegmentRomEnd),
    LOAD_MIO0(        /*seg*/ 0x08, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd),
    LOAD_RAW(         /*seg*/ 0x0F, _common0_geoSegmentRomStart,  _common0_geoSegmentRomEnd),
    JUMP_LINK(script_func_global_1),
    ALLOC_LEVEL_POOL(),
    MARIO(/*model*/ MODEL_MARIO, /*behParam*/ 0x00000001, /*beh*/ bhvMario),
    // LOAD_MODEL_FROM_GEO(MODEL_TOAD,       toad_geo),
    // JUMP_LINK(script_func_global_14),
    JUMP_LINK(script_func_global_16),
    LOAD_MODEL_FROM_GEO(MODEL_WATER_RING, water_ring_geo),
    LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_CASTLE_DOOR,  castle_door_geo),
    AREA(/*index*/ 1, world_geo),
        OBJECT(/*model*/ MODEL_CASTLE_GROUNDS_CASTLE_DOOR, /*pos*/  -80,  1240,   -8085,  /*angle*/ 0, 0, 0,    /*behParam*/ 0x000B0000,       /*beh*/ bhvDoorWarp),
        OBJECT(/*model*/ MODEL_CASTLE_GROUNDS_CASTLE_DOOR, /*pos*/   80,  1240,   -8085,  /*angle*/ 0, 180, 0,  /*behParam*/ 0x000B0000,       /*beh*/ bhvDoorWarp),
        OBJECT(/*model*/ MODEL_TOAD,                       /*pos*/ -1006, 5536,     321,  /*angle*/ 0, 300, 0,    /*behParam*/ DIALOG_082 << 24, /*beh*/ bhvToadBasic),
        OBJECT(/*model*/ MODEL_TOAD,                       /*pos*/  -346, 1150,   -6411,  /*angle*/ 0, 11, 0,    /*behParam*/ DIALOG_133 << 24, /*beh*/ bhvToadBasic),
        OBJECT(/*model*/ MODEL_TOAD,                       /*pos*/ -2727, 1464,     286,  /*angle*/ 0, 77, 0,   /*behParam*/ DIALOG_134 << 24, /*beh*/ bhvToadBasic),
        OBJECT(/*model*/ MODEL_TOAD,                       /*pos*/  2641, 4692,   -1318,  /*angle*/ 0, 225, 0,   /*behParam*/ 0, /*beh*/ bhvToadEvil),
        OBJECT(/*model*/ MODEL_NONE,            /*pos*/  294,   1305,  882,  /*angle*/ 0, 180, 0, /*behParam*/ 0x000A0000, /*beh*/ bhvWarps64),
        OBJECT(/*model*/ MODEL_NONE,            /*pos*/  0,  1240,   -7687,  /*angle*/ 0, 0, 0, /*behParam*/ 0x000C0000, /*beh*/ bhvWarps70),
        WARP_NODE(/*id*/ 0x0A, /*destLevel*/ LEVEL_BITDW, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ 0x0B, /*destLevel*/ LEVEL_BOWSER_1, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ 0x0C, /*destLevel*/ LEVEL_BITDW, /*destArea*/ 0x01, /*destNode*/ 0x0C, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ 0xF1, /*destLevel*/ LEVEL_BITDW, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*flags*/ WARP_NO_CHECKPOINT),
        JUMP_LINK(script_func_local_3),
        // JUMP_LINK(script_func_global_16),
        MACRO_OBJECTS(/*objList*/ bitdw_seg7_macro_objs),
        TERRAIN(/*terrainData*/ world_collision),
        SET_BACKGROUND_MUSIC(/*settingsPreset*/ 0x0000, /*seq*/ SEQ_LEVEL_WATER),
        TERRAIN_TYPE(/*terrainType*/ TERRAIN_WATER),
    END_AREA(),

    FREE_LEVEL_POOL(),
    MARIO_POS(/*area*/ 1, /*yaw*/ 180, /*pos*/ 294, 3000, 882),
    CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
    CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
    CLEAR_LEVEL(),
    SLEEP_BEFORE_EXIT(/*frames*/ 1),
    EXIT(),
};
