/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 22:34:54 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/20 00:37:29 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"
#include "libft.h"
#include "engine/init_game.h"
#include "engine/interface/events/events.h"
#include "engine/interface/events/keyboard.h"
#include "engine/scenes/init_scene.h"
#include "engine/scenes/update_scene.h"
#include "utils/error.h"

void	loop(t_game *game)
{
	game->is_running = TRUE;
	while (game->is_running)
	{
		reset_screen(game->screen);
		trigger_keys_bindings(game->curr_scene);
		render(game->curr_scene);
		if (SDL_UpdateTexture(game->sdl.texture, NULL, game->screen.pixels,
			game->screen.size.x * sizeof(uint32_t)) == SDL_ERROR)
			return (throw_void("loop", "SDL_UpdateTexture failed"));
		while (SDL_PollEvent(&game->sdl.event))
			handle_events(game);
		if (SDL_RenderCopy(game->sdl.renderer,
				game->sdl.texture, NULL, NULL))
			return (throw_void("loop", "SDL_RenderCopy failed"));
		SDL_RenderPresent(game->sdl.renderer);
		if (SDL_RenderClear(game->sdl.renderer) == SDL_ERROR)
			return (throw_void("loop", "SDL_RenderClear failed"));
	}
}