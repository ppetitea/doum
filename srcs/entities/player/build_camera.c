/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 01:11:36 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/17 21:23:47 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/error.h"
#include "entities/player.h"
#include "utils/matrix.h"
#include <math.h>

t_result	build_player_camera(t_camera *self, t_camera_args args)
{
	self->fov = args.fov;
	self->plan_width = args.plan_width;
	self->height = args.height;
	self->plan_half = self->plan_width / 2.0f;
	self->dist_to_plan = self->plan_half / (float)tan(self->fov / 2.0f);
	self->to_plan = vec2f_scalar(*self->dir, self->dist_to_plan);
	self->plan = ft_vec2f(-self->dir->y, self->dir->x);
	return (OK);
}

t_camera_args	camera_args(float fov, float plan_width, float height)
{
	t_camera_args	args;

	args.fov = fov;
	args.plan_width = plan_width;
	args.height = height;
	return (args);
}
