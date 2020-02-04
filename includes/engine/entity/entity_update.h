/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_update.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 23:21:04 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/04 00:09:27 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_UPDATE_H
# define ENTITY_UPDATE_H

# include "engine/game/game_init.h"
# include "engine/entity/entity_init.h"

/*
**	GET
*/
t_entity	*get_entity_by_name(t_list_head *entities, char *name);

/*
**	DUPLICATE
*/
t_entity	*duplicate_entity_by_type(t_entity *src);
t_entity	*duplicate_entity(t_entity *src);
t_result	copy_entity(t_entity *src, t_entity *dest);

/*
** OVERWRITE
*/
t_result	overwrite_entity_by_type_with_obj(t_entity *entity,
				t_dnon_object *entity_obj);
t_result	overwrite_entity_with_obj(t_entity *self,
				t_dnon_object *entity_obj);

/*
** TRIGGER
*/
t_result	trigger_entity_action_by_hover(t_list_head *entities,
				t_mouse *mouse);
t_result	trigger_entity_action_by_select(t_list_head *entities,
				t_mouse *mouse);
t_result	trigger_entity_action_by_drag(t_list_head *entities,
				t_mouse *mouse);
t_result	trigger_entity_action_by_drop(t_list_head *entities,
				t_mouse *mouse);


/*
**	UPDATE
*/
void		animate_texture(t_entity *entity);


#endif