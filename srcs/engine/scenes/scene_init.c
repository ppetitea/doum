/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 05:14:10 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/19 16:41:59 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/scene/scene_init.h"
#include "utils/error.h"

t_result	init_scene_interface(t_scene_interface *interface,
				t_screen *screen_ref)
{
	if (interface == NULL || screen_ref == NULL)
		return (throw_error("init_scene_interface", "NULL pointer provided"));
	interface->screen_ref = screen_ref;
	interface->mouse.pos = ft_vec2i(0, 0);
	interface->mouse.down = FALSE;
	interface->mouse.drag = FALSE;
	init_list_head(&interface->key_binds);
	init_list_head(&interface->key_hold_binds);
	return (OK);
}

t_scene		*init_new_scene(char *name, t_screen *screen_ref)
{
	t_scene	*scene;

	if (name == NULL || screen_ref == NULL)
		return (throw_null("init_scene", "NULL pointer provided"));
	if (!(scene = (t_scene*)malloc(sizeof(t_scene))))
		return (throw_null("init_scene", "malloc failed"));
	init_list_head(&scene->node);
	scene->name = name;
	init_scene_interface(&scene->interface, screen_ref);
	init_list_head(&scene->background);
	init_list_head(&scene->entities_storage);
	init_list_head(&scene->entities);
	scene->maps = NULL;
	scene->map_config = NULL;
	scene->curr_map = NULL;
	return (scene);
}