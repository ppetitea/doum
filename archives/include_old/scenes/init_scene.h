/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 16:27:20 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/25 01:31:22 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_SCENE_H
# define INIT_SCENE_H

# include "libft.h"
# include "engine/interface/screen_init.h"
# include "engine/interface/init_camera.h"

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
	t_list_head			entities;
	t_list_head			renderer;
	t_list_head			*maps;
	void				(*render)(struct s_scene*);
}						t_scene;

t_scene				*init_new_scene(char *name, t_screen *screen_ref);
t_result			build_scene_interface(t_scene_interface *interface,
						t_screen *screen_ref);
// t_result			build_scene_resources(t_scene_resources *resources);
// t_result			build_scene_entities(t_scene_entities *entities);
// t_result			build_scene_renderer(t_scene_renderer *renderer);

#endif