/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mgame_resources.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 15:18:54 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/18 16:50:00 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/interface/events/keyboard.h"
#include "engine/scenes/init_scene.h"
#include "build.h"
#include "utils/error.h"

t_result	init_game_resources(t_scene *scene)
{
	if (scene == NULL)
		return (throw_error("init_editor_resources", "NULL pointer provided"));
	if (!load_pistol_images(&scene->resources.images))
		return (throw_error("init_editor_resources", "load_button_down failed"));
	if (!load_shootgun_images(&scene->resources.images))
		return (throw_error("init_editor_resources", "load_button_up failed"));
	if (!load_ennemy_images(&scene->resources.images))
		return (throw_error("init_editor_resources", "load_button_up failed"));
	return (OK);
}
