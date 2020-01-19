/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 01:11:36 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/19 00:36:34 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entities/build_player.h"
#include "utils/error.h"
#include "utils/matrix.h"
#include "libft.h"
#include <math.h>

t_result	build_player_camera(t_camera *self, float fov, float plan_width,
				float height)
{
	self->fov = fov;
	self->plan_width = plan_width;
	self->height = height;
	self->plan_half = self->plan_width / 2.0f;
	self->dist_to_plan = self->plan_half / (float)tan(self->fov / 2.0f);
	self->to_plan = vec2f_scalar(*self->dir, self->dist_to_plan);
	self->plan = ft_vec2f(-self->dir->y, self->dir->x);
	return (OK);
}
