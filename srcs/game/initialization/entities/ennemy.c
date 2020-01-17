/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 00:28:13 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/17 19:37:30 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "entities/sprites/ennemies.h"
#include "utils/error.h"
#include "events/keyboard.h"

t_result	add_ennemy_front_texture(t_game *game, t_ennemy *ennemy)
{
	t_texture_args	args;
	t_vec2i			offset;
	t_usize			size;

	offset = ft_vec2i(-100, -130);
	size = ft_usize(200, 130);
	args = texture_args(ft_strdup("ennemy_front1"), offset, size, 200);
	if (!add_texture(game, &ennemy->orientation.front, args))
		return (throw_error("add_ennemy", "fail to add ennemy front texture"));
	args = texture_args(ft_strdup("ennemy_front2"), offset, size, 200);
	if (!add_texture(game, &ennemy->orientation.front, args))
		return (throw_error("add_ennemy", "fail to add ennemy front texture"));
	args = texture_args(ft_strdup("ennemy_front3"), offset, size, 200);
	if (!add_texture(game, &ennemy->orientation.front, args))
		return (throw_error("add_ennemy", "fail to add ennemy front texture"));
	args = texture_args(ft_strdup("ennemy_front4"), offset, size, 200);
	if (!add_texture(game, &ennemy->orientation.front, args))
		return (throw_error("add_ennemy", "fail to add ennemy front texture"));
	return (OK);
}

t_result	add_ennemy_right_texture(t_game *game, t_ennemy *ennemy)
{
	t_texture_args	args;
	t_vec2i			offset;
	t_usize			size;

	offset = ft_vec2i(-100, -130);
	size = ft_usize(200, 130);
	args = texture_args(ft_strdup("ennemy_right1"), offset, size, 200);
	if (!add_texture(game, &ennemy->orientation.right, args))
		return (throw_error("add_ennemy", "fail to add ennemy right texture"));
	args = texture_args(ft_strdup("ennemy_right2"), offset, size, 200);
	if (!add_texture(game, &ennemy->orientation.right, args))
		return (throw_error("add_ennemy", "fail to add ennemy right texture"));
	args = texture_args(ft_strdup("ennemy_right3"), offset, size, 200);
	if (!add_texture(game, &ennemy->orientation.right, args))
		return (throw_error("add_ennemy", "fail to add ennemy right texture"));
	return (OK);
}

t_result	add_ennemy_back_texture(t_game *game, t_ennemy *ennemy)
{
	t_texture_args	args;
	t_vec2i			offset;
	t_usize			size;

	offset = ft_vec2i(-100, -130);
	size = ft_usize(200, 130);
	args = texture_args(ft_strdup("ennemy_back1"), offset, size, 200);
	if (!add_texture(game, &ennemy->orientation.back, args))
		return (throw_error("add_ennemy", "fail to add ennemy back texture"));
	args = texture_args(ft_strdup("ennemy_back2"), offset, size, 200);
	if (!add_texture(game, &ennemy->orientation.back, args))
		return (throw_error("add_ennemy", "fail to add ennemy back texture"));
	args = texture_args(ft_strdup("ennemy_back3"), offset, size, 200);
	if (!add_texture(game, &ennemy->orientation.back, args))
		return (throw_error("add_ennemy", "fail to add ennemy back texture"));
	args = texture_args(ft_strdup("ennemy_back4"), offset, size, 200);
	if (!add_texture(game, &ennemy->orientation.back, args))
		return (throw_error("add_ennemy", "fail to add ennemy back texture"));
	return (OK);
}

t_result	add_ennemy_left_texture(t_game *game, t_ennemy *ennemy)
{
	t_texture_args	args;
	t_vec2i			offset;
	t_usize			size;

	offset = ft_vec2i(-100, -130);
	size = ft_usize(200, 130);
	args = texture_args(ft_strdup("ennemy_left1"), offset, size, 200);
	if (!add_texture(game, &ennemy->orientation.left, args))
		return (throw_error("add_ennemy", "fail to add ennemy left texture"));
	args = texture_args(ft_strdup("ennemy_left2"), offset, size, 200);
	if (!add_texture(game, &ennemy->orientation.left, args))
		return (throw_error("add_ennemy", "fail to add ennemy left texture"));
	args = texture_args(ft_strdup("ennemy_left3"), offset, size, 200);
	if (!add_texture(game, &ennemy->orientation.left, args))
		return (throw_error("add_ennemy", "fail to add ennemy left texture"));
	return (OK);
}

t_result	add_ennemy_attack_texture(t_game *game, t_ennemy *ennemy)
{
	t_texture_args	args;
	t_vec2i			offset;
	t_usize			size;

	offset = ft_vec2i(-100, -130);
	size = ft_usize(200, 130);
	args = texture_args(ft_strdup("ennemy_attack1"), offset, size, 200);
	if (!add_texture(game, &ennemy->attack, args))
		return (throw_error("add_ennemy", "fail to add ennemy attack texture"));
	args = texture_args(ft_strdup("ennemy_attack2"), offset, size, 200);
	if (!add_texture(game, &ennemy->attack, args))
		return (throw_error("add_ennemy", "fail to add ennemy attack texture"));
	args = texture_args(ft_strdup("ennemy_attack3"), offset, size, 200);
	if (!add_texture(game, &ennemy->attack, args))
		return (throw_error("add_ennemy", "fail to add ennemy attack texture"));
	return (OK);
}

