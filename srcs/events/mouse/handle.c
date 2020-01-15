/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 01:17:28 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/15 05:20:56 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"
#include "game.h"
#include "events/mouse.h"
#include "entities/entities.h"

#include <stdio.h>

void	handle_mouse_motion(t_game *game, SDL_MouseMotionEvent event)
{
	game->interface.mouse.pos = ft_vec2i(event.x, event.y);
	if (game->interface.mouse.down == TRUE &&
		game->interface.mouse.drag == FALSE)
	{
		game->interface.mouse.drag = TRUE;
		update_draggables_entities(game, &game->renderer.ui_components,
			game->interface.mouse);
	}
	else
		update_hoverables_entities(&game->renderer.ui_components,
			game->interface.mouse);
}

void	handle_mouse_down(t_game *game, SDL_MouseButtonEvent event)
{
	game->interface.mouse.down = TRUE;
	game->interface.mouse.pos = ft_vec2i(event.x, event.y);
	update_selectables_entities(game, &game->renderer.ui_components,
		game->interface.mouse);
}

void	handle_mouse_up(t_game *game, SDL_MouseButtonEvent event)
{
	game->interface.mouse.down = FALSE;
	game->interface.mouse.drag = FALSE;
	game->interface.mouse.pos = ft_vec2i(event.x, event.y);
	update_draggables_entities(game, &game->renderer.ui_components,
		game->interface.mouse);
	(void)game;
	(void)event;
}