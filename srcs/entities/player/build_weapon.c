/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_weapon.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 01:16:28 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/16 07:26:01 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/error.h"
#include "entities/player.h"

t_weapon	*add_weapon(t_weapon **list, char *name, t_weapon_type type)
{
	t_weapon	*new;

	if (!(new = (t_weapon*)malloc(sizeof(t_weapon))))
		return (throw_null("build weapon", "malloc failed"));
	init_list_head(&new->node);
	new->type = type;
	new->name = name;
	new->ammo = 100;
	new->cartridge_clip_size = 10;
	new->cartridges = new->cartridge_clip_size;
	new->damages = 42;
	new->fire = NULL;
	new->reload = NULL;
	if (*list == NULL)
		*list = new;
	else
		list_add_entry(&new->node, (t_list_head*)*list);
	return (new);
}
