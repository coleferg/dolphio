
void sliding_door_act_4(void) {
    o->oAction = 0;
}

void sliding_door_act_3(void) {
    // if (o->oTimer == 0)
    //     if (o->oDistanceToMario < 1500.0f) {
    //         cur_obj_shake_screen(SHAKE_POS_SMALL);
    //         // cur_obj_play_sound_2(SOUND_OBJ_THWOMP);
    //     }
    // if (o->oTimer > 9)
    //     o->oAction = 4;
}

void sliding_door_act_2(void) {
    o->oForwardVel = 0.0f;
    o->oAction = 3;
}

void sliding_door_act_1(void) {
    if (o->oTimer == 0) {
        cutscene_object(CUTSCENE_POV_TO_OBJECT_FAST, o);
        enable_time_stop_including_mario();
    }

    o->oMoveAngleYaw = o->oFaceAngleYaw + 0x4000;
    o->oForwardVel = 0.0f;

    if (cur_obj_lateral_dist_to_home() >= 420.0f)
    {
        o->oAction = 2;
    }
    else if (cur_obj_lateral_dist_to_home() >= 340.0f)
    {
        gObjCutsceneDone = TRUE;
        disable_time_stop_including_mario();
        spawn_mist_particles_variable(0, 0, 45.0f);
        o->oForwardVel = 5.0f;
    }
    else if (o->oTimer > 20.f)
    {
        spawn_mist_particles_variable(0, 0, 92.0f);
        o->oForwardVel = 5.0f;
    }
}

void sliding_door_act_0(void) {
    o->oMoveAngleYaw = o->oFaceAngleYaw + 0x4000;
    o->oForwardVel = 0.0f;
    if ((o->oBehParams >> 16) - 1 == gMarioState->ringsCollected)
        o->oAction = 1;
    // else if (cur_obj_lateral_dist_to_home() > 450.0f)
    // {
    //     o->oAction = 1;
    // }
    // else if (o->oTimer > 100.f)
    // {
    //     o->oForwardVel = 5.0f;
    // }
}

void (*sSlidingDoorActions[])(void) = { sliding_door_act_0, sliding_door_act_1,
                                          sliding_door_act_2, sliding_door_act_3,
                                          sliding_door_act_4 };

void bhv_sliding_door_loop(void) {
    cur_obj_call_action_function(sSlidingDoorActions);
}
