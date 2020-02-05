/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entities_overwrite.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 06:42:24 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/04 16:07:29 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entity/character_update.h"
#include "engine/entity/entity_update.h"
#include "utils/error.h"

#include <stdio.h>

t_result	overwrite_entity_by_type_with_obj(t_entity *entity,
				t_dnon_object *entity_obj)
{
	if (entity == NULL || entity_obj == NULL)
		return (throw_error("overwrite_entity_by_type", "NULL pointer"));
	if (entity->type == CHARACTER)
		return (overwrite_character_with_obj((t_character*)entity,
			get_child_list_object_by_key(entity_obj, "character")));
	else if (entity->type == UI)
		return (overwrite_entity_with_obj(entity,
			get_child_list_object_by_key(entity_obj, "entity")));
	else
		return (throw_warning_error("overwrite_entities", "type not found", 2));
}

t_result	overwrite_entities_by_type_with_obj(t_list_head *entities,
				t_dnon_object *entity_obj)
{
	t_list_head	*pos;
	t_list_head	*next;
	t_entity	*entity;

	if (entities == NULL || entity_obj == NULL)
		return (throw_error("overwrite_entities_with_obj", "NULL pointer"));
	pos = entities;
	next = pos->next;
	while ((pos = next) != entities)
	{
		next = next->next;
		entity = (t_entity*)pos;
		if (entity->type == CHARACTER)
			overwrite_character_with_obj((t_character*)entity, entity_obj);
		else if (entity->type == UI)
			overwrite_entity_with_obj(entity, entity_obj);
		// printf("entity draggable [%s]\n", entity->status.is_draggable ? "TRUE" : "FALSE");
	}
	return (OK);
}