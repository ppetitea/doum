/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 22:54:57 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/14 01:15:37 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textures/image_list.h"
#include "utils/error.h"
#include "game/game.h"
#include "libft.h"

#include <stdio.h>

t_bitmap_texture *get_image_by_name(t_game *game, char *name)
{
	t_image_node	*image_node;
	t_list_head		*pos;
	t_list_head		*next;

	pos = &game->images;
	next = pos->next;
	while ((pos = next) != &game->images)
	{
		next = next->next;
		image_node = (t_image_node*)pos;
		if (!strcmp(image_node->name, name))
			return (image_node->image);
		(void)name;
	}
	return (throw_null("get_image_by_name", "Error 404 not found"));
}