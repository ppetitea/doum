/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_orientation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 00:13:37 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/02 05:01:16 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entity/character_init.h"
#include "engine/game/game_init.h"
#include "utils/error.h"
#include <math.h>

static float	angle_gap(float f1, float f2)
{
	float	result;
	
	f1 += PI;
	f2 += PI;
	result =  ((f1 > f2) ? f1 - f2 : -(f2 - f1));
	if (result > PI)
		result = -(2 * PI - result);
	if (result < -PI)
		result = (result + 2 * PI);
	return (result);
}

static float	compute_angle_to_target(t_character *curr)
{
	t_character	*player;
	t_vec2f		dir_to_target;
	t_pos2f		target_pos;
	float		target_angle;
	float		character_angle;

	if (curr == NULL)
		return (throw_error("update_oriented_texture", "NULL pointer"));
	if (!(player = game_player()))
		return (throw_error("update_oriented_texture", "no player"));
	target_pos = player->camera.pos;
	dir_to_target = ft_vec2f(target_pos.x - curr->camera.pos.x,
						target_pos.y - curr->camera.pos.y);
	character_angle = atan2f(curr->camera.dir.x, curr->camera.dir.y);
	target_angle = atan2f(dir_to_target.x, dir_to_target.y);
	// printf("e %.2f p %.2f\n", character_angle / PI * 180, target_angle / PI * 180);
	return (angle_gap(character_angle, target_angle));
}

void	orientate_texture(t_character *c)
{
	t_list_head	*texture;
	float		angle;
	float		angle_abs;

	if (c == NULL)
		return (throw_warning("orientate_texture", "NULL pointer", 3));
	angle = compute_angle_to_target(c);
	angle_abs = ft_absf(angle);
	if (angle_abs <= PI / 8.0f)
		texture = &c->oriented->front;
	else if (angle_abs >= PI * (7.0f / 8.0f))
		texture = &c->oriented->back;
	else if (angle_abs <= PI * (3.0f / 8.0f))
		texture = (angle > 0) ? &c->oriented->front_r : &c->oriented->front_l;
	else if (angle_abs <= PI * (5.0f / 8.0f))
		texture = (angle > 0) ? &c->oriented->right : &c->oriented->left;
	else
		texture = (angle > 0) ? &c->oriented->back_r : &c->oriented->back_l;
	c->super.texture.curr = (t_texture*)texture->next;
	c->super.texture.curr_head = texture;
	c->super.texture.prev = (t_texture*)texture->next;
	c->super.texture.prev_head = texture;
	c->super.texture.animation = STOP;
}
