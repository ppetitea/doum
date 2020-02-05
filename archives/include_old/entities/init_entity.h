/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_entity.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 04:13:23 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/25 01:49:57 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_ENTITY_H
# define INIT_ENTITY_H

# include "libft.h"
# include "engine/resource/image/texture_init.h"
# include "engine/interface/init_camera.h"
# include "utils/parser.h"
# include <sys/time.h>

/*
**	Fabrique d'entites :
**
**	Permet de creer des entites generiques ayant des interfaces communes
**
**	Chaque entite possede les interfaces suivantes:
**		->	listener	(gere l'interaction avec l'utilisateur)
**		->	texture		(gere l'affichage a l'ecran)
**		->	position	(sur la map si l'entite est un sprite par exemple)
**		->	direction	(orientation dans la map)
*/

/*
**	Listener interface
*/

void					swap_to_editor_scene();
void					create_draggable_clone();
void					display_character_form();
void					set_draw_mode();
void					toogle_display_childs();
void					toogle_display();

void					swap_to_menu_scene();
void					swap_to_next_map();
void					swap_to_prev_map();

void					swap_to_game_scene();

/*
**	Texture interface
*/

/*
**	Entity
*/


t_result	build_entity_with_obj(t_entity *self, t_list_head *render,
				t_list_head *storage, t_dnon_object *entity_obj);
t_dnon_object	*build_obj_with_entity(t_entity *self);
t_result	init_entity_listener(t_listener *self);
t_result	build_entity_listener_with_obj(
				t_entity *self,
				t_list_head *render,
				t_list_head *storage,
				t_dnon_object *status_obj);
t_dnon_object	*build_obj_with_listener(t_entity *self);
t_result	init_entity_texture(t_entity_texture *self);
t_dnon_object	*build_obj_with_entity_texture(t_entity *self);
t_result	build_entity_childs_with_obj(t_entity *parent, t_list_head *render,
				t_list_head *storage, t_dnon_object *childs_obj);
t_dnon_object	*build_obj_with_entity_childs(t_entity *self);

void			animate_texture(t_entity *entity);
void			update_texture_by_status(t_entity_texture *self,
					t_listener *status);

/*
**	Point of view textures
*/


t_weapon		*init_new_weapon();
t_result		build_weapon_with_obj(t_weapon *self,
					t_dnon_object *weapon_obj);
t_dnon_object	*build_obj_with_weapon(t_weapon *self);

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
	t_list_head			view_textures;
	t_pov_textures		die_texture;
	t_list_head			all_weapons;
	t_list_head			weapons;
	t_weapon			*curr_weapon;
	t_oriented_textures	oriented;
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
t_result		build_character_with_obj(t_character *self,
					t_dnon_object *character_obj);
t_dnon_object	*build_obj_with_character(t_character *self);

void			orientate_texture(t_character *c);
void			character_run(t_character *self);
void			character_jump(t_character *self);
void			character_crawl(t_character *self);
void			character_attack(t_character *self);
void			character_die(t_character *self);


#endif
