/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_build.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 20:36:14 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/29 06:45:31 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entity/entity_update.h"
#include "engine/component/action.h"
#include "engine/scene/scene_init.h"
#include "engine/game/game_init.h"
#include "utils/parser.h"
#include "utils/error.h"
#include "build.h"

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

t_result	build_scene_background_texture_with_obj(t_game *game,
				t_scene *scene, t_dnon_object *scene_obj)
{
	if (game == NULL || scene == NULL || scene_obj == NULL)
		return (throw_error("build_scene_background", "NULL pointer provided"));
	if (!build_textures_with_obj(&game->resources.images,
		&scene->background,
		get_child_list_object_by_key(scene_obj, "background")))
		return (ERROR);
	if (&scene->background != scene->background.next)
		scene->bg = (t_texture*)scene->background.next;
	return (OK);
}

t_result	build_scene_key_binding(t_game *game, t_scene *scene,
				t_dnon_object *key_binding_obj)
{
	t_action_node	*action;
	
	if (game == NULL || scene == NULL || key_binding_obj)
		return (throw_error("build_scene_key_binding", "NULL pointer"));
	if (!(action = init_new_action()))
		return (throw_error("build_scene_key_binding", "new_action failed"));
	action->args = get_child_list_object_by_key(key_binding_obj, "args");
	init_action_resource_type_by_key(action, key_binding_obj);
	build_action_by_key(action, key_binding_obj);
	if (action->resource_type ==  R_GAME)
		action->resource = game;
	list_add_entry(&action->node, &scene->interface.key_binds);
	return (OK);
}

t_result	build_scene_key_binding_with_obj(t_game *game, t_scene *scene,
				t_dnon_object *key_binding_obj)
{
	t_key_binding	*bind;

	if (game == NULL || scene == NULL || key_binding_obj)
		return (throw_error("build_scene_key_binding", "NULL pointer"));
	if (!(bind = init_new_key_binding()))
		return (throw_error("build_scene_key_binding", "new_key_binding fail"));
	if ((bind->key = get_int_value_by_key(key_binding_obj, "key", -1)) == -1)
		return (throw_error("build_scene_key_binding", "key code not found"));
	bind->action.args = get_child_list_object_by_key(key_binding_obj, "args");
	init_action_resource_type_by_key(&bind->action, key_binding_obj);
	build_action_by_key(&bind->action, key_binding_obj);
	if (bind->action.resource_type ==  R_GAME)
		bind->action.resource = game;
	if (get_int_value_by_key(key_binding_obj, "hold", 0))
		list_add_entry(&bind->action.node, &scene->interface.key_hold_binds);
	else
		list_add_entry(&bind->action.node, &scene->interface.key_binds);
	return (OK);
}

t_result	build_scene_key_bindings(t_game *game, t_scene *scene,
				t_dnon_object *key_bindings_obj)
{
	t_dnon_object	*key_binding_obj;
	t_list_head		*pos;

	if (game == NULL || scene == NULL)
		return (throw_error("build_scene_key_bindings", "NULL pointer"));
	if (key_bindings_obj == NULL)
		return (ERROR);
	pos = (t_list_head*)key_bindings_obj->value;
	while ((pos = pos->next) != (t_list_head*)key_bindings_obj->value)
	{
		key_binding_obj = (t_dnon_object*)pos;
		if (key_binding_obj->type == LIST)
			build_scene_key_binding(game, scene, key_binding_obj);
	}
	return (OK);
}

t_result	build_scene_with_obj(t_game *game, t_dnon_object *scene_obj)
{
	t_scene			*scene;
	t_result		result;

	if (game == NULL || scene_obj == NULL)
		return (throw_error("build_menu_scene", "NULL pointer provided"));
	if (!(scene = init_new_scene()))
		return (throw_error("build_menu_scene", "init_new_scene failed"));
	if (!(scene->name = get_string_value_by_key(scene_obj, "name", NULL)))
		return (throw_error("build_menu_scene", "scene name not found"));
	scene->interface.screen_ref = &game->interface.screen;
	throw_debug("new scene:", scene->name, 1);
	result = build_scene_background_texture_with_obj(game, scene, scene_obj);
	throw_debug("scene_background:\t\t\t", result ? "OK" : "FAIL", 0);
	result = build_voxel_map_config_with_obj(&scene->map_render_config,
			get_child_list_object_by_key(scene_obj, "map_config"));
	throw_debug("scene_map_config:\t\t\t", result ? "OK" : "FAIL", 0);
	result = build_scene_entities_with_obj(&game->resources, scene,
			get_child_list_object_by_key(scene_obj, "entities"));
	throw_debug("scene entities:\t\t\t\t", result ? "OK" : "FAIL", 0);
	build_scene_key_bindings(game, scene,
		get_child_list_object_by_key(scene_obj, "key_bindings"));
	if (get_int_value_by_key(scene_obj, "current", 0))
		game->curr_scene = scene;
	list_add_entry(&scene->node, &game->resources.scenes);
	return (OK);
}

t_result	build_game_resources_scenes(t_game *game,
				t_dnon_object *scenes_obj)
{
	t_dnon_object	*scene_obj;
	t_list_head		*pos;
	t_result		result;

	if (game == NULL || scenes_obj == NULL)
		return (throw_error("build_game_scenes", "NULL pointer provided"));
	pos = (t_list_head*)scenes_obj->value;
	while ((pos = pos->next) != (t_list_head*)scenes_obj->value)
	{
		scene_obj = (t_dnon_object*)pos;
		if (scene_obj->type == LIST)
		{
			result = build_scene_with_obj(game, scene_obj);
			throw_debug("scene added:\t\t\t\t", result ? "OK" : "FAIL", 1);
		}
	}
	ft_putstr("scenes_added\n");
	return (OK);
}
