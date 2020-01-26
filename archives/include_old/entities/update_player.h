/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 17:04:35 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/19 16:41:10 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UPDATE_PLAYER_H
# define UPDATE_PLAYER_H

# include "engine/entities/init_player.h"

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
**	weapon
*/
t_result			weapon_fire(t_entity *entity);
t_result			weapon_reload(t_entity *entity);
t_result			weapon_next(t_entity *entity);
t_result			update_weapon_name(t_weapon *self, char *name);
t_result			update_weapon_ammo(t_weapon *self, size_t ammo);
t_result			update_weapon_damages(t_weapon *self, size_t damages);

/*
**	player
*/
t_result	update_player_velocity(t_player *self, float velocity);
t_result	update_player_life(t_player *self, float life);
t_result	update_player_armor(t_player *self, float armor);

#endif
