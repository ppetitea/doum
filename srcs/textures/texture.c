/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 23:55:41 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/14 01:37:02 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textures/texture.h"
#include "utils/error.h"
#include "libft.h"

t_texture_args	texture_args(char *name, t_vec2i offset, t_usize size)
{
	t_texture_args	ret;

	ret.name = name;
	ret.offset = offset;
	ret.size = size;
	return (ret);
}

t_texture		*create_texture(t_texture_args args)
{
	t_texture *self;

	if (!(self = (t_texture*)malloc(sizeof(t_texture))))
		return (throw_null("create_texture", "texture -> malloc failed"));
	if (!(self->pixels = (u_int32_t*)malloc(sizeof(u_int32_t)
		* args.size.x * args.size.y)))
		return (throw_null("create_texture", "pixels array -> malloc failed"));
	self->name = ft_strdup(args.name);
	self->offset = args.offset;
	self->size = args.size;
	return (self);
}

static void		set_texture_pixel(t_texture *self, t_bitmap_texture bmp,
	t_usize i, t_usize j)
{
	t_rgba	color;

	color.px = bmp.pixels[j.x + j.y * bmp.head.width];
	// if (color.rgba.r >= 254 && color.rgba.g >= 254 && color.rgba.b >= 254)
		// color.rgba.a = 0;
	self->pixels[i.x + i.y * self->size.x] = color.px;
}

t_texture		*create_texture_with_bmp(t_texture_args args,
	t_bitmap_texture bmp)
{
	t_texture		*self;
	t_usize			i;
	t_usize			j;
	t_vec2f			scale;

	if (!(self = create_texture(args)))
		return (throw_null("create_texture_with_bmp", "create_texture failed"));
	scale.x = (float)bmp.head.width / (float)self->size.x;
	scale.y = (float)bmp.head.height / (float)self->size.y;
	i.y = 0;
	while (i.y < self->size.y)
	{
		i.x = 0;
		while (i.x < self->size.x)
		{
			j = ft_usize(i.x * scale.x, i.y * scale.y);
			set_texture_pixel(self, bmp, i, j);
			i.x++;
		}
		i.y++;
	}
	return (self);
}

