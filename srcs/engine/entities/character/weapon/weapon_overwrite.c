/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_overwrite.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 08:23:20 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/26 08:56:47 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entity/character_update.h"
#include "utils/error.h"

t_result	overwrite_weapon_with_obj(t_character *character, t_weapon *self,
				t_dnon_object *weapon_obj)
{
	int		i;
	
	if (self == NULL || weapon_obj == NULL)
		return (throw_error("overwrite_weapon", "NULL pointer provided"));
	if ((i = get_int_value_by_key(weapon_obj, "active", -1)) != -1)
		update_weapon_activation(character, self, i ? TRUE : FALSE);
	if ((i = get_int_value_by_key(weapon_obj, "ammo", -1)) != -1)
		self->ammo = i;
	if ((i = get_int_value_by_key(weapon_obj, "magazine", -1)) != -1)
		self->magazine = i;
	if ((i = get_int_value_by_key(weapon_obj, "magazine_size", -1)) != -1)
		self->magazine_size = i;
	if ((i = get_int_value_by_key(weapon_obj, "damages", -1)) != -1)
		self->damages = i;
	return (OK);
}

t_result	overwrite_weapons_with_obj(t_character *self,
				t_dnon_object *weapons_obj)
{
	t_list_head		*pos;
	t_list_head		*next;
	t_dnon_object	*weapon_obj;
	t_weapon		*weap;
	
	if (self == NULL || weapons_obj == NULL)
		return (throw_error("overwrite_weapons", "NULL pointer provided"));
	pos = (t_list_head*)weapons_obj->value;
	next = pos->next;
	while ((pos = next) != (t_list_head*)weapons_obj->value)
	{
		next = next->next;
		weapon_obj = (t_dnon_object*)pos;
		if ((weap = get_weapon_by_name(&self->all_weapons, weapon_obj->key)))
			overwrite_weapon_with_obj(self, weap, weapon_obj);
		else if ((weap = get_weapon_by_name(&self->weapons, weapon_obj->key)))
			overwrite_weapon_with_obj(self, weap, weapon_obj);
	}
	return (OK);
}
