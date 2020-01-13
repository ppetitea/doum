/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 04:13:23 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/13 05:17:49 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UI_H
# define UI_H

# include "libft.h"
# include "textures/texture.h"

typedef enum	e_ui_component_type
{
	BUTTON,
	UNKNOW
}				t_ui_component_type;

typedef struct	s_listener_component
{
	t_bool		is_hoverable;
	t_bool		is_hover;
	t_bool		is_selectable;
	t_bool		is_select;
	t_bool		is_draggable;
	t_bool		is_dragged;
	t_bool		is_checkable;
	t_bool		is_checked;
}				t_listener_component;

typedef struct	s_ui_component
{
	t_list_head				node;
	t_vec2i					anchor;
	t_texture				*texture;
	t_listener_component	status;
	t_ui_component_type		type;
	void					(*update_texture)();
	void					(*update_anchor)();
}				t_ui_component;

typedef struct	s_ui_component_args
{
	t_vec2i					anchor;
	t_texture				*texture;
	t_listener_component	status;
	t_ui_component_type		type;
	void					(*update_texture)();
	void					(*update_anchor)();
}				t_ui_component_args;

t_result	build_ui_component(t_ui_component *self, t_ui_component_args args);
t_listener_component	listener_component(t_bool is_hoverable,
	t_bool is_selectable, t_bool is_draggable, t_bool is_checkable);

	
#endif