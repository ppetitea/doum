/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 04:57:16 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/15 04:28:39 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/error.h"
#include "entities/ui/button.h"
#include "entities/entities.h"
#include "resources/textures/texture.h"

static	t_listener_args entity_button_listener_args(t_bool display)
{
	t_listener_args	args;

	args.display = display;
	args.is_hoverable = TRUE;
	args.is_selectable = TRUE;
	args.action_select = NULL;
	args.is_draggable = FALSE;
	args.action_drag = NULL;
	return (args);
}

static	t_entity_texture_args	entity_button_texture_args(
	t_texture *texture, t_animation_status animation)
{
	t_entity_texture_args	args;
	
	args.anchor = ft_vec2i(0, 0);
	args.texture = texture;
	args.animation = animation;
	args.update_anchor = (t_result(*)(void*, t_vec2i))update_button_anchor;
	args.update_offset = (t_result(*)(void*, t_vec2i))update_button_offset;
	args.update_texture = (t_result(*)(void*))update_button_texture_with_status;
	return (args);
}

static	t_entity_args	entity_button_args(t_texture *texture,
			t_animation_status animation, t_bool display)
{
	t_entity_args	args;

	args.texture_args = entity_button_texture_args(texture, animation);
	args.listener_args = entity_button_listener_args(display);
	args.type = BUTTON;
	args.pos = ft_vec2f(0, 0);
	args.dir = ft_vec2f(0, 0);
	return (args);
}

t_button	*create_button(t_texture *hover, t_texture *selected,
				t_bool display)
{
	t_button		*self;
	t_entity_args	entity_args;

	if (!(self = (t_button*)malloc(sizeof(t_button))))
		return (throw_null("create_button", "malloc failed"));
	if (!(self->normal = texture_filter(*hover, FILTER_HOVER)))
		return (throw_null("create_button", "filter failed"));
	self->hover = hover;
	self->selected = selected;
	entity_args = entity_button_args(self->normal, NONE, display);
	build_entity(&self->super, entity_args);
	return (self);
}
