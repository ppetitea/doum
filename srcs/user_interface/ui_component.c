/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_component.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 04:44:34 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/13 05:15:45 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "user_interface/ui.h"
#include "libft.h"

t_listener_component	listener_component(t_bool is_hoverable,
	t_bool is_selectable, t_bool is_draggable, t_bool is_checkable)
{
	t_listener_component	ret;

	ret.is_hoverable = is_hoverable;
	ret.is_hover = FALSE;
	ret.is_selectable = is_selectable;
	ret.is_select = FALSE;
	ret.is_draggable = is_draggable;
	ret.is_dragged = FALSE;
	ret.is_checkable = is_checkable;
	ret.is_checked = FALSE;
	return (ret);
}

t_result	build_ui_component(t_ui_component *self, t_ui_component_args args)
{
	init_list_head(&self->node);
	self->anchor = args.anchor;
	self->texture = args.texture;
	self->status = args.status;
	self->type = args.type;
	self->update_texture = args.update_texture;
	self->update_anchor = args.update_anchor;
	return (OK);
}
