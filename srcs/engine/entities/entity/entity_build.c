/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_build.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 23:14:53 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/28 05:00:00 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/game/game_init.h"
#include "build.h"

t_result	build_entity_with_obj(t_game_resources *resources,
				t_entity *entity, t_dnon_object *entity_obj)
{
	if (resources == NULL || entity == NULL || entity_obj == NULL)
		return (throw_error("init_game_resource_entity", "NULL pointer"));
	if (!(entity->name = get_string_value_by_key(entity_obj, "name", NULL)))
		return (throw_error("init_game_resource_entity", "name not found"));
	throw_debug("NEW ENTITY:", entity->name, 3);
	build_entity_status_with_obj(&entity->status,
			get_child_list_object_by_key(entity_obj, "status"));
	if (!build_entity_textures_with_obj(&resources->images, &entity->texture,
			get_child_list_object_by_key(entity_obj, "textures")))
		return (throw_error("build_game_entity", "textures failed"));
	return (OK);
}

t_result	build_new_entity_with_obj(t_game_resources *resources,
				t_dnon_object *ui_obj)
{
	t_entity	*entity;

	if (resources == NULL || ui_obj == NULL)
		return (throw_error("build_resource_entity", "NULL pointer provided"));
	if (!(entity = init_new_entity(UI)))
		return (throw_error("build_resource_entity", "init_new_entity failed"));
	if (!build_entity_with_obj(resources, entity, ui_obj))
		return (throw_error("build_resource_entity", "build_entity failed"));
	list_add_entry(&entity->node, &resources->entities);
	return (OK);
}
