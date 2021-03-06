#include <ultra64.h>

#include "sm64.h"
#include "behavior_data.h"
#include "object_fields.h"
#include "types.h"
#include "dialog_ids.h"

#define TOAD_STAR_1_REQUIREMENT 0
#define TOAD_STAR_2_REQUIREMENT 0
#define TOAD_STAR_3_REQUIREMENT 0

#define TOAD_STAR_1_DIALOG DIALOG_082
#define TOAD_STAR_2_DIALOG DIALOG_076
#define TOAD_STAR_3_DIALOG DIALOG_083

#define TOAD_STAR_1_DIALOG_AFTER DIALOG_154
#define TOAD_STAR_2_DIALOG_AFTER DIALOG_155
#define TOAD_STAR_3_DIALOG_AFTER DIALOG_156

#define EVIL_TOAD_HEALTH 2


// #define CULT_DISTANCE 850.0f
// #define CULT_DISTANCE_VARIANCE 350.0f
// #define NUM_TOADS_IN_CULT 25

#define CULT_DISTANCE 700.0f
#define CULT_DISTANCE_VARIANCE 250.0f
#define NUM_TOADS_IN_CULT 10


// #define CULT_DISTANCE 700.0f
// #define CULT_DISTANCE_VARIANCE 250.0f
// #define NUM_TOADS_IN_CULT 4

enum ToadEvilStates {
    TOAD_NEAR_MARIO,
    TOAD_GOING_HOME,
    TOAD_IDLE,
    TOAD_TALKING,
    TOAD_EVIL_ATTACKED_MARIO,
    TOAD_EVIL_JUMP,
    TOAD_EVIL_POUNCE
};

enum ToadCultSpawnerStates {
    TOAD_CULT_CHANTING,
    TOAD_CULT_NOTICE_MARIO,
    TOAD_CULT_ATTACKING_MARIO
};

static struct ObjectHitbox sToadEvilHitbox = {
    /* interactType:      */ INTERACT_BOUNCE_TOP,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 3,
    /* health:            */ EVIL_TOAD_HEALTH,
    /* numLootCoins:      */ -1,
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
    else if (isAvoiding) cur_obj_play_sound_2(avoidSound);
    else if (isEvil) cur_obj_play_sound_2(evilSound);
    else cur_obj_play_sound_2(normalSound);
}

static void toad_near_mario(s16 isEvil) {
    s16 isHopping = cur_obj_check_anim_frame_in_range(9, 8);
    s16 isCloseToMario = o->oDistanceToMario < 1000.0f;
    s16 isAvoiding = checkIsToadAvoiding();
    s16 isCultToad = o->oBehParams == 0x2;

    if (!isCloseToMario && !isCultToad) {
        o->oAction = TOAD_GOING_HOME;
        playSoundByToadType(isAvoiding, isEvil, SOUND_OBJ_TOADLE_FOLLOW, NO_SOUND, SOUND_OBJ_TOADLE_DISAPPOINT);
    } else if (isHopping) {
        f32 targetVel = isAvoiding
            ? 3.5f 
            : 3.0f;
        s16 targetAngle = isAvoiding 
            ? obj_angle_to_object(gMarioObject, o)
            : obj_angle_to_object(o, gMarioObject);
        s16 rotSpeed = isCultToad ? 0x800 : 0x600;
        f32 fVelInc = 0.2f;
        if (o->oForwardVel > 10.0f) fVelInc = 1.0f;

        if (o->header.gfx.animInfo.animFrame == 9) cur_obj_play_sound_2(SOUND_OBJ_TOADLE_HOP);
        if (isEvil) targetVel = 4.0f;
        if (!isEvil && o->oDistanceToMario < 150.0f) targetVel = 0.0f;

        cur_obj_rotate_yaw_toward(targetAngle, rotSpeed);
        if (targetVel > 0.0f) {
            o->oForwardVel = approach_f32(o->oForwardVel, targetVel, fVelInc, fVelInc);
            cur_obj_update_floor_and_walls();
            obj_resolve_object_collisions(NULL);
            cur_obj_move_standard(-30);
        }
    } else if (isCultToad && o->oTimer > 30 + (random_float() * 10)) {
        o->oAction = TOAD_EVIL_POUNCE;
    }
    if (isCultToad && o->header.gfx.animInfo.animFrame == 20) o->header.gfx.animInfo.animFrame = (s16) random_float() * 5;
}

