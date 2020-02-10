/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render_build.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:59:00 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/08 03:46:17 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/scene/scene_init.h"
#include "engine/map/map_init.h"
#include "utils/error.h"
#include "build.h"

// static t_result	init_filter_with_obj(t_filter_type *type,
// 					char *filter_type)
// {
// 	if (type == NULL)
// 		return (throw_error("init_filter_with_obj", "NULL pointer provided"));
// 	if (filter_type == NULL)
// 		return (ERROR);
// 	if (!ft_strcmp(filter_type, "none"))
// 		*type = FILTER_NONE;
// 	else if (!ft_strcmp(filter_type, "circular_shadow"))
// 		*type = FILTER_CIRCULAR_SHADOW;
// 	else if (!ft_strcmp(filter_type, "blend"))
// 		*type = FILTER_BLEND;
// 	else
// 		throw_warning("init_filter_with_obj", "unkow type detected", 2);
// 	return (OK);
// }

static t_result	build_voxel_map_2d_config_with_obj(t_voxel_map_2d_config *config,
				t_dnon_object *map2d_config_obj)
{
	if (config == NULL)
		return (throw_error("build_voxel_map_2d_config", "NULL pointer"));
	if (map2d_config_obj == NULL)
		return (ERROR);
	config->display = get_int_value_by_key(map2d_config_obj, "display", 0);
	init_vec2i_with_obj(&config->box.anchor,
		get_child_list_object_by_key(map2d_config_obj, "anchor"));
	init_usize_with_obj(&config->size,
		get_child_list_object_by_key(map2d_config_obj, "size"));
	init_usize_with_obj(&config->character_size,
		get_child_list_object_by_key(map2d_config_obj, "character_size"));
	config->display_e_oriented =
		get_int_value_by_key(map2d_config_obj, "display_e_oriented", 0);
	config->display_e_oriented_storage =
		get_int_value_by_key(map2d_config_obj, "display_e_oriented_storage", 0);
	config->display_e_static =
		get_int_value_by_key(map2d_config_obj, "display_e_static", 0);
	config->display_e_static_storage =
		get_int_value_by_key(map2d_config_obj, "display_e_static_storage", 0);
	config->display_player =
		get_int_value_by_key(map2d_config_obj, "display_player", 0);
	return (OK);
}

t_result	memalloc_pre_render3d(t_voxel_map_3d_config *config)
{
	float		distance;
	float		delta;
	size_t		amount;
	t_screen	*screen;
	
	if (!(screen = game_screen()))
		return (throw_error("fill_slides_pre_render", "screen not found"));
	distance = 1;
	delta = 1;
	amount = 0;
	while (distance < config->horizon_dist)
	{
		distance += delta;
		delta += 0.005f;
		amount++;
	}
	config->pre_render.slides_amount = amount;
	if (!(config->pre_render.slides =
		(t_render_slide*)malloc(sizeof(t_render_slide) * amount)))
		return (throw_error("memalloc_pre_render", "malloc failed"));
	if (!(config->pre_render.columns_height =
		(uint32_t*)malloc(sizeof(uint32_t) * screen->size.x)))
		return (throw_error("memalloc_pre_render", "malloc failed"));
	return (OK);
}

t_result	fill_slides_pre_render3d(t_voxel_map_3d_config *config)
{
	float			distance;
	float			delta;
	size_t			amount;
	t_character		*player;
	t_render_slide	*slide;

	if (!(player = game_player()))
		return (throw_error("fill_slides_pre_render", "player not found"));
	distance = 1;
	delta = 1;
	amount = 0;
	while (amount < config->pre_render.slides_amount)
	{
		slide = &config->pre_render.slides[amount];
		slide->dist_to_slide = distance;
		slide->dist_ratio = player->camera.dist_to_plan / slide->dist_to_slide;
		slide->slide_half = slide->dist_to_slide
			* (float)tan(player->camera.fov / 2.0f);
		slide->slide_width = slide->slide_half * 2;
		slide->slide_delta = slide->slide_width / player->camera.plan_width;
		// printf(" slide %ld distance %f\n", amount, slide->dist_to_slide);
		// printf("slide %ld delta %f\n", amount, slide->slide_delta);
		distance += delta;
		delta += 0.005f;
		amount++;
	}
	return (OK);
}

