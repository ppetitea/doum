/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_init.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 23:21:04 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/06 03:29:57 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_INIT_H
# define ENTITY_INIT_H

# include "engine/resource/image/texture_init.h"
# include "engine/component/listener.h"
# include "utils/parser.h"
# include "libft.h"
# include <sys/time.h>

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
	struct timeval		last;
	t_vec2f				scale;
	t_vec2i				offset;
	t_vec2i				anchor;
	t_texture			*curr;
	t_list_head			*curr_head;
	t_texture			*prev;
	t_list_head			*prev_head;
	t_animation_status	animation;
	void				(*animate)(void*);
	t_list_head			*normal;
	t_list_head			*hover;
	t_list_head			*dragged;
	void				(*update_by_status)(struct s_entity_texture*,
							t_listener*);
}						t_entity_texture;

typedef enum	e_entity_type
{
	UI,
	CHARACTER,
}				t_entity_type;

typedef struct	s_entity
{
	t_list_head			node;
	t_entity_type		type;
	t_listener			status;
	t_entity_texture	texture;
	char				*name;
	t_list_head			childs;
	struct s_entity		*parent;
	void				(*destroy)(struct s_entity*);
}				t_entity;

t_result	init_entity(t_entity *self, t_entity_type type);
t_entity	*init_new_entity(t_entity_type type);

#endif
