/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 17:16:52 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/20 02:33:58 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entities/init_entity.h"
#include "engine/scenes/init_scene.h"
#include "utils/error.h"
#include "libft.h"
#include <time.h>
#include <math.h>

# include <stdio.h>

static t_texture	*handle_animation_end(t_entity *entity)
{
	t_texture	*ret;
	
	ret = (t_texture*)entity->texture.curr_head->next;
	if (entity->texture.animation == INFINITE)
		return ((t_texture*)entity->texture.curr_head->next);
	if (entity->texture.animation == IN_PROGRESS)
		ret = ((t_texture*)entity->texture.curr_head->next);
	else if (entity->texture.animation == EPHEMERAL)
	{
		entity->texture.curr_head = entity->texture.prev_head;
		ret = ((t_texture*)entity->texture.prev_head->next);
	}
	else if (entity->texture.animation == FINAL)
		ret = ((t_texture*)entity->texture.curr);
	else
		throw_void("handle_animation_end", "wrong animation type detected");
	entity->texture.animation = STOP;
	return (ret);
}

static	void	animate_texture(t_entity *entity)
{
	unsigned int		delta_ms;
	struct timespec		last;
	struct timespec		time;

	last = entity->texture.last;
	timespec_get(&time, TIME_UTC);
	delta_ms = (time.tv_sec - last.tv_sec) * 1000;
	delta_ms += (time.tv_nsec - last.tv_nsec) / 1.0e6;
	if (delta_ms > entity->texture.curr->delay_ms)
	{
		entity->texture.last = time;
		if (entity->texture.curr->node.next == entity->texture.curr_head)
			entity->texture.curr = handle_animation_end(entity);
		else
			entity->texture.curr = (t_texture*)entity->texture.curr->node.next;
	}
}

static t_result	render_ui_components(t_scene *scene)
{
	t_list_head		*pos;
	t_list_head		*next;
	t_entity		*entity;

	pos = &scene->renderer.ui_components;
	next = pos->next;
	while ((pos = next) != &scene->renderer.ui_components)
	{
		next = next->next;
		entity = (t_entity*)pos;
		if (entity->status.is_dragged)
			SDL_GetMouseState(&entity->texture.anchor.x,
				&entity->texture.anchor.y);
		if (entity->texture.animation != NONE &&
				entity->texture.animation != STOP)
				animate_texture(entity);
		if (entity->texture.curr != NULL)
			render_texture(*scene->interface.screen_ref, entity->texture.curr,
				entity->texture.anchor);
	}
	return (OK);
}

#include <stdio.h>

static void		compute_entity_position_in_plan(t_scene *scene,
					t_entity *entity, float angle, float distance)
{
	t_camera	*cam;
	size_t		screen_half;
	t_vec2i		anchor;

	cam = scene->renderer.cam_ref;
	screen_half = scene->interface.screen_ref->size.y / 2.0f;
	anchor.x = ((angle + cam->fov / 2.0f) / cam->fov) * cam->plan_width;
	// anchor.y = (cam->height / cam->dist_to_plan) * distance;
	anchor.y = screen_half + (cam->dist_to_plan / distance) * cam->height;
	// printf("distance %.2f\n", distance);
	// printf("anchor x %d y %d\n", anchor.x, anchor.y);
	entity->texture.anchor = anchor;
}

static t_bool	is_belong_to_camera_plan(t_scene *scene, t_entity *entity)
{
	t_camera	*cam;
	t_vec2f		dir;
	float		angle;
	float		distance;

	cam = scene->renderer.cam_ref;
	dir = vec2f_sub(entity->pos, *cam->pos);
	angle = atan2f(cam->dir->x, cam->dir->y) - atan2f(dir.x, dir.y) ;
	if (angle > PI || angle < -PI)
		angle = angle > 0 ? -(2 * PI - angle) : 2 * PI + angle;
	// printf("angle %.2f\n", angle / PI * 180.0f);
	// printf("player pos x %.2f y %.2f\n", cam->pos->x, cam->pos->y);
	if (ft_absf(angle) <= cam->fov / 2.0)
	{
		distance = vec2f_magnitude(dir) * cos(angle);
		entity->texture.scale = scene->interface.screen_ref->size.y / distance;
		compute_entity_position_in_plan(scene, entity, angle, distance);
		return (TRUE);
	}
	return (FALSE);
}

static t_result	render_sprites(t_scene *scene)
{
	t_list_head			*pos;
	t_list_head			*next;
	t_entity			*entity;
	t_entity_texture	*t;

	pos = &scene->renderer.sprites;
	next = pos->next;
	while ((pos = next) != &scene->renderer.sprites)
	{
		next = next->next;
		entity = (t_entity*)pos;
		t = &entity->texture;
		if (is_belong_to_camera_plan(scene, entity))
		{
			if (t->animation != NONE && t->animation != STOP)
				animate_texture(entity);
			if (t->curr != NULL)
				render_texture_with_scale(*scene->interface.screen_ref,
					t->curr, t->anchor, t->scale);
		}
	}
	return (OK);
}

t_result	render(t_scene *scene)
{
	render_sprites(scene);
	render_ui_components(scene);
	return (OK);
}
