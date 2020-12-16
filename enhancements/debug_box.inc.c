#include <ultra64.h>

#include "sm64.h"
#include "game/game_init.h"
#include "game/geo_misc.h"
#include "engine/math_util.h"

#include "debug_box.h"

/**
 * @file debug_box.inc.c
 * Draws 3D boxes for debugging purposes.
 *
 * How to use:
 *
 * In area.c, add this to the list of includes:
 *
 * #include "enhancements/debug_box.inc.c"
 *
 * Then in render_game() in the same file, add a call to render_debug_boxes():
 *
 * void render_game(void) {
 *    if (gCurrentArea != NULL && !gWarpTransition.pauseRendering) {
 *        geo_process_root(...);
 *
 *        render_debug_boxes(); // add here
 *
 *        gSPViewport(...);
 *        gDPSetScissor(...);
 *    //...
 * 
 * Now just call debug_box() whenever you want to draw one!
 *
 * debug_box by default takes two arguments: a center and bounds vec3f.
 * This will draw a box starting from the point (center - bounds) to (center + bounds).
 *
 * Use debug_box_rot to draw a box rotated in the xz-plane.
 *
 * If you want to draw a box by specifying min and max points, use debug_box_pos() instead.
 */

/**
 * Internal struct containing box info
 */
struct DebugBox {
    Vec3s center;
    Vec3s bounds;
    s16 yaw;
};

struct DebugBox *sBoxes[MAX_DEBUG_BOXES];
s16 sNumBoxes = 0;

extern Mat4 gMatStack[32]; //XXX: Hack

/**
 * The debug boxes' transparency
 */
#define DBG_BOX_ALPHA 0x7F
/**
 * The debug boxes' color
 */
#define DBG_BOX_COL 0xFF, 0x00, 0x00, DBG_BOX_ALPHA

/**
 * Sets up the RCP for drawing the boxes
 */
static const Gfx dl_debug_box_begin[] = {
    gsDPPipeSync(),
#if DBG_BOX_ALPHA < 0xFF
    gsDPSetRenderMode(G_RM_ZB_XLU_SURF, G_RM_NOOP2),
#else
    gsDPSetRenderMode(G_RM_ZB_OPA_SURF, G_RM_NOOP2),
#endif
    gsSPClearGeometryMode(G_LIGHTING | G_CULL_BACK),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH),
    gsSPTexture(0, 0, 0, 0, G_OFF),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsSPEndDisplayList(),
};

/**
 * Actually draws the box
 */
static const Gfx dl_debug_draw_box[] = {
    gsSP2Triangles( 0,  1,  2, 0x0,  2,  1,  3, 0x0),
    gsSP2Triangles( 2,  3,  6, 0x0,  6,  3,  7, 0x0),

    gsSP2Triangles( 4,  0,  2, 0x0,  2,  6,  4, 0x0),
    gsSP2Triangles( 1,  5,  3, 0x0,  3,  5,  7, 0x0),
    
    gsSP2Triangles( 1,  0,  4, 0x0,  1,  4,  5, 0x0),
    gsSP2Triangles( 5,  4,  6, 0x0,  5,  6,  7, 0x0),

    gsSPEndDisplayList(),
};

/**
 * Adds a box to the list to be rendered this frame.
 *
 * If there are already MAX_DEBUG_BOXES boxes, does nothing.
 */
static void append_debug_box(Vec3f center, Vec3f bounds, s16 yaw)
{
    if (sNumBoxes >= MAX_DEBUG_BOXES ||
       (sBoxes[sNumBoxes] = mem_pool_alloc(gEffectsMemoryPool, sizeof(struct DebugBox))) == NULL) {
        return;
    }

    vec3f_to_vec3s(sBoxes[sNumBoxes]->center, center);
    vec3f_to_vec3s(sBoxes[sNumBoxes]->bounds, bounds);

    sBoxes[sNumBoxes]->yaw = yaw;

    ++sNumBoxes;
}

/**
 * Draws a debug box from (center - bounds) to (center + bounds)
 * To draw a rotated box, use debug_box_rot()
 *
 * @see debug_box_rot()
 */
void debug_box(Vec3f center, Vec3f bounds)
{
    append_debug_box(center, bounds, 0);
}

/**
 * Draws a debug box from (center - bounds) to (center + bounds), rotating it by `yaw`
 */
void debug_box_rot(Vec3f center, Vec3f bounds, s16 yaw)
{
    append_debug_box(center, bounds, yaw);
}

