/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 22:26:15 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/14 02:01:03 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/game.h"
#include "textures/texture.h"
#include "textures/image_list.h"
#include "utils/error.h"
#include "libft.h"


#include <stdio.h>

t_result	list_add_image(t_game *game, t_bitmap_texture *image, char *name)
{
	t_image_node		*node;

	if (!(node = (t_image_node*)malloc(sizeof(t_image_node))))
		return (throw_error("image_node", "malloc failed"));
	node->name = name;
	node->image = image;
	init_list_head(&node->node);
	list_add_entry(&node->node, &game->images);
	return (OK);
}

t_result	initialize_images_list(t_game *game)
{
	t_bitmap_texture	*bmp;
	
	if (!(bmp = load_bmp("resources/textures/ui/buttons/down_white.bmp")))
		return (throw_error("initialize_images_list", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("down_white"));
	if (!(bmp = load_bmp("resources/textures/ui/buttons/down_orange.bmp")))
		return (throw_error("initialize_images_list", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("down_orange"));
	if (!(bmp = load_bmp("resources/textures/ui/buttons/up_white.bmp")))
		return (throw_error("initialize_images_list", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("up_white"));
	if (!(bmp = load_bmp("resources/textures/ui/buttons/up_orange.bmp")))
		return (throw_error("initialize_images_list", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("up_orange"));
	if (!(bmp = load_bmp("resources/textures/tmp/brick.bmp")))
		return (throw_error("initialize_images_list", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("brick"));
	if (!(bmp = load_bmp("resources/textures/tmp/msi.bmp")))
		return (throw_error("initialize_images_list", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("msi"));
	return (OK);
}