/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listener.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 23:48:12 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/29 00:50:06 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef LISTENER_H
# define LISTENER_H

# include "libft.h"

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
	t_list_head	hover_actions;
	t_list_head	select_actions;
	t_list_head	drag_actions;
	t_list_head	drop_actions;
}				t_listener;

#endif