/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_entity.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 04:44:34 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/25 01:03:12 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entities/init_entity.h"
#include "engine/entities/update_entity.h"
#include "utils/error.h"
#include "libft.h"
#include <math.h>

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
