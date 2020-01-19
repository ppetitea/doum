/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 15:18:54 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/19 20:02:51 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/scenes/init_scene.h"
#include "engine/init_game.h"
#include "init.h"
#include "utils/error.h"

t_result	init_menu_scene(t_game *game)
{
	char	*name;
	t_scene	*scene;

	name = NULL;
	if (game == NULL)
		return (throw_error("init_menu", "NULL pointer provided"));
	if (!(name = ft_strdup("menu")))
		return (throw_error("init_menu", "strdup failed"));
	if (!(scene = build_scene(name, &game->screen)))
		return (throw_error("init_menu", "build_scene failed"));
	if (!init_menu_interface(scene))
		return (throw_error("init_menu", "init_menu_interface failed"));
	if (!init_menu_resources(scene))
		return (throw_error("init_menu", "init_menu_resources failed"));
	if (!init_menu_entities(scene))
		return (throw_error("init_menu", "init_menu_entities failed"));
	list_add_entry(&scene->node, &game->scenes);
	return (OK);
}