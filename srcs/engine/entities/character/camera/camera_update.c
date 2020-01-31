/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 01:11:36 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/31 00:59:52 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entity/character_update.h"
#include "engine/entity/character_init.h"
#include "engine/component/action.h"
#include "engine/game/game_init.h"
#include "utils/matrix.h"
#include "utils/error.h"
#include "libft.h"
#include <math.h>

# include <stdio.h>

t_result	rotate_camera_left(t_entity *entity)
{
	t_character *character;
	t_camera	*cam;

	if (entity == NULL)
		return (throw_error("entity_turn_right", "NULL pointer provided"));
	if (entity->type != CHARACTER)
		return (throw_error("entity_turn_right", "entity isn't character"));
	character = (t_character*)entity;
	cam = &character->camera;
	cam->dir = to_vtx(rotate(-2.0f / 180.0f * PI), cam->dir);
	cam->start = to_vtx(rotate(-cam->fov_half), cam->dir);
	cam->end = to_vtx(rotate(cam->fov_half), cam->dir);
	cam->to_plan = vec2f_scalar(cam->dir, cam->dist_to_plan);
	cam->plan = ft_vec2f(-cam->dir.y, cam->dir.x);
	return (OK);
}

t_result	rotate_camera_right(t_entity *entity)
{
	t_character *character;
	t_camera	*cam;

	if (entity == NULL)
		return (throw_error("entity_turn_right", "NULL pointer provided"));
	if (entity->type != CHARACTER)
		return (throw_error("entity_turn_right", "entity isn't character"));
	character = (t_character*)entity;
	cam = &character->camera;
	cam->dir = to_vtx(rotate(2.0f / 180.0f * PI), cam->dir);
	cam->start = to_vtx(rotate(-cam->fov_half), cam->dir);
	cam->end = to_vtx(rotate(cam->fov_half), cam->dir);
	cam->to_plan = vec2f_scalar(cam->dir, cam->dist_to_plan);
	cam->plan = ft_vec2f(-cam->dir.y, cam->dir.x);
	return (OK);
}

t_result	rotate_camera(void *game_resource, t_resource_type resource_type,
					t_dnon_object *args)
{
	t_game	*game;

	if (game_resource == NULL || args == NULL)
		return (throw_error("rotate_camera", "NULL pointer provided"));
	if (resource_type != R_GAME)
		return (throw_error("rotate_camera", "resource must be game instance"));
	game = (t_game*)game_resource;
	if (game->curr_map == NULL)
		return (throw_error("rotate_camera", "curr_map is NULL"));
	if (game->curr_map->character_ref == NULL)
		return (throw_error("rotate_camera", "curr_character is NULL"));
	if (get_int_value_by_key(args, "right", 0))
		rotate_camera_right(&game->curr_map->character_ref->super);
	else if (get_int_value_by_key(args, "left", 0))
		rotate_camera_left(&game->curr_map->character_ref->super);
	else
		return (throw_error("rotate_camera", "args must be left or right"));
	return (OK);
}

t_result	elevate_camera(t_entity *entity)
{
	t_character	*character;

	if (entity == NULL)
		return (throw_error("translate_cam forward", "NULL pointer provided"));
	if (entity->type != CHARACTER)
		return (throw_error("translate_cam forward", "entity isn't character"));
	character = (t_character*)entity;
	character->camera.height += 10.0f * character->velocity;
	return (OK);
}

t_result	lower_camera(t_entity *entity)
{
	t_character	*character;

	if (entity == NULL)
		return (throw_error("translate_cam forward", "NULL pointer provided"));
	if (entity->type != CHARACTER)
		return (throw_error("translate_cam forward", "entity isn't character"));
	character = (t_character*)entity;
	if (character->camera.height - 10.0f * character->velocity > 0)
		character->camera.height -= 10.0f * character->velocity;
	return (OK);
}

t_result	translate_camera_forward(t_entity *entity)
{
	t_character	*character;
	t_camera	*cam;
	t_vec2f		move;

	if (entity == NULL)
		return (throw_error("translate_cam forward", "NULL pointer provided"));
	if (entity->type != CHARACTER)
		return (throw_error("translate_cam forward", "entity isn't character"));
	character = (t_character*)entity;
	cam = &character->camera;
	move = vec2f_scalar(ft_vec2f(cam->dir.x, cam->dir.y), character->velocity);
	cam->pos = vec2f_add(cam->pos, move);
	return (OK);
}

t_result	translate_camera_right(t_entity *entity)
{
	t_character	*character;
	t_camera	*cam;
	t_vec2f		move;

	if (entity == NULL)
		return (throw_error("translate_cam right", "NULL pointer provided"));
	if (entity->type != CHARACTER)
		return (throw_error("translate_cam right", "entity isn't character"));
	character = (t_character*)entity;
	cam = &character->camera;
	move = vec2f_scalar(ft_vec2f(-cam->dir.y, cam->dir.x), character->velocity);
	cam->pos = vec2f_add(cam->pos, move);
	return (OK);
}

t_result	translate_camera_left(t_entity *entity)
{
	t_character	*character;
	t_camera	*cam;
	t_vec2f		move;

	if (entity == NULL)
		return (throw_error("translate_cam left", "NULL pointer provided"));
	if (entity->type != CHARACTER)
		return (throw_error("translate_cam left", "entity isn't character"));
	character = (t_character*)entity;
	cam = &character->camera;
	move = vec2f_scalar(ft_vec2f(cam->dir.y, -cam->dir.x), character->velocity);
	cam->pos = vec2f_add(cam->pos, move);
	return (OK);
}

t_result	translate_camera_backward(t_entity *entity)
{
	t_character	*character;
	t_camera	*cam;
	t_vec2f		move;

	if (entity == NULL)
		return (throw_error("translate_cam left", "NULL pointer provided"));
	if (entity->type != CHARACTER)
		return (throw_error("translate_cam left", "entity isn't character"));
	character = (t_character*)entity;
	cam = &character->camera;
	move = vec2f_scalar(ft_vec2f(-cam->dir.x, -cam->dir.y), character->velocity);
	cam->pos = vec2f_add(cam->pos, move);
	return (OK);
}

t_result	translate_camera(void *game_resource, t_resource_type resource_type,
					t_dnon_object *args)
{
	t_game	*game;
	
	if (game_resource == NULL || args == NULL)
		return (throw_error("translate_camera", "NULL pointer provided"));
	if (resource_type != R_GAME)
		return (throw_error("translate_camera", "resource must be game"));
	game = (t_game*)game_resource;
	if (game->curr_map == NULL)
		return (throw_error("translate_camera", "curr_map is NULL"));
	if (game->curr_map->character_ref == NULL)
		return (throw_error("translate_camera", "curr_character is NULL"));
	if (get_int_value_by_key(args, "front", 0))
		translate_camera_forward(&game->curr_map->character_ref->super);
	else if (get_int_value_by_key(args, "left", 0))
		translate_camera_left(&game->curr_map->character_ref->super);
	else if (get_int_value_by_key(args, "back", 0))
		translate_camera_backward(&game->curr_map->character_ref->super);
	else if (get_int_value_by_key(args, "right", 0))
		translate_camera_right(&game->curr_map->character_ref->super);
	else
		return (throw_error("translate_camera", "wrong args detected"));
	return (OK);
}