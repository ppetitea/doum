/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 19:22:44 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/28 19:34:03 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/component/action.h"
#include "engine/game/game_init.h"
#include "utils/error.h"

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
		if (ft_strcmp(scene->name, name))
		{
			game->curr_scene = scene;
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