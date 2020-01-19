/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_spawner_entity.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 04:57:16 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/18 22:55:00 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entities/ui/update_spawner.h"
#include "engine/entities/ui/build_spawner.h"
#include "engine/entities/build_entity.h"
#include "utils/error.h"
#include "libft.h"

t_result	build_spawner_entity_listener(t_entity *self, t_list_head *render,
				t_list_head *storage, t_bool display)
{
	if (self == NULL || render == NULL || storage == NULL)
		return (throw_error("build_entity_listener", "NULL pointer provided"));
	self->status.is_hoverable = TRUE;
	self->status.is_hover = FALSE;
	self->status.is_selectable = FALSE;
	self->status.is_selected = FALSE;
	self->status.is_draggable = TRUE;
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

t_result	build_spawner_entity_texture(t_entity_texture *self,
				t_texture *texture, t_vec2i	anchor)
{
	if (self == NULL || texture == NULL)
		return (throw_error("build_entity_texture", "NULL pointer provided"));
	self->anchor = anchor;
	self->curr = texture;
	self->curr_head = texture;
	self->prev = texture;
	self->animation = NONE;
	return (OK);
}

t_result	build_spawner_entity_actions(t_entity_actions *self)
{
	if (self == NULL)
		return (throw_error("build_entity_actions", "NULL pointer provided"));
	self->action_drag = duplicate_spawner;
	self->action_select = NULL;
	self->update_texture = update_spawner_texture;
	return (OK);
}