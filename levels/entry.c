#include <ultra64.h>
#include "sm64.h"
#include "segment_symbols.h"
#include "level_commands.h"

#include "levels/intro/header.h"

#include "make_const_nonconst.h"

const LevelScript level_script_entry[] = {
    INIT_LEVEL(),
    SLEEP(/*frames*/ 2),
    BLACKOUT(/*active*/ FALSE),
    SET_REG(/*value*/ 0),
    EXECUTE(/*seg*/ 0x14, /*script*/ _introSegmentRomStart, /*scriptEnd*/ _introSegmentRomEnd, /*entry*/ level_intro_entry_1),
    JUMP(/*target*/ level_script_entry),
};

const LevelScript level_script_entry_error_screen[] = {
    INIT_LEVEL(),
    SLEEP(2),
    BLACKOUT(FALSE),
    SET_REG(0),
    EXECUTE(0x14, _introSegmentRomStart, _introSegmentRomEnd, level_intro_entry_error_screen),
    JUMP(level_script_entry_error_screen),
};
