/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_button.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 02:39:58 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/20 04:23:34 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/error.h"
#include "engine/entities/ui/init_button.h"

t_result	update_button_texture(t_entity *entity)
{
	t_button	*button;
	t_vec2i		curr_offset;
	
	if (entity->type != BUTTON)
		return (throw_error("update_button_offset",
			"entity provided is not a button"));
	curr_offset = entity->texture.curr->offset;
	button = (t_button*)entity;
	if (button->super.status.is_selected)
		button->super.texture.curr = &button->selected;
	else if (button->super.status.is_hover)
		button->super.texture.curr = &button->hover;
	else
		button->super.texture.curr = &button->normal;
	entity->texture.curr->offset = curr_offset;
	return (OK);
}
