/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:41:38 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/28 14:02:13 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/game/game_init.h"
#include "engine/scene/scene_init.h"
#include "engine/scene/scene_render.h"

t_vec2f	compute_render_scale(t_screen *screen, t_usize *size)
{
	t_vec2f	scale;

	scale.x = (float)screen->size.x / (float)size->x;
	scale.y = (float)screen->size.y / (float)size->y;
	return (scale);	
}

void	update_map_render_config(t_screen *screen, t_voxel_map_config *config)
{
	config->color_map.scale = compute_render_scale(screen,
		&config->color_map.size);
	config->height_map.scale = compute_render_scale(screen,
		&config->height_map.size);
	config->drop_map.scale = compute_render_scale(screen,
		&config->drop_map.size);
	config->map_3d.scale = compute_render_scale(screen,
		&config->map_3d.size);
}

void	render_scene_background(t_screen *screen, t_texture* background)
{
	t_vec2f	scale;
	t_vec2i	anchor;

	scale = compute_render_scale(screen, &background->size);
	anchor = ft_vec2i(0, 0);
	render_texture_with_scale_2d(screen, background, anchor, scale);
}

void	render_current_map(t_screen *screen, t_voxel_map_config *config,
			t_map *map)
{
	if (config->map_ref != map)
		update_map_render_config(screen, config);
	//render map texture 2d -> HERE <-
	if (config->color_map.display)
		map_render2d_oriented_entities(screen, &config->color_map,
			&map->e_oriented);
	if (config->height_map.display)
		map_render2d_oriented_entities(screen, &config->height_map,
			&map->e_oriented);
	if (config->drop_map.display)
		map_render2d_oriented_entities(screen, &config->drop_map,
			&map->e_oriented);
}

void	render_scene(t_game *game)
{
	if (game->curr_scene != NULL)
	{
		if (game->curr_scene->bg != NULL)
			render_scene_background(&game->interface.screen,
				game->curr_scene->bg);
		if (game->curr_map != NULL)
			render_current_map(&game->interface.screen,
				&game->curr_scene->map_render_config, game->curr_map);
		render_scene_entities(&game->interface.screen,
			&game->curr_scene->entities);
	}
}