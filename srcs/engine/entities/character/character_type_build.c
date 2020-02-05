/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_type_build.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 01:00:45 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/25 01:06:15 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build.h"

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