/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_background.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 16:39:07 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/20 21:09:14 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/resources/textures/texture.h"
#include "engine/resources/resources.h"
#include "init.h"
#include "utils/error.h"
#include "libft.h"

t_result	load_menu_image_background(t_list_head *images)
{
	t_bitmap_texture	*bmp;

	if (!(bmp = load_bmp("resources/textures/ui/images/menu_background.bmp")))
		return (throw_error("load_menu_image", "failed to load bmp"));
	list_add_image(images, bmp, ft_strdup("menu_background"));
	return (OK);
}
