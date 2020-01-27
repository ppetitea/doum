/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:41:54 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/27 15:49:00 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/scene/scene_init.h"
#include "engine/map/map_init.h"
#include "utils/error.h"

void	voxel_map_render2d_character(t_map *map, t_voxel_map_2d_config *config,
			t_character *character)
{
	t_texture	*curr;
	t_pos2i		anchor;
	float		scale;

	if (character->super.texture.curr == NULL)
		return ;
	curr = character->super.texture.curr;
	if (config->scale.x < config->scale.y)
		scale = config->scale.x;
	else
		scale = config->scale.y;
	anchor.x = character->camera.pos.x * scale + config->offset.x;
	anchor.y = character->camera.pos.y * scale + config->offset.y;
	render_texture_with_scale(map->screen_ref, curr, anchor, scale);
	(void)curr;
	(void)anchor;
	(void)scale;
	(void)config;
	(void)character;
	(void)map;
}

void	map_render2d_oriented_entities(t_map *map,
			t_voxel_map_2d_config *config, t_list_head *entities)
{
	t_character	*character;
	t_list_head	*pos;
	t_list_head	*next;

	if (map == NULL || config == NULL || entities == NULL)
		return (throw_void("map_render2d", "NULL pointer provided"));
	pos = entities;
	next = pos->next;
	while ((pos = next) != entities)
	{
		next = next->next;
		character = (t_character*)pos;
		map_render2d_character(map, config, character);
	}
}
