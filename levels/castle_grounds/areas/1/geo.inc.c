// 0x0E00073C
const GeoLayout castle_grounds_geo_00073C[] = {
   GEO_NODE_SCREEN_AREA(10, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH/2, SCREEN_HEIGHT/2),
   GEO_OPEN_NODE(),
      GEO_ZBUFFER(0),
      GEO_OPEN_NODE(),
         GEO_NODE_ORTHO(100),
         GEO_OPEN_NODE(),
            GEO_BACKGROUND(BACKGROUND_OCEAN_SKY, geo_skybox_main),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_ZBUFFER(1),
      GEO_OPEN_NODE(),
         GEO_CAMERA_FRUSTUM_WITH_FUNC(45, 100, 20000, geo_camera_fov),
         GEO_OPEN_NODE(),
            GEO_CAMERA(16, 0, 1500, 2500, 0, 1500, -12000, geo_camera_main),
            GEO_OPEN_NODE(),
               GEO_DISPLAY_LIST(LAYER_OPAQUE, castle_grounds_seg7_dl_07006D70),
               GEO_DISPLAY_LIST(LAYER_OPAQUE, castle_grounds_seg7_dl_070095F0),
               GEO_DISPLAY_LIST(LAYER_ALPHA, castle_grounds_seg7_dl_0700A860),
               GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, castle_grounds_seg7_dl_0700B1D0),
               GEO_DISPLAY_LIST(LAYER_ALPHA, castle_grounds_seg7_dl_0700BA20),
               GEO_DISPLAY_LIST(LAYER_OPAQUE_DECAL, castle_grounds_seg7_dl_0700C430),
               GEO_DISPLAY_LIST(LAYER_OPAQUE, castle_grounds_seg7_dl_0700C210),
               GEO_ASM(   0, geo_movtex_pause_control),
               GEO_ASM(0x1601, geo_movtex_draw_nocolor),
               GEO_ASM(0x1601, geo_movtex_draw_water_regions),
               GEO_RENDER_OBJ(),
               GEO_ASM(0, geo_envfx_main),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_ZBUFFER(0),
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_cannon_circle_base),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_END(),
};
