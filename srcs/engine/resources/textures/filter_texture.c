/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 19:24:43 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/18 19:31:33 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "resources/textures/texture.h"
#include "utils/color.h"
#include "utils/error.h"

static void	set_texture_pixel_hover(t_texture old,t_texture *new, t_usize i)
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

static void	set_texture_pixel(t_texture old,t_texture *new, t_usize i)
{
	t_rgba color;

	color.px = old.pixels[i.x + i.y * new->size.x]; 
	new->pixels[i.x + i.y * new->size.x] = color.px;
}

static void	set_texture_pixel_blend(t_texture old,t_texture *new, t_usize i)
{
	t_rgba color;

	color.px = old.pixels[i.x + i.y * new->size.x]; 
	color.rgba.a = 150; 
	new->pixels[i.x + i.y * new->size.x] = color.px;
}

t_texture	*texture_filter(t_texture old, t_filter_type filter)
{
	t_texture 		*new;
	t_texture_args	args;
	t_usize			i;

	args = texture_args(old.name, old.offset, old.size, -1.0f);
	if (!(new = create_texture(args)))
		return (throw_null("hover_filter", "create_texture failed"));
	i.y = 0;
	while (i.y < new->size.y)
	{
		i.x = 0;
		while (i.x < new->size.x)
		{
			if (filter == FILTER_HOVER)
				set_texture_pixel_hover(old, new, i);
			if (filter == FILTER_BLEND)
				set_texture_pixel_blend(old, new, i);
			if (filter == FILTER_NONE)
				set_texture_pixel(old, new, i);
			i.x++;
		}
		i.y++;
	}
	return (new);
}