#include "GMLuaAutogenScript.h"

void RegisterScripts(lua_State* _pL) {
	lua_register(_pL, "GMLScript_macros", lua_Script_macros);
	lua_register(_pL, "GMLScript_action_end_game", lua_Script_action_end_game);
	lua_register(_pL, "GMLScript_action_inherited", lua_Script_action_inherited);
	lua_register(_pL, "GMLScript___init_action", lua_Script___init_action);
	lua_register(_pL, "GMLScript_background_get_height", lua_Script_background_get_height);
	lua_register(_pL, "GMLScript_background_get_width", lua_Script_background_get_width);
	lua_register(_pL, "GMLScript___init_background", lua_Script___init_background);
	lua_register(_pL, "GMLScript_draw_set_blend_mode", lua_Script_draw_set_blend_mode);
	lua_register(_pL, "GMLScript_instance_create", lua_Script_instance_create);
	lua_register(_pL, "GMLScript_object_get_depth", lua_Script_object_get_depth);
	lua_register(_pL, "GMLScript_tile_add", lua_Script_tile_add);
	lua_register(_pL, "GMLScript_tile_exists", lua_Script_tile_exists);
	lua_register(_pL, "GMLScript_tile_get_background", lua_Script_tile_get_background);
	lua_register(_pL, "GMLScript_tile_get_height", lua_Script_tile_get_height);
	lua_register(_pL, "GMLScript_tile_get_left", lua_Script_tile_get_left);
	lua_register(_pL, "GMLScript_tile_get_top", lua_Script_tile_get_top);
	lua_register(_pL, "GMLScript_tile_get_width", lua_Script_tile_get_width);
	lua_register(_pL, "GMLScript_tile_layer_delete", lua_Script_tile_layer_delete);
	lua_register(_pL, "GMLScript_tile_layer_find", lua_Script_tile_layer_find);
	lua_register(_pL, "GMLScript_tile_layer_shift", lua_Script_tile_layer_shift);
	lua_register(_pL, "GMLScript_tile_set_scale", lua_Script_tile_set_scale);
	lua_register(_pL, "GMLScript___view_get", lua_Script___view_get);
	lua_register(_pL, "GMLScript___view_set", lua_Script___view_set);
	lua_register(_pL, "GMLScript___view_set_internal", lua_Script___view_set_internal);
	lua_register(_pL, "GMLScript___init_view", lua_Script___init_view);
	lua_register(_pL, "GMLScript___global_object_depths", lua_Script___global_object_depths);
	lua_register(_pL, "GMLScript___init_global", lua_Script___init_global);
	lua_register(_pL, "GMLScript_inside_screen", lua_Script_inside_screen);
	lua_register(_pL, "GMLScript_inside_stage", lua_Script_inside_stage);
	lua_register(_pL, "GMLScript_inside_screen_point", lua_Script_inside_screen_point);
	lua_register(_pL, "GMLScript_inside_screen_line", lua_Script_inside_screen_line);
	lua_register(_pL, "GMLScript_inside_camera", lua_Script_inside_camera);
	lua_register(_pL, "GMLScript_level_y", lua_Script_level_y);
	lua_register(_pL, "GMLScript_set_level", lua_Script_set_level);
	lua_register(_pL, "GMLScript_actor_init", lua_Script_actor_init);
	lua_register(_pL, "GMLScript_animation_init", lua_Script_animation_init);
	lua_register(_pL, "GMLScript_begin_animation", lua_Script_begin_animation);
	lua_register(_pL, "GMLScript_animation_code", lua_Script_animation_code);
	lua_register(_pL, "GMLScript_player_idle_ground", lua_Script_player_idle_ground);
	lua_register(_pL, "GMLScript_player_moving_ground", lua_Script_player_moving_ground);
	lua_register(_pL, "GMLScript_player_walking", lua_Script_player_walking);
	lua_register(_pL, "GMLScript_player_casual_walking", lua_Script_player_casual_walking);
	lua_register(_pL, "GMLScript_player_casual_walking_old", lua_Script_player_casual_walking_old);
	lua_register(_pL, "GMLScript_player_walljump", lua_Script_player_walljump);
	lua_register(_pL, "GMLScript_player_wallgrab", lua_Script_player_wallgrab);
	lua_register(_pL, "GMLScript_player_crouching", lua_Script_player_crouching);
	lua_register(_pL, "GMLScript_player_flying", lua_Script_player_flying);
	lua_register(_pL, "GMLScript_player_air", lua_Script_player_air);
	lua_register(_pL, "GMLScript_player_bullettime_check", lua_Script_player_bullettime_check);
	lua_register(_pL, "GMLScript_player_block_check", lua_Script_player_block_check);
	lua_register(_pL, "GMLScript_player_secondary", lua_Script_player_secondary);
	lua_register(_pL, "GMLScript_player_cable_control", lua_Script_player_cable_control);
	lua_register(_pL, "GMLScript_player_electromagnet", lua_Script_player_electromagnet);
	lua_register(_pL, "GMLScript_get_electromagnet_direction", lua_Script_get_electromagnet_direction);
	lua_register(_pL, "GMLScript_player_flamethrower", lua_Script_player_flamethrower);
	lua_register(_pL, "GMLScript_get_flamethrower_direction", lua_Script_get_flamethrower_direction);
	lua_register(_pL, "GMLScript_player_shoot_cable", lua_Script_player_shoot_cable);
	lua_register(_pL, "GMLScript_player_throw", lua_Script_player_throw);
	lua_register(_pL, "GMLScript_player_blocking", lua_Script_player_blocking);
	lua_register(_pL, "GMLScript_player_attack_check", lua_Script_player_attack_check);
	lua_register(_pL, "GMLScript_player_attack_check_old", lua_Script_player_attack_check_old);
	lua_register(_pL, "GMLScript_player_attack", lua_Script_player_attack);
	lua_register(_pL, "GMLScript_player_doorbreak", lua_Script_player_doorbreak);
	lua_register(_pL, "GMLScript_player_hurtfly", lua_Script_player_hurtfly);
	lua_register(_pL, "GMLScript_player_hurtfall", lua_Script_player_hurtfall);
	lua_register(_pL, "GMLScript_player_hurtground", lua_Script_player_hurtground);
	lua_register(_pL, "GMLScript_player_recover", lua_Script_player_recover);
	lua_register(_pL, "GMLScript_player_rolling", lua_Script_player_rolling);
	lua_register(_pL, "GMLScript_player_airdodge", lua_Script_player_airdodge);
	lua_register(_pL, "GMLScript_player_swapitem", lua_Script_player_swapitem);
	lua_register(_pL, "GMLScript_player_quickswap", lua_Script_player_quickswap);
	lua_register(_pL, "GMLScript_player_dead", lua_Script_player_dead);
	lua_register(_pL, "GMLScript_player_freeze", lua_Script_player_freeze);
	lua_register(_pL, "GMLScript_player_bikethrow", lua_Script_player_bikethrow);
	lua_register(_pL, "GMLScript_player_secondary_dragon", lua_Script_player_secondary_dragon);
	lua_register(_pL, "GMLScript_player_draw_cableholdUI", lua_Script_player_draw_cableholdUI);
	lua_register(_pL, "GMLScript_player_analogue_pressed_check", lua_Script_player_analogue_pressed_check);
	lua_register(_pL, "GMLScript_player_input", lua_Script_player_input);
	lua_register(_pL, "GMLScript_player_hurt", lua_Script_player_hurt);
	lua_register(_pL, "GMLScript_kill_player", lua_Script_kill_player);
	lua_register(_pL, "GMLScript_slash_hit", lua_Script_slash_hit);
	lua_register(_pL, "GMLScript_bullet_hit", lua_Script_bullet_hit);
	lua_register(_pL, "GMLScript_explosion_hit", lua_Script_explosion_hit);
	lua_register(_pL, "GMLScript_player_physics", lua_Script_player_physics);
	lua_register(_pL, "GMLScript_player_ragdoll", lua_Script_player_ragdoll);
	lua_register(_pL, "GMLScript_freeze_player", lua_Script_freeze_player);
	lua_register(_pL, "GMLScript_draw_player", lua_Script_draw_player);
	lua_register(_pL, "GMLScript_draw_player_slowdown", lua_Script_draw_player_slowdown);
	lua_register(_pL, "GMLScript_player_animation", lua_Script_player_animation);
	lua_register(_pL, "GMLScript_player_get_throwdirection", lua_Script_player_get_throwdirection);
	lua_register(_pL, "GMLScript_player_get_attackdirection", lua_Script_player_get_attackdirection);
	lua_register(_pL, "GMLScript_move_contact_layer_solid", lua_Script_move_contact_layer_solid);
	lua_register(_pL, "GMLScript_move_contact_layer", lua_Script_move_contact_layer);
	lua_register(_pL, "GMLScript_ground_meeting", lua_Script_ground_meeting);
	lua_register(_pL, "GMLScript_jumpdown_meeting", lua_Script_jumpdown_meeting);
	lua_register(_pL, "GMLScript_block_meeting", lua_Script_block_meeting);
	lua_register(_pL, "GMLScript_floor_check", lua_Script_floor_check);
	lua_register(_pL, "GMLScript_wall_check", lua_Script_wall_check);
	lua_register(_pL, "GMLScript_ceiling_check", lua_Script_ceiling_check);
	lua_register(_pL, "GMLScript_slope_check", lua_Script_slope_check);
	lua_register(_pL, "GMLScript_ragdoll_physics", lua_Script_ragdoll_physics);
	lua_register(_pL, "GMLScript_slope_land_check", lua_Script_slope_land_check);
	lua_register(_pL, "GMLScript_on_a_slope", lua_Script_on_a_slope);
	lua_register(_pL, "GMLScript_AI_physics", lua_Script_AI_physics);
	lua_register(_pL, "GMLScript_create_node", lua_Script_create_node);
	lua_register(_pL, "GMLScript_create_link", lua_Script_create_link);
	lua_register(_pL, "GMLScript_softbody_constraint", lua_Script_softbody_constraint);
	lua_register(_pL, "GMLScript_softbody_constraint_strong", lua_Script_softbody_constraint_strong);
	lua_register(_pL, "GMLScript_momentum_add", lua_Script_momentum_add);
	lua_register(_pL, "GMLScript_place_meeting_radius_dir", lua_Script_place_meeting_radius_dir);
	lua_register(_pL, "GMLScript_place_meeting_radius", lua_Script_place_meeting_radius);
	lua_register(_pL, "GMLScript_create_popuptext", lua_Script_create_popuptext);
	lua_register(_pL, "GMLScript_check_light_collision", lua_Script_check_light_collision);
	lua_register(_pL, "GMLScript_check_light_collision_new", lua_Script_check_light_collision_new);
	lua_register(_pL, "GMLScript_draw_flashlight", lua_Script_draw_flashlight);
	lua_register(_pL, "GMLScript_timer_to_string", lua_Script_timer_to_string);
	lua_register(_pL, "GMLScript_play_sound_materialbounce", lua_Script_play_sound_materialbounce);
	lua_register(_pL, "GMLScript_draw_sprite_sway", lua_Script_draw_sprite_sway);
	lua_register(_pL, "GMLScript_draw_sprite_wavy", lua_Script_draw_sprite_wavy);
	lua_register(_pL, "GMLScript_draw_sprite_wavy_random", lua_Script_draw_sprite_wavy_random);
	lua_register(_pL, "GMLScript_tile_layer_move_init", lua_Script_tile_layer_move_init);
	lua_register(_pL, "GMLScript_tile_layer_move", lua_Script_tile_layer_move);
	lua_register(_pL, "GMLScript_draw_vcig", lua_Script_draw_vcig);
	lua_register(_pL, "GMLScript_draw_minecart", lua_Script_draw_minecart);
	lua_register(_pL, "GMLScript_draw_rail", lua_Script_draw_rail);
	lua_register(_pL, "GMLScript_get_pulse", lua_Script_get_pulse);
	lua_register(_pL, "GMLScript_pulse_init", lua_Script_pulse_init);
	lua_register(_pL, "GMLScript_draw_rail_bottom", lua_Script_draw_rail_bottom);
	lua_register(_pL, "GMLScript_draw_laser", lua_Script_draw_laser);
	lua_register(_pL, "GMLScript_draw_laser_horizontal", lua_Script_draw_laser_horizontal);
	lua_register(_pL, "GMLScript_draw_line_dotted", lua_Script_draw_line_dotted);
	lua_register(_pL, "GMLScript_draw_line_dotted_radius", lua_Script_draw_line_dotted_radius);
	lua_register(_pL, "GMLScript_draw_line_dotted_inconsistent", lua_Script_draw_line_dotted_inconsistent);
	lua_register(_pL, "GMLScript_dissolve_sprite", lua_Script_dissolve_sprite);
	lua_register(_pL, "GMLScript_show_hint", lua_Script_show_hint);
	lua_register(_pL, "GMLScript_create_motion_trail", lua_Script_create_motion_trail);
	lua_register(_pL, "GMLScript_create_motion_trail_bg", lua_Script_create_motion_trail_bg);
	lua_register(_pL, "GMLScript_create_static_trail", lua_Script_create_static_trail);
	lua_register(_pL, "GMLScript_create_motion_trail_bg_growing", lua_Script_create_motion_trail_bg_growing);
	lua_register(_pL, "GMLScript_tile_bump_map", lua_Script_tile_bump_map);
	lua_register(_pL, "GMLScript_tile_blood_map", lua_Script_tile_blood_map);
	lua_register(_pL, "GMLScript_create_dust", lua_Script_create_dust);
	lua_register(_pL, "GMLScript_create_dust_var", lua_Script_create_dust_var);
	lua_register(_pL, "GMLScript_create_trail", lua_Script_create_trail);
	lua_register(_pL, "GMLScript_create_fade", lua_Script_create_fade);
	lua_register(_pL, "GMLScript_create_flash", lua_Script_create_flash);
	lua_register(_pL, "GMLScript_create_memory_flash", lua_Script_create_memory_flash);
	lua_register(_pL, "GMLScript_draw_sprite_recolored", lua_Script_draw_sprite_recolored);
	lua_register(_pL, "GMLScript_draw_sprite_recolored_old_2", lua_Script_draw_sprite_recolored_old_2);
	lua_register(_pL, "GMLScript_draw_sprite_recolored_debug", lua_Script_draw_sprite_recolored_debug);
	lua_register(_pL, "GMLScript_draw_sprite_recolored_old", lua_Script_draw_sprite_recolored_old);
	lua_register(_pL, "GMLScript_draw_surface_recolored", lua_Script_draw_surface_recolored);
	lua_register(_pL, "GMLScript_draw_surface_recolored_old", lua_Script_draw_surface_recolored_old);
	lua_register(_pL, "GMLScript_draw_sprite_existing_surface", lua_Script_draw_sprite_existing_surface);
	lua_register(_pL, "GMLScript_draw_rim_shading_surface", lua_Script_draw_rim_shading_surface);
	lua_register(_pL, "GMLScript_draw_rim_shading_surface_unbatched", lua_Script_draw_rim_shading_surface_unbatched);
	lua_register(_pL, "GMLScript_draw_rim_shading_surface_object", lua_Script_draw_rim_shading_surface_object);
	lua_register(_pL, "GMLScript_draw_recolor_init", lua_Script_draw_recolor_init);
	lua_register(_pL, "GMLScript_screen_shake_dir", lua_Script_screen_shake_dir);
	lua_register(_pL, "GMLScript_screen_shake", lua_Script_screen_shake);
	lua_register(_pL, "GMLScript_screen_freeze", lua_Script_screen_freeze);
	lua_register(_pL, "GMLScript_club_script", lua_Script_club_script);
	lua_register(_pL, "GMLScript_add_bloodtile", lua_Script_add_bloodtile);
	lua_register(_pL, "GMLScript_draw_bg_parallax", lua_Script_draw_bg_parallax);
	lua_register(_pL, "GMLScript_draw_sprite_parallax", lua_Script_draw_sprite_parallax);
	lua_register(_pL, "GMLScript_record_me", lua_Script_record_me);
	lua_register(_pL, "GMLScript_draw_rim_shading", lua_Script_draw_rim_shading);
	lua_register(_pL, "GMLScript_draw_sprite_surface", lua_Script_draw_sprite_surface);
	lua_register(_pL, "GMLScript_draw_beam_fragment", lua_Script_draw_beam_fragment);
	lua_register(_pL, "GMLScript_draw_lightning", lua_Script_draw_lightning);
	lua_register(_pL, "GMLScript_fastmerge_col", lua_Script_fastmerge_col);
	lua_register(_pL, "GMLScript_draw_static", lua_Script_draw_static);
	lua_register(_pL, "GMLScript_light_create", lua_Script_light_create);
	lua_register(_pL, "GMLScript_light_draw", lua_Script_light_draw);
	lua_register(_pL, "GMLScript_flashlight_create", lua_Script_flashlight_create);
	lua_register(_pL, "GMLScript_flashlight_draw", lua_Script_flashlight_draw);
	lua_register(_pL, "GMLScript_create_spriteswap", lua_Script_create_spriteswap);
	lua_register(_pL, "GMLScript_draw_semicircle", lua_Script_draw_semicircle);
	lua_register(_pL, "GMLScript_init_light_array", lua_Script_init_light_array);
	lua_register(_pL, "GMLScript_update_light_array", lua_Script_update_light_array);
	lua_register(_pL, "GMLScript_update_light_array_sorted", lua_Script_update_light_array_sorted);
	lua_register(_pL, "GMLScript_update_light_array_ext", lua_Script_update_light_array_ext);
	lua_register(_pL, "GMLScript_draw_shadow", lua_Script_draw_shadow);
	lua_register(_pL, "GMLScript_init_controls", lua_Script_init_controls);
	lua_register(_pL, "GMLScript_controller_check", lua_Script_controller_check);
	lua_register(_pL, "GMLScript_controller_check_ext", lua_Script_controller_check_ext);
	lua_register(_pL, "GMLScript_controller_check_pressed", lua_Script_controller_check_pressed);
	lua_register(_pL, "GMLScript_controller_check_pressed_ext", lua_Script_controller_check_pressed_ext);
	lua_register(_pL, "GMLScript_draw_control", lua_Script_draw_control);
	lua_register(_pL, "GMLScript_get_face_button_sprite", lua_Script_get_face_button_sprite);
	lua_register(_pL, "GMLScript_init_default_controls", lua_Script_init_default_controls);
	lua_register(_pL, "GMLScript_init_default_controls_options", lua_Script_init_default_controls_options);
	lua_register(_pL, "GMLScript_get_input", lua_Script_get_input);
	lua_register(_pL, "GMLScript_check_controls_valid", lua_Script_check_controls_valid);
	lua_register(_pL, "GMLScript_set_new_input", lua_Script_set_new_input);
	lua_register(_pL, "GMLScript_create_player", lua_Script_create_player);
	lua_register(_pL, "GMLScript_best_respawn", lua_Script_best_respawn);
	lua_register(_pL, "GMLScript_best_item_spawn", lua_Script_best_item_spawn);
	lua_register(_pL, "GMLScript_player_exists", lua_Script_player_exists);
	lua_register(_pL, "GMLScript_breathe_init", lua_Script_breathe_init);
	lua_register(_pL, "GMLScript_stealth_init", lua_Script_stealth_init);
	lua_register(_pL, "GMLScript_ai_add_special_animation", lua_Script_ai_add_special_animation);
	lua_register(_pL, "GMLScript_AI_init", lua_Script_AI_init);
	lua_register(_pL, "GMLScript_enemy_init_behaviour", lua_Script_enemy_init_behaviour);
	lua_register(_pL, "GMLScript_angle_distance", lua_Script_angle_distance);
	lua_register(_pL, "GMLScript_smoke_blocked", lua_Script_smoke_blocked);
	lua_register(_pL, "GMLScript_AI_can_shoot", lua_Script_AI_can_shoot);
	lua_register(_pL, "GMLScript_AI_see_player", lua_Script_AI_see_player);
	lua_register(_pL, "GMLScript_AI_line_of_sight", lua_Script_AI_line_of_sight);
	lua_register(_pL, "GMLScript_AI_hearing", lua_Script_AI_hearing);
	lua_register(_pL, "GMLScript_AI_object_in_sight", lua_Script_AI_object_in_sight);
	lua_register(_pL, "GMLScript_AI_aim", lua_Script_AI_aim);
	lua_register(_pL, "GMLScript_AI_move_aimer", lua_Script_AI_move_aimer);
	lua_register(_pL, "GMLScript_turret_line_of_sight", lua_Script_turret_line_of_sight);
	lua_register(_pL, "GMLScript_turret_aim", lua_Script_turret_aim);
	lua_register(_pL, "GMLScript_waypoint_compute", lua_Script_waypoint_compute);
	lua_register(_pL, "GMLScript_compute_path_new", lua_Script_compute_path_new);
	lua_register(_pL, "GMLScript_array_removefirst", lua_Script_array_removefirst);
	lua_register(_pL, "GMLScript_floor_above", lua_Script_floor_above);
	lua_register(_pL, "GMLScript_floor_below", lua_Script_floor_below);
	lua_register(_pL, "GMLScript_waypoint_compute_OLD", lua_Script_waypoint_compute_OLD);
	lua_register(_pL, "GMLScript_compute_path", lua_Script_compute_path);
	lua_register(_pL, "GMLScript_AI_find_waypoint_up", lua_Script_AI_find_waypoint_up);
	lua_register(_pL, "GMLScript_AI_find_waypoint_down", lua_Script_AI_find_waypoint_down);
	lua_register(_pL, "GMLScript_listen", lua_Script_listen);
	lua_register(_pL, "GMLScript_breathe", lua_Script_breathe);
	lua_register(_pL, "GMLScript_ai_set_hair", lua_Script_ai_set_hair);
	lua_register(_pL, "GMLScript_ai_set_gunpoint", lua_Script_ai_set_gunpoint);
	lua_register(_pL, "GMLScript_create_corpse", lua_Script_create_corpse);
	lua_register(_pL, "GMLScript_enemy_hurt", lua_Script_enemy_hurt);
	lua_register(_pL, "GMLScript_ai_aim_overlap", lua_Script_ai_aim_overlap);
	lua_register(_pL, "GMLScript_ai_shieldcop_vulnerablecheck", lua_Script_ai_shieldcop_vulnerablecheck);
	lua_register(_pL, "GMLScript_ai_overlap", lua_Script_ai_overlap);
	lua_register(_pL, "GMLScript_enemy_special_idle", lua_Script_enemy_special_idle);
	lua_register(_pL, "GMLScript_draw_enemy_icons", lua_Script_draw_enemy_icons);
	lua_register(_pL, "GMLScript_draw_enemy", lua_Script_draw_enemy);
	lua_register(_pL, "GMLScript_ai_find_soundsource", lua_Script_ai_find_soundsource);
	lua_register(_pL, "GMLScript_ai_state_control", lua_Script_ai_state_control);
	lua_register(_pL, "GMLScript_ai_idle_ground", lua_Script_ai_idle_ground);
	lua_register(_pL, "GMLScript_ai_idle_walking", lua_Script_ai_idle_walking);
	lua_register(_pL, "GMLScript_ai_break_idle", lua_Script_ai_break_idle);
	lua_register(_pL, "GMLScript_ai_update_target", lua_Script_ai_update_target);
	lua_register(_pL, "GMLScript_ai_check_stairdoor", lua_Script_ai_check_stairdoor);
	lua_register(_pL, "GMLScript_ai_running_actions", lua_Script_ai_running_actions);
	lua_register(_pL, "GMLScript_ai_check_for_trap", lua_Script_ai_check_for_trap);
	lua_register(_pL, "GMLScript_ai_check_for_flame", lua_Script_ai_check_for_flame);
	lua_register(_pL, "GMLScript_ai_check_for_edge", lua_Script_ai_check_for_edge);
	lua_register(_pL, "GMLScript_ai_aim_to_run", lua_Script_ai_aim_to_run);
	lua_register(_pL, "GMLScript_ai_runstall_to_run", lua_Script_ai_runstall_to_run);
	lua_register(_pL, "GMLScript_ai_open_door", lua_Script_ai_open_door);
	lua_register(_pL, "GMLScript_menu_step", lua_Script_menu_step);
	lua_register(_pL, "GMLScript_draw_crt_image", lua_Script_draw_crt_image);
	lua_register(_pL, "GMLScript_draw_crt_image_ext", lua_Script_draw_crt_image_ext);
	lua_register(_pL, "GMLScript_draw_crt_surface", lua_Script_draw_crt_surface);
	lua_register(_pL, "GMLScript_draw_sprite_distorted", lua_Script_draw_sprite_distorted);
	lua_register(_pL, "GMLScript_draw_sprite_distorted_logo", lua_Script_draw_sprite_distorted_logo);
	lua_register(_pL, "GMLScript_draw_distorted_surface", lua_Script_draw_distorted_surface);
	lua_register(_pL, "GMLScript_find_next_tape", lua_Script_find_next_tape);
	lua_register(_pL, "GMLScript_menu_init", lua_Script_menu_init);
	lua_register(_pL, "GMLScript_add_pausemenu_choice", lua_Script_add_pausemenu_choice);
	lua_register(_pL, "GMLScript_init_levelselect_data", lua_Script_init_levelselect_data);
	lua_register(_pL, "GMLScript_create_controls_menu", lua_Script_create_controls_menu);
	lua_register(_pL, "GMLScript_set_windowsize", lua_Script_set_windowsize);
	lua_register(_pL, "GMLScript_titlemenu_add_choice", lua_Script_titlemenu_add_choice);
	lua_register(_pL, "GMLScript_check_katana_unlocked", lua_Script_check_katana_unlocked);
	lua_register(_pL, "GMLScript_create_roomsfx", lua_Script_create_roomsfx);
	lua_register(_pL, "GMLScript_create_audio_looper", lua_Script_create_audio_looper);
	lua_register(_pL, "GMLScript_play_sound_basic", lua_Script_play_sound_basic);
	lua_register(_pL, "GMLScript_play_sound_ext", lua_Script_play_sound_ext);
	lua_register(_pL, "GMLScript_play_sound_pos", lua_Script_play_sound_pos);
	lua_register(_pL, "GMLScript_play_sound", lua_Script_play_sound);
	lua_register(_pL, "GMLScript_stop_music_sudden", lua_Script_stop_music_sudden);
	lua_register(_pL, "GMLScript_draw_itemicon", lua_Script_draw_itemicon);
	lua_register(_pL, "GMLScript_remove_doors", lua_Script_remove_doors);
	lua_register(_pL, "GMLScript_restore_doors", lua_Script_restore_doors);
	lua_register(_pL, "GMLScript_room_transition", lua_Script_room_transition);
	lua_register(_pL, "GMLScript_room_transition_fade", lua_Script_room_transition_fade);
	lua_register(_pL, "GMLScript_find_next_scene", lua_Script_find_next_scene);
	lua_register(_pL, "GMLScript_override_control_init", lua_Script_override_control_init);
	lua_register(_pL, "GMLScript_override_control_end", lua_Script_override_control_end);
	lua_register(_pL, "GMLScript_ds_grid_replace_all", lua_Script_ds_grid_replace_all);
	lua_register(_pL, "GMLScript_update_region", lua_Script_update_region);
	lua_register(_pL, "GMLScript_interact_binary", lua_Script_interact_binary);
	lua_register(_pL, "GMLScript_clear_screen", lua_Script_clear_screen);
	lua_register(_pL, "GMLScript_draw_text_outline_ext", lua_Script_draw_text_outline_ext);
	lua_register(_pL, "GMLScript_draw_text_glow_ext", lua_Script_draw_text_glow_ext);
	lua_register(_pL, "GMLScript_draw_fastline_width_col", lua_Script_draw_fastline_width_col);
	lua_register(_pL, "GMLScript_draw_bigcircle", lua_Script_draw_bigcircle);
	lua_register(_pL, "GMLScript_draw_fastcircle", lua_Script_draw_fastcircle);
	lua_register(_pL, "GMLScript_draw_lightsphere", lua_Script_draw_lightsphere);
	lua_register(_pL, "GMLScript_draw_rect_col", lua_Script_draw_rect_col);
	lua_register(_pL, "GMLScript_draw_circleui", lua_Script_draw_circleui);
	lua_register(_pL, "GMLScript_create_explosion", lua_Script_create_explosion);
	lua_register(_pL, "GMLScript_create_smokescreen", lua_Script_create_smokescreen);
	lua_register(_pL, "GMLScript_create_smoke", lua_Script_create_smoke);
	lua_register(_pL, "GMLScript_create_cutscene_camera", lua_Script_create_cutscene_camera);
	lua_register(_pL, "GMLScript_scr_level_complete", lua_Script_scr_level_complete);
	lua_register(_pL, "GMLScript_scr_level_complete_cut", lua_Script_scr_level_complete_cut);
	lua_register(_pL, "GMLScript_is_metal", lua_Script_is_metal);
	lua_register(_pL, "GMLScript_is_attractable", lua_Script_is_attractable);
	lua_register(_pL, "GMLScript_is_currently_attracted", lua_Script_is_currently_attracted);
	lua_register(_pL, "GMLScript_get_attract_strength", lua_Script_get_attract_strength);
	lua_register(_pL, "GMLScript_compute_attract_strength", lua_Script_compute_attract_strength);
	lua_register(_pL, "GMLScript_create_metal_projectile", lua_Script_create_metal_projectile);
	lua_register(_pL, "GMLScript_make_vhs_tape", lua_Script_make_vhs_tape);
	lua_register(_pL, "GMLScript_pipeline_draw", lua_Script_pipeline_draw);
	lua_register(_pL, "GMLScript_pipeline_grab_sprite_surface", lua_Script_pipeline_grab_sprite_surface);
	lua_register(_pL, "GMLScript_pipeline_color_surface", lua_Script_pipeline_color_surface);
	lua_register(_pL, "GMLScript_pipeline_rim_shading", lua_Script_pipeline_rim_shading);
	lua_register(_pL, "GMLScript_pipeline_draw_to_screen", lua_Script_pipeline_draw_to_screen);
	lua_register(_pL, "GMLScript_resolve_sound", lua_Script_resolve_sound);
	lua_register(_pL, "GMLScript_get_sound_vol", lua_Script_get_sound_vol);
	lua_register(_pL, "GMLScript_create_sound", lua_Script_create_sound);
	lua_register(_pL, "GMLScript_wallcam_compute_angle", lua_Script_wallcam_compute_angle);
	lua_register(_pL, "GMLScript_create_sound_floor", lua_Script_create_sound_floor);
	lua_register(_pL, "GMLScript_dialogue_init", lua_Script_dialogue_init);
	lua_register(_pL, "GMLScript_predictive_line_break_tags", lua_Script_predictive_line_break_tags);
	lua_register(_pL, "GMLScript_predictive_line_break_tags_asian", lua_Script_predictive_line_break_tags_asian);
	lua_register(_pL, "GMLScript_find_next_char", lua_Script_find_next_char);
	lua_register(_pL, "GMLScript_create_textbox_auto", lua_Script_create_textbox_auto);
	lua_register(_pL, "GMLScript_create_textbox", lua_Script_create_textbox);
	lua_register(_pL, "GMLScript_create_textbox_passive", lua_Script_create_textbox_passive);
	lua_register(_pL, "GMLScript_create_textbox_passive_auto", lua_Script_create_textbox_passive_auto);
	lua_register(_pL, "GMLScript_add_voiceover", lua_Script_add_voiceover);
	lua_register(_pL, "GMLScript_add_textsfx", lua_Script_add_textsfx);
	lua_register(_pL, "GMLScript_create_choicebox", lua_Script_create_choicebox);
	lua_register(_pL, "GMLScript_add_choice", lua_Script_add_choice);
	lua_register(_pL, "GMLScript_seen_state", lua_Script_seen_state);
	lua_register(_pL, "GMLScript_update_seen_states", lua_Script_update_seen_states);
	lua_register(_pL, "GMLScript_shift_textbox", lua_Script_shift_textbox);
	lua_register(_pL, "GMLScript_shift_textbox_arrow_horizontal", lua_Script_shift_textbox_arrow_horizontal);
	lua_register(_pL, "GMLScript_textbox_set_outline_color", lua_Script_textbox_set_outline_color);
	lua_register(_pL, "GMLScript_textbox_explode", lua_Script_textbox_explode);
	lua_register(_pL, "GMLScript_scr_addChoice", lua_Script_scr_addChoice);
	lua_register(_pL, "GMLScript_scr_addChoice_crossout", lua_Script_scr_addChoice_crossout);
	lua_register(_pL, "GMLScript_scr_addInterrupt", lua_Script_scr_addInterrupt);
	lua_register(_pL, "GMLScript_scr_addInterrupt_norepeat", lua_Script_scr_addInterrupt_norepeat);
	lua_register(_pL, "GMLScript_scr_addInterrupt_crossout", lua_Script_scr_addInterrupt_crossout);
	lua_register(_pL, "GMLScript_scr_addChoice_norepeat", lua_Script_scr_addChoice_norepeat);
	lua_register(_pL, "GMLScript_dialogue_1", lua_Script_dialogue_1);
	lua_register(_pL, "GMLScript_dialogue_factorysci_toosoon", lua_Script_dialogue_factorysci_toosoon);
	lua_register(_pL, "GMLScript_dialogue_factorysci", lua_Script_dialogue_factorysci);
	lua_register(_pL, "GMLScript_dialogue_factory_v", lua_Script_dialogue_factory_v);
	lua_register(_pL, "GMLScript_dialogue_factory_v_autokill", lua_Script_dialogue_factory_v_autokill);
	lua_register(_pL, "GMLScript_dialogue_receptionist", lua_Script_dialogue_receptionist);
	lua_register(_pL, "GMLScript_dialogue_lobby_cop", lua_Script_dialogue_lobby_cop);
	lua_register(_pL, "GMLScript_dialogue_receptionist_2", lua_Script_dialogue_receptionist_2);
	lua_register(_pL, "GMLScript_dialogue_gangster_1", lua_Script_dialogue_gangster_1);
	lua_register(_pL, "GMLScript_dialogue_penthouse", lua_Script_dialogue_penthouse);
	lua_register(_pL, "GMLScript_dialogue_club_2_tut1", lua_Script_dialogue_club_2_tut1);
	lua_register(_pL, "GMLScript_dialogue_club_2_tut2", lua_Script_dialogue_club_2_tut2);
	lua_register(_pL, "GMLScript_dialogue_club_run", lua_Script_dialogue_club_run);
	lua_register(_pL, "GMLScript_dialogue_club_phone", lua_Script_dialogue_club_phone);
	lua_register(_pL, "GMLScript_dialogue_club_electrohead", lua_Script_dialogue_club_electrohead);
	lua_register(_pL, "GMLScript_dialogue_prison_cops", lua_Script_dialogue_prison_cops);
	lua_register(_pL, "GMLScript_dialogue_prison_toiletguy", lua_Script_dialogue_prison_toiletguy);
	lua_register(_pL, "GMLScript_dialogue_prison_call", lua_Script_dialogue_prison_call);
	lua_register(_pL, "GMLScript_dialogue_prison_call_nochronos", lua_Script_dialogue_prison_call_nochronos);
	lua_register(_pL, "GMLScript_dialogue_homeless_vet", lua_Script_dialogue_homeless_vet);
	lua_register(_pL, "GMLScript_dialogue_studio_limo_outside", lua_Script_dialogue_studio_limo_outside);
	lua_register(_pL, "GMLScript_dialogue_studio_limo", lua_Script_dialogue_studio_limo);
	lua_register(_pL, "GMLScript_dialogue_haunted_vbreath", lua_Script_dialogue_haunted_vbreath);
	lua_register(_pL, "GMLScript_dialogue_haunted_vbreath_nosword", lua_Script_dialogue_haunted_vbreath_nosword);
	lua_register(_pL, "GMLScript_dialogue_studio_vphone", lua_Script_dialogue_studio_vphone);
	lua_register(_pL, "GMLScript_dialogue_studio_v1", lua_Script_dialogue_studio_v1);
	lua_register(_pL, "GMLScript_dialogue_studio_v2", lua_Script_dialogue_studio_v2);
	lua_register(_pL, "GMLScript_dialogue_studio_v3", lua_Script_dialogue_studio_v3);
	lua_register(_pL, "GMLScript_dialogue_haunted_elevator", lua_Script_dialogue_haunted_elevator);
	lua_register(_pL, "GMLScript_dialogue_studio_finale_1", lua_Script_dialogue_studio_finale_1);
	lua_register(_pL, "GMLScript_dialogue_studio_finale_4", lua_Script_dialogue_studio_finale_4);
	lua_register(_pL, "GMLScript_dialogue_studio_finale_5", lua_Script_dialogue_studio_finale_5);
	lua_register(_pL, "GMLScript_dialogue_studio_finale_6", lua_Script_dialogue_studio_finale_6);
	lua_register(_pL, "GMLScript_dialogue_tied_up", lua_Script_dialogue_tied_up);
	lua_register(_pL, "GMLScript_dialogue_mansion_outside", lua_Script_dialogue_mansion_outside);
	lua_register(_pL, "GMLScript_dialogue_mansion_outside_2", lua_Script_dialogue_mansion_outside_2);
	lua_register(_pL, "GMLScript_dialogue_mansion_kissyface_1", lua_Script_dialogue_mansion_kissyface_1);
	lua_register(_pL, "GMLScript_dialogue_mansion_kissyface_2", lua_Script_dialogue_mansion_kissyface_2);
	lua_register(_pL, "GMLScript_dialogue_mansion_v_death", lua_Script_dialogue_mansion_v_death);
	lua_register(_pL, "GMLScript_dialogue_chinatown_end_cops", lua_Script_dialogue_chinatown_end_cops);
	lua_register(_pL, "GMLScript_dialogue_chinatown_end_cops_fire", lua_Script_dialogue_chinatown_end_cops_fire);
	lua_register(_pL, "GMLScript_dialogue_chinatown_end_cops_die", lua_Script_dialogue_chinatown_end_cops_die);
	lua_register(_pL, "GMLScript_dialogue_chinatown_end_maskedmen_1", lua_Script_dialogue_chinatown_end_maskedmen_1);
	lua_register(_pL, "GMLScript_dialogue_chinatown_end_maskedmen_2", lua_Script_dialogue_chinatown_end_maskedmen_2);
	lua_register(_pL, "GMLScript_dialogue_chinatown_headhunter_dragon", lua_Script_dialogue_chinatown_headhunter_dragon);
	lua_register(_pL, "GMLScript_dialogue_chinatown_headhunter_2", lua_Script_dialogue_chinatown_headhunter_2);
	lua_register(_pL, "GMLScript_dialogue_chinatown_cops", lua_Script_dialogue_chinatown_cops);
	lua_register(_pL, "GMLScript_dialogue_chinatown_bouncer", lua_Script_dialogue_chinatown_bouncer);
	lua_register(_pL, "GMLScript_dialogue_chinatown_bouncer_2", lua_Script_dialogue_chinatown_bouncer_2);
	lua_register(_pL, "GMLScript_dialogue_chinatown_roulette_1", lua_Script_dialogue_chinatown_roulette_1);
	lua_register(_pL, "GMLScript_dialogue_chinatown_passive_cops", lua_Script_dialogue_chinatown_passive_cops);
	lua_register(_pL, "GMLScript_dialogue_dragon_cops_preentrance", lua_Script_dialogue_dragon_cops_preentrance);
	lua_register(_pL, "GMLScript_dialogue_dragon_entrance", lua_Script_dialogue_dragon_entrance);
	lua_register(_pL, "GMLScript_dialogue_dragon_fa_yuan", lua_Script_dialogue_dragon_fa_yuan);
	lua_register(_pL, "GMLScript_dialogue_mysterious_call", lua_Script_dialogue_mysterious_call);
	lua_register(_pL, "GMLScript_dialogue_sniper_1", lua_Script_dialogue_sniper_1);
	lua_register(_pL, "GMLScript_dialogue_sniper_2_fail", lua_Script_dialogue_sniper_2_fail);
	lua_register(_pL, "GMLScript_dialogue_sniper_2_success", lua_Script_dialogue_sniper_2_success);
	lua_register(_pL, "GMLScript_dialogue_sniper_3", lua_Script_dialogue_sniper_3);
	lua_register(_pL, "GMLScript_dialogue_sniper_wave0", lua_Script_dialogue_sniper_wave0);
	lua_register(_pL, "GMLScript_dialogue_sniper_wave_complete", lua_Script_dialogue_sniper_wave_complete);
	lua_register(_pL, "GMLScript_dialogue_sniper_4", lua_Script_dialogue_sniper_4);
	lua_register(_pL, "GMLScript_dialogue_sniper_5", lua_Script_dialogue_sniper_5);
	lua_register(_pL, "GMLScript_dialogue_sniper_6", lua_Script_dialogue_sniper_6);
	lua_register(_pL, "GMLScript_dialogue_sniper_fake_1", lua_Script_dialogue_sniper_fake_1);
	lua_register(_pL, "GMLScript_dialogue_sniper_fake_2", lua_Script_dialogue_sniper_fake_2);
	lua_register(_pL, "GMLScript_dialogue_sniper_fake_3", lua_Script_dialogue_sniper_fake_3);
	lua_register(_pL, "GMLScript_dialogue_sniper_fake_4", lua_Script_dialogue_sniper_fake_4);
	lua_register(_pL, "GMLScript_dialogue_sniper_fake_6", lua_Script_dialogue_sniper_fake_6);
	lua_register(_pL, "GMLScript_dialogue_sniper_fake_7", lua_Script_dialogue_sniper_fake_7);
	lua_register(_pL, "GMLScript_dialogue_sniper_fake_8", lua_Script_dialogue_sniper_fake_8);
	lua_register(_pL, "GMLScript_dialogue_sniper_fake_9", lua_Script_dialogue_sniper_fake_9);
	lua_register(_pL, "GMLScript_dialogue_leon_death", lua_Script_dialogue_leon_death);
	lua_register(_pL, "GMLScript_dialogue_bunker_receptionist", lua_Script_dialogue_bunker_receptionist);
	lua_register(_pL, "GMLScript_dialogue_bunker_receptionist_oldguy", lua_Script_dialogue_bunker_receptionist_oldguy);
	lua_register(_pL, "GMLScript_dialogue_bunker_headhunter_1", lua_Script_dialogue_bunker_headhunter_1);
	lua_register(_pL, "GMLScript_dialogue_bunker_headhunter_2", lua_Script_dialogue_bunker_headhunter_2);
	lua_register(_pL, "GMLScript_dialogue_bunker_headhunter_dying", lua_Script_dialogue_bunker_headhunter_dying);
	lua_register(_pL, "GMLScript_dialogue_bunker_access_denied", lua_Script_dialogue_bunker_access_denied);
	lua_register(_pL, "GMLScript_dialogue_bunker_end", lua_Script_dialogue_bunker_end);
	lua_register(_pL, "GMLScript_dialogue_headhunter_fight_1", lua_Script_dialogue_headhunter_fight_1);
	lua_register(_pL, "GMLScript_dialogue_headhunter_fight_2", lua_Script_dialogue_headhunter_fight_2);
	lua_register(_pL, "GMLScript_dialogue_headhunter_fight_3", lua_Script_dialogue_headhunter_fight_3);
	lua_register(_pL, "GMLScript_dialogue_govtlab_locked", lua_Script_dialogue_govtlab_locked);
	lua_register(_pL, "GMLScript_dialogue_girl_hallway_2", lua_Script_dialogue_girl_hallway_2);
	lua_register(_pL, "GMLScript_dialogue_girl_hallway_3", lua_Script_dialogue_girl_hallway_3);
	lua_register(_pL, "GMLScript_dialogue_girl_hallway_4", lua_Script_dialogue_girl_hallway_4);
	lua_register(_pL, "GMLScript_dialogue_girl_hallway_6", lua_Script_dialogue_girl_hallway_6);
	lua_register(_pL, "GMLScript_dialogue_girl_apartment_3_1", lua_Script_dialogue_girl_apartment_3_1);
	lua_register(_pL, "GMLScript_dialogue_girl_apartment_3_3", lua_Script_dialogue_girl_apartment_3_3);
	lua_register(_pL, "GMLScript_dialogue_girl_apartment_3_4", lua_Script_dialogue_girl_apartment_3_4);
	lua_register(_pL, "GMLScript_dialogue_girl_apartment_4_leavemovie", lua_Script_dialogue_girl_apartment_4_leavemovie);
	lua_register(_pL, "GMLScript_dialogue_apartment5_movie_girl", lua_Script_dialogue_apartment5_movie_girl);
	lua_register(_pL, "GMLScript_dialogue_apartment5_movie_solo", lua_Script_dialogue_apartment5_movie_solo);
	lua_register(_pL, "GMLScript_dialogue_girl_apartment_7_morning", lua_Script_dialogue_girl_apartment_7_morning);
	lua_register(_pL, "GMLScript_dialogue_girl_apartment_7_morning_2", lua_Script_dialogue_girl_apartment_7_morning_2);
	lua_register(_pL, "GMLScript_dialogue_girl_apartment_7_afternoon_1", lua_Script_dialogue_girl_apartment_7_afternoon_1);
	lua_register(_pL, "GMLScript_dialogue_girl_apartment_7_afternoon_2", lua_Script_dialogue_girl_apartment_7_afternoon_2);
	lua_register(_pL, "GMLScript_dialogue_girl_apartment_9_afternoon", lua_Script_dialogue_girl_apartment_9_afternoon);
	lua_register(_pL, "GMLScript_dialogue_girl_apartment_9_afternoon_rooftop_1", lua_Script_dialogue_girl_apartment_9_afternoon_rooftop_1);
	lua_register(_pL, "GMLScript_dialogue_girl_apartment_9_afternoon_rooftop_2", lua_Script_dialogue_girl_apartment_9_afternoon_rooftop_2);
	lua_register(_pL, "GMLScript_dialogue_girl_apartment_10", lua_Script_dialogue_girl_apartment_10);
	lua_register(_pL, "GMLScript_dialogue_girl_apartment_10_1", lua_Script_dialogue_girl_apartment_10_1);
	lua_register(_pL, "GMLScript_dialogue_girl_apartment_10_2", lua_Script_dialogue_girl_apartment_10_2);
	lua_register(_pL, "GMLScript_dialogue_girl_apartment_10_3", lua_Script_dialogue_girl_apartment_10_3);
	lua_register(_pL, "GMLScript_dialogue_girl_apartment_10_4", lua_Script_dialogue_girl_apartment_10_4);
	lua_register(_pL, "GMLScript_dialogue_apartment_searchresult_leviathan_fail", lua_Script_dialogue_apartment_searchresult_leviathan_fail);
	lua_register(_pL, "GMLScript_dialogue_apartment_searchresult_leviathan_failf", lua_Script_dialogue_apartment_searchresult_leviathan_failf);
	lua_register(_pL, "GMLScript_dialogue_girl_halloween", lua_Script_dialogue_girl_halloween);
	lua_register(_pL, "GMLScript_dialogue_girl_candy", lua_Script_dialogue_girl_candy);
	lua_register(_pL, "GMLScript_dialogue_tv_1", lua_Script_dialogue_tv_1);
	lua_register(_pL, "GMLScript_dialogue_tv_2", lua_Script_dialogue_tv_2);
	lua_register(_pL, "GMLScript_dialogue_tv_3", lua_Script_dialogue_tv_3);
	lua_register(_pL, "GMLScript_dialogue_tv_5", lua_Script_dialogue_tv_5);
	lua_register(_pL, "GMLScript_dialogue_tv_6", lua_Script_dialogue_tv_6);
	lua_register(_pL, "GMLScript_dialogue_videostore_girl", lua_Script_dialogue_videostore_girl);
	lua_register(_pL, "GMLScript_dialogue_bar_0", lua_Script_dialogue_bar_0);
	lua_register(_pL, "GMLScript_dialogue_bar_1", lua_Script_dialogue_bar_1);
	lua_register(_pL, "GMLScript_dialogue_bar_2", lua_Script_dialogue_bar_2);
	lua_register(_pL, "GMLScript_dialogue_bar_3", lua_Script_dialogue_bar_3);
	lua_register(_pL, "GMLScript_dialogue_jukebox", lua_Script_dialogue_jukebox);
	lua_register(_pL, "GMLScript_dialogue_hallway_passive", lua_Script_dialogue_hallway_passive);
	lua_register(_pL, "GMLScript_dialogue_hallway_police_1", lua_Script_dialogue_hallway_police_1);
	lua_register(_pL, "GMLScript_dialogue_apartment_note", lua_Script_dialogue_apartment_note);
	lua_register(_pL, "GMLScript_dialogue_hallway_police_2", lua_Script_dialogue_hallway_police_2);
	lua_register(_pL, "GMLScript_dialogue_hallway_police_3", lua_Script_dialogue_hallway_police_3);
	lua_register(_pL, "GMLScript_dialogue_snuff_0", lua_Script_dialogue_snuff_0);
	lua_register(_pL, "GMLScript_dialogue_snuff_1", lua_Script_dialogue_snuff_1);
	lua_register(_pL, "GMLScript_dialogue_snuff_2", lua_Script_dialogue_snuff_2);
	lua_register(_pL, "GMLScript_dialogue_snuff_3", lua_Script_dialogue_snuff_3);
	lua_register(_pL, "GMLScript_dialogue_snuff_4", lua_Script_dialogue_snuff_4);
	lua_register(_pL, "GMLScript_dialogue_snuff_5", lua_Script_dialogue_snuff_5);
	lua_register(_pL, "GMLScript_dialogue_ending_walkie", lua_Script_dialogue_ending_walkie);
	lua_register(_pL, "GMLScript_dialogue_ending_snow", lua_Script_dialogue_ending_snow);
	lua_register(_pL, "GMLScript_dialogue_nightmare_scientist_gibberish", lua_Script_dialogue_nightmare_scientist_gibberish);
	lua_register(_pL, "GMLScript_dialogue_nightmare_scientist_gibberish_2", lua_Script_dialogue_nightmare_scientist_gibberish_2);
	lua_register(_pL, "GMLScript_dialogue_nightmare_scientist_gibberish_3", lua_Script_dialogue_nightmare_scientist_gibberish_3);
	lua_register(_pL, "GMLScript_dialogue_nightmare_scientist_talk", lua_Script_dialogue_nightmare_scientist_talk);
	lua_register(_pL, "GMLScript_dialogue_fullscreen_0", lua_Script_dialogue_fullscreen_0);
	lua_register(_pL, "GMLScript_dialogue_results_1", lua_Script_dialogue_results_1);
	lua_register(_pL, "GMLScript_dialogue_results_1_bad", lua_Script_dialogue_results_1_bad);
	lua_register(_pL, "GMLScript_dialogue_results_2_good", lua_Script_dialogue_results_2_good);
	lua_register(_pL, "GMLScript_dialogue_results_2_bad", lua_Script_dialogue_results_2_bad);
	lua_register(_pL, "GMLScript_dialogue_results_3_good", lua_Script_dialogue_results_3_good);
	lua_register(_pL, "GMLScript_dialogue_results_3_okay", lua_Script_dialogue_results_3_okay);
	lua_register(_pL, "GMLScript_dialogue_results_3_bad", lua_Script_dialogue_results_3_bad);
	lua_register(_pL, "GMLScript_dialogue_results_4_good", lua_Script_dialogue_results_4_good);
	lua_register(_pL, "GMLScript_dialogue_results_4_bad", lua_Script_dialogue_results_4_bad);
	lua_register(_pL, "GMLScript_dialogue_results_4_nochronos_good", lua_Script_dialogue_results_4_nochronos_good);
	lua_register(_pL, "GMLScript_dialogue_results_4_nochronos_bad", lua_Script_dialogue_results_4_nochronos_bad);
	lua_register(_pL, "GMLScript_dialogue_results_5", lua_Script_dialogue_results_5);
	lua_register(_pL, "GMLScript_dialogue_results_6", lua_Script_dialogue_results_6);
	lua_register(_pL, "GMLScript_dialogue_results_7", lua_Script_dialogue_results_7);
	lua_register(_pL, "GMLScript_dialogue_results_9", lua_Script_dialogue_results_9);
	lua_register(_pL, "GMLScript_dialogue_results_9_2", lua_Script_dialogue_results_9_2);
	lua_register(_pL, "GMLScript_dialogue_results_10", lua_Script_dialogue_results_10);
	lua_register(_pL, "GMLScript_dialogue_results_11", lua_Script_dialogue_results_11);
	lua_register(_pL, "GMLScript_dialogue_unlocked_lab", lua_Script_dialogue_unlocked_lab);
	lua_register(_pL, "GMLScript_dialogue_psych_passive", lua_Script_dialogue_psych_passive);
	lua_register(_pL, "GMLScript_dialogue_psych_passive_2", lua_Script_dialogue_psych_passive_2);
	lua_register(_pL, "GMLScript_dialogue_motel_gangsters", lua_Script_dialogue_motel_gangsters);
	lua_register(_pL, "GMLScript_dialogue_club_bouncer", lua_Script_dialogue_club_bouncer);
	lua_register(_pL, "GMLScript_dialogue_club_bouncerfriend", lua_Script_dialogue_club_bouncerfriend);
	lua_register(_pL, "GMLScript_dialogue_club_pipes", lua_Script_dialogue_club_pipes);
	lua_register(_pL, "GMLScript_dialogue_club_skinnyricky", lua_Script_dialogue_club_skinnyricky);
	lua_register(_pL, "GMLScript_dialogue_haunted_robot", lua_Script_dialogue_haunted_robot);
	lua_register(_pL, "GMLScript_dialogue_haunted_robot2", lua_Script_dialogue_haunted_robot2);
	lua_register(_pL, "GMLScript_dialogue_mansion_fall", lua_Script_dialogue_mansion_fall);
	lua_register(_pL, "GMLScript_dialogue_mansion_eavesdrop", lua_Script_dialogue_mansion_eavesdrop);
	lua_register(_pL, "GMLScript_dialogue_notea", lua_Script_dialogue_notea);
	lua_register(_pL, "GMLScript_dialogue_candy", lua_Script_dialogue_candy);
	lua_register(_pL, "GMLScript_dialogue_psych_2", lua_Script_dialogue_psych_2);
	lua_register(_pL, "GMLScript_dialogue_psych_3", lua_Script_dialogue_psych_3);
	lua_register(_pL, "GMLScript_dialogue_psych_4", lua_Script_dialogue_psych_4);
	lua_register(_pL, "GMLScript_dialogue_psych_note", lua_Script_dialogue_psych_note);
	lua_register(_pL, "GMLScript_dialogue_psych_6_1", lua_Script_dialogue_psych_6_1);
	lua_register(_pL, "GMLScript_dialogue_psych_6_2", lua_Script_dialogue_psych_6_2);
	lua_register(_pL, "GMLScript_dialogue_psych_6_3", lua_Script_dialogue_psych_6_3);
	lua_register(_pL, "GMLScript_dialogue_psych_6_4", lua_Script_dialogue_psych_6_4);
	lua_register(_pL, "GMLScript_dialogue_psych_7", lua_Script_dialogue_psych_7);
	lua_register(_pL, "GMLScript_dialogue_psych_7_2", lua_Script_dialogue_psych_7_2);
	lua_register(_pL, "GMLScript_dialogue_psych_7_3", lua_Script_dialogue_psych_7_3);
	lua_register(_pL, "GMLScript_dialogue_psych_10", lua_Script_dialogue_psych_10);
	lua_register(_pL, "GMLScript_dialogue_psych_11", lua_Script_dialogue_psych_11);
	lua_register(_pL, "GMLScript_dialogue_psych_11_battle", lua_Script_dialogue_psych_11_battle);
	lua_register(_pL, "GMLScript_dialogue_psych_paper", lua_Script_dialogue_psych_paper);
	lua_register(_pL, "GMLScript_dialogue_psych_desk_rock", lua_Script_dialogue_psych_desk_rock);
	lua_register(_pL, "GMLScript_dialogue_psych_desk_picture", lua_Script_dialogue_psych_desk_picture);
	lua_register(_pL, "GMLScript_dialogue_psych_desk_generic", lua_Script_dialogue_psych_desk_generic);
	lua_register(_pL, "GMLScript_dialogue_psych_desk_annoyed", lua_Script_dialogue_psych_desk_annoyed);
	lua_register(_pL, "GMLScript_dialogue_psych_desk_angry", lua_Script_dialogue_psych_desk_angry);
	lua_register(_pL, "GMLScript_init_textbox_actors", lua_Script_init_textbox_actors);
	lua_register(_pL, "GMLScript_set_actor_talksfx", lua_Script_set_actor_talksfx);
	lua_register(_pL, "GMLScript_dialogue_maskedmen1", lua_Script_dialogue_maskedmen1);
	lua_register(_pL, "GMLScript_dialogue_maskedmen_alleyway", lua_Script_dialogue_maskedmen_alleyway);
	lua_register(_pL, "GMLScript_dialogue_maskedmen_postcredits", lua_Script_dialogue_maskedmen_postcredits);
	lua_register(_pL, "GMLScript_switch_saveload_begin", lua_Script_switch_saveload_begin);
	lua_register(_pL, "GMLScript_switch_save_end", lua_Script_switch_save_end);
	lua_register(_pL, "GMLScript_cutscene_init", lua_Script_cutscene_init);
	lua_register(_pL, "GMLScript_cutscene_wait", lua_Script_cutscene_wait);
	lua_register(_pL, "GMLScript_cutscene_move_player", lua_Script_cutscene_move_player);
	lua_register(_pL, "GMLScript_create_enemybike_formation", lua_Script_create_enemybike_formation);
	lua_register(_pL, "GMLScript_create_enemybike_formation_vertical", lua_Script_create_enemybike_formation_vertical);
	lua_register(_pL, "GMLScript_check_bikeslash_collision", lua_Script_check_bikeslash_collision);
	lua_register(_pL, "GMLScript_save_game", lua_Script_save_game);
	lua_register(_pL, "GMLScript_load_game", lua_Script_load_game);
	lua_register(_pL, "GMLScript_save_options", lua_Script_save_options);
	lua_register(_pL, "GMLScript_load_options", lua_Script_load_options);
	lua_register(_pL, "GMLScript_save_version_number", lua_Script_save_version_number);
	lua_register(_pL, "GMLScript_load_version_number", lua_Script_load_version_number);
	lua_register(_pL, "GMLScript_save_controls", lua_Script_save_controls);
	lua_register(_pL, "GMLScript_load_controls", lua_Script_load_controls);
	lua_register(_pL, "GMLScript_save_current_speedrun", lua_Script_save_current_speedrun);
	lua_register(_pL, "GMLScript_load_current_speedrun", lua_Script_load_current_speedrun);
	lua_register(_pL, "GMLScript_save_speedrun_options", lua_Script_save_speedrun_options);
	lua_register(_pL, "GMLScript_load_speedrun_options", lua_Script_load_speedrun_options);
	lua_register(_pL, "GMLScript_save_achievements", lua_Script_save_achievements);
	lua_register(_pL, "GMLScript_load_achievements", lua_Script_load_achievements);
	lua_register(_pL, "GMLScript_save_variable", lua_Script_save_variable);
	lua_register(_pL, "GMLScript_save_variable_rounded", lua_Script_save_variable_rounded);
	lua_register(_pL, "GMLScript_load_variable", lua_Script_load_variable);
	lua_register(_pL, "GMLScript_load_variable_rounded", lua_Script_load_variable_rounded);
	lua_register(_pL, "GMLScript_load_variable_string", lua_Script_load_variable_string);
	lua_register(_pL, "GMLScript_generate_hash", lua_Script_generate_hash);
	lua_register(_pL, "GMLScript_get_line_text", lua_Script_get_line_text);
	lua_register(_pL, "GMLScript_get_line_textbox_width", lua_Script_get_line_textbox_width);
	lua_register(_pL, "GMLScript_get_choice_text", lua_Script_get_choice_text);
	lua_register(_pL, "GMLScript_get_misc_text", lua_Script_get_misc_text);
	lua_register(_pL, "GMLScript_init_lines", lua_Script_init_lines);
	lua_register(_pL, "GMLScript_init_misc_text", lua_Script_init_misc_text);
	lua_register(_pL, "GMLScript_init_option_translations", lua_Script_init_option_translations);
	lua_register(_pL, "GMLScript_translate_option", lua_Script_translate_option);
	lua_register(_pL, "GMLScript_draw_set_font_localized", lua_Script_draw_set_font_localized);
	lua_register(_pL, "GMLScript_draw_set_font_override", lua_Script_draw_set_font_override);
	lua_register(_pL, "GMLScript_draw_text_scaled", lua_Script_draw_text_scaled);
	lua_register(_pL, "GMLScript_draw_text_scaled_outline_ext", lua_Script_draw_text_scaled_outline_ext);
	lua_register(_pL, "GMLScript_draw_text_scaled_color", lua_Script_draw_text_scaled_color);
	lua_register(_pL, "GMLScript_draw_text_scaled_colour", lua_Script_draw_text_scaled_colour);
	lua_register(_pL, "GMLScript_draw_text_scaled_transformed", lua_Script_draw_text_scaled_transformed);
	lua_register(_pL, "GMLScript_draw_text_scaled_ext_transformed", lua_Script_draw_text_scaled_ext_transformed);
	lua_register(_pL, "GMLScript_draw_text_scaled_transformed_colour", lua_Script_draw_text_scaled_transformed_colour);
	lua_register(_pL, "GMLScript_draw_text_scaled_transformed_color", lua_Script_draw_text_scaled_transformed_color);
	lua_register(_pL, "GMLScript_draw_text_scaled_glow_ext", lua_Script_draw_text_scaled_glow_ext);
	lua_register(_pL, "GMLScript_trigger_steam_achievement", lua_Script_trigger_steam_achievement);
	lua_register(_pL, "GMLScript_draw_speedrun_timer", lua_Script_draw_speedrun_timer);
	lua_register(_pL, "GMLScript_char_to_milli", lua_Script_char_to_milli);
	lua_register(_pL, "GMLScript_get_random", lua_Script_get_random);
	lua_register(_pL, "GMLScript_choose_random", lua_Script_choose_random);
}


