/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_button.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 04:57:16 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/14 02:21:46 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/error.h"
#include "user_interface/button.h"
#include "user_interface/ui.h"
#include "textures/texture.h"

static t_result	update_button_anchor(t_ui_component *component, t_vec2i anchor)
{
	t_button	*button;

	if (component->type != BUTTON)
		return (throw_error("update_button_anchor",
			"component provided is not a button"));
	button = (t_button*)component;
	button->parent.anchor = anchor;
	return (OK);
}

static t_result	update_button_offset(t_ui_component *component, t_vec2i offset)
{
	t_button	*button;

	if (component->type != BUTTON)
		return (throw_error("update_button_offset",
			"component provided is not a button"));
	button = (t_button*)component;
	button->parent.texture->offset = offset;
	return (OK);
}

static t_result	update_button_texture_with_status(t_ui_component *component)
{
	
	t_button	*button;
	t_vec2i		curr_offset;
	
	if (component->type != BUTTON)
		return (throw_error("update_button_offset",
			"component provided is not a button"));
	curr_offset = component->texture->offset;
	button = (t_button*)component;
	if (button->parent.status.is_dragged)
		button->parent.texture = button->dragged;
	else if (button->parent.status.is_selected)
		button->parent.texture = button->selected;
	else if (button->parent.status.is_hover)
		button->parent.texture = button->hover;
	else
		button->parent.texture = button->normal;
	component->texture->offset = curr_offset;
	return (OK);
}

static	t_listener_args t_listener_ui_button_args()
{
	t_listener_args	args;

	args.is_hoverable = TRUE;
	args.is_selectable = TRUE;
	args.action_select = NULL;
	args.is_draggable = FALSE;
	args.action_drag = NULL;
	return (args);
}

static	t_ui_component_args	ui_component_button_args(t_texture *texture)
{
	t_ui_component_args	args;
	
	args.type = BUTTON;
	args.anchor = ft_vec2i(0, 0);
	args.texture = texture;
	args.update_anchor = update_button_anchor;
	args.update_offset = update_button_offset;
	args.update_texture = update_button_texture_with_status;
	args.status = listener_component(t_listener_ui_button_args());
	return (args);
}

t_button	*create_ui_button(t_texture *normal, t_texture *selected)
{
	t_button			*self;
	t_ui_component_args	args;

	if (!(self = (t_button*)malloc(sizeof(t_button))))
		return (throw_null("create_ui_button", "malloc failed"));
	self->normal = texture_filter(*normal, FILTER_HOVER);
	self->hover = normal;
	self->selected = selected;
	self->dragged = texture_filter(*selected, FILTER_HOVER);
	args = ui_component_button_args(self->normal);
	build_ui_component(&self->parent, args);
	return (self);
}