static void toad_going_home(s16 isEvil) {
    s16 isHopping = cur_obj_check_anim_frame_in_range(9, 8);
    s16 isCloseToMario = o->oDistanceToMario < 1000.0f;
    s16 isAvoiding = checkIsToadAvoiding();

    if (isCloseToMario) {
        o->oAction = TOAD_NEAR_MARIO;
        playSoundByToadType(isAvoiding, isEvil, SOUND_OBJ_TOADLE_ATTACK, SOUND_OBJ_TOADLE_SCARED, SOUND_OBJ_TOADLE_EXCITE);
    } else if (isHopping) {
        f32 targetVel;
        s16 targetAngle = cur_obj_angle_to_home();
        s16 rotSpeed = 0x600;
        f32 fVelInc = 0.1;
        f32 distFromHome = cur_obj_lateral_dist_to_home();

        if (o->header.gfx.animInfo.animFrame == 9) cur_obj_play_sound_2(SOUND_OBJ_TOADLE_HOP);

        if (distFromHome > 50.0f) targetVel = 2.6f;
        else if (distFromHome > 10.0f) targetVel = 1.5f;
        else {
            targetVel = 0.0f;
            rotSpeed = 0x400;
            o->oAction = TOAD_IDLE;
        }

        cur_obj_rotate_yaw_toward(targetAngle, rotSpeed);
        if (targetVel > 0.0f) {
            o->oForwardVel = approach_f32(o->oForwardVel, targetVel, fVelInc, fVelInc);
            cur_obj_update_floor_and_walls();
            obj_resolve_object_collisions(NULL);
            cur_obj_move_standard(-30);
        }
    }
}

static void toad_evil_fire_dance(s16 isSemiCloseToMario) {
    s16 isHopping = cur_obj_check_anim_frame_in_range(9, 8);
    struct Object *cultSpawner = o->parentObj;

    if (isSemiCloseToMario && o->header.gfx.animInfo.animFrame == 9) cur_obj_play_sound_2(SOUND_OBJ_TOADLE_HOP);

    if (cultSpawner->oAction == TOAD_CULT_NOTICE_MARIO && cultSpawner->oTimer > o->oBehParams2ndByte) {
        s16 targetAngle = obj_angle_to_object(o, gMarioObject);
        s16 rotSpeed = 0x100;

        if (o->header.gfx.animInfo.animFrame == 1) o->header.gfx.animInfo.animFrame = 0;
        if (o->header.gfx.animInfo.animFrame == 0) {
            o->oForwardVel = 0.0f;
            cur_obj_rotate_yaw_toward(targetAngle, rotSpeed);
        };

        if (cultSpawner->oTimer > (290 + (9.0f * random_float() * random_sign()))) o->oAction = TOAD_EVIL_POUNCE;
    } else if (isHopping) {
        f32 targetVel = 6.0f;
        s32 toadRight;

        if (o->header.gfx.animInfo.animFrame == 9) cur_obj_play_sound_2(SOUND_OBJ_TOADLE_HOP);

        o->oMoveAngleYaw = obj_angle_to_object(o, cultSpawner);
        o->oForwardVel = 0.0f;

        toadRight = 0x4000 + o->oMoveAngleYaw;
        o->oVelX = targetVel * sins(toadRight);
        o->oVelZ = targetVel * coss(toadRight);

        cur_obj_update_floor_and_walls();
        obj_move_xz_2(0, FALSE);
        cur_obj_move_y(o->oGravity, o->oBounciness, o->oBuoyancy);
    } else if (o->header.gfx.animInfo.animFrame == 20) o->header.gfx.animInfo.animFrame = 5;
}

