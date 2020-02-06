/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_update.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 02:46:49 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/06 18:12:41 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_UPDATE_H
# define CHARACTER_UPDATE_H

# include "engine/entity/character_init.h"
# include "engine/game/game_init.h"

/*
**	GET
*/
t_weapon	*get_weapon_by_name(t_list_head *weapons, char *name);

/*
** DUPLICATE
*/
t_character	*duplicate_character(t_character *src);
t_weapon	*duplicate_weapon(t_weapon *src);


/*
** OVERWRITE
*/
t_result	overwrite_character_with_obj(t_character *self,
				t_dnon_object *character_obj);
t_result	overwrite_weapons_with_obj(t_character *self,
				t_dnon_object *weapons_obj);
t_result	overwrite_weapon_with_obj(t_character *character, t_weapon *self,
				t_dnon_object *weapon_obj);
t_result	overwrite_camera_with_obj(t_camera *camera,
				t_dnon_object *camera_obj);

/*
** TRIGGER
*/
t_result	trigger_player_action_by_drag(t_character *player, t_mouse *mouse);
t_result	trigger_character_action_by_drag(t_list_head *entities,
				t_mouse *mouse);
t_result	trigger_player_action_by_drop(t_character *player, t_mouse *mouse);
t_result	trigger_character_action_by_drop(t_list_head *entities,
				t_mouse *mouse);

/*
** UPDATE
*/
t_result	update_weapon_activation(t_character *character, t_weapon *weapon,
				t_bool is_active);
t_result	rotate_camera_left(t_entity *entity);
t_result	rotate_camera_right(t_entity *entity);
t_result	translate_camera_up(t_entity *entity);
t_result	translate_camera_down(t_entity *entity);
t_result	translate_camera_forward(t_entity *entity);
t_result	translate_camera_right(t_entity *entity);
t_result	translate_camera_left(t_entity *entity);
t_result	translate_camera_backward(t_entity *entity);
t_result	translate_camera_horizon_up(t_voxel_map_3d_config *config);
t_result	translate_camera_horizon_down(t_voxel_map_3d_config *config);

#endif