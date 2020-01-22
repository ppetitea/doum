/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_entities.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 15:18:54 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/21 23:55:34 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/scenes/init_scene.h"
#include "engine/entities/init_player.h"
#include "engine/init_game.h"
#include "utils/error.h"
#include "build.h"

t_result	init_game_entities(t_scene *scene)
{
	t_player *player;
	
	if (scene == NULL)
		return (throw_error("init_game_entities", "NULL pointer provided"));
	if (!(player = build_game_player(scene)))
		return (throw_error("init_game_entities", "init button start failed"));
	if (!build_game_ennemy(scene, player))
		return (throw_error("init_game_entities", "init button start failed"));
	scene->renderer.cam_ref = &player->cam;
	return (OK);
}