static void toad_idle(s16 isEvil) {
    s16 isAvoiding = (
        o->oToadMessageDialogId == TOAD_STAR_1_DIALOG ||
        o->oToadMessageDialogId == TOAD_STAR_2_DIALOG ||
        o->oToadMessageDialogId == TOAD_STAR_3_DIALOG
    );
    s16 isWaitingToPounce = o->oBehParams == 0x4 && isEvil;
    s16 isCloseToMario = o->oDistanceToMario < (isWaitingToPounce ? 2400.0f : 1000.0f);
    s16 isSemiCloseToMario = o->oDistanceToMario < (isWaitingToPounce ? 4000.0f : 2400.0f);

    if (o->oBehParams == 0x2) {
        toad_evil_fire_dance(isSemiCloseToMario);
        return;
    }

    if (isSemiCloseToMario && o->header.gfx.animInfo.animFrame == 9) cur_obj_play_sound_2(SOUND_OBJ_TOADLE_HOP);

    if (isCloseToMario) {
        o->oAction = TOAD_NEAR_MARIO;
        playSoundByToadType(isAvoiding, isEvil, SOUND_OBJ_TOADLE_ATTACK, SOUND_OBJ_TOADLE_SCARED, SOUND_OBJ_TOADLE_EXCITE);
        if (isEvil && isWaitingToPounce) {
            o->oAction = TOAD_EVIL_POUNCE;
            o->oMoveAngleYaw = obj_angle_to_object(o, gMarioObject);
        }
    } else if (isSemiCloseToMario) {
        s16 targetAngle = isAvoiding 
            ? obj_angle_to_object(gMarioObject, o)
            : obj_angle_to_object(o, gMarioObject);
        s16 rotSpeed = isWaitingToPounce ? 0x800 : 0x400;
        
        cur_obj_rotate_yaw_toward(targetAngle, rotSpeed);
    }
}

static void toad_evil_attacked_mario(void) {
    cur_obj_play_sound_2(SOUND_OBJ_TOADLE_ATTACK);
    o->header.gfx.animInfo.animFrame = 7;
    o->oForwardVel = -5.0f;
    o->oVelY = 12.0f;
    o->oAction = TOAD_EVIL_JUMP;
    cur_obj_move_standard(-30);
}

static void toad_evil_pounce(void) {
    o->header.gfx.animInfo.animFrame = 7;
    o->oForwardVel = 50.0f;
    o->oVelY = 20.0f;
    o->oAction = TOAD_EVIL_JUMP;
    cur_obj_move_standard(0);
}

static void toad_evil_jump(void) {
    cur_obj_update_floor_and_walls();

    if (cur_obj_check_anim_frame_in_range(9, 8) || !(o->oMoveFlags & OBJ_MOVE_MASK_ON_GROUND)) {
        s16 targetAngle = obj_angle_to_object(o, gMarioObject);
        s16 rotSpeed = 0x200;
        cur_obj_rotate_yaw_toward(targetAngle, rotSpeed);
        obj_resolve_object_collisions(NULL);
        cur_obj_move_standard(-30);
    }

    if (!(o->oMoveFlags & OBJ_MOVE_MASK_ON_GROUND)) {
        o->oTimer = 0;
    }

    if (o->oTimer > 20) {
        s16 isCloseToMario = o->oDistanceToMario < 1000.0f;
        s16 isCultToad = o->oBehParams == 0x2;
        o->oAction = (isCloseToMario || isCultToad) 
            ? TOAD_NEAR_MARIO
            : TOAD_GOING_HOME;
    };
}

void bhvToadEvil_loop(void) {
    o->oInteractionSubtype = 0;
    switch (o->oAction) {
        case OBJ_ACT_SQUISHED:
        case TOAD_EVIL_ATTACKED_MARIO:
            toad_evil_attacked_mario();
            break;
        case TOAD_EVIL_JUMP:
            toad_evil_jump();
            break;
        case TOAD_EVIL_POUNCE:
            toad_evil_pounce();
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
        s16 isCultToad = o->oBehParams == 0x2;

        if (o->oHealth -= 1 > 0) cur_obj_play_sound_2(SOUND_OBJ_TOADLE_HURT);
        obj_die_if_health_non_positive();

        if (o->oHealth == 0 && isCultToad) {
            struct Object *cultSpawner = o->parentObj;
            cultSpawner->oCultMembersKilled += 0x1;
            o->oHealth = -1;
            // if (cultSpawner->oCultMembersKilled == NUM_TOADS_IN_CULT) {
            //     o->oBehParams |= 18 << 24;
            //     spawn_default_star(cultSpawner->oPosX, cultSpawner->oPosY + 100, cultSpawner->oPosZ);
            // }
        }
    };
}

