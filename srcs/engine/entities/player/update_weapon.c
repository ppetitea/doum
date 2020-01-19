/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_weapon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 01:16:28 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/19 00:48:37 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/error.h"
#include "engine/entities/build_player.h"

t_result	weapon_next(t_entity *entity)
{
	t_player	*player;

	if (entity == NULL)
		return (throw_error("weapon_next", "NULL pointer provided"));
	if (entity->type != PLAYER)
		return (throw_error("weapon_next", "entity provided isn't a player"));
	player = (t_player*)entity;
	player->weapons = (t_weapon*)player->weapons->node.next;
	player->super.texture.animation = STOP;
	player->super.texture.curr = player->weapons->fire;
	player->super.texture.curr_head = player->weapons->fire;
	player->super.texture.prev = player->weapons->fire;
	return (OK);
}
#include	<stdio.h>

void		weapon_status(t_weapon weapon)
{
	printf("ammo %ld\n", weapon.ammo);
	printf("magazine %ld\n", weapon.magazine);
}

t_bool		handle_weapon_magazine(t_weapon *weapon)
{
	size_t	magazine_wishes;

	magazine_wishes = weapon->magazine_size - weapon->magazine;
	if (weapon->ammo == 0 || magazine_wishes == 0)
		return (FALSE);
	if (weapon->ammo < magazine_wishes)
		magazine_wishes = weapon->ammo;
	weapon->ammo -= magazine_wishes;
	weapon->magazine += magazine_wishes;
	return (TRUE);
}

t_result	weapon_reload(t_entity *entity)
{
	t_player	*player;

	if (entity == NULL)
		return (throw_error("weapon_next", "NULL pointer provided"));
	if (entity->type != PLAYER)
		return (throw_error("weapon_next", "entity provided isn't a player"));
	player = (t_player*)entity;
	handle_weapon_magazine(player->weapons);
	player->super.texture.animation = EPHEMERAL;
	player->super.texture.curr = player->weapons->reload;
	timespec_get(&player->super.texture.last, TIME_UTC);
	player->super.texture.curr_head = player->weapons->reload;
	player->super.texture.prev = player->weapons->fire;
	weapon_status(*player->weapons);
	return (OK);
}

t_result	weapon_fire(t_entity *entity)
{
	t_player	*player;

	if (entity == NULL)
		return (throw_error("weapon_next", "NULL pointer provided"));
	if (entity->type != PLAYER)
		return (throw_error("weapon_next", "entity provided isn't a player"));
	player = (t_player*)entity;
	if (player->weapons->magazine > 0)
	{
		player->weapons->magazine--;
		player->super.texture.curr = player->weapons->fire;
		player->super.texture.curr_head = player->weapons->fire;
		player->super.texture.animation = IN_PROGRESS;
		timespec_get(&player->super.texture.last, TIME_UTC);
	}
	weapon_status(*player->weapons);
	return (OK);
}

t_result	update_weapon_name(t_weapon *self, char *name)
{
	if (self == NULL || name == NULL)
		return (throw_error("update_weapon_name", "NULL pointer provided"));
	if (self->name != NULL)
		free(self->name);
	self->name = name;
	return (OK);
}

t_result	update_weapon_ammo(t_weapon *self, size_t ammo)
{
	if (self == NULL)
		return (throw_error("update_weapon_ammo", "NULL pointer provided"));
	self->ammo = ammo;
	return (OK);
}

t_result	update_weapon_damages(t_weapon *self, size_t damages)
{
	if (self == NULL)
		return (throw_error("update_weapon_damages", "NULL pointer provided"));
	self->damages = damages;
	return (OK);
}
