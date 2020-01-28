/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_filter.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 23:41:55 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/28 03:55:46 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_FILTER_H
# define TEXTURE_FILTER_H

# include "engine/resource/image/texture_init.h"
# include "libft.h"

/*
**	Un filtre peut etre applique pour creer une nouvelle texture
**	
**	BLEND -> transparence
**	HOVER -> ajoute une ombre circulaire progressive
**	NONE -> retourne une copie de la texture
*/

typedef enum			e_filter_type
{
	FILTER_CIRCULAR_SHADOW,
	FILTER_BLEND,
	FILTER_ROTATE_RIGHT,
	FILTER_ROTATE_LEFT,
	FILTER_MIRROR_HORIZONTAL,
	FILTER_MIRROR_VERTICAL,
	FILTER_NONE,
}						t_filter_type;

t_result		texture_filter(t_texture *new, t_texture old,
					t_filter_type filter);
t_texture		*new_texture_filter(t_texture old, t_filter_type filter);
void			set_texture_pixel_circular_shadow(t_texture old,
						t_texture *new, t_usize i);
void			set_texture_pixel(t_texture old,t_texture *new, t_usize i);
void			set_texture_pixel_blend(t_texture old,t_texture *new,
						t_usize i);

#endif