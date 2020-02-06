/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 00:36:19 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/06 19:45:55 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/game/game_init.h"
#include "engine/entity/entity_update.h"
#include "utils/error.h"
#include "ft/str.h"

t_entity	*get_entity_by_name(t_list_head *entities, char *name)
{
	t_list_head		*pos;
	t_list_head		*next;
	t_entity		*entity;

	if (entities == NULL || name == NULL)
		return (throw_null("get_entity_by_name", "NULL pointer provided"));
	pos = entities;
	next = pos->next;
	while ((pos = next) != entities)
	{
		next = next->next;
		entity = (t_entity*)pos;
		if (!ft_strcmp(entity->name, name))
			return (entity);
	}
	throw_warning("get_entity_by_name:", name, 2);
	throw_warning("entity not found:", name, 2);
	return (NULL);
}
