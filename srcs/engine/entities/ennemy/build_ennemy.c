/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_ennemy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 11:25:44 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/19 02:27:06 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/error.h"
#include "engine/entities/build_player.h"
#include "engine/entities/build_entity.h"
#include "engine/entities/sprites/build_ennemy.h"

static void	set_ennemy_textures_to_null(t_ennemy *self)
{
	if (self == NULL)
		return (throw_void("set_ennemy_texture_to_null", "NULL pointer"));
	self->orientation.front = NULL;
	self->orientation.front_r = NULL;
	self->orientation.front_l = NULL;
	self->orientation.right = NULL;
	self->orientation.back = NULL;
	self->orientation.back_r = NULL;
	self->orientation.back_l = NULL;
	self->orientation.left = NULL;
	self->attack = NULL;
	self->die = NULL;
}

t_ennemy	*build_ennemy(t_player *player)
{
	t_ennemy	*self;

	if (player == NULL)
		return (throw_null("build_ennemy", "NULL pointer provided"));
	if (!(self = (t_ennemy*)malloc(sizeof(t_ennemy))))
		return (throw_null("build_ennemy", "malloc failed"));
	if (!build_entity(&self->super, ENNEMY));
		return (throw_null("build_ennemy", "build entity failed"));
	set_ennemy_textures_to_null(self);
	self->damages = 10;
	self->life = 100;
	self->size = 10;
	self->velocity = 1.0f;
	self->player_ref = &player;
	return (self);
}