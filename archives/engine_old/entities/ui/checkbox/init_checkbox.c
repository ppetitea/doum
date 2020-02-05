/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_checkbox.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 04:57:16 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/20 04:00:32 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entities/ui/update_checkbox.h"
#include "engine/entities/ui/init_checkbox.h"
#include "engine/entities/init_entity.h"
#include "utils/error.h"
#include "libft.h"

t_checkbox	*init_new_checkbox()
{
	t_checkbox	*self;

	if (!(self = (t_checkbox*)malloc(sizeof(t_checkbox))))
		return (throw_null("init_checkbox", "malloc failed"));
	if (!init_entity(&self->super, CHECKBOX))
		return (throw_null("init_checkbox", "init entity failed"));
	// init_list_head(&self->linked_entities);
	self->normal.pixels = NULL;
	self->hover.pixels = NULL;
	self->checked.pixels = NULL;
	return (self);
}

t_result	init_checkbox_textures(t_checkbox *self, t_bitmap_texture hover,
				t_bitmap_texture checked, t_usize size)
{
	if (self == NULL)
		return (throw_error("init_checkbox_textures", "NULL pointer provided"));
	if (!init_texture(&self->hover, size))
		return (throw_error("init_checkbox_textures", "normal texture failed"));
	if (!init_texture(&self->checked, size))
		return (throw_error("init_checkbox_textures", "normal texture failed"));
	if (!fill_texture_with_bmp(&self->hover, &hover))
		return (throw_error("init_checkbox_textures", "fill texture failed"));
	if (!fill_texture_with_bmp(&self->checked, &checked))
		return (throw_error("init_checkbox_textures", "fill texture failed"));
	if (!(texture_filter(&self->normal, self->hover, FILTER_HOVER)))
		return (throw_error("init_checkbox_textures", "filter texture failed"));
	return (OK);
}

t_result	overwrite_checkbox_textures_offset(t_checkbox *self, t_vec2i offset)
{
	if (self == NULL)
		return (throw_error("overwrite_checkbox_offset", "NULL pointer"));
	self->normal.offset = offset;
	self->hover.offset = offset;
	self->checked.offset = offset;
	return (OK);
}
