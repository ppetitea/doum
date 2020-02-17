/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 15:18:54 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/17 18:19:39 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/error.h"
#include "utils/parser.h"
#include "libft.h"
#include "build.h"
#include "engine/resource/sound/sound.h"
#include <stdio.h>

t_result	build_game_resources(t_game *game,
				t_dnon_object *game_obj)
{
	t_dnon_object *resources_obj;

	if (game == NULL || game_obj == NULL)
		return (throw_error("build_resources", "NULL pointer provided"));
	if (!(resources_obj = get_child_list_object_by_key(game_obj, "resources")))
		return (throw_error("build_resources", "fail to find resources obj"));
	if (!resources_load_images(&game->resources.images,
		get_child_list_object_by_key(resources_obj, "images")))
		return (throw_error("build_game", "load_images failed"));
	if (!build_game_entities(&game->resources,
		get_child_list_object_by_key(game_obj, "entities")))
		return (throw_error("build_game_resources", "build entities failed"));
	if (!build_game_resources_maps(game,
		get_child_list_object_by_key(game_obj, "maps")))
		return (throw_error("build_game_resources", "build maps failed"));
	if (!build_game_resources_scenes(game,
		get_child_list_object_by_key(game_obj, "scenes")))
		return (throw_error("build_game_resources", "build scenes failed"));
	return (OK);
}

t_game	*build()
{
	t_dnon_object	*obj;
	t_game			*game;
	t_usize 		window;

	if (!(obj = parse_dnon_file("resources/resources.doom")))
		return (throw_null("build", "fail to parse file"));
	window = ft_usize(1080, 720);
	if (!(game = init_new_game(window)))
		return (throw_null("build_game", "build_game failed"));
	if (!build_game_resources(game, obj))
		return (throw_null("build_game", "build_resources failed"));
	if (!load_sounds(&game->resources.songs))
		return (throw_null("build_game", "load_sounds failed"));
	return (game);
}
