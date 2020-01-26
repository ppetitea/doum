/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_dup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 02:27:31 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/26 02:54:42 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entity/character_init.h"
#include "engine/entity/character_update.h"
#include "utils/error.h"

t_weapon	*duplicate_weapon(t_weapon *src)
{
	t_weapon	*dest;

	if (src == NULL)
		return (throw_null("duplicate_weapon", "NULL pointer provided"));
	if (!(dest = init_new_weapon()))
		return (throw_null("duplicate_weapon", "init_new_weapon failed"));
	dest->type = src->type;
	dest->name = src->name;
	dest->ammo = src->ammo;
	dest->damages = src->damages;
	dest->magazine = src->magazine;
	dest->magazine_size = src->magazine_size;
	dest->fire = src->fire;
	dest->reload = src->reload;
	return (dest);
}
