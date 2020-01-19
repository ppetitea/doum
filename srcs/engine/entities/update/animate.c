/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 07:02:47 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/19 23:31:11 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entities/init_entity.h"
#include "engine/entities/update_entity.h"
#include "engine/entities/sprites/init_ennemy.h"
#include "engine/entities/sprites/update_ennemy.h"
#include "utils/error.h"
#include "utils/matrix.h"

t_result	trigger_animation(t_entity *entity)
{
	if (entity == NULL)
		return (throw_error("update_listener", "NULL pointer provided"));
	if (entity->status.display)
		entity->texture.animation = IN_PROGRESS;
	return (OK);
}

t_result	update_entity_texture(t_entity *entity, t_list_head *texture_head)
{
	if (entity == NULL || texture_head == NULL)
		return (throw_error("update_listener", "NULL pointer provided"));
	if (entity->texture.curr_head != texture_head)
	{
		entity->texture.curr = (t_texture*)texture_head->next;
		entity->texture.curr_head = texture_head;
		entity->texture.prev = (t_texture*)texture_head->next;
		entity->texture.prev_head = texture_head;
		timespec_get(&entity->texture.last, TIME_UTC);
	}
	return (OK);
}