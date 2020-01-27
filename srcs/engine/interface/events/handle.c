/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 01:13:53 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/27 14:01:46 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"
#include "engine/interface/events/keyboard.h"
#include "engine/interface/events/mouse.h"
#include "engine/scene/scene_init.h"
#include "engine/game/game_init.h"

void	handle_events(t_game *game)
{
	t_sdl *sdl;

	sdl = &game->interface.sdl;
	if (sdl->event.type == SDL_MOUSEMOTION)
		handle_mouse_motion(game->curr_scene, sdl->event.motion);
	if (sdl->event.type == SDL_MOUSEBUTTONDOWN)
		handle_mouse_down(game->curr_scene, sdl->event.button);
	if (sdl->event.type == SDL_MOUSEBUTTONUP)
		handle_mouse_up(game->curr_scene, sdl->event.button);
	if (sdl->event.type == SDL_KEYDOWN)
		handle_keyboard_down(game->curr_scene, sdl->event.key.keysym.sym);
	if (sdl->event.type == SDL_KEYUP)
		handle_keyboard_up(game->curr_scene, sdl->event.key.keysym.sym);
	if (sdl->event.type == SDL_QUIT)
		game->is_running = FALSE;
}
