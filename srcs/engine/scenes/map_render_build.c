/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render_build.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:59:00 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/28 17:09:17 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/scene/scene_init.h"
#include "engine/map/map_init.h"
#include "utils/error.h"
#include "build.h"

static t_result	init_filter_with_obj(t_filter_type *type,
					char *filter_type)
{
	if (type == NULL)
		return (throw_error("init_filter_with_obj", "NULL pointer provided"));
	if (filter_type == NULL)
		return (ERROR);
	if (!ft_strcmp(filter_type, "none"))
		*type = FILTER_NONE;
	else if (!ft_strcmp(filter_type, "circular_shadow"))
		*type = FILTER_CIRCULAR_SHADOW;
	else if (!ft_strcmp(filter_type, "blend"))
		*type = FILTER_BLEND;
	else
		throw_warning("init_filter_with_obj", "unkow type detected", 2);
	return (OK);
}

static t_result	build_voxel_map_2d_config_with_obj(t_voxel_map_2d_config *config,
				t_dnon_object *map2d_config_obj)
{
	if (config == NULL)
		return (throw_error("build_voxel_map_2d_config", "NULL pointer"));
	if (map2d_config_obj == NULL)
		return (ERROR);
	config->display = get_int_value_by_key(map2d_config_obj, "display", 0);
	init_vec2i_with_obj(&config->anchor,
		get_child_list_object_by_key(map2d_config_obj, "anchor"));
	init_vec2i_with_obj(&config->offset,
		get_child_list_object_by_key(map2d_config_obj, "offset"));
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
	init_filter_with_obj(&config->character_filter,
		get_string_value_by_key(map2d_config_obj, "character_filter", NULL));
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
	init_vec2i_with_obj(&config->anchor, map3d_config_obj);
	init_vec2i_with_obj(&config->offset, map3d_config_obj);
	init_usize_with_obj(&config->size, map3d_config_obj);
	config->display_e_oriented =
		get_int_value_by_key(map3d_config_obj, "display_e_oriented", 0);
	config->display_e_oriented_storage =
		get_int_value_by_key(map3d_config_obj, "display_e_oriented_storage", 0);
	config->display_e_static =
		get_int_value_by_key(map3d_config_obj, "display_e_static", 0);
	config->display_e_static_storage =
		get_int_value_by_key(map3d_config_obj, "display_e_static_storage", 0);
	init_filter_with_obj(&config->character_filter,
		get_string_value_by_key(map3d_config_obj, "character_filter", NULL));
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
	throw_debug("map_3d_config:\t\t\t\t", result ? "OK" : "FAIL", 0);
	return (OK);
}
