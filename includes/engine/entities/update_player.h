/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 17:04:35 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/19 00:36:12 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UPDATE_PLAYER_H
# define UPDATE_PLAYER_H

# include "engine/entities/build_player.h"

/*
**	camera
*/
t_result	rotate_camera_right(t_entity *entity);
t_result	rotate_camera_left(t_entity *entity);
t_result	translate_camera_forward(t_entity *entity);
t_result	translate_camera_left(t_entity *entity);
t_result	translate_camera_right(t_entity *entity);
t_result	translate_camera_backward(t_entity *entity);

/*
**	player
*/
t_result	update_player_velocity(t_player *self, float velocity);
t_result	update_player_life(t_player *self, float life);
t_result	update_player_armor(t_player *self, float armor);

#endif
