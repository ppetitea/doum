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

t_result	init_scene_interface(t_scene_interface *interface)
{
	if (interface == NULL)
		return (throw_error("init_scene_interface", "NULL pointer provided"));
	interface->screen_ref = NULL;
	interface->mouse.pos = ft_vec2i(0, 0);
	interface->mouse.down = FALSE;
	interface->mouse.drag = FALSE;
	init_list_head(&interface->key_binds);
	init_list_head(&interface->key_hold_binds);
	return (OK);
}

t_scene		*init_new_scene()
{
	t_scene	*scene;

	if (!(scene = (t_scene*)malloc(sizeof(t_scene))))
		return (throw_null("init_scene", "malloc failed"));
	init_list_head(&scene->node);
	scene->name = NULL;
	init_scene_interface(&scene->interface);
	init_list_head(&scene->background);
	scene->bg = NULL;
	init_list_head(&scene->entities_storage);
	init_list_head(&scene->entities);
	init_voxel_map_config(&scene->map_render_config);
	return (scene);
}