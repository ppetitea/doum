/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 22:34:54 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/12 01:24:43 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"
#include "libft.h"
#include "game/game.h"
#include "events/events.h"

void	loop(t_game *game)
{
	game->is_running = TRUE;
	while (game->is_running)
	{
		SDL_UpdateTexture(game->sdl.texture, NULL, game->screen.pixels,
			game->screen.size.x * sizeof(uint32_t));
		while (SDL_PollEvent(&game->sdl.event))
			handle_events(game);
		SDL_RenderClear(game->sdl.renderer);
		SDL_RenderCopy(game->sdl.renderer, game->sdl.texture, NULL, NULL);
		SDL_RenderPresent(game->sdl.renderer);
	}
}