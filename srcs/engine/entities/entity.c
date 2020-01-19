/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 04:44:34 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/19 15:19:49 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entities/entities.h"
#include "utils/error.h"
#include "libft.h"
#include <time.h>

t_result	update_entity_anchor(t_entity *entity, t_vec2i anchor)
{
	if (entity == NULL)
		return (throw_error("update_entity_anchor", "NULL pointer provided"));
	entity->texture.anchor = anchor;
	return (OK);
}

t_result	update_entity_offset(t_entity *entity, t_vec2i offset)
{
	if (entity == NULL)
		return (throw_error("update_entity_offset", "NULL pointer provided"));
	entity->texture.t->offset = offset;
	return (OK);
}

t_result	build_entity_listener(t_listener *self, t_listener_args args)
{
	self->display = args.display;
	self->render_list = args.render_list;
	self->storage_list = args.storage_list;
	self->is_hoverable = args.is_hoverable;
	self->is_hover = FALSE;
	self->is_selectable = args.is_selectable;
	self->is_selected = FALSE;
	self->action_select = args.action_select;
	self->is_draggable = args.is_draggable;
	self->is_dragged = FALSE;
	self->action_drag = args.action_drag;
	return (OK);
}

t_result	build_entity_texture(t_entity_texture *self,
				t_entity_texture_args args)
{
	timespec_get(&self->last, TIME_UTC);
	self->scale = 1.0f;
	self->anchor = args.anchor;
	self->t = args.texture;
	self->t_head = args.texture;
	self->animation = args.animation;
	self->update_anchor = (t_result(*)(void*, t_vec2i))update_entity_anchor;
	self->update_offset = (t_result(*)(void*, t_vec2i))update_entity_offset;
	self->update_texture = args.update_texture;
	return (OK);
}

t_result	build_entity(t_entity *self, t_entity_args args)
{
	init_list_head(&self->node);
	if (!build_entity_texture(&self->texture, args.texture_args))
		return (throw_error("build_entity", "failed to build texture"));
	self->type = args.type;
	if (!build_entity_listener(&self->status, args.listener_args))
		return (throw_error("build_entity", "failed to build texture"));
	self->pos = args.pos;
	self->dir = args.dir;
	if (self->status.display)
		list_add_entry(&self->node, self->status.render_list);
	else
		list_add_entry(&self->node, self->status.storage_list);
	return (OK);
}
