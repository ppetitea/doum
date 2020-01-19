/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 01:17:28 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/19 22:17:55 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"
#include "engine/interface/events/mouse.h"
#include "engine/entities/entities.h"
#include "engine/entities/update_entity.h"
#include "engine/scenes/init_scene.h"
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
		update_draggables_entities(scene, &scene->renderer.ui_components,
			scene->interface.mouse);
	}
	else
		update_hoverables_entities(&scene->renderer.ui_components,
			scene->interface.mouse);
}

void	handle_mouse_down(t_scene *scene, SDL_MouseButtonEvent event)
{
	scene->interface.mouse.down = TRUE;
	scene->interface.mouse.pos = ft_vec2i(event.x, event.y);
	update_selectables_entities(scene, &scene->renderer.ui_components,
		scene->interface.mouse);
}

void	handle_mouse_up(t_scene *scene, SDL_MouseButtonEvent event)
{
	scene->interface.mouse.down = FALSE;
	scene->interface.mouse.drag = FALSE;
	scene->interface.mouse.pos = ft_vec2i(event.x, event.y);
	update_draggables_entities(scene, &scene->renderer.ui_components,
		scene->interface.mouse);
	(void)scene;
	(void)event;
}