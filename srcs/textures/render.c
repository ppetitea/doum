/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 01:19:09 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/13 21:21:51 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "textures/texture.h"
#include "textures/bitmap.h"
#include "screen/screen.h"
#include "utils/color.h"

void	set_texture_pixel(t_texture texture, t_screen screen, t_vec2i offset,
	t_usize i)
{
	t_rgba old;
	t_rgba curr;
	t_rgba new;

	old.px = screen.pixels[(offset.x + i.x) + (offset.y + i.y) * screen.size.x];
	curr.px = texture.pixels[i.x + i.y * texture.size.x];
	new.px = blend_add(curr, old);
	screen.pixels[(offset.x + i.x) + (offset.y + i.y) * screen.size.x] = new.px;
}

void	render_texture(t_screen screen, t_texture *texture, t_vec2i anchor)
{
	t_usize		start;
	t_usize		i;
	t_vec2i		offset;

	offset = ft_vec2i(texture->offset.x + anchor.x, texture->offset.y + anchor.y);
	start.x = (offset.x >= 0) ? 0 : -offset.x;
	start.y = (offset.y >= 0) ? 0 : -offset.y;
	i.y = start.y;
	while (offset.y + i.y < screen.size.y && i.y < (size_t)texture->size.y)
	{
		i.x = start.x;
		while (offset.x + i.x < screen.size.x && i.x < (size_t)texture->size.x)
		{
			// if (((t_rgba)texture->pixels[i.x + i.y * texture->size.x]).rgba.a)
			set_texture_pixel(*texture, screen, offset, i);
			i.x++;
		}
		i.y++;
	}
}
