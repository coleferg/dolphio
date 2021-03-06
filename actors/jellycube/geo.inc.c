#include "src/game/envfx_snow.h"

const GeoLayout jellycube_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SCALE(LAYER_TRANSPARENT, 65536),
		GEO_OPEN_NODE(),
			GEO_SHADOW(11, 51, 600),
			GEO_OPEN_NODE(),
				GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, NULL),
				GEO_OPEN_NODE(),
					GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, jellycube_bottom_mesh),
					GEO_OPEN_NODE(),
						GEO_DISPLAY_LIST(LAYER_TRANSPARENT, jellycube_midbottom_skinned),
						GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, jellycube_midbottom_mesh),
						GEO_OPEN_NODE(),
							GEO_DISPLAY_LIST(LAYER_TRANSPARENT, jellycube_midtop_skinned),
							GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, jellycube_midtop_mesh),
							GEO_OPEN_NODE(),
								GEO_DISPLAY_LIST(LAYER_TRANSPARENT, jellycube_top_skinned),
								GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, jellycube_top_mesh),
							GEO_CLOSE_NODE(),
						GEO_CLOSE_NODE(),
					GEO_CLOSE_NODE(),
					GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, NULL),
					GEO_OPEN_NODE(),
						GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, jellycube_bubs_mesh),
					GEO_CLOSE_NODE(),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, jellycube_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
