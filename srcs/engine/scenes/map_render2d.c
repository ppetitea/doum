/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render2d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:41:54 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/06 13:20:16 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/scene/scene_init.h"
#include "engine/scene/scene_render.h"
#include "engine/map/map_init.h"
#include "utils/error.h"

#include <stdio.h>

t_bool		is_mouse_belong_to_map(t_pos2i mouse, t_usize map_size,
				t_vec2i map_anchor)
{
	if (map_anchor.x < mouse.x && mouse.x < map_anchor.x + (int)map_size.x
		&& map_anchor.y < mouse.y && mouse.y < map_anchor.y + (int)map_size.y)
		return (TRUE);
	return (FALSE);
}

t_result	update_character_position_by_drag(t_character *character)
{
	t_game					*game;
	t_voxel_map_2d_config	*config;
	t_vec2i					*mouse;
	t_vec2f					pos;

	pos = ft_vec2f(0, 0);
	game = game_singleton(NULL);
	if (character && game && game->curr_scene)
	{
		config = &game->curr_scene->map_render_config.drop_map;
		mouse = &game->interface.mouse.pos;
		if (is_mouse_belong_to_map(*mouse, config->size, config->anchor))
		{
			pos.x = (mouse->x - config->anchor.x) / config->scale.x;
			pos.y = (mouse->y - config->anchor.y) / config->scale.y;
			character->camera.pos = pos;
		}
	}
	return (OK);
}

void	render_map2d_player(t_screen *screen,
		t_voxel_map_2d_config *config, t_map *map)
{
	t_character			*player;
	t_entity_texture	*t;
	t_texture			*texture;
	t_vec2f				scale;
	t_vec2i				anchor;

	if (screen == NULL || config == NULL || map == NULL)
		return (throw_void("render_map3d_player", "NULL pointer"));
	if (map->character_ref == NULL)
		return (throw_void("render_map3d_player", "player not found"));
	player = map->character_ref;
	t = &player->super.texture;
	if (t->normal->next != t->normal)
	{
		texture = (t_texture*)t->normal->next;
		scale = compute_render_scale(&texture->size, &config->character_size);
		player->super.texture.scale = scale;
		if (player->super.status.is_dragged)
			update_character_position_by_drag(player);
		anchor.x = player->camera.pos.x * config->scale.x + config->anchor.x;
		anchor.y = player->camera.pos.y * config->scale.y + config->anchor.y;
		render_texture_with_scale_2d(screen, texture, anchor, scale);
	}
}

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
	character->super.texture.scale = scale;
	if (character->super.status.is_dragged)
		update_character_position_by_drag(character);
	anchor.x = character->camera.pos.x * config->scale.x + config->anchor.x;
	anchor.y = character->camera.pos.y * config->scale.y + config->anchor.y;
	render_texture_with_scale_2d(screen, curr, anchor, scale);
}


void	map_render2d_oriented_entities(t_screen *screen,
			t_voxel_map_2d_config *config, t_list_head *entities, t_map *map)
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
	render_map2d_player(screen, config, map);
}
