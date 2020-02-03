/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 23:55:41 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/03 00:59:44 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/resource/image/texture_filter.h"
#include "engine/resource/image/texture_init.h"
#include "utils/error.h"
#include "libft.h"

static void		fill_texture_pixel(t_texture *self, t_bitmap_texture *bmp,
					t_usize i, t_usize j)
{
	t_bgra	color;

	color.px = bmp->pixels[j.x + j.y * bmp->head.width];
	// if (color.bgra.r == 0 && color.bgra.g >= 162 && color.bgra.b >= 232)
	// 	color.bgra.a = 0;
	self->pixels[i.x + i.y * self->size.x] = color.px;
	// printf("r %d ", color.bgra.r);
	// printf("g %d ", color.bgra.g);
	// printf("b %d ", color.bgra.b);
	// printf("a %d \n", color.bgra.a);
}

static void		fill_texture_pixel_with_blend(t_texture *self,
					t_bitmap_texture *bmp, t_usize i, t_usize j)
{
	t_bgra	color;

	color.px = bmp->pixels[j.x + j.y * bmp->head.width];
	color.bgra.a = 150;
	self->pixels[i.x + i.y * self->size.x] = color.px;
}

static void	fill_texture_pixel_with_circular_shadow(t_texture *self,
				t_bitmap_texture *bmp, t_usize i, t_usize j)
{
	t_usize	center;
	float	dist_px;
	float	dist_max;
	float	dist_pourcent;
	t_bgra	color;

	center = ft_usize(self->size.x * 0.5f, self->size.y * 0.5f);
	dist_max = (self->size.x * 0.5) * (self->size.x * 0.5)
				+ (self->size.y * 0.5) * (self->size.y * 0.5);
	dist_px = (i.x - center.x) * (i.x - center.x)
		+ (i.y - center.y) * (i.y - center.y);
	dist_pourcent = dist_px / dist_max;
	color.px = bmp->pixels[j.x + j.y * bmp->head.width];
	color.bgra.r *= 1 - dist_pourcent;
	color.bgra.g *= 1 - dist_pourcent;
	color.bgra.b *= 1 - dist_pourcent;
	self->pixels[i.x + i.y * self->size.x] = color.px;
}

static void	fill_texture_pixel_with_circular_blend(t_texture *self,
				t_bitmap_texture *bmp, t_usize i, t_usize j)
{
	t_usize	center;
	float	dist_px;
	float	dist_max;
	float	dist_pourcent;
	t_bgra	color;

	center = ft_usize(self->size.x * 0.5f, self->size.y * 0.5f);
	dist_max = (self->size.x * 0.5) * (self->size.x * 0.5)
				+ (self->size.y * 0.5) * (self->size.y * 0.5);
	dist_px = (i.x - center.x) * (i.x - center.x)
		+ (i.y - center.y) * (i.y - center.y);
	dist_pourcent = dist_px / dist_max;
	color.px = bmp->pixels[j.x + j.y * bmp->head.width];
	color.bgra.a *= 1 - dist_pourcent;
	self->pixels[i.x + i.y * self->size.x] = color.px;
}

t_result	fill_texture_with_bmp(t_texture *self, t_bitmap_texture *bmp,
				t_filter_type filter)
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
			if (filter == FILTER_CIRCULAR_SHADOW)
				fill_texture_pixel_with_circular_shadow(self, bmp, i, j);
			else if (filter == FILTER_CIRCULAR_BLEND)
				fill_texture_pixel_with_circular_blend(self, bmp, i, j);
			else if (filter == FILTER_BLEND)
				fill_texture_pixel_with_blend(self, bmp, i, j);
			else
				fill_texture_pixel(self, bmp, i, j);
			i.x++;
		}
		i.y++;
	}
	return (OK);
}
