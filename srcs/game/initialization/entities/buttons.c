/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 23:23:20 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/15 04:58:34 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "entities/ui/button.h"
#include "resources/textures/bitmap.h"
#include "resources/textures/texture.h"
#include "resources/resources.h"
#include "utils/error.h"
#include "libft.h"

static t_result	add_button(t_game *game, t_texture_args args1,
	t_texture_args args2, t_bool display)
{
	t_button			*button;
	t_texture			*normal;
	t_texture			*selected;
	t_bitmap_texture	*bmp;

	if (!(bmp = get_image_by_name(game, args1.name)))
		return (throw_error("add_button", args1.name));
	if (!(normal = create_texture_with_bmp(args1, *bmp)))
		return (throw_error("add_button", "texture creation failed"));
	if (!(bmp = get_image_by_name(game, args2.name)))
		return (throw_error("add_button", args2.name));
	if (!(selected = create_texture_with_bmp(args2, *bmp)))
		return (throw_error("add_button", "texture creation failed"));
	if (!(button = create_button(normal, selected, display)))
		return (throw_error("add_button", "button creation failed"));
	if (display)
		list_add_entry(&button->super.node, &game->renderer.ui_components);
	else
		list_add_entry(&button->super.node, &game->entities.ui_components);
	return (OK);
}

t_result	initialize_buttons_entities(t_game *game)
{
	t_texture_args		args1;
	t_texture_args		args2;

	args1 = texture_args("button_up_white", ft_vec2i(10, 10), ft_usize(100, 100), -1);
	args2 = texture_args("button_up_orange", ft_vec2i(10, 10), ft_usize(100, 100), -1);
	if (!(add_button(game, args1, args2, TRUE)))
		return (throw_error("initialize_ui_button", "add button failed"));
	args1 = texture_args("button_down_white", ft_vec2i(10, 105), ft_usize(100, 100), -1);
	args2 = texture_args("button_down_orange", ft_vec2i(10, 105), ft_usize(100, 100), -1);
	if (!(add_button(game, args1, args2, FALSE)))
		return (throw_error("initialize_ui_button", "add button failed"));
	return (OK);
}

