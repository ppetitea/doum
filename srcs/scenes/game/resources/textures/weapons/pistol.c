/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pistol.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 05:49:09 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/18 23:36:36 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "resources/resources.h"
#include "utils/error.h"
#include "libft.h"

static t_result	load_pistol_fire_images(t_list_head *images)
{
	t_bitmap_texture	*bmp;
	
	if (images == NULL)
		return (throw_error("load_pistol_textures", "NULL pointer provided"));
	if (!(bmp = load_bmp("resources/textures/sprites/guns/pistol/fire1.bmp")))
		return (throw_error("load_pistol_textures", "pistol_fire1 failed"));
	list_add_image(images, bmp, ft_strdup("pistol_fire1"));
	if (!(bmp = load_bmp("resources/textures/sprites/guns/pistol/fire2.bmp")))
		return (throw_error("load_pistol_textures", "pistol_fire2 failed"));
	list_add_image(images, bmp, ft_strdup("pistol_fire2"));
	if (!(bmp = load_bmp("resources/textures/sprites/guns/pistol/fire3.bmp")))
		return (throw_error("load_pistol_textures", "pistol_fire3 failed"));
	list_add_image(images, bmp, ft_strdup("pistol_fire3"));
	return (OK);
}

static t_result	load_pistol_reload_images(t_list_head *images)
{
	t_bitmap_texture	*bmp;
	
	if (images == NULL)
		return (throw_error("load_pistol_textures", "NULL pointer provided"));
	if (!(bmp = load_bmp("resources/textures/sprites/guns/pistol/reload1.bmp")))
		return (throw_error("load_pistol_textures", "pistol_reload1 failed"));
	list_add_image(images, bmp, ft_strdup("pistol_reload1"));
	if (!(bmp = load_bmp("resources/textures/sprites/guns/pistol/reload2.bmp")))
		return (throw_error("load_pistol_textures", "pistol_reload2 failed"));
	list_add_image(images, bmp, ft_strdup("pistol_reload2"));
	if (!(bmp = load_bmp("resources/textures/sprites/guns/pistol/reload3.bmp")))
		return (throw_error("load_pistol_textures", "pistol_reload3 failed"));
	list_add_image(images, bmp, ft_strdup("pistol_reload3"));
	if (!(bmp = load_bmp("resources/textures/sprites/guns/pistol/reload4.bmp")))
		return (throw_error("load_pistol_textures", "pistol_reload4 failed"));
	list_add_image(images, bmp, ft_strdup("pistol_reload4"));
	return (OK);
}

t_result	load_pistol_images(t_list_head *images)
{
	if (images == NULL)
		return (throw_error("load_pistol_textures", "NULL pointer provided"));
	if (!load_pistol_fire_images(images))
		return (throw_error("load_pistol_images", "fire images failed"));
	if (!load_pistol_reload_images(images))
		return (throw_error("load_pistol_images", "reload images failed"));
	return (OK);
}
