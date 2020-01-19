/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 05:14:10 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/18 16:34:56 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/scenes/build_scene.h"
#include "utils/error.h"

t_result	build_scene_renderer(t_scene_renderer *renderer)
{
	if (renderer == NULL)
		return (throw_error("build_scene_renderer", "NULL pointer provided"));
	init_list_head(&renderer->ui_components);
	init_list_head(&renderer->sprites);
	renderer->cam_ref = NULL;
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
				t_screen *screen_ref)
{
	if (interface == NULL || screen_ref == NULL)
		return (throw_error("build_scene_interface", "NULL pointer provided"));
	init_list_head(&interface->keys_binds);
	init_list_head(&interface->mouse_binds);
	interface->screen_ref = screen_ref;
	return (OK);
}

t_scene		*build_scene(char *name, t_screen *screen_ref)
{
	t_scene	*scene;

	if (name == NULL || screen_ref == NULL)
		return (throw_null("build_scene", "NULL pointer provided"));
	if (!(scene = (t_scene*)malloc(sizeof(t_scene))))
		return (throw_null("build_scene", "malloc failed"));
	init_list_head(&scene->node);
	scene->name = name;
	build_scene_interface(&scene->interface, screen_ref);
	build_scene_resources(&scene->resources);
	build_scene_entities(&scene->entities);
	build_scene_renderer(&scene->renderer);
	return (scene);
}