/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_checkbox.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 04:12:43 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/20 22:30:05 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UPDATE_CHECKBOX_H
# define UPDATE_CHECKBOX_H

# include "engine/entities/ui/init_checkbox.h"
# include "engine/entities/init_entity.h"

typedef struct	s_checbox_node
{
	t_list_head	node;
	t_entity	*entity_ref;
}				t_checkbox_node;

t_result	update_checkbox_texture(t_entity *entity);
t_result	checkbox_toogle_display_linked_entities(t_entity *entity);
t_result	link_entity_to_checkbox(t_checkbox *self, t_entity *entity);

#endif