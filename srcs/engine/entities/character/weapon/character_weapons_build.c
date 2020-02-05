/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_weapons_build.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 00:38:36 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/26 04:29:05 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "build.h"

t_result	build_character_weapons_with_obj(t_game_resources *resources,
				t_character *character, t_dnon_object *weapons_obj)
{
	t_list_head			*pos;
	t_list_head			*next;
	t_dnon_object		*weapon_obj;

	if (resources == NULL || character == NULL || weapons_obj == NULL)
		return (throw_error("build_char_weapons", "NULL pointer provided"));
	throw_debug("weapons:", "", 0);
	pos = (t_list_head*)weapons_obj->value;
	next = pos->next;
	while ((pos = next) != (t_list_head*)weapons_obj->value)
	{
		next = next->next;
		weapon_obj = (t_dnon_object*)pos;
		if (weapon_obj->type != LIST)
			return (throw_error("build_char_weapons", "obj must be a LIST"));
		else
			build_character_weapon_with_obj(resources, character, weapon_obj);
	}
	return (OK);
}
