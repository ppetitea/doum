/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_render.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 16:27:20 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/28 15:31:36 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_RENDER_H
# define SCENE_RENDER_H

# include "libft.h"
# include "engine/interface/screen_init.h"
# include "engine/resource/image/texture_filter.h"
# include "engine/scene/scene_init.h"
# include "engine/game/game_init.h"
# include "engine/map/map_init.h"
# include "utils/parser.h"

void	render_scene(t_game *game);
t_vec2f	compute_render_scale(t_usize *by_default, t_usize *wish);
void	update_map_render_config(t_voxel_map_config *config, t_map *map);
void	map_render2d_oriented_entities(t_screen *screen,
			t_voxel_map_2d_config *config, t_list_head *entities);
void	voxel_map_render2d_character(t_screen *screen, t_voxel_map_2d_config *config,
			t_character *character);

#endif