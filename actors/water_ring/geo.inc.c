// 0x0D000414
const GeoLayout normal_ring_geo[] = {
   GEO_NODE_START(),
   GEO_OPEN_NODE(),
      GEO_ASM(0, Geo18_8029D924),
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, water_ring_seg6_dl_06013AC0),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};
// 0x0D000414
const GeoLayout gold_ring_geo[] = {
   GEO_NODE_START(),
   GEO_OPEN_NODE(),
      GEO_ASM(0, Geo18_8029D924),
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, water_ring_seg6_dl_gold),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x0D000414
const GeoLayout water_ring_geo[] = {
   GEO_SCALE(0x00, 32768),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, NULL),
      GEO_OPEN_NODE(),
         GEO_SWITCH_CASE(2, geo_switch_anim_state),
         GEO_OPEN_NODE(),
            GEO_BRANCH(1, normal_ring_geo),
            GEO_BRANCH(1, gold_ring_geo),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_END(),
};
