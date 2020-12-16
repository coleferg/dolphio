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


enum JellycubeStates {
    CUBE_IDLE,
    CUBE_ENTER,
    CUBE_INSIDE,
    CUBE_EXIT
};

enum JellyAnims {
    CUBE_ANIM_WIGGLE,
    CUBE_ANIM_SPIN
};

enum JellyInsideStates {
    JELLY_INSIDE_IDLE,
    JELLY_INSIDE_A_BUTTON,
    JELLY_INSIDE_B_BUTTON
};

#define JELLY_EXIT_LENGTH 30

#define o gCurrentObject

static f32 calc_thing(f32 srcPx, f32 srcPy, f32 p1x, f32 p1y, f32 p2x, f32 p2y)
{
    return (srcPx - p2x) * (p1y - p2y) - (p1x - p2x) * (srcPy - p2y);
}

s8 isInRect(Vec3f srcPos, Vec3f v1, Vec3f v2, Vec3f v3)
{
    f32 d1, d2, d3;
    s8 has_neg, has_pos;

    d1 = calc_thing(srcPos[0], srcPos[2], v1[0], v1[2], v2[0], v2[2]);
    d2 = calc_thing(srcPos[0], srcPos[2], v2[0], v2[2], v3[0], v3[2]);
    d3 = calc_thing(srcPos[0], srcPos[2], v3[0], v3[2], v1[0], v1[2]);

    has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    return !(has_neg && has_pos);
}

s32 check_if_close_to_center(f32 threshold) {
    s32 isThere0 = (ABS(gMarioState->pos[0] - o->header.gfx.pos[0]) < threshold);
    s32 isThere1 = (ABS(gMarioState->pos[1] - (o->header.gfx.pos[1] - 69.0f)) < threshold);
    s32 isThere2 = (ABS(gMarioState->pos[2] - o->header.gfx.pos[2]) < threshold);
    return isThere0 && isThere1 && isThere2;
}

s32 is_dolphio_inside(void) {
    f32 dist = o->header.gfx.pos[1] - gMarioState->marioObj->header.gfx.pos[1];

    if (ABS(dist) < o->oJellyRadius) {
        // This solution needs rotation accounted for
        // Vec3f uL = { o->header.gfx.pos[0] - o->oJellyRadius, 0.0f, o->header.gfx.pos[2] + o->oJellyRadius };
        // Vec3f uR = { o->header.gfx.pos[0] + o->oJellyRadius, 0.0f, o->header.gfx.pos[2] + o->oJellyRadius };
        // Vec3f lL = { o->header.gfx.pos[0] - o->oJellyRadius, 0.0f, o->header.gfx.pos[2] - o->oJellyRadius };
        // Vec3f lR = { o->header.gfx.pos[0] + o->oJellyRadius, 0.0f, o->header.gfx.pos[2] - o->oJellyRadius };
        // if (
        //     isInTriangle(gMarioState->marioObj->header.gfx.pos, uL, uR, lL) ||
        //     isInTriangle(gMarioState->marioObj->header.gfx.pos, uR, uR, lL)
        // )

        // cheap solution - no rotation
        if (mario_is_within_rectangle(
            o->header.gfx.pos[0] - o->oJellyRadius,
            o->header.gfx.pos[0] + o->oJellyRadius,
            o->header.gfx.pos[2] - o->oJellyRadius,
            o->header.gfx.pos[2] + o->oJellyRadius
        )) return TRUE;
    }

    return FALSE;
}

void scale_jelly(f32 goal, f32 speed) {
    o->header.gfx.scale[0] = approach_f32_asymptotic(o->header.gfx.scale[0], goal, speed);
    o->header.gfx.scale[1] = approach_f32_asymptotic(o->header.gfx.scale[1], goal, speed);
    o->header.gfx.scale[2] = approach_f32_asymptotic(o->header.gfx.scale[2], goal, speed);
}

