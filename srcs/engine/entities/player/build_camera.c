/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 22:56:53 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/22 03:39:13 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entities/update_player.h"
#include "engine/entities/init_player.h"
#include "engine/interface/update_camera.h"
#include "utils/parser.h"
#include "utils/error.h"
#include "build.h"
#include <math.h>

t_result	build_player_camera(t_player *player, t_dnon_object *camera_obj)
{
	t_camera *cam;

	if (player == NULL || camera_obj == NULL)
		return (throw_error("build_player_camera", "NULL pointer provided"));
	cam = &player->cam;
	cam->dir = &player->super.dir;
	cam->pos = &player->super.pos;
	cam->fov = get_float_value_by_key(camera_obj, "fov", 90.0f) / 180.0f * PI;
	cam->fov_half = cam->fov / 2.0f;
	cam->plan_width = get_float_value_by_key(camera_obj, "plan_width", 640.0f);
	cam->height = get_float_value_by_key(camera_obj, "height", 160);
	cam->plan_half = cam->plan_width / 2.0f;
	cam->dist_to_plan = cam->plan_half / (float)tan(cam->fov / 2.0f);
	cam->to_plan = vec2f_scalar(*cam->dir, cam->dist_to_plan);
	cam->plan = ft_vec2f(-cam->dir->y, cam->dir->x);
	return (OK);
}
