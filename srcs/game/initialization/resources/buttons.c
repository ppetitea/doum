/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 22:26:15 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/15 04:07:54 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "resources/textures/texture.h"
#include "resources/resources.h"
#include "utils/error.h"
#include "libft.h"

t_result	load_button_textures(t_game *game)
{
	t_bitmap_texture	*bmp;
	
	if (!(bmp = load_bmp("resources/textures/ui/buttons/down_white.bmp")))
		return (throw_error("load_button_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("button_down_white"));
	if (!(bmp = load_bmp("resources/textures/ui/buttons/down_orange.bmp")))
		return (throw_error("load_button_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("button_down_orange"));
	if (!(bmp = load_bmp("resources/textures/ui/buttons/up_white.bmp")))
		return (throw_error("load_button_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("button_up_white"));
	if (!(bmp = load_bmp("resources/textures/ui/buttons/up_orange.bmp")))
		return (throw_error("load_button_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("button_up_orange"));
	if (!(bmp = load_bmp("resources/textures/ui/buttons/x_white.bmp")))
		return (throw_error("load_button_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("button_x_white"));
	if (!(bmp = load_bmp("resources/textures/ui/buttons/x_orange.bmp")))
		return (throw_error("load_button_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("button_x_orange"));
	if (!(bmp = load_bmp("resources/textures/ui/buttons/plus_white.bmp")))
		return (throw_error("load_button_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("button_plus_white"));
	if (!(bmp = load_bmp("resources/textures/ui/buttons/plus_orange.bmp")))
		return (throw_error("load_button_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("button_plus_orange"));
	return (OK);
}