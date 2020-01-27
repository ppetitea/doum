/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 01:17:28 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/27 14:01:08 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"
#include "engine/interface/events/mouse.h"
#include "engine/entity/entity_init.h"
#include "engine/entity/entity_update.h"
#include "engine/scene/scene_init.h"
#include "utils/error.h"

#include <stdio.h>

void	handle_mouse_motion(t_scene *scene, SDL_MouseMotionEvent event)
{
	if (scene == NULL)
		return (throw_void("handle_mouse_motion", "NULL pointer provided"));
	scene->interface.mouse.pos = ft_vec2i(event.x, event.y);
	if (scene->interface.mouse.down == TRUE &&
		scene->interface.mouse.drag == FALSE)
	{
		scene->interface.mouse.drag = TRUE;
		// update_draggables_entities(scene, &scene->renderer.ui_components,
		// 	scene->interface.mouse);
	}
	// else
	// 	update_hoverables_entities(&scene->renderer.ui_components,
	// 		scene->interface.mouse);
}

void	handle_mouse_down(t_scene *scene, SDL_MouseButtonEvent event)
{
	scene->interface.mouse.down = TRUE;
	scene->interface.mouse.pos = ft_vec2i(event.x, event.y);
	// if (!scene->interface.mouse.drag)
	// update_selectables_entities(scene, &scene->renderer.ui_components,
	// 	scene->interface.mouse);
}

void	handle_mouse_up(t_scene *scene, SDL_MouseButtonEvent event)
{
	scene->interface.mouse.down = FALSE;
	scene->interface.mouse.drag = FALSE;
	scene->interface.mouse.pos = ft_vec2i(event.x, event.y);
	// update_draggables_entities(scene, &scene->renderer.ui_components,
	// 	scene->interface.mouse);
	(void)scene;
	(void)event;
}