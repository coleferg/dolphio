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
#include "actors/group13.h"
#include "actors/group15.h"

#include "make_const_nonconst.h"
#include "levels/bowser_1/header.h"

const LevelScript level_bowser_1_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _bowser_1_segment_7SegmentRomStart, _bowser_1_segment_7SegmentRomEnd), 
	LOAD_MIO0(0x0A, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd), 
	LOAD_MIO0(0x06, _group15_mio0SegmentRomStart, _group15_mio0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group15_geoSegmentRomStart, _group15_geoSegmentRomEnd), 
	LOAD_MIO0(0x08, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_16), 
	LOAD_MODEL_FROM_GEO(MODEL_WATER_RING, water_ring_geo), 

	AREA(1, bowser_1_area_1),
		WARP_NODE(0xF0, LEVEL_BITDW, 0x01, 0x24, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BITDW, 0x01, 0x25, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0A, LEVEL_BOWSER_1, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_BOWSER_1, 0x01, 0x0B, WARP_NO_CHECKPOINT),
		INSTANT_WARP(3, 0x02, 0, 0, 0),
		WARP_NODE(0x05, LEVEL_BITS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_RED_FLAME, 581, 417, 13703, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, -531, 417, 13703, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, -272, 1197, 15263, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, 596, 1694, 16001, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, 1935, 2027, 16271, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, 3446, 2361, 16417, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, 3470, 2329, 15282, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_NONE, 3674, 2404, 15858, 0, -90, 0, 0x000A0000, bhvSwimmingWarp),
		OBJECT(MODEL_RED_FLAME, 2038, -1169, 4727, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_TOAD, 2260, -1194, 4858, 0, -125, 0, DIALOG_112 << 24, bhvToadBasic),
		OBJECT(MODEL_NONE, 7, 357, 5024, 0, 0, 0, 0x0, bhvJetStreamRingSpawner),
		OBJECT(MODEL_NONE, 7, -171, 5024, 0, 0, 0, 0x0, bhvJetStreamRingSpawner),
		OBJECT(MODEL_NONE, 1, -151, 10619, 0, 0, 0, 0x0, bhvJetStreamRingSpawner),
		OBJECT(MODEL_NONE, 7, -1244, 5024, 0, 0, 0, 0x0, bhvJetStreamRingSpawner),
		OBJECT(MODEL_NONE, 24, 2926, -16328, 0, 0, 0, 0x0A050000, bhvWarp),
		OBJECT(MODEL_SLIDING_DOOR, 9, 2926, -14188, 0, 0, 0, 0x1 << 16 << 5, bhvSlidingDoor),
		OBJECT(MODEL_SLIDING_DOOR, 9, 2926, -14188, 0, -180, 0, 0x1 << 16 << 5, bhvSlidingDoor),
		OBJECT(MODEL_NONE, -47, 1915, 2542, 0, 180, 0, 0x000B0000, bhvSpinAirborneWarp),
		OBJECT(MODEL_TOAD, -3236, 2051, -2064, 0, 55, 0, 0x4, bhvToadEvil),
		OBJECT(MODEL_TOAD, -3414, 2065, -1579, 0, 73, 0, 0x4, bhvToadEvil),
		OBJECT(MODEL_RED_FLAME, -5787, -848, -2028, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, -3565, -1509, -2148, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, -5787, -848, -1190, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, -3563, -1509, -1075, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, -8510, -350, 196, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, -7814, -350, -1147, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, -6980, -485, -1935, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_NONE, 107, 3683, -9150, -51, 0, 90, 0x1 << 16, bhvGoldRingSpawner),
		OBJECT(MODEL_NONE, -801, 4212, -10177, -90, 0, 90, 0x2 << 16, bhvGoldRingSpawner),
		OBJECT(MODEL_NONE, -366, 4830, -11298, 60, 0, 90, 0x4 << 16, bhvGoldRingSpawner),
		OBJECT(MODEL_NONE, 439, 5308, -12113, -90, 0, 90, 0x8 << 16, bhvGoldRingSpawner),
		OBJECT(MODEL_NONE, 0, 5641, -13301, -90, 0, 90, 0x10 << 16, bhvGoldRingSpawner),
		OBJECT(MODEL_NONE, 775, 2882, -8202, 0, 0, 0, 0x0, bhvJetStreamRingSpawner),
		OBJECT(MODEL_NONE, 31, 6273, -14642, 0, 0, 0, 0x1 << 16 << 5, bhvGoldRingStar),
		OBJECT(MODEL_NONE, -746, 573, 912, -53, 0, 90, 0x0, bhvJetStreamRingSpawner),
		OBJECT(MODEL_NONE, -1417, 752, 60, -57, 0, 90, 0x03000000, bhvJetStreamRingSpawner),
		OBJECT(MODEL_NONE, -2984, -1591, -1574, 0, 0, 0, 0x03000000, bhvJetStreamRingSpawner),
		OBJECT(MODEL_NONE, -774, 1059, -1926, 29, 0, 90, 0x0, bhvJetStreamRingSpawner),
		OBJECT(MODEL_NONE, 619, 1182, -2297, 0, 0, 90, 0x0, bhvJetStreamRingSpawner),
		OBJECT(MODEL_NONE, 1796, 1444, -2072, -8, 0, 90, 0x0, bhvJetStreamRingSpawner),
		OBJECT(MODEL_NONE, 3048, 2242, -1998, 0, 0, 0, 0x0, bhvJetStreamRingSpawner),
		OBJECT(MODEL_NONE, 3048, 2792, -1998, 0, 0, 0, 0x0, bhvJetStreamRingSpawner),
		OBJECT(MODEL_NONE, 2083, 2343, -4706, 0, 0, 0, 0x0, bhvJetStreamRingSpawner),
		OBJECT(MODEL_NONE, 1512, 2538, -6568, 98, 0, 90, 0x0, bhvJetStreamRingSpawner),
		TERRAIN(bowser_1_area_1_collision),
		ROOMS(bowser_1_area_1_collision_rooms),
		MACRO_OBJECTS(bowser_1_area_1_CaveLevelArea_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_UNDERGROUND),
		TERRAIN_TYPE(TERRAIN_STONE),
	END_AREA(),

	AREA(2, bowser_1_area_2),
		INSTANT_WARP(2, 0x01, 0, 0, 0),
		WARP_NODE(0xF0, LEVEL_BITDW, 0x01, 0x24, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BITDW, 0x01, 0x25, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, -7625, -1230, 6154, 0, 0, 0, 0x0, bhvToadCultSpawner),
		OBJECT(MODEL_RED_FLAME, -7625, -932, 6154, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, -7551, -802, 6193, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, -7551, -695, 6193, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, -7513, -932, 6212, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, -5787, -848, -2028, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, -5787, -848, -1190, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, -8510, -350, 196, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, -7814, -350, -1147, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, -6980, -485, -1935, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, -7117, -416, -649, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, -6296, 168, 3617, 0, 0, 0, 0x00000000, bhvFlame),
		TERRAIN(bowser_1_area_2_collision),
		MACRO_OBJECTS(bowser_1_area_2_CaveLevelArea2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_UNDERGROUND),
		TERRAIN_TYPE(TERRAIN_STONE),
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(1, 0, 0, 0, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
