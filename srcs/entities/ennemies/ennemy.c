/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 11:25:44 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/17 22:45:48 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities/update_entities.h"
#include "entities/sprites/ennemies.h"
#include "entities/player.h"
#include "utils/error.h"

t_result	build_ennemy_listener(t_listener *self, t_list_head *render,
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

t_result	build_ennemy_entity_texture(t_entity_texture *self,
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

t_result	build_ennemy_entity(t_entity *self, t_entity_args args)
{
	init_list_head(&self->node);
	self->type = ENNEMY;
	self->pos = args.pos;
	self->dir = args.dir;
	if (self->status.display)
		list_add_entry(&self->node, self->status.render_list);
	else
		list_add_entry(&self->node, self->status.storage_list);
	return (OK);
}

static void	set_ennemy_textures_to_null(t_ennemy *self)
{
	if (self == NULL)
		return (throw_void("set_ennemy_texture_to_null", "NULL pointer"));
	self->orientation.front = NULL;
	self->orientation.front_r = NULL;
	self->orientation.front_l = NULL;
	self->orientation.right = NULL;
	self->orientation.back = NULL;
	self->orientation.back_r = NULL;
	self->orientation.back_l = NULL;
	self->orientation.left = NULL;
	self->attack = NULL;
	self->die = NULL;
}

t_ennemy	*create_ennemy(t_player *player)
{
	t_ennemy	*self;

	if (!(self = (t_ennemy*)malloc(sizeof(t_ennemy))))
		return (throw_null("create_ennemy", "malloc failed"));
	set_ennemy_textures_to_null(self);
	self->damages = 10;
	self->life = 100;
	self->size = 10;
	self->velocity = 1.0f;
	self->player_ref = &player->super.pos;
	return (self);
}