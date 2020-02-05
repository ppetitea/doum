/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 00:00:54 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/25 01:55:11 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITMAP_LIST_H
# define BITMAP_LIST_H

# include "engine/resource/image/bitmap_parser.h"
# include "utils/parser.h"
# include "libft.h"

typedef struct			s_image_node
{
	t_list_head			node;
	char				*name;
	t_bitmap_texture	*image;
}						t_image_node;

t_result	resources_load_images(t_list_head *images,
				t_dnon_object *images_obj);
t_bitmap_texture *get_image_by_name(t_list_head *images, char *name);


#endif
