/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 22:34:54 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/27 14:03:40 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"
#include "libft.h"
#include "engine/game/game_init.h"
#include "engine/interface/events/events.h"
#include "engine/interface/events/keyboard.h"
#include "engine/scene/scene_init.h"
#include "engine/map/map_update.h"
#include "utils/error.h"

void	loop(t_game *game)
{
	game->is_running = TRUE;
	while (game->is_running)
	{
		reset_screen(game->interface.screen);
		// render(game->curr_scene);
		ft_putstr("TEST\n");
		if (game->curr_map != NULL)
			map_render2d(game->curr_map, &game->curr_map->drop_map);
		if (SDL_UpdateTexture(game->interface.sdl.texture, NULL,
			game->interface.screen.pixels,
			game->interface.screen.size.x * sizeof(uint32_t)) == SDL_ERROR)
			return (throw_void("loop", "SDL_UpdateTexture failed"));
		while (SDL_PollEvent(&game->interface.sdl.event))
		{
			if (game->interface.sdl.event.type == SDL_QUIT)
				game->is_running = FALSE;
		}
		// 	handle_events(game);
		// trigger_key_hold_bindings(&game->curr_scene->interface.key_hold_binds);
		if (SDL_RenderCopy(game->interface.sdl.renderer,
				game->interface.sdl.texture, NULL, NULL))
			return (throw_void("loop", "SDL_RenderCopy failed"));
		SDL_RenderPresent(game->interface.sdl.renderer);
		if (SDL_RenderClear(game->interface.sdl.renderer) == SDL_ERROR)
			return (throw_void("loop", "SDL_RenderClear failed"));
	}
}
