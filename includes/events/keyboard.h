/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 01:15:15 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/13 18:42:55 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYBOARD_H
# define KEYBOARD_H

# include "game/game.h"

void	handle_keyboard_down(t_game *game, SDL_Keycode key);
void	handle_keyboard_up(t_game *game, SDL_Keycode key);

#endif