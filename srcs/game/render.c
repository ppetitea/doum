/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 17:16:52 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/16 07:00:17 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "libft.h"
#include "entities/entities.h"
#include <time.h>

static	void	animate_texture(t_entity *entity)
{
	unsigned int		delta_ms;
	struct timespec		last;
	struct timespec		time;
	t_texture			*next;
	t_texture			*head;

	last = entity->texture.last;
	timespec_get(&time, TIME_UTC);
	delta_ms = (time.tv_sec - last.tv_sec) * 1000;
	delta_ms += ((time.tv_nsec / 10e5) - (last.tv_nsec / 10e5));
	if (delta_ms > entity->texture.t->delay_ms)
	{
		entity->texture.last = time;
		head = entity->texture.t_head;
		next = (t_texture*)entity->texture.t->node.next;
		if (entity->texture.animation == IN_PROGRESS && next == head)
			entity->texture.animation = STOP;
		entity->texture.t = (t_texture*)entity->texture.t->node.next;
		if (entity->texture.animation == EPHEMERAL && next == head)
		{
			entity->texture.animation = STOP;
			entity->texture.t = (t_texture*)entity->texture.t_last;
			entity->texture.t_head = (t_texture*)entity->texture.t_last;
		}
	}
}

static t_result	render_ui_components(t_game *game)
{
	t_list_head		*pos;
	t_list_head		*next;
	t_entity		*entity;

	pos = &game->renderer.ui_components;
	next = pos->next;
	while ((pos = next) != &game->renderer.ui_components)
	{
		next = next->next;
		entity = (t_entity*)pos;
		if (entity->status.is_dragged)
			SDL_GetMouseState(&entity->texture.anchor.x,
				&entity->texture.anchor.y);
		if (entity->texture.t != NULL)
			render_texture(game->interface.screen, entity->texture.t,
				entity->texture.anchor);
	}
	return (OK);
}

#include <stdio.h>

static t_result	render_sprites(t_game *game)
{
	t_list_head			*pos;
	t_list_head			*next;
	t_entity			*entity;
	
	pos = &game->renderer.sprites;
	next = pos->next;
	while ((pos = next) != &game->renderer.sprites)
	{
		next = next->next;
		entity = (t_entity*)pos;
		if (entity->texture.animation != NONE &&
				entity->texture.animation != STOP)
				animate_texture(entity);
		if (entity->texture.t != NULL)
			render_texture(game->interface.screen, entity->texture.t,
				entity->texture.anchor);
	}
	return (OK);
}

t_result	render(t_game *game)
{
	render_ui_components(game);
	render_sprites(game);
	return (OK);
}
