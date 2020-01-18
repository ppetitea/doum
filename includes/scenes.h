/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 16:27:20 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/18 05:40:47 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENES_H
# define SCENES_H

# include "libft.h"
# include "entities/player.h"
# include "interface/screen.h"

typedef struct			s_scene_interface
{
	t_screen			screen;
	t_list_head			mouse_binds;
	t_list_head			keys_binds;
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
	t_camera			*camera;
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

t_scene				*build_scene(char *name, t_usize screen_size);
t_result			build_scene_interface(t_scene_interface *interface,
						t_usize screen_size);
t_result			build_scene_resources(t_scene_resources *resources);
t_result			build_scene_entities(t_scene_entities *entities);
t_result			build_scene_renderer(t_scene_renderer *renderer);

#endif