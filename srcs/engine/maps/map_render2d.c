/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render2d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 02:49:02 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/26 17:43:21 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/resource/image/texture_init.h"
#include "engine/map/map_init.h"
#include "utils/error.h"

t_vec2f	compute_render_scale(t_usize map, t_usize render)
{
	t_vec2f	render_scale;

	render_scale.x = (float)render.x / (float)map.x;
	render_scale.y = (float)render.y / (float)map.y;
	return (render_scale);
}

void	map_render2d_character(t_map *map, t_map_render2d *render,
			t_character *character)
{
	t_texture	*curr;
	t_pos2i		anchor;
	float		scale;

	curr = character->super.texture.curr;
	if (render->scale.x < render->scale.y)
		scale = render->scale.x;
	else
		scale = render->scale.y;
	anchor.x = character->camera.pos.x * scale + render->offset.x;
	anchor.y = character->camera.pos.y * scale + render->offset.y;
	render_texture_with_scale(map->screen_ref, curr, anchor, scale);
}

void	map_render2d_oriented_entities(t_map *map, t_map_render2d *render,
			t_list_head *entities)
{
	t_character	*character;
	t_list_head	*pos;
	t_list_head	*next;

	pos = entities;
	next = pos->next;
	while ((pos = next) != entities)
	{
		next = next->next;
		character = (t_character*)pos;
		map_render2d_character(map, render, character);
	}
}

void	map_render2d(t_map *map, t_map_render2d *render)
{
	if (render->display == FALSE)
		return ;
	render_texture_with_scale_2d(map->screen_ref, render->texture->curr,
		vec2i_add(render->anchor, render->offset), render->scale);
	if (render->display_e_oriented)
	{
		map_render2d_oriented_entities(map, render, render->e_oriented);
		map_render2d_character(map, render, map->character_ref);
	}
	if (render->display_e_oriented_storage)
		map_render2d_oriented_entities(map, render, render->e_oriented_storage);
	// map_render2d_static_entities(&map->renderer2d,
	// 	&map->renderer2d.e_static);
}
