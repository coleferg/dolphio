#include <ultra64.h>

#include "sm64.h"
#include "behavior_data.h"
#include "object_fields.h"
#include "types.h"
#include "game/mario_actions_airborne.h"
#include "game/object_helpers.h"
#include "game/mario.h"
#include "game/object_list_processor.h"
#include "game/level_update.h"
#include "game/scenes.h"

#define o gCurrentObject
#define scene gCurrentScene


void scene_water_tube(void) {
    if (scene != SCENE_WATER_TUBE) {
        cur_obj_change_action(scene);
        return;
    }
    vec3s_copy(gCurrentTubeAngle, o->header.gfx.angle);

}

/* Scenes
    SCENE_DEFAULT
    SCENE_WATER_TUBE
*/
void scene_loop(void) {
    if (o->header.gfx.node.flags & 1) {
        switch(scene) {
            case SCENE_WATER_TUBE:
            case SCENE_DEFAULT:
            default:
                return;
        }
    }
}

void init_scene(void) {
    o->oAction = o->oBehParams >> 16;
    gCurrentScene = o->oAction;
}