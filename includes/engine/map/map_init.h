/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:16:02 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/26 20:13:14 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_INIT_H
# define MAP_INIT_H

# include "engine/resource/image/texture_init.h"
# include "engine/entity/character_init.h"
# include "engine/entity/entity_init.h"
# include "libft.h"
# include <sys/time.h>

typedef enum	e_map_type
{
	VOXEL_MAP,
	INT_MAP
}				t_map_type;

typedef struct	s_map_texture
{
	struct timeval		last;
	t_animation_status	animation;
	t_list_head			textures;
	t_texture			*curr;
}				t_map_texture;

typedef struct	s_map_render2d
{
	t_bool			display;
	t_map_texture	*texture;
	t_vec2i			anchor;
	t_vec2i			offset;
	t_usize			size;
	t_vec2f			scale;
	t_usize			e_oriented_size;
	t_list_head		*e_oriented;
	t_list_head		*e_oriented_storage;
	t_bool			display_e_oriented;
	t_bool			display_e_oriented_storage;
	t_bool			is_colorable;
	t_bool			is_elevable;
	t_bool			is_drop_zone;
}				t_map_render2d;

typedef struct	s_map_render3d
{
	t_bool			display;
	t_bool			is_running;
	t_map_texture	*sky;
	t_map_texture	*color_map;
	t_map_texture	*height_map;
	t_vec2i			anchor;
	t_vec2i			offset;
	t_usize			size;
	t_vec2f			scale;
	t_list_head		*e_static;
	t_bool			display_e_static;
	t_list_head		*e_oriented;
	t_bool			display_e_oriented;
}				t_map_render3d;

typedef struct	s_map
{
	t_list_head		node;
	t_map_type		type;
	char			*name;
	t_screen		*screen_ref;
	t_character		*character_ref;
	t_list_head		e_static;
	t_list_head		e_oriented;
	t_list_head		e_static_storage;
	t_list_head		e_oriented_storage;
	t_map_texture	sky_textures;
	t_map_texture	color_map_textures;
	t_map_texture	height_map_textures;
	t_map_render2d	color_map;
	t_map_render2d	height_map;
	t_map_render2d	drop_map;
	t_map_render3d	map3d;
}				t_map;

t_map		*init_new_map();
t_result	set_character_as_player(t_map *map,
				t_character *character);


#endif