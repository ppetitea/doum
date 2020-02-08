/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 22:34:54 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/08 19:20:02 by lbenard          ###   ########.fr       */
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
#include "utils/time.h"

void	loop(t_game *game)
{
	double	last_time;
	double	spf;

	game->is_running = TRUE;
	while (game->is_running)
	{
		last_time = get_wall_time();
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
		spf = get_wall_time() - last_time;
		printf("fps: %f\n", 1.0f / spf);
		set_delta(spf);
	}
}
