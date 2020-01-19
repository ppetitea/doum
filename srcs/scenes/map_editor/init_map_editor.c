/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_editor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 15:57:14 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/19 20:02:51 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/scenes/init_scene.h"
#include "engine/init_game.h"
#include "init.h"
#include "utils/error.h"

t_result	init_map_editor_scene(t_game *game)
{
	char	*name;
	t_scene	*scene;
	
	name = NULL;
	if (game == NULL)
		return (throw_error("init_map_editor", "NULL pointer provided"));
	if (!(name = ft_strdup("map_editor")))
		return (throw_error("init_map_editor", "strdup failed"));
	if (!(scene = build_scene(name, &game->screen)))
		return (throw_error("init_map_editor", "build_scene failed"));
	if (!init_map_editor_interface(scene))
		return (throw_error("init_map_editor", "map_editor_interface failed"));
	if (!init_map_editor_resources(scene))
		return (throw_error("init_map_editor", "map_editor_resources failed"));
	if (!init_map_editor_entities(scene))
		return (throw_error("init_map_editor", "map_editor_entities failed"));
	list_add_entry(&scene->node, &game->scenes);
	return (OK);
}
