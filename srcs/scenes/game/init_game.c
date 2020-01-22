/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 16:00:09 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/21 23:22:41 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/scenes/init_scene.h"
#include "engine/init_game.h"
#include "build.h"
#include "utils/error.h"

t_scene		*init_game_scene(t_game *game, t_dnon_object *scene_obj)
{
	char			*name;
	t_scene			*scene;
	t_dnon_object	*resources_obj;

	name = NULL;
	if (game == NULL || scene_obj == NULL)
		return (throw_null("init_game", "NULL pointer provided"));
	if (!(resources_obj = get_child_list_object_by_key(scene_obj, "resources")))
		return (throw_null("init", "fail to find game resources in file"));
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
