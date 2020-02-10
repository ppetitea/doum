/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 23:57:01 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/10 03:10:09 by ppetitea         ###   ########.fr       */
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

typedef	struct			s_box
{
	t_pos2i				offset;
	t_pos2i				size;
}						t_box;

typedef struct			s_render_box
{
	t_box		screen;
	t_box		texture;
	t_vec2f		scale;
	t_pos2i		start;
	t_pos2i		end;
}						t_render_box;

typedef struct			s_texture_box
{
	t_pos2i			anchor;		// in screen
	t_vec2f			scale;		//	orignal_size / wish_size
	t_pos2i			size;		//	in screen
	t_pos2i			offset;		//	in screen
	t_pos2i			start;		//	relative to offset
	t_pos2i			end;		//	in screent_pos2i

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

t_result		init_texture(t_texture *self, t_usize size);
t_texture		*init_new_texture(t_usize size);
t_result		init_oriented_textures(t_oriented_textures *self);

t_result		overwrite_texture_params(t_texture *self, t_vec2i offset,
					uint32_t delay_ms);
t_result		add_texture(t_list_head *textures, t_list_head *bmp_src,
					char *name, t_texture_args args);


t_vec2i			pos_in_screen(t_pos2i pos, t_vec2f render_scale);
t_vec2i			pos_in_texture(t_pos2i pos, t_vec2f render_scale);
void			limit_render_box_with_size(t_usize size, t_render_box *box);
void			limit_texture_box_with_size(t_usize size, t_texture_box *box);
void			update_texture_box_with_screen(t_screen *screen,
					t_texture_box *box, t_texture *texture);
void			update_entity_texture_box_with_size(t_screen *screen,
					t_texture_box *box, t_texture *texture, t_usize	size);
// void			update_entity_texture_box_with_zoom_box(t_screen *screen,
// 					t_texture_box *box, t_texture *texture, t_zoom_box zbox);
void			render_texture_with_box(t_screen *screen, t_texture *texture,
					t_texture_box *box);
void			render_texture_with_render_box(t_screen *screen,
					t_texture *texture, t_render_box box);

t_result		list_add_image(t_list_head *list, t_bitmap_texture *image,
					char *name);

#endif