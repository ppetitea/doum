/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_update.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 23:21:04 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/26 08:19:33 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_UPDATE_H
# define ENTITY_UPDATE_H

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
**	UPDATE
*/
void		animate_texture(t_entity *entity);

#endif