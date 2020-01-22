/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_entities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 22:52:40 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/22 04:50:31 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entities/sprites/build_ennemy.h"
#include "engine/entities/ui/build_image.h"
#include "engine/entities/ui/build_button.h"
#include "engine/entities/build_player.h"
#include "engine/entities/update_entity.h"
#include "engine/entities/get_entity.h"
#include "utils/error.h"
#include "utils/parser.h"
#include "build.h"

t_result	build_entity_by_type(t_scene *scene, t_dnon_object *entity_obj,
				char *entity_type)
{
	if (!ft_strcmp(entity_type, "button"))
		return (build_button(scene, entity_obj));
	if (!ft_strcmp(entity_type, "image"))
		return (build_image(scene, entity_obj));
	if (!ft_strcmp(entity_type, "player"))
		return (build_player(scene, entity_obj));
	if (!ft_strcmp(entity_type, "ennemy"))
		return (build_ennemy(scene, entity_obj));
	// else if (!ft_strcmp(entity_type, "button"))
	// 	return (build_buttton(scene, entity_obj));
	return (throw_error("build_entity_by_type", "unknow type detected"));
}

t_result	build_entities(t_scene *scene, t_list_head *entities)
{
	t_list_head			*pos;
	t_list_head			*next;
	t_dnon_object		*entity;

	if (scene == NULL || entities == NULL)
		return (throw_error("build_entities", "NULL pointer provided"));
	pos = entities;
	next = pos->next;
	while ((pos = next) != entities)
	{
		next = next->next;
		entity = (t_dnon_object*)pos;
		if (entity->type != LIST)
			return (throw_error("build_entities", "obj must be type LIST"));
		if (!build_entity_by_type(scene, entity,
				get_string_value_by_key(entity, "type", NULL)))
			return (throw_error("build_entities", "failed to build"));
	}
	return (OK);
}