t_result	build_pre_render3d(t_voxel_map_3d_config *config)
{
	t_screen	*screen;

	if (config == NULL)
		return (throw_error("build_camera_pre_render", "NULL pointer"));
	if (!(screen = game_screen()))
		return (throw_error("build_camera_pre_render", "screen not found"));
	if (!(config->pre_render.columns_height =
		(uint32_t*)malloc(sizeof(uint32_t) * (screen->size.x))))
		return (throw_error("build_camera_pre_render", "malloc failed"));
	if (!memalloc_pre_render3d(config))
		return (throw_error("build_camera_pre_render", "memalloc render fail"));
	if (!fill_slides_pre_render3d(config))
		return (throw_error("build_camera_pre_render", "fill_pre_render fail"));
	return (OK);
}

static t_result	build_voxel_map_3d_config_with_obj(t_voxel_map_3d_config *config,
				t_dnon_object *map3d_config_obj)
{
	if (config == NULL)
		return (throw_error("build_voxel_map_2d_config", "NULL pointer"));
	if (map3d_config_obj == NULL)
		return (ERROR);
	config->display = get_int_value_by_key(map3d_config_obj, "display", 0);
	init_vec2i_with_obj(&config->anchor,
		get_child_list_object_by_key(map3d_config_obj, "anchor"));
	init_vec2i_with_obj(&config->offset,
		get_child_list_object_by_key(map3d_config_obj, "offset"));
	init_usize_with_obj(&config->size,
		get_child_list_object_by_key(map3d_config_obj, "size"));
	config->horizon = get_int_value_by_key(map3d_config_obj, "horizon", 130);
	config->horizon_dist = get_int_value_by_key(map3d_config_obj,
		"horizon_distance", 3000);
	build_pre_render3d(config);
	config->display_e_oriented =
		get_int_value_by_key(map3d_config_obj, "display_e_oriented", 0);
	config->display_e_oriented_storage =
		get_int_value_by_key(map3d_config_obj, "display_e_oriented_storage", 0);
	config->display_e_static =
		get_int_value_by_key(map3d_config_obj, "display_e_static", 0);
	config->display_e_static_storage =
		get_int_value_by_key(map3d_config_obj, "display_e_static_storage", 0);
	config->display_player =
		get_int_value_by_key(map3d_config_obj, "display_player", 0);
	config->display_e_static_storage =
		get_int_value_by_key(map3d_config_obj, "display_e_static_storage", 0);
	return (OK);
}

t_result	build_voxel_map_config_with_obj(t_voxel_map_config *config,
				t_dnon_object *map_config_obj)
{
	t_result	result;

	if (config == NULL)
		return (throw_error("build_voxel_map_config", "NULL pointer"));
	if (map_config_obj == NULL)
		return (ERROR);
	result = build_voxel_map_2d_config_with_obj(&config->color_map,
		get_child_list_object_by_key(map_config_obj, "color_map"));
	throw_debug("color_map_config:\t\t\t", result ? "OK" : "FAIL", 0);
	result = build_voxel_map_2d_config_with_obj(&config->height_map,
		get_child_list_object_by_key(map_config_obj, "height_map"));
	throw_debug("height_map_config:\t\t\t", result ? "OK" : "FAIL", 0);
	result = build_voxel_map_2d_config_with_obj(&config->drop_map,
		get_child_list_object_by_key(map_config_obj, "drop_map"));
	throw_debug("drop_map_config:\t\t\t", result ? "OK" : "FAIL", 0);
	result = build_voxel_map_3d_config_with_obj(&config->map_3d,
		get_child_list_object_by_key(map_config_obj, "map3d"));
	config->character_obj = get_child_list_object_by_key(map_config_obj,
		"character");
	throw_debug("map_3d_config:\t\t\t\t", result ? "OK" : "FAIL", 0);
	return (OK);
}