/**
 * Draws a debug box from pMin to pMax
 * To draw a rotated box this way, use debug_box_pos_rot()
 *
 * @see debug_box_pos_rot()
 */
void debug_box_pos(Vec3f pMin, Vec3f pMax)
{
    debug_box_pos_rot(pMin, pMax, 0);
}

/**
 * Draws a debug box from pMin to pMax, rotating it in the xz-plane by `yaw`
 */
void debug_box_pos_rot(Vec3f pMin, Vec3f pMax, s16 yaw)
{
    Vec3f center, bounds;

    bounds[0] = pMax[0] - pMin[0] / 2.0f;
    bounds[1] = pMax[1] - pMin[1] / 2.0f;
    bounds[2] = pMax[2] - pMin[2] / 2.0f;

    center[0] = pMin[0] + bounds[0];
    center[1] = pMin[1] + bounds[1];
    center[2] = pMin[2] + bounds[2];

    append_debug_box(center, bounds, yaw);
}

static void render_box(struct DebugBox *box)
{
    Vtx *verts = alloc_display_list(8 * sizeof(Vtx));
    Mtx *translate;
    Mtx *rotate;
    Mtx *translateback;
    s32 x0 = box->center[0],
        y0 = box->center[1],
        z0 = box->center[2];

    s32 xb = box->bounds[0],
        yb = box->bounds[1],
        zb = box->bounds[2];

    if (verts != NULL) {
        if (box->yaw != 0) {
            // Translate to the origin, rotate, then translate back, effectively rotating the box about
            // its center
            translate =     alloc_display_list(sizeof(Mtx));
            rotate =        alloc_display_list(sizeof(Mtx));
            translateback = alloc_display_list(sizeof(Mtx));

            guTranslate(translate, box->center[0],  box->center[1],  box->center[2]);
            guRotate(rotate, box->yaw / (float)0x10000 * 360.0f, 0, 1.0f, 0);
            guTranslate(translateback, -box->center[0], -box->center[1], -box->center[2]);

            gSPMatrix(gDisplayListHead++, translate,     G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_PUSH);
            gSPMatrix(gDisplayListHead++, rotate,        G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_NOPUSH);
            gSPMatrix(gDisplayListHead++, translateback, G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_NOPUSH);
        }
        
#define DBG_BOX_VTX(i, x, y, z) make_vertex(verts, i, x, y, z, 0, 0, DBG_BOX_COL)
        DBG_BOX_VTX(0, x0 - xb, y0 + yb, z0 - zb);
        DBG_BOX_VTX(1, x0 + xb, y0 + yb, z0 - zb);
        DBG_BOX_VTX(2, x0 - xb, y0 - yb, z0 - zb);
        DBG_BOX_VTX(3, x0 + xb, y0 - yb, z0 - zb);
        DBG_BOX_VTX(4, x0 - xb, y0 + yb, z0 + zb);
        DBG_BOX_VTX(5, x0 + xb, y0 + yb, z0 + zb);
        DBG_BOX_VTX(6, x0 - xb, y0 - yb, z0 + zb);
        DBG_BOX_VTX(7, x0 + xb, y0 - yb, z0 + zb);
#undef DBG_BOX_VTX
        
        gSPVertex(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(verts), 8, 0);

        gSPDisplayList(gDisplayListHead++, dl_debug_draw_box);

        if (box->yaw != 0) {
            gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
        }
    }
}

void render_debug_boxes()
{
    s32 i;
    Mtx *mtx;

    if (sNumBoxes == 0) {
        return;
    }

    mtx = alloc_display_list(sizeof(Mtx));
    if (mtx == NULL) {
        for (i = 0; i < sNumBoxes; ++i) {
            mem_pool_free(gEffectsMemoryPool, sBoxes[i]);
        }
        sNumBoxes = 0;
        return;
    }

    //XXX: This is hacky. Ths camera's look-at matrix is stored in gMatStack[1], so this is a simple way
    //     of using it without reconstructing the matrix.
    mtxf_to_mtx(mtx, gMatStack[1]);
    gSPMatrix(gDisplayListHead++, mtx, G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPDisplayList(gDisplayListHead++, dl_debug_box_begin);

    for (i = 0; i < sNumBoxes; ++i) {
        render_box(sBoxes[i]);
        mem_pool_free(gEffectsMemoryPool, sBoxes[i]);
    }

    sNumBoxes = 0;
}
