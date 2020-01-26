/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entities_overwrite.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 06:42:24 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/26 08:19:44 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entity/character_update.h"
#include "engine/entity/entity_update.h"
#include "utils/error.h"

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
