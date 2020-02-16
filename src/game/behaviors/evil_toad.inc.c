// #include <ultra64.h>

// #include "sm64.h"
// #include "behavior_data.h"
// #include "object_fields.h"
// #include "types.h"
// #include "dialog_ids.h"

#define TOAD_STAR_1_REQUIREMENT 0
#define TOAD_STAR_2_REQUIREMENT 0
#define TOAD_STAR_3_REQUIREMENT 0

#define TOAD_STAR_1_DIALOG DIALOG_082
#define TOAD_STAR_2_DIALOG DIALOG_076
#define TOAD_STAR_3_DIALOG DIALOG_083

#define TOAD_STAR_1_DIALOG_AFTER DIALOG_154
#define TOAD_STAR_2_DIALOG_AFTER DIALOG_155
#define TOAD_STAR_3_DIALOG_AFTER DIALOG_156

enum ToadEvilStates {
    TOAD_NEAR_MARIO,
    TOAD_GOING_HOME,
    TOAD_IDLE,
    TOAD_TALKING,
    TOAD_EVIL_ATTACKED_MARIO,
    TOAD_EVIL_JUMP
};

static struct ObjectHitbox sToadEvilHitbox = {
    /* interactType:      */ INTERACT_BOUNCE_TOP,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 3,
    /* health:            */ 3,
    /* numLootCoins:      */ 5,
    /* radius:            */ 72,
    /* height:            */ 50,
    /* hurtboxRadius:     */ 42,
    /* hurtboxHeight:     */ 40
};

static u8 sToadEvilAttackHandlers[6] = {
        /* ATTACK_PUNCH:                 */ ATTACK_HANDLER_NOP,
        /* ATTACK_KICK_OR_TRIP:          */ ATTACK_HANDLER_NOP,
        /* ATTACK_FROM_ABOVE:            */ ATTACK_HANDLER_SQUISHED_WITH_BLUE_COIN,
        /* ATTACK_GROUND_POUND_OR_TWIRL: */ ATTACK_HANDLER_SQUISHED_WITH_BLUE_COIN,
        /* ATTACK_FAST_ATTACK:           */ ATTACK_HANDLER_NOP,
        /* ATTACK_FROM_BELOW:            */ ATTACK_HANDLER_NOP
};

s32 checkIsToadAvoiding(void) {
    return (
        o->oToadMessageDialogId == TOAD_STAR_1_DIALOG ||
        o->oToadMessageDialogId == TOAD_STAR_2_DIALOG ||
        o->oToadMessageDialogId == TOAD_STAR_3_DIALOG
    );
}

static void playSoundByToadType(s16 isAvoiding, s16 isEvil, u32 evilSound, u32 avoidSound, u32 normalSound) {
    if (o->oTimer < 7) {}
    else if (isAvoiding) PlaySound2(avoidSound);
    else if (isEvil) PlaySound2(evilSound);
    else PlaySound2(normalSound);
}

static void toad_near_mario(s16 isEvil) {
    s16 isHopping = obj_check_anim_frame_in_range(9, 8);
    s16 isCloseToMario = o->oDistanceToMario < 1000.0f;
    s16 isAvoiding = checkIsToadAvoiding();

    if (!isCloseToMario) {
        o->oAction = TOAD_GOING_HOME;
        playSoundByToadType(isAvoiding, isEvil, SOUND_OBJ_TOADLE_FOLLOW, NO_SOUND, SOUND_OBJ_TOADLE_DISAPPOINT);
    } else if (isHopping) {
        f32 targetVel = isAvoiding
            ? 3.5f 
            : 3.0f;
        s16 targetAngle = isAvoiding 
            ? angle_to_object(gMarioObject, o)
            : angle_to_object(o, gMarioObject);
        s16 rotSpeed = 0x600;
        f32 fVelInc = 0.2f;

        if (o->header.gfx.unk38.animFrame == 9) PlaySound2(SOUND_OBJ_TOADLE_HOP);
        if (isEvil) targetVel = 4.0f;
        if (!isEvil && o->oDistanceToMario < 150.0f) targetVel = 0.0f;

        obj_rotate_yaw_toward(targetAngle, rotSpeed);
        if (targetVel > 0.0f) {
            o->oForwardVel = approach_f32(o->oForwardVel, targetVel, fVelInc, fVelInc);
            obj_update_floor_and_walls();
            obj_move_standard(-30);
        }
    }
}

