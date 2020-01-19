/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_ennemy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 12:03:19 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/20 00:59:26 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entities/update_entity.h"
#include "engine/entities/sprites/init_ennemy.h"
#include "engine/entities/entities.h"
#include "engine/entities/init_player.h"
#include "utils/error.h"
#include "utils/matrix.h"
#include "libft.h"
#include <math.h>

#include <stdio.h>

static float	compute_angle_to_player(t_ennemy *ennemy)
{
	float	angle_to_player;
	t_vec2f	dir_to_player;
	t_pos2f	player_pos;

	if (ennemy == NULL)
		return (throw_error("update_ennemy_texture", "NULL pointer provided"));
	player_pos = ennemy->player_ref->super.pos;
	dir_to_player = ft_vec2f(player_pos.x - ennemy->super.pos.x,
						player_pos.y - ennemy->super.pos.y);
	angle_to_player = atan2f(ennemy->super.dir.x, ennemy->super.dir.y)
					 - atan2f(dir_to_player.x, dir_to_player.y);
	return (angle_to_player);
}

static void	texture_by_side(t_ennemy *ennemy, t_list_head *right,
				t_list_head *left, float angle)
{
	t_list_head	*texture_head;
	
	texture_head = (angle > 0) ? right : left;
	update_entity_texture(&ennemy->super, texture_head);
}

t_result	update_ennemy_texture_by_direction(t_ennemy *ennemy)
{
	t_oriented_textures		*sides;
	float					angle;

	if (ennemy == NULL)
		return (throw_error("update_ennemy_texture", "NULL pointer provided"));
	sides = &ennemy->orientation;
	angle = compute_angle_to_player(ennemy);					
	if (ft_absf(angle) <= PI / 8.0f)
		update_entity_texture(&ennemy->super, &sides->front);
	else if (ft_absf(angle) >= PI * (7.0f / 8.0f))
		update_entity_texture(&ennemy->super, &sides->back);
	else if (ft_absf(angle) <= PI * (3.0f / 8.0f))
		texture_by_side(ennemy, &sides->front_r, &sides->front_l, angle);
	else if (ft_absf(angle) <= PI * (5.0f / 8.0f))
		texture_by_side(ennemy, &sides->right, &sides->left, angle);
	else if (angle > 0)
		update_entity_texture(&ennemy->super, &sides->back_r);
	else
		update_entity_texture(&ennemy->super, &sides->back_l);
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
	ennemy->super.texture.curr = (t_texture*)ennemy->attack.next;
	ennemy->super.texture.curr_head = &ennemy->attack;
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
	ennemy->super.texture.curr = (t_texture*)ennemy->die.next;
	ennemy->super.texture.curr_head = &ennemy->die;
	return (OK);
}
