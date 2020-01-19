/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 23:55:41 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/19 01:48:57 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/resources/textures/texture.h"
#include "engine/resources/resources.h"
#include "utils/error.h"
#include "libft.h"

t_texture		*build_texture(char *name, t_usize size)
{
	t_texture *self;

	if (name == NULL)
		return (throw_null("create_texture", "NULL pointer provided"));
	if (!(self = (t_texture*)malloc(sizeof(t_texture))))
		return (throw_null("create_texture", "texture -> malloc failed"));
	if (!(self->pixels = (uint32_t*)malloc(sizeof(uint32_t)
		* size.x * size.y)))
		return (throw_null("create_texture", "pixels array -> malloc failed"));
	self->name = NULL;
	if (!(self->name = ft_strdup(name)))
		return (throw_null("create_texture", "ft_strdup failed"));
	init_list_head(&self->node);
	self->offset = ft_vec2i(0, 0);
	self->size = size;
	self->delay_ms = 100;
	return (self);
}

t_texture		*build_texture_with_args(char *name, t_texture_args args)
{
	t_texture *self;

	if (!(self = build_texture(name, args.size)))
		return (throw_null("build_texture_with_args", "build failed"));
	self->delay_ms = args.delay_ms;
	self->offset = args.offset;
	return (self);
}

t_result	add_texture(t_list_head *textures, t_list_head *bmp_src,
				char *name, t_texture_args args)
{
	t_image_node		*img;
	t_list_head			*pos;
	t_list_head			*next;
	t_texture			*texture;

	if (textures == NULL || bmp_src == NULL || name == NULL)
		return (throw_error("add_texture", "NULL pointer provided"));
	pos = bmp_src;
	next = pos->next;
	while ((pos = next) != bmp_src)
	{
		next = next->next;
		img = (t_image_node*)pos;
		if (!ft_strcmp(img->name, name))
		{
			if (!(texture = build_texture_with_args(name, args)))
				return (throw_error("add_texture", "build_texture failed"));
			if (!fill_texture_with_bmp(texture, img->image))
				return (throw_error("add_texture", "fill_texture failed"));
			return (OK);
		}
	}
	return (throw_error("add_texture", "error 404 not found"));
}
