/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_weapon.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 22:56:53 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/25 01:50:24 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/resource/image/texture_init.h"
#include "engine/interface/events/keyboard.h"
#include "engine/resource/image/bitmap_list.h"

#include "engine/entities/update_player.h"
#include "engine/entities/init_player.h"
#include "engine/entities/init_entity.h"
#include "engine/interface/update_camera.h"
#include "engine/entities/update_entity.h"
#include "utils/parser.h"
#include "utils/error.h"
#include "build.h"
#include <math.h>

t_result	init_weapon_type_with_obj(t_weapon_type *type, char *weapon_type)
{
	if (type == NULL || weapon_type == NULL)
		return (throw_error("init_weapon_type", "NULL pointer provided"));
	if (!ft_strcmp(weapon_type, "gun"))
		*type = GUN;
	else if (!ft_strcmp(weapon_type, "sword"))
		*type = SWORD;
	else
		return (throw_error("init_weapon_type", "unknow weapon type detected"));
	return (OK);
}

t_result	build_player_weapon_textures(t_list_head *images, t_weapon *self,
				t_dnon_object *w_textures_obj)
{
	if (images == NULL || self == NULL || w_textures_obj == NULL)
		return (throw_error("build_player_weapon", "NULL pointer provided"));
	if (!build_textures_with_obj(images, &self->fire,
		get_child_list_object_by_key(w_textures_obj, "fire")))
		return (throw_error("build_player_weapon", "fire texture failed"));
	if (!build_textures_with_obj(images, &self->reload,
		get_child_list_object_by_key(w_textures_obj, "reload")))
		return (throw_error("build_player_weapon", "reload texture failed"));
	return (OK);
}

t_result	add_player_weapon(t_weapon *weapon, t_player *player,
				t_dnon_object *weapon_obj)
{
	if (weapon == NULL || player == NULL || weapon_obj == NULL)
		return (throw_error("add_player_weapon", "NULL pointer provided"));
	if (get_int_value_by_key(weapon_obj, "active", 0))
	{
		list_add_entry(&weapon->node, &player->weapon.list);
		if (get_int_value_by_key(weapon_obj, "current", 0))
		{
			player->weapon.curr = weapon;
			player->super.texture.curr = (t_texture*)weapon->fire.next;
			player->super.texture.curr_head = &weapon->fire;
			player->super.texture.prev = (t_texture*)weapon->fire.next;
			player->super.texture.prev_head = &weapon->fire;
		}
	}
	else 
		list_add_entry(&weapon->node, &player->weapon.all);
	return (OK);
}

t_result	build_player_weapon(t_list_head *images, t_player *player,
				t_dnon_object *weapon_obj)
{
	t_weapon			*weapon;
	
	if (images == NULL || player == NULL || weapon_obj == NULL)
		return (throw_error("build_player_weapon", "NULL pointer provided"));
	if (!(weapon = init_new_weapon()))
		return (throw_error("build_player_weapon", "new_weapon failed"));
	if (!(weapon->name = get_string_value_by_key(weapon_obj, "name", NULL)))
		return (throw_error("build_player_weapon", "weapon name failed"));
	weapon->ammo = get_int_value_by_key(weapon_obj, "ammo", 100);
	weapon->damages = get_int_value_by_key(weapon_obj, "damages", 21);
	weapon->magazine = get_int_value_by_key(weapon_obj, "magazine", 10);
	weapon->magazine_size = get_int_value_by_key(weapon_obj, "magazine_size", 
		10);
	if (!build_player_weapon_textures(images, weapon,
		get_child_list_object_by_key(weapon_obj, "textures")))
		return (throw_error("build_player_weapon", "weapon textures failed"));
	if (!add_player_weapon(weapon, player, weapon_obj))
		return (throw_error("build_player_weapon", "add_weapon failed"));
	return (OK);
}

t_result	build_player_weapons(t_list_head *images, t_player *player,
				t_dnon_object *weapons_obj)
{
	t_list_head		*pos;
	t_list_head		*next;
	t_dnon_object	*weapon_obj;

	if (images == NULL || player == NULL || weapons_obj == NULL)
		return (throw_error("build_player_weapons", "NULL pointer provided"));
	pos = (t_list_head*)weapons_obj->value;
	next = pos->next;
	while ((pos = next) != (t_list_head*)weapons_obj->value)
	{
		next = next->next;
		weapon_obj = (t_dnon_object*)pos;
		if (!build_player_weapon(images, player, weapon_obj))
			return (throw_error("build_player_weapons", "build_weapon failed"));
	}
	return (OK);
}
