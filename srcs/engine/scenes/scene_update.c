/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_update.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 16:21:00 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/04 15:46:15 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entity/character_update.h"
#include "engine/entity/character_init.h"
#include "engine/entity/entity_update.h"
#include "engine/component/action.h"
#include "engine/scene/scene_init.h"
#include "engine/game/game_init.h"
#include "engine/map/map_update.h"
#include "engine/map/map_init.h"
#include "utils/error.h"

t_result	overwrite_characters_with_map_config(t_game *game)
{
	t_dnon_object	*character_obj;

	if (game == NULL)
		return (throw_error("apply_map_config", "NULL pointer provided"));
	if (game->curr_map == NULL)
		return (throw_error("apply_map_config", "curr_map is NULL"));
	if (game->curr_scene == NULL)
		return (throw_error("apply_map_config", "curr_scene is NULL"));
	if ((character_obj = game->curr_scene->map_render_config.character_obj))
	{
		overwrite_entities_by_type_with_obj(&game->curr_map->e_oriented,
			character_obj);	
		overwrite_entities_by_type_with_obj(&game->curr_map->e_oriented_storage,
			character_obj);
	}
	return (OK);
}
