/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_editor_entities.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 15:18:54 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/18 23:30:08 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/scenes/build_scene.h"
#include "engine/game.h"
#include "scenes/init.h"
#include "utils/error.h"

t_result	init_map_editor_entities(t_scene *scene)
{
	if (scene == NULL)
		return (throw_error("init_editor_entities", "NULL pointer provided"));
	if (!init_map_editor_button_down(scene))
		return (throw_error("init_editor_entities", "init button down fail"));
	if (!init_map_editor_button_up(scene))
		return (throw_error("init_editor_entities", "init button up fail"));
	if (!init_map_editor_spawner_exemple(scene))
		return (throw_error("init_editor_entities", "init spawner fail"));
	return (OK);
}
