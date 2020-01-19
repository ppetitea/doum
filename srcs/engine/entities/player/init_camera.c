/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 01:11:36 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/19 17:23:23 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/interface/init_camera.h"
#include "utils/error.h"
#include "utils/matrix.h"
#include "libft.h"
#include <math.h>

t_result	init_camera(t_camera *self)
{
	t_vec2f	dir;
	float	fov;
	float	plan_width;

	if (self == NULL)
		return (throw_error("init_camera", "NULL pointer provided"));
	dir = ft_vec2f(0, 1);
	fov = 90.0f / 180.0f * PI;
	plan_width = 640.0f;
	self->fov = fov;
	self->fov_half = self->fov / 2.0f;
	self->plan_width = plan_width;
	self->height = self->plan_width / 4.0f;
	self->plan_half = self->plan_width / 2.0f;
	self->dist_to_plan = self->plan_half / (float)tan(self->fov / 2.0f);
	self->to_plan = vec2f_scalar(dir, self->dist_to_plan);
	self->plan = ft_vec2f(-dir.y, dir.x);
	self->pos = NULL;
	self->dir = NULL;
	return (OK);
}

t_result	link_camera_to_entity(t_camera *self, t_vec2f *pos,
				t_vec2f *dir)
{
	if (self == NULL || pos == NULL || dir == NULL)
		return (throw_error("init_camera", "NULL pointer provided"));
	self->dir = dir;
	self->pos = pos;
	return (OK);
}

t_result	overwrite_camera_plan(t_camera *self, float fov,
				float plan_width, float height)
{
	t_vec2f	dir;

	if (self == NULL)
		return (throw_error("init_camera", "NULL pointer provided"));
	dir = (self->dir == NULL) ? ft_vec2f(0, 1) : *self->dir;
	self->fov = fov;
	self->fov_half = self->fov / 2.0f;
	self->plan_width = plan_width;
	self->plan_half = self->plan_width / 2.0f;
	self->dist_to_plan = self->plan_half / (float)tan(self->fov / 2.0f);
	self->to_plan = vec2f_scalar(dir, self->dist_to_plan);
	self->plan = ft_vec2f(-dir.y, dir.x);
	self->height = height;
	return (OK);
}
