/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_ennemy.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 08:35:32 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/19 02:41:52 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	BUILD_ENNEMY_H
# define BUILD_ENNEMY_H

# include "libft.h"
# include "engine/resources/textures/texture.h"
# include "engine/entities/build_entity.h"
# include "engine/entities/build_player.h"

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
	t_player			*player_ref;
	t_texture			*attack;
	t_texture			*die;
}					t_ennemy;

t_ennemy			*build_ennemy(t_player *player);
t_result			build_ennemy_entity_listener(
						t_entity *self,
						t_list_head *render,
						t_list_head *storage,
						t_bool display);
t_result			build_ennemy_entity_texture(t_entity_texture *self,
						t_texture *texture, t_vec2i	anchor);

#endif
