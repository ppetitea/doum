/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 16:52:20 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/31 00:42:41 by ppetitea         ###   ########.fr       */
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

void	init_render3d_loop(t_pos3f *pos, t_vec3f *delta, uint32_t *array,
			t_map *map)
{
	delta->z = 1;
	pos->z = 1;
	init_columns_height(array, map->color_map.curr->size);
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


void	increment_render3d_loop(t_pos3f *pos, t_vec3f *delta)
{
	pos->z += delta->z;
	delta->z += 0.005f;	
}

void	render_voxel_map3d(t_screen *screen, t_voxel_map_3d_config *config,
			t_map *map)
{
	uint32_t 	columns_height[screen->size.x];
	t_pos3f		pos;
	t_vec3f		delta;
	t_column	column;
	int			map_offset;

	init_render3d_loop(&pos, &delta, columns_height, map);
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
		increment_render3d_loop(&pos, &delta);
	}
}


// void	render_voxel_map3d(t_screen *screen, t_voxel_map_3d_config *config,
// 			t_map *map)
// {
// 	uint32_t 	columns_height[screen->size.x];
// 	t_pos2f		curr;
// 	t_pos2f		delta;
// 	t_camera	*cam;
// 	float		delta_z;
// 	float		z;
// 	int			mapoffset;
// 	int			mapheightperiod;
// 	int			mapwidthperiod;

// 	fill_uint32_array(columns_height, screen->size.x, (int)screen->size.y);
// 	cam = &map->character_ref->camera;
// 	mapwidthperiod = map->color_map.curr->size.x - 1;
// 	mapheightperiod = map->color_map.curr->size.y - 1;

// 	delta_z = 1;
// 	z = 1;
// 	while (z < config->render_dist)
// 	{
// 		curr = vec2f_scalar(cam->start, z);
// 		delta = vec2f_sub(vec2f_scalar(cam->end, z), curr);
// 		delta = vec2f_scalar(delta, 1.0f / (float)map->color_map.curr->size.x);
// 		curr = vec2f_add(curr, cam->pos);

// 		float invz = 1 / z * 240 * config->height_scale;
// 		for(int i=0; i < (int)screen->size.x; i++)
// 		{
// 			mapoffset = (((int)floorf(curr.y) & (int)mapwidthperiod) << 10)
// 						+ (((int)floorf(curr.x)) & ((int)mapheightperiod));
// 			mapoffset = (int)curr.x + (int)curr.y * map->color_map.curr->size.x;

			

			
// 			float heightonscreen = (cam->height - ((t_bgra)map->height_map.curr->pixels[mapoffset]).bgra.b) * invz + cam->horizon;
// 			draw_vertical_line(screen, i, heightonscreen, columns_height[i], map->color_map.curr->pixels[mapoffset]);
// 			if (heightonscreen < columns_height[i])
// 				columns_height[i] = heightonscreen;
// 			curr.x += delta.x;
// 			curr.y += delta.y;
// 		}
// 		z += delta_z;
// 		delta_z += 0.005f;
// 	}
// }

// void	render_voxel_map3d(t_screen *screen, t_voxel_map_3d_config *config,
// 			t_map *map)
// {
// 	uint32_t 	hiddeny[screen->size.x];
// 	t_camera	*cam;

// 	if (screen == NULL || config == NULL || map == NULL)
// 		return (throw_void("render_voxel_map3d", "NULL pointer provided"));
// 	cam = &map->character_ref->camera;
// 	int mapwidthperiod = screen->size.x - 1;
// 	int mapheightperiod = screen->size.y - 1;

// 	if (map->character_ref == NULL)
// 		return (throw_void("render_voxel_map3d", "character_ref not found"));

// 	for(int i = 0; i < (int)screen->size.x; i++)
// 		hiddeny[i] = (int)screen->size.y;

// 	float deltaz = 1;

// 	for(float z=1; z < config->render_dist; z += deltaz)
// 	{
// 		float plx =  -cam->dir.x * z - cam->dir.y * z;
// 		float ply =   cam->dir.y * z - cam->dir.x * z;
// 		float prx =   cam->dir.x * z - cam->dir.y * z;
// 		float pry =  -cam->dir.y * z - cam->dir.x * z;

// 		float dx = (prx - plx) / screen->size.x;
// 		float dy = (pry - ply) / screen->size.x;
// 		plx += cam->pos.x;
// 		ply += cam->pos.y;
// 		float invz = 1 / z * 240 * config->height_scale;
// 		for(int i=0; i < (int)screen->size.x; i++)
// 		{
// 			int mapoffset = (((int)floorf(ply) & (int)mapwidthperiod) << 10) + (((int)floorf(plx)) & ((int)mapheightperiod));
// 			float heightonscreen = (cam->height - ((t_bgra)map->height_map_textures.curr->pixels[mapoffset]).bgra.b) * invz + cam->horizon;
// 			draw_vertical_line(screen, i, heightonscreen, hiddeny[i], map->color_map_textures.curr->pixels[mapoffset]);
// 			if (heightonscreen < hiddeny[i])
// 				hiddeny[i] = heightonscreen;
// 			plx += dx;
// 			ply += dy;
// 		}
// 		deltaz += 0.005;
// 	}
// }