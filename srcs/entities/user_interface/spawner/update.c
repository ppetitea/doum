/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 01:39:22 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/15 02:43:28 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/error.h"
#include "entities/ui/spawner.h"
#include "entities/entities.h"
#include "resources/textures/texture.h"

t_result	update_spawner_anchor(t_entity *entity, t_vec2i anchor)
{
	t_spawner	*spawner;

	if (entity->type != SPAWNER)
		return (throw_error("update_spawner_anchor",
			"entity provided is not a spawner"));
	spawner = (t_spawner*)entity;
	spawner->super.texture.anchor = anchor;
	return (OK);
}

t_result	update_spawner_offset(t_entity *entity, t_vec2i offset)
{
	t_spawner	*spawner;

	if (entity->type != SPAWNER)
		return (throw_error("update_spawner_offset",
			"entity provided is not a spawner"));
	spawner = (t_spawner*)entity;
	spawner->super.texture.t->offset = offset;
	return (OK);
}

t_result	update_spawner_texture_with_status(t_entity *entity)
{
	t_spawner	*spawner;
	t_vec2i		curr_offset;

	if (entity->type != SPAWNER)
		return (throw_error("update_spawner_offset",
			"entity provided is not a spawner"));
	curr_offset = entity->texture.t->offset;
	spawner = (t_spawner*)entity;
	if (spawner->super.status.is_dragged)
		spawner->super.texture.t = spawner->dragged;
	else if (spawner->super.status.is_hover)
		spawner->super.texture.t = spawner->hover;
	else
		spawner->super.texture.t = spawner->normal;
	entity->texture.t->offset = curr_offset;
	return (OK);
}
