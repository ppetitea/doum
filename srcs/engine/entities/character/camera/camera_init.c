/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 01:11:36 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/06 03:14:37 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entity/character_init.h"
#include "utils/error.h"
#include "utils/matrix.h"
#include "libft.h"
#include <math.h>

t_result	init_camera(t_camera *self)
{
	float	fov;
	float	plan_width;

	if (self == NULL)
		return (throw_error("init_camera", "NULL pointer provided"));
	fov = 90.0f / 180.0f * PI;
	plan_width = 1080.0f;
	self->horizon = 120;
	self->fov = fov;
	self->fov_half = self->fov / 2.0f;
	self->dir = ft_vec2f(0, 1);
	self->dir = ft_vec2f(0, 1);
	self->start = to_vtx(rotate(-self->fov_half), self->dir);
	self->end = to_vtx(rotate(self->fov_half), self->dir);
	self->plan_width = plan_width;
	self->height = self->plan_width / 4.0f;
	self->plan_half = self->plan_width / 2.0f;
	self->dist_to_plan = self->plan_half / (float)tan(self->fov / 2.0f);
	self->to_plan = vec2f_scalar(self->dir, self->dist_to_plan);
	self->plan = ft_vec2f(-self->dir.y, self->dir.x);
	self->pos = ft_vec2f(0, 0);
	return (OK);
}

t_result	overwrite_camera_plan(t_camera *self, float fov,
				float plan_width, float height)
{
	if (self == NULL)
		return (throw_error("init_camera", "NULL pointer provided"));
	self->fov = fov;
	self->fov_half = self->fov / 2.0f;
	self->start = to_vtx(rotate(-self->fov_half), self->dir);
	self->end = to_vtx(rotate(self->fov_half), self->dir);
	self->plan_width = plan_width;
	self->plan_half = self->plan_width / 2.0f;
	self->dist_to_plan = self->plan_half / (float)tan(self->fov / 2.0f);
	self->to_plan = vec2f_scalar(self->dir, self->dist_to_plan);
	self->plan = ft_vec2f(-self->dir.y, self->dir.x);
	self->height = height;
	return (OK);
}
