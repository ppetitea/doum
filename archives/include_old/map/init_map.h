/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:16:02 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/25 01:50:24 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_MAP_H
# define INIT_MAP_H

# include "libft.h"
# include "engine/resource/image/bitmap_list.h"

# include "engine/resource/image/bitmap_list.h"
# include "engine/resource/image/texture_init.h"
# include "engine/entities/init_entity.h"

typedef enum	e_map_type
{
	VOXEL_MAP,
	INT_MAP
}				t_map_type;

typedef struct	s_map_renderer
{
	t_screen	*screen_ref;
	t_character	*character_ref;
	t_list_head	e_static;
	t_list_head	e_oriented;
}				t_map_renderer;

t_result	set_character_as_player(t_map_renderer *map_renderer,
				t_character *character);

typedef struct  s_map
{
	t_list_head		node;
	t_map_type		type;
	t_texture		map;
	t_texture		height_map;
	t_list_head		entities_storage;
	t_map_renderer	renderer;
	void			(*render)(t_screen*, struct s_map*);
}				t_map;

t_map	*init_new_map();

#endif