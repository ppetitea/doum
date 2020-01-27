/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_bmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 20:54:28 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/25 01:47:47 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "engine/resource/image/bitmap_list.h"
#include "utils/error.h"

t_result	list_add_image(t_list_head *list, t_bitmap_texture *image,
				char *name)
{
	t_image_node		*node;

	if (list == NULL || image == NULL || name == NULL)
		return (throw_error("list_add_image", "NULL pointer provided"));
	if (!(node = (t_image_node*)malloc(sizeof(t_image_node))))
		return (throw_error("list_add_image", "malloc failed"));
	node->name = ft_strdup(name);
	node->image = image;
	init_list_head(&node->node);
	list_add_entry(&node->node, list);
	return (OK);
}