static void toad_going_home(s16 isEvil) {
    s16 isHopping = obj_check_anim_frame_in_range(9, 8);
    s16 isCloseToMario = o->oDistanceToMario < 1000.0f;
    s16 isAvoiding = checkIsToadAvoiding();

    if (isCloseToMario) {
        o->oAction = TOAD_NEAR_MARIO;
        playSoundByToadType(isAvoiding, isEvil, SOUND_OBJ_TOADLE_ATTACK, SOUND_OBJ_TOADLE_SCARED, SOUND_OBJ_TOADLE_EXCITE);
    } else if (isHopping) {
        f32 targetVel;
        s16 targetAngle = obj_angle_to_home();
        s16 rotSpeed = 0x600;
        f32 fVelInc = 0.1;
        f32 distFromHome = obj_lateral_dist_to_home();

        if (o->header.gfx.unk38.animFrame == 9) PlaySound2(SOUND_OBJ_TOADLE_HOP);

        if (distFromHome > 50.0f) targetVel = 2.6f;
        else if (distFromHome > 10.0f) targetVel = 1.5f;
        else {
            targetVel = 0.0f;
            rotSpeed = 0x400;
            o->oAction = TOAD_IDLE;
        }

        obj_rotate_yaw_toward(targetAngle, rotSpeed);
        if (targetVel > 0.0f) {
            o->oForwardVel = approach_f32(o->oForwardVel, targetVel, fVelInc, fVelInc);
            obj_update_floor_and_walls();
            obj_move_standard(-30);
        }
    }
}

static void toad_idle(s16 isEvil) {
    s16 isAvoiding = (
        o->oToadMessageDialogId == TOAD_STAR_1_DIALOG ||
        o->oToadMessageDialogId == TOAD_STAR_2_DIALOG ||
        o->oToadMessageDialogId == TOAD_STAR_3_DIALOG
    );
    s16 isCloseToMario = o->oDistanceToMario < 1000.0f;
    s16 isSemiCloseToMario = o->oDistanceToMario < 2400.0f;

    if (isSemiCloseToMario && o->header.gfx.unk38.animFrame == 9) PlaySound2(SOUND_OBJ_TOADLE_HOP);

    if (isCloseToMario) {
        o->oAction = TOAD_NEAR_MARIO;
        playSoundByToadType(isAvoiding, isEvil, SOUND_OBJ_TOADLE_ATTACK, SOUND_OBJ_TOADLE_SCARED, SOUND_OBJ_TOADLE_EXCITE);
    } else if (isSemiCloseToMario) {
        s16 targetAngle = isAvoiding 
            ? angle_to_object(gMarioObject, o)
            : angle_to_object(o, gMarioObject);
        s16 rotSpeed = 0x400;
        
        obj_rotate_yaw_toward(targetAngle, rotSpeed);
    }
}

static void toad_evil_attacked_mario(void) {
    PlaySound2(SOUND_OBJ_TOADLE_ATTACK);
    o->header.gfx.unk38.animFrame = 7;
    o->oForwardVel = -5.0f;
    o->oVelY = 12.0f;
    o->oAction = TOAD_EVIL_JUMP;
    obj_move_standard(-30);
}

static void toad_evil_jump(void) {
    obj_resolve_object_collisions(NULL);
    obj_update_floor_and_walls();
    obj_move_standard(-30);
    if (o->oMoveFlags & OBJ_MOVE_MASK_ON_GROUND) {
        s16 isCloseToMario = o->oDistanceToMario < 1000.0f;
        o->oAction = isCloseToMario 
            ? TOAD_NEAR_MARIO
            : TOAD_GOING_HOME;
    };
}

