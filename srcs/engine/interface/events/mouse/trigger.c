/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trigger.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 01:08:30 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/06 13:32:00 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"
#include "engine/interface/events/mouse.h"
#include "engine/entity/entity_init.h"
#include "engine/entity/entity_update.h"
#include "engine/entity/character_update.h"
#include "engine/scene/scene_init.h"
#include "utils/error.h"

#include <stdio.h>

t_result	trigger_entities_by_hover(t_game *game)
{
	t_mouse	*mouse;

	if (game == NULL)
		return (throw_error("trigger_entities_by_hover", "NULL pointer"));
	mouse = &game->interface.mouse;
	if (game->curr_map != NULL)
	{
		trigger_entity_action_by_hover(&game->curr_map->e_static, mouse);
		trigger_entity_action_by_hover(&game->curr_map->e_oriented, mouse);
	}
	if (game->curr_scene != NULL)
		trigger_entity_action_by_hover(&game->curr_scene->entities, mouse);
	return (OK);
}

t_result	trigger_entities_by_select(t_game *game)
{
	t_mouse	*mouse;

	if (game == NULL)
		return (throw_error("trigger_entities_by_select", "NULL pointer"));
	mouse = &game->interface.mouse;
	if (game->curr_map != NULL)
	{
		if (trigger_entity_action_by_select(&game->curr_map->e_static, mouse))
			return (OK);
		if (trigger_entity_action_by_select(&game->curr_map->e_oriented, mouse))
			return (OK);
	}
	if (game->curr_scene != NULL)
		if (trigger_entity_action_by_select(&game->curr_scene->entities, mouse))
			return (OK);
	return (ERROR);
}

t_result	trigger_entities_by_drag(t_game *game)
{
	t_mouse	*mouse;

	if (game == NULL)
		return (throw_error("trigger_entities_by_drag", "NULL pointer"));
	mouse = &game->interface.mouse;
	if (game->curr_map != NULL)
	{
		if (trigger_entity_action_by_drag(&game->curr_map->e_static, mouse))
			return (OK);
		if (trigger_character_action_by_drag(&game->curr_map->e_oriented, mouse))
			return (OK);
		if (trigger_character_action_by_drag(&game->curr_map->e_oriented_storage,
			mouse))
			return (OK);
		if (trigger_player_action_by_drag(game->curr_map->character_ref, mouse))
			return (OK);
	}
	if (game->curr_scene != NULL)
		if (trigger_entity_action_by_drag(&game->curr_scene->entities, mouse))
			return (OK);
	return (ERROR);
}

t_result	trigger_entities_by_drop(t_game *game)
{
	t_mouse	*mouse;

	if (game == NULL)
		return (throw_error("trigger_entities_by_drop", "NULL pointer"));
	mouse = &game->interface.mouse;
	if (game->curr_map != NULL)
	{
		if (trigger_character_action_by_drop(&game->curr_map->e_static, mouse))
			return (OK);
		if (trigger_character_action_by_drop(&game->curr_map->e_oriented, mouse))
			return (OK);
		if (trigger_character_action_by_drop(&game->curr_map->e_oriented_storage, mouse))
			return (OK);
		if (trigger_player_action_by_drop(game->curr_map->character_ref, mouse))
			return (OK);
	}
	if (game->curr_scene != NULL)
		if (trigger_entity_action_by_drop(&game->curr_scene->entities, mouse))
			return (OK);
	return (ERROR);
}
