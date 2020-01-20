/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_menu_entities.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 15:18:54 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/20 04:07:35 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/scenes/init_scene.h"
#include "engine/init_game.h"
#include "init.h"
#include "utils/error.h"

t_result	init_menu_entities(t_scene *scene)
{
	if (scene == NULL)
		return (throw_error("init_menu_entities", "NULL pointer provided"));
	if (!init_menu_button_down(scene))
		return (throw_error("init_menu_entities", "init button down failed"));
	return (OK);
}
