/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 04:55:37 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/16 06:55:12 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/error.h"
#include "entities/player.h"

t_result	update_player_velocity(t_player *self, float velocity)
{
	if (self == NULL)
		return (throw_error("update_player_velocity", "NULL pointer provided"));
	self->velocity = velocity;
	return (OK);
}
t_result	update_player_life(t_player *self, float life)
{
	if (self == NULL)
		return (throw_error("update_player_life", "NULL pointer provided"));
	self->life = life;
	return (OK);
}
t_result	update_player_armor(t_player *self, float armor)
{
	if (self == NULL)
		return (throw_error("update_player_armor", "NULL pointer provided"));
	self->armor = armor;
	return (OK);
}