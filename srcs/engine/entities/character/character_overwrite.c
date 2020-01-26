/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_overwrite.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 07:21:06 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/26 08:56:02 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entity/character_update.h"
#include "engine/entity/character_action.h"
#include "engine/entity/character_init.h"
#include "engine/entity/entity_update.h"
#include "utils/error.h"

t_result	overwrite_character_hud_with_obj(t_character *self,
				t_dnon_object *character_obj)
{
	int		i;
	float	f;

	if (self == NULL || character_obj == NULL)
		return (throw_error("overwrite_character_hud", "NULL pointer"));
	if ((i = get_int_value_by_key(character_obj, "life", -1)) != -1)
		self->life = i;
	if ((i = get_int_value_by_key(character_obj, "armor", -1)) != -1)
		self->armor = i;
	if ((f = get_float_value_by_key(character_obj, "velocity", -1)) != -1)
		self->velocity = f;
	if ((f = get_float_value_by_key(character_obj, "size", -1)) != -1)
		self->size = f;
	return (OK);
}

t_result	overwrite_character_with_obj(t_character *self,
				t_dnon_object *character_obj)
{
	t_dnon_object *camera_obj;
	t_dnon_object *weapons_obj;
	t_dnon_object *entity_obj;

	if (self == NULL || character_obj == NULL)
		return (throw_error("overwrite_character", "NULL pointer provided"));
	if ((camera_obj = get_child_list_object_by_key(character_obj, "camera")))
		overwrite_camera_with_obj(&self->camera, camera_obj);
	if ((weapons_obj = get_child_list_object_by_key(character_obj, "weapons")))
		overwrite_weapons_with_obj(self, weapons_obj);
	if ((entity_obj = get_child_list_object_by_key(character_obj, "entity")))
		overwrite_entity_with_obj(&self->super, entity_obj);
	overwrite_character_hud_with_obj(self, character_obj);
	return (OK);
}

