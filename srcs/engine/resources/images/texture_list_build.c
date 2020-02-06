/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_list_build.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 00:50:37 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/06 20:19:49 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build.h"
#include "utils/error.h"

t_result	build_textures_with_obj(t_list_head *images, t_list_head *list,
				t_dnon_object *textures_obj)
{
	t_list_head		*pos;
	t_list_head		*next;
	t_dnon_object	*texture_obj;
	t_texture		*texture;

	if (images == NULL || list == NULL)
		return (throw_error("build_textures", "NULL pointer provided"));
	if (textures_obj == NULL)
		return (ERROR);
	pos = (t_list_head*)textures_obj->value;
	next = pos->next;
	while ((pos = next) != (t_list_head*)textures_obj->value)
	{
		next = next->next;
		texture_obj = (t_dnon_object*)pos;
		if (texture_obj->type != LIST)
			return (throw_error("build_textures", "texture_obj isn't LIST"));
		if (!(texture = build_texture_with_obj(images, list, texture_obj)))
			return (throw_error("build_textures", "build_texture failed"));
		else
			list_add_entry(&texture->node, list);
	}
	return (OK);
}