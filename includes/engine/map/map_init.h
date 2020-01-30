/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:16:02 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/30 09:19:23 by ppetitea         ###   ########.fr       */
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

typedef struct	s_map
{
	t_list_head		node;
	t_map_type		type;
	char			*name;
	t_character		*character_ref;
	t_list_head		e_static;
	t_list_head		e_oriented;
	t_list_head		e_static_storage;
	t_list_head		e_oriented_storage;
	t_map_texture	sky_textures;
	t_map_texture	color_map_textures;
	t_map_texture	height_map_textures;
}				t_map;

t_map		*init_new_map();
t_result	set_character_as_player(t_map *map,
				t_character *character);

#endif
