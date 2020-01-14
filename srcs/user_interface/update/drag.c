/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dragg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 18:56:45 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/13 20:28:11 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "game/game.h"
#include "user_interface/ui.h"

static t_bool	update_ui_components_drag_status(t_game *game,
	t_ui_component *component, t_vec2i mouse)
{
	t_vec2i			offset;

	if (component->status.is_dragged == TRUE && game->mouse.drag == FALSE)
	{
		offset.x = mouse.x + component->texture->offset.x;
		offset.y = mouse.y + component->texture->offset.y;
		component->texture->offset = offset;
		component->anchor = ft_vec2i(0, 0);
		component->status.is_dragged = FALSE;
		component->update_texture(component);
	}
	else if (is_texture_collide(*component->texture, mouse, component->anchor))
	{
		offset.x = component->texture->offset.x - mouse.x;
		offset.y = component->texture->offset.y - mouse.y;
		component->texture->offset = offset;
		component->anchor = mouse;
		component->status.is_dragged = TRUE;
		component->update_texture(component);
		if (component->status.action_drag != NULL)
			component->status.action_drag(game, component);
		return (TRUE);
	}
	return (FALSE);
}

t_result	update_ui_components_draggable(t_game *game, t_vec2i mouse)
{
	t_list_head		*pos;
	t_list_head		*next;
	t_ui_component	*component;

	pos = &game->ui_components;
	next = pos->next;
	while ((pos = next) != &game->ui_components)
	{
		next = next->next;
		component = (t_ui_component*)pos;
		if (component->status.is_draggable)
		{
			if (update_ui_components_drag_status(game, component, mouse))
			{
				list_del_entry(&component->node);
				list_add_entry(&component->node, &game->ui_components);
			 	break ;
			}
		}
	}
	return (OK);
}
