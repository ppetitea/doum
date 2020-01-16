/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawner.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 04:12:43 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/15 23:34:44 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAWNER_H
# define SPAWNER_H

# include "entities/entities.h"
# include "resources/textures/texture.h"

/*
**	Entite de type spawnner
**	Se duplique lorsqu'il est drag depuis sa position initiale
*/

typedef struct		s_spawner
{
	t_entity			super;
	t_texture			*normal;
	t_texture			*hover;
	t_texture			*dragged;
	t_texture			*initial_texture;
	struct s_spawner*	(*create_spawner)(t_game*, t_texture*, t_bool);
}					t_spawner;

t_spawner			*create_spawner(t_game *game, t_texture *texture, t_bool display);
t_result			update_spawner_texture(t_entity *entity);

#endif