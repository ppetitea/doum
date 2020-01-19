/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 16:27:20 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/20 00:31:19 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_SCENE_H
# define INIT_SCENE_H

# include "libft.h"
# include "engine/interface/init_screen.h"
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
	t_list_head			mouse_binds;
	t_list_head			keys_binds;
	t_mouse				mouse;
}						t_scene_interface;

typedef struct			s_scene_resources
{
	t_list_head			images;
	t_list_head			songs;
}						t_scene_resources;

typedef struct			s_scene_entities
{
	t_list_head			ui_components;
	t_list_head			sprites;
}						t_scene_entities;

typedef struct			s_scene_renderer
{
	t_list_head			ui_components;
	t_list_head			sprites;
	t_camera			*cam_ref;
}						t_scene_renderer;

typedef struct			s_scene
{
	t_list_head			node;
	char				*name;
	t_scene_interface	interface;
	t_scene_resources	resources;
	t_scene_entities	entities;
	t_scene_renderer	renderer;
}						t_scene;

t_scene				*init_new_scene(char *name, t_screen *screen_ref);
t_result			build_scene_interface(t_scene_interface *interface,
						t_screen *screen_ref);
t_result			build_scene_resources(t_scene_resources *resources);
t_result			build_scene_entities(t_scene_entities *entities);
t_result			build_scene_renderer(t_scene_renderer *renderer);

#endif