/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entities_dup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 03:40:51 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/26 04:02:50 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entity/character_update.h"
#include "engine/entity/character_init.h"
#include "engine/entity/entity_update.h"
#include "engine/game/game_init.h"
#include "utils/error.h"
 
t_entity	*duplicate_entity_by_type(t_entity *src)
{
	if (src == NULL)
		return (throw_null("duplicate_entity_by_type", "NULL pointer"));
	if (src->type == CHARACTER)
		return ((t_entity*)duplicate_character((t_character*)src));
	else if (src->type == UI)
		return (duplicate_entity(src));
	else
		return (throw_null("duplicate_entity_by_type", "unknow type detected"));
}
