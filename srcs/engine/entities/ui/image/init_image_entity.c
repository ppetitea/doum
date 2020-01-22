/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image_entity.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 04:57:16 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/20 20:49:08 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entities/ui/init_image.h"
#include "engine/entities/init_entity.h"
#include "utils/error.h"
#include "libft.h"

t_result	overwrite_image_entity_listener(t_entity *self,
				t_list_head *render, t_list_head *storage, t_bool display)
{
	if (self == NULL || render == NULL || storage == NULL)
		return (throw_error("init_entity_listener", "NULL pointer provided"));
	self->status.is_hoverable = FALSE;
	self->status.is_hover = FALSE;
	self->status.is_selectable = FALSE;
	self->status.is_selected = FALSE;
	self->status.is_draggable = FALSE;
	self->status.is_dragged = FALSE;
	self->status.display = display;
	self->status.render_list = render;
	self->status.storage_list = storage;
	if (display)
		list_add_first(&self->node, self->status.render_list);
	else
		list_add_first(&self->node, self->status.storage_list);
	return (OK);
}

t_result	overwrite_image_entity_texture(t_entity_texture *self,
				t_texture *texture, t_vec2i	anchor)
{
	if (self == NULL || texture == NULL)
		return (throw_error("init_entity_texture", "NULL pointer provided"));
	self->anchor = anchor;
	self->curr = texture;
	self->animation = NONE;
	return (OK);
}