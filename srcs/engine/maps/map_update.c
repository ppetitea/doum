/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 01:35:55 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/08 05:08:57 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entity/character_update.h"
#include "engine/entity/character_init.h"
#include "engine/entity/entity_update.h"
#include "engine/component/action.h"
#include "engine/game/game_init.h"
#include "engine/map/map_init.h"
#include "engine/map/map_update.h"
#include "utils/matrix.h"
#include "utils/error.h"
#include "libft.h"
#include <math.h>

# include <stdio.h>

t_result	spawn_character(void *game_resource, t_resource_type resource_type,
					t_dnon_object *args)
{
	t_game		*game;
	t_entity	*entity;
	t_character	*character_new;

	if (game_resource == NULL || args == NULL)
		return (throw_error("spawn_character", "NULL pointer provided"));
	if (resource_type != R_GAME)
		return (throw_error("spawn_character", "resource isn't game instance"));
	game = (t_game*)game_resource;
	if (game->curr_map == NULL)
		return (throw_error("spawn_character", "curr_map is NULL"));
	if (!(entity = get_entity_by_name(&game->resources.entities,
		get_string_value_by_key(args, "character_name", NULL))))
		return (throw_error("spawn_character", "args -> name not found"));
	if (entity->type != CHARACTER)
		return (throw_error("spawn_character", "entity isn't character"));
	if (!(character_new = duplicate_character((t_character*)entity)))
		return (throw_error("spawn_character", "character_dup failed"));
	overwrite_character_with_obj(character_new,
		get_child_list_object_by_key(args, "character"));
	list_add_entry(&character_new->super.node, &game->curr_map->e_oriented);
	return (OK);
}

// t_result	update_map(void *game_resource, t_resource_type resource_type,
// 					t_dnon_object *args)
// {
// 	t_game	*game;

// 	if (game_resource == NULL || args == NULL)
// 		return (throw_error("rotate_camera", "NULL pointer provided"));
// 	if (resource_type != R_GAME)
// 		return (throw_error("rotate_camera", "resource must be game instance"));
// 	game = (t_game*)game_resource;
// 	if (game->curr_map == NULL)
// 		return (throw_error("rotate_camera", "curr_map is NULL"));
// 	if (game->curr_map->character_ref == NULL)
// 		return (throw_error("rotate_camera", "curr_character is NULL"));
// 	if (get_int_value_by_key(args, "right", 0))
// 		rotate_camera_right(&game->curr_map->character_ref->super);
// 	else if (get_int_value_by_key(args, "left", 0))
// 		rotate_camera_left(&game->curr_map->character_ref->super);
// 	else
// 		return (throw_error("rotate_camera", "args must be left or right"));
// 	return (OK);
// }
