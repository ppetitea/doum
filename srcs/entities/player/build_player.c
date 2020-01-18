/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 22:59:06 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/18 04:15:13 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/error.h"
#include "entities/player.h"
#include "entities/entities.h"
#include "entities/update_entities.h"

t_result	build_player_listener(t_listener *self, t_list_head *render,
				t_list_head *storage, t_bool display)
{
	self->display = display;
	self->render_list = render;
	self->storage_list = storage;
	self->is_hoverable = FALSE;
	self->is_hover = FALSE;
	self->is_selectable = FALSE;
	self->is_selected = FALSE;
	self->action_select = NULL;
	self->is_draggable = FALSE;
	self->is_dragged = FALSE;
	self->action_drag = NULL;
	return (OK);
}

t_result	build_player_entity_texture(t_entity_texture *self,
				t_entity_texture_args args)
{
	timespec_get(&self->last, TIME_UTC);
	self->anchor = args.anchor;
	self->t = args.texture;
	self->t_head = args.texture;
	self->animation = args.animation;
	self->update_anchor = (t_result(*)(void*, t_vec2i))update_entity_anchor;
	self->update_offset = (t_result(*)(void*, t_vec2i))update_entity_offset;
	self->update_texture = args.update_texture;
	return (OK);
}

t_result	build_player_entity(t_entity *self, t_entity_args args)
{
	init_list_head(&self->node);
	self->type = PLAYER;
	self->pos = args.pos;
	self->dir = args.dir;
	if (self->status.display)
		list_add_entry(&self->node, self->status.render_list);
	else
		list_add_entry(&self->node, self->status.storage_list);
	return (OK);
}

t_player	*create_player()
{
	t_player	*self;

	if (!(self = (t_player*)malloc(sizeof(t_player))))
		return (throw_null("create_player", "malloc failed"));
	self->weapons = NULL;
	self->weapons_storage = NULL;
	self->cam.pos = &self->super.pos;
	self->cam.dir = &self->super.dir;
	// self->size = ft_usize(5, 5);
	self->velocity = 2.0f;
	self->life = 100;
	self->armor = 42;
	// self->catch_weapon = NULL;
	// self->drop_weapon = NULL;
	return (self);
}


t_result	update_player_texture(t_entity *entity)
{
	if (entity->type != PLAYER)
		return (throw_error("update_player_texture", "must provide player"));
	return (OK);
}

