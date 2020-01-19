/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_button.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 04:57:16 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/19 18:28:49 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entities/ui/update_button.h"
#include "engine/entities/ui/build_button.h"
#include "engine/entities/init_entity.h"
#include "utils/error.h"
#include "libft.h"

t_button	*build_button()
{
	t_button	*self;

	if (!(self = (t_button*)malloc(sizeof(t_button))))
		return (throw_null("build_button", "malloc failed"));
	if (!build_entity(&self->super, BUTTON));
		return (throw_null("build_button", "build entity failed"));
	self->normal = NULL;
	self->hover = NULL;
	self->selected = NULL;
	return (self);
}

t_result	build_button_textures(t_button *self, t_bitmap_texture hover,
				t_bitmap_texture select, t_usize size)
{
	if (self == NULL)
		return (throw_error("build_button_textures", "NULL pointer provided"));
	if (!(self->normal = build_texture("button_normal", size)))
		return (throw_error("build_button_textures", "normal texture failed"));
	if (!(self->hover = build_texture("button_hover", size)))
		return (throw_error("build_button_textures", "hover texture failed"));
	if (!(self->selected = build_texture("button_select", size)))
		return (throw_error("build_button_textures", "select texture failed"));
	if (!fill_texture_with_bmp(self->hover, &hover))
		return (throw_error("build_button_textures", "fill texture failed"));
	if (!fill_texture_with_bmp(self->selected, &select))
		return (throw_error("build_button_textures", "fill texture failed"));
	if (!(self->normal = texture_filter(*self->hover, FILTER_HOVER)))
		return (throw_error("build_button_textures", "filter texture failed"));
	return (OK);
}
