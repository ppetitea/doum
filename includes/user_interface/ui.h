/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 04:13:23 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/14 02:58:26 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UI_H
# define UI_H

# include "libft.h"
# include "textures/texture.h"
# include "game/game.h"

typedef enum	e_ui_component_type
{
	BUTTON,
	SPAWNER,
}				t_ui_component_type;

typedef struct	s_listener_component
{
	t_bool		is_hoverable;
	t_bool		is_hover;
	t_bool		is_selectable;
	t_bool		is_selected;
	t_result	(*action_select)(t_game*, void*);
	t_bool		is_draggable;
	t_bool		is_dragged;
	t_result	(*action_drag)(t_game*, void*);
}				t_listener_component;

typedef struct	s_listener_args
{
	t_bool		is_hoverable;
	t_bool		is_selectable;
	t_result	(*action_select)(t_game*, void*);
	t_bool		is_draggable;
	t_result	(*action_drag)(t_game*, void*);
}				t_listener_args;

typedef struct	s_ui_component
{
	t_list_head				node;
	t_vec2i					anchor;
	t_texture				*texture;
	t_listener_component	status;
	t_ui_component_type		type;
	t_result				(*update_anchor)(struct s_ui_component*, t_vec2i);
	t_result				(*update_offset)(struct s_ui_component*, t_vec2i);
	t_result				(*update_texture)(struct s_ui_component*);
}				t_ui_component;

typedef struct	s_ui_component_args
{
	t_vec2i					anchor;
	t_texture				*texture;
	t_listener_component	status;
	t_ui_component_type		type;
	t_result				(*update_anchor)(t_ui_component*, t_vec2i);
	t_result				(*update_offset)(t_ui_component*, t_vec2i);
	t_result				(*update_texture)(t_ui_component*);
}				t_ui_component_args;

t_result	build_ui_component(t_ui_component *self, t_ui_component_args args);
t_listener_component	listener_component(t_listener_args args);
t_result	initialize_user_interface(t_game *game);
t_result	update_ui_components_hoverable(t_game *game, t_vec2i mouse);
t_result	update_ui_components_selectable(t_game *game, t_vec2i mouse);
t_result	update_ui_components_draggable(t_game *game, t_vec2i mouse);

#endif