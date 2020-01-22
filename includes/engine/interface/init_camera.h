/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 17:04:35 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/22 17:02:30 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_CAMERA_H
# define INIT_CAMERA_H

# include "engine/resources/textures/texture.h"
# include "engine/entities/init_entity.h"
# include "utils/matrix.h"

typedef	struct	s_camera
{
	float	fov;
	float	fov_half;
	float	plan_width;
	float	plan_half;
	float	dist_to_plan;
	float	height;
	size_t	horizon;
	t_vec2f	*pos;
	t_vec2f	*dir;
	t_vec2f	to_plan;
	t_vec2f	plan;
}				t_camera;

t_result		init_camera(t_camera *self);
t_result		link_camera_to_entity(t_camera *self, t_vec2f *pos,
					t_vec2f *dir);
t_result		overwrite_camera_plan(t_camera *self, float fov,
					float plan_width, float height);

#endif
