/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 00:28:13 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/16 08:34:56 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "entities/player.h"
#include "utils/error.h"
#include "events/keyboard.h"

t_result	initialize_player_entity_texture(t_screen screen, t_player *player)
{
	t_entity_texture_args	args;

	args.anchor = ft_vec2i(screen.size.x / 2, screen.size.y);
	args.animation = STOP;
	args.texture = player->weapons->fire;
	args.update_texture = NULL;
	build_player_entity_texture(&player->super.texture, args);
	return (OK);
}

t_result	initialize_player_entity(t_game *game, t_player *player)
{
	t_entity_args	args;

	initialize_player_entity_texture(game->interface.screen, player);
	build_player_listener(&player->super.status, &game->renderer.sprites,
		&game->entities.sprites, TRUE);
	args.dir = ft_vec2f(0, 1);
	args.pos = ft_vec2f(0, 1);
	args.type = PLAYER;
	build_player_entity(&player->super, args);
	return (OK);
}

t_result	initialize_player_camera(t_game *game, t_camera *self)
{
	t_camera_args	args;

	args.fov = 90.0f / 180.0f * PI;
	args.plan_width = (float)game->interface.screen.size.x;
	args.height = (float)game->interface.screen.size.y / 2.0f;
	build_player_camera(self, args);
	return (OK);
}

t_result	add_pistol_weapon(t_game *game, t_player *player)
{
	t_weapon		*weapon;
	t_texture_args	args;
	t_vec2i			offset;
	t_usize			size;

	offset = ft_vec2i(-125, -300);
	size = ft_usize(300, 300);
	if (!(weapon = add_weapon(&player->weapons, ft_strdup("pistol"), GUN)))
		return (throw_error("add_pistol", "fail to add weapon"));
	if (player->weapons == NULL)
		ft_putstr("NULL\n");
	args = texture_args(ft_strdup("pistol_fire1"), offset, size, 50);
	if (!add_texture(game, &weapon->fire, args))
		return (throw_error("add_pistol", "fail to add texture on weapon"));
	args = texture_args(ft_strdup("pistol_fire2"), offset, size, 50);
	if (!add_texture(game, &weapon->fire, args))
		return (throw_error("add_pistol", "fail to add texture on weapon"));
	args = texture_args(ft_strdup("pistol_fire3"), offset, size, 50);
	if (!add_texture(game, &weapon->fire, args))
		return (throw_error("add_pistol", "fail to add texture on weapon"));
	offset = ft_vec2i(20, -300);
	args = texture_args(ft_strdup("pistol_reload1"), offset, size, 100);
	if (!add_texture(game, &weapon->reload, args))
		return (throw_error("add_pistol", "fail to add texture on weapon"));
	args = texture_args(ft_strdup("pistol_reload2"), offset, size, 100);
	if (!add_texture(game, &weapon->reload, args))
		return (throw_error("add_pistol", "fail to add texture on weapon"));
	args = texture_args(ft_strdup("pistol_reload3"), offset, size, 100);
	if (!add_texture(game, &weapon->reload, args))
		return (throw_error("add_pistol", "fail to add texture on weapon"));
	args = texture_args(ft_strdup("pistol_reload4"), offset, size, 100);
	if (!add_texture(game, &weapon->reload, args))
		return (throw_error("add_pistol", "fail to add texture on weapon"));
	return (OK);
}

t_result	add_shootgun_weapon(t_game *game, t_player *player)
{
	t_weapon		*weapon;
	t_texture_args	args;
	t_vec2i			offset;
	t_usize			size;

	offset = ft_vec2i(-125, -300);
	size = ft_usize(300, 300);
	if (!(weapon = add_weapon(&player->weapons, ft_strdup("shootgun"), GUN)))
		return (throw_error("add_shootgun", "fail to add weapon"));
	args = texture_args(ft_strdup("shootgun_fire1"), offset, size, 50);
	if (!add_texture(game, &weapon->fire, args))
		return (throw_error("add_shootgun", "fail to add texture on weapon"));
	args = texture_args(ft_strdup("shootgun_fire2"), offset, size, 50);
	if (!add_texture(game, &weapon->fire, args))
		return (throw_error("add_shootgun", "fail to add texture on weapon"));
	args = texture_args(ft_strdup("shootgun_fire3"), offset, size, 50);
	if (!add_texture(game, &weapon->fire, args))
		return (throw_error("add_shootgun", "fail to add texture on weapon"));
	args = texture_args(ft_strdup("shootgun_fire4"), offset, size, 50);
	if (!add_texture(game, &weapon->fire, args))
		return (throw_error("add_shootgun", "fail to add texture on weapon"));
	args = texture_args(ft_strdup("shootgun_reload1"), offset, size, 100);
	if (!add_texture(game, &weapon->reload, args))
		return (throw_error("add_shootgun", "fail to add texture on weapon"));
	args = texture_args(ft_strdup("shootgun_reload2"), offset, size, 100);
	if (!add_texture(game, &weapon->reload, args))
		return (throw_error("add_shootgun", "fail to add texture on weapon"));
	args = texture_args(ft_strdup("shootgun_reload3"), offset, size, 100);
	if (!add_texture(game, &weapon->reload, args))
		return (throw_error("add_shootgun", "fail to add texture on weapon"));
	return (OK);
}

t_result	initialize_player(t_game *game)
{
	t_player		*player;

	if (!(player = create_player()))
		return (throw_error("init_player", "failed to create player"));
	if(!add_pistol_weapon(game, player))
		return (throw_error("init_player", "failed to add pistol"));
	if(!add_shootgun_weapon(game, player))
		return (throw_error("init_player", "failed to add shootgun"));
	if (!(initialize_player_entity(game, player)))
		return (throw_error("init_player", "failed to init entity"));
	if (!initialize_player_camera(game, &player->cam))
		return (throw_error("init_player", "failed to init camera"));
	bind_key(&game->interface.keys_bind, SDLK_TAB, &player->super, weapon_next);
	bind_key(&game->interface.keys_bind, SDLK_SPACE, &player->super, weapon_fire);
	bind_key(&game->interface.keys_bind, SDLK_r, &player->super, weapon_reload);
	update_weapon_ammo(player->weapons, 20);
	return (OK);
}