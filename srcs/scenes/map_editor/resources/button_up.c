/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_up.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 16:39:07 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/18 21:05:25 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/resources/textures/texture.h"
#include "engine/resources/resources.h"
#include "init.h"
#include "utils/error.h"
#include "libft.h"

t_result	load_editor_button_up_images(t_list_head *images)
{
	t_bitmap_texture	*bmp;

	if (!(bmp = load_bmp("resources/textures/ui/buttons/up_white.bmp")))
		return (throw_error("load_button_textures", "failed to load bmp"));
	list_add_image(images, bmp, ft_strdup("button_up_white"));
	if (!(bmp = load_bmp("resources/textures/ui/buttons/up_orange.bmp")))
		return (throw_error("load_button_textures", "failed to load bmp"));
	list_add_image(images, bmp, ft_strdup("button_up_orange"));
	return (OK);
}
