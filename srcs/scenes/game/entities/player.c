/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 00:28:13 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/20 05:41:57 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/scenes/init_scene.h"
#include "engine/entities/init_player.h"
#include "engine/entities/update_player.h"
#include "engine/resources/textures/texture.h"
#include "engine/interface/events/keyboard.h"
#include "utils/error.h"

t_result	build_current_player_weapon(t_scene *scene, t_player *player,
				t_weapon *weapon)
{
	t_vec2i		anchor;

	if (scene == NULL || player == NULL || weapon == NULL)
		return (throw_error ("build_curr_weapon", "NULL pointer provided"));
	overwrite_current_player_weapon(&player->weapon, weapon);
	anchor.x = scene->interface.screen_ref->size.x / 2;
	anchor.y = scene->interface.screen_ref->size.y;
	overwrite_player_entity_texture(&player->super.texture, &weapon->fire,
		anchor);
	return (OK);
}

t_weapon	*add_pistol_weapon(t_scene *scene)
{
	t_weapon				*weapon;
	t_list_head				*images;
	t_texture_args			args;

	args.offset = ft_vec2i(0, -300);
	args.size = ft_usize(300, 300);
	args.delay_ms = 100;
	images = &scene->resources.images;
	if (!(weapon = init_new_weapon("pistol", GUN)))
		return (throw_null("add_pistol", "fail to build weapon"));
	if (!add_texture(&weapon->fire, images, "pistol_fire1", args))
		return (throw_null("add_pistol_weapon", "add_texture pf1 failed"));
	if (!add_texture(&weapon->fire, images, "pistol_fire2", args))
		return (throw_null("add_pistol_weapon", "add_texture pf2 failed"));
	if (!add_texture(&weapon->fire, images, "pistol_fire3", args))
		return (throw_null("add_pistol_weapon", "add_texture pf3 failed"));
	if (!add_texture(&weapon->reload, images, "pistol_reload1", args))
		return (throw_null("add_pistol_weapon", "add_texture pr1 failed"));
	if (!add_texture(&weapon->reload, images, "pistol_reload2", args))
		return (throw_null("add_pistol_weapon", "add_texture pr2 failed"));
	if (!add_texture(&weapon->reload, images, "pistol_reload3", args))
		return (throw_null("add_pistol_weapon", "add_texture pr3 failed"));
	if (!add_texture(&weapon->reload, images, "pistol_reload4", args))
		return (throw_null("add_pistol_weapon", "add_texture pr4 failed"));
	return (weapon);
}

t_weapon	*add_shootgun_weapon(t_scene *scene)
{
	t_weapon				*weapon;
	t_list_head				*images;
	t_texture_args			args;

	args.offset = ft_vec2i(0, -300);
	args.size = ft_usize(300, 300);
	args.delay_ms = 100;
	images = &scene->resources.images;
	if (!(weapon = init_new_weapon("shootgun", GUN)))
		return (throw_null("add_shootgun", "fail to build weapon"));
	if (!add_texture(&weapon->fire, images, "shootgun_fire1", args))
		return (throw_null("add_shootgun_weapon", "add_texture sf1 failed"));
	if (!add_texture(&weapon->fire, images, "shootgun_fire2", args))
		return (throw_null("add_shootgun_weapon", "add_texture sf2 failed"));
	if (!add_texture(&weapon->fire, images, "shootgun_fire3", args))
		return (throw_null("add_shootgun_weapon", "add_texture sf3 failed"));
	if (!add_texture(&weapon->fire, images, "shootgun_fire4", args))
		return (throw_null("add_shootgun_weapon", "add_texture sf4 failed"));
	if (!add_texture(&weapon->reload, images, "shootgun_reload1", args))
		return (throw_null("add_shootgun_weapon", "add_texture sr1 failed"));
	if (!add_texture(&weapon->reload, images, "shootgun_reload2", args))
		return (throw_null("add_shootgun_weapon", "add_texture sr2 failed"));
	if (!add_texture(&weapon->reload, images, "shootgun_reload3", args))
		return (throw_null("add_shootgun_weapon", "add_texture sr3 failed"));
	return (weapon);
}

t_result	build_player_weapons(t_scene *scene, t_player *player)
{
	t_weapon	*weapon;

	if(!(weapon = add_pistol_weapon(scene)))
		return (throw_error("build_player", "failed to add pistol"));
	list_add_entry(&weapon->node, &player->weapon.list);
	build_current_player_weapon(scene, player, weapon);
	if(!(weapon = add_shootgun_weapon(scene)))
		return (throw_error("build_player", "failed to add shootgun"));
	list_add_entry(&weapon->node, &player->weapon.list);
	return (OK);
}

t_result	build_player_bindings(t_scene *scene, t_player *player)
{
	bind_key(&scene->interface.key_binds, SDLK_TAB, &player->super, weapon_next);
	bind_key(&scene->interface.key_binds, SDLK_SPACE, &player->super, weapon_fire);
	bind_key(&scene->interface.key_binds, SDLK_r, &player->super, weapon_reload);
	bind_key(&scene->interface.key_hold_binds, SDLK_LEFT, &player->super, rotate_camera_left);
	bind_key(&scene->interface.key_hold_binds, SDLK_RIGHT, &player->super, rotate_camera_right);
	bind_key(&scene->interface.key_hold_binds, SDLK_w, &player->super, translate_camera_forward);
	bind_key(&scene->interface.key_hold_binds, SDLK_a, &player->super, translate_camera_left);
	bind_key(&scene->interface.key_hold_binds, SDLK_d, &player->super, translate_camera_right);
	bind_key(&scene->interface.key_hold_binds, SDLK_s, &player->super, translate_camera_backward);
	return (OK);
}

t_player	*build_game_player(t_scene *scene)
{
	t_player		*player;
	t_usize			screen;
	float			fov;

	fov = 90.0f / 180.0f * PI;
	screen = scene->interface.screen_ref->size;
	if (!(player = init_new_player()))
		return (throw_null("build_player", "failed to create player"));
	if (!build_player_weapons(scene, player))
		return (throw_null("build_player", "failed to init camera"));
	if (!(overwrite_player_entity_listener(&player->super,
		&scene->renderer.ui_components, &scene->entities.ui_components, TRUE)))
		return (throw_null("build_player", "failed to init entity"));
	if (!init_camera(&player->cam))
		return (throw_null("build_player", "failed to init camera"));
	link_camera_to_entity(&player->cam, &player->super.pos, &player->super.dir);
	overwrite_camera_plan(&player->cam, fov, screen.x, screen.y / 4);
	build_player_bindings(scene, player);
	overwrite_player_coordinates(player, ft_vec2f(10, 10), ft_vec2f(0, -1));
	return (player);
}
