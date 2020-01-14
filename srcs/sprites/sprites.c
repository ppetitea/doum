/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 03:28:38 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/14 07:24:52 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sprites/sprites.h"
#include "utils/error.h"

static t_result	update_sprite_anchor(t_ui_component *component, t_vec2i anchor)
{
	t_sprite	*sprite;

	if (component->type != SPRITE)
		return (throw_error("update_sprite_anchor",
			"component provided is not a sprite"));
	sprite = (t_sprite*)component;
	sprite->parent.anchor = anchor;
	return (OK);
}

static t_result	update_sprite_offset(t_ui_component *component, t_vec2i offset)
{
	t_sprite	*sprite;

	if (component->type != SPRITE)
		return (throw_error("update_sprite_offset",
			"component provided is not a sprite"));
	sprite = (t_sprite*)component;
	sprite->parent.texture->offset = offset;
	return (OK);
}

static t_result	update_sprite_texture_with_status(t_ui_component *component)
{
	// t_sprite	*sprite;
	// t_vec2i		curr_offset;

	if (component->type != SPRITE)
		return (throw_error("update_sprite_offset",
			"component provided is not a sprite"));
	// curr_offset = component->texture->offset;
	// sprite = (t_sprite*)component;
	// component->texture->offset = curr_offset;
	return (OK);
}
static	t_listener_args t_listener_sprite_component_args()
{
	t_listener_args	args;

	args.is_hoverable = FALSE;
	args.is_selectable = FALSE;
	args.action_select = NULL;
	args.is_draggable = FALSE;
	args.action_drag = NULL;
	return (args);
}

t_component_args	component_sprite_args(t_texture *texture, t_vec2i anchor)
{
	t_component_args	args;
	
	args.type = SPRITE;
	args.anchor = anchor;
	args.texture = texture;
	args.update_anchor = update_sprite_anchor;
	args.update_offset = update_sprite_offset;
	args.update_texture = update_sprite_texture_with_status;
	args.status = listener_component(t_listener_sprite_component_args());
	return (args);
}

t_sprite_args		sprite_args(t_vec2f pos, t_vec2f dir)
{
	t_sprite_args	args;

	args.position = pos;
	args.direction = dir;
	return (args);
}

void	initialize_sprite_textures(t_sprite *self)
{
	self->textures.north = NULL;
	self->textures.north_east = NULL;
	self->textures.east = NULL;
	self->textures.south_east = NULL;
	self->textures.south = NULL;
	self->textures.south_west = NULL;
	self->textures.west = NULL;
	self->textures.north_west = NULL;
}

t_sprite			*create_sprite(t_sprite_args args)
{
	t_sprite	*self;

	if (!(self = (t_sprite*)malloc(sizeof(t_sprite))))
		return (throw_null("create_sprite", "malloc failed"));
	self->pos = args.position;
	self->dir = args.direction;
	initialize_sprite_textures(self);
	return (self);
}


