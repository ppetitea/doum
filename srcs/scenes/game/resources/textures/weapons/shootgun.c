/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shootgun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 22:26:15 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/19 20:42:10 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/resources/resources.h"
#include "utils/error.h"
#include "libft.h"

static t_result	load_shootgun_fire_images(t_list_head *images)
{
	t_bitmap_texture	*bmp;
	
	if (images == NULL)
		return (throw_error("load_shootgun_images", "NULL pointer provided"));
	if (!(bmp = load_bmp("resources/textures/sprites/guns/shotgun/aim1.bmp")))
		return (throw_error("load_shotgun_images", "shootgun_fire1 failed"));
	list_add_image(images, bmp, ft_strdup("shootgun_fire1"));
	if (!(bmp = load_bmp("resources/textures/sprites/guns/shotgun/aim1fire.bmp")))
		return (throw_error("load_shotgun_images", "shootgun_fire2 failed"));
	list_add_image(images, bmp, ft_strdup("shootgun_fire2"));
	if (!(bmp = load_bmp("resources/textures/sprites/guns/shotgun/aim2.bmp")))
		return (throw_error("load_shotgun_images", "shootgun_fire3 failed"));
	list_add_image(images, bmp, ft_strdup("shootgun_fire3"));
	if (!(bmp = load_bmp("resources/textures/sprites/guns/shotgun/aim2fire.bmp")))
		return (throw_error("load_shotgun_images", "shootgun_fire4 failed"));
	list_add_image(images, bmp, ft_strdup("shootgun_fire4"));
	return (OK);
}

static t_result	load_shootgun_reload_images(t_list_head *images)
{
	t_bitmap_texture	*bmp;
	
	if (images == NULL)
		return (throw_error("load_shootgun_images", "NULL pointer provided"));
	if (!(bmp = load_bmp("resources/textures/sprites/guns/shotgun/reload1.bmp")))
		return (throw_error("load_shotgun_images", "shootgun_reload1"));
	list_add_image(images, bmp, ft_strdup("shootgun_reload1"));
	if (!(bmp = load_bmp("resources/textures/sprites/guns/shotgun/reload2.bmp")))
		return (throw_error("load_shotgun_images", "shootgun_reload2"));
	list_add_image(images, bmp, ft_strdup("shootgun_reload2"));
	if (!(bmp = load_bmp("resources/textures/sprites/guns/shotgun/reload3.bmp")))
		return (throw_error("load_shotgun_images", "shootgun_reload3"));
	list_add_image(images, bmp, ft_strdup("shootgun_reload3"));
	return (OK);
}

t_result	load_shootgun_images(t_list_head *images)
{
	if (images == NULL)
		return (throw_error("load_shootgun_images", "NULL pointer provided"));
	if (!load_shootgun_fire_images(images))
		return (throw_error("load_shootgun_images", "fire textures failed"));
	if (!load_shootgun_reload_images(images))
		return (throw_error("load_shootgun_images", "reload textures failed"));
	return (OK);
}
