/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_overwrite.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 06:49:05 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/28 04:12:28 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entity/entity_init.h"
#include "engine/component/action.h"
#include "utils/error.h"
#include "build.h"

t_action_node	*init_new_action()
{
	t_action_node *action;

	if (!(action = (t_action_node*)malloc(sizeof(t_action_node))))
		return (throw_null("init_new_action", "malloc failed"));
	init_list_head(&action->node);
	action->args = NULL;
	action->resource = NULL;
	action->resource_type = R_UNKNOW;
	action->action = NULL;
	return (action);
}

t_result	build_action_by_key(t_action_node *action,
				t_dnon_object *action_obj)
{
	if (action == NULL || action_obj == NULL)
		return (throw_error("build_action_by_key", "NULL pointer provided"));
	if (strcmp_obj("action", "swap_scene", action_obj))
		action->action = NULL;
	else if (strcmp_obj("action", "swap_map", action_obj))
		action->action = NULL;
	else
		return (throw_error("build_action_by_key", "unknow action detected"));
	return (OK);
}

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

t_result	build_entity_action_with_obj(t_entity *entity, t_list_head *actions,
				t_dnon_object *action_obj)
{
	t_action_node	*action;

	if (actions == NULL || action_obj == NULL)
		return (throw_error("build_action_with_obj", "NULL pointer provided"));
	if (!(action = init_new_action()))
		return (throw_error("build_action_with_obj", "init_new_action failed"));
	action->args = get_child_list_object_by_key(action_obj, "args");
	if (!build_action_by_key(action, action_obj))
		return (throw_error("build_action_with_obj", "action_by_key failed"));
	if (!init_action_resource_type_by_key(action, action_obj))
		return (throw_error("build_action_with_obj", "resource_by_key failed"));
	if (action->resource_type == R_ENTITY)
		action->resource = entity;
	else if (action->resource_type == R_GAME)
		action->resource = game_singleton(NULL);
	return (OK);
}

t_result	build_entity_actions_with_obj(t_entity *entity,
				t_list_head *actions, t_dnon_object *actions_obj)
{
	t_list_head		*pos;
	t_list_head		*next;
	t_dnon_object	*action_obj;
	
	if (entity == NULL || actions == NULL)
		return (throw_error("build_action_with_obj", "NULL pointer provided"));
	if (actions_obj == NULL)
		return (ERROR);
	pos = (t_list_head*)actions_obj->value;
	next = pos->next;
	while ((pos = next) != (t_list_head*)actions_obj->value)
	{
		next = next->next;
		action_obj = (t_dnon_object*)pos;
		build_entity_action_with_obj(entity, actions, action_obj);
	}
	return (OK);
}

t_result	overwrite_listener_with_obj(t_entity *entity,
				t_dnon_object *listener_obj)
{
	t_listener		*listener;
	t_dnon_object	*obj;
	int				result_i;

	if (entity == NULL || listener_obj == NULL)
		return (throw_error("overwrite_listener", "NULL pointer provided"));
	listener = &entity->status;
	if ((result_i = get_int_value_by_key(listener_obj, "display", -1)) != -1)
		listener->display = (result_i == 1) ? TRUE : FALSE;
	if ((result_i = get_int_value_by_key(listener_obj, "hoverable", -1)) != -1)
		listener->is_hoverable = (result_i == 1) ? TRUE : FALSE;
	if ((result_i = get_int_value_by_key(listener_obj, "selectable", -1)) != -1)
		listener->is_selectable = (result_i == 1) ? TRUE : FALSE;
	if ((result_i = get_int_value_by_key(listener_obj, "draggable", -1)) != -1)
		listener->is_draggable = (result_i == 1) ? TRUE : FALSE;
	if ((obj = get_child_list_object_by_key(listener_obj, "select")))
		build_entity_actions_with_obj(entity, &listener->select_actions, obj);
	if ((obj = get_child_list_object_by_key(listener_obj, "drag")))
		build_entity_actions_with_obj(entity, &listener->drag_actions, obj);
	if ((obj = get_child_list_object_by_key(listener_obj, "drop")))
		build_entity_actions_with_obj(entity, &listener->drop_actions, obj);
	return (OK);
}

t_result	overwrite_entity_texture_with_obj(t_entity_texture *self,
				t_dnon_object *e_texture_obj)
{
	char			*string;
	float			result_f;
	t_dnon_object	*vec2i_obj;

	if (self == NULL || e_texture_obj == NULL)
		return (throw_error("overwrite_e_texture", "NULL pointer provided"));
	if ((result_f = get_float_value_by_key(e_texture_obj, "scale", -1)) != -1)
		self->scale = result_f;
	if ((vec2i_obj = get_child_list_object_by_key(e_texture_obj, "offset")))
		init_vec2i_with_obj(&self->offset, vec2i_obj);
	if ((vec2i_obj = get_child_list_object_by_key(e_texture_obj, "anchor")))
		init_vec2i_with_obj(&self->anchor, vec2i_obj);
	if ((string = get_string_value_by_key(e_texture_obj, "animation", NULL)))
		build_entity_animation_type_with_obj(self, e_texture_obj);
	return (OK);
}

t_result	overwrite_entity_with_obj(t_entity *self, t_dnon_object *entity_obj)
{
	t_dnon_object	*listener_obj;
	t_dnon_object	*e_texture_obj;
	
	if (self == NULL || entity_obj == NULL)
		return (throw_error("overwrite_entity", "NULL pointer provided"));
	if ((listener_obj = get_child_list_object_by_key(entity_obj, "listener")))
		overwrite_listener_with_obj(self, listener_obj);
	if ((e_texture_obj = get_child_list_object_by_key(entity_obj, "texture")))
		overwrite_entity_texture_with_obj(&self->texture, e_texture_obj);
	return (OK);
}
