/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 15:18:54 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/20 00:56:38 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/scenes/init_scene.h"
#include "engine/init_game.h"
#include "init.h"
#include "libft.h"
#include "utils/error.h"

t_result	init_scenes(t_game *game)
{
	t_scene	*scene;
	
	if (game == NULL)
		return (throw_error("int_scenes", "NULL pointer provided"));
	// if (!init_menu_scene(game))
	// 	return (throw_error("init_game", "init_menu_scene failed"));
	// if (!init_map_editor_scene(game))
	// 	return (throw_error("init_game", "init_map_editor_scene failed"));
	if (!(scene = init_game_scene(game)))
		return (throw_error("init_game", "init_game_scene failed"));
	game->curr_scene = scene;
	return (OK);
}

t_game	*init()
{
	t_game		*game;
	t_usize 	window;

	window = ft_usize(640, 480);
	if (!(game = init_new_game(window)))
		return (throw_null("init_game", "build_game failed"));
	if (!init_scenes(game))
		return (throw_null("init_game", "init_scenes failed"));
	return (game);
}