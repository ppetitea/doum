/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 22:34:54 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/29 16:34:14 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"
#include "libft.h"
#include "engine/game/game_init.h"
#include "engine/interface/events/events.h"
#include "engine/interface/events/keyboard.h"
#include "engine/scene/scene_init.h"
#include "engine/scene/scene_render.h"
#include "engine/map/map_update.h"
#include "utils/error.h"

void	loop(t_game *game)
{
	game->is_running = TRUE;
	while (game->is_running)
	{
		reset_screen(game->interface.screen);
		render_scene(game);
		if (SDL_UpdateTexture(game->interface.sdl.texture, NULL,
			game->interface.screen.pixels,
			game->interface.screen.size.x * sizeof(uint32_t)) == SDL_ERROR)
			return (throw_void("loop", "SDL_UpdateTexture failed"));
		while (SDL_PollEvent(&game->interface.sdl.event))
			handle_events(game);
		trigger_key_hold_bindings(&game->curr_scene->interface.key_hold_binds);
		if (SDL_RenderCopy(game->interface.sdl.renderer,
				game->interface.sdl.texture, NULL, NULL))
			return (throw_void("loop", "SDL_RenderCopy failed"));
		SDL_RenderPresent(game->interface.sdl.renderer);
		if (SDL_RenderClear(game->interface.sdl.renderer) == SDL_ERROR)
			return (throw_void("loop", "SDL_RenderClear failed"));
	}
}