void return_jelly_home(void) {
    f32 lower = o->oPosY < o->oHomeY;
    f32 absYdist = ABS(o->oPosY - o->oHomeY);

    if (absYdist > 50.0f) {
        if (lower) o->oGravity = approach_f32_asymptotic(o->oGravity, 20.0f, 0.7f);
        else o->oGravity = approach_f32_asymptotic(o->oGravity, -20.0f, 0.7f);
    }

    if (absYdist < 100.0f) {
        o->oVelY *= 0.75f;
        o->oGravity = approach_f32_asymptotic(o->oGravity, 0.0f, 0.245);
        o->oPosY = approach_f32_asymptotic(o->oPosY, o->oHomeY, 0.165f);
    }
    if (o->oVelY > 70.0f) o->oVelY = 70.0f;
    if (o->oVelY < -70.0f) o->oVelY = -70.0f;
}

void scale_jelly_from_exit(void) {
    if (o->oJellyScaleProgress > JELLY_EXIT_LENGTH) return;
    if (++o->oJellyScaleProgress < 4) scale_jelly(o->oJellyOriginalScale * 1.2f, 0.7f);
    else if (o->oJellyScaleProgress < 12) scale_jelly(o->oJellyOriginalScale * 0.5f, 0.79f);
    else if (o->oJellyScaleProgress < JELLY_EXIT_LENGTH) scale_jelly(o->oJellyOriginalScale, 0.165f);
    else if (o->oJellyScaleProgress == JELLY_EXIT_LENGTH) {
        o->header.gfx.scale[0] = o->oJellyOriginalScale;
        o->header.gfx.scale[1] = o->oJellyOriginalScale;
        o->header.gfx.scale[2] = o->oJellyOriginalScale;
    }
}

void reset_jelly_scale_progress(void) {
    o->oJellyScaleProgress = 0;
}

void jelly_exit(void) {
    // if (o->oTimer <= 1) o->oVelY = 0.0f - (gMarioState->vel[1] * 1.2f);
    if (!is_dolphio_inside()) {
        o->oInteractStatus = 0;
        cur_obj_change_action(CUBE_IDLE);
    }
}

void set_exit_action(s32 upwards) {
    if (upwards) {
        f32 fauxHeight = MIN_MAX(
            get_relative_position_between_ranges(
                (f32) o->oTimer,
                0.0f,
                30.0f,
                500.0f,
                1350.0f
            ),
            500.0f,
            1350.0f
        );

        gMarioState->appliedGravChange = FALSE;
        gMarioState->gravPower[0] = fauxHeight;
        gMarioState->gravPower[1] = 1.15f;

        set_mario_action(gMarioState, ACT_DOLPHIN_JELLY_LAUNCH_UP, 0);
    } else {
        s32 num_spins = MIN_MAX(o->oTimer / 6, 1, 6);
        set_mario_action(gMarioState, ACT_DOLPHIN_JELLY_LAUNCH_OUT, num_spins);
    }
    cur_obj_change_action(CUBE_EXIT);
    set_camera_mode(gMarioState->area->camera, gMarioState->area->camera->defMode, 1);
    cur_obj_init_animation_and_anim_frame(CUBE_ANIM_WIGGLE, 0);
    reset_jelly_scale_progress();
}

void dolphio_approach_center_of_jelly(void) {
    gMarioState->vel[0] *= 0.9f;
    gMarioState->vel[1] *= 0.9f;
    gMarioState->vel[2] *= 0.9f;
    gMarioState->pos[0] = approach_f32_asymptotic(gMarioState->pos[0], o->header.gfx.pos[0], 0.75f);
    gMarioState->pos[1] = approach_f32_asymptotic(gMarioState->pos[1], o->header.gfx.pos[1] - 69.0f, 0.75f);
    gMarioState->pos[2] = approach_f32_asymptotic(gMarioState->pos[2], o->header.gfx.pos[2], 0.75f);
}

void readying_jelly_launch(void) {
    if (cur_obj_check_if_near_animation_end()) cur_obj_init_animation_and_anim_frame(CUBE_ANIM_SPIN, 0);
    if (!is_button_down(A_BUTTON) && !is_button_down(B_BUTTON)) {
        set_exit_action(o->oSubAction == JELLY_INSIDE_A_BUTTON);
    }
}

void jelly_inside(void) {
    s32 isThere = check_if_close_to_center(3.0f);
    if (!isThere) dolphio_approach_center_of_jelly();
    if (o->oSubAction != JELLY_INSIDE_IDLE) readying_jelly_launch();
    else if (o->oTimer < 3) return;
    else if (is_button_down(A_BUTTON)) {
        o->oSubAction = JELLY_INSIDE_A_BUTTON;
        o->oTimer = 0;
    }
    else if (is_button_down(B_BUTTON)) {
        o->oSubAction = JELLY_INSIDE_B_BUTTON;
        o->oTimer = 0;
    }
}

