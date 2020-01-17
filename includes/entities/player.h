/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 17:04:35 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/17 16:31:33 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "entities/entities.h"

typedef enum	e_weapon_type
{
	HANDS,
	GUN,
}				t_weapon_type;

typedef struct	s_weapon
{
	t_list_head		node;
	t_weapon_type	type;
	char			*name;
	size_t			ammo;
	size_t			cartridge_clip_size;
	size_t			cartridges;
	size_t			damages;
	t_texture		*fire;
	t_texture		*reload;
}				t_weapon;

typedef struct	s_weapon_args
{
	t_weapon_type	type;
	char			*name;
	size_t			ammo;
	size_t			damages;
	t_texture		*fire;
	t_texture		*reload;
}				t_weapon_args;

t_weapon			*add_weapon(t_weapon **list, char *name,
						t_weapon_type type);
t_result			weapon_fire(t_entity *entity);
t_result			weapon_reload(t_entity *entity);
t_result			weapon_next(t_entity *entity);
t_result			update_weapon_name(t_weapon *self, char *name);
t_result			update_weapon_ammo(t_weapon *self, size_t ammo);
t_result			update_weapon_damages(t_weapon *self, size_t damages);


typedef	struct	s_camera
{
	float	fov;
	float	plan_width;
	float	plan_half;
	float	dist_to_plan;
	float	height;
	t_vec2f	*pos;
	t_vec2f	*dir;
	t_vec2f	to_plan;
	t_vec2f	plan;
}				t_camera;

typedef struct		s_camera_args
{
	float	fov;
	float	plan_width;
	float	height;
	t_vec2f	*pos;
	t_vec2f	*dir;
}					t_camera_args;

t_camera_args		camera_args(float fov, float plan_width, float height);
t_result			build_player_camera(t_camera *self, t_camera_args args);

typedef struct		s_player
{
	t_entity		super;
	t_camera		cam;
	// t_usize			size;
	float			velocity;
	size_t			life;
	size_t			armor;
	t_weapon		*weapons;
	t_weapon		*weapons_storage;
	t_result		(*catch_weapon)(struct s_player*, char*);
	t_result		(*drop_weapon)(struct s_player*, char*);
}					t_player;

t_player			*create_player();
t_result			update_player_velocity(t_player *self, float velocity);
t_result			update_player_life(t_player *self, float life);
t_result			update_player_armor(t_player *self, float armor);

t_result			build_player_listener(t_listener *self, t_list_head *render,
						t_list_head *storage, t_bool display);
t_result			build_player_entity_texture(t_entity_texture *self,
						t_entity_texture_args args);
t_result			build_player_entity(t_entity *self, t_entity_args args);

#endif
