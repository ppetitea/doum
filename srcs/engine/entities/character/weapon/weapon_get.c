/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 02:41:10 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/26 14:33:56 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entity/character_init.h"
#include "utils/error.h"

#include <stdio.h>

t_weapon	*get_weapon_by_name(t_list_head *weapons, char *name)
{
	t_weapon	*weapon;
	t_list_head	*pos;
	t_list_head	*next;

	if (weapons == NULL || name == NULL)
		return (throw_null("get_weapon_by_name", "NULL pointer provided"));
	pos = weapons;
	next = pos->next;
	while ((pos = next) != weapons)
	{
		next = next->next;
		weapon = (t_weapon*)pos;
		if (!ft_strcmp(weapon->name, name))
			return (weapon);
	}
	throw_warning("weapon not found:", name, 2);
	return (NULL);
}
