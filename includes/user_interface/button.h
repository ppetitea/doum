/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 04:12:43 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/13 05:04:46 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUTTON_H
# define BUTTON_H

# include "user_interface/ui.h"
# include "textures/texture.h"

typedef struct		s_button
{
	t_ui_component	parent;
	t_texture		*normal;
	t_texture		*hover;
	t_texture		*selected;
	t_texture		*checked;
	t_texture		*dragged;
}					t_button;

t_button			*create_ui_button(t_texture *normal, t_texture *selected);

#endif