/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 18:56:45 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/16 05:53:15 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "game.h"
#include "entities/entities.h"

static t_bool	update_entity_select_status(t_game *game, t_entity *entity,
					t_mouse mouse)
{
	if (is_texture_collide(*entity->texture.t, mouse.pos,
			entity->texture.anchor))
	{
		if (entity->status.is_selected == FALSE)
		{
			entity->status.is_selected = TRUE;
			if (entity->status.action_select != NULL)
				entity->status.action_select(game, entity);
		}
		else
			entity->status.is_selected = FALSE;
	}
	else if (entity->status.is_selected == TRUE)
		entity->status.is_selected = FALSE;
	if (entity->texture.update_texture != NULL)
		entity->texture.update_texture(entity);
	return (FALSE);
}

t_result	update_selectables_entities(t_game *game, t_list_head *entities,
				t_mouse mouse)
{
	t_list_head		*pos;
	t_list_head		*next;
	t_entity		*entity;

	pos = entities;
	next = pos->next;
	while ((pos = next) != entities)
	{
		next = next->next;
		entity = (t_entity*)pos;
		if (entity->status.is_selectable)
		{
			if (update_entity_select_status(game, entity, mouse))
				break ;
		}
	}
	return (OK);
}

