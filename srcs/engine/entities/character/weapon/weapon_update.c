/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 07:59:24 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/26 07:59:55 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entity/character_update.h"
#include "utils/error.h"

t_result	update_weapon_activation(t_character *character, t_weapon *weapon,
				t_bool is_active)
{
	if (character == NULL || weapon ==  NULL)
		return (throw_error("update_weapon_activation", "NULL pointer"));
	list_del_entry(&weapon->node);
	if (is_active)
		list_add_entry(&weapon->node, &character->weapons);
	else
		list_add_entry(&weapon->node, &character->all_weapons);
	return (OK);
}
