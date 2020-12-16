#ifndef MARIO_ACTIONS_AIRBORNE_H
#define MARIO_ACTIONS_AIRBORNE_H

#include <PR/ultratypes.h>

#include "types.h"

s32 mario_execute_airborne_action(struct MarioState *m);
void set_dolphio_grav_power_from_bounce(struct MarioState *m, s16 floorHeight, u8 powerLevel);
f32 get_g_height_with_curve(f32 height);

#endif // MARIO_ACTIONS_AIRBORNE_H
