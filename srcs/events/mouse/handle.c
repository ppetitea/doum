/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 01:17:28 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/13 20:54:21 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"
#include "game/game.h"
#include "events/mouse.h"
#include "user_interface/ui.h"

void	handle_mouse_motion(t_game *game, SDL_MouseMotionEvent event)
{
	t_vec2i	mouse;

	mouse = ft_vec2i(event.x, event.y);
	if (game->mouse.down == TRUE && game->mouse.drag == FALSE)
	{
		game->mouse.drag = TRUE;
		update_ui_components_draggable(game, mouse);
	}
	else
		update_ui_components_hoverable(game, mouse);
}

void	handle_mouse_down(t_game *game, SDL_MouseButtonEvent event)
{
	t_vec2i	mouse;

	game->mouse.down = TRUE;
	mouse = ft_vec2i(event.x, event.y);
	update_ui_components_selectable(game, mouse);
}

void	handle_mouse_up(t_game *game, SDL_MouseButtonEvent event)
{
	t_vec2i	mouse;
	
	game->mouse.down = FALSE;
	game->mouse.drag = FALSE;
	mouse = ft_vec2i(event.x, event.y);
	update_ui_components_draggable(game, mouse);
	(void)game;
	(void)event;
}