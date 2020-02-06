/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_build.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 23:18:25 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/06 20:21:29 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entity/character_init.h"
#include "engine/game/game_init.h"
#include "build.h"
#include "utils/error.h"

t_result	memalloc_character_textures(t_character *self)
{
	if (self == NULL)
		return (throw_error("memalloc_character_textures", "NULL pointer"));
	if	(!(self->oriented =
		(t_oriented_textures*)malloc(sizeof(t_oriented_textures))))
		return (throw_error("build_resource_char", "malloc failed"));
	init_oriented_textures(self->oriented);
	if (!(self->hurt_texture =
			(t_pov_textures*)malloc(sizeof(t_pov_textures))))
		return (throw_error("build_character_die_with_obj", "malloc failed"));
	init_list_head(&self->hurt_texture->first_person);
	init_list_head(&self->hurt_texture->third_person);
	if (!(self->die_texture =
			(t_pov_textures*)malloc(sizeof(t_pov_textures))))
		return (throw_error("build_character_die_with_obj", "malloc failed"));
	init_list_head(&self->die_texture->first_person);
	init_list_head(&self->die_texture->third_person);
	return (OK);
}

t_result	build_character_hud_params_with_obj(t_character *self,
				t_dnon_object *char_obj)
{
	if (self == NULL || char_obj == NULL)
		return (throw_error("build_char_params", "NULL pointer provided"));
	self->life = get_int_value_by_key(char_obj, "life", 100);
	self->armor = get_int_value_by_key(char_obj, "armor", 0);
	self->velocity = get_float_value_by_key(char_obj, "velocity", 1.0f);
	self->size = get_float_value_by_key(char_obj, "size", 10);
	return (OK);
}

t_result	build_character_with_obj(t_game_resources *resources,
				t_dnon_object *char_obj)
{
	t_character	*character;

	if (resources == NULL || char_obj == NULL)
		return (throw_error("build_game_character", "NULL pointer provided"));
	if (!(character = init_new_character()))
		return (throw_error("build_game_character", "init_new_character fail"));
	if (!memalloc_character_textures(character))
		return (throw_error("build_resource_char", "memalloc_textures fail"));
	if (!build_entity_with_obj(resources, &character->super,
			get_child_list_object_by_key(char_obj, "entity")))
		return (throw_error("build_resource_char", "build_entity failed"));
	build_character_type_with_obj(character, char_obj);
	build_character_hud_params_with_obj(character, char_obj);
	build_character_camera_with_obj(&character->camera,
		get_child_list_object_by_key(char_obj, "camera"));
	build_character_weapons_with_obj(resources, character,
		get_child_list_object_by_key(char_obj, "weapons"));
	build_character_die_with_obj(resources, character,
		get_child_list_object_by_key(char_obj, "die"));
	build_oriented_textures(&resources->images, character->oriented,
		get_child_list_object_by_key(char_obj, "oriented"));
	list_add_entry(&character->super.node, &resources->entities);
	return (OK);	
}
