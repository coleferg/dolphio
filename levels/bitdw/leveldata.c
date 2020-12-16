#include <ultra64.h>
#include "sm64.h"
#include "surface_terrains.h"
#include "moving_texture_macros.h"
#include "level_misc_macros.h"
#include "macro_preset_names.h"
#include "special_preset_names.h"
#include "textures.h"
#include "dialog_ids.h"

#include "make_const_nonconst.h"
#include "levels/bitdw/texture.inc.c"
#include "levels/bitdw/areas/1/1/model.inc.c"
#include "levels/bitdw/areas/1/starting_platform/model.inc.c"
#include "levels/bitdw/areas/1/large_platform/model.inc.c"
#include "levels/bitdw/areas/1/wooden_bridge_and_fences/model.inc.c"
#include "levels/bitdw/areas/1/quartzy_path_1/model.inc.c"
#include "levels/bitdw/areas/1/quartzy_path_2/model.inc.c"
#include "levels/bitdw/areas/1/quartzy_path_fences/model.inc.c"
#include "levels/bitdw/areas/1/octogonal_platform/model.inc.c"
#include "levels/bitdw/areas/1/platform_with_hill/model.inc.c"
#include "levels/bitdw/areas/1/wooden_platform/model.inc.c"
#include "levels/bitdw/areas/1/platforms_and_tilting/model.inc.c"
#include "levels/bitdw/areas/1/platforms_and_tilting_2/model.inc.c"
#include "levels/bitdw/areas/1/quartz_crystal/model.inc.c"
#include "levels/bitdw/areas/1/staircase_slope_and_platform/model.inc.c"
#include "levels/bitdw/areas/1/track_for_pyramid_platforms/model.inc.c"
#include "levels/bitdw/areas/1/narrow_path_platform/model.inc.c"
#include "levels/bitdw/sliding_platform/model.inc.c"
#include "levels/bitdw/seesaw_platform/model.inc.c"
#include "levels/bitdw/square_platform/model.inc.c"
#include "levels/bitdw/ferris_wheel_axle/model.inc.c"
#include "levels/bitdw/ferris_platform/model.inc.c"
#include "levels/bitdw/collapsing_stairs_1/model.inc.c"
#include "levels/bitdw/collapsing_stairs_2/model.inc.c"
#include "levels/bitdw/collapsing_stairs_3/model.inc.c"
#include "levels/bitdw/collapsing_stairs_4/model.inc.c"
#include "levels/bitdw/collapsing_stairs_5/model.inc.c"
#include "levels/bitdw/areas/1/collision.inc.c"
#include "levels/bitdw/areas/1/macro.inc.c"
#include "levels/bitdw/sliding_platform/collision.inc.c"
#include "levels/bitdw/seesaw_platform/collision.inc.c"
#include "levels/bitdw/square_platform/collision.inc.c"
#include "levels/bitdw/ferris_wheel_axle/collision.inc.c"
#include "levels/bitdw/ferris_platform/collision.inc.c"
#include "levels/bitdw/collapsing_stairs_1/collision.inc.c"
#include "levels/bitdw/collapsing_stairs_2/collision.inc.c"
#include "levels/bitdw/collapsing_stairs_3/collision.inc.c"
#include "levels/bitdw/collapsing_stairs_4/collision.inc.c"
#include "levels/bitdw/collapsing_stairs_5/collision.inc.c"

// #include "levels/bitdw/areas/1/world/model.inc.c"
// #include "levels/bitdw/areas/1/world/collision.inc.c"
#include "levels/bitdw/leveldata.inc.c"
