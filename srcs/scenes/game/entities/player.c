/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 00:28:13 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/19 02:41:28 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/scenes/build_scene.h"
#include "engine/entities/build_player.h"
#include "engine/entities/update_player.h"
#include "engine/resources/textures/texture.h"
#include "events/keyboard.h"
#include "utils/error.h"

t_result	add_pistol_weapon(t_scene *scene, t_player *player)
{
	t_weapon				*weapon;
	t_texture				*texture;
	t_list_head				*images;
	t_texture_args			args;

	args.offset = ft_vec2i(-125, -300);
	args.size = ft_usize(300, 300);
	args.delay_ms = 100;
	images = &scene->resources.images;
	if (!(weapon = build_weapon("pistol", GUN)))
		return (throw_error("add_pistol", "fail to build weapon"));
	if (!add_texture(&weapon->fire, images, "pistol_fire1", args))
		return (throw_error("add_pistol_weapon", "add_texture pf1 failed"));
	if (!add_texture(&weapon->fire, images, "pistol_fire2", args))
		return (throw_error("add_pistol_weapon", "add_texture pf2 failed"));
	if (!add_texture(&weapon->fire, images, "pistol_fire3", args))
		return (throw_error("add_pistol_weapon", "add_texture pf3 failed"));
	if (!add_texture(&weapon->fire, images, "pistol_reload1", args))
		return (throw_error("add_pistol_weapon", "add_texture pr1 failed"));
	if (!add_texture(&weapon->fire, images, "pistol_reload2", args))
		return (throw_error("add_pistol_weapon", "add_texture pr2 failed"));
	if (!add_texture(&weapon->fire, images, "pistol_reload3", args))
		return (throw_error("add_pistol_weapon", "add_texture pr3 failed"));
	if (!add_texture(&weapon->fire, images, "pistol_reload4", args))
		return (throw_error("add_pistol_weapon", "add_texture pr4 failed"));
	return (OK);
}

t_result	add_shootgun_weapon(t_scene *scene, t_player *player)
{
	t_weapon				*weapon;
	t_texture				*texture;
	t_list_head				*images;
	t_texture_args			args;

	args.offset = ft_vec2i(-125, -300);
	args.size = ft_usize(300, 300);
	args.delay_ms = 100;
	images = &scene->resources.images;
	if (!(weapon = build_weapon("shootgun", GUN)))
		return (throw_error("add_shootgun", "fail to build weapon"));
	if (!add_texture(&weapon->fire, images, "shootgun_fire1", args))
		return (throw_error("add_shootgun_weapon", "add_texture sf1 failed"));
	if (!add_texture(&weapon->fire, images, "shootgun_fire2", args))
		return (throw_error("add_shootgun_weapon", "add_texture sf2 failed"));
	if (!add_texture(&weapon->fire, images, "shootgun_fire3", args))
		return (throw_error("add_shootgun_weapon", "add_texture sf3 failed"));
	if (!add_texture(&weapon->fire, images, "shootgun_fire4", args))
		return (throw_error("add_shootgun_weapon", "add_texture sf4 failed"));
	if (!add_texture(&weapon->fire, images, "shootgun_reload1", args))
		return (throw_error("add_shootgun_weapon", "add_texture sr1 failed"));
	if (!add_texture(&weapon->fire, images, "shootgun_reload2", args))
		return (throw_error("add_shootgun_weapon", "add_texture sr2 failed"));
	if (!add_texture(&weapon->fire, images, "shootgun_reload3", args))
		return (throw_error("add_shootgun_weapon", "add_texture sr3 failed"));
	return (OK);
}

t_player	*init_player(t_scene *scene)
{
	t_player		*player;
	t_usize			screen;

	screen = scene->interface.screen_ref->size;
	if (!(player = build_player()))
		return (throw_null("init_player", "failed to create player"));
	if(!add_pistol_weapon(scene, player))
		return (throw_null("init_player", "failed to add pistol"));
	if(!add_shootgun_weapon(scene, player))
		return (throw_null("init_player", "failed to add shootgun"));
	if (!(build_player_entity_listener(&player->super,
		&scene->renderer.ui_components, &scene->entities.ui_components, TRUE)));
		return (throw_null("init_player", "failed to init entity"));
	if (!build_player_camera(&player->cam, 90.0f / 180.0f * PI,
		screen.x, screen.y / 4.0f));
		return (throw_null("init_player", "failed to init camera"));
	scene->renderer.cam_ref = &player->cam;
	bind_key(&scene->interface.keys_binds, SDLK_TAB, &player->super, weapon_next);
	bind_key(&scene->interface.keys_binds, SDLK_SPACE, &player->super, weapon_fire);
	bind_key(&scene->interface.keys_binds, SDLK_r, &player->super, weapon_reload);
	bind_key(&scene->interface.keys_binds, SDLK_LEFT, &player->super, rotate_camera_left);
	bind_key(&scene->interface.keys_binds, SDLK_RIGHT, &player->super, rotate_camera_right);
	bind_key(&scene->interface.keys_binds, SDLK_w, &player->super, translate_camera_forward);
	bind_key(&scene->interface.keys_binds, SDLK_a, &player->super, translate_camera_left);
	bind_key(&scene->interface.keys_binds, SDLK_d, &player->super, translate_camera_right);
	bind_key(&scene->interface.keys_binds, SDLK_s, &player->super, translate_camera_backward);
	return (player);
}