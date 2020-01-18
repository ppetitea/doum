/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 17:16:52 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/18 03:57:17 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "libft.h"
#include "entities/entities.h"
#include <time.h>
#include <math.h>

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
		if (entity->texture.animation != NONE &&
				entity->texture.animation != STOP)
				animate_texture(entity);
		if (entity->texture.t != NULL)
			render_texture(game->interface.screen, entity->texture.t,
				entity->texture.anchor);
	}
	return (OK);
}

#include <stdio.h>

static void		compute_entity_position_in_plan(t_game *game,
					t_entity *entity, float angle, float distance)
{
	t_camera	*cam;
	size_t		screen_half;
	t_vec2i		anchor;

	cam = game->renderer.camera;
	screen_half = game->interface.screen.size.y / 2.0f;
	anchor.x = ((angle + cam->fov / 2.0f) / cam->fov) * cam->plan_width;
	// anchor.y = (cam->height / cam->dist_to_plan) * distance;
	anchor.y = screen_half + (cam->dist_to_plan / distance) * cam->height;
	// printf("distance %.2f\n", distance);
	// printf("anchor x %d y %d\n", anchor.x, anchor.y);
	entity->texture.anchor = anchor;
}

static t_bool	is_belong_to_camera_plan(t_game *game, t_entity *entity)
{
	t_camera	*cam;
	t_vec2f		dir;
	float		angle;
	float		distance;

	cam = game->renderer.camera;
	dir = vec2f_sub(entity->pos, *cam->pos);
	angle = atan2f(cam->dir->x, cam->dir->y) - atan2f(dir.x, dir.y) ;
	if (angle > PI || angle < -PI)
		angle = angle > 0 ? -(2 * PI - angle) : 2 * PI + angle;
	// printf("angle %.2f\n", angle / PI * 180.0f);
	// printf("player pos x %.2f y %.2f\n", cam->pos->x, cam->pos->y);
	if (ft_absf(angle) <= cam->fov / 2.0)
	{
		distance = vec2f_magnitude(dir) * cos(angle);
		entity->texture.scale = game->interface.screen.size.y / distance;
		compute_entity_position_in_plan(game, entity, angle, distance);
		return (TRUE);
	}
	return (FALSE);
}

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
		if (is_belong_to_camera_plan(game, entity))
		{
			if (entity->texture.animation != NONE &&
					entity->texture.animation != STOP)
					animate_texture(entity);
			if (entity->texture.t != NULL)
				render_texture_with_scale(game->interface.screen, entity->texture.t,
					entity->texture.anchor, entity->texture.scale);
			// if (entity->texture.t != NULL)
			// 	render_texture(game->interface.screen, entity->texture.t,
			// 		entity->texture.anchor);
		}
	}
	return (OK);
}

t_result	render(t_game *game)
{
	render_sprites(game);
	render_ui_components(game);
	return (OK);
}
