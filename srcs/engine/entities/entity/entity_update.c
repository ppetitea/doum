/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 00:00:39 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/01 01:05:40 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entity/entity_update.h"
#include "engine/component/action.h"
#include "engine/game/game_init.h"
#include "utils/parser.h"
#include "utils/error.h"

t_result	update_entity_texture_to_hover(t_entity *entity)
{
	if (entity == NULL)
		return (throw_error("update_entity_texture_to_hover", "NUL pointer"));
	if (entity->texture.hover != entity->texture.hover->next)
		entity->texture.curr = (t_texture*)entity->texture.hover->next;
	return (OK);
}

t_result	update_entity_texture_to_normal(t_entity *entity)
{
	if (entity == NULL)
		return (throw_error("update_entity_texture_to_normal", "NUL pointer"));
	if (entity->texture.normal != entity->texture.normal->next)
		entity->texture.curr = (t_texture*)entity->texture.normal->next;
	return (OK);
}

t_result	update_entity_texture_to_dragged(t_entity *entity)
{
	if (entity == NULL)
		return (throw_error("update_entity_texture_to_dragged", "NUL pointer"));
	if (entity->texture.dragged != entity->texture.dragged->next)
		entity->texture.curr = (t_texture*)entity->texture.dragged->next;
	return (OK);
}

t_result	update_entity_texture(void *entity_resource,
				t_resource_type resource_type, t_dnon_object *args)
{
	t_entity	*entity;
	
	if (entity_resource == NULL || args == NULL)
		return (throw_error("update_entity_texture", "NULL pointer"));
	if (resource_type != R_ENTITY)
		return (throw_error("update_entity_texture", "resource isn't entity"));
	entity = (t_entity*)entity_resource;
	if (get_int_value_by_key(args, "hover", 0))
		update_entity_texture_to_hover(entity);
	else if (get_int_value_by_key(args, "normal", 0))
		update_entity_texture_to_normal(entity);
	else if (get_int_value_by_key(args, "dragged", 0))
		update_entity_texture_to_dragged(entity);
	else
		return (throw_error("update_entity_texture", "wrong args detected"));
	return (OK);
}
