#include <ultra64.h>

#include "sm64.h"
#include "behavior_data.h"
#include "object_fields.h"
#include "types.h"
#include "dialog_ids.h"


#define SLOTH_STAR_1_REQUIREMENT 0
#define SLOTH_STAR_2_REQUIREMENT 0
#define SLOTH_STAR_3_REQUIREMENT 0

#define SLOTH_STAR_1_DIALOG DIALOG_082
#define SLOTH_STAR_2_DIALOG DIALOG_076
#define SLOTH_STAR_3_DIALOG DIALOG_083

#define SLOTH_STAR_1_DIALOG_AFTER DIALOG_154
#define SLOTH_STAR_2_DIALOG_AFTER DIALOG_155
#define SLOTH_STAR_3_DIALOG_AFTER DIALOG_156

#define SLOTH_SPEED 1.4f

enum SlothStates {
    SLOTH_IDLE
};

enum SlothAnims {
    SLOTH_STAND_ANIM,
    SLOTH_TOKE
};

static s32 sloth_to_toke(void) {
    if (o->oSoundStateID != SLOTH_TOKE) return cur_obj_set_anim_if_at_end(SLOTH_TOKE);
    return TRUE;
}

static s32 sloth_to_idle(void) {
    if (o->oSoundStateID != SLOTH_STAND_ANIM) return cur_obj_set_anim_if_at_end(SLOTH_STAND_ANIM);
    return TRUE;
}

static s32 sloth_is_smoking(void) {
    return o->oSoundStateID == SLOTH_TOKE;
}

void sloth_spawn_smoke(void) {
    Vec3f relativePos = {0, 0, 0};
    Vec3f smokePos = {0, 0, 0};
    struct Object *smoke;
    vec3f_set_dist_and_angle(relativePos, smokePos, 35, 0, o->oFaceAngleYaw);
    smoke = try_to_spawn_object(190, 0.2f, o, MODEL_SMOKE, bhvWhitePuffSmoke3);
    smoke->oPosX = smokePos[0] + smoke->oPosX;
    smoke->oPosY = smokePos[1] + smoke->oPosY;
    smoke->oPosZ = smokePos[2] + smoke->oPosZ;

    smoke->oForwardVel = 3;
    smoke->oVelY = 1;
    smoke->oGravity = 1;
    obj_translate_xyz_random(smoke, 0.1f);
}

static void sloth_idle(void) {
    if (sloth_is_smoking()) {
        o->oAnimState = cur_obj_check_anim_frame_in_range(63, 48) ? 1 : 0;
        if (cur_obj_check_anim_frame_in_range(111, 10)) sloth_spawn_smoke();
        sloth_to_idle();
    }
    else sloth_to_toke();
}

void bhvSlothBasic_loop(void) {
    if (o->header.gfx.node.flags & 1) {
        o->oInteractionSubtype = 0;
        switch (o->oAction) {
            case SLOTH_IDLE:
            default:
                sloth_idle();
                break;
        };
    }
}

void bhvSlothBasic_init(void) {
    s32 saveFlags = save_file_get_flags();
    s32 starCount = save_file_get_total_star_count(gCurrSaveFileNum - 1, 0, 24);
    s32 dialogId = (o->oBehParams >> 24) & 0xFF;
    s32 enoughStars = TRUE;

    switch (dialogId) {
        case SLOTH_STAR_1_DIALOG:
            enoughStars = (starCount >= SLOTH_STAR_1_REQUIREMENT);
            if (saveFlags & (1 << 24)) {
                dialogId = SLOTH_STAR_1_DIALOG_AFTER;
            }
            break;
        case SLOTH_STAR_2_DIALOG:
            enoughStars = (starCount >= SLOTH_STAR_2_REQUIREMENT);
            if (saveFlags & (1 << 25)) {
                dialogId = SLOTH_STAR_2_DIALOG_AFTER;
            }
            break;
        case SLOTH_STAR_3_DIALOG:
            enoughStars = (starCount >= SLOTH_STAR_3_REQUIREMENT);
            if (saveFlags & (1 << 26)) {
                dialogId = SLOTH_STAR_3_DIALOG_AFTER;
            }
            break;
    }
    if (enoughStars) {
        o->oToadMessageDialogId = dialogId;
        o->oToadMessageRecentlyTalked = 0;
        o->oAction = SLOTH_IDLE;
        o->oOpacity = 255;
    } else {
        obj_mark_for_deletion(o);
    }
}
