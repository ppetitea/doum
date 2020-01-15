/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 02:39:58 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/15 02:41:41 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/error.h"
#include "entities/ui/button.h"
#include "entities/entities.h"
#include "resources/textures/texture.h"

t_result	update_button_anchor(t_entity *entity, t_vec2i anchor)
{
	t_button	*button;

	if (entity->type != BUTTON)
		return (throw_error("update_button_anchor",
			"entity provided is not a button"));
	button = (t_button*)entity;
	button->super.texture.anchor = anchor;
	return (OK);
}

t_result	update_button_offset(t_entity *entity, t_vec2i offset)
{
	t_button	*button;

	if (entity->type != BUTTON)
		return (throw_error("update_button_offset",
			"entity provided is not a button"));
	button = (t_button*)entity;
	button->super.texture.t->offset = offset;
	return (OK);
}

t_result	update_button_texture_with_status(t_entity *entity)
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