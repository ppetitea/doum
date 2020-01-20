/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_entity.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 04:13:23 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/20 04:20:21 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_ENTITY_H
# define INIT_ENTITY_H

# include "libft.h"
# include "engine/resources/textures/texture.h"
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
	t_list_head	*render_list;
	t_list_head	*storage_list;
	t_bool		is_hoverable;
	t_bool		is_hover;
	t_bool		is_selectable;
	t_bool		is_selected;
	t_bool		is_draggable;
	t_bool		is_dragged;
}				t_listener;

/*
**	Texture interface
*/

typedef enum	e_animation_status
{
	INFINITE,
	IN_PROGRESS,
	EPHEMERAL,
	STOP,
	FINAL,
	NONE
}				t_animation_status;

typedef struct			s_entity_texture
{
	struct timespec		last;
	float				scale;
	t_vec2i				anchor;
	t_texture			*curr;
	t_list_head			*curr_head;
	t_texture			*prev;
	t_list_head			*prev_head;
	t_animation_status	animation;
}						t_entity_texture;

/*
**	Entity trigger actions
*/

typedef struct			s_entity_actions
{
	t_result			(*action_select)(void*);
	t_result			(*action_drag)(void*);
	t_result			(*update_texture)(void*);
}						t_entity_actions;

/*
**	Entity
*/

typedef enum	e_entity_type
{
	BUTTON,
	SPAWNER,
	SPRITE,
	PLAYER,
	ENNEMY,
}				t_entity_type;

typedef struct	s_entity
{
	t_list_head				node;
	t_entity_texture		texture;
	t_listener				status;
	t_entity_actions		trigger;
	t_entity_type			type;
	t_vec2f					pos;
	t_vec2f					dir;
}				t_entity;

t_result	init_entity(t_entity *self, t_entity_type type);
t_result	init_entity_actions(t_entity_actions *self);
t_result	init_entity_texture(t_entity_texture *self);
t_result	init_entity_listener(t_listener *self);

#endif