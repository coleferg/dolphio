#include "src/game/envfx_snow.h"

const GeoLayout lizard_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SHADOW(0, 135, 65),
		GEO_OPEN_NODE(),
			GEO_SCALE(0, 98304),
			GEO_OPEN_NODE(),
				GEO_NODE_START(),
				GEO_OPEN_NODE(),
					GEO_TRANSLATE_ROTATE(1, 0, 0, 0, 0, 90, 0),
					GEO_OPEN_NODE(),
						GEO_ANIMATED_PART(1, 0, 0, 0, NULL),
						GEO_OPEN_NODE(),
							GEO_ANIMATED_PART(1, 0, 73, 0, NULL),
							GEO_OPEN_NODE(),
								GEO_TRANSLATE_ROTATE(1, 0, 11, 0, -92, 90, 0),
								GEO_OPEN_NODE(),
									GEO_ANIMATED_PART(1, 0, 0, 0, NULL),
									GEO_OPEN_NODE(),
										GEO_TRANSLATE_ROTATE(1, 0, 135, 0, -175, 0, 0),
										GEO_OPEN_NODE(),
											GEO_ANIMATED_PART(1, 0, 0, 0, NULL),
											GEO_OPEN_NODE(),
												GEO_TRANSLATE_ROTATE(1, 0, 135, 0, -93, 0, 0),
												GEO_OPEN_NODE(),
													GEO_ANIMATED_PART(1, 0, 0, 0, lizard_lizard_waist_mesh),
													GEO_OPEN_NODE(),
														GEO_DISPLAY_LIST(1, lizard_lizard_body_skinned),
														GEO_ANIMATED_PART(1, 0, 17, 0, lizard_lizard_body_mesh),
														GEO_OPEN_NODE(),
															GEO_DISPLAY_LIST(1, lizard_lizard_shoulders_skinned),
															GEO_TRANSLATE_ROTATE(1, 0, 55, 0, 0, 180, 0),
															GEO_OPEN_NODE(),
																GEO_ANIMATED_PART(1, 0, 0, 0, lizard_lizard_shoulders_mesh),
																GEO_OPEN_NODE(),
																	GEO_TRANSLATE_ROTATE(1, 0, 18, 0, -3, -180, 0),
																	GEO_OPEN_NODE(),
																		GEO_ANIMATED_PART(1, 0, 0, 0, NULL),
																		GEO_OPEN_NODE(),
																			GEO_DISPLAY_LIST(1, lizard_lizard_frill_l_skinned),
																			GEO_TRANSLATE_ROTATE(1, 0, 15, 0, -90, 0, 90),
																			GEO_OPEN_NODE(),
																				GEO_ANIMATED_PART(1, 0, 0, 0, lizard_lizard_frill_l_mesh),
																			GEO_CLOSE_NODE(),
																			GEO_DISPLAY_LIST(1, lizard_lizard_frill_r_skinned),
																			GEO_TRANSLATE_ROTATE(1, 0, 15, 0, -90, 0, -90),
																			GEO_OPEN_NODE(),
																				GEO_ANIMATED_PART(1, 0, 0, 0, lizard_lizard_frill_r_mesh),
																			GEO_CLOSE_NODE(),
																		GEO_CLOSE_NODE(),
																	GEO_CLOSE_NODE(),
																	GEO_DISPLAY_LIST(1, lizard_lizard_head_skinned),
																	GEO_TRANSLATE_ROTATE(1, 0, 18, 0, -3, -180, 0),
																	GEO_OPEN_NODE(),
																		GEO_ANIMATED_PART(1, 0, 0, 0, lizard_lizard_head_mesh),
																		GEO_OPEN_NODE(),
																			GEO_DISPLAY_LIST(1, lizard_lizard_jaw_skinned),
																			GEO_TRANSLATE_ROTATE(1, 0, 7, -4, -80, 0, 0),
																			GEO_OPEN_NODE(),
																				GEO_ANIMATED_PART(1, 0, 0, 0, lizard_lizard_jaw_mesh),
																			GEO_CLOSE_NODE(),
																		GEO_CLOSE_NODE(),
																	GEO_CLOSE_NODE(),
																	GEO_DISPLAY_LIST(1, lizard_lizard_arm_l_skinned),
																	GEO_TRANSLATE_ROTATE(1, 0, 18, 0, -121, -95, 0),
																	GEO_OPEN_NODE(),
																		GEO_ANIMATED_PART(1, 0, 0, 0, NULL),
																		GEO_OPEN_NODE(),
																			GEO_TRANSLATE_ROTATE(1, 0, 25, 0, -31, 170, 0),
																			GEO_OPEN_NODE(),
																				GEO_ANIMATED_PART(1, 0, 0, 0, lizard_lizard_arm_l_mesh),
																				GEO_OPEN_NODE(),
																					GEO_DISPLAY_LIST(1, lizard_lizard_elbow_l_skinned),
																					GEO_TRANSLATE_ROTATE(1, 0, 29, 0, -4, 126, 0),
																					GEO_OPEN_NODE(),
																						GEO_ANIMATED_PART(1, 0, 0, 0, lizard_lizard_elbow_l_mesh),
																						GEO_OPEN_NODE(),
																							GEO_DISPLAY_LIST(1, lizard_lizard_hand_l_skinned),
																							GEO_TRANSLATE_ROTATE(1, 0, 23, 0, -5, -175, 0),
																							GEO_OPEN_NODE(),
																								GEO_ANIMATED_PART(1, 0, 0, 0, lizard_lizard_hand_l_mesh),
																							GEO_CLOSE_NODE(),
																						GEO_CLOSE_NODE(),
																					GEO_CLOSE_NODE(),
																				GEO_CLOSE_NODE(),
																			GEO_CLOSE_NODE(),
																		GEO_CLOSE_NODE(),
																	GEO_CLOSE_NODE(),
																	GEO_DISPLAY_LIST(1, lizard_lizard_arm_r_skinned),
																	GEO_TRANSLATE_ROTATE(1, 0, 18, 0, -121, 95, 0),
																	GEO_OPEN_NODE(),
																		GEO_ANIMATED_PART(1, 0, 0, 0, NULL),
																		GEO_OPEN_NODE(),
																			GEO_TRANSLATE_ROTATE(1, 0, 25, 0, -31, -170, 0),
																			GEO_OPEN_NODE(),
																				GEO_ANIMATED_PART(1, 0, 0, 0, lizard_lizard_arm_r_mesh),
																				GEO_OPEN_NODE(),
																					GEO_DISPLAY_LIST(1, lizard_lizard_elbow_r_skinned),
																					GEO_TRANSLATE_ROTATE(1, 0, 29, 0, -4, -126, 0),
																					GEO_OPEN_NODE(),
																						GEO_ANIMATED_PART(1, 0, 0, 0, lizard_lizard_elbow_r_mesh),
																						GEO_OPEN_NODE(),
																							GEO_DISPLAY_LIST(1, lizard_lizard_hand_r_skinned),
																							GEO_TRANSLATE_ROTATE(1, 0, 23, 0, -5, 175, 0),
																							GEO_OPEN_NODE(),
																								GEO_ANIMATED_PART(1, 0, 0, 0, lizard_lizard_hand_r_mesh),
																							GEO_CLOSE_NODE(),
																						GEO_CLOSE_NODE(),
																					GEO_CLOSE_NODE(),
																				GEO_CLOSE_NODE(),
																			GEO_CLOSE_NODE(),
																		GEO_CLOSE_NODE(),
																	GEO_CLOSE_NODE(),
																GEO_CLOSE_NODE(),
															GEO_CLOSE_NODE(),
														GEO_CLOSE_NODE(),
														GEO_DISPLAY_LIST(1, lizard_lizard_tail_skinned),
														GEO_TRANSLATE_ROTATE(1, 0, 4, 5, -83, 180, 0),
														GEO_OPEN_NODE(),
															GEO_ANIMATED_PART(1, 0, 0, 0, lizard_lizard_tail_mesh),
															GEO_OPEN_NODE(),
																GEO_DISPLAY_LIST(1, lizard_lizard_tail_low_skinned),
																GEO_TRANSLATE_ROTATE(1, 0, 50, 0, -13, 0, 0),
																GEO_OPEN_NODE(),
																	GEO_ANIMATED_PART(1, 0, 0, 0, lizard_lizard_tail_low_mesh),
																	GEO_OPEN_NODE(),
																		GEO_DISPLAY_LIST(1, lizard_lizard_tail_tip_skinned),
																		GEO_TRANSLATE_ROTATE(1, 0, 42, 0, -29, -180, 0),
																		GEO_OPEN_NODE(),
																			GEO_ANIMATED_PART(1, 0, 0, 0, lizard_lizard_tail_tip_mesh),
																		GEO_CLOSE_NODE(),
																	GEO_CLOSE_NODE(),
																GEO_CLOSE_NODE(),
															GEO_CLOSE_NODE(),
														GEO_CLOSE_NODE(),
														GEO_DISPLAY_LIST(1, lizard_lizard_thigh_l_skinned),
														GEO_TRANSLATE_ROTATE(1, 0, 17, 0, -152, 90, 0),
														GEO_OPEN_NODE(),
															GEO_ANIMATED_PART(1, 0, 0, 0, lizard_lizard_thigh_l_mesh),
															GEO_OPEN_NODE(),
																GEO_DISPLAY_LIST(1, lizard_lizard_leg_l_skinned),
																GEO_TRANSLATE_ROTATE(1, 0, 50, 0, -26, 0, 0),
																GEO_OPEN_NODE(),
																	GEO_ANIMATED_PART(1, 0, 0, 0, lizard_lizard_leg_l_mesh),
																	GEO_OPEN_NODE(),
																		GEO_DISPLAY_LIST(1, lizard_lizard_foot_l_skinned),
																		GEO_TRANSLATE_ROTATE(1, 0, 43, 0, -75, -107, 0),
																		GEO_OPEN_NODE(),
																			GEO_ANIMATED_PART(1, 0, 0, 0, lizard_lizard_foot_l_mesh),
																		GEO_CLOSE_NODE(),
																	GEO_CLOSE_NODE(),
																GEO_CLOSE_NODE(),
															GEO_CLOSE_NODE(),
														GEO_CLOSE_NODE(),
														GEO_DISPLAY_LIST(1, lizard_lizard_thigh_r_skinned),
														GEO_TRANSLATE_ROTATE(1, 0, 17, 0, -152, -90, 0),
														GEO_OPEN_NODE(),
															GEO_ANIMATED_PART(1, 0, 0, 0, lizard_lizard_thigh_r_mesh),
															GEO_OPEN_NODE(),
																GEO_DISPLAY_LIST(1, lizard_lizard_leg_r_skinned),
																GEO_TRANSLATE_ROTATE(1, 0, 50, 0, -26, 0, 0),
																GEO_OPEN_NODE(),
																	GEO_ANIMATED_PART(1, 0, 0, 0, lizard_lizard_leg_r_mesh),
																	GEO_OPEN_NODE(),
																		GEO_DISPLAY_LIST(1, lizard_lizard_foot_r_skinned),
																		GEO_TRANSLATE_ROTATE(1, 0, 43, 0, -75, 107, 0),
																		GEO_OPEN_NODE(),
																			GEO_ANIMATED_PART(1, 0, 0, 0, lizard_lizard_foot_r_mesh),
																		GEO_CLOSE_NODE(),
																	GEO_CLOSE_NODE(),
																GEO_CLOSE_NODE(),
															GEO_CLOSE_NODE(),
														GEO_CLOSE_NODE(),
													GEO_CLOSE_NODE(),
												GEO_CLOSE_NODE(),
											GEO_CLOSE_NODE(),
										GEO_CLOSE_NODE(),
									GEO_CLOSE_NODE(),
								GEO_CLOSE_NODE(),
							GEO_CLOSE_NODE(),
						GEO_CLOSE_NODE(),
					GEO_CLOSE_NODE(),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(0, lizard_material_revert_render_settings),
		GEO_DISPLAY_LIST(1, lizard_material_revert_render_settings),
		GEO_DISPLAY_LIST(2, lizard_material_revert_render_settings),
		GEO_DISPLAY_LIST(3, lizard_material_revert_render_settings),
		GEO_DISPLAY_LIST(4, lizard_material_revert_render_settings),
		GEO_DISPLAY_LIST(5, lizard_material_revert_render_settings),
		GEO_DISPLAY_LIST(6, lizard_material_revert_render_settings),
		GEO_DISPLAY_LIST(7, lizard_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};