/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 07:27:39 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/19 22:07:02 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "engine/entities/init_entity.h"
#include "utils/error.h"

t_result	toggle_display_entity(t_entity *entity)
{
	if (entity == NULL)
		return (throw_error("update_listener", "NULL pointer provided"));
	entity->status.display = !entity->status.display;
	list_del_entry(&entity->node);
	if (entity->status.display)
		list_add_entry(&entity->node, entity->status.render_list);
	else
		list_add_entry(&entity->node, entity->status.storage_list);
	return (OK);
}
