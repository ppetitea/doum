/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 05:59:37 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/15 08:32:58 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "entities/sprites/sprites.h"
#include "resources/textures/texture.h"
#include "resources/resources.h"
#include "events/keyboard.h"
#include "utils/error.h"
#include "libft.h"

static t_result	set_sprite_front_texture(t_game *game,
					t_sprite *sprite, t_texture_args args)
{
	t_texture			*texture;
	t_bitmap_texture	*bmp;

	if (!(bmp = get_image_by_name(game, args.name)))
		return (throw_error("get_sprite_texture", "texture not found"));
	if (!(texture = create_texture_with_bmp(args, *bmp)))
		return (throw_error("get_sprite_texture", "texture creation failed"));
	if (sprite->textures.front == NULL)
		sprite->textures.front = texture;
	else
		list_add_entry(&texture->node, &sprite->textures.front->node);
	return (OK);
}

static t_result	set_pistol_fire_sprite_textures(t_game *game, t_sprite *sprite)
{
	t_texture_args		args;

	args = texture_args("pistol_fire1", ft_vec2i(-150, -300), ft_usize(300, 300), 100);
	if (!set_sprite_front_texture(game, sprite, args))
		return (throw_error("initialize_fire_sprite", "fire1 failed"));
	args = texture_args("pistol_fire2", ft_vec2i(-125, -300), ft_usize(300, 300), 100);
	if (!set_sprite_front_texture(game, sprite, args))
		return (throw_error("initialize_fire_sprite", "fire2 failed"));
	args = texture_args("pistol_fire3", ft_vec2i(-100, -300), ft_usize(300, 300), 100);
	if (!set_sprite_front_texture(game, sprite, args))
		return (throw_error("initialize_fire_sprite", "fire3 failed"));
	return (OK);
}

static t_result	set_shootgun_fire_sprite_textures(t_game *game, t_sprite *sprite)
{
	t_texture_args		args;

	args = texture_args("shotgun_aim1", ft_vec2i(-125, -300), ft_usize(300, 300), 50);
	if (!set_sprite_front_texture(game, sprite, args))
		return (throw_error("initialize_fire_sprite", "shotgun_aim1 failed"));
	args = texture_args("shotgun_aim1fire", ft_vec2i(-125, -300), ft_usize(300, 300), 50);
	if (!set_sprite_front_texture(game, sprite, args))
		return (throw_error("initialize_fire_sprite", "shotgun_aim1fire failed"));
	args = texture_args("shotgun_aim2", ft_vec2i(-125, -300), ft_usize(300, 300), 50);
	if (!set_sprite_front_texture(game, sprite, args))
		return (throw_error("initialize_fire_sprite", "shotgun_aim2 failed"));
	args = texture_args("shotgun_aim2fire", ft_vec2i(-125, -300), ft_usize(300, 300), 50);
	if (!set_sprite_front_texture(game, sprite, args))
		return (throw_error("initialize_fire_sprite", "shotgun_aim2fire failed"));
	return (OK);
}

static t_result	set_shootgun_reload_sprite_textures(t_game *game,
			t_sprite *sprite)
{
	t_texture_args		args;

	args = texture_args("shotgun_reload1", ft_vec2i(-125, -300),
		ft_usize(300, 300), 100);
	if (!set_sprite_front_texture(game, sprite, args))
		return (throw_error("initialize_fire_sprite", "shotgun_reload1 fail"));
	args = texture_args("shotgun_reload2", ft_vec2i(-150, -300),
		ft_usize(300, 300), 100);
	if (!set_sprite_front_texture(game, sprite, args))
		return (throw_error("initialize_fire_sprite", "shotgun_reload2 fail"));
	args = texture_args("shotgun_reload3", ft_vec2i(-150, -300),
				ft_usize(300, 300), 100);
	if (!set_sprite_front_texture(game, sprite, args))
		return (throw_error("initialize_fire_sprite", "shotgun_reload3 fail"));
	return (OK);
}

