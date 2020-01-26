/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 02:49:02 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/26 17:27:59 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

t_result	init_map_renderer2d(t_map_render2d *map, t_map_texture *texture,
				t_list_head *e_oriented, t_list_head *e_oriented_storage)
{
	if (map == NULL || texture == NULL || e_oriented == NULL
		|| e_oriented_storage == NULL)
		return (throw_error("init_map_render2d", "NULL pointer provided"));
	map->display = FALSE;
	map->texture = texture;
	map->anchor = ft_vec2i(0, 0);
	map->offset = ft_vec2i(0, 0);
	map->size = ft_usize(640, 480);
	map->scale = ft_vec2f(1.0f, 1.0f);
	map->e_oriented = e_oriented;
	map->e_oriented_storage = e_oriented_storage;
	map->display_e_oriented = FALSE;
	map->display_e_oriented_storage = FALSE;
	map->is_colorable = FALSE;
	map->is_elevable = FALSE;
	map->is_drop_zone = FALSE;
	return (OK);
}

t_result	init_map_renderer3d(t_map *self)
{
	if (self == NULL)
		return (throw_error("init_map_render3d", "NULL pointer provided"));
	self->map3d.display = FALSE;
	self->map3d.is_running = FALSE;
	self->map3d.sky = &self->sky_textures;
	self->map3d.color_map = &self->color_map_textures;
	self->map3d.height_map = &self->height_map_textures;
	self->map3d.anchor = ft_vec2i(0, 0);
	self->map3d.offset = ft_vec2i(0, 0);
	self->map3d.size = ft_usize(640, 480);
	self->map3d.scale = ft_vec2f(1.0f, 1.0f);
	self->map3d.e_static = &self->e_static;
	self->map3d.display_e_static = FALSE;
	self->map3d.e_oriented = &self->e_oriented;
	self->map3d.display_e_oriented = FALSE;
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
	self->screen_ref = NULL;
	self->character_ref = NULL;
	init_list_head(&self->e_static);
	init_list_head(&self->e_oriented);
	init_list_head(&self->e_static_storage);
	init_list_head(&self->e_oriented_storage);
	init_map_texture(&self->sky_textures);
	init_map_texture(&self->color_map_textures);
	init_map_texture(&self->height_map_textures);
	init_map_renderer2d(&self->color_map, &self->color_map_textures,
		&self->e_oriented, &self->e_oriented_storage);
	init_map_renderer2d(&self->height_map, &self->height_map_textures,
		&self->e_oriented, &self->e_oriented_storage);
	init_map_renderer2d(&self->drop_map, &self->color_map_textures,
		&self->e_oriented, &self->e_oriented_storage);
	init_map_renderer3d(self);
	return (self);
}
