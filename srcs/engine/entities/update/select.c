/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 18:56:45 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/19 22:13:54 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "engine/entities/init_entity.h"
#include "engine/scenes/init_scene.h"

static t_bool	update_entity_select_status(t_scene *scene, t_entity *entity,
					t_mouse mouse)
{
	if (is_texture_collide(*entity->texture.curr, mouse.pos,
			entity->texture.anchor))
	{
		if (entity->status.is_selected == FALSE)
		{
			entity->status.is_selected = TRUE;
			if (entity->trigger.action_select != NULL)
				entity->trigger.action_select(entity);
		}
		else
			entity->status.is_selected = FALSE;
	}
	else if (entity->status.is_selected == TRUE)
		entity->status.is_selected = FALSE;
	if (entity->trigger.update_texture != NULL)
		entity->trigger.update_texture(entity);
	(void)scene;
	return (FALSE);
}

t_result	update_selectables_entities(t_scene *scene, t_list_head *entities,
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
			if (update_entity_select_status(scene, entity, mouse))
				break ;
		}
	}
	return (OK);
}

