/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_spawner.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 01:39:22 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/14 03:18:29 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/error.h"
#include "user_interface/spawner.h"
#include "user_interface/ui.h"
#include "textures/texture.h"

static t_result	update_spawner_anchor(t_ui_component *component, t_vec2i anchor)
{
	t_ui_spawner	*spawner;

	if (component->type != SPAWNER)
		return (throw_error("update_spawner_anchor",
			"component provided is not a spawner"));
	spawner = (t_ui_spawner*)component;
	spawner->parent.anchor = anchor;
	return (OK);
}

static t_result	update_spawner_offset(t_ui_component *component, t_vec2i offset)
{
	t_ui_spawner	*spawner;

	if (component->type != SPAWNER)
		return (throw_error("update_spawner_offset",
			"component provided is not a spawner"));
	spawner = (t_ui_spawner*)component;
	spawner->parent.texture->offset = offset;
	return (OK);
}

static t_result	update_spawner_texture_with_status(t_ui_component *component)
{
	t_ui_spawner	*spawner;
	t_vec2i		curr_offset;

	if (component->type != SPAWNER)
		return (throw_error("update_spawner_offset",
			"component provided is not a spawner"));
	curr_offset = component->texture->offset;
	spawner = (t_ui_spawner*)component;
	if (spawner->parent.status.is_dragged)
		spawner->parent.texture = spawner->dragged;
	else if (spawner->parent.status.is_hover)
		spawner->parent.texture = spawner->hover;
	else
		spawner->parent.texture = spawner->normal;
	component->texture->offset = curr_offset;
	return (OK);
}

static t_result	duplicate_ui_spawner(t_game *game, t_ui_component *component)
{
	t_ui_spawner	*self;

	if (component->type != SPAWNER)
		return (throw_error("duplicate_ui_spawner", "type isn't SPAWNER"));
	self = (t_ui_spawner*)component;
	if (self->texture_save->offset.x != self->normal->offset.x ||
		self->texture_save->offset.y != self->normal->offset.y)
		return (OK);
	if (!(self = self->create_ui_spawner(self->texture_save)))
		return (throw_error("duplicate_ui_spawner", "malloc failed"));
	list_add_entry(&self->parent.node, &game->ui_components);
	return (OK);
}

static	t_listener_args t_listener_ui_spawner_args()
{
	t_listener_args	args;

	args.is_hoverable = TRUE;
	args.is_selectable = FALSE;
	args.action_select = NULL;
	args.is_draggable = TRUE;
	args.action_drag = (t_result(*)(t_game*, void*))duplicate_ui_spawner;
	return (args);
}

static	t_ui_component_args	ui_component_spawner_args(t_texture *texture)
{
	t_ui_component_args	args;
	
	args.type = SPAWNER;
	args.anchor = ft_vec2i(0, 0);
	args.texture = texture;
	args.update_anchor = update_spawner_anchor;
	args.update_offset = update_spawner_offset;
	args.update_texture = update_spawner_texture_with_status;
	args.status = listener_component(t_listener_ui_spawner_args());
	return (args);
}

t_ui_spawner	*create_ui_spawner(t_texture *texture)
{
	t_ui_spawner		*self;
	t_ui_component_args	args;

	if (!(self = (t_ui_spawner*)malloc(sizeof(t_ui_spawner))))
		return (throw_null("create_ui_spawner", "malloc failed"));
	self->texture_save = texture;
	self->normal = texture_filter(*texture, FILTER_HOVER);
	self->hover = texture_filter(*texture, FILTER_NONE);
	self->dragged = texture_filter(*texture, FILTER_BLEND);
	self->create_ui_spawner = create_ui_spawner;
	args = ui_component_spawner_args(self->normal);
	build_ui_component(&self->parent, args);
	return (self);
}
