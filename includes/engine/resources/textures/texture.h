/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 23:57:01 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/19 02:34:25 by ppetitea         ###   ########.fr       */
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
	uint32_t		*pixels;
	uint32_t		delay_ms;
}						t_texture;

typedef struct	s_texture_args
{
	t_vec2i		offset;
	t_usize		size;
	uint32_t	delay_ms;
}				t_texture_args;

t_texture		*build_texture(char *name, t_usize size);
t_texture		*build_texture_with_args(char *name, t_texture_args args);
t_result		fill_texture_with_bmp(t_texture *self, t_bitmap_texture *bmp);
t_result		add_texture(t_list_head *textures, t_list_head *bmp_src,
					char *name, t_texture_args args);

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