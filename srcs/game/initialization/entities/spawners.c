/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawners.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 16:33:04 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/15 08:08:09 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "entities/ui/spawner.h"
#include "resources/textures/bitmap.h"
#include "resources/textures/texture.h"
#include "resources/resources.h"
#include "utils/error.h"
#include "libft.h"

static t_result	add_spawner(t_game *game, t_texture_args args, t_bool display)
{
	t_spawner			*spawner;
	t_texture			*texture;
	t_bitmap_texture	*bmp;

	if (!(bmp = get_image_by_name(game, args.name)))
		return (throw_error("add_spawner", args.name));
	if (!(texture = create_texture_with_bmp(args, *bmp)))
		return (throw_error("add_spawner", "texture creation failed"));
	if (!(spawner = create_spawner(game, texture, display)))
		return (throw_error("add_spawner", "spawner creation failed"));
	return (OK);
}

t_result	initialize_spawners_entities(t_game *game)
{
	t_texture_args		args;

	args = texture_args("button_x_orange", ft_vec2i(530, 10), ft_usize(100, 100), -1);
	if (!(add_spawner(game, args, TRUE)))
		return (throw_error("initialize_spawner", "add spawner failed"));
	(void)game;
	return (OK);
}