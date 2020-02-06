/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 01:15:15 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/06 18:49:23 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOUSE_H
# define MOUSE_H

# include "engine/game/game_init.h"
# include <SDL_events.h>

void	handle_mouse_motion(t_game *game, SDL_MouseMotionEvent event);
void	handle_mouse_down(t_game *game, SDL_MouseButtonEvent event);
void	handle_mouse_up(t_game *game, SDL_MouseButtonEvent event);

#endif