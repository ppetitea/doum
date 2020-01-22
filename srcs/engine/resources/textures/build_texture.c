/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 22:54:41 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/22 04:35:33 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/resources/textures/texture.h"
#include "engine/resources/resources.h"
#include "utils/parser.h"
#include "utils/error.h"
#include "build.h"

t_bitmap_texture	*get_bmp_by_texture_obj(t_list_head *images,
						t_dnon_object *texture_obj)
{
	t_bitmap_texture	*bmp;
	char				*key;
	
	if (images == NULL || texture_obj == NULL)
		return (throw_null("get_bmp_by_texture_obj", "NULL pointer provided"));
	if (!(key = get_string_value_by_key(texture_obj, "key", NULL)))
		return (throw_null("get_bmp_by_texture_obj", "get_string_value fail"));
	if (!(bmp = get_image_by_name(images, key)))
		return (throw_null("get_bmp_by_texture_obj", key));
	free(key);
	return (bmp);
}

t_texture	*build_texture_with_obj(t_list_head *images, t_list_head *list,
				t_dnon_object *texture_obj)
{
	t_bitmap_texture	*bmp;
	t_texture			*new;
	t_usize				size;

	if (images == NULL || list == NULL || texture_obj == NULL)
		return (throw_null("build_texture", "NULL pointer provided"));
	if (!(bmp = get_bmp_by_texture_obj(images, texture_obj)))
		return (throw_null("build_texture", "get_bmp_by_obj failed"));
	if (!(init_usize_with_obj(&size, 
			get_child_list_object_by_key(texture_obj, "size"))))
		return (throw_null("build_texture", "init_usize_with_obj failed"));
	if (!(new = init_new_texture(size)))
		return (throw_null("build_texture", "new_texture failed"));
	if (!fill_texture_with_bmp(new, bmp))
		return (throw_null("build_texture", "fill texture failed"));
	if (!(init_vec2i_with_obj(&new->offset,
			get_child_list_object_by_key(texture_obj, "offset"))))
		return (throw_null("build_texture", "init_vec2i_with_obj failed"));
	new->delay_ms = get_int_value_by_key(texture_obj, "delay_ms", 50);
	return (new);
}

t_result	build_textures_with_obj(t_list_head *images, t_list_head *list,
				t_dnon_object *textures_obj)
{
	t_list_head		*pos;
	t_list_head		*next;
	t_dnon_object	*texture_obj;
	t_texture		*texture;

	if (images == NULL || list == NULL || textures_obj == NULL)
		return (throw_error("build_textures", "NULL pointer provided"));
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

t_result	build_oriented_textures(t_list_head *images,
				t_oriented_textures *textures, t_dnon_object *o_textures_obj)
{
	if (images == NULL || textures == NULL || o_textures_obj == NULL)
		return (throw_error("build_ennemy_textures", "NULL pointer provided"));
	if (!build_textures_with_obj(images, &textures->front,
		get_child_list_object_by_key(o_textures_obj, "front")))
		return (throw_error("build_ennemy_textures", "front texture failed"));
	if (!build_textures_with_obj(images, &textures->front_l,
		get_child_list_object_by_key(o_textures_obj, "front_l")))
		return (throw_error("build_ennemy_textures", "front_l texture failed"));
	if (!build_textures_with_obj(images, &textures->front_r,
		get_child_list_object_by_key(o_textures_obj, "front_r")))
		return (throw_error("build_ennemy_textures", "front_r texture failed"));
	if (!build_textures_with_obj(images, &textures->left,
		get_child_list_object_by_key(o_textures_obj, "left")))
		return (throw_error("build_ennemy_textures", "left texture failed"));
	if (!build_textures_with_obj(images, &textures->right,
		get_child_list_object_by_key(o_textures_obj, "right")))
		return (throw_error("build_ennemy_textures", "right texture failed"));
	if (!build_textures_with_obj(images, &textures->back,
		get_child_list_object_by_key(o_textures_obj, "back")))
		return (throw_error("build_ennemy_textures", "back texture failed"));
	if (!build_textures_with_obj(images, &textures->back_l,
		get_child_list_object_by_key(o_textures_obj, "back_l")))
		return (throw_error("build_ennemy_textures", "back_l texture failed"));
	if (!build_textures_with_obj(images, &textures->back_r,
		get_child_list_object_by_key(o_textures_obj, "back_r")))
		return (throw_error("build_ennemy_textures", "back_r texture failed"));
	return (OK);
}
