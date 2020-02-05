/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 01:19:09 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/04 22:56:19 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/resource/image/texture_init.h"
#include "engine/interface/screen_init.h"
#include "utils/color.h"
#include "libft.h"

#include <stdio.h>

static void	set_screen_pixel(t_texture texture, t_screen *screen, t_vec2i offset,
	t_usize i)
{
	t_rgba old;
	t_rgba curr;
	t_rgba new;

	old.px = screen->pixels[(offset.x + i.x) + (offset.y + i.y) * screen->size.x];
	curr.px = texture.pixels[i.x + i.y * texture.size.x];
	new.px = blend_add(curr, old);
	screen->pixels[(offset.x + i.x) + (offset.y + i.y) * screen->size.x] = new.px;
	// printf("r %d ", new.rgba.r);
	// printf("g %d ", new.rgba.g);
	// printf("b %d ", new.rgba.b);
	// printf("a %d\n", new.rgba.a);
}

void	render_texture(t_screen *screen, t_texture *texture, t_vec2i anchor)
{
	t_usize		start;
	t_usize		i;
	t_vec2i		offset;

	offset = ft_vec2i(texture->offset.x + anchor.x, texture->offset.y + anchor.y);
	start.x = (offset.x >= 0) ? 0 : -offset.x;
	start.y = (offset.y >= 0) ? 0 : -offset.y;
	i.y = start.y;
	while (offset.y + i.y < screen->size.y && i.y < (size_t)texture->size.y)
	{
		i.x = start.x;
		while (offset.x + i.x < screen->size.x && i.x < (size_t)texture->size.x)
		{
			// if (((t_rgba)texture->pixels[i.x + i.y * texture->size.x]).rgba.a)
			set_screen_pixel(*texture, screen, offset, i);
			i.x++;
		}
		i.y++;
	}
}

void	set_pixel(t_screen *screen, t_usize i, t_texture texture, t_usize j)
{
	t_rgba old;
	t_rgba curr;
	t_rgba new;

	old.px = screen->pixels[i.x + i.y * screen->size.x];
	curr.px = texture.pixels[j.x + j.y * texture.size.x];
	new.px = blend_add(curr, old);
	screen->pixels[i.x + i.y * screen->size.x] = new.px;
}

void	render_texture_with_scale_2d(t_screen *screen, t_texture *texture,
			t_vec2i anchor, t_vec2f scale)
{
	t_usize		start;
	t_vec2i		offset;
	t_usize		size;
	t_usize		i;

	size = ft_usize(texture->size.x * scale.x, texture->size.y * scale.y);
	offset = ft_vec2i(texture->offset.x * scale.x, texture->offset.y * scale.y);
	offset = ft_vec2i(offset.x + anchor.x, offset.y + anchor.y);
	start.x = (offset.x >= 0) ? 0 : -offset.x;
	start.y = (offset.y >= 0) ? 0 : -offset.y;
	i.y = start.y;
	while (offset.y + i.y < screen->size.y && i.y < size.y)
	{
		i.x = start.x;
		while (offset.x + i.x < screen->size.x && i.x < size.x)
		{
			set_pixel(screen, ft_usize(offset.x + i.x, offset.y + i.y), 
					*texture, ft_usize(i.x / scale.x, i.y / scale.y));
			i.x++;
		}
		i.y++;
	}
}

void	render_texture_with_scale(t_screen *screen, t_texture *texture,
			t_vec2i anchor, float scale)
{
	t_usize		start;
	t_vec2i		offset;
	t_usize		size;
	t_usize		i;

	size = ft_usize(texture->size.x * scale, texture->size.y * scale);
	offset = ft_vec2i(texture->offset.x * scale, texture->offset.y * scale);
	offset = ft_vec2i(offset.x + anchor.x, offset.y + anchor.y);
	start.x = (offset.x >= 0) ? 0 : -offset.x;
	start.y = (offset.y >= 0) ? 0 : -offset.y;
	i.y = start.y;
	while (offset.y + i.y < screen->size.y && i.y < size.y)
	{
		i.x = start.x;
		while (offset.x + i.x < screen->size.x && i.x < size.x)
		{
			set_pixel(screen, ft_usize(offset.x + i.x, offset.y + i.y), 
					*texture, ft_usize(i.x / scale, i.y / scale));
			i.x++;
		}
		i.y++;
	}
}