static t_result	add_pistol_fire_sprite(t_game *game, t_bool display,
					t_animation_status animation)
{
	t_sprite			*sprite;
	t_entity_args		entity_args;
	t_vec2i				anchor;

	anchor = ft_vec2i(game->interface.screen.size.x * 0.5, game->interface.screen.size.y);
	entity_sprite_args1(&entity_args, NULL, animation, anchor);
	entity_sprite_args2(&entity_args, ft_vec2f(0, 0), ft_vec2f(0, 0));
	entity_sprite_args3(&entity_args, game, display);
	sprite = create_sprite(entity_args);
	if (!(set_pistol_fire_sprite_textures(game, sprite)))
		return (throw_error("add pistol_fire", "failed to set textures"));
	sprite->super.texture.t = sprite->textures.front;
	sprite->super.texture.t_head = sprite->textures.front;
	bind_key(&game->interface.keys_bind, SDLK_SPACE, &sprite->super,
		trigger_animation);
	bind_key(&game->interface.keys_bind, SDLK_TAB, &sprite->super,
		toggle_display_entity);
	return (OK);
}

static t_result	add_shootgun_fire_sprite(t_game *game, t_bool display,
					t_animation_status animation)
{
	t_sprite			*sprite;
	t_entity_args		entity_args;
	t_vec2i				anchor;

	anchor = ft_vec2i(game->interface.screen.size.x * 0.5, game->interface.screen.size.y);
	entity_sprite_args1(&entity_args, NULL, animation, anchor);
	entity_sprite_args2(&entity_args, ft_vec2f(0, 0), ft_vec2f(0, 0));
	entity_sprite_args3(&entity_args, game, display);
	sprite = create_sprite(entity_args);
	if (!(set_shootgun_fire_sprite_textures(game, sprite)))
		return (throw_error("add shootgun_fire", "failed to set textures"));
	sprite->super.texture.t = sprite->textures.front;
	sprite->super.texture.t_head = sprite->textures.front;
	bind_key(&game->interface.keys_bind, SDLK_SPACE, &sprite->super,
		trigger_animation);
	bind_key(&game->interface.keys_bind, SDLK_TAB, &sprite->super,
		toggle_display_entity);
	return (OK);
}

static t_result	add_shootgun_reload_sprite(t_game *game, t_bool display,
					t_animation_status animation)
{
	t_sprite			*sprite;
	t_entity_args		entity_args;
	t_vec2i				anchor;

	anchor = ft_vec2i(game->interface.screen.size.x * 0.5, game->interface.screen.size.y);
	entity_sprite_args1(&entity_args, NULL, animation, anchor);
	entity_sprite_args2(&entity_args, ft_vec2f(0, 0), ft_vec2f(0, 0));
	entity_sprite_args3(&entity_args, game, display);
	sprite = create_sprite(entity_args);
	if (!(set_shootgun_reload_sprite_textures(game, sprite)))
		return (throw_error("add shootgun_reload", "failed to set textures"));
	sprite->super.texture.t = sprite->textures.front;
	sprite->super.texture.t_head = sprite->textures.front;
	bind_key(&game->interface.keys_bind, SDLK_SPACE, &sprite->super,
		trigger_animation);
	return (OK);
}

t_result	initialize_sprites_entities(t_game *game)
{
	if (!(add_pistol_fire_sprite(game, FALSE, IN_PROGRESS)))
		return (throw_error("initialize_sprites", "pistol fire sprite failed"));
	if (!(add_shootgun_fire_sprite(game, TRUE, IN_PROGRESS)))
		return (throw_error("initialize_sprites", "shootgun fire sprite fail"));
	if (!(add_shootgun_reload_sprite(game, FALSE, IN_PROGRESS)))
		return (throw_error("initialize_sprites", "shootgun reload fail"));
	return (OK);
}
