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
#include "levels/bitdw/header.h"

const LevelScript level_bitdw_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _bitdw_segment_7SegmentRomStart, _bitdw_segment_7SegmentRomEnd), 
	LOAD_MIO0(0x0B, _effect_mio0SegmentRomStart, _effect_mio0SegmentRomEnd), 
	LOAD_MIO0(0x0A, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd), 
	LOAD_MIO0_TEXTURE(0x09, _sky_mio0SegmentRomStart, _sky_mio0SegmentRomEnd), 
	LOAD_MIO0(0x05, _group13_mio0SegmentRomStart, _group13_mio0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group13_geoSegmentRomStart, _group13_geoSegmentRomEnd), 
	LOAD_MIO0(0x06, _group15_mio0SegmentRomStart, _group15_mio0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group15_geoSegmentRomStart, _group15_geoSegmentRomEnd), 
	LOAD_MIO0(0x08, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_16), 

	AREA(1, bitdw_area_1),
		WARP_NODE(0x0A, LEVEL_BITDW, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_BOWSER_1, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0C, LEVEL_BITDW, 0x01, 0x0C, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BITDW, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BITDW, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0D, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0E, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x24, LEVEL_BOWSER_1, 0x01, 0x24, WARP_NO_CHECKPOINT),
		WARP_NODE(0x25, LEVEL_BOWSER_1, 0x01, 0x25, WARP_NO_CHECKPOINT),
		WARP_NODE(0x10, LEVEL_BITFS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0F, LEVEL_PSS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, -5777, 1526, -2873, 0, 0, 0, 0x000F0000, bhvWarp),
		OBJECT(MODEL_NONE, -6334, 999, -748, 0, 0, 0, 0x00100000, bhvWarp),
		OBJECT(MODEL_NONE, -18, 1243, -8075, 0, -180, 0, 0x00250000, bhvLaunchDeathWarp),
		OBJECT(MODEL_NONE, -18, 1243, -8075, 0, -180, 0, 0x00240000, bhvLaunchStarCollectWarp),
		OBJECT(MODEL_NONE, 13, 1217, -8967, 0, -180, 0, 0x320B0000, bhvWarp),
		OBJECT(MODEL_NONE, 272, 1464, 739, 0, -180, 0, 0x000A0000, bhvDeathWarp),
		OBJECT(MODEL_NONE, -1618, 4774, -8445, 0, 0, 0, 0x000E0000, bhvInstantActiveWarp),
		OBJECT(MODEL_NONE, -1605, 4780, -9425, 0, 0, 0, 0x240D6000, bhvWarp),
		MARIO_POS(0x01, -180, 272, 1464, 739),
		OBJECT(MODEL_TOAD, 733, 1257, 333, 0, -180, 0, DIALOG_134 << 24, bhvToadBasic),
		OBJECT(MODEL_JELLYCUBE, 1180, 1251, -5793, 0, 0, 0, 0x0, bhvJellycube),
		OBJECT(MODEL_NONE, 998, 1097, -5913, 0, 0, 0, 0x00000000, bhvJetStreamRingSpawner),
		OBJECT(MODEL_NONE, 1188, 3032, -5352, 0, 0, 0, 0x00000000, bhvJetStreamRingSpawner),
		OBJECT(MODEL_NONE, 2073, 4894, -4395, 90, 0, -90, 0x00000000, bhvJetStreamRingSpawner),
		OBJECT(MODEL_NONE, 2073, 4894, -2496, 90, 0, -90, 0x00000000, bhvJetStreamRingSpawner),
		OBJECT(MODEL_NONE, 530, 4898, -1414, 0, 0, 0, 0x00000000, bhvJetStreamRingSpawner),
		OBJECT(MODEL_NONE, -3314, 5374, -2482, 0, 0, 0, 0x00000000, bhvJetStreamRingSpawner),
		OBJECT(MODEL_NONE, -3314, 6062, -3242, 0, 0, 0, 0x00000000, bhvJetStreamRingSpawner),
		OBJECT(MODEL_NONE, -3314, 6629, -3242, 0, 0, 0, 0x00000000, bhvJetStreamRingSpawner),
		OBJECT(MODEL_NONE, -2103, 5966, -4044, 0, 0, 0, 0x00000000, bhvJetStreamRingSpawner),
		OBJECT(MODEL_NONE, 1085, 3724, -5300, 0, 0, 0, 0x00000000, bhvJetStreamRingSpawner),
		OBJECT(MODEL_NONE, -2098, 5430, -595, 0, 0, -90, 0x00000000, bhvJetStreamRingSpawner),
		TERRAIN(bitdw_area_1_collision),
		MACRO_OBJECTS(bitdw_area_1_area_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_WATER),
		TERRAIN_TYPE(TERRAIN_WATER),
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, -180, 272, 1464, 739),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
