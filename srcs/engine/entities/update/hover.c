/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hover.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 18:56:45 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/16 05:52:58 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "game.h"
#include "entities/entities.h"

static t_bool	update_entity_hover_status(t_entity *entity, t_mouse mouse)
{
	if (is_texture_collide(*entity->texture.t, mouse.pos,
			entity->texture.anchor))
	{
		entity->status.is_hover = TRUE;
		if (entity->texture.update_texture != NULL)
			entity->texture.update_texture(entity);
	}
	else if (entity->status.is_hover == TRUE)
	{
		entity->status.is_hover = FALSE;
		if (entity->texture.update_texture != NULL)
			entity->texture.update_texture(entity);
	}
	return (FALSE);
}

t_result	update_hoverables_entities(t_list_head *entities, t_mouse mouse)
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
		if (entity->status.is_hoverable)
		{
			if (update_entity_hover_status(entity, mouse))
				break ;
		}
	}
	return (OK);
}
