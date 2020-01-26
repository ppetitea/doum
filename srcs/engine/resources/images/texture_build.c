/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_build.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 00:47:57 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/25 22:22:42 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build.h"

static t_bitmap_texture	*get_bmp_by_texture_obj(t_list_head *images,
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
