/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_button.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 02:39:58 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/21 22:48:21 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/error.h"
#include "engine/entities/init_entity.h"
#include "engine/entities/update_entity.h"
#include "engine/entities/ui/init_button.h"
#include "engine/entities/ui/update_button.h"

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

t_result	trigger_button_action(t_entity *entity)
{
	t_button		*button;
	t_entity_node	*child;
	t_list_head		*pos;
	t_list_head		*next;
	
	if (entity == NULL)
		return (throw_error("trigger_button_action", "NULL pointer"));
	if (entity->type != BUTTON)
		return (throw_error("trigger_button_action", "entity must be button"));
	button = (t_button*)entity;
	child = NULL;
	pos = &entity->childs;
	next = pos->next;
	while ((pos = next) != &entity->childs)
	{
		next = next->next;
		child = (t_entity_node*)pos;
		button->action(child->entity);
	}
	return (OK);
}
