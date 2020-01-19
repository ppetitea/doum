/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 16:21:00 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/18 16:34:44 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/scenes/build_scene.h"
#include "engine/game.h"
#include "utils/error.h"

t_result	swap_scene(t_game *game, char *name)
{
	t_list_head	*pos;
	t_list_head	*next;
	t_scene		*scene;
	
	if (game == NULL || name == NULL)
		return (throw_error("swap_scene", "NULL pointer provided"));
	pos = &game->scenes;
	next = pos->next;
	while ((pos = next) != &game->scenes)
	{
		next = next->next;
		scene = (t_scene*)pos;
		if (!ft_strcmp(scene->name, name))
		{
			game->curr_scene = scene;
			return (OK);
		}
	}
	return (ERROR);
}