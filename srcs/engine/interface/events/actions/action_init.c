/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 05:41:17 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/29 06:40:20 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/component/action.h"
#include "utils/error.h"
#include "build.h"

t_result		init_action(t_action_node *action)
{
	if (action == NULL)
		return (throw_error("init_action", "NULL pointer provided"));
	init_list_head(&action->node);
	action->args = NULL;
	action->trigger_type = BASIC_TRIGGER;
	action->resource = NULL;
	action->resource_type = R_UNKNOW;
	action->action = NULL;
	return (OK);
}

t_action_node	*init_new_action()
{
	t_action_node *action;

	if (!(action = (t_action_node*)malloc(sizeof(t_action_node))))
		return (throw_null("init_new_action", "malloc failed"));
	init_action(action);
	return (action);
}

t_key_binding	*init_new_key_binding()
{
	t_key_binding	*bind;

	if (!(bind = (t_key_binding*)malloc(sizeof(t_key_binding))))
		return (throw_null("init_new_key_binding", "NULL pointer provided"));
	init_action(&bind->action);
	bind->action.trigger_type = KEY_BINDING;
	bind->is_down = FALSE;
	bind->key = -1;
	return (bind);
}
