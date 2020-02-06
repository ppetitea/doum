/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_texture_build.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 00:43:30 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/06 20:21:53 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build.h"
#include "utils/error.h"

t_result	build_point_of_view_textures(t_list_head *images,
				t_pov_textures *pov, t_dnon_object *pov_textures_obj)
{
	t_result	result;

	if (images == NULL || pov == NULL)
		return (throw_error("build_point_of_view_textures", "NULL pointer"));
	if (pov_textures_obj != NULL)
	{
		result = build_textures_with_obj(images, &pov->first_person,
			get_child_list_object_by_key(pov_textures_obj, "first_person"));
		throw_debug("\t\t\t1st person textures", result ? "OK" : "FAIL", 0);
		result = build_textures_with_obj(images, &pov->third_person,
			get_child_list_object_by_key(pov_textures_obj, "third_person"));
		throw_debug("\t\t\t3rd person textures", result ? "OK" : "FAIL", 0);
	}
	return (OK);
}
