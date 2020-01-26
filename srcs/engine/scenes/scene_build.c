/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_build.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 20:36:14 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/26 21:27:03 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entity/entity_update.h"
#include "engine/scene/scene_init.h"
#include "engine/game/game_init.h"
#include "utils/parser.h"
#include "utils/error.h"
#include "build.h"

t_result	set_entity_action_with_obj(t_entity *self, t_list_head *render,
				t_list_head *storage, t_dnon_object *entity_obj)
{
	if (self == NULL || render == NULL || storage == NULL || entity_obj == NULL)
		return (throw_error("set_entity_action_with_obj", "NULL pointer"));
	// YOU ARE HERE <3

	return (OK);
}

t_result	build_scene_entity_with_obj(t_game_resources *resources, 
				t_list_head *render, t_list_head *storage,
				t_dnon_object *entity_obj)
{
	t_entity	*src;
	t_entity	*entity;
	char		*name;

	if (resources == NULL || render == NULL || storage == NULL
		|| entity_obj == NULL)
		return (throw_error("build_scene_entity", "NULL pointer provided"));
	if (!(name = get_string_value_by_key(entity_obj, "key", NULL)))
		return (throw_error("build_map_entity_with_obj", "name not found"));
	throw_debug("add entity:", name, 0);
	if (!(src = get_entity_by_name(&resources->entities, name)))
		return (throw_error("build_map_entity_with_obj", "entity not found"));
	if (!(entity = duplicate_entity_by_type(src)))
		return (throw_error("build_map_entity_with_obj", "entity_dup failed"));
	if (!overwrite_entity_by_type_with_obj(entity, entity_obj))
		return (throw_error("build_map_entity_with_obj", "entity_over failed"));
	if (!set_entity_action_with_obj(entity, render, storage, entity_obj))
		return (throw_error("build_map_entity_with_obj", "entity_over failed"));
	if (entity->status.display)
		list_add_entry(&entity->node, render);
	else
		list_add_entry(&entity->node, storage);
	return (OK);
}

t_result	build_scene_entities_with_obj(t_game_resources *resources,
				t_scene *scene, t_dnon_object *scene_entities_obj)
{
	t_dnon_object	*scene_entity_obj;
	t_list_head		*pos;
	t_list_head		*next;
	t_result		result;
	
	if (resources == NULL || scene == NULL)
		return (throw_error("build_scene_entities_with_obj", "NULL pointer"));
	if (scene_entities_obj == NULL)
		return (ERROR);
	pos = (t_list_head*)scene_entities_obj->value;
	next = pos->next;
	while ((pos = next) != (t_list_head*)scene_entities_obj->value)
	{
		next = next->next;
		scene_entity_obj = (t_dnon_object*)pos;
		if (scene_entity_obj->type == LIST)
		{
			result = build_scene_entity_with_obj(resources, &scene->entities,
				&scene->entities_storage, scene_entity_obj);
			throw_warning("entity added:\t\t\t\t", result ? "OK" : "FAIL", 0);
		}
	}
	return (OK);
}

t_result	build_menu_scene_with_obj(t_game *game, t_dnon_object *scene_obj)
{
	t_scene	*scene;

	if (game == NULL || scene_obj == NULL)
		return (throw_error("build_menu_scene", "NULL pointer provided"));
	if (!(scene = init_new_scene(ft_strdup("menu"), &game->interface.screen)))
		return (throw_error("build_menu_scene", "init_new_scene failed"));
	throw_debug("new scene:\t\t", "menu", 1);
	if (!build_textures_with_obj(&game->resources.images, &scene->background,
		get_child_list_object_by_key(scene_obj, "background")))
		return (throw_error("build_menu_scene", "background failed"));
	if (!(scene->map_config = get_child_list_object_by_key(scene_obj, "map")))
		return (throw_error("build_menu_scene", "map_config failed"));
	if (!build_scene_entities_with_obj(&game->resources, scene,
			get_child_list_object_by_key(scene_obj, "entities")))
		return (throw_error("build_menu_scene", "entities failed"));
	return (OK);
}

t_result	build_game_resources_scenes(t_game *game,
				t_dnon_object *scenes_obj)
{
	if (game == NULL || scenes_obj == NULL)
		return (throw_error("build_game_scenes", "NULL pointer provided"));
	if (!build_menu_scene_with_obj(game,
		get_child_list_object_by_key(scenes_obj, "menu")))
		return (throw_error("build_game_scenes", "build_menu failed"));
	//build editor scene
	//build game scene
	return (OK);
}
