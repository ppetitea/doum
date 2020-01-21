/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkbox_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 16:39:07 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/20 04:07:43 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/resources/textures/texture.h"
#include "engine/resources/resources.h"
#include "init.h"
#include "utils/error.h"
#include "libft.h"

t_result	load_menu_checkbox_test_images(t_list_head *images)
{
	t_bitmap_texture	*bmp;

	if (!(bmp = load_bmp("resources/textures/ui/checkbox/test.bmp")))
		return (throw_error("load_checkbox_textures", "failed to load bmp"));
	list_add_image(images, bmp, ft_strdup("checkbox_test"));
	return (OK);
}
