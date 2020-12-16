#include <PR/ultratypes.h>

#include "area.h"
#include "engine/math_util.h"
#include "game_init.h"
#include "gfx_dimensions.h"
#include "main.h"
#include "memory.h"
#include "print.h"
#include "rendering_graph_node.h"
#include "shadow.h"
#include "sm64.h"
#include "scenes.h"

u8 gCurrentScene = SCENE_DEFAULT;

s16 gCurrentTubeAngle[3] = { 0, 0, 0 };

void change_scene(u8 scene) {
    gCurrentScene = scene;
}