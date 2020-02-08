/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 01:19:09 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/08 05:29:40 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/resource/image/texture_init.h"
#include "engine/interface/screen_init.h"
#include "utils/color.h"
#include "libft.h"

#include <stdio.h>

void	update_texture_box_with_screen(t_screen *screen, t_texture_box *box,
			t_texture *texture)
{
	if (box->scale.x <= 0)
		box->scale.x = 1;
	if (box->scale.y <= 0)
		box->scale.y = 1;
	box->offset.x = (int)(texture->offset.x / box->scale.x) + box->anchor.x;
	box->offset.y = (int)(texture->offset.y / box->scale.y) + box->anchor.y;
	box->start.x = (box->offset.x < 0) ? -box->offset.x : 0;
	box->start.y = (box->offset.y < 0) ? -box->offset.y : 0;
	box->size.x = (int)((float)texture->size.x / box->scale.x);
	box->size.y = (int)((float)texture->size.y / box->scale.y);
	box->end = vec2i_add(box->offset, box->size);
	if (box->end.x > (int)screen->size.x)
		box->end.x = (int)screen->size.x;
	if (box->end.y > (int)screen->size.y)
		box->end.y = (int)screen->size.y;
}

void	update_entity_texture_box_with_size(t_screen *screen,
			t_texture_box *box, t_texture *texture, t_usize	size)
{
	box->scale.x = (float)texture->size.x / (float)size.x;
	box->scale.y = (float)texture->size.y / (float)size.y;
	update_texture_box_with_screen(screen, box, texture);
}


static void	fill_screen_pixel_with_texture(t_screen *screen, t_texture *texture,
			t_texture_box *box, t_vec2i i)
{
	t_rgba old;
	t_rgba curr;
	t_rgba new;

	old.px = screen->pixels[box->offset.x + i.x
		+ (i.y + box->offset.y) * screen->size.x];
	curr.px = texture->pixels[(int)(i.x * box->scale.x)
		+ (int)(i.y * box->scale.y) * texture->size.x];
	if (curr.rgba.a == 0)
		new.px = old.px;
	else
		new.px = blend_add(curr, old);
	screen->pixels[box->offset.x + i.x
		+ (i.y + box->offset.y) * screen->size.x] = new.px;
}

void	render_texture_with_box(t_screen *screen, t_texture *texture,
			t_texture_box *box)
{
	t_vec2i		i;

	i.y = box->start.y;
	while (box->offset.y + i.y < box->end.y)
	{
		i.x = box->start.x;
		while (box->offset.x + i.x < box->end.x)
		{
			fill_screen_pixel_with_texture(screen, texture, box, i);
			++i.x;
		}
		++i.y;
	}
}

