/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 04:12:43 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/25 01:49:57 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_IMAGE_H
# define INIT_IMAGE_H

# include "engine/resource/image/texture_init.h"
# include "engine/entities/init_entity.h"

/*
**	Entite de type image animable
**	N'interagit pas avec l'utilisateur
*/

typedef struct		s_image
{
	t_entity		super;
	t_texture		texture;
}					t_image;

t_image				*init_new_image();
t_result			init_image_textures(
						t_image *self,
						t_bitmap_texture bmp,
						t_usize size);
t_result			overwrite_image_entity_texture(t_entity_texture *self,
						t_texture *texture, t_vec2i	anchor);
t_result			overwrite_image_entity_listener(
						t_entity *self,
						t_list_head *render,
						t_list_head *storage,
						t_bool display);

#endif