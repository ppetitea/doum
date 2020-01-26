/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_dup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 01:50:33 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/26 04:08:50 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entity/character_init.h"
#include "engine/entity/character_update.h"
#include "engine/entity/entity_update.h"
#include "utils/error.h"

t_result	copy_character_actions(t_character *src, t_character *dest)
{
	if (src == NULL || dest == NULL)
		return (throw_error("copy_character_actions", "NULL pointer provided"));
	dest->catch_weapon = src->catch_weapon;
	dest->drop_weapon = src->drop_weapon;
	dest->run = src->run;
	dest->jump = src->jump;
	dest->crawl = src->crawl;
	dest->attack = src->attack;
	dest->die = src->die;
	dest->orientate = src->orientate;
	return (OK);
}

t_result	copy_camera(t_camera *src, t_camera *dest)
{
	if (src == NULL || dest == NULL)
		return (throw_error("copy_camera", "NULL pointer provided"));
	dest->fov = src->fov;
	dest->fov_half = src->fov_half;
	dest->plan_width = src->plan_width;
	dest->plan_half = src->plan_half;
	dest->dist_to_plan = src->dist_to_plan;
	dest->height = src->height;
	dest->horizon = src->horizon;
	dest->pos = src->pos;
	dest->dir = src->dir;
	dest->to_plan = src->to_plan;
	dest->plan = src->plan;
	return (OK);
}

t_result	copy_character_weapons(t_list_head *src, t_list_head *dest)
{
	t_list_head	*pos;
	t_list_head	*next;
	t_weapon	*src_weapon;
	t_weapon	*dest_weapon;

	if (src == NULL || dest == NULL)
		return (throw_error("copy_character_weapons", "NULL pointer provided"));
	pos = src;
	next = pos->next;
	while ((pos = next) != src)
	{
		next = next->next;
		src_weapon = (t_weapon*)pos;
		if (!(dest_weapon = duplicate_weapon(src_weapon)))
			throw_warning("copy_character_weapon", "weapon_dup failed", 3);
		else
			list_add_entry(&dest_weapon->node, dest);
	}
	return (OK);
}

t_result	copy_character_hud(t_character *src, t_character *dest)
{
	if (src == NULL || dest == NULL)
		return (throw_error("copy_character_hud", "NULL pointer provided"));
	dest->type = src->type;
	dest->life = src->life;
	dest->armor = src->armor;
	dest->size = src->size;
	dest->velocity = src->velocity;
	return (OK);
}

t_character	*duplicate_character(t_character *src)
{
	t_character	*new;

	if (src == NULL)
		return (throw_null("duplicate_character", "NULL pointer provided"));
	if (!(new = init_new_character()))
		return (throw_null("duplicate_character", "init_new_character failed"));
	copy_entity(&src->super, &new->super);
	copy_character_hud(src, new);
	new->camera = src->camera;
	new->target = src->target;
	new->oriented = src->oriented;
	new->hurt_texture = src->hurt_texture;
	new->die_texture = src->die_texture;
	copy_character_weapons(&src->all_weapons, &new->all_weapons);
	copy_character_weapons(&src->weapons, &new->weapons);
	if (src->curr_weapon != NULL)
		new->curr_weapon = get_weapon_by_name(&new->weapons,
			src->curr_weapon->name);
	return (new);
}
