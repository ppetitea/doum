/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 23:06:52 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/28 03:53:43 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTION_H
# define ACTION_H

# include "libft.h"
# include "utils/parser.h"

typedef enum	e_resource_type
{
	R_GAME,
	R_SCENE,
	R_MAP,
	R_CHARACTER,
	R_ENTITY,
	R_ENTITY_LIST,
	R_UNKNOW,
}				t_resource_type;

typedef struct	s_action_node
{
	t_list_head		node;
	t_resource_type	resource_type;
	void			*resource;
	t_dnon_object	*args;
	t_result		(*action)(void*, t_dnon_object*);
}				t_action_node;

#endif
