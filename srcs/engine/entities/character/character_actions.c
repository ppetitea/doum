/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_actions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 00:06:50 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/26 07:49:24 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entity/character_init.h"
#include "engine/entity/entity_init.h"
#include "utils/error.h"

void	character_crawl(t_character *self)
{
	if (self == NULL)
		throw_warning("character_crawl", "NULL pointer provided", 3);
	else if (self->camera.height <= 10.0f)
		throw_warning("character_crawl", "camera is already on floor", 3);
	else
	{
		self->camera.height -= 10.0f;
	}
}

void	character_jump(t_character *self)
{
	if (self == NULL)
		throw_warning("character_jump", "NULL pointer provided", 3);
	else
	{
		self->camera.height += 10.0f;
	}
}

void	character_run(t_character *self)
{
	if (self == NULL)
		throw_warning("character_run", "NULL pointer provided", 3);
	else
	{
		self->velocity += 5.0f;
	}
}

void	character_attack(t_character *self)
{
	t_list_head	*attack_texture;

	if (self == NULL)
		return (throw_warning("character_attack", "NULL pointer provided", 3));
	if (self->life <= 0)
		return (throw_warning("character_attack", "character already dead", 3));
	if (self->curr_weapon == NULL)
		return (throw_warning("character_attack", "no weapon founded", 3));
	if (self->curr_weapon->type == GUN && self->curr_weapon->magazine == 0)
		return (throw_warning("character_attack", "gun magazine is empty", 3));
	if (self->is_player)
		attack_texture = &self->curr_weapon->fire->first_person;
	else
		attack_texture = &self->curr_weapon->fire->third_person;
	self->super.texture.curr = (t_texture*)attack_texture->next;
	self->super.texture.curr_head = attack_texture;
	self->super.texture.animation = IN_PROGRESS;
}

void	character_die(t_character *self)
{
	t_list_head	*die_texture;

	if (self == NULL)
		throw_warning("character_die", "NULL pointer provided", 3);
	else if (self->life > 0)
		throw_warning("character_die", "character life > 0", 3);
	else
	{
		if (self->is_player)
			die_texture = &self->die_texture->first_person;
		else
			die_texture = &self->die_texture->third_person;
		self->super.texture.curr = (t_texture*)die_texture->next;
		self->super.texture.curr_head = die_texture;
		self->super.texture.animation = FINAL;
	}
}

void	character_catch_weapon(t_character *self, char *name)
{
	t_weapon	*weapon;
	t_list_head	*pos;
	t_list_head	*next;

	if (self == NULL || name == NULL)
		throw_warning("character_catch_weapon", "NULL pointer provided", 3);
	else
	{
		pos = &self->all_weapons;
		next = pos->next;
		while ((pos = next) != &self->all_weapons)
		{
			next = next->next;
			weapon = (t_weapon*)pos;
			if (!ft_strcmp(weapon->name, name))
			{
				list_del_entry(&weapon->node);
				list_add_entry(&weapon->node, &self->weapons);
				self->curr_weapon = weapon;
				return ;
			}
		}
		throw_warning("character_catch_weapon", "weapon not found", 3);
		throw_warning("character_catch_weapon", name, 3);
	}
}

void	character_drop_weapon(t_character *self)
{
	t_weapon	*drop;

	if (self == NULL)
		throw_warning("character_catch_weapon", "NULL pointer provided", 3);
	else if (self->curr_weapon == NULL)
		throw_warning("character_catch_weapon", "curr weapon is NULL", 3);
	else 
	{
		drop = self->curr_weapon;
		if (self->curr_weapon->node.prev == &self->weapons)
			self->curr_weapon = (t_weapon*)self->weapons.next;
		else
			self->curr_weapon = (t_weapon*)self->curr_weapon->node.prev;
		list_del_entry(&drop->node);
		list_add_entry(&drop->node, &self->all_weapons);
	}
}

