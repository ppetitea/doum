/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_build.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 05:42:05 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/02 00:01:54 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entity/entity_init.h"
#include "engine/component/action.h"
#include "utils/error.h"
#include "build.h"

t_result	init_action_resource_type_by_key(t_action_node *action,
				t_dnon_object *action_obj)
{
	if (action == NULL || action_obj == NULL)
		return (throw_error("build_action_resource_by_key", "NULL pointer"));
	if (strcmp_obj("resource", "game", action_obj))
		action->resource_type = R_GAME;
	else if (strcmp_obj("resource", "scene", action_obj))
		action->resource_type = R_SCENE;
	else if (strcmp_obj("resource", "map", action_obj))
		action->resource_type = R_MAP;
	else if (strcmp_obj("resource", "character", action_obj))
		action->resource_type = R_CHARACTER;
	else if (strcmp_obj("resource", "entity", action_obj))
		action->resource_type = R_ENTITY;
	else if (strcmp_obj("resource", "entity_list", action_obj))
		action->resource_type = R_ENTITY_LIST;
	else
		return (throw_error("build_action_resource_by_key", "unknow resource"));
	return (OK);
}

t_result	build_action_by_key(t_action_node *action,
				t_dnon_object *action_obj)
{
	if (action == NULL || action_obj == NULL)
		return (throw_error("build_action_by_key", "NULL pointer provided"));
	if (strcmp_obj("action", "stop_game", action_obj))
		action->action = stop_game;
	else if (strcmp_obj("action", "swap_scene", action_obj))
		action->action = swap_scene;
	else if (strcmp_obj("action", "swap_map", action_obj))
		action->action = swap_map;
	else if (strcmp_obj("action", "rotate_camera", action_obj))
		action->action = rotate_camera;
	else if (strcmp_obj("action", "translate_camera", action_obj))
		action->action = translate_camera;
	else if (strcmp_obj("action", "translate_camera_horizon", action_obj))
		action->action = translate_camera_horizon;
	else if (strcmp_obj("action", "update_entity_texture", action_obj))
		action->action = update_entity_texture;
	else if (strcmp_obj("action", "spawn_character", action_obj))
		action->action = spawn_character;
	else
		return (throw_error("build_action_by_key", "unknow action detected"));
	return (OK);
}
