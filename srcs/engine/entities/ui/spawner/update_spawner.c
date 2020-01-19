/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_spawner.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 02:39:58 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/18 18:08:39 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/error.h"
#include "engine/entities/ui/build_spawner.h"

t_result	update_spawner_texture(t_entity *entity)
{
	t_spawner	*spawner;
	t_vec2i		curr_offset;
	
	if (entity->type != SPAWNER)
		return (throw_error("update_spawner_offset",
			"entity provided is not a spawner"));
	curr_offset = entity->texture.curr->offset;
	spawner = (t_spawner*)entity;
	if (spawner->super.status.is_dragged)
		spawner->super.texture.curr = spawner->dragged;
	else if (spawner->super.status.is_hover)
		spawner->super.texture.curr = spawner->hover;
	else
		spawner->super.texture.curr = spawner->normal;
	entity->texture.curr->offset = curr_offset;
	return (OK);
}