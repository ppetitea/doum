/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_down.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 16:39:07 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/21 01:39:03 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/resources/textures/texture.h"
#include "engine/resources/resources.h"
#include "init.h"
#include "utils/error.h"
#include "libft.h"

t_result	load_menu_button_down_images(t_list_head *images)
{
	t_bitmap_texture	*bmp;

	if (!(bmp = load_bmp("resources/textures/ui/buttons/down_white.bmp")))
		return (throw_error("load_button_textures", "failed to load bmp"));
	list_add_image(images, bmp, ft_strdup("button_down_white"));
	if (!(bmp = load_bmp("resources/textures/ui/buttons/down_orange.bmp")))
		return (throw_error("load_button_textures", "failed to load bmp"));
	list_add_image(images, bmp, ft_strdup("button_down_orange"));
	return (OK);
}
