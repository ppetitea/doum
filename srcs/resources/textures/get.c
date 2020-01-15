/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 22:54:57 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/15 04:16:20 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "resources/resources.h"
#include "utils/error.h"
#include "game.h"
#include "libft.h"

#include <stdio.h>

t_bitmap_texture *get_image_by_name(t_game *game, char *name)
{
	t_image_node	*image_node;
	t_list_head		*pos;
	t_list_head		*next;

	pos = &game->resources.images;
	next = pos->next;
	while ((pos = next) != &game->resources.images)
	{
		next = next->next;
		image_node = (t_image_node*)pos;
		if (!strcmp(image_node->name, name))
			return (image_node->image);
		(void)name;
	}
	return (throw_null("get_image_by_name", "Error 404 not found"));
}