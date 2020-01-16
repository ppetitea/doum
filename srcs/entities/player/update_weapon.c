/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_weapon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 01:16:28 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/16 08:34:32 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/error.h"
#include "entities/player.h"
#include "time.h"

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
	player->super.texture.t = player->weapons->fire;
	player->super.texture.t_head = player->weapons->fire;
	player->super.texture.t_last = player->weapons->fire;
	return (OK);
}
#include	<stdio.h>

void		weapon_status(t_weapon weapon)
{
	printf("ammo %ld\n", weapon.ammo);
	printf("cartridges %ld\n", weapon.cartridges);
}

t_bool		handle_weapon_cartridges(t_weapon *weapon)
{
	size_t	cartridges_wishes;

	cartridges_wishes = weapon->cartridge_clip_size - weapon->cartridges;
	if (weapon->ammo == 0 || cartridges_wishes == 0)
		return (FALSE);
	if (weapon->ammo < cartridges_wishes)
		cartridges_wishes = weapon->ammo;
	weapon->ammo -= cartridges_wishes;
	weapon->cartridges += cartridges_wishes;
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
	handle_weapon_cartridges(player->weapons);
	player->super.texture.animation = EPHEMERAL;
	player->super.texture.t = player->weapons->reload;
	timespec_get(&player->super.texture.last, TIME_UTC);
	player->super.texture.t_head = player->weapons->reload;
	player->super.texture.t_last = player->weapons->fire;
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
	if (player->weapons->cartridges > 0)
	{
		player->weapons->cartridges--;
		player->super.texture.t = player->weapons->fire;
		player->super.texture.t_head = player->weapons->fire;
		player->super.texture.animation = IN_PROGRESS;
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
