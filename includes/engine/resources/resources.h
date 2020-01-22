/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resources.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 23:03:16 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/22 04:35:26 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESOURCES_H
# define RESOURCES_H

# include "engine/resources/textures/texture.h"
# include "utils/parser.h"
# include "libft.h"

typedef struct			s_image_node
{
	t_list_head			node;
	char				*name;
	t_bitmap_texture	*image;
}						t_image_node;

t_result			list_add_image(t_list_head *images,
						t_bitmap_texture *image, char *name);
t_bitmap_texture	*get_image_by_name(t_list_head *images, char *name);
t_result			resources_load_images(t_list_head *images,
						t_dnon_object *images_obj);
t_result			build_oriented_textures(t_list_head *images,
						t_oriented_textures *textures,
						t_dnon_object *o_textures_obj);
t_result			build_textures_with_obj(t_list_head *images,
						t_list_head *list, t_dnon_object *textures_obj);
t_texture			*build_texture_with_obj(t_list_head *images,
						t_list_head *list, t_dnon_object *texture_obj);
t_bitmap_texture	*get_bmp_by_texture_obj(t_list_head *images,
						t_dnon_object *texture_obj);
						
#endif
