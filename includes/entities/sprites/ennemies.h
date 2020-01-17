/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemies.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 08:35:32 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/17 17:16:51 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ENNEMIES_H
# define ENNEMIES_H

# include "libft.h"
# include "resources/textures/texture.h"
# include "entities/entities.h"
# include "entities/player.h"

typedef enum		e_ennemy_type
{
	GUNMAN,
	MONSTER
}					t_ennemy_type;

typedef struct		s_ennemy
{
	t_entity			super;
	t_ennemy_type		type;
	float				velocity;
	size_t				life;
	size_t				damages;
	float				size;
	t_oriented_textures	orientation;
	t_pos2f				*player_ref;
	t_texture			*attack;
	t_texture			*die;
}					t_ennemy;

t_ennemy	*create_ennemy(t_player *player);
t_result	build_ennemy_entity(t_entity *self, t_entity_args args);
t_result	build_ennemy_entity_texture(t_entity_texture *self,
				t_entity_texture_args args);
t_result	build_ennemy_listener(t_listener *self, t_list_head *render,
				t_list_head *storage, t_bool display);

t_result	update_ennemy_texture_by_direction(t_ennemy *ennemy);
t_result	ennemy_move(t_entity *entity);
t_result	ennemy_turn_right(t_entity *entity);
t_result	ennemy_turn_left(t_entity *entity);
t_result	ennemy_attack(t_entity *entity);
t_result	ennemy_die(t_entity *entity);

#endif
