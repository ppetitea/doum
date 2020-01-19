/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 00:28:13 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/19 02:44:55 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entities/sprites/update_ennemy.h"
#include "engine/entities/sprites/build_ennemy.h"
#include "engine/resources/textures/texture.h"
#include "engine/scenes/build_scene.h"
#include "events/keyboard.h"
#include "utils/error.h"

t_result	add_ennemy_front_texture(t_scene *scene, t_ennemy *ennemy)
{
	t_texture_args	args;
	t_list_head		*images;
	t_list_head		*textures;

	images = &scene->resources.images;
	textures = &ennemy->orientation.front;
	args.offset = ft_vec2i(-100, -130);
	args.size = ft_usize(200, 130);
	args.delay_ms = 200;
	if (!add_texture(textures, images, "ennemy_front1", args))
		return (throw_error("add_ennemy", "fail to add ennemy front1 texture"));
	if (!add_texture(textures, images, "ennemy_front2", args))
		return (throw_error("add_ennemy", "fail to add ennemy front2 texture"));
	if (!add_texture(textures, images, "ennemy_front3", args))
		return (throw_error("add_ennemy", "fail to add ennemy front3 texture"));
	if (!add_texture(textures, images, "ennemy_front4", args))
		return (throw_error("add_ennemy", "fail to add ennemy front4 texture"));
	return (OK);
}

t_result	add_ennemy_front_right_texture(t_scene *scene, t_ennemy *ennemy)
{
	t_texture_args	args;
	t_list_head		*images;
	t_list_head		*textures;

	images = &scene->resources.images;
	textures = &ennemy->orientation.front_r;
	args.offset = ft_vec2i(-100, -130);
	args.size = ft_usize(200, 130);
	args.delay_ms = 200;
	if (!add_texture(textures, images, "ennemy_front_r1", args))
		return (throw_error("add_ennemy", "fail to add ennemy front_r1 texture"));
	if (!add_texture(textures, images, "ennemy_front_r2", args))
		return (throw_error("add_ennemy", "fail to add ennemy front_r2 texture"));
	if (!add_texture(textures, images, "ennemy_front_r3", args))
		return (throw_error("add_ennemy", "fail to add ennemy front_r3 texture"));
	if (!add_texture(textures, images, "ennemy_front_r4", args))
		return (throw_error("add_ennemy", "fail to add ennemy front_r4 texture"));
	return (OK);
}

t_result	add_ennemy_front_left_texture(t_scene *scene, t_ennemy *ennemy)
{
	t_texture_args	args;
	t_list_head		*images;
	t_list_head		*textures;

	images = &scene->resources.images;
	textures = &ennemy->orientation.front_l;
	args.offset = ft_vec2i(-100, -130);
	args.size = ft_usize(200, 130);
	args.delay_ms = 200;
	if (!add_texture(textures, images, "ennemy_front_l1", args))
		return (throw_error("add_ennemy", "fail to add ennemy front_l1 texture"));
	if (!add_texture(textures, images, "ennemy_front_l2", args))
		return (throw_error("add_ennemy", "fail to add ennemy front_l2 texture"));
	if (!add_texture(textures, images, "ennemy_front_l3", args))
		return (throw_error("add_ennemy", "fail to add ennemy front_l3 texture"));
	if (!add_texture(textures, images, "ennemy_front_l4", args))
		return (throw_error("add_ennemy", "fail to add ennemy front_l4 texture"));
	return (OK);
}

t_result	add_ennemy_right_texture(t_scene *scene, t_ennemy *ennemy)
{
	t_texture_args	args;
	t_list_head		*images;
	t_list_head		*textures;

	images = &scene->resources.images;
	textures = &ennemy->orientation.right;
	args.offset = ft_vec2i(-100, -130);
	args.size = ft_usize(200, 130);
	args.delay_ms = 200;
	if (!add_texture(textures, images, "ennemy_right1", args))
		return (throw_error("add_ennemy", "fail to add ennemy right1 texture"));
	if (!add_texture(textures, images, "ennemy_right2", args))
		return (throw_error("add_ennemy", "fail to add ennemy right2 texture"));
	if (!add_texture(textures, images, "ennemy_right3", args))
		return (throw_error("add_ennemy", "fail to add ennemy right3 texture"));
	return (OK);
}

t_result	add_ennemy_left_texture(t_scene *scene, t_ennemy *ennemy)
{
	t_texture_args	args;
	t_list_head		*images;
	t_list_head		*textures;

	images = &scene->resources.images;
	textures = &ennemy->orientation.left;
	args.offset = ft_vec2i(-100, -130);
	args.size = ft_usize(200, 130);
	args.delay_ms = 200;
	if (!add_texture(textures, images, "ennemy_left1", args))
		return (throw_error("add_ennemy", "fail to add ennemy left1 texture"));
	if (!add_texture(textures, images, "ennemy_left2", args))
		return (throw_error("add_ennemy", "fail to add ennemy left2 texture"));
	if (!add_texture(textures, images, "ennemy_left3", args))
		return (throw_error("add_ennemy", "fail to add ennemy left3 texture"));
	return (OK);
}

