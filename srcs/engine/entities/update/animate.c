/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 07:02:47 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/17 21:09:00 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities/entities.h"
#include "entities/sprites/ennemies.h"
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

t_result	update_entity_texture(t_entity *entity, t_texture *texture)
{
	if (entity == NULL || texture == NULL)
		return (throw_error("update_listener", "NULL pointer provided"));
	if (entity->texture.t_head != texture)
	{
		entity->texture.t = texture;
		entity->texture.t_head = texture;
		entity->texture.t_last = texture;
		timespec_get(&entity->texture.last, TIME_UTC);
	}
	return (OK);
}