void bhvToadEvil_loop(void) {
    o->oInteractionSubtype = 0;
    switch (o->oAction) {
        case TOAD_EVIL_ATTACKED_MARIO:
            toad_evil_attacked_mario();
            break;
        case TOAD_EVIL_JUMP:
            toad_evil_jump();
            break;
        case TOAD_NEAR_MARIO:
            toad_near_mario(TRUE);
            break;
        case TOAD_GOING_HOME:
            toad_going_home(TRUE);
            break;
        case TOAD_IDLE:
        default:
            toad_idle(TRUE);
            break;
    };

    if (obj_handle_attacks(
        &sToadEvilHitbox,
        TOAD_EVIL_ATTACKED_MARIO,
        sToadEvilAttackHandlers
    )) {
        if (o->oHealth -= 1 > 0) PlaySound2(SOUND_OBJ_TOADLE_HURT);
        obj_die_if_health_non_positive();
    };
}

void bhvToadEvil_init(void) {
    o->oToadMessageDialogId = 1;
    o->oToadMessageRecentlyTalked = 0;
    o->oAction = TOAD_IDLE;
    o->oOpacity = 255;
    o->oDeathSound = SOUND_OBJ_TOADLE_DEFEAT;
    set_object_hitbox(o, &sToadEvilHitbox);
}


static void toad_talking(void) {
    if (obj_update_dialog_with_cutscene(3, 1, CUTSCENE_DIALOG, o->oToadMessageDialogId)
        != 0) {
        o->oToadMessageRecentlyTalked = 0;
        o->oAction = TOAD_IDLE;
        switch (o->oToadMessageDialogId) {
            case TOAD_STAR_1_DIALOG:
                o->oToadMessageDialogId = TOAD_STAR_1_DIALOG_AFTER;
                bhv_spawn_star_no_level_exit(0);
                break;
            case TOAD_STAR_2_DIALOG:
                o->oToadMessageDialogId = TOAD_STAR_2_DIALOG_AFTER;
                bhv_spawn_star_no_level_exit(1);
                break;
            case TOAD_STAR_3_DIALOG:
                o->oToadMessageDialogId = TOAD_STAR_3_DIALOG_AFTER;
                bhv_spawn_star_no_level_exit(2);
                break;
        }
    }
}

void bhvToadBasic_loop(void) {
    if (o->header.gfx.node.flags & 1) {
        o->oInteractionSubtype = 0;
        switch (o->oAction) {
            case TOAD_TALKING:
                toad_talking();
            case TOAD_NEAR_MARIO:
                toad_near_mario(FALSE);
                break;
            case TOAD_GOING_HOME:
                toad_going_home(FALSE);
                break;
            case TOAD_IDLE:
            default:
                toad_idle(FALSE);
                break;
        };

        if (o->oToadMessageRecentlyTalked == 0) {
            o->oInteractionSubtype = INT_SUBTYPE_NPC;
            if (o->oInteractStatus & INT_STATUS_INTERACTED) {
                o->oInteractStatus = 0;
                o->oAction = TOAD_TALKING;
                PlaySound2(SOUND_OBJ_TOADLE_SPEAK);
            }
        } else if (o->oDistanceToMario > 700.0f) o->oToadMessageRecentlyTalked = 0;
    }
}

void bhvToadBasic_init(void) {
    s32 saveFlags = save_file_get_flags();
    s32 starCount = save_file_get_total_star_count(gCurrSaveFileNum - 1, 0, 24);
    s32 dialogId = (o->oBehParams >> 24) & 0xFF;
    s32 enoughStars = TRUE;

    switch (dialogId) {
        case TOAD_STAR_1_DIALOG:
            enoughStars = (starCount >= TOAD_STAR_1_REQUIREMENT);
            if (saveFlags & (1 << 24)) {
                dialogId = TOAD_STAR_1_DIALOG_AFTER;
            }
            break;
        case TOAD_STAR_2_DIALOG:
            enoughStars = (starCount >= TOAD_STAR_2_REQUIREMENT);
            if (saveFlags & (1 << 25)) {
                dialogId = TOAD_STAR_2_DIALOG_AFTER;
            }
            break;
        case TOAD_STAR_3_DIALOG:
            enoughStars = (starCount >= TOAD_STAR_3_REQUIREMENT);
            if (saveFlags & (1 << 26)) {
                dialogId = TOAD_STAR_3_DIALOG_AFTER;
            }
            break;
    }
    if (enoughStars) {
        o->oToadMessageDialogId = dialogId;
        o->oToadMessageRecentlyTalked = 0;
        o->oAction = TOAD_IDLE;
        o->oOpacity = 255;
    } else {
        mark_object_for_deletion(o);
    }
}
