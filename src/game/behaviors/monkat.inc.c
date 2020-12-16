#include <ultra64.h>

#include "sm64.h"
#include "behavior_data.h"
#include "object_fields.h"
#include "types.h"
#include "dialog_ids.h"


#define MONKAT_STAR_1_REQUIREMENT 0
#define MONKAT_STAR_2_REQUIREMENT 0
#define MONKAT_STAR_3_REQUIREMENT 0

#define MONKAT_STAR_1_DIALOG DIALOG_082
#define MONKAT_STAR_2_DIALOG DIALOG_076
#define MONKAT_STAR_3_DIALOG DIALOG_083

#define MONKAT_STAR_1_DIALOG_AFTER DIALOG_154
#define MONKAT_STAR_2_DIALOG_AFTER DIALOG_155
#define MONKAT_STAR_3_DIALOG_AFTER DIALOG_156

#define MONKAT_SPEED 1.4f

enum MonkatEvilStates {
    MONKAT_NEAR_MARIO,
    MONKAT_GOING_HOME,
    MONKAT_IDLE,
    MONKAT_TALKING
};

enum MonkatAnims {
    MONKAT_IDLE_ANIM,
    MONKAT_WALK,
    MONKAT_IDLE_TO_WALK,
    MONKAT_WALK_TO_IDLE
};

s32 checkIsMonkatAvoiding(void) {
    return (
        o->oToadMessageDialogId == MONKAT_STAR_1_DIALOG ||
        o->oToadMessageDialogId == MONKAT_STAR_2_DIALOG ||
        o->oToadMessageDialogId == MONKAT_STAR_3_DIALOG
    );
}

static void playSoundByMonkatType(s16 isAvoiding, s16 isEvil, u32 evilSound, u32 avoidSound, u32 normalSound) {
    if (o->oTimer < 7) {}
    else if (isAvoiding) cur_obj_play_sound_2(avoidSound);
    else if (isEvil) cur_obj_play_sound_2(evilSound);
    else cur_obj_play_sound_2(normalSound);
}

static s32 monkat_walk_to_idle(void) {
    switch (o->oSoundStateID) {
        case MONKAT_IDLE_TO_WALK:   return cur_obj_init_anim_and_check_if_end(MONKAT_WALK_TO_IDLE);
        case MONKAT_WALK:           return cur_obj_init_anim_and_check_if_end(MONKAT_WALK_TO_IDLE);
        case MONKAT_WALK_TO_IDLE:   return cur_obj_set_anim_if_at_end(MONKAT_IDLE_ANIM);
        case MONKAT_IDLE_ANIM:      return TRUE;
        default:                    return FALSE;
    }
}

static s32 monkat_idle_to_walk(void) {
    switch (o->oSoundStateID) {
        case MONKAT_WALK_TO_IDLE:   return cur_obj_init_anim_and_check_if_end(MONKAT_IDLE_TO_WALK);
        case MONKAT_IDLE_ANIM:      return cur_obj_init_anim_and_check_if_end(MONKAT_IDLE_TO_WALK);
        case MONKAT_IDLE_TO_WALK:   return cur_obj_set_anim_if_at_end(MONKAT_WALK);
        case MONKAT_WALK:           return TRUE;
        default:                    return FALSE;
    }
}

