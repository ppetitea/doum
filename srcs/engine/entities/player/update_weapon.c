/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_weapon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 01:16:28 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/22 15:29:11 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/error.h"
#include "engine/entities/init_player.h"

t_result	weapon_next(t_entity *entity)
{
	t_player	*player;

	if (entity == NULL)
		return (throw_error("weapon_next", "NULL pointer provided"));
	if (entity->type != PLAYER)
		return (throw_error("weapon_next", "entity provided isn't a player"));
	player = (t_player*)entity;
	if (player->weapon.list.next == &player->weapon.list)
		return (throw_error("weapon_next", "weapon list is empty"));
	if (player->weapon.curr->node.next == &player->weapon.list)
		player->weapon.curr = (t_weapon*)player->weapon.list.next;
	else
		player->weapon.curr = (t_weapon*)player->weapon.curr->node.next;
	player->super.texture.animation = STOP;
	player->super.texture.curr = (t_texture*)player->weapon.curr->fire.next;
	player->super.texture.curr_head = &player->weapon.curr->fire;
	player->super.texture.prev = player->super.texture.curr;
	player->super.texture.prev_head = player->super.texture.curr_head;
	return (OK);
}

#include	<stdio.h>

void		weapon_status(t_weapon weapon)
{
	(void)weapon;
	// printf("ammo %ld\n", weapon.ammo);
	// printf("magazine %ld\n", weapon.magazine);
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
	handle_weapon_magazine(player->weapon.curr);
	player->super.texture.animation = EPHEMERAL;
	player->super.texture.curr = (t_texture*)player->weapon.curr->reload.next;
	gettimeofday(&player->super.texture.last, NULL);
	// timespec_get(&player->super.texture.last, TIME_UTC);
	player->super.texture.curr_head = &player->weapon.curr->reload;
	weapon_status(*player->weapon.curr);
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
	if (player->weapon.curr->magazine > 0)
	{
		player->weapon.curr->magazine--;
		player->super.texture.curr = (t_texture*)player->weapon.curr->fire.next;
		player->super.texture.curr_head = &player->weapon.curr->fire;
		player->super.texture.prev = player->super.texture.curr;
		player->super.texture.prev_head = player->super.texture.curr_head;
		player->super.texture.animation = IN_PROGRESS;
		gettimeofday(&player->super.texture.last, NULL);
		// timespec_get(&player->super.texture.last, TIME_UTC);
	}
	weapon_status(*player->weapon.curr);
	return (OK);
}
