/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entities.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 04:13:23 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/15 06:00:27 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITIES_H
# define ENTITIES_H

# include "libft.h"
# include "resources/textures/texture.h"
# include "game.h"
# include <time.h>

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

typedef struct	s_listener
{
	t_bool		display;
	t_bool		is_hoverable;
	t_bool		is_hover;
	t_bool		is_selectable;
	t_bool		is_selected;
	t_result	(*action_select)(t_game*, void*); // void* -> t_entity*
	t_bool		is_draggable;
	t_bool		is_dragged;
	t_result	(*action_drag)(t_game*, void*); // void* -> t_entity*
}				t_listener;

typedef struct	s_listener_args
{
	t_bool		display;
	t_bool		is_hoverable;
	t_bool		is_selectable;
	t_result	(*action_select)(t_game*, void*); // void* -> t_entity*
	t_bool		is_draggable;
	t_result	(*action_drag)(t_game*, void*); // void* -> t_entity*
}				t_listener_args;

t_listener	listener(t_listener_args args);

/*
**	Texture interface
*/

typedef enum	e_animation_status
{
	INFINITE,
	IN_PROGRESS,
	STOP,
	NONE
}				t_animation_status;

typedef struct			s_entity_texture
{
	struct timespec		last;
	t_vec2i				anchor;
	t_texture			*t;
	t_texture			*t_head;
	t_animation_status	animation;
	t_result			(*update_anchor)(void*, t_vec2i);
	t_result			(*update_offset)(void*, t_vec2i);
	t_result			(*update_texture)(void*);
}						t_entity_texture;

typedef struct	s_entity_texture_args
{
	t_vec2i					anchor;
	t_texture				*texture;
	t_animation_status		animation;
	t_result				(*update_anchor)(void*, t_vec2i);
	t_result				(*update_offset)(void*, t_vec2i);
	t_result				(*update_texture)(void*);
}				t_entity_texture_args;

/*
**	Entity
*/

typedef enum	e_entity_type
{
	BUTTON,
	SPAWNER,
	SPRITE,
}				t_entity_type;

typedef struct	s_entity
{
	t_list_head				node;
	t_entity_texture		texture;
	t_listener				status;
	t_entity_type			type;
	t_vec2f					pos;
	t_vec2f					dir;
}				t_entity;

typedef struct	s_entity_args
{
	t_entity_texture_args	texture_args;
	t_listener_args			listener_args;
	t_entity_type			type;
	t_vec2f					pos;
	t_vec2f					dir;
}				t_entity_args;

t_result	build_entity(t_entity *self, t_entity_args args);

t_result	initialize_entities(t_game *game);
t_result	initialize_buttons_entities(t_game *game);
t_result	initialize_spawners_entities(t_game *game);
t_result	initialize_sprites_entities(t_game *game);


t_result	update_hoverables_entities(t_list_head *entities, t_mouse mouse);
t_result	update_selectables_entities(t_game *game, t_list_head *entities,
 				t_mouse mouse);
t_result	update_draggables_entities(t_game *game, t_list_head *entities,
 				t_mouse mouse);

#endif