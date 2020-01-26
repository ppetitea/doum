/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_animate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 02:04:06 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/25 02:04:32 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entity/entity_init.h"
#include "utils/error.h"

void	animate_texture(t_entity *entity)
{
	if (entity == NULL)
		throw_warning("animate", "NULL pointer provided", 3);
	else if (entity->status.display == FALSE)
		throw_warning("animate", "entity isn't display", 3);
	else
	{
		entity->texture.animation = IN_PROGRESS;
	}
}
