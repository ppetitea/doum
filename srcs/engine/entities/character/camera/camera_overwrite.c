/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_overwrite.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 08:24:48 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/26 08:59:46 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entity/character_update.h"
#include "utils/error.h"

t_result	overwrite_camera_with_obj(t_camera *camera,
				t_dnon_object *camera_obj)
{
	t_dnon_object	*vec2f_obj;
	float			result_f;
	
	if (camera == NULL || camera_obj == NULL)
		return (throw_error("overwrite_camera", "NULL pointer provided"));
	
	if ((result_f = get_float_value_by_key(camera_obj, "fov", -1)) != -1)
		camera->fov = result_f;
	if ((result_f = get_float_value_by_key(camera_obj, "plan_width", -1)) != -1)
		camera->plan_width = result_f;
	if ((result_f = get_float_value_by_key(camera_obj, "height", -1)) != -1)
		camera->height = result_f;
	if ((result_f = get_float_value_by_key(camera_obj, "horizon", -1)) != -1)
		camera->horizon = (size_t)result_f;
	if ((vec2f_obj = get_child_list_object_by_key(camera_obj, "position")))
		init_vec2f_with_obj(&camera->pos, vec2f_obj);
	if ((vec2f_obj = get_child_list_object_by_key(camera_obj, "direction")))
		init_vec2f_with_obj(&camera->dir, vec2f_obj);
	overwrite_camera_plan(camera, camera->fov, camera->plan_width,
		camera->height);
	return (OK);
}
