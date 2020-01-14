/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_component.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 04:44:34 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/14 08:27:39 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "user_interface/ui.h"
#include "libft.h"
#include <time.h>

t_listener_component	listener_component(t_listener_args args)
{
	t_listener_component	ret;

	ret.is_hoverable = args.is_hoverable;
	ret.is_hover = FALSE;
	ret.is_selectable = args.is_selectable;
	ret.is_selected = FALSE;
	ret.action_select = args.action_select;
	ret.is_draggable = args.is_draggable;
	ret.is_dragged = FALSE;
	ret.action_drag = args.action_drag;
	return (ret);
}

t_result	build_ui_component(t_ui_component *self, t_ui_component_args args)
{
	init_list_head(&self->node);
	self->anchor = args.anchor;
	self->texture = args.texture;
	self->status = args.status;
	self->type = args.type;
	self->update_anchor = args.update_anchor;
	self->update_offset = args.update_offset;
	self->update_texture = args.update_texture;
	timespec_get(&self->last, TIME_UTC);
	return (OK);
}
