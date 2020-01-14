/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 23:57:01 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/14 03:05:06 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# include "libft.h"
# include "textures/bitmap.h"
# include "screen/screen.h"

typedef struct			s_texture
{
	char				*name;
	t_vec2i				offset;
	t_usize				size;
	u_int32_t			*pixels;
}						t_texture;

typedef struct			s_texture_args
{
	char				*name;
	t_vec2i				offset;
	t_usize				size;
}						t_texture_args;

typedef enum			e_filter_type
{
	FILTER_HOVER,
	FILTER_BLEND,
	FILTER_NONE,
}						t_filter_type;

t_texture		*create_texture(t_texture_args args);
t_texture		*create_texture_with_bmp(t_texture_args args,
					t_bitmap_texture bmp);
t_texture_args	texture_args(char *name, t_vec2i offset, t_usize size);
void			render_texture(t_screen screen, t_texture *texture, t_vec2i anchor);
t_bool			is_texture_collide(t_texture self, t_vec2i pos, t_vec2i anchor);
t_texture		*texture_filter(t_texture old, t_filter_type filter);

#endif