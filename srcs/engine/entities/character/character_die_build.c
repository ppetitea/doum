/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_die_build.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 00:35:18 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/06 20:21:41 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build.h"
#include "utils/error.h"

t_result	build_character_die_with_obj(t_game_resources *resources,
				t_character *character, t_dnon_object *die_obj)
{
	if (resources == NULL || character == NULL)
		return (throw_error("build_character_die_with_obj", "NULL pointer"));
	throw_debug("die resources:", "", 0);
	if (die_obj == NULL)
		throw_warning("resources:\t", "FAIL", 3);
	else
		build_point_of_view_textures(
			&resources->images,
			character->die_texture,
			get_child_list_object_by_key(die_obj, "textures"));
	return (OK);
}
