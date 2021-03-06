#include <ultra64.h>
#include "game/level_update.h"
#include "game/area.h"
#include "game/memory.h"
#include "game/game_init.h"
#include "level_table.h"

#define PACK_TILESIZE(w, d) ((w << 2) + d)

typedef struct {
    int cmd:8;
    int s:12;
    int t:12;
    int pad:4;
    int i:4;
    int u:12;
    int v:12;
} SetTileSize;

extern Gfx mat_castle_grounds_mainWaterFallMat[];
extern Gfx mat_castle_grounds_riverWaterMat[];
extern Gfx mat_castle_grounds_headWaterMat[];
extern Gfx mat_castle_grounds_headWaterFallMat[];
extern Gfx mat_castle_grounds_lakeWaterMat[];
extern Gfx mat_bowser_1_waterMaterial[];
extern Gfx mat_bowser_1_waterfallMaterial[];
extern Gfx mat_world_waterMaterial[];
extern Gfx mat_world_waterfallMaterial[];
extern Gfx mat_bowser_1_slideWaterMat[];
extern Gfx mat_bowser_1_waterCenterMat[];
extern Gfx mat_bowser_1_warpMaterial[];
extern Gfx mat_bowser_1_deathPlaneMaterial[];
extern Gfx mat_bitfs_riverMaterial[];

/*
 * Scrolling texture system by red.
 * This file comes with Bob-Omb Battlefield as an example.
 */

/*
 * Parameters:
 * dl - Which display list to modify (make sure it's passed by reference).
 *
 * cmd - Location of the gsDPSetTileSize command in the display list.
 * In Bob-Omb Battlefield, it is 12.
 *
 * s/t - How much to scroll.
 */

static void shift_s(Gfx *dl, u32 cmd, u16 s) {
    SetTileSize *tile = segmented_to_virtual(dl);
    tile += cmd;
    tile->s += s;
    tile->u += s;
}

static void shift_t(Gfx *dl, u32 cmd, u16 t) {
    SetTileSize *tile = segmented_to_virtual(dl);
    tile += cmd;
    tile->t += t;
    tile->v += t;
}

/**
 * Main scrolling texture function. Call this every frame.
 * Add an entry to the switch (and make sure it's appropiate for the area you want it
 * to be active in, using another switch).
 */

void rgfx_update_scroll() {
    // switch(gCurrLevelNum) {
    //     case LEVEL_CASTLE_GROUNDS:
    //     if (gCurrAreaIndex == 1) {
    //         shift_t(&mat_castle_grounds_mainWaterFallMat, 11, PACK_TILESIZE(1, 1));
    //         shift_s(&mat_castle_grounds_riverWaterMat, 11, PACK_TILESIZE(0, 1));
    //         shift_s(&mat_castle_grounds_headWaterMat, 11, PACK_TILESIZE(0, 1));
    //         shift_t(&mat_castle_grounds_headWaterFallMat, 11, PACK_TILESIZE(0, 2));
    //         shift_s(&mat_castle_grounds_lakeWaterMat, 11, PACK_TILESIZE(0, 1));
    //     }
    //     break;
    //     case LEVEL_BOWSER_1:
    //     if (gCurrAreaIndex == 1) {
    //         shift_s(&mat_bowser_1_waterMaterial, 11, PACK_TILESIZE(0, 1));
    //         shift_t(&mat_bowser_1_waterfallMaterial, 18, PACK_TILESIZE(0, 3));
    //         shift_t(&mat_bowser_1_slideWaterMat, 11, PACK_TILESIZE(0, 3));
    //         shift_t(&mat_bowser_1_waterCenterMat, 11, PACK_TILESIZE(0, 2));
    //         shift_t(&mat_bowser_1_deathPlaneMaterial, 11, PACK_TILESIZE(0, 1));
    //         shift_t(&mat_bowser_1_warpMaterial, 11, PACK_TILESIZE(0, 1));
    //     }
    //     break;
    //     case LEVEL_BITDW:
    //     if (gCurrAreaIndex == 1) {
    //         shift_t(&mat_world_waterMaterial, 12, PACK_TILESIZE(0, 1));
    //         shift_s(&mat_world_waterfallMaterial, 12, PACK_TILESIZE(0, 4));
    //     }
    //     case LEVEL_BITFS:
    //     if (gCurrAreaIndex == 1) {
    //         shift_s(&mat_bitfs_riverMaterial, 18, PACK_TILESIZE(0, 3));
    //     }
    // }
}
