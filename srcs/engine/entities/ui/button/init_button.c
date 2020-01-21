/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_button.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 04:57:16 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/21 06:20:08 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entities/ui/update_button.h"
#include "engine/entities/ui/init_button.h"
#include "engine/entities/init_entity.h"
#include "utils/error.h"
#include "libft.h"

t_button	*init_new_button()
{
	t_button	*self;

	if (!(self = (t_button*)malloc(sizeof(t_button))))
		return (throw_null("init_button", "malloc failed"));
	if (!init_entity(&self->super, BUTTON))
		return (throw_null("init_button", "init entity failed"));
	self->normal.pixels = NULL;
	self->hover.pixels = NULL;
	self->selected.pixels = NULL;
	return (self);
}

t_result	init_button_textures(t_button *self, t_bitmap_texture hover,
				t_bitmap_texture select, t_usize size)
{
	if (self == NULL)
		return (throw_error("init_button_textures", "NULL pointer provided"));
	if (!init_texture(&self->hover, size))
		return (throw_error("init_button_textures", "normal texture failed"));
	if (!init_texture(&self->selected, size))
		return (throw_error("init_button_textures", "normal texture failed"));
	if (!fill_texture_with_bmp(&self->hover, &hover))
		return (throw_error("init_button_textures", "fill texture failed"));
	if (!fill_texture_with_bmp(&self->selected, &select))
		return (throw_error("init_button_textures", "fill texture failed"));
	if (!(texture_filter(&self->normal, self->hover, FILTER_HOVER)))
		return (throw_error("init_button_textures", "filter texture failed"));
	return (OK);
}
