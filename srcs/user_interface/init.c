/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 16:33:04 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/14 03:25:07 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/game.h"
#include "user_interface/button.h"
#include "user_interface/spawner.h"
#include "textures/bitmap.h"
#include "textures/texture.h"
#include "textures/image_list.h"
#include "utils/error.h"
#include "libft.h"

static t_result	add_button(t_game *game, t_texture_args args1,
	t_texture_args args2)
{
	t_button			*button;
	t_texture			*normal;
	t_texture			*selected;
	t_bitmap_texture	*bmp;

	if (!(bmp = get_image_by_name(game, args1.name)))
		return (throw_error("add_button", "texture not found"));
	if (!(normal = create_texture_with_bmp(args1, *bmp)))
		return (throw_error("add_button", "texture creation failed"));
	if (!(bmp = get_image_by_name(game, args2.name)))
		return (throw_error("add_button", "texture not found"));
	if (!(selected = create_texture_with_bmp(args2, *bmp)))
		return (throw_error("add_button", "texture creation failed"));
	if (!(button = create_ui_button(normal, selected)))
		return (throw_error("add_button", "button creation failed"));
	list_add_entry(&button->parent.node, &game->ui_components);
	return (OK);
}

static t_result	add_spawner(t_game *game, t_texture_args args)
{
	t_ui_spawner			*spawner;
	t_texture			*texture;
	t_bitmap_texture	*bmp;

	if (!(bmp = get_image_by_name(game, args.name)))
		return (throw_error("add_spawner", "texture not found"));
	if (!(texture = create_texture_with_bmp(args, *bmp)))
		return (throw_error("add_spawner", "texture creation failed"));
	if (!(spawner = create_ui_spawner(texture)))
		return (throw_error("add_spawner", "spawner creation failed"));
	list_add_entry(&spawner->parent.node, &game->ui_components);
	return (OK);
}

static t_result	initialize_ui_buttons(t_game *game)
{
	t_texture_args		args1;
	t_texture_args		args2;
	
	args1 = texture_args("up_white", ft_vec2i(10, 10), ft_usize(100, 100));
	args2 = texture_args("up_orange", ft_vec2i(10, 10), ft_usize(100, 100));
	if (!(add_button(game, args1, args2)))
		return (throw_error("initialize_ui_button", "add button failed"));
	args1 = texture_args("down_white", ft_vec2i(10, 105), ft_usize(100, 100));
	args2 = texture_args("down_orange", ft_vec2i(10, 105), ft_usize(100, 100));
	if (!(add_button(game, args1, args2)))
		return (throw_error("initialize_ui_button", "add button failed"));
	args1 = texture_args("brick", ft_vec2i(530, 10), ft_usize(100, 100));
	if (!(add_spawner(game, args1)))
		return (throw_error("initialize_ui_spawner", "add spawner failed"));
	args1 = texture_args("msi", ft_vec2i(425, 10), ft_usize(100, 100));
	if (!(add_spawner(game, args1)))
		return (throw_error("initialize_ui_spawner", "add spawner failed"));
	return (OK);
}

t_result	initialize_user_interface(t_game *game)
{
	initialize_ui_buttons(game);
	return (OK);
}