t_result	add_ennemy_back_texture(t_scene *scene, t_ennemy *ennemy)
{
	t_texture_args	args;
	t_list_head		*images;
	t_list_head		*textures;

	images = &scene->resources.images;
	textures = &ennemy->orientation.back;
	args.offset = ft_vec2i(-100, -130);
	args.size = ft_usize(200, 130);
	args.delay_ms = 200;
	if (!add_texture(textures, images, "ennemy_back1", args))
		return (throw_error("add_ennemy", "fail to add ennemy back1 texture"));
	if (!add_texture(textures, images, "ennemy_back2", args))
		return (throw_error("add_ennemy", "fail to add ennemy back2 texture"));
	if (!add_texture(textures, images, "ennemy_back3", args))
		return (throw_error("add_ennemy", "fail to add ennemy back3 texture"));
	if (!add_texture(textures, images, "ennemy_back4", args))
		return (throw_error("add_ennemy", "fail to add ennemy back4 texture"));
	return (OK);
}
t_result	add_ennemy_back_right_texture(t_scene *scene, t_ennemy *ennemy)
{
	t_texture_args	args;
	t_list_head		*images;
	t_list_head		*textures;

	images = &scene->resources.images;
	textures = &ennemy->orientation.back_r;
	args.offset = ft_vec2i(-100, -130);
	args.size = ft_usize(200, 130);
	args.delay_ms = 200;
	if (!add_texture(textures, images, "ennemy_back_r1", args))
		return (throw_error("add_ennemy", "fail to add ennemy back_r1 texture"));
	if (!add_texture(textures, images, "ennemy_back_r2", args))
		return (throw_error("add_ennemy", "fail to add ennemy back_r2 texture"));
	if (!add_texture(textures, images, "ennemy_back_r3", args))
		return (throw_error("add_ennemy", "fail to add ennemy back_r3 texture"));
	if (!add_texture(textures, images, "ennemy_back_r4", args))
		return (throw_error("add_ennemy", "fail to add ennemy back_r4 texture"));
	return (OK);
}

t_result	add_ennemy_back_left_texture(t_scene *scene, t_ennemy *ennemy)
{
	t_texture_args	args;
	t_list_head		*images;
	t_list_head		*textures;

	images = &scene->resources.images;
	textures = &ennemy->orientation.back_l;
	args.offset = ft_vec2i(-100, -130);
	args.size = ft_usize(200, 130);
	args.delay_ms = 200;
	if (!add_texture(textures, images, "ennemy_back_l1", args))
		return (throw_error("add_ennemy", "fail to add ennemy back_l1 texture"));
	if (!add_texture(textures, images, "ennemy_back_l2", args))
		return (throw_error("add_ennemy", "fail to add ennemy back_l2 texture"));
	if (!add_texture(textures, images, "ennemy_back_l3", args))
		return (throw_error("add_ennemy", "fail to add ennemy back_l3 texture"));
	if (!add_texture(textures, images, "ennemy_back_l4", args))
		return (throw_error("add_ennemy", "fail to add ennemy back_l4 texture"));
	return (OK);
}

t_result	add_ennemy_attack_texture(t_scene *scene, t_ennemy *ennemy)
{
	t_texture_args	args;
	t_list_head		*images;
	t_list_head		*textures;

	images = &scene->resources.images;
	textures = &ennemy->attack;
	args.offset = ft_vec2i(-100, -130);
	args.size = ft_usize(200, 130);
	args.delay_ms = 200;
	if (!add_texture(textures, images, "ennemy_attack1", args))
		return (throw_error("add_ennemy", "fail to add ennemy attack1 texture"));
	if (!add_texture(textures, images, "ennemy_attack2", args))
		return (throw_error("add_ennemy", "fail to add ennemy attack2 texture"));
	if (!add_texture(textures, images, "ennemy_attack3", args))
		return (throw_error("add_ennemy", "fail to add ennemy attack3 texture"));
	return (OK);
}

