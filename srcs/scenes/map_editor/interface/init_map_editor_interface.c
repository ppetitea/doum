/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_editor_interface.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 15:18:54 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/20 19:15:51 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/interface/events/keyboard.h"
#include "engine/scenes/init_scene.h"
#include "engine/scenes/update_scene.h"
#include "engine/init_game.h"
#include "init.h"
#include "utils/error.h"

t_result	init_map_editor_interface(t_scene *scene)
{
	if (scene == NULL)
		return (throw_error("init_editor_interface", "NULL pointer provided"));
	new_bind_key(&scene->interface.key_binds, SDLK_ESCAPE,
		swap_to_menu_scene);
	return (OK);
}