void jelly_enter(void) {
    s32 isThere = check_if_close_to_center(10.0f);
    dolphio_approach_center_of_jelly();

    if (o->oTimer > 1) {
        cur_obj_change_action(CUBE_INSIDE);
    } else if (!isThere) {
        o->oTimer = 0;
    }
}

void jelly_hop_perform_action(void) {
    // Manually perform beginning of jump action
    set_dolphio_grav_power_from_bounce(gMarioState, o->oPosY - 100.0f, 1);
    gMarioState->pos[1] = o->oPosY + o->oJellyRadius;
    gMarioState->vel[1] = 50.0f + gMarioState->forwardVel * 0.1 + (gMarioState->gravPower[0] / 80.0f);
    
    // Add cube upwards velocity to dolphio, dont negate velocity
    if (o->oVelY > 0.0f) gMarioState->vel[1] += o->oVelY;
    // Add a little extra if A was recently pressed
    if (gMarioState->framesSinceA < 4) gMarioState->vel[1] += 10.0f;

    if (!(gMarioState->action & ACT_FLAG_DIVING)) {
        switch (gMarioState->action) {
        case ACT_GROUND_POUND:
            gMarioState->action = ACT_TRIPLE_JUMP;
            gMarioState->actionArg = 0;
            break;
        case ACT_FORWARD_ROLLOUT:
            gMarioState->action = ACT_FREEFALL;
            gMarioState->actionArg = 0;
            break;
        case ACT_DOUBLE_JUMP:
            set_anim_to_frame(gMarioState, 0);
        default:
            gMarioState->action = ACT_DOUBLE_JUMP;
            gMarioState->actionArg = 0;
        }
    }

    play_sound(SOUND_ACTION_BOUNCE_OFF_OBJECT, gMarioState->marioObj->header.gfx.cameraToObject);
    cur_obj_change_action(CUBE_EXIT);
    o->oVelY = 0.0f - (gMarioState->vel[1] * 0.90);
}

// #include <stdio.h>
void jelly_interaction(void) {
    // f32 verticalDist = gMarioState->marioObj->header.gfx.pos[1] - o->header.gfx.pos[1];
    // o->oInteractStatus |= INT_STATUS_INTERACTED;
    s32 landingOnCube = gMarioState->vel[1] < 0.0f && gMarioState->pos[1] > (o->header.gfx.pos[1] + (o->oJellyRadius * 0.5f));

    cur_obj_init_animation_and_anim_frame(CUBE_ANIM_WIGGLE, 0);

    // Check if dolphio is at the top hitting "A"
    if (landingOnCube && gMarioState->controller->buttonDown & A_BUTTON) {
        jelly_hop_perform_action();
    } else {
        // dolphio collided with the side of the cube
        cur_obj_change_action(CUBE_ENTER);
        set_mario_action(gMarioState, ACT_FLOATING, 0);
        o->oVelY = gMarioState->vel[1] * 0.90;
    }

}

// #include <stdio.h>
void jelly_idle(void) {
    if (is_dolphio_inside()) jelly_interaction();
    // top/bottom is 200 units from center
    return;
}

void bhvJellycube_loop(void) {
    if (o->header.gfx.node.flags & 1) {
        o->oInteractionSubtype = 0;
        switch (o->oAction) {
            case CUBE_ENTER:
                jelly_enter();
                break;
            case CUBE_INSIDE:
                jelly_inside();
                break;
            case CUBE_EXIT:
                jelly_exit();
                break;
            case CUBE_IDLE:
            default:
                jelly_idle();
                break;
        };
        scale_jelly_from_exit();
        cur_obj_move_using_vel_and_gravity();
        return_jelly_home();
    }
}

void bhvJellycube_init(void) {
    o->oAction = 0;
    o->oJellyOriginalScale = o->header.gfx.scale[0];
    o->oJellyRadius = o->header.gfx.scale[0] * 200.0f;
    o->oJellyScaleProgress = JELLY_EXIT_LENGTH + 1;
    o->oGravity = 0.0f;
}
