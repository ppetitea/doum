/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_trigger.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 00:10:40 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/08 03:47:46 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/game/game_init.h"
#include "engine/component/action.h"
#include "engine/entity/character_update.h"
#include "utils/error.h"

#include <stdio.h>

t_bool		is_character_texture_collide(t_character *character,
				t_pos2i pos, t_voxel_map_2d_config *config)
{
	t_entity_texture	*texture;
	t_pos2i				min;
	t_pos2i				max;

	texture = &character->super.texture;
	min.x = texture->box.offset.x;
	min.y = texture->box.offset.y;
	max.x = min.x + texture->box.size.x;
	max.y = min.y + texture->box.size.y;
	(void)config;
	// printf("mouse x %d y %d\n", pos.x, pos.y);
	// printf("collide %d < x < %d && %d < y < %d\n", min.x, max.x, min.y, max.y);
	if (pos.x < min.x || max.x < pos.x || pos.y < min.y || max.y < pos.y)
		return (FALSE);
	return (TRUE);
}

// t_result	trigger_character_action_by_hover(t_list_head *entities,
// 				t_mouse *mouse)
// {
// 	t_entity	*entity;
// 	t_list_head	*pos;

// 	if (entities == NULL || mouse == NULL)
// 		return (throw_error("trigger_e_action_by_hover", "NULL pointer"));
// 	pos = entities;
// 	while ((pos = pos->next) != entities)
// 	{
// 		entity = (t_entity*)pos;
// 		if (entity->status.is_hoverable &&
// 			is_character_texture_collide(&entity->texture, mouse->pos))
// 		{
// 			if (entity->status.is_hover == FALSE)
// 				trigger_actions(&entity->status.hover_start_actions);
// 			entity->status.is_hover = TRUE;
// 		}
// 		else
// 		{
// 			if (entity->status.is_hover)
// 				trigger_actions(&entity->status.hover_end_actions);
// 			entity->status.is_hover = FALSE;
// 		}
// 	}
// 	return (OK);
// }

// t_result	trigger_character_action_by_select(t_list_head *entities,
// 				t_mouse *mouse)
// {
// 	t_entity	*entity;
// 	t_list_head	*pos;

// 	if (entities == NULL || mouse == NULL)
// 		return (throw_error("trigger_e_action_by_select", "NULL pointer"));
// 	pos = entities;
// 	while ((pos = pos->next) != entities)
// 	{
// 		entity = (t_entity*)pos;
// 		if (entity->status.is_selectable)
// 		{
// 			if (is_entity_texture_collide(&entity->texture, mouse->pos))
// 			{
// 				trigger_actions(&entity->status.select_actions);
// 				return (OK);
// 			}
// 		}
// 	}
// 	return (ERROR);
// }


t_result	trigger_player_action_by_drag(t_character *player, t_mouse *mouse)
{
	t_scene		*scene;

	if (player == NULL || mouse == NULL)
		return (throw_error("trigger_c_action_by_drag", "NULL pointer"));
	if (!(scene = game_singleton(NULL)->curr_scene))
		return (throw_error("trigger_c_action_by_drag", "scene not found"));
	if (player->super.status.is_draggable && player->super.type == CHARACTER)
	{
		if (is_character_texture_collide(player, mouse->pos,
				&scene->map_render_config.drop_map))
		{
			trigger_actions(&player->super.status.drag_actions);
			player->super.status.is_dragged = TRUE;
			return (OK);
		}
	}
	return (ERROR);
}

t_result	trigger_character_action_by_drag(t_list_head *entities,
				t_mouse *mouse)
{
	t_scene		*scene;
	t_entity	*entity;
	t_character	*character;
	t_list_head	*pos;

	if (entities == NULL || mouse == NULL)
		return (throw_error("trigger_c_action_by_drag", "NULL pointer"));
	if (!(scene = game_singleton(NULL)->curr_scene))
		return (throw_error("trigger_c_action_by_drag", "scene not found"));
	pos = entities;
	while ((pos = pos->prev) != entities)
	{
		entity = (t_entity*)pos;
		if (entity->status.is_draggable && entity->type == CHARACTER)
		{
			character = (t_character*)entity;
			if (is_character_texture_collide(character, mouse->pos,
					&scene->map_render_config.drop_map))
			{
				trigger_actions(&entity->status.drag_actions);
				entity->status.is_dragged = TRUE;
				return (OK);
			}
		}
	}
	return (ERROR);
}

t_result	trigger_player_action_by_drop(t_character *player, t_mouse *mouse)
{

	if (player == NULL || mouse == NULL)
		return (throw_error("trigger_c_action_by_drop", "NULL pointer"));
	if (player->super.status.is_dragged)
	{
		player->super.status.is_dragged = FALSE;
		trigger_actions(&player->super.status.drop_actions);
		return (OK);
	}
	return (ERROR);
}

t_result	trigger_character_action_by_drop(t_list_head *entities,
				t_mouse *mouse)
{
	t_entity	*entity;
	t_list_head	*pos;

	if (entities == NULL || mouse == NULL)
		return (throw_error("trigger_e_action_by_drop", "NULL pointer"));
	pos = entities;
	while ((pos = pos->next) != entities)
	{
		entity = (t_entity*)pos;
		if (entity->status.is_dragged)
		{
			entity->status.is_dragged = FALSE;
			trigger_actions(&entity->status.drop_actions);
			return (OK);
		}
	}
	return (ERROR);
}
