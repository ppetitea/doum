/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_texture_build.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 00:42:36 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/06 20:22:40 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build.h"
#include "utils/error.h"

t_result	build_character_weapon_textures(t_list_head *images,
				t_weapon *weapon, t_dnon_object *w_textures_obj)
{
	if (images == NULL || weapon == NULL || w_textures_obj == NULL)
		return (throw_error("build_character_weapon_textures", "NULL pointer"));
	if (!(weapon->fire = (t_pov_textures*)malloc(sizeof(t_pov_textures))))
		return (throw_error("build_character_weapon_textures", "malloc fail"));
	init_list_head(&weapon->fire->first_person);
	init_list_head(&weapon->fire->third_person);
	if (!(weapon->reload = (t_pov_textures*)malloc(sizeof(t_pov_textures))))
		return (throw_error("build_character_weapon_textures", "malloc fail"));
	init_list_head(&weapon->reload->first_person);
	init_list_head(&weapon->reload->third_person);
	throw_debug("\t", "fire", 0);
	build_point_of_view_textures(images, weapon->fire,
			get_child_list_object_by_key(w_textures_obj, "fire"));
	throw_debug("\t", "reload", 0);
	build_point_of_view_textures(images, weapon->reload,
			get_child_list_object_by_key(w_textures_obj, "reload"));
	return (OK);
}
