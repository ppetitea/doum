/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 15:18:54 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/21 03:43:28 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/scenes/init_scene.h"
#include "engine/init_game.h"
#include "init.h"
#include "utils/error.h"

t_scene	*init_menu_scene(t_game *game, t_dnon_object *scene_obj)
{
	char			*name;
	t_scene			*scene;
	t_dnon_object	*resources_obj;
	t_dnon_object	*entities_obj;

	name = NULL;
	if (game == NULL || scene_obj == NULL)
		return (throw_null("init_menu", "NULL pointer provided"));
	if (!(resources_obj = get_child_list_object_by_key(scene_obj, "resources")))
		return (throw_null("init", "fail to find menu resources in file"));
	if (!(entities_obj = get_child_list_object_by_key(scene_obj, "entities")))
		return (throw_null("init", "fail to find menu entities in file"));
	if (!(name = ft_strdup("menu")))
		return (throw_null("init_menu", "strdup failed"));
	if (!(scene = init_new_scene(name, &game->screen)))
		return (throw_null("init_menu", "build_scene failed"));
	if (!init_menu_interface(scene))
		return (throw_null("init_menu", "init_menu_interface failed"));
	if (!init_menu_resources(scene, resources_obj))
		return (throw_null("init_menu", "init_menu_resources failed"));
	if (!init_menu_entities(scene, entities_obj))
		return (throw_null("init_menu", "init_menu_entities failed"));
	list_add_entry(&scene->node, &game->scenes);
	return (scene);
}