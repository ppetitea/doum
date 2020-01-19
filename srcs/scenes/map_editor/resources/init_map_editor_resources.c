/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mmap_editor_resources.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 15:18:54 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/18 16:50:00 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/interface/events/keyboard.h"
#include "engine/scenes/build_scene.h"
#include "scenes/init.h"
#include "utils/error.h"

t_result	init_map_editor_resources(t_scene *scene)
{
	if (scene == NULL)
		return (throw_error("init_editor_resources", "NULL pointer provided"));
	if (!load_editor_button_down_images(&scene->resources.images))
		return (throw_error("init_editor_resources", "load_button_down failed"));
	if (!load_editor_button_up_images(&scene->resources.images))
		return (throw_error("init_editor_resources", "load_button_up failed"));
	if (!load_editor_button_plus_images(&scene->resources.images))
		return (throw_error("init_editor_resources", "load_button_plus failed"));
	if (!load_editor_button_x_images(&scene->resources.images))
		return (throw_error("init_editor_resources", "load_button_x failed"));
	return (OK);
}