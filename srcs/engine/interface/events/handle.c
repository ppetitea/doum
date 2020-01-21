/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 01:13:53 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/20 06:26:46 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"
#include "engine/interface/events/keyboard.h"
#include "engine/interface/events/mouse.h"
#include "engine/scenes/init_scene.h"
#include "engine/init_game.h"

void	handle_events(t_game *game)
{
	if (game->sdl.event.type == SDL_MOUSEMOTION)
		handle_mouse_motion(game->curr_scene, game->sdl.event.motion);
	if (game->sdl.event.type == SDL_MOUSEBUTTONDOWN)
		handle_mouse_down(game->curr_scene, game->sdl.event.button);
	if (game->sdl.event.type == SDL_MOUSEBUTTONUP)
		handle_mouse_up(game->curr_scene, game->sdl.event.button);
	if (game->sdl.event.type == SDL_KEYDOWN)
		handle_keyboard_down(game->curr_scene, game->sdl.event.key.keysym.sym);
	if (game->sdl.event.type == SDL_KEYUP)
		handle_keyboard_up(game->curr_scene, game->sdl.event.key.keysym.sym);
	if (game->sdl.event.type == SDL_QUIT)
		game->is_running = FALSE;
}