t_result	add_ennemy_die_texture(t_game *game, t_ennemy *ennemy)
{
	t_texture_args	args;
	t_vec2i			offset;
	t_usize			size;

	offset = ft_vec2i(-100, -130);
	size = ft_usize(200, 130);
	args = texture_args(ft_strdup("ennemy_die1"), offset, size, 200);
	if (!add_texture(game, &ennemy->die, args))
		return (throw_error("add_ennemy", "fail to add ennemy die texture"));
	args = texture_args(ft_strdup("ennemy_die2"), offset, size, 200);
	if (!add_texture(game, &ennemy->die, args))
		return (throw_error("add_ennemy", "fail to add ennemy die texture"));
	args = texture_args(ft_strdup("ennemy_die3"), offset, size, 200);
	if (!add_texture(game, &ennemy->die, args))
		return (throw_error("add_ennemy", "fail to add ennemy die texture"));
	args = texture_args(ft_strdup("ennemy_die4"), offset, size, 200);
	if (!add_texture(game, &ennemy->die, args))
		return (throw_error("add_ennemy", "fail to add ennemy die texture"));
	args = texture_args(ft_strdup("ennemy_die5"), offset, size, 200);
	if (!add_texture(game, &ennemy->die, args))
		return (throw_error("add_ennemy", "fail to add ennemy die texture"));
	args = texture_args(ft_strdup("ennemy_die6"), offset, size, 200);
	if (!add_texture(game, &ennemy->die, args))
		return (throw_error("add_ennemy", "fail to add ennemy die texture"));
	args = texture_args(ft_strdup("ennemy_die7"), offset, size, 200);
	if (!add_texture(game, &ennemy->die, args))
		return (throw_error("add_ennemy", "fail to add ennemy die texture"));
	args = texture_args(ft_strdup("ennemy_die8"), offset, size, 200);
	if (!add_texture(game, &ennemy->die, args))
		return (throw_error("add_ennemy", "fail to add ennemy die texture"));
	args = texture_args(ft_strdup("ennemy_die9"), offset, size, 200);
	if (!add_texture(game, &ennemy->die, args))
		return (throw_error("add_ennemy", "fail to add ennemy die texture"));
	args = texture_args(ft_strdup("ennemy_die10"), offset, size, 200);
	if (!add_texture(game, &ennemy->die, args))
		return (throw_error("add_ennemy", "fail to add ennemy die texture"));
	return (OK);
}

t_result	initialize_ennemy_entity_texture(t_screen screen, t_ennemy *ennemy)
{
	t_entity_texture_args	args;

	args.anchor = ft_vec2i(screen.size.x / 2, screen.size.y / 2);
	args.animation = STOP;
	args.texture = NULL;
	args.update_texture = NULL;
	build_ennemy_entity_texture(&ennemy->super.texture, args);
	return (OK);
}

t_result	initialize_ennemy_entity(t_game *game, t_ennemy *ennemy)
{
	t_entity_args	args;

	initialize_ennemy_entity_texture(game->interface.screen, ennemy);
	build_ennemy_listener(&ennemy->super.status, &game->renderer.sprites,
		&game->entities.sprites, TRUE);
	args.dir = ft_vec2f(0, 1);
	args.pos = ft_vec2f(10, 10);
	args.type = ENNEMY;
	build_ennemy_entity(&ennemy->super, args);
	return (OK);
}

t_result	initialize_ennemy(t_game *game, t_player *player)
{
	t_ennemy		*ennemy;

	if (!(ennemy = create_ennemy(player)))
		return (throw_error("init_ennemy", "failed to create ennemy"));
	if (!add_ennemy_front_texture(game, ennemy))
		return (throw_error("init_ennemy", "failed to add front texture"));
	if (!add_ennemy_right_texture(game, ennemy))
		return (throw_error("init_ennemy", "failed to add right texture"));
	if (!add_ennemy_back_texture(game, ennemy))
		return (throw_error("init_ennemy", "failed to add back texture"));
	if (!add_ennemy_left_texture(game, ennemy))
		return (throw_error("init_ennemy", "failed to add left texture"));
	if (!add_ennemy_attack_texture(game, ennemy))
		return (throw_error("init_ennemy", "failed to add attack texture"));
	if (!add_ennemy_die_texture(game, ennemy))
		return (throw_error("init_ennemy", "failed to add die texture"));
	if (!(initialize_ennemy_entity(game, ennemy)))
		return (throw_error("init_ennemy", "failed to init entity"));
	update_ennemy_texture_by_direction(ennemy);
	bind_key(&game->interface.keys_bind, SDLK_UP, &ennemy->super, ennemy_move);
	bind_key(&game->interface.keys_bind, SDLK_RIGHT, &ennemy->super, ennemy_turn_right);
	bind_key(&game->interface.keys_bind, SDLK_LEFT, &ennemy->super, ennemy_turn_left);
	bind_key(&game->interface.keys_bind, SDLK_a, &ennemy->super, ennemy_attack);
	bind_key(&game->interface.keys_bind, SDLK_d, &ennemy->super, ennemy_die);
	return (OK);
}