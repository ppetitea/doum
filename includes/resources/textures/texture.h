/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 23:57:01 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/18 01:38:25 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# include "libft.h"
# include "resources/textures/bitmap.h"
# include "interface/screen.h"

/*
**	Chaque texture est un noeud dans une liste
**	ce qui permet de creer des animations
*/

typedef struct			s_texture
{
	t_list_head		node;
	char			*name;
	t_vec2i			offset;
	t_usize			size;
	u_int32_t		*pixels;
	unsigned int	delay_ms;
}						t_texture;

typedef struct			s_texture_args
{
	char				*name;
	t_vec2i				offset;
	t_usize				size;
	float				delay_ms;
}						t_texture_args;

typedef struct		s_oriented_textures
{
	t_texture		*front;
	t_texture		*front_r;
	t_texture		*front_l;
	t_texture		*right;
	t_texture		*back;
	t_texture		*back_r;
	t_texture		*back_l;
	t_texture		*left;
}					t_oriented_textures;

t_texture		*create_texture(t_texture_args args);
t_texture		*create_texture_with_bmp(t_texture_args args,
					t_bitmap_texture bmp);
t_texture		*create_texture_with_bmp_name(t_list_head *list,
					t_texture_args args);
t_result		add_texture(t_list_head *resources, t_texture **texture_list,
					t_texture_args args);

t_texture_args	texture_args(char *name, t_vec2i offset, t_usize size,
					float delay);
void			render_texture(t_screen screen, t_texture *texture,
					t_vec2i anchor);
void			render_texture_with_scale(t_screen screen, t_texture *texture,
					t_vec2i anchor, float scale);
t_bool			is_texture_collide(t_texture self, t_vec2i pos, t_vec2i anchor);

/*
**	Un filtre peut etre applique pour creer une nouvelle texture
**	
**	BLEND -> transparence
**	HOVER -> ajoute une ombre circulaire progressive
**	NONE -> retourne une copie de la texture
*/

typedef enum			e_filter_type
{
	FILTER_HOVER,
	FILTER_BLEND,
	FILTER_ROTATE_RIGHT,
	FILTER_ROTATE_LEFT,
	FILTER_MIRROR_HORIZONTAL,
	FILTER_MIRROR_VERTICAL,
	FILTER_NONE,
}						t_filter_type;

t_texture		*texture_filter(t_texture old, t_filter_type filter);
t_vec2i			get_texture_center(t_texture texture);

#endif