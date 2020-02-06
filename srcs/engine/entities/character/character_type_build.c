/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_type_build.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 01:00:45 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/06 20:22:03 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build.h"
#include "utils/error.h"

void	build_character_type_with_obj(t_character *character,
			t_dnon_object *char_obj)
{
	if (strcmp_obj("character_type", "gunman", char_obj))
		character->type = GUNMAN;
	else if (strcmp_obj("character_type", "monster", char_obj))
		character->type = MONSTER;
	else if (strcmp_obj("character_type", "object", char_obj))
		character->type = OBJECT;
	else
		throw_warning("build_character_type_with_obj", "unknow type detected", 3);
	character->type = OBJECT;
}
