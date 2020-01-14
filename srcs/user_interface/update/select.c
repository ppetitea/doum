/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 18:56:45 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/13 22:20:43 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "game/game.h"
#include "user_interface/ui.h"

static t_bool	update_ui_components_select_status(t_ui_component *component,
	t_vec2i mouse)
{
	if (is_texture_collide(*component->texture, mouse, component->anchor))
	{
		if (component->status.is_selected == FALSE)
			component->status.is_selected = TRUE;
		else
			component->status.is_selected = FALSE;
	}
	else if (component->status.is_selected == TRUE)
		component->status.is_selected = FALSE;
	component->update_texture(component);
	return (FALSE);
}

t_result	update_ui_components_selectable(t_game *game, t_vec2i mouse)
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
		if (component->status.is_selectable)
		{
			if (update_ui_components_select_status(component, mouse))
				break ;
		}
	}
	return (OK);
}
