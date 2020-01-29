/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:41:54 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/29 03:39:24 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/scene/scene_init.h"
#include "engine/scene/scene_render.h"
#include "engine/map/map_init.h"
#include "utils/error.h"

#include <stdio.h>

void	voxel_map_render2d_character(t_screen *screen, t_voxel_map_2d_config *config,
			t_character *character)
{
	t_texture	*curr;
	t_pos2i		anchor;
	t_vec2f		scale;
	
	if (character->super.texture.curr == NULL)
		return ;
	curr = character->super.texture.curr;
	scale = compute_render_scale(&curr->size, &config->character_size);
	anchor.x = character->camera.pos.x * config->scale.x + config->anchor.x
		- curr->size.x * scale.x * 0.5;
	anchor.y = character->camera.pos.y * config->scale.y + config->anchor.y
		- curr->size.y * scale.y;
	render_texture_with_scale_2d(screen, curr, anchor, scale);
}

void	map_render2d_oriented_entities(t_screen *screen,
			t_voxel_map_2d_config *config, t_list_head *entities)
{
	t_character	*character;
	t_list_head	*pos;
	t_list_head	*next;

	if (screen == NULL || config == NULL || entities == NULL)
		return (throw_void("map_render2d", "NULL pointer provided"));
	pos = entities;
	next = pos->next;
	while ((pos = next) != entities)
	{
		next = next->next;
		character = (t_character*)pos;
		voxel_map_render2d_character(screen, config, character);
	}
}
