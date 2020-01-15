/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 07:02:47 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/15 07:11:15 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities/entities.h"
#include "utils/error.h"

t_result	trigger_animation(t_entity *entity)
{
	if (entity == NULL)
		return (throw_error("update_listener", "NULL pointer provided"));
	if (entity->status.display)
		entity->texture.animation = IN_PROGRESS;
	return (OK);
}