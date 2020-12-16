#include "src/game/envfx_snow.h"

const GeoLayout bowser_1_area_1_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(3, geo_switch_area),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, bowser_1_dl_1entrySlide_geo),
			GEO_BRANCH(1, bowser_1_dl_2firstRoom_geo),
			GEO_BRANCH(1, bowser_1_dl_4MainRoom_geo),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bowser_1_dl_1entrySlide_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, 556, 975, 14695),
		GEO_OPEN_NODE(),
			GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -556, -975, -14695, bowser_1_dl_slideGeo_mesh),
			GEO_TRANSLATE_NODE(LAYER_TRANSPARENT, -556, -975, -14695),
			GEO_OPEN_NODE(),
				GEO_CULLING_RADIUS(2128),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_TRANSPARENT, bowser_1_dl_slideWater_mesh),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bowser_1_dl_2firstRoom_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, 25, 533, 10308),
		GEO_OPEN_NODE(),
			GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -25, -533, -10308, bowser_1_dl_CaveGeo_001_mesh),
			GEO_TRANSLATE_NODE(LAYER_OPAQUE, -25, -533, -10308),
			GEO_OPEN_NODE(),
				GEO_CULLING_RADIUS(2128),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_OPAQUE, bowser_1_dl_Logs_mesh),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
			GEO_TRANSLATE_NODE(LAYER_TRANSPARENT, -21, -1769, -4388),
			GEO_OPEN_NODE(),
				GEO_CULLING_RADIUS(2128),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_TRANSPARENT, bowser_1_dl_WaterCenter_mesh),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
			GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -25, -533, -10308, bowser_1_dl_WaterFallRoomGeo_mesh),
			GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -25, -533, -10308, bowser_1_dl_firstRoomGeo_mesh),
			GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, -25, -533, -10308, bowser_1_dl_firstRoomWater_mesh),
			GEO_TRANSLATE_NODE(LAYER_ALPHA, 435, -704, -4224),
			GEO_OPEN_NODE(),
				GEO_CULLING_RADIUS(2128),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_ALPHA, bowser_1_dl_stalags_mesh),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
			GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, 1, 1078, -4327, bowser_1_dl_waterFallRoomWaterfalls_mesh),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bowser_1_dl_4MainRoom_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, 25, 533, -40),
		GEO_OPEN_NODE(),
			GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -25, -533, 40, bowser_1_dl_CaveGeo_mesh),
			GEO_OPEN_NODE(),
				GEO_CULLING_RADIUS(2128),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_OPAQUE, bowser_1_dl_Pillars_mesh),
				GEO_CLOSE_NODE(),
				GEO_DISPLAY_LIST(LAYER_TRANSPARENT, bowser_1_dl_Water_mesh),
				GEO_CULLING_RADIUS(2128),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_OPAQUE, bowser_1_dl_cultPathextension_mesh),
				GEO_CLOSE_NODE(),
				GEO_DISPLAY_LIST(LAYER_TRANSPARENT, bowser_1_dl_deathPlane_mesh),
				GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, -64, 0, bowser_1_dl_deathPlane_001_mesh),
				GEO_DISPLAY_LIST(LAYER_TRANSPARENT, bowser_1_dl_instawarp_mesh),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bowser_1_area_1[] = {
	GEO_NODE_SCREEN_AREA(10, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH/2, SCREEN_HEIGHT/2),
	GEO_OPEN_NODE(),
		GEO_ZBUFFER(0),
		GEO_OPEN_NODE(),
			GEO_NODE_ORTHO(100.0000),
			GEO_OPEN_NODE(),
				GEO_BACKGROUND_COLOR(0x0001),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_ZBUFFER(1),
		GEO_OPEN_NODE(),
			GEO_CAMERA_FRUSTUM_WITH_FUNC(80.0000, 100, 20000, geo_camera_fov),
			GEO_OPEN_NODE(),
				GEO_CAMERA(CAMERA_MODE_8_DIRECTIONS, 0, 0, 0, 0, -213, 0, geo_camera_main),
				GEO_OPEN_NODE(),
					GEO_BRANCH(1, bowser_1_area_1_geo),
					GEO_RENDER_OBJ(),
					GEO_ASM(ENVFX_MODE_NONE, geo_envfx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bowser_1_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, bowser_1_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, bowser_1_dl_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
