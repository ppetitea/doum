/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_weapon.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 01:16:28 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/19 01:17:45 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/error.h"
#include "engine/entities/build_player.h"

t_weapon	*build_weapon(char *name, t_weapon_type type)
{
	t_weapon	*new;

	if (name == NULL)
		return (throw_null("build_weapon", "NULL pointer provided"));
	if (!(new = (t_weapon*)malloc(sizeof(t_weapon))))
		return (throw_null("build weapon", "malloc failed"));
	init_list_head(&new->node);
	init_list_head(&new->fire);
	init_list_head(&new->reload);
	new->type = type;
	new->name = ft_strdup(name);
	new->ammo = 100;
	new->magazine_size = 10;
	new->magazine = new->magazine_size;
	new->damages = 42;
	return (new);
}
