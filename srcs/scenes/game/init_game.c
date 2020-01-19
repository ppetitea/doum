/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 16:00:09 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/19 23:32:43 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/scenes/init_scene.h"
#include "engine/init_game.h"
#include "init.h"
#include "utils/error.h"

t_scene		*init_game_scene(t_game *game)
{
	char	*name;
	t_scene	*scene;

	name = NULL;
	if (game == NULL)
		return (throw_null("init_game", "NULL pointer provided"));
	if (!(name = ft_strdup("game")))
		return (throw_null("init_game", "strdup failed"));
	if (!(scene = init_new_scene(name, &game->screen)))
		return (throw_null("init_game", "new_scene failed"));
	if (!init_game_interface(scene))
		return (throw_null("init_game", "game_interface failed"));
	if (!init_game_resources(scene))
		return (throw_null("init_game", "game_resources failed"));
	if (!init_game_entities(scene))
		return (throw_null("init_game", "game_entities failed"));
	list_add_entry(&scene->node, &game->scenes);
	return (scene);
}