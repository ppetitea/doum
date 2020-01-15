/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 03:28:38 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/15 05:46:26 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "entities/sprites/sprites.h"
#include "utils/error.h"

static	t_listener_args entity_sprite_listener_args(t_bool display)
{
	t_listener_args	args;

	args.display = display;
	args.is_hoverable = FALSE;
	args.is_selectable = FALSE;
	args.action_select = NULL;
	args.is_draggable = FALSE;
	args.action_drag = NULL;
	return (args);
}

static	t_entity_texture_args	entity_sprite_texture_args(
	t_texture *texture, t_animation_status animation, t_vec2i anchor)
{
	t_entity_texture_args	args;
	
	args.anchor = anchor;
	args.texture = texture;
	args.animation = animation;
	args.update_anchor = (t_result(*)(void*, t_vec2i))update_sprite_anchor;
	args.update_offset = (t_result(*)(void*, t_vec2i))update_sprite_offset;
	args.update_texture = (t_result(*)(void*))update_sprite_texture_with_status;
	return (args);
}

void		entity_sprite_args1(t_entity_args *self, t_texture *texture,
				t_animation_status animation, t_vec2i anchor)
{
	self->texture_args = entity_sprite_texture_args(texture, animation, anchor);
	self->type = SPRITE;
}

void		entity_sprite_args2(t_entity_args *self, t_vec2f pos, t_vec2f dir,
				t_bool display)
{
	self->listener_args = entity_sprite_listener_args(display);
	self->pos = pos;
	self->dir = dir;
}

t_sprite	*create_sprite(t_entity_args entity_args)
{
	t_sprite		*self;

	if (!(self = (t_sprite*)malloc(sizeof(t_sprite))))
		return (throw_null("create_sprite", "malloc failed"));
	self->textures.front = NULL;
	self->textures.right = NULL;
	self->textures.back = NULL;
	self->textures.left = NULL;
	build_entity(&self->super, entity_args);
	return (self);
}


