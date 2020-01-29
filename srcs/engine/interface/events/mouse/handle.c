/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 01:17:28 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/29 05:28:25 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"
#include "engine/interface/events/events.h"
#include "engine/interface/events/mouse.h"
#include "engine/entity/entity_init.h"
#include "engine/entity/entity_update.h"
#include "engine/scene/scene_init.h"
#include "utils/error.h"

#include <stdio.h>

void	handle_mouse_motion(t_game *game, SDL_MouseMotionEvent event)
{
	if (game == NULL)
		return (throw_void("handle_mouse_motion", "NULL pointer provided"));
	game->interface.mouse.pos = ft_vec2i(event.x, event.y);
	if (game->interface.mouse.down == TRUE &&
		game->interface.mouse.drag == FALSE)
	{
		game->interface.mouse.drag = TRUE;
		trigger_entities_by_drag(game);
	}
	else
		trigger_entities_by_hover(game);
}

void	handle_mouse_down(t_game *game, SDL_MouseButtonEvent event)
{
	game->interface.mouse.down = TRUE;
	game->interface.mouse.pos = ft_vec2i(event.x, event.y);
	if (!game->interface.mouse.drag)
		trigger_entities_by_select(game);
}

void	handle_mouse_up(t_game *game, SDL_MouseButtonEvent event)
{
	game->interface.mouse.down = FALSE;
	game->interface.mouse.drag = FALSE;
	game->interface.mouse.pos = ft_vec2i(event.x, event.y);
	if (game->interface.mouse.drag)
		trigger_entities_by_drop(game);
	(void)event;
}