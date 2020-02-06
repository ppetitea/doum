/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_build.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 00:39:12 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/06 20:22:23 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build.h"
#include "utils/error.h"

static t_result	add_weapon_to_character_with_obj(t_character *character,
					t_weapon *weapon, t_dnon_object *weapon_obj)
{
	if (character == NULL || weapon == NULL || weapon_obj == NULL)
		return (throw_error("add_weapon", "NULL pointer provided"));
	if (get_int_value_by_key(weapon_obj, "active", 0))
	{
		list_add_entry(&weapon->node, &character->weapons);
		if (get_int_value_by_key(weapon_obj, "current", 0))
			character->curr_weapon = weapon;
	}
	else
		list_add_entry(&weapon->node, &character->all_weapons);
	return (OK);
}

t_result	build_character_weapon_with_obj(t_game_resources *resources,
				t_character *character, t_dnon_object *weapon_obj)
{
	t_weapon	*weapon;

	if (character == NULL || weapon_obj == NULL)
		return (throw_error("build_char_weapons", "NULL pointer provided"));
	if (!(weapon = init_new_weapon()))
		return (throw_error("build_char_weapons", "init_new_weapon failed"));
	build_weapon_type_with_obj(weapon, weapon_obj);
	if (!(weapon->name = get_string_value_by_key(weapon_obj, "name", NULL)))
		return (throw_error("build_player_weapon", "weapon name failed"));
	throw_debug("", weapon->name, 0);
	weapon->ammo = get_int_value_by_key(weapon_obj, "ammo", 0);
	weapon->damages = get_int_value_by_key(weapon_obj, "damages", 3);
	weapon->magazine = get_int_value_by_key(weapon_obj, "magazine", 0);
	weapon->magazine_size = get_int_value_by_key(weapon_obj, "magazine_size",
		0);
	if (!build_character_weapon_textures(&resources->images, weapon,
		get_child_list_object_by_key(weapon_obj, "textures")))
		return (throw_error("build_player_weapon", "weapon textures failed"));
	if (!add_weapon_to_character_with_obj(character, weapon, weapon_obj))
		return (throw_error("build_player_weapon", "add_weapon failed"));
	return (OK);
}
