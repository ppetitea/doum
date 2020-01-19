/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 23:55:41 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/18 18:49:39 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/resources/textures/texture.h"
#include "engine/resources/textures/bitmap.h"
#include "utils/error.h"
#include "libft.h"

static void		set_texture_pixel(t_texture *self, t_bitmap_texture *bmp,
					t_usize i, t_usize j)
{
	t_bgra	color;

	color.px = bmp->pixels[j.x + j.y * bmp->head.width];
	if (color.bgra.r == 0 && color.bgra.g >= 162 && color.bgra.b >= 232)
		color.bgra.a = 0;
	self->pixels[i.x + i.y * self->size.x] = color.px;
	// printf("r %d ", color.bgra.r);
	// printf("g %d ", color.bgra.g);
	// printf("b %d ", color.bgra.b);
	// printf("a %d \n", color.bgra.a);
}

t_result	fill_texture_with_bmp(t_texture *self, t_bitmap_texture *bmp)
{
	t_vec2f			scale;
	t_usize			i;
	t_usize			j;

	if (self == NULL || bmp == NULL || bmp->pixels == NULL)
		return (throw_error("fill_texture_with_bmp", "NULL pointer provided"));
	scale.x = (float)bmp->head.width / (float)self->size.x;
	scale.y = (float)bmp->head.height / (float)self->size.y;
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
	return (OK);
}
