/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 14:41:00 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/05 18:06:51 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/interface/screen_init.h"
#include "engine/scene/scene_init.h"
#include "engine/scene/scene_render.h"
#include "engine/map/map_init.h"
#include "utils/matrix.h"
#include "utils/error.h"
#include "utils/color.h"

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
	return (d1.x * d1.x + d1.y * d1.y < d2.x * d2.x + d2.y * d2.y);
}

void	draw_vertical_line(t_voxel_map_3d_config *config, t_screen *screen,
		t_column column, uint32_t color)
{
	column.x = column.x * config->scale.x + config->anchor.x;
	column.y_bot = column.y_bot * config->scale.y + config->anchor.y;
	column.y_top = column.y_top * config->scale.y + config->anchor.y;
	if (column.y_top > column.y_bot)
		return ;
	if (column.y_top < 0)
		column.y_top = 0;
	if (column.y_bot > (int)screen->size.y)
		column.y_bot = (int)screen->size.y;
	if (column.y_bot < 0)
		column.y_bot = 0;
	while (column.y_top < column.y_bot)
		screen->pixels[(column.y_top++) * screen->size.x + column.x] = color;
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

void	limit_int(int *n, t_usize size)
{
	int	size_xy;

	size_xy = (int)(size.x * size.y);
	while (*n < 0)
		*n += size_xy;
	while (*n > size_xy)
		*n -= size_xy;
}

int		compute_map_offset(t_pos3f pos, t_usize size)
{
	int	offset;

	offset = (int)pos.x + (int)pos.y * size.x;
	limit_int(&offset, size);
	return (offset);
}

float	compute_column_height(t_voxel_map_3d_config *config, t_map *map,
		int map_offset, t_pos3f pos)
{
	t_bgra		*pixel;
	t_camera	*cam;
	float		height;

	pixel = (t_bgra*)&map->height_map.curr->pixels[map_offset];
	cam = &map->character_ref->camera;
	height = cam->height - pixel->bgra.b;
	return (height * (1 / pos.z * 400 * config->height_scale) + cam->horizon);
}

void	update_position_and_delta_with_z(t_map *map,
		t_pos3f *pos, t_vec3f *delta)
{
	t_camera	*cam;

	cam = &map->character_ref->camera;
	pos->x = cam->start.x * pos->z;
	pos->y = cam->start.y * pos->z;
	delta->x = cam->end.x * pos->z - pos->x;
	delta->y = cam->end.y * pos->z - pos->y;
	delta->x = delta->x / (float)map->color_map.curr->size.x;
	delta->y = delta->y / (float)map->color_map.curr->size.x;
	pos->x += cam->pos.x;
	pos->y += cam->pos.y;
}

void	render_voxel_map_curr_character(t_voxel_map_3d_config *config,
		t_screen *screen, t_character *character, t_pos3f pos)
{
	t_entity_texture *t;

	if (screen == NULL || character == NULL)
		return (throw_void("render_voxel_map_curr_character", "NULL pointer"));
	t = &character->super.texture;
	if (t->animation != NONE && t->animation != STOP)
		animate_texture(&character->super);
	if (t->curr != NULL)
		render_texture_with_scale(screen, t->curr, t->anchor, t->scale.x);
	(void)pos;
	(void)config;
}

// map->e_oriented
// t_list_head head;

// character = (t_character*)head.next;


// character->camera.pos
// character->camera.height

void	render_voxel_map3d_floor(t_screen *screen, t_voxel_map_3d_config *config,
		t_map *map)
{
	uint32_t 	columns_height[screen->size.x];
	t_pos3f		pos;
	t_vec3f		delta;
	t_column	column;
	int			map_offset;

	delta.z = 1;
	pos.z = 1;
	init_columns_height(columns_height, map->color_map.curr->size);
	while (pos.z < config->render_dist)
	{
		update_position_and_delta_with_z(map, &pos, &delta);
		column.x = -1;
		while (++column.x < (int)map->color_map.curr->size.x)
		{
			map_offset = compute_map_offset(pos, map->color_map.curr->size);
			column.y_bot = columns_height[column.x];
			column.y_top = compute_column_height(config, map, map_offset, pos);
			draw_vertical_line(config, screen, column,
					map->color_map.curr->pixels[map_offset]);
			if (column.y_top < (int)columns_height[column.x])
				columns_height[column.x] = column.y_top;
			pos = ft_pos3f(pos.x + delta.x, pos.y + delta.y, pos.z);
		}
		pos.z += delta.z;
		delta.z += 0.005f;
	}
}

void	render_map3d_player(t_screen *screen,
		t_voxel_map_3d_config *config, t_map *map)
{
	t_entity_texture	*texture;

	if (screen == NULL || config == NULL || map == NULL)
		return (throw_void("render_map3d_player", "NULL pointer"));
	if (map->character_ref == NULL)
		return (throw_void("render_map3d_player", "player not found"));
	texture = &map->character_ref->super.texture;
	if (texture->animation != NONE && texture->animation != STOP)
		animate_texture(&map->character_ref->super);
	render_texture_with_scale_2d(screen, texture->curr, texture->anchor,
			texture->scale);
}

static t_bool	is_belong_to_camera_plan(t_voxel_map_3d_config *config,
		t_map *map, t_screen *screen, t_character *character)
{
	t_camera	*cam;
	t_vec2f		dir;
	float		angle;
	t_vec2i		anchor;

	cam = &map->character_ref->camera;
	dir = vec2f_sub(character->camera.pos, cam->pos);
	angle = atan2f(cam->dir.x, cam->dir.y) - atan2f(dir.x, dir.y);
	if (angle > PI || angle < -PI)
		angle = angle > 0 ? -(2 * PI - angle) : 2 * PI + angle;
	if (ft_absf(angle) <= cam->fov_half)
	{
		character->orientate(character);
		character->target_dist = vec2f_magnitude(dir);
		// printf("dist %.2f\n", character->target_dist);
		character->super.texture.scale.x = screen->size.y / character->target_dist;
		character->super.texture.scale.y = screen->size.y / character->target_dist;
		anchor.x = ((angle + cam->fov_half) / cam->fov) * cam->plan_width;
		anchor.y = cam->height - character->camera.height;
		anchor.y = anchor.y * (1 / character->target_dist * 400 * config->height_scale) + cam->horizon;
		character->super.texture.anchor = anchor;
		return (TRUE);
	}
	(void)config;
	return (FALSE);
}

void	update_render_list_with_player_cam(t_voxel_map_3d_config *config,
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

void	render_character3d(t_voxel_map_3d_config *config,
		t_screen *screen, t_character *character)
{
	t_entity_texture *t;

	if (screen == NULL || character == NULL)
		return (throw_void("render_voxel_map_curr_character", "NULL pointer"));
	t = &character->super.texture;
	if (t->animation != NONE && t->animation != STOP)
		animate_texture(&character->super);
	if (t->curr != NULL)
		render_texture_with_scale(screen, t->curr, t->anchor, t->scale.x);
	(void)config;
}

void	render_map3d(t_screen *screen, t_voxel_map_3d_config *config,
		t_map *map)
{
	t_character	*character;
	t_list_head	*pos;
	t_rangef	range;

	range.max = config->render_dist;
	pos = &map->e_oriented;
	while ((pos = pos->prev) != &map->e_oriented)
	{
		character = (t_character*)pos;
		range.min = character->target_dist;
		render_floor3d(screen, config, map);
		render_character3d(screen, config, character);
		range.max = range.min;
	}
}

void	render_voxel_map3d(t_screen *screen, t_voxel_map_3d_config *config,
		t_map *map)
{
	update_render_list_with_player_cam(config, map, screen);
	bubble_sort_linked_list(&map->e_oriented, sprite_distance_rule);
	map->curr_character = (t_character*)map->e_oriented.next;
	render_voxel_map3d_floor(screen, config, map);
	if (config->display_player)
		render_map3d_player(screen, config, map);
}
