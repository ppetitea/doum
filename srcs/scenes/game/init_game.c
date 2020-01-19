/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 16:00:09 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/18 21:00:28 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/scenes/build_scene.h"
#include "engine/game.h"
#include "scenes/init.h"
#include "utils/error.h"

t_result	init_game_scene(t_game *game)
{
	char	*name;
	t_scene	*scene;

	name = NULL;
	if (game == NULL)
		return (throw_error("init_game", "NULL pointer provided"));
	if (!(name = ft_strdup("game")))
		return (throw_error("init_game", "strdup failed"));
	if (!(scene = build_scene(name, &game->screen)))
		return (throw_error("init_game", "build_scene failed"));
	if (!init_game_interface(scene))
		return (throw_error("init_game", "game_interface failed"));
	if (!init_game_resources(scene))
		return (throw_error("init_game", "game_resources failed"));
	if (!init_game_entities(scene))
		return (throw_error("init_game", "game_entities failed"));
	list_add_entry(&scene->node, &game->scenes);
	return (OK);
}