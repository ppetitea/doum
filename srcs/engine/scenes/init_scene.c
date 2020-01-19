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

#include "engine/scenes/init_scene.h"
#include "utils/error.h"

t_result	init_scene_renderer(t_scene_renderer *renderer)
{
	if (renderer == NULL)
		return (throw_error("init_scene_renderer", "NULL pointer provided"));
	init_list_head(&renderer->ui_components);
	init_list_head(&renderer->sprites);
	renderer->cam_ref = NULL;
	return (OK);
}

t_result	init_scene_entities(t_scene_entities *entities)
{
	if (entities == NULL)
		return (throw_error("init_scene_entities", "NULL pointer provided"));
	init_list_head(&entities->ui_components);
	init_list_head(&entities->sprites);
	return (OK);
}

t_result	init_scene_resources(t_scene_resources *resources)
{
	if (resources == NULL)
		return (throw_error("init_scene", "NULL pointer provided"));
	init_list_head(&resources->images);
	init_list_head(&resources->songs);
	return (OK);
}

t_result	init_scene_interface(t_scene_interface *interface,
				t_screen *screen_ref)
{
	if (interface == NULL || screen_ref == NULL)
		return (throw_error("init_scene_interface", "NULL pointer provided"));
	init_list_head(&interface->keys_binds);
	init_list_head(&interface->mouse_binds);
	interface->screen_ref = screen_ref;
	interface->mouse.pos = ft_vec2i(0, 0);
	interface->mouse.down = FALSE;
	interface->mouse.drag = FALSE;
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
	init_scene_resources(&scene->resources);
	init_scene_entities(&scene->entities);
	init_scene_renderer(&scene->renderer);
	return (scene);
}