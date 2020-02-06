/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_build.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 01:00:12 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/06 17:59:22 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build.h"
#include <math.h>

void	build_character_camera_with_obj(t_camera *self,
				t_dnon_object *camera_obj)
{
	if (self == NULL || camera_obj == NULL)
		return (throw_warning("build_camera_with_obj", "NULL pointer", 3));
	init_vec2f_with_obj(&self->dir,
		get_child_list_object_by_key(camera_obj, "direction"));
	init_vec2f_with_obj(&self->pos,
		get_child_list_object_by_key(camera_obj, "position"));
	self->fov = get_float_value_by_key(camera_obj, "fov", 90.0f) / 180.0f * PI;
	self->fov_half = self->fov / 2.0f;
	self->plan_width = get_float_value_by_key(camera_obj, "plan_width", 640.0f);
	self->height = get_float_value_by_key(camera_obj, "height", 160);
	self->plan_half = self->plan_width / 2.0f;
	self->dist_to_plan = self->plan_half / (float)tan(self->fov / 2.0f);
	self->to_plan = vec2f_scalar(self->dir, self->dist_to_plan);
	self->plan = ft_vec2f(-self->dir.y, self->dir.x);
}
