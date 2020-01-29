/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 16:52:20 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/29 18:40:34 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/interface/screen_init.h"
#include "engine/scene/scene_init.h"
#include "engine/scene/scene_render.h"
#include "engine/map/map_init.h"
#include "utils/error.h"
#include "utils/color.h"

#include <stdio.h>

void	draw_vertical_line(t_screen *screen, int x, int ytop, int ybot, uint32_t color)
{
	if (ytop > ybot)
		return ;
	if (ytop < 0)
		ytop = 0;
	if (ybot > (int)screen->size.y)
		ybot = (int)screen->size.y;
	if (ybot < 0)
		ybot = 0;
	while (ytop < ybot)
		screen->pixels[(ytop++) * screen->size.x + x] = color;
}

// void	render2(uint32_t *pixels, int *hm, uint32_t *colormap, t_point player, float phi, int height, int horizon, int scale_height, int distance, uint32_t *bg)
// {
// 	memset(pixels, 0xFFFFFFFF, sizeof(uint32_t) * WIDTH * HEIGHT);
// 	draw_bg(pixels, bg);
// 	int mapwidthperiod = WIDTH - 1;
// 	int mapheightperiod = HEIGHT - 1;

// 	(void)scale_height;

// 	float sinang = sin(phi);
// 	float cosang = cos(phi);

// 	uint32_t hiddeny[WIDTH];

// 	for (int i = 0; i < WIDTH; i++)
// 		hiddeny[i] = 0;

// 	for(int i = 0; i < WIDTH; i++)
// 		hiddeny[i] = HEIGHT;

// 	float deltaz = 1;

// 	for(float z=1; z < distance; z += deltaz)
// 	{
// 		float plx =  -cosang * z - sinang * z;
// 		float ply =   sinang * z - cosang * z;
// 		float prx =   cosang * z - sinang * z;
// 		float pry =  -sinang * z - cosang * z;

// 		float dx = (prx - plx) / WIDTH;
// 		float dy = (pry - ply) / WIDTH;
// 		plx += player.x;
// 		ply += player.y;
// 		float invz = 1 / z * 240 * scale_height;
// 		for(int i=0; i< WIDTH; i++)
// 		{
// 			int mapoffset = (((int)floorf(ply) & (int)mapwidthperiod) << 10) + (((int)floorf(plx)) & ((int)mapheightperiod));
// 			float heightonscreen = (height - hm[mapoffset]) * invz + horizon;
// 			draw_vertical_line(pixels, i, heightonscreen, hiddeny[i], colormap[mapoffset]);
// 			if (heightonscreen < hiddeny[i]) hiddeny[i] = heightonscreen;
// 			plx += dx;
// 			ply += dy;
// 		}
// 		deltaz += 0.005;
// 	}
// }

int	get_blue(uint32_t color)
{
	int c;
	color = color << 24;
	color = color >> 24;
	c = (int) color;
	return (c);
}

void	render_voxel_map3d(t_screen *screen, t_voxel_map_3d_config *config,
			t_map *map)
{
	if (screen == NULL || config == NULL || map == NULL)
		return (throw_void("render_voxel_map3d", "NULL pointer provided"));
	uint32_t 	hiddeny[screen->size.x];
	int mapwidthperiod = screen->size.x - 1;
	int mapheightperiod = screen->size.y - 1;
	t_camera	*cam;

	if (map->character_ref == NULL)
		return (throw_void("render_voxel_map3d", "character_ref not found"));
	cam = &map->character_ref->camera;

	for(int i = 0; i < (int)screen->size.x; i++)
		hiddeny[i] = (int)screen->size.y;

	float deltaz = 1;

	for(float z=1; z < config->render_dist; z += deltaz)
	{
		float plx =  -cam->dir.x * z - cam->dir.y * z;
		float ply =   cam->dir.y * z - cam->dir.x * z;
		float prx =   cam->dir.x * z - cam->dir.y * z;
		float pry =  -cam->dir.y * z - cam->dir.x * z;

		float dx = (prx - plx) / screen->size.x;
		float dy = (pry - ply) / screen->size.x;
		plx += cam->pos.x;
		ply += cam->pos.y;
		float invz = 1 / z * 240 * config->height_scale;
		for(int i=0; i < (int)screen->size.x; i++)
		{
			int mapoffset = (((int)floorf(ply) & (int)mapwidthperiod) << 10) + (((int)floorf(plx)) & ((int)mapheightperiod));
			float heightonscreen = (cam->height - ((t_bgra)map->height_map_textures.curr->pixels[mapoffset]).bgra.b) * invz + cam->horizon;
			draw_vertical_line(screen, i, heightonscreen, hiddeny[i], map->color_map_textures.curr->pixels[mapoffset]);
			if (heightonscreen < hiddeny[i])
				hiddeny[i] = heightonscreen;
			plx += dx;
			ply += dy;
		}
		deltaz += 0.005;
	}
}
