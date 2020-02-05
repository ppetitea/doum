/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 01:15:15 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/29 01:42:17 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "engine/game/game_init.h"
# include "engine/entity/entity_init.h"

void		handle_events(t_game *game);


/*
** triggers
*/
t_result	trigger_entities_by_hover(t_game *game);
t_result	trigger_entities_by_select(t_game *game);
t_result	trigger_entities_by_drag(t_game *game);
t_result	trigger_entities_by_drop(t_game *game);

#endif