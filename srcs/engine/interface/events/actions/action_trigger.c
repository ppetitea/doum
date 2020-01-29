/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_trigger.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 00:32:19 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/29 03:26:42 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/resource/image/texture_init.h"
#include "engine/entity/entity_init.h"
#include "engine/component/action.h"
#include "engine/entity/entity_update.h"
#include "engine/game/game_init.h"
#include "utils/parser.h"
#include "utils/error.h"

t_result	trigger_actions(t_list_head *actions)
{
	t_list_head		*pos;
	t_action_node	*action;

	if (actions == NULL)
		return (throw_error("trigger_entity_actions", "NULL pointer"));
	pos = actions;
	while ((pos = pos->next) != actions)
	{
		action = (t_action_node*)pos;
		if (action->action == NULL)
			return (throw_error("trigger_action", "function pointer is NULL"));
		else
			action->action(action->resource, action->resource_type,
				action->args);
	}
	(void)action;
	return (OK);
}
