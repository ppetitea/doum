/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_init.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 23:21:04 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/26 08:00:46 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_INIT_H
# define CHARACTER_INIT_H

# include "engine/entity/entity_init.h"

typedef	struct	s_camera
{
	float	fov;
	float	fov_half;
	float	plan_width;
	float	plan_half;
	float	dist_to_plan;
	float	height;
	size_t	horizon;
	t_vec2f	pos;
	t_vec2f	dir;
	t_vec2f	to_plan;
	t_vec2f	plan;
}				t_camera;

t_result		init_camera(t_camera *self);
t_result		overwrite_camera_plan(t_camera *self, float fov,
					float plan_width, float height);
				
typedef enum	e_weapon_type
{
	HAND,
	MELEE,
	GUN,
}				t_weapon_type;

typedef struct	s_pov_textures
{
	t_list_head	first_person;
	t_list_head	third_person;
}				t_pov_textures;

typedef struct	s_weapon
{
	t_list_head			node;
	t_weapon_type		type;
	char				*name;
	size_t				ammo;
	size_t				magazine_size;
	size_t				magazine;
	ssize_t				damages;
	t_pov_textures		*fire;
	t_pov_textures		*reload;
}				t_weapon;

t_weapon		*init_new_weapon();

typedef enum	e_character_type
{
	GUNMAN,
	MONSTER,
	OBJECT,
}				t_character_type;

typedef struct	s_character
{
	t_entity			super;
	t_character_type	type;
	t_camera			camera;
	t_bool				is_player;
	ssize_t				life;
	size_t				armor;
	float				size;
	float				velocity;
	struct s_character	*target;
	t_pov_textures		*hurt_texture;
	t_pov_textures		*die_texture;
	t_list_head			all_weapons;
	t_list_head			weapons;
	t_weapon			*curr_weapon;
	t_oriented_textures	*oriented;
	void				(*orientate)(struct s_character*);
	void				(*catch_weapon)(struct s_character*, char*);
	void				(*drop_weapon)(struct s_character*);
	void				(*run)(struct s_character*);
	void				(*jump)(struct s_character*);
	void				(*crawl)(struct s_character*);
	void				(*attack)(struct s_character*);
	void				(*die)(struct s_character*);
}				t_character;

t_character		*init_new_character();

#endif