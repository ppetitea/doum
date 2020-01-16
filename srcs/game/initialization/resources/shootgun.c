/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shootgun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 22:26:15 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/16 05:46:04 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "resources/textures/texture.h"
#include "resources/resources.h"
#include "utils/error.h"
#include "libft.h"

t_result	load_shotgun_textures(t_game *game)
{
	t_bitmap_texture	*bmp;
	
	if (!(bmp = load_bmp("resources/textures/sprites/guns/shotgun/aim1.bmp")))
		return (throw_error("load_shotgun_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("shootgun_fire1"));
	if (!(bmp = load_bmp("resources/textures/sprites/guns/shotgun/aim1fire.bmp")))
		return (throw_error("load_shotgun_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("shootgun_fire2"));
	if (!(bmp = load_bmp("resources/textures/sprites/guns/shotgun/aim2.bmp")))
		return (throw_error("load_shotgun_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("shootgun_fire3"));
	if (!(bmp = load_bmp("resources/textures/sprites/guns/shotgun/aim2fire.bmp")))
		return (throw_error("load_shotgun_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("shootgun_fire4"));
	if (!(bmp = load_bmp("resources/textures/sprites/guns/shotgun/reload1.bmp")))
		return (throw_error("load_shotgun_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("shootgun_reload1"));
	if (!(bmp = load_bmp("resources/textures/sprites/guns/shotgun/reload2.bmp")))
		return (throw_error("load_shotgun_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("shootgun_reload2"));
	if (!(bmp = load_bmp("resources/textures/sprites/guns/shotgun/reload3.bmp")))
		return (throw_error("load_shotgun_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("shootgun_reload3"));
	return (OK);
}