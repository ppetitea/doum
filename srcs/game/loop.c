/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 22:34:54 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/18 04:12:34 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"
#include "libft.h"
#include "game.h"
#include "events/events.h"
#include "events/keyboard.h"

#include "utils/debug.h"

void	loop(t_game *game)
{
	game->is_running = TRUE;
	while (game->is_running)
	{
		reset_screen(game->interface.screen);
		// debug(game);
		trigger_keys_bindings(game);
		render(game);
		if (SDL_UpdateTexture(
			game->interface.sdl.texture, NULL,
			game->interface.screen.pixels,
			game->interface.screen.size.x * sizeof(uint32_t)) == SDL_ERROR)
			return (throw_void("loop", "SDL_UpdateTexture failed"));
		while (SDL_PollEvent(&game->interface.sdl.event))
			handle_events(game);
		if (SDL_RenderCopy(game->interface.sdl.renderer,
				game->interface.sdl.texture, NULL, NULL))
			return (throw_void("loop", "SDL_RenderCopy failed"));
		SDL_RenderPresent(game->interface.sdl.renderer);
		if (SDL_RenderClear(game->interface.sdl.renderer) == SDL_ERROR)
			return (throw_void("loop", "SDL_RenderClear failed"));
	}
}