/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 02:49:02 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/09 00:10:03 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/game/game_init.h"
#include "engine/map/map_init.h"
#include "engine/map/map_update.h"
#include "utils/error.h"

t_result	init_map_texture(t_map_texture *self)
{
	if (self == NULL)
		return (throw_error("init_map_textures", "NULL pointer provided"));
	gettimeofday(&self->last, NULL);
	init_list_head(&self->textures);
	self->curr = NULL;
	self->animation = NONE;
	return (OK);
}

t_map	*init_new_map()
{
	t_map	*self;

	if (!(self = (t_map*)malloc(sizeof(t_map))))
		return (throw_null("init_new_map", "malloc failed"));
	init_list_head(&self->node);
	self->type = VOXEL_MAP;
	self->name = NULL;
	self->character_ref = NULL;
	init_list_head(&self->e_static);
	init_list_head(&self->e_oriented);
	init_list_head(&self->e_static_storage);
	init_list_head(&self->e_oriented_storage);
	init_map_texture(&self->sky);
	init_map_texture(&self->color_map);
	init_map_texture(&self->height_map);
	return (self);
}

t_map	*game_map()
{
	t_game *game;

	if (!(game = game_singleton(NULL)))
		return (throw_null("game_map", "current map not found"));
	return (game->curr_map);
}