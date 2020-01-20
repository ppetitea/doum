/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_spawner.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 04:12:43 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/20 05:23:23 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_SPAWNER_H
# define INIT_SPAWNER_H

# include "engine/resources/textures/texture.h"
# include "engine/entities/init_entity.h"

/*
**	Entite de type spawnner
**	Se duplique lorsqu'il est drag depuis sa position initiale
*/

typedef struct		s_spawner
{
	t_entity			super;
	t_texture			normal;
	t_texture			hover;
	t_texture			dragged;
	t_texture			save;
	t_result			(*create_spawner_with_another)(struct s_spawner*);
}					t_spawner;

t_spawner			*init_new_spawner();
t_result			init_spawner_textures(
						t_spawner *self,
						t_bitmap_texture bmp,
						t_usize size, t_vec2i offset);
t_result			overwrite_spawner_entity_texture(t_entity_texture *self,
						t_texture *texture, t_vec2i	anchor);
t_result			overwrite_spawner_entity_listener(
						t_entity *self,
						t_list_head *render,
						t_list_head *storage,
						t_bool display);
t_result			overwrite_spawner_entity_actions(t_entity_actions *self);
t_result			duplicate_spawner(t_entity *entity);


#endif