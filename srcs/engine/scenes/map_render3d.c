/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 14:41:00 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/08 03:53:33 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/interface/screen_init.h"
#include "engine/scene/scene_init.h"
#include "engine/scene/scene_render.h"
#include "engine/map/map_init.h"
#include "utils/matrix.h"
#include "utils/error.h"
#include "utils/color.h"
#include "maths/maths.h"
#include "maths/vec2f.h"
#include "maths/vec3f.h"

#include <stdio.h>

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
	struct timeval		last;
	struct timeval		time;

	last = entity->texture.last;
	gettimeofday(&time, NULL);
	delta_ms = (time.tv_sec - last.tv_sec) * 1000;
	delta_ms += (time.tv_usec - last.tv_usec) / 1.0e3;
	if (delta_ms > entity->texture.curr->delay_ms)
	{
		entity->texture.last = time;
		if (entity->texture.curr->node.next == entity->texture.curr_head)
			entity->texture.curr = handle_animation_end(entity);
		else
			entity->texture.curr = (t_texture*)entity->texture.curr->node.next;
	}
}

t_bool	sprite_distance_rule(t_list_head *pos, t_list_head *next)
{
	t_character	*c1;
	t_character	*c2;
	t_character	*player;
	t_vec2f		d1;
	t_vec2f		d2;

	c1 = (t_character*)pos;
	c2 = (t_character*)next;
	if (!(player = game_player()))
	{
		throw_void("sprite_distance_rule", "player not_found");
		return (FALSE);
	}
	d1.x = c1->camera.pos.x - player->camera.pos.x;
	d1.y = c1->camera.pos.y - player->camera.pos.y;
	d2.x = c2->camera.pos.x - player->camera.pos.x;
	d2.y = c2->camera.pos.y - player->camera.pos.y;
	return (d1.x * d1.x + d1.y * d1.y > d2.x * d2.x + d2.y * d2.y);
}

void	draw_vertical_line(t_voxel_map_3d_config *config, t_screen *screen,
		t_column column, uint32_t color)
{
	column.x = column.x * config->scale.x + config->anchor.x;
	column.y_bot = column.y_bot * config->scale.y + config->anchor.y;
	column.y_top = column.y_top * config->scale.y + config->anchor.y;
	// if (column.y_top < 0)
	// 	column.y_top = 0;
	// if (column.y_bot > (int)screen->size.y)
	// 	column.y_bot = (int)screen->size.y;
	// if (column.y_bot < 0)
	// 	column.y_bot = 0;
	while (column.y_top < column.y_bot)
	{
		screen->pixels[column.y_top * screen->size.x + column.x] = color;
		++column.y_top;
	}
}

t_result	init_columns_height(uint32_t *array, t_usize size)
{
	size_t	i;

	if (array == NULL)
		return (throw_error("fill_uint32_array", "NULL pointer"));
	i = 0;
	while (i < size.x)
	{
		array[i] = (uint32_t)size.y;
		i++;
	}
	return (OK);
}


int		get_floor_height(t_map *map, t_character *character)
{
	t_texture	*hmap;
	t_pos2i		pos;
	t_bgra		color;

	hmap = map->height_map.curr;
	pos.x = (int)character->camera.pos.x;
	pos.y = (int)character->camera.pos.y;
	color.px = hmap->pixels[pos.x + pos.y * hmap->size.x];
	return (color.bgra.b);
}

static t_bool	is_belong_to_camera_plan(t_voxel_map_3d_config *config,
		t_map *map, t_screen *screen, t_character *character)
{
	t_texture_box	*box;
	t_camera		*cam;
	t_vec2f			dir;
	float			angle;
	t_vec2i			anchor;

	cam = &map->character_ref->camera;
	dir = vec2f_sub(character->camera.pos, cam->pos);
	angle = atan2f(cam->dir.x, cam->dir.y) - atan2f(dir.x, dir.y);
	if (angle > PI || angle < -PI)
		angle = angle > 0 ? -(2 * PI - angle) : 2 * PI + angle;
	if (ft_absf(angle) <= cam->fov_half)
	{
		character->target_dist = vec2f_magnitude(dir) * cos(angle);
		box = &character->super.texture.box;
		box->scale.x = 1.0f / (screen->size.y / character->target_dist);
		box->scale.y = 1.0f / (screen->size.y / character->target_dist);
		anchor.x = ((angle + cam->fov_half) / cam->fov) * cam->plan_width;
		anchor.y = config->horizon + (cam->dist_to_plan / character->target_dist)
					* (cam->height - get_floor_height(map, character));
		anchor.x *= config->scale.x;
		anchor.y *= config->scale.y;
		box->anchor = anchor;
		return (TRUE);
	}
	(void)config;
	return (FALSE);
}

void	update_render_list_with_fov(t_voxel_map_3d_config *config,
		t_map *map, t_screen *screen)
{
	t_list_head	*pos;
	t_list_head	*next;
	t_character	*character;

	if (map == NULL || map->character_ref == NULL)
		return (throw_void("update_render_list_with_player", "NULL pointer"));
	pos = &map->e_oriented;
	next = pos->next;
	while ((pos = next) != &map->e_oriented)
	{
		next = next->next;
		character = (t_character*)pos;
		if (!is_belong_to_camera_plan(config, map, screen, character))
		{
			list_del_entry(&character->super.node);
			list_add_entry(&character->super.node, &map->e_oriented_storage);
		}
	}
}

