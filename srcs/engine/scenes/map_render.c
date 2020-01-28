/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:41:54 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/28 13:58:33 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/scene/scene_init.h"
#include "engine/scene/scene_render.h"
#include "engine/map/map_init.h"
#include "utils/error.h"

void	voxel_map_render2d_character(t_screen *screen, t_voxel_map_2d_config *config,
			t_character *character)
{
	t_texture	*curr;
	t_pos2i		anchor;
	t_vec2f		scale;

	if (character->super.texture.curr == NULL)
		return ;
	curr = character->super.texture.curr;
	scale = compute_render_scale(screen, &curr->size);
	anchor.x = character->camera.pos.x * scale.x + config->offset.x;
	anchor.y = character->camera.pos.y * scale.y + config->offset.y;
	render_texture_with_scale_2d(screen, curr, anchor, scale);
	(void)curr;
	(void)anchor;
	(void)scale;
	(void)config;
	(void)character;
}

void	map_render2d_oriented_entities(t_screen *screen,
			t_voxel_map_2d_config *config, t_list_head *entities)
{
	t_character	*character;
	t_list_head	*pos;
	t_list_head	*next;

	if (screen == NULL || config == NULL || entities == NULL)
		return (throw_void("map_render2d", "NULL pointer provided"));
	if (!config->display_e_oriented)
		return ;
	pos = entities;
	next = pos->next;
	while ((pos = next) != entities)
	{
		next = next->next;
		character = (t_character*)pos;
		voxel_map_render2d_character(screen, config, character);
	}
}
