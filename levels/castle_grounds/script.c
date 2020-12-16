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
#include "actors/group15.h"

#include "make_const_nonconst.h"
#include "levels/castle_grounds/header.h"

const LevelScript level_castle_grounds_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _castle_grounds_segment_7SegmentRomStart, _castle_grounds_segment_7SegmentRomEnd), 
	LOAD_MIO0(0x0A, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd), 
	LOAD_MIO0_TEXTURE(0x09, _outside_mio0SegmentRomStart, _outside_mio0SegmentRomEnd), 
	LOAD_MIO0(0x05, _group10_mio0SegmentRomStart, _group10_mio0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group10_geoSegmentRomStart, _group10_geoSegmentRomEnd), 
	LOAD_MIO0(0x06, _group15_mio0SegmentRomStart, _group15_mio0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group15_geoSegmentRomStart, _group15_geoSegmentRomEnd), 
	LOAD_MIO0(0x08, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	LOAD_MODEL_FROM_GEO(MODEL_COURTYARD_SPIKY_TREE, spiky_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_WATER_RING, water_ring_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_TOAD, toad_geo), 

	AREA(1, castle_grounds_area_1),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0D, LEVEL_BITDW, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_CASTLE_GROUNDS, 0x01, 0x0B, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0C, LEVEL_BITDW, 0x01, 0x0E, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0E, LEVEL_BITFS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 290, 7442, -4220, 0, 0, 0, 0x000B0000, bhvSpinAirborneWarp),
		OBJECT(MODEL_NONE, 15467, 1439, 12120, 0, 0, 0, 0xCC0E0000, bhvWarp),
		OBJECT(MODEL_NONE, 14548, 8596, -14757, 0, -48, 0, 0x000A0000, bhvSpinAirborneWarp),
		OBJECT(MODEL_NONE, 15465, 8407, -15656, 0, -45, 0, 0x200C0000, bhvWarp),
		OBJECT(MODEL_NONE, -8758, 4228, -1664, 0, 0, 0, 0x0, bhvJetStreamRingSpawner),
		OBJECT(MODEL_NONE, 9566, 7184, -8460, 0, 0, 0, 0x0, bhvJetStreamRingSpawner),
		OBJECT(MODEL_NONE, 9566, 7687, -8460, 0, 0, 0, 0x0, bhvJetStreamRingSpawner),
		OBJECT(MODEL_NONE, 246, 8330, -1430, 0, 0, 0, 0x0, bhvJetStreamRingSpawner),
		OBJECT(MODEL_NONE, 9566, 8129, -8460, 0, 0, 0, 0x0, bhvJetStreamRingSpawner),
		OBJECT(MODEL_NONE, 9566, 8519, -8460, 0, 0, 0, 0x0, bhvJetStreamRingSpawner),
		OBJECT(MODEL_NONE, 130, 7556, -3652, -93, 0, 90, 0x0, bhvJetStreamRingSpawner),
		OBJECT(MODEL_NONE, 5791, 9821, 4969, 0, 0, 90, 0x0, bhvJetStreamRingSpawner),
		OBJECT(MODEL_NONE, 5852, 11319, 4837, 0, 0, 90, 0x0, bhvJetStreamRingSpawner),
		OBJECT(MODEL_NONE, 6300, 10711, 4879, 0, 0, 0, 0x0, bhvJetStreamRingSpawner),
		OBJECT(MODEL_NONE, 11011, 3761, -8544, 0, 0, 0, 0x0, bhvJetStreamRingSpawner),
		OBJECT(MODEL_NONE, 11011, 6340, -8544, 0, 0, 0, 0x0, bhvJetStreamRingSpawner),
		OBJECT(MODEL_NONE, 7918, 3761, -11592, 0, 0, 0, 0x0, bhvJetStreamRingSpawner),
		OBJECT(MODEL_NONE, 7918, 6340, -11592, 0, 0, 0, 0x0, bhvJetStreamRingSpawner),
		OBJECT(MODEL_NONE, 11011, 5057, -8544, 0, 0, 0, 0x0, bhvJetStreamRingSpawner),
		OBJECT(MODEL_NONE, 7918, 5057, -11592, 0, 0, 0, 0x0, bhvJetStreamRingSpawner),
		OBJECT(MODEL_NONE, 861, 9276, 1810, -74, 0, 90, 0x0, bhvJetStreamRingSpawner),
		OBJECT(MODEL_NONE, 1621, 9606, 3323, -61, 0, 90, 0x0, bhvJetStreamRingSpawner),
		OBJECT(MODEL_NONE, 2974, 9772, 4550, -41, 0, 90, 0x0, bhvJetStreamRingSpawner),
		TERRAIN(castle_grounds_area_1_collision),
		MACRO_OBJECTS(castle_grounds_area_1_Area_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_GRASS),
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(1, 0, 0, 0, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