void	update_storage_list_with_fov(t_voxel_map_3d_config *config,
		t_map *map, t_screen *screen)
{
	t_list_head	*pos;
	t_list_head	*next;
	t_character	*character;

	if (map == NULL || map->character_ref == NULL)
		return (throw_void("update_render_list_with_player", "NULL pointer"));
	pos = &map->e_oriented_storage;
	next = pos->next;
	while ((pos = next) != &map->e_oriented_storage)
	{
		next = next->next;
		character = (t_character*)pos;
		if (is_belong_to_camera_plan(config, map, screen, character))
		{
			list_del_entry(&character->super.node);
			list_add_entry(&character->super.node, &map->e_oriented);
		}
	}
}

void	render_character3d(t_screen *screen, t_voxel_map_3d_config *config,
			t_character *character)
{
	t_entity_texture	*t;
	t_vec2f				scale;

	if (screen == NULL || character == NULL)
		return (throw_void("render_voxel_map_curr_character", "NULL pointer"));
	t = &character->super.texture;
	if (t->curr == NULL)
		return ;
	if (t->animation != NONE && t->animation != STOP)
		animate_texture(&character->super);
	scale = compute_render_scale(screen->size, config->size);
	t->box.scale.x *= scale.x;
	t->box.scale.y *= scale.y;
	update_texture_box_with_screen(screen, &t->box, t->curr);
	// printf("box->size x %d y %d\n", t->box.size.x, t->box.size.y);
	render_texture_with_box(screen, t->curr, &t->box);
}

int		compute_map_offset(t_pos2f pos, t_usize size)
{
	int		offset;

	while ((int)pos.x >= (int)size.x)
		pos.x -= (float)size.x;
	while ((int)pos.y >= (int)size.y)
		pos.y -= (float)size.y;
	while ((int)pos.x < 0)
		pos.x += (float)size.x;
	while ((int)pos.y < 0)
		pos.y += (float)size.y;
	offset = (int)pos.x + (int)pos.y * size.x;
	return (offset);
}

void	render_floor3d_with_pre_render(t_screen *screen,
		t_voxel_map_3d_config *config, t_map *map)
{
	t_render_slide	*slide;
	int			slide_index;
	t_camera	*cam;
	t_pos2f		pos;
	t_vec2f		delta;
	t_column	column;
	int			map_offset;

	cam = &map->character_ref->camera;
	slide_index = config->pre_render.index.min;
	while (slide_index < config->pre_render.index.max)
	{
		slide = &config->pre_render.slides[slide_index];
		delta = ft_vec2f(-cam->dir.y, cam->dir.x); 
		pos = vec2f_scalar(cam->dir, slide->dist_to_slide);
		pos = vec2f_sub(pos, vec2f_scalar(delta, slide->slide_half));
		pos = vec2f_add(pos, cam->pos);
		delta = vec2f_scalar(delta, slide->slide_delta);
		column.x = -1;
		while (++column.x < (int)screen->size.x)
		{
			map_offset = compute_map_offset(pos, map->color_map.curr->size);
			column.y_bot = config->pre_render.columns_height[column.x];
			column.y_top = config->horizon + (slide->dist_ratio)
				* (cam->height - ((t_bgra)map->height_map.curr->pixels[map_offset]).bgra.b);
			draw_vertical_line(config, screen, column,
					map->color_map.curr->pixels[map_offset]);
			if (column.y_top < (int)config->pre_render.columns_height[column.x])
				config->pre_render.columns_height[column.x] = column.y_top;
			pos = vec2f_add(pos, delta);
		}
		slide_index++;
	}
}

void	update_slide_index(t_pre_render3d *pre_render, t_rangef *range)
{
	size_t		i;
	
	i = pre_render->index.max - 1;
	while (pre_render->slides[i].dist_to_slide > range->min)
		i--;
	pre_render->index.min = i;
}

void	render_map3d(t_screen *screen, t_voxel_map_3d_config *config,
		t_map *map)
{
	t_character	*character;
	t_list_head	*pos;
	t_rangef	range;

	config->pre_render.index.max = config->pre_render.slides_amount;
	range.max = config->horizon_dist;
	pos = &map->e_oriented;
	while ((pos = pos->prev) != &map->e_oriented)
	{
		character = (t_character*)pos;
		range.min = character->target_dist;
		update_slide_index(&config->pre_render, &range);
		init_columns_height(config->pre_render.columns_height, map->height_map.curr->size);
		render_floor3d_with_pre_render(screen, config, map);
		render_character3d(screen, config, character);
		range.max = range.min;
		config->pre_render.index.max = config->pre_render.index.min;
	}
	config->pre_render.index.min = 0;
	init_columns_height(config->pre_render.columns_height, map->height_map.curr->size);
	render_floor3d_with_pre_render(screen, config, map);
}

void	render_map3d_player(t_screen *screen,
		t_voxel_map_3d_config *config, t_map *map)
{
	t_entity_texture	*t;
	t_vec2f				scale;

	if (screen == NULL || config == NULL || map == NULL)
		return (throw_void("render_map3d_player", "NULL pointer"));
	if (map->character_ref == NULL)
		return (throw_void("render_map3d_player", "player not found"));
	t = &map->character_ref->super.texture;
	if (t->animation != NONE && t->animation != STOP)
		animate_texture(&map->character_ref->super);
	scale = compute_render_scale(screen->size, config->size);
	t->box.scale.x *= scale.x;
	t->box.scale.y *= scale.y;
	update_texture_box_with_screen(screen, &t->box, t->curr);
	render_texture_with_box(screen, t->curr, &t->box);
}

void	render_voxel_map3d(t_screen *screen, t_voxel_map_3d_config *config,
		t_map *map)
{
	update_render_list_with_fov(config, map, screen);
	update_storage_list_with_fov(config, map, screen);
	bubble_sort_linked_list(&map->e_oriented, sprite_distance_rule);
	map->curr_character = (t_character*)map->e_oriented.next;
	render_map3d(screen, config, map);
	if (config->display_player)
		render_map3d_player(screen, config, map);
}
