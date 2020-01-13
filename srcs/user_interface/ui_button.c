/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_button.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 04:57:16 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/13 05:18:34 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/error.h"
#include "user_interface/button.h"
#include "user_interface/ui.h"

t_ui_component_args	ui_button_args(t_texture *texture)
{
	t_ui_component_args	args;
	
	args.type = BUTTON;
	args.anchor = ft_vec2i(0, 0);
	args.texture = texture;
	args.update_anchor = NULL;
	args.update_texture = NULL;
	args.status = listener_component(TRUE, TRUE, TRUE, TRUE);
	return (args);
}

t_button	*create_ui_button(t_texture *normal, t_texture *selected)
{
	t_button			*self;
	t_ui_component_args	args;

	if (!(self = (t_button*)malloc(sizeof(t_button))))
		return (throw_null("create_ui_button", "malloc failed"));
	args = ui_button_args(normal);
	build_ui_component(&self->parent, args);
	
}
