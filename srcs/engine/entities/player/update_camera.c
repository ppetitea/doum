/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 01:11:36 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/20 02:54:52 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/error.h"
#include "engine/entities/init_player.h"
#include <math.h>

# include <stdio.h>

t_result	rotate_camera_left(t_entity *entity)
{
	t_player *player;

	if (entity == NULL)
		return (throw_error("entity_turn_right", "NULL pointer provided"));
	if (entity->type != PLAYER)
		return (throw_error("entity_turn_right", "entity isn't player"));
	player = (t_player*)entity;
	*player->cam.dir = to_vtx(rotate(-1.0f / 180.0f * PI), *player->cam.dir);
	player->cam.to_plan = vec2f_scalar(*player->cam.dir, player->cam.dist_to_plan);
	player->cam.plan = ft_vec2f(-player->cam.dir->y, player->cam.dir->x);
	return (OK);
}
t_result	rotate_camera_right(t_entity *entity)
{
	t_player *player;

	if (entity == NULL)
		return (throw_error("entity_turn_right", "NULL pointer provided"));
	if (entity->type != PLAYER)
		return (throw_error("entity_turn_right", "entity isn't player"));
	player = (t_player*)entity;
	*player->cam.dir = to_vtx(rotate(1.0f / 180.0f * PI), *player->cam.dir);
	player->cam.to_plan = vec2f_scalar(*player->cam.dir, player->cam.dist_to_plan);
	player->cam.plan = ft_vec2f(-player->cam.dir->y, player->cam.dir->x);
	return (OK);
}

t_result	translate_camera_forward(t_entity *entity)
{
	t_player	*player;
	t_camera	cam;
	t_vec2f		move;

	if (entity == NULL)
		return (throw_error("translate_cam forward", "NULL pointer provided"));
	if (entity->type != PLAYER)
		return (throw_error("translate_cam forward", "entity isn't player"));
	player = (t_player*)entity;
	cam = player->cam;
	move = vec2f_scalar(ft_vec2f(cam.dir->x, cam.dir->y), player->velocity);
	*player->cam.pos = vec2f_add(*cam.pos, move);
	return (OK);
}

t_result	translate_camera_right(t_entity *entity)
{
	t_player	*player;
	t_camera	cam;
	t_vec2f		move;

	if (entity == NULL)
		return (throw_error("translate_cam right", "NULL pointer provided"));
	if (entity->type != PLAYER)
		return (throw_error("translate_cam right", "entity isn't player"));
	player = (t_player*)entity;
	cam = player->cam;
	move = vec2f_scalar(ft_vec2f(-cam.dir->y, cam.dir->x), player->velocity);
	*player->cam.pos = vec2f_add(*cam.pos, move);
	return (OK);
}

t_result	translate_camera_left(t_entity *entity)
{
	t_player	*player;
	t_camera	cam;
	t_vec2f		move;

	if (entity == NULL)
		return (throw_error("translate_cam left", "NULL pointer provided"));
	if (entity->type != PLAYER)
		return (throw_error("translate_cam left", "entity isn't player"));
	player = (t_player*)entity;
	cam = player->cam;
	move = vec2f_scalar(ft_vec2f(cam.dir->y, -cam.dir->x), player->velocity);
	*player->cam.pos = vec2f_add(*cam.pos, move);
	return (OK);
}

t_result	translate_camera_backward(t_entity *entity)
{
	t_player	*player;
	t_camera	cam;
	t_vec2f		move;

	if (entity == NULL)
		return (throw_error("translate_cam left", "NULL pointer provided"));
	if (entity->type != PLAYER)
		return (throw_error("translate_cam left", "entity isn't player"));
	player = (t_player*)entity;
	cam = player->cam;
	move = vec2f_scalar(ft_vec2f(-cam.dir->x, -cam.dir->y), player->velocity);
	*player->cam.pos = vec2f_add(*cam.pos, move);
	return (OK);
}
