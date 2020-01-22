/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 22:59:06 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/22 01:06:38 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/error.h"
#include "engine/entities/init_player.h"
#include "engine/entities/entities.h"

t_result	init_player_weapon(t_player_weapons *self)
{
	if (self == NULL)
		return (throw_error("init_player_weapon", "NULL pointer provided"));
	init_list_head(&self->list);
	init_list_head(&self->all);
	self->curr = NULL;
	self->catch_weapon = NULL;
	self->drop_weapon = NULL;
	return (OK);
}

t_result	overwrite_current_player_weapon(t_player_weapons *self,
				t_weapon *curr)
{
	if (self == NULL || curr == NULL)
		return (throw_error("overwrite_weapon", "NULL pointer provided"));
	self->curr = curr;
	return (OK);
}

t_player	*init_new_player()
{
	t_player	*self;

	if (!(self = (t_player*)malloc(sizeof(t_player))))
		return (throw_null("init_player", "malloc failed"));
	if (!init_entity(&self->super, PLAYER))
		return (throw_null("init_player", "init entity failed"));
	init_player_weapon(&self->weapon);
	self->velocity = 2.0f;
	self->life = 100;
	self->armor = 42;
	return (self);
}

t_result	overwrite_player_defense(t_player *self, size_t life, size_t armor)
{
	if (!(self == NULL))
		return (throw_error("overwrite_player_life", "NULL pointer provided"));
	self->life = life;
	self->armor = armor;
	return (OK);
}

t_result	overwrite_player_coordinates(t_player *self, t_vec2f pos,
				t_vec2f dir)
{
	if (self == NULL)
		return (throw_error("overwrite_player_coor", "NULL pointer provided"));
	self->super.pos = pos;
	self->super.dir = dir;
	return (OK);
}

