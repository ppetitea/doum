/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_trigger.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 00:10:40 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/08 02:15:17 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/resource/image/texture_init.h"
#include "engine/entity/entity_init.h"
#include "engine/component/action.h"
#include "engine/entity/entity_update.h"
#include "engine/game/game_init.h"
#include "utils/parser.h"
#include "utils/error.h"

#include <stdio.h>

t_bool		is_entity_texture_collide(t_entity_texture *e_texture, t_pos2i pos)
{
	t_pos2i	min;
	t_pos2i	max;

	min.x = e_texture->box.offset.x;
	min.y = e_texture->box.offset.y;
	max.x = min.x + e_texture->box.size.x;
	max.y = min.y + e_texture->box.size.y;
	if (pos.x < min.x || max.x < pos.x || pos.y < min.y || max.y < pos.y)
		return (FALSE);
	return (TRUE);
}

t_result	trigger_entity_action_by_hover(t_list_head *entities, t_mouse *mouse)
{
	t_entity	*entity;
	t_list_head	*pos;

	if (entities == NULL || mouse == NULL)
		return (throw_error("trigger_e_action_by_hover", "NULL pointer"));
	pos = entities;
	while ((pos = pos->next) != entities)
	{
		entity = (t_entity*)pos;
		if (entity->status.is_hoverable &&
			is_entity_texture_collide(&entity->texture, mouse->pos))
		{
			if (entity->status.is_hover == FALSE)
				trigger_actions(&entity->status.hover_start_actions);
			entity->status.is_hover = TRUE;
		}
		else
		{
			if (entity->status.is_hover)
				trigger_actions(&entity->status.hover_end_actions);
			entity->status.is_hover = FALSE;
		}
	}
	return (OK);
}

t_result	trigger_entity_action_by_select(t_list_head *entities, t_mouse *mouse)
{
	t_entity	*entity;
	t_list_head	*pos;

	if (entities == NULL || mouse == NULL)
		return (throw_error("trigger_e_action_by_select", "NULL pointer"));
	pos = entities;
	while ((pos = pos->next) != entities)
	{
		entity = (t_entity*)pos;
		if (entity->status.is_selectable)
		{
			if (is_entity_texture_collide(&entity->texture, mouse->pos))
			{
				trigger_actions(&entity->status.select_actions);
				return (OK);
			}
		}
	}
	return (ERROR);
}

t_result	trigger_entity_action_by_drag(t_list_head *entities, t_mouse *mouse)
{
	t_entity	*entity;
	t_list_head	*pos;

	if (entities == NULL || mouse == NULL)
		return (throw_error("trigger_e_action_by_drag", "NULL pointer"));
	pos = entities;
	while ((pos = pos->next) != entities)
	{
		entity = (t_entity*)pos;
		if (entity->status.is_draggable)
		{
			if (is_entity_texture_collide(&entity->texture, mouse->pos))
			{
				trigger_actions(&entity->status.drag_actions);
				entity->status.is_dragged = TRUE;
				return (OK);
			}
		}
	}
	return (ERROR);
}

t_result	trigger_entity_action_by_drop(t_list_head *entities, t_mouse *mouse)
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
			trigger_actions(&entity->status.drop_actions);
			entity->status.is_dragged = FALSE;
			return (OK);
		}
	}
	return (OK);
}
