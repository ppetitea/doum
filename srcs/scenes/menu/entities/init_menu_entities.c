/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_menu_entities.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 15:18:54 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/18 21:19:18 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/scenes/build_scene.h"
#include "engine/game.h"
#include "scenes/init.h"
#include "utils/error.h"

t_result	init_menu_entities(t_scene *scene)
{
	if (scene == NULL)
		return (throw_error("init_menu_entities", "NULL pointer provided"));
	if (!init_menu_button_start(scene))
		return (throw_error("init_menu_entities", "init button start failed"));
	return (OK);
}
