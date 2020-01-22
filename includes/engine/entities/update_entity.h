/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_entity.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 04:13:23 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/21 23:52:01 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UPDATE_ENTITY_H
# define UPDATE_ENTITY_H

# include "libft.h"
# include "engine/resources/textures/texture.h"
# include "engine/entities/init_entity.h"
# include "engine/scenes/init_scene.h"

typedef struct	s_entity_node
{
	t_list_head	node;
	t_entity	*entity;
}				t_entity_node;

t_result	entity_add_child(t_entity *parent, t_entity *child);

t_result	update_entity_anchor(t_entity *entity, t_vec2i anchor);
t_result	update_entity_offset(t_entity *entity, t_vec2i offset);
t_result	update_entity_texture(t_entity *entity, t_list_head *texture_head);

t_result	update_hoverables_entities(t_list_head *entities, t_mouse mouse);
t_result	update_selectables_entities(t_scene *scene, t_list_head *entities,
 				t_mouse mouse);
t_result	update_draggables_entities(t_scene *scene, t_list_head *entities,
 				t_mouse mouse);

t_result	trigger_animation(t_entity *entity);
t_result	toggle_display_entity(t_entity *entity);
t_result	display_entity(t_entity *entity);
t_result	hide_entity(t_entity *entity);

#endif