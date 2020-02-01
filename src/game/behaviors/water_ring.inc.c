// water_ring.c.inc

f32 WaterRingCalcMarioDistInFront(void) {
    f32 marioDistX = o->oPosX - gMarioObject->header.gfx.pos[0];
    f32 marioDistY = o->oPosY - (gMarioObject->header.gfx.pos[1] + 80.0f);
    f32 marioDistZ = o->oPosZ - gMarioObject->header.gfx.pos[2];
    f32 marioDistInFront = marioDistX * o->oWaterRingNormalX + marioDistY * o->oWaterRingNormalY
                           + marioDistZ * o->oWaterRingNormalZ;

    return marioDistInFront;
}

void WaterRingInit(void) {
    SetObjAnimation(0);
    o->oWaterRingScalePhaseX = (s32)(RandomFloat() * 4096.0f) + 0x1000;
    o->oWaterRingScalePhaseY = (s32)(RandomFloat() * 4096.0f) + 0x1000;
    o->oWaterRingScalePhaseZ = (s32)(RandomFloat() * 4096.0f) + 0x1000;

    //! This normal calculation assumes a facing yaw of 0, which is not the case
    //  for the manta ray rings. It also errs by multiplying the normal X by -1.
    //  This cause the ring's orientation for the purposes of collision to be
    //  different than the graphical orientation, which means that Mario won't
    //  necessarily collect a ring even if he appears to swim through it.
    o->oWaterRingNormalX = coss(o->oFaceAnglePitch) * sins(o->oFaceAngleRoll) * -1.0f;
    o->oWaterRingNormalY = coss(o->oFaceAnglePitch) * coss(o->oFaceAngleRoll);
    o->oWaterRingNormalZ = sins(o->oFaceAnglePitch);

    o->oWaterRingMarioDistInFront = WaterRingCalcMarioDistInFront();

    // Adding this code will alter the ring's graphical orientation to align with the faulty
    // collision orientation:
    //
    o->oFaceAngleYaw = 0;
    o->oFaceAngleRoll *= -1;
}

void bhv_jet_stream_water_ring_init(void) {
    WaterRingInit();
    o->oOpacity = 200;
    SetObjAnimation(0);
    // o->oFaceAnglePitch = 0x8000;
}

// sp28 = arg0
// sp2c = ringManager

void CheckWaterRingCollection(f32 avgScale, struct Object *ringManager) {
    f32 marioDistInFront = WaterRingCalcMarioDistInFront();
    struct Object *ringSpawner;

    if (!is_point_close_to_object(o, gMarioObject->header.gfx.pos[0],
                                  gMarioObject->header.gfx.pos[1] + 120.0f,
                                  gMarioObject->header.gfx.pos[2], avgScale * 150.0)) {
        o->oWaterRingMarioDistInFront = marioDistInFront;
        return;
    }

    // if (o->oWaterRingMarioDistInFront * marioDistInFront < 0) {
    //     ringSpawner = o->parentObj;
    //     if (ringSpawner) {
    //         ringSpawner->oWaterRingSpawnerRingsCollected++;
    //         play_sound(SOUND_MENU_STAR_SOUND, gDefaultSoundArgs);
    //     }

    //     o->oIntangibleTimer = 20;
    //     o->oAction = WATER_RING_ACT_COLLECTED;
    // }

    o->oWaterRingMarioDistInFront = marioDistInFront;
}

void SetWaterRingScale(f32 avgScale) {
    o->header.gfx.scale[0] = sins(o->oWaterRingScalePhaseX) * 0.1 + avgScale;
    o->header.gfx.scale[1] = sins(o->oWaterRingScalePhaseY) * 0.5 + avgScale;
    o->header.gfx.scale[2] = sins(o->oWaterRingScalePhaseZ) * 0.1 + avgScale;
    o->oWaterRingScalePhaseX += 0x1700;
    o->oWaterRingScalePhaseY += 0x1700;
    o->oWaterRingScalePhaseZ += 0x1700;
}

void WaterRingCollectedLoop(void) {
    f32 avgScale = (f32) o->oTimer * 0.2 + o->oWaterRingAvgScale;

    if (o->oTimer >= 20)
        o->activeFlags = 0;

    o->oOpacity -= 10;
    if (o->oOpacity < 0)
        o->oOpacity = 0;

    SetWaterRingScale(avgScale);
}

