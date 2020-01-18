/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pistol.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 22:26:15 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/18 05:56:12 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "resources/textures/texture.h"
#include "resources/resources.h"
#include "utils/error.h"
#include "libft.h"

// t_result	load_pistol_textures(t_game *game)
// {
// 	t_bitmap_texture	*bmp;
	
// 	if (!(bmp = load_bmp("resources/textures/sprites/guns/pistol/fire1.bmp")))
// 		return (throw_error("load_pistol_textures", "failed to load bmp"));
// 	list_add_image(game, bmp, ft_strdup("pistol_fire1"));
// 	if (!(bmp = load_bmp("resources/textures/sprites/guns/pistol/fire2.bmp")))
// 		return (throw_error("load_pistol_textures", "failed to load bmp"));
// 	list_add_image(game, bmp, ft_strdup("pistol_fire2"));
// 	if (!(bmp = load_bmp("resources/textures/sprites/guns/pistol/fire3.bmp")))
// 		return (throw_error("load_pistol_textures", "failed to load bmp"));
// 	list_add_image(game, bmp, ft_strdup("pistol_fire3"));
// 	if (!(bmp = load_bmp("resources/textures/sprites/guns/pistol/reload1.bmp")))
// 		return (throw_error("load_pistol_textures", "failed to load bmp"));
// 	list_add_image(game, bmp, ft_strdup("pistol_reload1"));
// 	if (!(bmp = load_bmp("resources/textures/sprites/guns/pistol/reload2.bmp")))
// 		return (throw_error("load_pistol_textures", "failed to load bmp"));
// 	list_add_image(game, bmp, ft_strdup("pistol_reload2"));
// 	if (!(bmp = load_bmp("resources/textures/sprites/guns/pistol/reload3.bmp")))
// 		return (throw_error("load_pistol_textures", "failed to load bmp"));
// 	list_add_image(game, bmp, ft_strdup("pistol_reload3"));
// 	if (!(bmp = load_bmp("resources/textures/sprites/guns/pistol/reload4.bmp")))
// 		return (throw_error("load_pistol_textures", "failed to load bmp"));
// 	list_add_image(game, bmp, ft_strdup("pistol_reload4"));
// 	return (OK);
// }