t_result	add_ennemy_die_texture(t_scene *scene, t_ennemy *ennemy)
{
	t_texture_args	args;
	t_list_head		*images;
	t_list_head		*textures;

	images = &scene->resources.images;
	textures = &ennemy->die;
	args.offset = ft_vec2i(-100, -130);
	args.size = ft_usize(200, 130);
	args.delay_ms = 200;
	if (!add_texture(textures, images, "ennemy_die1", args))
		return (throw_error("add_ennemy", "fail to add ennemy die1 texture"));
	if (!add_texture(textures, images, "ennemy_die2", args))
		return (throw_error("add_ennemy", "fail to add ennemy die2 texture"));
	if (!add_texture(textures, images, "ennemy_die3", args))
		return (throw_error("add_ennemy", "fail to add ennemy die3 texture"));
	if (!add_texture(textures, images, "ennemy_die4", args))
		return (throw_error("add_ennemy", "fail to add ennemy die4 texture"));
	if (!add_texture(textures, images, "ennemy_die5", args))
		return (throw_error("add_ennemy", "fail to add ennemy die5 texture"));
	if (!add_texture(textures, images, "ennemy_die6", args))
		return (throw_error("add_ennemy", "fail to add ennemy die6 texture"));
	if (!add_texture(textures, images, "ennemy_die7", args))
		return (throw_error("add_ennemy", "fail to add ennemy die7 texture"));
	if (!add_texture(textures, images, "ennemy_die8", args))
		return (throw_error("add_ennemy", "fail to add ennemy die8 texture"));
	if (!add_texture(textures, images, "ennemy_die9", args))
		return (throw_error("add_ennemy", "fail to add ennemy die9 texture"));
	if (!add_texture(textures, images, "ennemy_die10", args))
		return (throw_error("add_ennemy", "fail to add ennemy die10 texture"));
	return (OK);
}

t_result	init_ennemy(t_scene *scene, t_player *player)
{ 
	t_ennemy		*ennemy;
	t_usize			screen;

	screen = scene->interface.screen_ref->size;
	if (!(ennemy = build_ennemy(player)))
		return (throw_error("init_ennemy", "failed to create ennemy"));
	if (!add_ennemy_front_texture(scene, ennemy))
		return (throw_error("init_ennemy", "failed to add front texture"));
	if (!add_ennemy_front_right_texture(scene, ennemy))
		return (throw_error("init_ennemy", "failed to add front texture"));
	if (!add_ennemy_front_left_texture(scene, ennemy))
		return (throw_error("init_ennemy", "failed to add front texture"));
	if (!add_ennemy_right_texture(scene, ennemy))
		return (throw_error("init_ennemy", "failed to add right texture"));
	if (!add_ennemy_back_texture(scene, ennemy))
		return (throw_error("init_ennemy", "failed to add back texture"));
	if (!add_ennemy_back_right_texture(scene, ennemy))
		return (throw_error("init_ennemy", "failed to add back texture"));
	if (!add_ennemy_back_left_texture(scene, ennemy))
		return (throw_error("init_ennemy", "failed to add back texture"));
	if (!add_ennemy_left_texture(scene, ennemy))
		return (throw_error("init_ennemy", "failed to add left texture"));
	if (!add_ennemy_attack_texture(scene, ennemy))
		return (throw_error("init_ennemy", "failed to add attack texture"));
	if (!add_ennemy_die_texture(scene, ennemy))
		return (throw_error("init_ennemy", "failed to add die texture"));
	if (!(initialize_ennemy_entity(scene, ennemy)))
		return (throw_error("init_ennemy", "failed to init entity"));
	if (!build_ennemy_entity_listener(&ennemy->super,
		&scene->renderer.sprites, &scene->entities.sprites, TRUE))
		return (throw_error("init_ennemy", "failed to build listener"));
		
	update_ennemy_texture_by_direction(ennemy);
	bind_key(&scene->interface.keys_binds, SDLK_KP_8, &ennemy->super, ennemy_move_forward);
	bind_key(&scene->interface.keys_binds, SDLK_KP_2, &ennemy->super, ennemy_move_backward);
	bind_key(&scene->interface.keys_binds, SDLK_KP_4, &ennemy->super, ennemy_turn_right);
	bind_key(&scene->interface.keys_binds, SDLK_KP_6, &ennemy->super, ennemy_turn_left);
	bind_key(&scene->interface.keys_binds, SDLK_KP_5, &ennemy->super, ennemy_attack);
	bind_key(&scene->interface.keys_binds, SDLK_KP_0, &ennemy->super, ennemy_die);
	bind_key(&scene->interface.keys_binds, SDLK_w, &ennemy->super, update_ennemy_texture);
	bind_key(&scene->interface.keys_binds, SDLK_a, &ennemy->super, update_ennemy_texture);
	bind_key(&scene->interface.keys_binds, SDLK_s, &ennemy->super, update_ennemy_texture);
	bind_key(&scene->interface.keys_binds, SDLK_d, &ennemy->super, update_ennemy_texture);
	return (OK);
}