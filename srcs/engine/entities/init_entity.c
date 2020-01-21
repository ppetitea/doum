/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_entity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 04:44:34 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/20 23:08:59 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entities/init_entity.h"
#include "engine/entities/update_entity.h"
#include "utils/error.h"
#include "libft.h"
#include <time.h>

t_result	init_entity_listener(t_listener *self)
{
	if (self == NULL)
		return (throw_error("init_entity_listener", "NULL pointer provided"));
	self->display = FALSE;
	self->render_list = NULL;
	self->storage_list = NULL;
	self->is_hoverable = FALSE;
	self->is_hover = FALSE;
	self->is_selectable = FALSE;
	self->is_selected = FALSE;
	self->is_draggable = FALSE;
	self->is_dragged = FALSE;
	return (OK);
}

t_result	init_entity_texture(t_entity_texture *self)
{
	if (self == NULL)
		return (throw_error("init_entity_texture", "NULL pointer provided"));
	timespec_get(&self->last, TIME_UTC);
	self->scale = 1.0f;
	self->anchor = ft_vec2i(0, 0);
	self->curr = NULL;
	self->curr_head = NULL;
	self->prev = NULL;
	self->prev_head = NULL;
	self->animation = NONE;
	return (OK);
}

t_result	init_entity_actions(t_entity_actions *self)
{
	if (self == NULL)
		return (throw_error("init_entity_actions", "NULL pointer provided"));
	self->action_drag = NULL;
	self->action_select = NULL;
	self->update_texture = NULL;
	return (OK);
}

t_result	init_entity(t_entity *self, t_entity_type type)
{
	if (self == NULL)
		return (throw_error("init_entity", "NULL pointer provided"));
	if (!init_entity_texture(&self->texture))
		return (throw_error("init_entity", "failed to init texture"));
	if (!init_entity_listener(&self->status))
		return (throw_error("init_entity", "failed to init listener"));
	if (!init_entity_actions(&self->trigger))
		return (throw_error("init_entity", "failed to init actions"));
	init_list_head(&self->node);
	init_list_head(&self->childs);
	self->parent = NULL;
	self->type = type;
	self->pos = ft_vec2f(0, 0);
	self->dir = ft_vec2f(0, 1);
	return (OK);
}