void bhvToadEvil_init(void) {
    o->oToadMessageDialogId = 1;
    o->oToadMessageRecentlyTalked = 0;
    o->oAction = TOAD_IDLE;
    o->oOpacity = 255;
    o->oDeathSound = SOUND_OBJ_TOADLE_DEFEAT;
    obj_set_hitbox(o, &sToadEvilHitbox);
}


static void toad_talking(void) {
    if (cur_obj_update_dialog_with_cutscene(3, 1, CUTSCENE_DIALOG, o->oToadMessageDialogId)
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
                cur_obj_play_sound_2(SOUND_OBJ_TOADLE_SPEAK);
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
        obj_mark_for_deletion(o);
    }
}


static void toad_cult_chanting(void) {
    if (o->oDistanceToMario < 2600.0f) {
        o->oAction = TOAD_CULT_NOTICE_MARIO;
    }
}


static void toad_cult_notice_mario(void) {
    if (o->oTimer == 0) {
        cur_obj_play_sound_2(SOUND_OBJ_BOO_LAUGH_LONG);
        cutscene_object_without_dialog(CUTSCENE_POV_TO_OBJECT, o);
        gMarioState->paralyzed = TRUE;
    } else if (o->oTimer > 302) {
        o->oAction = TOAD_CULT_ATTACKING_MARIO;
    } else if (o->oTimer > 260) gMarioState->paralyzed = FALSE;
}


static void toad_cult_attacking_mario(void) {
    if (o->oTimer % 100 == 0) {
        spawn_object_relative(0x0, 0, 250, 0, o, MODEL_BLUE_FLAME, bhvBlueBowserFlame);
    }
    if (o->oCultMembersKilled == NUM_TOADS_IN_CULT) {
        struct Object *newFruit;
        gObjCutsceneDone = TRUE;

        newFruit = spawn_object_abs_with_rot(o, 0, MODEL_FRUIT, bhvStarSpawnCoordinates, o->oPosX, o->oPosY + 1500,
                                     o->oPosZ, 0, 0, 0);
        newFruit->oBehParams = 1 << 24;
        newFruit->oHomeX = gMarioState->pos[0];
        newFruit->oHomeY = gMarioState->pos[1] + 500;
        newFruit->oHomeZ = gMarioState->pos[2];
        newFruit->oFaceAnglePitch = 0;
        newFruit->oFaceAngleRoll = 0;
        newFruit->oBehParams2ndByte = 1;
        // newFruit->oInteractionSubtype |= INT_SUBTYPE_NO_EXIT;

        // func_802F1BD4(o->oPosX, o->oPosY + 100, o->oPosZ);
        o->oCultMembersKilled = (NUM_TOADS_IN_CULT + 1);
        o->activeFlags = 0;
    }
}

void bhvToadCultSpawner_loop(void) {
    switch (o->oAction) {
        case TOAD_CULT_NOTICE_MARIO:
            toad_cult_notice_mario();
            break;
        case TOAD_CULT_ATTACKING_MARIO:
            toad_cult_attacking_mario();
            break;
        case TOAD_CULT_CHANTING:
        default:
            toad_cult_chanting();
            break;
    };
}

void bhvToadCultSpawner_init(void) {
    s32 angleInc = 0xFFFF / NUM_TOADS_IN_CULT;
    s32 curToad = 0;
    s32 curAngle = 0;
    Vec3f relativePos;
    o->oCultMembersKilled = 0;

    relativePos[0] = 0;
    relativePos[1] = 0;
    relativePos[2] = 0;
 
    while (curToad < NUM_TOADS_IN_CULT) {
        struct Object *toad;
        Vec3f toadPos;
        f32 thisToadDistance = CULT_DISTANCE + (random_float() * (f32) random_sign() * CULT_DISTANCE_VARIANCE);
        vec3f_set_dist_and_angle(relativePos, toadPos, thisToadDistance, 0, curAngle);

        toad = spawn_object_relative(0x2, toadPos[0], toadPos[1], toadPos[2], o, MODEL_TOAD, bhvToadEvil);
        toad->oMoveAngleYaw = obj_angle_to_object(toad, o);
        toad->parentObj = o;
        toad->oBehParams = 0x2;
        toad->oBehParams2ndByte = 0x65 + (s32) (45.0f * random_float());
        toad->header.gfx.animInfo.animFrame = 5;

        curToad++;
        curAngle += angleInc;
    }
}
