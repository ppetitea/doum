/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_render.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 16:27:20 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/28 13:56:37 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_RENDER_H
# define SCENE_RENDER_H

# include "libft.h"
# include "engine/interface/screen_init.h"
# include "engine/resource/image/texture_filter.h"
# include "engine/scene/scene_init.h"
# include "engine/map/map_init.h"
# include "utils/parser.h"

t_vec2f	compute_render_scale(t_screen *screen, t_usize *size);
void	update_map_render_config(t_screen *screen, t_voxel_map_config *config);
void	map_render2d_oriented_entities(t_screen *screen,
			t_voxel_map_2d_config *config, t_list_head *entities);
void	voxel_map_render2d_character(t_screen *screen, t_voxel_map_2d_config *config,
			t_character *character);



#endif