void JetStreamWaterRingNotCollectedLoop(void) {
    // f32 avgScale = (f32) o->oTimer / 225.0 * 3.0 + 0.5;
    f32 avgScale = (f32) min(30.0, o->oTimer) / 50.0 * 3.0 + 0.5;

    //! In this case ringSpawner and ringManager are the same object,
    //  because the Jet Stream Ring Spawner is its own parent object.
    struct Object *ringSpawner = o->parentObj;
    struct Object *ringManager = ringSpawner->parentObj;

    // if (o->oTimer >= 226) {
    //     o->oOpacity -= 2;
    //     if (o->oOpacity < 3)
    //         o->activeFlags = 0;
    // }

    CheckWaterRingCollection(avgScale, ringManager);
    SetWaterRingScale(avgScale);

    // o->oPosY += 1.0f;
    o->oFaceAngleYaw += 0x040;
    set_object_visibility(o, 10000);

    o->oOpacity = sins(o->oTimer * 0x0800) * 20.0f + 180.0f;
    o->oWaterRingAvgScale = avgScale;
}

void bhv_jet_stream_water_ring_loop(void) {
    switch (o->oAction) {
        case WATER_RING_ACT_NOT_COLLECTED:
            JetStreamWaterRingNotCollectedLoop();
            break;

        case WATER_RING_ACT_COLLECTED:
            WaterRingCollectedLoop();
            break;
    }
}

void Unknown802EB8A4(void) {
    struct Object *ringManager = spawn_object(o, MODEL_NONE, bhvMantaRayRingManager);
    o->parentObj = ringManager;
}

void JetStreamRingSpawnerActiveLoop(void) {
    //! The Jet Stream Ring Spawner is its own parent object. The code may have been copied
    //  from the Manta Ray, which spawns rings but also has a Ring Manager object as its
    //  parent. The Jet Stream Ring Spawner functions as both a spawner and a Ring Manager.
    struct Object *currentObj = o->parentObj;
    struct Object *waterRing;

    //! Because the index counter overflows at 10000, it's possible to wait
    //  for about 4 hours and 38 minutes if you miss a ring, and the index will
    //  come around again.
    if (o->oTimer == 50 && o->oAction != JS_RING_SPAWNER_ACT_INACTIVE) {
        waterRing = spawn_object(o, MODEL_WATER_RING, bhvJetStreamWaterRing);
        // waterRing->oWaterRingIndex = currentObj->oWaterRingMgrNextRingIndex;
        // currentObj->oWaterRingMgrNextRingIndex++;
        // if (currentObj->oWaterRingMgrNextRingIndex >= 10001)
        //     currentObj->oWaterRingMgrNextRingIndex = 0;
    }
}

void JetStreamRingSpawnerInactiveLoop(void) {
    if (o->oTimer == 1000)
        o->oTimer = 0;
    o->oWaterRingSpawnerRingsCollected = 0;
    o->oAction = JS_RING_SPAWNER_ACT_ACTIVE;
}

void bhv_jet_stream_ring_spawner_loop(void) {
    switch (o->oAction) {
        case JS_RING_SPAWNER_ACT_ACTIVE:
            JetStreamRingSpawnerActiveLoop();

            if (o->oWaterRingSpawnerRingsCollected == 1) {
                o->oTimer = 0;
                o->oAction = JS_RING_SPAWNER_ACT_INACTIVE;
            }
            break;

        case JS_RING_SPAWNER_ACT_INACTIVE:
            JetStreamRingSpawnerInactiveLoop();
            break;
    }
}

void bhv_manta_ray_water_ring_init(void) {
    WaterRingInit();
    o->oOpacity = 150;
}

void MantaRayWaterRingNotCollectedLoop(void) {
    f32 avgScale = (f32) o->oTimer / 50.0f * 1.3 + 0.1;
    struct Object *ringSpawner = o->parentObj;
    struct Object *ringManager = ringSpawner->parentObj;

    if (avgScale > 1.3)
        avgScale = 1.3;

    if (o->oTimer >= 151) {
        o->oOpacity -= 2;
        if (o->oOpacity < 3)
            o->activeFlags = 0;
    }

    CheckWaterRingCollection(avgScale, ringManager);
    SetWaterRingScale(avgScale);
    set_object_visibility(o, 5000);

    if (ringSpawner->oWaterRingSpawnerRingsCollected == 4
        && o->oWaterRingIndex == ringManager->oWaterRingMgrLastRingCollected + 1)
        o->oOpacity = sins(o->oTimer * 0x1000) * 200.0f + 50.0f;

    o->oWaterRingAvgScale = avgScale;
}

void bhv_manta_ray_water_ring_loop(void) {
    switch (o->oAction) {
        case WATER_RING_ACT_NOT_COLLECTED:
            MantaRayWaterRingNotCollectedLoop();
            break;

        case WATER_RING_ACT_COLLECTED:
            WaterRingCollectedLoop();
            break;
    }
}
