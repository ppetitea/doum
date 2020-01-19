/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scenes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 15:18:54 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/18 20:58:24 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/scenes/build_scene.h"
#include "engine/game.h"
#include "scenes/init.h"
#include "utils/error.h"

t_result	*init_scenes(t_game *game)
{
	t_scene		*scene;
	
	if (game == NULL)
		return (throw_null("int_scenes", "NULL pointer provided"));
	if (!init_menu_scene(game))
		return (throw_null("init_game", "init_menu_scene failed"));
	if (!init_map_editor_scene(game))
		return (throw_null("init_game", "init_map_editor_scene failed"));
	if (!init_game_scene(game))
		return (throw_null("init_game", "init_game_scene failed"));
	return (game);
}