/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 05:59:37 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/14 10:28:04 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/game.h"
#include "sprites/sprites.h"
#include "textures/texture.h"
#include "textures/image_list.h"
#include "utils/error.h"
#include "libft.h"

static t_result	set_sprite_south_texture(t_game *game, t_sprite *sprite,
					t_texture_args args)
{
	t_texture			*texture;
	t_bitmap_texture	*bmp;

	if (!(bmp = get_image_by_name(game, args.name)))
		return (throw_error("get_sprite_texture", "texture not found"));
	if (!(texture = create_texture_with_bmp(args, *bmp)))
		return (throw_error("get_sprite_texture", "texture creation failed"));
	if (sprite->textures.south == NULL)
		sprite->textures.south = texture;
	else
		list_add_entry(&texture->node, &sprite->textures.south->node);
	return (OK);
}

static t_result	set_pistol_fire_sprite_textures(t_game *game, t_sprite *sprite)
{
	t_texture_args		args;

	args = texture_args("pistol_fire1", ft_vec2i(-150, -300), ft_usize(300, 300), 100);
	if (!set_sprite_south_texture(game, sprite, args))
		return (throw_error("initialize_fire_sprite", "fire1 failed"));
	args = texture_args("pistol_fire2", ft_vec2i(-125, -300), ft_usize(300, 300), 100);
	if (!set_sprite_south_texture(game, sprite, args))
		return (throw_error("initialize_fire_sprite", "fire2 failed"));
	args = texture_args("pistol_fire3", ft_vec2i(-100, -300), ft_usize(300, 300), 100);
	if (!set_sprite_south_texture(game, sprite, args))
		return (throw_error("initialize_fire_sprite", "fire3 failed"));

		
	// args = texture_args("shotgun_aim1", ft_vec2i(-125, -300), ft_usize(300, 300), 50);
	// if (!set_sprite_south_texture(game, sprite, args))
	// 	return (throw_error("initialize_fire_sprite", "shotgun_aim1 failed"));
	// args = texture_args("shotgun_aim1fire", ft_vec2i(-125, -300), ft_usize(300, 300), 50);
	// if (!set_sprite_south_texture(game, sprite, args))
	// 	return (throw_error("initialize_fire_sprite", "shotgun_aim1fire failed"));
	// args = texture_args("shotgun_aim2", ft_vec2i(-125, -300), ft_usize(300, 300), 50);
	// if (!set_sprite_south_texture(game, sprite, args))
	// 	return (throw_error("initialize_fire_sprite", "shotgun_aim2 failed"));
	// args = texture_args("shotgun_aim2fire", ft_vec2i(-125, -300), ft_usize(300, 300), 50);
	// if (!set_sprite_south_texture(game, sprite, args))
	// 	return (throw_error("initialize_fire_sprite", "shotgun_aim2fire failed"));
	
	// args = texture_args("shotgun_reload1", ft_vec2i(-125, -300), ft_usize(300, 300), 100);
	// if (!set_sprite_south_texture(game, sprite, args))
	// 	return (throw_error("initialize_fire_sprite", "shotgun_reload1 failed"));
	// args = texture_args("shotgun_reload2", ft_vec2i(-150, -300), ft_usize(300, 300), 100);
	// if (!set_sprite_south_texture(game, sprite, args))
	// 	return (throw_error("initialize_fire_sprite", "shotgun_reload2 failed"));
	// args = texture_args("shotgun_reload3", ft_vec2i(-150, -300), ft_usize(300, 300), 100);
	// if (!set_sprite_south_texture(game, sprite, args))
	// 	return (throw_error("initialize_fire_sprite", "shotgun_reload3 failed"));
	return (OK);
}

static t_result	add_pistol_fire_sprite(t_game *game)
{
	t_sprite			*sprite;
	t_component_args	component_args;
	t_vec2i				anchor;

	anchor = ft_vec2i(game->screen.size.x * 0.5, game->screen.size.y);
	sprite = create_sprite(sprite_args(ft_vec2f(0, 0), ft_vec2f(0, -1)));
	if (!(set_pistol_fire_sprite_textures(game, sprite)))
		return (throw_error("add pistol_fire", "failed to set textures"));
	component_args = component_sprite_args(sprite->textures.south, anchor);
	build_ui_component(&sprite->parent, component_args);
	list_add_entry(&sprite->parent.node, &game->sprites);
	(void)game;
	return (OK);
}

t_result	initialize_sprites(t_game *game)
{
	if (!(add_pistol_fire_sprite(game)))
		return (throw_error("initialize_sprites", "pistol fire sprite failed"));
	(void)game;
	return (OK);
}