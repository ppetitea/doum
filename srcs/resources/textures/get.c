/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 22:54:57 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/17 22:53:33 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "resources/resources.h"
#include "utils/error.h"
#include "libft.h"

t_bitmap_texture *get_image_by_name(t_list_head *list, char *name)
{
	t_image_node	*image_node;
	t_list_head		*pos;
	t_list_head		*next;

	pos = list;
	next = pos->next;
	while ((pos = next) != list)
	{
		next = next->next;
		image_node = (t_image_node*)pos;
		if (!strcmp(image_node->name, name))
			return (image_node->image);
		(void)name;
	}
	return (throw_null("get_image_by_name", "Error 404 not found"));
}