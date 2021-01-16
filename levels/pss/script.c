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
#include "levels/pss/header.h"

const LevelScript level_pss_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _pss_segment_7SegmentRomStart, _pss_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _mountain_yay0SegmentRomStart, _mountain_yay0SegmentRomEnd), 
	LOAD_YAY0(0x06, _group15_yay0SegmentRomStart, _group15_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group15_geoSegmentRomStart, _group15_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_YAY0(0xb, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	LOAD_MODEL_FROM_GEO(MODEL_WATER_RING, water_ring_geo), 

	AREA(1, pss_area_1),
		WARP_NODE(0x0A, LEVEL_PSS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_PSS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_PSS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_PSS, 0x01, 0x0B, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_JELLYCUBE, 12459, 200, 0, 0, 0, 0, 0x0, bhvJellycube),
		OBJECT(MODEL_JELLYCUBE, 11136, 200, 0, 0, 0, 0, 0x0, bhvJellycube),
		OBJECT(MODEL_JELLYCUBE, 1263, 1916, 0, 0, 0, 0, 0x0, bhvJellycube),
		OBJECT(MODEL_JELLYCUBE, 8048, 200, 0, 0, 0, 0, 0x0, bhvJellycube),
		OBJECT(MODEL_JELLYCUBE, 11138, 1916, 0, 0, 0, 0, 0x0, bhvJellycube),
		OBJECT(MODEL_JELLYCUBE, 8869, 1916, 0, 0, 0, 0, 0x0, bhvJellycube),
		OBJECT(MODEL_JELLYCUBE, 4873, 1916, 0, 0, 0, 0, 0x0, bhvJellycube),
		OBJECT(MODEL_NONE, 1263, 3348, 0, 0, 0, 0, 0x0, bhvJetStreamRingSpawner),
		OBJECT(MODEL_NONE, 1263, 4816, 0, 0, 0, 0, 0x0, bhvJetStreamRingSpawner),
		OBJECT(MODEL_NONE, 14769, 200, 0, 0, 0, 0, 0x000B0000, bhvInstantActiveWarp),
		OBJECT(MODEL_NONE, 14769, 200, 0, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, 0, 14769, 200, 0),
		TERRAIN(pss_area_1_collision),
		MACRO_OBJECTS(pss_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_UNDERGROUND),
		TERRAIN_TYPE(TERRAIN_WATER),
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 14769, 200, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
