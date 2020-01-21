/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pixel_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 19:30:45 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/20 20:33:58 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/resources/textures/texture.h"
#include "utils/color.h"
#include "utils/error.h"

void	set_texture_pixel_circular_shadow(t_texture old,
				t_texture *new, t_usize i)
{
	t_usize	center;
	float	dist_px;
	float	dist_max;
	float	dist_pourcent;
	t_rgba	color;

	center = ft_usize(new->size.x * 0.5f, new->size.y * 0.5f);
	dist_max = (new->size.x * 0.5) * (new->size.x * 0.5)
				+ (new->size.y * 0.5) * (new->size.y * 0.5);
	dist_px = (i.x - center.x) * (i.x - center.x)
		+ (i.y - center.y) * (i.y - center.y);
	dist_pourcent = dist_px / dist_max;
	color.px = old.pixels[i.x + i.y * new->size.x]; 
	color.rgba.r *= 1 - dist_pourcent;
	color.rgba.g *= 1 - dist_pourcent;
	color.rgba.b *= 1 - dist_pourcent;
	new->pixels[i.x + i.y * new->size.x] = color.px;
}

void	set_texture_pixel(t_texture old,t_texture *new, t_usize i)
{
	t_bgra color;

	color.px = old.pixels[i.x + i.y * new->size.x];
	new->pixels[i.x + i.y * new->size.x] = color.px;
}

void	set_texture_pixel_blend(t_texture old,t_texture *new, t_usize i)
{
	t_rgba color;

	color.px = old.pixels[i.x + i.y * new->size.x]; 
	color.rgba.a = 150; 
	new->pixels[i.x + i.y * new->size.x] = color.px;
}
