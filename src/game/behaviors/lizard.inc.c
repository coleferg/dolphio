#include <ultra64.h>

#include "sm64.h"
#include "behavior_data.h"
#include "object_fields.h"
#include "types.h"
#include "dialog_ids.h"


#define LIZARD_SPEED 32.4f
// #define LIZARD_SPEED 0.0f
#define LIZARD_ATTACK_DISTANCE 2400.0f
#define LIZARD_SIGHT_NOTICE 4000.0f

enum LizardEvilStates {
    LIZARD_NEAR_MARIO,
    LIZARD_GOING_HOME,
    LIZARD_IDLE,
    LIZARD_TALKING
};

enum LizardAnims {
    LIZARD_RUN,
    LIZARD_IDLE_ANIM,
    LIZARD_IDLE_TO_RUN,
    LIZARD_RUN_TO_IDLE
};

static struct ObjectHitbox sLizardHitbox = {
    /* interactType:      */ INTERACT_BOUNCE_TOP,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 1,
    /* numLootCoins:      */ -1,
    /* radius:            */ 72,
    /* height:            */ 175,
    /* hurtboxRadius:     */ 50,
    /* hurtboxHeight:     */ 40
};

static u8 sLizardAttackHandlers[6] = {
        /* ATTACK_PUNCH:                 */ ATTACK_HANDLER_NOP,
        /* ATTACK_KICK_OR_TRIP:          */ ATTACK_HANDLER_NOP,
        /* ATTACK_FROM_ABOVE:            */ ATTACK_HANDLER_SQUISHED_WITH_BLUE_COIN,
        /* ATTACK_GROUND_POUND_OR_TWIRL: */ ATTACK_HANDLER_SQUISHED_WITH_BLUE_COIN,
        /* ATTACK_FAST_ATTACK:           */ ATTACK_HANDLER_NOP,
        /* ATTACK_FROM_BELOW:            */ ATTACK_HANDLER_NOP
};

static void playSoundByLizardType(s16 isAvoiding, s16 isEvil, u32 evilSound, u32 avoidSound, u32 normalSound) {
    if (o->oTimer < 7) {}
    else if (isAvoiding) cur_obj_play_sound_2(avoidSound);
    else if (isEvil) cur_obj_play_sound_2(evilSound);
    else cur_obj_play_sound_2(normalSound);
}

static s32 lizard_walk_to_idle(void) {
    // switch (o->oSoundStateID) {
    //     case LIZARD_IDLE_TO_RUN:   return cur_obj_init_anim_and_check_if_end(LIZARD_RUN_TO_IDLE);
    //     case LIZARD_RUN:           return cur_obj_init_anim_and_check_if_end(LIZARD_RUN_TO_IDLE);
    //     case LIZARD_RUN_TO_IDLE:   return cur_obj_set_anim_if_at_end(LIZARD_IDLE_ANIM);
    //     case LIZARD_IDLE_ANIM:      return TRUE;
    //     default:                    return FALSE;
    // }
    return TRUE;
}

static s32 lizard_idle_to_run(void) {
    // switch (o->oSoundStateID) {
    //     case LIZARD_RUN_TO_IDLE:   return cur_obj_init_anim_and_check_if_end(LIZARD_IDLE_TO_RUN);
    //     case LIZARD_IDLE_ANIM:      return cur_obj_init_anim_and_check_if_end(LIZARD_IDLE_TO_RUN);
    //     case LIZARD_IDLE_TO_RUN:   return cur_obj_set_anim_if_at_end(LIZARD_RUN);
    //     case LIZARD_RUN:           return TRUE;
    //     default:                    return FALSE;
    // }
    return TRUE;
}

static void lizard_near_mario(void) {
    s16 isCloseToMario = o->oDistanceToMario < LIZARD_ATTACK_DISTANCE;

    if (!isCloseToMario) {
        if (lizard_idle_to_run()) {
            o->oAction = LIZARD_GOING_HOME;
        }
    } else {
        f32 targetVel = LIZARD_SPEED;
        s16 targetAngle = obj_angle_to_object(o, gMarioObject);
        s16 rotSpeed = 0x800;
        f32 fVelInc = 0.4f;
        f32 fVelDec = 0.4f;
        if (o->oForwardVel > 10.0f) fVelInc = 1.0f;

        if (!lizard_idle_to_run()) fVelInc = 0.1f;

        cur_obj_rotate_yaw_toward(targetAngle, rotSpeed);
        o->oForwardVel = approach_f32(o->oForwardVel, targetVel, fVelInc, fVelDec);
        if (cur_obj_check_if_at_animation_end()) {
            cur_obj_init_animation_with_accel_and_sound(o->oSoundStateID, o->oForwardVel / LIZARD_SPEED * 1.5f);
        }
        cur_obj_update_floor_and_walls();
        obj_resolve_object_collisions(NULL);
        cur_obj_move_standard(78);
    }
}

static void lizard_going_home(void) {
    s16 isCloseToMario = o->oDistanceToMario < LIZARD_ATTACK_DISTANCE;

    if (isCloseToMario) {
        o->oAction = LIZARD_NEAR_MARIO;
    } else {
        f32 targetVel;
        s16 targetAngle = cur_obj_angle_to_home();
        s16 rotSpeed = 0x600;
        f32 fVelInc = 0.1;
        f32 fVelDec = 0.2;
        f32 distFromHome = cur_obj_lateral_dist_to_home();

        if (distFromHome > 50.0f) targetVel = LIZARD_SPEED + 0.4f;
        else if (distFromHome > 10.0f) targetVel = LIZARD_SPEED;
        else {
            if (lizard_walk_to_idle()) o->oAction = LIZARD_IDLE;
            targetVel = 0.0f;
            rotSpeed = 0x400;
        }

        cur_obj_rotate_yaw_toward(targetAngle, rotSpeed);
        o->oForwardVel = approach_f32(o->oForwardVel, targetVel, fVelInc, fVelDec);
        cur_obj_update_floor_and_walls();
        obj_resolve_object_collisions(NULL);
        cur_obj_move_standard(78);
    }
}

static void lizard_idle(void) {
    s16 isCloseToMario = o->oDistanceToMario < LIZARD_ATTACK_DISTANCE;
    s16 isSemiCloseToMario = o->oDistanceToMario < LIZARD_SIGHT_NOTICE;
    cur_obj_set_anim_if_at_end(LIZARD_IDLE_ANIM);

    if (isCloseToMario) {
        o->oAction = LIZARD_NEAR_MARIO;
    } else if (isSemiCloseToMario) {
        s16 targetAngle = obj_angle_to_object(o, gMarioObject);
        s16 rotSpeed = 0x800;
        
        cur_obj_rotate_yaw_toward(targetAngle, rotSpeed);
        cur_obj_move_standard(78);
    }
}

void bhvLizardBasic_loop(void) {
    if (o->header.gfx.node.flags & 1) {
        o->oInteractionSubtype = 0;
        switch (o->oAction) {
            case LIZARD_NEAR_MARIO:
                lizard_near_mario();
                break;
            case LIZARD_GOING_HOME:
                lizard_going_home();
                break;
            case LIZARD_IDLE:
            default:
                lizard_idle();
                break;
        };
        if (obj_handle_attacks(
            &sLizardHitbox,
            LIZARD_GOING_HOME,
            sLizardAttackHandlers
        )) {
            o->oHealth -= 1;
            obj_die_if_health_non_positive();
        }
    }
}

void bhvLizardBasic_init(void) {
    o->oAction = LIZARD_IDLE;
}
