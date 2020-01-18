/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 22:26:15 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/18 06:01:58 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "resources/textures/texture.h"
#include "resources/resources.h"
#include "utils/error.h"
#include "libft.h"

t_result	list_add_image(t_list_head *list, t_bitmap_texture *image,
				char *name)
{
	t_image_node		*node;

	if (list == NULL || image == NULL || name == NULL)
		return (throw_error("list_add_image", "NULL pointer provided"));
	if (!(node = (t_image_node*)malloc(sizeof(t_image_node))))
		return (throw_error("list_add_image", "malloc failed"));
	node->name = name;
	node->image = image;
	init_list_head(&node->node);
	list_add_entry(&node->node, list);
	return (OK);
}

t_result	initialize_images_list(t_game *game)
{
	if (!load_pistol_textures(game))
		return (throw_error("initialize_images_list", "failed to load pistol"));
	if (!load_shotgun_textures(game))
		return (throw_error("initialize_images_list", "failed to load shotgun"));
	if (!load_button_textures(game))
		return (throw_error("initialize_images_list", "failed to load button"));
	if (!load_ennemy_textures(game))
		return (throw_error("initialize_images_list", "failed to load ennemy"));
	return (OK);
}