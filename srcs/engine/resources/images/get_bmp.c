/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 22:54:57 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/25 01:55:20 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/resource/image/bitmap_list.h"
#include "engine/resource/image/texture_init.h"

#include "utils/error.h"
#include "libft.h"

t_bitmap_texture *get_image_by_name(t_list_head *images, char *name)
{
	t_image_node	*image_node;
	t_list_head		*pos;
	t_list_head		*next;

	pos = images;
	next = pos->next;
	while ((pos = next) != images)
	{
		next = next->next;
		image_node = (t_image_node*)pos;
		if (!strcmp(image_node->name, name))
			return (image_node->image);
	}
	return (throw_null("get_image_by_name", "Error 404 not found"));
}