// spawn_default_fruit.c.inc

static struct ObjectHitbox sCollectFruitHitbox = {
    /* interactType:      */ INTERACT_FRUIT,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 80,
    /* height:            */ 50,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

enum FruitAnims {
    FRUIT_IDLE_CLOSED,
	FRUIT_IDLE_OPEN,
	FRUIT_OPEN,
	FRUIT_CLOSE
};

#define OPEN_DIST 1400.0f

static s32 fruit_closed_to_open(void) {
    switch (o->oSoundStateID) {
        case FRUIT_IDLE_CLOSED:      return cur_obj_init_anim_and_check_if_end(FRUIT_OPEN);
        case FRUIT_CLOSE:            return cur_obj_init_anim_and_check_if_end(FRUIT_OPEN);
        case FRUIT_OPEN:             return cur_obj_set_anim_if_at_end(FRUIT_IDLE_OPEN);
        case FRUIT_IDLE_OPEN:        return TRUE;
        default:                     return FALSE;
    }
}

static s32 fruit_open_to_closed(void) {
    switch (o->oSoundStateID) {
        case FRUIT_IDLE_OPEN:       return cur_obj_init_anim_and_check_if_end(FRUIT_CLOSE);
        case FRUIT_OPEN:            return cur_obj_init_anim_and_check_if_end(FRUIT_CLOSE);
        case FRUIT_CLOSE:           return cur_obj_set_anim_if_at_end(FRUIT_IDLE_CLOSED);
        case FRUIT_IDLE_CLOSED:     return TRUE;
        default:                    return FALSE;
    }
}

void bhv_collect_fruit_init(void) {
    s8 fruitId;
    u8 currentLevelStarFlags;

    fruitId = o->oBehParams >> 24;
    o->header.gfx.sharedChild = gLoadedGraphNodes[MODEL_FRUIT];

    if (is_fruit_collected(gCurrSaveFileNum - 1, fruitId)) {
        o->oOpacity = 150;
    } else {
        o->oOpacity = 255;
    }

    obj_set_hitbox(o, &sCollectFruitHitbox);
}

void bhv_collect_fruit_loop(void) {
    s16 isCloseToMario = o->oDistanceToMario < OPEN_DIST;
    s16 marioDir = obj_angle_to_object(o, gMarioObject) - DEGREES(90);
    // s16 startYaw;
    // o->oFaceAnglePitch += 0x600;
    // o->oFaceAngleRoll += 0x200;

    o->oFaceAngleYaw += 0x100;

    if (isCloseToMario) fruit_closed_to_open();
    else fruit_open_to_closed();

    // startYaw = (s16) o->oFaceAngleYaw;
    // o->oFaceAngleYaw = approach_s16_symmetric(o->oFaceAngleYaw, marioDir, 0x50);
    // axonium reference
    // abs_angle_diff(o->oAngleToMario, o->oFaceAngleYaw) <= 0x2000;

    if (o->oInteractStatus & INT_STATUS_INTERACTED) {
        mark_obj_for_deletion(o);
        o->oInteractStatus = 0;
    }
}

void bhv_fruit_spawn_init(void) {
    o->oMoveAngleYaw = atan2s(o->oHomeZ - o->oPosZ, o->oHomeX - o->oPosX);
    o->oStarSpawnDisFromHome = sqrtf(sqr(o->oHomeX - o->oPosX) + sqr(o->oHomeZ - o->oPosZ));
    o->oVelY = (o->oHomeY - o->oPosY) / 30.0f;
    o->oForwardVel = o->oStarSpawnDisFromHome / 30.0f;
    o->oStarSpawnUnkFC = o->oPosY;
    if (o->oBehParams2ndByte == 0 || gCurrCourseNum == COURSE_BBH)
        cutscene_object(CUTSCENE_STAR_SPAWN, o);
    else
        cutscene_object(CUTSCENE_RED_COIN_STAR_SPAWN, o);

    set_time_stop_flags(TIME_STOP_ENABLED | TIME_STOP_MARIO_AND_DOORS);
    o->activeFlags |= 0x20;
    cur_obj_become_intangible();
}

void bhv_fruit_spawn_loop(void) {
    switch (o->oAction) {
        case 0:
            o->oFaceAngleYaw += 0x1000;
            if (o->oTimer > 20)
                o->oAction = 1;
            break;

        case 1:
            obj_move_xyz_using_fvel_and_yaw(o);
            o->oStarSpawnUnkFC += o->oVelY;
            o->oPosY = o->oStarSpawnUnkFC + sins((o->oTimer * 0x8000) / 30) * 400.0f;
            o->oFaceAngleYaw += 0x1000;
            spawn_object(o, MODEL_NONE, bhvSparkleSpawn);
            cur_obj_play_sound_1(SOUND_ENV_STAR);
            if (o->oTimer == 30) {
                o->oAction = 2;
                o->oForwardVel = 0;
                play_power_star_jingle(TRUE);
            }
            break;

        case 2:
            if (o->oTimer < 20)
                o->oVelY = 20 - o->oTimer;
            else
                o->oVelY = -10.0f;

            spawn_object(o, MODEL_NONE, bhvSparkleSpawn);
            obj_move_xyz_using_fvel_and_yaw(o);
            o->oFaceAngleYaw = o->oFaceAngleYaw - o->oTimer * 0x10 + 0x1000;
            cur_obj_play_sound_1(SOUND_ENV_STAR);

            if (o->oPosY < o->oHomeY) {
                cur_obj_play_sound_2(SOUND_GENERAL_STAR_APPEARS);
                cur_obj_become_tangible();
                o->oPosY = o->oHomeY;
                o->oAction = 3;
            }
            break;

        case 3:
            o->oFaceAngleYaw += 0x800;
            if (o->oTimer == 20) {
                gObjCutsceneDone = TRUE;
                clear_time_stop_flags(TIME_STOP_ENABLED | TIME_STOP_MARIO_AND_DOORS);
                o->activeFlags &= ~0x20;
            }

            if (o->oInteractStatus & INT_STATUS_INTERACTED) {
                mark_obj_for_deletion(o);
                o->oInteractStatus = 0;
            }
            break;
    }
}

struct Object *spawn_fruit(struct Object *sp30, f32 sp34, f32 sp38, f32 sp3C) {
    sp30 = spawn_object_abs_with_rot(o, 0, MODEL_FRUIT, bhvStarSpawnCoordinates, o->oPosX, o->oPosY,
                                     o->oPosZ, 0, 0, 0);
    sp30->oBehParams = o->oBehParams;
    sp30->oHomeX = sp34;
    sp30->oHomeY = sp38;
    sp30->oHomeZ = sp3C;
    sp30->oFaceAnglePitch = 0;
    sp30->oFaceAngleRoll = 0;
    return sp30;
}

void spawn_default_fruit(f32 sp20, f32 sp24, f32 sp28) {
    struct Object *sp1C;
    sp1C = spawn_fruit(sp1C, sp20, sp24, sp28);
    sp1C->oBehParams2ndByte = 0;
}

void spawn_red_coin_cutscene_fruit(f32 sp20, f32 sp24, f32 sp28) {
    struct Object *sp1C;
    sp1C = spawn_fruit(sp1C, sp20, sp24, sp28);
    sp1C->oBehParams2ndByte = 1;
}

void spawn_no_exit_fruit(f32 sp20, f32 sp24, f32 sp28) {
    struct Object *sp1C;
    sp1C = spawn_fruit(sp1C, sp20, sp24, sp28);
    sp1C->oBehParams2ndByte = 1;
    sp1C->oInteractionSubtype |= INT_SUBTYPE_NO_EXIT;
}

void bhv_hidden_red_coin_fruit_init(void) {
    s16 sp36;
    struct Object *sp30;

    if (gCurrCourseNum != COURSE_JRB)
        spawn_object(o, MODEL_TRANSPARENT_STAR, bhvRedCoinStarMarker);

    sp36 = count_objects_with_behavior(bhvRedCoin);
    if (sp36 == 0) {
        sp30 =
            spawn_object_abs_with_rot(o, 0, MODEL_FRUIT, bhvStar, o->oPosX, o->oPosY, o->oPosZ, 0, 0, 0);
        sp30->oBehParams = o->oBehParams;
        o->activeFlags = 0;
    }

    o->oHiddenStarTriggerCounter = 8 - sp36;
}

void bhv_hidden_red_coin_fruit_loop(void) {
    gRedCoinsCollected = o->oHiddenStarTriggerCounter;
    switch (o->oAction) {
        case 0:
            if (o->oHiddenStarTriggerCounter == 8)
                o->oAction = 1;
            break;

        case 1:
            if (o->oTimer > 2) {
                spawn_red_coin_cutscene_fruit(o->oPosX, o->oPosY, o->oPosZ);
                spawn_mist_particles();
                o->activeFlags = 0;
            }
            break;
    }
}
