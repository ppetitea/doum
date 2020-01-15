/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 03:29:06 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/15 06:00:04 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITES_H
# define SPRITES_H

# include "libft.h"
# include "resources/textures/texture.h"
# include "entities/entities.h"

/*
**	Entite de type sprite
**	
*/

typedef struct		s_sprite_textures
{
	t_texture		*front;
	t_texture		*right;
	t_texture		*back;
	t_texture		*left;
}					t_sprite_textures;

typedef struct		s_sprite
{
	t_entity			super;
	t_sprite_textures	textures;
}					t_sprite;

t_sprite			*create_sprite(t_entity_args entity_args);
void				entity_sprite_args1(t_entity_args *self, t_texture *texture,
						t_animation_status animation, t_vec2i anchor);
void				entity_sprite_args2(t_entity_args *self, t_vec2f pos,
						t_vec2f dir, t_bool display);

t_result			update_sprite_anchor(t_entity *component, t_vec2i anchor);
t_result			update_sprite_offset(t_entity *component, t_vec2i offset);
t_result			update_sprite_texture_with_status(t_entity *component);

#endif