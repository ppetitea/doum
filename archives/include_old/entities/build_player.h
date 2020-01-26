/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_player.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 17:04:35 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/22 03:38:24 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILD_PLAYER_H
# define BUILD_PLAYER_H

# include "engine/entities/init_player.h"
# include "engine/scenes/init_scene.h"
# include "utils/parser.h"
# include "utils/error.h"

t_result	build_player(t_scene *scene, t_dnon_object *player_obj);
t_result	build_player_camera(t_player *player, t_dnon_object *camera_obj);
t_result	build_player_weapons(t_list_head *images, t_player *player,
				t_dnon_object *weapons_obj);
t_result	build_player_weapon(t_list_head *images, t_player *player,
				t_dnon_object *weapon_obj);
t_result	add_player_weapon(t_weapon *weapon, t_player *player,
				t_dnon_object *weapon_obj);
t_result	build_player_weapon_textures(t_list_head *images, t_weapon *self,
				t_dnon_object *w_textures_obj);
t_result	init_weapon_type_with_obj(t_weapon_type *type, char *weapon_type);


#endif
