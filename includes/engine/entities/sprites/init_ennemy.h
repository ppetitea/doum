/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ennemy.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 08:35:32 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/20 00:12:30 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	INIT_ENNEMY_H
# define INIT_ENNEMY_H

# include "libft.h"
# include "engine/resources/textures/texture.h"
# include "engine/entities/init_entity.h"
# include "engine/entities/init_player.h"

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
	t_player			*player_ref;
	t_oriented_textures	orientation;
	t_list_head			attack;
	t_list_head			die;
}					t_ennemy;

t_ennemy			*init_new_ennemy(t_player *player);
t_result			overwrite_ennemy_entity_listener(
						t_entity *self,
						t_list_head *render,
						t_list_head *storage,
						t_bool display);
t_result			overwrite_ennemy_entity_texture(t_entity_texture *self,
						t_list_head *texture_head, t_vec2i	anchor);
t_result			overwrite_ennemy_fight_params(t_ennemy *self,
						size_t damages, size_t life, float velocity);
t_result			overwrite_ennemy_coordinates(t_ennemy *self, t_vec2f pos,
						t_vec2f dir);

#endif
