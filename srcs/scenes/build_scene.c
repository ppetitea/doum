/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 05:14:10 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/18 05:45:46 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scenes.h"
#include "utils/error.h"

t_result	build_scene_renderer(t_scene_renderer *renderer)
{
	if (renderer == NULL)
		return (throw_error("build_scene_renderer", "NULL pointer provided"));
	init_list_head(&renderer->ui_components);
	init_list_head(&renderer->sprites);
	renderer->camera = NULL;
	return (OK);
}

t_result	build_scene_entities(t_scene_entities *entities)
{
	if (entities == NULL)
		return (throw_error("build_scene_entities", "NULL pointer provided"));
	init_list_head(&entities->ui_components);
	init_list_head(&entities->sprites);
	return (OK);
}

t_result	build_scene_resources(t_scene_resources *resources)
{
	if (resources == NULL)
		return (throw_error("build_scene", "NULL pointer provided"));
	init_list_head(&resources->images);
	init_list_head(&resources->songs);
	return (OK);
}

t_result	build_scene_interface(t_scene_interface *interface,
				t_usize screen_size)
{
	if (interface == NULL)
		return (throw_error("build_scene_interface", "NULL pointer provided"));
	init_list_head(&interface->keys_binds);
	init_list_head(&interface->mouse_binds);
	interface->screen.size = screen_size;
	if (!(interface->screen.pixels = (uint32_t*)malloc(sizeof(uint32_t)
		* screen_size.x * screen_size.y)))
		return (throw_error("build_scene_interface", "malloc failed"));
	return (OK);
}

t_scene		*build_scene(char *name, t_usize screen_size)
{
	t_scene	*scene;

	if (name == NULL)
		return (throw_null("build_scene", "NULL pointer provided"));
	if (!(scene = (t_scene*)malloc(sizeof(t_scene))))
		return (throw_null("build_scene", "malloc failed"));
	init_list_head(&scene->node);
	scene->name = name;
	build_scene_interface(&scene->interface, screen_size);
	build_scene_resources(&scene->resources);
	build_scene_entities(&scene->entities);
	build_scene_renderer(&scene->renderer);
	return (scene);
}