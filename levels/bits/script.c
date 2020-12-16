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

#include "make_const_nonconst.h"
#include "levels/bits/header.h"

const LevelScript level_bits_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _bits_segment_7SegmentRomStart, _bits_segment_7SegmentRomEnd), 
	LOAD_MIO0(0x0A, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd), 
	LOAD_MIO0_TEXTURE(0x09, _sky_mio0SegmentRomStart, _sky_mio0SegmentRomEnd), 
	LOAD_MIO0(0x06, _group15_mio0SegmentRomStart, _group14_mio0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group15_geoSegmentRomStart, _group14_geoSegmentRomEnd), 
	LOAD_MIO0(0x08, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_16), 
	JUMP_LINK(script_func_global_1), 

	AREA(1, bits_area_1),
		WARP_NODE(0x0A, LEVEL_BITS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BITS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BITS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 0, 5565, 15809, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, 0, 0, 5565, 15809),
		TERRAIN(bits_area_1_collision),
		MACRO_OBJECTS(bits_area_1_Area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_KOOPA_ROAD),
		TERRAIN_TYPE(TERRAIN_STONE),
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 0, 5565, 15809),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
