/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_interface.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 15:18:54 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/18 23:54:52 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/interface/events/keyboard.h"
#include "engine/scenes/build_scene.h"
#include "engine/game.h"
#include "scenes/init.h"
#include "utils/error.h"

t_result	init_game_interface(t_scene *scene)
{
	if (scene == NULL)
		return (throw_error("init_game_interface", "NULL pointer provided"));
	// bind_key(&scene->interface.keys_binds, SDLK_RETURN, launch_game());
	(void)scene;
	return (OK);
}
