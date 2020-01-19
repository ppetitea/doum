/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_ennemy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 12:03:19 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/19 02:53:15 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities/update_entities.h"
#include "entities/sprites/ennemies.h"
#include "entities/entities.h"
#include "entities/player.h"
#include "utils/error.h"
#include "utils/matrix.h"
#include "libft.h"
#include <math.h>

#include <stdio.h>

static float	float_abs(float n)
{
	return (n > 0 ? n : -n);
}

t_result	update_ennemy_texture_by_direction(t_ennemy *ennemy)
{
	float	angle_to_player;
	t_vec2f	dir_to_player;

	if (ennemy == NULL)
		return (throw_error("update_ennemy_texture", "NULL pointer provided"));
	dir_to_player = ft_vec2f(ennemy->player_ref->x - ennemy->super.pos.x,
		ennemy->player_ref->y - ennemy->super.pos.y);
	angle_to_player = atan2f(ennemy->super.dir.x, ennemy->super.dir.y)
					 - atan2f(dir_to_player.x, dir_to_player.y);
					
	// printf("angle %.2f\n", angle_to_player / PI * 180.0f);////////////////////////
	if (float_abs(angle_to_player) <= PI / 8.0f)
		update_entity_texture(&ennemy->super, ennemy->orientation.front);
	else if (float_abs(angle_to_player) >= PI * (7.0f / 8.0f))
		update_entity_texture(&ennemy->super, ennemy->orientation.back);
	else if (float_abs(angle_to_player) <= PI * (3.0f / 8.0f))
	{
		if (angle_to_player > 0)
			update_entity_texture(&ennemy->super, ennemy->orientation.front_r);
		else
			update_entity_texture(&ennemy->super, ennemy->orientation.front_l);
	}
	else if (float_abs(angle_to_player) <= PI * (5.0f / 8.0f))
	{
		if (angle_to_player > 0)
			update_entity_texture(&ennemy->super, ennemy->orientation.right);
		else
			update_entity_texture(&ennemy->super, ennemy->orientation.left);
	}
	else if (angle_to_player > 0)
		update_entity_texture(&ennemy->super, ennemy->orientation.back_r);
	else
		update_entity_texture(&ennemy->super, ennemy->orientation.back_l);
	return (OK);
}

t_result	update_ennemy_texture(t_entity *entity)
{
	t_ennemy	*ennemy;
	
	if (entity == NULL)
		return (throw_error("entity_turn_right", "NULL pointer provided"));
	if (entity->type != ENNEMY)
		return (throw_error("entity_turn_right", "entity isn't ennemy"));
	ennemy = (t_ennemy*)entity;
	update_ennemy_texture_by_direction(ennemy);
	return (OK);
}

t_result	ennemy_turn_right(t_entity *entity)
{
	t_ennemy	*ennemy;
	float		angle;
	
	if (entity == NULL)
		return (throw_error("entity_turn_right", "NULL pointer provided"));
	if (entity->type != ENNEMY)
		return (throw_error("entity_turn_right", "entity isn't ennemy"));
	ennemy = (t_ennemy*)entity;
	angle = 1.0f * ennemy->velocity / 180.0f * PI;
	entity->dir = to_vtx(rotate(angle), entity->dir);
	update_ennemy_texture_by_direction((t_ennemy*)entity);
	return (OK);
}

t_result	ennemy_turn_left(t_entity *entity)
{
	t_ennemy	*ennemy;
	float		angle;
	
	if (entity == NULL)
		return (throw_error("entity_turn_right", "NULL pointer provided"));
	if (entity->type != ENNEMY)
		return (throw_error("entity_turn_right", "entity isn't ennemy"));
	ennemy = (t_ennemy*)entity;
	angle = -1.0f * ennemy->velocity / 180.0f * PI;
	entity->dir = to_vtx(rotate(angle), entity->dir);
	update_ennemy_texture_by_direction((t_ennemy*)entity);
	return (OK);
}

t_result	ennemy_move_forward(t_entity *entity)
{
	t_ennemy *ennemy;

	if (entity == NULL)
		return (throw_error("entity_turn_right", "NULL pointer provided"));
	if (entity->type != ENNEMY)
		return (throw_error("entity_turn_right", "entity isn't ennemy"));
	ennemy = (t_ennemy*)entity;
	update_ennemy_texture_by_direction((t_ennemy*)entity);
	ennemy->super.pos = vec2f_add(ennemy->super.pos,
		vec2f_scalar(ennemy->super.dir, 1.2f * ennemy->velocity));
	ennemy->super.texture.animation = IN_PROGRESS;
	return (OK);
}

t_result	ennemy_move_backward(t_entity *entity)
{
	t_ennemy *ennemy;

	if (entity == NULL)
		return (throw_error("entity_turn_right", "NULL pointer provided"));
	if (entity->type != ENNEMY)
		return (throw_error("entity_turn_right", "entity isn't ennemy"));
	ennemy = (t_ennemy*)entity;
	update_ennemy_texture_by_direction((t_ennemy*)entity);
	ennemy->super.pos = vec2f_add(ennemy->super.pos,
		vec2f_scalar(ennemy->super.dir, -1.2f * ennemy->velocity));
	ennemy->super.texture.animation = IN_PROGRESS;
	return (OK);
}

t_result	ennemy_attack(t_entity *entity)
{
	t_ennemy *ennemy;

	if (entity == NULL)
		return (throw_error("entity_turn_right", "NULL pointer provided"));
	if (entity->type != ENNEMY)
		return (throw_error("entity_turn_right", "entity isn't ennemy"));
	ennemy = (t_ennemy*)entity;
	update_ennemy_texture_by_direction((t_ennemy*)entity);
	ennemy->super.texture.animation = EPHEMERAL;
	ennemy->super.texture.t = ennemy->attack;
	ennemy->super.texture.t_head = ennemy->attack;
	return (OK);
}
t_result	ennemy_die(t_entity *entity)
{
	t_ennemy *ennemy;

	if (entity == NULL)
		return (throw_error("entity_turn_right", "NULL pointer provided"));
	if (entity->type != ENNEMY)
		return (throw_error("entity_turn_right", "entity isn't ennemy"));
	ennemy = (t_ennemy*)entity;
	update_ennemy_texture_by_direction((t_ennemy*)entity);
	ennemy->super.texture.animation = EPHEMERAL;
	ennemy->super.texture.t = ennemy->die;
	ennemy->super.texture.t_head = ennemy->die;
	return (OK);
}
