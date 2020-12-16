// white_puff.c.inc

void bhv_white_puff_1_loop(void) {
    f32 sp1C = 0.1f;
    f32 sp18 = 0.5f;
    if (o->oTimer == 0) {
        obj_translate_xz_random(o, 40.0f);
        o->oPosY += 30.0f;
    }
    cur_obj_scale(o->oTimer * sp18 + sp1C);
    o->oOpacity = 50;
    cur_obj_move_using_fvel_and_gravity();
    if (o->oTimer > 4)
        obj_mark_for_deletion(o);
}

void bhv_white_puff_2_loop(void) {
    if (o->oTimer == 0)
        obj_translate_xz_random(o, 40.0f);
}

void bhv_white_puff_3_loop(void) {
    f32 scale = 0.2f + (((f32) o->oTimer) / 20.0f);
    o->header.gfx.scale[0] = scale;
    o->header.gfx.scale[1] = scale;
    o->header.gfx.scale[2] = scale;
    o->oVelY = 1;

    if (o->oTimer == 0) obj_translate_xz_random(o, 5.0f);
    
}