static void monkat_near_mario(s16 isEvil) {
    s16 isCloseToMario = o->oDistanceToMario < 1000.0f;
    s16 isAvoiding = checkIsMonkatAvoiding();
    s16 isCultMonkat = o->oBehParams == 0x2;
    

    if (!isCloseToMario && !isCultMonkat) {
        if (monkat_idle_to_walk()) {
            o->oAction = MONKAT_GOING_HOME;
            playSoundByMonkatType(isAvoiding, isEvil, SOUND_OBJ_TOADLE_FOLLOW, NO_SOUND, SOUND_OBJ_TOADLE_DISAPPOINT);
        }
    } else {
        f32 targetVel = isAvoiding
            ? 3.5f 
            : MONKAT_SPEED;
        s16 targetAngle = isAvoiding 
            ? obj_angle_to_object(gMarioObject, o)
            : obj_angle_to_object(o, gMarioObject);
        s16 rotSpeed = isCultMonkat ? 0x800 : 0x600;
        f32 fVelInc = 0.2f;
        f32 fVelDec = 0.4f;
        if (o->oForwardVel > 10.0f) fVelInc = 1.0f;

        if (isEvil) targetVel = 4.0f;
        if (!isEvil && o->oDistanceToMario < 240.0f) {
            targetVel = 0.0f;
            monkat_walk_to_idle();
        } else {
            if (!monkat_idle_to_walk()) fVelInc = 0.1f;
        }

        cur_obj_rotate_yaw_toward(targetAngle, rotSpeed);
        o->oForwardVel = approach_f32(o->oForwardVel, targetVel, fVelInc, fVelDec);
        cur_obj_update_floor_and_walls();
        obj_resolve_object_collisions(NULL);
        cur_obj_move_standard(-30);
    }
}

static void monkat_going_home(s16 isEvil) {
    s16 isCloseToMario = o->oDistanceToMario < 1000.0f;
    s16 isAvoiding = checkIsMonkatAvoiding();

    if (isCloseToMario) {
        o->oAction = MONKAT_NEAR_MARIO;
        playSoundByMonkatType(isAvoiding, isEvil, SOUND_OBJ_TOADLE_ATTACK, SOUND_OBJ_TOADLE_SCARED, SOUND_OBJ_TOADLE_EXCITE);
    } else {
        f32 targetVel;
        s16 targetAngle = cur_obj_angle_to_home();
        s16 rotSpeed = 0x600;
        f32 fVelInc = 0.1;
        f32 fVelDec = 0.2;
        f32 distFromHome = cur_obj_lateral_dist_to_home();

        if (distFromHome > 50.0f) targetVel = MONKAT_SPEED + 0.4f;
        else if (distFromHome > 10.0f) targetVel = MONKAT_SPEED;
        else {
            if (monkat_walk_to_idle()) o->oAction = MONKAT_IDLE;
            targetVel = 0.0f;
            rotSpeed = 0x400;
        }

        cur_obj_rotate_yaw_toward(targetAngle, rotSpeed);
        o->oForwardVel = approach_f32(o->oForwardVel, targetVel, fVelInc, fVelDec);
        cur_obj_update_floor_and_walls();
        obj_resolve_object_collisions(NULL);
        cur_obj_move_standard(-30);
    }
}

static void monkat_idle(s16 isEvil) {
    s16 isAvoiding = (
        o->oToadMessageDialogId == MONKAT_STAR_1_DIALOG ||
        o->oToadMessageDialogId == MONKAT_STAR_2_DIALOG ||
        o->oToadMessageDialogId == MONKAT_STAR_3_DIALOG
    );
    s16 isWaitingToPounce = o->oBehParams == 0x4 && isEvil;
    s16 isCloseToMario = o->oDistanceToMario < (isWaitingToPounce ? 2400.0f : 1000.0f);
    s16 isSemiCloseToMario = o->oDistanceToMario < (isWaitingToPounce ? 4000.0f : 2400.0f);
    cur_obj_set_anim_if_at_end(MONKAT_IDLE_ANIM);

    if (isCloseToMario) {
        o->oAction = MONKAT_NEAR_MARIO;
        playSoundByMonkatType(isAvoiding, isEvil, SOUND_OBJ_TOADLE_ATTACK, SOUND_OBJ_TOADLE_SCARED, SOUND_OBJ_TOADLE_EXCITE);
    } else if (isSemiCloseToMario) {
        s16 targetAngle = isAvoiding 
            ? obj_angle_to_object(gMarioObject, o)
            : obj_angle_to_object(o, gMarioObject);
        s16 rotSpeed = isWaitingToPounce ? 0x800 : 0x400;
        
        cur_obj_rotate_yaw_toward(targetAngle, rotSpeed);
    }
}

