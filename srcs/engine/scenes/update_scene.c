/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 16:21:00 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/20 18:56:46 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/scenes/init_scene.h"
#include "engine/scenes/update_scene.h"
#include "engine/init_game.h"
#include "utils/error.h"

t_result	swap_scene(char *name)
{
	t_game		*game;
	t_list_head	*pos;
	t_list_head	*next;
	t_scene		*next_scene;
	
	if (name == NULL)
		return (throw_error("swap_scene", "NULL pointer provided"));
	if(!(game = game_singleton(NULL)))
		return (throw_error("swap_scene", "game_singleton uninitialized"));
	pos = &game->scenes;
	next = pos->next;
	while ((pos = next) != &game->scenes)
	{
		next = next->next;
		next_scene = (t_scene*)pos;
		if (!ft_strcmp(next_scene->name, name))
		{
			game->curr_scene = next_scene;
			return (OK);
		}
	}
	return (throw_error("swap_scene", "error 404 scene not found"));
}

t_result	swap_to_game_scene()
{
	if (!swap_scene("game"))
		return (throw_error("swap_to_game_scene", "swap_scene failed"));
	return (OK);
}
t_result	swap_to_menu_scene()
{
	if (!swap_scene("menu"))
		return (throw_error("swap_to_menu_scene", "swap_scene failed"));
	return (OK);
}
t_result	swap_to_map_editor_scene()
{
	if (!swap_scene("map_editor"))
		return (throw_error("swap_to_map_editor_scene", "swap_scene failed"));
	return (OK);
}