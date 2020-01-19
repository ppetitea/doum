/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_player.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 17:04:35 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/19 02:30:04 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILD_PLAYER_H
# define BUILD_PLAYER_H

# include "engine/resources/textures/texture.h"
# include "engine/entities/build_entity.h"
# include "utils/matrix.h"

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
	size_t			magazine_size;
	size_t			magazine;
	size_t			damages;
	t_texture		fire;
	t_texture		reload;
}				t_weapon;

t_weapon			*build_weapon(char *name, t_weapon_type type);
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

t_result			build_player_camera(t_camera *self, float fov,
						float plan_width, float height);

typedef struct		s_player
{
	t_entity		super;
	t_camera		cam;
	float			velocity;
	size_t			life;
	size_t			armor;
	t_weapon		*weapons;
	t_weapon		*weapons_storage;
	t_result		(*catch_weapon)(struct s_player*, char*);
	t_result		(*drop_weapon)(struct s_player*, char*);
}					t_player;

t_player			*build_player();
t_result			build_player_entity_listener(t_entity *self, t_list_head *render,
						t_list_head *storage, t_bool display);
t_result			build_player_entity_texture(t_entity_texture *self,
						t_texture *texture, t_vec2i	anchor);

#endif
