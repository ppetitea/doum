/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_menu_resources.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 15:18:54 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/19 16:41:59 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/interface/events/keyboard.h"
#include "engine/scenes/init_scene.h"
#include "init.h"
#include "utils/error.h"

t_result	init_menu_resources(t_scene *scene)
{
	if (scene == NULL)
		return (throw_error("init_menu_resources", "NULL pointer provided"));
	if (!load_menu_button_down_images(&scene->resources.images))
		return (throw_error("init_menu_resources", "load_button_down failed"));
	return (OK);
}