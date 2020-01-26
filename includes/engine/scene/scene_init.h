/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_init.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 16:27:20 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/26 20:21:28 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_INIT_H
# define SCENE_INIT_H

# include "libft.h"
# include "engine/interface/screen_init.h"
# include "engine/map/map_init.h"
# include "utils/parser.h"

typedef struct			s_mouse
{
	t_vec2i				pos;
	t_bool				down;
	t_bool				drag;
}						t_mouse;

typedef struct			s_scene_interface
{
	t_screen			*screen_ref;
	t_mouse				mouse;
	t_list_head			key_binds;
	t_list_head			key_hold_binds;
}						t_scene_interface;

typedef struct			s_scene
{
	t_list_head			node;
	char				*name;
	t_scene_interface	interface;
	t_list_head			background;
	t_list_head			entities_storage;
	t_list_head			entities;
	t_list_head			*maps;
	t_dnon_object		*map_config;
	t_map				*curr_map;
}						t_scene;

t_scene				*init_new_scene(char *name, t_screen *screen_ref);

#endif