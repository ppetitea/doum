/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 15:18:54 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/27 14:04:07 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/error.h"
#include "utils/parser.h"
#include "libft.h"
#include "build.h"


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
	// if (!build_game_resources_scenes(resources,
	// 	get_child_list_object_by_key(game_obj, "scenes")))
	// 	return (throw_error("build_game_resources", "build scenes failed"));
	return (OK);
}

t_game	*build()
{
	t_dnon_object	*obj;
	t_game			*game;
	t_usize 		window;

	if (!(obj = parse_dnon_file("resources/game.doom")))
		return (throw_null("build", "fail to parse file"));
	window = ft_usize(640, 480);
	if (!(game = init_new_game(window)))
		return (throw_null("build_game", "build_game failed"));
	if (!build_game_resources(game, obj))
		return (throw_null("build_game", "build_resources failed"));
	if (game->resources.voxel_maps.next != &game->resources.voxel_maps)
		game->curr_map = (t_map*)game->resources.voxel_maps.next;
	// if (!build_maps(game, get_child_list_object_by_key(obj, "maps")))
	// 	return (throw_null("build_game", "build_maps failed"));
	// if (!build_scenes(game, obj))
	// 	return (throw_null("build_game", "build_scenes failed"));
	(void)obj;
	(void)window;
	(void)game;
	// return (NULL);
	return (game);
}
