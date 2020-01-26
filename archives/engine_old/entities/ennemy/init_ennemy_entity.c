/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ennemy_entity.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 11:25:44 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/19 18:29:15 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/error.h"
#include "engine/entities/init_player.h"
#include "engine/entities/init_entity.h"
#include "engine/entities/sprites/init_ennemy.h"

t_result	overwrite_ennemy_entity_listener(t_entity *self, t_list_head *render,
				t_list_head *storage, t_bool display)
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
		list_add_entry(&self->node, self->status.render_list);
	else
		list_add_entry(&self->node, self->status.storage_list);
	return (OK);
}

t_result	overwrite_ennemy_entity_texture(t_entity_texture *self,
				t_list_head *texture_head, t_vec2i	anchor)
{
	if (self == NULL || texture_head == NULL)
		return (throw_error("overwrite_entity_texture", "NULL pointer"));
	self->anchor = anchor;
	self->curr = (t_texture*)texture_head->next;
	self->curr_head = texture_head;
	self->prev = (t_texture*)texture_head->next;;
	self->prev_head = texture_head;
	self->animation = STOP;
	return (OK);
}
