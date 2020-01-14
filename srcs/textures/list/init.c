/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 22:26:15 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/14 10:10:08 by ppetitea         ###   ########.fr       */
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

t_result	load_pistol_textures(t_game *game)
{
	t_bitmap_texture	*bmp;
	
	if (!(bmp = load_bmp("resources/textures/sprites/guns/pistol/fire1.bmp")))
		return (throw_error("load_pistol_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("pistol_fire1"));
	if (!(bmp = load_bmp("resources/textures/sprites/guns/pistol/fire2.bmp")))
		return (throw_error("load_pistol_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("pistol_fire2"));
	if (!(bmp = load_bmp("resources/textures/sprites/guns/pistol/fire3.bmp")))
		return (throw_error("load_pistol_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("pistol_fire3"));
	if (!(bmp = load_bmp("resources/textures/sprites/guns/pistol/reload1.bmp")))
		return (throw_error("load_pistol_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("pistol_reload1"));
	if (!(bmp = load_bmp("resources/textures/sprites/guns/pistol/reload2.bmp")))
		return (throw_error("load_pistol_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("pistol_reload2"));
	return (OK);
}

t_result	load_shotgun_textures(t_game *game)
{
	t_bitmap_texture	*bmp;
	
	if (!(bmp = load_bmp("resources/textures/sprites/guns/shotgun/aim1.bmp")))
		return (throw_error("load_shotgun_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("shotgun_aim1"));
	if (!(bmp = load_bmp("resources/textures/sprites/guns/shotgun/aim1fire.bmp")))
		return (throw_error("load_shotgun_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("shotgun_aim1fire"));
	if (!(bmp = load_bmp("resources/textures/sprites/guns/shotgun/aim2.bmp")))
		return (throw_error("load_shotgun_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("shotgun_aim2"));
	if (!(bmp = load_bmp("resources/textures/sprites/guns/shotgun/aim2fire.bmp")))
		return (throw_error("load_shotgun_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("shotgun_aim2fire"));
	if (!(bmp = load_bmp("resources/textures/sprites/guns/shotgun/reload1.bmp")))
		return (throw_error("load_shotgun_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("shotgun_reload1"));
	if (!(bmp = load_bmp("resources/textures/sprites/guns/shotgun/reload2.bmp")))
		return (throw_error("load_shotgun_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("shotgun_reload2"));
	if (!(bmp = load_bmp("resources/textures/sprites/guns/shotgun/reload3.bmp")))
		return (throw_error("load_shotgun_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("shotgun_reload3"));
	return (OK);
}


t_result	initialize_images_list(t_game *game)
{
	if (!load_pistol_textures(game))
		return (throw_error("initialize_images_list", "failed to load pistol"));
	if (!load_shotgun_textures(game))
		return (throw_error("initialize_images_list", "failed to load shotgun"));
	return (OK);
}