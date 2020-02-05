/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 00:05:38 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/05 16:32:24 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entity/character_init.h"
#include "engine/entity/character_action.h"
#include "engine/entity/entity_init.h"
#include "engine/map/map_init.h"
#include "engine/game/game_init.h"
#include "utils/error.h"

t_character	*init_new_character()
{
	t_character *self;

	if (!(self = (t_character*)malloc(sizeof(t_character))))
		return (throw_null("init_new_character", "malloc failed"));
	init_entity(&self->super, CHARACTER);
	self->super.type = CHARACTER;
	self->type = OBJECT;
	init_camera(&self->camera);
	self->life = 100;
	self->armor = 0;
	self->size = 10;
	self->velocity = 1.0f;
	self->target = NULL;
	self->target_dist = -1.0f;
	self->hurt_texture = NULL;
	self->die_texture = NULL;
	self->oriented = NULL;
	init_list_head(&self->all_weapons);
	init_list_head(&self->weapons);
	self->curr_weapon = NULL;
	self->catch_weapon = character_catch_weapon;
	self->drop_weapon = character_drop_weapon;
	self->orientate = orientate_texture;
	self->jump = character_jump;
	self->crawl = character_crawl;
	self->attack = character_attack;
	self->die = character_die;
	self->run = character_run;
	return (self);
}

t_character	*game_player()
{
	t_map *map;

	if (!(map = game_map()))
		return (throw_null("game_player", "current player not found"));
	return (map->character_ref);
}