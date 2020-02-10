/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:41:38 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/08 16:40:50 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/game/game_init.h"
#include "engine/scene/scene_init.h"
#include "engine/scene/scene_render.h"
#include "utils/error.h"

#include <stdio.h>


void	render_voxel_map2d(t_screen *screen, t_texture* texture,
			t_voxel_map_2d_config *config, t_map *map)
{
	if (screen == NULL || texture == NULL || config == NULL || map == NULL)
		throw_error("render_voxel_map2d", "NULL pointer provided");
	update_entity_texture_box_with_size(screen, &config->box, texture,
		config->size);
	render_texture_with_box(screen, texture, &config->box);
	if (config->display_e_oriented)
		map_render2d_oriented_entities(screen, config, &map->e_oriented, map);
	if (config->display_e_oriented_storage)
		map_render2d_oriented_entities(screen, config,
			&map->e_oriented_storage, map);
	if (config->display_e_static)
		map_render2d_oriented_entities(screen, config, &map->e_static, map);
	if (config->display_e_static_storage)
		map_render2d_oriented_entities(screen, config,
		&map->e_static_storage, map);
	(void)map;
	(void)texture;
	(void)config;
	(void)screen;
}
t_vec2f	compute_render_scale(t_usize by_default, t_usize wish)
{
	t_vec2f	scale;

	scale.x =  (float)wish.x / (float)by_default.x;
	scale.y =  (float)wish.y / (float)by_default.y;
	// printf("wish x %zu y %zu\n", wish->x, wish->y);
	// printf("by_default x %zu y %zu\n", by_default->x, by_default->y);
	// printf("1scale x %.2f y %.2f\n", scale.x, scale.y);
	return (scale);
}

void	update_map_render_config(t_voxel_map_config *config, t_map *map)
{
	if (config == NULL || map == NULL)
		throw_error("update_map_render_config", "NULL pointer provided");
	// printf("update_map_config\n");
	config->color_map.box.scale = compute_render_scale(
		map->color_map.curr->size, config->color_map.size);
	config->height_map.box.scale = compute_render_scale(
		map->height_map.curr->size, config->height_map.size);
	config->drop_map.box.scale = compute_render_scale(
		map->color_map.curr->size, config->drop_map.size);
	config->map_3d.scale = compute_render_scale(game_screen()->size,
		config->map_3d.size);
	config->map_3d.inv_scale.x = 1.0f / config->map_3d.scale.x;
	config->map_3d.inv_scale.y = 1.0f / config->map_3d.scale.y;
	config->map_ref = map;
	// printf("3dscale x %.2f y %.2f\n", config->map_3d.scale.x, config->map_3d.scale.y);
	// printf("3dinv_scale x %.2f y %.2f\n", config->map_3d.inv_scale.x, config->map_3d.inv_scale.y);
}

void	render_current_map(t_screen *screen, t_voxel_map_config *config,
			t_map *map)
{
	if (screen == NULL || config == NULL || map == NULL)
		throw_error("render_current_map", "NULL pointer provided");
	if (config->map_ref != map)
		update_map_render_config(config, map);
	if (config->map_3d.display && map->character_ref != NULL)
		render_voxel_map3d(screen, &config->map_3d, map);
	if (config->color_map.display)
		render_voxel_map2d(screen, map->color_map.curr,
			&config->color_map, map);
	if (config->height_map.display)
		render_voxel_map2d(screen, map->height_map.curr,
			&config->height_map, map);
	if (config->drop_map.display)
		render_voxel_map2d(screen, map->color_map.curr,
			&config->drop_map, map);
}

void	render_scene_background(t_screen *screen, t_texture* background)
{
	t_texture_box	box;

	if (screen == NULL || background == NULL)
		throw_error("render_scene_background", "NULL pointer provided");
	box.anchor = ft_vec2i(0, 0);
	update_entity_texture_box_with_size(screen, &box, background,
		screen->size);
	render_texture_with_box(screen, background, &box);
}

void	render_scene_entities(t_screen *screen, t_list_head *entities)
{
	t_entity	*entity;
	t_list_head	*pos;
	t_list_head	*next;

	if (screen == NULL || entities == NULL)
		throw_error("render_scene_entities", "NULL pointer provided");
	pos = entities;
	next = pos->next;
	while ((pos = next) != entities)
	{
		next = next->next;
		entity = (t_entity*)pos;
		if (entity->texture.curr)
		{
			update_texture_box_with_screen(screen, &entity->texture.box,
				entity->texture.curr);
			render_texture_with_box(screen, entity->texture.curr,
				&entity->texture.box);
		}
	}
}

void	render_scene(t_game *game)
{
	if (game->curr_scene != NULL)
	{
		if (game->curr_scene->bg != NULL)
			render_scene_background(&game->interface.screen,
				game->curr_scene->bg);
		if (game->curr_map != NULL)
		{
			// printf("map: %s\n", game->curr_map->name);
			render_current_map(&game->interface.screen,
				&game->curr_scene->map_render_config, game->curr_map);
		}
		render_scene_entities(&game->interface.screen,
			&game->curr_scene->entities);
	}
}
