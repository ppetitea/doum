/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 01:13:53 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/14 23:51:04 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"
#include "game.h"
#include "events/keyboard.h"
#include "events/mouse.h"

void	handle_events(t_game *game)
{
	if (game->interface.sdl.event.type == SDL_MOUSEMOTION)
		handle_mouse_motion(game, game->interface.sdl.event.motion);
	if (game->interface.sdl.event.type == SDL_MOUSEBUTTONDOWN)
		handle_mouse_down(game, game->interface.sdl.event.button);
	if (game->interface.sdl.event.type == SDL_MOUSEBUTTONUP)
		handle_mouse_up(game, game->interface.sdl.event.button);
	if (game->interface.sdl.event.type == SDL_KEYDOWN)
		handle_keyboard_down(game, game->interface.sdl.event.key.keysym.sym);
	if (game->interface.sdl.event.type == SDL_KEYUP)
		handle_keyboard_up(game, game->interface.sdl.event.key.keysym.sym);
	if (game->interface.sdl.event.type == SDL_QUIT)
		game->is_running = FALSE;
}
