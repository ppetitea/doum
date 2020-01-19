/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_camera.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 17:04:35 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/19 16:37:41 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UPDATE_CAMERA_H
# define UPDATE_CAMERA_H

# include "engine/interface/init_camera.h"

/*
**	camera
*/
t_result	rotate_camera_right(t_entity *entity);
t_result	rotate_camera_left(t_entity *entity);
t_result	translate_camera_forward(t_entity *entity);
t_result	translate_camera_left(t_entity *entity);
t_result	translate_camera_right(t_entity *entity);
t_result	translate_camera_backward(t_entity *entity);

#endif
