/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_ennemy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 22:56:53 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/22 04:52:54 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/interface/events/keyboard.h"
#include "engine/resources/resources.h"
#include "engine/entities/sprites/init_ennemy.h"
#include "engine/entities/sprites/update_ennemy.h"
#include "engine/interface/update_camera.h"
#include "engine/entities/get_entity.h"
#include "utils/parser.h"
#include "utils/error.h"
#include "build.h"
#include <math.h>

t_result	init_ennemy_type_with_obj(t_ennemy_type *type, char *ennemy_type)
{
	if (type == NULL || ennemy_type == NULL)
		return (throw_error("init_ennemy_type", "NULL pointer provided"));
	if (!ft_strcmp(ennemy_type, "monster"))
		*type = MONSTER;
	else if (!ft_strcmp(ennemy_type, "gunman"))
		*type = GUNMAN;
	else
		return (throw_error("init_ennemy_type", "unknow ennemy type detected"));
	return (OK);
}

t_result	build_ennemy_textures(t_list_head *images, t_ennemy *self,
				t_dnon_object *e_textures_obj)
{
	if (images == NULL || self == NULL || e_textures_obj == NULL)
		return (throw_error("build_ennemy_textures", "NULL pointer provided"));
	if (!build_textures_with_obj(images, &self->attack,
		get_child_list_object_by_key(e_textures_obj, "attack")))
		return (throw_error("build_ennemy_textures", "attack texture failed"));
	if (!build_textures_with_obj(images, &self->die,
		get_child_list_object_by_key(e_textures_obj, "die")))
		return (throw_error("build_ennemy_textures", "die texture failed"));
	if (!build_oriented_textures(images, &self->orientation,
		get_child_list_object_by_key(e_textures_obj, "oriented")))
		return (throw_error("build_ennemy_textures", "build o_textures fail"));
	return (OK);
}

t_result	build_ennemy_bindings(t_scene *scene, t_ennemy *ennemy)
{
	new_entity_bind_key(&scene->interface.key_hold_binds, SDLK_KP_8,
		&ennemy->super, ennemy_move_forward);
	new_entity_bind_key(&scene->interface.key_hold_binds, SDLK_KP_2,
		&ennemy->super, ennemy_move_backward);
	new_entity_bind_key(&scene->interface.key_hold_binds, SDLK_KP_4,
		&ennemy->super, ennemy_turn_right);
	new_entity_bind_key(&scene->interface.key_hold_binds, SDLK_KP_6,
		&ennemy->super, ennemy_turn_left);
	new_entity_bind_key(&scene->interface.key_binds, SDLK_KP_5,
		&ennemy->super, ennemy_attack);
	new_entity_bind_key(&scene->interface.key_binds, SDLK_KP_0,
		&ennemy->super, ennemy_die);
	new_entity_bind_key(&scene->interface.key_hold_binds, SDLK_w,
		&ennemy->super, update_ennemy_texture);
	new_entity_bind_key(&scene->interface.key_hold_binds, SDLK_a,
		&ennemy->super, update_ennemy_texture);
	new_entity_bind_key(&scene->interface.key_hold_binds, SDLK_s,
		&ennemy->super, update_ennemy_texture);
	new_entity_bind_key(&scene->interface.key_hold_binds, SDLK_d,
		&ennemy->super, update_ennemy_texture);
	return (OK);
}

t_result	build_ennemy(t_scene *scene, t_dnon_object *ennemy_obj)
{
	t_player		*player;
	t_ennemy		*ennemy;

	if (scene == NULL || ennemy_obj == NULL)
		return (throw_error("build_ennemy", "NULL pointer provided"));
	if (!(player = (t_player*)get_entity_by_name(scene, "player")))
		return (throw_error("build_ennemy", "player isn't create yet"));
	if (!(ennemy = init_new_ennemy(player)))
		return (throw_error("build_ennemy", "init_new_ennemy failed"));
	if (!build_ennemy_textures(&scene->resources.images, ennemy,
			get_child_list_object_by_key(ennemy_obj, "textures")))
		return (throw_error("build_ennemy", "build textures failed"));
	if (!init_entity_with_obj(&ennemy->super, &scene->renderer.sprites,
			&scene->entities.sprites,
			get_child_list_object_by_key(ennemy_obj, "entity")))
		return (throw_error("build_ennemy", "build_entity failed"));
	ennemy->life = get_int_value_by_key(ennemy_obj, "life", 100);
	ennemy->damages = get_int_value_by_key(ennemy_obj, "damages", 10);
	ennemy->size = get_float_value_by_key(ennemy_obj, "size", 10.0f);
	ennemy->velocity = get_float_value_by_key(ennemy_obj, "velocity", 2.0f);
	init_ennemy_type_with_obj(&ennemy->type,
		get_string_value_by_key(ennemy_obj, "ennemy_type", "monster"));
	build_ennemy_bindings(scene, ennemy);
	update_ennemy_texture_by_direction(ennemy);
	return (OK);
}
