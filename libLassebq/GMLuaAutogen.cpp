#include "GMLuaAutogen.h"

lua_CFunction lua_get_RLFunc_by_id(const int id)
{
	switch (id)
	{
	case 0: return (lua_camera_create);
	case 1: return (lua_camera_create_view);
	case 2: return (lua_camera_destroy);
	case 3: return (lua_camera_apply);
	case 4: return (lua_camera_get_active);
	case 5: return (lua_camera_get_default);
	case 6: return (lua_camera_set_default);
	case 7: return (lua_camera_set_view_mat);
	case 8: return (lua_camera_set_proj_mat);
	case 9: return (lua_camera_set_update_script);
	case 10: return (lua_camera_set_begin_script);
	case 11: return (lua_camera_set_end_script);
	case 12: return (lua_camera_set_view_pos);
	case 13: return (lua_camera_set_view_size);
	case 14: return (lua_camera_set_view_speed);
	case 15: return (lua_camera_set_view_border);
	case 16: return (lua_camera_set_view_angle);
	case 17: return (lua_camera_set_view_target);
	case 18: return (lua_camera_get_view_mat);
	case 19: return (lua_camera_get_proj_mat);
	case 20: return (lua_camera_get_update_script);
	case 21: return (lua_camera_get_begin_script);
	case 22: return (lua_camera_get_end_script);
	case 23: return (lua_camera_get_view_x);
	case 24: return (lua_camera_get_view_y);
	case 25: return (lua_camera_get_view_width);
	case 26: return (lua_camera_get_view_height);
	case 27: return (lua_camera_get_view_speed_x);
	case 28: return (lua_camera_get_view_speed_y);
	case 29: return (lua_camera_get_view_border_x);
	case 30: return (lua_camera_get_view_border_y);
	case 31: return (lua_camera_get_view_angle);
	case 32: return (lua_camera_get_view_target);
	case 33: return (lua_view_get_camera);
	case 34: return (lua_view_get_visible);
	case 35: return (lua_view_get_xport);
	case 36: return (lua_view_get_yport);
	case 37: return (lua_view_get_wport);
	case 38: return (lua_view_get_hport);
	case 39: return (lua_view_get_surface_id);
	case 40: return (lua_view_set_camera);
	case 41: return (lua_view_set_visible);
	case 42: return (lua_view_set_xport);
	case 43: return (lua_view_set_yport);
	case 44: return (lua_view_set_wport);
	case 45: return (lua_view_set_hport);
	case 46: return (lua_view_set_surface_id);
	case 47: return (lua_move_random);
	case 48: return (lua_place_free);
	case 49: return (lua_place_empty);
	case 50: return (lua_place_meeting);
	case 51: return (lua_place_snapped);
	case 52: return (lua_move_snap);
	case 53: return (lua_move_towards_point);
	case 54: return (lua_move_contact);
	case 55: return (lua_move_contact_solid);
	case 56: return (lua_move_contact_all);
	case 57: return (lua_move_outside_solid);
	case 58: return (lua_move_outside_all);
	case 59: return (lua_move_bounce);
	case 60: return (lua_move_bounce_solid);
	case 61: return (lua_move_bounce_all);
	case 62: return (lua_move_wrap);
	case 63: return (lua_motion_set);
	case 64: return (lua_motion_add);
	case 65: return (lua_distance_to_point);
	case 66: return (lua_distance_to_object);
	case 67: return (lua_path_start);
	case 68: return (lua_path_end);
	case 69: return (lua_mp_linear_step);
	case 70: return (lua_mp_linear_path);
	case 71: return (lua_mp_linear_step_object);
	case 72: return (lua_mp_linear_path_object);
	case 73: return (lua_mp_potential_settings);
	case 74: return (lua_mp_potential_step);
	case 75: return (lua_mp_potential_path);
	case 76: return (lua_mp_potential_step_object);
	case 77: return (lua_mp_potential_path_object);
	case 78: return (lua_mp_grid_create);
	case 79: return (lua_mp_grid_destroy);
	case 80: return (lua_mp_grid_clear_all);
	case 81: return (lua_mp_grid_clear_cell);
	case 82: return (lua_mp_grid_clear_rectangle);
	case 83: return (lua_mp_grid_add_cell);
	case 84: return (lua_mp_grid_get_cell);
	case 85: return (lua_mp_grid_add_rectangle);
	case 86: return (lua_mp_grid_add_instances);
	case 87: return (lua_mp_grid_path);
	case 88: return (lua_mp_grid_draw);
	case 89: return (lua_mp_grid_to_ds_grid);
	case 90: return (lua_collision_point);
	case 91: return (lua_collision_point_list);
	case 92: return (lua_collision_rectangle);
	case 93: return (lua_collision_rectangle_list);
	case 94: return (lua_collision_circle);
	case 95: return (lua_collision_circle_list);
	case 96: return (lua_collision_ellipse);
	case 97: return (lua_collision_ellipse_list);
	case 98: return (lua_collision_line);
	case 99: return (lua_collision_line_list);
	case 100: return (lua_instance_find);
	case 101: return (lua_instance_exists);
	case 102: return (lua_instance_number);
	case 103: return (lua_instance_position);
	case 104: return (lua_instance_position_list);
	case 105: return (lua_instance_nearest);
	case 106: return (lua_instance_furthest);
	case 107: return (lua_instance_place);
	case 108: return (lua_instance_place_list);
	case 109: return (lua_instance_create_depth);
	case 110: return (lua_instance_create_layer);
	case 111: return (lua_instance_copy);
	case 112: return (lua_instance_change);
	case 113: return (lua_instance_destroy);
	case 114: return (lua_instance_sprite);
	case 115: return (lua_position_empty);
	case 116: return (lua_position_meeting);
	case 117: return (lua_position_destroy);
	case 118: return (lua_position_change);
	case 119: return (lua_instance_id_get);
	case 120: return (lua_instance_deactivate_all);
	case 121: return (lua_instance_deactivate_object);
	case 122: return (lua_instance_deactivate_region);
	case 123: return (lua_instance_activate_all);
	case 124: return (lua_instance_activate_object);
	case 125: return (lua_instance_activate_region);
	case 126: return (lua_instance_deactivate_region_special);
	case 127: return (lua_room_goto);
	case 128: return (lua_room_goto_previous);
	case 129: return (lua_room_goto_next);
	case 130: return (lua_room_previous);
	case 131: return (lua_room_next);
	case 132: return (lua_room_restart);
	case 133: return (lua_game_end);
	case 134: return (lua_game_restart);
	case 135: return (lua_game_load);
	case 136: return (lua_game_save);
	case 137: return (lua_game_save_buffer);
	case 138: return (lua_game_load_buffer);
	case 139: return (lua_transition_define);
	case 140: return (lua_transition_exists);
	case 141: return (lua_sleep);
	case 142: return (lua_point_in_rectangle);
	case 143: return (lua_point_in_triangle);
	case 144: return (lua_point_in_circle);
	case 145: return (lua_rectangle_in_rectangle);
	case 146: return (lua_rectangle_in_triangle);
	case 147: return (lua_rectangle_in_circle);
	case 148: return (lua_is_bool);
	case 149: return (lua_is_real);
	case 150: return (lua_is_string);
	case 151: return (lua_is_array);
	case 152: return (lua_is_undefined);
	case 153: return (lua_is_int32);
	case 154: return (lua_is_int64);
	case 155: return (lua_is_ptr);
	case 156: return (lua_is_vec3);
	case 157: return (lua_is_vec4);
	case 158: return (lua_is_matrix);
	case 159: return (lua_typeof);
	case 160: return (lua_array_length_1d);
	case 161: return (lua_array_length_2d);
	case 162: return (lua_array_height_2d);
	case 163: return (lua_array_get);
	case 164: return (lua_array_set);
	case 165: return (lua_array_set_pre);
	case 166: return (lua_array_set_post);
	case 167: return (lua_array_get_2D);
	case 168: return (lua_array_set_2D);
	case 169: return (lua_array_set_2D_pre);
	case 170: return (lua_array_set_2D_post);
	case 171: return (lua_array_equals);
	case 172: return (lua_array_create);
	case 173: return (lua_array_copy);
	case 174: return (lua_random);
	case 175: return (lua_random_range);
	case 176: return (lua_irandom);
	case 177: return (lua_irandom_range);
	case 178: return (lua_random_use_old_version);
	case 179: return (lua_random_set_seed);
	case 180: return (lua_random_get_seed);
	case 181: return (lua_randomize);
	case 182: return (lua_randomise);
	case 183: return (lua_abs);
	case 184: return (lua_round);
	case 185: return (lua_floor);
	case 186: return (lua_ceil);
	case 187: return (lua_sign);
	case 188: return (lua_frac);
	case 189: return (lua_sqrt);
	case 190: return (lua_sqr);
	case 191: return (lua_exp);
	case 192: return (lua_ln);
	case 193: return (lua_log2);
	case 194: return (lua_log10);
	case 195: return (lua_sin);
	case 196: return (lua_cos);
	case 197: return (lua_tan);
	case 198: return (lua_arcsin);
	case 199: return (lua_arccos);
	case 200: return (lua_arctan);
	case 201: return (lua_arctan2);
	case 202: return (lua_dsin);
	case 203: return (lua_dcos);
	case 204: return (lua_dtan);
	case 205: return (lua_darcsin);
	case 206: return (lua_darccos);
	case 207: return (lua_darctan);
	case 208: return (lua_darctan2);
	case 209: return (lua_degtorad);
	case 210: return (lua_radtodeg);
	case 211: return (lua_power);
	case 212: return (lua_logn);
	case 213: return (lua_min);
	case 214: return (lua_max);
	case 215: return (lua_min3);
	case 216: return (lua_max3);
	case 217: return (lua_mean);
	case 218: return (lua_median);
	case 219: return (lua_choose);
	case 220: return (lua_clamp);
	case 221: return (lua_lerp);
	case 222: return (lua_real);
	case 223: return (lua_bool);
	case 224: return (lua_string);
	case 225: return (lua_int64);
	case 226: return (lua_ptr);
	case 227: return (lua_string_format);
	case 228: return (lua_chr);
	case 229: return (lua_ansi_char);
	case 230: return (lua_ord);
	case 231: return (lua_string_length);
	case 232: return (lua_string_pos);
	case 233: return (lua_string_copy);
	case 234: return (lua_string_char_at);
	case 235: return (lua_string_ord_at);
	case 236: return (lua_string_byte_length);
	case 237: return (lua_string_byte_at);
	case 238: return (lua_string_set_byte_at);
	case 239: return (lua_string_delete);
	case 240: return (lua_string_insert);
	case 241: return (lua_string_lower);
	case 242: return (lua_string_upper);
	case 243: return (lua_string_repeat);
	case 244: return (lua_string_letters);
	case 245: return (lua_string_digits);
	case 246: return (lua_string_lettersdigits);
	case 247: return (lua_string_replace);
	case 248: return (lua_string_replace_all);
	case 249: return (lua_string_count);
	case 250: return (lua_string_hash_to_newline);
	case 251: return (lua_point_distance);
	case 252: return (lua_point_direction);
	case 253: return (lua_lengthdir_x);
	case 254: return (lua_lengthdir_y);
	case 255: return (lua_point_distance_3d);
	case 256: return (lua_dot_product);
	case 257: return (lua_dot_product_normalised);
	case 258: return (lua_dot_product_normalized);
	case 259: return (lua_dot_product_3d);
	case 260: return (lua_dot_product_3d_normalised);
	case 261: return (lua_dot_product_3d_normalized);
	case 262: return (lua_math_set_epsilon);
	case 263: return (lua_math_get_epsilon);
	case 264: return (lua_angle_difference);
	case 265: return (lua_display_get_width);
	case 266: return (lua_display_get_height);
	case 267: return (lua_display_get_colordepth);
	case 268: return (lua_display_get_frequency);
	case 269: return (lua_display_get_orientation);
	case 270: return (lua_display_set_size);
	case 271: return (lua_display_set_colordepth);
	case 272: return (lua_display_set_frequency);
	case 273: return (lua_display_set_all);
	case 274: return (lua_display_test_all);
	case 275: return (lua_display_reset);
	case 276: return (lua_display_mouse_get_x);
	case 277: return (lua_display_mouse_get_y);
	case 278: return (lua_display_mouse_set);
	case 279: return (lua_draw_enable_drawevent);
	case 280: return (lua_display_get_windows_vertex_buffer_method);
	case 281: return (lua_display_get_windows_alternate_sync);
	case 282: return (lua_display_set_windows_vertex_buffer_method);
	case 283: return (lua_display_set_windows_alternate_sync);
	case 284: return (lua_display_set_ui_visibility);
	case 285: return (lua_display_set_timing_method);
	case 286: return (lua_display_get_timing_method);
	case 287: return (lua_display_set_sleep_margin);
	case 288: return (lua_display_get_sleep_margin);
	case 289: return (lua_window_set_visible);
	case 290: return (lua_window_get_visible);
	case 291: return (lua_window_set_fullscreen);
	case 292: return (lua_window_get_fullscreen);
	case 293: return (lua_window_set_showborder);
	case 294: return (lua_window_get_showborder);
	case 295: return (lua_window_set_showicons);
	case 296: return (lua_window_get_showicons);
	case 297: return (lua_window_set_stayontop);
	case 298: return (lua_window_get_stayontop);
	case 299: return (lua_window_set_sizeable);
	case 300: return (lua_window_get_sizeable);
	case 301: return (lua_window_set_caption);
	case 302: return (lua_window_get_caption);
	case 303: return (lua_window_set_cursor);
	case 304: return (lua_window_get_cursor);
	case 305: return (lua_window_set_color);
	case 306: return (lua_window_set_colour);
	case 307: return (lua_window_get_color);
	case 308: return (lua_window_get_colour);
	case 309: return (lua_window_set_min_width);
	case 310: return (lua_window_set_max_width);
	case 311: return (lua_window_set_min_height);
	case 312: return (lua_window_set_max_height);
	case 313: return (lua_window_set_position);
	case 314: return (lua_window_set_size);
	case 315: return (lua_window_set_rectangle);
	case 316: return (lua_window_center);
	case 317: return (lua_window_default);
	case 318: return (lua_window_get_x);
	case 319: return (lua_window_get_y);
	case 320: return (lua_window_get_width);
	case 321: return (lua_window_get_height);
	case 322: return (lua_window_get_visible_rects);
	case 323: return (lua_window_mouse_get_x);
	case 324: return (lua_window_mouse_get_y);
	case 325: return (lua_window_mouse_set);
	case 326: return (lua_window_view_mouse_get_x);
	case 327: return (lua_window_view_mouse_get_y);
	case 328: return (lua_window_view_mouse_set);
	case 329: return (lua_window_views_mouse_get_x);
	case 330: return (lua_window_views_mouse_get_y);
	case 331: return (lua_window_views_mouse_set);
	case 332: return (lua_screen_save);
	case 333: return (lua_screen_save_part);
	case 334: return (lua_draw_getpixel);
	case 335: return (lua_draw_getpixel_ext);
	case 336: return (lua_draw_set_color);
	case 337: return (lua_draw_set_colour);
	case 338: return (lua_draw_set_alpha);
	case 339: return (lua_draw_get_color);
	case 340: return (lua_draw_get_colour);
	case 341: return (lua_draw_get_alpha);
	case 342: return (lua_make_color);
	case 343: return (lua_make_colour);
	case 344: return (lua_make_color_rgb);
	case 345: return (lua_make_colour_rgb);
	case 346: return (lua_make_color_hsv);
	case 347: return (lua_make_colour_hsv);
	case 348: return (lua_color_get_red);
	case 349: return (lua_colour_get_red);
	case 350: return (lua_color_get_green);
	case 351: return (lua_colour_get_green);
	case 352: return (lua_color_get_blue);
	case 353: return (lua_colour_get_blue);
	case 354: return (lua_color_get_hue);
	case 355: return (lua_colour_get_hue);
	case 356: return (lua_color_get_saturation);
	case 357: return (lua_colour_get_saturation);
	case 358: return (lua_color_get_value);
	case 359: return (lua_colour_get_value);
	case 360: return (lua_merge_color);
	case 361: return (lua_merge_colour);
	case 362: return (lua_draw_set_blend_mode);
	case 363: return (lua_draw_set_blend_mode_ext);
	case 364: return (lua_draw_set_color_write_enable);
	case 365: return (lua_draw_set_colour_write_enable);
	case 366: return (lua_draw_set_alpha_test);
	case 367: return (lua_draw_set_alpha_test_ref_value);
	case 368: return (lua_draw_get_alpha_test);
	case 369: return (lua_draw_get_alpha_test_ref_value);
	case 370: return (lua_draw_clear);
	case 371: return (lua_draw_clear_alpha);
	case 372: return (lua_draw_point);
	case 373: return (lua_draw_line);
	case 374: return (lua_draw_line_width);
	case 375: return (lua_draw_rectangle);
	case 376: return (lua_draw_roundrect);
	case 377: return (lua_draw_roundrect_ext);
	case 378: return (lua_draw_triangle);
	case 379: return (lua_draw_circle);
	case 380: return (lua_draw_ellipse);
	case 381: return (lua_draw_arrow);
	case 382: return (lua_draw_button);
	case 383: return (lua_draw_healthbar);
	case 384: return (lua_draw_path);
	case 385: return (lua_draw_point_color);
	case 386: return (lua_draw_point_colour);
	case 387: return (lua_draw_line_color);
	case 388: return (lua_draw_line_colour);
	case 389: return (lua_draw_line_width_color);
	case 390: return (lua_draw_line_width_colour);
	case 391: return (lua_draw_rectangle_color);
	case 392: return (lua_draw_rectangle_colour);
	case 393: return (lua_draw_roundrect_color);
	case 394: return (lua_draw_roundrect_colour);
	case 395: return (lua_draw_roundrect_color_ext);
	case 396: return (lua_draw_roundrect_colour_ext);
	case 397: return (lua_draw_triangle_color);
	case 398: return (lua_draw_triangle_colour);
	case 399: return (lua_draw_circle_color);
	case 400: return (lua_draw_circle_colour);
	case 401: return (lua_draw_ellipse_color);
	case 402: return (lua_draw_ellipse_colour);
	case 403: return (lua_draw_get_circle_precision);
	case 404: return (lua_draw_set_circle_precision);
	case 405: return (lua_draw_primitive_begin);
	case 406: return (lua_draw_primitive_begin_texture);
	case 407: return (lua_draw_primitive_end);
	case 408: return (lua_draw_vertex);
	case 409: return (lua_draw_vertex_color);
	case 410: return (lua_draw_vertex_colour);
	case 411: return (lua_draw_vertex_texture);
	case 412: return (lua_draw_vertex_texture_color);
	case 413: return (lua_draw_vertex_texture_colour);
	case 414: return (lua_sprite_get_uvs);
	case 415: return (lua_background_get_uvs);
	case 416: return (lua_font_get_uvs);
	case 417: return (lua_sprite_get_texture);
	case 418: return (lua_background_get_texture);
	case 419: return (lua_font_get_texture);
	case 420: return (lua_texture_exists);
	case 421: return (lua_texture_set_interpolation);
	case 422: return (lua_texture_set_interpolation_ext);
	case 423: return (lua_texture_set_blending);
	case 424: return (lua_texture_set_repeat);
	case 425: return (lua_texture_set_repeat_ext);
	case 426: return (lua_texture_get_width);
	case 427: return (lua_texture_get_height);
	case 428: return (lua_texture_preload);
	case 429: return (lua_texture_set_priority);
	case 430: return (lua_texture_global_scale);
	case 431: return (lua_texture_get_uvs);
	case 432: return (lua_draw_get_font);
	case 433: return (lua_draw_set_font);
	case 434: return (lua_draw_get_halign);
	case 435: return (lua_draw_set_halign);
	case 436: return (lua_draw_get_valign);
	case 437: return (lua_draw_set_valign);
	case 438: return (lua_string_width);
	case 439: return (lua_string_height);
	case 440: return (lua_string_width_ext);
	case 441: return (lua_string_height_ext);
	case 442: return (lua_draw_text);
	case 443: return (lua_draw_text_ext);
	case 444: return (lua_draw_text_transformed);
	case 445: return (lua_draw_text_ext_transformed);
	case 446: return (lua_draw_text_color);
	case 447: return (lua_draw_text_colour);
	case 448: return (lua_draw_text_transformed_color);
	case 449: return (lua_draw_text_transformed_colour);
	case 450: return (lua_draw_text_ext_color);
	case 451: return (lua_draw_text_ext_colour);
	case 452: return (lua_draw_text_ext_transformed_color);
	case 453: return (lua_draw_text_ext_transformed_colour);
	case 454: return (lua_collision_shape);
	case 455: return (lua_draw_self);
	case 456: return (lua_draw_sprite);
	case 457: return (lua_draw_shape);
	case 458: return (lua_draw_shape_string);
	case 459: return (lua_draw_sprite_ext);
	case 460: return (lua_draw_sprite_pos);
	case 461: return (lua_draw_sprite_stretched);
	case 462: return (lua_draw_sprite_stretched_ext);
	case 463: return (lua_draw_sprite_part);
	case 464: return (lua_draw_sprite_part_ext);
	case 465: return (lua_draw_sprite_general);
	case 466: return (lua_draw_sprite_tiled);
	case 467: return (lua_draw_sprite_tiled_ext);
	case 468: return (lua_draw_background);
	case 469: return (lua_draw_background_ext);
	case 470: return (lua_draw_background_stretched);
	case 471: return (lua_draw_background_stretched_ext);
	case 472: return (lua_draw_background_part);
	case 473: return (lua_draw_background_part_ext);
	case 474: return (lua_draw_background_general);
	case 475: return (lua_draw_background_tiled);
	case 476: return (lua_draw_background_tiled_ext);
	case 477: return (lua_shader_enable_corner_id);
	case 478: return (lua_tile_get_x);
	case 479: return (lua_tile_get_y);
	case 480: return (lua_tile_get_left);
	case 481: return (lua_tile_get_top);
	case 482: return (lua_tile_get_width);
	case 483: return (lua_tile_get_height);
	case 484: return (lua_tile_get_depth);
	case 485: return (lua_tile_get_visible);
	case 486: return (lua_tile_get_xscale);
	case 487: return (lua_tile_get_yscale);
	case 488: return (lua_tile_get_blend);
	case 489: return (lua_tile_get_alpha);
	case 490: return (lua_tile_get_background);
	case 491: return (lua_tile_set_visible);
	case 492: return (lua_tile_set_background);
	case 493: return (lua_tile_set_region);
	case 494: return (lua_tile_set_position);
	case 495: return (lua_tile_set_depth);
	case 496: return (lua_tile_set_scale);
	case 497: return (lua_tile_set_blend);
	case 498: return (lua_tile_set_alpha);
	case 499: return (lua_tile_get_count);
	case 500: return (lua_tile_get_id);
	case 501: return (lua_tile_get_ids);
	case 502: return (lua_tile_get_ids_at_depth);
	case 503: return (lua_tile_add);
	case 504: return (lua_tile_exists);
	case 505: return (lua_tile_delete);
	case 506: return (lua_tile_layer_hide);
	case 507: return (lua_tile_layer_show);
	case 508: return (lua_tile_layer_delete);
	case 509: return (lua_tile_layer_shift);
	case 510: return (lua_tile_layer_find);
	case 511: return (lua_tile_layer_delete_at);
	case 512: return (lua_tile_layer_depth);
	case 513: return (lua_surface_create);
	case 514: return (lua_surface_create_ext);
	case 515: return (lua_surface_create_special);
	case 516: return (lua_surface_resize);
	case 517: return (lua_surface_free);
	case 518: return (lua_surface_exists);
	case 519: return (lua_surface_get_width);
	case 520: return (lua_surface_get_height);
	case 521: return (lua_surface_get_texture);
	case 522: return (lua_surface_get_target);
	case 523: return (lua_surface_set_target);
	case 524: return (lua_surface_get_target_ext);
	case 525: return (lua_surface_set_target_ext);
	case 526: return (lua_surface_reset_target);
	case 527: return (lua_surface_depth_disable);
	case 528: return (lua_surface_get_depth_disable);
	case 529: return (lua_draw_surface);
	case 530: return (lua_draw_surface_ext);
	case 531: return (lua_draw_surface_stretched);
	case 532: return (lua_draw_surface_stretched_ext);
	case 533: return (lua_draw_surface_part);
	case 534: return (lua_draw_surface_part_ext);
	case 535: return (lua_draw_surface_general);
	case 536: return (lua_draw_surface_tiled);
	case 537: return (lua_draw_surface_tiled_ext);
	case 538: return (lua_surface_save);
	case 539: return (lua_surface_save_part);
	case 540: return (lua_surface_getpixel);
	case 541: return (lua_surface_getpixel_ext);
	case 542: return (lua_surface_copy);
	case 543: return (lua_surface_copy_part);
	case 544: return (lua_skeleton_animation_set);
	case 545: return (lua_skeleton_animation_get);
	case 546: return (lua_skeleton_animation_mix);
	case 547: return (lua_skeleton_animation_set_ext);
	case 548: return (lua_skeleton_animation_get_ext);
	case 549: return (lua_skeleton_animation_get_duration);
	case 550: return (lua_skeleton_animation_get_frames);
	case 551: return (lua_skeleton_animation_clear);
	case 552: return (lua_skeleton_skin_set);
	case 553: return (lua_skeleton_skin_get);
	case 554: return (lua_skeleton_attachment_set);
	case 555: return (lua_skeleton_attachment_get);
	case 556: return (lua_skeleton_attachment_create);
	case 557: return (lua_skeleton_collision_draw_set);
	case 558: return (lua_skeleton_bone_data_get);
	case 559: return (lua_skeleton_bone_data_set);
	case 560: return (lua_skeleton_bone_state_get);
	case 561: return (lua_skeleton_bone_state_set);
	case 562: return (lua_draw_skeleton);
	case 563: return (lua_draw_skeleton_time);
	case 564: return (lua_draw_skeleton_instance);
	case 565: return (lua_draw_skeleton_collision);
	case 566: return (lua_skeleton_animation_list);
	case 567: return (lua_skeleton_skin_list);
	case 568: return (lua_skeleton_slot_data);
	case 569: return (lua_skeleton_animation_get_frame);
	case 570: return (lua_skeleton_animation_set_frame);
	case 571: return (lua_skeleton_get_minmax);
	case 572: return (lua_skeleton_get_num_bounds);
	case 573: return (lua_skeleton_get_bounds);
	case 574: return (lua_draw_enable_swf_aa);
	case 575: return (lua_draw_set_swf_aa_level);
	case 576: return (lua_draw_get_swf_aa_level);
	case 577: return (lua_action_path_old);
	case 578: return (lua_action_set_sprite);
	case 579: return (lua_action_draw_font);
	case 580: return (lua_action_draw_font_old);
	case 581: return (lua_action_fill_color);
	case 582: return (lua_action_fill_colour);
	case 583: return (lua_action_line_color);
	case 584: return (lua_action_line_colour);
	case 585: return (lua_action_highscore);
	case 586: return (lua_action_set_relative);
	case 587: return (lua_action_move);
	case 588: return (lua_action_set_motion);
	case 589: return (lua_action_set_hspeed);
	case 590: return (lua_action_set_vspeed);
	case 591: return (lua_action_set_gravity);
	case 592: return (lua_action_set_friction);
	case 593: return (lua_action_move_point);
	case 594: return (lua_action_move_to);
	case 595: return (lua_action_move_start);
	case 596: return (lua_action_move_random);
	case 597: return (lua_action_snap);
	case 598: return (lua_action_wrap);
	case 599: return (lua_action_reverse_xdir);
	case 600: return (lua_action_reverse_ydir);
	case 601: return (lua_action_move_contact);
	case 602: return (lua_action_bounce);
	case 603: return (lua_action_path);
	case 604: return (lua_action_path_end);
	case 605: return (lua_action_path_position);
	case 606: return (lua_action_path_speed);
	case 607: return (lua_action_linear_step);
	case 608: return (lua_action_potential_step);
	case 609: return (lua_action_kill_object);
	case 610: return (lua_action_create_object);
	case 611: return (lua_action_create_object_motion);
	case 612: return (lua_action_create_object_random);
	case 613: return (lua_action_change_object);
	case 614: return (lua_action_kill_position);
	case 615: return (lua_action_sprite_set);
	case 616: return (lua_action_sprite_transform);
	case 617: return (lua_action_sprite_color);
	case 618: return (lua_action_sprite_colour);
	case 619: return (lua_action_sound);
	case 620: return (lua_action_end_sound);
	case 621: return (lua_action_if_sound);
	case 622: return (lua_action_another_room);
	case 623: return (lua_action_current_room);
	case 624: return (lua_action_previous_room);
	case 625: return (lua_action_next_room);
	case 626: return (lua_action_if_previous_room);
	case 627: return (lua_action_if_next_room);
	case 628: return (lua_action_set_alarm);
	case 629: return (lua_action_sleep);
	case 630: return (lua_action_set_timeline);
	case 631: return (lua_action_set_timeline_position);
	case 632: return (lua_action_set_timeline_speed);
	case 633: return (lua_action_timeline_set);
	case 634: return (lua_action_timeline_start);
	case 635: return (lua_action_timeline_pause);
	case 636: return (lua_action_timeline_stop);
	case 637: return (lua_action_message);
	case 638: return (lua_action_show_info);
	case 639: return (lua_action_show_video);
	case 640: return (lua_action_end_game);
	case 641: return (lua_action_restart_game);
	case 642: return (lua_action_save_game);
	case 643: return (lua_action_load_game);
	case 644: return (lua_action_replace_sprite);
	case 645: return (lua_action_replace_sound);
	case 646: return (lua_action_replace_background);
	case 647: return (lua_action_if_empty);
	case 648: return (lua_action_if_collision);
	case 649: return (lua_action_if);
	case 650: return (lua_action_if_number);
	case 651: return (lua_action_if_object);
	case 652: return (lua_action_if_question);
	case 653: return (lua_action_if_dice);
	case 654: return (lua_action_if_mouse);
	case 655: return (lua_action_if_aligned);
	case 656: return (lua_action_execute_script);
	case 657: return (lua_action_inherited);
	case 658: return (lua_action_if_variable);
	case 659: return (lua_action_draw_variable);
	case 660: return (lua_action_set_score);
	case 661: return (lua_action_if_score);
	case 662: return (lua_action_draw_score);
	case 663: return (lua_action_highscore_show);
	case 664: return (lua_action_highscore_clear);
	case 665: return (lua_action_set_life);
	case 666: return (lua_action_if_life);
	case 667: return (lua_action_draw_life);
	case 668: return (lua_action_draw_life_images);
	case 669: return (lua_action_set_health);
	case 670: return (lua_action_if_health);
	case 671: return (lua_action_draw_health);
	case 672: return (lua_action_set_caption);
	case 673: return (lua_action_partsyst_create);
	case 674: return (lua_action_partsyst_destroy);
	case 675: return (lua_action_partsyst_clear);
	case 676: return (lua_action_parttype_create_old);
	case 677: return (lua_action_parttype_create);
	case 678: return (lua_action_parttype_color);
	case 679: return (lua_action_parttype_colour);
	case 680: return (lua_action_parttype_life);
	case 681: return (lua_action_parttype_speed);
	case 682: return (lua_action_parttype_gravity);
	case 683: return (lua_action_parttype_secondary);
	case 684: return (lua_action_partemit_create);
	case 685: return (lua_action_partemit_destroy);
	case 686: return (lua_action_partemit_burst);
	case 687: return (lua_action_partemit_stream);
	case 688: return (lua_action_cd_play);
	case 689: return (lua_action_cd_stop);
	case 690: return (lua_action_cd_pause);
	case 691: return (lua_action_cd_resume);
	case 692: return (lua_action_cd_present);
	case 693: return (lua_action_cd_playing);
	case 694: return (lua_action_set_cursor);
	case 695: return (lua_action_webpage);
	case 696: return (lua_action_draw_sprite);
	case 697: return (lua_action_draw_background);
	case 698: return (lua_action_draw_text);
	case 699: return (lua_action_draw_text_transformed);
	case 700: return (lua_action_draw_rectangle);
	case 701: return (lua_action_draw_gradient_hor);
	case 702: return (lua_action_draw_gradient_vert);
	case 703: return (lua_action_draw_ellipse);
	case 704: return (lua_action_draw_ellipse_gradient);
	case 705: return (lua_action_draw_line);
	case 706: return (lua_action_draw_arrow);
	case 707: return (lua_action_color);
	case 708: return (lua_action_colour);
	case 709: return (lua_action_font);
	case 710: return (lua_action_fullscreen);
	case 711: return (lua_action_snapshot);
	case 712: return (lua_action_effect);
	case 713: return (lua_file_bin_open);
	case 714: return (lua_file_bin_rewrite);
	case 715: return (lua_file_bin_close);
	case 716: return (lua_file_bin_position);
	case 717: return (lua_file_bin_size);
	case 718: return (lua_file_bin_seek);
	case 719: return (lua_file_bin_read_byte);
	case 720: return (lua_file_bin_write_byte);
	case 721: return (lua_file_text_open_from_string);
	case 722: return (lua_file_text_open_read);
	case 723: return (lua_file_text_open_write);
	case 724: return (lua_file_text_open_append);
	case 725: return (lua_file_text_close);
	case 726: return (lua_file_text_read_string);
	case 727: return (lua_file_text_read_real);
	case 728: return (lua_file_text_readln);
	case 729: return (lua_file_text_eof);
	case 730: return (lua_file_text_eoln);
	case 731: return (lua_file_text_write_string);
	case 732: return (lua_file_text_write_real);
	case 733: return (lua_file_text_writeln);
	case 734: return (lua_file_open_read);
	case 735: return (lua_file_open_write);
	case 736: return (lua_file_open_append);
	case 737: return (lua_file_close);
	case 738: return (lua_file_read_string);
	case 739: return (lua_file_read_real);
	case 740: return (lua_file_readln);
	case 741: return (lua_file_eof);
	case 742: return (lua_file_write_string);
	case 743: return (lua_file_write_real);
	case 744: return (lua_file_writeln);
	case 745: return (lua_file_exists);
	case 746: return (lua_file_delete);
	case 747: return (lua_file_rename);
	case 748: return (lua_file_copy);
	case 749: return (lua_directory_exists);
	case 750: return (lua_directory_create);
	case 751: return (lua_directory_destroy);
	case 752: return (lua_file_find_first);
	case 753: return (lua_file_find_next);
	case 754: return (lua_file_find_close);
	case 755: return (lua_file_attributes);
	case 756: return (lua_filename_name);
	case 757: return (lua_filename_path);
	case 758: return (lua_filename_dir);
	case 759: return (lua_filename_drive);
	case 760: return (lua_filename_ext);
	case 761: return (lua_filename_change_ext);
	case 762: return (lua_execute_program);
	case 763: return (lua_execute_shell);
	case 764: return (lua_parameter_count);
	case 765: return (lua_parameter_string);
	case 766: return (lua_environment_get_variable);
	case 767: return (lua_ini_open_from_string);
	case 768: return (lua_ini_open);
	case 769: return (lua_ini_close);
	case 770: return (lua_ini_read_string);
	case 771: return (lua_ini_read_real);
	case 772: return (lua_ini_write_string);
	case 773: return (lua_ini_write_real);
	case 774: return (lua_ini_key_exists);
	case 775: return (lua_ini_section_exists);
	case 776: return (lua_ini_key_delete);
	case 777: return (lua_ini_section_delete);
	case 778: return (lua_http_post_string);
	case 779: return (lua_http_get);
	case 780: return (lua_http_get_file);
	case 781: return (lua_http_request);
	case 782: return (lua_http_get_request_crossorigin);
	case 783: return (lua_http_set_request_crossorigin);
	case 784: return (lua_json_encode);
	case 785: return (lua_json_decode);
	case 786: return (lua_zip_unzip);
	case 787: return (lua_load_csv);
	case 788: return (lua_sprite_name);
	case 789: return (lua_sprite_exists);
	case 790: return (lua_sprite_get_name);
	case 791: return (lua_sprite_get_number);
	case 792: return (lua_sprite_get_width);
	case 793: return (lua_sprite_get_height);
	case 794: return (lua_sprite_get_transparent);
	case 795: return (lua_sprite_get_smooth);
	case 796: return (lua_sprite_get_preload);
	case 797: return (lua_sprite_get_xoffset);
	case 798: return (lua_sprite_get_yoffset);
	case 799: return (lua_sprite_get_bbox_mode);
	case 800: return (lua_sprite_get_bbox_left);
	case 801: return (lua_sprite_get_bbox_right);
	case 802: return (lua_sprite_get_bbox_top);
	case 803: return (lua_sprite_get_bbox_bottom);
	case 804: return (lua_sprite_get_precise);
	case 805: return (lua_sprite_collision_mask);
	case 806: return (lua_sprite_set_cache_size);
	case 807: return (lua_sprite_set_cache_size_ext);
	case 808: return (lua_font_set_cache_size);
	case 809: return (lua_sprite_get_tpe);
	case 810: return (lua_sprite_set_offset);
	case 811: return (lua_sprite_set_bbox_mode);
	case 812: return (lua_sprite_set_bbox);
	case 813: return (lua_sprite_set_precise);
	case 814: return (lua_sprite_set_alpha_from_sprite);
	case 815: return (lua_sprite_add);
	case 816: return (lua_sprite_create_from_screen);
	case 817: return (lua_sprite_add_from_screen);
	case 818: return (lua_sprite_create_from_surface);
	case 819: return (lua_sprite_add_from_surface);
	case 820: return (lua_sprite_replace);
	case 821: return (lua_sprite_add_sprite);
	case 822: return (lua_sprite_replace_sprite);
	case 823: return (lua_sprite_save_strip);
	case 824: return (lua_sprite_delete);
	case 825: return (lua_sprite_duplicate);
	case 826: return (lua_sprite_assign);
	case 827: return (lua_sprite_merge);
	case 828: return (lua_sprite_save);
	case 829: return (lua_sprite_prefetch);
	case 830: return (lua_sprite_prefetch_multi);
	case 831: return (lua_sprite_flush);
	case 832: return (lua_sprite_flush_multi);
	case 833: return (lua_sprite_set_speed);
	case 834: return (lua_sprite_get_speed_type);
	case 835: return (lua_sprite_get_speed);
	case 836: return (lua_background_name);
	case 837: return (lua_background_exists);
	case 838: return (lua_background_get_name);
	case 839: return (lua_background_get_width);
	case 840: return (lua_background_get_height);
	case 841: return (lua_background_get_transparent);
	case 842: return (lua_background_get_smooth);
	case 843: return (lua_background_get_preload);
	case 844: return (lua_background_set_alpha_from_background);
	case 845: return (lua_background_create_color);
	case 846: return (lua_background_create_colour);
	case 847: return (lua_background_replace);
	case 848: return (lua_background_create_from_screen);
	case 849: return (lua_background_create_from_surface);
	case 850: return (lua_background_create_gradient);
	case 851: return (lua_background_add);
	case 852: return (lua_background_add_background);
	case 853: return (lua_background_replace_background);
	case 854: return (lua_background_delete);
	case 855: return (lua_background_duplicate);
	case 856: return (lua_background_assign);
	case 857: return (lua_background_save);
	case 858: return (lua_background_prefetch);
	case 859: return (lua_background_prefetch_multi);
	case 860: return (lua_background_flush);
	case 861: return (lua_background_flush_multi);
	case 862: return (lua_texture_is_ready);
	case 863: return (lua_texture_prefetch);
	case 864: return (lua_texture_flush);
	case 865: return (lua_texturegroup_get_textures);
	case 866: return (lua_texturegroup_get_sprites);
	case 867: return (lua_texturegroup_get_fonts);
	case 868: return (lua_texturegroup_get_tilesets);
	case 869: return (lua_texture_debug_messages);
	case 870: return (lua_sound_name);
	case 871: return (lua_sound_exists);
	case 872: return (lua_sound_get_name);
	case 873: return (lua_sound_get_kind);
	case 874: return (lua_sound_get_preload);
	case 875: return (lua_sound_discard);
	case 876: return (lua_sound_restore);
	case 877: return (lua_sound_add);
	case 878: return (lua_sound_replace);
	case 879: return (lua_sound_delete);
	case 880: return (lua_audio_delete);
	case 881: return (lua_font_name);
	case 882: return (lua_font_exists);
	case 883: return (lua_font_get_name);
	case 884: return (lua_font_get_fontname);
	case 885: return (lua_font_get_size);
	case 886: return (lua_font_get_bold);
	case 887: return (lua_font_get_italic);
	case 888: return (lua_font_get_first);
	case 889: return (lua_font_get_last);
	case 890: return (lua_font_add_enable_aa);
	case 891: return (lua_font_add_get_enable_aa);
	case 892: return (lua_font_add);
	case 893: return (lua_font_add_sprite);
	case 894: return (lua_font_add_sprite_ext);
	case 895: return (lua_font_replace_sprite);
	case 896: return (lua_font_replace_sprite_ext);
	case 897: return (lua_font_delete);
	case 898: return (lua_font_set_dynamic_texture_size);
	case 899: return (lua_font_get_dynamic_texture_size);
	case 900: return (lua_script_exists);
	case 901: return (lua_script_get_name);
	case 902: return (lua_script_get_text);
	case 903: return (lua_script_execute);
	case 904: return (lua_path_name);
	case 905: return (lua_path_exists);
	case 906: return (lua_path_get_name);
	case 907: return (lua_path_get_length);
	case 908: return (lua_path_get_time);
	case 909: return (lua_path_get_kind);
	case 910: return (lua_path_get_closed);
	case 911: return (lua_path_get_precision);
	case 912: return (lua_path_get_number);
	case 913: return (lua_path_get_point_x);
	case 914: return (lua_path_get_point_y);
	case 915: return (lua_path_get_point_speed);
	case 916: return (lua_path_get_x);
	case 917: return (lua_path_get_y);
	case 918: return (lua_path_get_speed);
	case 919: return (lua_path_set_kind);
	case 920: return (lua_path_set_closed);
	case 921: return (lua_path_set_precision);
	case 922: return (lua_path_add);
	case 923: return (lua_path_duplicate);
	case 924: return (lua_path_assign);
	case 925: return (lua_path_append);
	case 926: return (lua_path_delete);
	case 927: return (lua_path_add_point);
	case 928: return (lua_path_insert_point);
	case 929: return (lua_path_change_point);
	case 930: return (lua_path_delete_point);
	case 931: return (lua_path_clear_points);
	case 932: return (lua_path_reverse);
	case 933: return (lua_path_mirror);
	case 934: return (lua_path_flip);
	case 935: return (lua_path_rotate);
	case 936: return (lua_path_rescale);
	case 937: return (lua_path_shift);
	case 938: return (lua_timeline_name);
	case 939: return (lua_timeline_exists);
	case 940: return (lua_timeline_get_name);
	case 941: return (lua_timeline_add);
	case 942: return (lua_timeline_delete);
	case 943: return (lua_timeline_moment_clear);
	case 944: return (lua_timeline_clear);
	case 945: return (lua_timeline_moment_add);
	case 946: return (lua_timeline_moment_add_script);
	case 947: return (lua_timeline_size);
	case 948: return (lua_timeline_max_moment);
	case 949: return (lua_object_name);
	case 950: return (lua_object_exists);
	case 951: return (lua_object_get_name);
	case 952: return (lua_object_get_sprite);
	case 953: return (lua_object_get_solid);
	case 954: return (lua_object_get_visible);
	case 955: return (lua_object_get_persistent);
	case 956: return (lua_object_get_mask);
	case 957: return (lua_object_get_parent);
	case 958: return (lua_object_get_physics);
	case 959: return (lua_object_is_ancestor);
	case 960: return (lua_object_set_sprite);
	case 961: return (lua_object_set_solid);
	case 962: return (lua_object_set_visible);
	case 963: return (lua_object_set_persistent);
	case 964: return (lua_object_set_mask);
	case 965: return (lua_object_set_parent);
	case 966: return (lua_object_set_collisions);
	case 967: return (lua_object_add);
	case 968: return (lua_object_delete);
	case 969: return (lua_object_event_clear);
	case 970: return (lua_object_event_add);
	case 971: return (lua_room_name);
	case 972: return (lua_room_exists);
	case 973: return (lua_room_get_name);
	case 974: return (lua_room_set_width);
	case 975: return (lua_room_set_height);
	case 976: return (lua_room_set_caption);
	case 977: return (lua_room_set_persistent);
	case 978: return (lua_room_set_code);
	case 979: return (lua_room_set_background_color);
	case 980: return (lua_room_set_background_colour);
	case 981: return (lua_room_set_background);
	case 982: return (lua_room_set_viewport);
	case 983: return (lua_room_get_viewport);
	case 984: return (lua_room_set_view_enabled);
	case 985: return (lua_room_add);
	case 986: return (lua_room_duplicate);
	case 987: return (lua_room_assign);
	case 988: return (lua_room_instance_add);
	case 989: return (lua_room_instance_clear);
	case 990: return (lua_room_tile_add);
	case 991: return (lua_room_tile_add_ext);
	case 992: return (lua_room_tile_clear);
	case 993: return (lua_room_get_camera);
	case 994: return (lua_room_set_camera);
	case 995: return (lua_asset_get_index);
	case 996: return (lua_asset_get_type);
	case 997: return (lua_splash_set_caption);
	case 998: return (lua_splash_set_fullscreen);
	case 999: return (lua_splash_set_border);
	case 1000: return (lua_splash_set_size);
	case 1001: return (lua_splash_set_adapt);
	case 1002: return (lua_splash_set_top);
	case 1003: return (lua_splash_set_color);
	case 1004: return (lua_splash_set_main);
	case 1005: return (lua_splash_set_scale);
	case 1006: return (lua_splash_set_cursor);
	case 1007: return (lua_splash_set_interrupt);
	case 1008: return (lua_splash_set_stop_key);
	case 1009: return (lua_splash_set_stop_mouse);
	case 1010: return (lua_splash_show_video);
	case 1011: return (lua_splash_show_image);
	case 1012: return (lua_splash_show_text);
	case 1013: return (lua_show_image);
	case 1014: return (lua_show_video);
	case 1015: return (lua_show_text);
	case 1016: return (lua_show_message);
	case 1017: return (lua_show_question);
	case 1018: return (lua_show_message_async);
	case 1019: return (lua_show_question_async);
	case 1020: return (lua_show_error);
	case 1021: return (lua_show_info);
	case 1022: return (lua_load_info);
	case 1023: return (lua_highscore_show);
	case 1024: return (lua_highscore_set_background);
	case 1025: return (lua_highscore_set_border);
	case 1026: return (lua_highscore_set_font);
	case 1027: return (lua_highscore_set_strings);
	case 1028: return (lua_highscore_set_colors);
	case 1029: return (lua_highscore_show_ext);
	case 1030: return (lua_highscore_clear);
	case 1031: return (lua_highscore_add);
	case 1032: return (lua_highscore_add_current);
	case 1033: return (lua_highscore_value);
	case 1034: return (lua_highscore_name);
	case 1035: return (lua_draw_highscore);
	case 1036: return (lua_show_message_ext);
	case 1037: return (lua_message_background);
	case 1038: return (lua_message_button);
	case 1039: return (lua_message_alpha);
	case 1040: return (lua_message_text_font);
	case 1041: return (lua_message_button_font);
	case 1042: return (lua_message_input_font);
	case 1043: return (lua_message_mouse_color);
	case 1044: return (lua_message_input_color);
	case 1045: return (lua_message_position);
	case 1046: return (lua_message_size);
	case 1047: return (lua_message_caption);
	case 1048: return (lua_show_menu);
	case 1049: return (lua_show_menu_pos);
	case 1050: return (lua_get_integer);
	case 1051: return (lua_get_integer_async);
	case 1052: return (lua_get_string);
	case 1053: return (lua_get_string_async);
	case 1054: return (lua_get_login_async);
	case 1055: return (lua_get_color);
	case 1056: return (lua_get_open_filename);
	case 1057: return (lua_get_save_filename);
	case 1058: return (lua_get_open_filename_ext);
	case 1059: return (lua_get_save_filename_ext);
	case 1060: return (lua_get_directory);
	case 1061: return (lua_get_directory_alt);
	case 1062: return (lua_keyboard_get_numlock);
	case 1063: return (lua_keyboard_set_numlock);
	case 1064: return (lua_keyboard_key_press);
	case 1065: return (lua_keyboard_key_release);
	case 1066: return (lua_keyboard_set_map);
	case 1067: return (lua_keyboard_get_map);
	case 1068: return (lua_keyboard_unset_map);
	case 1069: return (lua_keyboard_check);
	case 1070: return (lua_keyboard_check_pressed);
	case 1071: return (lua_keyboard_check_released);
	case 1072: return (lua_keyboard_check_direct);
	case 1073: return (lua_mouse_check_button);
	case 1074: return (lua_mouse_check_button_pressed);
	case 1075: return (lua_mouse_check_button_released);
	case 1076: return (lua_mouse_wheel_up);
	case 1077: return (lua_mouse_wheel_down);
	case 1078: return (lua_keyboard_virtual_show);
	case 1079: return (lua_keyboard_virtual_hide);
	case 1080: return (lua_keyboard_virtual_status);
	case 1081: return (lua_keyboard_virtual_height);
	case 1082: return (lua_keyboard_clear);
	case 1083: return (lua_mouse_clear);
	case 1084: return (lua_io_clear);
	case 1085: return (lua_io_handle);
	case 1086: return (lua_device_mouse_dbclick_enable);
	case 1087: return (lua_keyboard_wait);
	case 1088: return (lua_mouse_wait);
	case 1089: return (lua_browser_input_capture);
	case 1090: return (lua_gpio_set);
	case 1091: return (lua_gpio_clear);
	case 1092: return (lua_gpio_get);
	case 1093: return (lua_gpio_set_mode);
	case 1094: return (lua_F_GPIO_Set_Function);
	case 1095: return (lua_gesture_drag_time);
	case 1096: return (lua_gesture_drag_distance);
	case 1097: return (lua_gesture_flick_speed);
	case 1098: return (lua_gesture_double_tap_time);
	case 1099: return (lua_gesture_double_tap_distance);
	case 1100: return (lua_gesture_pinch_distance);
	case 1101: return (lua_gesture_pinch_angle_towards);
	case 1102: return (lua_gesture_pinch_angle_away);
	case 1103: return (lua_gesture_rotate_time);
	case 1104: return (lua_gesture_rotate_angle);
	case 1105: return (lua_gesture_tap_count);
	case 1106: return (lua_gesture_get_drag_time);
	case 1107: return (lua_gesture_get_drag_distance);
	case 1108: return (lua_gesture_get_flick_speed);
	case 1109: return (lua_gesture_get_double_tap_time);
	case 1110: return (lua_gesture_get_double_tap_distance);
	case 1111: return (lua_gesture_get_pinch_distance);
	case 1112: return (lua_gesture_get_pinch_angle_towards);
	case 1113: return (lua_gesture_get_pinch_angle_away);
	case 1114: return (lua_gesture_get_rotate_time);
	case 1115: return (lua_gesture_get_rotate_angle);
	case 1116: return (lua_gesture_get_tap_count);
	case 1117: return (lua_matrix_get);
	case 1118: return (lua_matrix_set);
	case 1119: return (lua_matrix_build_identity);
	case 1120: return (lua_matrix_build);
	case 1121: return (lua_matrix_build_lookat);
	case 1122: return (lua_matrix_build_projection_ortho);
	case 1123: return (lua_matrix_build_projection_perspective);
	case 1124: return (lua_matrix_build_projection_perspective_fov);
	case 1125: return (lua_matrix_multiply);
	case 1126: return (lua_matrix_transform_vertex);
	case 1127: return (lua_frustum_build);
	case 1128: return (lua_frustum_test_sphere);
	case 1129: return (lua_draw_texture_flush);
	case 1130: return (lua_draw_flush);
	case 1131: return (lua_matrix_stack_push);
	case 1132: return (lua_matrix_stack_pop);
	case 1133: return (lua_matrix_stack_set);
	case 1134: return (lua_matrix_stack_clear);
	case 1135: return (lua_matrix_stack_top);
	case 1136: return (lua_matrix_stack_is_empty);
	case 1137: return (lua_gpu_set_blendenable);
	case 1138: return (lua_gpu_set_ztestenable);
	case 1139: return (lua_gpu_set_zfunc);
	case 1140: return (lua_gpu_set_zwriteenable);
	case 1141: return (lua_gpu_set_fog);
	case 1142: return (lua_gpu_set_cullmode);
	case 1143: return (lua_gpu_set_blendmode);
	case 1144: return (lua_gpu_set_blendmode_ext);
	case 1145: return (lua_gpu_set_blendmode_ext_sepalpha);
	case 1146: return (lua_gpu_set_colorwriteenable);
	case 1147: return (lua_gpu_set_colourwriteenable);
	case 1148: return (lua_gpu_set_alphatestenable);
	case 1149: return (lua_gpu_set_alphatestref);
	case 1150: return (lua_gpu_set_alphatestfunc);
	case 1151: return (lua_gpu_set_texfilter);
	case 1152: return (lua_gpu_set_texfilter_ext);
	case 1153: return (lua_gpu_set_texrepeat);
	case 1154: return (lua_gpu_set_texrepeat_ext);
	case 1155: return (lua_gpu_set_tex_filter);
	case 1156: return (lua_gpu_set_tex_filter_ext);
	case 1157: return (lua_gpu_set_tex_repeat);
	case 1158: return (lua_gpu_set_tex_repeat_ext);
	case 1159: return (lua_gpu_set_tex_mip_filter);
	case 1160: return (lua_gpu_set_tex_mip_filter_ext);
	case 1161: return (lua_gpu_set_tex_mip_bias);
	case 1162: return (lua_gpu_set_tex_mip_bias_ext);
	case 1163: return (lua_gpu_set_tex_min_mip);
	case 1164: return (lua_gpu_set_tex_min_mip_ext);
	case 1165: return (lua_gpu_set_tex_max_mip);
	case 1166: return (lua_gpu_set_tex_max_mip_ext);
	case 1167: return (lua_gpu_set_tex_max_aniso);
	case 1168: return (lua_gpu_set_tex_max_aniso_ext);
	case 1169: return (lua_gpu_set_tex_mip_enable);
	case 1170: return (lua_gpu_set_tex_mip_enable_ext);
	case 1171: return (lua_gpu_get_blendenable);
	case 1172: return (lua_gpu_get_ztestenable);
	case 1173: return (lua_gpu_get_zfunc);
	case 1174: return (lua_gpu_get_zwriteenable);
	case 1175: return (lua_gpu_get_fog);
	case 1176: return (lua_gpu_get_cullmode);
	case 1177: return (lua_gpu_get_blendmode);
	case 1178: return (lua_gpu_get_blendmode_ext);
	case 1179: return (lua_gpu_get_blendmode_ext_sepalpha);
	case 1180: return (lua_gpu_get_blendmode_src);
	case 1181: return (lua_gpu_get_blendmode_dest);
	case 1182: return (lua_gpu_get_blendmode_srcalpha);
	case 1183: return (lua_gpu_get_blendmode_destalpha);
	case 1184: return (lua_gpu_get_colorwriteenable);
	case 1185: return (lua_gpu_get_colourwriteenable);
	case 1186: return (lua_gpu_get_alphatestenable);
	case 1187: return (lua_gpu_get_alphatestref);
	case 1188: return (lua_gpu_get_alphatestfunc);
	case 1189: return (lua_gpu_get_texfilter);
	case 1190: return (lua_gpu_get_texfilter_ext);
	case 1191: return (lua_gpu_get_texrepeat);
	case 1192: return (lua_gpu_get_texrepeat_ext);
	case 1193: return (lua_gpu_get_tex_filter);
	case 1194: return (lua_gpu_get_tex_filter_ext);
	case 1195: return (lua_gpu_get_tex_repeat);
	case 1196: return (lua_gpu_get_tex_repeat_ext);
	case 1197: return (lua_gpu_get_tex_mip_filter);
	case 1198: return (lua_gpu_get_tex_mip_filter_ext);
	case 1199: return (lua_gpu_get_tex_mip_bias);
	case 1200: return (lua_gpu_get_tex_mip_bias_ext);
	case 1201: return (lua_gpu_get_tex_min_mip);
	case 1202: return (lua_gpu_get_tex_min_mip_ext);
	case 1203: return (lua_gpu_get_tex_max_mip);
	case 1204: return (lua_gpu_get_tex_max_mip_ext);
	case 1205: return (lua_gpu_get_tex_max_aniso);
	case 1206: return (lua_gpu_get_tex_max_aniso_ext);
	case 1207: return (lua_gpu_get_tex_mip_enable);
	case 1208: return (lua_gpu_get_tex_mip_enable_ext);
	case 1209: return (lua_gpu_push_state);
	case 1210: return (lua_gpu_pop_state);
	case 1211: return (lua_gpu_get_state);
	case 1212: return (lua_gpu_set_state);
	case 1213: return (lua_draw_light_define_ambient);
	case 1214: return (lua_draw_light_define_direction);
	case 1215: return (lua_draw_light_define_point);
	case 1216: return (lua_draw_light_enable);
	case 1217: return (lua_draw_set_lighting);
	case 1218: return (lua_draw_light_get_ambient);
	case 1219: return (lua_draw_light_get);
	case 1220: return (lua_draw_get_lighting);
	case 1221: return (lua_part_type_create);
	case 1222: return (lua_part_type_destroy);
	case 1223: return (lua_part_type_exists);
	case 1224: return (lua_part_type_clear);
	case 1225: return (lua_part_type_shape);
	case 1226: return (lua_part_type_sprite);
	case 1227: return (lua_part_type_size);
	case 1228: return (lua_part_type_scale);
	case 1229: return (lua_part_type_life);
	case 1230: return (lua_part_type_step);
	case 1231: return (lua_part_type_death);
	case 1232: return (lua_part_type_speed);
	case 1233: return (lua_part_type_direction);
	case 1234: return (lua_part_type_orientation);
	case 1235: return (lua_part_type_gravity);
	case 1236: return (lua_part_type_color_mix);
	case 1237: return (lua_part_type_color_rgb);
	case 1238: return (lua_part_type_color_hsv);
	case 1239: return (lua_part_type_color1);
	case 1240: return (lua_part_type_color2);
	case 1241: return (lua_part_type_color3);
	case 1242: return (lua_part_type_color);
	case 1243: return (lua_part_type_colour_mix);
	case 1244: return (lua_part_type_colour_rgb);
	case 1245: return (lua_part_type_colour_hsv);
	case 1246: return (lua_part_type_colour1);
	case 1247: return (lua_part_type_colour2);
	case 1248: return (lua_part_type_colour3);
	case 1249: return (lua_part_type_colour);
	case 1250: return (lua_part_type_alpha1);
	case 1251: return (lua_part_type_alpha2);
	case 1252: return (lua_part_type_alpha3);
	case 1253: return (lua_part_type_alpha);
	case 1254: return (lua_part_type_blend);
	case 1255: return (lua_part_system_create);
	case 1256: return (lua_part_system_destroy);
	case 1257: return (lua_part_system_exists);
	case 1258: return (lua_part_system_clear);
	case 1259: return (lua_part_system_draw_order);
	case 1260: return (lua_part_system_depth);
	case 1261: return (lua_part_system_position);
	case 1262: return (lua_part_system_automatic_update);
	case 1263: return (lua_part_system_automatic_draw);
	case 1264: return (lua_part_system_update);
	case 1265: return (lua_part_system_drawit);
	case 1266: return (lua_part_system_create_layer);
	case 1267: return (lua_part_system_get_layer);
	case 1268: return (lua_part_system_layer);
	case 1269: return (lua_part_particles_create);
	case 1270: return (lua_part_particles_create_color);
	case 1271: return (lua_part_particles_create_colour);
	case 1272: return (lua_part_particles_clear);
	case 1273: return (lua_part_particles_count);
	case 1274: return (lua_part_emitter_create);
	case 1275: return (lua_part_emitter_destroy);
	case 1276: return (lua_part_emitter_destroy_all);
	case 1277: return (lua_part_emitter_exists);
	case 1278: return (lua_part_emitter_clear);
	case 1279: return (lua_part_emitter_region);
	case 1280: return (lua_part_emitter_burst);
	case 1281: return (lua_part_emitter_stream);
	case 1282: return (lua_effect_create_below);
	case 1283: return (lua_effect_create_above);
	case 1284: return (lua_effect_clear);
	case 1285: return (lua_event_inherited);
	case 1286: return (lua_event_perform);
	case 1287: return (lua_event_user);
	case 1288: return (lua_event_perform_object);
	case 1289: return (lua_external_define);
	case 1290: return (lua_external_call);
	case 1291: return (lua_external_free);
	case 1292: return (lua_external_define0);
	case 1293: return (lua_external_call0);
	case 1294: return (lua_external_define1);
	case 1295: return (lua_external_call1);
	case 1296: return (lua_external_define2);
	case 1297: return (lua_external_call2);
	case 1298: return (lua_external_define3);
	case 1299: return (lua_external_call3);
	case 1300: return (lua_external_define4);
	case 1301: return (lua_external_call4);
	case 1302: return (lua_external_define5);
	case 1303: return (lua_external_call5);
	case 1304: return (lua_external_define6);
	case 1305: return (lua_external_call6);
	case 1306: return (lua_external_define7);
	case 1307: return (lua_external_call7);
	case 1308: return (lua_external_define8);
	case 1309: return (lua_external_call8);
	case 1310: return (lua_window_handle);
	case 1311: return (lua_window_device);
	case 1312: return (lua_show_debug_message);
	case 1313: return (lua_show_debug_overlay);
	case 1314: return (lua_debug_event);
	case 1315: return (lua_debug_get_callstack);
	case 1316: return (lua_set_program_priority);
	case 1317: return (lua_set_application_title);
	case 1318: return (lua_gif_add_surface);
	case 1319: return (lua_gif_save);
	case 1320: return (lua_gif_open);
	case 1321: return (lua_alarm_set);
	case 1322: return (lua_alarm_get);
	case 1323: return (lua_variable_global_exists);
	case 1324: return (lua_variable_global_get);
	case 1325: return (lua_variable_global_set);
	case 1326: return (lua_variable_instance_exists);
	case 1327: return (lua_variable_instance_get);
	case 1328: return (lua_variable_instance_set);
	case 1329: return (lua_variable_instance_get_names);
	case 1330: return (lua_clipboard_has_text);
	case 1331: return (lua_clipboard_set_text);
	case 1332: return (lua_clipboard_get_text);
	case 1333: return (lua_date_current_datetime);
	case 1334: return (lua_date_current_date);
	case 1335: return (lua_date_current_time);
	case 1336: return (lua_date_create_datetime);
	case 1337: return (lua_date_create_date);
	case 1338: return (lua_date_create_time);
	case 1339: return (lua_date_valid_datetime);
	case 1340: return (lua_date_valid_date);
	case 1341: return (lua_date_valid_time);
	case 1342: return (lua_date_inc_year);
	case 1343: return (lua_date_inc_month);
	case 1344: return (lua_date_inc_week);
	case 1345: return (lua_date_inc_day);
	case 1346: return (lua_date_inc_hour);
	case 1347: return (lua_date_inc_minute);
	case 1348: return (lua_date_inc_second);
	case 1349: return (lua_date_get_year);
	case 1350: return (lua_date_get_month);
	case 1351: return (lua_date_get_week);
	case 1352: return (lua_date_get_day);
	case 1353: return (lua_date_get_hour);
	case 1354: return (lua_date_get_minute);
	case 1355: return (lua_date_get_second);
	case 1356: return (lua_date_get_weekday);
	case 1357: return (lua_date_get_day_of_year);
	case 1358: return (lua_date_get_hour_of_year);
	case 1359: return (lua_date_get_minute_of_year);
	case 1360: return (lua_date_get_second_of_year);
	case 1361: return (lua_date_year_span);
	case 1362: return (lua_date_month_span);
	case 1363: return (lua_date_week_span);
	case 1364: return (lua_date_day_span);
	case 1365: return (lua_date_hour_span);
	case 1366: return (lua_date_minute_span);
	case 1367: return (lua_date_second_span);
	case 1368: return (lua_date_compare_datetime);
	case 1369: return (lua_date_compare_date);
	case 1370: return (lua_date_compare_time);
	case 1371: return (lua_date_date_of);
	case 1372: return (lua_date_time_of);
	case 1373: return (lua_date_datetime_string);
	case 1374: return (lua_date_date_string);
	case 1375: return (lua_date_time_string);
	case 1376: return (lua_date_days_in_month);
	case 1377: return (lua_date_days_in_year);
	case 1378: return (lua_date_leap_year);
	case 1379: return (lua_date_is_today);
	case 1380: return (lua_date_set_timezone);
	case 1381: return (lua_date_get_timezone);
	case 1382: return (lua_game_set_speed);
	case 1383: return (lua_game_get_speed);
	case 1384: return (lua_ds_set_precision);
	case 1385: return (lua_ds_exists);
	case 1386: return (lua_ds_stack_create);
	case 1387: return (lua_ds_stack_destroy);
	case 1388: return (lua_ds_stack_clear);
	case 1389: return (lua_ds_stack_copy);
	case 1390: return (lua_ds_stack_size);
	case 1391: return (lua_ds_stack_empty);
	case 1392: return (lua_ds_stack_push);
	case 1393: return (lua_ds_stack_pop);
	case 1394: return (lua_ds_stack_top);
	case 1395: return (lua_ds_stack_write);
	case 1396: return (lua_ds_stack_read);
	case 1397: return (lua_ds_queue_create);
	case 1398: return (lua_ds_queue_destroy);
	case 1399: return (lua_ds_queue_clear);
	case 1400: return (lua_ds_queue_copy);
	case 1401: return (lua_ds_queue_size);
	case 1402: return (lua_ds_queue_empty);
	case 1403: return (lua_ds_queue_enqueue);
	case 1404: return (lua_ds_queue_dequeue);
	case 1405: return (lua_ds_queue_head);
	case 1406: return (lua_ds_queue_tail);
	case 1407: return (lua_ds_queue_write);
	case 1408: return (lua_ds_queue_read);
	case 1409: return (lua_ds_list_create);
	case 1410: return (lua_ds_list_destroy);
	case 1411: return (lua_ds_list_clear);
	case 1412: return (lua_ds_list_copy);
	case 1413: return (lua_ds_list_size);
	case 1414: return (lua_ds_list_empty);
	case 1415: return (lua_ds_list_add);
	case 1416: return (lua_ds_list_insert);
	case 1417: return (lua_ds_list_replace);
	case 1418: return (lua_ds_list_delete);
	case 1419: return (lua_ds_list_find_index);
	case 1420: return (lua_ds_list_find_value);
	case 1421: return (lua_ds_list_mark_as_list);
	case 1422: return (lua_ds_list_mark_as_map);
	case 1423: return (lua_ds_list_sort);
	case 1424: return (lua_ds_list_shuffle);
	case 1425: return (lua_ds_list_write);
	case 1426: return (lua_ds_list_read);
	case 1427: return (lua_ds_list_set);
	case 1428: return (lua_ds_list_set_post);
	case 1429: return (lua_ds_list_set_pre);
	case 1430: return (lua_ds_map_create);
	case 1431: return (lua_ds_map_destroy);
	case 1432: return (lua_ds_map_clear);
	case 1433: return (lua_ds_map_copy);
	case 1434: return (lua_ds_map_size);
	case 1435: return (lua_ds_map_empty);
	case 1436: return (lua_ds_map_add);
	case 1437: return (lua_ds_map_set);
	case 1438: return (lua_ds_map_set_pre);
	case 1439: return (lua_ds_map_set_post);
	case 1440: return (lua_ds_map_add_list);
	case 1441: return (lua_ds_map_add_map);
	case 1442: return (lua_ds_map_replace);
	case 1443: return (lua_ds_map_replace_list);
	case 1444: return (lua_ds_map_replace_map);
	case 1445: return (lua_ds_map_delete);
	case 1446: return (lua_ds_map_exists);
	case 1447: return (lua_ds_map_find_value);
	case 1448: return (lua_ds_map_find_previous);
	case 1449: return (lua_ds_map_find_next);
	case 1450: return (lua_ds_map_find_first);
	case 1451: return (lua_ds_map_find_last);
	case 1452: return (lua_ds_map_write);
	case 1453: return (lua_ds_map_read);
	case 1454: return (lua_ds_map_secure_save);
	case 1455: return (lua_ds_map_secure_load);
	case 1456: return (lua_ds_map_secure_load_buffer);
	case 1457: return (lua_ds_map_secure_save_buffer);
	case 1458: return (lua_ds_priority_create);
	case 1459: return (lua_ds_priority_destroy);
	case 1460: return (lua_ds_priority_clear);
	case 1461: return (lua_ds_priority_copy);
	case 1462: return (lua_ds_priority_size);
	case 1463: return (lua_ds_priority_empty);
	case 1464: return (lua_ds_priority_add);
	case 1465: return (lua_ds_priority_change_priority);
	case 1466: return (lua_ds_priority_find_priority);
	case 1467: return (lua_ds_priority_delete_value);
	case 1468: return (lua_ds_priority_delete_min);
	case 1469: return (lua_ds_priority_find_min);
	case 1470: return (lua_ds_priority_delete_max);
	case 1471: return (lua_ds_priority_find_max);
	case 1472: return (lua_ds_priority_write);
	case 1473: return (lua_ds_priority_read);
	case 1474: return (lua_ds_grid_create);
	case 1475: return (lua_ds_grid_destroy);
	case 1476: return (lua_ds_grid_copy);
	case 1477: return (lua_ds_grid_resize);
	case 1478: return (lua_ds_grid_width);
	case 1479: return (lua_ds_grid_height);
	case 1480: return (lua_ds_grid_clear);
	case 1481: return (lua_ds_grid_set);
	case 1482: return (lua_ds_grid_set_pre);
	case 1483: return (lua_ds_grid_set_post);
	case 1484: return (lua_ds_grid_add);
	case 1485: return (lua_ds_grid_multiply);
	case 1486: return (lua_ds_grid_set_region);
	case 1487: return (lua_ds_grid_add_region);
	case 1488: return (lua_ds_grid_multiply_region);
	case 1489: return (lua_ds_grid_set_disk);
	case 1490: return (lua_ds_grid_add_disk);
	case 1491: return (lua_ds_grid_multiply_disk);
	case 1492: return (lua_ds_grid_set_grid_region);
	case 1493: return (lua_ds_grid_add_grid_region);
	case 1494: return (lua_ds_grid_multiply_grid_region);
	case 1495: return (lua_ds_grid_get);
	case 1496: return (lua_ds_grid_get_sum);
	case 1497: return (lua_ds_grid_get_max);
	case 1498: return (lua_ds_grid_get_min);
	case 1499: return (lua_ds_grid_get_mean);
	case 1500: return (lua_ds_grid_get_disk_sum);
	case 1501: return (lua_ds_grid_get_disk_max);
	case 1502: return (lua_ds_grid_get_disk_min);
	case 1503: return (lua_ds_grid_get_disk_mean);
	case 1504: return (lua_ds_grid_value_exists);
	case 1505: return (lua_ds_grid_value_x);
	case 1506: return (lua_ds_grid_value_y);
	case 1507: return (lua_ds_grid_value_disk_exists);
	case 1508: return (lua_ds_grid_value_disk_x);
	case 1509: return (lua_ds_grid_value_disk_y);
	case 1510: return (lua_ds_grid_shuffle);
	case 1511: return (lua_ds_grid_write);
	case 1512: return (lua_ds_grid_read);
	case 1513: return (lua_ds_grid_sort);
	case 1514: return (lua_sound_play);
	case 1515: return (lua_sound_loop);
	case 1516: return (lua_sound_stop);
	case 1517: return (lua_sound_stop_all);
	case 1518: return (lua_sound_isplaying);
	case 1519: return (lua_sound_volume);
	case 1520: return (lua_sound_fade);
	case 1521: return (lua_sound_pan);
	case 1522: return (lua_sound_background_tempo);
	case 1523: return (lua_sound_global_volume);
	case 1524: return (lua_sound_set_search_directory);
	case 1525: return (lua_sound_effect_set);
	case 1526: return (lua_sound_effect_chorus);
	case 1527: return (lua_sound_effect_compressor);
	case 1528: return (lua_sound_effect_echo);
	case 1529: return (lua_sound_effect_flanger);
	case 1530: return (lua_sound_effect_gargle);
	case 1531: return (lua_sound_effect_equalizer);
	case 1532: return (lua_sound_effect_reverb);
	case 1533: return (lua_sound_3d_set_sound_position);
	case 1534: return (lua_sound_3d_set_sound_velocity);
	case 1535: return (lua_sound_3d_set_sound_distance);
	case 1536: return (lua_sound_3d_set_sound_cone);
	case 1537: return (lua_cd_init);
	case 1538: return (lua_cd_present);
	case 1539: return (lua_cd_number);
	case 1540: return (lua_cd_playing);
	case 1541: return (lua_cd_paused);
	case 1542: return (lua_cd_track);
	case 1543: return (lua_cd_length);
	case 1544: return (lua_cd_track_length);
	case 1545: return (lua_cd_position);
	case 1546: return (lua_cd_track_position);
	case 1547: return (lua_cd_play);
	case 1548: return (lua_cd_stop);
	case 1549: return (lua_cd_pause);
	case 1550: return (lua_cd_resume);
	case 1551: return (lua_cd_set_position);
	case 1552: return (lua_cd_set_track_position);
	case 1553: return (lua_cd_open_door);
	case 1554: return (lua_cd_close_door);
	case 1555: return (lua_MCI_command);
	case 1556: return (lua_audio_listener_position);
	case 1557: return (lua_audio_listener_velocity);
	case 1558: return (lua_audio_listener_orientation);
	case 1559: return (lua_audio_emitter_position);
	case 1560: return (lua_audio_emitter_velocity);
	case 1561: return (lua_audio_system);
	case 1562: return (lua_audio_emitter_create);
	case 1563: return (lua_audio_emitter_free);
	case 1564: return (lua_audio_play_sound);
	case 1565: return (lua_audio_play_sound_on);
	case 1566: return (lua_audio_play_sound_at);
	case 1567: return (lua_audio_falloff_set_model);
	case 1568: return (lua_audio_stop_sound);
	case 1569: return (lua_audio_pause_sound);
	case 1570: return (lua_audio_resume_sound);
	case 1571: return (lua_audio_pause_all);
	case 1572: return (lua_audio_resume_all);
	case 1573: return (lua_audio_is_playing);
	case 1574: return (lua_audio_is_paused);
	case 1575: return (lua_audio_exists);
	case 1576: return (lua_audio_system_is_available);
	case 1577: return (lua_audio_master_gain);
	case 1578: return (lua_audio_emitter_exists);
	case 1579: return (lua_audio_get_type);
	case 1580: return (lua_audio_emitter_gain);
	case 1581: return (lua_audio_emitter_pitch);
	case 1582: return (lua_audio_emitter_falloff);
	case 1583: return (lua_audio_channel_num);
	case 1584: return (lua_audio_play_music);
	case 1585: return (lua_audio_stop_music);
	case 1586: return (lua_audio_pause_music);
	case 1587: return (lua_audio_resume_music);
	case 1588: return (lua_audio_music_is_playing);
	case 1589: return (lua_audio_music_gain);
	case 1590: return (lua_audio_sound_gain);
	case 1591: return (lua_audio_sound_pitch);
	case 1592: return (lua_audio_stop_all);
	case 1593: return (lua_audio_sound_length);
	case 1594: return (lua_audio_emitter_get_gain);
	case 1595: return (lua_audio_emitter_get_pitch);
	case 1596: return (lua_audio_emitter_get_x);
	case 1597: return (lua_audio_emitter_get_y);
	case 1598: return (lua_audio_emitter_get_z);
	case 1599: return (lua_audio_emitter_get_vx);
	case 1600: return (lua_audio_emitter_get_vy);
	case 1601: return (lua_audio_emitter_get_vz);
	case 1602: return (lua_audio_listener_set_position);
	case 1603: return (lua_audio_listener_set_velocity);
	case 1604: return (lua_audio_listener_set_orientation);
	case 1605: return (lua_audio_listener_get_data);
	case 1606: return (lua_audio_set_master_gain);
	case 1607: return (lua_audio_get_master_gain);
	case 1608: return (lua_audio_sound_get_gain);
	case 1609: return (lua_audio_sound_get_pitch);
	case 1610: return (lua_audio_get_name);
	case 1611: return (lua_audio_sound_set_track_position);
	case 1612: return (lua_audio_sound_get_track_position);
	case 1613: return (lua_audio_group_load);
	case 1614: return (lua_audio_group_unload);
	case 1615: return (lua_audio_group_is_loaded);
	case 1616: return (lua_audio_group_load_progress);
	case 1617: return (lua_audio_group_name);
	case 1618: return (lua_audio_group_stop_all);
	case 1619: return (lua_audio_group_set_gain);
	case 1620: return (lua_audio_create_buffer_sound);
	case 1621: return (lua_audio_free_buffer_sound);
	case 1622: return (lua_audio_create_play_queue);
	case 1623: return (lua_audio_free_play_queue);
	case 1624: return (lua_audio_queue_sound);
	case 1625: return (lua_audio_start_recording);
	case 1626: return (lua_audio_stop_recording);
	case 1627: return (lua_audio_get_recorder_count);
	case 1628: return (lua_audio_get_recorder_info);
	case 1629: return (lua_audio_sound_get_listener_mask);
	case 1630: return (lua_audio_sound_set_listener_mask);
	case 1631: return (lua_audio_emitter_get_listener_mask);
	case 1632: return (lua_audio_emitter_set_listener_mask);
	case 1633: return (lua_audio_get_listener_mask);
	case 1634: return (lua_audio_set_listener_mask);
	case 1635: return (lua_audio_get_listener_info);
	case 1636: return (lua_audio_get_listener_count);
	case 1637: return (lua_audio_create_sync_group);
	case 1638: return (lua_audio_destroy_sync_group);
	case 1639: return (lua_audio_play_in_sync_group);
	case 1640: return (lua_audio_start_sync_group);
	case 1641: return (lua_audio_pause_sync_group);
	case 1642: return (lua_audio_resume_sync_group);
	case 1643: return (lua_audio_stop_sync_group);
	case 1644: return (lua_audio_sync_group_get_track_pos);
	case 1645: return (lua_audio_sync_group_debug);
	case 1646: return (lua_audio_sync_group_is_playing);
	case 1647: return (lua_audio_create_stream);
	case 1648: return (lua_audio_destroy_stream);
	case 1649: return (lua_audio_debug);
	case 1650: return (lua_physics_world_create);
	case 1651: return (lua_physics_world_gravity);
	case 1652: return (lua_physics_world_update_speed);
	case 1653: return (lua_physics_world_update_iterations);
	case 1654: return (lua_physics_world_draw_debug);
	case 1655: return (lua_physics_pause_enable);
	case 1656: return (lua_physics_fixture_create);
	case 1657: return (lua_physics_fixture_set_kinematic);
	case 1658: return (lua_physics_fixture_set_awake);
	case 1659: return (lua_physics_fixture_set_density);
	case 1660: return (lua_physics_fixture_set_restitution);
	case 1661: return (lua_physics_fixture_set_friction);
	case 1662: return (lua_physics_fixture_set_collision_group);
	case 1663: return (lua_physics_fixture_set_sensor);
	case 1664: return (lua_physics_fixture_set_linear_damping);
	case 1665: return (lua_physics_fixture_set_angular_damping);
	case 1666: return (lua_physics_fixture_set_circle_shape);
	case 1667: return (lua_physics_fixture_set_box_shape);
	case 1668: return (lua_physics_fixture_set_edge_shape);
	case 1669: return (lua_physics_fixture_set_polygon_shape);
	case 1670: return (lua_physics_fixture_set_chain_shape);
	case 1671: return (lua_physics_fixture_add_point);
	case 1672: return (lua_physics_fixture_bind);
	case 1673: return (lua_physics_fixture_bind_ext);
	case 1674: return (lua_physics_fixture_delete);
	case 1675: return (lua_physics_apply_force);
	case 1676: return (lua_physics_apply_impulse);
	case 1677: return (lua_physics_apply_angular_impulse);
	case 1678: return (lua_physics_apply_local_force);
	case 1679: return (lua_physics_apply_local_impulse);
	case 1680: return (lua_physics_apply_torque);
	case 1681: return (lua_physics_mass_properties);
	case 1682: return (lua_physics_draw_debug);
	case 1683: return (lua_physics_test_overlap);
	case 1684: return (lua_physics_remove_fixture);
	case 1685: return (lua_physics_get_friction);
	case 1686: return (lua_physics_get_density);
	case 1687: return (lua_physics_get_restitution);
	case 1688: return (lua_physics_set_friction);
	case 1689: return (lua_physics_set_density);
	case 1690: return (lua_physics_set_restitution);
	case 1691: return (lua_physics_joint_distance_create);
	case 1692: return (lua_physics_joint_rope_create);
	case 1693: return (lua_physics_joint_revolute_create);
	case 1694: return (lua_physics_joint_prismatic_create);
	case 1695: return (lua_physics_joint_pulley_create);
	case 1696: return (lua_physics_joint_wheel_create);
	case 1697: return (lua_physics_joint_gear_create);
	case 1698: return (lua_physics_joint_weld_create);
	case 1699: return (lua_physics_joint_friction_create);
	case 1700: return (lua_physics_joint_enable_motor);
	case 1701: return (lua_physics_joint_get_value);
	case 1702: return (lua_physics_joint_set_value);
	case 1703: return (lua_physics_joint_delete);
	case 1704: return (lua_physics_particle_create);
	case 1705: return (lua_physics_particle_delete);
	case 1706: return (lua_physics_particle_delete_region_circle);
	case 1707: return (lua_physics_particle_delete_region_box);
	case 1708: return (lua_physics_particle_delete_region_poly);
	case 1709: return (lua_physics_particle_set_flags);
	case 1710: return (lua_physics_particle_set_category_flags);
	case 1711: return (lua_physics_particle_draw);
	case 1712: return (lua_physics_particle_draw_ext);
	case 1713: return (lua_physics_particle_count);
	case 1714: return (lua_physics_particle_get_data);
	case 1715: return (lua_physics_particle_get_data_particle);
	case 1716: return (lua_physics_particle_group_begin);
	case 1717: return (lua_physics_particle_group_circle);
	case 1718: return (lua_physics_particle_group_box);
	case 1719: return (lua_physics_particle_group_polygon);
	case 1720: return (lua_physics_particle_group_add_point);
	case 1721: return (lua_physics_particle_group_end);
	case 1722: return (lua_physics_particle_group_join);
	case 1723: return (lua_physics_particle_group_delete);
	case 1724: return (lua_physics_particle_group_count);
	case 1725: return (lua_physics_particle_group_get_data);
	case 1726: return (lua_physics_particle_group_get_mass);
	case 1727: return (lua_physics_particle_group_get_inertia);
	case 1728: return (lua_physics_particle_group_get_centre_x);
	case 1729: return (lua_physics_particle_group_get_centre_y);
	case 1730: return (lua_physics_particle_group_get_vel_x);
	case 1731: return (lua_physics_particle_group_get_vel_y);
	case 1732: return (lua_physics_particle_group_get_ang_vel);
	case 1733: return (lua_physics_particle_group_get_x);
	case 1734: return (lua_physics_particle_group_get_y);
	case 1735: return (lua_physics_particle_group_get_angle);
	case 1736: return (lua_physics_particle_set_group_flags);
	case 1737: return (lua_physics_particle_get_group_flags);
	case 1738: return (lua_physics_particle_get_max_count);
	case 1739: return (lua_physics_particle_get_radius);
	case 1740: return (lua_physics_particle_get_density);
	case 1741: return (lua_physics_particle_get_damping);
	case 1742: return (lua_physics_particle_get_gravity_scale);
	case 1743: return (lua_physics_particle_set_max_count);
	case 1744: return (lua_physics_particle_set_radius);
	case 1745: return (lua_physics_particle_set_density);
	case 1746: return (lua_physics_particle_set_damping);
	case 1747: return (lua_physics_particle_set_gravity_scale);
	case 1748: return (lua_gamepad_is_supported);
	case 1749: return (lua_gamepad_get_device_count);
	case 1750: return (lua_gamepad_is_connected);
	case 1751: return (lua_gamepad_get_description);
	case 1752: return (lua_gamepad_get_button_threshold);
	case 1753: return (lua_gamepad_set_button_threshold);
	case 1754: return (lua_gamepad_get_axis_deadzone);
	case 1755: return (lua_gamepad_set_axis_deadzone);
	case 1756: return (lua_gamepad_button_count);
	case 1757: return (lua_gamepad_button_check);
	case 1758: return (lua_gamepad_button_check_pressed);
	case 1759: return (lua_gamepad_button_check_released);
	case 1760: return (lua_gamepad_button_value);
	case 1761: return (lua_gamepad_axis_count);
	case 1762: return (lua_gamepad_axis_value);
	case 1763: return (lua_gamepad_hat_value);
	case 1764: return (lua_gamepad_hat_count);
	case 1765: return (lua_gamepad_remove_mapping);
	case 1766: return (lua_gamepad_test_mapping);
	case 1767: return (lua_gamepad_get_mapping);
	case 1768: return (lua_gamepad_get_guid);
	case 1769: return (lua_gamepad_set_vibration);
	case 1770: return (lua_gamepad_add_hardware_mapping_from_string);
	case 1771: return (lua_gamepad_add_hardware_mapping_from_file);
	case 1772: return (lua_gamepad_get_hardware_mappings);
	case 1773: return (lua_gamepad_set_color);
	case 1774: return (lua_gamepad_set_colour);
	case 1775: return (lua_buffer_create);
	case 1776: return (lua_buffer_delete);
	case 1777: return (lua_buffer_write);
	case 1778: return (lua_buffer_read);
	case 1779: return (lua_buffer_poke);
	case 1780: return (lua_buffer_peek);
	case 1781: return (lua_buffer_seek);
	case 1782: return (lua_buffer_save);
	case 1783: return (lua_buffer_save_ext);
	case 1784: return (lua_buffer_load);
	case 1785: return (lua_buffer_load_ext);
	case 1786: return (lua_buffer_load_partial);
	case 1787: return (lua_buffer_save_async);
	case 1788: return (lua_buffer_load_async);
	case 1789: return (lua_buffer_async_group_begin);
	case 1790: return (lua_buffer_async_group_end);
	case 1791: return (lua_buffer_async_group_option);
	case 1792: return (lua_buffer_copy);
	case 1793: return (lua_buffer_exists);
	case 1794: return (lua_buffer_get_type);
	case 1795: return (lua_buffer_get_alignment);
	case 1796: return (lua_buffer_fill);
	case 1797: return (lua_buffer_get_size);
	case 1798: return (lua_buffer_tell);
	case 1799: return (lua_buffer_resize);
	case 1800: return (lua_buffer_md5);
	case 1801: return (lua_buffer_sha1);
	case 1802: return (lua_buffer_base64_encode);
	case 1803: return (lua_buffer_base64_decode);
	case 1804: return (lua_buffer_base64_decode_ext);
	case 1805: return (lua_buffer_sizeof);
	case 1806: return (lua_buffer_get_address);
	case 1807: return (lua_buffer_get_surface);
	case 1808: return (lua_buffer_set_surface);
	case 1809: return (lua_buffer_create_from_vertex_buffer);
	case 1810: return (lua_buffer_create_from_vertex_buffer_ext);
	case 1811: return (lua_buffer_copy_from_vertex_buffer);
	case 1812: return (lua_buffer_compress);
	case 1813: return (lua_buffer_decompress);
	case 1814: return (lua_vertex_create_buffer);
	case 1815: return (lua_vertex_create_buffer_ext);
	case 1816: return (lua_vertex_delete_buffer);
	case 1817: return (lua_vertex_begin);
	case 1818: return (lua_vertex_end);
	case 1819: return (lua_vertex_position);
	case 1820: return (lua_vertex_position_3d);
	case 1821: return (lua_vertex_colour);
	case 1822: return (lua_vertex_color);
	case 1823: return (lua_vertex_argb);
	case 1824: return (lua_vertex_texcoord);
	case 1825: return (lua_vertex_normal);
	case 1826: return (lua_vertex_float1);
	case 1827: return (lua_vertex_float2);
	case 1828: return (lua_vertex_float3);
	case 1829: return (lua_vertex_float4);
	case 1830: return (lua_vertex_ubyte4);
	case 1831: return (lua_vertex_submit);
	case 1832: return (lua_vertex_freeze);
	case 1833: return (lua_vertex_get_number);
	case 1834: return (lua_vertex_get_buffer_size);
	case 1835: return (lua_vertex_create_buffer_from_buffer);
	case 1836: return (lua_vertex_create_buffer_from_buffer_ext);
	case 1837: return (lua_network_create_socket);
	case 1838: return (lua_network_create_socket_ext);
	case 1839: return (lua_network_create_server);
	case 1840: return (lua_network_create_server_raw);
	case 1841: return (lua_network_connect);
	case 1842: return (lua_network_connect_raw);
	case 1843: return (lua_network_send_packet);
	case 1844: return (lua_network_send_raw);
	case 1845: return (lua_network_send_broadcast);
	case 1846: return (lua_network_send_udp);
	case 1847: return (lua_network_send_udp_raw);
	case 1848: return (lua_network_resolve);
	case 1849: return (lua_network_destroy);
	case 1850: return (lua_network_set_timeout);
	case 1851: return (lua_network_set_config);
	case 1852: return (lua_shader_set);
	case 1853: return (lua_shader_get_name);
	case 1854: return (lua_shader_reset);
	case 1855: return (lua_shader_current);
	case 1856: return (lua_shader_get_uniform);
	case 1857: return (lua_shader_get_sampler_index);
	case 1858: return (lua_shader_set_uniform_i);
	case 1859: return (lua_shader_set_uniform_i_array);
	case 1860: return (lua_shader_set_uniform_f);
	case 1861: return (lua_shader_set_uniform_f_array);
	case 1862: return (lua_shader_set_uniform_matrix);
	case 1863: return (lua_shader_set_uniform_matrix_array);
	case 1864: return (lua_shader_is_compiled);
	case 1865: return (lua_shaders_are_supported);
	case 1866: return (lua_texture_set_stage);
	case 1867: return (lua_texture_get_texel_width);
	case 1868: return (lua_texture_get_texel_height);
	case 1869: return (lua_vertex_format_begin);
	case 1870: return (lua_vertex_format_delete);
	case 1871: return (lua_vertex_format_end);
	case 1872: return (lua_vertex_format_add_position);
	case 1873: return (lua_vertex_format_add_position_3d);
	case 1874: return (lua_vertex_format_add_colour);
	case 1875: return (lua_vertex_format_add_color);
	case 1876: return (lua_vertex_format_add_normal);
	case 1877: return (lua_vertex_format_add_textcoord);
	case 1878: return (lua_vertex_format_add_texcoord);
	case 1879: return (lua_vertex_format_add_custom);
	case 1880: return (lua_steam_activate_overlay);
	case 1881: return (lua_steam_is_overlay_enabled);
	case 1882: return (lua_steam_is_overlay_activated);
	case 1883: return (lua_steam_get_persona_name);
	case 1884: return (lua_steam_initialised);
	case 1885: return (lua_steam_is_cloud_enabled_for_app);
	case 1886: return (lua_steam_is_cloud_enabled_for_account);
	case 1887: return (lua_steam_file_persisted);
	case 1888: return (lua_steam_get_quota_total);
	case 1889: return (lua_steam_get_quota_free);
	case 1890: return (lua_steam_file_write);
	case 1891: return (lua_steam_file_write_file);
	case 1892: return (lua_steam_file_read);
	case 1893: return (lua_steam_file_delete);
	case 1894: return (lua_steam_file_exists);
	case 1895: return (lua_steam_file_size);
	case 1896: return (lua_steam_file_share);
	case 1897: return (lua_steam_publish_workshop_file);
	case 1898: return (lua_steam_is_screenshot_requested);
	case 1899: return (lua_steam_send_screenshot);
	case 1900: return (lua_steam_is_user_logged_on);
	case 1901: return (lua_steam_get_user_steam_id);
	case 1902: return (lua_steam_user_owns_dlc);
	case 1903: return (lua_steam_user_installed_dlc);
	case 1904: return (lua_steam_current_game_language);
	case 1905: return (lua_steam_available_languages);
	case 1906: return (lua_steam_activate_overlay_browser);
	case 1907: return (lua_steam_activate_overlay_user);
	case 1908: return (lua_steam_activate_overlay_store);
	case 1909: return (lua_steam_get_user_persona_name);
	case 1910: return (lua_steam_set_achievement);
	case 1911: return (lua_steam_get_achievement);
	case 1912: return (lua_steam_clear_achievement);
	case 1913: return (lua_steam_set_stat_int);
	case 1914: return (lua_steam_set_stat_float);
	case 1915: return (lua_steam_set_stat_avg_rate);
	case 1916: return (lua_steam_get_stat_int);
	case 1917: return (lua_steam_get_stat_float);
	case 1918: return (lua_steam_get_stat_avg_rate);
	case 1919: return (lua_steam_reset_all_stats);
	case 1920: return (lua_steam_reset_all_stats_achievements);
	case 1921: return (lua_steam_stats_ready);
	case 1922: return (lua_steam_create_leaderboard);
	case 1923: return (lua_steam_upload_score);
	case 1924: return (lua_steam_download_scores_around_user);
	case 1925: return (lua_steam_download_scores);
	case 1926: return (lua_steam_download_friends_scores);
	case 1927: return (lua_steam_upload_score_buffer);
	case 1928: return (lua_steam_upload_score_ext);
	case 1929: return (lua_steam_upload_score_buffer_ext);
	case 1930: return (lua_steam_get_app_id);
	case 1931: return (lua_steam_get_user_account_id);
	case 1932: return (lua_steam_ugc_download);
	case 1933: return (lua_steam_ugc_create_item);
	case 1934: return (lua_steam_ugc_start_item_update);
	case 1935: return (lua_steam_ugc_set_item_title);
	case 1936: return (lua_steam_ugc_set_item_description);
	case 1937: return (lua_steam_ugc_set_item_visibility);
	case 1938: return (lua_steam_ugc_set_item_tags);
	case 1939: return (lua_steam_ugc_set_item_content);
	case 1940: return (lua_steam_ugc_set_item_preview);
	case 1941: return (lua_steam_ugc_submit_item_update);
	case 1942: return (lua_steam_ugc_get_item_update_progress);
	case 1943: return (lua_steam_ugc_subscribe_item);
	case 1944: return (lua_steam_ugc_unsubscribe_item);
	case 1945: return (lua_steam_ugc_num_subscribed_items);
	case 1946: return (lua_steam_ugc_get_subscribed_items);
	case 1947: return (lua_steam_ugc_get_item_install_info);
	case 1948: return (lua_steam_ugc_get_item_update_info);
	case 1949: return (lua_steam_ugc_request_item_details);
	case 1950: return (lua_steam_ugc_create_query_user);
	case 1951: return (lua_steam_ugc_create_query_user_ex);
	case 1952: return (lua_steam_ugc_create_query_all);
	case 1953: return (lua_steam_ugc_create_query_all_ex);
	case 1954: return (lua_steam_ugc_query_set_cloud_filename_filter);
	case 1955: return (lua_steam_ugc_query_set_match_any_tag);
	case 1956: return (lua_steam_ugc_query_set_search_text);
	case 1957: return (lua_steam_ugc_query_set_ranked_by_trend_days);
	case 1958: return (lua_steam_ugc_query_add_required_tag);
	case 1959: return (lua_steam_ugc_query_add_excluded_tag);
	case 1960: return (lua_steam_ugc_query_set_return_long_description);
	case 1961: return (lua_steam_ugc_query_set_return_total_only);
	case 1962: return (lua_steam_ugc_query_set_allow_cached_response);
	case 1963: return (lua_steam_ugc_send_query);
	case 1964: return (lua_push_local_notification);
	case 1965: return (lua_push_get_first_local_notification);
	case 1966: return (lua_push_get_next_local_notification);
	case 1967: return (lua_push_cancel_local_notification);
	case 1968: return (lua_push_get_application_badge_number);
	case 1969: return (lua_push_set_application_badge_number);
	case 1970: return (lua_iap_activate);
	case 1971: return (lua_iap_status);
	case 1972: return (lua_iap_acquire);
	case 1973: return (lua_iap_consume);
	case 1974: return (lua_iap_is_purchased);
	case 1975: return (lua_iap_enumerate_products);
	case 1976: return (lua_iap_restore_all);
	case 1977: return (lua_iap_product_details);
	case 1978: return (lua_iap_purchase_details);
	case 1979: return (lua_iap_store_status);
	case 1980: return (lua_iap_event_queue);
	case 1981: return (lua_iap_product_status);
	case 1982: return (lua_iap_is_downloaded);
	case 1983: return (lua_iap_product_files);
	case 1984: return (lua_iap_files_purchased);
	case 1985: return (lua_YoYo_AddVirtualKey);
	case 1986: return (lua_YoYo_DeleteVirtualKey);
	case 1987: return (lua_YoYo_ShowVirtualKey);
	case 1988: return (lua_YoYo_HideVirtualKey);
	case 1989: return (lua_virtual_key_add);
	case 1990: return (lua_virtual_key_delete);
	case 1991: return (lua_virtual_key_show);
	case 1992: return (lua_virtual_key_hide);
	case 1993: return (lua_YoYo_LoginAchievements);
	case 1994: return (lua_YoYo_LogoutAchievements);
	case 1995: return (lua_YoYo_PostAchievement);
	case 1996: return (lua_YoYo_PostScore);
	case 1997: return (lua_YoYo_AchievementsAvailable);
	case 1998: return (lua_achievement_available);
	case 1999: return (lua_achievement_post_score);
	case 2000: return (lua_achievement_post);
	case 2001: return (lua_achievement_increment);
	case 2002: return (lua_achievement_event);
	case 2003: return (lua_achievement_login);
	case 2004: return (lua_achievement_logout);
	case 2005: return (lua_achievement_reset);
	case 2006: return (lua_achievement_show_achievements);
	case 2007: return (lua_achievement_show);
	case 2008: return (lua_achievement_show_leaderboards);
	case 2009: return (lua_achievement_load_friends);
	case 2010: return (lua_achievement_load_leaderboard);
	case 2011: return (lua_achievement_get_pic);
	case 2012: return (lua_achievement_get_info);
	case 2013: return (lua_achievement_load_progress);
	case 2014: return (lua_achievement_send_challenge);
	case 2015: return (lua_achievement_get_challenges);
	case 2016: return (lua_achievement_show_challenge_notifications);
	case 2017: return (lua_cloud_file_save);
	case 2018: return (lua_cloud_string_save);
	case 2019: return (lua_cloud_synchronise);
	case 2020: return (lua_YoYo_OpenURL);
	case 2021: return (lua_YoYo_OpenURL_ext);
	case 2022: return (lua_YoYo_OpenURL_full);
	case 2023: return (lua_url_open);
	case 2024: return (lua_url_open_ext);
	case 2025: return (lua_url_open_full);
	case 2026: return (lua_url_get_domain);
	case 2027: return (lua_YoYo_EnableAds);
	case 2028: return (lua_YoYo_DisableAds);
	case 2029: return (lua_YoYo_LeaveRating);
	case 2030: return (lua_ads_enable);
	case 2031: return (lua_ads_disable);
	case 2032: return (lua_ads_event);
	case 2033: return (lua_ads_event_preload);
	case 2034: return (lua_ads_get_display_width);
	case 2035: return (lua_ads_get_display_height);
	case 2036: return (lua_ads_move);
	case 2037: return (lua_ads_interstitial_available);
	case 2038: return (lua_ads_interstitial_display);
	case 2039: return (lua_ads_engagement_available);
	case 2040: return (lua_ads_engagement_launch);
	case 2041: return (lua_ads_engagement_active);
	case 2042: return (lua_ads_setup);
	case 2043: return (lua_ads_set_reward_callback);
	case 2044: return (lua_clickable_add);
	case 2045: return (lua_clickable_add_ext);
	case 2046: return (lua_clickable_change);
	case 2047: return (lua_clickable_change_ext);
	case 2048: return (lua_clickable_delete);
	case 2049: return (lua_clickable_exists);
	case 2050: return (lua_clickable_set_style);
	case 2051: return (lua_shop_leave_rating);
	case 2052: return (lua_YoYo_GetTimer);
	case 2053: return (lua_YoYo_GetPlatform);
	case 2054: return (lua_YoYo_GetDevice);
	case 2055: return (lua_YoYo_GetCPUDetails);
	case 2056: return (lua_YoYo_GetConfig);
	case 2057: return (lua_YoYo_GetSessionKey);
	case 2058: return (lua_YoYo_CheckSecurity);
	case 2059: return (lua_get_timer);
	case 2060: return (lua_os_get_config);
	case 2061: return (lua_os_get_info);
	case 2062: return (lua_os_get_language);
	case 2063: return (lua_os_get_region);
	case 2064: return (lua_os_request_permission);
	case 2065: return (lua_os_check_permission);
	case 2066: return (lua_code_is_compiled);
	case 2067: return (lua_display_get_dpi_x);
	case 2068: return (lua_display_get_dpi_y);
	case 2069: return (lua_display_set_gui_size);
	case 2070: return (lua_display_get_gui_width);
	case 2071: return (lua_display_get_gui_height);
	case 2072: return (lua_display_set_gui_maximise);
	case 2073: return (lua_display_set_gui_maximize);
	case 2074: return (lua_YoYo_OF_StartDashboard);
	case 2075: return (lua_YoYo_OF_AddAchievement);
	case 2076: return (lua_YoYo_OF_AddLeaderboard);
	case 2077: return (lua_YoYo_OF_SendChallenge);
	case 2078: return (lua_YoYo_OF_SendInvite);
	case 2079: return (lua_YoYo_OF_SendSocial);
	case 2080: return (lua_YoYo_OF_SetURL);
	case 2081: return (lua_YoYo_OF_AcceptChallenge);
	case 2082: return (lua_YoYo_OF_IsOnline);
	case 2083: return (lua_YoYo_OF_SendChallengeResult);
	case 2084: return (lua_openfeint_start);
	case 2085: return (lua_achievement_map_achievement);
	case 2086: return (lua_achievement_map_leaderboard);
	case 2087: return (lua_openfeint_send_challenge);
	case 2088: return (lua_openfeint_send_invite);
	case 2089: return (lua_openfeint_send_social);
	case 2090: return (lua_openfeint_set_url);
	case 2091: return (lua_openfeint_accept_challenge);
	case 2092: return (lua_achievement_login_status);
	case 2093: return (lua_openfeint_send_result);
	case 2094: return (lua_YoYo_MouseCheckButton);
	case 2095: return (lua_YoYo_MouseCheckButtonPressed);
	case 2096: return (lua_YoYo_MouseCheckButtonReleased);
	case 2097: return (lua_YoYo_MouseX);
	case 2098: return (lua_YoYo_MouseY);
	case 2099: return (lua_YoYo_MouseXRaw);
	case 2100: return (lua_YoYo_MouseYRaw);
	case 2101: return (lua_YoYo_GetTiltX);
	case 2102: return (lua_YoYo_GetTiltY);
	case 2103: return (lua_YoYo_GetTiltZ);
	case 2104: return (lua_YoYo_IsKeypadOpen);
	case 2105: return (lua_device_mouse_check_button);
	case 2106: return (lua_device_mouse_check_button_pressed);
	case 2107: return (lua_device_mouse_check_button_released);
	case 2108: return (lua_device_mouse_x);
	case 2109: return (lua_device_mouse_y);
	case 2110: return (lua_device_mouse_raw_x);
	case 2111: return (lua_device_mouse_raw_y);
	case 2112: return (lua_device_mouse_x_to_gui);
	case 2113: return (lua_device_mouse_y_to_gui);
	case 2114: return (lua_device_get_tilt_x);
	case 2115: return (lua_device_get_tilt_y);
	case 2116: return (lua_device_get_tilt_z);
	case 2117: return (lua_device_is_keypad_open);
	case 2118: return (lua_facebook_init);
	case 2119: return (lua_facebook_login);
	case 2120: return (lua_facebook_status);
	case 2121: return (lua_facebook_graph_request);
	case 2122: return (lua_facebook_dialog);
	case 2123: return (lua_facebook_logout);
	case 2124: return (lua_facebook_user_id);
	case 2125: return (lua_facebook_accesstoken);
	case 2126: return (lua_facebook_launch_offerwall);
	case 2127: return (lua_facebook_post_message);
	case 2128: return (lua_facebook_send_invite);
	case 2129: return (lua_facebook_check_permission);
	case 2130: return (lua_facebook_request_read_permissions);
	case 2131: return (lua_facebook_request_publish_permissions);
	case 2132: return (lua_YoYo_OSPauseEvent);
	case 2133: return (lua_os_is_paused);
	case 2134: return (lua_window_has_focus);
	case 2135: return (lua_base64_encode);
	case 2136: return (lua_base64_decode);
	case 2137: return (lua_md5_string_unicode);
	case 2138: return (lua_md5_string_utf8);
	case 2139: return (lua_md5_file);
	case 2140: return (lua_sha1_string_unicode);
	case 2141: return (lua_sha1_string_utf8);
	case 2142: return (lua_sha1_file);
	case 2143: return (lua_os_is_network_connected);
	case 2144: return (lua_os_powersave_enable);
	case 2145: return (lua_os_lock_orientation);
	case 2146: return (lua_analytics_event);
	case 2147: return (lua_analytics_event_ext);
	case 2148: return (lua_winphone_license_trial_version);
	case 2149: return (lua_winphone_tile_title);
	case 2150: return (lua_winphone_tile_count);
	case 2151: return (lua_winphone_tile_back_title);
	case 2152: return (lua_winphone_tile_back_content);
	case 2153: return (lua_winphone_tile_back_content_wide);
	case 2154: return (lua_winphone_tile_front_image);
	case 2155: return (lua_winphone_tile_front_image_small);
	case 2156: return (lua_winphone_tile_front_image_wide);
	case 2157: return (lua_winphone_tile_back_image);
	case 2158: return (lua_winphone_tile_back_image_wide);
	case 2159: return (lua_winphone_tile_background_color);
	case 2160: return (lua_winphone_tile_background_colour);
	case 2161: return (lua_winphone_tile_icon_image);
	case 2162: return (lua_winphone_tile_small_icon_image);
	case 2163: return (lua_winphone_tile_wide_content);
	case 2164: return (lua_winphone_tile_cycle_images);
	case 2165: return (lua_winphone_tile_small_background_image);
	case 2166: return (lua_gml_release_mode);
	case 2167: return (lua_application_surface_draw_enable);
	case 2168: return (lua_application_get_position);
	case 2169: return (lua_application_surface_enable);
	case 2170: return (lua_application_surface_is_enabled);
	case 2171: return (lua_yyg_player_run);
	case 2172: return (lua_yyg_player_restarted);
	case 2173: return (lua_yyg_player_launch_args);
	case 2174: return (lua_extension_stubfunc_real);
	case 2175: return (lua_extension_stubfunc_string);
	case 2176: return (lua_ps4_share_screenshot_enable);
	case 2177: return (lua_ps4_share_video_enable);
	case 2178: return (lua_ps4_touchpad_mouse_enable);
	case 2179: return (lua_xboxone_package_check_license);
	case 2180: return (lua_xboxone_get_user_count);
	case 2181: return (lua_xboxone_get_user);
	case 2182: return (lua_xboxone_get_activating_user);
	case 2183: return (lua_xboxone_user_is_active);
	case 2184: return (lua_xboxone_user_is_guest);
	case 2185: return (lua_xboxone_user_is_signed_in);
	case 2186: return (lua_xboxone_user_is_remote);
	case 2187: return (lua_xboxone_gamedisplayname_for_user);
	case 2188: return (lua_xboxone_appdisplayname_for_user);
	case 2189: return (lua_xboxone_user_id_for_user);
	case 2190: return (lua_xboxone_agegroup_for_user);
	case 2191: return (lua_xboxone_gamerscore_for_user);
	case 2192: return (lua_xboxone_reputation_for_user);
	case 2193: return (lua_xboxone_user_for_pad);
	case 2194: return (lua_xboxone_pad_count_for_user);
	case 2195: return (lua_xboxone_pad_for_user);
	case 2196: return (lua_xboxone_sponsor_for_user);
	case 2197: return (lua_xboxone_show_account_picker);
	case 2198: return (lua_xboxone_sprite_add_from_gamerpicture);
	case 2199: return (lua_xboxone_show_profile_card_for_user);
	case 2200: return (lua_xboxone_generate_player_session_id);
	case 2201: return (lua_xboxone_set_savedata_user);
	case 2202: return (lua_xboxone_get_savedata_user);
	case 2203: return (lua_xboxone_get_file_error);
	case 2204: return (lua_xboxone_was_terminated);
	case 2205: return (lua_xboxone_is_suspending);
	case 2206: return (lua_xboxone_is_constrained);
	case 2207: return (lua_xboxone_suspend);
	case 2208: return (lua_xboxone_show_help);
	case 2209: return (lua_xboxone_license_trial_version);
	case 2210: return (lua_xboxone_license_trial_user);
	case 2211: return (lua_xboxone_license_trial_time_remaining);
	case 2212: return (lua_xboxone_check_privilege);
	case 2213: return (lua_xboxone_fire_event);
	case 2214: return (lua_xboxone_get_stats_for_user);
	case 2215: return (lua_xboxone_stats_setup);
	case 2216: return (lua_xboxone_stats_set_stat_real);
	case 2217: return (lua_xboxone_stats_set_stat_int);
	case 2218: return (lua_xboxone_stats_set_stat_string);
	case 2219: return (lua_xboxone_stats_delete_stat);
	case 2220: return (lua_xboxone_stats_get_stat);
	case 2221: return (lua_xboxone_stats_get_stat_names);
	case 2222: return (lua_xboxone_stats_add_user);
	case 2223: return (lua_xboxone_stats_remove_user);
	case 2224: return (lua_xboxone_stats_flush_user);
	case 2225: return (lua_xboxone_stats_get_leaderboard);
	case 2226: return (lua_xboxone_stats_get_social_leaderboard);
	case 2227: return (lua_xboxone_achievements_set_progress);
	case 2228: return (lua_xboxone_set_rich_presence);
	case 2229: return (lua_xboxone_matchmaking_create);
	case 2230: return (lua_xboxone_matchmaking_find);
	case 2231: return (lua_xboxone_matchmaking_start);
	case 2232: return (lua_xboxone_matchmaking_stop);
	case 2233: return (lua_xboxone_matchmaking_session_get_users);
	case 2234: return (lua_xboxone_matchmaking_session_leave);
	case 2235: return (lua_xboxone_matchmaking_send_invites);
	case 2236: return (lua_xboxone_matchmaking_set_joinable_session);
	case 2237: return (lua_xboxone_matchmaking_join_invite);
	case 2238: return (lua_xboxone_matchmaking_join_session);
	case 2239: return (lua_xboxone_matchmaking_set_find_timeout);
	case 2240: return (lua_xboxone_chat_add_user_to_channel);
	case 2241: return (lua_xboxone_chat_remove_user_from_channel);
	case 2242: return (lua_xboxone_chat_set_muted);
	case 2243: return (lua_xboxone_set_service_configuration_id);
	case 2244: return (lua_xboxone_read_player_leaderboard);
	case 2245: return (lua_xboxlive_get_user_count);
	case 2246: return (lua_xboxlive_get_user);
	case 2247: return (lua_xboxlive_get_activating_user);
	case 2248: return (lua_xboxlive_user_is_active);
	case 2249: return (lua_xboxlive_user_is_guest);
	case 2250: return (lua_xboxlive_user_is_signed_in);
	case 2251: return (lua_xboxlive_user_is_signing_in);
	case 2252: return (lua_xboxlive_user_is_remote);
	case 2253: return (lua_xboxlive_gamedisplayname_for_user);
	case 2254: return (lua_xboxlive_appdisplayname_for_user);
	case 2255: return (lua_xboxlive_gamertag_for_user);
	case 2256: return (lua_xboxlive_user_id_for_user);
	case 2257: return (lua_xboxlive_agegroup_for_user);
	case 2258: return (lua_xboxlive_gamerscore_for_user);
	case 2259: return (lua_xboxlive_reputation_for_user);
	case 2260: return (lua_xboxlive_user_for_pad);
	case 2261: return (lua_xboxlive_pad_count_for_user);
	case 2262: return (lua_xboxlive_pad_for_user);
	case 2263: return (lua_xboxlive_sponsor_for_user);
	case 2264: return (lua_xboxlive_show_account_picker);
	case 2265: return (lua_xboxlive_sprite_add_from_gamerpicture);
	case 2266: return (lua_xboxlive_show_profile_card_for_user);
	case 2267: return (lua_xboxlive_generate_player_session_id);
	case 2268: return (lua_xboxlive_read_player_leaderboard);
	case 2269: return (lua_xboxlive_set_savedata_user);
	case 2270: return (lua_xboxlive_get_savedata_user);
	case 2271: return (lua_xboxlive_get_file_error);
	case 2272: return (lua_uwp_was_terminated);
	case 2273: return (lua_uwp_is_suspending);
	case 2274: return (lua_uwp_is_constrained);
	case 2275: return (lua_uwp_suspend);
	case 2276: return (lua_uwp_show_help);
	case 2277: return (lua_uwp_license_trial_version);
	case 2278: return (lua_uwp_license_trial_user);
	case 2279: return (lua_uwp_license_trial_time_remaining);
	case 2280: return (lua_uwp_check_privilege);
	case 2281: return (lua_xboxlive_fire_event);
	case 2282: return (lua_xboxlive_get_stats_for_user);
	case 2283: return (lua_xboxlive_stats_setup);
	case 2284: return (lua_xboxlive_stats_set_stat_real);
	case 2285: return (lua_xboxlive_stats_set_stat_int);
	case 2286: return (lua_xboxlive_stats_set_stat_string);
	case 2287: return (lua_xboxlive_stats_delete_stat);
	case 2288: return (lua_xboxlive_stats_get_stat);
	case 2289: return (lua_xboxlive_stats_get_stat_names);
	case 2290: return (lua_xboxlive_stats_add_user);
	case 2291: return (lua_xboxlive_stats_remove_user);
	case 2292: return (lua_xboxlive_stats_flush_user);
	case 2293: return (lua_xboxlive_stats_get_leaderboard);
	case 2294: return (lua_xboxlive_stats_get_social_leaderboard);
	case 2295: return (lua_xboxlive_achievements_set_progress);
	case 2296: return (lua_xboxlive_set_rich_presence);
	case 2297: return (lua_xboxlive_matchmaking_create);
	case 2298: return (lua_xboxlive_matchmaking_find);
	case 2299: return (lua_xboxlive_matchmaking_start);
	case 2300: return (lua_xboxlive_matchmaking_stop);
	case 2301: return (lua_xboxlive_matchmaking_session_get_users);
	case 2302: return (lua_xboxlive_matchmaking_session_leave);
	case 2303: return (lua_xboxlive_matchmaking_send_invites);
	case 2304: return (lua_xboxlive_matchmaking_set_joinable_session);
	case 2305: return (lua_xboxlive_matchmaking_join_invite);
	case 2306: return (lua_xboxlive_matchmaking_join_session);
	case 2307: return (lua_xboxlive_matchmaking_set_find_timeout);
	case 2308: return (lua_xboxlive_chat_add_user_to_channel);
	case 2309: return (lua_xboxlive_chat_remove_user_from_channel);
	case 2310: return (lua_xboxlive_chat_set_muted);
	case 2311: return (lua_xboxlive_set_service_configuration_id);
	case 2312: return (lua_psn_get_leaderboard_score_range);
	case 2313: return (lua_psn_default_user_name);
	case 2314: return (lua_psn_name_for_pad);
	case 2315: return (lua_psn_unlock_trophy);
	case 2316: return (lua_psn_get_trophy_unlock_state);
	case 2317: return (lua_psn_init_np_libs);
	case 2318: return (lua_psn_exit_np_libs);
	case 2319: return (lua_psn_get_leaderboard_score);
	case 2320: return (lua_psn_post_leaderboard_score);
	case 2321: return (lua_psn_post_leaderboard_score_comment);
	case 2322: return (lua_psn_check_np_availability);
	case 2323: return (lua_psn_tick_error_dialog);
	case 2324: return (lua_psn_get_friends_scores);
	case 2325: return (lua_psn_name_for_user);
	case 2326: return (lua_psn_default_user);
	case 2327: return (lua_psn_user_for_pad);
	case 2328: return (lua_matchmaking_reset_create_params);
	case 2329: return (lua_matchmaking_add_create_param);
	case 2330: return (lua_matchmaking_session_create);
	case 2331: return (lua_matchmaking_session_get_users);
	case 2332: return (lua_matchmaking_session_get_owner);
	case 2333: return (lua_matchmaking_session_set_closed);
	case 2334: return (lua_matchmaking_session_set_open);
	case 2335: return (lua_matchmaking_session_set_hidden);
	case 2336: return (lua_matchmaking_reset_find_params);
	case 2337: return (lua_matchmaking_add_find_param);
	case 2338: return (lua_matchmaking_session_find);
	case 2339: return (lua_matchmaking_session_join);
	case 2340: return (lua_matchmaking_session_leave);
	case 2341: return (lua_matchmaking_session_update);
	case 2342: return (lua_matchmaking_start);
	case 2343: return (lua_matchmaking_stop);
	case 2344: return (lua_matchmaking_session_invite_start);
	case 2345: return (lua_matchmaking_send_invites_no_ui);
	case 2346: return (lua_matchmaking_send_invites);
	case 2347: return (lua_matchmaking_tick_invites);
	case 2348: return (lua_matchmaking_join_invite);
	case 2349: return (lua_psn_np_check_plus);
	case 2350: return (lua_psn_np_commerce_dialog_open);
	case 2351: return (lua_psn_np_commerce_dialog_tick);
	case 2352: return (lua_psn_np_notify_plus_feature);
	case 2353: return (lua_psn_set_content_restriction);
	case 2354: return (lua_psn_load_modules);
	case 2355: return (lua_psn_get_avatar_url);
	case 2356: return (lua_psn_get_tus_data);
	case 2357: return (lua_psn_set_tus_data);
	case 2358: return (lua_psn_get_tus_variable);
	case 2359: return (lua_psn_set_tus_variable);
	case 2360: return (lua_psn_delete_tus_data);
	case 2361: return (lua_psn_content_restriction_add);
	case 2362: return (lua_psn_net_check);
	case 2363: return (lua_psn_setup_trophies);
	case 2364: return (lua_psn_tick);
	case 2365: return (lua_psn_init_trophy);
	case 2366: return (lua_psn_np_status);
	case 2367: return (lua_psn_show_error_dialog);
	case 2368: return (lua_psn_check_free_space);
	case 2369: return (lua_psn_get_entitlement_list);
	case 2370: return (lua_video_open);
	case 2371: return (lua_video_close);
	case 2372: return (lua_video_draw);
	case 2373: return (lua_video_set_volume);
	case 2374: return (lua_switch_get_operation_mode);
	case 2375: return (lua_switch_get_performance_mode);
	case 2376: return (lua_switch_set_performance_config);
	case 2377: return (lua_switch_get_performance_config);
	case 2378: return (lua_switch_language_get_desired_language);
	case 2379: return (lua_switch_set_local_network_mode);
	case 2380: return (lua_switch_controller_vibration_permitted);
	case 2381: return (lua_switch_controller_show_strap_guide);
	case 2382: return (lua_switch_controller_support_show);
	case 2383: return (lua_switch_controller_support_set_defaults);
	case 2384: return (lua_switch_controller_support_set_all);
	case 2385: return (lua_switch_controller_support_set_identification_color);
	case 2386: return (lua_switch_controller_support_set_identification_colour);
	case 2387: return (lua_switch_controller_support_set_show_explain_text);
	case 2388: return (lua_switch_controller_support_set_show_identification_colors);
	case 2389: return (lua_switch_controller_support_set_show_identification_colours);
	case 2390: return (lua_switch_controller_support_set_left_justify);
	case 2391: return (lua_switch_controller_support_set_permit_joycon_dual);
	case 2392: return (lua_switch_controller_support_set_singleplayer_only);
	case 2393: return (lua_switch_controller_support_set_maintain_connections);
	case 2394: return (lua_switch_controller_support_set_player_min);
	case 2395: return (lua_switch_controller_support_set_player_max);
	case 2396: return (lua_switch_controller_support_set_explain_text);
	case 2397: return (lua_switch_controller_support_get_player_count);
	case 2398: return (lua_switch_controller_support_get_selected_id);
	case 2399: return (lua_switch_controller_joycon_set_holdtype);
	case 2400: return (lua_switch_controller_joycon_get_holdtype);
	case 2401: return (lua_switch_controller_joycon_left_connected);
	case 2402: return (lua_switch_controller_joycon_right_connected);
	case 2403: return (lua_switch_controller_set_supported_styles);
	case 2404: return (lua_switch_controller_get_supported_styles);
	case 2405: return (lua_switch_controller_set_handheld_activation_mode);
	case 2406: return (lua_switch_controller_get_handheld_activation_mode);
	case 2407: return (lua_switch_controller_vibrate_hd);
	case 2408: return (lua_switch_controller_acceleration);
	case 2409: return (lua_switch_controller_angular_velocity);
	case 2410: return (lua_switch_controller_direction);
	case 2411: return (lua_switch_controller_angle);
	case 2412: return (lua_switch_controller_is_at_rest);
	case 2413: return (lua_switch_controller_get_sixaxis_handle_count);
	case 2414: return (lua_switch_controller_set_gyro_zero_drift_mode);
	case 2415: return (lua_switch_controller_get_gyro_zero_drift_mode);
	case 2416: return (lua_switch_controller_is_sensor_fusion_enabled);
	case 2417: return (lua_switch_controller_enable_sensor_fusion);
	case 2418: return (lua_switch_controller_set_sensor_fusion_params);
	case 2419: return (lua_switch_controller_get_sensor_fusion_params);
	case 2420: return (lua_switch_controller_reset_sensor_fusion_params);
	case 2421: return (lua_switch_screenshot_disable);
	case 2422: return (lua_switch_screenshot_enable);
	case 2423: return (lua_switch_screenshot_set_orientation);
	case 2424: return (lua_switch_recording_enable);
	case 2425: return (lua_switch_recording_disable);
	case 2426: return (lua_switch_save_data_mount);
	case 2427: return (lua_switch_save_data_commit);
	case 2428: return (lua_switch_save_data_unmount);
	case 2429: return (lua_switch_theme_set);
	case 2430: return (lua_switch_add_ssl_certificate);
	case 2431: return (lua_switch_accounts_get_accounts);
	case 2432: return (lua_switch_accounts_get_nickname);
	case 2433: return (lua_switch_accounts_open_preselected_user);
	case 2434: return (lua_switch_accounts_open_user);
	case 2435: return (lua_switch_accounts_close_user);
	case 2436: return (lua_switch_accounts_login_user);
	case 2437: return (lua_switch_accounts_is_user_open);
	case 2438: return (lua_switch_accounts_is_user_online);
	case 2439: return (lua_switch_accounts_select_account);
	case 2440: return (lua_switch_accounts_get_online_token);
	case 2441: return (lua_switch_irsensor_get_mode);
	case 2442: return (lua_switch_irsensor_set_mode);
	case 2443: return (lua_switch_irsensor_common_config_set_all);
	case 2444: return (lua_switch_irsensor_common_config_set_exposure_time);
	case 2445: return (lua_switch_irsensor_common_config_set_light_target);
	case 2446: return (lua_switch_irsensor_common_config_set_gain);
	case 2447: return (lua_switch_irsensor_common_config_is_negative_image_used);
	case 2448: return (lua_switch_irsensor_cluster_config_set_defaults);
	case 2449: return (lua_switch_irsensor_cluster_config_set_window_of_interest);
	case 2450: return (lua_switch_irsensor_cluster_config_set_object_pixel_count_min);
	case 2451: return (lua_switch_irsensor_cluster_config_set_object_pixel_count_max);
	case 2452: return (lua_switch_irsensor_cluster_config_set_object_intensity_min);
	case 2453: return (lua_switch_irsensor_cluster_config_set_external_light_filtering);
	case 2454: return (lua_switch_irsensor_cluster_create_state_buffer);
	case 2455: return (lua_switch_irsensor_moment_config_set_defaults);
	case 2456: return (lua_switch_irsensor_moment_config_set_window_of_interest);
	case 2457: return (lua_switch_irsensor_moment_config_set_preprocess);
	case 2458: return (lua_switch_irsensor_moment_config_set_preprocess_intensity_threshold);
	case 2459: return (lua_switch_irsensor_moment_create_state_buffer);
	case 2460: return (lua_switch_irsensor_image_config_set_defaults);
	case 2461: return (lua_switch_irsensor_image_config_set_format);
	case 2462: return (lua_switch_irsensor_image_config_set_orig_format);
	case 2463: return (lua_switch_irsensor_image_config_set_trimming_format);
	case 2464: return (lua_switch_irsensor_image_config_set_trimming_start);
	case 2465: return (lua_switch_irsensor_image_config_set_external_light_filtering);
	case 2466: return (lua_switch_irsensor_image_create_state_buffers);
	case 2467: return (lua_switch_irsensor_hand_config_set_mode);
	case 2468: return (lua_switch_irsensor_hand_create_state_buffers);
	case 2469: return (lua_switch_bnvib_load);
	case 2470: return (lua_switch_bnvib_unload);
	case 2471: return (lua_switch_bnvib_get_value);
	case 2472: return (lua_switch_bnvib_is_looping);
	case 2473: return (lua_switch_bnvib_get_loop_end_position);
	case 2474: return (lua_switch_bnvib_get_loop_interval);
	case 2475: return (lua_switch_bnvib_get_loop_start_position);
	case 2476: return (lua_switch_bnvib_get_length);
	case 2477: return (lua_switch_bnvib_get_sampling_rate);
	case 2478: return (lua_switch_matchmaking_start);
	case 2479: return (lua_switch_matchmaking_stop);
	case 2480: return (lua_switch_matchmaking_session_create);
	case 2481: return (lua_switch_matchmaking_session_leave);
	case 2482: return (lua_switch_matchmaking_session_find);
	case 2483: return (lua_switch_matchmaking_session_join);
	case 2484: return (lua_switch_matchmaking_session_autojoin);
	case 2485: return (lua_switch_gameserver_login_user);
	case 2486: return (lua_switch_gameserver_logout_user);
	case 2487: return (lua_switch_controller_get_default_joycon_assignment);
	case 2488: return (lua_switch_controller_set_default_joycon_assignment);
	case 2489: return (lua_switch_controller_start_lr_assignment);
	case 2490: return (lua_switch_controller_stop_lr_assignment);
	case 2491: return (lua_switch_leaderboard_get_scores);
	case 2492: return (lua_switch_leaderboard_post_score);
	case 2493: return (lua_switch_leaderboard_post_common_data);
	case 2494: return (lua_switch_error_show_os_code);
	case 2495: return (lua_switch_show_store);
	case 2496: return (lua_switch_error_get_os_code_info);
	case 2497: return (lua_switch_error_begin);
	case 2498: return (lua_switch_error_end);
	case 2499: return (lua_switch_error_set_application_code);
	case 2500: return (lua_switch_error_set_dialog_message);
	case 2501: return (lua_switch_error_set_fullscreen_message);
	case 2502: return (lua_switch_error_set_language_code);
	case 2506: return (lua_ERROR);
	case 2507: return (lua_testFailed);
	case 2529: return (lua_win8_livetile_tile_notification);
	case 2530: return (lua_win8_livetile_tile_clear);
	case 2531: return (lua_win8_livetile_badge_notification);
	case 2532: return (lua_win8_livetile_badge_clear);
	case 2533: return (lua_win8_livetile_queue_enable);
	case 2534: return (lua_win8_appbar_enable);
	case 2535: return (lua_win8_appbar_add_element);
	case 2536: return (lua_win8_appbar_remove_element);
	case 2537: return (lua_win8_share_image);
	case 2538: return (lua_win8_share_screenshot);
	case 2539: return (lua_win8_share_file);
	case 2540: return (lua_win8_share_url);
	case 2541: return (lua_win8_share_text);
	case 2542: return (lua_win8_settingscharm_add_entry);
	case 2543: return (lua_win8_settingscharm_add_html_entry);
	case 2544: return (lua_win8_settingscharm_add_xaml_entry);
	case 2545: return (lua_win8_settingscharm_set_xaml_property);
	case 2546: return (lua_win8_settingscharm_get_xaml_property);
	case 2547: return (lua_win8_settingscharm_remove_entry);
	case 2548: return (lua_win8_search_enable);
	case 2549: return (lua_win8_search_disable);
	case 2550: return (lua_win8_search_add_suggestions);
	case 2551: return (lua_win8_device_touchscreen_available);
	case 2552: return (lua_win8_secondarytile_pin);
	case 2553: return (lua_win8_secondarytile_delete);
	case 2554: return (lua_win8_secondarytile_badge_notification);
	case 2555: return (lua_win8_license_initialize_sandbox);
	case 2556: return (lua_win8_license_trial_version);
	case 2557: return (lua_win8_livetile_notification_begin);
	case 2558: return (lua_win8_livetile_notification_secondary_begin);
	case 2559: return (lua_win8_livetile_notification_expiry);
	case 2560: return (lua_win8_livetile_notification_tag);
	case 2561: return (lua_win8_livetile_notification_text_add);
	case 2562: return (lua_win8_livetile_notification_image_add);
	case 2563: return (lua_win8_livetile_notification_end);
	case 2564: return (lua_uwp_livetile_tile_clear);
	case 2565: return (lua_uwp_livetile_badge_notification);
	case 2566: return (lua_uwp_livetile_badge_clear);
	case 2567: return (lua_uwp_livetile_queue_enable);
	case 2568: return (lua_uwp_secondarytile_pin);
	case 2569: return (lua_uwp_secondarytile_delete);
	case 2570: return (lua_uwp_secondarytile_badge_notification);
	case 2571: return (lua_uwp_secondarytile_tile_clear);
	case 2572: return (lua_uwp_secondarytile_badge_clear);
	case 2573: return (lua_uwp_livetile_notification_begin);
	case 2574: return (lua_uwp_livetile_notification_secondary_begin);
	case 2575: return (lua_uwp_livetile_notification_expiry);
	case 2576: return (lua_uwp_livetile_notification_tag);
	case 2577: return (lua_uwp_livetile_notification_text_add);
	case 2578: return (lua_uwp_livetile_notification_image_add);
	case 2579: return (lua_uwp_livetile_notification_end);
	case 2580: return (lua_uwp_livetile_notification_template_add);
	case 2581: return (lua_uwp_appbar_enable);
	case 2582: return (lua_uwp_appbar_add_element);
	case 2583: return (lua_uwp_appbar_remove_element);
	case 2584: return (lua_uwp_device_touchscreen_available);
	case 2585: return (lua_layer_get_id);
	case 2586: return (lua_layer_get_id_at_depth);
	case 2587: return (lua_layer_get_depth);
	case 2588: return (lua_layer_create);
	case 2589: return (lua_layer_destroy);
	case 2590: return (lua_layer_destroy_instances);
	case 2591: return (lua_layer_add_instance);
	case 2592: return (lua_layer_has_instance);
	case 2593: return (lua_layer_set_visible);
	case 2594: return (lua_layer_get_visible);
	case 2595: return (lua_layer_exists);
	case 2596: return (lua_layer_x);
	case 2597: return (lua_layer_y);
	case 2598: return (lua_layer_get_x);
	case 2599: return (lua_layer_get_y);
	case 2600: return (lua_layer_hspeed);
	case 2601: return (lua_layer_vspeed);
	case 2602: return (lua_layer_get_hspeed);
	case 2603: return (lua_layer_get_vspeed);
	case 2604: return (lua_layer_script_begin);
	case 2605: return (lua_layer_script_end);
	case 2606: return (lua_layer_shader);
	case 2607: return (lua_layer_get_script_begin);
	case 2608: return (lua_layer_get_script_end);
	case 2609: return (lua_layer_get_shader);
	case 2610: return (lua_layer_set_target_room);
	case 2611: return (lua_layer_get_target_room);
	case 2612: return (lua_layer_reset_target_room);
	case 2613: return (lua_layer_get_all);
	case 2614: return (lua_layer_get_all_elements);
	case 2615: return (lua_layer_get_name);
	case 2616: return (lua_layer_depth);
	case 2617: return (lua_layer_get_element_layer);
	case 2618: return (lua_layer_get_element_type);
	case 2619: return (lua_layer_element_move);
	case 2620: return (lua_layer_force_draw_depth);
	case 2621: return (lua_layer_is_draw_depth_forced);
	case 2622: return (lua_layer_get_forced_depth);
	case 2623: return (lua_layer_background_get_id);
	case 2624: return (lua_layer_background_exists);
	case 2625: return (lua_layer_background_create);
	case 2626: return (lua_layer_background_destroy);
	case 2627: return (lua_layer_background_visible);
	case 2628: return (lua_layer_background_htiled);
	case 2629: return (lua_layer_background_vtiled);
	case 2630: return (lua_layer_background_xscale);
	case 2631: return (lua_layer_background_yscale);
	case 2632: return (lua_layer_background_stretch);
	case 2633: return (lua_layer_background_blend);
	case 2634: return (lua_layer_background_alpha);
	case 2635: return (lua_layer_background_index);
	case 2636: return (lua_layer_background_speed);
	case 2637: return (lua_layer_background_sprite);
	case 2638: return (lua_layer_background_change);
	case 2639: return (lua_layer_background_get_visible);
	case 2640: return (lua_layer_background_get_sprite);
	case 2641: return (lua_layer_background_get_htiled);
	case 2642: return (lua_layer_background_get_vtiled);
	case 2643: return (lua_layer_background_get_xscale);
	case 2644: return (lua_layer_background_get_yscale);
	case 2645: return (lua_layer_background_get_stretch);
	case 2646: return (lua_layer_background_get_blend);
	case 2647: return (lua_layer_background_get_alpha);
	case 2648: return (lua_layer_background_get_index);
	case 2649: return (lua_layer_background_get_speed);
	case 2650: return (lua_layer_sprite_get_id);
	case 2651: return (lua_layer_sprite_exists);
	case 2652: return (lua_layer_sprite_create);
	case 2653: return (lua_layer_sprite_destroy);
	case 2654: return (lua_layer_sprite_change);
	case 2655: return (lua_layer_sprite_index);
	case 2656: return (lua_layer_sprite_speed);
	case 2657: return (lua_layer_sprite_xscale);
	case 2658: return (lua_layer_sprite_yscale);
	case 2659: return (lua_layer_sprite_angle);
	case 2660: return (lua_layer_sprite_blend);
	case 2661: return (lua_layer_sprite_alpha);
	case 2662: return (lua_layer_sprite_x);
	case 2663: return (lua_layer_sprite_y);
	case 2664: return (lua_layer_sprite_get_sprite);
	case 2665: return (lua_layer_sprite_get_index);
	case 2666: return (lua_layer_sprite_get_speed);
	case 2667: return (lua_layer_sprite_get_xscale);
	case 2668: return (lua_layer_sprite_get_yscale);
	case 2669: return (lua_layer_sprite_get_angle);
	case 2670: return (lua_layer_sprite_get_blend);
	case 2671: return (lua_layer_sprite_get_alpha);
	case 2672: return (lua_layer_sprite_get_x);
	case 2673: return (lua_layer_sprite_get_y);
	case 2674: return (lua_instance_activate_layer);
	case 2675: return (lua_instance_deactivate_layer);
	case 2676: return (lua_layer_tilemap_get_id);
	case 2677: return (lua_layer_tilemap_exists);
	case 2678: return (lua_layer_tilemap_create);
	case 2679: return (lua_layer_tilemap_destroy);
	case 2680: return (lua_tilemap_tileset);
	case 2681: return (lua_tilemap_x);
	case 2682: return (lua_tilemap_y);
	case 2683: return (lua_tilemap_set);
	case 2684: return (lua_tilemap_set_at_pixel);
	case 2685: return (lua_tilemap_get_tileset);
	case 2686: return (lua_tilemap_get_tile_width);
	case 2687: return (lua_tilemap_get_tile_height);
	case 2688: return (lua_tilemap_get_width);
	case 2689: return (lua_tilemap_get_height);
	case 2690: return (lua_tilemap_set_width);
	case 2691: return (lua_tilemap_set_height);
	case 2692: return (lua_tilemap_get_x);
	case 2693: return (lua_tilemap_get_y);
	case 2694: return (lua_tilemap_get);
	case 2695: return (lua_tilemap_get_at_pixel);
	case 2696: return (lua_tilemap_get_cell_x_at_pixel);
	case 2697: return (lua_tilemap_get_cell_y_at_pixel);
	case 2698: return (lua_tilemap_clear);
	case 2699: return (lua_draw_tilemap);
	case 2700: return (lua_draw_tile);
	case 2701: return (lua_tilemap_set_global_mask);
	case 2702: return (lua_tilemap_get_global_mask);
	case 2703: return (lua_tilemap_set_mask);
	case 2704: return (lua_tilemap_get_mask);
	case 2705: return (lua_tilemap_get_frame);
	case 2706: return (lua_tile_set_empty);
	case 2707: return (lua_tile_set_index);
	case 2708: return (lua_tile_set_flip);
	case 2709: return (lua_tile_set_mirror);
	case 2710: return (lua_tile_set_rotate);
	case 2711: return (lua_tile_get_empty);
	case 2712: return (lua_tile_get_index);
	case 2713: return (lua_tile_get_flip);
	case 2714: return (lua_tile_get_mirror);
	case 2715: return (lua_tile_get_rotate);
	case 2716: return (lua_layer_tile_exists);
	case 2717: return (lua_layer_tile_create);
	case 2718: return (lua_layer_tile_destroy);
	case 2719: return (lua_layer_tile_change);
	case 2720: return (lua_layer_tile_xscale);
	case 2721: return (lua_layer_tile_yscale);
	case 2722: return (lua_layer_tile_blend);
	case 2723: return (lua_layer_tile_alpha);
	case 2724: return (lua_layer_tile_x);
	case 2725: return (lua_layer_tile_y);
	case 2726: return (lua_layer_tile_region);
	case 2727: return (lua_layer_tile_visible);
	case 2728: return (lua_layer_tile_get_sprite);
	case 2729: return (lua_layer_tile_get_xscale);
	case 2730: return (lua_layer_tile_get_yscale);
	case 2731: return (lua_layer_tile_get_blend);
	case 2732: return (lua_layer_tile_get_alpha);
	case 2733: return (lua_layer_tile_get_x);
	case 2734: return (lua_layer_tile_get_y);
	case 2735: return (lua_layer_tile_get_region);
	case 2736: return (lua_layer_tile_get_visible);
	case 2737: return (lua_layer_instance_get_instance);
	default:   return (nullptr);
	}
}

#pragma region //rfunc

int lua_camera_create(lua_State *_pL) { return DoLuaGMLCall(_pL, 0, 0); }
int lua_camera_create_view(lua_State *_pL) { return DoLuaGMLCall(_pL, 1, 4); }
int lua_camera_destroy(lua_State *_pL) { return DoLuaGMLCall(_pL, 2, 1); }
int lua_camera_apply(lua_State *_pL) { return DoLuaGMLCall(_pL, 3, 1); }
int lua_camera_get_active(lua_State *_pL) { return DoLuaGMLCall(_pL, 4, 0); }
int lua_camera_get_default(lua_State *_pL) { return DoLuaGMLCall(_pL, 5, 0); }
int lua_camera_set_default(lua_State *_pL) { return DoLuaGMLCall(_pL, 6, 1); }
int lua_camera_set_view_mat(lua_State *_pL) { return DoLuaGMLCall(_pL, 7, 2); }
int lua_camera_set_proj_mat(lua_State *_pL) { return DoLuaGMLCall(_pL, 8, 2); }
int lua_camera_set_update_script(lua_State *_pL) { return DoLuaGMLCall(_pL, 9, 2); }
int lua_camera_set_begin_script(lua_State *_pL) { return DoLuaGMLCall(_pL, 10, 2); }
int lua_camera_set_end_script(lua_State *_pL) { return DoLuaGMLCall(_pL, 11, 2); }
int lua_camera_set_view_pos(lua_State *_pL) { return DoLuaGMLCall(_pL, 12, 3); }
int lua_camera_set_view_size(lua_State *_pL) { return DoLuaGMLCall(_pL, 13, 3); }
int lua_camera_set_view_speed(lua_State *_pL) { return DoLuaGMLCall(_pL, 14, 3); }
int lua_camera_set_view_border(lua_State *_pL) { return DoLuaGMLCall(_pL, 15, 3); }
int lua_camera_set_view_angle(lua_State *_pL) { return DoLuaGMLCall(_pL, 16, 2); }
int lua_camera_set_view_target(lua_State *_pL) { return DoLuaGMLCall(_pL, 17, 2); }
int lua_camera_get_view_mat(lua_State *_pL) { return DoLuaGMLCall(_pL, 18, 1); }
int lua_camera_get_proj_mat(lua_State *_pL) { return DoLuaGMLCall(_pL, 19, 1); }
int lua_camera_get_update_script(lua_State *_pL) { return DoLuaGMLCall(_pL, 20, 1); }
int lua_camera_get_begin_script(lua_State *_pL) { return DoLuaGMLCall(_pL, 21, 1); }
int lua_camera_get_end_script(lua_State *_pL) { return DoLuaGMLCall(_pL, 22, 1); }
int lua_camera_get_view_x(lua_State *_pL) { return DoLuaGMLCall(_pL, 23, 1); }
int lua_camera_get_view_y(lua_State *_pL) { return DoLuaGMLCall(_pL, 24, 1); }
int lua_camera_get_view_width(lua_State *_pL) { return DoLuaGMLCall(_pL, 25, 1); }
int lua_camera_get_view_height(lua_State *_pL) { return DoLuaGMLCall(_pL, 26, 1); }
int lua_camera_get_view_speed_x(lua_State *_pL) { return DoLuaGMLCall(_pL, 27, 1); }
int lua_camera_get_view_speed_y(lua_State *_pL) { return DoLuaGMLCall(_pL, 28, 1); }
int lua_camera_get_view_border_x(lua_State *_pL) { return DoLuaGMLCall(_pL, 29, 1); }
int lua_camera_get_view_border_y(lua_State *_pL) { return DoLuaGMLCall(_pL, 30, 1); }
int lua_camera_get_view_angle(lua_State *_pL) { return DoLuaGMLCall(_pL, 31, 1); }
int lua_camera_get_view_target(lua_State *_pL) { return DoLuaGMLCall(_pL, 32, 1); }
int lua_view_get_camera(lua_State *_pL) { return DoLuaGMLCall(_pL, 33, 1); }
int lua_view_get_visible(lua_State *_pL) { return DoLuaGMLCall(_pL, 34, 1); }
int lua_view_get_xport(lua_State *_pL) { return DoLuaGMLCall(_pL, 35, 1); }
int lua_view_get_yport(lua_State *_pL) { return DoLuaGMLCall(_pL, 36, 1); }
int lua_view_get_wport(lua_State *_pL) { return DoLuaGMLCall(_pL, 37, 1); }
int lua_view_get_hport(lua_State *_pL) { return DoLuaGMLCall(_pL, 38, 1); }
int lua_view_get_surface_id(lua_State *_pL) { return DoLuaGMLCall(_pL, 39, 1); }
int lua_view_set_camera(lua_State *_pL) { return DoLuaGMLCall(_pL, 40, 2); }
int lua_view_set_visible(lua_State *_pL) { return DoLuaGMLCall(_pL, 41, 2); }
int lua_view_set_xport(lua_State *_pL) { return DoLuaGMLCall(_pL, 42, 2); }
int lua_view_set_yport(lua_State *_pL) { return DoLuaGMLCall(_pL, 43, 2); }
int lua_view_set_wport(lua_State *_pL) { return DoLuaGMLCall(_pL, 44, 2); }
int lua_view_set_hport(lua_State *_pL) { return DoLuaGMLCall(_pL, 45, 2); }
int lua_view_set_surface_id(lua_State *_pL) { return DoLuaGMLCall(_pL, 46, 2); }
int lua_move_random(lua_State *_pL) { return DoLuaGMLCall(_pL, 47, 2); }
int lua_place_free(lua_State *_pL) { return DoLuaGMLCall(_pL, 48, 2); }
int lua_place_empty(lua_State *_pL) { return DoLuaGMLCall(_pL, 49, 2); }
int lua_place_meeting(lua_State *_pL) { return DoLuaGMLCall(_pL, 50, 3); }
int lua_place_snapped(lua_State *_pL) { return DoLuaGMLCall(_pL, 51, 2); }
int lua_move_snap(lua_State *_pL) { return DoLuaGMLCall(_pL, 52, 2); }
int lua_move_towards_point(lua_State *_pL) { return DoLuaGMLCall(_pL, 53, 3); }
int lua_move_contact(lua_State *_pL) { return DoLuaGMLCall(_pL, 54, 1); }
int lua_move_contact_solid(lua_State *_pL) { return DoLuaGMLCall(_pL, 55, 2); }
int lua_move_contact_all(lua_State *_pL) { return DoLuaGMLCall(_pL, 56, 2); }
int lua_move_outside_solid(lua_State *_pL) { return DoLuaGMLCall(_pL, 57, 2); }
int lua_move_outside_all(lua_State *_pL) { return DoLuaGMLCall(_pL, 58, 2); }
int lua_move_bounce(lua_State *_pL) { return DoLuaGMLCall(_pL, 59, 1); }
int lua_move_bounce_solid(lua_State *_pL) { return DoLuaGMLCall(_pL, 60, 1); }
int lua_move_bounce_all(lua_State *_pL) { return DoLuaGMLCall(_pL, 61, 1); }
int lua_move_wrap(lua_State *_pL) { return DoLuaGMLCall(_pL, 62, 3); }
int lua_motion_set(lua_State *_pL) { return DoLuaGMLCall(_pL, 63, 2); }
int lua_motion_add(lua_State *_pL) { return DoLuaGMLCall(_pL, 64, 2); }
int lua_distance_to_point(lua_State *_pL) { return DoLuaGMLCall(_pL, 65, 2); }
int lua_distance_to_object(lua_State *_pL) { return DoLuaGMLCall(_pL, 66, 1); }
int lua_path_start(lua_State *_pL) { return DoLuaGMLCall(_pL, 67, 4); }
int lua_path_end(lua_State *_pL) { return DoLuaGMLCall(_pL, 68, 0); }
int lua_mp_linear_step(lua_State *_pL) { return DoLuaGMLCall(_pL, 69, 4); }
int lua_mp_linear_path(lua_State *_pL) { return DoLuaGMLCall(_pL, 70, 5); }
int lua_mp_linear_step_object(lua_State *_pL) { return DoLuaGMLCall(_pL, 71, 4); }
int lua_mp_linear_path_object(lua_State *_pL) { return DoLuaGMLCall(_pL, 72, 5); }
int lua_mp_potential_settings(lua_State *_pL) { return DoLuaGMLCall(_pL, 73, 4); }
int lua_mp_potential_step(lua_State *_pL) { return DoLuaGMLCall(_pL, 74, 4); }
int lua_mp_potential_path(lua_State *_pL) { return DoLuaGMLCall(_pL, 75, 6); }
int lua_mp_potential_step_object(lua_State *_pL) { return DoLuaGMLCall(_pL, 76, 4); }
int lua_mp_potential_path_object(lua_State *_pL) { return DoLuaGMLCall(_pL, 77, 6); }
int lua_mp_grid_create(lua_State *_pL) { return DoLuaGMLCall(_pL, 78, 6); }
int lua_mp_grid_destroy(lua_State *_pL) { return DoLuaGMLCall(_pL, 79, 1); }
int lua_mp_grid_clear_all(lua_State *_pL) { return DoLuaGMLCall(_pL, 80, 1); }
int lua_mp_grid_clear_cell(lua_State *_pL) { return DoLuaGMLCall(_pL, 81, 3); }
int lua_mp_grid_clear_rectangle(lua_State *_pL) { return DoLuaGMLCall(_pL, 82, 5); }
int lua_mp_grid_add_cell(lua_State *_pL) { return DoLuaGMLCall(_pL, 83, 3); }
int lua_mp_grid_get_cell(lua_State *_pL) { return DoLuaGMLCall(_pL, 84, 3); }
int lua_mp_grid_add_rectangle(lua_State *_pL) { return DoLuaGMLCall(_pL, 85, 5); }
int lua_mp_grid_add_instances(lua_State *_pL) { return DoLuaGMLCall(_pL, 86, 3); }
int lua_mp_grid_path(lua_State *_pL) { return DoLuaGMLCall(_pL, 87, 7); }
int lua_mp_grid_draw(lua_State *_pL) { return DoLuaGMLCall(_pL, 88, 1); }
int lua_mp_grid_to_ds_grid(lua_State *_pL) { return DoLuaGMLCall(_pL, 89, 1); }
int lua_collision_point(lua_State *_pL) { return DoLuaGMLCall(_pL, 90, 5); }
int lua_collision_point_list(lua_State *_pL) { return DoLuaGMLCall(_pL, 91, 7); }
int lua_collision_rectangle(lua_State *_pL) { return DoLuaGMLCall(_pL, 92, 7); }
int lua_collision_rectangle_list(lua_State *_pL) { return DoLuaGMLCall(_pL, 93, 9); }
int lua_collision_circle(lua_State *_pL) { return DoLuaGMLCall(_pL, 94, 6); }
int lua_collision_circle_list(lua_State *_pL) { return DoLuaGMLCall(_pL, 95, 8); }
int lua_collision_ellipse(lua_State *_pL) { return DoLuaGMLCall(_pL, 96, 7); }
int lua_collision_ellipse_list(lua_State *_pL) { return DoLuaGMLCall(_pL, 97, 9); }
int lua_collision_line(lua_State *_pL) { return DoLuaGMLCall(_pL, 98, 7); }
int lua_collision_line_list(lua_State *_pL) { return DoLuaGMLCall(_pL, 99, 9); }
int lua_instance_find(lua_State *_pL) { return DoLuaGMLCall(_pL, 100, 2); }
int lua_instance_exists(lua_State *_pL) { return DoLuaGMLCall(_pL, 101, 1); }
int lua_instance_number(lua_State *_pL) { return DoLuaGMLCall(_pL, 102, 1); }
int lua_instance_position(lua_State *_pL) { return DoLuaGMLCall(_pL, 103, 3); }
int lua_instance_position_list(lua_State *_pL) { return DoLuaGMLCall(_pL, 104, 4); }
int lua_instance_nearest(lua_State *_pL) { return DoLuaGMLCall(_pL, 105, 3); }
int lua_instance_furthest(lua_State *_pL) { return DoLuaGMLCall(_pL, 106, 3); }
int lua_instance_place(lua_State *_pL) { return DoLuaGMLCall(_pL, 107, 3); }
int lua_instance_place_list(lua_State *_pL) { return DoLuaGMLCall(_pL, 108, 5); }
int lua_instance_create_depth(lua_State *_pL) { return DoLuaGMLCall(_pL, 109, 4); }
int lua_instance_create_layer(lua_State *_pL) { return DoLuaGMLCall(_pL, 110, 4); }
int lua_instance_copy(lua_State *_pL) { return DoLuaGMLCall(_pL, 111, 1); }
int lua_instance_change(lua_State *_pL) { return DoLuaGMLCall(_pL, 112, 2); }
int lua_instance_destroy(lua_State *_pL) { return DoLuaGMLCall(_pL, 113, -1); }
int lua_instance_sprite(lua_State *_pL) { return DoLuaGMLCall(_pL, 114, 1); }
int lua_position_empty(lua_State *_pL) { return DoLuaGMLCall(_pL, 115, 2); }
int lua_position_meeting(lua_State *_pL) { return DoLuaGMLCall(_pL, 116, 3); }
int lua_position_destroy(lua_State *_pL) { return DoLuaGMLCall(_pL, 117, 2); }
int lua_position_change(lua_State *_pL) { return DoLuaGMLCall(_pL, 118, 4); }
int lua_instance_id_get(lua_State *_pL) { return DoLuaGMLCall(_pL, 119, 1); }
int lua_instance_deactivate_all(lua_State *_pL) { return DoLuaGMLCall(_pL, 120, 1); }
int lua_instance_deactivate_object(lua_State *_pL) { return DoLuaGMLCall(_pL, 121, 1); }
int lua_instance_deactivate_region(lua_State *_pL) { return DoLuaGMLCall(_pL, 122, 6); }
int lua_instance_activate_all(lua_State *_pL) { return DoLuaGMLCall(_pL, 123, 0); }
int lua_instance_activate_object(lua_State *_pL) { return DoLuaGMLCall(_pL, 124, 1); }
int lua_instance_activate_region(lua_State *_pL) { return DoLuaGMLCall(_pL, 125, 5); }
int lua_instance_deactivate_region_special(lua_State *_pL) { return DoLuaGMLCall(_pL, 126, 5); }
int lua_room_goto(lua_State *_pL) { return DoLuaGMLCall(_pL, 127, 1); }
int lua_room_goto_previous(lua_State *_pL) { return DoLuaGMLCall(_pL, 128, 0); }
int lua_room_goto_next(lua_State *_pL) { return DoLuaGMLCall(_pL, 129, 0); }
int lua_room_previous(lua_State *_pL) { return DoLuaGMLCall(_pL, 130, 1); }
int lua_room_next(lua_State *_pL) { return DoLuaGMLCall(_pL, 131, 1); }
int lua_room_restart(lua_State *_pL) { return DoLuaGMLCall(_pL, 132, 0); }
int lua_game_end(lua_State *_pL) { return DoLuaGMLCall(_pL, 133, 0); }
int lua_game_restart(lua_State *_pL) { return DoLuaGMLCall(_pL, 134, 0); }
int lua_game_load(lua_State *_pL) { return DoLuaGMLCall(_pL, 135, 1); }
int lua_game_save(lua_State *_pL) { return DoLuaGMLCall(_pL, 136, 1); }
int lua_game_save_buffer(lua_State *_pL) { return DoLuaGMLCall(_pL, 137, 1); }
int lua_game_load_buffer(lua_State *_pL) { return DoLuaGMLCall(_pL, 138, 1); }
int lua_transition_define(lua_State *_pL) { return DoLuaGMLCall(_pL, 139, 2); }
int lua_transition_exists(lua_State *_pL) { return DoLuaGMLCall(_pL, 140, 1); }
int lua_sleep(lua_State *_pL) { return DoLuaGMLCall(_pL, 141, 1); }
int lua_point_in_rectangle(lua_State *_pL) { return DoLuaGMLCall(_pL, 142, 6); }
int lua_point_in_triangle(lua_State *_pL) { return DoLuaGMLCall(_pL, 143, 8); }
int lua_point_in_circle(lua_State *_pL) { return DoLuaGMLCall(_pL, 144, 5); }
int lua_rectangle_in_rectangle(lua_State *_pL) { return DoLuaGMLCall(_pL, 145, 8); }
int lua_rectangle_in_triangle(lua_State *_pL) { return DoLuaGMLCall(_pL, 146, 10); }
int lua_rectangle_in_circle(lua_State *_pL) { return DoLuaGMLCall(_pL, 147, 7); }
int lua_is_bool(lua_State *_pL) { return DoLuaGMLCall(_pL, 148, 1); }
int lua_is_real(lua_State *_pL) { return DoLuaGMLCall(_pL, 149, 1); }
int lua_is_string(lua_State *_pL) { return DoLuaGMLCall(_pL, 150, 1); }
int lua_is_array(lua_State *_pL) { return DoLuaGMLCall(_pL, 151, 1); }
int lua_is_undefined(lua_State *_pL) { return DoLuaGMLCall(_pL, 152, 1); }
int lua_is_int32(lua_State *_pL) { return DoLuaGMLCall(_pL, 153, 1); }
int lua_is_int64(lua_State *_pL) { return DoLuaGMLCall(_pL, 154, 1); }
int lua_is_ptr(lua_State *_pL) { return DoLuaGMLCall(_pL, 155, 1); }
int lua_is_vec3(lua_State *_pL) { return DoLuaGMLCall(_pL, 156, 1); }
int lua_is_vec4(lua_State *_pL) { return DoLuaGMLCall(_pL, 157, 1); }
int lua_is_matrix(lua_State *_pL) { return DoLuaGMLCall(_pL, 158, 1); }
int lua_typeof(lua_State *_pL) { return DoLuaGMLCall(_pL, 159, 1); }
int lua_array_length_1d(lua_State *_pL) { return DoLuaGMLCall(_pL, 160, 1); }
int lua_array_length_2d(lua_State *_pL) { return DoLuaGMLCall(_pL, 161, 2); }
int lua_array_height_2d(lua_State *_pL) { return DoLuaGMLCall(_pL, 162, 1); }
int lua_array_get(lua_State *_pL) { return DoLuaGMLCall(_pL, 163, 2); }
int lua_array_set(lua_State *_pL) { return DoLuaGMLCall(_pL, 164, 3); }
int lua_array_set_pre(lua_State *_pL) { return DoLuaGMLCall(_pL, 165, 3); }
int lua_array_set_post(lua_State *_pL) { return DoLuaGMLCall(_pL, 166, 3); }
int lua_array_get_2D(lua_State *_pL) { return DoLuaGMLCall(_pL, 167, 2); }
int lua_array_set_2D(lua_State *_pL) { return DoLuaGMLCall(_pL, 168, 3); }
int lua_array_set_2D_pre(lua_State *_pL) { return DoLuaGMLCall(_pL, 169, 3); }
int lua_array_set_2D_post(lua_State *_pL) { return DoLuaGMLCall(_pL, 170, 3); }
int lua_array_equals(lua_State *_pL) { return DoLuaGMLCall(_pL, 171, 2); }
int lua_array_create(lua_State *_pL) { return DoLuaGMLCall(_pL, 172, -1); }
int lua_array_copy(lua_State *_pL) { return DoLuaGMLCall(_pL, 173, 5); }
int lua_random(lua_State *_pL) { return DoLuaGMLCall(_pL, 174, 1); }
int lua_random_range(lua_State *_pL) { return DoLuaGMLCall(_pL, 175, 2); }
int lua_irandom(lua_State *_pL) { return DoLuaGMLCall(_pL, 176, 1); }
int lua_irandom_range(lua_State *_pL) { return DoLuaGMLCall(_pL, 177, 2); }
int lua_random_use_old_version(lua_State *_pL) { return DoLuaGMLCall(_pL, 178, 1); }
int lua_random_set_seed(lua_State *_pL) { return DoLuaGMLCall(_pL, 179, 1); }
int lua_random_get_seed(lua_State *_pL) { return DoLuaGMLCall(_pL, 180, 0); }
int lua_randomize(lua_State *_pL) { return DoLuaGMLCall(_pL, 181, 0); }
int lua_randomise(lua_State *_pL) { return DoLuaGMLCall(_pL, 182, 0); }
int lua_abs(lua_State *_pL) { return DoLuaGMLCall(_pL, 183, 1); }
int lua_round(lua_State *_pL) { return DoLuaGMLCall(_pL, 184, 1); }
int lua_floor(lua_State *_pL) { return DoLuaGMLCall(_pL, 185, 1); }
int lua_ceil(lua_State *_pL) { return DoLuaGMLCall(_pL, 186, 1); }
int lua_sign(lua_State *_pL) { return DoLuaGMLCall(_pL, 187, 1); }
int lua_frac(lua_State *_pL) { return DoLuaGMLCall(_pL, 188, 1); }
int lua_sqrt(lua_State *_pL) { return DoLuaGMLCall(_pL, 189, 1); }
int lua_sqr(lua_State *_pL) { return DoLuaGMLCall(_pL, 190, 1); }
int lua_exp(lua_State *_pL) { return DoLuaGMLCall(_pL, 191, 1); }
int lua_ln(lua_State *_pL) { return DoLuaGMLCall(_pL, 192, 1); }
int lua_log2(lua_State *_pL) { return DoLuaGMLCall(_pL, 193, 1); }
int lua_log10(lua_State *_pL) { return DoLuaGMLCall(_pL, 194, 1); }
int lua_sin(lua_State *_pL) { return DoLuaGMLCall(_pL, 195, 1); }
int lua_cos(lua_State *_pL) { return DoLuaGMLCall(_pL, 196, 1); }
int lua_tan(lua_State *_pL) { return DoLuaGMLCall(_pL, 197, 1); }
int lua_arcsin(lua_State *_pL) { return DoLuaGMLCall(_pL, 198, 1); }
int lua_arccos(lua_State *_pL) { return DoLuaGMLCall(_pL, 199, 1); }
int lua_arctan(lua_State *_pL) { return DoLuaGMLCall(_pL, 200, 1); }
int lua_arctan2(lua_State *_pL) { return DoLuaGMLCall(_pL, 201, 2); }
int lua_dsin(lua_State *_pL) { return DoLuaGMLCall(_pL, 202, 1); }
int lua_dcos(lua_State *_pL) { return DoLuaGMLCall(_pL, 203, 1); }
int lua_dtan(lua_State *_pL) { return DoLuaGMLCall(_pL, 204, 1); }
int lua_darcsin(lua_State *_pL) { return DoLuaGMLCall(_pL, 205, 1); }
int lua_darccos(lua_State *_pL) { return DoLuaGMLCall(_pL, 206, 1); }
int lua_darctan(lua_State *_pL) { return DoLuaGMLCall(_pL, 207, 1); }
int lua_darctan2(lua_State *_pL) { return DoLuaGMLCall(_pL, 208, 2); }
int lua_degtorad(lua_State *_pL) { return DoLuaGMLCall(_pL, 209, 1); }
int lua_radtodeg(lua_State *_pL) { return DoLuaGMLCall(_pL, 210, 1); }
int lua_power(lua_State *_pL) { return DoLuaGMLCall(_pL, 211, 2); }
int lua_logn(lua_State *_pL) { return DoLuaGMLCall(_pL, 212, 2); }
int lua_min(lua_State *_pL) { return DoLuaGMLCall(_pL, 213, -1); }
int lua_max(lua_State *_pL) { return DoLuaGMLCall(_pL, 214, -1); }
int lua_min3(lua_State *_pL) { return DoLuaGMLCall(_pL, 215, 3); }
int lua_max3(lua_State *_pL) { return DoLuaGMLCall(_pL, 216, 3); }
int lua_mean(lua_State *_pL) { return DoLuaGMLCall(_pL, 217, -1); }
int lua_median(lua_State *_pL) { return DoLuaGMLCall(_pL, 218, -1); }
int lua_choose(lua_State *_pL) { return DoLuaGMLCall(_pL, 219, -1); }
int lua_clamp(lua_State *_pL) { return DoLuaGMLCall(_pL, 220, 3); }
int lua_lerp(lua_State *_pL) { return DoLuaGMLCall(_pL, 221, 3); }
int lua_real(lua_State *_pL) { return DoLuaGMLCall(_pL, 222, 1); }
int lua_bool(lua_State *_pL) { return DoLuaGMLCall(_pL, 223, 1); }
int lua_string(lua_State *_pL) { return DoLuaGMLCall(_pL, 224, 1); }
int lua_int64(lua_State *_pL) { return DoLuaGMLCall(_pL, 225, 1); }
int lua_ptr(lua_State *_pL) { return DoLuaGMLCall(_pL, 226, 1); }
int lua_string_format(lua_State *_pL) { return DoLuaGMLCall(_pL, 227, 3); }
int lua_chr(lua_State *_pL) { return DoLuaGMLCall(_pL, 228, 1); }
int lua_ansi_char(lua_State *_pL) { return DoLuaGMLCall(_pL, 229, 1); }
int lua_ord(lua_State *_pL) { return DoLuaGMLCall(_pL, 230, 1); }
int lua_string_length(lua_State *_pL) { return DoLuaGMLCall(_pL, 231, 1); }
int lua_string_pos(lua_State *_pL) { return DoLuaGMLCall(_pL, 232, 2); }
int lua_string_copy(lua_State *_pL) { return DoLuaGMLCall(_pL, 233, 3); }
int lua_string_char_at(lua_State *_pL) { return DoLuaGMLCall(_pL, 234, 2); }
int lua_string_ord_at(lua_State *_pL) { return DoLuaGMLCall(_pL, 235, 2); }
int lua_string_byte_length(lua_State *_pL) { return DoLuaGMLCall(_pL, 236, 1); }
int lua_string_byte_at(lua_State *_pL) { return DoLuaGMLCall(_pL, 237, 2); }
int lua_string_set_byte_at(lua_State *_pL) { return DoLuaGMLCall(_pL, 238, 3); }
int lua_string_delete(lua_State *_pL) { return DoLuaGMLCall(_pL, 239, 3); }
int lua_string_insert(lua_State *_pL) { return DoLuaGMLCall(_pL, 240, 3); }
int lua_string_lower(lua_State *_pL) { return DoLuaGMLCall(_pL, 241, 1); }
int lua_string_upper(lua_State *_pL) { return DoLuaGMLCall(_pL, 242, 1); }
int lua_string_repeat(lua_State *_pL) { return DoLuaGMLCall(_pL, 243, 2); }
int lua_string_letters(lua_State *_pL) { return DoLuaGMLCall(_pL, 244, 1); }
int lua_string_digits(lua_State *_pL) { return DoLuaGMLCall(_pL, 245, 1); }
int lua_string_lettersdigits(lua_State *_pL) { return DoLuaGMLCall(_pL, 246, 1); }
int lua_string_replace(lua_State *_pL) { return DoLuaGMLCall(_pL, 247, 3); }
int lua_string_replace_all(lua_State *_pL) { return DoLuaGMLCall(_pL, 248, 3); }
int lua_string_count(lua_State *_pL) { return DoLuaGMLCall(_pL, 249, 2); }
int lua_string_hash_to_newline(lua_State *_pL) { return DoLuaGMLCall(_pL, 250, 1); }
int lua_point_distance(lua_State *_pL) { return DoLuaGMLCall(_pL, 251, 4); }
int lua_point_direction(lua_State *_pL) { return DoLuaGMLCall(_pL, 252, 4); }
int lua_lengthdir_x(lua_State *_pL) { return DoLuaGMLCall(_pL, 253, 2); }
int lua_lengthdir_y(lua_State *_pL) { return DoLuaGMLCall(_pL, 254, 2); }
int lua_point_distance_3d(lua_State *_pL) { return DoLuaGMLCall(_pL, 255, 6); }
int lua_dot_product(lua_State *_pL) { return DoLuaGMLCall(_pL, 256, 4); }
int lua_dot_product_normalised(lua_State *_pL) { return DoLuaGMLCall(_pL, 257, 4); }
int lua_dot_product_normalized(lua_State *_pL) { return DoLuaGMLCall(_pL, 258, 4); }
int lua_dot_product_3d(lua_State *_pL) { return DoLuaGMLCall(_pL, 259, 6); }
int lua_dot_product_3d_normalised(lua_State *_pL) { return DoLuaGMLCall(_pL, 260, 6); }
int lua_dot_product_3d_normalized(lua_State *_pL) { return DoLuaGMLCall(_pL, 261, 6); }
int lua_math_set_epsilon(lua_State *_pL) { return DoLuaGMLCall(_pL, 262, 1); }
int lua_math_get_epsilon(lua_State *_pL) { return DoLuaGMLCall(_pL, 263, 0); }
int lua_angle_difference(lua_State *_pL) { return DoLuaGMLCall(_pL, 264, 1); }
int lua_display_get_width(lua_State *_pL) { return DoLuaGMLCall(_pL, 265, 0); }
int lua_display_get_height(lua_State *_pL) { return DoLuaGMLCall(_pL, 266, 0); }
int lua_display_get_colordepth(lua_State *_pL) { return DoLuaGMLCall(_pL, 267, 0); }
int lua_display_get_frequency(lua_State *_pL) { return DoLuaGMLCall(_pL, 268, 0); }
int lua_display_get_orientation(lua_State *_pL) { return DoLuaGMLCall(_pL, 269, 0); }
int lua_display_set_size(lua_State *_pL) { return DoLuaGMLCall(_pL, 270, 2); }
int lua_display_set_colordepth(lua_State *_pL) { return DoLuaGMLCall(_pL, 271, 1); }
int lua_display_set_frequency(lua_State *_pL) { return DoLuaGMLCall(_pL, 272, 1); }
int lua_display_set_all(lua_State *_pL) { return DoLuaGMLCall(_pL, 273, 4); }
int lua_display_test_all(lua_State *_pL) { return DoLuaGMLCall(_pL, 274, 4); }
int lua_display_reset(lua_State *_pL) { return DoLuaGMLCall(_pL, 275, 1); }
int lua_display_mouse_get_x(lua_State *_pL) { return DoLuaGMLCall(_pL, 276, 0); }
int lua_display_mouse_get_y(lua_State *_pL) { return DoLuaGMLCall(_pL, 277, 0); }
int lua_display_mouse_set(lua_State *_pL) { return DoLuaGMLCall(_pL, 278, 2); }
int lua_draw_enable_drawevent(lua_State *_pL) { return DoLuaGMLCall(_pL, 279, 1); }
int lua_display_get_windows_vertex_buffer_method(lua_State *_pL) { return DoLuaGMLCall(_pL, 280, 0); }
int lua_display_get_windows_alternate_sync(lua_State *_pL) { return DoLuaGMLCall(_pL, 281, 0); }
int lua_display_set_windows_vertex_buffer_method(lua_State *_pL) { return DoLuaGMLCall(_pL, 282, 1); }
int lua_display_set_windows_alternate_sync(lua_State *_pL) { return DoLuaGMLCall(_pL, 283, 1); }
int lua_display_set_ui_visibility(lua_State *_pL) { return DoLuaGMLCall(_pL, 284, 1); }
int lua_display_set_timing_method(lua_State *_pL) { return DoLuaGMLCall(_pL, 285, 1); }
int lua_display_get_timing_method(lua_State *_pL) { return DoLuaGMLCall(_pL, 286, 0); }
int lua_display_set_sleep_margin(lua_State *_pL) { return DoLuaGMLCall(_pL, 287, 1); }
int lua_display_get_sleep_margin(lua_State *_pL) { return DoLuaGMLCall(_pL, 288, 0); }
int lua_window_set_visible(lua_State *_pL) { return DoLuaGMLCall(_pL, 289, 1); }
int lua_window_get_visible(lua_State *_pL) { return DoLuaGMLCall(_pL, 290, 0); }
int lua_window_set_fullscreen(lua_State *_pL) { return DoLuaGMLCall(_pL, 291, 1); }
int lua_window_get_fullscreen(lua_State *_pL) { return DoLuaGMLCall(_pL, 292, 0); }
int lua_window_set_showborder(lua_State *_pL) { return DoLuaGMLCall(_pL, 293, 1); }
int lua_window_get_showborder(lua_State *_pL) { return DoLuaGMLCall(_pL, 294, 0); }
int lua_window_set_showicons(lua_State *_pL) { return DoLuaGMLCall(_pL, 295, 1); }
int lua_window_get_showicons(lua_State *_pL) { return DoLuaGMLCall(_pL, 296, 0); }
int lua_window_set_stayontop(lua_State *_pL) { return DoLuaGMLCall(_pL, 297, 1); }
int lua_window_get_stayontop(lua_State *_pL) { return DoLuaGMLCall(_pL, 298, 0); }
int lua_window_set_sizeable(lua_State *_pL) { return DoLuaGMLCall(_pL, 299, 1); }
int lua_window_get_sizeable(lua_State *_pL) { return DoLuaGMLCall(_pL, 300, 0); }
int lua_window_set_caption(lua_State *_pL) { return DoLuaGMLCall(_pL, 301, 1); }
int lua_window_get_caption(lua_State *_pL) { return DoLuaGMLCall(_pL, 302, 0); }
int lua_window_set_cursor(lua_State *_pL) { return DoLuaGMLCall(_pL, 303, 1); }
int lua_window_get_cursor(lua_State *_pL) { return DoLuaGMLCall(_pL, 304, 0); }
int lua_window_set_color(lua_State *_pL) { return DoLuaGMLCall(_pL, 305, 1); }
int lua_window_set_colour(lua_State *_pL) { return DoLuaGMLCall(_pL, 306, 1); }
int lua_window_get_color(lua_State *_pL) { return DoLuaGMLCall(_pL, 307, 0); }
int lua_window_get_colour(lua_State *_pL) { return DoLuaGMLCall(_pL, 308, 0); }
int lua_window_set_min_width(lua_State *_pL) { return DoLuaGMLCall(_pL, 309, 1); }
int lua_window_set_max_width(lua_State *_pL) { return DoLuaGMLCall(_pL, 310, 1); }
int lua_window_set_min_height(lua_State *_pL) { return DoLuaGMLCall(_pL, 311, 1); }
int lua_window_set_max_height(lua_State *_pL) { return DoLuaGMLCall(_pL, 312, 1); }
int lua_window_set_position(lua_State *_pL) { return DoLuaGMLCall(_pL, 313, 2); }
int lua_window_set_size(lua_State *_pL) { return DoLuaGMLCall(_pL, 314, 2); }
int lua_window_set_rectangle(lua_State *_pL) { return DoLuaGMLCall(_pL, 315, 4); }
int lua_window_center(lua_State *_pL) { return DoLuaGMLCall(_pL, 316, 0); }
int lua_window_default(lua_State *_pL) { return DoLuaGMLCall(_pL, 317, 0); }
int lua_window_get_x(lua_State *_pL) { return DoLuaGMLCall(_pL, 318, 0); }
int lua_window_get_y(lua_State *_pL) { return DoLuaGMLCall(_pL, 319, 0); }
int lua_window_get_width(lua_State *_pL) { return DoLuaGMLCall(_pL, 320, 0); }
int lua_window_get_height(lua_State *_pL) { return DoLuaGMLCall(_pL, 321, 0); }
int lua_window_get_visible_rects(lua_State *_pL) { return DoLuaGMLCall(_pL, 322, 4); }
int lua_window_mouse_get_x(lua_State *_pL) { return DoLuaGMLCall(_pL, 323, 0); }
int lua_window_mouse_get_y(lua_State *_pL) { return DoLuaGMLCall(_pL, 324, 0); }
int lua_window_mouse_set(lua_State *_pL) { return DoLuaGMLCall(_pL, 325, 2); }
int lua_window_view_mouse_get_x(lua_State *_pL) { return DoLuaGMLCall(_pL, 326, 1); }
int lua_window_view_mouse_get_y(lua_State *_pL) { return DoLuaGMLCall(_pL, 327, 1); }
int lua_window_view_mouse_set(lua_State *_pL) { return DoLuaGMLCall(_pL, 328, 3); }
int lua_window_views_mouse_get_x(lua_State *_pL) { return DoLuaGMLCall(_pL, 329, 0); }
int lua_window_views_mouse_get_y(lua_State *_pL) { return DoLuaGMLCall(_pL, 330, 0); }
int lua_window_views_mouse_set(lua_State *_pL) { return DoLuaGMLCall(_pL, 331, 2); }
int lua_screen_save(lua_State *_pL) { return DoLuaGMLCall(_pL, 332, 1); }
int lua_screen_save_part(lua_State *_pL) { return DoLuaGMLCall(_pL, 333, 5); }
int lua_draw_getpixel(lua_State *_pL) { return DoLuaGMLCall(_pL, 334, 2); }
int lua_draw_getpixel_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 335, 2); }
int lua_draw_set_color(lua_State *_pL) { return DoLuaGMLCall(_pL, 336, 1); }
int lua_draw_set_colour(lua_State *_pL) { return DoLuaGMLCall(_pL, 337, 1); }
int lua_draw_set_alpha(lua_State *_pL) { return DoLuaGMLCall(_pL, 338, 1); }
int lua_draw_get_color(lua_State *_pL) { return DoLuaGMLCall(_pL, 339, 0); }
int lua_draw_get_colour(lua_State *_pL) { return DoLuaGMLCall(_pL, 340, 0); }
int lua_draw_get_alpha(lua_State *_pL) { return DoLuaGMLCall(_pL, 341, 0); }
int lua_make_color(lua_State *_pL) { return DoLuaGMLCall(_pL, 342, 3); }
int lua_make_colour(lua_State *_pL) { return DoLuaGMLCall(_pL, 343, 3); }
int lua_make_color_rgb(lua_State *_pL) { return DoLuaGMLCall(_pL, 344, 3); }
int lua_make_colour_rgb(lua_State *_pL) { return DoLuaGMLCall(_pL, 345, 3); }
int lua_make_color_hsv(lua_State *_pL) { return DoLuaGMLCall(_pL, 346, 3); }
int lua_make_colour_hsv(lua_State *_pL) { return DoLuaGMLCall(_pL, 347, 3); }
int lua_color_get_red(lua_State *_pL) { return DoLuaGMLCall(_pL, 348, 1); }
int lua_colour_get_red(lua_State *_pL) { return DoLuaGMLCall(_pL, 349, 1); }
int lua_color_get_green(lua_State *_pL) { return DoLuaGMLCall(_pL, 350, 1); }
int lua_colour_get_green(lua_State *_pL) { return DoLuaGMLCall(_pL, 351, 1); }
int lua_color_get_blue(lua_State *_pL) { return DoLuaGMLCall(_pL, 352, 1); }
int lua_colour_get_blue(lua_State *_pL) { return DoLuaGMLCall(_pL, 353, 1); }
int lua_color_get_hue(lua_State *_pL) { return DoLuaGMLCall(_pL, 354, 1); }
int lua_colour_get_hue(lua_State *_pL) { return DoLuaGMLCall(_pL, 355, 1); }
int lua_color_get_saturation(lua_State *_pL) { return DoLuaGMLCall(_pL, 356, 1); }
int lua_colour_get_saturation(lua_State *_pL) { return DoLuaGMLCall(_pL, 357, 1); }
int lua_color_get_value(lua_State *_pL) { return DoLuaGMLCall(_pL, 358, 1); }
int lua_colour_get_value(lua_State *_pL) { return DoLuaGMLCall(_pL, 359, 1); }
int lua_merge_color(lua_State *_pL) { return DoLuaGMLCall(_pL, 360, 3); }
int lua_merge_colour(lua_State *_pL) { return DoLuaGMLCall(_pL, 361, 3); }
int lua_draw_set_blend_mode(lua_State *_pL) { return DoLuaGMLCall(_pL, 362, 1); }
int lua_draw_set_blend_mode_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 363, 2); }
int lua_draw_set_color_write_enable(lua_State *_pL) { return DoLuaGMLCall(_pL, 364, 4); }
int lua_draw_set_colour_write_enable(lua_State *_pL) { return DoLuaGMLCall(_pL, 365, 4); }
int lua_draw_set_alpha_test(lua_State *_pL) { return DoLuaGMLCall(_pL, 366, 1); }
int lua_draw_set_alpha_test_ref_value(lua_State *_pL) { return DoLuaGMLCall(_pL, 367, 1); }
int lua_draw_get_alpha_test(lua_State *_pL) { return DoLuaGMLCall(_pL, 368, 0); }
int lua_draw_get_alpha_test_ref_value(lua_State *_pL) { return DoLuaGMLCall(_pL, 369, 0); }
int lua_draw_clear(lua_State *_pL) { return DoLuaGMLCall(_pL, 370, 1); }
int lua_draw_clear_alpha(lua_State *_pL) { return DoLuaGMLCall(_pL, 371, 2); }
int lua_draw_point(lua_State *_pL) { return DoLuaGMLCall(_pL, 372, 2); }
int lua_draw_line(lua_State *_pL) { return DoLuaGMLCall(_pL, 373, 4); }
int lua_draw_line_width(lua_State *_pL) { return DoLuaGMLCall(_pL, 374, 5); }
int lua_draw_rectangle(lua_State *_pL) { return DoLuaGMLCall(_pL, 375, 5); }
int lua_draw_roundrect(lua_State *_pL) { return DoLuaGMLCall(_pL, 376, 5); }
int lua_draw_roundrect_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 377, 5); }
int lua_draw_triangle(lua_State *_pL) { return DoLuaGMLCall(_pL, 378, 7); }
int lua_draw_circle(lua_State *_pL) { return DoLuaGMLCall(_pL, 379, 4); }
int lua_draw_ellipse(lua_State *_pL) { return DoLuaGMLCall(_pL, 380, 5); }
int lua_draw_arrow(lua_State *_pL) { return DoLuaGMLCall(_pL, 381, 5); }
int lua_draw_button(lua_State *_pL) { return DoLuaGMLCall(_pL, 382, 5); }
int lua_draw_healthbar(lua_State *_pL) { return DoLuaGMLCall(_pL, 383, 11); }
int lua_draw_path(lua_State *_pL) { return DoLuaGMLCall(_pL, 384, 4); }
int lua_draw_point_color(lua_State *_pL) { return DoLuaGMLCall(_pL, 385, 3); }
int lua_draw_point_colour(lua_State *_pL) { return DoLuaGMLCall(_pL, 386, 3); }
int lua_draw_line_color(lua_State *_pL) { return DoLuaGMLCall(_pL, 387, 6); }
int lua_draw_line_colour(lua_State *_pL) { return DoLuaGMLCall(_pL, 388, 6); }
int lua_draw_line_width_color(lua_State *_pL) { return DoLuaGMLCall(_pL, 389, 7); }
int lua_draw_line_width_colour(lua_State *_pL) { return DoLuaGMLCall(_pL, 390, 7); }
int lua_draw_rectangle_color(lua_State *_pL) { return DoLuaGMLCall(_pL, 391, 9); }
int lua_draw_rectangle_colour(lua_State *_pL) { return DoLuaGMLCall(_pL, 392, 9); }
int lua_draw_roundrect_color(lua_State *_pL) { return DoLuaGMLCall(_pL, 393, 7); }
int lua_draw_roundrect_colour(lua_State *_pL) { return DoLuaGMLCall(_pL, 394, 7); }
int lua_draw_roundrect_color_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 395, 7); }
int lua_draw_roundrect_colour_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 396, 7); }
int lua_draw_triangle_color(lua_State *_pL) { return DoLuaGMLCall(_pL, 397, 10); }
int lua_draw_triangle_colour(lua_State *_pL) { return DoLuaGMLCall(_pL, 398, 10); }
int lua_draw_circle_color(lua_State *_pL) { return DoLuaGMLCall(_pL, 399, 6); }
int lua_draw_circle_colour(lua_State *_pL) { return DoLuaGMLCall(_pL, 400, 6); }
int lua_draw_ellipse_color(lua_State *_pL) { return DoLuaGMLCall(_pL, 401, 7); }
int lua_draw_ellipse_colour(lua_State *_pL) { return DoLuaGMLCall(_pL, 402, 7); }
int lua_draw_get_circle_precision(lua_State *_pL) { return DoLuaGMLCall(_pL, 403, 0); }
int lua_draw_set_circle_precision(lua_State *_pL) { return DoLuaGMLCall(_pL, 404, 1); }
int lua_draw_primitive_begin(lua_State *_pL) { return DoLuaGMLCall(_pL, 405, 1); }
int lua_draw_primitive_begin_texture(lua_State *_pL) { return DoLuaGMLCall(_pL, 406, 2); }
int lua_draw_primitive_end(lua_State *_pL) { return DoLuaGMLCall(_pL, 407, 0); }
int lua_draw_vertex(lua_State *_pL) { return DoLuaGMLCall(_pL, 408, 2); }
int lua_draw_vertex_color(lua_State *_pL) { return DoLuaGMLCall(_pL, 409, 4); }
int lua_draw_vertex_colour(lua_State *_pL) { return DoLuaGMLCall(_pL, 410, 4); }
int lua_draw_vertex_texture(lua_State *_pL) { return DoLuaGMLCall(_pL, 411, 4); }
int lua_draw_vertex_texture_color(lua_State *_pL) { return DoLuaGMLCall(_pL, 412, 6); }
int lua_draw_vertex_texture_colour(lua_State *_pL) { return DoLuaGMLCall(_pL, 413, 6); }
int lua_sprite_get_uvs(lua_State *_pL) { return DoLuaGMLCall(_pL, 414, 2); }
int lua_background_get_uvs(lua_State *_pL) { return DoLuaGMLCall(_pL, 415, 2); }
int lua_font_get_uvs(lua_State *_pL) { return DoLuaGMLCall(_pL, 416, 2); }
int lua_sprite_get_texture(lua_State *_pL) { return DoLuaGMLCall(_pL, 417, 2); }
int lua_background_get_texture(lua_State *_pL) { return DoLuaGMLCall(_pL, 418, 1); }
int lua_font_get_texture(lua_State *_pL) { return DoLuaGMLCall(_pL, 419, 1); }
int lua_texture_exists(lua_State *_pL) { return DoLuaGMLCall(_pL, 420, 1); }
int lua_texture_set_interpolation(lua_State *_pL) { return DoLuaGMLCall(_pL, 421, 1); }
int lua_texture_set_interpolation_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 422, 2); }
int lua_texture_set_blending(lua_State *_pL) { return DoLuaGMLCall(_pL, 423, 1); }
int lua_texture_set_repeat(lua_State *_pL) { return DoLuaGMLCall(_pL, 424, 1); }
int lua_texture_set_repeat_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 425, 2); }
int lua_texture_get_width(lua_State *_pL) { return DoLuaGMLCall(_pL, 426, 1); }
int lua_texture_get_height(lua_State *_pL) { return DoLuaGMLCall(_pL, 427, 1); }
int lua_texture_preload(lua_State *_pL) { return DoLuaGMLCall(_pL, 428, 1); }
int lua_texture_set_priority(lua_State *_pL) { return DoLuaGMLCall(_pL, 429, 2); }
int lua_texture_global_scale(lua_State *_pL) { return DoLuaGMLCall(_pL, 430, 1); }
int lua_texture_get_uvs(lua_State *_pL) { return DoLuaGMLCall(_pL, 431, 1); }
int lua_draw_get_font(lua_State *_pL) { return DoLuaGMLCall(_pL, 432, 0); }
int lua_draw_set_font(lua_State *_pL) { return DoLuaGMLCall(_pL, 433, 1); }
int lua_draw_get_halign(lua_State *_pL) { return DoLuaGMLCall(_pL, 434, 0); }
int lua_draw_set_halign(lua_State *_pL) { return DoLuaGMLCall(_pL, 435, 1); }
int lua_draw_get_valign(lua_State *_pL) { return DoLuaGMLCall(_pL, 436, 0); }
int lua_draw_set_valign(lua_State *_pL) { return DoLuaGMLCall(_pL, 437, 1); }
int lua_string_width(lua_State *_pL) { return DoLuaGMLCall(_pL, 438, 1); }
int lua_string_height(lua_State *_pL) { return DoLuaGMLCall(_pL, 439, 1); }
int lua_string_width_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 440, 3); }
int lua_string_height_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 441, 3); }
int lua_draw_text(lua_State *_pL) { return DoLuaGMLCall(_pL, 442, 3); }
int lua_draw_text_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 443, 5); }
int lua_draw_text_transformed(lua_State *_pL) { return DoLuaGMLCall(_pL, 444, 6); }
int lua_draw_text_ext_transformed(lua_State *_pL) { return DoLuaGMLCall(_pL, 445, 8); }
int lua_draw_text_color(lua_State *_pL) { return DoLuaGMLCall(_pL, 446, 8); }
int lua_draw_text_colour(lua_State *_pL) { return DoLuaGMLCall(_pL, 447, 8); }
int lua_draw_text_transformed_color(lua_State *_pL) { return DoLuaGMLCall(_pL, 448, 11); }
int lua_draw_text_transformed_colour(lua_State *_pL) { return DoLuaGMLCall(_pL, 449, 11); }
int lua_draw_text_ext_color(lua_State *_pL) { return DoLuaGMLCall(_pL, 450, 10); }
int lua_draw_text_ext_colour(lua_State *_pL) { return DoLuaGMLCall(_pL, 451, 10); }
int lua_draw_text_ext_transformed_color(lua_State *_pL) { return DoLuaGMLCall(_pL, 452, 13); }
int lua_draw_text_ext_transformed_colour(lua_State *_pL) { return DoLuaGMLCall(_pL, 453, 13); }
int lua_collision_shape(lua_State *_pL) { return DoLuaGMLCall(_pL, 454, 9); }
int lua_draw_self(lua_State *_pL) { return DoLuaGMLCall(_pL, 455, 0); }
int lua_draw_sprite(lua_State *_pL) { return DoLuaGMLCall(_pL, 456, 4); }
int lua_draw_shape(lua_State *_pL) { return DoLuaGMLCall(_pL, 457, 11); }
int lua_draw_shape_string(lua_State *_pL) { return DoLuaGMLCall(_pL, 458, 10); }
int lua_draw_sprite_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 459, 9); }
int lua_draw_sprite_pos(lua_State *_pL) { return DoLuaGMLCall(_pL, 460, 11); }
int lua_draw_sprite_stretched(lua_State *_pL) { return DoLuaGMLCall(_pL, 461, 6); }
int lua_draw_sprite_stretched_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 462, 8); }
int lua_draw_sprite_part(lua_State *_pL) { return DoLuaGMLCall(_pL, 463, 8); }
int lua_draw_sprite_part_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 464, 12); }
int lua_draw_sprite_general(lua_State *_pL) { return DoLuaGMLCall(_pL, 465, 16); }
int lua_draw_sprite_tiled(lua_State *_pL) { return DoLuaGMLCall(_pL, 466, 4); }
int lua_draw_sprite_tiled_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 467, 8); }
int lua_draw_background(lua_State *_pL) { return DoLuaGMLCall(_pL, 468, 3); }
int lua_draw_background_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 469, 8); }
int lua_draw_background_stretched(lua_State *_pL) { return DoLuaGMLCall(_pL, 470, 5); }
int lua_draw_background_stretched_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 471, 7); }
int lua_draw_background_part(lua_State *_pL) { return DoLuaGMLCall(_pL, 472, 7); }
int lua_draw_background_part_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 473, 11); }
int lua_draw_background_general(lua_State *_pL) { return DoLuaGMLCall(_pL, 474, 15); }
int lua_draw_background_tiled(lua_State *_pL) { return DoLuaGMLCall(_pL, 475, 3); }
int lua_draw_background_tiled_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 476, 7); }
int lua_shader_enable_corner_id(lua_State *_pL) { return DoLuaGMLCall(_pL, 477, 1); }
int lua_tile_get_x(lua_State *_pL) { return DoLuaGMLCall(_pL, 478, 1); }
int lua_tile_get_y(lua_State *_pL) { return DoLuaGMLCall(_pL, 479, 1); }
int lua_tile_get_left(lua_State *_pL) { return DoLuaGMLCall(_pL, 480, 1); }
int lua_tile_get_top(lua_State *_pL) { return DoLuaGMLCall(_pL, 481, 1); }
int lua_tile_get_width(lua_State *_pL) { return DoLuaGMLCall(_pL, 482, 1); }
int lua_tile_get_height(lua_State *_pL) { return DoLuaGMLCall(_pL, 483, 1); }
int lua_tile_get_depth(lua_State *_pL) { return DoLuaGMLCall(_pL, 484, 1); }
int lua_tile_get_visible(lua_State *_pL) { return DoLuaGMLCall(_pL, 485, 1); }
int lua_tile_get_xscale(lua_State *_pL) { return DoLuaGMLCall(_pL, 486, 1); }
int lua_tile_get_yscale(lua_State *_pL) { return DoLuaGMLCall(_pL, 487, 1); }
int lua_tile_get_blend(lua_State *_pL) { return DoLuaGMLCall(_pL, 488, 1); }
int lua_tile_get_alpha(lua_State *_pL) { return DoLuaGMLCall(_pL, 489, 1); }
int lua_tile_get_background(lua_State *_pL) { return DoLuaGMLCall(_pL, 490, 1); }
int lua_tile_set_visible(lua_State *_pL) { return DoLuaGMLCall(_pL, 491, 2); }
int lua_tile_set_background(lua_State *_pL) { return DoLuaGMLCall(_pL, 492, 2); }
int lua_tile_set_region(lua_State *_pL) { return DoLuaGMLCall(_pL, 493, 5); }
int lua_tile_set_position(lua_State *_pL) { return DoLuaGMLCall(_pL, 494, 3); }
int lua_tile_set_depth(lua_State *_pL) { return DoLuaGMLCall(_pL, 495, 2); }
int lua_tile_set_scale(lua_State *_pL) { return DoLuaGMLCall(_pL, 496, 3); }
int lua_tile_set_blend(lua_State *_pL) { return DoLuaGMLCall(_pL, 497, 2); }
int lua_tile_set_alpha(lua_State *_pL) { return DoLuaGMLCall(_pL, 498, 2); }
int lua_tile_get_count(lua_State *_pL) { return DoLuaGMLCall(_pL, 499, 0); }
int lua_tile_get_id(lua_State *_pL) { return DoLuaGMLCall(_pL, 500, 1); }
int lua_tile_get_ids(lua_State *_pL) { return DoLuaGMLCall(_pL, 501, 0); }
int lua_tile_get_ids_at_depth(lua_State *_pL) { return DoLuaGMLCall(_pL, 502, 1); }
int lua_tile_add(lua_State *_pL) { return DoLuaGMLCall(_pL, 503, 8); }
int lua_tile_exists(lua_State *_pL) { return DoLuaGMLCall(_pL, 504, 1); }
int lua_tile_delete(lua_State *_pL) { return DoLuaGMLCall(_pL, 505, 1); }
int lua_tile_layer_hide(lua_State *_pL) { return DoLuaGMLCall(_pL, 506, 1); }
int lua_tile_layer_show(lua_State *_pL) { return DoLuaGMLCall(_pL, 507, 1); }
int lua_tile_layer_delete(lua_State *_pL) { return DoLuaGMLCall(_pL, 508, 1); }
int lua_tile_layer_shift(lua_State *_pL) { return DoLuaGMLCall(_pL, 509, 3); }
int lua_tile_layer_find(lua_State *_pL) { return DoLuaGMLCall(_pL, 510, 3); }
int lua_tile_layer_delete_at(lua_State *_pL) { return DoLuaGMLCall(_pL, 511, 3); }
int lua_tile_layer_depth(lua_State *_pL) { return DoLuaGMLCall(_pL, 512, 2); }
int lua_surface_create(lua_State *_pL) { return DoLuaGMLCall(_pL, 513, 2); }
int lua_surface_create_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 514, 3); }
int lua_surface_create_special(lua_State *_pL) { return DoLuaGMLCall(_pL, 515, 3); }
int lua_surface_resize(lua_State *_pL) { return DoLuaGMLCall(_pL, 516, 3); }
int lua_surface_free(lua_State *_pL) { return DoLuaGMLCall(_pL, 517, 1); }
int lua_surface_exists(lua_State *_pL) { return DoLuaGMLCall(_pL, 518, 1); }
int lua_surface_get_width(lua_State *_pL) { return DoLuaGMLCall(_pL, 519, 1); }
int lua_surface_get_height(lua_State *_pL) { return DoLuaGMLCall(_pL, 520, 1); }
int lua_surface_get_texture(lua_State *_pL) { return DoLuaGMLCall(_pL, 521, 1); }
int lua_surface_get_target(lua_State *_pL) { return DoLuaGMLCall(_pL, 522, 0); }
int lua_surface_set_target(lua_State *_pL) { return DoLuaGMLCall(_pL, 523, 1); }
int lua_surface_get_target_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 524, 1); }
int lua_surface_set_target_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 525, 2); }
int lua_surface_reset_target(lua_State *_pL) { return DoLuaGMLCall(_pL, 526, 0); }
int lua_surface_depth_disable(lua_State *_pL) { return DoLuaGMLCall(_pL, 527, 1); }
int lua_surface_get_depth_disable(lua_State *_pL) { return DoLuaGMLCall(_pL, 528, 0); }
int lua_draw_surface(lua_State *_pL) { return DoLuaGMLCall(_pL, 529, 3); }
int lua_draw_surface_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 530, 8); }
int lua_draw_surface_stretched(lua_State *_pL) { return DoLuaGMLCall(_pL, 531, 5); }
int lua_draw_surface_stretched_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 532, 7); }
int lua_draw_surface_part(lua_State *_pL) { return DoLuaGMLCall(_pL, 533, 7); }
int lua_draw_surface_part_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 534, 11); }
int lua_draw_surface_general(lua_State *_pL) { return DoLuaGMLCall(_pL, 535, 15); }
int lua_draw_surface_tiled(lua_State *_pL) { return DoLuaGMLCall(_pL, 536, 3); }
int lua_draw_surface_tiled_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 537, 7); }
int lua_surface_save(lua_State *_pL) { return DoLuaGMLCall(_pL, 538, 2); }
int lua_surface_save_part(lua_State *_pL) { return DoLuaGMLCall(_pL, 539, 6); }
int lua_surface_getpixel(lua_State *_pL) { return DoLuaGMLCall(_pL, 540, 3); }
int lua_surface_getpixel_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 541, 3); }
int lua_surface_copy(lua_State *_pL) { return DoLuaGMLCall(_pL, 542, 4); }
int lua_surface_copy_part(lua_State *_pL) { return DoLuaGMLCall(_pL, 543, 8); }
int lua_skeleton_animation_set(lua_State *_pL) { return DoLuaGMLCall(_pL, 544, 1); }
int lua_skeleton_animation_get(lua_State *_pL) { return DoLuaGMLCall(_pL, 545, 0); }
int lua_skeleton_animation_mix(lua_State *_pL) { return DoLuaGMLCall(_pL, 546, 3); }
int lua_skeleton_animation_set_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 547, 2); }
int lua_skeleton_animation_get_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 548, 1); }
int lua_skeleton_animation_get_duration(lua_State *_pL) { return DoLuaGMLCall(_pL, 549, 1); }
int lua_skeleton_animation_get_frames(lua_State *_pL) { return DoLuaGMLCall(_pL, 550, 1); }
int lua_skeleton_animation_clear(lua_State *_pL) { return DoLuaGMLCall(_pL, 551, 1); }
int lua_skeleton_skin_set(lua_State *_pL) { return DoLuaGMLCall(_pL, 552, 2); }
int lua_skeleton_skin_get(lua_State *_pL) { return DoLuaGMLCall(_pL, 553, 2); }
int lua_skeleton_attachment_set(lua_State *_pL) { return DoLuaGMLCall(_pL, 554, 2); }
int lua_skeleton_attachment_get(lua_State *_pL) { return DoLuaGMLCall(_pL, 555, 2); }
int lua_skeleton_attachment_create(lua_State *_pL) { return DoLuaGMLCall(_pL, 556, 1); }
int lua_skeleton_collision_draw_set(lua_State *_pL) { return DoLuaGMLCall(_pL, 557, 1); }
int lua_skeleton_bone_data_get(lua_State *_pL) { return DoLuaGMLCall(_pL, 558, 2); }
int lua_skeleton_bone_data_set(lua_State *_pL) { return DoLuaGMLCall(_pL, 559, 2); }
int lua_skeleton_bone_state_get(lua_State *_pL) { return DoLuaGMLCall(_pL, 560, 2); }
int lua_skeleton_bone_state_set(lua_State *_pL) { return DoLuaGMLCall(_pL, 561, 2); }
int lua_draw_skeleton(lua_State *_pL) { return DoLuaGMLCall(_pL, 562, 11); }
int lua_draw_skeleton_time(lua_State *_pL) { return DoLuaGMLCall(_pL, 563, 11); }
int lua_draw_skeleton_instance(lua_State *_pL) { return DoLuaGMLCall(_pL, 564, 4); }
int lua_draw_skeleton_collision(lua_State *_pL) { return DoLuaGMLCall(_pL, 565, 9); }
int lua_skeleton_animation_list(lua_State *_pL) { return DoLuaGMLCall(_pL, 566, 2); }
int lua_skeleton_skin_list(lua_State *_pL) { return DoLuaGMLCall(_pL, 567, 2); }
int lua_skeleton_slot_data(lua_State *_pL) { return DoLuaGMLCall(_pL, 568, 2); }
int lua_skeleton_animation_get_frame(lua_State *_pL) { return DoLuaGMLCall(_pL, 569, 1); }
int lua_skeleton_animation_set_frame(lua_State *_pL) { return DoLuaGMLCall(_pL, 570, 2); }
int lua_skeleton_get_minmax(lua_State *_pL) { return DoLuaGMLCall(_pL, 571, 0); }
int lua_skeleton_get_num_bounds(lua_State *_pL) { return DoLuaGMLCall(_pL, 572, 0); }
int lua_skeleton_get_bounds(lua_State *_pL) { return DoLuaGMLCall(_pL, 573, 1); }
int lua_draw_enable_swf_aa(lua_State *_pL) { return DoLuaGMLCall(_pL, 574, 1); }
int lua_draw_set_swf_aa_level(lua_State *_pL) { return DoLuaGMLCall(_pL, 575, 1); }
int lua_draw_get_swf_aa_level(lua_State *_pL) { return DoLuaGMLCall(_pL, 576, 0); }
int lua_action_path_old(lua_State *_pL) { return DoLuaGMLCall(_pL, 577, 3); }
int lua_action_set_sprite(lua_State *_pL) { return DoLuaGMLCall(_pL, 578, 2); }
int lua_action_draw_font(lua_State *_pL) { return DoLuaGMLCall(_pL, 579, 1); }
int lua_action_draw_font_old(lua_State *_pL) { return DoLuaGMLCall(_pL, 580, 6); }
int lua_action_fill_color(lua_State *_pL) { return DoLuaGMLCall(_pL, 581, 1); }
int lua_action_fill_colour(lua_State *_pL) { return DoLuaGMLCall(_pL, 582, 1); }
int lua_action_line_color(lua_State *_pL) { return DoLuaGMLCall(_pL, 583, 1); }
int lua_action_line_colour(lua_State *_pL) { return DoLuaGMLCall(_pL, 584, 1); }
int lua_action_highscore(lua_State *_pL) { return DoLuaGMLCall(_pL, 585, 0); }
int lua_action_set_relative(lua_State *_pL) { return DoLuaGMLCall(_pL, 586, 1); }
int lua_action_move(lua_State *_pL) { return DoLuaGMLCall(_pL, 587, 2); }
int lua_action_set_motion(lua_State *_pL) { return DoLuaGMLCall(_pL, 588, 2); }
int lua_action_set_hspeed(lua_State *_pL) { return DoLuaGMLCall(_pL, 589, 1); }
int lua_action_set_vspeed(lua_State *_pL) { return DoLuaGMLCall(_pL, 590, 1); }
int lua_action_set_gravity(lua_State *_pL) { return DoLuaGMLCall(_pL, 591, 2); }
int lua_action_set_friction(lua_State *_pL) { return DoLuaGMLCall(_pL, 592, 1); }
int lua_action_move_point(lua_State *_pL) { return DoLuaGMLCall(_pL, 593, 3); }
int lua_action_move_to(lua_State *_pL) { return DoLuaGMLCall(_pL, 594, 2); }
int lua_action_move_start(lua_State *_pL) { return DoLuaGMLCall(_pL, 595, 0); }
int lua_action_move_random(lua_State *_pL) { return DoLuaGMLCall(_pL, 596, 2); }
int lua_action_snap(lua_State *_pL) { return DoLuaGMLCall(_pL, 597, 2); }
int lua_action_wrap(lua_State *_pL) { return DoLuaGMLCall(_pL, 598, 1); }
int lua_action_reverse_xdir(lua_State *_pL) { return DoLuaGMLCall(_pL, 599, 0); }
int lua_action_reverse_ydir(lua_State *_pL) { return DoLuaGMLCall(_pL, 600, 0); }
int lua_action_move_contact(lua_State *_pL) { return DoLuaGMLCall(_pL, 601, 3); }
int lua_action_bounce(lua_State *_pL) { return DoLuaGMLCall(_pL, 602, 2); }
int lua_action_path(lua_State *_pL) { return DoLuaGMLCall(_pL, 603, 4); }
int lua_action_path_end(lua_State *_pL) { return DoLuaGMLCall(_pL, 604, 0); }
int lua_action_path_position(lua_State *_pL) { return DoLuaGMLCall(_pL, 605, 1); }
int lua_action_path_speed(lua_State *_pL) { return DoLuaGMLCall(_pL, 606, 1); }
int lua_action_linear_step(lua_State *_pL) { return DoLuaGMLCall(_pL, 607, 4); }
int lua_action_potential_step(lua_State *_pL) { return DoLuaGMLCall(_pL, 608, 4); }
int lua_action_kill_object(lua_State *_pL) { return DoLuaGMLCall(_pL, 609, 0); }
int lua_action_create_object(lua_State *_pL) { return DoLuaGMLCall(_pL, 610, 3); }
int lua_action_create_object_motion(lua_State *_pL) { return DoLuaGMLCall(_pL, 611, 5); }
int lua_action_create_object_random(lua_State *_pL) { return DoLuaGMLCall(_pL, 612, 6); }
int lua_action_change_object(lua_State *_pL) { return DoLuaGMLCall(_pL, 613, 2); }
int lua_action_kill_position(lua_State *_pL) { return DoLuaGMLCall(_pL, 614, 2); }
int lua_action_sprite_set(lua_State *_pL) { return DoLuaGMLCall(_pL, 615, 3); }
int lua_action_sprite_transform(lua_State *_pL) { return DoLuaGMLCall(_pL, 616, 4); }
int lua_action_sprite_color(lua_State *_pL) { return DoLuaGMLCall(_pL, 617, 2); }
int lua_action_sprite_colour(lua_State *_pL) { return DoLuaGMLCall(_pL, 618, 2); }
int lua_action_sound(lua_State *_pL) { return DoLuaGMLCall(_pL, 619, 2); }
int lua_action_end_sound(lua_State *_pL) { return DoLuaGMLCall(_pL, 620, 1); }
int lua_action_if_sound(lua_State *_pL) { return DoLuaGMLCall(_pL, 621, 1); }
int lua_action_another_room(lua_State *_pL) { return DoLuaGMLCall(_pL, 622, 1); }
int lua_action_current_room(lua_State *_pL) { return DoLuaGMLCall(_pL, 623, 0); }
int lua_action_previous_room(lua_State *_pL) { return DoLuaGMLCall(_pL, 624, 0); }
int lua_action_next_room(lua_State *_pL) { return DoLuaGMLCall(_pL, 625, 0); }
int lua_action_if_previous_room(lua_State *_pL) { return DoLuaGMLCall(_pL, 626, 0); }
int lua_action_if_next_room(lua_State *_pL) { return DoLuaGMLCall(_pL, 627, 0); }
int lua_action_set_alarm(lua_State *_pL) { return DoLuaGMLCall(_pL, 628, 2); }
int lua_action_sleep(lua_State *_pL) { return DoLuaGMLCall(_pL, 629, 2); }
int lua_action_set_timeline(lua_State *_pL) { return DoLuaGMLCall(_pL, 630, 2); }
int lua_action_set_timeline_position(lua_State *_pL) { return DoLuaGMLCall(_pL, 631, 1); }
int lua_action_set_timeline_speed(lua_State *_pL) { return DoLuaGMLCall(_pL, 632, 1); }
int lua_action_timeline_set(lua_State *_pL) { return DoLuaGMLCall(_pL, 633, 4); }
int lua_action_timeline_start(lua_State *_pL) { return DoLuaGMLCall(_pL, 634, 0); }
int lua_action_timeline_pause(lua_State *_pL) { return DoLuaGMLCall(_pL, 635, 0); }
int lua_action_timeline_stop(lua_State *_pL) { return DoLuaGMLCall(_pL, 636, 0); }
int lua_action_message(lua_State *_pL) { return DoLuaGMLCall(_pL, 637, 1); }
int lua_action_show_info(lua_State *_pL) { return DoLuaGMLCall(_pL, 638, 0); }
int lua_action_show_video(lua_State *_pL) { return DoLuaGMLCall(_pL, 639, 3); }
int lua_action_end_game(lua_State *_pL) { return DoLuaGMLCall(_pL, 640, 0); }
int lua_action_restart_game(lua_State *_pL) { return DoLuaGMLCall(_pL, 641, 0); }
int lua_action_save_game(lua_State *_pL) { return DoLuaGMLCall(_pL, 642, 1); }
int lua_action_load_game(lua_State *_pL) { return DoLuaGMLCall(_pL, 643, 1); }
int lua_action_replace_sprite(lua_State *_pL) { return DoLuaGMLCall(_pL, 644, 3); }
int lua_action_replace_sound(lua_State *_pL) { return DoLuaGMLCall(_pL, 645, 2); }
int lua_action_replace_background(lua_State *_pL) { return DoLuaGMLCall(_pL, 646, 2); }
int lua_action_if_empty(lua_State *_pL) { return DoLuaGMLCall(_pL, 647, 3); }
int lua_action_if_collision(lua_State *_pL) { return DoLuaGMLCall(_pL, 648, 3); }
int lua_action_if(lua_State *_pL) { return DoLuaGMLCall(_pL, 649, 1); }
int lua_action_if_number(lua_State *_pL) { return DoLuaGMLCall(_pL, 650, 3); }
int lua_action_if_object(lua_State *_pL) { return DoLuaGMLCall(_pL, 651, 3); }
int lua_action_if_question(lua_State *_pL) { return DoLuaGMLCall(_pL, 652, 1); }
int lua_action_if_dice(lua_State *_pL) { return DoLuaGMLCall(_pL, 653, 1); }
int lua_action_if_mouse(lua_State *_pL) { return DoLuaGMLCall(_pL, 654, 1); }
int lua_action_if_aligned(lua_State *_pL) { return DoLuaGMLCall(_pL, 655, 2); }
int lua_action_execute_script(lua_State *_pL) { return DoLuaGMLCall(_pL, 656, 6); }
int lua_action_inherited(lua_State *_pL) { return DoLuaGMLCall(_pL, 657, 0); }
int lua_action_if_variable(lua_State *_pL) { return DoLuaGMLCall(_pL, 658, 3); }
int lua_action_draw_variable(lua_State *_pL) { return DoLuaGMLCall(_pL, 659, 3); }
int lua_action_set_score(lua_State *_pL) { return DoLuaGMLCall(_pL, 660, 1); }
int lua_action_if_score(lua_State *_pL) { return DoLuaGMLCall(_pL, 661, 2); }
int lua_action_draw_score(lua_State *_pL) { return DoLuaGMLCall(_pL, 662, 3); }
int lua_action_highscore_show(lua_State *_pL) { return DoLuaGMLCall(_pL, 663, 11); }
int lua_action_highscore_clear(lua_State *_pL) { return DoLuaGMLCall(_pL, 664, 0); }
int lua_action_set_life(lua_State *_pL) { return DoLuaGMLCall(_pL, 665, 1); }
int lua_action_if_life(lua_State *_pL) { return DoLuaGMLCall(_pL, 666, 2); }
int lua_action_draw_life(lua_State *_pL) { return DoLuaGMLCall(_pL, 667, 3); }
int lua_action_draw_life_images(lua_State *_pL) { return DoLuaGMLCall(_pL, 668, 3); }
int lua_action_set_health(lua_State *_pL) { return DoLuaGMLCall(_pL, 669, 1); }
int lua_action_if_health(lua_State *_pL) { return DoLuaGMLCall(_pL, 670, 2); }
int lua_action_draw_health(lua_State *_pL) { return DoLuaGMLCall(_pL, 671, 6); }
int lua_action_set_caption(lua_State *_pL) { return DoLuaGMLCall(_pL, 672, 6); }
int lua_action_partsyst_create(lua_State *_pL) { return DoLuaGMLCall(_pL, 673, 1); }
int lua_action_partsyst_destroy(lua_State *_pL) { return DoLuaGMLCall(_pL, 674, 0); }
int lua_action_partsyst_clear(lua_State *_pL) { return DoLuaGMLCall(_pL, 675, 0); }
int lua_action_parttype_create_old(lua_State *_pL) { return DoLuaGMLCall(_pL, 676, 6); }
int lua_action_parttype_create(lua_State *_pL) { return DoLuaGMLCall(_pL, 677, 6); }
int lua_action_parttype_color(lua_State *_pL) { return DoLuaGMLCall(_pL, 678, 6); }
int lua_action_parttype_colour(lua_State *_pL) { return DoLuaGMLCall(_pL, 679, 6); }
int lua_action_parttype_life(lua_State *_pL) { return DoLuaGMLCall(_pL, 680, 3); }
int lua_action_parttype_speed(lua_State *_pL) { return DoLuaGMLCall(_pL, 681, 6); }
int lua_action_parttype_gravity(lua_State *_pL) { return DoLuaGMLCall(_pL, 682, 3); }
int lua_action_parttype_secondary(lua_State *_pL) { return DoLuaGMLCall(_pL, 683, 5); }
int lua_action_partemit_create(lua_State *_pL) { return DoLuaGMLCall(_pL, 684, 6); }
int lua_action_partemit_destroy(lua_State *_pL) { return DoLuaGMLCall(_pL, 685, 1); }
int lua_action_partemit_burst(lua_State *_pL) { return DoLuaGMLCall(_pL, 686, 3); }
int lua_action_partemit_stream(lua_State *_pL) { return DoLuaGMLCall(_pL, 687, 3); }
int lua_action_cd_play(lua_State *_pL) { return DoLuaGMLCall(_pL, 688, 2); }
int lua_action_cd_stop(lua_State *_pL) { return DoLuaGMLCall(_pL, 689, 0); }
int lua_action_cd_pause(lua_State *_pL) { return DoLuaGMLCall(_pL, 690, 0); }
int lua_action_cd_resume(lua_State *_pL) { return DoLuaGMLCall(_pL, 691, 0); }
int lua_action_cd_present(lua_State *_pL) { return DoLuaGMLCall(_pL, 692, 0); }
int lua_action_cd_playing(lua_State *_pL) { return DoLuaGMLCall(_pL, 693, 0); }
int lua_action_set_cursor(lua_State *_pL) { return DoLuaGMLCall(_pL, 694, 2); }
int lua_action_webpage(lua_State *_pL) { return DoLuaGMLCall(_pL, 695, 1); }
int lua_action_draw_sprite(lua_State *_pL) { return DoLuaGMLCall(_pL, 696, 4); }
int lua_action_draw_background(lua_State *_pL) { return DoLuaGMLCall(_pL, 697, 4); }
int lua_action_draw_text(lua_State *_pL) { return DoLuaGMLCall(_pL, 698, 3); }
int lua_action_draw_text_transformed(lua_State *_pL) { return DoLuaGMLCall(_pL, 699, 6); }
int lua_action_draw_rectangle(lua_State *_pL) { return DoLuaGMLCall(_pL, 700, 5); }
int lua_action_draw_gradient_hor(lua_State *_pL) { return DoLuaGMLCall(_pL, 701, 6); }
int lua_action_draw_gradient_vert(lua_State *_pL) { return DoLuaGMLCall(_pL, 702, 6); }
int lua_action_draw_ellipse(lua_State *_pL) { return DoLuaGMLCall(_pL, 703, 5); }
int lua_action_draw_ellipse_gradient(lua_State *_pL) { return DoLuaGMLCall(_pL, 704, 6); }
int lua_action_draw_line(lua_State *_pL) { return DoLuaGMLCall(_pL, 705, 4); }
int lua_action_draw_arrow(lua_State *_pL) { return DoLuaGMLCall(_pL, 706, 5); }
int lua_action_color(lua_State *_pL) { return DoLuaGMLCall(_pL, 707, 1); }
int lua_action_colour(lua_State *_pL) { return DoLuaGMLCall(_pL, 708, 1); }
int lua_action_font(lua_State *_pL) { return DoLuaGMLCall(_pL, 709, 2); }
int lua_action_fullscreen(lua_State *_pL) { return DoLuaGMLCall(_pL, 710, 1); }
int lua_action_snapshot(lua_State *_pL) { return DoLuaGMLCall(_pL, 711, 1); }
int lua_action_effect(lua_State *_pL) { return DoLuaGMLCall(_pL, 712, 6); }
int lua_file_bin_open(lua_State *_pL) { return DoLuaGMLCall(_pL, 713, 2); }
int lua_file_bin_rewrite(lua_State *_pL) { return DoLuaGMLCall(_pL, 714, 1); }
int lua_file_bin_close(lua_State *_pL) { return DoLuaGMLCall(_pL, 715, 1); }
int lua_file_bin_position(lua_State *_pL) { return DoLuaGMLCall(_pL, 716, 1); }
int lua_file_bin_size(lua_State *_pL) { return DoLuaGMLCall(_pL, 717, 1); }
int lua_file_bin_seek(lua_State *_pL) { return DoLuaGMLCall(_pL, 718, 2); }
int lua_file_bin_read_byte(lua_State *_pL) { return DoLuaGMLCall(_pL, 719, 1); }
int lua_file_bin_write_byte(lua_State *_pL) { return DoLuaGMLCall(_pL, 720, 2); }
int lua_file_text_open_from_string(lua_State *_pL) { return DoLuaGMLCall(_pL, 721, 1); }
int lua_file_text_open_read(lua_State *_pL) { return DoLuaGMLCall(_pL, 722, 1); }
int lua_file_text_open_write(lua_State *_pL) { return DoLuaGMLCall(_pL, 723, 1); }
int lua_file_text_open_append(lua_State *_pL) { return DoLuaGMLCall(_pL, 724, 1); }
int lua_file_text_close(lua_State *_pL) { return DoLuaGMLCall(_pL, 725, 1); }
int lua_file_text_read_string(lua_State *_pL) { return DoLuaGMLCall(_pL, 726, 1); }
int lua_file_text_read_real(lua_State *_pL) { return DoLuaGMLCall(_pL, 727, 1); }
int lua_file_text_readln(lua_State *_pL) { return DoLuaGMLCall(_pL, 728, 1); }
int lua_file_text_eof(lua_State *_pL) { return DoLuaGMLCall(_pL, 729, 1); }
int lua_file_text_eoln(lua_State *_pL) { return DoLuaGMLCall(_pL, 730, 1); }
int lua_file_text_write_string(lua_State *_pL) { return DoLuaGMLCall(_pL, 731, 2); }
int lua_file_text_write_real(lua_State *_pL) { return DoLuaGMLCall(_pL, 732, 2); }
int lua_file_text_writeln(lua_State *_pL) { return DoLuaGMLCall(_pL, 733, 1); }
int lua_file_open_read(lua_State *_pL) { return DoLuaGMLCall(_pL, 734, 1); }
int lua_file_open_write(lua_State *_pL) { return DoLuaGMLCall(_pL, 735, 1); }
int lua_file_open_append(lua_State *_pL) { return DoLuaGMLCall(_pL, 736, 1); }
int lua_file_close(lua_State *_pL) { return DoLuaGMLCall(_pL, 737, 0); }
int lua_file_read_string(lua_State *_pL) { return DoLuaGMLCall(_pL, 738, 0); }
int lua_file_read_real(lua_State *_pL) { return DoLuaGMLCall(_pL, 739, 0); }
int lua_file_readln(lua_State *_pL) { return DoLuaGMLCall(_pL, 740, 0); }
int lua_file_eof(lua_State *_pL) { return DoLuaGMLCall(_pL, 741, 0); }
int lua_file_write_string(lua_State *_pL) { return DoLuaGMLCall(_pL, 742, 1); }
int lua_file_write_real(lua_State *_pL) { return DoLuaGMLCall(_pL, 743, 1); }
int lua_file_writeln(lua_State *_pL) { return DoLuaGMLCall(_pL, 744, 0); }
int lua_file_exists(lua_State *_pL) { return DoLuaGMLCall(_pL, 745, 1); }
int lua_file_delete(lua_State *_pL) { return DoLuaGMLCall(_pL, 746, 1); }
int lua_file_rename(lua_State *_pL) { return DoLuaGMLCall(_pL, 747, 2); }
int lua_file_copy(lua_State *_pL) { return DoLuaGMLCall(_pL, 748, 2); }
int lua_directory_exists(lua_State *_pL) { return DoLuaGMLCall(_pL, 749, 1); }
int lua_directory_create(lua_State *_pL) { return DoLuaGMLCall(_pL, 750, 1); }
int lua_directory_destroy(lua_State *_pL) { return DoLuaGMLCall(_pL, 751, 1); }
int lua_file_find_first(lua_State *_pL) { return DoLuaGMLCall(_pL, 752, 2); }
int lua_file_find_next(lua_State *_pL) { return DoLuaGMLCall(_pL, 753, 0); }
int lua_file_find_close(lua_State *_pL) { return DoLuaGMLCall(_pL, 754, 0); }
int lua_file_attributes(lua_State *_pL) { return DoLuaGMLCall(_pL, 755, 2); }
int lua_filename_name(lua_State *_pL) { return DoLuaGMLCall(_pL, 756, 1); }
int lua_filename_path(lua_State *_pL) { return DoLuaGMLCall(_pL, 757, 1); }
int lua_filename_dir(lua_State *_pL) { return DoLuaGMLCall(_pL, 758, 1); }
int lua_filename_drive(lua_State *_pL) { return DoLuaGMLCall(_pL, 759, 1); }
int lua_filename_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 760, 1); }
int lua_filename_change_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 761, 2); }
int lua_execute_program(lua_State *_pL) { return DoLuaGMLCall(_pL, 762, 3); }
int lua_execute_shell(lua_State *_pL) { return DoLuaGMLCall(_pL, 763, 2); }
int lua_parameter_count(lua_State *_pL) { return DoLuaGMLCall(_pL, 764, 0); }
int lua_parameter_string(lua_State *_pL) { return DoLuaGMLCall(_pL, 765, 1); }
int lua_environment_get_variable(lua_State *_pL) { return DoLuaGMLCall(_pL, 766, 1); }
int lua_ini_open_from_string(lua_State *_pL) { return DoLuaGMLCall(_pL, 767, 1); }
int lua_ini_open(lua_State *_pL) { return DoLuaGMLCall(_pL, 768, 1); }
int lua_ini_close(lua_State *_pL) { return DoLuaGMLCall(_pL, 769, 0); }
int lua_ini_read_string(lua_State *_pL) { return DoLuaGMLCall(_pL, 770, 3); }
int lua_ini_read_real(lua_State *_pL) { return DoLuaGMLCall(_pL, 771, 3); }
int lua_ini_write_string(lua_State *_pL) { return DoLuaGMLCall(_pL, 772, 3); }
int lua_ini_write_real(lua_State *_pL) { return DoLuaGMLCall(_pL, 773, 3); }
int lua_ini_key_exists(lua_State *_pL) { return DoLuaGMLCall(_pL, 774, 2); }
int lua_ini_section_exists(lua_State *_pL) { return DoLuaGMLCall(_pL, 775, 1); }
int lua_ini_key_delete(lua_State *_pL) { return DoLuaGMLCall(_pL, 776, 2); }
int lua_ini_section_delete(lua_State *_pL) { return DoLuaGMLCall(_pL, 777, 1); }
int lua_http_post_string(lua_State *_pL) { return DoLuaGMLCall(_pL, 778, 2); }
int lua_http_get(lua_State *_pL) { return DoLuaGMLCall(_pL, 779, 1); }
int lua_http_get_file(lua_State *_pL) { return DoLuaGMLCall(_pL, 780, 2); }
int lua_http_request(lua_State *_pL) { return DoLuaGMLCall(_pL, 781, 4); }
int lua_http_get_request_crossorigin(lua_State *_pL) { return DoLuaGMLCall(_pL, 782, 0); }
int lua_http_set_request_crossorigin(lua_State *_pL) { return DoLuaGMLCall(_pL, 783, 1); }
int lua_json_encode(lua_State *_pL) { return DoLuaGMLCall(_pL, 784, 1); }
int lua_json_decode(lua_State *_pL) { return DoLuaGMLCall(_pL, 785, 1); }
int lua_zip_unzip(lua_State *_pL) { return DoLuaGMLCall(_pL, 786, 2); }
int lua_load_csv(lua_State *_pL) { return DoLuaGMLCall(_pL, 787, 1); }
int lua_sprite_name(lua_State *_pL) { return DoLuaGMLCall(_pL, 788, 1); }
int lua_sprite_exists(lua_State *_pL) { return DoLuaGMLCall(_pL, 789, 1); }
int lua_sprite_get_name(lua_State *_pL) { return DoLuaGMLCall(_pL, 790, 1); }
int lua_sprite_get_number(lua_State *_pL) { return DoLuaGMLCall(_pL, 791, 1); }
int lua_sprite_get_width(lua_State *_pL) { return DoLuaGMLCall(_pL, 792, 1); }
int lua_sprite_get_height(lua_State *_pL) { return DoLuaGMLCall(_pL, 793, 1); }
int lua_sprite_get_transparent(lua_State *_pL) { return DoLuaGMLCall(_pL, 794, 1); }
int lua_sprite_get_smooth(lua_State *_pL) { return DoLuaGMLCall(_pL, 795, 1); }
int lua_sprite_get_preload(lua_State *_pL) { return DoLuaGMLCall(_pL, 796, 1); }
int lua_sprite_get_xoffset(lua_State *_pL) { return DoLuaGMLCall(_pL, 797, 1); }
int lua_sprite_get_yoffset(lua_State *_pL) { return DoLuaGMLCall(_pL, 798, 1); }
int lua_sprite_get_bbox_mode(lua_State *_pL) { return DoLuaGMLCall(_pL, 799, 1); }
int lua_sprite_get_bbox_left(lua_State *_pL) { return DoLuaGMLCall(_pL, 800, 1); }
int lua_sprite_get_bbox_right(lua_State *_pL) { return DoLuaGMLCall(_pL, 801, 1); }
int lua_sprite_get_bbox_top(lua_State *_pL) { return DoLuaGMLCall(_pL, 802, 1); }
int lua_sprite_get_bbox_bottom(lua_State *_pL) { return DoLuaGMLCall(_pL, 803, 1); }
int lua_sprite_get_precise(lua_State *_pL) { return DoLuaGMLCall(_pL, 804, 1); }
int lua_sprite_collision_mask(lua_State *_pL) { return DoLuaGMLCall(_pL, 805, 9); }
int lua_sprite_set_cache_size(lua_State *_pL) { return DoLuaGMLCall(_pL, 806, 2); }
int lua_sprite_set_cache_size_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 807, 3); }
int lua_font_set_cache_size(lua_State *_pL) { return DoLuaGMLCall(_pL, 808, 2); }
int lua_sprite_get_tpe(lua_State *_pL) { return DoLuaGMLCall(_pL, 809, 2); }
int lua_sprite_set_offset(lua_State *_pL) { return DoLuaGMLCall(_pL, 810, 3); }
int lua_sprite_set_bbox_mode(lua_State *_pL) { return DoLuaGMLCall(_pL, 811, 2); }
int lua_sprite_set_bbox(lua_State *_pL) { return DoLuaGMLCall(_pL, 812, 5); }
int lua_sprite_set_precise(lua_State *_pL) { return DoLuaGMLCall(_pL, 813, 2); }
int lua_sprite_set_alpha_from_sprite(lua_State *_pL) { return DoLuaGMLCall(_pL, 814, 2); }
int lua_sprite_add(lua_State *_pL) { return DoLuaGMLCall(_pL, 815, 6); }
int lua_sprite_create_from_screen(lua_State *_pL) { return DoLuaGMLCall(_pL, 816, 8); }
int lua_sprite_add_from_screen(lua_State *_pL) { return DoLuaGMLCall(_pL, 817, 7); }
int lua_sprite_create_from_surface(lua_State *_pL) { return DoLuaGMLCall(_pL, 818, 9); }
int lua_sprite_add_from_surface(lua_State *_pL) { return DoLuaGMLCall(_pL, 819, 8); }
int lua_sprite_replace(lua_State *_pL) { return DoLuaGMLCall(_pL, 820, 7); }
int lua_sprite_add_sprite(lua_State *_pL) { return DoLuaGMLCall(_pL, 821, 1); }
int lua_sprite_replace_sprite(lua_State *_pL) { return DoLuaGMLCall(_pL, 822, 2); }
int lua_sprite_save_strip(lua_State *_pL) { return DoLuaGMLCall(_pL, 823, 2); }
int lua_sprite_delete(lua_State *_pL) { return DoLuaGMLCall(_pL, 824, 1); }
int lua_sprite_duplicate(lua_State *_pL) { return DoLuaGMLCall(_pL, 825, 1); }
int lua_sprite_assign(lua_State *_pL) { return DoLuaGMLCall(_pL, 826, 2); }
int lua_sprite_merge(lua_State *_pL) { return DoLuaGMLCall(_pL, 827, 2); }
int lua_sprite_save(lua_State *_pL) { return DoLuaGMLCall(_pL, 828, 3); }
int lua_sprite_prefetch(lua_State *_pL) { return DoLuaGMLCall(_pL, 829, 1); }
int lua_sprite_prefetch_multi(lua_State *_pL) { return DoLuaGMLCall(_pL, 830, 1); }
int lua_sprite_flush(lua_State *_pL) { return DoLuaGMLCall(_pL, 831, 1); }
int lua_sprite_flush_multi(lua_State *_pL) { return DoLuaGMLCall(_pL, 832, 1); }
int lua_sprite_set_speed(lua_State *_pL) { return DoLuaGMLCall(_pL, 833, 3); }
int lua_sprite_get_speed_type(lua_State *_pL) { return DoLuaGMLCall(_pL, 834, 1); }
int lua_sprite_get_speed(lua_State *_pL) { return DoLuaGMLCall(_pL, 835, 1); }
int lua_background_name(lua_State *_pL) { return DoLuaGMLCall(_pL, 836, 1); }
int lua_background_exists(lua_State *_pL) { return DoLuaGMLCall(_pL, 837, 1); }
int lua_background_get_name(lua_State *_pL) { return DoLuaGMLCall(_pL, 838, 1); }
int lua_background_get_width(lua_State *_pL) { return DoLuaGMLCall(_pL, 839, 1); }
int lua_background_get_height(lua_State *_pL) { return DoLuaGMLCall(_pL, 840, 1); }
int lua_background_get_transparent(lua_State *_pL) { return DoLuaGMLCall(_pL, 841, 1); }
int lua_background_get_smooth(lua_State *_pL) { return DoLuaGMLCall(_pL, 842, 1); }
int lua_background_get_preload(lua_State *_pL) { return DoLuaGMLCall(_pL, 843, 1); }
int lua_background_set_alpha_from_background(lua_State *_pL) { return DoLuaGMLCall(_pL, 844, 2); }
int lua_background_create_color(lua_State *_pL) { return DoLuaGMLCall(_pL, 845, 3); }
int lua_background_create_colour(lua_State *_pL) { return DoLuaGMLCall(_pL, 846, 3); }
int lua_background_replace(lua_State *_pL) { return DoLuaGMLCall(_pL, 847, 4); }
int lua_background_create_from_screen(lua_State *_pL) { return DoLuaGMLCall(_pL, 848, 6); }
int lua_background_create_from_surface(lua_State *_pL) { return DoLuaGMLCall(_pL, 849, 7); }
int lua_background_create_gradient(lua_State *_pL) { return DoLuaGMLCall(_pL, 850, 5); }
int lua_background_add(lua_State *_pL) { return DoLuaGMLCall(_pL, 851, 3); }
int lua_background_add_background(lua_State *_pL) { return DoLuaGMLCall(_pL, 852, 1); }
int lua_background_replace_background(lua_State *_pL) { return DoLuaGMLCall(_pL, 853, 2); }
int lua_background_delete(lua_State *_pL) { return DoLuaGMLCall(_pL, 854, 1); }
int lua_background_duplicate(lua_State *_pL) { return DoLuaGMLCall(_pL, 855, 1); }
int lua_background_assign(lua_State *_pL) { return DoLuaGMLCall(_pL, 856, 2); }
int lua_background_save(lua_State *_pL) { return DoLuaGMLCall(_pL, 857, 2); }
int lua_background_prefetch(lua_State *_pL) { return DoLuaGMLCall(_pL, 858, 1); }
int lua_background_prefetch_multi(lua_State *_pL) { return DoLuaGMLCall(_pL, 859, 1); }
int lua_background_flush(lua_State *_pL) { return DoLuaGMLCall(_pL, 860, 1); }
int lua_background_flush_multi(lua_State *_pL) { return DoLuaGMLCall(_pL, 861, 1); }
int lua_texture_is_ready(lua_State *_pL) { return DoLuaGMLCall(_pL, 862, 1); }
int lua_texture_prefetch(lua_State *_pL) { return DoLuaGMLCall(_pL, 863, 1); }
int lua_texture_flush(lua_State *_pL) { return DoLuaGMLCall(_pL, 864, 1); }
int lua_texturegroup_get_textures(lua_State *_pL) { return DoLuaGMLCall(_pL, 865, 1); }
int lua_texturegroup_get_sprites(lua_State *_pL) { return DoLuaGMLCall(_pL, 866, 1); }
int lua_texturegroup_get_fonts(lua_State *_pL) { return DoLuaGMLCall(_pL, 867, 1); }
int lua_texturegroup_get_tilesets(lua_State *_pL) { return DoLuaGMLCall(_pL, 868, 1); }
int lua_texture_debug_messages(lua_State *_pL) { return DoLuaGMLCall(_pL, 869, 1); }
int lua_sound_name(lua_State *_pL) { return DoLuaGMLCall(_pL, 870, 1); }
int lua_sound_exists(lua_State *_pL) { return DoLuaGMLCall(_pL, 871, 1); }
int lua_sound_get_name(lua_State *_pL) { return DoLuaGMLCall(_pL, 872, 1); }
int lua_sound_get_kind(lua_State *_pL) { return DoLuaGMLCall(_pL, 873, 1); }
int lua_sound_get_preload(lua_State *_pL) { return DoLuaGMLCall(_pL, 874, 1); }
int lua_sound_discard(lua_State *_pL) { return DoLuaGMLCall(_pL, 875, 1); }
int lua_sound_restore(lua_State *_pL) { return DoLuaGMLCall(_pL, 876, 1); }
int lua_sound_add(lua_State *_pL) { return DoLuaGMLCall(_pL, 877, 3); }
int lua_sound_replace(lua_State *_pL) { return DoLuaGMLCall(_pL, 878, 4); }
int lua_sound_delete(lua_State *_pL) { return DoLuaGMLCall(_pL, 879, 1); }
int lua_audio_delete(lua_State *_pL) { return DoLuaGMLCall(_pL, 880, 1); }
int lua_font_name(lua_State *_pL) { return DoLuaGMLCall(_pL, 881, 1); }
int lua_font_exists(lua_State *_pL) { return DoLuaGMLCall(_pL, 882, 1); }
int lua_font_get_name(lua_State *_pL) { return DoLuaGMLCall(_pL, 883, 1); }
int lua_font_get_fontname(lua_State *_pL) { return DoLuaGMLCall(_pL, 884, 1); }
int lua_font_get_size(lua_State *_pL) { return DoLuaGMLCall(_pL, 885, 1); }
int lua_font_get_bold(lua_State *_pL) { return DoLuaGMLCall(_pL, 886, 1); }
int lua_font_get_italic(lua_State *_pL) { return DoLuaGMLCall(_pL, 887, 1); }
int lua_font_get_first(lua_State *_pL) { return DoLuaGMLCall(_pL, 888, 1); }
int lua_font_get_last(lua_State *_pL) { return DoLuaGMLCall(_pL, 889, 1); }
int lua_font_add_enable_aa(lua_State *_pL) { return DoLuaGMLCall(_pL, 890, 1); }
int lua_font_add_get_enable_aa(lua_State *_pL) { return DoLuaGMLCall(_pL, 891, 0); }
int lua_font_add(lua_State *_pL) { return DoLuaGMLCall(_pL, 892, 6); }
int lua_font_add_sprite(lua_State *_pL) { return DoLuaGMLCall(_pL, 893, 4); }
int lua_font_add_sprite_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 894, 4); }
int lua_font_replace_sprite(lua_State *_pL) { return DoLuaGMLCall(_pL, 895, 5); }
int lua_font_replace_sprite_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 896, 5); }
int lua_font_delete(lua_State *_pL) { return DoLuaGMLCall(_pL, 897, 1); }
int lua_font_set_dynamic_texture_size(lua_State *_pL) { return DoLuaGMLCall(_pL, 898, 1); }
int lua_font_get_dynamic_texture_size(lua_State *_pL) { return DoLuaGMLCall(_pL, 899, 0); }
int lua_script_exists(lua_State *_pL) { return DoLuaGMLCall(_pL, 900, 1); }
int lua_script_get_name(lua_State *_pL) { return DoLuaGMLCall(_pL, 901, 1); }
int lua_script_get_text(lua_State *_pL) { return DoLuaGMLCall(_pL, 902, 1); }
int lua_script_execute(lua_State *_pL) { return DoLuaGMLCall(_pL, 903, -1); }
int lua_path_name(lua_State *_pL) { return DoLuaGMLCall(_pL, 904, 1); }
int lua_path_exists(lua_State *_pL) { return DoLuaGMLCall(_pL, 905, 1); }
int lua_path_get_name(lua_State *_pL) { return DoLuaGMLCall(_pL, 906, 1); }
int lua_path_get_length(lua_State *_pL) { return DoLuaGMLCall(_pL, 907, 1); }
int lua_path_get_time(lua_State *_pL) { return DoLuaGMLCall(_pL, 908, 2); }
int lua_path_get_kind(lua_State *_pL) { return DoLuaGMLCall(_pL, 909, 1); }
int lua_path_get_closed(lua_State *_pL) { return DoLuaGMLCall(_pL, 910, 1); }
int lua_path_get_precision(lua_State *_pL) { return DoLuaGMLCall(_pL, 911, 1); }
int lua_path_get_number(lua_State *_pL) { return DoLuaGMLCall(_pL, 912, 1); }
int lua_path_get_point_x(lua_State *_pL) { return DoLuaGMLCall(_pL, 913, 2); }
int lua_path_get_point_y(lua_State *_pL) { return DoLuaGMLCall(_pL, 914, 2); }
int lua_path_get_point_speed(lua_State *_pL) { return DoLuaGMLCall(_pL, 915, 2); }
int lua_path_get_x(lua_State *_pL) { return DoLuaGMLCall(_pL, 916, 2); }
int lua_path_get_y(lua_State *_pL) { return DoLuaGMLCall(_pL, 917, 2); }
int lua_path_get_speed(lua_State *_pL) { return DoLuaGMLCall(_pL, 918, 2); }
int lua_path_set_kind(lua_State *_pL) { return DoLuaGMLCall(_pL, 919, 2); }
int lua_path_set_closed(lua_State *_pL) { return DoLuaGMLCall(_pL, 920, 2); }
int lua_path_set_precision(lua_State *_pL) { return DoLuaGMLCall(_pL, 921, 2); }
int lua_path_add(lua_State *_pL) { return DoLuaGMLCall(_pL, 922, 0); }
int lua_path_duplicate(lua_State *_pL) { return DoLuaGMLCall(_pL, 923, 1); }
int lua_path_assign(lua_State *_pL) { return DoLuaGMLCall(_pL, 924, 2); }
int lua_path_append(lua_State *_pL) { return DoLuaGMLCall(_pL, 925, 2); }
int lua_path_delete(lua_State *_pL) { return DoLuaGMLCall(_pL, 926, 1); }
int lua_path_add_point(lua_State *_pL) { return DoLuaGMLCall(_pL, 927, 4); }
int lua_path_insert_point(lua_State *_pL) { return DoLuaGMLCall(_pL, 928, 5); }
int lua_path_change_point(lua_State *_pL) { return DoLuaGMLCall(_pL, 929, 5); }
int lua_path_delete_point(lua_State *_pL) { return DoLuaGMLCall(_pL, 930, 2); }
int lua_path_clear_points(lua_State *_pL) { return DoLuaGMLCall(_pL, 931, 1); }
int lua_path_reverse(lua_State *_pL) { return DoLuaGMLCall(_pL, 932, 1); }
int lua_path_mirror(lua_State *_pL) { return DoLuaGMLCall(_pL, 933, 1); }
int lua_path_flip(lua_State *_pL) { return DoLuaGMLCall(_pL, 934, 1); }
int lua_path_rotate(lua_State *_pL) { return DoLuaGMLCall(_pL, 935, 2); }
int lua_path_rescale(lua_State *_pL) { return DoLuaGMLCall(_pL, 936, 3); }
int lua_path_shift(lua_State *_pL) { return DoLuaGMLCall(_pL, 937, 3); }
int lua_timeline_name(lua_State *_pL) { return DoLuaGMLCall(_pL, 938, 1); }
int lua_timeline_exists(lua_State *_pL) { return DoLuaGMLCall(_pL, 939, 1); }
int lua_timeline_get_name(lua_State *_pL) { return DoLuaGMLCall(_pL, 940, 1); }
int lua_timeline_add(lua_State *_pL) { return DoLuaGMLCall(_pL, 941, 0); }
int lua_timeline_delete(lua_State *_pL) { return DoLuaGMLCall(_pL, 942, 1); }
int lua_timeline_moment_clear(lua_State *_pL) { return DoLuaGMLCall(_pL, 943, 2); }
int lua_timeline_clear(lua_State *_pL) { return DoLuaGMLCall(_pL, 944, 1); }
int lua_timeline_moment_add(lua_State *_pL) { return DoLuaGMLCall(_pL, 945, 3); }
int lua_timeline_moment_add_script(lua_State *_pL) { return DoLuaGMLCall(_pL, 946, 3); }
int lua_timeline_size(lua_State *_pL) { return DoLuaGMLCall(_pL, 947, 1); }
int lua_timeline_max_moment(lua_State *_pL) { return DoLuaGMLCall(_pL, 948, 1); }
int lua_object_name(lua_State *_pL) { return DoLuaGMLCall(_pL, 949, 1); }
int lua_object_exists(lua_State *_pL) { return DoLuaGMLCall(_pL, 950, 1); }
int lua_object_get_name(lua_State *_pL) { return DoLuaGMLCall(_pL, 951, 1); }
int lua_object_get_sprite(lua_State *_pL) { return DoLuaGMLCall(_pL, 952, 1); }
int lua_object_get_solid(lua_State *_pL) { return DoLuaGMLCall(_pL, 953, 1); }
int lua_object_get_visible(lua_State *_pL) { return DoLuaGMLCall(_pL, 954, 1); }
int lua_object_get_persistent(lua_State *_pL) { return DoLuaGMLCall(_pL, 955, 1); }
int lua_object_get_mask(lua_State *_pL) { return DoLuaGMLCall(_pL, 956, 1); }
int lua_object_get_parent(lua_State *_pL) { return DoLuaGMLCall(_pL, 957, 1); }
int lua_object_get_physics(lua_State *_pL) { return DoLuaGMLCall(_pL, 958, 1); }
int lua_object_is_ancestor(lua_State *_pL) { return DoLuaGMLCall(_pL, 959, 2); }
int lua_object_set_sprite(lua_State *_pL) { return DoLuaGMLCall(_pL, 960, 2); }
int lua_object_set_solid(lua_State *_pL) { return DoLuaGMLCall(_pL, 961, 2); }
int lua_object_set_visible(lua_State *_pL) { return DoLuaGMLCall(_pL, 962, 2); }
int lua_object_set_persistent(lua_State *_pL) { return DoLuaGMLCall(_pL, 963, 2); }
int lua_object_set_mask(lua_State *_pL) { return DoLuaGMLCall(_pL, 964, 2); }
int lua_object_set_parent(lua_State *_pL) { return DoLuaGMLCall(_pL, 965, 2); }
int lua_object_set_collisions(lua_State *_pL) { return DoLuaGMLCall(_pL, 966, 2); }
int lua_object_add(lua_State *_pL) { return DoLuaGMLCall(_pL, 967, 0); }
int lua_object_delete(lua_State *_pL) { return DoLuaGMLCall(_pL, 968, 1); }
int lua_object_event_clear(lua_State *_pL) { return DoLuaGMLCall(_pL, 969, 3); }
int lua_object_event_add(lua_State *_pL) { return DoLuaGMLCall(_pL, 970, 4); }
int lua_room_name(lua_State *_pL) { return DoLuaGMLCall(_pL, 971, 1); }
int lua_room_exists(lua_State *_pL) { return DoLuaGMLCall(_pL, 972, 1); }
int lua_room_get_name(lua_State *_pL) { return DoLuaGMLCall(_pL, 973, 1); }
int lua_room_set_width(lua_State *_pL) { return DoLuaGMLCall(_pL, 974, 2); }
int lua_room_set_height(lua_State *_pL) { return DoLuaGMLCall(_pL, 975, 2); }
int lua_room_set_caption(lua_State *_pL) { return DoLuaGMLCall(_pL, 976, 2); }
int lua_room_set_persistent(lua_State *_pL) { return DoLuaGMLCall(_pL, 977, 2); }
int lua_room_set_code(lua_State *_pL) { return DoLuaGMLCall(_pL, 978, 2); }
int lua_room_set_background_color(lua_State *_pL) { return DoLuaGMLCall(_pL, 979, 3); }
int lua_room_set_background_colour(lua_State *_pL) { return DoLuaGMLCall(_pL, 980, 3); }
int lua_room_set_background(lua_State *_pL) { return DoLuaGMLCall(_pL, 981, 12); }
int lua_room_set_viewport(lua_State *_pL) { return DoLuaGMLCall(_pL, 982, 7); }
int lua_room_get_viewport(lua_State *_pL) { return DoLuaGMLCall(_pL, 983, 2); }
int lua_room_set_view_enabled(lua_State *_pL) { return DoLuaGMLCall(_pL, 984, 2); }
int lua_room_add(lua_State *_pL) { return DoLuaGMLCall(_pL, 985, 0); }
int lua_room_duplicate(lua_State *_pL) { return DoLuaGMLCall(_pL, 986, 1); }
int lua_room_assign(lua_State *_pL) { return DoLuaGMLCall(_pL, 987, 2); }
int lua_room_instance_add(lua_State *_pL) { return DoLuaGMLCall(_pL, 988, 4); }
int lua_room_instance_clear(lua_State *_pL) { return DoLuaGMLCall(_pL, 989, 1); }
int lua_room_tile_add(lua_State *_pL) { return DoLuaGMLCall(_pL, 990, 9); }
int lua_room_tile_add_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 991, 12); }
int lua_room_tile_clear(lua_State *_pL) { return DoLuaGMLCall(_pL, 992, 1); }
int lua_room_get_camera(lua_State *_pL) { return DoLuaGMLCall(_pL, 993, 2); }
int lua_room_set_camera(lua_State *_pL) { return DoLuaGMLCall(_pL, 994, 3); }
int lua_asset_get_index(lua_State *_pL) { return DoLuaGMLCall(_pL, 995, 1); }
int lua_asset_get_type(lua_State *_pL) { return DoLuaGMLCall(_pL, 996, 1); }
int lua_splash_set_caption(lua_State *_pL) { return DoLuaGMLCall(_pL, 997, 1); }
int lua_splash_set_fullscreen(lua_State *_pL) { return DoLuaGMLCall(_pL, 998, 1); }
int lua_splash_set_border(lua_State *_pL) { return DoLuaGMLCall(_pL, 999, 1); }
int lua_splash_set_size(lua_State *_pL) { return DoLuaGMLCall(_pL, 1000, 2); }
int lua_splash_set_adapt(lua_State *_pL) { return DoLuaGMLCall(_pL, 1001, 1); }
int lua_splash_set_top(lua_State *_pL) { return DoLuaGMLCall(_pL, 1002, 1); }
int lua_splash_set_color(lua_State *_pL) { return DoLuaGMLCall(_pL, 1003, 1); }
int lua_splash_set_main(lua_State *_pL) { return DoLuaGMLCall(_pL, 1004, 1); }
int lua_splash_set_scale(lua_State *_pL) { return DoLuaGMLCall(_pL, 1005, 1); }
int lua_splash_set_cursor(lua_State *_pL) { return DoLuaGMLCall(_pL, 1006, 1); }
int lua_splash_set_interrupt(lua_State *_pL) { return DoLuaGMLCall(_pL, 1007, 1); }
int lua_splash_set_stop_key(lua_State *_pL) { return DoLuaGMLCall(_pL, 1008, 1); }
int lua_splash_set_stop_mouse(lua_State *_pL) { return DoLuaGMLCall(_pL, 1009, 1); }
int lua_splash_show_video(lua_State *_pL) { return DoLuaGMLCall(_pL, 1010, 2); }
int lua_splash_show_image(lua_State *_pL) { return DoLuaGMLCall(_pL, 1011, 2); }
int lua_splash_show_text(lua_State *_pL) { return DoLuaGMLCall(_pL, 1012, 2); }
int lua_show_image(lua_State *_pL) { return DoLuaGMLCall(_pL, 1013, 3); }
int lua_show_video(lua_State *_pL) { return DoLuaGMLCall(_pL, 1014, 3); }
int lua_show_text(lua_State *_pL) { return DoLuaGMLCall(_pL, 1015, 4); }
int lua_show_message(lua_State *_pL) { return DoLuaGMLCall(_pL, 1016, 1); }
int lua_show_question(lua_State *_pL) { return DoLuaGMLCall(_pL, 1017, 1); }
int lua_show_message_async(lua_State *_pL) { return DoLuaGMLCall(_pL, 1018, 1); }
int lua_show_question_async(lua_State *_pL) { return DoLuaGMLCall(_pL, 1019, 1); }
int lua_show_error(lua_State *_pL) { return DoLuaGMLCall(_pL, 1020, 2); }
int lua_show_info(lua_State *_pL) { return DoLuaGMLCall(_pL, 1021, 0); }
int lua_load_info(lua_State *_pL) { return DoLuaGMLCall(_pL, 1022, 1); }
int lua_highscore_show(lua_State *_pL) { return DoLuaGMLCall(_pL, 1023, 1); }
int lua_highscore_set_background(lua_State *_pL) { return DoLuaGMLCall(_pL, 1024, 1); }
int lua_highscore_set_border(lua_State *_pL) { return DoLuaGMLCall(_pL, 1025, 1); }
int lua_highscore_set_font(lua_State *_pL) { return DoLuaGMLCall(_pL, 1026, 3); }
int lua_highscore_set_strings(lua_State *_pL) { return DoLuaGMLCall(_pL, 1027, 3); }
int lua_highscore_set_colors(lua_State *_pL) { return DoLuaGMLCall(_pL, 1028, 3); }
int lua_highscore_show_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 1029, 7); }
int lua_highscore_clear(lua_State *_pL) { return DoLuaGMLCall(_pL, 1030, 0); }
int lua_highscore_add(lua_State *_pL) { return DoLuaGMLCall(_pL, 1031, 2); }
int lua_highscore_add_current(lua_State *_pL) { return DoLuaGMLCall(_pL, 1032, 0); }
int lua_highscore_value(lua_State *_pL) { return DoLuaGMLCall(_pL, 1033, 1); }
int lua_highscore_name(lua_State *_pL) { return DoLuaGMLCall(_pL, 1034, 1); }
int lua_draw_highscore(lua_State *_pL) { return DoLuaGMLCall(_pL, 1035, 4); }
int lua_show_message_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 1036, 4); }
int lua_message_background(lua_State *_pL) { return DoLuaGMLCall(_pL, 1037, 1); }
int lua_message_button(lua_State *_pL) { return DoLuaGMLCall(_pL, 1038, 1); }
int lua_message_alpha(lua_State *_pL) { return DoLuaGMLCall(_pL, 1039, 1); }
int lua_message_text_font(lua_State *_pL) { return DoLuaGMLCall(_pL, 1040, 4); }
int lua_message_button_font(lua_State *_pL) { return DoLuaGMLCall(_pL, 1041, 4); }
int lua_message_input_font(lua_State *_pL) { return DoLuaGMLCall(_pL, 1042, 4); }
int lua_message_mouse_color(lua_State *_pL) { return DoLuaGMLCall(_pL, 1043, 1); }
int lua_message_input_color(lua_State *_pL) { return DoLuaGMLCall(_pL, 1044, 1); }
int lua_message_position(lua_State *_pL) { return DoLuaGMLCall(_pL, 1045, 2); }
int lua_message_size(lua_State *_pL) { return DoLuaGMLCall(_pL, 1046, 2); }
int lua_message_caption(lua_State *_pL) { return DoLuaGMLCall(_pL, 1047, 2); }
int lua_show_menu(lua_State *_pL) { return DoLuaGMLCall(_pL, 1048, 2); }
int lua_show_menu_pos(lua_State *_pL) { return DoLuaGMLCall(_pL, 1049, 4); }
int lua_get_integer(lua_State *_pL) { return DoLuaGMLCall(_pL, 1050, 2); }
int lua_get_integer_async(lua_State *_pL) { return DoLuaGMLCall(_pL, 1051, 2); }
int lua_get_string(lua_State *_pL) { return DoLuaGMLCall(_pL, 1052, 2); }
int lua_get_string_async(lua_State *_pL) { return DoLuaGMLCall(_pL, 1053, 2); }
int lua_get_login_async(lua_State *_pL) { return DoLuaGMLCall(_pL, 1054, 2); }
int lua_get_color(lua_State *_pL) { return DoLuaGMLCall(_pL, 1055, 1); }
int lua_get_open_filename(lua_State *_pL) { return DoLuaGMLCall(_pL, 1056, 2); }
int lua_get_save_filename(lua_State *_pL) { return DoLuaGMLCall(_pL, 1057, 2); }
int lua_get_open_filename_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 1058, 4); }
int lua_get_save_filename_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 1059, 4); }
int lua_get_directory(lua_State *_pL) { return DoLuaGMLCall(_pL, 1060, 1); }
int lua_get_directory_alt(lua_State *_pL) { return DoLuaGMLCall(_pL, 1061, 2); }
int lua_keyboard_get_numlock(lua_State *_pL) { return DoLuaGMLCall(_pL, 1062, 0); }
int lua_keyboard_set_numlock(lua_State *_pL) { return DoLuaGMLCall(_pL, 1063, 1); }
int lua_keyboard_key_press(lua_State *_pL) { return DoLuaGMLCall(_pL, 1064, 1); }
int lua_keyboard_key_release(lua_State *_pL) { return DoLuaGMLCall(_pL, 1065, 1); }
int lua_keyboard_set_map(lua_State *_pL) { return DoLuaGMLCall(_pL, 1066, 2); }
int lua_keyboard_get_map(lua_State *_pL) { return DoLuaGMLCall(_pL, 1067, 1); }
int lua_keyboard_unset_map(lua_State *_pL) { return DoLuaGMLCall(_pL, 1068, 0); }
int lua_keyboard_check(lua_State *_pL) { return DoLuaGMLCall(_pL, 1069, 1); }
int lua_keyboard_check_pressed(lua_State *_pL) { return DoLuaGMLCall(_pL, 1070, 1); }
int lua_keyboard_check_released(lua_State *_pL) { return DoLuaGMLCall(_pL, 1071, 1); }
int lua_keyboard_check_direct(lua_State *_pL) { return DoLuaGMLCall(_pL, 1072, 1); }
int lua_mouse_check_button(lua_State *_pL) { return DoLuaGMLCall(_pL, 1073, 1); }
int lua_mouse_check_button_pressed(lua_State *_pL) { return DoLuaGMLCall(_pL, 1074, 1); }
int lua_mouse_check_button_released(lua_State *_pL) { return DoLuaGMLCall(_pL, 1075, 1); }
int lua_mouse_wheel_up(lua_State *_pL) { return DoLuaGMLCall(_pL, 1076, 0); }
int lua_mouse_wheel_down(lua_State *_pL) { return DoLuaGMLCall(_pL, 1077, 0); }
int lua_keyboard_virtual_show(lua_State *_pL) { return DoLuaGMLCall(_pL, 1078, 4); }
int lua_keyboard_virtual_hide(lua_State *_pL) { return DoLuaGMLCall(_pL, 1079, 0); }
int lua_keyboard_virtual_status(lua_State *_pL) { return DoLuaGMLCall(_pL, 1080, 0); }
int lua_keyboard_virtual_height(lua_State *_pL) { return DoLuaGMLCall(_pL, 1081, 0); }
int lua_keyboard_clear(lua_State *_pL) { return DoLuaGMLCall(_pL, 1082, 1); }
int lua_mouse_clear(lua_State *_pL) { return DoLuaGMLCall(_pL, 1083, 1); }
int lua_io_clear(lua_State *_pL) { return DoLuaGMLCall(_pL, 1084, 0); }
int lua_io_handle(lua_State *_pL) { return DoLuaGMLCall(_pL, 1085, 0); }
int lua_device_mouse_dbclick_enable(lua_State *_pL) { return DoLuaGMLCall(_pL, 1086, 0); }
int lua_keyboard_wait(lua_State *_pL) { return DoLuaGMLCall(_pL, 1087, 0); }
int lua_mouse_wait(lua_State *_pL) { return DoLuaGMLCall(_pL, 1088, 0); }
int lua_browser_input_capture(lua_State *_pL) { return DoLuaGMLCall(_pL, 1089, 1); }
int lua_gpio_set(lua_State *_pL) { return DoLuaGMLCall(_pL, 1090, 2); }
int lua_gpio_clear(lua_State *_pL) { return DoLuaGMLCall(_pL, 1091, 1); }
int lua_gpio_get(lua_State *_pL) { return DoLuaGMLCall(_pL, 1092, 1); }
int lua_gpio_set_mode(lua_State *_pL) { return DoLuaGMLCall(_pL, 1093, 2); }
int lua_F_GPIO_Set_Function(lua_State *_pL) { return DoLuaGMLCall(_pL, 1094, 2); }
int lua_gesture_drag_time(lua_State *_pL) { return DoLuaGMLCall(_pL, 1095, 1); }
int lua_gesture_drag_distance(lua_State *_pL) { return DoLuaGMLCall(_pL, 1096, 1); }
int lua_gesture_flick_speed(lua_State *_pL) { return DoLuaGMLCall(_pL, 1097, 1); }
int lua_gesture_double_tap_time(lua_State *_pL) { return DoLuaGMLCall(_pL, 1098, 1); }
int lua_gesture_double_tap_distance(lua_State *_pL) { return DoLuaGMLCall(_pL, 1099, 1); }
int lua_gesture_pinch_distance(lua_State *_pL) { return DoLuaGMLCall(_pL, 1100, 1); }
int lua_gesture_pinch_angle_towards(lua_State *_pL) { return DoLuaGMLCall(_pL, 1101, 1); }
int lua_gesture_pinch_angle_away(lua_State *_pL) { return DoLuaGMLCall(_pL, 1102, 1); }
int lua_gesture_rotate_time(lua_State *_pL) { return DoLuaGMLCall(_pL, 1103, 1); }
int lua_gesture_rotate_angle(lua_State *_pL) { return DoLuaGMLCall(_pL, 1104, 1); }
int lua_gesture_tap_count(lua_State *_pL) { return DoLuaGMLCall(_pL, 1105, 1); }
int lua_gesture_get_drag_time(lua_State *_pL) { return DoLuaGMLCall(_pL, 1106, 0); }
int lua_gesture_get_drag_distance(lua_State *_pL) { return DoLuaGMLCall(_pL, 1107, 0); }
int lua_gesture_get_flick_speed(lua_State *_pL) { return DoLuaGMLCall(_pL, 1108, 0); }
int lua_gesture_get_double_tap_time(lua_State *_pL) { return DoLuaGMLCall(_pL, 1109, 0); }
int lua_gesture_get_double_tap_distance(lua_State *_pL) { return DoLuaGMLCall(_pL, 1110, 0); }
int lua_gesture_get_pinch_distance(lua_State *_pL) { return DoLuaGMLCall(_pL, 1111, 0); }
int lua_gesture_get_pinch_angle_towards(lua_State *_pL) { return DoLuaGMLCall(_pL, 1112, 0); }
int lua_gesture_get_pinch_angle_away(lua_State *_pL) { return DoLuaGMLCall(_pL, 1113, 0); }
int lua_gesture_get_rotate_time(lua_State *_pL) { return DoLuaGMLCall(_pL, 1114, 0); }
int lua_gesture_get_rotate_angle(lua_State *_pL) { return DoLuaGMLCall(_pL, 1115, 0); }
int lua_gesture_get_tap_count(lua_State *_pL) { return DoLuaGMLCall(_pL, 1116, 0); }
int lua_matrix_get(lua_State *_pL) { return DoLuaGMLCall(_pL, 1117, 1); }
int lua_matrix_set(lua_State *_pL) { return DoLuaGMLCall(_pL, 1118, 2); }
int lua_matrix_build_identity(lua_State *_pL) { return DoLuaGMLCall(_pL, 1119, 0); }
int lua_matrix_build(lua_State *_pL) { return DoLuaGMLCall(_pL, 1120, 9); }
int lua_matrix_build_lookat(lua_State *_pL) { return DoLuaGMLCall(_pL, 1121, 9); }
int lua_matrix_build_projection_ortho(lua_State *_pL) { return DoLuaGMLCall(_pL, 1122, 4); }
int lua_matrix_build_projection_perspective(lua_State *_pL) { return DoLuaGMLCall(_pL, 1123, 4); }
int lua_matrix_build_projection_perspective_fov(lua_State *_pL) { return DoLuaGMLCall(_pL, 1124, 4); }
int lua_matrix_multiply(lua_State *_pL) { return DoLuaGMLCall(_pL, 1125, 2); }
int lua_matrix_transform_vertex(lua_State *_pL) { return DoLuaGMLCall(_pL, 1126, 4); }
int lua_frustum_build(lua_State *_pL) { return DoLuaGMLCall(_pL, 1127, 0); }
int lua_frustum_test_sphere(lua_State *_pL) { return DoLuaGMLCall(_pL, 1128, 4); }
int lua_draw_texture_flush(lua_State *_pL) { return DoLuaGMLCall(_pL, 1129, 0); }
int lua_draw_flush(lua_State *_pL) { return DoLuaGMLCall(_pL, 1130, 0); }
int lua_matrix_stack_push(lua_State *_pL) { return DoLuaGMLCall(_pL, 1131, 0); }
int lua_matrix_stack_pop(lua_State *_pL) { return DoLuaGMLCall(_pL, 1132, 0); }
int lua_matrix_stack_set(lua_State *_pL) { return DoLuaGMLCall(_pL, 1133, 1); }
int lua_matrix_stack_clear(lua_State *_pL) { return DoLuaGMLCall(_pL, 1134, 0); }
int lua_matrix_stack_top(lua_State *_pL) { return DoLuaGMLCall(_pL, 1135, 0); }
int lua_matrix_stack_is_empty(lua_State *_pL) { return DoLuaGMLCall(_pL, 1136, 0); }
int lua_gpu_set_blendenable(lua_State *_pL) { return DoLuaGMLCall(_pL, 1137, 1); }
int lua_gpu_set_ztestenable(lua_State *_pL) { return DoLuaGMLCall(_pL, 1138, 1); }
int lua_gpu_set_zfunc(lua_State *_pL) { return DoLuaGMLCall(_pL, 1139, 1); }
int lua_gpu_set_zwriteenable(lua_State *_pL) { return DoLuaGMLCall(_pL, 1140, 1); }
int lua_gpu_set_fog(lua_State *_pL) { return DoLuaGMLCall(_pL, 1141, -1); }
int lua_gpu_set_cullmode(lua_State *_pL) { return DoLuaGMLCall(_pL, 1142, 1); }
int lua_gpu_set_blendmode(lua_State *_pL) { return DoLuaGMLCall(_pL, 1143, 1); }
int lua_gpu_set_blendmode_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 1144, -1); }
int lua_gpu_set_blendmode_ext_sepalpha(lua_State *_pL) { return DoLuaGMLCall(_pL, 1145, -1); }
int lua_gpu_set_colorwriteenable(lua_State *_pL) { return DoLuaGMLCall(_pL, 1146, -1); }
int lua_gpu_set_colourwriteenable(lua_State *_pL) { return DoLuaGMLCall(_pL, 1147, -1); }
int lua_gpu_set_alphatestenable(lua_State *_pL) { return DoLuaGMLCall(_pL, 1148, 1); }
int lua_gpu_set_alphatestref(lua_State *_pL) { return DoLuaGMLCall(_pL, 1149, 1); }
int lua_gpu_set_alphatestfunc(lua_State *_pL) { return DoLuaGMLCall(_pL, 1150, 1); }
int lua_gpu_set_texfilter(lua_State *_pL) { return DoLuaGMLCall(_pL, 1151, 1); }
int lua_gpu_set_texfilter_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 1152, 2); }
int lua_gpu_set_texrepeat(lua_State *_pL) { return DoLuaGMLCall(_pL, 1153, 1); }
int lua_gpu_set_texrepeat_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 1154, 2); }
int lua_gpu_set_tex_filter(lua_State *_pL) { return DoLuaGMLCall(_pL, 1155, 1); }
int lua_gpu_set_tex_filter_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 1156, 2); }
int lua_gpu_set_tex_repeat(lua_State *_pL) { return DoLuaGMLCall(_pL, 1157, 1); }
int lua_gpu_set_tex_repeat_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 1158, 2); }
int lua_gpu_set_tex_mip_filter(lua_State *_pL) { return DoLuaGMLCall(_pL, 1159, 1); }
int lua_gpu_set_tex_mip_filter_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 1160, 2); }
int lua_gpu_set_tex_mip_bias(lua_State *_pL) { return DoLuaGMLCall(_pL, 1161, 1); }
int lua_gpu_set_tex_mip_bias_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 1162, 2); }
int lua_gpu_set_tex_min_mip(lua_State *_pL) { return DoLuaGMLCall(_pL, 1163, 1); }
int lua_gpu_set_tex_min_mip_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 1164, 2); }
int lua_gpu_set_tex_max_mip(lua_State *_pL) { return DoLuaGMLCall(_pL, 1165, 1); }
int lua_gpu_set_tex_max_mip_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 1166, 2); }
int lua_gpu_set_tex_max_aniso(lua_State *_pL) { return DoLuaGMLCall(_pL, 1167, 1); }
int lua_gpu_set_tex_max_aniso_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 1168, 2); }
int lua_gpu_set_tex_mip_enable(lua_State *_pL) { return DoLuaGMLCall(_pL, 1169, 1); }
int lua_gpu_set_tex_mip_enable_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 1170, 2); }
int lua_gpu_get_blendenable(lua_State *_pL) { return DoLuaGMLCall(_pL, 1171, 0); }
int lua_gpu_get_ztestenable(lua_State *_pL) { return DoLuaGMLCall(_pL, 1172, 0); }
int lua_gpu_get_zfunc(lua_State *_pL) { return DoLuaGMLCall(_pL, 1173, 0); }
int lua_gpu_get_zwriteenable(lua_State *_pL) { return DoLuaGMLCall(_pL, 1174, 0); }
int lua_gpu_get_fog(lua_State *_pL) { return DoLuaGMLCall(_pL, 1175, 0); }
int lua_gpu_get_cullmode(lua_State *_pL) { return DoLuaGMLCall(_pL, 1176, 0); }
int lua_gpu_get_blendmode(lua_State *_pL) { return DoLuaGMLCall(_pL, 1177, 0); }
int lua_gpu_get_blendmode_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 1178, 0); }
int lua_gpu_get_blendmode_ext_sepalpha(lua_State *_pL) { return DoLuaGMLCall(_pL, 1179, 0); }
int lua_gpu_get_blendmode_src(lua_State *_pL) { return DoLuaGMLCall(_pL, 1180, 0); }
int lua_gpu_get_blendmode_dest(lua_State *_pL) { return DoLuaGMLCall(_pL, 1181, 0); }
int lua_gpu_get_blendmode_srcalpha(lua_State *_pL) { return DoLuaGMLCall(_pL, 1182, 0); }
int lua_gpu_get_blendmode_destalpha(lua_State *_pL) { return DoLuaGMLCall(_pL, 1183, 0); }
int lua_gpu_get_colorwriteenable(lua_State *_pL) { return DoLuaGMLCall(_pL, 1184, 0); }
int lua_gpu_get_colourwriteenable(lua_State *_pL) { return DoLuaGMLCall(_pL, 1185, 0); }
int lua_gpu_get_alphatestenable(lua_State *_pL) { return DoLuaGMLCall(_pL, 1186, 0); }
int lua_gpu_get_alphatestref(lua_State *_pL) { return DoLuaGMLCall(_pL, 1187, 0); }
int lua_gpu_get_alphatestfunc(lua_State *_pL) { return DoLuaGMLCall(_pL, 1188, 0); }
int lua_gpu_get_texfilter(lua_State *_pL) { return DoLuaGMLCall(_pL, 1189, 0); }
int lua_gpu_get_texfilter_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 1190, 1); }
int lua_gpu_get_texrepeat(lua_State *_pL) { return DoLuaGMLCall(_pL, 1191, 0); }
int lua_gpu_get_texrepeat_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 1192, 1); }
int lua_gpu_get_tex_filter(lua_State *_pL) { return DoLuaGMLCall(_pL, 1193, 0); }
int lua_gpu_get_tex_filter_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 1194, 1); }
int lua_gpu_get_tex_repeat(lua_State *_pL) { return DoLuaGMLCall(_pL, 1195, 0); }
int lua_gpu_get_tex_repeat_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 1196, 1); }
int lua_gpu_get_tex_mip_filter(lua_State *_pL) { return DoLuaGMLCall(_pL, 1197, 0); }
int lua_gpu_get_tex_mip_filter_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 1198, 1); }
int lua_gpu_get_tex_mip_bias(lua_State *_pL) { return DoLuaGMLCall(_pL, 1199, 0); }
int lua_gpu_get_tex_mip_bias_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 1200, 1); }
int lua_gpu_get_tex_min_mip(lua_State *_pL) { return DoLuaGMLCall(_pL, 1201, 0); }
int lua_gpu_get_tex_min_mip_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 1202, 1); }
int lua_gpu_get_tex_max_mip(lua_State *_pL) { return DoLuaGMLCall(_pL, 1203, 0); }
int lua_gpu_get_tex_max_mip_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 1204, 1); }
int lua_gpu_get_tex_max_aniso(lua_State *_pL) { return DoLuaGMLCall(_pL, 1205, 1); }
int lua_gpu_get_tex_max_aniso_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 1206, 2); }
int lua_gpu_get_tex_mip_enable(lua_State *_pL) { return DoLuaGMLCall(_pL, 1207, 0); }
int lua_gpu_get_tex_mip_enable_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 1208, 1); }
int lua_gpu_push_state(lua_State *_pL) { return DoLuaGMLCall(_pL, 1209, 0); }
int lua_gpu_pop_state(lua_State *_pL) { return DoLuaGMLCall(_pL, 1210, 0); }
int lua_gpu_get_state(lua_State *_pL) { return DoLuaGMLCall(_pL, 1211, 0); }
int lua_gpu_set_state(lua_State *_pL) { return DoLuaGMLCall(_pL, 1212, 1); }
int lua_draw_light_define_ambient(lua_State *_pL) { return DoLuaGMLCall(_pL, 1213, 1); }
int lua_draw_light_define_direction(lua_State *_pL) { return DoLuaGMLCall(_pL, 1214, 5); }
int lua_draw_light_define_point(lua_State *_pL) { return DoLuaGMLCall(_pL, 1215, 6); }
int lua_draw_light_enable(lua_State *_pL) { return DoLuaGMLCall(_pL, 1216, 2); }
int lua_draw_set_lighting(lua_State *_pL) { return DoLuaGMLCall(_pL, 1217, 1); }
int lua_draw_light_get_ambient(lua_State *_pL) { return DoLuaGMLCall(_pL, 1218, 0); }
int lua_draw_light_get(lua_State *_pL) { return DoLuaGMLCall(_pL, 1219, 1); }
int lua_draw_get_lighting(lua_State *_pL) { return DoLuaGMLCall(_pL, 1220, 0); }
int lua_part_type_create(lua_State *_pL) { return DoLuaGMLCall(_pL, 1221, 0); }
int lua_part_type_destroy(lua_State *_pL) { return DoLuaGMLCall(_pL, 1222, 1); }
int lua_part_type_exists(lua_State *_pL) { return DoLuaGMLCall(_pL, 1223, 1); }
int lua_part_type_clear(lua_State *_pL) { return DoLuaGMLCall(_pL, 1224, 1); }
int lua_part_type_shape(lua_State *_pL) { return DoLuaGMLCall(_pL, 1225, 2); }
int lua_part_type_sprite(lua_State *_pL) { return DoLuaGMLCall(_pL, 1226, 5); }
int lua_part_type_size(lua_State *_pL) { return DoLuaGMLCall(_pL, 1227, 5); }
int lua_part_type_scale(lua_State *_pL) { return DoLuaGMLCall(_pL, 1228, 3); }
int lua_part_type_life(lua_State *_pL) { return DoLuaGMLCall(_pL, 1229, 3); }
int lua_part_type_step(lua_State *_pL) { return DoLuaGMLCall(_pL, 1230, 3); }
int lua_part_type_death(lua_State *_pL) { return DoLuaGMLCall(_pL, 1231, 3); }
int lua_part_type_speed(lua_State *_pL) { return DoLuaGMLCall(_pL, 1232, 5); }
int lua_part_type_direction(lua_State *_pL) { return DoLuaGMLCall(_pL, 1233, 5); }
int lua_part_type_orientation(lua_State *_pL) { return DoLuaGMLCall(_pL, 1234, 6); }
int lua_part_type_gravity(lua_State *_pL) { return DoLuaGMLCall(_pL, 1235, 3); }
int lua_part_type_color_mix(lua_State *_pL) { return DoLuaGMLCall(_pL, 1236, 3); }
int lua_part_type_color_rgb(lua_State *_pL) { return DoLuaGMLCall(_pL, 1237, 7); }
int lua_part_type_color_hsv(lua_State *_pL) { return DoLuaGMLCall(_pL, 1238, 7); }
int lua_part_type_color1(lua_State *_pL) { return DoLuaGMLCall(_pL, 1239, 2); }
int lua_part_type_color2(lua_State *_pL) { return DoLuaGMLCall(_pL, 1240, 3); }
int lua_part_type_color3(lua_State *_pL) { return DoLuaGMLCall(_pL, 1241, 4); }
int lua_part_type_color(lua_State *_pL) { return DoLuaGMLCall(_pL, 1242, 4); }
int lua_part_type_colour_mix(lua_State *_pL) { return DoLuaGMLCall(_pL, 1243, 3); }
int lua_part_type_colour_rgb(lua_State *_pL) { return DoLuaGMLCall(_pL, 1244, 7); }
int lua_part_type_colour_hsv(lua_State *_pL) { return DoLuaGMLCall(_pL, 1245, 7); }
int lua_part_type_colour1(lua_State *_pL) { return DoLuaGMLCall(_pL, 1246, 2); }
int lua_part_type_colour2(lua_State *_pL) { return DoLuaGMLCall(_pL, 1247, 3); }
int lua_part_type_colour3(lua_State *_pL) { return DoLuaGMLCall(_pL, 1248, 4); }
int lua_part_type_colour(lua_State *_pL) { return DoLuaGMLCall(_pL, 1249, 4); }
int lua_part_type_alpha1(lua_State *_pL) { return DoLuaGMLCall(_pL, 1250, 2); }
int lua_part_type_alpha2(lua_State *_pL) { return DoLuaGMLCall(_pL, 1251, 3); }
int lua_part_type_alpha3(lua_State *_pL) { return DoLuaGMLCall(_pL, 1252, 4); }
int lua_part_type_alpha(lua_State *_pL) { return DoLuaGMLCall(_pL, 1253, 4); }
int lua_part_type_blend(lua_State *_pL) { return DoLuaGMLCall(_pL, 1254, 2); }
int lua_part_system_create(lua_State *_pL) { return DoLuaGMLCall(_pL, 1255, 0); }
int lua_part_system_destroy(lua_State *_pL) { return DoLuaGMLCall(_pL, 1256, 1); }
int lua_part_system_exists(lua_State *_pL) { return DoLuaGMLCall(_pL, 1257, 1); }
int lua_part_system_clear(lua_State *_pL) { return DoLuaGMLCall(_pL, 1258, 1); }
int lua_part_system_draw_order(lua_State *_pL) { return DoLuaGMLCall(_pL, 1259, 2); }
int lua_part_system_depth(lua_State *_pL) { return DoLuaGMLCall(_pL, 1260, 2); }
int lua_part_system_position(lua_State *_pL) { return DoLuaGMLCall(_pL, 1261, 3); }
int lua_part_system_automatic_update(lua_State *_pL) { return DoLuaGMLCall(_pL, 1262, 2); }
int lua_part_system_automatic_draw(lua_State *_pL) { return DoLuaGMLCall(_pL, 1263, 2); }
int lua_part_system_update(lua_State *_pL) { return DoLuaGMLCall(_pL, 1264, 1); }
int lua_part_system_drawit(lua_State *_pL) { return DoLuaGMLCall(_pL, 1265, 1); }
int lua_part_system_create_layer(lua_State *_pL) { return DoLuaGMLCall(_pL, 1266, 2); }
int lua_part_system_get_layer(lua_State *_pL) { return DoLuaGMLCall(_pL, 1267, 1); }
int lua_part_system_layer(lua_State *_pL) { return DoLuaGMLCall(_pL, 1268, 2); }
int lua_part_particles_create(lua_State *_pL) { return DoLuaGMLCall(_pL, 1269, 5); }
int lua_part_particles_create_color(lua_State *_pL) { return DoLuaGMLCall(_pL, 1270, 6); }
int lua_part_particles_create_colour(lua_State *_pL) { return DoLuaGMLCall(_pL, 1271, 6); }
int lua_part_particles_clear(lua_State *_pL) { return DoLuaGMLCall(_pL, 1272, 1); }
int lua_part_particles_count(lua_State *_pL) { return DoLuaGMLCall(_pL, 1273, 1); }
int lua_part_emitter_create(lua_State *_pL) { return DoLuaGMLCall(_pL, 1274, 1); }
int lua_part_emitter_destroy(lua_State *_pL) { return DoLuaGMLCall(_pL, 1275, 2); }
int lua_part_emitter_destroy_all(lua_State *_pL) { return DoLuaGMLCall(_pL, 1276, 1); }
int lua_part_emitter_exists(lua_State *_pL) { return DoLuaGMLCall(_pL, 1277, 2); }
int lua_part_emitter_clear(lua_State *_pL) { return DoLuaGMLCall(_pL, 1278, 2); }
int lua_part_emitter_region(lua_State *_pL) { return DoLuaGMLCall(_pL, 1279, 8); }
int lua_part_emitter_burst(lua_State *_pL) { return DoLuaGMLCall(_pL, 1280, 4); }
int lua_part_emitter_stream(lua_State *_pL) { return DoLuaGMLCall(_pL, 1281, 4); }
int lua_effect_create_below(lua_State *_pL) { return DoLuaGMLCall(_pL, 1282, 5); }
int lua_effect_create_above(lua_State *_pL) { return DoLuaGMLCall(_pL, 1283, 5); }
int lua_effect_clear(lua_State *_pL) { return DoLuaGMLCall(_pL, 1284, 0); }
int lua_event_inherited(lua_State *_pL) { return DoLuaGMLCall(_pL, 1285, 0); }
int lua_event_perform(lua_State *_pL) { return DoLuaGMLCall(_pL, 1286, 2); }
int lua_event_user(lua_State *_pL) { return DoLuaGMLCall(_pL, 1287, 1); }
int lua_event_perform_object(lua_State *_pL) { return DoLuaGMLCall(_pL, 1288, 3); }
int lua_external_define(lua_State *_pL) { return DoLuaGMLCall(_pL, 1289, -1); }
int lua_external_call(lua_State *_pL) { return DoLuaGMLCall(_pL, 1290, -1); }
int lua_external_free(lua_State *_pL) { return DoLuaGMLCall(_pL, 1291, 1); }
int lua_external_define0(lua_State *_pL) { return DoLuaGMLCall(_pL, 1292, 3); }
int lua_external_call0(lua_State *_pL) { return DoLuaGMLCall(_pL, 1293, 1); }
int lua_external_define1(lua_State *_pL) { return DoLuaGMLCall(_pL, 1294, 4); }
int lua_external_call1(lua_State *_pL) { return DoLuaGMLCall(_pL, 1295, 2); }
int lua_external_define2(lua_State *_pL) { return DoLuaGMLCall(_pL, 1296, 5); }
int lua_external_call2(lua_State *_pL) { return DoLuaGMLCall(_pL, 1297, 3); }
int lua_external_define3(lua_State *_pL) { return DoLuaGMLCall(_pL, 1298, 6); }
int lua_external_call3(lua_State *_pL) { return DoLuaGMLCall(_pL, 1299, 4); }
int lua_external_define4(lua_State *_pL) { return DoLuaGMLCall(_pL, 1300, 7); }
int lua_external_call4(lua_State *_pL) { return DoLuaGMLCall(_pL, 1301, 5); }
int lua_external_define5(lua_State *_pL) { return DoLuaGMLCall(_pL, 1302, 3); }
int lua_external_call5(lua_State *_pL) { return DoLuaGMLCall(_pL, 1303, 6); }
int lua_external_define6(lua_State *_pL) { return DoLuaGMLCall(_pL, 1304, 3); }
int lua_external_call6(lua_State *_pL) { return DoLuaGMLCall(_pL, 1305, 7); }
int lua_external_define7(lua_State *_pL) { return DoLuaGMLCall(_pL, 1306, 3); }
int lua_external_call7(lua_State *_pL) { return DoLuaGMLCall(_pL, 1307, 8); }
int lua_external_define8(lua_State *_pL) { return DoLuaGMLCall(_pL, 1308, 3); }
int lua_external_call8(lua_State *_pL) { return DoLuaGMLCall(_pL, 1309, 9); }
int lua_window_handle(lua_State *_pL) { return DoLuaGMLCall(_pL, 1310, 0); }
int lua_window_device(lua_State *_pL) { return DoLuaGMLCall(_pL, 1311, 0); }
int lua_show_debug_message(lua_State *_pL) { return DoLuaGMLCall(_pL, 1312, 1); }
int lua_show_debug_overlay(lua_State *_pL) { return DoLuaGMLCall(_pL, 1313, 1); }
int lua_debug_event(lua_State *_pL) { return DoLuaGMLCall(_pL, 1314, 1); }
int lua_debug_get_callstack(lua_State *_pL) { return DoLuaGMLCall(_pL, 1315, 0); }
int lua_set_program_priority(lua_State *_pL) { return DoLuaGMLCall(_pL, 1316, 1); }
int lua_set_application_title(lua_State *_pL) { return DoLuaGMLCall(_pL, 1317, 1); }
int lua_gif_add_surface(lua_State *_pL) { return DoLuaGMLCall(_pL, 1318, 3); }
int lua_gif_save(lua_State *_pL) { return DoLuaGMLCall(_pL, 1319, 2); }
int lua_gif_open(lua_State *_pL) { return DoLuaGMLCall(_pL, 1320, 2); }
int lua_alarm_set(lua_State *_pL) { return DoLuaGMLCall(_pL, 1321, 2); }
int lua_alarm_get(lua_State *_pL) { return DoLuaGMLCall(_pL, 1322, 1); }
int lua_variable_global_exists(lua_State *_pL) { return DoLuaGMLCall(_pL, 1323, 1); }
int lua_variable_global_get(lua_State *_pL) { return DoLuaGMLCall(_pL, 1324, 1); }
int lua_variable_global_set(lua_State *_pL) { return DoLuaGMLCall(_pL, 1325, 2); }
int lua_variable_instance_exists(lua_State *_pL) { return DoLuaGMLCall(_pL, 1326, 2); }
int lua_variable_instance_get(lua_State *_pL) { return DoLuaGMLCall(_pL, 1327, 2); }
int lua_variable_instance_set(lua_State *_pL) { return DoLuaGMLCall(_pL, 1328, 3); }
int lua_variable_instance_get_names(lua_State *_pL) { return DoLuaGMLCall(_pL, 1329, 1); }
int lua_clipboard_has_text(lua_State *_pL) { return DoLuaGMLCall(_pL, 1330, 0); }
int lua_clipboard_set_text(lua_State *_pL) { return DoLuaGMLCall(_pL, 1331, 1); }
int lua_clipboard_get_text(lua_State *_pL) { return DoLuaGMLCall(_pL, 1332, 0); }
int lua_date_current_datetime(lua_State *_pL) { return DoLuaGMLCall(_pL, 1333, 0); }
int lua_date_current_date(lua_State *_pL) { return DoLuaGMLCall(_pL, 1334, 0); }
int lua_date_current_time(lua_State *_pL) { return DoLuaGMLCall(_pL, 1335, 0); }
int lua_date_create_datetime(lua_State *_pL) { return DoLuaGMLCall(_pL, 1336, 6); }
int lua_date_create_date(lua_State *_pL) { return DoLuaGMLCall(_pL, 1337, 3); }
int lua_date_create_time(lua_State *_pL) { return DoLuaGMLCall(_pL, 1338, 3); }
int lua_date_valid_datetime(lua_State *_pL) { return DoLuaGMLCall(_pL, 1339, 6); }
int lua_date_valid_date(lua_State *_pL) { return DoLuaGMLCall(_pL, 1340, 3); }
int lua_date_valid_time(lua_State *_pL) { return DoLuaGMLCall(_pL, 1341, 3); }
int lua_date_inc_year(lua_State *_pL) { return DoLuaGMLCall(_pL, 1342, 2); }
int lua_date_inc_month(lua_State *_pL) { return DoLuaGMLCall(_pL, 1343, 2); }
int lua_date_inc_week(lua_State *_pL) { return DoLuaGMLCall(_pL, 1344, 2); }
int lua_date_inc_day(lua_State *_pL) { return DoLuaGMLCall(_pL, 1345, 2); }
int lua_date_inc_hour(lua_State *_pL) { return DoLuaGMLCall(_pL, 1346, 2); }
int lua_date_inc_minute(lua_State *_pL) { return DoLuaGMLCall(_pL, 1347, 2); }
int lua_date_inc_second(lua_State *_pL) { return DoLuaGMLCall(_pL, 1348, 2); }
int lua_date_get_year(lua_State *_pL) { return DoLuaGMLCall(_pL, 1349, 1); }
int lua_date_get_month(lua_State *_pL) { return DoLuaGMLCall(_pL, 1350, 1); }
int lua_date_get_week(lua_State *_pL) { return DoLuaGMLCall(_pL, 1351, 1); }
int lua_date_get_day(lua_State *_pL) { return DoLuaGMLCall(_pL, 1352, 1); }
int lua_date_get_hour(lua_State *_pL) { return DoLuaGMLCall(_pL, 1353, 1); }
int lua_date_get_minute(lua_State *_pL) { return DoLuaGMLCall(_pL, 1354, 1); }
int lua_date_get_second(lua_State *_pL) { return DoLuaGMLCall(_pL, 1355, 1); }
int lua_date_get_weekday(lua_State *_pL) { return DoLuaGMLCall(_pL, 1356, 1); }
int lua_date_get_day_of_year(lua_State *_pL) { return DoLuaGMLCall(_pL, 1357, 1); }
int lua_date_get_hour_of_year(lua_State *_pL) { return DoLuaGMLCall(_pL, 1358, 1); }
int lua_date_get_minute_of_year(lua_State *_pL) { return DoLuaGMLCall(_pL, 1359, 1); }
int lua_date_get_second_of_year(lua_State *_pL) { return DoLuaGMLCall(_pL, 1360, 1); }
int lua_date_year_span(lua_State *_pL) { return DoLuaGMLCall(_pL, 1361, 2); }
int lua_date_month_span(lua_State *_pL) { return DoLuaGMLCall(_pL, 1362, 2); }
int lua_date_week_span(lua_State *_pL) { return DoLuaGMLCall(_pL, 1363, 2); }
int lua_date_day_span(lua_State *_pL) { return DoLuaGMLCall(_pL, 1364, 2); }
int lua_date_hour_span(lua_State *_pL) { return DoLuaGMLCall(_pL, 1365, 2); }
int lua_date_minute_span(lua_State *_pL) { return DoLuaGMLCall(_pL, 1366, 2); }
int lua_date_second_span(lua_State *_pL) { return DoLuaGMLCall(_pL, 1367, 2); }
int lua_date_compare_datetime(lua_State *_pL) { return DoLuaGMLCall(_pL, 1368, 2); }
int lua_date_compare_date(lua_State *_pL) { return DoLuaGMLCall(_pL, 1369, 2); }
int lua_date_compare_time(lua_State *_pL) { return DoLuaGMLCall(_pL, 1370, 2); }
int lua_date_date_of(lua_State *_pL) { return DoLuaGMLCall(_pL, 1371, 1); }
int lua_date_time_of(lua_State *_pL) { return DoLuaGMLCall(_pL, 1372, 1); }
int lua_date_datetime_string(lua_State *_pL) { return DoLuaGMLCall(_pL, 1373, 1); }
int lua_date_date_string(lua_State *_pL) { return DoLuaGMLCall(_pL, 1374, 1); }
int lua_date_time_string(lua_State *_pL) { return DoLuaGMLCall(_pL, 1375, 1); }
int lua_date_days_in_month(lua_State *_pL) { return DoLuaGMLCall(_pL, 1376, 1); }
int lua_date_days_in_year(lua_State *_pL) { return DoLuaGMLCall(_pL, 1377, 1); }
int lua_date_leap_year(lua_State *_pL) { return DoLuaGMLCall(_pL, 1378, 1); }
int lua_date_is_today(lua_State *_pL) { return DoLuaGMLCall(_pL, 1379, 1); }
int lua_date_set_timezone(lua_State *_pL) { return DoLuaGMLCall(_pL, 1380, 1); }
int lua_date_get_timezone(lua_State *_pL) { return DoLuaGMLCall(_pL, 1381, 0); }
int lua_game_set_speed(lua_State *_pL) { return DoLuaGMLCall(_pL, 1382, 2); }
int lua_game_get_speed(lua_State *_pL) { return DoLuaGMLCall(_pL, 1383, 2); }
int lua_ds_set_precision(lua_State *_pL) { return DoLuaGMLCall(_pL, 1384, 1); }
int lua_ds_exists(lua_State *_pL) { return DoLuaGMLCall(_pL, 1385, 2); }
int lua_ds_stack_create(lua_State *_pL) { return DoLuaGMLCall(_pL, 1386, 0); }
int lua_ds_stack_destroy(lua_State *_pL) { return DoLuaGMLCall(_pL, 1387, 1); }
int lua_ds_stack_clear(lua_State *_pL) { return DoLuaGMLCall(_pL, 1388, 1); }
int lua_ds_stack_copy(lua_State *_pL) { return DoLuaGMLCall(_pL, 1389, 2); }
int lua_ds_stack_size(lua_State *_pL) { return DoLuaGMLCall(_pL, 1390, 1); }
int lua_ds_stack_empty(lua_State *_pL) { return DoLuaGMLCall(_pL, 1391, 1); }
int lua_ds_stack_push(lua_State *_pL) { return DoLuaGMLCall(_pL, 1392, -1); }
int lua_ds_stack_pop(lua_State *_pL) { return DoLuaGMLCall(_pL, 1393, 1); }
int lua_ds_stack_top(lua_State *_pL) { return DoLuaGMLCall(_pL, 1394, 1); }
int lua_ds_stack_write(lua_State *_pL) { return DoLuaGMLCall(_pL, 1395, 1); }
int lua_ds_stack_read(lua_State *_pL) { return DoLuaGMLCall(_pL, 1396, 2); }
int lua_ds_queue_create(lua_State *_pL) { return DoLuaGMLCall(_pL, 1397, 0); }
int lua_ds_queue_destroy(lua_State *_pL) { return DoLuaGMLCall(_pL, 1398, 1); }
int lua_ds_queue_clear(lua_State *_pL) { return DoLuaGMLCall(_pL, 1399, 1); }
int lua_ds_queue_copy(lua_State *_pL) { return DoLuaGMLCall(_pL, 1400, 2); }
int lua_ds_queue_size(lua_State *_pL) { return DoLuaGMLCall(_pL, 1401, 1); }
int lua_ds_queue_empty(lua_State *_pL) { return DoLuaGMLCall(_pL, 1402, 1); }
int lua_ds_queue_enqueue(lua_State *_pL) { return DoLuaGMLCall(_pL, 1403, -1); }
int lua_ds_queue_dequeue(lua_State *_pL) { return DoLuaGMLCall(_pL, 1404, 1); }
int lua_ds_queue_head(lua_State *_pL) { return DoLuaGMLCall(_pL, 1405, 1); }
int lua_ds_queue_tail(lua_State *_pL) { return DoLuaGMLCall(_pL, 1406, 1); }
int lua_ds_queue_write(lua_State *_pL) { return DoLuaGMLCall(_pL, 1407, 1); }
int lua_ds_queue_read(lua_State *_pL) { return DoLuaGMLCall(_pL, 1408, 2); }
int lua_ds_list_create(lua_State *_pL) { return DoLuaGMLCall(_pL, 1409, 0); }
int lua_ds_list_destroy(lua_State *_pL) { return DoLuaGMLCall(_pL, 1410, 1); }
int lua_ds_list_clear(lua_State *_pL) { return DoLuaGMLCall(_pL, 1411, 1); }
int lua_ds_list_copy(lua_State *_pL) { return DoLuaGMLCall(_pL, 1412, 2); }
int lua_ds_list_size(lua_State *_pL) { return DoLuaGMLCall(_pL, 1413, 1); }
int lua_ds_list_empty(lua_State *_pL) { return DoLuaGMLCall(_pL, 1414, 1); }
int lua_ds_list_add(lua_State *_pL) { return DoLuaGMLCall(_pL, 1415, -1); }
int lua_ds_list_insert(lua_State *_pL) { return DoLuaGMLCall(_pL, 1416, 3); }
int lua_ds_list_replace(lua_State *_pL) { return DoLuaGMLCall(_pL, 1417, 3); }
int lua_ds_list_delete(lua_State *_pL) { return DoLuaGMLCall(_pL, 1418, 2); }
int lua_ds_list_find_index(lua_State *_pL) { return DoLuaGMLCall(_pL, 1419, 2); }
int lua_ds_list_find_value(lua_State *_pL) { return DoLuaGMLCall(_pL, 1420, 2); }
int lua_ds_list_mark_as_list(lua_State *_pL) { return DoLuaGMLCall(_pL, 1421, 2); }
int lua_ds_list_mark_as_map(lua_State *_pL) { return DoLuaGMLCall(_pL, 1422, 2); }
int lua_ds_list_sort(lua_State *_pL) { return DoLuaGMLCall(_pL, 1423, 2); }
int lua_ds_list_shuffle(lua_State *_pL) { return DoLuaGMLCall(_pL, 1424, 1); }
int lua_ds_list_write(lua_State *_pL) { return DoLuaGMLCall(_pL, 1425, 1); }
int lua_ds_list_read(lua_State *_pL) { return DoLuaGMLCall(_pL, 1426, 2); }
int lua_ds_list_set(lua_State *_pL) { return DoLuaGMLCall(_pL, 1427, 3); }
int lua_ds_list_set_post(lua_State *_pL) { return DoLuaGMLCall(_pL, 1428, 3); }
int lua_ds_list_set_pre(lua_State *_pL) { return DoLuaGMLCall(_pL, 1429, 3); }
int lua_ds_map_create(lua_State *_pL) { return DoLuaGMLCall(_pL, 1430, 0); }
int lua_ds_map_destroy(lua_State *_pL) { return DoLuaGMLCall(_pL, 1431, 1); }
int lua_ds_map_clear(lua_State *_pL) { return DoLuaGMLCall(_pL, 1432, 1); }
int lua_ds_map_copy(lua_State *_pL) { return DoLuaGMLCall(_pL, 1433, 2); }
int lua_ds_map_size(lua_State *_pL) { return DoLuaGMLCall(_pL, 1434, 1); }
int lua_ds_map_empty(lua_State *_pL) { return DoLuaGMLCall(_pL, 1435, 1); }
int lua_ds_map_add(lua_State *_pL) { return DoLuaGMLCall(_pL, 1436, 3); }
int lua_ds_map_set(lua_State *_pL) { return DoLuaGMLCall(_pL, 1437, 3); }
int lua_ds_map_set_pre(lua_State *_pL) { return DoLuaGMLCall(_pL, 1438, 3); }
int lua_ds_map_set_post(lua_State *_pL) { return DoLuaGMLCall(_pL, 1439, 3); }
int lua_ds_map_add_list(lua_State *_pL) { return DoLuaGMLCall(_pL, 1440, 3); }
int lua_ds_map_add_map(lua_State *_pL) { return DoLuaGMLCall(_pL, 1441, 3); }
int lua_ds_map_replace(lua_State *_pL) { return DoLuaGMLCall(_pL, 1442, 3); }
int lua_ds_map_replace_list(lua_State *_pL) { return DoLuaGMLCall(_pL, 1443, 3); }
int lua_ds_map_replace_map(lua_State *_pL) { return DoLuaGMLCall(_pL, 1444, 3); }
int lua_ds_map_delete(lua_State *_pL) { return DoLuaGMLCall(_pL, 1445, 2); }
int lua_ds_map_exists(lua_State *_pL) { return DoLuaGMLCall(_pL, 1446, 2); }
int lua_ds_map_find_value(lua_State *_pL) { return DoLuaGMLCall(_pL, 1447, 2); }
int lua_ds_map_find_previous(lua_State *_pL) { return DoLuaGMLCall(_pL, 1448, 2); }
int lua_ds_map_find_next(lua_State *_pL) { return DoLuaGMLCall(_pL, 1449, 2); }
int lua_ds_map_find_first(lua_State *_pL) { return DoLuaGMLCall(_pL, 1450, 1); }
int lua_ds_map_find_last(lua_State *_pL) { return DoLuaGMLCall(_pL, 1451, 1); }
int lua_ds_map_write(lua_State *_pL) { return DoLuaGMLCall(_pL, 1452, 1); }
int lua_ds_map_read(lua_State *_pL) { return DoLuaGMLCall(_pL, 1453, 2); }
int lua_ds_map_secure_save(lua_State *_pL) { return DoLuaGMLCall(_pL, 1454, 2); }
int lua_ds_map_secure_load(lua_State *_pL) { return DoLuaGMLCall(_pL, 1455, 1); }
int lua_ds_map_secure_load_buffer(lua_State *_pL) { return DoLuaGMLCall(_pL, 1456, 1); }
int lua_ds_map_secure_save_buffer(lua_State *_pL) { return DoLuaGMLCall(_pL, 1457, 2); }
int lua_ds_priority_create(lua_State *_pL) { return DoLuaGMLCall(_pL, 1458, 0); }
int lua_ds_priority_destroy(lua_State *_pL) { return DoLuaGMLCall(_pL, 1459, 1); }
int lua_ds_priority_clear(lua_State *_pL) { return DoLuaGMLCall(_pL, 1460, 1); }
int lua_ds_priority_copy(lua_State *_pL) { return DoLuaGMLCall(_pL, 1461, 2); }
int lua_ds_priority_size(lua_State *_pL) { return DoLuaGMLCall(_pL, 1462, 1); }
int lua_ds_priority_empty(lua_State *_pL) { return DoLuaGMLCall(_pL, 1463, 1); }
int lua_ds_priority_add(lua_State *_pL) { return DoLuaGMLCall(_pL, 1464, 3); }
int lua_ds_priority_change_priority(lua_State *_pL) { return DoLuaGMLCall(_pL, 1465, 3); }
int lua_ds_priority_find_priority(lua_State *_pL) { return DoLuaGMLCall(_pL, 1466, 2); }
int lua_ds_priority_delete_value(lua_State *_pL) { return DoLuaGMLCall(_pL, 1467, 2); }
int lua_ds_priority_delete_min(lua_State *_pL) { return DoLuaGMLCall(_pL, 1468, 1); }
int lua_ds_priority_find_min(lua_State *_pL) { return DoLuaGMLCall(_pL, 1469, 1); }
int lua_ds_priority_delete_max(lua_State *_pL) { return DoLuaGMLCall(_pL, 1470, 1); }
int lua_ds_priority_find_max(lua_State *_pL) { return DoLuaGMLCall(_pL, 1471, 1); }
int lua_ds_priority_write(lua_State *_pL) { return DoLuaGMLCall(_pL, 1472, 1); }
int lua_ds_priority_read(lua_State *_pL) { return DoLuaGMLCall(_pL, 1473, 2); }
int lua_ds_grid_create(lua_State *_pL) { return DoLuaGMLCall(_pL, 1474, 2); }
int lua_ds_grid_destroy(lua_State *_pL) { return DoLuaGMLCall(_pL, 1475, 1); }
int lua_ds_grid_copy(lua_State *_pL) { return DoLuaGMLCall(_pL, 1476, 2); }
int lua_ds_grid_resize(lua_State *_pL) { return DoLuaGMLCall(_pL, 1477, 3); }
int lua_ds_grid_width(lua_State *_pL) { return DoLuaGMLCall(_pL, 1478, 1); }
int lua_ds_grid_height(lua_State *_pL) { return DoLuaGMLCall(_pL, 1479, 1); }
int lua_ds_grid_clear(lua_State *_pL) { return DoLuaGMLCall(_pL, 1480, 2); }
int lua_ds_grid_set(lua_State *_pL) { return DoLuaGMLCall(_pL, 1481, 4); }
int lua_ds_grid_set_pre(lua_State *_pL) { return DoLuaGMLCall(_pL, 1482, 4); }
int lua_ds_grid_set_post(lua_State *_pL) { return DoLuaGMLCall(_pL, 1483, 4); }
int lua_ds_grid_add(lua_State *_pL) { return DoLuaGMLCall(_pL, 1484, 4); }
int lua_ds_grid_multiply(lua_State *_pL) { return DoLuaGMLCall(_pL, 1485, 4); }
int lua_ds_grid_set_region(lua_State *_pL) { return DoLuaGMLCall(_pL, 1486, 6); }
int lua_ds_grid_add_region(lua_State *_pL) { return DoLuaGMLCall(_pL, 1487, 6); }
int lua_ds_grid_multiply_region(lua_State *_pL) { return DoLuaGMLCall(_pL, 1488, 6); }
int lua_ds_grid_set_disk(lua_State *_pL) { return DoLuaGMLCall(_pL, 1489, 5); }
int lua_ds_grid_add_disk(lua_State *_pL) { return DoLuaGMLCall(_pL, 1490, 5); }
int lua_ds_grid_multiply_disk(lua_State *_pL) { return DoLuaGMLCall(_pL, 1491, 5); }
int lua_ds_grid_set_grid_region(lua_State *_pL) { return DoLuaGMLCall(_pL, 1492, 8); }
int lua_ds_grid_add_grid_region(lua_State *_pL) { return DoLuaGMLCall(_pL, 1493, 8); }
int lua_ds_grid_multiply_grid_region(lua_State *_pL) { return DoLuaGMLCall(_pL, 1494, 8); }
int lua_ds_grid_get(lua_State *_pL) { return DoLuaGMLCall(_pL, 1495, 3); }
int lua_ds_grid_get_sum(lua_State *_pL) { return DoLuaGMLCall(_pL, 1496, 5); }
int lua_ds_grid_get_max(lua_State *_pL) { return DoLuaGMLCall(_pL, 1497, 5); }
int lua_ds_grid_get_min(lua_State *_pL) { return DoLuaGMLCall(_pL, 1498, 5); }
int lua_ds_grid_get_mean(lua_State *_pL) { return DoLuaGMLCall(_pL, 1499, 5); }
int lua_ds_grid_get_disk_sum(lua_State *_pL) { return DoLuaGMLCall(_pL, 1500, 4); }
int lua_ds_grid_get_disk_max(lua_State *_pL) { return DoLuaGMLCall(_pL, 1501, 4); }
int lua_ds_grid_get_disk_min(lua_State *_pL) { return DoLuaGMLCall(_pL, 1502, 4); }
int lua_ds_grid_get_disk_mean(lua_State *_pL) { return DoLuaGMLCall(_pL, 1503, 4); }
int lua_ds_grid_value_exists(lua_State *_pL) { return DoLuaGMLCall(_pL, 1504, 6); }
int lua_ds_grid_value_x(lua_State *_pL) { return DoLuaGMLCall(_pL, 1505, 6); }
int lua_ds_grid_value_y(lua_State *_pL) { return DoLuaGMLCall(_pL, 1506, 6); }
int lua_ds_grid_value_disk_exists(lua_State *_pL) { return DoLuaGMLCall(_pL, 1507, 5); }
int lua_ds_grid_value_disk_x(lua_State *_pL) { return DoLuaGMLCall(_pL, 1508, 5); }
int lua_ds_grid_value_disk_y(lua_State *_pL) { return DoLuaGMLCall(_pL, 1509, 5); }
int lua_ds_grid_shuffle(lua_State *_pL) { return DoLuaGMLCall(_pL, 1510, 1); }
int lua_ds_grid_write(lua_State *_pL) { return DoLuaGMLCall(_pL, 1511, 1); }
int lua_ds_grid_read(lua_State *_pL) { return DoLuaGMLCall(_pL, 1512, 2); }
int lua_ds_grid_sort(lua_State *_pL) { return DoLuaGMLCall(_pL, 1513, 3); }
int lua_sound_play(lua_State *_pL) { return DoLuaGMLCall(_pL, 1514, 1); }
int lua_sound_loop(lua_State *_pL) { return DoLuaGMLCall(_pL, 1515, 1); }
int lua_sound_stop(lua_State *_pL) { return DoLuaGMLCall(_pL, 1516, 1); }
int lua_sound_stop_all(lua_State *_pL) { return DoLuaGMLCall(_pL, 1517, 0); }
int lua_sound_isplaying(lua_State *_pL) { return DoLuaGMLCall(_pL, 1518, 1); }
int lua_sound_volume(lua_State *_pL) { return DoLuaGMLCall(_pL, 1519, 2); }
int lua_sound_fade(lua_State *_pL) { return DoLuaGMLCall(_pL, 1520, 3); }
int lua_sound_pan(lua_State *_pL) { return DoLuaGMLCall(_pL, 1521, 2); }
int lua_sound_background_tempo(lua_State *_pL) { return DoLuaGMLCall(_pL, 1522, 1); }
int lua_sound_global_volume(lua_State *_pL) { return DoLuaGMLCall(_pL, 1523, 1); }
int lua_sound_set_search_directory(lua_State *_pL) { return DoLuaGMLCall(_pL, 1524, 1); }
int lua_sound_effect_set(lua_State *_pL) { return DoLuaGMLCall(_pL, 1525, 2); }
int lua_sound_effect_chorus(lua_State *_pL) { return DoLuaGMLCall(_pL, 1526, 8); }
int lua_sound_effect_compressor(lua_State *_pL) { return DoLuaGMLCall(_pL, 1527, 7); }
int lua_sound_effect_echo(lua_State *_pL) { return DoLuaGMLCall(_pL, 1528, 6); }
int lua_sound_effect_flanger(lua_State *_pL) { return DoLuaGMLCall(_pL, 1529, 8); }
int lua_sound_effect_gargle(lua_State *_pL) { return DoLuaGMLCall(_pL, 1530, 3); }
int lua_sound_effect_equalizer(lua_State *_pL) { return DoLuaGMLCall(_pL, 1531, 4); }
int lua_sound_effect_reverb(lua_State *_pL) { return DoLuaGMLCall(_pL, 1532, 5); }
int lua_sound_3d_set_sound_position(lua_State *_pL) { return DoLuaGMLCall(_pL, 1533, 4); }
int lua_sound_3d_set_sound_velocity(lua_State *_pL) { return DoLuaGMLCall(_pL, 1534, 4); }
int lua_sound_3d_set_sound_distance(lua_State *_pL) { return DoLuaGMLCall(_pL, 1535, 3); }
int lua_sound_3d_set_sound_cone(lua_State *_pL) { return DoLuaGMLCall(_pL, 1536, 7); }
int lua_cd_init(lua_State *_pL) { return DoLuaGMLCall(_pL, 1537, 0); }
int lua_cd_present(lua_State *_pL) { return DoLuaGMLCall(_pL, 1538, 0); }
int lua_cd_number(lua_State *_pL) { return DoLuaGMLCall(_pL, 1539, 0); }
int lua_cd_playing(lua_State *_pL) { return DoLuaGMLCall(_pL, 1540, 0); }
int lua_cd_paused(lua_State *_pL) { return DoLuaGMLCall(_pL, 1541, 0); }
int lua_cd_track(lua_State *_pL) { return DoLuaGMLCall(_pL, 1542, 0); }
int lua_cd_length(lua_State *_pL) { return DoLuaGMLCall(_pL, 1543, 0); }
int lua_cd_track_length(lua_State *_pL) { return DoLuaGMLCall(_pL, 1544, 1); }
int lua_cd_position(lua_State *_pL) { return DoLuaGMLCall(_pL, 1545, 0); }
int lua_cd_track_position(lua_State *_pL) { return DoLuaGMLCall(_pL, 1546, 0); }
int lua_cd_play(lua_State *_pL) { return DoLuaGMLCall(_pL, 1547, 2); }
int lua_cd_stop(lua_State *_pL) { return DoLuaGMLCall(_pL, 1548, 0); }
int lua_cd_pause(lua_State *_pL) { return DoLuaGMLCall(_pL, 1549, 0); }
int lua_cd_resume(lua_State *_pL) { return DoLuaGMLCall(_pL, 1550, 0); }
int lua_cd_set_position(lua_State *_pL) { return DoLuaGMLCall(_pL, 1551, 1); }
int lua_cd_set_track_position(lua_State *_pL) { return DoLuaGMLCall(_pL, 1552, 1); }
int lua_cd_open_door(lua_State *_pL) { return DoLuaGMLCall(_pL, 1553, 0); }
int lua_cd_close_door(lua_State *_pL) { return DoLuaGMLCall(_pL, 1554, 0); }
int lua_MCI_command(lua_State *_pL) { return DoLuaGMLCall(_pL, 1555, 1); }
int lua_audio_listener_position(lua_State *_pL) { return DoLuaGMLCall(_pL, 1556, 3); }
int lua_audio_listener_velocity(lua_State *_pL) { return DoLuaGMLCall(_pL, 1557, 3); }
int lua_audio_listener_orientation(lua_State *_pL) { return DoLuaGMLCall(_pL, 1558, 6); }
int lua_audio_emitter_position(lua_State *_pL) { return DoLuaGMLCall(_pL, 1559, 4); }
int lua_audio_emitter_velocity(lua_State *_pL) { return DoLuaGMLCall(_pL, 1560, 4); }
int lua_audio_system(lua_State *_pL) { return DoLuaGMLCall(_pL, 1561, 0); }
int lua_audio_emitter_create(lua_State *_pL) { return DoLuaGMLCall(_pL, 1562, 0); }
int lua_audio_emitter_free(lua_State *_pL) { return DoLuaGMLCall(_pL, 1563, 1); }
int lua_audio_play_sound(lua_State *_pL) { return DoLuaGMLCall(_pL, 1564, 3); }
int lua_audio_play_sound_on(lua_State *_pL) { return DoLuaGMLCall(_pL, 1565, 4); }
int lua_audio_play_sound_at(lua_State *_pL) { return DoLuaGMLCall(_pL, 1566, 9); }
int lua_audio_falloff_set_model(lua_State *_pL) { return DoLuaGMLCall(_pL, 1567, 1); }
int lua_audio_stop_sound(lua_State *_pL) { return DoLuaGMLCall(_pL, 1568, 1); }
int lua_audio_pause_sound(lua_State *_pL) { return DoLuaGMLCall(_pL, 1569, 1); }
int lua_audio_resume_sound(lua_State *_pL) { return DoLuaGMLCall(_pL, 1570, 1); }
int lua_audio_pause_all(lua_State *_pL) { return DoLuaGMLCall(_pL, 1571, 0); }
int lua_audio_resume_all(lua_State *_pL) { return DoLuaGMLCall(_pL, 1572, 0); }
int lua_audio_is_playing(lua_State *_pL) { return DoLuaGMLCall(_pL, 1573, 1); }
int lua_audio_is_paused(lua_State *_pL) { return DoLuaGMLCall(_pL, 1574, 1); }
int lua_audio_exists(lua_State *_pL) { return DoLuaGMLCall(_pL, 1575, 1); }
int lua_audio_system_is_available(lua_State *_pL) { return DoLuaGMLCall(_pL, 1576, 0); }
int lua_audio_master_gain(lua_State *_pL) { return DoLuaGMLCall(_pL, 1577, 1); }
int lua_audio_emitter_exists(lua_State *_pL) { return DoLuaGMLCall(_pL, 1578, 1); }
int lua_audio_get_type(lua_State *_pL) { return DoLuaGMLCall(_pL, 1579, 1); }
int lua_audio_emitter_gain(lua_State *_pL) { return DoLuaGMLCall(_pL, 1580, 2); }
int lua_audio_emitter_pitch(lua_State *_pL) { return DoLuaGMLCall(_pL, 1581, 2); }
int lua_audio_emitter_falloff(lua_State *_pL) { return DoLuaGMLCall(_pL, 1582, 4); }
int lua_audio_channel_num(lua_State *_pL) { return DoLuaGMLCall(_pL, 1583, 1); }
int lua_audio_play_music(lua_State *_pL) { return DoLuaGMLCall(_pL, 1584, 2); }
int lua_audio_stop_music(lua_State *_pL) { return DoLuaGMLCall(_pL, 1585, 0); }
int lua_audio_pause_music(lua_State *_pL) { return DoLuaGMLCall(_pL, 1586, 0); }
int lua_audio_resume_music(lua_State *_pL) { return DoLuaGMLCall(_pL, 1587, 0); }
int lua_audio_music_is_playing(lua_State *_pL) { return DoLuaGMLCall(_pL, 1588, 0); }
int lua_audio_music_gain(lua_State *_pL) { return DoLuaGMLCall(_pL, 1589, 2); }
int lua_audio_sound_gain(lua_State *_pL) { return DoLuaGMLCall(_pL, 1590, 3); }
int lua_audio_sound_pitch(lua_State *_pL) { return DoLuaGMLCall(_pL, 1591, 2); }
int lua_audio_stop_all(lua_State *_pL) { return DoLuaGMLCall(_pL, 1592, 0); }
int lua_audio_sound_length(lua_State *_pL) { return DoLuaGMLCall(_pL, 1593, 1); }
int lua_audio_emitter_get_gain(lua_State *_pL) { return DoLuaGMLCall(_pL, 1594, 1); }
int lua_audio_emitter_get_pitch(lua_State *_pL) { return DoLuaGMLCall(_pL, 1595, 1); }
int lua_audio_emitter_get_x(lua_State *_pL) { return DoLuaGMLCall(_pL, 1596, 1); }
int lua_audio_emitter_get_y(lua_State *_pL) { return DoLuaGMLCall(_pL, 1597, 1); }
int lua_audio_emitter_get_z(lua_State *_pL) { return DoLuaGMLCall(_pL, 1598, 1); }
int lua_audio_emitter_get_vx(lua_State *_pL) { return DoLuaGMLCall(_pL, 1599, 1); }
int lua_audio_emitter_get_vy(lua_State *_pL) { return DoLuaGMLCall(_pL, 1600, 1); }
int lua_audio_emitter_get_vz(lua_State *_pL) { return DoLuaGMLCall(_pL, 1601, 1); }
int lua_audio_listener_set_position(lua_State *_pL) { return DoLuaGMLCall(_pL, 1602, 4); }
int lua_audio_listener_set_velocity(lua_State *_pL) { return DoLuaGMLCall(_pL, 1603, 4); }
int lua_audio_listener_set_orientation(lua_State *_pL) { return DoLuaGMLCall(_pL, 1604, 7); }
int lua_audio_listener_get_data(lua_State *_pL) { return DoLuaGMLCall(_pL, 1605, 1); }
int lua_audio_set_master_gain(lua_State *_pL) { return DoLuaGMLCall(_pL, 1606, 2); }
int lua_audio_get_master_gain(lua_State *_pL) { return DoLuaGMLCall(_pL, 1607, 1); }
int lua_audio_sound_get_gain(lua_State *_pL) { return DoLuaGMLCall(_pL, 1608, 1); }
int lua_audio_sound_get_pitch(lua_State *_pL) { return DoLuaGMLCall(_pL, 1609, 1); }
int lua_audio_get_name(lua_State *_pL) { return DoLuaGMLCall(_pL, 1610, 1); }
int lua_audio_sound_set_track_position(lua_State *_pL) { return DoLuaGMLCall(_pL, 1611, 2); }
int lua_audio_sound_get_track_position(lua_State *_pL) { return DoLuaGMLCall(_pL, 1612, 1); }
int lua_audio_group_load(lua_State *_pL) { return DoLuaGMLCall(_pL, 1613, 1); }
int lua_audio_group_unload(lua_State *_pL) { return DoLuaGMLCall(_pL, 1614, 1); }
int lua_audio_group_is_loaded(lua_State *_pL) { return DoLuaGMLCall(_pL, 1615, 1); }
int lua_audio_group_load_progress(lua_State *_pL) { return DoLuaGMLCall(_pL, 1616, 1); }
int lua_audio_group_name(lua_State *_pL) { return DoLuaGMLCall(_pL, 1617, 1); }
int lua_audio_group_stop_all(lua_State *_pL) { return DoLuaGMLCall(_pL, 1618, 1); }
int lua_audio_group_set_gain(lua_State *_pL) { return DoLuaGMLCall(_pL, 1619, 3); }
int lua_audio_create_buffer_sound(lua_State *_pL) { return DoLuaGMLCall(_pL, 1620, 6); }
int lua_audio_free_buffer_sound(lua_State *_pL) { return DoLuaGMLCall(_pL, 1621, 1); }
int lua_audio_create_play_queue(lua_State *_pL) { return DoLuaGMLCall(_pL, 1622, 3); }
int lua_audio_free_play_queue(lua_State *_pL) { return DoLuaGMLCall(_pL, 1623, 0); }
int lua_audio_queue_sound(lua_State *_pL) { return DoLuaGMLCall(_pL, 1624, 4); }
int lua_audio_start_recording(lua_State *_pL) { return DoLuaGMLCall(_pL, 1625, 1); }
int lua_audio_stop_recording(lua_State *_pL) { return DoLuaGMLCall(_pL, 1626, 1); }
int lua_audio_get_recorder_count(lua_State *_pL) { return DoLuaGMLCall(_pL, 1627, 0); }
int lua_audio_get_recorder_info(lua_State *_pL) { return DoLuaGMLCall(_pL, 1628, 1); }
int lua_audio_sound_get_listener_mask(lua_State *_pL) { return DoLuaGMLCall(_pL, 1629, 1); }
int lua_audio_sound_set_listener_mask(lua_State *_pL) { return DoLuaGMLCall(_pL, 1630, 2); }
int lua_audio_emitter_get_listener_mask(lua_State *_pL) { return DoLuaGMLCall(_pL, 1631, 1); }
int lua_audio_emitter_set_listener_mask(lua_State *_pL) { return DoLuaGMLCall(_pL, 1632, 2); }
int lua_audio_get_listener_mask(lua_State *_pL) { return DoLuaGMLCall(_pL, 1633, 0); }
int lua_audio_set_listener_mask(lua_State *_pL) { return DoLuaGMLCall(_pL, 1634, 1); }
int lua_audio_get_listener_info(lua_State *_pL) { return DoLuaGMLCall(_pL, 1635, 0); }
int lua_audio_get_listener_count(lua_State *_pL) { return DoLuaGMLCall(_pL, 1636, 0); }
int lua_audio_create_sync_group(lua_State *_pL) { return DoLuaGMLCall(_pL, 1637, 1); }
int lua_audio_destroy_sync_group(lua_State *_pL) { return DoLuaGMLCall(_pL, 1638, 1); }
int lua_audio_play_in_sync_group(lua_State *_pL) { return DoLuaGMLCall(_pL, 1639, 4); }
int lua_audio_start_sync_group(lua_State *_pL) { return DoLuaGMLCall(_pL, 1640, 1); }
int lua_audio_pause_sync_group(lua_State *_pL) { return DoLuaGMLCall(_pL, 1641, 1); }
int lua_audio_resume_sync_group(lua_State *_pL) { return DoLuaGMLCall(_pL, 1642, 1); }
int lua_audio_stop_sync_group(lua_State *_pL) { return DoLuaGMLCall(_pL, 1643, 1); }
int lua_audio_sync_group_get_track_pos(lua_State *_pL) { return DoLuaGMLCall(_pL, 1644, 1); }
int lua_audio_sync_group_debug(lua_State *_pL) { return DoLuaGMLCall(_pL, 1645, 1); }
int lua_audio_sync_group_is_playing(lua_State *_pL) { return DoLuaGMLCall(_pL, 1646, 1); }
int lua_audio_create_stream(lua_State *_pL) { return DoLuaGMLCall(_pL, 1647, 1); }
int lua_audio_destroy_stream(lua_State *_pL) { return DoLuaGMLCall(_pL, 1648, 1); }
int lua_audio_debug(lua_State *_pL) { return DoLuaGMLCall(_pL, 1649, 1); }
int lua_physics_world_create(lua_State *_pL) { return DoLuaGMLCall(_pL, 1650, 1); }
int lua_physics_world_gravity(lua_State *_pL) { return DoLuaGMLCall(_pL, 1651, 2); }
int lua_physics_world_update_speed(lua_State *_pL) { return DoLuaGMLCall(_pL, 1652, 1); }
int lua_physics_world_update_iterations(lua_State *_pL) { return DoLuaGMLCall(_pL, 1653, 1); }
int lua_physics_world_draw_debug(lua_State *_pL) { return DoLuaGMLCall(_pL, 1654, 1); }
int lua_physics_pause_enable(lua_State *_pL) { return DoLuaGMLCall(_pL, 1655, 1); }
int lua_physics_fixture_create(lua_State *_pL) { return DoLuaGMLCall(_pL, 1656, 0); }
int lua_physics_fixture_set_kinematic(lua_State *_pL) { return DoLuaGMLCall(_pL, 1657, 1); }
int lua_physics_fixture_set_awake(lua_State *_pL) { return DoLuaGMLCall(_pL, 1658, 2); }
int lua_physics_fixture_set_density(lua_State *_pL) { return DoLuaGMLCall(_pL, 1659, 2); }
int lua_physics_fixture_set_restitution(lua_State *_pL) { return DoLuaGMLCall(_pL, 1660, 2); }
int lua_physics_fixture_set_friction(lua_State *_pL) { return DoLuaGMLCall(_pL, 1661, 2); }
int lua_physics_fixture_set_collision_group(lua_State *_pL) { return DoLuaGMLCall(_pL, 1662, 2); }
int lua_physics_fixture_set_sensor(lua_State *_pL) { return DoLuaGMLCall(_pL, 1663, 2); }
int lua_physics_fixture_set_linear_damping(lua_State *_pL) { return DoLuaGMLCall(_pL, 1664, 2); }
int lua_physics_fixture_set_angular_damping(lua_State *_pL) { return DoLuaGMLCall(_pL, 1665, 2); }
int lua_physics_fixture_set_circle_shape(lua_State *_pL) { return DoLuaGMLCall(_pL, 1666, 2); }
int lua_physics_fixture_set_box_shape(lua_State *_pL) { return DoLuaGMLCall(_pL, 1667, 3); }
int lua_physics_fixture_set_edge_shape(lua_State *_pL) { return DoLuaGMLCall(_pL, 1668, 5); }
int lua_physics_fixture_set_polygon_shape(lua_State *_pL) { return DoLuaGMLCall(_pL, 1669, 1); }
int lua_physics_fixture_set_chain_shape(lua_State *_pL) { return DoLuaGMLCall(_pL, 1670, 2); }
int lua_physics_fixture_add_point(lua_State *_pL) { return DoLuaGMLCall(_pL, 1671, 3); }
int lua_physics_fixture_bind(lua_State *_pL) { return DoLuaGMLCall(_pL, 1672, 2); }
int lua_physics_fixture_bind_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 1673, 4); }
int lua_physics_fixture_delete(lua_State *_pL) { return DoLuaGMLCall(_pL, 1674, 1); }
int lua_physics_apply_force(lua_State *_pL) { return DoLuaGMLCall(_pL, 1675, 4); }
int lua_physics_apply_impulse(lua_State *_pL) { return DoLuaGMLCall(_pL, 1676, 4); }
int lua_physics_apply_angular_impulse(lua_State *_pL) { return DoLuaGMLCall(_pL, 1677, 1); }
int lua_physics_apply_local_force(lua_State *_pL) { return DoLuaGMLCall(_pL, 1678, 4); }
int lua_physics_apply_local_impulse(lua_State *_pL) { return DoLuaGMLCall(_pL, 1679, 4); }
int lua_physics_apply_torque(lua_State *_pL) { return DoLuaGMLCall(_pL, 1680, 1); }
int lua_physics_mass_properties(lua_State *_pL) { return DoLuaGMLCall(_pL, 1681, 4); }
int lua_physics_draw_debug(lua_State *_pL) { return DoLuaGMLCall(_pL, 1682, 0); }
int lua_physics_test_overlap(lua_State *_pL) { return DoLuaGMLCall(_pL, 1683, 4); }
int lua_physics_remove_fixture(lua_State *_pL) { return DoLuaGMLCall(_pL, 1684, 2); }
int lua_physics_get_friction(lua_State *_pL) { return DoLuaGMLCall(_pL, 1685, 1); }
int lua_physics_get_density(lua_State *_pL) { return DoLuaGMLCall(_pL, 1686, 1); }
int lua_physics_get_restitution(lua_State *_pL) { return DoLuaGMLCall(_pL, 1687, 1); }
int lua_physics_set_friction(lua_State *_pL) { return DoLuaGMLCall(_pL, 1688, 2); }
int lua_physics_set_density(lua_State *_pL) { return DoLuaGMLCall(_pL, 1689, 2); }
int lua_physics_set_restitution(lua_State *_pL) { return DoLuaGMLCall(_pL, 1690, 2); }
int lua_physics_joint_distance_create(lua_State *_pL) { return DoLuaGMLCall(_pL, 1691, 7); }
int lua_physics_joint_rope_create(lua_State *_pL) { return DoLuaGMLCall(_pL, 1692, 8); }
int lua_physics_joint_revolute_create(lua_State *_pL) { return DoLuaGMLCall(_pL, 1693, 11); }
int lua_physics_joint_prismatic_create(lua_State *_pL) { return DoLuaGMLCall(_pL, 1694, 13); }
int lua_physics_joint_pulley_create(lua_State *_pL) { return DoLuaGMLCall(_pL, 1695, 12); }
int lua_physics_joint_wheel_create(lua_State *_pL) { return DoLuaGMLCall(_pL, 1696, 12); }
int lua_physics_joint_gear_create(lua_State *_pL) { return DoLuaGMLCall(_pL, 1697, 5); }
int lua_physics_joint_weld_create(lua_State *_pL) { return DoLuaGMLCall(_pL, 1698, 8); }
int lua_physics_joint_friction_create(lua_State *_pL) { return DoLuaGMLCall(_pL, 1699, 7); }
int lua_physics_joint_enable_motor(lua_State *_pL) { return DoLuaGMLCall(_pL, 1700, 2); }
int lua_physics_joint_get_value(lua_State *_pL) { return DoLuaGMLCall(_pL, 1701, 2); }
int lua_physics_joint_set_value(lua_State *_pL) { return DoLuaGMLCall(_pL, 1702, 3); }
int lua_physics_joint_delete(lua_State *_pL) { return DoLuaGMLCall(_pL, 1703, 1); }
int lua_physics_particle_create(lua_State *_pL) { return DoLuaGMLCall(_pL, 1704, 8); }
int lua_physics_particle_delete(lua_State *_pL) { return DoLuaGMLCall(_pL, 1705, 1); }
int lua_physics_particle_delete_region_circle(lua_State *_pL) { return DoLuaGMLCall(_pL, 1706, 3); }
int lua_physics_particle_delete_region_box(lua_State *_pL) { return DoLuaGMLCall(_pL, 1707, 4); }
int lua_physics_particle_delete_region_poly(lua_State *_pL) { return DoLuaGMLCall(_pL, 1708, 1); }
int lua_physics_particle_set_flags(lua_State *_pL) { return DoLuaGMLCall(_pL, 1709, 2); }
int lua_physics_particle_set_category_flags(lua_State *_pL) { return DoLuaGMLCall(_pL, 1710, 2); }
int lua_physics_particle_draw(lua_State *_pL) { return DoLuaGMLCall(_pL, 1711, 4); }
int lua_physics_particle_draw_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 1712, 9); }
int lua_physics_particle_count(lua_State *_pL) { return DoLuaGMLCall(_pL, 1713, 0); }
int lua_physics_particle_get_data(lua_State *_pL) { return DoLuaGMLCall(_pL, 1714, 2); }
int lua_physics_particle_get_data_particle(lua_State *_pL) { return DoLuaGMLCall(_pL, 1715, 2); }
int lua_physics_particle_group_begin(lua_State *_pL) { return DoLuaGMLCall(_pL, 1716, 12); }
int lua_physics_particle_group_circle(lua_State *_pL) { return DoLuaGMLCall(_pL, 1717, 2); }
int lua_physics_particle_group_box(lua_State *_pL) { return DoLuaGMLCall(_pL, 1718, 3); }
int lua_physics_particle_group_polygon(lua_State *_pL) { return DoLuaGMLCall(_pL, 1719, 1); }
int lua_physics_particle_group_add_point(lua_State *_pL) { return DoLuaGMLCall(_pL, 1720, 3); }
int lua_physics_particle_group_end(lua_State *_pL) { return DoLuaGMLCall(_pL, 1721, 0); }
int lua_physics_particle_group_join(lua_State *_pL) { return DoLuaGMLCall(_pL, 1722, 2); }
int lua_physics_particle_group_delete(lua_State *_pL) { return DoLuaGMLCall(_pL, 1723, 1); }
int lua_physics_particle_group_count(lua_State *_pL) { return DoLuaGMLCall(_pL, 1724, 1); }
int lua_physics_particle_group_get_data(lua_State *_pL) { return DoLuaGMLCall(_pL, 1725, 3); }
int lua_physics_particle_group_get_mass(lua_State *_pL) { return DoLuaGMLCall(_pL, 1726, 1); }
int lua_physics_particle_group_get_inertia(lua_State *_pL) { return DoLuaGMLCall(_pL, 1727, 1); }
int lua_physics_particle_group_get_centre_x(lua_State *_pL) { return DoLuaGMLCall(_pL, 1728, 1); }
int lua_physics_particle_group_get_centre_y(lua_State *_pL) { return DoLuaGMLCall(_pL, 1729, 1); }
int lua_physics_particle_group_get_vel_x(lua_State *_pL) { return DoLuaGMLCall(_pL, 1730, 1); }
int lua_physics_particle_group_get_vel_y(lua_State *_pL) { return DoLuaGMLCall(_pL, 1731, 1); }
int lua_physics_particle_group_get_ang_vel(lua_State *_pL) { return DoLuaGMLCall(_pL, 1732, 1); }
int lua_physics_particle_group_get_x(lua_State *_pL) { return DoLuaGMLCall(_pL, 1733, 1); }
int lua_physics_particle_group_get_y(lua_State *_pL) { return DoLuaGMLCall(_pL, 1734, 1); }
int lua_physics_particle_group_get_angle(lua_State *_pL) { return DoLuaGMLCall(_pL, 1735, 1); }
int lua_physics_particle_set_group_flags(lua_State *_pL) { return DoLuaGMLCall(_pL, 1736, 2); }
int lua_physics_particle_get_group_flags(lua_State *_pL) { return DoLuaGMLCall(_pL, 1737, 1); }
int lua_physics_particle_get_max_count(lua_State *_pL) { return DoLuaGMLCall(_pL, 1738, 0); }
int lua_physics_particle_get_radius(lua_State *_pL) { return DoLuaGMLCall(_pL, 1739, 0); }
int lua_physics_particle_get_density(lua_State *_pL) { return DoLuaGMLCall(_pL, 1740, 0); }
int lua_physics_particle_get_damping(lua_State *_pL) { return DoLuaGMLCall(_pL, 1741, 0); }
int lua_physics_particle_get_gravity_scale(lua_State *_pL) { return DoLuaGMLCall(_pL, 1742, 0); }
int lua_physics_particle_set_max_count(lua_State *_pL) { return DoLuaGMLCall(_pL, 1743, 1); }
int lua_physics_particle_set_radius(lua_State *_pL) { return DoLuaGMLCall(_pL, 1744, 1); }
int lua_physics_particle_set_density(lua_State *_pL) { return DoLuaGMLCall(_pL, 1745, 1); }
int lua_physics_particle_set_damping(lua_State *_pL) { return DoLuaGMLCall(_pL, 1746, 1); }
int lua_physics_particle_set_gravity_scale(lua_State *_pL) { return DoLuaGMLCall(_pL, 1747, 1); }
int lua_gamepad_is_supported(lua_State *_pL) { return DoLuaGMLCall(_pL, 1748, 0); }
int lua_gamepad_get_device_count(lua_State *_pL) { return DoLuaGMLCall(_pL, 1749, 0); }
int lua_gamepad_is_connected(lua_State *_pL) { return DoLuaGMLCall(_pL, 1750, 1); }
int lua_gamepad_get_description(lua_State *_pL) { return DoLuaGMLCall(_pL, 1751, 1); }
int lua_gamepad_get_button_threshold(lua_State *_pL) { return DoLuaGMLCall(_pL, 1752, 1); }
int lua_gamepad_set_button_threshold(lua_State *_pL) { return DoLuaGMLCall(_pL, 1753, 2); }
int lua_gamepad_get_axis_deadzone(lua_State *_pL) { return DoLuaGMLCall(_pL, 1754, 1); }
int lua_gamepad_set_axis_deadzone(lua_State *_pL) { return DoLuaGMLCall(_pL, 1755, 2); }
int lua_gamepad_button_count(lua_State *_pL) { return DoLuaGMLCall(_pL, 1756, 1); }
int lua_gamepad_button_check(lua_State *_pL) { return DoLuaGMLCall(_pL, 1757, 2); }
int lua_gamepad_button_check_pressed(lua_State *_pL) { return DoLuaGMLCall(_pL, 1758, 2); }
int lua_gamepad_button_check_released(lua_State *_pL) { return DoLuaGMLCall(_pL, 1759, 2); }
int lua_gamepad_button_value(lua_State *_pL) { return DoLuaGMLCall(_pL, 1760, 2); }
int lua_gamepad_axis_count(lua_State *_pL) { return DoLuaGMLCall(_pL, 1761, 1); }
int lua_gamepad_axis_value(lua_State *_pL) { return DoLuaGMLCall(_pL, 1762, 2); }
int lua_gamepad_hat_value(lua_State *_pL) { return DoLuaGMLCall(_pL, 1763, 2); }
int lua_gamepad_hat_count(lua_State *_pL) { return DoLuaGMLCall(_pL, 1764, 1); }
int lua_gamepad_remove_mapping(lua_State *_pL) { return DoLuaGMLCall(_pL, 1765, 1); }
int lua_gamepad_test_mapping(lua_State *_pL) { return DoLuaGMLCall(_pL, 1766, 2); }
int lua_gamepad_get_mapping(lua_State *_pL) { return DoLuaGMLCall(_pL, 1767, 1); }
int lua_gamepad_get_guid(lua_State *_pL) { return DoLuaGMLCall(_pL, 1768, 1); }
int lua_gamepad_set_vibration(lua_State *_pL) { return DoLuaGMLCall(_pL, 1769, 3); }
int lua_gamepad_add_hardware_mapping_from_string(lua_State *_pL) { return DoLuaGMLCall(_pL, 1770, 1); }
int lua_gamepad_add_hardware_mapping_from_file(lua_State *_pL) { return DoLuaGMLCall(_pL, 1771, 1); }
int lua_gamepad_get_hardware_mappings(lua_State *_pL) { return DoLuaGMLCall(_pL, 1772, 0); }
int lua_gamepad_set_color(lua_State *_pL) { return DoLuaGMLCall(_pL, 1773, 2); }
int lua_gamepad_set_colour(lua_State *_pL) { return DoLuaGMLCall(_pL, 1774, 2); }
int lua_buffer_create(lua_State *_pL) { return DoLuaGMLCall(_pL, 1775, 3); }
int lua_buffer_delete(lua_State *_pL) { return DoLuaGMLCall(_pL, 1776, 1); }
int lua_buffer_write(lua_State *_pL) { return DoLuaGMLCall(_pL, 1777, 3); }
int lua_buffer_read(lua_State *_pL) { return DoLuaGMLCall(_pL, 1778, 2); }
int lua_buffer_poke(lua_State *_pL) { return DoLuaGMLCall(_pL, 1779, 4); }
int lua_buffer_peek(lua_State *_pL) { return DoLuaGMLCall(_pL, 1780, 3); }
int lua_buffer_seek(lua_State *_pL) { return DoLuaGMLCall(_pL, 1781, 3); }
int lua_buffer_save(lua_State *_pL) { return DoLuaGMLCall(_pL, 1782, 2); }
int lua_buffer_save_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 1783, 4); }
int lua_buffer_load(lua_State *_pL) { return DoLuaGMLCall(_pL, 1784, 1); }
int lua_buffer_load_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 1785, 3); }
int lua_buffer_load_partial(lua_State *_pL) { return DoLuaGMLCall(_pL, 1786, 5); }
int lua_buffer_save_async(lua_State *_pL) { return DoLuaGMLCall(_pL, 1787, 4); }
int lua_buffer_load_async(lua_State *_pL) { return DoLuaGMLCall(_pL, 1788, 4); }
int lua_buffer_async_group_begin(lua_State *_pL) { return DoLuaGMLCall(_pL, 1789, 1); }
int lua_buffer_async_group_end(lua_State *_pL) { return DoLuaGMLCall(_pL, 1790, 0); }
int lua_buffer_async_group_option(lua_State *_pL) { return DoLuaGMLCall(_pL, 1791, 2); }
int lua_buffer_copy(lua_State *_pL) { return DoLuaGMLCall(_pL, 1792, 5); }
int lua_buffer_exists(lua_State *_pL) { return DoLuaGMLCall(_pL, 1793, 1); }
int lua_buffer_get_type(lua_State *_pL) { return DoLuaGMLCall(_pL, 1794, 1); }
int lua_buffer_get_alignment(lua_State *_pL) { return DoLuaGMLCall(_pL, 1795, 1); }
int lua_buffer_fill(lua_State *_pL) { return DoLuaGMLCall(_pL, 1796, 5); }
int lua_buffer_get_size(lua_State *_pL) { return DoLuaGMLCall(_pL, 1797, 1); }
int lua_buffer_tell(lua_State *_pL) { return DoLuaGMLCall(_pL, 1798, 1); }
int lua_buffer_resize(lua_State *_pL) { return DoLuaGMLCall(_pL, 1799, 2); }
int lua_buffer_md5(lua_State *_pL) { return DoLuaGMLCall(_pL, 1800, 3); }
int lua_buffer_sha1(lua_State *_pL) { return DoLuaGMLCall(_pL, 1801, 3); }
int lua_buffer_base64_encode(lua_State *_pL) { return DoLuaGMLCall(_pL, 1802, 3); }
int lua_buffer_base64_decode(lua_State *_pL) { return DoLuaGMLCall(_pL, 1803, 1); }
int lua_buffer_base64_decode_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 1804, 3); }
int lua_buffer_sizeof(lua_State *_pL) { return DoLuaGMLCall(_pL, 1805, 1); }
int lua_buffer_get_address(lua_State *_pL) { return DoLuaGMLCall(_pL, 1806, 1); }
int lua_buffer_get_surface(lua_State *_pL) { return DoLuaGMLCall(_pL, 1807, 5); }
int lua_buffer_set_surface(lua_State *_pL) { return DoLuaGMLCall(_pL, 1808, 5); }
int lua_buffer_create_from_vertex_buffer(lua_State *_pL) { return DoLuaGMLCall(_pL, 1809, 3); }
int lua_buffer_create_from_vertex_buffer_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 1810, 5); }
int lua_buffer_copy_from_vertex_buffer(lua_State *_pL) { return DoLuaGMLCall(_pL, 1811, 5); }
int lua_buffer_compress(lua_State *_pL) { return DoLuaGMLCall(_pL, 1812, 3); }
int lua_buffer_decompress(lua_State *_pL) { return DoLuaGMLCall(_pL, 1813, 1); }
int lua_vertex_create_buffer(lua_State *_pL) { return DoLuaGMLCall(_pL, 1814, 0); }
int lua_vertex_create_buffer_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 1815, 1); }
int lua_vertex_delete_buffer(lua_State *_pL) { return DoLuaGMLCall(_pL, 1816, 1); }
int lua_vertex_begin(lua_State *_pL) { return DoLuaGMLCall(_pL, 1817, 2); }
int lua_vertex_end(lua_State *_pL) { return DoLuaGMLCall(_pL, 1818, 1); }
int lua_vertex_position(lua_State *_pL) { return DoLuaGMLCall(_pL, 1819, 3); }
int lua_vertex_position_3d(lua_State *_pL) { return DoLuaGMLCall(_pL, 1820, 4); }
int lua_vertex_colour(lua_State *_pL) { return DoLuaGMLCall(_pL, 1821, 3); }
int lua_vertex_color(lua_State *_pL) { return DoLuaGMLCall(_pL, 1822, 3); }
int lua_vertex_argb(lua_State *_pL) { return DoLuaGMLCall(_pL, 1823, 2); }
int lua_vertex_texcoord(lua_State *_pL) { return DoLuaGMLCall(_pL, 1824, 3); }
int lua_vertex_normal(lua_State *_pL) { return DoLuaGMLCall(_pL, 1825, 4); }
int lua_vertex_float1(lua_State *_pL) { return DoLuaGMLCall(_pL, 1826, 2); }
int lua_vertex_float2(lua_State *_pL) { return DoLuaGMLCall(_pL, 1827, 3); }
int lua_vertex_float3(lua_State *_pL) { return DoLuaGMLCall(_pL, 1828, 4); }
int lua_vertex_float4(lua_State *_pL) { return DoLuaGMLCall(_pL, 1829, 5); }
int lua_vertex_ubyte4(lua_State *_pL) { return DoLuaGMLCall(_pL, 1830, 5); }
int lua_vertex_submit(lua_State *_pL) { return DoLuaGMLCall(_pL, 1831, 3); }
int lua_vertex_freeze(lua_State *_pL) { return DoLuaGMLCall(_pL, 1832, 1); }
int lua_vertex_get_number(lua_State *_pL) { return DoLuaGMLCall(_pL, 1833, 1); }
int lua_vertex_get_buffer_size(lua_State *_pL) { return DoLuaGMLCall(_pL, 1834, 1); }
int lua_vertex_create_buffer_from_buffer(lua_State *_pL) { return DoLuaGMLCall(_pL, 1835, 2); }
int lua_vertex_create_buffer_from_buffer_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 1836, 4); }
int lua_network_create_socket(lua_State *_pL) { return DoLuaGMLCall(_pL, 1837, 1); }
int lua_network_create_socket_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 1838, 2); }
int lua_network_create_server(lua_State *_pL) { return DoLuaGMLCall(_pL, 1839, 3); }
int lua_network_create_server_raw(lua_State *_pL) { return DoLuaGMLCall(_pL, 1840, 3); }
int lua_network_connect(lua_State *_pL) { return DoLuaGMLCall(_pL, 1841, 3); }
int lua_network_connect_raw(lua_State *_pL) { return DoLuaGMLCall(_pL, 1842, 3); }
int lua_network_send_packet(lua_State *_pL) { return DoLuaGMLCall(_pL, 1843, 3); }
int lua_network_send_raw(lua_State *_pL) { return DoLuaGMLCall(_pL, 1844, 3); }
int lua_network_send_broadcast(lua_State *_pL) { return DoLuaGMLCall(_pL, 1845, 3); }
int lua_network_send_udp(lua_State *_pL) { return DoLuaGMLCall(_pL, 1846, 5); }
int lua_network_send_udp_raw(lua_State *_pL) { return DoLuaGMLCall(_pL, 1847, 5); }
int lua_network_resolve(lua_State *_pL) { return DoLuaGMLCall(_pL, 1848, 1); }
int lua_network_destroy(lua_State *_pL) { return DoLuaGMLCall(_pL, 1849, 1); }
int lua_network_set_timeout(lua_State *_pL) { return DoLuaGMLCall(_pL, 1850, 3); }
int lua_network_set_config(lua_State *_pL) { return DoLuaGMLCall(_pL, 1851, 2); }
int lua_shader_set(lua_State *_pL) { return DoLuaGMLCall(_pL, 1852, 1); }
int lua_shader_get_name(lua_State *_pL) { return DoLuaGMLCall(_pL, 1853, 1); }
int lua_shader_reset(lua_State *_pL) { return DoLuaGMLCall(_pL, 1854, 1); }
int lua_shader_current(lua_State *_pL) { return DoLuaGMLCall(_pL, 1855, 0); }
int lua_shader_get_uniform(lua_State *_pL) { return DoLuaGMLCall(_pL, 1856, 2); }
int lua_shader_get_sampler_index(lua_State *_pL) { return DoLuaGMLCall(_pL, 1857, 2); }
int lua_shader_set_uniform_i(lua_State *_pL) { return DoLuaGMLCall(_pL, 1858, -1); }
int lua_shader_set_uniform_i_array(lua_State *_pL) { return DoLuaGMLCall(_pL, 1859, 2); }
int lua_shader_set_uniform_f(lua_State *_pL) { return DoLuaGMLCall(_pL, 1860, -1); }
int lua_shader_set_uniform_f_array(lua_State *_pL) { return DoLuaGMLCall(_pL, 1861, 2); }
int lua_shader_set_uniform_matrix(lua_State *_pL) { return DoLuaGMLCall(_pL, 1862, 1); }
int lua_shader_set_uniform_matrix_array(lua_State *_pL) { return DoLuaGMLCall(_pL, 1863, 2); }
int lua_shader_is_compiled(lua_State *_pL) { return DoLuaGMLCall(_pL, 1864, 1); }
int lua_shaders_are_supported(lua_State *_pL) { return DoLuaGMLCall(_pL, 1865, 0); }
int lua_texture_set_stage(lua_State *_pL) { return DoLuaGMLCall(_pL, 1866, 2); }
int lua_texture_get_texel_width(lua_State *_pL) { return DoLuaGMLCall(_pL, 1867, 1); }
int lua_texture_get_texel_height(lua_State *_pL) { return DoLuaGMLCall(_pL, 1868, 1); }
int lua_vertex_format_begin(lua_State *_pL) { return DoLuaGMLCall(_pL, 1869, 0); }
int lua_vertex_format_delete(lua_State *_pL) { return DoLuaGMLCall(_pL, 1870, 1); }
int lua_vertex_format_end(lua_State *_pL) { return DoLuaGMLCall(_pL, 1871, 0); }
int lua_vertex_format_add_position(lua_State *_pL) { return DoLuaGMLCall(_pL, 1872, 0); }
int lua_vertex_format_add_position_3d(lua_State *_pL) { return DoLuaGMLCall(_pL, 1873, 0); }
int lua_vertex_format_add_colour(lua_State *_pL) { return DoLuaGMLCall(_pL, 1874, 0); }
int lua_vertex_format_add_color(lua_State *_pL) { return DoLuaGMLCall(_pL, 1875, 0); }
int lua_vertex_format_add_normal(lua_State *_pL) { return DoLuaGMLCall(_pL, 1876, 0); }
int lua_vertex_format_add_textcoord(lua_State *_pL) { return DoLuaGMLCall(_pL, 1877, 0); }
int lua_vertex_format_add_texcoord(lua_State *_pL) { return DoLuaGMLCall(_pL, 1878, 0); }
int lua_vertex_format_add_custom(lua_State *_pL) { return DoLuaGMLCall(_pL, 1879, 2); }
int lua_steam_activate_overlay(lua_State *_pL) { return DoLuaGMLCall(_pL, 1880, 1); }
int lua_steam_is_overlay_enabled(lua_State *_pL) { return DoLuaGMLCall(_pL, 1881, 0); }
int lua_steam_is_overlay_activated(lua_State *_pL) { return DoLuaGMLCall(_pL, 1882, 0); }
int lua_steam_get_persona_name(lua_State *_pL) { return DoLuaGMLCall(_pL, 1883, 0); }
int lua_steam_initialised(lua_State *_pL) { return DoLuaGMLCall(_pL, 1884, 0); }
int lua_steam_is_cloud_enabled_for_app(lua_State *_pL) { return DoLuaGMLCall(_pL, 1885, 0); }
int lua_steam_is_cloud_enabled_for_account(lua_State *_pL) { return DoLuaGMLCall(_pL, 1886, 0); }
int lua_steam_file_persisted(lua_State *_pL) { return DoLuaGMLCall(_pL, 1887, 1); }
int lua_steam_get_quota_total(lua_State *_pL) { return DoLuaGMLCall(_pL, 1888, 0); }
int lua_steam_get_quota_free(lua_State *_pL) { return DoLuaGMLCall(_pL, 1889, 0); }
int lua_steam_file_write(lua_State *_pL) { return DoLuaGMLCall(_pL, 1890, 3); }
int lua_steam_file_write_file(lua_State *_pL) { return DoLuaGMLCall(_pL, 1891, 2); }
int lua_steam_file_read(lua_State *_pL) { return DoLuaGMLCall(_pL, 1892, 1); }
int lua_steam_file_delete(lua_State *_pL) { return DoLuaGMLCall(_pL, 1893, 1); }
int lua_steam_file_exists(lua_State *_pL) { return DoLuaGMLCall(_pL, 1894, 1); }
int lua_steam_file_size(lua_State *_pL) { return DoLuaGMLCall(_pL, 1895, 1); }
int lua_steam_file_share(lua_State *_pL) { return DoLuaGMLCall(_pL, 1896, 1); }
int lua_steam_publish_workshop_file(lua_State *_pL) { return DoLuaGMLCall(_pL, 1897, 4); }
int lua_steam_is_screenshot_requested(lua_State *_pL) { return DoLuaGMLCall(_pL, 1898, 0); }
int lua_steam_send_screenshot(lua_State *_pL) { return DoLuaGMLCall(_pL, 1899, 3); }
int lua_steam_is_user_logged_on(lua_State *_pL) { return DoLuaGMLCall(_pL, 1900, 0); }
int lua_steam_get_user_steam_id(lua_State *_pL) { return DoLuaGMLCall(_pL, 1901, 0); }
int lua_steam_user_owns_dlc(lua_State *_pL) { return DoLuaGMLCall(_pL, 1902, 1); }
int lua_steam_user_installed_dlc(lua_State *_pL) { return DoLuaGMLCall(_pL, 1903, 1); }
int lua_steam_current_game_language(lua_State *_pL) { return DoLuaGMLCall(_pL, 1904, 1); }
int lua_steam_available_languages(lua_State *_pL) { return DoLuaGMLCall(_pL, 1905, 1); }
int lua_steam_activate_overlay_browser(lua_State *_pL) { return DoLuaGMLCall(_pL, 1906, 1); }
int lua_steam_activate_overlay_user(lua_State *_pL) { return DoLuaGMLCall(_pL, 1907, 2); }
int lua_steam_activate_overlay_store(lua_State *_pL) { return DoLuaGMLCall(_pL, 1908, 1); }
int lua_steam_get_user_persona_name(lua_State *_pL) { return DoLuaGMLCall(_pL, 1909, 1); }
int lua_steam_set_achievement(lua_State *_pL) { return DoLuaGMLCall(_pL, 1910, 1); }
int lua_steam_get_achievement(lua_State *_pL) { return DoLuaGMLCall(_pL, 1911, 1); }
int lua_steam_clear_achievement(lua_State *_pL) { return DoLuaGMLCall(_pL, 1912, 1); }
int lua_steam_set_stat_int(lua_State *_pL) { return DoLuaGMLCall(_pL, 1913, 2); }
int lua_steam_set_stat_float(lua_State *_pL) { return DoLuaGMLCall(_pL, 1914, 2); }
int lua_steam_set_stat_avg_rate(lua_State *_pL) { return DoLuaGMLCall(_pL, 1915, 3); }
int lua_steam_get_stat_int(lua_State *_pL) { return DoLuaGMLCall(_pL, 1916, 1); }
int lua_steam_get_stat_float(lua_State *_pL) { return DoLuaGMLCall(_pL, 1917, 1); }
int lua_steam_get_stat_avg_rate(lua_State *_pL) { return DoLuaGMLCall(_pL, 1918, 1); }
int lua_steam_reset_all_stats(lua_State *_pL) { return DoLuaGMLCall(_pL, 1919, 0); }
int lua_steam_reset_all_stats_achievements(lua_State *_pL) { return DoLuaGMLCall(_pL, 1920, 0); }
int lua_steam_stats_ready(lua_State *_pL) { return DoLuaGMLCall(_pL, 1921, 0); }
int lua_steam_create_leaderboard(lua_State *_pL) { return DoLuaGMLCall(_pL, 1922, 3); }
int lua_steam_upload_score(lua_State *_pL) { return DoLuaGMLCall(_pL, 1923, 2); }
int lua_steam_download_scores_around_user(lua_State *_pL) { return DoLuaGMLCall(_pL, 1924, 3); }
int lua_steam_download_scores(lua_State *_pL) { return DoLuaGMLCall(_pL, 1925, 3); }
int lua_steam_download_friends_scores(lua_State *_pL) { return DoLuaGMLCall(_pL, 1926, 1); }
int lua_steam_upload_score_buffer(lua_State *_pL) { return DoLuaGMLCall(_pL, 1927, 3); }
int lua_steam_upload_score_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 1928, 3); }
int lua_steam_upload_score_buffer_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 1929, 4); }
int lua_steam_get_app_id(lua_State *_pL) { return DoLuaGMLCall(_pL, 1930, 0); }
int lua_steam_get_user_account_id(lua_State *_pL) { return DoLuaGMLCall(_pL, 1931, 0); }
int lua_steam_ugc_download(lua_State *_pL) { return DoLuaGMLCall(_pL, 1932, 2); }
int lua_steam_ugc_create_item(lua_State *_pL) { return DoLuaGMLCall(_pL, 1933, 2); }
int lua_steam_ugc_start_item_update(lua_State *_pL) { return DoLuaGMLCall(_pL, 1934, 2); }
int lua_steam_ugc_set_item_title(lua_State *_pL) { return DoLuaGMLCall(_pL, 1935, 2); }
int lua_steam_ugc_set_item_description(lua_State *_pL) { return DoLuaGMLCall(_pL, 1936, 2); }
int lua_steam_ugc_set_item_visibility(lua_State *_pL) { return DoLuaGMLCall(_pL, 1937, 2); }
int lua_steam_ugc_set_item_tags(lua_State *_pL) { return DoLuaGMLCall(_pL, 1938, 2); }
int lua_steam_ugc_set_item_content(lua_State *_pL) { return DoLuaGMLCall(_pL, 1939, 2); }
int lua_steam_ugc_set_item_preview(lua_State *_pL) { return DoLuaGMLCall(_pL, 1940, 2); }
int lua_steam_ugc_submit_item_update(lua_State *_pL) { return DoLuaGMLCall(_pL, 1941, 2); }
int lua_steam_ugc_get_item_update_progress(lua_State *_pL) { return DoLuaGMLCall(_pL, 1942, 1); }
int lua_steam_ugc_subscribe_item(lua_State *_pL) { return DoLuaGMLCall(_pL, 1943, 1); }
int lua_steam_ugc_unsubscribe_item(lua_State *_pL) { return DoLuaGMLCall(_pL, 1944, 1); }
int lua_steam_ugc_num_subscribed_items(lua_State *_pL) { return DoLuaGMLCall(_pL, 1945, 0); }
int lua_steam_ugc_get_subscribed_items(lua_State *_pL) { return DoLuaGMLCall(_pL, 1946, 1); }
int lua_steam_ugc_get_item_install_info(lua_State *_pL) { return DoLuaGMLCall(_pL, 1947, 2); }
int lua_steam_ugc_get_item_update_info(lua_State *_pL) { return DoLuaGMLCall(_pL, 1948, 2); }
int lua_steam_ugc_request_item_details(lua_State *_pL) { return DoLuaGMLCall(_pL, 1949, 2); }
int lua_steam_ugc_create_query_user(lua_State *_pL) { return DoLuaGMLCall(_pL, 1950, 4); }
int lua_steam_ugc_create_query_user_ex(lua_State *_pL) { return DoLuaGMLCall(_pL, 1951, 7); }
int lua_steam_ugc_create_query_all(lua_State *_pL) { return DoLuaGMLCall(_pL, 1952, 3); }
int lua_steam_ugc_create_query_all_ex(lua_State *_pL) { return DoLuaGMLCall(_pL, 1953, 5); }
int lua_steam_ugc_query_set_cloud_filename_filter(lua_State *_pL) { return DoLuaGMLCall(_pL, 1954, 2); }
int lua_steam_ugc_query_set_match_any_tag(lua_State *_pL) { return DoLuaGMLCall(_pL, 1955, 2); }
int lua_steam_ugc_query_set_search_text(lua_State *_pL) { return DoLuaGMLCall(_pL, 1956, 2); }
int lua_steam_ugc_query_set_ranked_by_trend_days(lua_State *_pL) { return DoLuaGMLCall(_pL, 1957, 2); }
int lua_steam_ugc_query_add_required_tag(lua_State *_pL) { return DoLuaGMLCall(_pL, 1958, 2); }
int lua_steam_ugc_query_add_excluded_tag(lua_State *_pL) { return DoLuaGMLCall(_pL, 1959, 2); }
int lua_steam_ugc_query_set_return_long_description(lua_State *_pL) { return DoLuaGMLCall(_pL, 1960, 2); }
int lua_steam_ugc_query_set_return_total_only(lua_State *_pL) { return DoLuaGMLCall(_pL, 1961, 2); }
int lua_steam_ugc_query_set_allow_cached_response(lua_State *_pL) { return DoLuaGMLCall(_pL, 1962, 2); }
int lua_steam_ugc_send_query(lua_State *_pL) { return DoLuaGMLCall(_pL, 1963, 1); }
int lua_push_local_notification(lua_State *_pL) { return DoLuaGMLCall(_pL, 1964, 4); }
int lua_push_get_first_local_notification(lua_State *_pL) { return DoLuaGMLCall(_pL, 1965, 1); }
int lua_push_get_next_local_notification(lua_State *_pL) { return DoLuaGMLCall(_pL, 1966, 1); }
int lua_push_cancel_local_notification(lua_State *_pL) { return DoLuaGMLCall(_pL, 1967, 1); }
int lua_push_get_application_badge_number(lua_State *_pL) { return DoLuaGMLCall(_pL, 1968, 0); }
int lua_push_set_application_badge_number(lua_State *_pL) { return DoLuaGMLCall(_pL, 1969, 1); }
int lua_iap_activate(lua_State *_pL) { return DoLuaGMLCall(_pL, 1970, 1); }
int lua_iap_status(lua_State *_pL) { return DoLuaGMLCall(_pL, 1971, 0); }
int lua_iap_acquire(lua_State *_pL) { return DoLuaGMLCall(_pL, 1972, 2); }
int lua_iap_consume(lua_State *_pL) { return DoLuaGMLCall(_pL, 1973, 1); }
int lua_iap_is_purchased(lua_State *_pL) { return DoLuaGMLCall(_pL, 1974, 1); }
int lua_iap_enumerate_products(lua_State *_pL) { return DoLuaGMLCall(_pL, 1975, 1); }
int lua_iap_restore_all(lua_State *_pL) { return DoLuaGMLCall(_pL, 1976, 0); }
int lua_iap_product_details(lua_State *_pL) { return DoLuaGMLCall(_pL, 1977, 2); }
int lua_iap_purchase_details(lua_State *_pL) { return DoLuaGMLCall(_pL, 1978, 2); }
int lua_iap_store_status(lua_State *_pL) { return DoLuaGMLCall(_pL, 1979, 0); }
int lua_iap_event_queue(lua_State *_pL) { return DoLuaGMLCall(_pL, 1980, 0); }
int lua_iap_product_status(lua_State *_pL) { return DoLuaGMLCall(_pL, 1981, 1); }
int lua_iap_is_downloaded(lua_State *_pL) { return DoLuaGMLCall(_pL, 1982, 1); }
int lua_iap_product_files(lua_State *_pL) { return DoLuaGMLCall(_pL, 1983, 2); }
int lua_iap_files_purchased(lua_State *_pL) { return DoLuaGMLCall(_pL, 1984, 0); }
int lua_YoYo_AddVirtualKey(lua_State *_pL) { return DoLuaGMLCall(_pL, 1985, 5); }
int lua_YoYo_DeleteVirtualKey(lua_State *_pL) { return DoLuaGMLCall(_pL, 1986, 1); }
int lua_YoYo_ShowVirtualKey(lua_State *_pL) { return DoLuaGMLCall(_pL, 1987, 1); }
int lua_YoYo_HideVirtualKey(lua_State *_pL) { return DoLuaGMLCall(_pL, 1988, 1); }
int lua_virtual_key_add(lua_State *_pL) { return DoLuaGMLCall(_pL, 1989, 5); }
int lua_virtual_key_delete(lua_State *_pL) { return DoLuaGMLCall(_pL, 1990, 1); }
int lua_virtual_key_show(lua_State *_pL) { return DoLuaGMLCall(_pL, 1991, 1); }
int lua_virtual_key_hide(lua_State *_pL) { return DoLuaGMLCall(_pL, 1992, 1); }
int lua_YoYo_LoginAchievements(lua_State *_pL) { return DoLuaGMLCall(_pL, 1993, 0); }
int lua_YoYo_LogoutAchievements(lua_State *_pL) { return DoLuaGMLCall(_pL, 1994, 0); }
int lua_YoYo_PostAchievement(lua_State *_pL) { return DoLuaGMLCall(_pL, 1995, 2); }
int lua_YoYo_PostScore(lua_State *_pL) { return DoLuaGMLCall(_pL, 1996, 2); }
int lua_YoYo_AchievementsAvailable(lua_State *_pL) { return DoLuaGMLCall(_pL, 1997, 0); }
int lua_achievement_available(lua_State *_pL) { return DoLuaGMLCall(_pL, 1998, 0); }
int lua_achievement_post_score(lua_State *_pL) { return DoLuaGMLCall(_pL, 1999, 2); }
int lua_achievement_post(lua_State *_pL) { return DoLuaGMLCall(_pL, 2000, 2); }
int lua_achievement_increment(lua_State *_pL) { return DoLuaGMLCall(_pL, 2001, 2); }
int lua_achievement_event(lua_State *_pL) { return DoLuaGMLCall(_pL, 2002, 1); }
int lua_achievement_login(lua_State *_pL) { return DoLuaGMLCall(_pL, 2003, 0); }
int lua_achievement_logout(lua_State *_pL) { return DoLuaGMLCall(_pL, 2004, 0); }
int lua_achievement_reset(lua_State *_pL) { return DoLuaGMLCall(_pL, 2005, 0); }
int lua_achievement_show_achievements(lua_State *_pL) { return DoLuaGMLCall(_pL, 2006, 0); }
int lua_achievement_show(lua_State *_pL) { return DoLuaGMLCall(_pL, 2007, 2); }
int lua_achievement_show_leaderboards(lua_State *_pL) { return DoLuaGMLCall(_pL, 2008, 0); }
int lua_achievement_load_friends(lua_State *_pL) { return DoLuaGMLCall(_pL, 2009, 0); }
int lua_achievement_load_leaderboard(lua_State *_pL) { return DoLuaGMLCall(_pL, 2010, 4); }
int lua_achievement_get_pic(lua_State *_pL) { return DoLuaGMLCall(_pL, 2011, 1); }
int lua_achievement_get_info(lua_State *_pL) { return DoLuaGMLCall(_pL, 2012, 1); }
int lua_achievement_load_progress(lua_State *_pL) { return DoLuaGMLCall(_pL, 2013, 0); }
int lua_achievement_send_challenge(lua_State *_pL) { return DoLuaGMLCall(_pL, 2014, 5); }
int lua_achievement_get_challenges(lua_State *_pL) { return DoLuaGMLCall(_pL, 2015, 0); }
int lua_achievement_show_challenge_notifications(lua_State *_pL) { return DoLuaGMLCall(_pL, 2016, 3); }
int lua_cloud_file_save(lua_State *_pL) { return DoLuaGMLCall(_pL, 2017, 2); }
int lua_cloud_string_save(lua_State *_pL) { return DoLuaGMLCall(_pL, 2018, 2); }
int lua_cloud_synchronise(lua_State *_pL) { return DoLuaGMLCall(_pL, 2019, 0); }
int lua_YoYo_OpenURL(lua_State *_pL) { return DoLuaGMLCall(_pL, 2020, 1); }
int lua_YoYo_OpenURL_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 2021, 2); }
int lua_YoYo_OpenURL_full(lua_State *_pL) { return DoLuaGMLCall(_pL, 2022, 3); }
int lua_url_open(lua_State *_pL) { return DoLuaGMLCall(_pL, 2023, 1); }
int lua_url_open_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 2024, 2); }
int lua_url_open_full(lua_State *_pL) { return DoLuaGMLCall(_pL, 2025, 3); }
int lua_url_get_domain(lua_State *_pL) { return DoLuaGMLCall(_pL, 2026, 1); }
int lua_YoYo_EnableAds(lua_State *_pL) { return DoLuaGMLCall(_pL, 2027, 5); }
int lua_YoYo_DisableAds(lua_State *_pL) { return DoLuaGMLCall(_pL, 2028, 0); }
int lua_YoYo_LeaveRating(lua_State *_pL) { return DoLuaGMLCall(_pL, 2029, 4); }
int lua_ads_enable(lua_State *_pL) { return DoLuaGMLCall(_pL, 2030, 3); }
int lua_ads_disable(lua_State *_pL) { return DoLuaGMLCall(_pL, 2031, 1); }
int lua_ads_event(lua_State *_pL) { return DoLuaGMLCall(_pL, 2032, 1); }
int lua_ads_event_preload(lua_State *_pL) { return DoLuaGMLCall(_pL, 2033, 1); }
int lua_ads_get_display_width(lua_State *_pL) { return DoLuaGMLCall(_pL, 2034, 1); }
int lua_ads_get_display_height(lua_State *_pL) { return DoLuaGMLCall(_pL, 2035, 1); }
int lua_ads_move(lua_State *_pL) { return DoLuaGMLCall(_pL, 2036, 3); }
int lua_ads_interstitial_available(lua_State *_pL) { return DoLuaGMLCall(_pL, 2037, 0); }
int lua_ads_interstitial_display(lua_State *_pL) { return DoLuaGMLCall(_pL, 2038, 0); }
int lua_ads_engagement_available(lua_State *_pL) { return DoLuaGMLCall(_pL, 2039, 1); }
int lua_ads_engagement_launch(lua_State *_pL) { return DoLuaGMLCall(_pL, 2040, 1); }
int lua_ads_engagement_active(lua_State *_pL) { return DoLuaGMLCall(_pL, 2041, 1); }
int lua_ads_setup(lua_State *_pL) { return DoLuaGMLCall(_pL, 2042, 2); }
int lua_ads_set_reward_callback(lua_State *_pL) { return DoLuaGMLCall(_pL, 2043, 1); }
int lua_clickable_add(lua_State *_pL) { return DoLuaGMLCall(_pL, 2044, 6); }
int lua_clickable_add_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 2045, 8); }
int lua_clickable_change(lua_State *_pL) { return DoLuaGMLCall(_pL, 2046, 4); }
int lua_clickable_change_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 2047, 5); }
int lua_clickable_delete(lua_State *_pL) { return DoLuaGMLCall(_pL, 2048, 1); }
int lua_clickable_exists(lua_State *_pL) { return DoLuaGMLCall(_pL, 2049, 1); }
int lua_clickable_set_style(lua_State *_pL) { return DoLuaGMLCall(_pL, 2050, 2); }
int lua_shop_leave_rating(lua_State *_pL) { return DoLuaGMLCall(_pL, 2051, 4); }
int lua_YoYo_GetTimer(lua_State *_pL) { return DoLuaGMLCall(_pL, 2052, 0); }
int lua_YoYo_GetPlatform(lua_State *_pL) { return DoLuaGMLCall(_pL, 2053, 0); }
int lua_YoYo_GetDevice(lua_State *_pL) { return DoLuaGMLCall(_pL, 2054, 0); }
int lua_YoYo_GetCPUDetails(lua_State *_pL) { return DoLuaGMLCall(_pL, 2055, 0); }
int lua_YoYo_GetConfig(lua_State *_pL) { return DoLuaGMLCall(_pL, 2056, 0); }
int lua_YoYo_GetSessionKey(lua_State *_pL) { return DoLuaGMLCall(_pL, 2057, 0); }
int lua_YoYo_CheckSecurity(lua_State *_pL) { return DoLuaGMLCall(_pL, 2058, 1); }
int lua_get_timer(lua_State *_pL) { return DoLuaGMLCall(_pL, 2059, 0); }
int lua_os_get_config(lua_State *_pL) { return DoLuaGMLCall(_pL, 2060, 0); }
int lua_os_get_info(lua_State *_pL) { return DoLuaGMLCall(_pL, 2061, 0); }
int lua_os_get_language(lua_State *_pL) { return DoLuaGMLCall(_pL, 2062, 0); }
int lua_os_get_region(lua_State *_pL) { return DoLuaGMLCall(_pL, 2063, 0); }
int lua_os_request_permission(lua_State *_pL) { return DoLuaGMLCall(_pL, 2064, 1); }
int lua_os_check_permission(lua_State *_pL) { return DoLuaGMLCall(_pL, 2065, 1); }
int lua_code_is_compiled(lua_State *_pL) { return DoLuaGMLCall(_pL, 2066, 0); }
int lua_display_get_dpi_x(lua_State *_pL) { return DoLuaGMLCall(_pL, 2067, 0); }
int lua_display_get_dpi_y(lua_State *_pL) { return DoLuaGMLCall(_pL, 2068, 0); }
int lua_display_set_gui_size(lua_State *_pL) { return DoLuaGMLCall(_pL, 2069, 2); }
int lua_display_get_gui_width(lua_State *_pL) { return DoLuaGMLCall(_pL, 2070, 0); }
int lua_display_get_gui_height(lua_State *_pL) { return DoLuaGMLCall(_pL, 2071, 0); }
int lua_display_set_gui_maximise(lua_State *_pL) { return DoLuaGMLCall(_pL, 2072, 2); }
int lua_display_set_gui_maximize(lua_State *_pL) { return DoLuaGMLCall(_pL, 2073, 2); }
int lua_YoYo_OF_StartDashboard(lua_State *_pL) { return DoLuaGMLCall(_pL, 2074, 0); }
int lua_YoYo_OF_AddAchievement(lua_State *_pL) { return DoLuaGMLCall(_pL, 2075, 2); }
int lua_YoYo_OF_AddLeaderboard(lua_State *_pL) { return DoLuaGMLCall(_pL, 2076, 3); }
int lua_YoYo_OF_SendChallenge(lua_State *_pL) { return DoLuaGMLCall(_pL, 2077, 3); }
int lua_YoYo_OF_SendInvite(lua_State *_pL) { return DoLuaGMLCall(_pL, 2078, 1); }
int lua_YoYo_OF_SendSocial(lua_State *_pL) { return DoLuaGMLCall(_pL, 2079, 3); }
int lua_YoYo_OF_SetURL(lua_State *_pL) { return DoLuaGMLCall(_pL, 2080, 1); }
int lua_YoYo_OF_AcceptChallenge(lua_State *_pL) { return DoLuaGMLCall(_pL, 2081, 0); }
int lua_YoYo_OF_IsOnline(lua_State *_pL) { return DoLuaGMLCall(_pL, 2082, 0); }
int lua_YoYo_OF_SendChallengeResult(lua_State *_pL) { return DoLuaGMLCall(_pL, 2083, 2); }
int lua_openfeint_start(lua_State *_pL) { return DoLuaGMLCall(_pL, 2084, 0); }
int lua_achievement_map_achievement(lua_State *_pL) { return DoLuaGMLCall(_pL, 2085, 2); }
int lua_achievement_map_leaderboard(lua_State *_pL) { return DoLuaGMLCall(_pL, 2086, 3); }
int lua_openfeint_send_challenge(lua_State *_pL) { return DoLuaGMLCall(_pL, 2087, 3); }
int lua_openfeint_send_invite(lua_State *_pL) { return DoLuaGMLCall(_pL, 2088, 1); }
int lua_openfeint_send_social(lua_State *_pL) { return DoLuaGMLCall(_pL, 2089, 3); }
int lua_openfeint_set_url(lua_State *_pL) { return DoLuaGMLCall(_pL, 2090, 1); }
int lua_openfeint_accept_challenge(lua_State *_pL) { return DoLuaGMLCall(_pL, 2091, 0); }
int lua_achievement_login_status(lua_State *_pL) { return DoLuaGMLCall(_pL, 2092, 0); }
int lua_openfeint_send_result(lua_State *_pL) { return DoLuaGMLCall(_pL, 2093, 2); }
int lua_YoYo_MouseCheckButton(lua_State *_pL) { return DoLuaGMLCall(_pL, 2094, 2); }
int lua_YoYo_MouseCheckButtonPressed(lua_State *_pL) { return DoLuaGMLCall(_pL, 2095, 2); }
int lua_YoYo_MouseCheckButtonReleased(lua_State *_pL) { return DoLuaGMLCall(_pL, 2096, 2); }
int lua_YoYo_MouseX(lua_State *_pL) { return DoLuaGMLCall(_pL, 2097, 1); }
int lua_YoYo_MouseY(lua_State *_pL) { return DoLuaGMLCall(_pL, 2098, 1); }
int lua_YoYo_MouseXRaw(lua_State *_pL) { return DoLuaGMLCall(_pL, 2099, 1); }
int lua_YoYo_MouseYRaw(lua_State *_pL) { return DoLuaGMLCall(_pL, 2100, 1); }
int lua_YoYo_GetTiltX(lua_State *_pL) { return DoLuaGMLCall(_pL, 2101, 0); }
int lua_YoYo_GetTiltY(lua_State *_pL) { return DoLuaGMLCall(_pL, 2102, 0); }
int lua_YoYo_GetTiltZ(lua_State *_pL) { return DoLuaGMLCall(_pL, 2103, 0); }
int lua_YoYo_IsKeypadOpen(lua_State *_pL) { return DoLuaGMLCall(_pL, 2104, 0); }
int lua_device_mouse_check_button(lua_State *_pL) { return DoLuaGMLCall(_pL, 2105, 2); }
int lua_device_mouse_check_button_pressed(lua_State *_pL) { return DoLuaGMLCall(_pL, 2106, 2); }
int lua_device_mouse_check_button_released(lua_State *_pL) { return DoLuaGMLCall(_pL, 2107, 2); }
int lua_device_mouse_x(lua_State *_pL) { return DoLuaGMLCall(_pL, 2108, 1); }
int lua_device_mouse_y(lua_State *_pL) { return DoLuaGMLCall(_pL, 2109, 1); }
int lua_device_mouse_raw_x(lua_State *_pL) { return DoLuaGMLCall(_pL, 2110, 1); }
int lua_device_mouse_raw_y(lua_State *_pL) { return DoLuaGMLCall(_pL, 2111, 1); }
int lua_device_mouse_x_to_gui(lua_State *_pL) { return DoLuaGMLCall(_pL, 2112, 1); }
int lua_device_mouse_y_to_gui(lua_State *_pL) { return DoLuaGMLCall(_pL, 2113, 1); }
int lua_device_get_tilt_x(lua_State *_pL) { return DoLuaGMLCall(_pL, 2114, 0); }
int lua_device_get_tilt_y(lua_State *_pL) { return DoLuaGMLCall(_pL, 2115, 0); }
int lua_device_get_tilt_z(lua_State *_pL) { return DoLuaGMLCall(_pL, 2116, 0); }
int lua_device_is_keypad_open(lua_State *_pL) { return DoLuaGMLCall(_pL, 2117, 0); }
int lua_facebook_init(lua_State *_pL) { return DoLuaGMLCall(_pL, 2118, 0); }
int lua_facebook_login(lua_State *_pL) { return DoLuaGMLCall(_pL, 2119, 2); }
int lua_facebook_status(lua_State *_pL) { return DoLuaGMLCall(_pL, 2120, 0); }
int lua_facebook_graph_request(lua_State *_pL) { return DoLuaGMLCall(_pL, 2121, 4); }
int lua_facebook_dialog(lua_State *_pL) { return DoLuaGMLCall(_pL, 2122, 3); }
int lua_facebook_logout(lua_State *_pL) { return DoLuaGMLCall(_pL, 2123, 0); }
int lua_facebook_user_id(lua_State *_pL) { return DoLuaGMLCall(_pL, 2124, 0); }
int lua_facebook_accesstoken(lua_State *_pL) { return DoLuaGMLCall(_pL, 2125, 0); }
int lua_facebook_launch_offerwall(lua_State *_pL) { return DoLuaGMLCall(_pL, 2126, 1); }
int lua_facebook_post_message(lua_State *_pL) { return DoLuaGMLCall(_pL, 2127, 7); }
int lua_facebook_send_invite(lua_State *_pL) { return DoLuaGMLCall(_pL, 2128, 5); }
int lua_facebook_check_permission(lua_State *_pL) { return DoLuaGMLCall(_pL, 2129, 1); }
int lua_facebook_request_read_permissions(lua_State *_pL) { return DoLuaGMLCall(_pL, 2130, 1); }
int lua_facebook_request_publish_permissions(lua_State *_pL) { return DoLuaGMLCall(_pL, 2131, 1); }
int lua_YoYo_OSPauseEvent(lua_State *_pL) { return DoLuaGMLCall(_pL, 2132, 0); }
int lua_os_is_paused(lua_State *_pL) { return DoLuaGMLCall(_pL, 2133, 0); }
int lua_window_has_focus(lua_State *_pL) { return DoLuaGMLCall(_pL, 2134, 0); }
int lua_base64_encode(lua_State *_pL) { return DoLuaGMLCall(_pL, 2135, 1); }
int lua_base64_decode(lua_State *_pL) { return DoLuaGMLCall(_pL, 2136, 1); }
int lua_md5_string_unicode(lua_State *_pL) { return DoLuaGMLCall(_pL, 2137, 1); }
int lua_md5_string_utf8(lua_State *_pL) { return DoLuaGMLCall(_pL, 2138, 1); }
int lua_md5_file(lua_State *_pL) { return DoLuaGMLCall(_pL, 2139, 1); }
int lua_sha1_string_unicode(lua_State *_pL) { return DoLuaGMLCall(_pL, 2140, 1); }
int lua_sha1_string_utf8(lua_State *_pL) { return DoLuaGMLCall(_pL, 2141, 1); }
int lua_sha1_file(lua_State *_pL) { return DoLuaGMLCall(_pL, 2142, 1); }
int lua_os_is_network_connected(lua_State *_pL) { return DoLuaGMLCall(_pL, 2143, 0); }
int lua_os_powersave_enable(lua_State *_pL) { return DoLuaGMLCall(_pL, 2144, 1); }
int lua_os_lock_orientation(lua_State *_pL) { return DoLuaGMLCall(_pL, 2145, 1); }
int lua_analytics_event(lua_State *_pL) { return DoLuaGMLCall(_pL, 2146, 1); }
int lua_analytics_event_ext(lua_State *_pL) { return DoLuaGMLCall(_pL, 2147, -1); }
int lua_winphone_license_trial_version(lua_State *_pL) { return DoLuaGMLCall(_pL, 2148, 0); }
int lua_winphone_tile_title(lua_State *_pL) { return DoLuaGMLCall(_pL, 2149, 1); }
int lua_winphone_tile_count(lua_State *_pL) { return DoLuaGMLCall(_pL, 2150, 1); }
int lua_winphone_tile_back_title(lua_State *_pL) { return DoLuaGMLCall(_pL, 2151, 1); }
int lua_winphone_tile_back_content(lua_State *_pL) { return DoLuaGMLCall(_pL, 2152, 1); }
int lua_winphone_tile_back_content_wide(lua_State *_pL) { return DoLuaGMLCall(_pL, 2153, 1); }
int lua_winphone_tile_front_image(lua_State *_pL) { return DoLuaGMLCall(_pL, 2154, 1); }
int lua_winphone_tile_front_image_small(lua_State *_pL) { return DoLuaGMLCall(_pL, 2155, 1); }
int lua_winphone_tile_front_image_wide(lua_State *_pL) { return DoLuaGMLCall(_pL, 2156, 1); }
int lua_winphone_tile_back_image(lua_State *_pL) { return DoLuaGMLCall(_pL, 2157, 1); }
int lua_winphone_tile_back_image_wide(lua_State *_pL) { return DoLuaGMLCall(_pL, 2158, 1); }
int lua_winphone_tile_background_color(lua_State *_pL) { return DoLuaGMLCall(_pL, 2159, 1); }
int lua_winphone_tile_background_colour(lua_State *_pL) { return DoLuaGMLCall(_pL, 2160, 1); }
int lua_winphone_tile_icon_image(lua_State *_pL) { return DoLuaGMLCall(_pL, 2161, 1); }
int lua_winphone_tile_small_icon_image(lua_State *_pL) { return DoLuaGMLCall(_pL, 2162, 1); }
int lua_winphone_tile_wide_content(lua_State *_pL) { return DoLuaGMLCall(_pL, 2163, 2); }
int lua_winphone_tile_cycle_images(lua_State *_pL) { return DoLuaGMLCall(_pL, 2164, -1); }
int lua_winphone_tile_small_background_image(lua_State *_pL) { return DoLuaGMLCall(_pL, 2165, 1); }
int lua_gml_release_mode(lua_State *_pL) { return DoLuaGMLCall(_pL, 2166, 1); }
int lua_application_surface_draw_enable(lua_State *_pL) { return DoLuaGMLCall(_pL, 2167, 1); }
int lua_application_get_position(lua_State *_pL) { return DoLuaGMLCall(_pL, 2168, 0); }
int lua_application_surface_enable(lua_State *_pL) { return DoLuaGMLCall(_pL, 2169, 1); }
int lua_application_surface_is_enabled(lua_State *_pL) { return DoLuaGMLCall(_pL, 2170, 0); }
int lua_yyg_player_run(lua_State *_pL) { return DoLuaGMLCall(_pL, 2171, 4); }
int lua_yyg_player_restarted(lua_State *_pL) { return DoLuaGMLCall(_pL, 2172, 0); }
int lua_yyg_player_launch_args(lua_State *_pL) { return DoLuaGMLCall(_pL, 2173, 0); }
int lua_extension_stubfunc_real(lua_State *_pL) { return DoLuaGMLCall(_pL, 2174, 0); }
int lua_extension_stubfunc_string(lua_State *_pL) { return DoLuaGMLCall(_pL, 2175, 0); }
int lua_ps4_share_screenshot_enable(lua_State *_pL) { return DoLuaGMLCall(_pL, 2176, 1); }
int lua_ps4_share_video_enable(lua_State *_pL) { return DoLuaGMLCall(_pL, 2177, 1); }
int lua_ps4_touchpad_mouse_enable(lua_State *_pL) { return DoLuaGMLCall(_pL, 2178, 1); }
int lua_xboxone_package_check_license(lua_State *_pL) { return DoLuaGMLCall(_pL, 2179, 1); }
int lua_xboxone_get_user_count(lua_State *_pL) { return DoLuaGMLCall(_pL, 2180, 0); }
int lua_xboxone_get_user(lua_State *_pL) { return DoLuaGMLCall(_pL, 2181, 1); }
int lua_xboxone_get_activating_user(lua_State *_pL) { return DoLuaGMLCall(_pL, 2182, 1); }
int lua_xboxone_user_is_active(lua_State *_pL) { return DoLuaGMLCall(_pL, 2183, 1); }
int lua_xboxone_user_is_guest(lua_State *_pL) { return DoLuaGMLCall(_pL, 2184, 1); }
int lua_xboxone_user_is_signed_in(lua_State *_pL) { return DoLuaGMLCall(_pL, 2185, 1); }
int lua_xboxone_user_is_remote(lua_State *_pL) { return DoLuaGMLCall(_pL, 2186, 1); }
int lua_xboxone_gamedisplayname_for_user(lua_State *_pL) { return DoLuaGMLCall(_pL, 2187, 1); }
int lua_xboxone_appdisplayname_for_user(lua_State *_pL) { return DoLuaGMLCall(_pL, 2188, 1); }
int lua_xboxone_user_id_for_user(lua_State *_pL) { return DoLuaGMLCall(_pL, 2189, 1); }
int lua_xboxone_agegroup_for_user(lua_State *_pL) { return DoLuaGMLCall(_pL, 2190, 1); }
int lua_xboxone_gamerscore_for_user(lua_State *_pL) { return DoLuaGMLCall(_pL, 2191, 1); }
int lua_xboxone_reputation_for_user(lua_State *_pL) { return DoLuaGMLCall(_pL, 2192, 1); }
int lua_xboxone_user_for_pad(lua_State *_pL) { return DoLuaGMLCall(_pL, 2193, 1); }
int lua_xboxone_pad_count_for_user(lua_State *_pL) { return DoLuaGMLCall(_pL, 2194, 1); }
int lua_xboxone_pad_for_user(lua_State *_pL) { return DoLuaGMLCall(_pL, 2195, 2); }
int lua_xboxone_sponsor_for_user(lua_State *_pL) { return DoLuaGMLCall(_pL, 2196, 2); }
int lua_xboxone_show_account_picker(lua_State *_pL) { return DoLuaGMLCall(_pL, 2197, 2); }
int lua_xboxone_sprite_add_from_gamerpicture(lua_State *_pL) { return DoLuaGMLCall(_pL, 2198, 4); }
int lua_xboxone_show_profile_card_for_user(lua_State *_pL) { return DoLuaGMLCall(_pL, 2199, 2); }
int lua_xboxone_generate_player_session_id(lua_State *_pL) { return DoLuaGMLCall(_pL, 2200, 0); }
int lua_xboxone_set_savedata_user(lua_State *_pL) { return DoLuaGMLCall(_pL, 2201, 1); }
int lua_xboxone_get_savedata_user(lua_State *_pL) { return DoLuaGMLCall(_pL, 2202, 0); }
int lua_xboxone_get_file_error(lua_State *_pL) { return DoLuaGMLCall(_pL, 2203, 0); }
int lua_xboxone_was_terminated(lua_State *_pL) { return DoLuaGMLCall(_pL, 2204, 0); }
int lua_xboxone_is_suspending(lua_State *_pL) { return DoLuaGMLCall(_pL, 2205, 0); }
int lua_xboxone_is_constrained(lua_State *_pL) { return DoLuaGMLCall(_pL, 2206, 0); }
int lua_xboxone_suspend(lua_State *_pL) { return DoLuaGMLCall(_pL, 2207, 0); }
int lua_xboxone_show_help(lua_State *_pL) { return DoLuaGMLCall(_pL, 2208, 1); }
int lua_xboxone_license_trial_version(lua_State *_pL) { return DoLuaGMLCall(_pL, 2209, 0); }
int lua_xboxone_license_trial_user(lua_State *_pL) { return DoLuaGMLCall(_pL, 2210, 0); }
int lua_xboxone_license_trial_time_remaining(lua_State *_pL) { return DoLuaGMLCall(_pL, 2211, 0); }
int lua_xboxone_check_privilege(lua_State *_pL) { return DoLuaGMLCall(_pL, 2212, 3); }
int lua_xboxone_fire_event(lua_State *_pL) { return DoLuaGMLCall(_pL, 2213, -1); }
int lua_xboxone_get_stats_for_user(lua_State *_pL) { return DoLuaGMLCall(_pL, 2214, -1); }
int lua_xboxone_stats_setup(lua_State *_pL) { return DoLuaGMLCall(_pL, 2215, 2); }
int lua_xboxone_stats_set_stat_real(lua_State *_pL) { return DoLuaGMLCall(_pL, 2216, 3); }
int lua_xboxone_stats_set_stat_int(lua_State *_pL) { return DoLuaGMLCall(_pL, 2217, 3); }
int lua_xboxone_stats_set_stat_string(lua_State *_pL) { return DoLuaGMLCall(_pL, 2218, 3); }
int lua_xboxone_stats_delete_stat(lua_State *_pL) { return DoLuaGMLCall(_pL, 2219, 2); }
int lua_xboxone_stats_get_stat(lua_State *_pL) { return DoLuaGMLCall(_pL, 2220, 2); }
int lua_xboxone_stats_get_stat_names(lua_State *_pL) { return DoLuaGMLCall(_pL, 2221, 1); }
int lua_xboxone_stats_add_user(lua_State *_pL) { return DoLuaGMLCall(_pL, 2222, 1); }
int lua_xboxone_stats_remove_user(lua_State *_pL) { return DoLuaGMLCall(_pL, 2223, 1); }
int lua_xboxone_stats_flush_user(lua_State *_pL) { return DoLuaGMLCall(_pL, 2224, 2); }
int lua_xboxone_stats_get_leaderboard(lua_State *_pL) { return DoLuaGMLCall(_pL, 2225, 6); }
int lua_xboxone_stats_get_social_leaderboard(lua_State *_pL) { return DoLuaGMLCall(_pL, 2226, 7); }
int lua_xboxone_achievements_set_progress(lua_State *_pL) { return DoLuaGMLCall(_pL, 2227, 3); }
int lua_xboxone_set_rich_presence(lua_State *_pL) { return DoLuaGMLCall(_pL, 2228, 3); }
int lua_xboxone_matchmaking_create(lua_State *_pL) { return DoLuaGMLCall(_pL, 2229, 4); }
int lua_xboxone_matchmaking_find(lua_State *_pL) { return DoLuaGMLCall(_pL, 2230, 3); }
int lua_xboxone_matchmaking_start(lua_State *_pL) { return DoLuaGMLCall(_pL, 2231, 1); }
int lua_xboxone_matchmaking_stop(lua_State *_pL) { return DoLuaGMLCall(_pL, 2232, 1); }
int lua_xboxone_matchmaking_session_get_users(lua_State *_pL) { return DoLuaGMLCall(_pL, 2233, 1); }
int lua_xboxone_matchmaking_session_leave(lua_State *_pL) { return DoLuaGMLCall(_pL, 2234, 1); }
int lua_xboxone_matchmaking_send_invites(lua_State *_pL) { return DoLuaGMLCall(_pL, 2235, 3); }
int lua_xboxone_matchmaking_set_joinable_session(lua_State *_pL) { return DoLuaGMLCall(_pL, 2236, 2); }
int lua_xboxone_matchmaking_join_invite(lua_State *_pL) { return DoLuaGMLCall(_pL, 2237, 4); }
int lua_xboxone_matchmaking_join_session(lua_State *_pL) { return DoLuaGMLCall(_pL, 2238, 3); }
int lua_xboxone_matchmaking_set_find_timeout(lua_State *_pL) { return DoLuaGMLCall(_pL, 2239, 1); }
int lua_xboxone_chat_add_user_to_channel(lua_State *_pL) { return DoLuaGMLCall(_pL, 2240, 2); }
int lua_xboxone_chat_remove_user_from_channel(lua_State *_pL) { return DoLuaGMLCall(_pL, 2241, 2); }
int lua_xboxone_chat_set_muted(lua_State *_pL) { return DoLuaGMLCall(_pL, 2242, 1); }
int lua_xboxone_set_service_configuration_id(lua_State *_pL) { return DoLuaGMLCall(_pL, 2243, 1); }
int lua_xboxone_read_player_leaderboard(lua_State *_pL) { return DoLuaGMLCall(_pL, 2244, 4); }
int lua_xboxlive_get_user_count(lua_State *_pL) { return DoLuaGMLCall(_pL, 2245, 0); }
int lua_xboxlive_get_user(lua_State *_pL) { return DoLuaGMLCall(_pL, 2246, 1); }
int lua_xboxlive_get_activating_user(lua_State *_pL) { return DoLuaGMLCall(_pL, 2247, 1); }
int lua_xboxlive_user_is_active(lua_State *_pL) { return DoLuaGMLCall(_pL, 2248, 1); }
int lua_xboxlive_user_is_guest(lua_State *_pL) { return DoLuaGMLCall(_pL, 2249, 1); }
int lua_xboxlive_user_is_signed_in(lua_State *_pL) { return DoLuaGMLCall(_pL, 2250, 1); }
int lua_xboxlive_user_is_signing_in(lua_State *_pL) { return DoLuaGMLCall(_pL, 2251, 1); }
int lua_xboxlive_user_is_remote(lua_State *_pL) { return DoLuaGMLCall(_pL, 2252, 1); }
int lua_xboxlive_gamedisplayname_for_user(lua_State *_pL) { return DoLuaGMLCall(_pL, 2253, 1); }
int lua_xboxlive_appdisplayname_for_user(lua_State *_pL) { return DoLuaGMLCall(_pL, 2254, 1); }
int lua_xboxlive_gamertag_for_user(lua_State *_pL) { return DoLuaGMLCall(_pL, 2255, -1); }
int lua_xboxlive_user_id_for_user(lua_State *_pL) { return DoLuaGMLCall(_pL, 2256, 1); }
int lua_xboxlive_agegroup_for_user(lua_State *_pL) { return DoLuaGMLCall(_pL, 2257, 1); }
int lua_xboxlive_gamerscore_for_user(lua_State *_pL) { return DoLuaGMLCall(_pL, 2258, 1); }
int lua_xboxlive_reputation_for_user(lua_State *_pL) { return DoLuaGMLCall(_pL, 2259, 1); }
int lua_xboxlive_user_for_pad(lua_State *_pL) { return DoLuaGMLCall(_pL, 2260, 1); }
int lua_xboxlive_pad_count_for_user(lua_State *_pL) { return DoLuaGMLCall(_pL, 2261, 1); }
int lua_xboxlive_pad_for_user(lua_State *_pL) { return DoLuaGMLCall(_pL, 2262, 2); }
int lua_xboxlive_sponsor_for_user(lua_State *_pL) { return DoLuaGMLCall(_pL, 2263, 2); }
int lua_xboxlive_show_account_picker(lua_State *_pL) { return DoLuaGMLCall(_pL, 2264, 2); }
int lua_xboxlive_sprite_add_from_gamerpicture(lua_State *_pL) { return DoLuaGMLCall(_pL, 2265, 4); }
int lua_xboxlive_show_profile_card_for_user(lua_State *_pL) { return DoLuaGMLCall(_pL, 2266, 2); }
int lua_xboxlive_generate_player_session_id(lua_State *_pL) { return DoLuaGMLCall(_pL, 2267, 0); }
int lua_xboxlive_read_player_leaderboard(lua_State *_pL) { return DoLuaGMLCall(_pL, 2268, 4); }
int lua_xboxlive_set_savedata_user(lua_State *_pL) { return DoLuaGMLCall(_pL, 2269, 1); }
int lua_xboxlive_get_savedata_user(lua_State *_pL) { return DoLuaGMLCall(_pL, 2270, 0); }
int lua_xboxlive_get_file_error(lua_State *_pL) { return DoLuaGMLCall(_pL, 2271, 0); }
int lua_uwp_was_terminated(lua_State *_pL) { return DoLuaGMLCall(_pL, 2272, 0); }
int lua_uwp_is_suspending(lua_State *_pL) { return DoLuaGMLCall(_pL, 2273, 0); }
int lua_uwp_is_constrained(lua_State *_pL) { return DoLuaGMLCall(_pL, 2274, 0); }
int lua_uwp_suspend(lua_State *_pL) { return DoLuaGMLCall(_pL, 2275, 0); }
int lua_uwp_show_help(lua_State *_pL) { return DoLuaGMLCall(_pL, 2276, 1); }
int lua_uwp_license_trial_version(lua_State *_pL) { return DoLuaGMLCall(_pL, 2277, 0); }
int lua_uwp_license_trial_user(lua_State *_pL) { return DoLuaGMLCall(_pL, 2278, 0); }
int lua_uwp_license_trial_time_remaining(lua_State *_pL) { return DoLuaGMLCall(_pL, 2279, 0); }
int lua_uwp_check_privilege(lua_State *_pL) { return DoLuaGMLCall(_pL, 2280, 3); }
int lua_xboxlive_fire_event(lua_State *_pL) { return DoLuaGMLCall(_pL, 2281, -1); }
int lua_xboxlive_get_stats_for_user(lua_State *_pL) { return DoLuaGMLCall(_pL, 2282, -1); }
int lua_xboxlive_stats_setup(lua_State *_pL) { return DoLuaGMLCall(_pL, 2283, 2); }
int lua_xboxlive_stats_set_stat_real(lua_State *_pL) { return DoLuaGMLCall(_pL, 2284, 3); }
int lua_xboxlive_stats_set_stat_int(lua_State *_pL) { return DoLuaGMLCall(_pL, 2285, 3); }
int lua_xboxlive_stats_set_stat_string(lua_State *_pL) { return DoLuaGMLCall(_pL, 2286, 3); }
int lua_xboxlive_stats_delete_stat(lua_State *_pL) { return DoLuaGMLCall(_pL, 2287, 2); }
int lua_xboxlive_stats_get_stat(lua_State *_pL) { return DoLuaGMLCall(_pL, 2288, 2); }
int lua_xboxlive_stats_get_stat_names(lua_State *_pL) { return DoLuaGMLCall(_pL, 2289, 1); }
int lua_xboxlive_stats_add_user(lua_State *_pL) { return DoLuaGMLCall(_pL, 2290, 1); }
int lua_xboxlive_stats_remove_user(lua_State *_pL) { return DoLuaGMLCall(_pL, 2291, 1); }
int lua_xboxlive_stats_flush_user(lua_State *_pL) { return DoLuaGMLCall(_pL, 2292, 2); }
int lua_xboxlive_stats_get_leaderboard(lua_State *_pL) { return DoLuaGMLCall(_pL, 2293, 6); }
int lua_xboxlive_stats_get_social_leaderboard(lua_State *_pL) { return DoLuaGMLCall(_pL, 2294, 7); }
int lua_xboxlive_achievements_set_progress(lua_State *_pL) { return DoLuaGMLCall(_pL, 2295, 3); }
int lua_xboxlive_set_rich_presence(lua_State *_pL) { return DoLuaGMLCall(_pL, 2296, 3); }
int lua_xboxlive_matchmaking_create(lua_State *_pL) { return DoLuaGMLCall(_pL, 2297, -1); }
int lua_xboxlive_matchmaking_find(lua_State *_pL) { return DoLuaGMLCall(_pL, 2298, -1); }
int lua_xboxlive_matchmaking_start(lua_State *_pL) { return DoLuaGMLCall(_pL, 2299, 1); }
int lua_xboxlive_matchmaking_stop(lua_State *_pL) { return DoLuaGMLCall(_pL, 2300, 1); }
int lua_xboxlive_matchmaking_session_get_users(lua_State *_pL) { return DoLuaGMLCall(_pL, 2301, 1); }
int lua_xboxlive_matchmaking_session_leave(lua_State *_pL) { return DoLuaGMLCall(_pL, 2302, 1); }
int lua_xboxlive_matchmaking_send_invites(lua_State *_pL) { return DoLuaGMLCall(_pL, 2303, 3); }
int lua_xboxlive_matchmaking_set_joinable_session(lua_State *_pL) { return DoLuaGMLCall(_pL, 2304, 2); }
int lua_xboxlive_matchmaking_join_invite(lua_State *_pL) { return DoLuaGMLCall(_pL, 2305, 4); }
int lua_xboxlive_matchmaking_join_session(lua_State *_pL) { return DoLuaGMLCall(_pL, 2306, 3); }
int lua_xboxlive_matchmaking_set_find_timeout(lua_State *_pL) { return DoLuaGMLCall(_pL, 2307, 1); }
int lua_xboxlive_chat_add_user_to_channel(lua_State *_pL) { return DoLuaGMLCall(_pL, 2308, 2); }
int lua_xboxlive_chat_remove_user_from_channel(lua_State *_pL) { return DoLuaGMLCall(_pL, 2309, 2); }
int lua_xboxlive_chat_set_muted(lua_State *_pL) { return DoLuaGMLCall(_pL, 2310, 2); }
int lua_xboxlive_set_service_configuration_id(lua_State *_pL) { return DoLuaGMLCall(_pL, 2311, 1); }
int lua_psn_get_leaderboard_score_range(lua_State *_pL) { return DoLuaGMLCall(_pL, 2312, 4); }
int lua_psn_default_user_name(lua_State *_pL) { return DoLuaGMLCall(_pL, 2313, 0); }
int lua_psn_name_for_pad(lua_State *_pL) { return DoLuaGMLCall(_pL, 2314, 1); }
int lua_psn_unlock_trophy(lua_State *_pL) { return DoLuaGMLCall(_pL, 2315, 2); }
int lua_psn_get_trophy_unlock_state(lua_State *_pL) { return DoLuaGMLCall(_pL, 2316, 1); }
int lua_psn_init_np_libs(lua_State *_pL) { return DoLuaGMLCall(_pL, 2317, 3); }
int lua_psn_exit_np_libs(lua_State *_pL) { return DoLuaGMLCall(_pL, 2318, 0); }
int lua_psn_get_leaderboard_score(lua_State *_pL) { return DoLuaGMLCall(_pL, 2319, 2); }
int lua_psn_post_leaderboard_score(lua_State *_pL) { return DoLuaGMLCall(_pL, 2320, 3); }
int lua_psn_post_leaderboard_score_comment(lua_State *_pL) { return DoLuaGMLCall(_pL, 2321, 4); }
int lua_psn_check_np_availability(lua_State *_pL) { return DoLuaGMLCall(_pL, 2322, 2); }
int lua_psn_tick_error_dialog(lua_State *_pL) { return DoLuaGMLCall(_pL, 2323, 0); }
int lua_psn_get_friends_scores(lua_State *_pL) { return DoLuaGMLCall(_pL, 2324, 4); }
int lua_psn_name_for_user(lua_State *_pL) { return DoLuaGMLCall(_pL, 2325, 1); }
int lua_psn_default_user(lua_State *_pL) { return DoLuaGMLCall(_pL, 2326, 0); }
int lua_psn_user_for_pad(lua_State *_pL) { return DoLuaGMLCall(_pL, 2327, 1); }
int lua_matchmaking_reset_create_params(lua_State *_pL) { return DoLuaGMLCall(_pL, 2328, 0); }
int lua_matchmaking_add_create_param(lua_State *_pL) { return DoLuaGMLCall(_pL, 2329, 2); }
int lua_matchmaking_session_create(lua_State *_pL) { return DoLuaGMLCall(_pL, 2330, 2); }
int lua_matchmaking_session_get_users(lua_State *_pL) { return DoLuaGMLCall(_pL, 2331, 1); }
int lua_matchmaking_session_get_owner(lua_State *_pL) { return DoLuaGMLCall(_pL, 2332, 1); }
int lua_matchmaking_session_set_closed(lua_State *_pL) { return DoLuaGMLCall(_pL, 2333, 1); }
int lua_matchmaking_session_set_open(lua_State *_pL) { return DoLuaGMLCall(_pL, 2334, 1); }
int lua_matchmaking_session_set_hidden(lua_State *_pL) { return DoLuaGMLCall(_pL, 2335, 1); }
int lua_matchmaking_reset_find_params(lua_State *_pL) { return DoLuaGMLCall(_pL, 2336, 0); }
int lua_matchmaking_add_find_param(lua_State *_pL) { return DoLuaGMLCall(_pL, 2337, 3); }
int lua_matchmaking_session_find(lua_State *_pL) { return DoLuaGMLCall(_pL, 2338, 0); }
int lua_matchmaking_session_join(lua_State *_pL) { return DoLuaGMLCall(_pL, 2339, 1); }
int lua_matchmaking_session_leave(lua_State *_pL) { return DoLuaGMLCall(_pL, 2340, 1); }
int lua_matchmaking_session_update(lua_State *_pL) { return DoLuaGMLCall(_pL, 2341, 1); }
int lua_matchmaking_start(lua_State *_pL) { return DoLuaGMLCall(_pL, 2342, 2); }
int lua_matchmaking_stop(lua_State *_pL) { return DoLuaGMLCall(_pL, 2343, 0); }
int lua_matchmaking_session_invite_start(lua_State *_pL) { return DoLuaGMLCall(_pL, 2344, 1); }
int lua_matchmaking_send_invites_no_ui(lua_State *_pL) { return DoLuaGMLCall(_pL, 2345, 4); }
int lua_matchmaking_send_invites(lua_State *_pL) { return DoLuaGMLCall(_pL, 2346, 3); }
int lua_matchmaking_tick_invites(lua_State *_pL) { return DoLuaGMLCall(_pL, 2347, 0); }
int lua_matchmaking_join_invite(lua_State *_pL) { return DoLuaGMLCall(_pL, 2348, 1); }
int lua_psn_np_check_plus(lua_State *_pL) { return DoLuaGMLCall(_pL, 2349, 3); }
int lua_psn_np_commerce_dialog_open(lua_State *_pL) { return DoLuaGMLCall(_pL, 2350, 3); }
int lua_psn_np_commerce_dialog_tick(lua_State *_pL) { return DoLuaGMLCall(_pL, 2351, 0); }
int lua_psn_np_notify_plus_feature(lua_State *_pL) { return DoLuaGMLCall(_pL, 2352, 3); }
int lua_psn_set_content_restriction(lua_State *_pL) { return DoLuaGMLCall(_pL, 2353, 1); }
int lua_psn_load_modules(lua_State *_pL) { return DoLuaGMLCall(_pL, 2354, 0); }
int lua_psn_get_avatar_url(lua_State *_pL) { return DoLuaGMLCall(_pL, 2355, 1); }
int lua_psn_get_tus_data(lua_State *_pL) { return DoLuaGMLCall(_pL, 2356, 2); }
int lua_psn_set_tus_data(lua_State *_pL) { return DoLuaGMLCall(_pL, 2357, 4); }
int lua_psn_get_tus_variable(lua_State *_pL) { return DoLuaGMLCall(_pL, 2358, 2); }
int lua_psn_set_tus_variable(lua_State *_pL) { return DoLuaGMLCall(_pL, 2359, 3); }
int lua_psn_delete_tus_data(lua_State *_pL) { return DoLuaGMLCall(_pL, 2360, 2); }
int lua_psn_content_restriction_add(lua_State *_pL) { return DoLuaGMLCall(_pL, 2361, 2); }
int lua_psn_net_check(lua_State *_pL) { return DoLuaGMLCall(_pL, 2362, 1); }
int lua_psn_setup_trophies(lua_State *_pL) { return DoLuaGMLCall(_pL, 2363, 0); }
int lua_psn_tick(lua_State *_pL) { return DoLuaGMLCall(_pL, 2364, 0); }
int lua_psn_init_trophy(lua_State *_pL) { return DoLuaGMLCall(_pL, 2365, 1); }
int lua_psn_np_status(lua_State *_pL) { return DoLuaGMLCall(_pL, 2366, 1); }
int lua_psn_show_error_dialog(lua_State *_pL) { return DoLuaGMLCall(_pL, 2367, 1); }
int lua_psn_check_free_space(lua_State *_pL) { return DoLuaGMLCall(_pL, 2368, 2); }
int lua_psn_get_entitlement_list(lua_State *_pL) { return DoLuaGMLCall(_pL, 2369, 0); }
int lua_video_open(lua_State *_pL) { return DoLuaGMLCall(_pL, 2370, 1); }
int lua_video_close(lua_State *_pL) { return DoLuaGMLCall(_pL, 2371, 0); }
int lua_video_draw(lua_State *_pL) { return DoLuaGMLCall(_pL, 2372, 0); }
int lua_video_set_volume(lua_State *_pL) { return DoLuaGMLCall(_pL, 2373, 1); }
int lua_switch_get_operation_mode(lua_State *_pL) { return DoLuaGMLCall(_pL, 2374, 0); }
int lua_switch_get_performance_mode(lua_State *_pL) { return DoLuaGMLCall(_pL, 2375, 0); }
int lua_switch_set_performance_config(lua_State *_pL) { return DoLuaGMLCall(_pL, 2376, 2); }
int lua_switch_get_performance_config(lua_State *_pL) { return DoLuaGMLCall(_pL, 2377, 1); }
int lua_switch_language_get_desired_language(lua_State *_pL) { return DoLuaGMLCall(_pL, 2378, 0); }
int lua_switch_set_local_network_mode(lua_State *_pL) { return DoLuaGMLCall(_pL, 2379, 1); }
int lua_switch_controller_vibration_permitted(lua_State *_pL) { return DoLuaGMLCall(_pL, 2380, 0); }
int lua_switch_controller_show_strap_guide(lua_State *_pL) { return DoLuaGMLCall(_pL, 2381, 0); }
int lua_switch_controller_support_show(lua_State *_pL) { return DoLuaGMLCall(_pL, 2382, 0); }
int lua_switch_controller_support_set_defaults(lua_State *_pL) { return DoLuaGMLCall(_pL, 2383, 0); }
int lua_switch_controller_support_set_all(lua_State *_pL) { return DoLuaGMLCall(_pL, 2384, 8); }
int lua_switch_controller_support_set_identification_color(lua_State *_pL) { return DoLuaGMLCall(_pL, 2385, 2); }
int lua_switch_controller_support_set_identification_colour(lua_State *_pL) { return DoLuaGMLCall(_pL, 2386, 2); }
int lua_switch_controller_support_set_show_explain_text(lua_State *_pL) { return DoLuaGMLCall(_pL, 2387, 1); }
int lua_switch_controller_support_set_show_identification_colors(lua_State *_pL) { return DoLuaGMLCall(_pL, 2388, 1); }
int lua_switch_controller_support_set_show_identification_colours(lua_State *_pL) { return DoLuaGMLCall(_pL, 2389, 1); }
int lua_switch_controller_support_set_left_justify(lua_State *_pL) { return DoLuaGMLCall(_pL, 2390, 1); }
int lua_switch_controller_support_set_permit_joycon_dual(lua_State *_pL) { return DoLuaGMLCall(_pL, 2391, 1); }
int lua_switch_controller_support_set_singleplayer_only(lua_State *_pL) { return DoLuaGMLCall(_pL, 2392, 1); }
int lua_switch_controller_support_set_maintain_connections(lua_State *_pL) { return DoLuaGMLCall(_pL, 2393, 1); }
int lua_switch_controller_support_set_player_min(lua_State *_pL) { return DoLuaGMLCall(_pL, 2394, 1); }
int lua_switch_controller_support_set_player_max(lua_State *_pL) { return DoLuaGMLCall(_pL, 2395, 1); }
int lua_switch_controller_support_set_explain_text(lua_State *_pL) { return DoLuaGMLCall(_pL, 2396, 2); }
int lua_switch_controller_support_get_player_count(lua_State *_pL) { return DoLuaGMLCall(_pL, 2397, 0); }
int lua_switch_controller_support_get_selected_id(lua_State *_pL) { return DoLuaGMLCall(_pL, 2398, 0); }
int lua_switch_controller_joycon_set_holdtype(lua_State *_pL) { return DoLuaGMLCall(_pL, 2399, 1); }
int lua_switch_controller_joycon_get_holdtype(lua_State *_pL) { return DoLuaGMLCall(_pL, 2400, 0); }
int lua_switch_controller_joycon_left_connected(lua_State *_pL) { return DoLuaGMLCall(_pL, 2401, 1); }
int lua_switch_controller_joycon_right_connected(lua_State *_pL) { return DoLuaGMLCall(_pL, 2402, 1); }
int lua_switch_controller_set_supported_styles(lua_State *_pL) { return DoLuaGMLCall(_pL, 2403, 1); }
int lua_switch_controller_get_supported_styles(lua_State *_pL) { return DoLuaGMLCall(_pL, 2404, 0); }
int lua_switch_controller_set_handheld_activation_mode(lua_State *_pL) { return DoLuaGMLCall(_pL, 2405, 1); }
int lua_switch_controller_get_handheld_activation_mode(lua_State *_pL) { return DoLuaGMLCall(_pL, 2406, 0); }
int lua_switch_controller_vibrate_hd(lua_State *_pL) { return DoLuaGMLCall(_pL, 2407, 6); }
int lua_switch_controller_acceleration(lua_State *_pL) { return DoLuaGMLCall(_pL, 2408, -1); }
int lua_switch_controller_angular_velocity(lua_State *_pL) { return DoLuaGMLCall(_pL, 2409, -1); }
int lua_switch_controller_direction(lua_State *_pL) { return DoLuaGMLCall(_pL, 2410, -1); }
int lua_switch_controller_angle(lua_State *_pL) { return DoLuaGMLCall(_pL, 2411, -1); }
int lua_switch_controller_is_at_rest(lua_State *_pL) { return DoLuaGMLCall(_pL, 2412, -1); }
int lua_switch_controller_get_sixaxis_handle_count(lua_State *_pL) { return DoLuaGMLCall(_pL, 2413, 1); }
int lua_switch_controller_set_gyro_zero_drift_mode(lua_State *_pL) { return DoLuaGMLCall(_pL, 2414, 2); }
int lua_switch_controller_get_gyro_zero_drift_mode(lua_State *_pL) { return DoLuaGMLCall(_pL, 2415, 3); }
int lua_switch_controller_is_sensor_fusion_enabled(lua_State *_pL) { return DoLuaGMLCall(_pL, 2416, 2); }
int lua_switch_controller_enable_sensor_fusion(lua_State *_pL) { return DoLuaGMLCall(_pL, 2417, 3); }
int lua_switch_controller_set_sensor_fusion_params(lua_State *_pL) { return DoLuaGMLCall(_pL, 2418, 4); }
int lua_switch_controller_get_sensor_fusion_params(lua_State *_pL) { return DoLuaGMLCall(_pL, 2419, 2); }
int lua_switch_controller_reset_sensor_fusion_params(lua_State *_pL) { return DoLuaGMLCall(_pL, 2420, 2); }
int lua_switch_screenshot_disable(lua_State *_pL) { return DoLuaGMLCall(_pL, 2421, 0); }
int lua_switch_screenshot_enable(lua_State *_pL) { return DoLuaGMLCall(_pL, 2422, 0); }
int lua_switch_screenshot_set_orientation(lua_State *_pL) { return DoLuaGMLCall(_pL, 2423, 1); }
int lua_switch_recording_enable(lua_State *_pL) { return DoLuaGMLCall(_pL, 2424, 0); }
int lua_switch_recording_disable(lua_State *_pL) { return DoLuaGMLCall(_pL, 2425, 0); }
int lua_switch_save_data_mount(lua_State *_pL) { return DoLuaGMLCall(_pL, 2426, 1); }
int lua_switch_save_data_commit(lua_State *_pL) { return DoLuaGMLCall(_pL, 2427, 0); }
int lua_switch_save_data_unmount(lua_State *_pL) { return DoLuaGMLCall(_pL, 2428, 0); }
int lua_switch_theme_set(lua_State *_pL) { return DoLuaGMLCall(_pL, 2429, 1); }
int lua_switch_add_ssl_certificate(lua_State *_pL) { return DoLuaGMLCall(_pL, 2430, 2); }
int lua_switch_accounts_get_accounts(lua_State *_pL) { return DoLuaGMLCall(_pL, 2431, 0); }
int lua_switch_accounts_get_nickname(lua_State *_pL) { return DoLuaGMLCall(_pL, 2432, 1); }
int lua_switch_accounts_open_preselected_user(lua_State *_pL) { return DoLuaGMLCall(_pL, 2433, 0); }
int lua_switch_accounts_open_user(lua_State *_pL) { return DoLuaGMLCall(_pL, 2434, 1); }
int lua_switch_accounts_close_user(lua_State *_pL) { return DoLuaGMLCall(_pL, 2435, 1); }
int lua_switch_accounts_login_user(lua_State *_pL) { return DoLuaGMLCall(_pL, 2436, 1); }
int lua_switch_accounts_is_user_open(lua_State *_pL) { return DoLuaGMLCall(_pL, 2437, 1); }
int lua_switch_accounts_is_user_online(lua_State *_pL) { return DoLuaGMLCall(_pL, 2438, 1); }
int lua_switch_accounts_select_account(lua_State *_pL) { return DoLuaGMLCall(_pL, 2439, 3); }
int lua_switch_accounts_get_online_token(lua_State *_pL) { return DoLuaGMLCall(_pL, 2440, 1); }
int lua_switch_irsensor_get_mode(lua_State *_pL) { return DoLuaGMLCall(_pL, 2441, 1); }
int lua_switch_irsensor_set_mode(lua_State *_pL) { return DoLuaGMLCall(_pL, 2442, 2); }
int lua_switch_irsensor_common_config_set_all(lua_State *_pL) { return DoLuaGMLCall(_pL, 2443, 5); }
int lua_switch_irsensor_common_config_set_exposure_time(lua_State *_pL) { return DoLuaGMLCall(_pL, 2444, 2); }
int lua_switch_irsensor_common_config_set_light_target(lua_State *_pL) { return DoLuaGMLCall(_pL, 2445, 2); }
int lua_switch_irsensor_common_config_set_gain(lua_State *_pL) { return DoLuaGMLCall(_pL, 2446, 2); }
int lua_switch_irsensor_common_config_is_negative_image_used(lua_State *_pL) { return DoLuaGMLCall(_pL, 2447, 2); }
int lua_switch_irsensor_cluster_config_set_defaults(lua_State *_pL) { return DoLuaGMLCall(_pL, 2448, 1); }
int lua_switch_irsensor_cluster_config_set_window_of_interest(lua_State *_pL) { return DoLuaGMLCall(_pL, 2449, 5); }
int lua_switch_irsensor_cluster_config_set_object_pixel_count_min(lua_State *_pL) { return DoLuaGMLCall(_pL, 2450, 2); }
int lua_switch_irsensor_cluster_config_set_object_pixel_count_max(lua_State *_pL) { return DoLuaGMLCall(_pL, 2451, 2); }
int lua_switch_irsensor_cluster_config_set_object_intensity_min(lua_State *_pL) { return DoLuaGMLCall(_pL, 2452, 2); }
int lua_switch_irsensor_cluster_config_set_external_light_filtering(lua_State *_pL) { return DoLuaGMLCall(_pL, 2453, 2); }
int lua_switch_irsensor_cluster_create_state_buffer(lua_State *_pL) { return DoLuaGMLCall(_pL, 2454, 1); }
int lua_switch_irsensor_moment_config_set_defaults(lua_State *_pL) { return DoLuaGMLCall(_pL, 2455, 1); }
int lua_switch_irsensor_moment_config_set_window_of_interest(lua_State *_pL) { return DoLuaGMLCall(_pL, 2456, 5); }
int lua_switch_irsensor_moment_config_set_preprocess(lua_State *_pL) { return DoLuaGMLCall(_pL, 2457, 2); }
int lua_switch_irsensor_moment_config_set_preprocess_intensity_threshold(lua_State *_pL) { return DoLuaGMLCall(_pL, 2458, 2); }
int lua_switch_irsensor_moment_create_state_buffer(lua_State *_pL) { return DoLuaGMLCall(_pL, 2459, 1); }
int lua_switch_irsensor_image_config_set_defaults(lua_State *_pL) { return DoLuaGMLCall(_pL, 2460, 1); }
int lua_switch_irsensor_image_config_set_format(lua_State *_pL) { return DoLuaGMLCall(_pL, 2461, 2); }
int lua_switch_irsensor_image_config_set_orig_format(lua_State *_pL) { return DoLuaGMLCall(_pL, 2462, 2); }
int lua_switch_irsensor_image_config_set_trimming_format(lua_State *_pL) { return DoLuaGMLCall(_pL, 2463, 2); }
int lua_switch_irsensor_image_config_set_trimming_start(lua_State *_pL) { return DoLuaGMLCall(_pL, 2464, 3); }
int lua_switch_irsensor_image_config_set_external_light_filtering(lua_State *_pL) { return DoLuaGMLCall(_pL, 2465, 2); }
int lua_switch_irsensor_image_create_state_buffers(lua_State *_pL) { return DoLuaGMLCall(_pL, 2466, 1); }
int lua_switch_irsensor_hand_config_set_mode(lua_State *_pL) { return DoLuaGMLCall(_pL, 2467, 2); }
int lua_switch_irsensor_hand_create_state_buffers(lua_State *_pL) { return DoLuaGMLCall(_pL, 2468, 1); }
int lua_switch_bnvib_load(lua_State *_pL) { return DoLuaGMLCall(_pL, 2469, 1); }
int lua_switch_bnvib_unload(lua_State *_pL) { return DoLuaGMLCall(_pL, 2470, 1); }
int lua_switch_bnvib_get_value(lua_State *_pL) { return DoLuaGMLCall(_pL, 2471, 2); }
int lua_switch_bnvib_is_looping(lua_State *_pL) { return DoLuaGMLCall(_pL, 2472, 1); }
int lua_switch_bnvib_get_loop_end_position(lua_State *_pL) { return DoLuaGMLCall(_pL, 2473, 1); }
int lua_switch_bnvib_get_loop_interval(lua_State *_pL) { return DoLuaGMLCall(_pL, 2474, 1); }
int lua_switch_bnvib_get_loop_start_position(lua_State *_pL) { return DoLuaGMLCall(_pL, 2475, 1); }
int lua_switch_bnvib_get_length(lua_State *_pL) { return DoLuaGMLCall(_pL, 2476, 1); }
int lua_switch_bnvib_get_sampling_rate(lua_State *_pL) { return DoLuaGMLCall(_pL, 2477, 1); }
int lua_switch_matchmaking_start(lua_State *_pL) { return DoLuaGMLCall(_pL, 2478, 1); }
int lua_switch_matchmaking_stop(lua_State *_pL) { return DoLuaGMLCall(_pL, 2479, 1); }
int lua_switch_matchmaking_session_create(lua_State *_pL) { return DoLuaGMLCall(_pL, 2480, 6); }
int lua_switch_matchmaking_session_leave(lua_State *_pL) { return DoLuaGMLCall(_pL, 2481, 2); }
int lua_switch_matchmaking_session_find(lua_State *_pL) { return DoLuaGMLCall(_pL, 2482, 3); }
int lua_switch_matchmaking_session_join(lua_State *_pL) { return DoLuaGMLCall(_pL, 2483, 2); }
int lua_switch_matchmaking_session_autojoin(lua_State *_pL) { return DoLuaGMLCall(_pL, 2484, 3); }
int lua_switch_gameserver_login_user(lua_State *_pL) { return DoLuaGMLCall(_pL, 2485, 3); }
int lua_switch_gameserver_logout_user(lua_State *_pL) { return DoLuaGMLCall(_pL, 2486, 1); }
int lua_switch_controller_get_default_joycon_assignment(lua_State *_pL) { return DoLuaGMLCall(_pL, 2487, 0); }
int lua_switch_controller_set_default_joycon_assignment(lua_State *_pL) { return DoLuaGMLCall(_pL, 2488, 1); }
int lua_switch_controller_start_lr_assignment(lua_State *_pL) { return DoLuaGMLCall(_pL, 2489, 0); }
int lua_switch_controller_stop_lr_assignment(lua_State *_pL) { return DoLuaGMLCall(_pL, 2490, 0); }
int lua_switch_leaderboard_get_scores(lua_State *_pL) { return DoLuaGMLCall(_pL, 2491, -1); }
int lua_switch_leaderboard_post_score(lua_State *_pL) { return DoLuaGMLCall(_pL, 2492, 3); }
int lua_switch_leaderboard_post_common_data(lua_State *_pL) { return DoLuaGMLCall(_pL, 2493, -1); }
int lua_switch_error_show_os_code(lua_State *_pL) { return DoLuaGMLCall(_pL, 2494, 1); }
int lua_switch_show_store(lua_State *_pL) { return DoLuaGMLCall(_pL, 2495, 1); }
int lua_switch_error_get_os_code_info(lua_State *_pL) { return DoLuaGMLCall(_pL, 2496, 1); }
int lua_switch_error_begin(lua_State *_pL) { return DoLuaGMLCall(_pL, 2497, 0); }
int lua_switch_error_end(lua_State *_pL) { return DoLuaGMLCall(_pL, 2498, 0); }
int lua_switch_error_set_application_code(lua_State *_pL) { return DoLuaGMLCall(_pL, 2499, 1); }
int lua_switch_error_set_dialog_message(lua_State *_pL) { return DoLuaGMLCall(_pL, 2500, 1); }
int lua_switch_error_set_fullscreen_message(lua_State *_pL) { return DoLuaGMLCall(_pL, 2501, 1); }
int lua_switch_error_set_language_code(lua_State *_pL) { return DoLuaGMLCall(_pL, 2502, 1); }
int lua_ERROR(lua_State *_pL) { return DoLuaGMLCall(_pL, 2506, 1); }
int lua_testFailed(lua_State *_pL) { return DoLuaGMLCall(_pL, 2507, 1); }
int lua_win8_livetile_tile_notification(lua_State *_pL) { return DoLuaGMLCall(_pL, 2529, 4); }
int lua_win8_livetile_tile_clear(lua_State *_pL) { return DoLuaGMLCall(_pL, 2530, 0); }
int lua_win8_livetile_badge_notification(lua_State *_pL) { return DoLuaGMLCall(_pL, 2531, 1); }
int lua_win8_livetile_badge_clear(lua_State *_pL) { return DoLuaGMLCall(_pL, 2532, 0); }
int lua_win8_livetile_queue_enable(lua_State *_pL) { return DoLuaGMLCall(_pL, 2533, 1); }
int lua_win8_appbar_enable(lua_State *_pL) { return DoLuaGMLCall(_pL, 2534, 1); }
int lua_win8_appbar_add_element(lua_State *_pL) { return DoLuaGMLCall(_pL, 2535, 6); }
int lua_win8_appbar_remove_element(lua_State *_pL) { return DoLuaGMLCall(_pL, 2536, 1); }
int lua_win8_share_image(lua_State *_pL) { return DoLuaGMLCall(_pL, 2537, 3); }
int lua_win8_share_screenshot(lua_State *_pL) { return DoLuaGMLCall(_pL, 2538, 2); }
int lua_win8_share_file(lua_State *_pL) { return DoLuaGMLCall(_pL, 2539, 3); }
int lua_win8_share_url(lua_State *_pL) { return DoLuaGMLCall(_pL, 2540, 3); }
int lua_win8_share_text(lua_State *_pL) { return DoLuaGMLCall(_pL, 2541, 3); }
int lua_win8_settingscharm_add_entry(lua_State *_pL) { return DoLuaGMLCall(_pL, 2542, 2); }
int lua_win8_settingscharm_add_html_entry(lua_State *_pL) { return DoLuaGMLCall(_pL, 2543, 3); }
int lua_win8_settingscharm_add_xaml_entry(lua_State *_pL) { return DoLuaGMLCall(_pL, 2544, 4); }
int lua_win8_settingscharm_set_xaml_property(lua_State *_pL) { return DoLuaGMLCall(_pL, 2545, 4); }
int lua_win8_settingscharm_get_xaml_property(lua_State *_pL) { return DoLuaGMLCall(_pL, 2546, 3); }
int lua_win8_settingscharm_remove_entry(lua_State *_pL) { return DoLuaGMLCall(_pL, 2547, 1); }
int lua_win8_search_enable(lua_State *_pL) { return DoLuaGMLCall(_pL, 2548, 1); }
int lua_win8_search_disable(lua_State *_pL) { return DoLuaGMLCall(_pL, 2549, 0); }
int lua_win8_search_add_suggestions(lua_State *_pL) { return DoLuaGMLCall(_pL, 2550, 1); }
int lua_win8_device_touchscreen_available(lua_State *_pL) { return DoLuaGMLCall(_pL, 2551, 0); }
int lua_win8_secondarytile_pin(lua_State *_pL) { return DoLuaGMLCall(_pL, 2552, 8); }
int lua_win8_secondarytile_delete(lua_State *_pL) { return DoLuaGMLCall(_pL, 2553, 1); }
int lua_win8_secondarytile_badge_notification(lua_State *_pL) { return DoLuaGMLCall(_pL, 2554, 2); }
int lua_win8_license_initialize_sandbox(lua_State *_pL) { return DoLuaGMLCall(_pL, 2555, 1); }
int lua_win8_license_trial_version(lua_State *_pL) { return DoLuaGMLCall(_pL, 2556, 0); }
int lua_win8_livetile_notification_begin(lua_State *_pL) { return DoLuaGMLCall(_pL, 2557, 1); }
int lua_win8_livetile_notification_secondary_begin(lua_State *_pL) { return DoLuaGMLCall(_pL, 2558, 2); }
int lua_win8_livetile_notification_expiry(lua_State *_pL) { return DoLuaGMLCall(_pL, 2559, 1); }
int lua_win8_livetile_notification_tag(lua_State *_pL) { return DoLuaGMLCall(_pL, 2560, 1); }
int lua_win8_livetile_notification_text_add(lua_State *_pL) { return DoLuaGMLCall(_pL, 2561, 1); }
int lua_win8_livetile_notification_image_add(lua_State *_pL) { return DoLuaGMLCall(_pL, 2562, 1); }
int lua_win8_livetile_notification_end(lua_State *_pL) { return DoLuaGMLCall(_pL, 2563, 0); }
int lua_uwp_livetile_tile_clear(lua_State *_pL) { return DoLuaGMLCall(_pL, 2564, 0); }
int lua_uwp_livetile_badge_notification(lua_State *_pL) { return DoLuaGMLCall(_pL, 2565, 1); }
int lua_uwp_livetile_badge_clear(lua_State *_pL) { return DoLuaGMLCall(_pL, 2566, 0); }
int lua_uwp_livetile_queue_enable(lua_State *_pL) { return DoLuaGMLCall(_pL, 2567, 1); }
int lua_uwp_secondarytile_pin(lua_State *_pL) { return DoLuaGMLCall(_pL, 2568, 8); }
int lua_uwp_secondarytile_delete(lua_State *_pL) { return DoLuaGMLCall(_pL, 2569, 1); }
int lua_uwp_secondarytile_badge_notification(lua_State *_pL) { return DoLuaGMLCall(_pL, 2570, 2); }
int lua_uwp_secondarytile_tile_clear(lua_State *_pL) { return DoLuaGMLCall(_pL, 2571, 1); }
int lua_uwp_secondarytile_badge_clear(lua_State *_pL) { return DoLuaGMLCall(_pL, 2572, 1); }
int lua_uwp_livetile_notification_begin(lua_State *_pL) { return DoLuaGMLCall(_pL, 2573, 1); }
int lua_uwp_livetile_notification_secondary_begin(lua_State *_pL) { return DoLuaGMLCall(_pL, 2574, 2); }
int lua_uwp_livetile_notification_expiry(lua_State *_pL) { return DoLuaGMLCall(_pL, 2575, 1); }
int lua_uwp_livetile_notification_tag(lua_State *_pL) { return DoLuaGMLCall(_pL, 2576, 1); }
int lua_uwp_livetile_notification_text_add(lua_State *_pL) { return DoLuaGMLCall(_pL, 2577, 1); }
int lua_uwp_livetile_notification_image_add(lua_State *_pL) { return DoLuaGMLCall(_pL, 2578, 1); }
int lua_uwp_livetile_notification_end(lua_State *_pL) { return DoLuaGMLCall(_pL, 2579, 0); }
int lua_uwp_livetile_notification_template_add(lua_State *_pL) { return DoLuaGMLCall(_pL, 2580, 1); }
int lua_uwp_appbar_enable(lua_State *_pL) { return DoLuaGMLCall(_pL, 2581, 1); }
int lua_uwp_appbar_add_element(lua_State *_pL) { return DoLuaGMLCall(_pL, 2582, 7); }
int lua_uwp_appbar_remove_element(lua_State *_pL) { return DoLuaGMLCall(_pL, 2583, 1); }
int lua_uwp_device_touchscreen_available(lua_State *_pL) { return DoLuaGMLCall(_pL, 2584, 0); }
int lua_layer_get_id(lua_State *_pL) { return DoLuaGMLCall(_pL, 2585, 1); }
int lua_layer_get_id_at_depth(lua_State *_pL) { return DoLuaGMLCall(_pL, 2586, 1); }
int lua_layer_get_depth(lua_State *_pL) { return DoLuaGMLCall(_pL, 2587, 1); }
int lua_layer_create(lua_State *_pL) { return DoLuaGMLCall(_pL, 2588, 2); }
int lua_layer_destroy(lua_State *_pL) { return DoLuaGMLCall(_pL, 2589, 1); }
int lua_layer_destroy_instances(lua_State *_pL) { return DoLuaGMLCall(_pL, 2590, 1); }
int lua_layer_add_instance(lua_State *_pL) { return DoLuaGMLCall(_pL, 2591, 2); }
int lua_layer_has_instance(lua_State *_pL) { return DoLuaGMLCall(_pL, 2592, 2); }
int lua_layer_set_visible(lua_State *_pL) { return DoLuaGMLCall(_pL, 2593, 2); }
int lua_layer_get_visible(lua_State *_pL) { return DoLuaGMLCall(_pL, 2594, 1); }
int lua_layer_exists(lua_State *_pL) { return DoLuaGMLCall(_pL, 2595, 1); }
int lua_layer_x(lua_State *_pL) { return DoLuaGMLCall(_pL, 2596, 2); }
int lua_layer_y(lua_State *_pL) { return DoLuaGMLCall(_pL, 2597, 2); }
int lua_layer_get_x(lua_State *_pL) { return DoLuaGMLCall(_pL, 2598, 1); }
int lua_layer_get_y(lua_State *_pL) { return DoLuaGMLCall(_pL, 2599, 1); }
int lua_layer_hspeed(lua_State *_pL) { return DoLuaGMLCall(_pL, 2600, 2); }
int lua_layer_vspeed(lua_State *_pL) { return DoLuaGMLCall(_pL, 2601, 2); }
int lua_layer_get_hspeed(lua_State *_pL) { return DoLuaGMLCall(_pL, 2602, 1); }
int lua_layer_get_vspeed(lua_State *_pL) { return DoLuaGMLCall(_pL, 2603, 1); }
int lua_layer_script_begin(lua_State *_pL) { return DoLuaGMLCall(_pL, 2604, 2); }
int lua_layer_script_end(lua_State *_pL) { return DoLuaGMLCall(_pL, 2605, 2); }
int lua_layer_shader(lua_State *_pL) { return DoLuaGMLCall(_pL, 2606, 2); }
int lua_layer_get_script_begin(lua_State *_pL) { return DoLuaGMLCall(_pL, 2607, 1); }
int lua_layer_get_script_end(lua_State *_pL) { return DoLuaGMLCall(_pL, 2608, 1); }
int lua_layer_get_shader(lua_State *_pL) { return DoLuaGMLCall(_pL, 2609, 1); }
int lua_layer_set_target_room(lua_State *_pL) { return DoLuaGMLCall(_pL, 2610, 1); }
int lua_layer_get_target_room(lua_State *_pL) { return DoLuaGMLCall(_pL, 2611, 0); }
int lua_layer_reset_target_room(lua_State *_pL) { return DoLuaGMLCall(_pL, 2612, 0); }
int lua_layer_get_all(lua_State *_pL) { return DoLuaGMLCall(_pL, 2613, 0); }
int lua_layer_get_all_elements(lua_State *_pL) { return DoLuaGMLCall(_pL, 2614, 1); }
int lua_layer_get_name(lua_State *_pL) { return DoLuaGMLCall(_pL, 2615, 1); }
int lua_layer_depth(lua_State *_pL) { return DoLuaGMLCall(_pL, 2616, 2); }
int lua_layer_get_element_layer(lua_State *_pL) { return DoLuaGMLCall(_pL, 2617, 1); }
int lua_layer_get_element_type(lua_State *_pL) { return DoLuaGMLCall(_pL, 2618, 1); }
int lua_layer_element_move(lua_State *_pL) { return DoLuaGMLCall(_pL, 2619, 2); }
int lua_layer_force_draw_depth(lua_State *_pL) { return DoLuaGMLCall(_pL, 2620, 2); }
int lua_layer_is_draw_depth_forced(lua_State *_pL) { return DoLuaGMLCall(_pL, 2621, 0); }
int lua_layer_get_forced_depth(lua_State *_pL) { return DoLuaGMLCall(_pL, 2622, 0); }
int lua_layer_background_get_id(lua_State *_pL) { return DoLuaGMLCall(_pL, 2623, 1); }
int lua_layer_background_exists(lua_State *_pL) { return DoLuaGMLCall(_pL, 2624, 2); }
int lua_layer_background_create(lua_State *_pL) { return DoLuaGMLCall(_pL, 2625, 2); }
int lua_layer_background_destroy(lua_State *_pL) { return DoLuaGMLCall(_pL, 2626, 1); }
int lua_layer_background_visible(lua_State *_pL) { return DoLuaGMLCall(_pL, 2627, 2); }
int lua_layer_background_htiled(lua_State *_pL) { return DoLuaGMLCall(_pL, 2628, 2); }
int lua_layer_background_vtiled(lua_State *_pL) { return DoLuaGMLCall(_pL, 2629, 2); }
int lua_layer_background_xscale(lua_State *_pL) { return DoLuaGMLCall(_pL, 2630, 2); }
int lua_layer_background_yscale(lua_State *_pL) { return DoLuaGMLCall(_pL, 2631, 2); }
int lua_layer_background_stretch(lua_State *_pL) { return DoLuaGMLCall(_pL, 2632, 2); }
int lua_layer_background_blend(lua_State *_pL) { return DoLuaGMLCall(_pL, 2633, 2); }
int lua_layer_background_alpha(lua_State *_pL) { return DoLuaGMLCall(_pL, 2634, 2); }
int lua_layer_background_index(lua_State *_pL) { return DoLuaGMLCall(_pL, 2635, 2); }
int lua_layer_background_speed(lua_State *_pL) { return DoLuaGMLCall(_pL, 2636, 2); }
int lua_layer_background_sprite(lua_State *_pL) { return DoLuaGMLCall(_pL, 2637, 2); }
int lua_layer_background_change(lua_State *_pL) { return DoLuaGMLCall(_pL, 2638, 2); }
int lua_layer_background_get_visible(lua_State *_pL) { return DoLuaGMLCall(_pL, 2639, 1); }
int lua_layer_background_get_sprite(lua_State *_pL) { return DoLuaGMLCall(_pL, 2640, 1); }
int lua_layer_background_get_htiled(lua_State *_pL) { return DoLuaGMLCall(_pL, 2641, 1); }
int lua_layer_background_get_vtiled(lua_State *_pL) { return DoLuaGMLCall(_pL, 2642, 1); }
int lua_layer_background_get_xscale(lua_State *_pL) { return DoLuaGMLCall(_pL, 2643, 1); }
int lua_layer_background_get_yscale(lua_State *_pL) { return DoLuaGMLCall(_pL, 2644, 1); }
int lua_layer_background_get_stretch(lua_State *_pL) { return DoLuaGMLCall(_pL, 2645, 1); }
int lua_layer_background_get_blend(lua_State *_pL) { return DoLuaGMLCall(_pL, 2646, 1); }
int lua_layer_background_get_alpha(lua_State *_pL) { return DoLuaGMLCall(_pL, 2647, 1); }
int lua_layer_background_get_index(lua_State *_pL) { return DoLuaGMLCall(_pL, 2648, 1); }
int lua_layer_background_get_speed(lua_State *_pL) { return DoLuaGMLCall(_pL, 2649, 1); }
int lua_layer_sprite_get_id(lua_State *_pL) { return DoLuaGMLCall(_pL, 2650, 2); }
int lua_layer_sprite_exists(lua_State *_pL) { return DoLuaGMLCall(_pL, 2651, 2); }
int lua_layer_sprite_create(lua_State *_pL) { return DoLuaGMLCall(_pL, 2652, 4); }
int lua_layer_sprite_destroy(lua_State *_pL) { return DoLuaGMLCall(_pL, 2653, 1); }
int lua_layer_sprite_change(lua_State *_pL) { return DoLuaGMLCall(_pL, 2654, 2); }
int lua_layer_sprite_index(lua_State *_pL) { return DoLuaGMLCall(_pL, 2655, 2); }
int lua_layer_sprite_speed(lua_State *_pL) { return DoLuaGMLCall(_pL, 2656, 2); }
int lua_layer_sprite_xscale(lua_State *_pL) { return DoLuaGMLCall(_pL, 2657, 2); }
int lua_layer_sprite_yscale(lua_State *_pL) { return DoLuaGMLCall(_pL, 2658, 2); }
int lua_layer_sprite_angle(lua_State *_pL) { return DoLuaGMLCall(_pL, 2659, 2); }
int lua_layer_sprite_blend(lua_State *_pL) { return DoLuaGMLCall(_pL, 2660, 2); }
int lua_layer_sprite_alpha(lua_State *_pL) { return DoLuaGMLCall(_pL, 2661, 2); }
int lua_layer_sprite_x(lua_State *_pL) { return DoLuaGMLCall(_pL, 2662, 2); }
int lua_layer_sprite_y(lua_State *_pL) { return DoLuaGMLCall(_pL, 2663, 2); }
int lua_layer_sprite_get_sprite(lua_State *_pL) { return DoLuaGMLCall(_pL, 2664, 1); }
int lua_layer_sprite_get_index(lua_State *_pL) { return DoLuaGMLCall(_pL, 2665, 1); }
int lua_layer_sprite_get_speed(lua_State *_pL) { return DoLuaGMLCall(_pL, 2666, 1); }
int lua_layer_sprite_get_xscale(lua_State *_pL) { return DoLuaGMLCall(_pL, 2667, 1); }
int lua_layer_sprite_get_yscale(lua_State *_pL) { return DoLuaGMLCall(_pL, 2668, 1); }
int lua_layer_sprite_get_angle(lua_State *_pL) { return DoLuaGMLCall(_pL, 2669, 1); }
int lua_layer_sprite_get_blend(lua_State *_pL) { return DoLuaGMLCall(_pL, 2670, 1); }
int lua_layer_sprite_get_alpha(lua_State *_pL) { return DoLuaGMLCall(_pL, 2671, 1); }
int lua_layer_sprite_get_x(lua_State *_pL) { return DoLuaGMLCall(_pL, 2672, 1); }
int lua_layer_sprite_get_y(lua_State *_pL) { return DoLuaGMLCall(_pL, 2673, 1); }
int lua_instance_activate_layer(lua_State *_pL) { return DoLuaGMLCall(_pL, 2674, 1); }
int lua_instance_deactivate_layer(lua_State *_pL) { return DoLuaGMLCall(_pL, 2675, 1); }
int lua_layer_tilemap_get_id(lua_State *_pL) { return DoLuaGMLCall(_pL, 2676, 1); }
int lua_layer_tilemap_exists(lua_State *_pL) { return DoLuaGMLCall(_pL, 2677, 2); }
int lua_layer_tilemap_create(lua_State *_pL) { return DoLuaGMLCall(_pL, 2678, 6); }
int lua_layer_tilemap_destroy(lua_State *_pL) { return DoLuaGMLCall(_pL, 2679, 1); }
int lua_tilemap_tileset(lua_State *_pL) { return DoLuaGMLCall(_pL, 2680, 2); }
int lua_tilemap_x(lua_State *_pL) { return DoLuaGMLCall(_pL, 2681, 2); }
int lua_tilemap_y(lua_State *_pL) { return DoLuaGMLCall(_pL, 2682, 2); }
int lua_tilemap_set(lua_State *_pL) { return DoLuaGMLCall(_pL, 2683, 4); }
int lua_tilemap_set_at_pixel(lua_State *_pL) { return DoLuaGMLCall(_pL, 2684, 4); }
int lua_tilemap_get_tileset(lua_State *_pL) { return DoLuaGMLCall(_pL, 2685, 1); }
int lua_tilemap_get_tile_width(lua_State *_pL) { return DoLuaGMLCall(_pL, 2686, 1); }
int lua_tilemap_get_tile_height(lua_State *_pL) { return DoLuaGMLCall(_pL, 2687, 1); }
int lua_tilemap_get_width(lua_State *_pL) { return DoLuaGMLCall(_pL, 2688, 1); }
int lua_tilemap_get_height(lua_State *_pL) { return DoLuaGMLCall(_pL, 2689, 1); }
int lua_tilemap_set_width(lua_State *_pL) { return DoLuaGMLCall(_pL, 2690, 1); }
int lua_tilemap_set_height(lua_State *_pL) { return DoLuaGMLCall(_pL, 2691, 1); }
int lua_tilemap_get_x(lua_State *_pL) { return DoLuaGMLCall(_pL, 2692, 1); }
int lua_tilemap_get_y(lua_State *_pL) { return DoLuaGMLCall(_pL, 2693, 1); }
int lua_tilemap_get(lua_State *_pL) { return DoLuaGMLCall(_pL, 2694, 3); }
int lua_tilemap_get_at_pixel(lua_State *_pL) { return DoLuaGMLCall(_pL, 2695, 3); }
int lua_tilemap_get_cell_x_at_pixel(lua_State *_pL) { return DoLuaGMLCall(_pL, 2696, 3); }
int lua_tilemap_get_cell_y_at_pixel(lua_State *_pL) { return DoLuaGMLCall(_pL, 2697, 3); }
int lua_tilemap_clear(lua_State *_pL) { return DoLuaGMLCall(_pL, 2698, 2); }
int lua_draw_tilemap(lua_State *_pL) { return DoLuaGMLCall(_pL, 2699, 3); }
int lua_draw_tile(lua_State *_pL) { return DoLuaGMLCall(_pL, 2700, 5); }
int lua_tilemap_set_global_mask(lua_State *_pL) { return DoLuaGMLCall(_pL, 2701, 1); }
int lua_tilemap_get_global_mask(lua_State *_pL) { return DoLuaGMLCall(_pL, 2702, 0); }
int lua_tilemap_set_mask(lua_State *_pL) { return DoLuaGMLCall(_pL, 2703, 2); }
int lua_tilemap_get_mask(lua_State *_pL) { return DoLuaGMLCall(_pL, 2704, 1); }
int lua_tilemap_get_frame(lua_State *_pL) { return DoLuaGMLCall(_pL, 2705, 1); }
int lua_tile_set_empty(lua_State *_pL) { return DoLuaGMLCall(_pL, 2706, 1); }
int lua_tile_set_index(lua_State *_pL) { return DoLuaGMLCall(_pL, 2707, 2); }
int lua_tile_set_flip(lua_State *_pL) { return DoLuaGMLCall(_pL, 2708, 2); }
int lua_tile_set_mirror(lua_State *_pL) { return DoLuaGMLCall(_pL, 2709, 2); }
int lua_tile_set_rotate(lua_State *_pL) { return DoLuaGMLCall(_pL, 2710, 2); }
int lua_tile_get_empty(lua_State *_pL) { return DoLuaGMLCall(_pL, 2711, 1); }
int lua_tile_get_index(lua_State *_pL) { return DoLuaGMLCall(_pL, 2712, 1); }
int lua_tile_get_flip(lua_State *_pL) { return DoLuaGMLCall(_pL, 2713, 1); }
int lua_tile_get_mirror(lua_State *_pL) { return DoLuaGMLCall(_pL, 2714, 1); }
int lua_tile_get_rotate(lua_State *_pL) { return DoLuaGMLCall(_pL, 2715, 1); }
int lua_layer_tile_exists(lua_State *_pL) { return DoLuaGMLCall(_pL, 2716, 2); }
int lua_layer_tile_create(lua_State *_pL) { return DoLuaGMLCall(_pL, 2717, 8); }
int lua_layer_tile_destroy(lua_State *_pL) { return DoLuaGMLCall(_pL, 2718, 1); }
int lua_layer_tile_change(lua_State *_pL) { return DoLuaGMLCall(_pL, 2719, 2); }
int lua_layer_tile_xscale(lua_State *_pL) { return DoLuaGMLCall(_pL, 2720, 2); }
int lua_layer_tile_yscale(lua_State *_pL) { return DoLuaGMLCall(_pL, 2721, 2); }
int lua_layer_tile_blend(lua_State *_pL) { return DoLuaGMLCall(_pL, 2722, 2); }
int lua_layer_tile_alpha(lua_State *_pL) { return DoLuaGMLCall(_pL, 2723, 2); }
int lua_layer_tile_x(lua_State *_pL) { return DoLuaGMLCall(_pL, 2724, 2); }
int lua_layer_tile_y(lua_State *_pL) { return DoLuaGMLCall(_pL, 2725, 2); }
int lua_layer_tile_region(lua_State *_pL) { return DoLuaGMLCall(_pL, 2726, 5); }
int lua_layer_tile_visible(lua_State *_pL) { return DoLuaGMLCall(_pL, 2727, 2); }
int lua_layer_tile_get_sprite(lua_State *_pL) { return DoLuaGMLCall(_pL, 2728, 1); }
int lua_layer_tile_get_xscale(lua_State *_pL) { return DoLuaGMLCall(_pL, 2729, 1); }
int lua_layer_tile_get_yscale(lua_State *_pL) { return DoLuaGMLCall(_pL, 2730, 1); }
int lua_layer_tile_get_blend(lua_State *_pL) { return DoLuaGMLCall(_pL, 2731, 1); }
int lua_layer_tile_get_alpha(lua_State *_pL) { return DoLuaGMLCall(_pL, 2732, 1); }
int lua_layer_tile_get_x(lua_State *_pL) { return DoLuaGMLCall(_pL, 2733, 1); }
int lua_layer_tile_get_y(lua_State *_pL) { return DoLuaGMLCall(_pL, 2734, 1); }
int lua_layer_tile_get_region(lua_State *_pL) { return DoLuaGMLCall(_pL, 2735, 1); }
int lua_layer_tile_get_visible(lua_State *_pL) { return DoLuaGMLCall(_pL, 2736, 1); }
int lua_layer_instance_get_instance(lua_State *_pL) { return DoLuaGMLCall(_pL, 2737, 1); }

#pragma endregion