/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hover.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 18:56:45 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/13 22:22:36 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "game/game.h"
#include "user_interface/ui.h"

static t_bool	update_ui_components_hover_status(t_ui_component *component,
	t_vec2i mouse)
{
	if (is_texture_collide(*component->texture, mouse, component->anchor))
	{
		component->status.is_hover = TRUE;
		component->update_texture(component);
	}
	else if (component->status.is_hover == TRUE)
	{
		component->status.is_hover = FALSE;
		component->update_texture(component);
	}
	return (FALSE);
}

t_result	update_ui_components_hoverable(t_game *game, t_vec2i mouse)
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
		if (component->status.is_hoverable)
		{
			if (update_ui_components_hover_status(component, mouse))
				break ;
		}
	}
	return (OK);
}
