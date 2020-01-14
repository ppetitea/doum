/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 03:29:06 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/14 07:28:17 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITES_H
# define SPRITES_H

# include "libft.h"
# include "textures/texture.h"
# include "user_interface/ui.h"

typedef struct		s_sprite_textures
{
	t_texture		*north;
	t_texture		*north_east;
	t_texture		*east;
	t_texture		*south_east;
	t_texture		*south;
	t_texture		*south_west;
	t_texture		*west;
	t_texture		*north_west;
}					t_sprite_textures;

typedef struct		s_sprite
{
	t_component			parent;
	t_vec2f				pos;
	t_vec2f				dir;
	t_sprite_textures	textures;
}					t_sprite;

typedef struct		s_sprite_args
{
	t_vec2f		position;
	t_vec2f		direction;
}					t_sprite_args;

t_sprite_args			sprite_args(t_vec2f pos, t_vec2f dir);
t_sprite				*create_sprite(t_sprite_args args);
t_result				initialize_sprites(t_game *game);
t_component_args		component_sprite_args(t_texture *texture,
							t_vec2i anchor);

#endif