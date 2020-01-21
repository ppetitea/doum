/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_menu_interface.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 15:18:54 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/20 20:19:27 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/interface/events/keyboard.h"
#include "engine/scenes/init_scene.h"
#include "engine/scenes/update_scene.h"
#include "engine/init_game.h"
#include "engine/update_game.h"
#include "init.h"
#include "utils/error.h"

t_result	init_menu_interface(t_scene *scene)
{
	if (scene == NULL)
		return (throw_error("init_menu_interface", "NULL pointer provided"));
	new_bind_key(&scene->interface.key_binds, SDLK_ESCAPE,
		destroy_game);
	return (OK);
}