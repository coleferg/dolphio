const GeoLayout castle_grounds_area_1_LevelRoot[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(1, 0, 0, 0, NULL),
		GEO_OPEN_NODE(),
			GEO_ANIMATED_PART(1, 0, 0, 0, NULL),
			GEO_OPEN_NODE(),
				GEO_ANIMATED_PART(1, 0, 0, 0, castle_grounds_levelGeo_mesh),
				GEO_OPEN_NODE(),
					GEO_ANIMATED_PART(1, 9958, 5296, -10600, castle_grounds_Head_mesh),
					GEO_ANIMATED_PART(5, 0, 0, 8191, castle_grounds_headWater_mesh),
					GEO_ANIMATED_PART(5, 0, 0, 8191, castle_grounds_headWaterFall_mesh),
					GEO_ANIMATED_PART(5, 0, 0, 8191, castle_grounds_lakeWater_mesh),
					GEO_ANIMATED_PART(5, 0, 0, 8191, castle_grounds_mainWaterFall_mesh),
					GEO_ANIMATED_PART(5, 0, 0, 8191, castle_grounds_riverWater_mesh),
					GEO_ANIMATED_PART(1, 4645, 0, 1674, castle_grounds_WarpPlane_mesh),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout castle_grounds_area_1_level[] = {
	GEO_NODE_SCREEN_AREA(10, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH/2, SCREEN_HEIGHT/2),
	GEO_OPEN_NODE(),
		GEO_ZBUFFER(0),
		GEO_OPEN_NODE(),
			GEO_NODE_ORTHO(100.0000),
			GEO_OPEN_NODE(),
				GEO_BACKGROUND(BACKGROUND_OCEAN_SKY, geo_skybox_main),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_ZBUFFER(1),
		GEO_OPEN_NODE(),
			GEO_CAMERA_FRUSTUM_WITH_FUNC(90.0000, 100, 30000, geo_camera_fov),
			GEO_OPEN_NODE(),
				GEO_CAMERA(14, 0, 0, 0, 0, -213, 0, geo_camera_main),
				GEO_OPEN_NODE(),
					GEO_BRANCH(1, castle_grounds_area_1_LevelRoot),
					GEO_RENDER_OBJ(),
					GEO_ASM(0, geo_enfvx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(0, castle_grounds_material_revert_render_settings),
		GEO_DISPLAY_LIST(1, castle_grounds_material_revert_render_settings),
		GEO_DISPLAY_LIST(2, castle_grounds_material_revert_render_settings),
		GEO_DISPLAY_LIST(3, castle_grounds_material_revert_render_settings),
		GEO_DISPLAY_LIST(4, castle_grounds_material_revert_render_settings),
		GEO_DISPLAY_LIST(5, castle_grounds_material_revert_render_settings),
		GEO_DISPLAY_LIST(6, castle_grounds_material_revert_render_settings),
		GEO_DISPLAY_LIST(7, castle_grounds_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
