/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_weapon.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 01:16:28 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/22 01:34:54 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/error.h"
#include "engine/entities/init_player.h"

t_weapon	*init_new_weapon()
{
	t_weapon	*new;

	if (!(new = (t_weapon*)malloc(sizeof(t_weapon))))
		return (throw_null("build weapon", "malloc failed"));
	init_list_head(&new->node);
	init_list_head(&new->fire);
	init_list_head(&new->reload);
	new->type = GUN;
	new->name = NULL;
	new->ammo = 100;
	new->magazine_size = 10;
	new->magazine = new->magazine_size;
	new->damages = 42;
	return (new);
}

t_result	overwrite_weapon_ammo(t_weapon *self, size_t ammo,
				size_t magazine_size, size_t magazine)
{
	if (self == NULL)
		return (throw_error("init_weapon_ammo", "NULL pointer provided"));
	self->ammo = ammo;
	self->magazine = magazine;
	self->magazine_size = magazine_size;
	return (OK);
}
