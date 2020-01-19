/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_entity.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 04:13:23 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/18 22:01:09 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UPDATE_ENTITIES_H
# define UPDATE_ENTITIES_H

# include "libft.h"
# include "resources/textures/texture.h"
# include "game.h"
# include "entities/entities.h"

t_result	update_entity_anchor(t_entity *entity, t_vec2i anchor);
t_result	update_entity_offset(t_entity *entity, t_vec2i offset);
t_result	update_entity_texture(t_entity *entity, t_texture *texture);

t_result	update_hoverables_entities(t_list_head *entities, t_mouse mouse);
t_result	update_selectables_entities(t_game *game, t_list_head *entities,
 				t_mouse mouse);
t_result	update_draggables_entities(t_game *game, t_list_head *entities,
 				t_mouse mouse);

t_result	trigger_animation(t_entity *entity);
t_result	toggle_display_entity(t_entity *entity);

#endif