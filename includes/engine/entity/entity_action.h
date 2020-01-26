/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_action.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 23:57:51 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/25 00:09:08 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_ACTION_H
# define ENTITY_ACTION_H

# include "engine/entity/entity_init.h"

typedef enum	e_resource_type
{
	GAME,
	SCENE,
	ENTITY,
}				t_resource_type;

typedef struct	s_action_node
{
	t_list_head	node;
	void		*resource_ref;
	t_result	(*action)(void*);
}				t_action_node;

#endif
