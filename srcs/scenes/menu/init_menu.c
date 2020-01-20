/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 15:18:54 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/20 04:13:36 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/scenes/init_scene.h"
#include "engine/init_game.h"
#include "init.h"
#include "utils/error.h"

t_scene	*init_menu_scene(t_game *game)
{
	char	*name;
	t_scene	*scene;

	name = NULL;
	if (game == NULL)
		return (throw_null("init_menu", "NULL pointer provided"));
	if (!(name = ft_strdup("menu")))
		return (throw_null("init_menu", "strdup failed"));
	if (!(scene = init_new_scene(name, &game->screen)))
		return (throw_null("init_menu", "build_scene failed"));
	if (!init_menu_interface(scene))
		return (throw_null("init_menu", "init_menu_interface failed"));
	if (!init_menu_resources(scene))
		return (throw_null("init_menu", "init_menu_resources failed"));
	if (!init_menu_entities(scene))
		return (throw_null("init_menu", "init_menu_entities failed"));
	list_add_entry(&scene->node, &game->scenes);
	return (scene);
}