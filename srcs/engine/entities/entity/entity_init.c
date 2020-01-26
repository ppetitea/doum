/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 04:44:34 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/26 03:34:48 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entity/entity_init.h"
#include "engine/entity/entity_update.h"
#include "utils/error.h"
#include "libft.h"
#include <sys/time.h>

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
	init_list_head(&self->select_actions);
	init_list_head(&self->drag_actions);
	return (OK);
}

t_result	init_entity_texture(t_entity_texture *self)
{
	if (self == NULL)
		return (throw_error("init_entity_texture", "NULL pointer provided"));
	gettimeofday(&self->last, NULL);
	self->scale = 1.0f;
	self->offset = ft_vec2i(0, 0);
	self->anchor = ft_vec2i(0, 0);
	self->curr = NULL;
	self->curr_head = NULL;
	self->prev = NULL;
	self->prev_head = NULL;
	self->animation = NONE;
	self->animate = (void (*)(void*))animate_texture;
	self->normal = NULL;
	self->hover = NULL;
	self->dragged = NULL;
	return (OK);
}

t_result	init_entity(t_entity *self, t_entity_type type)
{
	if (self == NULL)
		return (throw_error("init_entity", "NULL pointer provided"));
	init_list_head(&self->node);
	self->type = type;
	if (!init_entity_listener(&self->status))
		return (throw_error("init_entity", "failed to init listener"));
	if (!init_entity_texture(&self->texture))
		return (throw_error("init_entity", "failed to init texture"));
	self->name = NULL;
	init_list_head(&self->childs);
	self->parent = NULL;
	self->destroy = NULL;
	return (OK);
}

t_entity	*init_new_entity(t_entity_type type)
{
	t_entity	*self;

	if (!(self = (t_entity*)malloc(sizeof(t_entity))))
		return (throw_null("init_new_entity", "malloc failed"));
	if (!init_entity(self, type))
		return (throw_null("init_new_entity", "init_entity failed"));
	return (self);
}
