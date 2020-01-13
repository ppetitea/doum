/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 23:57:01 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/13 04:05:29 by ppetitea         ###   ########.fr       */
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

t_texture		*create_texture_with_bmp(t_texture_args args,
					t_bitmap_texture bmp);
t_texture_args	texture_args(char *name, t_vec2i offset,
					t_usize size);
void			render_texture(t_screen screen, t_texture *texture);

#endif