// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   init_player.h                                      :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2020/01/15 17:04:35 by ppetitea          #+#    #+#             */
// /*   Updated: 2020/01/23 20:29:45 by ppetitea         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #ifndef INIT_PLAYER_H
// # define INIT_PLAYER_H

// # include "engine/resource/image/texture_init.h"
// # include "engine/interface/init_camera.h"
// # include "engine/entities/init_entity.h"
// # include "utils/matrix.h"

// typedef enum	e_weapon_type
// {
// 	SWORD,
// 	GUN,
// }				t_weapon_type;

// typedef struct	s_weapon
// {
// 	t_list_head		node;
// 	t_weapon_type	type;
// 	char			*name;
// 	size_t			ammo;
// 	size_t			magazine_size;
// 	size_t			magazine;
// 	size_t			damages;
// 	t_list_head		fire;
// 	t_list_head		reload;
// }				t_weapon;

// t_weapon			*init_new_weapon();
// t_result			overwrite_weapon_ammo(t_weapon *self, size_t ammo,
// 						size_t magazine_size, size_t magazine);

// typedef struct		s_player_weapons
// {
// 	t_weapon		*curr;
// 	t_list_head		list;
// 	t_list_head		all;
// 	t_result		(*catch_weapon)(void*, char*);
// 	t_result		(*drop_weapon)(void*, char*);
// }					t_player_weapons;

// t_result			init_player_weapon(t_player_weapons *self);
// t_result			overwrite_current_player_weapon(t_player_weapons *self,
// 						t_weapon *curr);

// typedef struct		s_player
// {
// 	t_entity			super;
// 	t_camera			cam;
// 	float				velocity;
// 	size_t				life;
// 	size_t				armor;
// 	t_player_weapons	weapon;
// }					t_player;

// t_player			*init_new_player();
// t_result			overwrite_player_defense(t_player *self, size_t life,
// 						size_t armor);
// t_result			overwrite_player_coordinates(t_player *self, t_vec2f pos,
// 						t_vec2f dir);
// t_result			overwrite_player_entity_listener(
// 						t_entity *self,
// 						t_list_head *render,
// 						t_list_head *storage,
// 						t_bool display);
// t_result			overwrite_player_entity_texture(t_entity_texture *self,
// 						t_list_head *texture_head, t_vec2i	anchor);

// #endif
