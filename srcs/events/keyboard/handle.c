/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 01:17:28 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/14 23:51:04 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "events/keyboard.h"

void	handle_keyboard_down(t_game *game, SDL_Keycode key)
{
	if (key == SDLK_ESCAPE)
		game->is_running = FALSE;
	(void)game;
}

void	handle_keyboard_up(t_game *game, SDL_Keycode key)
{
	(void)game;
	(void)key;
}
