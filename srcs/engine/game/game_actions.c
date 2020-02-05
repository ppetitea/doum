/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 19:22:44 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/04 15:49:16 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/interface/events/events.h"
#include "engine/entity/entity_update.h"
#include "engine/scene/scene_render.h"
#include "engine/component/action.h"
#include "engine/game/game_init.h"
#include "utils/error.h"


#include <stdio.h>

t_result		swap_scene_by_name(t_game *game, char *name)
{
	t_scene			*scene;
	t_list_head		*pos;

	if (game == NULL || name == NULL)
		return (throw_error("swap_scene_by_name", "NULL pointer provided"));
	pos = &game->resources.scenes;
	while ((pos = pos->next) != &game->resources.scenes)
	{
		scene = (t_scene*)pos;
		if (!ft_strcmp(scene->name, name))
		{
			game->curr_scene = scene;
			trigger_entities_by_hover(game);
			overwrite_characters_with_map_config(game);
			return (OK);
		}
	}
	return (throw_error("swap_scene_by_name", "scene_not_found"));
}

t_result		swap_scene(void *game, t_resource_type resource_type,
					t_dnon_object *args)
{
	if (game == NULL || args == NULL)
		return (throw_error("swap_scene", "NULL pointer provided"));
	if (resource_type != R_GAME)
		return (throw_error("swap_scene", "resource must be game instance"));
	swap_scene_by_name(game, get_string_value_by_key(args, "scene_name", NULL));
	return (OK);
}

t_result		swap_map(void *game_resource, t_resource_type resource_type,
					t_dnon_object *args)
{
	t_game	*game;
	
	if (game_resource == NULL || args == NULL)
		return (throw_error("swap_map", "NULL pointer provided"));
	if (resource_type != R_GAME)
		return (throw_error("swap_map", "resource must be game instance"));
	game = (t_game*)game_resource;
	if (game->curr_map == NULL)
		return (throw_error("swap_map", "current_map is NULL"));
	if (strcmp_obj("side", "next", args))
	{
		if (game->curr_map->node.next == &game->resources.voxel_maps)
			game->curr_map = (t_map*)game->resources.voxel_maps.next;
		else
			game->curr_map = (t_map*)game->curr_map->node.next;
	}
	else if (game->curr_map->node.prev == &game->resources.voxel_maps)
		game->curr_map = (t_map*)game->resources.voxel_maps.prev;
	else
		game->curr_map = (t_map*)game->curr_map->node.prev;
	return (OK);
}

t_result		stop_game(void *game_resource, t_resource_type resource_type,
					t_dnon_object *args)
{
	t_game	*game;
	
	if (game_resource == NULL)
		return (throw_error("stop_game", "NULL pointer provided"));
	if (resource_type != R_GAME)
		return (throw_error("stop_game", "resource must be game instance"));
	game = (t_game*)game_resource;
	game->is_running = FALSE;
	(void)args;
	return (OK);
}
