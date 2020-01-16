/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemies.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 08:35:32 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/16 09:09:42 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ENNEMIES_H
# define ENNEMIES_H

# include "entities/entities.h"

typedef enum		e_ennemy_type
{
	GUNMAN,
	MONSTER
}					t_ennemy_type;

typedef	struct		s_rotation_animations
{
	t_texture		*right;
	t_texture		*left;
}					t_rotation_animations;

typedef	struct		s_translation_animations
{
	t_texture		*forward;
	t_texture		*backward;
}					t_translation_animations;

typedef struct		s_oriented_textures
{
	t_translation_animations	move;
	t_rotation_animations		turn;
}					t_oriented_textures;

typedef struct		s_ennemy
{
	t_entity			super;
	t_ennemy_type		type;
	float				velocity;
	size_t				life;
	size_t				damages;
	t_oriented_textures	*front;
	t_oriented_textures	*right;
	t_oriented_textures	*back;
	t_oriented_textures	*left;
}					t_ennemy;

#endif
