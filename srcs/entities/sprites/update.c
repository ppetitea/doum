/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 03:28:38 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/15 23:42:46 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "entities/sprites/sprites.h"
#include "utils/error.h"

t_result	update_sprite_texture(t_entity *entity)
{
	if (entity->type != SPRITE)
		return (throw_error("update_sprite_texture", "must provide sprite"));
	return (OK);
}
