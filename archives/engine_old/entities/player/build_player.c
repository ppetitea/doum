/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 22:56:53 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/25 01:50:24 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/interface/events/keyboard.h"
#include "engine/resource/image/bitmap_list.h"

#include "engine/entities/update_player.h"
#include "engine/entities/build_player.h"
#include "engine/interface/update_camera.h"
#include "utils/parser.h"
#include "utils/error.h"
#include "build.h"
#include <math.h>

t_result	build_player_bindings(t_scene *scene, t_player *player)
{
	new_entity_bind_key(&scene->interface.key_binds, SDLK_TAB,
		&player->super, weapon_next);
	new_entity_bind_key(&scene->interface.key_binds, SDLK_SPACE,
		&player->super, weapon_fire);
	new_entity_bind_key(&scene->interface.key_binds, SDLK_r,
		&player->super, weapon_reload);
	new_entity_bind_key(&scene->interface.key_hold_binds, SDLK_UP,
		&player->super, elevate_camera);
	new_entity_bind_key(&scene->interface.key_hold_binds, SDLK_DOWN,
		&player->super, lower_camera);
	new_entity_bind_key(&scene->interface.key_hold_binds, SDLK_LEFT,
		&player->super, rotate_camera_left);
	new_entity_bind_key(&scene->interface.key_hold_binds, SDLK_RIGHT,
		&player->super, rotate_camera_right);
	new_entity_bind_key(&scene->interface.key_hold_binds, SDLK_w,
		&player->super, translate_camera_forward);
	new_entity_bind_key(&scene->interface.key_hold_binds, SDLK_a,
		&player->super, translate_camera_left);
	new_entity_bind_key(&scene->interface.key_hold_binds, SDLK_d,
		&player->super, translate_camera_right);
	new_entity_bind_key(&scene->interface.key_hold_binds, SDLK_s,
		&player->super, translate_camera_backward);
	return (OK);
}

t_result	build_player(t_scene *scene, t_dnon_object *player_obj)
{
	t_player		*player;
	t_list_head		*images;

	images = &scene->resources.images;
	if (!(player = init_new_player()))
		return (throw_error("build_player", "init_new_player failed"));
	if (!build_player_weapons(images, player,
			get_child_list_object_by_key(player_obj, "weapons")))
		return (throw_error("build_player", "build weapons failed"));
	if (!init_entity_with_obj(&player->super, &scene->renderer.ui_components,
			&scene->entities.ui_components,
			get_child_list_object_by_key(player_obj, "entity")))
		return (throw_error("build_player", "build_entity failed"));
	if (!build_player_camera(player,
			get_child_list_object_by_key(player_obj, "camera")))
		return (throw_error("build_player", "build camera failed"));
	player->life = get_int_value_by_key(player_obj, "life", 100);
	player->armor = get_int_value_by_key(player_obj, "armor", 42);
	player->velocity = get_float_value_by_key(player_obj, "velocity", 1.0f);
	build_player_bindings(scene, player);
	scene->renderer.cam_ref = &player->cam;
	return (OK);
}
