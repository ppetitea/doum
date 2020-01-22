/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_editor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 15:57:14 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/21 23:22:41 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/scenes/init_scene.h"
#include "engine/init_game.h"
#include "utils/error.h"
#include "build.h"

t_scene		*init_map_editor_scene(t_game *game, t_dnon_object *scene_obj)
{
	char			*name;
	t_scene			*scene;
	t_dnon_object	*resources_obj;

	name = NULL;
	if (game == NULL || scene_obj == NULL)
		return (throw_null("init_map_editor", "NULL pointer provided"));
	if (!(resources_obj = get_child_list_object_by_key(scene_obj, "resources")))
		return (throw_null("init", "fail to find editor resources in file"));
	if (!(name = ft_strdup("map_editor")))
		return (throw_null("init_map_editor", "strdup failed"));
	if (!(scene = init_new_scene(name, &game->screen)))
		return (throw_null("init_map_editor", "build_scene failed"));
	if (!init_map_editor_interface(scene))
		return (throw_null("init_map_editor", "init_map_editor_interface failed"));
	if (!init_map_editor_resources(scene))
		return (throw_null("init_map_editor", "init_map_editor_resources failed"));
	if (!init_map_editor_entities(scene))
		return (throw_null("init_map_editor", "init_map_editor_entities failed"));
	list_add_entry(&scene->node, &game->scenes);
	return (scene);
}