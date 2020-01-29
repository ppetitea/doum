/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_trigger.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 00:10:40 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/29 03:26:51 by ppetitea         ###   ########.fr       */
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

	min.x = (int)e_texture->offset.x + (int)e_texture->anchor.x;
	min.y = (int)e_texture->offset.y + (int)e_texture->anchor.y;
	max.x = (int)e_texture->curr->size.x + (int)e_texture->offset.x
			+ (int)e_texture->anchor.x;
	max.y = (int)e_texture->curr->size.y + (int)e_texture->offset.y
			+ (int)e_texture->anchor.y;
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
		if (entity->status.is_hoverable)
		{
			if (is_entity_texture_collide(&entity->texture, mouse->pos))
			{
				trigger_actions(&entity->status.hover_actions);
				return (OK);
			}
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
	return (OK);
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