int lua_Script_macros(lua_State *_pL) { return DoLuaScriptCall(_pL, 0); }
int lua_Script_action_end_game(lua_State *_pL) { return DoLuaScriptCall(_pL, 1); }
int lua_Script_action_inherited(lua_State *_pL) { return DoLuaScriptCall(_pL, 2); }
int lua_Script___init_action(lua_State *_pL) { return DoLuaScriptCall(_pL, 3); }
int lua_Script_background_get_height(lua_State *_pL) { return DoLuaScriptCall(_pL, 4); }
int lua_Script_background_get_width(lua_State *_pL) { return DoLuaScriptCall(_pL, 5); }
int lua_Script___init_background(lua_State *_pL) { return DoLuaScriptCall(_pL, 6); }
int lua_Script_draw_set_blend_mode(lua_State *_pL) { return DoLuaScriptCall(_pL, 7); }
int lua_Script_instance_create(lua_State *_pL) { return DoLuaScriptCall(_pL, 8); }
int lua_Script_object_get_depth(lua_State *_pL) { return DoLuaScriptCall(_pL, 9); }
int lua_Script_tile_add(lua_State *_pL) { return DoLuaScriptCall(_pL, 10); }
int lua_Script_tile_exists(lua_State *_pL) { return DoLuaScriptCall(_pL, 11); }
int lua_Script_tile_get_background(lua_State *_pL) { return DoLuaScriptCall(_pL, 12); }
int lua_Script_tile_get_height(lua_State *_pL) { return DoLuaScriptCall(_pL, 13); }
int lua_Script_tile_get_left(lua_State *_pL) { return DoLuaScriptCall(_pL, 14); }
int lua_Script_tile_get_top(lua_State *_pL) { return DoLuaScriptCall(_pL, 15); }
int lua_Script_tile_get_width(lua_State *_pL) { return DoLuaScriptCall(_pL, 16); }
int lua_Script_tile_layer_delete(lua_State *_pL) { return DoLuaScriptCall(_pL, 17); }
int lua_Script_tile_layer_find(lua_State *_pL) { return DoLuaScriptCall(_pL, 18); }
int lua_Script_tile_layer_shift(lua_State *_pL) { return DoLuaScriptCall(_pL, 19); }
int lua_Script_tile_set_scale(lua_State *_pL) { return DoLuaScriptCall(_pL, 20); }
int lua_Script___view_get(lua_State *_pL) { return DoLuaScriptCall(_pL, 21); }
int lua_Script___view_set(lua_State *_pL) { return DoLuaScriptCall(_pL, 22); }
int lua_Script___view_set_internal(lua_State *_pL) { return DoLuaScriptCall(_pL, 23); }
int lua_Script___init_view(lua_State *_pL) { return DoLuaScriptCall(_pL, 24); }
int lua_Script___global_object_depths(lua_State *_pL) { return DoLuaScriptCall(_pL, 25); }
int lua_Script___init_global(lua_State *_pL) { return DoLuaScriptCall(_pL, 26); }
int lua_Script_inside_screen(lua_State *_pL) { return DoLuaScriptCall(_pL, 27); }
int lua_Script_inside_stage(lua_State *_pL) { return DoLuaScriptCall(_pL, 28); }
int lua_Script_inside_screen_point(lua_State *_pL) { return DoLuaScriptCall(_pL, 29); }
int lua_Script_inside_screen_line(lua_State *_pL) { return DoLuaScriptCall(_pL, 30); }
int lua_Script_inside_camera(lua_State *_pL) { return DoLuaScriptCall(_pL, 31); }
int lua_Script_level_y(lua_State *_pL) { return DoLuaScriptCall(_pL, 32); }
int lua_Script_set_level(lua_State *_pL) { return DoLuaScriptCall(_pL, 33); }
int lua_Script_actor_init(lua_State *_pL) { return DoLuaScriptCall(_pL, 34); }
int lua_Script_animation_init(lua_State *_pL) { return DoLuaScriptCall(_pL, 35); }
int lua_Script_begin_animation(lua_State *_pL) { return DoLuaScriptCall(_pL, 36); }
int lua_Script_animation_code(lua_State *_pL) { return DoLuaScriptCall(_pL, 37); }
int lua_Script_player_idle_ground(lua_State *_pL) { return DoLuaScriptCall(_pL, 38); }
int lua_Script_player_moving_ground(lua_State *_pL) { return DoLuaScriptCall(_pL, 39); }
int lua_Script_player_walking(lua_State *_pL) { return DoLuaScriptCall(_pL, 40); }
int lua_Script_player_casual_walking(lua_State *_pL) { return DoLuaScriptCall(_pL, 41); }
int lua_Script_player_casual_walking_old(lua_State *_pL) { return DoLuaScriptCall(_pL, 42); }
int lua_Script_player_walljump(lua_State *_pL) { return DoLuaScriptCall(_pL, 43); }
int lua_Script_player_wallgrab(lua_State *_pL) { return DoLuaScriptCall(_pL, 44); }
int lua_Script_player_crouching(lua_State *_pL) { return DoLuaScriptCall(_pL, 45); }
int lua_Script_player_flying(lua_State *_pL) { return DoLuaScriptCall(_pL, 46); }
int lua_Script_player_air(lua_State *_pL) { return DoLuaScriptCall(_pL, 47); }
int lua_Script_player_bullettime_check(lua_State *_pL) { return DoLuaScriptCall(_pL, 48); }
int lua_Script_player_block_check(lua_State *_pL) { return DoLuaScriptCall(_pL, 49); }
int lua_Script_player_secondary(lua_State *_pL) { return DoLuaScriptCall(_pL, 50); }
int lua_Script_player_cable_control(lua_State *_pL) { return DoLuaScriptCall(_pL, 51); }
int lua_Script_player_electromagnet(lua_State *_pL) { return DoLuaScriptCall(_pL, 52); }
int lua_Script_get_electromagnet_direction(lua_State *_pL) { return DoLuaScriptCall(_pL, 53); }
int lua_Script_player_flamethrower(lua_State *_pL) { return DoLuaScriptCall(_pL, 54); }
int lua_Script_get_flamethrower_direction(lua_State *_pL) { return DoLuaScriptCall(_pL, 55); }
int lua_Script_player_shoot_cable(lua_State *_pL) { return DoLuaScriptCall(_pL, 56); }
int lua_Script_player_throw(lua_State *_pL) { return DoLuaScriptCall(_pL, 57); }
int lua_Script_player_blocking(lua_State *_pL) { return DoLuaScriptCall(_pL, 58); }
int lua_Script_player_attack_check(lua_State *_pL) { return DoLuaScriptCall(_pL, 59); }
int lua_Script_player_attack_check_old(lua_State *_pL) { return DoLuaScriptCall(_pL, 60); }
int lua_Script_player_attack(lua_State *_pL) { return DoLuaScriptCall(_pL, 61); }
int lua_Script_player_doorbreak(lua_State *_pL) { return DoLuaScriptCall(_pL, 62); }
int lua_Script_player_hurtfly(lua_State *_pL) { return DoLuaScriptCall(_pL, 63); }
int lua_Script_player_hurtfall(lua_State *_pL) { return DoLuaScriptCall(_pL, 64); }
int lua_Script_player_hurtground(lua_State *_pL) { return DoLuaScriptCall(_pL, 65); }
int lua_Script_player_recover(lua_State *_pL) { return DoLuaScriptCall(_pL, 66); }
int lua_Script_player_rolling(lua_State *_pL) { return DoLuaScriptCall(_pL, 67); }
int lua_Script_player_airdodge(lua_State *_pL) { return DoLuaScriptCall(_pL, 68); }
int lua_Script_player_swapitem(lua_State *_pL) { return DoLuaScriptCall(_pL, 69); }
int lua_Script_player_quickswap(lua_State *_pL) { return DoLuaScriptCall(_pL, 70); }
int lua_Script_player_dead(lua_State *_pL) { return DoLuaScriptCall(_pL, 71); }
int lua_Script_player_freeze(lua_State *_pL) { return DoLuaScriptCall(_pL, 72); }
int lua_Script_player_bikethrow(lua_State *_pL) { return DoLuaScriptCall(_pL, 73); }
int lua_Script_player_secondary_dragon(lua_State *_pL) { return DoLuaScriptCall(_pL, 74); }
int lua_Script_player_draw_cableholdUI(lua_State *_pL) { return DoLuaScriptCall(_pL, 75); }
int lua_Script_player_analogue_pressed_check(lua_State *_pL) { return DoLuaScriptCall(_pL, 76); }
int lua_Script_player_input(lua_State *_pL) { return DoLuaScriptCall(_pL, 77); }
int lua_Script_player_hurt(lua_State *_pL) { return DoLuaScriptCall(_pL, 78); }
int lua_Script_kill_player(lua_State *_pL) { return DoLuaScriptCall(_pL, 79); }
int lua_Script_slash_hit(lua_State *_pL) { return DoLuaScriptCall(_pL, 80); }
int lua_Script_bullet_hit(lua_State *_pL) { return DoLuaScriptCall(_pL, 81); }
int lua_Script_explosion_hit(lua_State *_pL) { return DoLuaScriptCall(_pL, 82); }
int lua_Script_player_physics(lua_State *_pL) { return DoLuaScriptCall(_pL, 83); }
int lua_Script_player_ragdoll(lua_State *_pL) { return DoLuaScriptCall(_pL, 84); }
int lua_Script_freeze_player(lua_State *_pL) { return DoLuaScriptCall(_pL, 85); }
int lua_Script_draw_player(lua_State *_pL) { return DoLuaScriptCall(_pL, 86); }
int lua_Script_draw_player_slowdown(lua_State *_pL) { return DoLuaScriptCall(_pL, 87); }
int lua_Script_player_animation(lua_State *_pL) { return DoLuaScriptCall(_pL, 88); }
int lua_Script_player_get_throwdirection(lua_State *_pL) { return DoLuaScriptCall(_pL, 89); }
int lua_Script_player_get_attackdirection(lua_State *_pL) { return DoLuaScriptCall(_pL, 90); }
int lua_Script_move_contact_layer_solid(lua_State *_pL) { return DoLuaScriptCall(_pL, 91); }
int lua_Script_move_contact_layer(lua_State *_pL) { return DoLuaScriptCall(_pL, 92); }
int lua_Script_ground_meeting(lua_State *_pL) { return DoLuaScriptCall(_pL, 93); }
int lua_Script_jumpdown_meeting(lua_State *_pL) { return DoLuaScriptCall(_pL, 94); }
int lua_Script_block_meeting(lua_State *_pL) { return DoLuaScriptCall(_pL, 95); }
int lua_Script_floor_check(lua_State *_pL) { return DoLuaScriptCall(_pL, 96); }
int lua_Script_wall_check(lua_State *_pL) { return DoLuaScriptCall(_pL, 97); }
int lua_Script_ceiling_check(lua_State *_pL) { return DoLuaScriptCall(_pL, 98); }
int lua_Script_slope_check(lua_State *_pL) { return DoLuaScriptCall(_pL, 99); }
int lua_Script_ragdoll_physics(lua_State *_pL) { return DoLuaScriptCall(_pL, 100); }
int lua_Script_slope_land_check(lua_State *_pL) { return DoLuaScriptCall(_pL, 101); }
int lua_Script_on_a_slope(lua_State *_pL) { return DoLuaScriptCall(_pL, 102); }
int lua_Script_AI_physics(lua_State *_pL) { return DoLuaScriptCall(_pL, 103); }
int lua_Script_create_node(lua_State *_pL) { return DoLuaScriptCall(_pL, 104); }
int lua_Script_create_link(lua_State *_pL) { return DoLuaScriptCall(_pL, 105); }
int lua_Script_softbody_constraint(lua_State *_pL) { return DoLuaScriptCall(_pL, 106); }
int lua_Script_softbody_constraint_strong(lua_State *_pL) { return DoLuaScriptCall(_pL, 107); }
int lua_Script_momentum_add(lua_State *_pL) { return DoLuaScriptCall(_pL, 108); }
int lua_Script_place_meeting_radius_dir(lua_State *_pL) { return DoLuaScriptCall(_pL, 109); }
int lua_Script_place_meeting_radius(lua_State *_pL) { return DoLuaScriptCall(_pL, 110); }
int lua_Script_create_popuptext(lua_State *_pL) { return DoLuaScriptCall(_pL, 111); }
int lua_Script_check_light_collision(lua_State *_pL) { return DoLuaScriptCall(_pL, 112); }
int lua_Script_check_light_collision_new(lua_State *_pL) { return DoLuaScriptCall(_pL, 113); }
int lua_Script_draw_flashlight(lua_State *_pL) { return DoLuaScriptCall(_pL, 114); }
int lua_Script_timer_to_string(lua_State *_pL) { return DoLuaScriptCall(_pL, 115); }
int lua_Script_play_sound_materialbounce(lua_State *_pL) { return DoLuaScriptCall(_pL, 116); }
int lua_Script_draw_sprite_sway(lua_State *_pL) { return DoLuaScriptCall(_pL, 117); }
int lua_Script_draw_sprite_wavy(lua_State *_pL) { return DoLuaScriptCall(_pL, 118); }
int lua_Script_draw_sprite_wavy_random(lua_State *_pL) { return DoLuaScriptCall(_pL, 119); }
int lua_Script_tile_layer_move_init(lua_State *_pL) { return DoLuaScriptCall(_pL, 120); }
int lua_Script_tile_layer_move(lua_State *_pL) { return DoLuaScriptCall(_pL, 121); }
int lua_Script_draw_vcig(lua_State *_pL) { return DoLuaScriptCall(_pL, 122); }
int lua_Script_draw_minecart(lua_State *_pL) { return DoLuaScriptCall(_pL, 123); }
int lua_Script_draw_rail(lua_State *_pL) { return DoLuaScriptCall(_pL, 124); }
int lua_Script_get_pulse(lua_State *_pL) { return DoLuaScriptCall(_pL, 125); }
int lua_Script_pulse_init(lua_State *_pL) { return DoLuaScriptCall(_pL, 126); }
int lua_Script_draw_rail_bottom(lua_State *_pL) { return DoLuaScriptCall(_pL, 127); }
int lua_Script_draw_laser(lua_State *_pL) { return DoLuaScriptCall(_pL, 128); }
int lua_Script_draw_laser_horizontal(lua_State *_pL) { return DoLuaScriptCall(_pL, 129); }
int lua_Script_draw_line_dotted(lua_State *_pL) { return DoLuaScriptCall(_pL, 130); }
int lua_Script_draw_line_dotted_radius(lua_State *_pL) { return DoLuaScriptCall(_pL, 131); }
int lua_Script_draw_line_dotted_inconsistent(lua_State *_pL) { return DoLuaScriptCall(_pL, 132); }
int lua_Script_dissolve_sprite(lua_State *_pL) { return DoLuaScriptCall(_pL, 133); }
int lua_Script_show_hint(lua_State *_pL) { return DoLuaScriptCall(_pL, 134); }
int lua_Script_create_motion_trail(lua_State *_pL) { return DoLuaScriptCall(_pL, 135); }
int lua_Script_create_motion_trail_bg(lua_State *_pL) { return DoLuaScriptCall(_pL, 136); }
int lua_Script_create_static_trail(lua_State *_pL) { return DoLuaScriptCall(_pL, 137); }
int lua_Script_create_motion_trail_bg_growing(lua_State *_pL) { return DoLuaScriptCall(_pL, 138); }
int lua_Script_tile_bump_map(lua_State *_pL) { return DoLuaScriptCall(_pL, 139); }
int lua_Script_tile_blood_map(lua_State *_pL) { return DoLuaScriptCall(_pL, 140); }
int lua_Script_create_dust(lua_State *_pL) { return DoLuaScriptCall(_pL, 141); }
int lua_Script_create_dust_var(lua_State *_pL) { return DoLuaScriptCall(_pL, 142); }
int lua_Script_create_trail(lua_State *_pL) { return DoLuaScriptCall(_pL, 143); }
int lua_Script_create_fade(lua_State *_pL) { return DoLuaScriptCall(_pL, 144); }
int lua_Script_create_flash(lua_State *_pL) { return DoLuaScriptCall(_pL, 145); }
int lua_Script_create_memory_flash(lua_State *_pL) { return DoLuaScriptCall(_pL, 146); }
int lua_Script_draw_sprite_recolored(lua_State *_pL) { return DoLuaScriptCall(_pL, 147); }
int lua_Script_draw_sprite_recolored_old_2(lua_State *_pL) { return DoLuaScriptCall(_pL, 148); }
int lua_Script_draw_sprite_recolored_debug(lua_State *_pL) { return DoLuaScriptCall(_pL, 149); }
int lua_Script_draw_sprite_recolored_old(lua_State *_pL) { return DoLuaScriptCall(_pL, 150); }
int lua_Script_draw_surface_recolored(lua_State *_pL) { return DoLuaScriptCall(_pL, 151); }
int lua_Script_draw_surface_recolored_old(lua_State *_pL) { return DoLuaScriptCall(_pL, 152); }
int lua_Script_draw_sprite_existing_surface(lua_State *_pL) { return DoLuaScriptCall(_pL, 153); }
int lua_Script_draw_rim_shading_surface(lua_State *_pL) { return DoLuaScriptCall(_pL, 154); }
int lua_Script_draw_rim_shading_surface_unbatched(lua_State *_pL) { return DoLuaScriptCall(_pL, 155); }
int lua_Script_draw_rim_shading_surface_object(lua_State *_pL) { return DoLuaScriptCall(_pL, 156); }
int lua_Script_draw_recolor_init(lua_State *_pL) { return DoLuaScriptCall(_pL, 157); }
int lua_Script_screen_shake_dir(lua_State *_pL) { return DoLuaScriptCall(_pL, 158); }
int lua_Script_screen_shake(lua_State *_pL) { return DoLuaScriptCall(_pL, 159); }
int lua_Script_screen_freeze(lua_State *_pL) { return DoLuaScriptCall(_pL, 160); }
int lua_Script_club_script(lua_State *_pL) { return DoLuaScriptCall(_pL, 161); }
int lua_Script_add_bloodtile(lua_State *_pL) { return DoLuaScriptCall(_pL, 162); }
int lua_Script_draw_bg_parallax(lua_State *_pL) { return DoLuaScriptCall(_pL, 163); }
int lua_Script_draw_sprite_parallax(lua_State *_pL) { return DoLuaScriptCall(_pL, 164); }
int lua_Script_record_me(lua_State *_pL) { return DoLuaScriptCall(_pL, 165); }
int lua_Script_draw_rim_shading(lua_State *_pL) { return DoLuaScriptCall(_pL, 166); }
int lua_Script_draw_sprite_surface(lua_State *_pL) { return DoLuaScriptCall(_pL, 167); }
int lua_Script_draw_beam_fragment(lua_State *_pL) { return DoLuaScriptCall(_pL, 168); }
int lua_Script_draw_lightning(lua_State *_pL) { return DoLuaScriptCall(_pL, 169); }
int lua_Script_fastmerge_col(lua_State *_pL) { return DoLuaScriptCall(_pL, 170); }
int lua_Script_draw_static(lua_State *_pL) { return DoLuaScriptCall(_pL, 171); }
int lua_Script_light_create(lua_State *_pL) { return DoLuaScriptCall(_pL, 172); }
int lua_Script_light_draw(lua_State *_pL) { return DoLuaScriptCall(_pL, 173); }
int lua_Script_flashlight_create(lua_State *_pL) { return DoLuaScriptCall(_pL, 174); }
int lua_Script_flashlight_draw(lua_State *_pL) { return DoLuaScriptCall(_pL, 175); }
int lua_Script_create_spriteswap(lua_State *_pL) { return DoLuaScriptCall(_pL, 176); }
int lua_Script_draw_semicircle(lua_State *_pL) { return DoLuaScriptCall(_pL, 177); }
int lua_Script_init_light_array(lua_State *_pL) { return DoLuaScriptCall(_pL, 178); }
int lua_Script_update_light_array(lua_State *_pL) { return DoLuaScriptCall(_pL, 179); }
int lua_Script_update_light_array_sorted(lua_State *_pL) { return DoLuaScriptCall(_pL, 180); }
int lua_Script_update_light_array_ext(lua_State *_pL) { return DoLuaScriptCall(_pL, 181); }
int lua_Script_draw_shadow(lua_State *_pL) { return DoLuaScriptCall(_pL, 182); }
int lua_Script_init_controls(lua_State *_pL) { return DoLuaScriptCall(_pL, 183); }
int lua_Script_controller_check(lua_State *_pL) { return DoLuaScriptCall(_pL, 184); }
int lua_Script_controller_check_ext(lua_State *_pL) { return DoLuaScriptCall(_pL, 185); }
int lua_Script_controller_check_pressed(lua_State *_pL) { return DoLuaScriptCall(_pL, 186); }
int lua_Script_controller_check_pressed_ext(lua_State *_pL) { return DoLuaScriptCall(_pL, 187); }
int lua_Script_draw_control(lua_State *_pL) { return DoLuaScriptCall(_pL, 188); }
int lua_Script_get_face_button_sprite(lua_State *_pL) { return DoLuaScriptCall(_pL, 189); }
int lua_Script_init_default_controls(lua_State *_pL) { return DoLuaScriptCall(_pL, 190); }
int lua_Script_init_default_controls_options(lua_State *_pL) { return DoLuaScriptCall(_pL, 191); }
int lua_Script_get_input(lua_State *_pL) { return DoLuaScriptCall(_pL, 192); }
int lua_Script_check_controls_valid(lua_State *_pL) { return DoLuaScriptCall(_pL, 193); }
int lua_Script_set_new_input(lua_State *_pL) { return DoLuaScriptCall(_pL, 194); }
int lua_Script_create_player(lua_State *_pL) { return DoLuaScriptCall(_pL, 195); }
int lua_Script_best_respawn(lua_State *_pL) { return DoLuaScriptCall(_pL, 196); }
int lua_Script_best_item_spawn(lua_State *_pL) { return DoLuaScriptCall(_pL, 197); }
int lua_Script_player_exists(lua_State *_pL) { return DoLuaScriptCall(_pL, 198); }
int lua_Script_breathe_init(lua_State *_pL) { return DoLuaScriptCall(_pL, 199); }
int lua_Script_stealth_init(lua_State *_pL) { return DoLuaScriptCall(_pL, 200); }
int lua_Script_ai_add_special_animation(lua_State *_pL) { return DoLuaScriptCall(_pL, 201); }
int lua_Script_AI_init(lua_State *_pL) { return DoLuaScriptCall(_pL, 202); }
int lua_Script_enemy_init_behaviour(lua_State *_pL) { return DoLuaScriptCall(_pL, 203); }
int lua_Script_angle_distance(lua_State *_pL) { return DoLuaScriptCall(_pL, 204); }
int lua_Script_smoke_blocked(lua_State *_pL) { return DoLuaScriptCall(_pL, 205); }
int lua_Script_AI_can_shoot(lua_State *_pL) { return DoLuaScriptCall(_pL, 206); }
int lua_Script_AI_see_player(lua_State *_pL) { return DoLuaScriptCall(_pL, 207); }
int lua_Script_AI_line_of_sight(lua_State *_pL) { return DoLuaScriptCall(_pL, 208); }
int lua_Script_AI_hearing(lua_State *_pL) { return DoLuaScriptCall(_pL, 209); }
int lua_Script_AI_object_in_sight(lua_State *_pL) { return DoLuaScriptCall(_pL, 210); }
int lua_Script_AI_aim(lua_State *_pL) { return DoLuaScriptCall(_pL, 211); }
int lua_Script_AI_move_aimer(lua_State *_pL) { return DoLuaScriptCall(_pL, 212); }
int lua_Script_turret_line_of_sight(lua_State *_pL) { return DoLuaScriptCall(_pL, 213); }
int lua_Script_turret_aim(lua_State *_pL) { return DoLuaScriptCall(_pL, 214); }
int lua_Script_waypoint_compute(lua_State *_pL) { return DoLuaScriptCall(_pL, 215); }
int lua_Script_compute_path_new(lua_State *_pL) { return DoLuaScriptCall(_pL, 216); }
int lua_Script_array_removefirst(lua_State *_pL) { return DoLuaScriptCall(_pL, 217); }
int lua_Script_floor_above(lua_State *_pL) { return DoLuaScriptCall(_pL, 218); }
int lua_Script_floor_below(lua_State *_pL) { return DoLuaScriptCall(_pL, 219); }
int lua_Script_waypoint_compute_OLD(lua_State *_pL) { return DoLuaScriptCall(_pL, 220); }
int lua_Script_compute_path(lua_State *_pL) { return DoLuaScriptCall(_pL, 221); }
int lua_Script_AI_find_waypoint_up(lua_State *_pL) { return DoLuaScriptCall(_pL, 222); }
int lua_Script_AI_find_waypoint_down(lua_State *_pL) { return DoLuaScriptCall(_pL, 223); }
int lua_Script_listen(lua_State *_pL) { return DoLuaScriptCall(_pL, 224); }
int lua_Script_breathe(lua_State *_pL) { return DoLuaScriptCall(_pL, 225); }
int lua_Script_ai_set_hair(lua_State *_pL) { return DoLuaScriptCall(_pL, 226); }
int lua_Script_ai_set_gunpoint(lua_State *_pL) { return DoLuaScriptCall(_pL, 227); }
int lua_Script_create_corpse(lua_State *_pL) { return DoLuaScriptCall(_pL, 228); }
int lua_Script_enemy_hurt(lua_State *_pL) { return DoLuaScriptCall(_pL, 229); }
int lua_Script_ai_aim_overlap(lua_State *_pL) { return DoLuaScriptCall(_pL, 230); }
int lua_Script_ai_shieldcop_vulnerablecheck(lua_State *_pL) { return DoLuaScriptCall(_pL, 231); }
int lua_Script_ai_overlap(lua_State *_pL) { return DoLuaScriptCall(_pL, 232); }
int lua_Script_enemy_special_idle(lua_State *_pL) { return DoLuaScriptCall(_pL, 233); }
int lua_Script_draw_enemy_icons(lua_State *_pL) { return DoLuaScriptCall(_pL, 234); }
int lua_Script_draw_enemy(lua_State *_pL) { return DoLuaScriptCall(_pL, 235); }
int lua_Script_ai_find_soundsource(lua_State *_pL) { return DoLuaScriptCall(_pL, 236); }
int lua_Script_ai_state_control(lua_State *_pL) { return DoLuaScriptCall(_pL, 237); }
int lua_Script_ai_idle_ground(lua_State *_pL) { return DoLuaScriptCall(_pL, 238); }
int lua_Script_ai_idle_walking(lua_State *_pL) { return DoLuaScriptCall(_pL, 239); }
int lua_Script_ai_break_idle(lua_State *_pL) { return DoLuaScriptCall(_pL, 240); }
int lua_Script_ai_update_target(lua_State *_pL) { return DoLuaScriptCall(_pL, 241); }
int lua_Script_ai_check_stairdoor(lua_State *_pL) { return DoLuaScriptCall(_pL, 242); }
int lua_Script_ai_running_actions(lua_State *_pL) { return DoLuaScriptCall(_pL, 243); }
int lua_Script_ai_check_for_trap(lua_State *_pL) { return DoLuaScriptCall(_pL, 244); }
int lua_Script_ai_check_for_flame(lua_State *_pL) { return DoLuaScriptCall(_pL, 245); }
int lua_Script_ai_check_for_edge(lua_State *_pL) { return DoLuaScriptCall(_pL, 246); }
int lua_Script_ai_aim_to_run(lua_State *_pL) { return DoLuaScriptCall(_pL, 247); }
int lua_Script_ai_runstall_to_run(lua_State *_pL) { return DoLuaScriptCall(_pL, 248); }
int lua_Script_ai_open_door(lua_State *_pL) { return DoLuaScriptCall(_pL, 249); }
int lua_Script_menu_step(lua_State *_pL) { return DoLuaScriptCall(_pL, 250); }
int lua_Script_draw_crt_image(lua_State *_pL) { return DoLuaScriptCall(_pL, 251); }
int lua_Script_draw_crt_image_ext(lua_State *_pL) { return DoLuaScriptCall(_pL, 252); }
int lua_Script_draw_crt_surface(lua_State *_pL) { return DoLuaScriptCall(_pL, 253); }
int lua_Script_draw_sprite_distorted(lua_State *_pL) { return DoLuaScriptCall(_pL, 254); }
int lua_Script_draw_sprite_distorted_logo(lua_State *_pL) { return DoLuaScriptCall(_pL, 255); }
int lua_Script_draw_distorted_surface(lua_State *_pL) { return DoLuaScriptCall(_pL, 256); }
int lua_Script_find_next_tape(lua_State *_pL) { return DoLuaScriptCall(_pL, 257); }
int lua_Script_menu_init(lua_State *_pL) { return DoLuaScriptCall(_pL, 258); }
int lua_Script_add_pausemenu_choice(lua_State *_pL) { return DoLuaScriptCall(_pL, 259); }
int lua_Script_init_levelselect_data(lua_State *_pL) { return DoLuaScriptCall(_pL, 260); }
int lua_Script_create_controls_menu(lua_State *_pL) { return DoLuaScriptCall(_pL, 261); }
int lua_Script_set_windowsize(lua_State *_pL) { return DoLuaScriptCall(_pL, 262); }
int lua_Script_titlemenu_add_choice(lua_State *_pL) { return DoLuaScriptCall(_pL, 263); }
int lua_Script_check_katana_unlocked(lua_State *_pL) { return DoLuaScriptCall(_pL, 264); }
int lua_Script_create_roomsfx(lua_State *_pL) { return DoLuaScriptCall(_pL, 265); }
int lua_Script_create_audio_looper(lua_State *_pL) { return DoLuaScriptCall(_pL, 266); }
int lua_Script_play_sound_basic(lua_State *_pL) { return DoLuaScriptCall(_pL, 267); }
int lua_Script_play_sound_ext(lua_State *_pL) { return DoLuaScriptCall(_pL, 268); }
int lua_Script_play_sound_pos(lua_State *_pL) { return DoLuaScriptCall(_pL, 269); }
int lua_Script_play_sound(lua_State *_pL) { return DoLuaScriptCall(_pL, 270); }
int lua_Script_stop_music_sudden(lua_State *_pL) { return DoLuaScriptCall(_pL, 271); }
int lua_Script_draw_itemicon(lua_State *_pL) { return DoLuaScriptCall(_pL, 272); }
int lua_Script_remove_doors(lua_State *_pL) { return DoLuaScriptCall(_pL, 273); }
int lua_Script_restore_doors(lua_State *_pL) { return DoLuaScriptCall(_pL, 274); }
int lua_Script_room_transition(lua_State *_pL) { return DoLuaScriptCall(_pL, 275); }
int lua_Script_room_transition_fade(lua_State *_pL) { return DoLuaScriptCall(_pL, 276); }
int lua_Script_find_next_scene(lua_State *_pL) { return DoLuaScriptCall(_pL, 277); }
int lua_Script_override_control_init(lua_State *_pL) { return DoLuaScriptCall(_pL, 278); }
int lua_Script_override_control_end(lua_State *_pL) { return DoLuaScriptCall(_pL, 279); }
int lua_Script_ds_grid_replace_all(lua_State *_pL) { return DoLuaScriptCall(_pL, 280); }
int lua_Script_update_region(lua_State *_pL) { return DoLuaScriptCall(_pL, 281); }
int lua_Script_interact_binary(lua_State *_pL) { return DoLuaScriptCall(_pL, 282); }
int lua_Script_clear_screen(lua_State *_pL) { return DoLuaScriptCall(_pL, 283); }
int lua_Script_draw_text_outline_ext(lua_State *_pL) { return DoLuaScriptCall(_pL, 284); }
int lua_Script_draw_text_glow_ext(lua_State *_pL) { return DoLuaScriptCall(_pL, 285); }
int lua_Script_draw_fastline_width_col(lua_State *_pL) { return DoLuaScriptCall(_pL, 286); }
int lua_Script_draw_bigcircle(lua_State *_pL) { return DoLuaScriptCall(_pL, 287); }
int lua_Script_draw_fastcircle(lua_State *_pL) { return DoLuaScriptCall(_pL, 288); }
int lua_Script_draw_lightsphere(lua_State *_pL) { return DoLuaScriptCall(_pL, 289); }
int lua_Script_draw_rect_col(lua_State *_pL) { return DoLuaScriptCall(_pL, 290); }
int lua_Script_draw_circleui(lua_State *_pL) { return DoLuaScriptCall(_pL, 291); }
int lua_Script_create_explosion(lua_State *_pL) { return DoLuaScriptCall(_pL, 292); }
int lua_Script_create_smokescreen(lua_State *_pL) { return DoLuaScriptCall(_pL, 293); }
int lua_Script_create_smoke(lua_State *_pL) { return DoLuaScriptCall(_pL, 294); }
int lua_Script_create_cutscene_camera(lua_State *_pL) { return DoLuaScriptCall(_pL, 295); }
int lua_Script_scr_level_complete(lua_State *_pL) { return DoLuaScriptCall(_pL, 296); }
int lua_Script_scr_level_complete_cut(lua_State *_pL) { return DoLuaScriptCall(_pL, 297); }
int lua_Script_is_metal(lua_State *_pL) { return DoLuaScriptCall(_pL, 298); }
int lua_Script_is_attractable(lua_State *_pL) { return DoLuaScriptCall(_pL, 299); }
int lua_Script_is_currently_attracted(lua_State *_pL) { return DoLuaScriptCall(_pL, 300); }
int lua_Script_get_attract_strength(lua_State *_pL) { return DoLuaScriptCall(_pL, 301); }
int lua_Script_compute_attract_strength(lua_State *_pL) { return DoLuaScriptCall(_pL, 302); }
int lua_Script_create_metal_projectile(lua_State *_pL) { return DoLuaScriptCall(_pL, 303); }
int lua_Script_make_vhs_tape(lua_State *_pL) { return DoLuaScriptCall(_pL, 304); }
int lua_Script_pipeline_draw(lua_State *_pL) { return DoLuaScriptCall(_pL, 305); }
int lua_Script_pipeline_grab_sprite_surface(lua_State *_pL) { return DoLuaScriptCall(_pL, 306); }
int lua_Script_pipeline_color_surface(lua_State *_pL) { return DoLuaScriptCall(_pL, 307); }
int lua_Script_pipeline_rim_shading(lua_State *_pL) { return DoLuaScriptCall(_pL, 308); }
int lua_Script_pipeline_draw_to_screen(lua_State *_pL) { return DoLuaScriptCall(_pL, 309); }
int lua_Script_resolve_sound(lua_State *_pL) { return DoLuaScriptCall(_pL, 310); }
int lua_Script_get_sound_vol(lua_State *_pL) { return DoLuaScriptCall(_pL, 311); }
int lua_Script_create_sound(lua_State *_pL) { return DoLuaScriptCall(_pL, 312); }
int lua_Script_wallcam_compute_angle(lua_State *_pL) { return DoLuaScriptCall(_pL, 313); }
int lua_Script_create_sound_floor(lua_State *_pL) { return DoLuaScriptCall(_pL, 314); }
int lua_Script_dialogue_init(lua_State *_pL) { return DoLuaScriptCall(_pL, 315); }
int lua_Script_predictive_line_break_tags(lua_State *_pL) { return DoLuaScriptCall(_pL, 316); }
int lua_Script_predictive_line_break_tags_asian(lua_State *_pL) { return DoLuaScriptCall(_pL, 317); }
int lua_Script_find_next_char(lua_State *_pL) { return DoLuaScriptCall(_pL, 318); }
int lua_Script_create_textbox_auto(lua_State *_pL) { return DoLuaScriptCall(_pL, 319); }
int lua_Script_create_textbox(lua_State *_pL) { return DoLuaScriptCall(_pL, 320); }
int lua_Script_create_textbox_passive(lua_State *_pL) { return DoLuaScriptCall(_pL, 321); }
int lua_Script_create_textbox_passive_auto(lua_State *_pL) { return DoLuaScriptCall(_pL, 322); }
int lua_Script_add_voiceover(lua_State *_pL) { return DoLuaScriptCall(_pL, 323); }
int lua_Script_add_textsfx(lua_State *_pL) { return DoLuaScriptCall(_pL, 324); }
int lua_Script_create_choicebox(lua_State *_pL) { return DoLuaScriptCall(_pL, 325); }
int lua_Script_add_choice(lua_State *_pL) { return DoLuaScriptCall(_pL, 326); }
int lua_Script_seen_state(lua_State *_pL) { return DoLuaScriptCall(_pL, 327); }
int lua_Script_update_seen_states(lua_State *_pL) { return DoLuaScriptCall(_pL, 328); }
int lua_Script_shift_textbox(lua_State *_pL) { return DoLuaScriptCall(_pL, 329); }
int lua_Script_shift_textbox_arrow_horizontal(lua_State *_pL) { return DoLuaScriptCall(_pL, 330); }
int lua_Script_textbox_set_outline_color(lua_State *_pL) { return DoLuaScriptCall(_pL, 331); }
int lua_Script_textbox_explode(lua_State *_pL) { return DoLuaScriptCall(_pL, 332); }
int lua_Script_scr_addChoice(lua_State *_pL) { return DoLuaScriptCall(_pL, 333); }
int lua_Script_scr_addChoice_crossout(lua_State *_pL) { return DoLuaScriptCall(_pL, 334); }
int lua_Script_scr_addInterrupt(lua_State *_pL) { return DoLuaScriptCall(_pL, 335); }
int lua_Script_scr_addInterrupt_norepeat(lua_State *_pL) { return DoLuaScriptCall(_pL, 336); }
int lua_Script_scr_addInterrupt_crossout(lua_State *_pL) { return DoLuaScriptCall(_pL, 337); }
int lua_Script_scr_addChoice_norepeat(lua_State *_pL) { return DoLuaScriptCall(_pL, 338); }
int lua_Script_dialogue_1(lua_State *_pL) { return DoLuaScriptCall(_pL, 339); }
int lua_Script_dialogue_factorysci_toosoon(lua_State *_pL) { return DoLuaScriptCall(_pL, 340); }
int lua_Script_dialogue_factorysci(lua_State *_pL) { return DoLuaScriptCall(_pL, 341); }
int lua_Script_dialogue_factory_v(lua_State *_pL) { return DoLuaScriptCall(_pL, 342); }
int lua_Script_dialogue_factory_v_autokill(lua_State *_pL) { return DoLuaScriptCall(_pL, 343); }
int lua_Script_dialogue_receptionist(lua_State *_pL) { return DoLuaScriptCall(_pL, 344); }
int lua_Script_dialogue_lobby_cop(lua_State *_pL) { return DoLuaScriptCall(_pL, 345); }
int lua_Script_dialogue_receptionist_2(lua_State *_pL) { return DoLuaScriptCall(_pL, 346); }
int lua_Script_dialogue_gangster_1(lua_State *_pL) { return DoLuaScriptCall(_pL, 347); }
int lua_Script_dialogue_penthouse(lua_State *_pL) { return DoLuaScriptCall(_pL, 348); }
int lua_Script_dialogue_club_2_tut1(lua_State *_pL) { return DoLuaScriptCall(_pL, 349); }
int lua_Script_dialogue_club_2_tut2(lua_State *_pL) { return DoLuaScriptCall(_pL, 350); }
int lua_Script_dialogue_club_run(lua_State *_pL) { return DoLuaScriptCall(_pL, 351); }
int lua_Script_dialogue_club_phone(lua_State *_pL) { return DoLuaScriptCall(_pL, 352); }
int lua_Script_dialogue_club_electrohead(lua_State *_pL) { return DoLuaScriptCall(_pL, 353); }
int lua_Script_dialogue_prison_cops(lua_State *_pL) { return DoLuaScriptCall(_pL, 354); }
int lua_Script_dialogue_prison_toiletguy(lua_State *_pL) { return DoLuaScriptCall(_pL, 355); }
int lua_Script_dialogue_prison_call(lua_State *_pL) { return DoLuaScriptCall(_pL, 356); }
int lua_Script_dialogue_prison_call_nochronos(lua_State *_pL) { return DoLuaScriptCall(_pL, 357); }
int lua_Script_dialogue_homeless_vet(lua_State *_pL) { return DoLuaScriptCall(_pL, 358); }
int lua_Script_dialogue_studio_limo_outside(lua_State *_pL) { return DoLuaScriptCall(_pL, 359); }
int lua_Script_dialogue_studio_limo(lua_State *_pL) { return DoLuaScriptCall(_pL, 360); }
int lua_Script_dialogue_haunted_vbreath(lua_State *_pL) { return DoLuaScriptCall(_pL, 361); }
int lua_Script_dialogue_haunted_vbreath_nosword(lua_State *_pL) { return DoLuaScriptCall(_pL, 362); }
int lua_Script_dialogue_studio_vphone(lua_State *_pL) { return DoLuaScriptCall(_pL, 363); }
int lua_Script_dialogue_studio_v1(lua_State *_pL) { return DoLuaScriptCall(_pL, 364); }
int lua_Script_dialogue_studio_v2(lua_State *_pL) { return DoLuaScriptCall(_pL, 365); }
int lua_Script_dialogue_studio_v3(lua_State *_pL) { return DoLuaScriptCall(_pL, 366); }
int lua_Script_dialogue_haunted_elevator(lua_State *_pL) { return DoLuaScriptCall(_pL, 367); }
int lua_Script_dialogue_studio_finale_1(lua_State *_pL) { return DoLuaScriptCall(_pL, 368); }
int lua_Script_dialogue_studio_finale_4(lua_State *_pL) { return DoLuaScriptCall(_pL, 369); }
int lua_Script_dialogue_studio_finale_5(lua_State *_pL) { return DoLuaScriptCall(_pL, 370); }
int lua_Script_dialogue_studio_finale_6(lua_State *_pL) { return DoLuaScriptCall(_pL, 371); }
int lua_Script_dialogue_tied_up(lua_State *_pL) { return DoLuaScriptCall(_pL, 372); }
int lua_Script_dialogue_mansion_outside(lua_State *_pL) { return DoLuaScriptCall(_pL, 373); }
int lua_Script_dialogue_mansion_outside_2(lua_State *_pL) { return DoLuaScriptCall(_pL, 374); }
int lua_Script_dialogue_mansion_kissyface_1(lua_State *_pL) { return DoLuaScriptCall(_pL, 375); }
int lua_Script_dialogue_mansion_kissyface_2(lua_State *_pL) { return DoLuaScriptCall(_pL, 376); }
int lua_Script_dialogue_mansion_v_death(lua_State *_pL) { return DoLuaScriptCall(_pL, 377); }
int lua_Script_dialogue_chinatown_end_cops(lua_State *_pL) { return DoLuaScriptCall(_pL, 378); }
int lua_Script_dialogue_chinatown_end_cops_fire(lua_State *_pL) { return DoLuaScriptCall(_pL, 379); }
int lua_Script_dialogue_chinatown_end_cops_die(lua_State *_pL) { return DoLuaScriptCall(_pL, 380); }
int lua_Script_dialogue_chinatown_end_maskedmen_1(lua_State *_pL) { return DoLuaScriptCall(_pL, 381); }
int lua_Script_dialogue_chinatown_end_maskedmen_2(lua_State *_pL) { return DoLuaScriptCall(_pL, 382); }
int lua_Script_dialogue_chinatown_headhunter_dragon(lua_State *_pL) { return DoLuaScriptCall(_pL, 383); }
int lua_Script_dialogue_chinatown_headhunter_2(lua_State *_pL) { return DoLuaScriptCall(_pL, 384); }
int lua_Script_dialogue_chinatown_cops(lua_State *_pL) { return DoLuaScriptCall(_pL, 385); }
int lua_Script_dialogue_chinatown_bouncer(lua_State *_pL) { return DoLuaScriptCall(_pL, 386); }
int lua_Script_dialogue_chinatown_bouncer_2(lua_State *_pL) { return DoLuaScriptCall(_pL, 387); }
int lua_Script_dialogue_chinatown_roulette_1(lua_State *_pL) { return DoLuaScriptCall(_pL, 388); }
int lua_Script_dialogue_chinatown_passive_cops(lua_State *_pL) { return DoLuaScriptCall(_pL, 389); }
int lua_Script_dialogue_dragon_cops_preentrance(lua_State *_pL) { return DoLuaScriptCall(_pL, 390); }
int lua_Script_dialogue_dragon_entrance(lua_State *_pL) { return DoLuaScriptCall(_pL, 391); }
int lua_Script_dialogue_dragon_fa_yuan(lua_State *_pL) { return DoLuaScriptCall(_pL, 392); }
int lua_Script_dialogue_mysterious_call(lua_State *_pL) { return DoLuaScriptCall(_pL, 393); }
int lua_Script_dialogue_sniper_1(lua_State *_pL) { return DoLuaScriptCall(_pL, 394); }
int lua_Script_dialogue_sniper_2_fail(lua_State *_pL) { return DoLuaScriptCall(_pL, 395); }
int lua_Script_dialogue_sniper_2_success(lua_State *_pL) { return DoLuaScriptCall(_pL, 396); }
int lua_Script_dialogue_sniper_3(lua_State *_pL) { return DoLuaScriptCall(_pL, 397); }
int lua_Script_dialogue_sniper_wave0(lua_State *_pL) { return DoLuaScriptCall(_pL, 398); }
int lua_Script_dialogue_sniper_wave_complete(lua_State *_pL) { return DoLuaScriptCall(_pL, 399); }
int lua_Script_dialogue_sniper_4(lua_State *_pL) { return DoLuaScriptCall(_pL, 400); }
int lua_Script_dialogue_sniper_5(lua_State *_pL) { return DoLuaScriptCall(_pL, 401); }
int lua_Script_dialogue_sniper_6(lua_State *_pL) { return DoLuaScriptCall(_pL, 402); }
int lua_Script_dialogue_sniper_fake_1(lua_State *_pL) { return DoLuaScriptCall(_pL, 403); }
int lua_Script_dialogue_sniper_fake_2(lua_State *_pL) { return DoLuaScriptCall(_pL, 404); }
int lua_Script_dialogue_sniper_fake_3(lua_State *_pL) { return DoLuaScriptCall(_pL, 405); }
int lua_Script_dialogue_sniper_fake_4(lua_State *_pL) { return DoLuaScriptCall(_pL, 406); }
int lua_Script_dialogue_sniper_fake_6(lua_State *_pL) { return DoLuaScriptCall(_pL, 407); }
int lua_Script_dialogue_sniper_fake_7(lua_State *_pL) { return DoLuaScriptCall(_pL, 408); }
int lua_Script_dialogue_sniper_fake_8(lua_State *_pL) { return DoLuaScriptCall(_pL, 409); }
int lua_Script_dialogue_sniper_fake_9(lua_State *_pL) { return DoLuaScriptCall(_pL, 410); }
int lua_Script_dialogue_leon_death(lua_State *_pL) { return DoLuaScriptCall(_pL, 411); }
int lua_Script_dialogue_bunker_receptionist(lua_State *_pL) { return DoLuaScriptCall(_pL, 412); }
int lua_Script_dialogue_bunker_receptionist_oldguy(lua_State *_pL) { return DoLuaScriptCall(_pL, 413); }
int lua_Script_dialogue_bunker_headhunter_1(lua_State *_pL) { return DoLuaScriptCall(_pL, 414); }
int lua_Script_dialogue_bunker_headhunter_2(lua_State *_pL) { return DoLuaScriptCall(_pL, 415); }
int lua_Script_dialogue_bunker_headhunter_dying(lua_State *_pL) { return DoLuaScriptCall(_pL, 416); }
int lua_Script_dialogue_bunker_access_denied(lua_State *_pL) { return DoLuaScriptCall(_pL, 417); }
int lua_Script_dialogue_bunker_end(lua_State *_pL) { return DoLuaScriptCall(_pL, 418); }
int lua_Script_dialogue_headhunter_fight_1(lua_State *_pL) { return DoLuaScriptCall(_pL, 419); }
int lua_Script_dialogue_headhunter_fight_2(lua_State *_pL) { return DoLuaScriptCall(_pL, 420); }
int lua_Script_dialogue_headhunter_fight_3(lua_State *_pL) { return DoLuaScriptCall(_pL, 421); }
int lua_Script_dialogue_govtlab_locked(lua_State *_pL) { return DoLuaScriptCall(_pL, 422); }
int lua_Script_dialogue_girl_hallway_2(lua_State *_pL) { return DoLuaScriptCall(_pL, 423); }
int lua_Script_dialogue_girl_hallway_3(lua_State *_pL) { return DoLuaScriptCall(_pL, 424); }
int lua_Script_dialogue_girl_hallway_4(lua_State *_pL) { return DoLuaScriptCall(_pL, 425); }
int lua_Script_dialogue_girl_hallway_6(lua_State *_pL) { return DoLuaScriptCall(_pL, 426); }
int lua_Script_dialogue_girl_apartment_3_1(lua_State *_pL) { return DoLuaScriptCall(_pL, 427); }
int lua_Script_dialogue_girl_apartment_3_3(lua_State *_pL) { return DoLuaScriptCall(_pL, 428); }
int lua_Script_dialogue_girl_apartment_3_4(lua_State *_pL) { return DoLuaScriptCall(_pL, 429); }
int lua_Script_dialogue_girl_apartment_4_leavemovie(lua_State *_pL) { return DoLuaScriptCall(_pL, 430); }
int lua_Script_dialogue_apartment5_movie_girl(lua_State *_pL) { return DoLuaScriptCall(_pL, 431); }
int lua_Script_dialogue_apartment5_movie_solo(lua_State *_pL) { return DoLuaScriptCall(_pL, 432); }
int lua_Script_dialogue_girl_apartment_7_morning(lua_State *_pL) { return DoLuaScriptCall(_pL, 433); }
int lua_Script_dialogue_girl_apartment_7_morning_2(lua_State *_pL) { return DoLuaScriptCall(_pL, 434); }
int lua_Script_dialogue_girl_apartment_7_afternoon_1(lua_State *_pL) { return DoLuaScriptCall(_pL, 435); }
int lua_Script_dialogue_girl_apartment_7_afternoon_2(lua_State *_pL) { return DoLuaScriptCall(_pL, 436); }
int lua_Script_dialogue_girl_apartment_9_afternoon(lua_State *_pL) { return DoLuaScriptCall(_pL, 437); }
int lua_Script_dialogue_girl_apartment_9_afternoon_rooftop_1(lua_State *_pL) { return DoLuaScriptCall(_pL, 438); }
int lua_Script_dialogue_girl_apartment_9_afternoon_rooftop_2(lua_State *_pL) { return DoLuaScriptCall(_pL, 439); }
int lua_Script_dialogue_girl_apartment_10(lua_State *_pL) { return DoLuaScriptCall(_pL, 440); }
int lua_Script_dialogue_girl_apartment_10_1(lua_State *_pL) { return DoLuaScriptCall(_pL, 441); }
int lua_Script_dialogue_girl_apartment_10_2(lua_State *_pL) { return DoLuaScriptCall(_pL, 442); }
int lua_Script_dialogue_girl_apartment_10_3(lua_State *_pL) { return DoLuaScriptCall(_pL, 443); }
int lua_Script_dialogue_girl_apartment_10_4(lua_State *_pL) { return DoLuaScriptCall(_pL, 444); }
int lua_Script_dialogue_apartment_searchresult_leviathan_fail(lua_State *_pL) { return DoLuaScriptCall(_pL, 445); }
int lua_Script_dialogue_apartment_searchresult_leviathan_failf(lua_State *_pL) { return DoLuaScriptCall(_pL, 446); }
int lua_Script_dialogue_girl_halloween(lua_State *_pL) { return DoLuaScriptCall(_pL, 447); }
int lua_Script_dialogue_girl_candy(lua_State *_pL) { return DoLuaScriptCall(_pL, 448); }
int lua_Script_dialogue_tv_1(lua_State *_pL) { return DoLuaScriptCall(_pL, 449); }
int lua_Script_dialogue_tv_2(lua_State *_pL) { return DoLuaScriptCall(_pL, 450); }
int lua_Script_dialogue_tv_3(lua_State *_pL) { return DoLuaScriptCall(_pL, 451); }
int lua_Script_dialogue_tv_5(lua_State *_pL) { return DoLuaScriptCall(_pL, 452); }
int lua_Script_dialogue_tv_6(lua_State *_pL) { return DoLuaScriptCall(_pL, 453); }
int lua_Script_dialogue_videostore_girl(lua_State *_pL) { return DoLuaScriptCall(_pL, 454); }
int lua_Script_dialogue_bar_0(lua_State *_pL) { return DoLuaScriptCall(_pL, 455); }
int lua_Script_dialogue_bar_1(lua_State *_pL) { return DoLuaScriptCall(_pL, 456); }
int lua_Script_dialogue_bar_2(lua_State *_pL) { return DoLuaScriptCall(_pL, 457); }
int lua_Script_dialogue_bar_3(lua_State *_pL) { return DoLuaScriptCall(_pL, 458); }
int lua_Script_dialogue_jukebox(lua_State *_pL) { return DoLuaScriptCall(_pL, 459); }
int lua_Script_dialogue_hallway_passive(lua_State *_pL) { return DoLuaScriptCall(_pL, 460); }
int lua_Script_dialogue_hallway_police_1(lua_State *_pL) { return DoLuaScriptCall(_pL, 461); }
int lua_Script_dialogue_apartment_note(lua_State *_pL) { return DoLuaScriptCall(_pL, 462); }
int lua_Script_dialogue_hallway_police_2(lua_State *_pL) { return DoLuaScriptCall(_pL, 463); }
int lua_Script_dialogue_hallway_police_3(lua_State *_pL) { return DoLuaScriptCall(_pL, 464); }
int lua_Script_dialogue_snuff_0(lua_State *_pL) { return DoLuaScriptCall(_pL, 465); }
int lua_Script_dialogue_snuff_1(lua_State *_pL) { return DoLuaScriptCall(_pL, 466); }
int lua_Script_dialogue_snuff_2(lua_State *_pL) { return DoLuaScriptCall(_pL, 467); }
int lua_Script_dialogue_snuff_3(lua_State *_pL) { return DoLuaScriptCall(_pL, 468); }
int lua_Script_dialogue_snuff_4(lua_State *_pL) { return DoLuaScriptCall(_pL, 469); }
int lua_Script_dialogue_snuff_5(lua_State *_pL) { return DoLuaScriptCall(_pL, 470); }
int lua_Script_dialogue_ending_walkie(lua_State *_pL) { return DoLuaScriptCall(_pL, 471); }
int lua_Script_dialogue_ending_snow(lua_State *_pL) { return DoLuaScriptCall(_pL, 472); }
int lua_Script_dialogue_nightmare_scientist_gibberish(lua_State *_pL) { return DoLuaScriptCall(_pL, 473); }
int lua_Script_dialogue_nightmare_scientist_gibberish_2(lua_State *_pL) { return DoLuaScriptCall(_pL, 474); }
int lua_Script_dialogue_nightmare_scientist_gibberish_3(lua_State *_pL) { return DoLuaScriptCall(_pL, 475); }
int lua_Script_dialogue_nightmare_scientist_talk(lua_State *_pL) { return DoLuaScriptCall(_pL, 476); }
int lua_Script_dialogue_fullscreen_0(lua_State *_pL) { return DoLuaScriptCall(_pL, 477); }
int lua_Script_dialogue_results_1(lua_State *_pL) { return DoLuaScriptCall(_pL, 478); }
int lua_Script_dialogue_results_1_bad(lua_State *_pL) { return DoLuaScriptCall(_pL, 479); }
int lua_Script_dialogue_results_2_good(lua_State *_pL) { return DoLuaScriptCall(_pL, 480); }
int lua_Script_dialogue_results_2_bad(lua_State *_pL) { return DoLuaScriptCall(_pL, 481); }
int lua_Script_dialogue_results_3_good(lua_State *_pL) { return DoLuaScriptCall(_pL, 482); }
int lua_Script_dialogue_results_3_okay(lua_State *_pL) { return DoLuaScriptCall(_pL, 483); }
int lua_Script_dialogue_results_3_bad(lua_State *_pL) { return DoLuaScriptCall(_pL, 484); }
int lua_Script_dialogue_results_4_good(lua_State *_pL) { return DoLuaScriptCall(_pL, 485); }
int lua_Script_dialogue_results_4_bad(lua_State *_pL) { return DoLuaScriptCall(_pL, 486); }
int lua_Script_dialogue_results_4_nochronos_good(lua_State *_pL) { return DoLuaScriptCall(_pL, 487); }
int lua_Script_dialogue_results_4_nochronos_bad(lua_State *_pL) { return DoLuaScriptCall(_pL, 488); }
int lua_Script_dialogue_results_5(lua_State *_pL) { return DoLuaScriptCall(_pL, 489); }
int lua_Script_dialogue_results_6(lua_State *_pL) { return DoLuaScriptCall(_pL, 490); }
int lua_Script_dialogue_results_7(lua_State *_pL) { return DoLuaScriptCall(_pL, 491); }
int lua_Script_dialogue_results_9(lua_State *_pL) { return DoLuaScriptCall(_pL, 492); }
int lua_Script_dialogue_results_9_2(lua_State *_pL) { return DoLuaScriptCall(_pL, 493); }
int lua_Script_dialogue_results_10(lua_State *_pL) { return DoLuaScriptCall(_pL, 494); }
int lua_Script_dialogue_results_11(lua_State *_pL) { return DoLuaScriptCall(_pL, 495); }
int lua_Script_dialogue_unlocked_lab(lua_State *_pL) { return DoLuaScriptCall(_pL, 496); }
int lua_Script_dialogue_psych_passive(lua_State *_pL) { return DoLuaScriptCall(_pL, 497); }
int lua_Script_dialogue_psych_passive_2(lua_State *_pL) { return DoLuaScriptCall(_pL, 498); }
int lua_Script_dialogue_motel_gangsters(lua_State *_pL) { return DoLuaScriptCall(_pL, 499); }
int lua_Script_dialogue_club_bouncer(lua_State *_pL) { return DoLuaScriptCall(_pL, 500); }
int lua_Script_dialogue_club_bouncerfriend(lua_State *_pL) { return DoLuaScriptCall(_pL, 501); }
int lua_Script_dialogue_club_pipes(lua_State *_pL) { return DoLuaScriptCall(_pL, 502); }
int lua_Script_dialogue_club_skinnyricky(lua_State *_pL) { return DoLuaScriptCall(_pL, 503); }
int lua_Script_dialogue_haunted_robot(lua_State *_pL) { return DoLuaScriptCall(_pL, 504); }
int lua_Script_dialogue_haunted_robot2(lua_State *_pL) { return DoLuaScriptCall(_pL, 505); }
int lua_Script_dialogue_mansion_fall(lua_State *_pL) { return DoLuaScriptCall(_pL, 506); }
int lua_Script_dialogue_mansion_eavesdrop(lua_State *_pL) { return DoLuaScriptCall(_pL, 507); }
int lua_Script_dialogue_notea(lua_State *_pL) { return DoLuaScriptCall(_pL, 508); }
int lua_Script_dialogue_candy(lua_State *_pL) { return DoLuaScriptCall(_pL, 509); }
int lua_Script_dialogue_psych_2(lua_State *_pL) { return DoLuaScriptCall(_pL, 510); }
int lua_Script_dialogue_psych_3(lua_State *_pL) { return DoLuaScriptCall(_pL, 511); }
int lua_Script_dialogue_psych_4(lua_State *_pL) { return DoLuaScriptCall(_pL, 512); }
int lua_Script_dialogue_psych_note(lua_State *_pL) { return DoLuaScriptCall(_pL, 513); }
int lua_Script_dialogue_psych_6_1(lua_State *_pL) { return DoLuaScriptCall(_pL, 514); }
int lua_Script_dialogue_psych_6_2(lua_State *_pL) { return DoLuaScriptCall(_pL, 515); }
int lua_Script_dialogue_psych_6_3(lua_State *_pL) { return DoLuaScriptCall(_pL, 516); }
int lua_Script_dialogue_psych_6_4(lua_State *_pL) { return DoLuaScriptCall(_pL, 517); }
int lua_Script_dialogue_psych_7(lua_State *_pL) { return DoLuaScriptCall(_pL, 518); }
int lua_Script_dialogue_psych_7_2(lua_State *_pL) { return DoLuaScriptCall(_pL, 519); }
int lua_Script_dialogue_psych_7_3(lua_State *_pL) { return DoLuaScriptCall(_pL, 520); }
int lua_Script_dialogue_psych_10(lua_State *_pL) { return DoLuaScriptCall(_pL, 521); }
int lua_Script_dialogue_psych_11(lua_State *_pL) { return DoLuaScriptCall(_pL, 522); }
int lua_Script_dialogue_psych_11_battle(lua_State *_pL) { return DoLuaScriptCall(_pL, 523); }
int lua_Script_dialogue_psych_paper(lua_State *_pL) { return DoLuaScriptCall(_pL, 524); }
int lua_Script_dialogue_psych_desk_rock(lua_State *_pL) { return DoLuaScriptCall(_pL, 525); }
int lua_Script_dialogue_psych_desk_picture(lua_State *_pL) { return DoLuaScriptCall(_pL, 526); }
int lua_Script_dialogue_psych_desk_generic(lua_State *_pL) { return DoLuaScriptCall(_pL, 527); }
int lua_Script_dialogue_psych_desk_annoyed(lua_State *_pL) { return DoLuaScriptCall(_pL, 528); }
int lua_Script_dialogue_psych_desk_angry(lua_State *_pL) { return DoLuaScriptCall(_pL, 529); }
int lua_Script_init_textbox_actors(lua_State *_pL) { return DoLuaScriptCall(_pL, 530); }
int lua_Script_set_actor_talksfx(lua_State *_pL) { return DoLuaScriptCall(_pL, 531); }
int lua_Script_dialogue_maskedmen1(lua_State *_pL) { return DoLuaScriptCall(_pL, 532); }
int lua_Script_dialogue_maskedmen_alleyway(lua_State *_pL) { return DoLuaScriptCall(_pL, 533); }
int lua_Script_dialogue_maskedmen_postcredits(lua_State *_pL) { return DoLuaScriptCall(_pL, 534); }
int lua_Script_switch_saveload_begin(lua_State *_pL) { return DoLuaScriptCall(_pL, 535); }
int lua_Script_switch_save_end(lua_State *_pL) { return DoLuaScriptCall(_pL, 536); }
int lua_Script_cutscene_init(lua_State *_pL) { return DoLuaScriptCall(_pL, 537); }
int lua_Script_cutscene_wait(lua_State *_pL) { return DoLuaScriptCall(_pL, 538); }
int lua_Script_cutscene_move_player(lua_State *_pL) { return DoLuaScriptCall(_pL, 539); }
int lua_Script_create_enemybike_formation(lua_State *_pL) { return DoLuaScriptCall(_pL, 540); }
int lua_Script_create_enemybike_formation_vertical(lua_State *_pL) { return DoLuaScriptCall(_pL, 541); }
int lua_Script_check_bikeslash_collision(lua_State *_pL) { return DoLuaScriptCall(_pL, 542); }
int lua_Script_save_game(lua_State *_pL) { return DoLuaScriptCall(_pL, 543); }
int lua_Script_load_game(lua_State *_pL) { return DoLuaScriptCall(_pL, 544); }
int lua_Script_save_options(lua_State *_pL) { return DoLuaScriptCall(_pL, 545); }
int lua_Script_load_options(lua_State *_pL) { return DoLuaScriptCall(_pL, 546); }
int lua_Script_save_version_number(lua_State *_pL) { return DoLuaScriptCall(_pL, 547); }
int lua_Script_load_version_number(lua_State *_pL) { return DoLuaScriptCall(_pL, 548); }
int lua_Script_save_controls(lua_State *_pL) { return DoLuaScriptCall(_pL, 549); }
int lua_Script_load_controls(lua_State *_pL) { return DoLuaScriptCall(_pL, 550); }
int lua_Script_save_current_speedrun(lua_State *_pL) { return DoLuaScriptCall(_pL, 551); }
int lua_Script_load_current_speedrun(lua_State *_pL) { return DoLuaScriptCall(_pL, 552); }
int lua_Script_save_speedrun_options(lua_State *_pL) { return DoLuaScriptCall(_pL, 553); }
int lua_Script_load_speedrun_options(lua_State *_pL) { return DoLuaScriptCall(_pL, 554); }
int lua_Script_save_achievements(lua_State *_pL) { return DoLuaScriptCall(_pL, 555); }
int lua_Script_load_achievements(lua_State *_pL) { return DoLuaScriptCall(_pL, 556); }
int lua_Script_save_variable(lua_State *_pL) { return DoLuaScriptCall(_pL, 557); }
int lua_Script_save_variable_rounded(lua_State *_pL) { return DoLuaScriptCall(_pL, 558); }
int lua_Script_load_variable(lua_State *_pL) { return DoLuaScriptCall(_pL, 559); }
int lua_Script_load_variable_rounded(lua_State *_pL) { return DoLuaScriptCall(_pL, 560); }
int lua_Script_load_variable_string(lua_State *_pL) { return DoLuaScriptCall(_pL, 561); }
int lua_Script_generate_hash(lua_State *_pL) { return DoLuaScriptCall(_pL, 562); }
int lua_Script_get_line_text(lua_State *_pL) { return DoLuaScriptCall(_pL, 563); }
int lua_Script_get_line_textbox_width(lua_State *_pL) { return DoLuaScriptCall(_pL, 564); }
int lua_Script_get_choice_text(lua_State *_pL) { return DoLuaScriptCall(_pL, 565); }
int lua_Script_get_misc_text(lua_State *_pL) { return DoLuaScriptCall(_pL, 566); }
int lua_Script_init_lines(lua_State *_pL) { return DoLuaScriptCall(_pL, 567); }
int lua_Script_init_misc_text(lua_State *_pL) { return DoLuaScriptCall(_pL, 568); }
int lua_Script_init_option_translations(lua_State *_pL) { return DoLuaScriptCall(_pL, 569); }
int lua_Script_translate_option(lua_State *_pL) { return DoLuaScriptCall(_pL, 570); }
int lua_Script_draw_set_font_localized(lua_State *_pL) { return DoLuaScriptCall(_pL, 571); }
int lua_Script_draw_set_font_override(lua_State *_pL) { return DoLuaScriptCall(_pL, 572); }
int lua_Script_draw_text_scaled(lua_State *_pL) { return DoLuaScriptCall(_pL, 573); }
int lua_Script_draw_text_scaled_outline_ext(lua_State *_pL) { return DoLuaScriptCall(_pL, 574); }
int lua_Script_draw_text_scaled_color(lua_State *_pL) { return DoLuaScriptCall(_pL, 575); }
int lua_Script_draw_text_scaled_colour(lua_State *_pL) { return DoLuaScriptCall(_pL, 576); }
int lua_Script_draw_text_scaled_transformed(lua_State *_pL) { return DoLuaScriptCall(_pL, 577); }
int lua_Script_draw_text_scaled_ext_transformed(lua_State *_pL) { return DoLuaScriptCall(_pL, 578); }
int lua_Script_draw_text_scaled_transformed_colour(lua_State *_pL) { return DoLuaScriptCall(_pL, 579); }
int lua_Script_draw_text_scaled_transformed_color(lua_State *_pL) { return DoLuaScriptCall(_pL, 580); }
int lua_Script_draw_text_scaled_glow_ext(lua_State *_pL) { return DoLuaScriptCall(_pL, 581); }
int lua_Script_trigger_steam_achievement(lua_State *_pL) { return DoLuaScriptCall(_pL, 582); }
int lua_Script_draw_speedrun_timer(lua_State *_pL) { return DoLuaScriptCall(_pL, 583); }
int lua_Script_char_to_milli(lua_State *_pL) { return DoLuaScriptCall(_pL, 584); }
int lua_Script_get_random(lua_State *_pL) { return DoLuaScriptCall(_pL, 585); }
int lua_Script_choose_random(lua_State *_pL) { return DoLuaScriptCall(_pL, 586); }
