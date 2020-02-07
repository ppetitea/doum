/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugibone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 17:01:39 by lugibone          #+#    #+#             */
/*   Updated: 2020/02/07 17:23:09 by lugibone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/color.h"

void	putpixel(t_texture *texture, int x, int y, uint32_t color)
{
	if (y < 0 + texture->offset.y || y > texture->size.y + texture->offset.y)
		return (0);
	if (x < 0 + texture->offset.x || x > texture->size.x + texture->offset.x)
		return (0);
	texture->pixels[y * WIDTH + x] = color;
}

void	brush_square(t_texture *texture, int x, int y, int size, uint32_t color)
{
	int i;
	int j;

	i = -1 - size / 2;
	j = -1 - size / 2;
	while (++i < size / 2)
	{
		while(++j < size / 2)
		{
			putpixel(texture, x + j, y + i, color);
		}
		j = -1 - size / 2;
	}
}

void	brush_reduce(t_texture *texture, int x, int y, int size, int value)
{
	int i;
	int j;
	t_bgra color;

	x += texture.offset.x;
	y += texture.offset.y;
	i = -1 - size / 2;
	j = -1 - size / 2;
	while (++i < size / 2)
	{
		while(++j < size / 2)
		{
			color.px = (texture->pixels[(y + i) * (x + j)])
			color.bgra.r -= color.bgra.r - value < 0 ? 0 : value;
			color.bgra.g -= color.bgra.g - value < 0 ? 0 : value;
			color.bgra.b -= color.bgra.b - value < 0 ? 0 : value;
			putpixel(texture, x + j, y + i, color.px);
		}
		j = -1 - size / 2;
	}
}
