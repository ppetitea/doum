/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_checkbox.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 02:39:58 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/21 00:06:09 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/error.h"
#include "engine/entities/ui/init_checkbox.h"
#include "engine/entities/ui/update_checkbox.h"
#include "engine/entities/update_entity.h"

// t_result	checkbox_toogle_display_linked_entities(t_entity *entity)
// {
// 	t_checkbox	*checkbox;
// 	t_list_head	*pos;
// 	t_list_head	*next;
// 	t_entity	*linked;
	
// 	if (entity->type != CHECKBOX)
// 		return (throw_error("checkbox_toggle_dle", "must provide checkbox"));
// 	checkbox = (t_checkbox*)entity;
// 	pos = &checkbox->linked_entities;
// 	next = pos->next;
// 	while ((pos = next) != &checkbox->linked_entities)
// 	{
// 		next = next->next;
// 		linked = (t_entity*)pos;
// 		if (checkbox->super.status.is_selected)
// 			display_entity(linked);
// 		else
// 			hide_entity(linked);
// 	}
// 	return (OK);
// }

// t_result	link_entity_to_checkbox(t_checkbox *self, t_entity *entity)
// {
// 	t_checkbox_node	*node;

// 	if (self == NULL || entity == NULL)
// 		return (throw_error("link_entity", "NULL pointer provided"));
// 	if (!(node = (t_checkbox_node*)malloc(sizeof(t_checkbox_node))))
// 		return (throw_error("link_entity", "malloc failed"));
// 	init_list_head(&node->node);
// 	node->entity_ref = entity;
// 	list_add_entry(&node->node, &self->linked_entities);
// 	return (OK);
// }

t_result	update_checkbox_texture(t_entity *entity)
{
	t_checkbox	*checkbox;
	t_vec2i		curr_offset;
	
	if (entity->type != CHECKBOX)
		return (throw_error("update_checkbox_offset",
			"entity provided is not a checkbox"));
	curr_offset = entity->texture.curr->offset;
	checkbox = (t_checkbox*)entity;
	if (checkbox->super.status.is_selected)
		checkbox->super.texture.curr = &checkbox->checked;
	else if (checkbox->super.status.is_hover)
		checkbox->super.texture.curr = &checkbox->hover;
	else
		checkbox->super.texture.curr = &checkbox->normal;
	entity->texture.curr->offset = curr_offset;
	return (OK);
}