static void monkat_talking(void) {
    monkat_walk_to_idle();
    if (cur_obj_update_dialog_with_cutscene(3, 1, CUTSCENE_DIALOG, o->oToadMessageDialogId)
        != 0) {
        o->oToadMessageRecentlyTalked = 0;
        o->oAction = MONKAT_IDLE;
        switch (o->oToadMessageDialogId) {
            case MONKAT_STAR_1_DIALOG:
                o->oToadMessageDialogId = MONKAT_STAR_1_DIALOG_AFTER;
                bhv_spawn_star_no_level_exit(0);
                break;
            case MONKAT_STAR_2_DIALOG:
                o->oToadMessageDialogId = MONKAT_STAR_2_DIALOG_AFTER;
                bhv_spawn_star_no_level_exit(1);
                break;
            case MONKAT_STAR_3_DIALOG:
                o->oToadMessageDialogId = MONKAT_STAR_3_DIALOG_AFTER;
                bhv_spawn_star_no_level_exit(2);
                break;
        }
    }
}

void bhvMonkatBasic_loop(void) {
    if (o->header.gfx.node.flags & 1) {
        o->oInteractionSubtype = 0;
        switch (o->oAction) {
            case MONKAT_TALKING:
                monkat_talking();
            case MONKAT_NEAR_MARIO:
                monkat_near_mario(FALSE);
                break;
            case MONKAT_GOING_HOME:
                monkat_going_home(FALSE);
                break;
            case MONKAT_IDLE:
            default:
                monkat_idle(FALSE);
                break;
        };

        if (o->oToadMessageRecentlyTalked == 0) {
            o->oInteractionSubtype = INT_SUBTYPE_NPC;
            if (o->oInteractStatus & INT_STATUS_INTERACTED) {
                o->oInteractStatus = 0;
                o->oAction = MONKAT_TALKING;
                if (o->oSoundStateID != MONKAT_IDLE_ANIM) cur_obj_init_animation_with_sound(MONKAT_IDLE_ANIM);
                cur_obj_play_sound_2(SOUND_OBJ_TOADLE_SPEAK);
            }
        } else if (o->oDistanceToMario > 700.0f) o->oToadMessageRecentlyTalked = 0;
    }
}

void bhvMonkatBasic_init(void) {
    s32 saveFlags = save_file_get_flags();
    s32 starCount = save_file_get_total_star_count(gCurrSaveFileNum - 1, 0, 24);
    s32 dialogId = (o->oBehParams >> 24) & 0xFF;
    s32 enoughStars = TRUE;

    switch (dialogId) {
        case MONKAT_STAR_1_DIALOG:
            enoughStars = (starCount >= MONKAT_STAR_1_REQUIREMENT);
            if (saveFlags & (1 << 24)) {
                dialogId = MONKAT_STAR_1_DIALOG_AFTER;
            }
            break;
        case MONKAT_STAR_2_DIALOG:
            enoughStars = (starCount >= MONKAT_STAR_2_REQUIREMENT);
            if (saveFlags & (1 << 25)) {
                dialogId = MONKAT_STAR_2_DIALOG_AFTER;
            }
            break;
        case MONKAT_STAR_3_DIALOG:
            enoughStars = (starCount >= MONKAT_STAR_3_REQUIREMENT);
            if (saveFlags & (1 << 26)) {
                dialogId = MONKAT_STAR_3_DIALOG_AFTER;
            }
            break;
    }
    if (enoughStars) {
        o->oToadMessageDialogId = dialogId;
        o->oToadMessageRecentlyTalked = 0;
        o->oAction = MONKAT_IDLE;
        o->oOpacity = 255;
    } else {
        obj_mark_for_deletion(o);
    }
}
