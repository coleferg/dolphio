#include "types.h"
#include "include/segment_symbols.h"
#include "memory.h"
#include "engine/math_util.h"
#include "src/engine/behavior_script.h"
#include "game/area.h"
#include "level_table.h"
#include "texscroll.h"

#ifdef TARGET_N64
#define SCROLL_CONDITION(condition) condition
#else
#define SCROLL_CONDITION(condition) 1
#endif



#include "src/game/texscroll/bitdw_texscroll.inc.c"
#include "src/game/texscroll/castle_grounds_texscroll.inc.c"
#include "src/game/texscroll/bowser_1_texscroll.inc.c"
#include "src/game/texscroll/bitfs_texscroll.inc.c"
#include "src/game/texscroll/bits_texscroll.inc.c"
#include "src/game/texscroll/group0_texscroll.inc.c"
#include "src/game/texscroll/pss_texscroll.inc.c"
void scroll_textures() {
	switch(gCurrLevelNum) {
        case LEVEL_CASTLE_GROUNDS:
            if (gCurrAreaIndex == 1) {
                scroll_textures_castle_grounds();
            }
            break;
        case LEVEL_BOWSER_1:
            if (gCurrAreaIndex == 1) {
                scroll_textures_bowser_1();
            }
            break;
        case LEVEL_BITDW:
            if (gCurrAreaIndex == 1) {
                scroll_textures_bitdw();
            }
            break;
        case LEVEL_BITFS:
            if (gCurrAreaIndex == 1) {
                scroll_textures_bitfs();
            }
            break;
        case LEVEL_BITS:
            if (gCurrAreaIndex == 1) {
                scroll_textures_bits();
            }
            break;
    }

#if FALSE

	

	
	
	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_bitfs_segment_7SegmentRomStart)) {
		scroll_textures_bitfs();
	}

	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_bitdw_segment_7SegmentRomStart)) {
		scroll_textures_bitdw();
	}
	
	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_castle_grounds_segment_7SegmentRomStart)) {
		scroll_textures_castle_grounds();
	}

	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_bowser_1_segment_7SegmentRomStart)) {
		scroll_textures_bowser_1();
	}

	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_bits_segment_7SegmentRomStart)) {
		scroll_textures_bits();
	}
#endif
	if(SCROLL_CONDITION(sSegmentROMTable[0x4] == (uintptr_t)_group0_mio0SegmentRomStart)) {
		scroll_textures_group0();
	}

	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_pss_segment_7SegmentRomStart)) {
		scroll_textures_pss();
	}

}
