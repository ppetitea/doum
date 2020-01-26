/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_checkbox_entity.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 04:57:16 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/21 00:06:38 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entities/ui/update_checkbox.h"
#include "engine/entities/ui/init_checkbox.h"
#include "engine/entities/init_entity.h"
#include "engine/entities/update_entity.h"
#include "utils/error.h"
#include "libft.h"

t_result	overwrite_checkbox_entity_listener(t_entity *self,
				t_list_head *render, t_list_head *storage, t_bool display)
{
	if (self == NULL || render == NULL || storage == NULL)
		return (throw_error("init_entity_listener", "NULL pointer provided"));
	self->status.is_hoverable = TRUE;
	self->status.is_hover = FALSE;
	self->status.is_selectable = TRUE;
	self->status.is_selected = FALSE;
	self->status.is_draggable = FALSE;
	self->status.is_dragged = FALSE;
	self->status.display = display;
	self->status.render_list = render;
	self->status.storage_list = storage;
	if (display)
		list_add_entry(&self->node, self->status.render_list);
	else
		list_add_entry(&self->node, self->status.storage_list);
	return (OK);
}

t_result	overwrite_checkbox_entity_texture(t_entity_texture *self,
				t_texture *texture, t_vec2i	anchor)
{
	if (self == NULL || texture == NULL)
		return (throw_error("init_entity_texture", "NULL pointer provided"));
	self->anchor = anchor;
	self->curr = texture;
	self->animation = NONE;
	return (OK);
}

t_result	overwrite_checkbox_entity_actions(t_entity_actions *self,
				t_result (*toggle_action)(t_entity*))
{
	if (self == NULL)
		return (throw_error("init_entity_actions", "NULL pointer provided"));
	self->action_drag = NULL;
	self->action_select = (t_result (*)(void*))toggle_action;
	self->update_texture = (t_result (*)(void*))update_checkbox_texture;
	return (OK);
}
