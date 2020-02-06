/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 23:57:01 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/06 19:22:25 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_INIT_H
# define TEXTURE_INIT_H

# include "containers/list.h"
# include "maths/vec2f.h"
# include "engine/resource/image/bitmap_parser.h"

/*
**	Chaque texture est un noeud dans une liste
**	ce qui permet de creer des animations
*/

typedef struct			s_texture_box
{
	t_vec2i			anchor;
	float			scale;
	t_vec2i			offset;
	t_usize			limit;
}						t_texture_box;

typedef struct			s_texture
{
	t_list_head	node;
	char		*name;
	t_vec2i		offset;
	t_usize		size;
	t_u32		*pixels;
	uint32_t	delay_ms;
}						t_texture;

typedef struct	s_texture_args
{
	t_vec2i		offset;
	t_usize		size;
	uint32_t	delay_ms;
}				t_texture_args;

typedef struct		s_oriented_textures
{
	t_list_head		front;
	t_list_head		front_r;
	t_list_head		front_l;
	t_list_head		right;
	t_list_head		left;
	t_list_head		back;
	t_list_head		back_r;
	t_list_head		back_l;
}					t_oriented_textures;

t_texture		*init_new_texture(t_usize size);
t_result		init_texture(t_texture *self, t_usize size);

t_result		overwrite_texture_params(t_texture *self, t_vec2i offset,
					uint32_t delay_ms);
t_result		add_texture(t_list_head *textures, t_list_head *bmp_src,
					char *name, t_texture_args args);


t_result		init_oriented_textures(t_oriented_textures *self);
void			render_texture(t_screen *screen, t_texture *texture,
					t_vec2i anchor);
void			render_texture_with_scale(t_screen *screen, t_texture *texture,
					t_vec2i anchor, float scale);
void			render_texture_with_scale_2d(t_screen *screen, t_texture *texture,
					t_vec2i anchor, t_vec2f scale);
t_bool			is_texture_collide(t_texture self, t_vec2i pos, t_vec2i anchor);
t_result		list_add_image(t_list_head *list, t_bitmap_texture *image,
					char *name);

#endif