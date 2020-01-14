/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 17:16:52 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/14 09:18:18 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/game.h"
#include "libft.h"
#include "user_interface/ui.h"
#include <time.h>

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

#include <stdio.h>
static t_result	render_sprites(t_game *game)
{
	t_list_head		*pos;
	t_list_head		*next;
	t_component		*component;
	struct timespec	time;
	unsigned int	delta_ms;

	pos = &game->sprites;
	next = pos->next;
	while ((pos = next) != &game->sprites)
	{
		next = next->next;
		component = (t_component*)pos;
		timespec_get(&time, TIME_UTC);
		delta_ms = ((time.tv_nsec / 10e5) - (component->last.tv_nsec / 10e5));
		if (delta_ms > component->texture->delay_ms)
		{
			component->last = time;
			component->texture = (t_texture*)component->texture->node.next;
		}
		render_texture(game->screen, component->texture, component->anchor);
	}
	return (OK);
}

t_result	render(t_game *game)
{
	render_ui_components(game);
	render_sprites(game);
	return (OK);
}
