/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entities_build.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 23:16:03 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/06 20:20:48 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/game/game_init.h"
#include "build.h"
#include "utils/error.h"

static t_result	build_game_entity_by_type(t_game_resources *resources,
				t_dnon_object *entity_obj)
{
	if (resources == NULL || entity_obj == NULL)
		return (throw_error("build_game_entities", "NULL pointer provided"));
	if (strcmp_obj("type", "character", entity_obj))
		build_character_with_obj(resources, entity_obj);
	else if (strcmp_obj("type", "ui", entity_obj))
		build_new_entity_with_obj(resources, entity_obj);
	else
		throw_warning_error("build_game_entities", "unknow entity detected", 3);
	return (OK);
}

t_result	build_game_entities(t_game_resources *resources,
				t_dnon_object *entities_obj)
{
	t_list_head			*pos;
	t_list_head			*next;
	t_dnon_object		*entity_obj;

	if (resources == NULL || entities_obj == NULL)
		return (throw_error("build_game_entities", "NULL pointer provided"));
	pos = (t_list_head*)entities_obj->value;
	next = pos->next;
	while ((pos = next) != (t_list_head*)entities_obj->value)
	{
		next = next->next;
		entity_obj = (t_dnon_object*)pos;
		if (entity_obj->type != LIST)
			return (throw_error("build_entities", "obj must be type LIST"));
		if (!build_game_entity_by_type(resources, entity_obj))
			return (throw_error("build_entities", "failed to build entity"));
	}
	return (OK);
}
