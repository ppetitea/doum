/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ennemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 11:25:44 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/20 00:12:16 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/error.h"
#include "engine/entities/init_player.h"
#include "engine/entities/init_entity.h"
#include "engine/entities/sprites/init_ennemy.h"

static void	init_ennemy_textures(t_ennemy *self)
{
	if (self == NULL)
		return (throw_void("set_ennemy_texture_to_null", "NULL pointer"));
	init_list_head(&self->orientation.front);
	init_list_head(&self->orientation.front_r);
	init_list_head(&self->orientation.front_l);
	init_list_head(&self->orientation.right);
	init_list_head(&self->orientation.back);
	init_list_head(&self->orientation.back_r);
	init_list_head(&self->orientation.back_l);
	init_list_head(&self->orientation.left);
	init_list_head(&self->attack);
	init_list_head(&self->die);
}

t_ennemy	*init_new_ennemy(t_player *player)
{
	t_ennemy	*self;

	if (player == NULL)
		return (throw_null("init_new_ennemy", "NULL pointer provided"));
	if (!(self = (t_ennemy*)malloc(sizeof(t_ennemy))))
		return (throw_null("init_new_ennemy", "malloc failed"));
	if (!init_entity(&self->super, ENNEMY))
		return (throw_null("init_new_ennemy", "init entity failed"));
	init_ennemy_textures(self);
	self->damages = 10;
	self->life = 100;
	self->size = 10;
	self->velocity = 1.0f;
	self->player_ref = player;
	return (self);
}

t_result	overwrite_ennemy_fight_params(t_ennemy *self, size_t damages,
				size_t life, float velocity)
{
	if (self == NULL)
		return (throw_error("overwrite_ennemy_fight_params", "NULL pointer"));
	self->damages = damages;
	self->life = life;
	self->velocity = velocity;
	return (OK);
}

t_result	overwrite_ennemy_coordinates(t_ennemy *self, t_vec2f pos,
				t_vec2f dir)
{
	if (self == NULL)
		return (throw_error("overwrite_ennemy_coor", "NULL pointer provided"));
	self->super.pos = pos;
	self->super.dir = dir;
	return (OK);
}


