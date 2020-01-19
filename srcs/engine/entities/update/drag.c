/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dragg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 18:56:45 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/13 20:28:11 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "engine/scenes/init_scene.h"
#include "engine/entities/entities.h"

static void	set_entity_draggable_on(t_scene *scene, t_entity *entity,
	t_mouse mouse)
{
	t_vec2i			offset;
	
	offset.x = entity->texture.curr->offset.x - mouse.pos.x;
	offset.y = entity->texture.curr->offset.y - mouse.pos.y;
	entity->texture.curr->offset = offset;
	entity->texture.anchor = mouse.pos;
	entity->status.is_dragged = TRUE;
	if (entity->trigger.update_texture != NULL)
		entity->trigger.update_texture(entity);
	if (entity->trigger.action_drag != NULL)
		entity->trigger.action_drag(entity);
	(void)scene;
}

static void	set_entity_draggable_off(t_entity *entity, t_mouse mouse)
{
	t_vec2i			offset;

	offset.x = mouse.pos.x + entity->texture.curr->offset.x;
	offset.y = mouse.pos.y + entity->texture.curr->offset.y;
	entity->texture.curr->offset = offset;
	entity->texture.anchor = ft_vec2i(0, 0);
	entity->status.is_dragged = FALSE;
	if (entity->trigger.update_texture != NULL)
		entity->trigger.update_texture(entity);
}

static t_bool	update_entity_drag_status(t_scene *scene, t_entity *entity,
	t_mouse mouse)
{
	t_entity_texture	texture;

	texture = entity->texture;
	if (entity->status.is_dragged == TRUE && mouse.drag == FALSE)
		set_entity_draggable_off(entity, mouse);		
	else if (is_texture_collide(*texture.curr, mouse.pos, texture.anchor))
	{
		set_entity_draggable_on(scene, entity, mouse);
		return (TRUE);
	}
	return (FALSE);
}

t_result	update_draggables_entities(t_scene *scene, t_list_head *entities, t_mouse mouse)
{
	t_list_head		*pos;
	t_list_head		*prev;
	t_entity		*entity;

	pos = entities;
	prev = pos->prev;
	while ((pos = prev) != entities)
	{
		prev = prev->prev;
		entity = (t_entity*)pos;
		if (entity->status.is_draggable)
		{
			if (update_entity_drag_status(scene, entity, mouse))
			{
				list_del_entry(&entity->node);
				list_add_entry(&entity->node, entities);
			 	break ;
			}
		}
	}
	return (OK);
}
