/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:59:00 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/04 15:28:38 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/scene/scene_init.h"
#include "engine/map/map_init.h"
#include "utils/error.h"

t_result	init_voxel_map_2d_config(t_voxel_map_2d_config *config)
{
	if (config == NULL)
		return (throw_error("init_voxel_map_2d_config", "NULL pointer"));
	config->display = FALSE;
	config->anchor = ft_vec2i(0, 0);
	config->offset = ft_vec2i(0, 0);
	config->size = ft_usize(640, 480);
	config->scale = ft_vec2f(1.0f, 1.0f);
	config->display_e_oriented = FALSE;
	config->display_e_oriented_storage = FALSE;
	config->display_e_static = FALSE;
	config->display_e_static_storage = FALSE;
	config->display_player = FALSE;
	config->character_size = ft_usize(50, 50);
	return (OK);
}

t_result	init_voxel_map_3d_config(t_voxel_map_3d_config *config)
{
	if (config == NULL)
		return (throw_error("init_voxel_map_2d_config", "NULL pointer"));
	config->display = FALSE;
	config->is_running = FALSE;
	config->anchor = ft_vec2i(0, 0);
	config->offset = ft_vec2i(0, 0);
	config->size = ft_usize(640, 480);
	config->scale = ft_vec2f(1.0f, 1.0f);
	config->height_scale = 2;
	config->render_dist = 300;
	config->display_e_oriented = FALSE;
	config->display_e_oriented_storage = FALSE;
	config->display_e_static = FALSE;
	config->display_e_static_storage = FALSE;
	config->display_player = FALSE;
	return (OK);
}

t_result	init_voxel_map_config(t_voxel_map_config *config)
{
	if (config == NULL)
		return (throw_error("init_voxel_map_config", "NULL pointer"));
	init_voxel_map_2d_config(&config->color_map);
	init_voxel_map_2d_config(&config->height_map);
	init_voxel_map_2d_config(&config->drop_map);
	init_voxel_map_3d_config(&config->map_3d);
	config->character_obj = NULL;
	config->map_ref = NULL;
	return (OK);
}
