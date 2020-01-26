/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_dup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 00:52:05 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/26 03:38:59 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entity/entity_init.h"
#include "utils/error.h"

t_result	copy_entity_status(t_listener *src, t_listener *dest)
{
	if (src == NULL || dest == NULL)
		return (throw_error("copy_entity_status", "NULL pointer provided"));
	dest->display = src->display;
	dest->is_draggable = src->is_draggable;
	dest->is_dragged = src->is_dragged;
	dest->drag_actions = src->drag_actions;
	dest->is_hover = src->is_hover;
	dest->is_hoverable = src->is_hoverable;
	dest->is_selectable = src->is_selectable;
	dest->is_selected = src->is_selected;
	dest->select_actions = src->select_actions;
	dest->render_list = src->render_list;
	dest->storage_list =src->storage_list;
	return (OK);
}

t_result	copy_entity_texture(t_entity_texture *src, t_entity_texture *dest)
{
	if (src == NULL || dest == NULL)
		return (throw_error("copy_entity_texture", "NULL pointer provided"));
	dest->animation = src->animation;
	dest->anchor = src->anchor;
	dest->animate = src->animate;
	dest->curr = src->curr;
	dest->curr_head = src->curr_head;
	dest->dragged = src->dragged;
	// duplicate texture_list;
	dest->hover = src->hover;
	dest->last = src->last;
	dest->normal = src->normal;
	dest->offset = src->offset;
	dest->prev = src->prev;
	dest->prev_head = src->prev_head;
	dest->scale = src->scale;
	dest->update_by_status = src->update_by_status;
	return (OK);
}

t_result	copy_entity(t_entity *src, t_entity *dest)
{
	if (src == NULL || dest == NULL)
		return (throw_error("copy_entity", "NULL Ppointer provided"));
	dest->name = src->name;
	copy_entity_status(&src->status, &dest->status);
	copy_entity_texture(&src->texture, &dest->texture);
	dest->destroy = src->destroy;
	return (OK);
}

t_entity	*duplicate_entity(t_entity *src)
{
	t_entity *new;

	if (src == NULL)
		return (throw_null("duplicate_entity", "NULL pointer provided"));
	if (!(new = init_new_entity(src->type)))
		return (throw_null("duplicate_entity", "init_new_entity failed"));
	if (!copy_entity(src, new))
		return (throw_null("duplicate_entity", "copy_entity failed"));
	return (new);
}
