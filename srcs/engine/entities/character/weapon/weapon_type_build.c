/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_type_build.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 00:59:17 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/06 20:22:43 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build.h"
#include "utils/error.h"

t_result	build_weapon_type_with_obj(t_weapon *weapon,
				t_dnon_object *weapon_obj)
{
	if (weapon == NULL || weapon_obj == NULL)
		return (throw_error("build_weapon_type_with_obj", "NULL pointer"));
	if (strcmp_obj("type", "gun", weapon_obj))
		weapon->type = GUN;
	else if (strcmp_obj("type", "melee", weapon_obj))
		weapon->type = MELEE;
	else if (strcmp_obj("type", "hand", weapon_obj))
		weapon->type = HAND;
	else
	{
		weapon->type = HAND;
		throw_error("buid_weapon_type_with_obj", "unknow type detected");
	}
	return (OK);
}