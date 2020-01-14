/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 17:16:52 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/14 03:25:29 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/game.h"
#include "libft.h"
#include "user_interface/ui.h"

static t_result	render_ui_components(t_game *game)
{
	t_list_head		*pos;
	t_list_head		*next;
	t_ui_component	*component;

	pos = &game->ui_components;
	next = pos->next;
	while ((pos = next) != &game->ui_components)
	{
		next = next->next;
		component = (t_ui_component*)pos;
		if (component->status.is_dragged)
			SDL_GetMouseState(&component->anchor.x, &component->anchor.y);
		render_texture(game->screen, component->texture, component->anchor);
	}
	return (OK);
}

t_result	render(t_game *game)
{
	render_ui_components(game);
	return (OK);
}
