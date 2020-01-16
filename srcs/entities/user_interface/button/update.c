/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 02:39:58 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/15 23:35:39 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/error.h"
#include "entities/ui/button.h"
#include "entities/entities.h"
#include "resources/textures/texture.h"

t_result	update_button_texture(t_entity *entity)
{
	t_button	*button;
	t_vec2i		curr_offset;
	
	if (entity->type != BUTTON)
		return (throw_error("update_button_offset",
			"entity provided is not a button"));
	curr_offset = entity->texture.t->offset;
	button = (t_button*)entity;
	if (button->super.status.is_selected)
		button->super.texture.t = button->selected;
	else if (button->super.status.is_hover)
		button->super.texture.t = button->hover;
	else
		button->super.texture.t = button->normal;
	entity->texture.t->offset = curr_offset;
	return (OK);
}