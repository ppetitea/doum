/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 15:18:54 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/21 03:41:07 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/scenes/init_scene.h"
#include "engine/init_game.h"
#include "init.h"
#include "libft.h"
#include "utils/error.h"
#include "utils/parser.h"

t_result	init_scenes(t_game *game, t_dnon_object *obj)
{
	t_scene			*scene;
	t_dnon_object	*scene_obj;

	if (game == NULL || obj == NULL)
		return (throw_error("int_scenes", "NULL pointer provided"));
	if (!(scene_obj = get_child_list_object_by_key(obj, "menu")))
		return (throw_error("init", "fail to find scenes in file"));
	if (!(scene = init_menu_scene(game, scene_obj)))
		return (throw_error("init_game", "init_menu_scene failed"));
	game->curr_scene = scene;
	if (!(scene_obj = get_child_list_object_by_key(obj, "menu")))
		return (throw_error("init", "fail to find scenes in file"));
	if (!(scene = init_map_editor_scene(game, scene_obj)))
		return (throw_error("init_game", "init_map_editor_scene failed"));
	if (!(scene_obj = get_child_list_object_by_key(obj, "menu")))
		return (throw_error("init", "fail to find scenes in file"));
	if (!(scene = init_game_scene(game, scene_obj)))
		return (throw_error("init_game", "init_game_scene failed"));
	return (OK);
}

t_game	*init()
{
	t_dnon_object	*obj;
	t_game			*game;
	t_usize 		window;

	if (!(obj = parse_dnon_file("resources/the_one.doom")))
		return (throw_null("init", "fail to parse file"));
	if (!(obj = get_child_list_object_by_key(obj, "scenes")))
		return (throw_null("init", "fail to find scenes in file"));
	window = ft_usize(640, 480);
	if (!(game = init_new_game(window)))
		return (throw_null("init_game", "build_game failed"));
	if (!init_scenes(game, obj))
		return (throw_null("init_game", "init_scenes failed"));
	return (game);
}