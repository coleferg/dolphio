const GeoLayout world_geo[] = {
	GEO_NODE_SCREEN_AREA(10, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH/2, SCREEN_HEIGHT/2),
		GEO_OPEN_NODE(),
			GEO_ZBUFFER(0),
			GEO_OPEN_NODE(),
				GEO_NODE_ORTHO(100),
				GEO_OPEN_NODE(),
					GEO_BACKGROUND_COLOR(0x0001),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
			GEO_ZBUFFER(1),
			GEO_OPEN_NODE(),
				GEO_CAMERA_FRUSTUM_WITH_FUNC(45, 100, 20000, geo_camera_fov),
				GEO_OPEN_NODE(),
					GEO_CAMERA(14, 0, 2000, 6000, 0, 0, 0, geo_camera_preset_and_pos),
					GEO_OPEN_NODE(),
						GEO_OPEN_NODE(),
							GEO_ANIMATED_PART(1, 0, 0, 0, world_mesh),
							GEO_OPEN_NODE(),
								GEO_TRANSLATE_ROTATE(1, 0, 0, 0, -90, 0, 0),
								GEO_OPEN_NODE(),
									GEO_ANIMATED_PART(5, 0, 0, 0, death_mesh),
								GEO_CLOSE_NODE(),
								GEO_TRANSLATE_ROTATE(1, 0, 0, 0, -90, 0, 0),
								GEO_OPEN_NODE(),
									GEO_ANIMATED_PART(1, 0, 0, 0, island_mesh),
								GEO_CLOSE_NODE(),
								GEO_TRANSLATE_ROTATE(1, 0, 0, 0, -90, 0, 0),
								GEO_OPEN_NODE(),
									GEO_ANIMATED_PART(7, 0, 0, 0, water_mesh),
								GEO_CLOSE_NODE(),
								GEO_TRANSLATE_ROTATE(1, 0, 0, 0, -90, 0, 0),
								GEO_OPEN_NODE(),
									GEO_ANIMATED_PART(5, 0, 0, 0, waterfall_mesh),
								GEO_CLOSE_NODE(),
							GEO_CLOSE_NODE(),
						GEO_CLOSE_NODE(),
						GEO_DISPLAY_LIST(0, material_revert_render_settings),
						GEO_DISPLAY_LIST(1, material_revert_render_settings),
						GEO_DISPLAY_LIST(2, material_revert_render_settings),
						GEO_DISPLAY_LIST(3, material_revert_render_settings),
						GEO_DISPLAY_LIST(4, material_revert_render_settings),
						GEO_DISPLAY_LIST(5, material_revert_render_settings),
						GEO_DISPLAY_LIST(6, material_revert_render_settings),
						GEO_DISPLAY_LIST(7, material_revert_render_settings),
						GEO_ASM(         0, geo_movtex_pause_control),
						GEO_RENDER_OBJ(), // To here
						GEO_ASM(0, geo_enfvx_main),
					GEO_CLOSE_NODE(),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
   GEO_END(),
};