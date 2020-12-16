#ifndef SCENES_H
#define SCENES_H

#include <PR/ultratypes.h>

#include "engine/graph_node.h"

#define SCENE_DEFAULT    0x0001
#define SCENE_WATER_TUBE 0x0002

extern u8 gCurrentScene;
extern s16 gCurrentTubeAngle[3];

#endif