/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 22:59:06 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/19 00:42:37 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/error.h"
#include "engine/entities/build_player.h"
#include "engine/entities/entities.h"

t_player	*build_player()
{
	t_player	*self;

	if (!(self = (t_player*)malloc(sizeof(t_player))))
		return (throw_null("build_player", "malloc failed"));
	if (!build_entity(&self->super, PLAYER));
		return (throw_null("build_player", "build entity failed"));
	self->weapons = NULL;
	self->weapons_storage = NULL;
	self->velocity = 2.0f;
	self->life = 100;
	self->armor = 42;
	self->cam.dir = &self->super.dir;
	self->cam.pos = &self->super.pos;
	// self->catch_weapon = NULL;
	// self->drop_weapon = NULL;
	return (self);
}


